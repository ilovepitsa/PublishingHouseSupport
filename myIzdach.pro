QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth.cpp \
    client.cpp \
    edittyporg.cpp \
    editwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    workers.cpp

HEADERS += \
    Types.h \
    auth.h \
    client.h \
    edittyporg.h \
    editwindow.h \
    mainwindow.h \
    manager.h \
    workers.h

FORMS += \
    auth.ui \
    client.ui \
    edittyporg.ui \
    editwindow.ui \
    mainwindow.ui \
    manager.ui \
    workers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
