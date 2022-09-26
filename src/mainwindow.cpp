/*
*   Copyright (C) 2014 Alireza Hor <alirezafour@gmail.com>
*
*   This program is free software; you can redistribute it and/or modify
*   it under the terms of the GNU General Public License version 3,
*   or (at your option) any later version, as published by the Free
*   Software Foundation
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details
*
*   You should have received a copy of the GNU General Public
*   License along with this program;
*/

#include "src/mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent) 
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  Title & Date Config
    setWindowTitle("Lug Register");
    curentDate = QDate::currentDate();
    curentDate_Str = curentDate.toString(Qt::ISODate);
    ui->todayDay_lbl->setText(curentDate_Str);
    ui->todayDay_lbl_SelectTab->setText(curentDate_Str);

    //  Picture User Config
    LoadImage("Image/empty.jpg");
    BrowsingImage("Image/empty.jpg");
    VoteImage("Image/question.jpg");

    //inputMask of line edit Config
    std::unique_ptr<const QValidator> v = std::make_unique<const QIntValidator>(0, 9999999999, this); //the input code from mage page can be between these numbers
    ui->Line_Code_Main->setValidator(v.get());
    ui->Line_Code_Register->setValidator(v.get());
    ui->Line_Code_Export->setValidator(v.get());
    ui->Line_Code_Vote->setValidator(v.get());
    ui->Line_Date_Export->setInputMask("0000-00-00;_");

    //default set
    ui->Line_Date_Export->setText(curentDate_Str);



    // [Connect buttons to Slots]
    // main tab
    connect(ui->B_Search_Main, SIGNAL(clicked()), SLOT(On_B_Search_Main_Clicked()));
    connect(ui->B_ShowAll_Main, SIGNAL(clicked()), SLOT(On_B_ShowAll_Main_Clicked()));
    connect(ui->B_Delete_Main, SIGNAL(clicked()), SLOT(On_B_Delete_Main_Clicked()));
    connect(ui->B_Update_Main, SIGNAL(clicked()), SLOT(On_B_Update_Main_Clicked()));
    // lines
    connect(ui->Line_Code_Main, SIGNAL(returnPressed()), SLOT(On_B_Search_Main_Clicked()));

    // register tab
    connect(ui->B_Add_Register, SIGNAL(clicked()), SLOT(On_B_Add_Register_Clicked()));
    connect(ui->B_BrowsePicture_Register, SIGNAL(clicked()), SLOT(On_B_BrawsePicture_Clicked()));
    connect(ui->CB_FirstTime_Register, SIGNAL(pressed()), SLOT(On_CB_FirstTime_Register_Pressed()));

    //export tab
    // Buttons
    connect(ui->B_SelectByCode_Export, SIGNAL(clicked()), SLOT(On_B_SelectCodeByCode_Export_Clicked()));
    connect(ui->B_SelectByDate_Export, SIGNAL(clicked()), SLOT(On_B_SelectByDate_Export_Clicked()));
    connect(ui->B_SelectAll_Export, SIGNAL(clicked()), SLOT(On_B_SelectAll_Export_Clicked()));
    connect(ui->B_Export_Export, SIGNAL(clicked()), SLOT(On_B_Export_Export_Clicked()));

    connect(ui->B_DocuExport_Export, SIGNAL(pressed()), SLOT(On_B_DocuExport_Export_Pressed()));
    // Line
	connect(ui->Line_Code_Export, SIGNAL(returnPressed()), SLOT(On_B_SelectCodeByCode_Export_Clicked()));
	connect(ui->Line_Date_Export, SIGNAL(returnPressed()), SLOT(On_B_SelectByDate_Export_Clicked()));

    // search tab
    connect(ui->B_SearchName_Search, SIGNAL(clicked()), SLOT(On_B_SearchName_Search_Clicked()));
    connect(ui->B_SearchFamily_Search, SIGNAL(clicked()), SLOT(On_B_SearchFamily_Search_Clicked()));
    // Line
	connect(ui->Line_Name_Search, SIGNAL(returnPressed()), SLOT(On_B_SearchName_Search_Clicked()));
	connect(ui->Line_Family_Search, SIGNAL(returnPressed()), SLOT(On_B_SearchFamily_Search_Clicked()));
	connect(ui->Line_Name_Search, SIGNAL(textChanged(QString)), SLOT(On_B_SearchName_Search_Clicked()));
	connect(ui->Line_Family_Search, SIGNAL(textChanged(QString)), SLOT(On_B_SearchFamily_Search_Clicked()));

    // vote tab
    connect(ui->B_Ok_Vote, SIGNAL(pressed()), SLOT(On_B_Ok_Vote_Pressed()));
    // Line
    connect(ui->Line_Code_Vote, SIGNAL(returnPressed()), SLOT(On_B_Ok_Vote_Pressed()));

    // Menu actions
    connect(ui->actionE_xit, SIGNAL(triggered()), this ,SLOT(close()));
    connect(ui->action_Connect, SIGNAL(triggered()), this ,SLOT(databaseConnectSlot()));
    connect(ui->actionExport_Today, SIGNAL(triggered()), this , SLOT(on_export_today_action_triggered()));
    connect(ui->action_DucoWiki_Export_Today, SIGNAL(triggered()), this, SLOT(on_ducoWiki_export_action_triggered()));

    databaseConnectSlot();

    ResetPersonTable("person", *ui->Table_View_Main);
    ResetPersonTable("person", *ui->Table_View_Register);
    ResetPersonTable("person", *ui->Table_view_SearchTab);
    ResetPersonTable("person", *ui->Table_view_VoteTab);

    ResetExportTable("export", *ui->Table_View_Export);

    ui->Line_Code_Main->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

    image.save("Image/" + ui->Line_Code_Register->text() +".jpg");
    return true;
}

