#include "privatescreen.h"
#include "ui_privatescreen.h"
#include "qdebug.h"
#include <iostream>
#include <QTextCodec>
#include <QMap>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

PrivateScreen::PrivateScreen(QTcpSocket* socket,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PrivateScreen)
{
    ui->setupUi(this);
    map = new QMap<QChar,qint16>;
    hafMap = new QMap<QChar,QString>;
    tcpsocket = socket;
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(readMsg()));
    connect(tcpsocket,SIGNAL(bytesWritten(qint64)),this,SLOT(Socket_sendMsg()));
}

PrivateScreen::~PrivateScreen()
{
    delete ui;
}

void PrivateScreen::on_But_send_clicked()
{    
     QString gettext = ui->textEdit->toPlainText();
     if(gettext.length()==0)  return;
     toHaf(gettext);
     toHistory(gettext);
     sendMsg(gettext);
}

void PrivateScreen::toHaf(QString gettext)
{
    map->clear();
    for(int i=0;i<gettext.length();i++)
    {
        if(map->find(gettext[i])==map->end())   map->insert(gettext[i],1);
        else    map->insert(gettext[i],map->find(gettext[i]).value()+1);
    }
    MinHeap heap(map->count());
    hafWin.setWordsCount(0);
    hafWin.setWordsCount(map->count());
    for ( QMap<QChar,qint16>::iterator it = map->begin(); it != map->end(); it++ )
    {
                hafWin.displayWords(it.key(),it.value());
               heap.insert(new Node(it.key(),it.value()));
    }
   Node*first,*second;
   for(int i=1;i<=map->count()-1;i++)
   {
       first = heap.reMini();
       second = heap.reMini();
       parent = new Node(first->weight+second->weight);
       parent->left=first; parent->right = second;
       heap.insert(parent);
   }
   hafMap->clear();
   qDebug()<<"count: "<<map->count();
   if(map->count()==1)
   {
       hafWin.displayHafCode(map->begin().key(),"0");
       hafMap->insert(map->begin().key(),QString("0"));
       return;
   }
   buildHafCode(parent,"");
   for(QMap<QChar,QString>::iterator it = hafMap->begin();it!=hafMap->end();it++)
       hafWin.displayHafCode(it.key(),it.value());
}

void PrivateScreen::on_But_close_clicked()
{
    hafWin.close();
    hisWin.close();
    this->close();
}

void PrivateScreen::on_pushButton_clicked()
{
    hafWin.move(this->x()-1.4*this->frameSize().width(),this->y());
    hafWin.show();
}

void PrivateScreen::buildHafCode(Node *node, QString str)
{
    if(!node->left&&!node->right)
    {
        qDebug()<<node->value<<' '<<str;
        hafMap->insert(node->value,str);
    }
    if(node->left)  buildHafCode(node->left,str+'0');
    if(node->right) buildHafCode(node->right,str+'1');
}

void PrivateScreen::on_But_history_clicked()
{
   hisWin.move(this->x()-this->frameSize().width(),this->y()+this->frameSize().height());
   hisWin.show();
}

void PrivateScreen::toHistory(QString str)
{
    QString hafStr = "";
    for(int i=0;i<str.length();i++)
    {
        hafStr+=hafMap->find(str[i]).value();
    }
    hisWin.displayMsg(str);
    hisWin.displayMsgHaf(hafStr);
}

void PrivateScreen::readMsg()
{
    QString str = tcpsocket->readAll();
    ui->textBrowser->append(str);
}

void PrivateScreen::Socket_sendMsg()
{
    qDebug()<<"send success";
}

void PrivateScreen::sendMsg(QString str)
{
    tcpsocket->write(str.toStdString().data(),str.length());
}
