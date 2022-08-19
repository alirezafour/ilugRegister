#-------------------------------------------------
#
# Project created 2014-12-07T15:51:53
#
#-------------------------------------------------

message( STATUS " -- Begining cmake build for LugRegister --")

#project setup
project(LugRegister)
cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME "LugRegister") # set variable

message( STATUS " -- Set target ${TARGET_NAME} --")

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

set(PROJECT_SOURCES
        src/main.cpp
        src/database_export.cpp
        src/configfile.cpp
        src/database/mydatabase.cpp
        src/model/personmodel.cpp
        src/model/attendantmodel.cpp
        src/model/duedaymodel.cpp
        src/model/reportmodel.cpp
        src/controllers/ilugapicontroller.cpp
        src/model/person.cpp
        src/UI/widgetui.cpp
        src/mainwindow.cpp

        src/database_export.h
        src/configfile.h
        src/database/mydatabase.h
        src/model/personmodel.h
        src/model/attendantmodel.h
        src/model/duedaymodel.h
        src/model/reportmodel.h
        src/controllers/ilugapicontroller.h
        src/model/person.h
        src/UI/widgetui.h
        src/mainwindow.h

        ui/mainwindow.ui
)

add_executable(${TARGET_NAME}
        ${PROJECT_SOURCES})

target_link_libraries(${TARGET_NAME} PRIVATE Qt6::Sql)
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)


install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${TARGET_NAME})
endif()
