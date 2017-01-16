#include "src/mainwindow.h"
#include "src/ui_mainwindow.h"
#include "src/database_export.h"

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
    loadImage(":/pic/build/Image/empty.jpg");
    BrowsingImage(":/pic/build/Image/empty.jpg");
    voteImage(":/pic/build/Image/question.jpg");


    // [Conncet buttons to Slots]
    connect(ui->SearchButton, SIGNAL(clicked()), SLOT(on_search_button_clicked()));
    connect(ui->AddButton_Registertab, SIGNAL(clicked()), SLOT(on_add_button_registerTab_clicked()));
    connect(ui->SelectButton, SIGNAL(clicked()), SLOT(on_select_button_clicked()));
    connect(ui->deleteButton, SIGNAL(clicked()), SLOT(on_delete_button_clicked()));
    connect(ui->updateButton, SIGNAL(clicked()), SLOT(on_update_button_clicked()));
    connect(ui->addPicture_Button, SIGNAL(clicked()), SLOT(browsingImage()));
    connect(ui->selectCode_dateTable_button, SIGNAL(clicked()), SLOT(findCodeFromAttendant()));
    connect(ui->selectDate_dateTable_button, SIGNAL(clicked()), SLOT(selectByDate()));
    connect(ui->selectAll_Button, SIGNAL(clicked()), SLOT(selectDateSlot()));
    connect(ui->ExportButton, SIGNAL(clicked()), SLOT(ExportToFileSlot()));
    connect(ui->SearchName_Button, SIGNAL(clicked()), SLOT(searchNameSlot()));
    connect(ui->SearchFamily_Button, SIGNAL(clicked()), SLOT(searchFamilySlot()));
    connect(ui->FirstTime_Checkbox_Register, SIGNAL(pressed()), SLOT(generateCode()));
    connect(ui->docuExportButton, SIGNAL(pressed()), SLOT(ExportToDucoWikiFileSlot()));
    //connect(ui->report_btn, SIGNAL(pressed()), SLOT(reportButton()));
    connect(ui->Ok_Button_VoteTab, SIGNAL(pressed()), SLOT(reportForVoteSlot()));

    //  [Connect LineEdits to Slots]
    connect(ui->Code_Line, SIGNAL(returnPressed()), SLOT(on_search_button_clicked()));
    connect(ui->Code_Line3_Selecttab, SIGNAL(returnPressed()), SLOT(findCodeFromAttendant()));
    connect(ui->Date_Line, SIGNAL(returnPressed()), SLOT(selectByDate()));
    connect(ui->Name_Line3_SearchTab, SIGNAL(returnPressed()), SLOT(searchNameSlot()));
    connect(ui->Family_Line3_SearchTab, SIGNAL(returnPressed()), SLOT(searchFamilySlot()));
    connect(ui->Name_Line3_SearchTab, SIGNAL(textChanged(QString)), SLOT(searchNameSlot()));
    connect(ui->Family_Line3_SearchTab, SIGNAL(textChanged(QString)), SLOT(searchFamilySlot()));
    connect(ui->codeLine_VoteTab, SIGNAL(returnPressed()), SLOT(reportForVoteSlot()));

    // [ Connect actions to Slots]
    connect(ui->actionE_xit, SIGNAL(triggered()), this ,SLOT(close()));
    connect(ui->action_Connect, SIGNAL(triggered()), this ,SLOT(databaseConnectSlot()));
    connect(ui->actionExport_Today, SIGNAL(triggered()), this , SLOT(ExportToFileTodaySlot()));
    connect(ui->action_DucoWiki_Export_Today, SIGNAL(triggered()), this, SLOT(ExportToDucoWikiFileTodaySlot()));


    databaseConnect();
    ui->Code_Line->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connect To Database Function
//*******************
bool MainWindow::databaseConnect()
{
    if (!m_db.open()) {
        QMessageBox::critical(0, tr("Cannot open database"),
                              tr("Unable to establish a database connection.\n"), QMessageBox::Cancel);
        ui->db_status->setText(tr("Connect to Database Failed."));
        return false;
    }
    ViewTable("person", *ui->Table_view);
    ui->statusBar->showMessage(tr("Database Connected!"),3000);
    ui->Code_Line->setFocus();
    return true;
}

