QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    AppManager.cpp \
    BoardWidget.cpp \
    CellButton.cpp \
    MainWindow.cpp \
    StatusPanel.cpp \
    WelcomeWindow.cpp \
    main.cpp

HEADERS += \
    AppManager.h \
    BoardWidget.h \
    CellButton.h \
    MainWindow.h \
    StatusPanel.h \
    WelcomeWindow.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
