# Set global parameters
cmake_minimum_required(VERSION 3.0)
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

# Set threads library for macOS
if(APPLE)
	set(CMAKE_THREAD_LIBS_INIT "-lpthread")
    set(CMAKE_HAVE_THREADS_LIBRARY 1)
    set(CMAKE_USE_WIN32_THREADS_INIT 0)
    set(CMAKE_USE_PTHREADS_INIT 1)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
endif()

# Set installation paths
string(TOLOWER ${CMAKE_BUILD_TYPE} CMAKE_BUILD_TYPE_PATH)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../install/phomemo/${CMAKE_BUILD_TYPE_PATH}/lib)

# Set package parameters
set(Boost_NO_SYSTEM_PATHS TRUE)
set(BOOST_ROOT ${PROJECT_SOURCE_DIR}/../../install/boost)

# Find packages
find_package(Boost REQUIRED COMPONENTS system thread date_time regex serialization)

# Set include directories
include_directories(
	${PROJECT_SOURCE_DIR}
	${PROJECT_BINARY_DIR}
	${Boost_INCLUDE_DIRS}
)

# Add subdirectories
add_subdirectory(applications)
add_subdirectory(communication)
add_subdirectory(printer)
add_subdirectory(utility)