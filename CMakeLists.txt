cmake_minimum_required(VERSION 3.0.0)
project(home_ass)
add_executable(${PROJECT_NAME} main.cpp)

add_library(
    messengen 
    messengen.h 
    messengen.cpp
)
add_library(
    httpcon
    httpcon.h
    httpcon.cpp
)
add_library(
    tts
    tts.h
    tts.cpp
)
add_library(
    alsaplay
    alsaplay.h
    alsaplay.cpp
)


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
#linking libcurl
add_subdirectory(external/libcurl)
target_include_directories(
    httpcon 
    PUBLIC external/libcurl/include
)
target_link_directories(
    httpcon
    PRIVATE external/libcurl/src
)
target_link_libraries(httpcon libcurl)

##linking flite
find_path(FLITE_ROOT flite/flite.h PATH_SUFFIXES include)
#set(FLITE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/flite)
message(STATUS "Flite root is ${FLITE_ROOT} ")
add_library(FLite INTERFACE IMPORTED)
target_include_directories(FLite INTERFACE ${FLITE_ROOT})
target_link_directories(FLite INTERFACE ${FLITE_ROOT}/lib)
target_link_libraries(FLite INTERFACE  -lflite_usenglish -lflite_cmulex -lflite_cmu_us_slt -lflite -lm)
target_link_libraries(tts PUBLIC FLite)
#JSON
find_package(nlohmann_json)
target_link_libraries(messengen nlohmann_json::nlohmann_json)
#ALSA
find_package(ALSA REQUIRED)
include_directories(${ALSA_INCLUDE_DIRS})
target_link_libraries(alsaplay PUBLIC ${ALSA_LIBRARIES})

target_link_libraries(${PROJECT_NAME} PUBLIC messengen httpcon alsaplay tts )



