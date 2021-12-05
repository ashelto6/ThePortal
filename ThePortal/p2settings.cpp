#include "p2settings.h"
#include "ui_p2settings.h"

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

void p2Settings::on_backToHome_2_clicked()
{
    emit homeFromSettingsClicked();
}

void p2Settings::on_backToHome_3_clicked()
{
    emit homeFromSettingsClicked();
}

void p2Settings::on_backToHome_4_clicked()
{
    emit homeFromSettingsClicked();
}

void p2Settings::on_backToHome_5_clicked()
{
    emit homeFromSettingsClicked();
}

void p2Settings::updateSettingsDateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_2->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_3->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_4->setDateTime(QDateTime::currentDateTime());
    ui->dateTimeEdit_5->setDateTime(QDateTime::currentDateTime());
}

void p2Settings::on_displaySettingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    setSettingsTypeButton(0);
}

void p2Settings::on_networkSettingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    setSettingsTypeButton(1);
}

void p2Settings::on_securitySettingsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    setSettingsTypeButton(2);
}

void p2Settings::on_systemSettingsButton_clicked()
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
        ui->displaySettingsButton->setAutoFillBackground(true);
        ui->displaySettingsButton->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->systemSettingsButton->setAutoFillBackground(true);
        ui->systemSettingsButton->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton->setAutoFillBackground(true);
        ui->securitySettingsButton->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton->setAutoFillBackground(true);
        ui->networkSettingsButton->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 1 )
    {
        //changed pressed button background to blue, white text
        ui->networkSettingsButton->setAutoFillBackground(true);
        ui->networkSettingsButton->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->systemSettingsButton->setAutoFillBackground(true);
        ui->systemSettingsButton->setStyleSheet("background-color: white; color: black");

        ui->displaySettingsButton->setAutoFillBackground(true);
        ui->displaySettingsButton->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton->setAutoFillBackground(true);
        ui->securitySettingsButton->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 2 )
    {
        //changed pressed button background to blue, white text
        ui->securitySettingsButton->setAutoFillBackground(true);
        ui->securitySettingsButton->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->displaySettingsButton->setAutoFillBackground(true);
        ui->displaySettingsButton->setStyleSheet("background-color: white; color: black");

        ui->systemSettingsButton->setAutoFillBackground(true);
        ui->systemSettingsButton->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton->setAutoFillBackground(true);
        ui->networkSettingsButton->setStyleSheet("background-color: white; color: black");
    }
    else if( value == 3 )
    {
        //changed pressed button background to blue, white text
        ui->systemSettingsButton->setAutoFillBackground(true);
        ui->systemSettingsButton->setStyleSheet("background-color: blue; color: white");

        //change other buttons to white background. black text
        ui->displaySettingsButton->setAutoFillBackground(true);
        ui->displaySettingsButton->setStyleSheet("background-color: white; color: black");

        ui->securitySettingsButton->setAutoFillBackground(true);
        ui->securitySettingsButton->setStyleSheet("background-color: white; color: black");

        ui->networkSettingsButton->setAutoFillBackground(true);
        ui->networkSettingsButton->setStyleSheet("background-color: white; color: black");
    }
}

void p2Settings::setIcons()
{
    //setting icons for settings backTo buttons
    ui->backToLanding->setIcon(QIcon("/home/pi/portalImages/back-button.png"));
    ui->backToLanding->setIconSize(QSize(65, 65));

    ui->backToHome->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome->setIconSize(QSize(65, 65));

    ui->backToHome_2->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome_2->setIconSize(QSize(65, 65));

    ui->backToHome_3->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome_3->setIconSize(QSize(65, 65));

    ui->backToHome_4->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome_4->setIconSize(QSize(65, 65));

    ui->backToHome_5->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome_5->setIconSize(QSize(65, 65));

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
    ui->displaySettingsButton->setAutoFillBackground(true);
    ui->displaySettingsButton->setStyleSheet("background-color: white; color: black");

    ui->systemSettingsButton->setAutoFillBackground(true);
    ui->systemSettingsButton->setStyleSheet("background-color: white; color: black");

    ui->securitySettingsButton->setAutoFillBackground(true);
    ui->securitySettingsButton->setStyleSheet("background-color: white; color: black");

    ui->networkSettingsButton->setAutoFillBackground(true);
    ui->networkSettingsButton->setStyleSheet("background-color: white; color: black");
}
