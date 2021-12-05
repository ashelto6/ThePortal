#ifndef PAGE2_H
#define PAGE2_H

#include <QWidget>

//.h files for each page of stackedwidget
#include "p2landing.h"
#include "p2settings.h"

namespace Ui {
class Page2;
}

class Page2 : public QWidget
{
    Q_OBJECT

public:
    explicit Page2(QWidget *parent = nullptr);
    ~Page2();

signals:
   void homeClicked();

   void wallpaper1Set();
   void wallpaper2Set();
   void wallpaper3Set();

   void updateWallpaper1Settings();
   void updateWallpaper2Settings();
   void updateWallpaper3Settings();

   void reWriteWp1Config();
   void reWriteWp2Config();
   void reWriteWp3Config();

private slots:
    void backHome();
    void toSettings();
    void toLanding();

    void setWallpaper1();
    void setWallpaper2();
    void setWallpaper3();

    void initWallpaperConfig1();
    void initWallpaperConfig2();
    void initWallpaperConfig3();

    void writeNewWp1Config();
    void writeNewWp2Config();
    void writeNewWp3Config();

private:
    Ui::Page2 *ui;
    p2Landing _p2Landing;
    p2Settings _p2Settings;

    void setBackground(int);
};

#endif // PAGE2_H
