#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

include(../QtRPT/QtRPT.pri)
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    database_export.cpp \
    configfile.cpp \
    logindialog.cpp

HEADERS  += mainwindow.h\
    database_export.h \
    configfile.h \
    logindialog.h

FORMS    += mainwindow.ui \
    logindialog.ui
