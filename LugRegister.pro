#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

QT       += core widgets gui sql

#include($$PWD/QtRPT/QtRPT.pri)

#greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp\
        $$PWD/src/mainwindow.cpp\
    $$PWD/src/database_export.cpp \
    $$PWD/src/configfile.cpp \
    #$$PWD/src/logindialog.cpp \
    $$PWD/src/database/mydatabase.cpp \
    $$PWD/src/model/personmodel.cpp \
    $$PWD/src/model/attendantmodel.cpp \
    $$PWD/src/model/duedaymodel.cpp \
    $$PWD/src/model/reportmodel.cpp \

HEADERS  += $$PWD/src/mainwindow.h\
    $$PWD/src/database_export.h \
    $$PWD/src/configfile.h \
    #$$PWD/src/logindialog.h \
    $$PWD/src/database/mydatabase.h \
    $$PWD/src/model/personmodel.h \
    $$PWD/src/model/attendantmodel.h \
    $$PWD/src/model/duedaymodel.h \
    $$PWD/src/model/reportmodel.h \

FORMS    += $$PWD/ui/mainwindow.ui \
    #$$PWD/ui/logindialog.ui

RESOURCES += $$PWD//rsc.qrc
