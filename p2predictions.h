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

private:
    Ui::p2Predictions *ui;
};

#endif // P2PREDICTIONS_H
