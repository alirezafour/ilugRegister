#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QtWidgets>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QDate>
#include "../src/model/duedaymodel.h"
#include "../src/model/personmodel.h"
#include "../src/model/attendantmodel.h"
#include "../src/database/mydatabase.h"

#include "src/controllers/ilugapicontroller.h"
#include "src/model/person.h"

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
    void on_search_button_clicked();
    void on_add_button_registerTab_clicked();
    void on_delete_button_clicked();
    void on_select_button_clicked();
    void selectDateSlot();
    void on_update_button_clicked();
    void findCodeFromAttendant();
    void selectByDate();
    void browsingImage();
    void on_export_button_clicked();
    void on_export_today_action_triggered();
    void on_ducoWiki_export_action_triggered();
    void on_docu_export_button_clicked();
    void searchNameSlot();
    void searchFamilySlot();
    void generateCode();
    void reportForVoteSlot();
    
private:
    MyDatabase m_db;
    AttendantModel m_attendantModel;
    PersonModel m_personModel;
    DueDayModel m_dueDayModel;
    QSqlTableModel *searchModel;
    ILugApiController m_iLAController;
    QDate curentDate;
    QString curentDate_Str;

private:
    void ViewTable(QString table, QTableView &tableview);
    void filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview);
    bool databaseConnect(); //database Connection Function
    bool loadImage(const QString &);
    bool BrowsingImage(const QString &);
    bool reportforVote();
    bool voteImage(const QString &);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
