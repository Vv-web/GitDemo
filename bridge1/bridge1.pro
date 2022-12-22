#-------------------------------------------------
#
# Project created by QtCreator 2020-05-25T17:48:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bridge1
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

SOURCES += \
        main.cpp \
        mainwidget.cpp \
    subwidget1.cpp \
    monitroingpoint.cpp \
    sensor.cpp \
    sensordialog.cpp \
    deletedialog.cpp \
    deflectionpointdialog.cpp

HEADERS += \
        mainwidget.h \
    subwidget1.h \
    monitroingpoint.h \
    sensor.h \
    sensordialog.h \
    deletedialog.h \
    deflectionpointdialog.h

FORMS += \
        mainwidget.ui \
    subwidget1.ui \
    sensordialog.ui \
    deletedialog.ui \
    deflectionpointdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
