#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QMapIterator>
#include <QString>

//.h files for each page of stackedwidget
#include "page2.h"
#include "home.h"
#include "p2settings.h"
#include "p2landing.h"
#include "test.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setParams(QMap<QString, QString>&);
    void setConfigs();
    ~MainWindow();

private slots:
    void goHome();
    void goToNext();

    void setToWallpaper1();
    void setToWallpaper2();
    void setToWallpaper3();

    void writeWp1Config();
    void writeWp2Config();
    void writeWp3Config();
    void changeToTest();
    void createPageNow(int*);
    void goBack();

signals:




















    void wallpaperConfig0();
    void wallpaperConfig1();
    void wallpaperConfig2();
    void tester(int);


private:
    Ui::MainWindow *ui;
    QMap<QString, QString> _params;
    p2Settings _p2Settings;
    Page2 _Page2;
    Home _Home;
    test _test;
    int* count;
    p2Landing _p2Landing;

    void reWriteConfigFile();
    void setBackground(int);
};
#endif // MAINWINDOW_H
