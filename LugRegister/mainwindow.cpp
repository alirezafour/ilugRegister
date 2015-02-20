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

//Find data From Database by Code Function
//**************
bool MainWindow::FindCode()
{   
    ui->Code_Line->selectAll();     //select all Code in Code Line

    if(ui->Code_Line->text().isEmpty())
    {
        QMessageBox::critical(0, "Enter Code", "Please First type Code \n Type Code First");
        ui->Code_Line->setFocus();
        return false;
    }

    QSqlQuery query;    //query for person
    QSqlQuery query2;   //query for attendant
    QSqlQuery query3;   //query for dueDay
    QString attendantDay;   //  what si in the table attendant?
    QString dueDayDate; // what is in the table dueDay?
    QString dateInsert("\"" + curentDate_Str + "\""); // add " to curent day

    query.exec("SELECT firstname, lastname, sessionCounter FROM person WHERE Code == "+ ui->Code_Line->text());
    query2.exec("SELECT Date FROM attendant WHERE Code ==" + ui->Code_Line->text());
    query3.exec("SELECT Date FROM dueDay WHERE Date ==" + dateInsert);
    while(query3.next())
    {
        dueDayDate = QString(query3.value(0).toString());
    }
    if(!(curentDate_Str == dueDayDate))
    {
        query3.prepare("INSERT INTO dueDay (Date)"
                    "VALUES (:Date)");
        query3.bindValue(":Date", curentDate_Str);
        query3.exec();
    }
    while (query2.next())
    {
        attendantDay = QString(query2.value(0).toString());
    }
        ui->Name_Line->setText("");
        ui->Family_Line->setText("");

        while(query.next())
        {
            QString name = query.value(0).toString();
            QString family = query.value(1).toString();
            int sessionCounter = query.value(2).toInt();
            if(!(curentDate_Str == attendantDay))
            {
                sessionCounter++;
                QString Sc = QString::number(sessionCounter);
                query2.exec("UPDATE person SET sessionCounter = "+ Sc + " WHERE Code == "+ ui->Code_Line->text());

                // Insert to attendant Table a record
                query.prepare("INSERT INTO attendant (Code, firstname, lastname, Date) "
                                  "VALUES (:Code, :firstname, :lastname, :Date)");
                    query.bindValue(":Code", ui->Code_Line->text());
                    query.bindValue(":firstname", name);
                    query.bindValue(":lastname", family);
                    query.bindValue(":Date", curentDate_Str);
                    query.exec();
            }
            ui->Name_Line->setText(name);
            ui->Family_Line->setText(family);
        }
        if(!loadImage("Image/" + ui->Code_Line->text() +".jpg"))
            loadImage("Image/empty.jpg");
        filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);
        ui->Code_Line->setFocus();
    return true;
}
