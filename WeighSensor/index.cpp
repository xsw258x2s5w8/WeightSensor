#include "index.h"
#include "ui_index.h"
float OpenZeroIsn=23.23;  //开机置零内码
float ManualZeroIsn=14.32; //手动置零内码
float ZeroIsn_init=32.3;//初始化计算

Index::Index(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Index)
{
    qDebug()<<OpenZeroIsn<<"dffffffffffffffffffffffffffffffffffffffffffffffffffff";
    ui->setupUi(this);
   // this->setWindowState(Qt::WindowFullScreen);

    connect(ui->menu,SIGNAL(clicked()),this,SLOT(showMenuWidget()));
    connect(ui->QRcode,SIGNAL(clicked()),this,SLOT(showQRcode()));
    connect(ui->print,SIGNAL(clicked()),this,SLOT(showPrint()));
    connect(ui->yiciguobang,SIGNAL(clicked()),this,SLOT(showYiguobang()));
    connect(ui->erciguobang,SIGNAL(clicked()),this,SLOT(showErciguobang()));
    connect(ui->shipin,SIGNAL(clicked()),this,SLOT(showShipin()));

    //接口初始化
    maininterfacetempimpl=new MainInterfaceTempImpl();

    //以太网初始化
    InitEthernet();

    //视频设置初始化
    VideoInit();

    //IP视频初始化
    IPvideoInit();

    //开启ip摄像头    

    //动态生成界面字段
    showLineEdit();

//    //开启ip摄像头
//    const string videoStreamAddress = "rtsp://admin:123456@192.168.1.105:10554/udp/av0_0";
//    if(!vcap.open(videoStreamAddress)) {
//        cout << "Error opening video stream or file" << endl;
//        return ;
//    }else
//        cout<<"success"<<endl;
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(readframe()));
//    connect(timer, SIGNAL(timeout()), this, SLOT(showImage()));
//    timer->start(33);
}

Index::~Index()
{
    delete ui;
}

void Index::InitEthernet()//初始化以太网
{
    //读取数据库网络设置
    IpConfigImpl ipmpl;
    if(ipmpl.isExistIp() > 0){//判断IP信息
        QString IP,netmask,gateway;
        //赋值
        IpConfig config = ipmpl.selectIpConfig();
        IP = config.getIp();
        netmask = config.getSubnetWay();
        gateway = config.getGateWay();
        QProcess *process = new QProcess();//IP+子网
        QProcess *process2 = new QProcess();//网关
        process->start("ifconfig eth0 " + IP + " netmask " + netmask);
        process2->start("route add default gw " + gateway);
    }
}

void Index::VideoInit()
{
    VideoSettingsTempImpl videotempimpl;
    if(videotempimpl.isExistVideoSettings() < 0){//判断视频设置临时表是否有数据，若有数据先删除
        VideoSettingsTemp videotemp;
        VideoSettingsImpl videompl;
        VideoSettings video;
        video = videompl.selectVideoSettingByFormat("流畅");//根据视频格式查找格式id
        videotemp.setIsOpenCamera(0);//将视频设置信息存入临时表
        videotemp.setCompcRatio(80);
        videotemp.setId(video.getVideoFormatId());
        videotempimpl.insertVideoSettings(videotemp);
    }
}

void Index::IPvideoInit()
{
    //读取数据库视频设置，第一次开机，无视频
//    int first =  ;//判断是否第一次开机
//    RTSPimpl rtspmpl;
//    RTSP rtsp = rtspmpl.selectRtspById(1);
//    if(rtsp.getId() < 0)
//        ;
//    else{//读取数据库第一个IP摄像头的IP
//        QString firstCamIP =  ;//RTSP
//        const string videoStreamAddress = firstCamIP;    //"rtsp://admin:123456@192.168.1.105:10554/udp/av0_0";
//        if(!vcap.open(videoStreamAddress)) {
//            cout << "Error opening video stream or file" << endl;
//            return ;
//        }else
//            cout<<"success"<<endl;
//     int firstshipinshezhi =   ;//读取视频清晰度的设置
//    if(firstshipinshezhi < 0)
//        ;
//    else
//        ;//设置视频清晰度
//    }
}

void Index::showMenuWidget()
{
    page2 *menu=new page2();
    menu->show(); //open menu Widget
//    this->close();  //close parent Widget
}

void Index::showQRcode()
{
    Erweimaguanli *showQRcode=new Erweimaguanli();
    showQRcode->show();
//    this->close();
}

void Index::showPrint()
{
    Lishijilu *showPrint=new Lishijilu();
    showPrint->show();
//    this->close();
}

