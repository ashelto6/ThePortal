#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //adding pages to stacked widget
    ui->stackedWidget->addWidget(&_Home);
    ui->stackedWidget->addWidget(&_Page2);
    ui->stackedWidget->addWidget(&_test);


    //connections for navigation buttons
    connect(&_Home, SIGNAL(nextClicked()), this, SLOT(goToNext()));
    connect(&_Page2, SIGNAL(homeClicked()), this, SLOT(goHome()));

    //connections for changing wallpapers from settings page
    connect(&_Page2, SIGNAL(wallpaper1Set()), this, SLOT(setToWallpaper1()));
    connect(&_Page2, SIGNAL(wallpaper2Set()), this, SLOT(setToWallpaper2()));
    connect(&_Page2, SIGNAL(wallpaper3Set()), this, SLOT(setToWallpaper3()));

    //connections for setting the intial wallpaper based on configurations
    connect(this, SIGNAL(wallpaperConfig0()), &_Page2, SLOT(initWallpaperConfig1()));
    connect(this, SIGNAL(wallpaperConfig1()), &_Page2, SLOT(initWallpaperConfig2()));
    connect(this, SIGNAL(wallpaperConfig2()), &_Page2, SLOT(initWallpaperConfig3()));

    //write new wallpaper configurations to file
    connect(&_Page2, SIGNAL(reWriteWp1Config()), this, SLOT(writeWp1Config()));
    connect(&_Page2, SIGNAL(reWriteWp2Config()), this, SLOT(writeWp2Config()));
    connect(&_Page2, SIGNAL(reWriteWp3Config()), this, SLOT(writeWp3Config()));

    connect(&_test, SIGNAL(createPage()), this, SLOT(createPageNow()));
    connect(this, SIGNAL(tester()), &_test, SLOT(getCount()));
    connect(&_Home, SIGNAL(go()), this, SLOT(goBack()));
    connect(&_Home, SIGNAL(createButton()), &_test, SLOT(LandingDateTime()));
    //ui->stackedWidget->setCurrentIndex(2);


}

 void MainWindow::setParams(QMap<QString, QString>& params)
 {
    QMapIterator<QString, QString> i(params);
    while(i.hasNext())
    {
        i.next();
        _params[i.key()] = i.value();
    }
/*
    QFile file("/home/pi/log.txt");
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);
    QMapIterator<QString, QString> it(_params);
    while(it.hasNext())
    {
        it.next();
        out << it.key() << " " << it.value();
    }
*/
 }

 void MainWindow::setConfigs()
 {
    //QFile file("/home/pi/log.txt");

    // wallpaper config
    if(_params.value("wallpaper") == "0")
    {
        /*
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream out(&file);

        out << _params.value("wallpaper") << "\n";
        */
        setBackground(1);
        emit wallpaperConfig0();
    }
    else if(_params.value("wallpaper") == "1")
    {
        /*
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream out(&file);

        out << _params.value("wallpaper") << "\n";
        */
        setBackground(2);
        emit wallpaperConfig1();
    }
    else if(_params.value("wallpaper") == "2")
    {
        /*
        if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream out(&file);

        out << _params.value("wallpaper") << "\n";
        */
        setBackground(3);
        emit wallpaperConfig2();
    }
 }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::goToNext()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::setToWallpaper1()
{
    setBackground(1);
}

void MainWindow::setToWallpaper2()
{
    setBackground(2);
}

void MainWindow::setToWallpaper3()
{
    setBackground(3);
}

void MainWindow::writeWp1Config()
{
    if(_params.value("wallpaper") != "0")
    {
        _params["wallpaper"] = "0";
        reWriteConfigFile();
    }
}

void MainWindow::writeWp2Config()
{
    if(_params.value("wallpaper") != "1")
    {
        _params["wallpaper"] = "1";
        reWriteConfigFile();
    }
}

void MainWindow::writeWp3Config()
{
    if(_params.value("wallpaper") != "2")
    {
        _params["wallpaper"] = "2";
        reWriteConfigFile();
    }
}

void MainWindow::changeToTest()
{
    ui->stackedWidget->setCurrentIndex(2);

}


void MainWindow::goBack()
{
    ui->stackedWidget->setCurrentIndex(2);

}
void MainWindow::createPageNow(int* ptr)
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::reWriteConfigFile()
{
    QFile file("/home/pi/Documents/config.txt");
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);
    QMapIterator<QString, QString> i(_params);
    while(i.hasNext())
    {
        i.next();
        out << i.key() << "=" << i.value() << "\n";
    }

    file.close();
}

void MainWindow::setBackground(int value)
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



