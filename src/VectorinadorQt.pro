QT       += core gui widgets opengl openglwidgets

CONFIG   += c++17

TARGET = VectorinadorQt
TEMPLATE = app

unix:!macx {
    LIBS += -lGLU
}
win32 {
    LIBS += -lglu32 -lopengl32
}

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    vectorcanvas.cpp \
    vista3d.cpp \
    vectorinador10000.cpp

HEADERS += \
    mainwindow.h \
    vectorcanvas.h \
    vista3d.h \
    vectorinador10000.hpp
