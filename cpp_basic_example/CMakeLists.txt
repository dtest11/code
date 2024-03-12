cmake_minimum_required(VERSION 3.28)
project(example)
# set(CMAKE_CXX_COMPILER "/usr/bin/clang++")


include(FetchContent)
find_package(Python3 COMPONENTS Interpreter Development)
FetchContent_Declare(
        spdlog
       GIT_REPOSITORY git@github.com:gabime/spdlog.git
       GIT_TAG v1.12.0
)


# After the following call, the CMake targets defined by googletest and
# Catch2 will be available to the rest of the build
FetchContent_MakeAvailable(spdlog)

 set(SOURCE
         src/hello.cpp
         src/main.cpp
 )
add_executable(example
         ${SOURCE}
)
target_include_directories(example
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)
#target_link_libraries(example PRIVATE ${PROJECT_SOURCE_DIR}/include spdlog::spdlog)