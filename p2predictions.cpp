#include "p2predictions.h"
#include "ui_p2predictions.h"

p2Predictions::p2Predictions(QWidget *parent) : QWidget(parent), ui(new Ui::p2Predictions)
{
    ui->setupUi(this);

    setIrisSpinBoxes();

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
    resetIrisSpinBoxes();
    ui->irisPredictionLabel->setText("");
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

void p2Predictions::on_SubmitButton_clicked()
{
    double sepalLength = ui->sepalLengthSpin->value();
    double sepalWidth = ui->sepalWidthSpin->value();
    double petalLength = ui->petalLengthSpin->value();
    double petalWidth = ui->petalWidthSpin->value();

    callIrisScript(sepalLength, sepalWidth, petalLength, petalWidth);
}

void p2Predictions::callIrisScript(double sepalLength, double sepalWidth, double petalLength, double petalWidth)
{
    QStringList params = QStringList() << "/home/pi/Documents/IrisPredictions.py" << QString::number(sepalLength) << QString::number(sepalWidth) << QString::number(petalLength) << QString::number(petalWidth);
    QProcess *process = new QProcess();
    process->start("python3", params);
    process->waitForFinished(-1);

    QString irisPrediction = process->readAll();
    ui->irisPredictionLabel->setText(irisPrediction);

    process->close();
}

void p2Predictions::setIrisSpinBoxes()
{
    ui->sepalLengthSpin->setRange(4.3,7.9);
    ui->sepalLengthSpin->setSingleStep(0.10);

    ui->sepalWidthSpin->setRange(2.0,4.4);
    ui->sepalWidthSpin->setSingleStep(0.10);

    ui->petalLengthSpin->setRange(1.0,6.9);
    ui->petalLengthSpin->setSingleStep(0.10);

    ui->petalWidthSpin->setRange(0.1,2.5);
    ui->petalWidthSpin->setSingleStep(0.10);
}

void p2Predictions::resetIrisSpinBoxes()
{
    ui->sepalLengthSpin->setValue(4.3);
    ui->sepalWidthSpin->setValue(2.0);
    ui->petalLengthSpin->setValue(1.0);
    ui->petalWidthSpin->setValue(0.1);
}

void p2Predictions::on_resetButton_clicked()
{
    resetIrisSpinBoxes();
    ui->irisPredictionLabel->setText("");
}
