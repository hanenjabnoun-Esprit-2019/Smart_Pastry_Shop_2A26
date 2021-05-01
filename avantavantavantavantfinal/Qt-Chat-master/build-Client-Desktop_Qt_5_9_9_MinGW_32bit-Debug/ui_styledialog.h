/********************************************************************************
** Form generated from reading UI file 'styledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STYLEDIALOG_H
#define UI_STYLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StyleDialog
{
public:
    QLabel *Pattern;
    QPushButton *selectFont;
    QPushButton *selectColor;
    QPushButton *pushButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *currentFont;
    QLabel *currentColor;

    void setupUi(QDialog *StyleDialog)
    {
        if (StyleDialog->objectName().isEmpty())
            StyleDialog->setObjectName(QStringLiteral("StyleDialog"));
        StyleDialog->resize(316, 161);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StyleDialog->sizePolicy().hasHeightForWidth());
        StyleDialog->setSizePolicy(sizePolicy);
        StyleDialog->setStyleSheet(QLatin1String("background: rgb(28, 28, 28);\n"
"color:silver;"));
        Pattern = new QLabel(StyleDialog);
        Pattern->setObjectName(QStringLiteral("Pattern"));
        Pattern->setGeometry(QRect(9, 75, 301, 41));
        QFont font;
        font.setFamily(QStringLiteral("Gadugi"));
        font.setPointSize(12);
        Pattern->setFont(font);
        Pattern->setAlignment(Qt::AlignCenter);
        selectFont = new QPushButton(StyleDialog);
        selectFont->setObjectName(QStringLiteral("selectFont"));
        selectFont->setGeometry(QRect(9, 9, 111, 27));
        selectFont->setFont(font);
        selectFont->setCursor(QCursor(Qt::PointingHandCursor));
        selectFont->setStyleSheet(QLatin1String("color: silver;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 4px;"));
        selectColor = new QPushButton(StyleDialog);
        selectColor->setObjectName(QStringLiteral("selectColor"));
        selectColor->setGeometry(QRect(9, 42, 111, 27));
        selectColor->setFont(font);
        selectColor->setCursor(QCursor(Qt::PointingHandCursor));
        selectColor->setStyleSheet(QLatin1String("color: silver;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 4px;"));
        pushButton = new QPushButton(StyleDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 120, 80, 27));
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QLatin1String("color: silver;\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 4px;"));
        layoutWidget = new QWidget(StyleDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(125, 9, 181, 61));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        currentFont = new QLabel(layoutWidget);
        currentFont->setObjectName(QStringLiteral("currentFont"));
        currentFont->setFont(font);

        verticalLayout->addWidget(currentFont);

        currentColor = new QLabel(layoutWidget);
        currentColor->setObjectName(QStringLiteral("currentColor"));
        currentColor->setFont(font);

        verticalLayout->addWidget(currentColor);


        retranslateUi(StyleDialog);

        QMetaObject::connectSlotsByName(StyleDialog);
    } // setupUi

    void retranslateUi(QDialog *StyleDialog)
    {
        StyleDialog->setWindowTitle(QApplication::translate("StyleDialog", "Dialog", Q_NULLPTR));
        Pattern->setText(QApplication::translate("StyleDialog", "Pattern", Q_NULLPTR));
        selectFont->setText(QApplication::translate("StyleDialog", "Select font", Q_NULLPTR));
        selectColor->setText(QApplication::translate("StyleDialog", "Select color", Q_NULLPTR));
        pushButton->setText(QApplication::translate("StyleDialog", "Ok", Q_NULLPTR));
        currentFont->setText(QString());
        currentColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StyleDialog: public Ui_StyleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STYLEDIALOG_H
