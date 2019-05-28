set(cmake_version 3.13.1)

cmake_minimum_required(VERSION ${cmake_version})

set(AppName "ParserCPP")

project(${AppName} 
		VERSION 1.0.0.0
		LANGUAGES CXX)
		
message(STATUS "cur c++ compiler is:${CMAKE_CXX_COMPILER}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} /std:c++14 /Od /W4 /WX")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} /std:c++14 /O2 /W4 /WX")
endif(MSVC)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O0 -fPIC -Wall -Wextra")
endif (UNIX)

set(INCLUDE_DIRS
	${CMAKE_SOURCE_DIR}/include
	)
set(HEADERS 
	${CMAKE_SOURCE_DIR}/include/LineParser.h
	)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(SOURCES
	${SOURCE_DIR}/main.cpp
	${SOURCE_DIR}/LineParser.cpp
	)


include_directories("${INCLUDE_DIRS}")

# Setup testing
enable_testing()
add_subdirectory(tests)

# Create application
add_executable(${AppName} ${SOURCES} ${HEADERS})
