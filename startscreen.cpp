#include "startscreen.h"
#include "ui_startscreen.h"
#include <QNetworkInterface>


StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);
    QList<QHostAddress> list=QNetworkInterface::allAddresses();
    foreach(QHostAddress address,list)
    {
        if(address.protocol()==QAbstractSocket::IPv4Protocol&&address.toString()!=QString("127.0.0.1"))
        {
           ui->lab_IP_W->setText(address.toString());
           break;
        }
    }
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::on_Button_exit_clicked()
{
    this->close();
}

void StartScreen::on_Button_connect_clicked()
{
    QString tarIp_text = ui->LineEdit_TargetIp->text();
   bool flag = true;
    for(int i=0;i<tarIp_text.length();i++)
    {
        if(tarIp_text[i]!='.'&&(tarIp_text[i]<'0'||tarIp_text[i]>'9'))
        {
            ui->textBro_msgout->append("target IP error!");
            flag = false;
            break;
        }
    }
    if(flag)
    {
        tcpsocket = new QTcpSocket(this);
       tcpsocket->connectToHost(QHostAddress(tarIp_text),ui->Edit_conPort->text().toInt());
        ui->textBro_msgout->append(QString("connect to ")+tarIp_text);
       priWin = new PrivateScreen(tcpsocket);
       priWin->show();
    }
}

void StartScreen::on_Button_listen_clicked()
{
    tcpserver = new QTcpServer(this);
    tcpserver->listen(QHostAddress::Any,ui->Edit_lisPort->text().toInt()) ;
    ui->textBro_msgout->append(QString("Listening port success"));
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(getConnection()));
}

void StartScreen::getConnection()
{

    tcpsocket = tcpserver->nextPendingConnection();
    ui->textBro_msgout->append(QString("receive connect from ")+tcpsocket->peerAddress().toString());
    qDebug()<<"run";
    priWin = new PrivateScreen(tcpsocket);
    priWin->show();
}

void StartScreen::slotShow()
{
    ui->textBro_msgout->append(QString("connect success"));
}


