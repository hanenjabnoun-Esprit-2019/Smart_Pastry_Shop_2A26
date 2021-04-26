#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------
QT += sql

QT       += core gui sql
QT += network
CONFIG += console
QT += printsupport
QT += multimedia
QT += charts
QT += core gui charts
QT       += core gui printsupport widgets network charts sql \
  multimedia serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += openssl-linked
SOURCES += \
    carte_fid.cpp \
    client.cpp \
    deppartement.cpp \
    employer.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    notification.cpp \
    popup.cpp \
    qcustomplot.cpp \
    smtp.cpp

HEADERS += \
    carte_fid.h \
    client.h \
    deppartement.h \
    employer.h \
        mainwindow.h \
    connection.h \
    nizar.h \
    notification.h \
    popup.h \
    qcustomplot.h \
    smtp.h

FORMS += \
        mainwindow.ui \
        nizar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc