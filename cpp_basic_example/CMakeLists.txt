cmake_minimum_required(VERSION 3.28)
project(example)
# set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
find_package(Python3 COMPONENTS Interpreter Development)
FetchContent_Declare(
        spdlog
       GIT_REPOSITORY git@github.com:gabime/spdlog.git
       GIT_TAG v1.12.0
)

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