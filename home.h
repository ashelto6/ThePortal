#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QTimer>
#include <QFont>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>

#include "globals.h"

#include <pthread.h>

namespace Ui {
class Home;
}

class Home : public QWidget
{
    Q_OBJECT

public:
    explicit Home(QWidget *parent = nullptr);
    ~Home();
    static void* relayThreadFn(void* arg);
    void runThread();

signals:
    void nextClicked();
    void newDateTime();
    void newPage();
    void createButton();
    void go();
    void send5();

private slots:
    void on_changePage_clicked();
    void on_dial_valueChanged(int value);
    void on_dial_2_valueChanged(int value);

    void updateTime();
    void createNewPage();

    void onpushButtonclicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Home *ui;
    bool _unlocked[2] = {false}; //left dial is _unlocked[0] right dial is _unlocked[1]
    int _dialPos = rand() % 356 + 2; //random position for left dial
    int _dial2Pos = rand() % 356 + 2; //random position for right dial
    QGraphicsDropShadowEffect *_bodyShadowDial = new QGraphicsDropShadowEffect,
                              *_bodyShadowDial2 = new QGraphicsDropShadowEffect;

    void setDials();
};

#endif // HOME_H
