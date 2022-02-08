#ifndef P2PREDICTIONS_H
#define P2PREDICTIONS_H

#include <QWidget>

#include "p2landing.h"

namespace Ui {
class p2Predictions;
}

class p2Predictions : public QWidget
{
    Q_OBJECT

public:
    explicit p2Predictions(QWidget *parent = nullptr);
    ~p2Predictions();

signals:
    void backToLandingFromPredictions();
    void homeFromPredictionsClicked();

private slots:
    void on_minimizeButton_clicked();
    void on_closeButton_clicked();
    void on_backToHome_clicked();
    void on_SubmitButton_clicked();
    void on_resetButton_clicked();

    void on_IrisNavButton_clicked();
    void on_TitanicNavButton_clicked();
    void on_BostonNavButton_clicked();

    void updatePredictionsDateTime();

private:
    Ui::p2Predictions *ui;
    p2Landing _p2Landing;

    void callIrisScript(double, double, double, double);
    void setIrisSpinBoxes();
    void resetIrisSpinBoxes();
};

#endif // P2PREDICTIONS_H
