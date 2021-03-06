#ifndef PRIVATESCREEN_H
#define PRIVATESCREEN_H

#include "hafdisplay.h"
#include "minheap.h"
#include "historydisplay.h"
#include <QWidget>
#include <QTime>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

namespace Ui {
class PrivateScreen;
}

class PrivateScreen : public QWidget
{
    Q_OBJECT

public:
    explicit PrivateScreen(QTcpSocket* socket, QWidget *parent = 0);
    ~PrivateScreen();


private slots:
    void on_But_send_clicked();

    void on_But_close_clicked();

    void on_pushButton_clicked();

    void on_But_history_clicked();

    void Socket_sendMsg();

   void readMsg();

private:
    Ui::PrivateScreen *ui;
    Node* parent;
    HafDisplay hafWin;
    HistoryDisplay hisWin;
    QMap<QChar,qint16>* map;
    QMap<QChar,QString>* hafMap;
    QTcpSocket* tcpsocket;
    void buildHafCode(Node* node,QString str);
    void toHaf(QString gettext);
    void toHistory(QString str);
    void sendMsg(QString str);
    //bool cmp(const Record &a,const Record &b);
};





#endif // PRIVATESCREEN_H
