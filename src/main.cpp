#include "src/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    // when added Password Card and section number active this form
    //QMetaObject::invokeMethod(&w, "login", Qt::QueuedConnection);

    return a.exec();
}
