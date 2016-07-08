#include "hafdisplay.h"
#include "ui_hafdisplay.h"
#include <QDebug>

HafDisplay::HafDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HafDisplay)
{
    ui->setupUi(this);
    columun = 0;
    ui->tableWidget->horizontalHeader()->setHidden(true);
    //ui->tableWidget->resizeRowToContents(0);
    ui->tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->tableWidget->setGeometry(ui->tableWidget->x(),ui->tableWidget->y(),ui->tableWidget->width(),ui->tableWidget->height()*1.25);
}

HafDisplay::~HafDisplay()
{
    delete ui;
}
void  HafDisplay::setWordsCount(int num)
{
    ui->tableWidget->setColumnCount(num);

    if(num<=6)
    {
        for(int i=0;i<num;i++)
       {
            ui->tableWidget->setColumnWidth(i,(ui->tableWidget->width()-ui->tableWidget->verticalHeader()->width())/num);
        }

    }
    else for(int i=0;i<num;i++)
        ui->tableWidget->setColumnWidth(i,(ui->tableWidget->width()-ui->tableWidget->verticalHeader()->width())/6);
    columun = 0;
    ui->BrowhafCode->clear();
}

void HafDisplay::displayWords(QChar words, qint16 times)
{
    if(words=='\xa')  ui->tableWidget->setItem(0,columun,new QTableWidgetItem("Return"));
    else if(words==' ')ui->tableWidget->setItem(0,columun,new QTableWidgetItem("Space"));
    else ui->tableWidget->setItem(0,columun,new QTableWidgetItem(words));
    ui->tableWidget->setItem(1,columun,new QTableWidgetItem(QString::number(times,10)));
    columun++;
}

void HafDisplay::displayHafCode(QChar word, QString str)
{
    if(word=='\xa') ui->BrowhafCode->append(QString("Return")+'\t'+str);
    else if(word==' ') ui->BrowhafCode->append(QString("Space")+'\t'+str);
    else ui->BrowhafCode->append(word+'\t'+str);
}
