#-------------------------------------------------
#
# Project created by QtCreator 2017-06-26T17:37:22
#
#-------------------------------------------------

QT       += core gui printsupport sql
QT	+=xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeighSensor
TEMPLATE = app

#PKGCONFIG += poppler-qt4

#CONFIG += c++11 link_pkgconfig

SOURCES += main.cpp\
        index.cpp \
    page2.cpp \
    page1.cpp \
    tiaochen.cpp \
    wurenzhishou.cpp \
    jiance.cpp \
    shipinshezhi.cpp \
    erweimaguanli.cpp \
    dayin.cpp \
    page3.cpp \
    dizhi.cpp \
    dangeshedizhi.cpp \
    shezhi.cpp \
    tiaojiao.cpp \
    shuruxishutioajiao.cpp \
    shuruxishu.cpp \
    zidongtiaojiaocha.cpp \
    yajiaoqueren.cpp \
    zidongzhoujiaocha.cpp \
    yazhouqueren.cpp \
    shuzhongliangtiaojiao.cpp \
    shuruzhongliang.cpp \
    chengtaizhuangtai.cpp \
    chengtaicanshu.cpp \
    tiaochen_2.cpp \
    biaoding.cpp \
    biaoding_1.cpp \
    biaoding_2.cpp \
    anzhuangceshi.cpp \
    anzhuangceshi1.cpp \
    caishubeifen.cpp \
    canshuhuanyuan.cpp \
    chaizai.cpp \
    tongxunbaohu.cpp \
    jiandingshijian.cpp \
    andizhizucheng.cpp \
    andizhizucheng2.cpp \
    zidongzuwang.cpp \
    kongchengqueren.cpp \
    yajiaoquerendizhi.cpp \
    shuliangyuxieyi.cpp \
    wangjimima.cpp \
    yibiaoxinxi.cpp \
    jiance2.cpp \
    pcders232.cpp \
    cunchuqijiance.cpp \
    xianshipingjiance.cpp \
    beiguangliangdu.cpp \
    shouhou.cpp \
    gongdianzhuangtai.cpp \
    kaikejiance.cpp \
    erweimashengcheng.cpp \
    erweimachaxun.cpp \
    wangluoshezhi.cpp \
    yitaiwangshezhi.cpp \
    wifi.cpp \
    lanya.cpp \
    tongxunshezhi.cpp \
    ruanjiangengxin.cpp \
    chushihua.cpp \
    jiexianshiyitu.cpp \
    bangzhushouce.cpp \
    bangzhushouce1.cpp \
    quedinggengxin.cpp \
    dayincanshu.cpp \
    lishijilu.cpp \
    yiciguobang.cpp \
    erciguobang.cpp \
    shipin.cpp \
    wanzheng.cpp \
    wanzheng_chaxun.cpp \
    buwanzheng.cpp \
    buwanzheng_chaxun.cpp \
    baobiaodayin.cpp \
    qingchujillu.cpp \
    shiboqi.cpp \
    huohao.cpp \
    liuchengshezhi.cpp \
    shouyecanshu.cpp \
    mylineedit.cpp \
    chehao.cpp \
    huohaoshezhi.cpp \
    mylineedit1.cpp \
    mywidget.cpp \
    lib/tableprinter.cpp \
    previewprint.cpp \
    testpreviewdialogsetup.cpp \
    erciguobang_car.cpp \
    erciguobang_art.cpp \
    erciguobang_carname1.cpp \
    impl/widget.cpp \
    impl/weightrecordsimpl.cpp \
    impl/weightrecords.cpp \
    impl/sqliteimpl.cpp \
    impl/overweightimpl.cpp \
    impl/overweight.cpp \
    impl/caridmanagementimpl.cpp \
    impl/caridmanagement.cpp \
    impl/artidmanagementimpl.cpp \
    impl/artidmanagement.cpp \
    language/russianinputpanelcontext.cpp \
    language/russianinputpanel.cpp \
    language/myinputpannelcontext.cpp \
    language/myinputpanel.cpp \
    language/clicklabel.cpp \
    language/chnpanel.cpp \
    qrcodewidget.cpp \
    impl/userimpl.cpp \
    impl/useraliveimpl.cpp \
    impl/useralive.cpp \
    impl/user.cpp \
    impl/interface.cpp \
    impl/authinterfaceimpl.cpp \
    impl/authinterface.cpp \
    lib/documentwidget.cpp \
    window.cpp \
    lib/mydelegate.cpp \
    impl/maininterfaceimpl.cpp \
    impl/maininterface.cpp \
    lib/mytableview.cpp \
    impl/afterserviceimpl.cpp \
    impl/afterservice.cpp \
    impl/instinfoimpl.cpp \
    impl/instinfo.cpp \
    yibiaoxinxi_product.cpp \
    shouhou_product.cpp \
    impl/maininterfacetempimpl.cpp \
    impl/maininterfacetemp.cpp \
    shipin_twousb.cpp \
    lib/clickedcam.cpp \
    impl/rtspimpl.cpp \
    impl/rtsp.cpp \
    impl/ipconfigimpl.cpp \
    impl/ipconfig.cpp \
    impl/videosettingstempimpl.cpp \
    impl/videosettingstemp.cpp \
    impl/videosettingsimpl.cpp \
    impl/videosettings.cpp \
    dangexianshi.cpp \
    lib/sensorisnthread.cpp \
    lib/analysissensordata.cpp \
    impl/sensorinfoimpl.cpp \
    impl/sensorinfo.cpp \
    lib/steedythread.cpp \
    impl/weightplatformimpl.cpp \
    impl/weightplatform.cpp

