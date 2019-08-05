CONFIG += c++17

LIBS += -lstdc++fs

HEADERS += BatStat.h
HEADERS += options.h

SOURCES += options.cpp
SOURCES += BatStat.cpp
SOURCES += main.cpp

TARGET = battery_stat

