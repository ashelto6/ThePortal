#ifndef TEST_H
#define TEST_H

#include <QWidget>

#include "home.h"
#include "p2landing.h"
#include "globals.h"

namespace Ui {
class test;
}

class test : public QWidget
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    ~test();


signals:
    void createPage(int*);
    void numIs(int);



private slots:
    void getCount(int*);



    void get5();









    void on_pushButton_clicked();
    void LandingDateTime();


private:
    Ui::test *ui;
    Home _Home;
    int x;
    p2Landing _p2Landing;
};

#endif // TEST_H
