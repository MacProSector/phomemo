#!/bin/bash

# Declare global variables
CORES=$(getconf _NPROCESSORS_ONLN)
ECLIPSE=4.23.0
DB_TYPE=Debug
RL_TYPE=Release

# Declare directory variables
PROJECT_DIR=$(pwd)/../..
SRC_DIR=$PROJECT_DIR/src
BUILD_DIR=$PROJECT_DIR/build
INSTALL_DIR=$PROJECT_DIR/install
TEMP_DIR=$PROJECT_DIR/temp

# Declare Boost variables
BOOST=boost
BOOST_DIR_BUILD=$BUILD_DIR/$BOOST
BOOST_DIR_INSTALL=$INSTALL_DIR/$BOOST
BOOST_VER_MAJ=1
BOOST_VER_MIN=79
BOOST_VER_PAT=0
BOOST_URL="https://sourceforge.net/projects/boost/files/boost/$BOOST_VER_MAJ.$BOOST_VER_MIN.$BOOST_VER_PAT/boost_${BOOST_VER_MAJ}_${BOOST_VER_MIN}_${BOOST_VER_PAT}.tar.gz/download"
BOOST_CFLAGS="-fPIC"
BOOST_BOOTSTRAP_FLAGS="--with-libraries=system,thread,date_time,regex,serialization"

# Declare Phomemo variables
PHOMEMO=phomemo
PHOMEMO_DIR_SRC=$SRC_DIR/$PHOMEMO
PHOMEMO_DIR_BUILD_DB=$BUILD_DIR/$PHOMEMO/$(echo $DB_TYPE | tr "[:upper:]" "[:lower:]")
PHOMEMO_DIR_BUILD_RL=$BUILD_DIR/$PHOMEMO/$(echo $RL_TYPE | tr "[:upper:]" "[:lower:]")

echo "[INFO]: Setting up Phomemo..."

# Create build and temporary folders
if [ -d "$TEMP_DIR" ]; then
	echo "[INFO]: Removing existing temporary folders..."
	rm -rf "$TEMP_DIR"
fi
echo "[INFO]: Creating build and temporary folders..."
mkdir -p "$BUILD_DIR"
mkdir -p "$TEMP_DIR"

RETURN=$?
if [ $RETURN -ne 0 ]; then
	echo "[ERROR]: Setup failed for Phomemo. Quit."
	exit $RETURN
fi

# Install Boost
echo "[INFO]: Installing Boost $BOOST_VER_MAJ.$BOOST_VER_MIN.$BOOST_VER_PAT..."
if [ ! -d "$BOOST_DIR_BUILD" ]; then
	echo "[INFO]: Downloading Boost $BOOST_VER_MAJ.$BOOST_VER_MIN.$BOOST_VER_PAT..."
	cd "$TEMP_DIR"
	curl -L --progress-bar "$BOOST_URL" -o "boost_${BOOST_VER_MAJ}_${BOOST_VER_MIN}_${BOOST_VER_PAT}.tar.gz"

	echo "[INFO]: Extracting Boost $BOOST_VER_MAJ.$BOOST_VER_MIN.$BOOST_VER_PAT..."
	tar -xzf "boost_${BOOST_VER_MAJ}_${BOOST_VER_MIN}_${BOOST_VER_PAT}.tar.gz"
	mv "boost_${BOOST_VER_MAJ}_${BOOST_VER_MIN}_${BOOST_VER_PAT}" "$BOOST_DIR_BUILD"
else
	echo "[INFO]: Boost build folder exists. Skip."
fi
echo "[INFO]: Building Boost $BOOST_VER_MAJ.$BOOST_VER_MIN.$BOOST_VER_PAT..."
if [ ! -d "$BOOST_DIR_INSTALL" ]; then
	cd "$BOOST_DIR_BUILD"
	./bootstrap.sh "$BOOST_BOOTSTRAP_FLAGS" --prefix="$(printf "%q" "$BOOST_DIR_INSTALL")"
	./b2 cxxflags="$BOOST_CFLAGS" cflags="$BOOST_CFLAGS" -j$CORES install

	RETURN=$?
	if [ $RETURN -ne 0 ]; then
		echo "[ERROR]: Setup failed for Phomemo. Quit."
		exit $RETURN
	fi
else
	echo "[INFO]: Boost install folder exists. Skip."
fi

# Remove temporary folder
if [ -d "$TEMP_DIR" ]; then
	echo "[INFO]: Removing temporary folder..."
	rm -rf "$TEMP_DIR"
fi

# Create Phomemo projects
echo "[INFO]: Creating Phomemo projects..."
echo "[INFO]: Creating Phomemo debug project..."
if [ ! -d "$PHOMEMO_DIR_BUILD_DB" ]; then
	mkdir -p "$PHOMEMO_DIR_BUILD_DB"
	cd "$PHOMEMO_DIR_BUILD_DB"

	cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=$DB_TYPE -DCMAKE_ECLIPSE_MAKE_ARGUMENTS=-j$CORES -DCMAKE_ECLIPSE_VERSION=$ECLIPSE "$PHOMEMO_DIR_SRC"

	RETURN=$?
	if [ $RETURN -ne 0 ]; then
		echo "[ERROR]: Setup failed for Phomemo. Quit."
		exit $RETURN
	fi
else
	echo "[INFO]: Phomemo debug project exists. Skip."
fi
echo "[INFO]: Creating Phomemo release project..."
if [ ! -d "$PHOMEMO_DIR_BUILD_RL" ]; then
	mkdir -p "$PHOMEMO_DIR_BUILD_RL"
	cd "$PHOMEMO_DIR_BUILD_RL"

	cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=$RL_TYPE -DCMAKE_ECLIPSE_MAKE_ARGUMENTS=-j$CORES -DCMAKE_ECLIPSE_VERSION=$ECLIPSE "$PHOMEMO_DIR_SRC"

	RETURN=$?
	if [ $RETURN -ne 0 ]; then
		echo "[ERROR]: Setup failed for Phomemo. Quit."
		exit $RETURN
	fi
else
	echo "[INFO]: Phomemo release project exists. Skip."
fi

echo "[INFO]: Setup completed for Phomemo."
