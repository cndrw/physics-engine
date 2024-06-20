cmake_minimum_required(VERSION 3.28)
project(physics_engine)

set(CMAKE_CXX_STANDARD 17)
# add_compile_options(-Wall -Wextra -pedantic -O0)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Adding our source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
# set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

# Declaring our executable
add_executable(${PROJECT_NAME}
        include/solver.hpp
        include/solver.hpp
        src/solver.cpp
        src/solver.cpp)
#[[
        include/scene.hpp
        include/shapes.hpp
        include/transform.hpp
        include/engine.hpp
        include/engine.hpp
        src/engine.cpp
        src/engine.cpp
        src/scene.cpp
        src/scene.cpp
        src/shapes.cpp
        src/shapes.cpp
        include/rigidbody.hpp
        src/rigidbody.cpp
        src/transform.cpp)
]]
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)


