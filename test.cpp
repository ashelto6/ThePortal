#include "test.h"
#include "ui_test.h"

test::test(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);

    connect(&_Home, SIGNAL(createButton()), this, SLOT(LandingDateTime()));
    connect(&_Home, SIGNAL(send5()), this, SLOT(get5()));
}

test::~test()
{
    delete ui;
}

void test::LandingDateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    x = GLOBALS::instance()->getNum();;
    std::string numstr = std::to_string(x);
    ui->pushButton->setText(QString::fromStdString(numstr));

}

void test::on_pushButton_clicked()
{
    int x = 10;
    emit createPage(&x);
    //getCount(&x);
    std::string numstr = std::to_string(x);
    ui->pushButton->setText(QString::fromStdString(numstr));
}

void test::getCount(int* num)
{
    int* x = num;
    *x = 20;



}


void test::get5()
{

   emit numIs(x);



}
