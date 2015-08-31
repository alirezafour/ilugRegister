/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Connect;
    QAction *actionE_xit;
    QAction *action_Aboat;
    QAction *actionExport_Today;
    QAction *action_DucoWiki_Export_Today;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *baseTabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QFormLayout *formLayout;
    QLabel *Code_Label;
    QLabel *Name_Label;
    QLineEdit *Name_Line;
    QLabel *Family_Label;
    QLineEdit *Family_Line;
    QLineEdit *Code_Line;
    QLabel *Email_Label;
    QLineEdit *Email_Line;
    QSpacerItem *horizontalSpacer;
    QLabel *ImageLabel_Maintab;
    QVBoxLayout *verticalLayout;
    QLabel *todayDay_lbl;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *db_status;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *deleteButton;
    QPushButton *updateButton;
    QPushButton *SelectButton;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *SearchButton;
    QFrame *line_2;
    QTableView *Table_view;
    QWidget *tab_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_6;
    QFormLayout *formLayout_2;
    QLabel *Code_Label2;
    QLineEdit *Code_Line2_Registertab;
    QLabel *Name_Label2;
    QLineEdit *Name_Line2_Registertab;
    QLabel *Family_Label2;
    QLineEdit *Family_Line2_Registertab;
    QLineEdit *Email_Line2_Register;
    QLabel *Email_Label2;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *FirstTime_Checkbox_Register;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *AddButton_Registertab;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *addPicture_Button;
    QLabel *imageLabel_RegisterTab;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_7;
    QFrame *line_5;
    QTableView *Table_view_2;
    QWidget *tab_3;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_5;
    QLabel *Code_Label3;
    QLineEdit *Code_Line3_Selecttab;
    QLabel *Date_Label;
    QLineEdit *Date_Line;
    QSpacerItem *horizontalSpacer_8;
    QGridLayout *gridLayout_6;
    QLabel *CurrentDay_label;
    QLabel *todayDay_lbl_SelectTab;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *selectCode_dateTable_button;
    QPushButton *selectDate_dateTable_button;
    QPushButton *selectAll_Button;
    QPushButton *ExportButton;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_3;
    QTableView *Table_view_5;
    QWidget *tab_4;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_3;
    QLabel *Name_Label3;
    QLineEdit *Name_Line3_SearchTab;
    QLabel *Family_Label3;
    QLineEdit *Family_Line3_SearchTab;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *SearchName_Button;
    QPushButton *SearchFamily_Button;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QFrame *line_4;
    QTableView *Table_view_SearchTab;
    QWidget *tab_5;
    QTableView *Table_view_new1;
    QPushButton *Ok_Button_ReportTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Code_Label3_new1;
    QLineEdit *Code_Line3_Report;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menu_Export;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(588, 544);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(0, 0));
        MainWindow->setAutoFillBackground(false);
        action_Connect = new QAction(MainWindow);
        action_Connect->setObjectName(QStringLiteral("action_Connect"));
        actionE_xit = new QAction(MainWindow);
        actionE_xit->setObjectName(QStringLiteral("actionE_xit"));
        action_Aboat = new QAction(MainWindow);
        action_Aboat->setObjectName(QStringLiteral("action_Aboat"));
        actionExport_Today = new QAction(MainWindow);
        actionExport_Today->setObjectName(QStringLiteral("actionExport_Today"));
        action_DucoWiki_Export_Today = new QAction(MainWindow);
        action_DucoWiki_Export_Today->setObjectName(QStringLiteral("action_DucoWiki_Export_Today"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        baseTabWidget = new QTabWidget(centralWidget);
        baseTabWidget->setObjectName(QStringLiteral("baseTabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        Code_Label = new QLabel(tab);
        Code_Label->setObjectName(QStringLiteral("Code_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Code_Label->sizePolicy().hasHeightForWidth());
        Code_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, Code_Label);

        Name_Label = new QLabel(tab);
        Name_Label->setObjectName(QStringLiteral("Name_Label"));
        sizePolicy1.setHeightForWidth(Name_Label->sizePolicy().hasHeightForWidth());
        Name_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, Name_Label);

        Name_Line = new QLineEdit(tab);
        Name_Line->setObjectName(QStringLiteral("Name_Line"));

        formLayout->setWidget(1, QFormLayout::FieldRole, Name_Line);

        Family_Label = new QLabel(tab);
        Family_Label->setObjectName(QStringLiteral("Family_Label"));
        sizePolicy1.setHeightForWidth(Family_Label->sizePolicy().hasHeightForWidth());
        Family_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, Family_Label);

        Family_Line = new QLineEdit(tab);
        Family_Line->setObjectName(QStringLiteral("Family_Line"));

        formLayout->setWidget(2, QFormLayout::FieldRole, Family_Line);

        Code_Line = new QLineEdit(tab);
        Code_Line->setObjectName(QStringLiteral("Code_Line"));

        formLayout->setWidget(0, QFormLayout::FieldRole, Code_Line);

        Email_Label = new QLabel(tab);
        Email_Label->setObjectName(QStringLiteral("Email_Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Email_Label);

        Email_Line = new QLineEdit(tab);
        Email_Line->setObjectName(QStringLiteral("Email_Line"));

        formLayout->setWidget(3, QFormLayout::FieldRole, Email_Line);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ImageLabel_Maintab = new QLabel(tab);
        ImageLabel_Maintab->setObjectName(QStringLiteral("ImageLabel_Maintab"));
        sizePolicy1.setHeightForWidth(ImageLabel_Maintab->sizePolicy().hasHeightForWidth());
        ImageLabel_Maintab->setSizePolicy(sizePolicy1);
        ImageLabel_Maintab->setMinimumSize(QSize(0, 0));
        ImageLabel_Maintab->setMaximumSize(QSize(40000, 40000));

        horizontalLayout_2->addWidget(ImageLabel_Maintab);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        todayDay_lbl = new QLabel(tab);
        todayDay_lbl->setObjectName(QStringLiteral("todayDay_lbl"));
        sizePolicy1.setHeightForWidth(todayDay_lbl->sizePolicy().hasHeightForWidth());
        todayDay_lbl->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(todayDay_lbl);

        line = new QFrame(tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        db_status = new QLabel(tab);
        db_status->setObjectName(QStringLiteral("db_status"));
        sizePolicy1.setHeightForWidth(db_status->sizePolicy().hasHeightForWidth());
        db_status->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(db_status);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        deleteButton = new QPushButton(tab);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(deleteButton);

        updateButton = new QPushButton(tab);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        sizePolicy1.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(updateButton);

        SelectButton = new QPushButton(tab);
        SelectButton->setObjectName(QStringLiteral("SelectButton"));
        sizePolicy1.setHeightForWidth(SelectButton->sizePolicy().hasHeightForWidth());
        SelectButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(SelectButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        SearchButton = new QPushButton(tab);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));

        horizontalLayout_3->addWidget(SearchButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        Table_view = new QTableView(tab);
        Table_view->setObjectName(QStringLiteral("Table_view"));
        sizePolicy.setHeightForWidth(Table_view->sizePolicy().hasHeightForWidth());
        Table_view->setSizePolicy(sizePolicy);
        Table_view->setMinimumSize(QSize(1, 3));
        Table_view->setBaseSize(QSize(2, 2));
        Table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(Table_view);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        baseTabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_5 = new QGridLayout(tab_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        Code_Label2 = new QLabel(tab_2);
        Code_Label2->setObjectName(QStringLiteral("Code_Label2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Code_Label2);

        Code_Line2_Registertab = new QLineEdit(tab_2);
        Code_Line2_Registertab->setObjectName(QStringLiteral("Code_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Code_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Code_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Code_Line2_Registertab);

        Name_Label2 = new QLabel(tab_2);
        Name_Label2->setObjectName(QStringLiteral("Name_Label2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Name_Label2);

        Name_Line2_Registertab = new QLineEdit(tab_2);
        Name_Line2_Registertab->setObjectName(QStringLiteral("Name_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Name_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Name_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Name_Line2_Registertab);

        Family_Label2 = new QLabel(tab_2);
        Family_Label2->setObjectName(QStringLiteral("Family_Label2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Family_Label2);

        Family_Line2_Registertab = new QLineEdit(tab_2);
        Family_Line2_Registertab->setObjectName(QStringLiteral("Family_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Family_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Family_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, Family_Line2_Registertab);

        Email_Line2_Register = new QLineEdit(tab_2);
        Email_Line2_Register->setObjectName(QStringLiteral("Email_Line2_Register"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, Email_Line2_Register);

        Email_Label2 = new QLabel(tab_2);
        Email_Label2->setObjectName(QStringLiteral("Email_Label2"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, Email_Label2);


        verticalLayout_6->addLayout(formLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        FirstTime_Checkbox_Register = new QCheckBox(tab_2);
        FirstTime_Checkbox_Register->setObjectName(QStringLiteral("FirstTime_Checkbox_Register"));

        verticalLayout_5->addWidget(FirstTime_Checkbox_Register);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        AddButton_Registertab = new QPushButton(tab_2);
        AddButton_Registertab->setObjectName(QStringLiteral("AddButton_Registertab"));
        sizePolicy1.setHeightForWidth(AddButton_Registertab->sizePolicy().hasHeightForWidth());
        AddButton_Registertab->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(AddButton_Registertab);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 2, 1);

        addPicture_Button = new QPushButton(tab_2);
        addPicture_Button->setObjectName(QStringLiteral("addPicture_Button"));
        sizePolicy1.setHeightForWidth(addPicture_Button->sizePolicy().hasHeightForWidth());
        addPicture_Button->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(addPicture_Button, 1, 3, 1, 1);

        imageLabel_RegisterTab = new QLabel(tab_2);
        imageLabel_RegisterTab->setObjectName(QStringLiteral("imageLabel_RegisterTab"));
        imageLabel_RegisterTab->setMinimumSize(QSize(150, 150));
        imageLabel_RegisterTab->setMaximumSize(QSize(150, 150));

        gridLayout_3->addWidget(imageLabel_RegisterTab, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(148, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_6, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_7, 1, 2, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        line_5 = new QFrame(tab_2);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        Table_view_2 = new QTableView(tab_2);
        Table_view_2->setObjectName(QStringLiteral("Table_view_2"));
        sizePolicy.setHeightForWidth(Table_view_2->sizePolicy().hasHeightForWidth());
        Table_view_2->setSizePolicy(sizePolicy);
        Table_view_2->setMinimumSize(QSize(1, 3));
        Table_view_2->setBaseSize(QSize(2, 2));
        Table_view_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_7->addWidget(Table_view_2);


        gridLayout_4->addLayout(verticalLayout_7, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        baseTabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_9 = new QGridLayout(tab_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        Code_Label3 = new QLabel(tab_3);
        Code_Label3->setObjectName(QStringLiteral("Code_Label3"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, Code_Label3);

        Code_Line3_Selecttab = new QLineEdit(tab_3);
        Code_Line3_Selecttab->setObjectName(QStringLiteral("Code_Line3_Selecttab"));
        sizePolicy1.setHeightForWidth(Code_Line3_Selecttab->sizePolicy().hasHeightForWidth());
        Code_Line3_Selecttab->setSizePolicy(sizePolicy1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, Code_Line3_Selecttab);

        Date_Label = new QLabel(tab_3);
        Date_Label->setObjectName(QStringLiteral("Date_Label"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, Date_Label);

        Date_Line = new QLineEdit(tab_3);
        Date_Line->setObjectName(QStringLiteral("Date_Line"));
        sizePolicy1.setHeightForWidth(Date_Line->sizePolicy().hasHeightForWidth());
        Date_Line->setSizePolicy(sizePolicy1);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, Date_Line);


        gridLayout_7->addLayout(formLayout_5, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        CurrentDay_label = new QLabel(tab_3);
        CurrentDay_label->setObjectName(QStringLiteral("CurrentDay_label"));

        gridLayout_6->addWidget(CurrentDay_label, 0, 0, 1, 1);

        todayDay_lbl_SelectTab = new QLabel(tab_3);
        todayDay_lbl_SelectTab->setObjectName(QStringLiteral("todayDay_lbl_SelectTab"));

        gridLayout_6->addWidget(todayDay_lbl_SelectTab, 0, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_6->addItem(verticalSpacer_4, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 2, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        selectCode_dateTable_button = new QPushButton(tab_3);
        selectCode_dateTable_button->setObjectName(QStringLiteral("selectCode_dateTable_button"));
        sizePolicy1.setHeightForWidth(selectCode_dateTable_button->sizePolicy().hasHeightForWidth());
        selectCode_dateTable_button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectCode_dateTable_button);

        selectDate_dateTable_button = new QPushButton(tab_3);
        selectDate_dateTable_button->setObjectName(QStringLiteral("selectDate_dateTable_button"));
        sizePolicy1.setHeightForWidth(selectDate_dateTable_button->sizePolicy().hasHeightForWidth());
        selectDate_dateTable_button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectDate_dateTable_button);

        selectAll_Button = new QPushButton(tab_3);
        selectAll_Button->setObjectName(QStringLiteral("selectAll_Button"));
        sizePolicy1.setHeightForWidth(selectAll_Button->sizePolicy().hasHeightForWidth());
        selectAll_Button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectAll_Button);

        ExportButton = new QPushButton(tab_3);
        ExportButton->setObjectName(QStringLiteral("ExportButton"));
        sizePolicy1.setHeightForWidth(ExportButton->sizePolicy().hasHeightForWidth());
        ExportButton->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(ExportButton);


        horizontalLayout_10->addLayout(horizontalLayout_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        gridLayout_7->addLayout(horizontalLayout_10, 1, 0, 1, 3);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        line_3 = new QFrame(tab_3);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        Table_view_5 = new QTableView(tab_3);
        Table_view_5->setObjectName(QStringLiteral("Table_view_5"));
        sizePolicy.setHeightForWidth(Table_view_5->sizePolicy().hasHeightForWidth());
        Table_view_5->setSizePolicy(sizePolicy);
        Table_view_5->setMinimumSize(QSize(1, 3));
        Table_view_5->setBaseSize(QSize(2, 2));
        Table_view_5->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(Table_view_5);


        gridLayout_8->addLayout(verticalLayout_4, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        baseTabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        gridLayout_10 = new QGridLayout(tab_4);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        formLayout_3 = new QFormLayout();
        formLayout_3->setSpacing(6);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        Name_Label3 = new QLabel(tab_4);
        Name_Label3->setObjectName(QStringLiteral("Name_Label3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Name_Label3);

        Name_Line3_SearchTab = new QLineEdit(tab_4);
        Name_Line3_SearchTab->setObjectName(QStringLiteral("Name_Line3_SearchTab"));
        sizePolicy1.setHeightForWidth(Name_Line3_SearchTab->sizePolicy().hasHeightForWidth());
        Name_Line3_SearchTab->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, Name_Line3_SearchTab);

        Family_Label3 = new QLabel(tab_4);
        Family_Label3->setObjectName(QStringLiteral("Family_Label3"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, Family_Label3);

        Family_Line3_SearchTab = new QLineEdit(tab_4);
        Family_Line3_SearchTab->setObjectName(QStringLiteral("Family_Line3_SearchTab"));
        sizePolicy1.setHeightForWidth(Family_Line3_SearchTab->sizePolicy().hasHeightForWidth());
        Family_Line3_SearchTab->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Family_Line3_SearchTab);


        horizontalLayout_7->addLayout(formLayout_3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        SearchName_Button = new QPushButton(tab_4);
        SearchName_Button->setObjectName(QStringLiteral("SearchName_Button"));

        horizontalLayout_6->addWidget(SearchName_Button);

        SearchFamily_Button = new QPushButton(tab_4);
        SearchFamily_Button->setObjectName(QStringLiteral("SearchFamily_Button"));

        horizontalLayout_6->addWidget(SearchFamily_Button);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_12);


        verticalLayout_9->addLayout(horizontalLayout_6);


        gridLayout_10->addLayout(verticalLayout_9, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_10->addItem(verticalSpacer);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        line_4 = new QFrame(tab_4);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        Table_view_SearchTab = new QTableView(tab_4);
        Table_view_SearchTab->setObjectName(QStringLiteral("Table_view_SearchTab"));
        sizePolicy.setHeightForWidth(Table_view_SearchTab->sizePolicy().hasHeightForWidth());
        Table_view_SearchTab->setSizePolicy(sizePolicy);
        Table_view_SearchTab->setMinimumSize(QSize(1, 3));
        Table_view_SearchTab->setBaseSize(QSize(2, 2));
        Table_view_SearchTab->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_8->addWidget(Table_view_SearchTab);


        verticalLayout_10->addLayout(verticalLayout_8);


        gridLayout_10->addLayout(verticalLayout_10, 1, 0, 1, 1);

        baseTabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        Table_view_new1 = new QTableView(tab_5);
        Table_view_new1->setObjectName(QStringLiteral("Table_view_new1"));
        Table_view_new1->setGeometry(QRect(10, 230, 544, 192));
        sizePolicy.setHeightForWidth(Table_view_new1->sizePolicy().hasHeightForWidth());
        Table_view_new1->setSizePolicy(sizePolicy);
        Table_view_new1->setMinimumSize(QSize(1, 3));
        Table_view_new1->setBaseSize(QSize(2, 2));
        Table_view_new1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Ok_Button_ReportTab = new QPushButton(tab_5);
        Ok_Button_ReportTab->setObjectName(QStringLiteral("Ok_Button_ReportTab"));
        Ok_Button_ReportTab->setGeometry(QRect(50, 150, 97, 31));
        layoutWidget = new QWidget(tab_5);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 172, 25));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        Code_Label3_new1 = new QLabel(layoutWidget);
        Code_Label3_new1->setObjectName(QStringLiteral("Code_Label3_new1"));

        horizontalLayout_8->addWidget(Code_Label3_new1);

        Code_Line3_Report = new QLineEdit(layoutWidget);
        Code_Line3_Report->setObjectName(QStringLiteral("Code_Line3_Report"));
        sizePolicy1.setHeightForWidth(Code_Line3_Report->sizePolicy().hasHeightForWidth());
        Code_Line3_Report->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(Code_Line3_Report);

        baseTabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(baseTabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 588, 20));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QStringLiteral("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QStringLiteral("menu_Help"));
        menu_Export = new QMenu(menuBar);
        menu_Export->setObjectName(QStringLiteral("menu_Export"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
#ifndef QT_NO_SHORTCUT
        Name_Label3->setBuddy(Name_Line3_SearchTab);
        Family_Label3->setBuddy(Family_Line3_SearchTab);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(Code_Line, Name_Line);
        QWidget::setTabOrder(Name_Line, Family_Line);
        QWidget::setTabOrder(Family_Line, deleteButton);
        QWidget::setTabOrder(deleteButton, updateButton);
        QWidget::setTabOrder(updateButton, SelectButton);
        QWidget::setTabOrder(SelectButton, Table_view);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menu_Export->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menu_File->addAction(action_Connect);
        menu_File->addAction(actionE_xit);
        menu_Help->addAction(action_Aboat);
        menu_Export->addAction(actionExport_Today);
        menu_Export->addAction(action_DucoWiki_Export_Today);

        retranslateUi(MainWindow);

        baseTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        action_Connect->setText(QApplication::translate("MainWindow", "&Connect", 0));
        action_Connect->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionE_xit->setText(QApplication::translate("MainWindow", "E&xit", 0));
        actionE_xit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        action_Aboat->setText(QApplication::translate("MainWindow", "empty", 0));
        actionExport_Today->setText(QApplication::translate("MainWindow", "Ex&port Today", 0));
        action_DucoWiki_Export_Today->setText(QApplication::translate("MainWindow", "&DucoWiki Export Today", 0));
        Code_Label->setText(QApplication::translate("MainWindow", "Code :", 0));
        Name_Label->setText(QApplication::translate("MainWindow", "Name :", 0));
        Family_Label->setText(QApplication::translate("MainWindow", "Family :", 0));
        Email_Label->setText(QApplication::translate("MainWindow", "Email :", 0));
        ImageLabel_Maintab->setText(QApplication::translate("MainWindow", "Load Pic", 0));
        todayDay_lbl->setText(QApplication::translate("MainWindow", "day", 0));
        db_status->setText(QApplication::translate("MainWindow", "Database Not Connect", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "&Delete", 0));
        updateButton->setText(QApplication::translate("MainWindow", "&Update", 0));
        SelectButton->setText(QApplication::translate("MainWindow", "Show &All", 0));
        SearchButton->setText(QApplication::translate("MainWindow", "S&earch", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(tab), QApplication::translate("MainWindow", "&Main", 0));
        Code_Label2->setText(QApplication::translate("MainWindow", "Code :", 0));
        Name_Label2->setText(QApplication::translate("MainWindow", "Name :", 0));
        Family_Label2->setText(QApplication::translate("MainWindow", "Family :", 0));
        Email_Label2->setText(QApplication::translate("MainWindow", "E-Mail :", 0));
        FirstTime_Checkbox_Register->setText(QApplication::translate("MainWindow", "First time", 0));
        AddButton_Registertab->setText(QApplication::translate("MainWindow", "&Add", 0));
        addPicture_Button->setText(QApplication::translate("MainWindow", "Browse Picture", 0));
        imageLabel_RegisterTab->setText(QApplication::translate("MainWindow", "Load Pic", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "&Register", 0));
        Code_Label3->setText(QApplication::translate("MainWindow", "Code :", 0));
        Date_Label->setText(QApplication::translate("MainWindow", "Date :", 0));
        CurrentDay_label->setText(QApplication::translate("MainWindow", "Current Day :", 0));
        todayDay_lbl_SelectTab->setText(QApplication::translate("MainWindow", "Date", 0));
        selectCode_dateTable_button->setText(QApplication::translate("MainWindow", "Select By Code", 0));
        selectDate_dateTable_button->setText(QApplication::translate("MainWindow", "Select By Date", 0));
        selectAll_Button->setText(QApplication::translate("MainWindow", "Select All", 0));
        ExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "&Export", 0));
        Name_Label3->setText(QApplication::translate("MainWindow", "Name :", 0));
        Family_Label3->setText(QApplication::translate("MainWindow", "Family :", 0));
        SearchName_Button->setText(QApplication::translate("MainWindow", "Search Name", 0));
        SearchFamily_Button->setText(QApplication::translate("MainWindow", "Search Family", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "&Search", 0));
        Ok_Button_ReportTab->setText(QApplication::translate("MainWindow", "OK", 0));
        Code_Label3_new1->setText(QApplication::translate("MainWindow", "Code :", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Re&port", 0));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menu_Export->setTitle(QApplication::translate("MainWindow", "E&xport", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
