#-------------------------------------------------
#
# Project created by QtCreator 2015-09-20T14:34:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Lokaverkefni
TEMPLATE = app


SOURCES += main.cpp \
    uiproto.cpp

HEADERS  += \
    uiproto.h

FORMS    += \
    uiproto.ui

INCLUDEPATH += C:/programs/opencvold/build/include

LIBS += -LC:/programs/opencvold/freshbuild/lib/Debug \
    -lopencv_calib3d2411d \
    -lopencv_contrib2411d \
    -lopencv_core2411d \
    -lopencv_features2d2411d \
    -lopencv_flann2411d \
    -lopencv_gpu2411d \
    -lopencv_haartraining_engined \
    -lopencv_highgui2411d \
    -lopencv_imgproc2411d \
    -lopencv_legacy2411d \
    -lopencv_ml2411d \
    -lopencv_nonfree2411d \
    -lopencv_objdetect2411d \
    -lopencv_ocl2411d \
    -lopencv_photo2411d \
    -lopencv_stitching2411d \
    -lopencv_superres2411d \
    -lopencv_ts2411d \
    -lopencv_video2411d \
    -lopencv_videostab2411d \
    -lopencv_ml2411d
