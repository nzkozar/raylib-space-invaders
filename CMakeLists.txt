cmake_minimum_required(VERSION 3.30)

project(${CMAKE_PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

function(include_dependency libName gitURL gitTag)
    FetchContent_Declare(
            ${libName}
            GIT_REPOSITORY ${gitURL}
            GIT_TAG ${gitTag}
            GIT_SHALLOW TRUE
            GIT_PROGRESS TRUE
    )
    FetchContent_MakeAvailable(${libName})
endfunction()

set(LIB1 raylib)
find_package(${LIB1} QUIET)
if (NOT ${LIB1}_FOUND)
    include_dependency(${LIB1} https://github.com/raysan5/raylib.git 5.5)
endif ()

# Set your source directories
set(SOURCE_DIRS src)
# Collect sources from specified directories
foreach(DIR ${SOURCE_DIRS})
    file(GLOB_RECURSE DIR_SOURCES
            LIST_DIRECTORIES false
            "${DIR}/*.cpp" "${DIR}/*.hpp"
    )
    list(APPEND SOURCES ${DIR_SOURCES})
endforeach()


add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${raylib_INCLUDE_DIRS})

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${LIB1})