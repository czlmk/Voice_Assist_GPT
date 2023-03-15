cmake_minimum_required(VERSION 3.0.0)
project(home_ass VERSION 0.1.0)

add_library(
    messengen 
    messengen.h 
    messengen.cpp
)

find_package(nlohmann_json)

include_directories()

add_executable(home_ass main.cpp)

#check if have all submodule
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/libcurl/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
add_subdirectory(external/libcurl)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC external/libcurl/include
)

target_link_directories(
    ${PROJECT_NAME}
    PRIVATE external/libcurl/src
)
target_link_libraries(home_ass messengen nlohmann_json curl-d)


