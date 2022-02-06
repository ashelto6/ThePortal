#include "p2predictions.h"
#include "ui_p2predictions.h"

p2Predictions::p2Predictions(QWidget *parent) : QWidget(parent), ui(new Ui::p2Predictions)
{
    ui->setupUi(this);

    //connection for updating date and time
    connect(&_p2Landing, SIGNAL(dateTimeUpdate()), this, SLOT(updatePredictionsDateTime()));
}

p2Predictions::~p2Predictions()
{
    delete ui;
}

void p2Predictions::on_minimizeButton_clicked()
{
    emit backToLandingFromPredictions();
}

void p2Predictions::on_closeButton_clicked()
{
    close();
    ui->stackedWidget->setCurrentIndex(0);
    emit backToLandingFromPredictions();
}

void p2Predictions::on_IrisNavButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void p2Predictions::on_TitanicNavButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void p2Predictions::on_BostonNavButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void p2Predictions::on_backToHome_clicked()
{
    emit homeFromPredictionsClicked();
}

void p2Predictions::updatePredictionsDateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}