bool MainWindow::VoteImage(const QString &fileName)
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

bool MainWindow::LoadImage(const QString &fileName)
{
    QSize size(150, 150);
    QImage image(fileName);
    if (image.isNull()) return false;
    image = image.scaled(size, Qt::KeepAspectRatio);
    ui->ImageLabel_Maintab->setPixmap(QPixmap::fromImage(image));
    ui->ImageLabel_Maintab->setFixedSize(size);
    return true;
}

void MainWindow::ResetPersonTable(const QString& title, QTableView &tableview)
{
    QSqlTableModel* personModel = m_iLAController.getPersonModel();
    personModel->select();
    personModel->setFilter("");
    tableview.setModel(personModel);
    tableview.setWindowTitle(title);
    tableview.resizeColumnsToContents();
    tableview.resizeRowsToContents();

    ui->statusBar->showMessage(tr("Data Selected!"), 3000);
}

void MainWindow::ResetExportTable(const QString& title, QTableView& tableview)
{
	QSqlTableModel* exportModel = m_iLAController.getExportModel();
    exportModel->setFilter("");
	tableview.setModel(exportModel);
	tableview.setWindowTitle(title);
	tableview.resizeColumnsToContents();
	tableview.resizeRowsToContents();

	ui->statusBar->showMessage(tr("Data Selected!"), 3000);
}

void MainWindow::SetFilterOnPerson(const QString& column, const QString& filter)
{
    m_iLAController.getPersonModel()->setFilter(QString(" %1 = '%2'").arg(column, filter));
    if(m_iLAController.getPersonModel()->lastError().isValid())
        QMessageBox::critical(0, tr("SQL Error"), m_iLAController.getPersonModel()->lastError().text());
}

void MainWindow::SetFilterOnExport(const QString& column, const QString& filter)
{
    m_iLAController.getExportModel()->setFilter(QString(" %1 = '%2'").arg(column, filter));
	if (m_iLAController.getExportModel()->lastError().isValid())
		QMessageBox::critical(0, tr("SQL Error"), m_iLAController.getExportModel()->lastError().text());
}

