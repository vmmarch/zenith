cmake_minimum_required(VERSION 3.17)
project(example-model)

include_directories(../../include ../../modules)

link_libraries(D:/project/zenith/bin/glfw3.dll)

add_executable(${PROJECT_NAME} main.cpp ../../extern/GLAD/glad.c)