#include "p2landing.h"
#include "ui_p2landing.h"

p2Landing::p2Landing(QWidget *parent) : QWidget(parent), ui(new Ui::p2Landing)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);

    //settings icons for the landing page
    setIcons();

    //getting current date & time
    connect(&_Home, SIGNAL(newDateTime()), this, SLOT(updateDateTime()));
}

p2Landing::~p2Landing()
{
    delete ui;
}

void p2Landing::on_backToHome_clicked()
{
    emit homeFromLandingClicked();
}

void p2Landing::on_settingsButton_clicked()
{
    emit settingsClicked();
}

void p2Landing::updateDateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    emit dateTimeUpdate();
}

void p2Landing::setIcons()
{
    //setting icon for back to home button
    ui->backToHome->setIcon(QIcon("/home/pi/portalImages/home.png"));
    ui->backToHome->setIconSize(QSize(65, 65));

    //setting app icons
    ui->settingsButton->setIcon(QIcon("/home/pi/portalImages/settings-icon.jpg"));
    ui->settingsButton->setIconSize(QSize(115, 115));
}
