TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lpthread
CONFIG(release, debug|release) {
    CONFIG += optimize_full
}
SOURCES += \
        main.cpp \
    game.cpp \
    particle.cpp \
    gravityobject.cpp

HEADERS += \
    game.hpp \
    particle.hpp \
    gravityobject.hpp \
    vectorhelperfunctions.hpp
