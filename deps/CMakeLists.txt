cmake_minimum_required(VERSION 2.8)

project(deps)

include(ExternalProject)

ExternalProject_Add(
GLFW
URL https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
CMAKE_ARGS 
-DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
-DGLFW_BUILD_EXAMPLES=0
-DGLFW_BUILD_TESTS=0
-DGLFW_BUILD_DOCS=0
INSTALL_COMMAND cmake -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install -P cmake_install.cmake
)

