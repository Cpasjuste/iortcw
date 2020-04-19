cmake_minimum_required(VERSION 3.2)
#set(CMAKE_VERBOSE_MAKEFILE ON)

option(PLATFORM_LINUX "Linux platform target" OFF)
option(PLATFORM_SWITCH "Nintendo Switch platform target" OFF)

project(iortcw)

if (PLATFORM_LINUX)
    set(CMAKE_SYSTEM_NAME "Linux")
elseif (PLATFORM_SWITCH)
    set(DEVKITPRO $ENV{DEVKITPRO} CACHE BOOL "DEVKITPRO")
    include("${DEVKITPRO}/switch.cmake")
endif ()

file(GLOB SOURCES
        SP/code/botlib/*.c
        SP/code/cgame/*.c
        SP/code/client/*.c
        SP/code/game/*.c
        SP/code/qcommon/*.c
        SP/code/renderer/*.c
        SP/code/sdl/*.c
        SP/code/server/*.c
        SP/code/splines/*.cpp
        SP/code/ui/*.c
        )

list(APPEND SOURCES
        SP/code/sys/con_log.c
        SP/code/sys/con_tty.c
        SP/code/sys/sys_main.c
        SP/code/sys/sys_unix.c
        SP/code/sys/sys_loadlib.c
        )

set(INCLUDES
        SP/code/botlib
        SP/code/cgame
        SP/code/client
        SP/code/game
        SP/code/qcommon
        SP/code/renderer
        SP/code/sdl
        SP/code/server
        SP/code/splines
        SP/code/sys
        SP/code/ui
        )

list(REMOVE_ITEM SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/renderer/tr_subs.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/splines/q_shared.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/qcommon/vm_armv7l.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/qcommon/vm_none.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/qcommon/vm_powerpc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/qcommon/vm_powerpc_asm.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/qcommon/vm_sparc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/SP/code/cgame/cg_syscalls.c
        )

find_package(SDL2 REQUIRED)
find_package(CURL REQUIRED)
find_package(ZLIB REQUIRED)
# vorbis
include(FindPkgConfig)
pkg_search_module(VORBIS REQUIRED vorbis)
pkg_search_module(VORBISFILE REQUIRED vorbisfile)
pkg_search_module(OGG REQUIRED ogg)

set(CFLAGS -DNODL -DUSE_CURL -DUSE_CODEC_VORBIS -DBOTLIB -DNO_VM_COMPILED -DGAMEDLL -DQAGAME -DCGAMEDLL -DCGAME)
set(CMAKE_CXX_FLAGS "-fno-exceptions -std=gnu++11 -fpermissive" CACHE STRING "C++ flags" FORCE)

set(LDFLAGS)

if (PLATFORM_SWITCH)
    find_package(JPEG REQUIRED)
    list(APPEND CFLAGS -DARCH_STRING=\"aarch64\")
else ()
    file(GLOB JPEG_SOURCES SP/code/jpeg-8c/*.c)
    list(APPEND SOURCES ${JPEG_SOURCES})
    set(JPEG_INCLUDE_DIRS SP/code/jpeg-8c)
    list(APPEND SOURCES
            SP/code/asm/ftola.c
            SP/code/asm/snapvector.c
            )
    list(APPEND CFLAGS -DARCH_STRING=\"x86_64\")
    list(APPEND LDFLAGS minizip rt)
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC
        ${SDL2_INCLUDE_DIRS}
        ${VORBIS_INCLUDE_DIRS}
        ${VORBISFILE_INCLUDE_DIRS}
        ${OGG_INCLUDE_DIRS}
        ${CURL_INCLUDE_DIRS}
        ${ZLIB_INCLUDE_DIRS}
        ${JPEG_INCLUDE_DIRS}
        ${INCLUDES})
target_link_libraries(${PROJECT_NAME} PUBLIC
        ${SDL2_LIBRARIES}
        ${VORBIS_LIBRARIES}
        ${VORBISFILE_LIBRARIES}
        ${OGG_LIBRARIES}
        ${CURL_LIBRARIES}
        ${ZLIB_LIBRARIES}
        ${JPEG_LIBRARIES}
        ${LDFLAGS})
target_compile_options(${PROJECT_NAME} PUBLIC ${CFLAGS})