#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

include($$PWD/QtRPT/QtRPT.pri)
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += $$PWD/src/main.cpp\
        $$PWD/src/mainwindow.cpp\
    $$PWD/src/database_export.cpp \
    $$PWD/src/configfile.cpp \
    $$PWD/src/logindialog.cpp \
    $$PWD/src/database/mydatabase.cpp

HEADERS  += $$PWD/src/mainwindow.h\
    $$PWD/src/database_export.h \
    $$PWD/src/configfile.h \
    $$PWD/src/logindialog.h \
$$PWD/src/database/mydatabase.h

FORMS    += $$PWD/ui/mainwindow.ui \
    $$PWD/ui/logindialog.ui

RESOURCES += $$PWD//rsc.qrc
