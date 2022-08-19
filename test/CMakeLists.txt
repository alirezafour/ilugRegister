#-------------------------------------------------
#
# Project created 2014-12-07T15:51:53
#
#-------------------------------------------------

message( STATUS " -- Begining cmake build for LugRegister --")

#project setup
project(LugRegisterTest)
cmake_minimum_required(VERSION 3.5)

enable_testing()

set(TARGET_NAME "LugRegisterTest") # set variable

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
#	set(CMAKE_PREFIX_PATH "C:\\Qt\\"

set(CMAKE_AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui") #set ui files

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(PROJECT_SOURCES
        tst_testlug.cpp
        #../src/database_export.cpp
        #../src/configfile.cpp
        ../src/database/mydatabase.cpp
        ../src/model/personmodel.cpp
        ../src/model/attendantmodel.cpp
        ../src/model/duedaymodel.cpp
        ../src/model/reportmodel.cpp
        #../src/controllers/ilugapicontroller.cpp
        #../src/model/person.cpp
        #../src/UI/widgetui.cpp

        tst_testlug.h
        #../src/database_export.h
        #../src/configfile.h
        ../src/database/mydatabase.h
        ../src/model/personmodel.h
        ../src/model/attendantmodel.h
        ../src/model/duedaymodel.h
        ../src/model/reportmodel.h
        #../src/controllers/ilugapicontroller.h
        #../src/model/person.h
        #../src/UI/widgetui.h
)

qt_add_executable(${TARGET_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES})

add_test(${TARGET_NAME} ${TARGET_NAME})

target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Test)

set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)


install(TARGETS ${TARGET_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${TARGET_NAME})
endif()
