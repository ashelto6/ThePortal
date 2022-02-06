#include "page2.h"
#include "ui_page2.h"

Page2::Page2(QWidget *parent) : QWidget(parent), ui(new Ui::Page2)
{
    ui->setupUi(this);

    //adding pages to stacked widget
    ui->stackedWidget->addWidget(&_p2Landing); // index0
    ui->stackedWidget->addWidget(&_p2Settings); // index1
    ui->stackedWidget->addWidget(&_p2Predictions); // index2

    //connections for returning to the landing page from an app
    connect(&_p2Settings, SIGNAL(backToLandingFromSettingsClicked()), this, SLOT(toLanding()));
    connect(&_p2Predictions, SIGNAL(backToLandingFromPredictions()), this, SLOT(toLanding()));

    //connections for going into an app
    connect(&_p2Landing, SIGNAL(settingsClicked()), this, SLOT(toSettings()));
    connect(&_p2Landing, SIGNAL(predictionsClicked()), this, SLOT(toPredictions()));

    //connections for going home from a page of page2 stackedwidget
    connect(&_p2Landing, SIGNAL(homeFromLandingClicked()), this, SLOT(backHome()));
    connect(&_p2Settings, SIGNAL(homeFromSettingsClicked()), this, SLOT(backHome()));
    connect(&_p2Predictions, SIGNAL(homeFromPredictionsClicked()), this, SLOT(backHome()));

    //connections for changing wallpapers
    connect(&_p2Settings, SIGNAL(wallpaper1Clicked()), this, SLOT(setWallpaper1()));
    connect(&_p2Settings, SIGNAL(wallpaper2Clicked()), this, SLOT(setWallpaper2()));
    connect(&_p2Settings, SIGNAL(wallpaper3Clicked()), this, SLOT(setWallpaper3()));

    //update button colors of selected wallpaper
    connect(this, SIGNAL(updateWallpaper1Settings()), &_p2Settings, SLOT(updateWpSettings1()));
    connect(this, SIGNAL(updateWallpaper2Settings()), &_p2Settings, SLOT(updateWpSettings2()));
    connect(this, SIGNAL(updateWallpaper3Settings()), &_p2Settings, SLOT(updateWpSettings3()));

    //overwrite config file with updated configurations
    connect(&_p2Settings, SIGNAL(newWp1Config()), this, SLOT(writeNewWp1Config()));
    connect(&_p2Settings, SIGNAL(newWp2Config()), this, SLOT(writeNewWp2Config()));
    connect(&_p2Settings, SIGNAL(newWp3Config()), this, SLOT(writeNewWp3Config()));
}

Page2::~Page2()
{
    delete ui;
}

void Page2::backHome()
{
    emit homeClicked();
}

void Page2::toPredictions()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Page2::toSettings()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Page2::toLanding()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Page2::initWallpaperConfig1()
{
    setBackground(1);
    emit updateWallpaper1Settings();
}

void Page2::initWallpaperConfig2()
{
    setBackground(2);
    emit updateWallpaper2Settings();
}

void Page2::initWallpaperConfig3()
{
    setBackground(3);
    emit updateWallpaper3Settings();
}

void Page2::setWallpaper1()
{
    setBackground(1);
    emit wallpaper1Set();
}

void Page2::setWallpaper2()
{
    setBackground(2);
    emit wallpaper2Set();
}

void Page2::setWallpaper3()
{
    setBackground(3);
    emit wallpaper3Set();
}

void Page2::writeNewWp1Config()
{
    emit reWriteWp1Config();
}

void Page2::writeNewWp2Config()
{
    emit reWriteWp2Config();
}

void Page2::writeNewWp3Config()
{
    emit reWriteWp3Config();
}

void Page2::setBackground(int value)
{
    if (value == 1)
    {
        QPixmap bkgnd("/home/pi/portalImages/wallpaper1.jpg");
        bkgnd = bkgnd.scaled(ui->stackedWidget->widget(0)->size(), Qt::KeepAspectRatioByExpanding);
        QPalette background;
        background.setBrush(QPalette::Background, bkgnd);
        ui->stackedWidget->widget(0)->setPalette(background);
    }
    else if (value == 2)
    {
        QPixmap bkgnd("/home/pi/portalImages/wallpaper2.png");
        bkgnd = bkgnd.scaled(ui->stackedWidget->widget(0)->size(), Qt::KeepAspectRatioByExpanding);
        QPalette background;
        background.setBrush(QPalette::Background, bkgnd);
        ui->stackedWidget->widget(0)->setPalette(background);
    }
    else if (value == 3)
    {
        QPixmap bkgnd("/home/pi/portalImages/wallpaper3.jpg");
        bkgnd = bkgnd.scaled(ui->stackedWidget->widget(0)->size(), Qt::KeepAspectRatioByExpanding);
        QPalette background;
        background.setBrush(QPalette::Background, bkgnd);
        ui->stackedWidget->widget(0)->setPalette(background);
    }
}

