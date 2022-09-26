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
 
private:
    void ResetPersonTable(const QString& title, QTableView& tableview);
    void ResetExportTable(const QString& title, QTableView& tableview);
    void SetFilterOnPerson(const QString& column, const QString& filter);
    void SetFilterOnExport(const QString& column, const QString& filter);
    void SetFilterOnPersonStartWith(const QString& column, const QString& filterStart);
    bool LoadImage(const QString& path);
    bool BrowsingImage(const QString& path);
    bool VoteImage(const QString& path);

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
    Ui::MainWindow *ui;
};