HEADERS  += index.h \
    page2.h \
    page1.h \
    tiaochen.h \
    wurenzhishou.h \
    jiance.h \
    shipinshezhi.h \
    erweimaguanli.h \
    dayin.h \
    page3.h \
    dizhi.h \
    dangeshedizhi.h \
    shezhi.h \
    tiaojiao.h \
    shuruxishutioajiao.h \
    shuruxishu.h \
    zidongtiaojiaocha.h \
    yajiaoqueren.h \
    zidongzhoujiaocha.h \
    yazhouqueren.h \
    shuzhongliangtiaojiao.h \
    shuruzhongliang.h \
    chengtaizhuangtai.h \
    chengtaicanshu.h \
    tiaochen_2.h \
    biaoding.h \
    biaoding_1.h \
    biaoding_2.h \
    anzhuangceshi.h \
    anzhuangceshi1.h \
    caishubeifen.h \
    canshuhuanyuan.h \
    chaizai.h \
    tongxunbaohu.h \
    jiandingshijian.h \
    andizhizucheng.h \
    andizhizucheng2.h \
    zidongzuwang.h \
    kongchengqueren.h \
    yajiaoquerendizhi.h \
    shuliangyuxieyi.h \
    wangjimima.h \
    yibiaoxinxi.h \
    jiance2.h \
    pcders232.h \
    cunchuqijiance.h \
    xianshipingjiance.h \
    beiguangliangdu.h \
    shouhou.h \
    gongdianzhuangtai.h \
    kaikejiance.h \
    erweimashengcheng.h \
    erweimachaxun.h \
    wangluoshezhi.h \
    yitaiwangshezhi.h \
    wifi.h \
    lanya.h \
    tongxunshezhi.h \
    ruanjiangengxin.h \
    chushihua.h \
    jiexianshiyitu.h \
    bangzhushouce.h \
    bangzhushouce1.h \
    quedinggengxin.h \
    dayincanshu.h \
    lishijilu.h \
    yiciguobang.h \
    erciguobang.h \
    shipin.h \
    wanzheng.h \
    wanzheng_chaxun.h \
    buwanzheng.h \
    buwanzheng_chaxun.h \
    baobiaodayin.h \
    qingchujillu.h \
    shiboqi.h \
    huohao.h \
    liuchengshezhi.h \
    shouyecanshu.h \
    mylineedit.h \
    chehao.h \
    huohaoshezhi.h \
    mylineedit1.h \
    mywidget.h \
    lib/tableprinter.h \
    previewprint.h \
    testpreviewdialogsetup.h \
    erciguobang_car.h \
    erciguobang_art.h \
    erciguobang_carname1.h \
    impl/widget.h \
    impl/weightrecordsimpl.h \
    impl/weightrecords.h \
    impl/sqliteimpl.h \
    impl/overweightimpl.h \
    impl/overweight.h \
    impl/caridmanagementimpl.h \
    impl/caridmanagement.h \
    impl/artidmanagementimpl.h \
    impl/artidmanagement.h \
    language/russianinputpanelcontext.h \
    language/russianinputpanel.h \
    language/myinputpannelcontext.h \
    language/myinputpanel.h \
    language/clicklabel.h \
    language/chnpanel.h \
    qrcodewidget.h \
    impl/userimpl.h \
    impl/useraliveimpl.h \
    impl/useralive.h \
    impl/user.h \
    impl/interface.h \
    impl/authinterfaceimpl.h \
    impl/authinterface.h \
    lib/documentwidget.h \
    window.h \
    lib/mydelegate.h \
    impl/maininterfaceimpl.h \
    impl/maininterface.h \
    lib/mytableview.h \
    impl/afterserviceimpl.h \
    impl/afterservice.h \
    impl/instinfoimpl.h \
    impl/instinfo.h \
    yibiaoxinxi_product.h \
    shouhou_product.h \
    impl/maininterfacetempimpl.h \
    impl/maininterfacetemp.h \
    shipin_twousb.h \
    lib/clickedcam.h \
    impl/rtspimpl.h \
    impl/rtsp.h \
    impl/ipconfigimpl.h \
    impl/ipconfig.h \
    impl/videosettingstempimpl.h \
    impl/videosettingstemp.h \
    impl/videosettingsimpl.h \
    impl/videosettings.h \
    dangexianshi.h \
    lib/DataStruct.h \
    lib/sensorisnthread.h \
    lib/Mymath.h \
    lib/analysissensordata.h \
    impl/sensorinfoimpl.h \
    impl/sensorinfo.h \
    lib/steedythread.h \
    impl/weightplatformimpl.h \
    impl/weightplatform.h

