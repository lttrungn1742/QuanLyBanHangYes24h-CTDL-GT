QT       += core gui
QT       += charts
requires(qtConfig(combobox))
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Products.cpp \
    addstatus.cpp \
    brand.cpp \
    category.cpp \
    chartforph.cpp \
    drilldownchart.cpp \
    drilldownslice.cpp \
    fuctionchung.cpp \
    kind.cpp \
    madein.cpp \
    main.cpp \
    managerwg.cpp \
    monthhd.cpp \
    muahang.cpp \
    payment.cpp \
    phselect.cpp \
    purchasehst.cpp \
    report.cpp \
    statistics.cpp \
    status.cpp

HEADERS += \
    Products.h \
    addstatus.h \
    brand.h \
    category.h \
    chartforph.h \
    drilldownchart.h \
    drilldownslice.h \
    fuctionchung.h \
    kind.h \
    madein.h \
    managerwg.h \
    monthhd.h \
    muahang.h \
    payment.h \
    phselect.h \
    purchasehst.h \
    report.h \
    statistics.h \
    status.h

FORMS += \
    addstatus.ui \
    chartforph.ui \
    managerwg.ui \
    muahang.ui \
    phselect.ui \
    report.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Icon/back.png \
    dataCate.txt \
    paymentlist.txt \
    photo/find.png \
    photo/productImage.png \
    photo/them.png \
    photo/xoa.png \
    photoProducts/000000000.png \
    photoProducts/000000002.png \
    photoProducts/000003001.png \
    photoProducts/020004004.png \
    photoProducts/020200013.png \
    purchasehstlist.txt \
    statuslist.txt \
    time.txt
