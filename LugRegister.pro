#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T15:51:53
#
#-------------------------------------------------

include(QtRPT/QtRPT.pri)
QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LugRegister
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp\
    src/database_export.cpp \
    src/configfile.cpp \
    src/logindialog.cpp

HEADERS  += include/mainwindow.h\
    include/database_export.h \
    include/configfile.h \
    include/logindialog.h

FORMS    += ui/mainwindow.ui \
    ui/logindialog.ui