FORMS    += index.ui \
    page2.ui \
    page1.ui \
    tiaochen.ui \
    wurenzhishou.ui \
    jiance.ui \
    shipinshezhi.ui \
    erweimaguanli.ui \
    dayin.ui \
    page3.ui \
    dizhi.ui \
    dangeshedizhi.ui \
    shezhi.ui \
    tiaojiao.ui \
    shuruxishutioajiao.ui \
    shuruxishu.ui \
    zidongtiaojiaocha.ui \
    yajiaoqueren.ui \
    zidongzhoujiaocha.ui \
    yazhouqueren.ui \
    shuzhongliangtiaojiao.ui \
    shuruzhongliang.ui \
    chengtaizhuangtai.ui \
    chengtaicanshu.ui \
    tiaochen_2.ui \
    biaoding.ui \
    biaoding_1.ui \
    biaoding_2.ui \
    anzhuangceshi.ui \
    anzhuangceshi1.ui \
    caishubeifen.ui \
    canshuhuanyuan.ui \
    chaizai.ui \
    tongxunbaohu.ui \
    jiandingshijian.ui \
    andizhizucheng.ui \
    andizhizucheng2.ui \
    zidongzuwang.ui \
    kongchengqueren.ui \
    yajiaoquerendizhi.ui \
    shuliangyuxieyi.ui \
    wangjimima.ui \
    yibiaoxinxi.ui \
    jiance2.ui \
    pcders232.ui \
    cunchuqijiance.ui \
    xianshipingjiance.ui \
    beiguangliangdu.ui \
    shouhou.ui \
    gongdianzhuangtai.ui \
    kaikejiance.ui \
    erweimashengcheng.ui \
    erweimachaxun.ui \
    wangluoshezhi.ui \
    yitaiwangshezhi.ui \
    wifi.ui \
    lanya.ui \
    tongxunshezhi.ui \
    ruanjiangengxin.ui \
    chushihua.ui \
    jiexianshiyitu.ui \
    bangzhushouce.ui \
    bangzhushouce1.ui \
    quedinggengxin.ui \
    dayincanshu.ui \
    lishijilu.ui \
    yiciguobang.ui \
    erciguobang.ui \
    shipin.ui \
    wanzheng.ui \
    wanzheng_chaxun.ui \
    buwanzheng.ui \
    buwanzheng_chaxun.ui \
    baobiaodayin.ui \
    qingchujillu.ui \
    shiboqi.ui \
    huohao.ui \
    liuchengshezhi.ui \
    shouyecanshu.ui \
    chehao.ui \
    huohaoshezhi.ui \
    previewprint.ui \
    testpreviewdialogsetup.ui \
    erciguobang_car.ui \
    language/russianinputpanelform.ui \
    language/myinputpanelform.ui \
    qrcode.ui \
    window.ui \
    yibiaoxinxi_product.ui \
    shouhou_product.ui \
    shipin_twousb.ui \
    dangexianshi.ui

