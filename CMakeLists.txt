cmake_minimum_required(VERSION 2.8)
project(story_script)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -lpthread") #Add Flags here.
set(EXECUTABLE_OUTPUT_PATH ${story_script_SOURCE_DIR}/bin)
file(GLOB story_script_HEADERS "include/*.hpp" "include/Tokens/*.hpp" "include/Tests/*.hpp")
add_custom_target(story_script SOURCES ${story_script_HEADERS})

add_definitions("-std=c++14")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_AUTOMOC ON)
#find_package(Qt5Widgets)

subdirs(src)
