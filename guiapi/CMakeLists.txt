# ----------------------------------------------------------------------
#
# Copyright (C) 2020 dahan All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ----------------------------------------------------------------------

# ===> Creates on 2021/5/26. <===

#
# @author 2B键盘
#
CMAKE_MINIMUM_REQUIRED(VERSION 3.17)
PROJECT(GUI)

SET(CMAKE_CXX_STANDARD 14)
SET(UPPER_FOLDER ..)

ADD_DEFINITIONS(-D__ZENITH_BUILD_DLL__)

INCLUDE_DIRECTORIES(${PROJECT_NAME} SYSTEM ${UPPER_FOLDER}/include)

ADD_LIBRARY(${PROJECT_NAME} SHARED
        component.cpp
)

