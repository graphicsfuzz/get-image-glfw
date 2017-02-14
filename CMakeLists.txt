cmake_minimum_required(VERSION 2.8)

project(cpp)

# -- Build dependencies -- #
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/deps)
execute_process(
COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} ${CMAKE_SOURCE_DIR}/deps -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} -DCMAKE_TOOLCHAIN_FILE=${CMAKE_TOOLCHAIN_FILE}
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps
)
execute_process(
COMMAND ${CMAKE_COMMAND} --build . --config ${CMAKE_BUILD_TYPE}
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps
)
execute_process(
COMMAND ${CMAKE_COMMAND} -DCMAKE_INSTALL_PREFIX=../install -P cmake_install.cmake
WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/deps
)
# -- End build dependencies -- #

# Make sure CMake can find built dependencies
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR}/deps/install ${CMAKE_PREFIX_PATH})

find_package(glfw3 REQUIRED)

# We also want to use some include/source files from the GLFW source root
set(GLFW_SRC_DIR ${CMAKE_BINARY_DIR}/deps/GLFW-prefix/src/GLFW)


add_executable(get_image get_image.cpp lodepng.cpp ${GLFW_SRC_DIR}/deps/glad.c)
add_executable(get_gl_info get_gl_info.cpp ${GLFW_SRC_DIR}/deps/glad.c)

target_link_libraries(get_image glfw)
target_link_libraries(get_gl_info glfw)

target_include_directories(get_image PUBLIC ${GLFW_SRC_DIR}/deps)
target_include_directories(get_gl_info PUBLIC ${GLFW_SRC_DIR}/deps)

install(TARGETS get_image get_gl_info
    DESTINATION bin
)


if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-Wall -std=c++11 ${CMAKE_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")
endif()
