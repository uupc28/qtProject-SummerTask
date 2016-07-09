#include "historydisplay.h"
#include "ui_historydisplay.h"

HistoryDisplay::HistoryDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistoryDisplay)
{
    ui->setupUi(this);
}

HistoryDisplay::~HistoryDisplay()
{
    delete ui;
}

void HistoryDisplay::on_But_close_clicked()
{
    this->close();
}

void HistoryDisplay::displayMsg(QString str)
{
    ui->textBrowser->clear();
    ui->textBrowser->append(QString("Msg:\n")+str);
}
void HistoryDisplay::displayMsgHaf(QString str)
{
    ui->textBrowser->append(QString("HafMsg:\n")+str);
}
