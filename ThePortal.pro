QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 console

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form.cpp \
    globals.cpp \
    home.cpp \
    main.cpp \
    mainwindow.cpp \
    p2landing.cpp \
    p2predictions.cpp \
    p2settings.cpp \
    page2.cpp \
    test.cpp \
    template.cpp

HEADERS += \
    form.h \
    globals.h \
    home.h \
    mainwindow.h \
    p2landing.h \
    p2predictions.h \
    p2settings.h \
    page2.h \
    test.h \
    template.h

FORMS += \
    form.ui \
    home.ui \
    mainwindow.ui \
    p2landing.ui \
    p2predictions.ui \
    p2settings.ui \
    page2.ui \
    test.ui \
    template.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    assets.qrc
