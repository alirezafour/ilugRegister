SOURCES += $$PWD/database_export.cpp \
    $$PWD/configfile.cpp \
    $$PWD/database/mydatabase.cpp \
    $$PWD/model/personmodel.cpp \
    $$PWD/model/attendantmodel.cpp \
    $$PWD/model/duedaymodel.cpp \
    $$PWD/model/reportmodel.cpp \
    $$PWD/controllers/ilugapicontroller.cpp

HEADERS  += \ $$PWD/database_export.h \
    $$PWD/configfile.h \
    $$PWD/database/mydatabase.h \
    $$PWD/model/personmodel.h \
    $$PWD/model/attendantmodel.h \
    $$PWD/model/duedaymodel.h \
    $$PWD/model/reportmodel.h \
    $$PWD/controllers/ilugapicontroller.h

FORMS    += $$PWD/../ui/mainwindow.ui

RESOURCES += $$PWD/..//rsc.qrc
