QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creator_of_map.cpp \
    main.cpp \
    mainscene.cpp \
    mainwindow.cpp \
    tank.cpp \
    tank2.cpp \
    wall.cpp

HEADERS += \
    creator_of_map.h \
    mainscene.h \
    mainwindow.h \
    tank.h \
    tank2.h \
    wall.h
FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    map.txt
