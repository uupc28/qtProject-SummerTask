#ifndef HAFDISPLAY_H
#define HAFDISPLAY_H

#include <QWidget>

namespace Ui {
class HafDisplay;
}

class HafDisplay : public QWidget
{
    Q_OBJECT

public:
    explicit HafDisplay(QWidget *parent = 0);
    ~HafDisplay();
    void displayWords(QChar words, qint16 times);
    void setWordsCount(int num);
    void displayHafCode(QChar word,QString str);

private:
    Ui::HafDisplay *ui;
    int columun;
};

#endif // HAFDISPLAY_H
