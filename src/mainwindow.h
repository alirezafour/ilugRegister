#pragma once

#include <QMainWindow>
#include <QtWidgets>
#include <QDate>

#include "src/controllers/ilugapicontroller.h"

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
    void On_B_Search_Main_Clicked();
    void On_B_Add_Register_Clicked();
    void On_B_Delete_Main_Clicked();
    void On_B_ShowAll_Main_Clicked();
    void On_B_SelectAll_Export_Clicked();
    void On_B_Update_Main_Clicked();
    void On_B_SelectCodeByCode_Export_Clicked();
    void On_B_SelectByDate_Export_Clicked();
    void On_B_BrawsePicture_Clicked();
    void On_B_Export_Export_Clicked();
    void on_export_today_action_triggered();
    void on_ducoWiki_export_action_triggered();
    void On_B_DocuExport_Export_Pressed();
    void On_B_SearchName_Search_Clicked();
    void On_B_SearchFamily_Search_Clicked();
    void On_CB_FirstTime_Register_Pressed();
    void On_B_Ok_Vote_Pressed();
    
private:
    ILugApiController m_iLAController{};
    QDate curentDate;
    QString curentDate_Str;

private:
    void ViewTable(QString table, QTableView &tableview);
    void filterView(QString table, QString Column, QString RecordFilter, QTableView &tableview);
    void filterViewLike(QString table, QString Column, QString RecordFilter, QTableView &tableview);
    bool databaseConnect(); //database Connection Function
    bool loadImage(const QString &);
    bool BrowsingImage(const QString &);
    bool voteImage(const QString &);

    Ui::MainWindow *ui;
};
