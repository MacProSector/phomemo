#!/bin/bash

# Declare global variables
CORES=$(grep -c ^processor /proc/cpuinfo)
ECLIPSE=4.23.0
DB_TYPE=Debug
RL_TYPE=Release

# Declare directory variables
PROJECT_DIR=$(pwd)/../..
SRC_DIR=$PROJECT_DIR/src
BUILD_DIR=$PROJECT_DIR/build
INSTALL_DIR=$PROJECT_DIR/install

# Declare Phomemo variables
PHOMEMO=phomemo
PHOMEMO_DIR_SRC=$SRC_DIR/$PHOMEMO
PHOMEMO_DIR_BUILD_DB=$BUILD_DIR/$PHOMEMO/$(echo $DB_TYPE | tr "[:upper:]" "[:lower:]")
PHOMEMO_DIR_BUILD_RL=$BUILD_DIR/$PHOMEMO/$(echo $RL_TYPE | tr "[:upper:]" "[:lower:]")

echo "[INFO]: Setting up Phomemo..."

# Create build folders
echo "[INFO]: Creating build folders..."
mkdir -p "$BUILD_DIR"
RETURN=$?
if [ $RETURN -ne 0 ]; then
	echo "[ERROR]: Setup failed for Phomemo. Quit."
	exit $RETURN
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