void Index::showYiguobang()
{
    Yiciguobang *showYiguobang=new Yiciguobang();
    showYiguobang->setCarWeight(ui->weight_label->text());//获取重量
    showYiguobang->setCarTare(ui->lineEdit->text());//获取预设皮重


    //发送字段编辑框里的数据
    QStringList strList;
    strList.append(ui->lineEdit_carId->text());
    strList.append(ui->lineEdit_artId->text());
    qDebug()<<"主页index："<<listLedit.length();
    for(int i=0;i<listLedit.length();i++){
        strList.append(listLedit[i]->text());
    }

    showYiguobang->showData(strList);//根据字段生成界面内容

    showYiguobang->show();
//    this->close();
}

void Index::showErciguobang()
{
    Erciguobang *showErciguobang=new Erciguobang();
    showErciguobang->setcarWeight(ui->weight_label->text());//获取称出重量

    //发送字段编辑框里的数据
    QStringList strList;
    strList.append(ui->lineEdit_carId->text());
    strList.append(ui->lineEdit_artId->text());
    qDebug()<<"主页index："<<listLedit.length();
    for(int i=0;i<listLedit.length();i++){
        strList.append(listLedit[i]->text());
    }

    showErciguobang->showData(strList);  //进入二次过磅页面的显示

    showErciguobang->show();
//    this->close();
}

void Index::showShipin()
{
    Shipin *showShipin = new Shipin();
    showShipin->show();
//    this->close();
}

void Index::readframe()
{
 //   int counter = 0;
 //   for(;;){
 //       counter++;
        if(!vcap.read(frame))
        {
            cout << "No frame" << endl;
            waitKey();
        }
//        if (counter %2!= 0)
//            continue;
//        cv::imshow("Output Window", image);
//        double rate=vcap.get(CV_CAP_PROP_FPS);
//        std::cout<<"帧率为:"<<rate<<std::endl;
//        if(cv::waitKey(1) >= 0) break;
//   }
}

QImage Mat2QImage(Mat cvImg)
{
    QImage qImg;
    if (cvImg.channels() == 3)                             //3 channels color image
    {

        cvtColor(cvImg, cvImg, CV_BGR2RGB);
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_RGB888);
    }
    else if (cvImg.channels() == 1)                    //grayscale image
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_Indexed8);
    }
    else
    {
        qImg = QImage((const unsigned char*)(cvImg.data),
               cvImg.cols, cvImg.rows,
               cvImg.cols*cvImg.channels(),
               QImage::Format_RGB888);
    }

    return qImg;
}

void Index::showImage()
{
    vcap >> frame;
    realimage = Mat2QImage(frame);
    int Owidth = realimage.width(),Oheight = realimage.height();
//    cout<<Owidth<<","<<Oheight<<endl;
    int Fwidth,Fheight;       //缩放后的图片大小
    int Mul;
    if(Owidth/ui->iplabel->width() >= Oheight/ui->iplabel->height())
        Mul=Owidth/ui->iplabel->width();
    else
        Mul=Oheight/ui->iplabel->height();
    Fwidth=Owidth/Mul;
    Fheight=Oheight/Mul;//记录图片与label大小的比例，用于缩放图片
    image = realimage.scaled(Fwidth,Fheight,Qt::KeepAspectRatio);
    ui->iplabel->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
}


void Index::showLineEdit()
{
    //先获取临时表中的字段
    QList<MainInterfaceTemp> list=maininterfacetempimpl->selectMainInterfaceTemp();

    //遍历list，序号从3 开始是因为前面三条是固定下来的
    for(int i=3;i<list.length();i++){
       MainInterfaceTemp temp;
       temp=list.at(i);


       //创建部件
       QLabel *label=new QLabel(temp.getOtherName());
       QLineEdit *lineEdit=new QLineEdit();
       lineEdit->setObjectName("lineEdit_"+temp.getPara());

       int row;//用于确定插入第几行

       // i为3时 实际代表的是第4个部件
       if(i%2==0){  //偶数情况实际是奇数位的部件 插入gridlaout的 0,1

           row=i/2;  //  这里row假设为2，显示的是第三行

           //添加到布局
           ui->gridLayout->addWidget(label,row,0);
           ui->gridLayout->addWidget(lineEdit,row,1);
       }else if(i%2==1){ //奇数情况 插入gridlayout 2,3
           //确定行数
           row=(i-1)/2;

           //添加到布局
           ui->gridLayout->addWidget(label,row,2);
           ui->gridLayout->addWidget(lineEdit,row,3);

       }

       //添加
       listLedit.append(lineEdit);
    }


}


void Index::generateEdit()
{
}
