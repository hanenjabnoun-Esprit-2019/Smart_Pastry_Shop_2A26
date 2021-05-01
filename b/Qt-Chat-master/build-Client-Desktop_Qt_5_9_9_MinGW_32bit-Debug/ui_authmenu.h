/********************************************************************************
** Form generated from reading UI file 'authmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHMENU_H
#define UI_AUTHMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthMenu
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QFormLayout *Auth;
    QLabel *LoginLabel;
    QLineEdit *Login;
    QLineEdit *Password;
    QLabel *PassLabel;
    QLabel *Status;
    QGridLayout *Sign;
    QSpacerItem *horizontalSpacer;
    QPushButton *SignButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *AuthMenu)
    {
        if (AuthMenu->objectName().isEmpty())
            AuthMenu->setObjectName(QStringLiteral("AuthMenu"));
        AuthMenu->resize(308, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthMenu->sizePolicy().hasHeightForWidth());
        AuthMenu->setSizePolicy(sizePolicy);
        AuthMenu->setMinimumSize(QSize(308, 349));
        AuthMenu->setMaximumSize(QSize(400, 500));
        AuthMenu->setStyleSheet(QStringLiteral("background: rgb(29, 29, 29)"));
        centralWidget = new QWidget(AuthMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 157, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Gadugi"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: silver;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        Auth = new QFormLayout();
        Auth->setSpacing(6);
        Auth->setObjectName(QStringLiteral("Auth"));
        LoginLabel = new QLabel(centralWidget);
        LoginLabel->setObjectName(QStringLiteral("LoginLabel"));
        LoginLabel->setMinimumSize(QSize(70, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Gadugi"));
        font1.setPointSize(12);
        LoginLabel->setFont(font1);
        LoginLabel->setAutoFillBackground(false);
        LoginLabel->setStyleSheet(QStringLiteral("color: silver;"));
        LoginLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Auth->setWidget(0, QFormLayout::LabelRole, LoginLabel);

        Login = new QLineEdit(centralWidget);
        Login->setObjectName(QStringLiteral("Login"));
        Login->setFocusPolicy(Qt::StrongFocus);
        Login->setContextMenuPolicy(Qt::DefaultContextMenu);
        Login->setAutoFillBackground(false);
        Login->setStyleSheet(QLatin1String("color: silver;\n"
"selection-color: none;\n"
"\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 2px;"));
        Login->setFrame(true);
        Login->setReadOnly(false);
        Login->setCursorMoveStyle(Qt::LogicalMoveStyle);
        Login->setClearButtonEnabled(false);

        Auth->setWidget(0, QFormLayout::FieldRole, Login);

        Password = new QLineEdit(centralWidget);
        Password->setObjectName(QStringLiteral("Password"));
        Password->setStyleSheet(QLatin1String("color: silver;\n"
"selection-color: none;\n"
"\n"
"border-width: 2px;\n"
"border-style: solid;\n"
"border-color: rgb(52, 52, 52);\n"
"padding: 2px;"));

        Auth->setWidget(1, QFormLayout::FieldRole, Password);

        PassLabel = new QLabel(centralWidget);
        PassLabel->setObjectName(QStringLiteral("PassLabel"));
        PassLabel->setFont(font1);
        PassLabel->setStyleSheet(QStringLiteral("color: silver;"));

        Auth->setWidget(1, QFormLayout::LabelRole, PassLabel);


        verticalLayout->addLayout(Auth);

        Status = new QLabel(centralWidget);
        Status->setObjectName(QStringLiteral("Status"));
        Status->setMinimumSize(QSize(0, 32));
        Status->setFont(font1);
        Status->setStyleSheet(QStringLiteral("color:rgba(255, 8, 8,150)"));
        Status->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(Status);

        Sign = new QGridLayout();
        Sign->setSpacing(6);
        Sign->setObjectName(QStringLiteral("Sign"));
        horizontalSpacer = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Sign->addItem(horizontalSpacer, 0, 0, 1, 1);

        SignButton = new QPushButton(centralWidget);
        SignButton->setObjectName(QStringLiteral("SignButton"));
        SignButton->setFont(font1);
        SignButton->setCursor(QCursor(Qt::PointingHandCursor));
        SignButton->setStyleSheet(QLatin1String("QPushButton{\n"
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
"\n"
""));

        Sign->addWidget(SignButton, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(108, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Sign->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        verticalLayout->addLayout(Sign);

        verticalSpacer = new QSpacerItem(20, 156, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        AuthMenu->setCentralWidget(centralWidget);

        retranslateUi(AuthMenu);

        QMetaObject::connectSlotsByName(AuthMenu);
    } // setupUi

    void retranslateUi(QMainWindow *AuthMenu)
    {
        AuthMenu->setWindowTitle(QApplication::translate("AuthMenu", "AuthMenu", Q_NULLPTR));
        label->setText(QApplication::translate("AuthMenu", "Qt Chat", Q_NULLPTR));
        LoginLabel->setText(QApplication::translate("AuthMenu", "Login:", Q_NULLPTR));
        PassLabel->setText(QApplication::translate("AuthMenu", "Password:", Q_NULLPTR));
        Status->setText(QString());
        SignButton->setText(QApplication::translate("AuthMenu", "Sign in", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthMenu: public Ui_AuthMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHMENU_H
