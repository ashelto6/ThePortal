#include "p2predictions.h"
#include "ui_p2predictions.h"

p2Predictions::p2Predictions(QWidget *parent) : QWidget(parent), ui(new Ui::p2Predictions)
{
    ui->setupUi(this);
}

p2Predictions::~p2Predictions()
{
    delete ui;
}
