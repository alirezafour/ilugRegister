#-------------------------------------------------
#
# Project created 2014-12-07T15:51:53
#
#-------------------------------------------------

message( STATUS " -- Begining cmake build for LugRegister --")

#project setup
project(LugRegister)
cmake_minimum_required(VERSION 3.5)

message( STATUS " -- Set target ${PROJECT_NAME} --")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP") #multi process compiling

# Find Qt
#if(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
        set(CMAKE_PREFIX_PATH "D:/Qt/6.3.1/msvc2019_64") #Qt Prefix path

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui")

find_package(QT NAMES Qt5 Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(src)

file(GLOB SOURCES
     "src/*.cpp"
     "src/*/*.cpp"

     "src/*.h"
     "src/*/*.h"

     "ui/*.ui"
)

add_executable(${PROJECT_NAME}
        ${SOURCES})

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        Qt6::Sql
        Qt6::Widgets
)


set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/build/Export
                ${CMAKE_CURRENT_BINARY_DIR}/Export)

add_custom_command(TARGET ${PROJECT_NAME}  POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_CURRENT_SOURCE_DIR}/build/Image
                ${CMAKE_CURRENT_BINARY_DIR}/Image)

# Tests
enable_testing()
add_subdirectory( test )