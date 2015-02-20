#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database_export.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //default set
    ui->Date_Line->setText("yyyy-mm-dd");

    //  Title & Date Config
    setWindowTitle("Lug Register");
    curentDate = QDate::currentDate();
    curentDate_Str = curentDate.toString(Qt::ISODate);
    ui->todayDay_lbl->setText(curentDate_Str);
    ui->todayDay_lbl_SelectTab->setText(curentDate_Str);

    //  Picture User Config
    loadImage("Image/empty.jpg");
    BrowsingImage("Image/empty.jpg");

}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


//Connect To Database Function
//*******************
bool MainWindow::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("lug.db");
    db.setUserName("ilug");
    db.setPassword("ilug");

    if (!db.open()) {
        QMessageBox::critical(0, qApp->tr("Cannot open database"),
            qApp->tr("Unable to establish a database connection.\n"), QMessageBox::Cancel);
        return false;
    }
    ViewTable("person", *ui->Table_view);
    ui->statusBar->showMessage("Database Connected!",3000);
    ui->Code_Line->setFocus();
    return true;
}
