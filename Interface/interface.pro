QT -= gui
QT += widgets
QT += qml
QT += quick
QT += network

CONFIG += c++11 console
CONFIG -= app_bundle
QT += gui qml quick

# The following lines tells Qmake to use pkg-config for opencv
QT_CONFIG -= no-pkg-config
CONFIG  += link_pkgconfig
#PKGCONFIG += opencv4


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
        backend.cpp \
        localserver.cpp \
        main.cpp \
        qtcp_server.cpp \
        thread.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    main.qrc

HEADERS += \
    backend.h \
    localserver.h \
    qtcp_server.h \
    thread.h
