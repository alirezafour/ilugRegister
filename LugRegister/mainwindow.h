#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtWidgets>
#include <QtSql>
#include <QDate>
#include "logindialog.h"

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
    void reportForVoteSlot();
    
private:
    QSqlDatabase db;
    QDate curentDate;
    QString curentDate_Str;

public:
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
    bool voteImage(const QString &);
    bool reportforVote();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
