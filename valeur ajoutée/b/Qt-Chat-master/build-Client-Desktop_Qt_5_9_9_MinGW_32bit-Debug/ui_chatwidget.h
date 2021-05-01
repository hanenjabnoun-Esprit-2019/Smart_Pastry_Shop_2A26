/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chatwidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout;
    QListWidget *Dialog_2;
    QHBoxLayout *horizontalLayout;
    QTextEdit *MessageLine;
    QPushButton *SendButton;
    QPushButton *loadImageButton;
    QLabel *LoadedImages;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *Users;

    void setupUi(QDialog *chatwidget)
    {
        if (chatwidget->objectName().isEmpty())
            chatwidget->setObjectName(QStringLiteral("chatwidget"));
        chatwidget->resize(911, 567);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        chatwidget->setWindowIcon(icon);
        groupBox = new QGroupBox(chatwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 893, 544));
        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(208, 0, 685, 544));
        verticalLayout = new QVBoxLayout(layoutWidget_3);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Dialog_2 = new QListWidget(layoutWidget_3);
        Dialog_2->setObjectName(QStringLiteral("Dialog_2"));
        Dialog_2->setStyleSheet(QStringLiteral("background-color: rgb(23, 23, 23)"));
        Dialog_2->setFrameShape(QFrame::Panel);
        Dialog_2->setResizeMode(QListView::Adjust);
        Dialog_2->setBatchSize(100);
        Dialog_2->setWordWrap(true);

        verticalLayout->addWidget(Dialog_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        MessageLine = new QTextEdit(layoutWidget_3);
        MessageLine->setObjectName(QStringLiteral("MessageLine"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MessageLine->sizePolicy().hasHeightForWidth());
        MessageLine->setSizePolicy(sizePolicy);
        MessageLine->setMinimumSize(QSize(556, 61));
        MessageLine->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Helvetica"));
        font.setPointSize(11);
        MessageLine->setFont(font);
        MessageLine->setStyleSheet(QLatin1String("color: silver;\n"
"selection-color: none;\n"
"\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 2px;"));
        MessageLine->setFrameShape(QFrame::Panel);

        horizontalLayout->addWidget(MessageLine);

        SendButton = new QPushButton(layoutWidget_3);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SendButton->sizePolicy().hasHeightForWidth());
        SendButton->setSizePolicy(sizePolicy1);
        SendButton->setMinimumSize(QSize(81, 61));
        SendButton->setMaximumSize(QSize(81, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Gadugi"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        SendButton->setFont(font1);
        SendButton->setCursor(QCursor(Qt::PointingHandCursor));
        SendButton->setStyleSheet(QLatin1String("QPushButton{\n"
"color: silver;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 4px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"padding: 2px;\n"
"}\n"
""));

        horizontalLayout->addWidget(SendButton);

        loadImageButton = new QPushButton(layoutWidget_3);
        loadImageButton->setObjectName(QStringLiteral("loadImageButton"));
        loadImageButton->setStyleSheet(QLatin1String("QPushButton {\n"
"image: url(\":/Image/attach.png\");\n"
"background: none;\n"
"outline:none;\n"
"border:none;\n"
"width: 32px;\n"
"height: 48px;\n"
"}\n"
""));

        horizontalLayout->addWidget(loadImageButton);


        verticalLayout->addLayout(horizontalLayout);

        LoadedImages = new QLabel(layoutWidget_3);
        LoadedImages->setObjectName(QStringLiteral("LoadedImages"));
        QFont font2;
        font2.setFamily(QStringLiteral("Gadugi"));
        font2.setPointSize(10);
        LoadedImages->setFont(font2);
        LoadedImages->setStyleSheet(QStringLiteral("color:silver;"));

        verticalLayout->addWidget(LoadedImages);

        layoutWidget_4 = new QWidget(groupBox);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(0, 0, 202, 544));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setFamily(QStringLiteral("Gadugi"));
        font3.setPointSize(12);
        label->setFont(font3);
        label->setStyleSheet(QStringLiteral("color: silver;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        Users = new QListWidget(layoutWidget_4);
        Users->setObjectName(QStringLiteral("Users"));
        Users->setMinimumSize(QSize(200, 0));
        Users->setStyleSheet(QLatin1String("color: silver;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 2px;"));
        Users->setFrameShape(QFrame::Panel);

        verticalLayout_2->addWidget(Users);


        retranslateUi(chatwidget);

        QMetaObject::connectSlotsByName(chatwidget);
    } // setupUi

    void retranslateUi(QDialog *chatwidget)
    {
        chatwidget->setWindowTitle(QApplication::translate("chatwidget", "Chat", Q_NULLPTR));
        groupBox->setTitle(QString());
        MessageLine->setHtml(QApplication::translate("chatwidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Helvetica'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        SendButton->setText(QApplication::translate("chatwidget", "Send", Q_NULLPTR));
        loadImageButton->setText(QString());
        LoadedImages->setText(QApplication::translate("chatwidget", "Selected images:", Q_NULLPTR));
        label->setText(QApplication::translate("chatwidget", "Users online", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class chatwidget: public Ui_chatwidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
