#-------------------------------------------------
#
# Project created by QtCreator 2016-11-13T01:09:21
#
#-------------------------------------------------

QT       += testlib sql

QT       -= gui

TARGET = tst_testlug
TEMPLATE = app

CONFIG   += warn_on qmltestcase c++11
CONFIG += testcase

include($$PWD/../LugRegister.pro)
INCLUDEPATH += ..
SOURCES -= $$PWD/src/main.cpp


SOURCES += $$PWD/tst_testlug.cpp


DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    $$PWD/tst_testlug.h

SOURCES -= $$PWD/../src/main.cpp
