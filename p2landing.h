#ifndef P2LANDING_H
#define P2LANDING_H

#include <QWidget>

#include "home.h"

namespace Ui {
class p2Landing;
}

class p2Landing : public QWidget
{
    Q_OBJECT

public:
    explicit p2Landing(QWidget *parent = nullptr);
    ~p2Landing();

signals:
    void homeFromLandingClicked();
    void settingsClicked();
    void predictionsClicked();

    void dateTimeUpdate();

private slots:
    void on_backToHome_clicked();
    void on_predictionsButton_clicked();
    void on_settingsButton_clicked();

    void updateLandingDateTime();

private:
    Ui::p2Landing *ui;
    Home _Home;

    void setIcons();
};

#endif // P2LANDING_H
