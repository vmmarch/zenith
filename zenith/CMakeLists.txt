CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(zenith)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DZENITH_BUILD_DLL)

ADD_LIBRARY(
        zenith SHARED
        core/application.cpp
        core/application.h
        core/core.h
        core/entry_ptr.h
)

SET_TARGET_PROPERTIES(zenith PROPERTIES PREFIX "")
