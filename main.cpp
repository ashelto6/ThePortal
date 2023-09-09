#include "mainwindow.h"

#include <QApplication>
#include <QCursor>
#include <QString>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
//#include <QMapIterator>

//#include <Eigen/Dense>
//#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <ctime>
#include <iostream>

void readParams(QMap<QString, QString>& params)
{
    QFile file("/home/pi/Documents/config.txt");
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0, "error", file.errorString());

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split("=");
        params[fields[0]] = fields[1];
    }

    file.close();
}

/*
void writesum(QStringList args){
    QFile file("/home/pi/log1.txt");
    if(!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }
    QTextStream out(&file);
    for(int i = 0; i < args.size() ; ++i )
        out << args[i] << "\n";



    file.close();
}
*/

/*
void eigenMatrixToFile(const Eigen::MatrixXd& M, QString filename)
{
    QFile file( filename );
    if(!file.open(QFile::WriteOnly | QFile::Text))
        return;

    QTextStream out(&file);
    for(int i = 0; i < M.rows(); ++i)
    {
        QStringList row;
        for(int j = 0; j < M.cols(); ++j)
            row << QString::number(M(i,j));
        out << (row.join(" ") + "\n");
    }
}

using Eigen::MatrixXd;
*/
/*
void toCons()
{
    std::cout << "not enough args.\n";
}
*/
int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QMap<QString, QString> params;

    readParams(params);


    //QMapIterator<QString, QString> i(params);

/*  MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);

    eigenMatrixToFile(m, "/home/pi/log.txt");
*/

/*  QFile file("/home/pi/log.txt");
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream out(&file);
    QMapIterator<QString, QString> i(params);
    while(i.hasNext())
    {
        i.next();
        out << i.key() << " " << i.value();
    }

    file.close();
*/
    QApplication a(argc, argv);
    /*
    QStringList args = QCoreApplication::arguments();
    if (args.size() != 4)
    {
        toCons();
        exit(1);
    }
    writesum(args);
    */
    //removing cursor
    a.setOverrideCursor(QCursor(Qt::BlankCursor));

    MainWindow w;
    w.setParams(params);
    w.setConfigs();
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
