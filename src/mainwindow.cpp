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

#include "src/database_export.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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

    //inputMask of line edit Config
    std::unique_ptr<QValidator> v = std::make_unique<QIntValidator>(0, 9999999999, this); //the input code from mage page can be between these numbers
    ui->Code_Line->setValidator(v);
    ui->Code_Line2_Registertab->setValidator(v);
    ui->Code_Line3_Selecttab->setValidator(v);
    ui->codeLine_VoteTab->setValidator(v);
    ui->Date_Line->setInputMask("0000-00-00;_");

    //default set
    ui->Date_Line->setText(curentDate_Str);



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
    connect(ui->ExportButton, SIGNAL(clicked()), SLOT(on_export_button_clicked()));
    connect(ui->SearchName_Button, SIGNAL(clicked()), SLOT(searchNameSlot()));
    connect(ui->SearchFamily_Button, SIGNAL(clicked()), SLOT(searchFamilySlot()));
    connect(ui->FirstTime_Checkbox_Register, SIGNAL(pressed()), SLOT(generateCode()));
    connect(ui->docuExportButton, SIGNAL(pressed()), SLOT(on_docu_export_button_clicked()));
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
    connect(ui->actionExport_Today, SIGNAL(triggered()), this , SLOT(on_export_today_action_triggered()));
    connect(ui->action_DucoWiki_Export_Today, SIGNAL(triggered()), this, SLOT(on_ducoWiki_export_action_triggered()));

    databaseConnectSlot();
    ui->Code_Line->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    model->setFilter(Column + " = " + RecordFilter);
    tableview.setModel(model);
    tableview.setWindowTitle(table);
    tableview.resizeColumnsToContents();
    tableview.resizeRowsToContents();
}

//this Slot for Connect to Database by Click the Connect button
//******************
void MainWindow::databaseConnectSlot()
{
    if(!m_iLAController.openDatabase())
    {
        QMessageBox::critical(0, tr("Error to Connect"), tr("ERROR!!! Conection Failed"));
        ui->db_status->setText(tr("Connect to Database Failed."));
    }
    else
    {
        ui->db_status->setText(tr("Connect to database Successful."));
        ViewTable("person", *ui->Table_view);
        ui->statusBar->showMessage(tr("Database Connected!"),3000);
        ui->Code_Line->setFocus();
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
    QString  code = ui->Code_Line->text();
    //call the method and get the data
    Person person = m_iLAController.findPersonByCode(code);

    //set data for Ui
    ui->Name_Line->setText(person.getFirstName());
    ui->Family_Line->setText(person.getLastName());
    ui->Email_Line->setText(person.getEmail());

    //TODO : manage photo outside of the Controller
    if(!loadImage("Image/" + code +".jpg"))
        loadImage(":/pic/build/Image/empty.jpg");

    //TODO : change View Table System
    filterView("person","Code", code, *ui->Table_view);
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
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("Select firstName, lastName, date "
                    "FROM person, attendant, dueDay "
                    "WHERE person.id = attendant.personId "
                    "AND dueDay.id = attendant.dateId;");
    qDebug() << model->lastError().text();
    ui->Table_view_5->setModel(model);
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
    QString code = ui->Code_Line3_Selecttab->text();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("Select firstName, lastName, date "
                    "FROM person, attendant, dueDay "
                    "WHERE person.id = attendant.personId "
                    "AND dueDay.id = attendant.dateId "
                    "AND person.code = " + code + ";");
    ui->Table_view_5->setModel(model);
    ui->Code_Line3_Selecttab->selectAll();
    ui->Code_Line3_Selecttab->setFocus();
}

//this function for searching and show on table by Date in Select tab
//********************
void MainWindow::selectByDate()
{
    QString date = ui->Date_Line->text();
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("Select firstName, lastName, date "
                    "FROM person, attendant, dueDay "
                    "WHERE person.id = attendant.personId "
                    "AND dueDay.id = attendant.dateId "
                    "AND dueDay.date = '" + date + "';");
    ui->Table_view_5->setModel(model);
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
void MainWindow::on_export_button_clicked()
{
    if(!(m_iLAController.exportToTextByDate(ui->Date_Line->text())))
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

void MainWindow::on_docu_export_button_clicked()
{
    if(!(m_iLAController.exportToTextByDate(ui->Date_Line->text(), true)))
        QMessageBox::critical(0, tr("Error Open File"), tr("Open File Failed."));
    else
        QMessageBox::information(0, tr("Export File Saved!"), tr("Export File Saved!"));
}

//yhis Slot for use searchName Function
//*************************
void MainWindow::searchNameSlot()
{
    static QSqlTableModel *model = new QSqlTableModel(this);
    m_iLAController.searchPersonByFirstName(ui->Name_Line3_SearchTab->text(), model);
    ui->Table_view_SearchTab->setModel(model);
    ui->Table_view_SearchTab->resizeColumnsToContents();
    ui->Table_view_SearchTab->resizeRowsToContents();
}

//this Slot for use searchfamily Function
//************************
void MainWindow::searchFamilySlot()
{
    static QSqlTableModel *model = new QSqlTableModel(this);
    m_iLAController.searchPersonByLastName(ui->Family_Line3_SearchTab->text(), model);
    ui->Table_view_SearchTab->setModel(model);
    ui->Table_view_SearchTab->resizeColumnsToContents();
    ui->Table_view_SearchTab->resizeRowsToContents();
}

void MainWindow::generateCode()
{
    ui->Code_Line2_Registertab->setText("100");
}

void MainWindow::reportForVoteSlot()
{
    ui->codeLine_VoteTab->selectAll();     //select all Code in Code Line in Report Tab

    if(ui->codeLine_VoteTab->text().isEmpty())
    {
        QMessageBox::critical(0, tr("Enter Code"), tr("Please First type Code \n Type Code First."));
        ui->codeLine_VoteTab->setFocus();
    }
    else
    {
        static QSqlQueryModel *model = new QSqlQueryModel(this);
        QString code = ui->codeLine_VoteTab->text();
        if(m_iLAController.countForElection(code, model))
        {
            voteImage(":/pic/build/Image/true.jpg");
        }
        else
        {
            voteImage(":/pic/build/Image/false.jpg");
        }
        model->setQuery("Select firstName, lastName, date "
                        "FROM person, attendant, dueDay "
                        "WHERE person.id = attendant.personId "
                        "AND dueDay.id = attendant.dateId "
                        "AND person.code = " + code + ";");
        ui->Table_view_VoteTab->setModel(model);
        ui->codeLine_VoteTab->setFocus();
        ui->codeLine_VoteTab->selectAll();
    }
}






