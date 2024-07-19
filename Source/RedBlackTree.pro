QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    demo.cpp \
    main.cpp \
    mainwindow.cpp \
    mygraphicsview.cpp \
    rbtree.cpp \
    tabwidget.cpp \
    test.cpp \
    theory.cpp

HEADERS += \
    demo.h \
    mainwindow.h \
    mygraphicsview.h \
    rbtree.h \
    tabwidget.h \
    test.h \
    theory.h

FORMS += \
    demo.ui \
    mainwindow.ui \
    tabwidget.ui \
    test.ui \
    theory.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
