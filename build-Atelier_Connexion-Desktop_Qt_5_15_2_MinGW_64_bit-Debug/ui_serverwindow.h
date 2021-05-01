/********************************************************************************
** Form generated from reading UI file 'serverwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERWINDOW_H
#define UI_SERVERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerWindow
{
public:
    QGridLayout *gridLayout;
    QPushButton *startStopButton;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QPlainTextEdit *logEditor;
    QPushButton *pushButton;

    void setupUi(QWidget *ServerWindow)
    {
        if (ServerWindow->objectName().isEmpty())
            ServerWindow->setObjectName(QString::fromUtf8("ServerWindow"));
        ServerWindow->resize(488, 349);
        gridLayout = new QGridLayout(ServerWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        startStopButton = new QPushButton(ServerWindow);
        startStopButton->setObjectName(QString::fromUtf8("startStopButton"));

        gridLayout->addWidget(startStopButton, 3, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(298, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 1);

        label = new QLabel(ServerWindow);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);

        logEditor = new QPlainTextEdit(ServerWindow);
        logEditor->setObjectName(QString::fromUtf8("logEditor"));
        logEditor->setReadOnly(true);

        gridLayout->addWidget(logEditor, 1, 0, 1, 1);

        pushButton = new QPushButton(ServerWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);


        retranslateUi(ServerWindow);

        QMetaObject::connectSlotsByName(ServerWindow);
    } // setupUi

    void retranslateUi(QWidget *ServerWindow)
    {
        ServerWindow->setWindowTitle(QCoreApplication::translate("ServerWindow", "Qt Simple Chat Server", nullptr));
        startStopButton->setText(QCoreApplication::translate("ServerWindow", "Start Server", nullptr));
        label->setText(QCoreApplication::translate("ServerWindow", "Server Log", nullptr));
        pushButton->setText(QCoreApplication::translate("ServerWindow", "Start chatbox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerWindow: public Ui_ServerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERWINDOW_H
