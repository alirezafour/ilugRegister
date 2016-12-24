#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<iostream>
using namespace std;

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtWidgets>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDate>
#include "logindialog.h"
#include "qtrpt.h"
#include "../src/model/duedaymodel.h"
#include "../src/model/personmodel.h"
#include "../src/model/attendantmodel.h"
#include "../src/database/mydatabase.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void databaseConnectSlot();
    void findSlot();
    void addDataSlot();
    void deleteSlot();
    void selectPersonSlot();
    void selectDateSlot();
    void updateSlot();
    void findCodeFromAttendant();
    void selectByDate();
    void browsingImage();
    void ExportToFileSlot();
    void ExportToFileTodaySlot();
    void ExportToDucoWikiFileTodaySlot();
    void ExportToDucoWikiFileSlot();
    void searchNameSlot();
    void searchFamilySlot();
    void generateCode();
    void login();
    void reportButton();
    void setValueReport(int recNo, QString paramName, QVariant &paramValue, int reportPage);
    void reportForVoteSlot();
    
private:
    MyDatabase m_db;
    AttendantModel m_attendantModel;
    PersonModel m_personModel;
    DueDayModel m_dueDayModel;

    QDate curentDate;
    QString curentDate_Str;

private:
    void ViewTable(QString table, QTableView &tableview);
    void filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview);
    bool databaseConnect(); //database Connection Function
    bool FindCode();       //Select data From Data base (Find Code)
    bool AddData();          //Add data To database
    bool DeleteData();
    bool UpdateData();
    bool loadImage(const QString &);
    bool BrowsingImage(const QString &);
    bool exportToTextFile(QString dateExport);
    bool exportToTextFileToday(QString dateExport);
    bool exportToDucoWikiFileToday(QString dataExport);
    bool searchName();
    bool searchFamily();
    bool reportforVote();
    bool voteImage(const QString &);


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
