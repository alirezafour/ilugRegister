/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
    QWidget *main_tab;
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
    QWidget *register_tab;
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
    QWidget *export_tab;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QFormLayout *formLayout_5;
    QLabel *Code_Label3;
    QLineEdit *Code_Line3_Selecttab;
    QLabel *Date_Label;
    QLineEdit *Date_Line;
    QGridLayout *gridLayout_6;
    QLabel *todayDay_lbl_SelectTab;
    QLabel *CurrentDay_label;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *selectCode_dateTable_button;
    QPushButton *selectDate_dateTable_button;
    QPushButton *selectAll_Button;
    QPushButton *ExportButton;
    QPushButton *docuExportButton;
    QPushButton *report_btn;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_3;
    QTableView *Table_view_5;
    QWidget *search_tab;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_7;
    QFormLayout *formLayout_3;
    QLabel *Name_Label3;
    QLineEdit *Name_Line3_SearchTab;
    QLabel *Family_Label3;
    QLineEdit *Family_Line3_SearchTab;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *SearchName_Button;
    QPushButton *SearchFamily_Button;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_8;
    QFrame *line_4;
    QTableView *Table_view_SearchTab;
    QWidget *vote_tab;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_13;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_11;
    QLabel *CodeLabal_VoteTab;
    QLineEdit *codeLine_VoteTab;
    QSpacerItem *horizontalSpacer_10;
    QLabel *ImageLabel_Votetab;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *Ok_Button_VoteTab;
    QPushButton *selectAllButton_VoteTab;
    QSpacerItem *horizontalSpacer_13;
    QTableView *Table_view_VoteTab;
    QFrame *line_6;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menu_Export;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(639, 544);
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
        main_tab = new QWidget();
        main_tab->setObjectName(QStringLiteral("main_tab"));
        gridLayout_2 = new QGridLayout(main_tab);
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
        Code_Label = new QLabel(main_tab);
        Code_Label->setObjectName(QStringLiteral("Code_Label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Code_Label->sizePolicy().hasHeightForWidth());
        Code_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::LabelRole, Code_Label);

        Name_Label = new QLabel(main_tab);
        Name_Label->setObjectName(QStringLiteral("Name_Label"));
        sizePolicy1.setHeightForWidth(Name_Label->sizePolicy().hasHeightForWidth());
        Name_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::LabelRole, Name_Label);

        Name_Line = new QLineEdit(main_tab);
        Name_Line->setObjectName(QStringLiteral("Name_Line"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Name_Line->sizePolicy().hasHeightForWidth());
        Name_Line->setSizePolicy(sizePolicy2);

        formLayout->setWidget(1, QFormLayout::FieldRole, Name_Line);

        Family_Label = new QLabel(main_tab);
        Family_Label->setObjectName(QStringLiteral("Family_Label"));
        sizePolicy1.setHeightForWidth(Family_Label->sizePolicy().hasHeightForWidth());
        Family_Label->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::LabelRole, Family_Label);

        Family_Line = new QLineEdit(main_tab);
        Family_Line->setObjectName(QStringLiteral("Family_Line"));
        sizePolicy1.setHeightForWidth(Family_Line->sizePolicy().hasHeightForWidth());
        Family_Line->setSizePolicy(sizePolicy1);

        formLayout->setWidget(2, QFormLayout::FieldRole, Family_Line);

        Code_Line = new QLineEdit(main_tab);
        Code_Line->setObjectName(QStringLiteral("Code_Line"));
        sizePolicy1.setHeightForWidth(Code_Line->sizePolicy().hasHeightForWidth());
        Code_Line->setSizePolicy(sizePolicy1);

        formLayout->setWidget(0, QFormLayout::FieldRole, Code_Line);

        Email_Label = new QLabel(main_tab);
        Email_Label->setObjectName(QStringLiteral("Email_Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, Email_Label);

        Email_Line = new QLineEdit(main_tab);
        Email_Line->setObjectName(QStringLiteral("Email_Line"));
        sizePolicy1.setHeightForWidth(Email_Line->sizePolicy().hasHeightForWidth());
        Email_Line->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::FieldRole, Email_Line);


        horizontalLayout_2->addLayout(formLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        ImageLabel_Maintab = new QLabel(main_tab);
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

        todayDay_lbl = new QLabel(main_tab);
        todayDay_lbl->setObjectName(QStringLiteral("todayDay_lbl"));
        sizePolicy1.setHeightForWidth(todayDay_lbl->sizePolicy().hasHeightForWidth());
        todayDay_lbl->setSizePolicy(sizePolicy1);

        verticalLayout_2->addWidget(todayDay_lbl);

        line = new QFrame(main_tab);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        db_status = new QLabel(main_tab);
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
        deleteButton = new QPushButton(main_tab);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));
        sizePolicy1.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(deleteButton);

        updateButton = new QPushButton(main_tab);
        updateButton->setObjectName(QStringLiteral("updateButton"));
        sizePolicy1.setHeightForWidth(updateButton->sizePolicy().hasHeightForWidth());
        updateButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(updateButton);

        SelectButton = new QPushButton(main_tab);
        SelectButton->setObjectName(QStringLiteral("SelectButton"));
        sizePolicy1.setHeightForWidth(SelectButton->sizePolicy().hasHeightForWidth());
        SelectButton->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(SelectButton);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        SearchButton = new QPushButton(main_tab);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));

        horizontalLayout_3->addWidget(SearchButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout_2);

        line_2 = new QFrame(main_tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        Table_view = new QTableView(main_tab);
        Table_view->setObjectName(QStringLiteral("Table_view"));
        sizePolicy.setHeightForWidth(Table_view->sizePolicy().hasHeightForWidth());
        Table_view->setSizePolicy(sizePolicy);
        Table_view->setMinimumSize(QSize(1, 3));
        Table_view->setBaseSize(QSize(2, 2));
        Table_view->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_3->addWidget(Table_view);


        gridLayout_2->addLayout(verticalLayout_3, 0, 0, 1, 1);

        baseTabWidget->addTab(main_tab, QString());
        register_tab = new QWidget();
        register_tab->setObjectName(QStringLiteral("register_tab"));
        gridLayout_5 = new QGridLayout(register_tab);
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
        Code_Label2 = new QLabel(register_tab);
        Code_Label2->setObjectName(QStringLiteral("Code_Label2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Code_Label2);

        Code_Line2_Registertab = new QLineEdit(register_tab);
        Code_Line2_Registertab->setObjectName(QStringLiteral("Code_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Code_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Code_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, Code_Line2_Registertab);

        Name_Label2 = new QLabel(register_tab);
        Name_Label2->setObjectName(QStringLiteral("Name_Label2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, Name_Label2);

        Name_Line2_Registertab = new QLineEdit(register_tab);
        Name_Line2_Registertab->setObjectName(QStringLiteral("Name_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Name_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Name_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Name_Line2_Registertab);

        Family_Label2 = new QLabel(register_tab);
        Family_Label2->setObjectName(QStringLiteral("Family_Label2"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, Family_Label2);

        Family_Line2_Registertab = new QLineEdit(register_tab);
        Family_Line2_Registertab->setObjectName(QStringLiteral("Family_Line2_Registertab"));
        sizePolicy1.setHeightForWidth(Family_Line2_Registertab->sizePolicy().hasHeightForWidth());
        Family_Line2_Registertab->setSizePolicy(sizePolicy1);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, Family_Line2_Registertab);

        Email_Line2_Register = new QLineEdit(register_tab);
        Email_Line2_Register->setObjectName(QStringLiteral("Email_Line2_Register"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, Email_Line2_Register);

        Email_Label2 = new QLabel(register_tab);
        Email_Label2->setObjectName(QStringLiteral("Email_Label2"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, Email_Label2);


        verticalLayout_6->addLayout(formLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        FirstTime_Checkbox_Register = new QCheckBox(register_tab);
        FirstTime_Checkbox_Register->setObjectName(QStringLiteral("FirstTime_Checkbox_Register"));

        verticalLayout_5->addWidget(FirstTime_Checkbox_Register);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        AddButton_Registertab = new QPushButton(register_tab);
        AddButton_Registertab->setObjectName(QStringLiteral("AddButton_Registertab"));
        sizePolicy1.setHeightForWidth(AddButton_Registertab->sizePolicy().hasHeightForWidth());
        AddButton_Registertab->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(AddButton_Registertab);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_5);


        gridLayout_3->addLayout(verticalLayout_6, 0, 0, 2, 1);

        addPicture_Button = new QPushButton(register_tab);
        addPicture_Button->setObjectName(QStringLiteral("addPicture_Button"));
        sizePolicy1.setHeightForWidth(addPicture_Button->sizePolicy().hasHeightForWidth());
        addPicture_Button->setSizePolicy(sizePolicy1);

        gridLayout_3->addWidget(addPicture_Button, 1, 3, 1, 1);

        imageLabel_RegisterTab = new QLabel(register_tab);
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
        line_5 = new QFrame(register_tab);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_5);

        Table_view_2 = new QTableView(register_tab);
        Table_view_2->setObjectName(QStringLiteral("Table_view_2"));
        sizePolicy.setHeightForWidth(Table_view_2->sizePolicy().hasHeightForWidth());
        Table_view_2->setSizePolicy(sizePolicy);
        Table_view_2->setMinimumSize(QSize(1, 3));
        Table_view_2->setBaseSize(QSize(2, 2));
        Table_view_2->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_7->addWidget(Table_view_2);


        gridLayout_4->addLayout(verticalLayout_7, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        baseTabWidget->addTab(register_tab, QString());
        export_tab = new QWidget();
        export_tab->setObjectName(QStringLiteral("export_tab"));
        gridLayout_9 = new QGridLayout(export_tab);
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
        Code_Label3 = new QLabel(export_tab);
        Code_Label3->setObjectName(QStringLiteral("Code_Label3"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, Code_Label3);

        Code_Line3_Selecttab = new QLineEdit(export_tab);
        Code_Line3_Selecttab->setObjectName(QStringLiteral("Code_Line3_Selecttab"));
        sizePolicy1.setHeightForWidth(Code_Line3_Selecttab->sizePolicy().hasHeightForWidth());
        Code_Line3_Selecttab->setSizePolicy(sizePolicy1);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, Code_Line3_Selecttab);

        Date_Label = new QLabel(export_tab);
        Date_Label->setObjectName(QStringLiteral("Date_Label"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, Date_Label);

        Date_Line = new QLineEdit(export_tab);
        Date_Line->setObjectName(QStringLiteral("Date_Line"));
        sizePolicy1.setHeightForWidth(Date_Line->sizePolicy().hasHeightForWidth());
        Date_Line->setSizePolicy(sizePolicy1);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, Date_Line);


        gridLayout_7->addLayout(formLayout_5, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        todayDay_lbl_SelectTab = new QLabel(export_tab);
        todayDay_lbl_SelectTab->setObjectName(QStringLiteral("todayDay_lbl_SelectTab"));

        gridLayout_6->addWidget(todayDay_lbl_SelectTab, 0, 1, 1, 1);

        CurrentDay_label = new QLabel(export_tab);
        CurrentDay_label->setObjectName(QStringLiteral("CurrentDay_label"));
        sizePolicy1.setHeightForWidth(CurrentDay_label->sizePolicy().hasHeightForWidth());
        CurrentDay_label->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(CurrentDay_label, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_2, 1, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 2, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        selectCode_dateTable_button = new QPushButton(export_tab);
        selectCode_dateTable_button->setObjectName(QStringLiteral("selectCode_dateTable_button"));
        sizePolicy1.setHeightForWidth(selectCode_dateTable_button->sizePolicy().hasHeightForWidth());
        selectCode_dateTable_button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectCode_dateTable_button);

        selectDate_dateTable_button = new QPushButton(export_tab);
        selectDate_dateTable_button->setObjectName(QStringLiteral("selectDate_dateTable_button"));
        sizePolicy1.setHeightForWidth(selectDate_dateTable_button->sizePolicy().hasHeightForWidth());
        selectDate_dateTable_button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectDate_dateTable_button);

        selectAll_Button = new QPushButton(export_tab);
        selectAll_Button->setObjectName(QStringLiteral("selectAll_Button"));
        sizePolicy1.setHeightForWidth(selectAll_Button->sizePolicy().hasHeightForWidth());
        selectAll_Button->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(selectAll_Button);

        ExportButton = new QPushButton(export_tab);
        ExportButton->setObjectName(QStringLiteral("ExportButton"));
        ExportButton->setEnabled(false);
        sizePolicy1.setHeightForWidth(ExportButton->sizePolicy().hasHeightForWidth());
        ExportButton->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(ExportButton);

        docuExportButton = new QPushButton(export_tab);
        docuExportButton->setObjectName(QStringLiteral("docuExportButton"));

        horizontalLayout_4->addWidget(docuExportButton);

        report_btn = new QPushButton(export_tab);
        report_btn->setObjectName(QStringLiteral("report_btn"));

        horizontalLayout_4->addWidget(report_btn);


        horizontalLayout_10->addLayout(horizontalLayout_4);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        gridLayout_7->addLayout(horizontalLayout_10, 1, 0, 1, 3);


        gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        line_3 = new QFrame(export_tab);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        Table_view_5 = new QTableView(export_tab);
        Table_view_5->setObjectName(QStringLiteral("Table_view_5"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Table_view_5->sizePolicy().hasHeightForWidth());
        Table_view_5->setSizePolicy(sizePolicy3);
        Table_view_5->setMinimumSize(QSize(1, 3));
        Table_view_5->setBaseSize(QSize(2, 2));
        Table_view_5->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_4->addWidget(Table_view_5);


        gridLayout_8->addLayout(verticalLayout_4, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_8, 0, 0, 1, 1);

        baseTabWidget->addTab(export_tab, QString());
        search_tab = new QWidget();
        search_tab->setObjectName(QStringLiteral("search_tab"));
        gridLayout_10 = new QGridLayout(search_tab);
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
        Name_Label3 = new QLabel(search_tab);
        Name_Label3->setObjectName(QStringLiteral("Name_Label3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, Name_Label3);

        Name_Line3_SearchTab = new QLineEdit(search_tab);
        Name_Line3_SearchTab->setObjectName(QStringLiteral("Name_Line3_SearchTab"));
        sizePolicy1.setHeightForWidth(Name_Line3_SearchTab->sizePolicy().hasHeightForWidth());
        Name_Line3_SearchTab->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, Name_Line3_SearchTab);

        Family_Label3 = new QLabel(search_tab);
        Family_Label3->setObjectName(QStringLiteral("Family_Label3"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, Family_Label3);

        Family_Line3_SearchTab = new QLineEdit(search_tab);
        Family_Line3_SearchTab->setObjectName(QStringLiteral("Family_Line3_SearchTab"));
        sizePolicy1.setHeightForWidth(Family_Line3_SearchTab->sizePolicy().hasHeightForWidth());
        Family_Line3_SearchTab->setSizePolicy(sizePolicy1);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, Family_Line3_SearchTab);


        horizontalLayout_7->addLayout(formLayout_3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_9->addLayout(horizontalLayout_7);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_9->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        SearchName_Button = new QPushButton(search_tab);
        SearchName_Button->setObjectName(QStringLiteral("SearchName_Button"));

        horizontalLayout_6->addWidget(SearchName_Button);

        SearchFamily_Button = new QPushButton(search_tab);
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
        line_4 = new QFrame(search_tab);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line_4);

        Table_view_SearchTab = new QTableView(search_tab);
        Table_view_SearchTab->setObjectName(QStringLiteral("Table_view_SearchTab"));
        sizePolicy3.setHeightForWidth(Table_view_SearchTab->sizePolicy().hasHeightForWidth());
        Table_view_SearchTab->setSizePolicy(sizePolicy3);
        Table_view_SearchTab->setMinimumSize(QSize(1, 3));
        Table_view_SearchTab->setBaseSize(QSize(2, 2));
        Table_view_SearchTab->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_8->addWidget(Table_view_SearchTab);


        verticalLayout_10->addLayout(verticalLayout_8);


        gridLayout_10->addLayout(verticalLayout_10, 1, 0, 1, 1);

        baseTabWidget->addTab(search_tab, QString());
        vote_tab = new QWidget();
        vote_tab->setObjectName(QStringLiteral("vote_tab"));
        vote_tab->setEnabled(true);
        gridLayout_14 = new QGridLayout(vote_tab);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setSpacing(6);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setSpacing(6);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setSpacing(6);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        CodeLabal_VoteTab = new QLabel(vote_tab);
        CodeLabal_VoteTab->setObjectName(QStringLiteral("CodeLabal_VoteTab"));

        gridLayout_11->addWidget(CodeLabal_VoteTab, 0, 0, 1, 1);

        codeLine_VoteTab = new QLineEdit(vote_tab);
        codeLine_VoteTab->setObjectName(QStringLiteral("codeLine_VoteTab"));
        sizePolicy1.setHeightForWidth(codeLine_VoteTab->sizePolicy().hasHeightForWidth());
        codeLine_VoteTab->setSizePolicy(sizePolicy1);

        gridLayout_11->addWidget(codeLine_VoteTab, 0, 1, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(308, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_10, 0, 1, 1, 1);

        ImageLabel_Votetab = new QLabel(vote_tab);
        ImageLabel_Votetab->setObjectName(QStringLiteral("ImageLabel_Votetab"));
        sizePolicy1.setHeightForWidth(ImageLabel_Votetab->sizePolicy().hasHeightForWidth());
        ImageLabel_Votetab->setSizePolicy(sizePolicy1);
        ImageLabel_Votetab->setMinimumSize(QSize(0, 0));
        ImageLabel_Votetab->setMaximumSize(QSize(40000, 40000));

        gridLayout_12->addWidget(ImageLabel_Votetab, 0, 2, 2, 1);

        verticalSpacer_5 = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_12->addItem(verticalSpacer_5, 1, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        Ok_Button_VoteTab = new QPushButton(vote_tab);
        Ok_Button_VoteTab->setObjectName(QStringLiteral("Ok_Button_VoteTab"));

        horizontalLayout_9->addWidget(Ok_Button_VoteTab);

        selectAllButton_VoteTab = new QPushButton(vote_tab);
        selectAllButton_VoteTab->setObjectName(QStringLiteral("selectAllButton_VoteTab"));
        selectAllButton_VoteTab->setEnabled(false);

        horizontalLayout_9->addWidget(selectAllButton_VoteTab);


        horizontalLayout_11->addLayout(horizontalLayout_9);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);


        gridLayout_12->addLayout(horizontalLayout_11, 2, 0, 1, 2);


        gridLayout_13->addLayout(gridLayout_12, 0, 0, 1, 1);

        Table_view_VoteTab = new QTableView(vote_tab);
        Table_view_VoteTab->setObjectName(QStringLiteral("Table_view_VoteTab"));
        sizePolicy3.setHeightForWidth(Table_view_VoteTab->sizePolicy().hasHeightForWidth());
        Table_view_VoteTab->setSizePolicy(sizePolicy3);
        Table_view_VoteTab->setMinimumSize(QSize(1, 3));
        Table_view_VoteTab->setBaseSize(QSize(2, 2));
        Table_view_VoteTab->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_13->addWidget(Table_view_VoteTab, 1, 0, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 0, 0, 1, 1);

        line_6 = new QFrame(vote_tab);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout_14->addWidget(line_6, 1, 0, 1, 1);

        baseTabWidget->addTab(vote_tab, QString());

        gridLayout->addWidget(baseTabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 639, 27));
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
        Code_Line->setText(QString());
        Email_Label->setText(QApplication::translate("MainWindow", "Email :", 0));
        ImageLabel_Maintab->setText(QApplication::translate("MainWindow", "Load Pic", 0));
        todayDay_lbl->setText(QApplication::translate("MainWindow", "day", 0));
        db_status->setText(QApplication::translate("MainWindow", "Database Not Connect", 0));
        deleteButton->setText(QApplication::translate("MainWindow", "&Delete", 0));
        updateButton->setText(QApplication::translate("MainWindow", "&Update", 0));
        SelectButton->setText(QApplication::translate("MainWindow", "Show &All", 0));
        SearchButton->setText(QApplication::translate("MainWindow", "S&earch", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(main_tab), QApplication::translate("MainWindow", "&Main", 0));
        Code_Label2->setText(QApplication::translate("MainWindow", "Code :", 0));
        Name_Label2->setText(QApplication::translate("MainWindow", "Name :", 0));
        Family_Label2->setText(QApplication::translate("MainWindow", "Family :", 0));
        Email_Label2->setText(QApplication::translate("MainWindow", "E-Mail :", 0));
        FirstTime_Checkbox_Register->setText(QApplication::translate("MainWindow", "First time", 0));
        AddButton_Registertab->setText(QApplication::translate("MainWindow", "&Add", 0));
        addPicture_Button->setText(QApplication::translate("MainWindow", "Browse Picture", 0));
        imageLabel_RegisterTab->setText(QApplication::translate("MainWindow", "Load Pic", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(register_tab), QApplication::translate("MainWindow", "&Register", 0));
        Code_Label3->setText(QApplication::translate("MainWindow", "Code :", 0));
        Date_Label->setText(QApplication::translate("MainWindow", "Date :", 0));
        todayDay_lbl_SelectTab->setText(QApplication::translate("MainWindow", "Date", 0));
        CurrentDay_label->setText(QApplication::translate("MainWindow", "Current Day :", 0));
        selectCode_dateTable_button->setText(QApplication::translate("MainWindow", "Select By Code", 0));
        selectDate_dateTable_button->setText(QApplication::translate("MainWindow", "Select By Date", 0));
        selectAll_Button->setText(QApplication::translate("MainWindow", "Select All", 0));
        ExportButton->setText(QApplication::translate("MainWindow", "Export", 0));
        docuExportButton->setText(QApplication::translate("MainWindow", "Duco Export", 0));
        report_btn->setText(QApplication::translate("MainWindow", "Report", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(export_tab), QApplication::translate("MainWindow", "&Export", 0));
        Name_Label3->setText(QApplication::translate("MainWindow", "Name :", 0));
        Family_Label3->setText(QApplication::translate("MainWindow", "Family :", 0));
        SearchName_Button->setText(QApplication::translate("MainWindow", "Search Name", 0));
        SearchFamily_Button->setText(QApplication::translate("MainWindow", "Search Family", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(search_tab), QApplication::translate("MainWindow", "&Search", 0));
        CodeLabal_VoteTab->setText(QApplication::translate("MainWindow", "Code :", 0));
        ImageLabel_Votetab->setText(QApplication::translate("MainWindow", "Load Pic", 0));
        Ok_Button_VoteTab->setText(QApplication::translate("MainWindow", "OK", 0));
        selectAllButton_VoteTab->setText(QApplication::translate("MainWindow", "Select &All", 0));
        baseTabWidget->setTabText(baseTabWidget->indexOf(vote_tab), QApplication::translate("MainWindow", "&Vote", 0));
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
