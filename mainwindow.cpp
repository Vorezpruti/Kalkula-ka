#include "mainwindow.h"
#include <QtCore/QCoreApplication>


QString value = "", total = "";
int prvniNum = 0,
    druhyNum = 0,
    meziSoucet = 0;

/* pokud 0 - rovna_se , 1 - scitani, 2 - odcitani, 3 - nasobeni, 4 - deleni */
int proces = 0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{ 

    lcd = new QLCDNumber(10, this);
    lcd -> setGeometry(QRect(QPoint(50,75), QSize(200, 50)));


    clear_button = new QPushButton("C", this);
    clear_button -> setGeometry(QRect(QPoint(100,300), QSize(50,50)));
    connect(clear_button, SIGNAL(released()), this, SLOT(clear()));

    rovno_button = new QPushButton("=", this);
    rovno_button -> setGeometry(QRect(QPoint(150,300), QSize(50,50)));
    connect(rovno_button, SIGNAL(released()), this, SLOT(rovno()));

    scitani_button = new QPushButton("+", this);
    scitani_button -> setGeometry(QRect(QPoint(200,150), QSize(50,50)));
    connect(scitani_button, SIGNAL(released()), this, SLOT(scitani()));

    nasobeni_button = new QPushButton("x", this);
    nasobeni_button -> setGeometry(QRect(QPoint(200,250), QSize(50,50)));
    connect(nasobeni_button, SIGNAL(released()), this, SLOT(nasobeni()));

    deleni_button = new QPushButton("/", this);
    deleni_button -> setGeometry(QRect(QPoint(200,300), QSize(50,50)));
    connect(deleni_button, SIGNAL(released()), this, SLOT(deleni()));

    odcitani_button = new QPushButton("-", this);
    odcitani_button -> setGeometry(QRect(QPoint(200,200), QSize(50,50)));
    connect(odcitani_button, SIGNAL(released()), this, SLOT(odcitani()));

    nula_button = new QPushButton("0", this);
    nula_button -> setGeometry(QRect(QPoint(50,300), QSize(50,50)));
    connect(nula_button, SIGNAL(released()), this, SLOT(nula()));

    jedna_button = new QPushButton("1", this);
    jedna_button -> setGeometry(QRect(QPoint(50,250), QSize(50,50)));
    connect(jedna_button, SIGNAL(released()), this, SLOT(jedna()));

    dva_button = new QPushButton("2", this);
    dva_button -> setGeometry(QRect(QPoint(100,250), QSize(50,50)));
    connect(dva_button, SIGNAL(released()), this, SLOT(dva()));

    tri_button = new QPushButton("3", this);
    tri_button -> setGeometry(QRect(QPoint(150,250), QSize(50,50)));
    connect(tri_button, SIGNAL(released()), this, SLOT(tri()));

    ctyri_button = new QPushButton("4", this);
    ctyri_button -> setGeometry(QRect(QPoint(50,200), QSize(50,50)));
    connect(ctyri_button, SIGNAL(released()), this, SLOT(ctyri()));

    pet_button = new QPushButton("5", this);
    pet_button -> setGeometry(QRect(QPoint(100,200), QSize(50,50)));
    connect(pet_button, SIGNAL(released()), this, SLOT(pet()));

    sest_button = new QPushButton("6", this);
    sest_button -> setGeometry(QRect(QPoint(150,200), QSize(50,50)));
    connect(sest_button, SIGNAL(released()), this, SLOT(sest()));

    sedm_button = new QPushButton("7", this);
    sedm_button -> setGeometry(QRect(QPoint(50,150), QSize(50,50)));
    connect(sedm_button, SIGNAL(released()), this, SLOT(sedm()));

    osm_button = new QPushButton("8", this);
    osm_button -> setGeometry(QRect(QPoint(100,150), QSize(50,50)));
    connect(osm_button, SIGNAL(released()), this, SLOT(osm()));

    devet_button = new QPushButton("9", this);
    devet_button -> setGeometry(QRect(QPoint(150,150), QSize(50,50)));
    connect(devet_button, SIGNAL(released()), this, SLOT(devet()));
}

void MainWindow::clear() {
    value = "";
    lcd -> display("0");
}


void MainWindow::rovno() {
    druhyNum = value.toInt();
    switch (proces) {

    /* pouze cislo */
    case 0:
        proces = 0;
        total = QString::number(druhyNum);
        lcd -> display(total);
        break;

    /* scitani */
    case 1:
        total = QString::number(prvniNum + druhyNum);
        lcd -> display(total);

        break;

    /* odcitani */
    case 2:
        total = QString::number(prvniNum - druhyNum);
        lcd -> display(total);

        break;

    /* nasobeni */
    case 3:
        total = QString::number(prvniNum * druhyNum);
        lcd -> display(total);

        break;

    /* deleni */
    case 4:
        if(druhyNum != 0) {
            total = QString::number(prvniNum / druhyNum);
            lcd -> display(total);
        } else {
            total = "0";
            lcd -> display("ERR");
        }

        break;

    /* default = error */
    default:
        lcd -> display("ERROR");


    }

    if (total == "0")
        total = "";
    value = total;
    proces = 0;
    total = "";

}

void MainWindow::scitani() {

    prvniNum = value.toInt();
    value = "" ;
    lcd -> display("0");
    proces = 1;

}

void MainWindow::nasobeni() {

    prvniNum = value.toInt();
    value = "" ;
    lcd -> display("0");
    proces = 3;
}

void MainWindow::deleni() {

    prvniNum = value.toInt();
    value = "" ;
    lcd -> display("0");
    proces = 4;
}

void MainWindow::odcitani() {

    prvniNum = value.toInt();
    value = "" ;
    lcd -> display("0");
    proces = 2;
}

void MainWindow::nula() {

    value = value + "0";
    lcd -> display(value);
}

void MainWindow::jedna() {

    value = value + "1";
    lcd -> display(value);
}

void MainWindow::dva() {

    value = value + "2";
    lcd -> display(value);
}

void MainWindow::tri() {

    value = value + "3";
    lcd -> display(value);
}

void MainWindow::ctyri() {

    value = value + "4";
    lcd -> display(value);
}

void MainWindow::pet() {

    value = value + "5";
    lcd -> display(value);
}

void MainWindow::sest() {

    value = value + "6";
    lcd -> display(value);
}

void MainWindow::sedm() {

    value = value + "7";
    lcd -> display(value);
}

void MainWindow::osm() {

    value = value + "8";
    lcd -> display(value);
}

void MainWindow::devet() {

    value = value + "9";
    lcd -> display(value);
}


MainWindow::~MainWindow()
{
}
