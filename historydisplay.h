#ifndef HISTORYDISPLAY_H
#define HISTORYDISPLAY_H

#include <QWidget>

namespace Ui {
class HistoryDisplay;
}

class HistoryDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit HistoryDisplay(QWidget *parent = 0);
    ~HistoryDisplay();
    void displayMsg(QString str);
    void displayMsgHaf(QString str);
private slots:
    void on_But_close_clicked();

private:
    Ui::HistoryDisplay *ui;
};

#endif // HISTORYDISPLAY_H
