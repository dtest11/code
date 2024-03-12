cmake_minimum_required(VERSION 3.28.0)

project(example)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)
find_package(Python3 COMPONENTS Interpreter Development)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0
)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY git@github.com:catchorg/Catch2.git
        GIT_TAG v3.5.3
)
FetchContent_MakeAvailable(spdlog Catch2)


set(SOURCES
        src/array_slice.cpp
        src/hello.cpp
        src/main.cpp
)

add_executable(example ${SOURCES})
target_include_directories(example PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(example PRIVATE spdlog::spdlog Catch2::Catch2)
