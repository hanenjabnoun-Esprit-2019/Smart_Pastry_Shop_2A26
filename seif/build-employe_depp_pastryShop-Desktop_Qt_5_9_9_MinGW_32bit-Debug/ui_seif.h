/********************************************************************************
** Form generated from reading UI file 'seif.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEIF_H
#define UI_SEIF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QTabWidget *employer;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGroupBox *groupBox;
    QPushButton *pb_ajouter;
    QLineEdit *le_id;
    QLineEdit *le_prenom;
    QLineEdit *le_nom;
    QLineEdit *le_numero;
    QLineEdit *le_id_depp;
    QLineEdit *le_salaire;
    QWidget *tab_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QTableView *tab_employer;
    QLineEdit *le_id_chercher;
    QPushButton *pb_chercher;
    QPushButton *reset_employer;
    QWidget *tab_4;
    QGroupBox *groupBox_2;
    QLineEdit *le_id_supp;
    QLabel *label_7;
    QPushButton *pb_supp;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_7;
    QLineEdit *le_id_2;
    QLineEdit *le_prenom_2;
    QLineEdit *le_nom_2;
    QLineEdit *le_numero_2;
    QLineEdit *le_id_depp_2;
    QLineEdit *le_salaire_2;
    QPushButton *pb_update;
    QLabel *label_8;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *trier;
    QPushButton *pdf;
    QWidget *tab_6;
    QTabWidget *depp;
    QWidget *tab_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QGroupBox *groupBox_4;
    QPushButton *pb_ajouter_depp;
    QLineEdit *le_id_dep;
    QLineEdit *le_spec;
    QLineEdit *le_gerant;
    QLineEdit *le_local;
    QWidget *tab_8;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QTableView *tab_depp;
    QLineEdit *le_id_chercher_depp;
    QPushButton *pb_chercher_depp;
    QPushButton *reset_depp;
    QWidget *tab_9;
    QGroupBox *groupBox_5;
    QPushButton *update_depp;
    QLineEdit *le_id_dep_2;
    QLineEdit *le_spec_2;
    QLineEdit *le_gerant_2;
    QLineEdit *le_local_2;
    QLabel *label_13;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QWidget *tab_10;
    QGroupBox *groupBox_6;
    QLineEdit *le_id_dep_supp;
    QLabel *label_14;
    QPushButton *pb_supp_depp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QLatin1String("QToolTip\n"
"\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
"    border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0"
                        ".2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0 #646464, stop: 1 #5d5d5d);\n"
"    padding: 1px;\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #"
                        "b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
"    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y"
                        "1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_arro"
                        "w.png);\n"
"}\n"
"\n"
"QGroupBox:focus\n"
"{\n"
"border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 7px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"      s"
                        "ubcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinear"
                        "Gradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vert"
                        "ical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #3"
                        "23232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a, stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in "
                        "the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar\n"
"{\n"
"    border: 2px solid grey;\n"
"    border-radius: 5px;\n"
"    text-align: center;\n"
"}\n"
"\n"
"QProgressBar::chunk\n"
"{\n"
"    background-color: #d7801a;\n"
"    width: 2.15px;\n"
"    margin: 0.5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"    padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
""
                        "    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);"
                        "\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #44"
                        "4;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 731, 481));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        employer = new QTabWidget(tab_5);
        employer->setObjectName(QStringLiteral("employer"));
        employer->setGeometry(QRect(0, 0, 661, 391));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 61, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 50, 61, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 80, 61, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 110, 61, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 140, 91, 21));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 170, 91, 21));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 331, 191));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(250, 160, 75, 23));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(130, 10, 113, 20));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(130, 40, 113, 20));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(130, 70, 113, 20));
        le_numero = new QLineEdit(groupBox);
        le_numero->setObjectName(QStringLiteral("le_numero"));
        le_numero->setGeometry(QRect(130, 100, 113, 20));
        le_id_depp = new QLineEdit(groupBox);
        le_id_depp->setObjectName(QStringLiteral("le_id_depp"));
        le_id_depp->setGeometry(QRect(130, 130, 113, 20));
        le_salaire = new QLineEdit(groupBox);
        le_salaire->setObjectName(QStringLiteral("le_salaire"));
        le_salaire->setGeometry(QRect(130, 160, 113, 20));
        employer->addTab(tab, QString());
        groupBox->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        scrollArea = new QScrollArea(tab_3);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 641, 321));
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 639, 319));
        tab_employer = new QTableView(scrollAreaWidgetContents);
        tab_employer->setObjectName(QStringLiteral("tab_employer"));
        tab_employer->setGeometry(QRect(10, 50, 611, 261));
        tab_employer->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_id_chercher = new QLineEdit(scrollAreaWidgetContents);
        le_id_chercher->setObjectName(QStringLiteral("le_id_chercher"));
        le_id_chercher->setGeometry(QRect(80, 10, 341, 21));
        le_id_chercher->setStyleSheet(QStringLiteral(""));
        pb_chercher = new QPushButton(scrollAreaWidgetContents);
        pb_chercher->setObjectName(QStringLiteral("pb_chercher"));
        pb_chercher->setGeometry(QRect(430, 10, 75, 23));
        reset_employer = new QPushButton(scrollAreaWidgetContents);
        reset_employer->setObjectName(QStringLiteral("reset_employer"));
        reset_employer->setGeometry(QRect(10, 10, 31, 21));
        scrollArea->setWidget(scrollAreaWidgetContents);
        employer->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_2 = new QGroupBox(tab_4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 341, 191));
        le_id_supp = new QLineEdit(groupBox_2);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(90, 80, 113, 20));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(70, 80, 61, 21));
        pb_supp = new QPushButton(groupBox_2);
        pb_supp->setObjectName(QStringLiteral("pb_supp"));
        pb_supp->setGeometry(QRect(220, 140, 75, 23));
        label_7->raise();
        pb_supp->raise();
        le_id_supp->raise();
        employer->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 341, 191));
        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 0, 331, 191));
        le_id_2 = new QLineEdit(groupBox_7);
        le_id_2->setObjectName(QStringLiteral("le_id_2"));
        le_id_2->setGeometry(QRect(130, 10, 113, 20));
        le_prenom_2 = new QLineEdit(groupBox_7);
        le_prenom_2->setObjectName(QStringLiteral("le_prenom_2"));
        le_prenom_2->setGeometry(QRect(130, 40, 113, 20));
        le_nom_2 = new QLineEdit(groupBox_7);
        le_nom_2->setObjectName(QStringLiteral("le_nom_2"));
        le_nom_2->setGeometry(QRect(130, 70, 113, 20));
        le_numero_2 = new QLineEdit(groupBox_7);
        le_numero_2->setObjectName(QStringLiteral("le_numero_2"));
        le_numero_2->setGeometry(QRect(130, 100, 113, 20));
        le_id_depp_2 = new QLineEdit(groupBox_7);
        le_id_depp_2->setObjectName(QStringLiteral("le_id_depp_2"));
        le_id_depp_2->setGeometry(QRect(130, 130, 113, 20));
        le_salaire_2 = new QLineEdit(groupBox_7);
        le_salaire_2->setObjectName(QStringLiteral("le_salaire_2"));
        le_salaire_2->setGeometry(QRect(130, 160, 113, 20));
        pb_update = new QPushButton(groupBox_7);
        pb_update->setObjectName(QStringLiteral("pb_update"));
        pb_update->setGeometry(QRect(250, 150, 75, 23));
        label_8 = new QLabel(groupBox_7);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 10, 61, 16));
        label_15 = new QLabel(groupBox_7);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 40, 61, 16));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 70, 61, 16));
        label_17 = new QLabel(groupBox_7);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(40, 100, 61, 16));
        label_18 = new QLabel(groupBox_7);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(40, 130, 91, 21));
        label_19 = new QLabel(groupBox_7);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(40, 160, 91, 21));
        employer->addTab(tab_2, QString());
        trier = new QPushButton(tab_5);
        trier->setObjectName(QStringLiteral("trier"));
        trier->setGeometry(QRect(210, 380, 201, 31));
        trier->setStyleSheet(QStringLiteral(""));
        pdf = new QPushButton(tab_5);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(210, 420, 201, 31));
        pdf->setStyleSheet(QStringLiteral(""));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        depp = new QTabWidget(tab_6);
        depp->setObjectName(QStringLiteral("depp"));
        depp->setGeometry(QRect(20, 0, 651, 331));
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        label_9 = new QLabel(tab_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 20, 61, 16));
        label_10 = new QLabel(tab_7);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 80, 61, 16));
        label_11 = new QLabel(tab_7);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 50, 61, 16));
        label_12 = new QLabel(tab_7);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 110, 61, 16));
        groupBox_4 = new QGroupBox(tab_7);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 10, 331, 191));
        pb_ajouter_depp = new QPushButton(groupBox_4);
        pb_ajouter_depp->setObjectName(QStringLiteral("pb_ajouter_depp"));
        pb_ajouter_depp->setGeometry(QRect(250, 160, 75, 23));
        le_id_dep = new QLineEdit(groupBox_4);
        le_id_dep->setObjectName(QStringLiteral("le_id_dep"));
        le_id_dep->setGeometry(QRect(130, 10, 113, 20));
        le_spec = new QLineEdit(groupBox_4);
        le_spec->setObjectName(QStringLiteral("le_spec"));
        le_spec->setGeometry(QRect(130, 40, 113, 20));
        le_gerant = new QLineEdit(groupBox_4);
        le_gerant->setObjectName(QStringLiteral("le_gerant"));
        le_gerant->setGeometry(QRect(130, 70, 113, 20));
        le_local = new QLineEdit(groupBox_4);
        le_local->setObjectName(QStringLiteral("le_local"));
        le_local->setGeometry(QRect(130, 100, 113, 20));
        depp->addTab(tab_7, QString());
        groupBox_4->raise();
        label_9->raise();
        label_11->raise();
        label_10->raise();
        label_12->raise();
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        scrollArea_2 = new QScrollArea(tab_8);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(12, 22, 621, 281));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 619, 279));
        tab_depp = new QTableView(scrollAreaWidgetContents_2);
        tab_depp->setObjectName(QStringLiteral("tab_depp"));
        tab_depp->setGeometry(QRect(0, 60, 611, 181));
        tab_depp->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_id_chercher_depp = new QLineEdit(scrollAreaWidgetContents_2);
        le_id_chercher_depp->setObjectName(QStringLiteral("le_id_chercher_depp"));
        le_id_chercher_depp->setGeometry(QRect(80, 20, 381, 21));
        pb_chercher_depp = new QPushButton(scrollAreaWidgetContents_2);
        pb_chercher_depp->setObjectName(QStringLiteral("pb_chercher_depp"));
        pb_chercher_depp->setGeometry(QRect(470, 20, 75, 23));
        reset_depp = new QPushButton(scrollAreaWidgetContents_2);
        reset_depp->setObjectName(QStringLiteral("reset_depp"));
        reset_depp->setGeometry(QRect(10, 10, 31, 21));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        depp->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox_5 = new QGroupBox(tab_9);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 341, 191));
        update_depp = new QPushButton(groupBox_5);
        update_depp->setObjectName(QStringLiteral("update_depp"));
        update_depp->setGeometry(QRect(220, 140, 75, 23));
        le_id_dep_2 = new QLineEdit(groupBox_5);
        le_id_dep_2->setObjectName(QStringLiteral("le_id_dep_2"));
        le_id_dep_2->setGeometry(QRect(100, 20, 113, 20));
        le_spec_2 = new QLineEdit(groupBox_5);
        le_spec_2->setObjectName(QStringLiteral("le_spec_2"));
        le_spec_2->setGeometry(QRect(100, 50, 113, 20));
        le_gerant_2 = new QLineEdit(groupBox_5);
        le_gerant_2->setObjectName(QStringLiteral("le_gerant_2"));
        le_gerant_2->setGeometry(QRect(100, 80, 113, 20));
        le_local_2 = new QLineEdit(groupBox_5);
        le_local_2->setObjectName(QStringLiteral("le_local_2"));
        le_local_2->setGeometry(QRect(100, 110, 113, 20));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 20, 47, 13));
        label_20 = new QLabel(groupBox_5);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(20, 50, 47, 13));
        label_21 = new QLabel(groupBox_5);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(20, 80, 47, 16));
        label_22 = new QLabel(groupBox_5);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 110, 47, 13));
        depp->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        groupBox_6 = new QGroupBox(tab_10);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 10, 341, 191));
        le_id_dep_supp = new QLineEdit(groupBox_6);
        le_id_dep_supp->setObjectName(QStringLiteral("le_id_dep_supp"));
        le_id_dep_supp->setGeometry(QRect(110, 80, 113, 20));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(90, 80, 61, 21));
        pb_supp_depp = new QPushButton(groupBox_6);
        pb_supp_depp->setObjectName(QStringLiteral("pb_supp_depp"));
        pb_supp_depp->setGeometry(QRect(220, 140, 75, 23));
        label_14->raise();
        pb_supp_depp->raise();
        le_id_dep_supp->raise();
        depp->addTab(tab_10, QString());
        tabWidget->addTab(tab_6, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        employer->setCurrentIndex(3);
        depp->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "numero", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "id departement", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        groupBox->setTitle(QString());
        pb_ajouter->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        employer->setTabText(employer->indexOf(tab), QApplication::translate("MainWindow", "nouvel employ\303\251", Q_NULLPTR));
        pb_chercher->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        reset_employer->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
        employer->setTabText(employer->indexOf(tab_3), QApplication::translate("MainWindow", "consulter liste ", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_7->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        pb_supp->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        employer->setTabText(employer->indexOf(tab_4), QApplication::translate("MainWindow", "supprimer employ\303\251", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        groupBox_7->setTitle(QString());
        pb_update->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "numero", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "id departement", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "salaire", Q_NULLPTR));
        employer->setTabText(employer->indexOf(tab_2), QApplication::translate("MainWindow", "modifier employ\303\251", Q_NULLPTR));
        trier->setText(QApplication::translate("MainWindow", "trier par salaire", Q_NULLPTR));
        pdf->setText(QApplication::translate("MainWindow", "pdf", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "g\303\251rer employer", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "g\303\251rant", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "sp\303\251cialit\303\251", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "localisation", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        pb_ajouter_depp->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        depp->setTabText(depp->indexOf(tab_7), QApplication::translate("MainWindow", "nouveau depp", Q_NULLPTR));
        pb_chercher_depp->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        reset_depp->setText(QApplication::translate("MainWindow", "<-", Q_NULLPTR));
        depp->setTabText(depp->indexOf(tab_8), QApplication::translate("MainWindow", "consulter liste ", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        update_depp->setText(QApplication::translate("MainWindow", "continuer", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "sp\303\251cialit\303\251", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "g\303\251rant", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "localisation", Q_NULLPTR));
        depp->setTabText(depp->indexOf(tab_9), QApplication::translate("MainWindow", "modifier ", Q_NULLPTR));
        groupBox_6->setTitle(QString());
        label_14->setText(QApplication::translate("MainWindow", "id", Q_NULLPTR));
        pb_supp_depp->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        depp->setTabText(depp->indexOf(tab_10), QApplication::translate("MainWindow", "supprimer depp", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "g\303\251rer d\303\251partement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEIF_H