TRANSLATIONS =WeighSensor.ts

RESOURCES += \
    myimages.qrc

#二维码PC
#INCLUDEPATH += /usr/local/include
#LIBS += -L/usr/local/lib -lqrencode

unix:!macx: LIBS += -L$$PWD/../../../home/wl/libqrencode/lib/ -lqrencode

INCLUDEPATH += $$PWD/../../../home/wl/libqrencode/include
DEPENDPATH += $$PWD/../../../home/wl/libqrencode/include

unix:!macx: LIBS += -L$$PWD/../../../home/wl/libpng/lib/ -lpng

INCLUDEPATH += $$PWD/../../../home/wl/libpng/include
DEPENDPATH += $$PWD/../../../home/wl/libpng/include

#二维码ARM
#INCLUDEPATH += /usr/local/qrencode-arm-linux/include
#LIBS += -L/usr/local/qrencode-arm-linux/lib -lqrencode

#unix:!macx: LIBS += -L$$PWD/../../usr/local/lib/ -lpng

#INCLUDEPATH += $$PWD/../../usr/local/include
#DEPENDPATH += $$PWD/../../usr/local/include

#unix:!macx: LIBS += -L$$PWD/../../usr/local/qrencode-arm-linux/lib/ -lqrencode

#INCLUDEPATH += $$PWD/../../usr/local/qrencode-arm-linux/include
#DEPENDPATH += $$PWD/../../usr/local/qrencode-arm-linux/include

#opencv-PC
INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_*.so

#opencv-ARM
#INCLUDEPATH += /usr/local/opencv-arm/include \
#                /usr/local/opencv-arm/include/opencv \
#                /usr/local/opencv-arm/include/opencv2

#LIBS += /usr/local/opencv-arm/lib/libopencv_*.so

#pdf_PC
INCLUDEPATH  += /usr/local/include/include/poppler/qt4
LIBS         += -L/usr/local/include/include/lib -lpoppler-qt4

unix:!macx: LIBS += -L$$PWD/../../../usr/local/include/lib/ -lpoppler-qt4

INCLUDEPATH += $$PWD/../../../usr/local/include/include
DEPENDPATH += $$PWD/../../../usr/local/include/include




#unix:!macx: LIBS += -L$$PWD/../../../home/wl/protocal_terminal/ -lprotocal1

#INCLUDEPATH += $$PWD/../../../home/wl/protocal_terminal
#DEPENDPATH += $$PWD/../../../home/wl/protocal_terminal

#OTHER_FILES += \
#    lib/protocal_terminal/libprotocal1.so



#unix:!macx: LIBS += -L$$PWD/../../../opt/qtcreator-2.6.2/lib/ -lprotocal1

#INCLUDEPATH += $$PWD/../../../opt/qtcreator-2.6.2
#DEPENDPATH += $$PWD/../../../opt/qtcreator-2.6.2

#opencv-PC
INCLUDEPATH += /home/wl/protocal_terminal/

LIBS += /home/wl/protocal_terminal/libprotocal1.so
