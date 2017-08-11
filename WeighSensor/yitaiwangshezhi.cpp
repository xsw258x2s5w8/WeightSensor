#include "yitaiwangshezhi.h"
#include "ui_yitaiwangshezhi.h"

Yitaiwangshezhi::Yitaiwangshezhi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Yitaiwangshezhi)
{
    ui->setupUi(this);

//读取数据库内的IP现实在界面上
    IpConfigImpl ipmpl;
    if(ipmpl.isExistIp()>0){
        IpConfig config = ipmpl.selectIpConfig();
        ui->lineEdit_IP->setText(config.getIp());
        ui->lineEdit_netmask->setText(config.getSubnetWay());
        ui->lineEdit_gateway->setText(config.getGateWay());
        ui->lineEdit_DNS->setText(config.getDns());
    }

    connect(ui->returnIndex,SIGNAL(clicked()),this,SLOT(returnIndex()));
    connect(ui->returnPage,SIGNAL(clicked()),this,SLOT(returnPage()));
    connect(ui->save,SIGNAL(clicked()),this,SLOT(saveInfo()));
}

Yitaiwangshezhi::~Yitaiwangshezhi()
{
    delete ui;
}

void Yitaiwangshezhi::saveInfo()
{
    //判断IP是否合法
    QString IP = ui->lineEdit_IP->text() + ".";
    QString num11 = IP.section(".",0,0);
    QString num12 = IP.section(".",1,1);
    QString num13 = IP.section(".",2,2);
    QString num14 = IP.section(".",3,3);
    //判断子网掩码是否合法
    QString mask = ui->lineEdit_netmask->text() + ".";
    int b = 0, i, n[4];
    n[3] = mask.section(".",0,0).toInt();
    n[2] = mask.section(".",1,1).toInt();
    n[1] = mask.section(".",2,2).toInt();
    n[0] = mask.section(".",3,3).toInt();
    for(i = 0; i < 4; ++i) //将子网掩码存入32位无符号整型
        b += n[i] << (i * 8);
    b = ~b + 1;
    //判断网关是否合法
    QString gateway = ui->lineEdit_gateway->text() + ".";
    QString num21 = gateway.section(".",0,0);
    QString num22 = gateway.section(".",1,1);
    QString num23 = gateway.section(".",2,2);
    QString num24 = gateway.section(".",3,3);
    if(num11 >= "0" && num11 < "256" && num12 >= "0" && num12 < "256" && num13 >= "0" && num13 < "256" && num14 >= "0" && num14 < "256")
        if((b & (b - 1)) == 0)
            if(num21 >= "0" && num21 < "256" && num22 >= "0" && num22 < "256" && num23 >= "0" && num23 < "256" && num24 >= "0" && num24 < "256"){
                //保存到数据库
                IpConfigImpl ipmpl;
                IpConfig config;
                config.setIp(ui->lineEdit_IP->text() );
                config.setSubnetWay(ui->lineEdit_netmask->text());
                config.setGateWay(ui->lineEdit_gateway->text());
                config.setDns(ui->lineEdit_DNS->text());
                if (ipmpl.insertIpConfig(config) > 0)
                    setEthernet();
            }else
                QMessageBox::warning(NULL,"网关","网关不合法！",QMessageBox::Yes,QMessageBox::Yes);
        else
            QMessageBox::warning(NULL,"子网掩码","子网掩码不合法！",QMessageBox::Yes,QMessageBox::Yes);
    else
        QMessageBox::warning(NULL,"IP","IP不合法！",QMessageBox::Yes,QMessageBox::Yes);   
}

void Yitaiwangshezhi::setEthernet()//设置以太网
{
    QProcess *process = new QProcess();//IP+子网
    QProcess *process2 = new QProcess();//网关
    process->start("ifconfig eth0 " + ui->lineEdit_IP->text() + " netmask " + ui->lineEdit_netmask->text());
    process2->start("route add default gw " + ui->lineEdit_gateway->text());
    QFile data("/etc/resolv.conf");//DNS
    if(data.open(QIODevice::WriteOnly))
    {
        QTextStream out(&data);
        out << "nameserver "<<ui->lineEdit_DNS->text();
        out.flush();
    }
    data.close();
//    ::system("/etc/resolv.conf restart ");
    QMessageBox::information(NULL,"以太网","设置成功！",QMessageBox::Yes,QMessageBox::Yes);
}

void Yitaiwangshezhi::returnIndex()
{
//    Index *menu=new Index();
//    menu->show();
    this->close();
}

void Yitaiwangshezhi::returnPage()
{
    Wangluoshezhi *returnPage=new Wangluoshezhi();
    returnPage->show();
    this->close();
}
