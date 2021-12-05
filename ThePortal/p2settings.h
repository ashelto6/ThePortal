#ifndef P2SETTINGS_H
#define P2SETTINGS_H

#include <QWidget>

#include "p2landing.h"

namespace Ui {
class p2Settings;
}

class p2Settings : public QWidget
{
    Q_OBJECT

public:
    explicit p2Settings(QWidget *parent = nullptr);
    ~p2Settings();

signals:
    void backToLandingFromSettingsClicked();
    void homeFromSettingsClicked();

    void wallpaper1Clicked();
    void wallpaper2Clicked();
    void wallpaper3Clicked();

    void newWp1Config();
    void newWp2Config();
    void newWp3Config();

private slots:
    void on_backToLanding_clicked();

    void on_backToHome_clicked();
    void on_backToHome_2_clicked();
    void on_backToHome_3_clicked();
    void on_backToHome_4_clicked();
    void on_backToHome_5_clicked();

    void on_wallpaper1Button_clicked();
    void on_wallpaper2Button_clicked();
    void on_wallpaper3Button_clicked();

    void updateWpSettings1();
    void updateWpSettings2();
    void updateWpSettings3();

    void updateSettingsDateTime();

    void on_displaySettingsButton_clicked();
    void on_systemSettingsButton_clicked();
    void on_securitySettingsButton_clicked();
    void on_networkSettingsButton_clicked();

private:
    Ui::p2Settings *ui;
    p2Landing _p2Landing;

    void setWallpaperLabel(int);
    void resetSettingsButtons();
    void setSettingsTypeButton(int);
    void setIcons();
};

#endif // P2SETTINGS_H
