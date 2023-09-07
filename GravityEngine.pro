QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    body.cpp \
    bodylistwindow.cpp \
    bodywindow.cpp \
    createbodywindow.cpp \
    editbodywindow.cpp \
    engine.cpp \
    main.cpp \
    mainwindow.cpp \
    scene.cpp \
    settings.cpp \
    settingswindow.cpp \
    statisticswindow.cpp

HEADERS += \
    body.h \
    bodylistwindow.h \
    bodywindow.h \
    createbodywindow.h \
    directions.h \
    editbodywindow.h \
    engine.h \
    guiheaders.h \
    mainwindow.h \
    scene.h \
    settings.h \
    settingswindow.h \
    statisticswindow.h

FORMS += \
    bodylistwindow.ui \
    bodywindow.ui \
    mainwindow.ui \
    settingswindow.ui \
    statisticswindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