void MainWindow::SetFilterOnPersonStartWith(const QString& column, const QString& filter)
{
    m_iLAController.getPersonModel()->setFilter(QString(" %1 LIKE '%2'").arg(column, filter));
	if (m_iLAController.getPersonModel()->lastError().isValid())
		QMessageBox::critical(0, tr("SQL Error"), m_iLAController.getPersonModel()->lastError().text());
}

void MainWindow::databaseConnectSlot()
{
    if(!m_iLAController.openDatabase())
    {
        QMessageBox::critical(0, tr("Error to Connect"), tr("ERROR!!! Connection Failed"));
        ui->db_status->setText(tr("Connect to Database Failed."));
    }
    else
    {
        ui->db_status->setText(tr("Connect to database Successful."));
        ResetPersonTable("person", *ui->Table_View_Main);
        ui->statusBar->showMessage(tr("Database Connected!"),3000);
        ui->Line_Code_Main->setFocus();
    }
}

void MainWindow::On_B_Search_Main_Clicked()
{
    ui->Line_Code_Main->selectAll();
    ui->Line_Name_Main->setText("");
    ui->Line_Family_Main->setText("");
    ui->Line_Email_Main->setText("");

    if(ui->Line_Code_Main->text().isEmpty()) //if there is no code on the code line
    {
        QMessageBox::critical(0, tr("Enter Code"), tr("Please First type Code \n Type Code First"));
        ui->Line_Code_Main->setFocus();
    }

    Person person = m_iLAController.findPersonByCode(ui->Line_Code_Main->text());

    ui->Line_Name_Main->setText(person.getFirstName());
    ui->Line_Family_Main->setText(person.getLastName());
    ui->Line_Email_Main->setText(person.getEmail());

    if(!LoadImage("Image/" + ui->Line_Code_Main->text() +".jpg"))
        LoadImage(":/pic/build/Image/empty.jpg");

    SetFilterOnPerson("Code", ui->Line_Code_Main->text());
    ui->Line_Code_Main->setFocus();
}

void MainWindow::On_B_Add_Register_Clicked()
{
    Person person;
    person.setCode(ui->Line_Code_Register->text());
    person.setFirstName(ui->Line_Name_Register->text());
    person.setLastName(ui->Line_Family_Register->text());
    person.setEmail(ui->Line_Email_Register->text());

    if(!m_iLAController.addPerson(person))
    {
        QMessageBox::critical(0, tr("Error to add data"), tr("ERROR!!! add Data Failed"));
    }
    else
    {
        SetFilterOnPerson("Code", ui->Line_Code_Register->text());
        ui->db_status->setText(tr("Data Added to Database"));
    }

    //clear the field for next user
    ui->Line_Name_Register->setText("");
    ui->Line_Family_Register->setText("");
    ui->Line_Email_Register->setText("");

    ui->statusBar->showMessage("Data Added!",3000);
    ui->Line_Code_Register->selectAll();  //select all Code in Code Line
    ui->Line_Code_Register->setFocus();
}

void MainWindow::On_B_Delete_Main_Clicked()
{
    if(!m_iLAController.deletePerson(ui->Line_Code_Main->text()))
    {
        QMessageBox::critical(0, tr("Error to Delete data"), tr("ERROR!!! Delete Data Failed"));
    }
    else
    {
        SetFilterOnPerson("person","Code");

        ui->Line_Name_Main->setText("");
        ui->Line_Family_Main->setText("");
        ui->Line_Email_Main->setText("");
        ui->db_status->setText(tr("Data Deleted!"));
        ui->statusBar->showMessage(tr("Data Deleted!"), 3000);
    }

    ui->Line_Code_Main->selectAll();  //select all Code in Code Line
    ui->Line_Code_Main->setFocus();
}

void MainWindow::On_B_ShowAll_Main_Clicked()
{
    ResetPersonTable("person", *ui->Table_View_Main);
    ui->db_status->setText(tr("Data Selected!"));
    ui->Line_Code_Main->selectAll();
    ui->Line_Code_Main->setFocus();
}

