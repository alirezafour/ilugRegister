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

    // [Conncet buttons to Slots]
    connect(ui->SearchButton, SIGNAL(clicked()), SLOT(findSlot()));
    connect(ui->AddButton_Registertab, SIGNAL(clicked()), SLOT(addDataSlot()));
    connect(ui->SelectButton, SIGNAL(clicked()), SLOT(selectPersonSlot()));
    connect(ui->deleteButton, SIGNAL(clicked()), SLOT(deleteSlot()));
    connect(ui->updateButton, SIGNAL(clicked()), SLOT(updateSlot()));
    connect(ui->addPicture_Button, SIGNAL(clicked()), SLOT(browsingImage()));
    connect(ui->selectCode_dateTable_button, SIGNAL(clicked()), SLOT(findCodeFromAttendant()));
    connect(ui->selectDate_dateTable_button, SIGNAL(clicked()), SLOT(selectByDate()));
    connect(ui->selectAll_Button, SIGNAL(clicked()), SLOT(selectDateSlot()));
    connect(ui->ExportButton, SIGNAL(clicked()), SLOT(ExportToFileSlot()));
    connect(ui->SearchName_Button, SIGNAL(clicked()), SLOT(searchNameSlot()));
    connect(ui->SearchFamily_Button, SIGNAL(clicked()), SLOT(searchFamilySlot()));
    connect(ui->FirstTime_Checkbox_Register, SIGNAL(pressed()), SLOT(generateCode()));
    connect(ui->docuExportButton, SIGNAL(pressed()), SLOT(ExportToDucoWikiFileSlot()));

    //  [Connect LineEdits to Slots]
    connect(ui->Code_Line, SIGNAL(returnPressed()), SLOT(findSlot()));
    connect(ui->Code_Line3_Selecttab, SIGNAL(returnPressed()), SLOT(findCodeFromAttendant()));
    connect(ui->Date_Line, SIGNAL(returnPressed()), SLOT(selectByDate()));
    connect(ui->Name_Line3_SearchTab, SIGNAL(returnPressed()), SLOT(searchNameSlot()));
    connect(ui->Family_Line3_SearchTab, SIGNAL(returnPressed()), SLOT(searchFamilySlot()));
    connect(ui->Name_Line3_SearchTab, SIGNAL(textChanged(QString)), SLOT(searchNameSlot()));
    connect(ui->Family_Line3_SearchTab, SIGNAL(textChanged(QString)), SLOT(searchFamilySlot()));

    // [ Connect actions to Slots]
    connect(ui->actionE_xit, SIGNAL(triggered()), this ,SLOT(close()));
    connect(ui->action_Connect, SIGNAL(triggered()), this ,SLOT(databaseConnectSlot()));
    connect(ui->actionExport_Today, SIGNAL(triggered()), this , SLOT(ExportToFileTodaySlot()));
    connect(ui->action_DucoWiki_Export_Today, SIGNAL(triggered()), this, SLOT(ExportToDucoWikiFileTodaySlot()));

    if(!databaseConnect())
    {
        QMessageBox::critical(0, "Error to Connect", "ERROR!!! Conection Failed");
        ui->db_status->setText("Connect to Database Failed.");
    }
    else
        ui->db_status->setText("Connect to database Successful.");

    ui->Code_Line->setFocus();
}

MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}