//this Function for load Image and show in Register tab
//***********************
//TODO : change show Picture system
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
    if(!(db_export.openFile("Export/" + ui->Date_Line->text() + ".txt"))) return false;

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
    QString name = QString("'%" + ui->Name_Line3_SearchTab->text() + "%'");
    QString filter = QString("firstName LIKE "+ name);

    QSqlTableModel *model = new QSqlTableModel(this);
    m_personModel.setModel(model);
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
    QString family = QString("'%"+ui->Family_Line3_SearchTab->text()+"%'");
    QString filter = QString("lastname LIKE "+ family);

    QSqlTableModel *model = new QSqlTableModel(this);
    m_personModel.setModel(model);
    model->setFilter(filter);
    ui->Table_view_SearchTab->setModel(model);
    ui->Table_view_SearchTab->resizeColumnsToContents();
    ui->Table_view_SearchTab->resizeRowsToContents();
    return true;
}

bool MainWindow::reportforVote()
{
    ui->codeLine_VoteTab->selectAll();     //select all Code in Code Line in Report Tab

    if(ui->codeLine_VoteTab->text().isEmpty())
    {
        QMessageBox::critical(0, tr("Enter Code"), tr("Please First type Code \n Type Code First."));
        ui->codeLine_VoteTab->setFocus();
        return 1;
    }

    QString code;
    int count = 0;
    code = ui->codeLine_VoteTab->text();

    QSqlQuery query;    //query
    QSqlQuery query2;   //query
    QString date;
    query.exec("SELECT Date FROM dueDay ORDER BY date(Date) DESC Limit 15");
    while(query.next())
    {
        date = query.value(0).toString();
    }
    query2.exec("SELECT firstname, lastname FROM attendant WHERE Code = " + code + " AND date(Date) >= \"" + date + "\"");
    while(query2.next())
    {
        count++;
    }
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query2);

    if(count >= 15)
    {
        voteImage(":/pic/build/Image/true.jpg");
    }
    else
    {
        voteImage(":/pic/build/Image/false.jpg");
    }

    ui->Table_view_VoteTab->setModel(model);
    ui->codeLine_VoteTab->setFocus();
    ui->codeLine_VoteTab->selectAll();
    return 0;
}

bool MainWindow::voteImage(const QString &fileName)
{
    QSize size;
    size.setHeight(150);
    size.setWidth(150);
    QImage image(fileName);
    if (image.isNull()) return false;
    image = image.scaled(size, Qt::KeepAspectRatio);
    ui->ImageLabel_Votetab->setPixmap(QPixmap::fromImage(image));
    ui->ImageLabel_Votetab->setFixedSize(size);
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

    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable(table);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    tableview.setModel(model);
    tableview.setWindowTitle(table);
    tableview.resizeColumnsToContents();
    tableview.resizeRowsToContents();

    ui->statusBar->showMessage(tr("Data Selected!"), 3000);
}

//this Function for viewed by rule
//********************
void MainWindow::filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview)
{
    QSqlTableModel *model = new QSqlTableModel(this);
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
        QMessageBox::critical(0, tr("Error to Connect"), tr("ERROR!!! Conection Failed"));
        ui->db_status->setText(tr("Connect to Database Failed."));
    }
    else
    {
        ui->db_status->setText(tr("Connect to database Successful."));
    }
}

//this Slot for Select Data From Database by Click the Search Button or Enter in Code text line
//*****************
void MainWindow::on_search_button_clicked()
{
    ui->Code_Line->selectAll();     //select all Code in Code Line
    ui->Name_Line->setText("");
    ui->Family_Line->setText("");
    ui->Email_Line->setText("");

    if(ui->Code_Line->text().isEmpty()) //if there is no code on the code line
    {
        QMessageBox::critical(0, tr("Enter Code"), tr("Please First type Code \n Type Code First"));
        ui->Code_Line->setFocus();
    }
    //call the method and get the data
    Person person = m_iLAController.findPersonByCode(ui->Code_Line->text());

    //set data for Ui
    ui->Name_Line->setText(person.firstName());
    ui->Family_Line->setText(person.lastName());
    ui->Email_Line->setText(person.email());

    //TODO : manage photo outside of the Controller
    if(!loadImage("Image/" + ui->Code_Line->text() +".jpg"))
        loadImage(":/pic/build/Image/empty.jpg");

    //TODO : change View Table System
    filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);
    ui->Code_Line->setFocus();
}

