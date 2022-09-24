cmake_minimum_required(VERSION 3.0.0)
project(VoxelGame)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(VoxelGame src/main.cpp src/Window.cpp)
target_compile_features(VoxelGame PRIVATE cxx_std_20)
target_link_libraries(VoxelGame SDL2)
target_link_libraries(VoxelGame OpenGL)
