cmake_minimum_required(VERSION 3.0.0)
project(home_ass VERSION 0.1.0)

add_library(messengen messengen.h messengen.cpp)
find_package(nlohmann_json )
include_directories()

add_executable(home_ass main.cpp)

target_link_libraries(home_ass messengen)




#link for nlohmann
target_link_libraries(home_ass nlohmann_json)