//this Slot for add Data to Databade by Click to Add Button
//*****************
void MainWindow::on_add_button_registerTab_clicked()
{
    Person person;
    person.setCode(ui->Code_Line2_Registertab->text());
    person.setFirstName(ui->Name_Line2_Registertab->text());
    person.setLastName(ui->Family_Line2_Registertab->text());
    person.setEmail(ui->Email_Line2_Register->text());

    if(!m_iLAController.addPerson(person))
    {
        QMessageBox::critical(0, tr("Error to add data"), tr("ERROR!!! add Data Failed"));
    }
    else
    {
        //TODO : change View Table System
        //show persion data in tableview
        filterView("person","Code", ui->Code_Line2_Registertab->text(), *ui->Table_view_2);
        ui->db_status->setText(tr("Data Added to Database"));
    }

    //clear the field for next user
    ui->Name_Line2_Registertab->setText("");
    ui->Family_Line2_Registertab->setText("");
    ui->Email_Line2_Register->setText("");

    ui->statusBar->showMessage("Data Added!",3000);
    ui->Code_Line2_Registertab->selectAll();  //select all Code in Code Line
    ui->Code_Line2_Registertab->setFocus();
}

//this Slot for delete Data from Databade by Click to Delete Button
//*****************
void MainWindow::on_delete_button_clicked()
{
    if(!m_iLAController.deletePerson(ui->Code_Line->text()))
    {
        QMessageBox::critical(0, tr("Error to Delete data"), tr("ERROR!!! Delete Data Failed"));
    }
    else
    {
        //show table
        //TODO : change the view System
        filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);

        ui->Name_Line->setText("");
        ui->Family_Line->setText("");
        ui->Email_Line->setText("");
        ui->db_status->setText(tr("Data Deleted!"));
        ui->statusBar->showMessage(tr("Data Deleted!"), 3000);
    }

    ui->Code_Line->selectAll();  //select all Code in Code Line
    ui->Code_Line->setFocus();
}

//this Slot for select Data from Databade by Click to Select Button
//*****************
void MainWindow::on_select_button_clicked()
{
    ViewTable("person", *ui->Table_view);
    ui->db_status->setText(tr("Data Selected!"));
    ui->Code_Line->selectAll();
    ui->Code_Line->setFocus();
}

//this Slot for Select Data From attendant Table
//**********************
void MainWindow::selectDateSlot()
{
    ViewTable("attendant", *ui->Table_view_5);
    ui->db_status->setText(tr("Data Selected!"));
}

//this Slot for update Data to Databade by Click to Update Button
//*****************
void MainWindow::on_update_button_clicked()
{
    Person person;
    person.setCode(ui->Code_Line->text());
    person.setFirstName(ui->Name_Line->text());
    person.setLastName(ui->Family_Line->text());
    person.setEmail(ui->Email_Line->text());
    if(!m_iLAController.updatePerson(person))
    {
        QMessageBox::critical(0, tr("Error to Update data"), tr("ERROR!!! Update Data Failed"));
    }
    else
    {
        ui->db_status->setText(tr("Data Updated!"));
        //show person image
        //TODO : change show Picture system
        loadImage("Image/" + ui->Code_Line->text() +".jpg");

        //TODO : change view system
        filterView("person","Code", ui->Code_Line->text(), *ui->Table_view);
    }

    ui->statusBar->showMessage(tr("Data Updated!"), 3000);
    ui->Code_Line->selectAll();  //select all Code in Code Line
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
    ui->statusBar->showMessage(tr("Data Selected!"), 3000);
}

//this Slot for Add Image
//************************
void MainWindow::browsingImage()
{
    if(ui->Code_Line2_Registertab->text()=="")
    {
        QMessageBox::information(this,tr("Empty Code Line Edit."), tr("Enter Code First Please."));
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
    ui->statusBar->showMessage(tr("Image Added!"), 3000);
}

//this slot for use exportToTextFile function and alarm for success or not
//************************
void MainWindow::ExportToFileSlot()
{
    QString str("\"" + ui->Date_Line->text() + "\"");
    if(!(exportToTextFile(str)))
        QMessageBox::critical(0,tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0,tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::ExportToFileTodaySlot()
{
    QString str("\"" + curentDate_Str + "\"");
    if(!(exportToTextFileToday(str)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::ExportToDucoWikiFileTodaySlot()
{
    if(!(exportToDucoWikiFileToday(curentDate_Str)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::ExportToDucoWikiFileSlot()
{
    if(!(exportToDucoWikiFileToday(ui->Date_Line->text())))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
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

void MainWindow::reportForVoteSlot()
{
    reportforVote();
}






