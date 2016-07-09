#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "privatescreen.h"
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QWidget>

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = 0);
    ~StartScreen();

private slots:
    void on_Button_exit_clicked();

    void on_Button_connect_clicked();

    void on_Button_listen_clicked();

    void slotShow();

    void getConnection();

private:
    Ui::StartScreen *ui;
    PrivateScreen* priWin;
    QTcpServer* tcpserver;
    QTcpSocket* tcpsocket;
};

#endif // STARTSCREEN_H
