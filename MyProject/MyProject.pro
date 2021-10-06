QT       += core gui
QT +=charts
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
     status.cpp \
    Products.cpp \
    addpd.cpp \
    brand.cpp \
    branddialog.cpp \
    cart.cpp \
    cartwidget.cpp \
    category.cpp \
    categorydialog.cpp \
    dialogaddbrand.cpp \
    editproduct.cpp \
    informationuser.cpp \
    kind.cpp \
    lsmh.cpp \
    madein.cpp \
    madeindialog.cpp \
    main.cpp \
    managerPd.cpp \
    paywidget.cpp \
    program.cpp \
    qt_user.cpp \
    regist.cpp \
    signin.cpp \
    userdetail.cpp \
    viewdetailproduct.cpp \
    vs_user.cpp

HEADERS += \
     Products.h \
     addstatus.h \
     baocao.h \
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
     status.h \
    Products.h \
    addpd.h \
    brand.h \
    branddialog.h \
    cart.h \
    cartwidget.h \
    category.h \
    categorydialog.h \
    dialogaddbrand.h \
    editproduct.h \
    informationuser.h \
    kind.h \
    lsmh.h \
    madein.h \
    madeindialog.h \
    managerPd.h \
    paywidget.h \
    program.h \
    qt_user.h \
    regist.h \
    signin.h \
    userdetail.h \
    viewdetailproduct.h \
    vs_user.h

FORMS += \
     addstatus.ui \
     chartforph.ui \
     managerwg.ui \
     muahang.ui \
     phselect.ui \
     report.ui \
    addpd.ui \
    branddialog.ui \
    cartwidget.ui \
    categorydialog.ui \
    dialogaddbrand.ui \
    editproduct.ui \
    informationuser.ui \
    lsmh.ui \
    madeindialog.ui \
    managerPd.ui \
    paywidget.ui \
    program.ui \
    qt_user.ui \
    regist.ui \
    signin.ui \
    userdetail.ui \
    viewdetailproduct.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
     Icon/back.png \
     dataCate.txt \
     paymentlist.txt \
     purchasehstlist.txt \
     statuslist.txt \
     time.txt \
    Users.txt \
    cart/root.txt \
    dataBrand.txt \
    dataCate.txt \
    dataKind.txt \
    dataMadein.txt \
    dataProducts.txt \
    photo/find.png

SUBDIRS += \
     purchasehstmgr.pro
