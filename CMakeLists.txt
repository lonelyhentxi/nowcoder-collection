cmake_minimum_required(VERSION 3.10)


set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_HOME}/scripts/buildsystems/vcpkg.cmake)
project("nowcoder-collection")

set(CMAKE_CXX_STANDARD 14)
find_package(Catch2 CONFIG REQUIRED)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/cmake-build-debug)
include_directories(
        "coding-interviews")
file(GLOB_RECURSE CODE_INTERVIEWS_SOURCES "coding-interviews/*.hpp" "coding-interviews/*_spec.cpp")
add_executable(code_interviews "coding-interviews/spec.cpp" "${CODE_INTERVIEWS_SOURCES}")
target_link_libraries(code_interviews PRIVATE Catch2::Catch2)