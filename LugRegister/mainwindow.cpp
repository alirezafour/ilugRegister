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

//Add data to Database Function
//**************
bool MainWindow::AddData()
{

    QSqlQuery query;
    int AddCode = 0;
    AddCode = ui->Code_Line2_Registertab->text().toInt();
    QString AddName =ui->Name_Line2_Registertab->text();
    QString AddFamily = ui->Family_Line2_Registertab->text();

    if(AddCode==0 || AddName=="" || AddFamily=="") return false;


    query.prepare("INSERT INTO person (Code, firstname, lastname) "
                      "VALUES (:Code, :firstname, :lastname)");
        query.bindValue(":Code", AddCode);
        query.bindValue(":firstname", AddName);
        query.bindValue(":lastname", AddFamily);
        query.exec();


    filterView("person","Code", ui->Code_Line2_Registertab->text(), *ui->Table_view_2);
    ui->statusBar->showMessage("Data Added!",3000);
    ui->Code_Line2_Registertab->selectAll();  //select all Code in Code Line
    ui->Code_Line2_Registertab->setFocus();
    return true;
}

//this Function for Delete Data From person Table and folow Delete From attendant by Code
//*******************
bool MainWindow::DeleteData()
{
    if(ui->Code_Line->text().isEmpty()) return false;

    QSqlQuery query;
    query.exec("DELETE FROM person WHERE Code ==" + ui->Code_Line->text());
    query.exec("DELETE FROM attendant WHERE Code ==" + ui->Code_Line->text());
    filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);
    ui->statusBar->showMessage("Data Deleted!",3000);
    ui->Code_Line->selectAll();  //select all Code in Code Line
    ui->Code_Line->setFocus();
    return true;
}

//this Function for Update data in Main tab
//*******************
bool MainWindow::UpdateData()
{
    QSqlQuery query;
    int Code = 0;
    Code = ui->Code_Line->text().toInt();
    QString Name = ui->Name_Line->text();
    QString Family = ui->Family_Line->text();

    if(Code==0 || Name=="" || Family=="") return false;

    query.prepare("UPDATE person SET firstname = :firstname, lastname = :lastname WHERE Code == :Code ");
        query.bindValue(":firstname", Name);
        query.bindValue(":lastname", Family);
        query.bindValue(":Code", Code);
        query.exec();
    query.prepare("UPDATE attendant SET firstname = :firstname, lastname = :lastname WHERE Code == :Code ");
        query.bindValue(":firstname", Name);
        query.bindValue(":lastname", Family);
        query.bindValue(":Code", Code);
        query.exec();

    loadImage("Image/" + ui->Code_Line->text() +".jpg");

    filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);
    ui->statusBar->showMessage("Data Updated!",3000);
    ui->Code_Line->selectAll();  //select all Code in Code Line
    ui->Code_Line->setFocus();
    return true;

}

//this Function for load Image and show in Register tab
//***********************
bool MainWindow::BrowsingImage(const QString &fileName)
{
    QSize size;
    size.setHeight(150);
    size.setWidth(150);
    QImage image(fileName);
    if (image.isNull())
    {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        setWindowFilePath(QString());
        ui->imageLabel_RegisterTab->setPixmap(QPixmap());
        ui->imageLabel_RegisterTab->setFixedSize(size);
        return false;
    }
    image = image.scaled(size, Qt::KeepAspectRatio);
    ui->imageLabel_RegisterTab->setPixmap(QPixmap::fromImage(image));
    ui->imageLabel_RegisterTab->setFixedSize(size);

    image.save("Image/" + ui->Code_Line2_Registertab->text() +".jpg");
    return true;
}

//this function for export date in date line to text file
//******************************
bool MainWindow::exportToTextFile(QString dateExport)
{
    QSqlQuery query;
    database_Export db_export;
    if(!(db_export.openFile("Export/"+ui->Date_Line->text() + ".txt"))) return false;

    query.exec("SELECT firstname, lastname FROM attendant WHERE Date == "+ dateExport);
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString family = query.value(1).toString();
        db_export.insertToFile(name , family);
    }
    db_export.closeFile();
    return true;
}

bool MainWindow::exportToTextFileToday(QString dateExport)
{
    QSqlQuery query;
    database_Export db_export;
    if(!(db_export.openFile("Export/" + curentDate_Str + ".txt"))) return false;

    query.exec("SELECT firstname, lastname FROM attendant WHERE Date == "+ dateExport);
    while(query.next())
    {
        QString name = query.value(0).toString();
        QString family = query.value(1).toString();
        db_export.insertToFile(name , family);
    }
    db_export.closeFile();
    return true;
}

bool MainWindow::exportToDucoWikiFileToday(QString dateExport)
{
        QSqlQuery query;
        database_Export db_export;
        if(!(db_export.openFile("Export/DucoWiki " + curentDate_Str + ".txt"))) return false;

        query.exec("SELECT firstname, lastname FROM attendant WHERE Date == "+ dateExport);
        while(query.next())
        {
            QString name = query.value(0).toString();
            QString family = query.value(1).toString();
            db_export.docuExport(name , family);
        }
        db_export.closeFile();
        return true;
}

//this function for searching name in database and show to table in search tab
//****************************
bool MainWindow::searchName()
{
    QString name;
    name = QString("\'\%"+ui->Name_Line3_SearchTab->text()+"\%\'");
    QString filter;
    filter = QString("firstname LIKE "+ name);

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setFilter(filter);
    ui->Table_view_SearchTab->setModel(model);
    ui->Table_view_SearchTab->resizeColumnsToContents();
    ui->Table_view_SearchTab->resizeRowsToContents();
    return true;
}

//this function for searchin family in database and show to table in search tab
//***********************************
bool MainWindow::searchFamily()
{
    QString family;
    family = QString("\'\%"+ui->Family_Line3_SearchTab->text()+"\%\'");
    QString filter;
    filter = QString("lastname LIKE "+ family);

    QSqlTableModel *model = new QSqlTableModel(this, db);
    model->setTable("person");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setFilter(filter);
    ui->Table_view_SearchTab->setModel(model);
    ui->Table_view_SearchTab->resizeColumnsToContents();
    ui->Table_view_SearchTab->resizeRowsToContents();
    return true;
}

//this Function for loa image and show in Main tab
//**************************
bool MainWindow::loadImage(const QString &fileName)
{
    QSize size;
    size.setHeight(150);
    size.setWidth(150);
    QImage image(fileName);
    if (image.isNull()) return false;
    image = image.scaled(size, Qt::KeepAspectRatio);
    ui->ImageLabel_Maintab->setPixmap(QPixmap::fromImage(image));
    ui->ImageLabel_Maintab->setFixedSize(size);
    return true;
}



//this Function for view all Data from table
//*******************
void MainWindow::ViewTable(QString table,QTableView &tableview)
{

    QSqlTableModel *model = new QSqlTableModel(this, db);
        model->setTable(table);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        tableview.setModel(model);
        tableview.setWindowTitle(table);
        tableview.resizeColumnsToContents();
        tableview.resizeRowsToContents();

    ui->statusBar->showMessage("Data Selected!",3000);
}

//this Function for viewed by rule
//********************
void MainWindow::filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview)
{
    QSqlTableModel *model = new QSqlTableModel(this, db);
        model->setTable(table);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
        model->setFilter(Column + " ==" + RecordFilter);
        tableview.setModel(model);
       tableview.setWindowTitle(table);
       tableview.resizeColumnsToContents();
       tableview.resizeRowsToContents();
}


//this Slot for Connect to Database by Click the Connect button
//******************
void MainWindow::ConnectionSlot()
{
    if(!createConnection())
    {
        QMessageBox::critical(0, "Error to Connect", "ERROR!!! Conection Failed");
        ui->db_status->setText("Connect to Database Failed.");
    }
    else
    {
        ui->db_status->setText("Connect to database Successful.");
    }
}

//this Slot for Select Data From Database by Click the Search Button or Enter in Code text line
//*****************
void MainWindow::findSlot()
{
    FindCode();
}

//this Slot for add Data to Databade by Click to Add Button
//*****************
void MainWindow::addDataSlot()
{
    if(!AddData())
        QMessageBox::critical(0, "Error to add data", "ERROR!!! add Data Failed");
    else
        ui->db_status->setText("Data Added to Database");
}

//this Slot for delete Data from Databade by Click to Delete Button
//*****************
void MainWindow::deleteSlot()
{
    if(!DeleteData())
        QMessageBox::critical(0, "Error to Delete data", "ERROR!!! Delete Data Failed");
    else
        ui->db_status->setText("Data Deleted!");
    ui->Code_Line->selectAll();
    ui->Code_Line->setFocus();
}

//this Slot for select Data from Databade by Click to Select Button
//*****************
void MainWindow::selectPersonSlot()
{
    ViewTable("person", *ui->Table_view);
    ui->db_status->setText("Data Selected!");
    ui->Code_Line->selectAll();
    ui->Code_Line->setFocus();
}

//this Slot for Select Data From attendant Table
//**********************
void MainWindow::selectDateSlot()
{
    ViewTable("attendant", *ui->Table_view_5);
    ui->db_status->setText("Data Selected!");
}

//this Slot for update Data to Databade by Click to Update Button
//*****************
void MainWindow::updateSlot()
{
    if(!UpdateData())
        QMessageBox::critical(0, "Error to Update data", "ERROR!!! Update Data Failed");
    else
        ui->db_status->setText("Data Updated!");
    ui->Code_Line->selectAll();
    ui->Code_Line->setFocus();

}

//this function for searching and finding code in attendent table in database and show to table in Select tab
//***********************
void MainWindow::findCodeFromAttendant()
{
    filterView("attendant", "Code", ui->Code_Line3_Selecttab->text(), *ui->Table_view_5);
    ui->Code_Line3_Selecttab->selectAll();
    ui->Code_Line3_Selecttab->setFocus();
}
