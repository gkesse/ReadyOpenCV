TEMPLATE = app
TARGET = GOpenCV
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
RCC_DIR = build
CONFIG += console release c++11
QT += widgets
RESOURCES += resources.qrc

include(../code/GProject/src/GMain.pri)
