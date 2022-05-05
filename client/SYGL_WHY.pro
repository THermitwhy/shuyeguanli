QT       += core gui
QT       += network
QT       += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    json_sy.cpp \
    main.cpp \
    mainwindow_sy.cpp \
    moer.cpp \
    qmenu_WHY.cpp \
    socket_sy.cpp \
    zujian_sy.cpp

HEADERS += \
    json_sy.h \
    mainwindow_sy.h \
    moer.h \
    qmenu_WHY.h \
    socket_sy.h \
    zujian_sy.h

TRANSLATIONS += \
    SYGL_WHY_zh_SG.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
