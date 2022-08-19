#include "src/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // TODO: Creating app
    // setting UI class
    // going inot loop for UI

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
