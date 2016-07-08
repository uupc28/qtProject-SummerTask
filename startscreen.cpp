#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);
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
           { ui->textBro_msgout->append("target IP error!");
            flag = false;
            break;
        }
    }
    if(flag)
    {
        ;
    }
    priWin.move(this->x(),this->y()+this->frameSize().height());
    priWin.show();
}

void StartScreen::on_Button_listen_clicked()
{
    tcpserver = new QTcpServer;
    if(tcpserver->listen(QHostAddress::Any,28282))   ui->textBro_msgout->append(QString("Listening port 28282..."));
    else{
        ui->textBro_msgout->append(QString("Listen port 28282 fail."));
    }
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT())
}

void StartScreen::receiveConnection()
{
    tcpsocket = tcpserver->nextPendingConnection();
}
