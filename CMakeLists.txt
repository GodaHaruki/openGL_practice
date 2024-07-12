cmake_minimum_required(VERSION 3.2)

project(component_system)

set(CXX_STANDARD 11)

set(glad_DIR glad)
set(glfw_DIR glfw-3.4)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

include_directories(${glad_DIR}/include)
add_subdirectory(${glad_DIR})
add_subdirectory(${glfw_DIR})

add_executable(main 
  ./src/main.cpp
  ./src/vertex_array/vertex_array.cpp
  ./src/shader/shader.cpp
)

target_link_libraries(main OpenGL::GL glfw glad)