QT += core
QT -= gui

CONFIG += c++11

TARGET = MCSysInfoProvider
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sysinfoprovider.cpp
include(../MCIPC/MCIPC.pri)

HEADERS += \
    sysinfoprovider.h
