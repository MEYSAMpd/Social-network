#-------------------------------------------------
#
# Project created by QtCreator 2025-01-15T20:53:48
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FinalProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        socialnetwork.cpp \
    user.cpp \
    sign_up.cpp \
    main_user_page.cpp \
    edit_profile.cpp \
    add_note.cpp \
    other_user_page.cpp \
    suggestions.cpp \
    see_cocetions.cpp \
    edit_delete_note.cpp

HEADERS  += socialnetwork.h \
    user.h \
    sign_up.h \
    main_user_page.h \
    edit_profile.h \
    add_note.h \
    other_user_page.h \
    suggestions.h \
    see_cocetions.h \
    edit_delete_note.h

FORMS    += socialnetwork.ui \
    sign_up.ui \
    main_user_page.ui \
    edit_profile.ui \
    add_note.ui \
    other_user_page.ui \
    suggestions.ui \
    see_cocetions.ui \
    edit_delete_note.ui

FORMS    += socialnetwork.ui

RESOURCES += \
    resource.qrc

DISTFILES +=
