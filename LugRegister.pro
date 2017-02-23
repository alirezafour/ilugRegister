#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp\
        $$PWD/src/mainwindow.cpp\
    $$PWD/src/database_export.cpp \
    $$PWD/src/configfile.cpp \
    $$PWD/src/database/mydatabase.cpp \
    $$PWD/src/model/personmodel.cpp \
    $$PWD/src/model/attendantmodel.cpp \
    $$PWD/src/model/duedaymodel.cpp \
    $$PWD/src/model/reportmodel.cpp \
    $$PWD/src/controllers/ilugapicontroller.cpp \
    $$PWD/src/model/person.cpp

HEADERS  += $$PWD/src/mainwindow.h\
    $$PWD/src/database_export.h \
    $$PWD/src/configfile.h \
    $$PWD/src/database/mydatabase.h \
    $$PWD/src/model/personmodel.h \
    $$PWD/src/model/attendantmodel.h \
    $$PWD/src/model/duedaymodel.h \
    $$PWD/src/model/reportmodel.h \
    $$PWD/src/controllers/ilugapicontroller.h \
    $$PWD/src/model/person.h

FORMS    += $$PWD/ui/mainwindow.ui

RESOURCES += $$PWD//rsc.qrc
