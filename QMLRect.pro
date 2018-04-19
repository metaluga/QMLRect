TEMPLATE = app

QT += sql
QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    engine.cpp \
    sqliteconnector.cpp \
    connector.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    engine.h \
    sqliteconnector.h \
    connector.h
