#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtWidgets>
#include <QtSql>
#include <QDate>

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
    void ConnectionSlot();
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
    void searchNameSlot();
    void searchFamilySlot();
    
private:
    QSqlDatabase db;
    QDate curentDate;
    QString curentDate_Str;

    void ViewTable(QString table, QTableView &tableview);
    void filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview);
    bool createConnection(); //database Connection Function
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

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
