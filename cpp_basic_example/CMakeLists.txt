cmake_minimum_required(VERSION 3.28.0)

project(s)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
include(FetchContent)
find_package(Python3 COMPONENTS Interpreter Development)
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0
)

FetchContent_Declare(
        termcolor
        GIT_REPOSITORY git@github.com:ikalnytskyi/termcolor.git
        GIT_TAG   v2.1.0
)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY git@github.com:catchorg/Catch2.git
        GIT_TAG v3.5.3
)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 3b15fa82ea74739b574d705fea44959b58142eb8) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases


FetchContent_MakeAvailable(spdlog Catch2 termcolor cpr)


set(SOURCES
        src/array_slice.cpp
        src/hello.cpp
        src/color.cpp
        src/main.cpp
        src/http/download.cpp
)

add_executable(s ${SOURCES})
target_include_directories(s PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(s PRIVATE spdlog::spdlog Catch2::Catch2 termcolor::termcolor cpr::cpr)
