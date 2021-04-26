QT += sql
QT       += core gui

CONFIG += console
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

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connection.cpp \
    deppartement.cpp \
    employer.cpp \
    main.cpp \
    seif.cpp

HEADERS += \
    connection.h \
    deppartement.h \
    employer.h \
    seif.h

FORMS += \
    seif.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