//Connect To Database Function
//*******************
bool MainWindow::databaseConnect()
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

    query.exec("SELECT firstname, lastname, sessionCounter, email FROM person WHERE Code == "+ ui->Code_Line->text());
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
        ui->Email_Line->setText("");

        while(query.next())
        {
            QString name = query.value(0).toString();
            QString family = query.value(1).toString();
            int sessionCounter = query.value(2).toInt();
            QString email = query.value(3).toString();
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
            ui->Email_Line->setText(email);
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
    QString AddEmail = ui->Email_Line2_Register->text();

    //check fileds is empty make error
    if(AddCode==0 || AddName=="" || AddFamily=="") return false;

    //clear the field for next user
    ui->Name_Line2_Registertab->setText("");
    ui->Family_Line2_Registertab->setText("");
    ui->Email_Line2_Register->setText("");

    //find the person in database
    query.prepare("INSERT INTO person (Code, firstname, lastname, email) "
                      "VALUES (:Code, :firstname, :lastname, :email)");
        query.bindValue(":Code", AddCode);
        query.bindValue(":firstname", AddName);
        query.bindValue(":lastname", AddFamily);
        query.bindValue(":email", AddEmail);
        query.exec();

    //show persion data in tableview
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
    //make error is code field is empty
    if(ui->Code_Line->text().isEmpty()) return false;

    //delete person data from 2 table if database
    QSqlQuery query;
    query.exec("DELETE FROM person WHERE Code ==" + ui->Code_Line->text());
    query.exec("DELETE FROM attendant WHERE Code ==" + ui->Code_Line->text());

    //show table
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
    QSqlQuery query2;
    int Code = 0;
    Code = ui->Code_Line->text().toInt();
    QString Name = ui->Name_Line->text();
    QString Family = ui->Family_Line->text();
    QString Email = ui->Email_Line->text();

    //make error is code, name, family empty
    if(Code==0 || Name=="" || Family=="") return false;

    //update 2 table data
    query.prepare("UPDATE person SET firstname = :firstname, lastname = :lastname, email = :email WHERE Code == :Code ");
        query.bindValue(":firstname", Name);
        query.bindValue(":lastname", Family);
        query.bindValue(":Code", Code);
        query.bindValue(":email", Email);
        query.exec();
    query2.prepare("UPDATE attendant SET firstname = :firstname, lastname = :lastname, email = :email WHERE Code == :Code ");
        query2.bindValue(":firstname", Name);
        query2.bindValue(":lastname", Family);
        query2.bindValue(":Code", Code);
        query2.bindValue(":email", Email);
        query2.exec();

    //show person image
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
    if(!(db_export.openFile("Export/" + dateExport + ".txt"))) return false;

    query.exec("SELECT firstname, lastname FROM attendant WHERE Date == \""+ dateExport + "\"");
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
        if(!(db_export.openFile("Export/DucoWiki " + dateExport + ".txt"))) return false;

        query.exec("SELECT Code, firstname, lastname FROM attendant WHERE Date == \""+ dateExport + "\"");
        while(query.next())
        {
            int code = query.value(0).toInt();
            QString name = query.value(1).toString();
            QString family = query.value(2).toString();

            //save to ducowiki text file
            db_export.docuExport(code, name, family);
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

//this function for searching family in database and show to table in search tab
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
void MainWindow::databaseConnectSlot()
{
    if(!databaseConnect())
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

//this function for searching and show on table by Date in Select tab
//********************
void MainWindow::selectByDate()
{
    QString str("\"" + ui->Date_Line->text() + "\"");
    filterView("attendant", "Date", str, *ui->Table_view_5);
    ui->statusBar->showMessage("Data Selected!",3000);
}

//this Slot for Add Image
//************************
void MainWindow::browsingImage()
{
    if(ui->Code_Line2_Registertab->text()=="")
    {
        QMessageBox::information(this,"Empty Code Line Edit.", "Enter Code First Please.");
        return;
    }
    QStringList mimeTypeFilters;
    foreach (const QByteArray &mimeTypeName, QImageReader::supportedMimeTypes())
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QFileDialog dialog(this, tr("Open File"),
                       picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.first());
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");

    while (dialog.exec() == QDialog::Accepted && !BrowsingImage(dialog.selectedFiles().first())) {}
    ui->statusBar->showMessage("Image Added!",3000);
}

//this slot for use exportToTextFile function and alarm for success or not
//************************
void MainWindow::ExportToFileSlot()
{
    QString str("\"" + ui->Date_Line->text() + "\"");
    if(!(exportToTextFile(str)))
        QMessageBox::critical(0,"Error Open File", "Open File Failed.");
    else
        QMessageBox::information(0,"Export File Saved!", "Export File Saved!");
}

void MainWindow::ExportToFileTodaySlot()
{
    QString str("\"" + curentDate_Str + "\"");
    if(!(exportToTextFileToday(str)))
        QMessageBox::critical(0,"Error Open File", "Open File Failed.");
    else
        QMessageBox::information(0,"Export File Saved!", "Export File Saved!");
}

void MainWindow::ExportToDucoWikiFileTodaySlot()
{
    if(!(exportToDucoWikiFileToday(curentDate_Str)))
        QMessageBox::critical(0,"Error Open File", "Open File Failed.");
    else
        QMessageBox::information(0,"Export File Saved!", "Export File Saved!");
}

void MainWindow::ExportToDucoWikiFileSlot()
{
    if(!(exportToDucoWikiFileToday(ui->Date_Line->text())))
        QMessageBox::critical(0,"Error Open File", "Open File Failed.");
    else
        QMessageBox::information(0,"Export File Saved!", "Export File Saved!");
}

//yhis Slot for use searchName Function
//*************************
void MainWindow::searchNameSlot()
{
    searchName();
}

//this Slot for use searchfamily Function
//************************
void MainWindow::searchFamilySlot()
{
    searchFamily();
}

void MainWindow::generateCode()
{
    ui->Code_Line2_Registertab->setText("100");
}






