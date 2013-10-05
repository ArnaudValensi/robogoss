#-------------------------------------------------
#
# Project created by QtCreator 2013-10-04T23:38:58
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Robotgosse-v1
TEMPLATE = app
LIB_PATH = "$$_PRO_FILE_PWD_/../../librairie"

CONFIG(release, debug|release): DESTDIR = $$OUT_PWD/release
CONFIG(debug, debug|release): DESTDIR = $$OUT_PWD/debug

DLLFiles.path = $$DESTDIR
DLLFiles.files += $$files("$$LIB_PATH/vlc/*.dll")
DLLFiles.files += $$files("$$LIB_PATH/qextserialport/Qt5ExtSerialPort1.dll")
INSTALLS += DLLFiles

INCLUDEPATH += "$$LIB_PATH/qextserialport/src"

win32: LIBS +=  "$$LIB_PATH/qextserialport/Qt5ExtSerialPort1.dll"
else: unix: LIBS +=  -L"$$LIB_PATH/qextserialport" -lQt5ExtSerialPort

# VLC
DEFINES += _WIN32_WINNT=0x0501
DEFINES += WINVER=0x0501

win32:INCLUDEPATH += $$LIB_PATH/vlc/include

unix:LIBS += -L/usr/lib -lpthread -lvlc -g
win32:LIBS += $$LIB_PATH/vlc/lib/libvlc.lib -lws2_32


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
