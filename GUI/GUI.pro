QT       += core gui
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth_reg.cpp \
    functions_for_client.cpp \
    main.cpp \
    mainwindow.cpp \
    singleton_client.cpp \
    statistics.cpp \
    task1.cpp

HEADERS += \
    auth_reg.h \
    functions_for_client.h \
    mainwindow.h \
    sha1.hpp \
    singleton_client.h \
    statistics.h \
    task1.h

FORMS += \
    auth_reg.ui \
    mainwindow.ui \
    statistics.ui \
    task1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
