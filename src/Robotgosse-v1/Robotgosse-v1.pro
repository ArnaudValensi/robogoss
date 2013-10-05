#-------------------------------------------------
#
# Project created by QtCreator 2013-10-04T23:38:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotgosse-v1
TEMPLATE = app

INCLUDEPATH += "$$_PRO_FILE_PWD_/../../librairie/qextserialport/src"

win32: LIBS +=  "$$_PRO_FILE_PWD_/../../librairie/qextserialport/Qt5ExtSerialPort1.dll"
else: unix: LIBS +=  -L"$$_PRO_FILE_PWD_/../../librairie/qextserialport" -lQt5ExtSerialPort

# VLC
DEFINES += _WIN32_WINNT=0x0501
DEFINES += WINVER=0x0501

win32:INCLUDEPATH += $$(BOOST_ROOT) $$(VLC_SDK)/include

unix:LIBS += -L/usr/lib -lpthread -lvlc -g
win32:LIBS += -L$$(BOOST_ROOT)/stage/lib $$(VLC_SDK)/lib/libvlc.lib -lws2_32


SOURCES += main.cpp\
        Controller.cpp \
    Serial.cpp \
    ConnectionController.cpp \
    UDP.cpp \
    Communication.cpp \
    Video.cpp

HEADERS  += Controller.h \
    Communication.h \
    Serial.h \
    ConnectionController.h \
    UDP.h \
    define_exception.h \
    Video.h

FORMS    += controller.ui \
    Connection.ui