void MainWindow::On_B_SelectAll_Export_Clicked()
{
    ResetExportTable("export", *ui->Table_View_Export);
    ui->db_status->setText(tr("Data Selected!"));
}

void MainWindow::On_B_Update_Main_Clicked()
{
    Person person;
    person.setCode(ui->Line_Code_Main->text());
    person.setFirstName(ui->Line_Name_Main->text());
    person.setLastName(ui->Line_Family_Main->text());
    person.setEmail(ui->Line_Email_Main->text());
    if(!m_iLAController.updatePerson(person))
    {
        QMessageBox::critical(0, tr("Error to Update data"), tr("ERROR!!! Update Data Failed"));
    }
    else
    {
        ui->db_status->setText(tr("Data Updated!"));
        //show person image
        //TODO : change show Picture system
        LoadImage("Image/" + ui->Line_Code_Main->text() +".jpg");

        //TODO : change view system
        SetFilterOnPerson("Code", ui->Line_Code_Main->text());
    }

    ui->statusBar->showMessage(tr("Data Updated!"), 3000);
    ui->Line_Code_Main->selectAll();  //select all Code in Code Line
    ui->Line_Code_Main->setFocus();
}

void MainWindow::On_B_SelectCodeByCode_Export_Clicked()
{
    SetFilterOnExport("Code", ui->Line_Code_Export->text());
    ui->Line_Code_Export->selectAll();
    ui->Line_Code_Export->setFocus();
}

//this function for searching and show on table by Date in Select tab
//********************
void MainWindow::On_B_SelectByDate_Export_Clicked()
{
    SetFilterOnExport("day", ui->Line_Date_Export->text());
    ui->statusBar->showMessage(tr("Data Selected!"), 3000);
}

//this Slot for Add Image
//************************
void MainWindow::On_B_BrawsePicture_Clicked()
{
    if(ui->Line_Code_Register->text()=="")
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

void MainWindow::On_B_Export_Export_Clicked()
{
    if(!(m_iLAController.exportToTextByDate(ui->Line_Date_Export->text())))
        QMessageBox::critical(0,tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0,tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::on_export_today_action_triggered()
{
    if(!(m_iLAController.exportToTextByDate(curentDate_Str)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::on_ducoWiki_export_action_triggered()
{
    if(!(m_iLAController.exportToTextByDate(curentDate_Str, true)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::On_B_DocuExport_Export_Pressed()
{
    if(!(m_iLAController.exportToTextByDate(ui->Line_Date_Export->text(), true)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

void MainWindow::On_B_SearchName_Search_Clicked()
{
    QString name = ui->Line_Name_Search->text();
    name += "%";
	SetFilterOnPersonStartWith("firstName", name);
}

void MainWindow::On_B_SearchFamily_Search_Clicked()
{
	QString lastname = ui->Line_Family_Search->text();
    lastname += "%";
    SetFilterOnPersonStartWith("lastName", lastname);
}

void MainWindow::On_CB_FirstTime_Register_Pressed()
{
    ui->Line_Code_Register->setText("100");
}

void MainWindow::On_B_Ok_Vote_Pressed()
{
    ui->Line_Code_Vote->selectAll();     //select all Code in Code Line in Report Tab

    if(ui->Line_Code_Vote->text().isEmpty())
    {
        QMessageBox::critical(0, tr("Enter Code"), tr("Please First type Code \n Type Code First."));
        ui->Line_Code_Vote->setFocus();
    }
    else
    {
        QString code = ui->Line_Code_Vote->text();
        if(m_iLAController.countForElection(code))
        {
            VoteImage(":/pic/build/Image/true.jpg");
        }
        else
        {
            VoteImage(":/pic/build/Image/false.jpg");
        }

        SetFilterOnPerson( "Code", code);
        ui->Line_Code_Vote->setFocus();
        ui->Line_Code_Vote->selectAll();
    }
}






