cmake_minimum_required (VERSION 3.23)

#Compiler
set(CMAKE_CXX_COMPILER	"C:/MinGW/bin/g++.exe")
set(CMAKE_C_COMPILER	"C:/MinGW/bin/gcc.exe")

project (pokeciv)

# Directories
include_directories ("${PROJECT_SOURCE_DIR}/src/client")
include_directories ("${PROJECT_SOURCE_DIR}/src/server")
include_directories ("${PROJECT_SOURCE_DIR}/src/shared")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Enable C++11
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(CMAKE_COMPILER_IS_GNUCC)
	SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Wall -std=c11   -pthread -g -lsfml-xxx")
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -pthread -g -lsfml-xxx")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

# Enable build for Windows
add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 2)

# Sources
file(GLOB_RECURSE client_sources src/client/*.h)
file(GLOB_RECURSE client_sources src/client/*.cpp)
file(GLOB_RECURSE server_sources src/server/*.h)
file(GLOB_RECURSE server_sources src/server/*.cpp)
file(GLOB_RECURSE shared_sources src/shared/*.h)
file(GLOB_RECURSE shared_sources src/shared/*.cpp)

#jsoncpp
include_directories ("${PROJECT_SOURCE_DIR}/extern/jsoncpp-1.8.0")
file(GLOB_RECURSE jsoncpp_sources extern/jsoncpp-1.8.0/*.cpp)

# Executables
add_executable(client WIN32 ${client_sources} ${shared_sources} ${jsoncpp_sources})
add_executable(server WIN32 ${server_sources} ${shared_sources} ${jsoncpp_sources})

# SFML
set(SFML_ROOT "D:/Utils/SFML-2.5.1")
set(CMAKE_MODULE_PATH "${SFML_ROOT}/lib/cmake/SFML" ${CMAKE_MODULE_PATH})

find_package(SFML 2.5.1 COMPONENTS graphics window system network)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(client ${SFML_LIBRARIES})
endif()

# libmicrohttpd
find_library(
	MHD_LIBRARY
	NAMES microhttpd microhttpd-10 libmicrohttpd libmicrohttpd-dll libmicrohttpd-dll_d libmicrohttpd_d
	PATHS "D:/Utils/libmicrohttpd-0.9.77-w32-bin/x86_64/VS2022/Debug-dll"
	DOC "microhttpd library"
)

target_link_libraries(server ${MHD_LIBRARY})

