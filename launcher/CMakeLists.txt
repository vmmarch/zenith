CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(launcher)

add_definitions(-DZENITH_PLATFORM_WINDOWS -DZENITH_BUILD_DLL)

ADD_LIBRARY(
        launcher SHARED
        core/application.cpp
        core/application.h
        core/core.h
        entry_ptr.h
)

SET_TARGET_PROPERTIES(launcher PROPERTIES PREFIX "")
