TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        physicsserver.cpp \
        planet.cpp \
        sceneloader.cpp \
        tinyxml2/tinyxml2.cpp

LIBS += -lsfml-graphics -lsfml-system -lsfml-window

HEADERS += \
    funcs.h \
    physicsserver.h \
    planet.h \
    sceneloader.h \
    tinyxml2/tinyxml2.h

RESOURCES += \
    Sprites/Mars.png \
    Sprites/Earth.png \
    Scene.xml
