#include "p2settings.h"
#include "ui_p2settings.h"

#include <unistd.h>
#include <linux/reboot.h>
#include <sys/reboot.h>



p2Settings::p2Settings(QWidget *parent) : QWidget(parent), ui(new Ui::p2Settings)
{
    ui->setupUi(this);

    //setting icons for settings page
    setIcons();

    //setting initial bg and text color of settings type buttons
    resetSettingsButtons();

    //connection for updating date and time
    connect(&_p2Landing, SIGNAL(dateTimeUpdate()), this, SLOT(updateSettingsDateTime()));
}

p2Settings::~p2Settings()
{
    delete ui;
}

void p2Settings::on_backToLanding_clicked()
{
    resetSettingsButtons();
    ui->stackedWidget->setCurrentIndex(0);
    emit backToLandingFromSettingsClicked();
}

void p2Settings::on_backToHome_clicked()
{
    emit homeFromSettingsClicked();
}

void p2Settings::updateSettingsDateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void p2Settings::on_displaySettingsButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setSettingsTypeButton(0);
}

void p2Settings::on_networkSettingsButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    setSettingsTypeButton(1);
}

void p2Settings::on_securitySettingsButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    setSettingsTypeButton(2);
}

void p2Settings::on_systemSettingsButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    setSettingsTypeButton(3);
}

void p2Settings::on_wallpaper1Button_clicked()
{
    emit newWp1Config();
    emit wallpaper1Clicked();

    setWallpaperLabel(1);
}

void p2Settings::on_wallpaper2Button_clicked()
{
    emit newWp2Config();
    emit wallpaper2Clicked();

    setWallpaperLabel(2);
}

void p2Settings::on_wallpaper3Button_clicked()
{
    emit newWp3Config();
    emit wallpaper3Clicked();

    setWallpaperLabel(3);
}

void p2Settings::updateWpSettings1()
{
    setWallpaperLabel(1);
}

void p2Settings::updateWpSettings2()
{
    setWallpaperLabel(2);
}

void p2Settings::updateWpSettings3()
{
    setWallpaperLabel(3);
}

void p2Settings::setSettingsTypeButton(int value)
{
    if( value == 0 )
    {
        //changed pressed button background to blue, white text
        ui->displaySettingsButton_2->setAutoFillBackground(true);
        ui->displaySettingsButton_2->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->systemSettingsButton_2->setAutoFillBackground(true);
        ui->systemSettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton_2->setAutoFillBackground(true);
        ui->securitySettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton_2->setAutoFillBackground(true);
        ui->networkSettingsButton_2->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 1 )
    {
        //changed pressed button background to blue, white text
        ui->networkSettingsButton_2->setAutoFillBackground(true);
        ui->networkSettingsButton_2->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->systemSettingsButton_2->setAutoFillBackground(true);
        ui->systemSettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->displaySettingsButton_2->setAutoFillBackground(true);
        ui->displaySettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton_2->setAutoFillBackground(true);
        ui->securitySettingsButton_2->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 2 )
    {
        //changed pressed button background to blue, white text
        ui->securitySettingsButton_2->setAutoFillBackground(true);
        ui->securitySettingsButton_2->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->displaySettingsButton_2->setAutoFillBackground(true);
        ui->displaySettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->systemSettingsButton_2->setAutoFillBackground(true);
        ui->systemSettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton_2->setAutoFillBackground(true);
        ui->networkSettingsButton_2->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 3 )
    {
        //changed pressed button background to blue, white text
        ui->systemSettingsButton_2->setAutoFillBackground(true);
        ui->systemSettingsButton_2->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->displaySettingsButton_2->setAutoFillBackground(true);
        ui->displaySettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton_2->setAutoFillBackground(true);
        ui->securitySettingsButton_2->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton_2->setAutoFillBackground(true);
        ui->networkSettingsButton_2->setStyleSheet("background-color: white; color: black");
    }
}

void p2Settings::setIcons()
{
    //setting icons for settings backTo buttons
    ui->backToLanding->setIcon(QIcon("/home/pi/portalImages/back-button.png"));
    ui->backToLanding->setIconSize(QSize(65, 65));

    ui->backToHome->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome->setIconSize(QSize(65, 65));

    //setting wallpaper settings images
    ui->wallpaper1Button->setIcon(QIcon("/home/pi/portalImages/wallpaper1.jpg"));
    ui->wallpaper1Button->setIconSize(QSize(207, 140));

    ui->wallpaper2Button->setIcon(QIcon("/home/pi/portalImages/wallpaper2.png"));
    ui->wallpaper2Button->setIconSize(QSize(207, 140));

    ui->wallpaper3Button->setIcon(QIcon("/home/pi/portalImages/wallpaper3.jpg"));
    ui->wallpaper3Button->setIconSize(QSize(207, 140));
}

void p2Settings::setWallpaperLabel(int value)
{
    if( value == 1 )
    {
        ui->wallpaper1Label->setStyleSheet("background-color: blue; color: white;");
        ui->wallpaper2Label->setStyleSheet("background-color: transparent; color: black");
        ui->wallpaper3Label->setStyleSheet("background-color: transparent; color: black");
    }
    else if( value == 2 )
    {
        ui->wallpaper2Label->setStyleSheet("background-color: blue; color: white;");
        ui->wallpaper1Label->setStyleSheet("background-color: transparent; color: black");
        ui->wallpaper3Label->setStyleSheet("background-color: transparent; color: black");
    }
    else if( value == 3 )
    {
        ui->wallpaper3Label->setStyleSheet("background-color: blue; color: white;");
        ui->wallpaper1Label->setStyleSheet("background-color: transparent; color: black");
        ui->wallpaper2Label->setStyleSheet("background-color: transparent; color: black");
    }
}

void p2Settings::resetSettingsButtons()
{
    ui->displaySettingsButton_2->setAutoFillBackground(true);
    ui->displaySettingsButton_2->setStyleSheet("background-color: white; color: black");

    ui->systemSettingsButton_2->setAutoFillBackground(true);
    ui->systemSettingsButton_2->setStyleSheet("background-color: white; color: black");

    ui->securitySettingsButton_2->setAutoFillBackground(true);
    ui->securitySettingsButton_2->setStyleSheet("background-color: white; color: black");

    ui->networkSettingsButton_2->setAutoFillBackground(true);
    ui->networkSettingsButton_2->setStyleSheet("background-color: white; color: black");
}

void p2Settings::on_pushButton_clicked()
{

    QProcess process;
    process.startDetached("reboot", QStringList({}));

}

void p2Settings::on_pushButton_2_clicked()
{
    QProcess process;
    process.startDetached("shutdown -P now", QStringList({}));
}

void p2Settings::on_pushButton_3_clicked()
{
    exit(0);
}
