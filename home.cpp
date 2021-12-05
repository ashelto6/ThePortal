#include "home.h"
#include "ui_home.h"

Home::Home(QWidget *parent) : QWidget(parent), ui(new Ui::Home)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);

    //setting initial state of dials
    setDials();

    //changing label font size
    QFont font = ui->label->font();
    font.setPointSize(18);
    font.setBold(true);
    ui->label->setFont(font);

    //set default button to locked
    ui->changePage->setIcon(QIcon("/home/pi/portalImages/lock-icon.png"));
    ui->changePage->setIconSize(QSize(65, 65));

    //getting current date and time
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);
}

Home::~Home()
{
    delete ui;
}

void Home::on_changePage_clicked()
{
    if(_unlocked[0] && _unlocked[1])
        emit nextClicked();
    else
        QMessageBox::warning(this, "Dials not ready", "Dials must be in \"Ready\" position",
                             QMessageBox::Ok);
}

void Home::updateTime()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    emit newDateTime();
}

void Home::setDials()
{
    //setting initial shadow color for dials
    _bodyShadowDial->setBlurRadius(30.0);
    _bodyShadowDial->setColor(QColor(200, 0, 0));
    _bodyShadowDial->setOffset(0.0);
    ui->dial->setGraphicsEffect(_bodyShadowDial);
    ui->dial->setRange(0,359);

    _bodyShadowDial2->setBlurRadius(30.0);
    _bodyShadowDial2->setColor(QColor(200, 0, 0));
    _bodyShadowDial2->setOffset(0.0);
    ui->dial_2->setGraphicsEffect(_bodyShadowDial2);
    ui->dial_2->setRange(0,359);
}

void Home::on_dial_valueChanged(int value)
{
    if(value == _dialPos || value == _dialPos+1 || value == _dialPos-1)
    {
        _bodyShadowDial->setColor(QColor(0, 200, 0));
        _unlocked[0] = true;
        if(_unlocked[1])
            ui->changePage->setIcon(QIcon("/home/pi/portalImages/home.png"));
        else
            ui->changePage->setIcon(QIcon("/home/pi/portalImages/lock-icon.png"));
    }
    else
    {
        _bodyShadowDial->setColor(QColor(200, 0, 0));
        _unlocked[0] = false;
        ui->changePage->setIcon(QIcon("/home/pi/portalImages/lock-icon.png"));
    }
}

void Home::on_dial_2_valueChanged(int value)
{
    if(value == _dial2Pos || value == _dial2Pos+1 || value == _dial2Pos-1)
    {
        _bodyShadowDial2->setColor(QColor(0, 200, 0));
        _unlocked[1] = true;
        if(_unlocked[0])
            ui->changePage->setIcon(QIcon("/home/pi/portalImages/home.png"));
        else
            ui->changePage->setIcon(QIcon("/home/pi/portalImages/lock-icon.png"));
    }
    else
    {
        _bodyShadowDial2->setColor(QColor(200, 0, 0));
        _unlocked[1] = false;
        ui->changePage->setIcon(QIcon("/home/pi/portalImages/lock-icon.png"));
    }
}
