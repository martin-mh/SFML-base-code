TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    application.cpp \
    engine/animatedspritenode.cpp \
    engine/command.cpp \
    engine/commandqueue.cpp \
    engine/entity.cpp \
    engine/paralleltask.cpp \
    engine/resourceholder.inl \
    engine/scenenode.cpp \
    engine/spritenode.cpp \
    engine/state.cpp \
    engine/statestack.cpp \
    engine/textnode.cpp \
    engine/utility.cpp \
    engine/gui/button.cpp \
    engine/gui/component.cpp \
    engine/gui/container.cpp \
    engine/gui/label.cpp \
    game/character.cpp \
    game/datatables.cpp \
    game/gamestate.cpp \
    game/level_datatables.cpp \
    game/player.cpp \
    game/world.cpp \
    menu/menustate.cpp \
    title/titlestate.cpp

HEADERS += \
    application.h \
    resourceidentifiers.h \
    stateidentifiers.h \
    engine/animatedspritenode.h \
    engine/command.h \
    engine/commandqueue.h \
    engine/entity.h \
    engine/paralleltask.h \
    engine/resourceholder.h \
    engine/scenenode.h \
    engine/spritenode.h \
    engine/state.h \
    engine/statestack.h \
    engine/textnode.h \
    engine/utility.h \
    engine/gui/button.h \
    engine/gui/component.h \
    engine/gui/container.h \
    engine/gui/label.h \
    game/category.h \
    game/character.h \
    game/datatables.h \
    game/gamestate.h \
    game/player.h \
    game/world.h \
    menu/menustate.h \
    title/titlestate.h

LIBS += -L"/home/imote/Development/SFML-build/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "/home/imote/Development/SFML/include"
DEPENDPATH += "/home/imote/Development/SFML/include"

