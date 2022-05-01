# Set global parameters
cmake_minimum_required(VERSION 2.8.12)
project(phomemo)

# Set CMake parameters
set(CMAKE_SYSTEM_NAME Linux)

# Set compiler parameters
set(CMAKE_C_FLAGS "-Wall -Wextra -static-libc -fPIC")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Wextra -Wno-unused-command-line-argument -static-libstdc++ -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set installation paths
string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_PATH)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/lib)

# Set include directories
include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
)

# Add subdirectories
add_subdirectory(applications)
