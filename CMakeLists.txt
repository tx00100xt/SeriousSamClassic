cmake_minimum_required(VERSION 2.8.12)
project(SeriousEngine)

# Set @rpath for Mac OS X shared library install names.

# Use system SDL2 is on by default
option(USE_SYSTEM_SDL2 "Use systems sdl2 development files" On)
option(USE_SYSTEM_ZLIB "Use systems zlib development files" On)
option(USE_CCACHE "Set to ON to use ccache if present in the system" ${USE_CCACHE})

# fallback for cmake versions without add_compile_options # RAKE! Borrowed from dhewm3 project
if(NOT COMMAND add_compile_options)
	function(add_compile_options)
		foreach(arg ${ARGN})
			set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${arg}" PARENT_SCOPE)
			set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${arg}" PARENT_SCOPE)
		endforeach()
	endfunction()
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
include(CheckCXXCompilerFlag)

# SeriousSam expects the libs to be in Debug/
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/Debug)

if(USE_CCACHE)
    find_program(CCACHE_FOUND ccache)
    if(CCACHE_FOUND)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
    endif()
endif()


# Use systemwide SDL2 or custom build
# RAKE!: Find a way to use their custom built library if
# they want to use that instead or if their system only
# allows for a setup like this. Maybe use a SDL2_DIR var or
# some thing set in the system enviroment.
if(NOT USE_SYSTEM_SDL2)
    include_directories(${CMAKE_SOURCE_DIR}/External/SDL2)
else()
    find_package(SDL2 REQUIRED)
    if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIR})
    else()
        message(FATAL_ERROR "Error USE_SYSTEM_SDL2 is set but neccessary developer files are missing")
    endif()
endif()

if(USE_SYSTEM_ZLIB)
    find_package(ZLIB REQUIRED)
    if(ZLIB_FOUND)
        include_directories(${ZLIB_INCLUDE_DIRS})
    else()
        message(FATAL_ERROR "Error! USE_SYSTEM_ZLIB is set but neccessary developer files are missing")
    endif()
endif()


# Set up some sanity stuff...
if(CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME MATCHES "GNU|kFreeBSD")
    SET(LINUX TRUE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wno-reorder -Wno-unused-but-set-variable -Wno-maybe-uninitialized -Wno-class-memaccess -Wno-unused-function -Wno-format")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -Wno-reorder -Wno-unused-but-set-variable -Wno-maybe-uninitialized -Wno-class-memaccess -Wno-unused-function -Wno-format")
endif()
if(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
    SET(FREEBSD TRUE)
endif()
if(APPLE)
    SET(MACOSX TRUE)
endif()
if(MSVC)
    SET(WINDOWS TRUE)
endif()

# remove clang spam.
if(MACOSX OR FREEBSD)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-nullability-completeness")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-nullability-completeness")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "None Debug Release RelWithDebInfo MinSizeRel" FORCE)
endif()
SET(DEBUG FALSE)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    SET(DEBUG TRUE)
endif()

if (LINUX)
    set (CMAKE_OS_NAME "GNU/Linux" CACHE STRING "Operating system name" FORCE)
    ## Check for Debian GNU/Linux
    find_file (DEBIAN_FOUND debian_version debconf.conf
      PATHS /etc
      )
    if (DEBIAN_FOUND)
      set (CMAKE_OS_NAME "Debian" CACHE STRING "Operating system name" FORCE)
    endif (DEBIAN_FOUND)
    ##  Check for Fedora
    find_file (FEDORA_FOUND fedora-release
      PATHS /etc
      )
    if (FEDORA_FOUND)
      set (CMAKE_OS_NAME "Fedora" CACHE STRING "Operating system name" FORCE)
    endif (FEDORA_FOUND)
    ##  Check for RedHat
    find_file (REDHAT_FOUND redhat-release inittab.RH
      PATHS /etc
      )
    if (REDHAT_FOUND)
      set (CMAKE_OS_NAME "RedHat" CACHE STRING "Operating system name" FORCE)
    endif (REDHAT_FOUND)   
    ## Extra check for Ubuntu    
    if (DEBIAN_FOUND)
      ## At its core Ubuntu is a Debian system, with
      ## a slightly altered configuration; hence from
      ## a first superficial inspection a system will
      ## be considered as Debian, which signifies an
      ## extra check is required.
      find_file (UBUNTU_EXTRA legal issue
	PATHS /etc
	)
    if (UBUNTU_EXTRA)
	## Scan contents of file
	file (STRINGS ${UBUNTU_EXTRA} UBUNTU_FOUND
	  REGEX Ubuntu
	  )
	## Check result of string search
	if (UBUNTU_FOUND)
	  set (CMAKE_OS_NAME "Ubuntu" CACHE STRING "Operating system name" FORCE)
	  set (DEBIAN_FOUND FALSE)
	endif (UBUNTU_FOUND)
    endif (UBUNTU_EXTRA)      
    endif (DEBIAN_FOUND)
endif (LINUX)

add_subdirectory(SamTFE/Sources)
add_subdirectory(SamTSE/Sources)
