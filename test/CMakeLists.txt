#-------------------------------------------------
#
# Project created 2014-12-07T15:51:53
#
#-------------------------------------------------

message( STATUS " -- Begining cmake build for LugRegisterTest --")

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

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        tst_testlug.cpp
        ../src/database/mydatabase.cpp
        ../src/model/personmodel.cpp
        ../src/model/attendantmodel.cpp
        ../src/model/duedaymodel.cpp

        tst_testlug.h
        ../src/database/mydatabase.h
        ../src/model/personmodel.h
        ../src/model/attendantmodel.h
        ../src/model/duedaymodel.h
)

include_directories(
    ../
    ../src
)

enable_testing(true)

add_executable(${TARGET_NAME}
        ${PROJECT_SOURCES})

add_test(${TARGET_NAME} ${TARGET_NAME})

target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Test)
target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
