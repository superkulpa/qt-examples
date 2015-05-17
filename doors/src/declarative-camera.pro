TEMPLATE=app
TARGET=declarative-camera

CONFIG+=debug CONFIG+=declarative_debug CONFIG+=qml_debug
 
QT += quick qml multimedia

SOURCES += qmlcamera.cpp
RESOURCES += declarative-camera.qrc


#target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/declarative-camera
#INSTALLS += target

