QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
        src/calculatercell.cpp \
        src/calculatermodel.cpp \
        src/drawermodel.cpp
        src/calculatermodel.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH += $$PWD/qml
QML2_IMPORT_PATH += $$PWD/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    qml/Calculater/qmldir \
    qml/Drawer/qmldir \
    qml/Graph/qmldir \
    qml/Header/qmldir \
    qml/ResourceProvider/qmldir \
    qml/StyleSetting/qmldir

INCLUDEPATH += $$PWD/include

HEADERS += \
    include/calculatercell.h \
    include/calculatermodel.h \
    include/drawermodel.h
    include/calculatermodel.h

