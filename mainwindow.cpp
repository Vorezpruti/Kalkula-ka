/** \file
 * @file    mainwindow.cpp
 * @author  Miroslav Karpíšek
 * @date    19 april 2016
 * @brief   nadefinovani objektu kalkulacky a nasledne vyuziti matematicke knihovny.
 */

#include "mainwindow.h"
#include <QtCore/QCoreApplication>
#include "mathematic_lib.h"


QString value = "", total = "";
double prvniNum = 0,
    druhyNum = 0,
    meziSoucet = 0;

int druhyNum_int = 0;

/* pokud 0 - rovna_se , 1 - scitani, 2 - odcitani, 3 - nasobeni, 4 - deleni */
int proces = 0;
/**
 * @brief sestaveni celeho okna kalkulaci a pozicovani objektu
 */
MainWindow::MainWindow(QWidget *parent) :
    /* nize je napozicovany kazdy jednotlivy objekt kalkulacky, a take spusteni signalu */



    QMainWindow(parent) {

    lcd = new QLCDNumber(10, this);
    lcd -> setGeometry(QRect(QPoint(50,50), QSize(200, 50)));


    clear_button = new QPushButton("C", this);
    clear_button -> setGeometry(QRect(QPoint(200,300), QSize(50,50)));
    connect(clear_button, SIGNAL(released()), this, SLOT(clear()));

    rovno_button = new QPushButton("=", this);
    rovno_button -> setGeometry(QRect(QPoint(150,300), QSize(50,50)));
    connect(rovno_button, SIGNAL(released()), this, SLOT(rovno()));

    scitani_button = new QPushButton("+", this);
    scitani_button -> setGeometry(QRect(QPoint(50,100), QSize(50,50)));
    connect(scitani_button, SIGNAL(released()), this, SLOT(scitani()));

    nasobeni_button = new QPushButton("x", this);
    nasobeni_button -> setGeometry(QRect(QPoint(150,100), QSize(50,50)));
    connect(nasobeni_button, SIGNAL(released()), this, SLOT(nasobeni()));

    deleni_button = new QPushButton("/", this);
    deleni_button -> setGeometry(QRect(QPoint(200,100), QSize(50,50)));
    connect(deleni_button, SIGNAL(released()), this, SLOT(deleni()));

    odcitani_button = new QPushButton("-", this);
    odcitani_button -> setGeometry(QRect(QPoint(100,100), QSize(50,50)));
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

    tecka_button = new QPushButton(".", this);
    tecka_button -> setGeometry(QRect(QPoint(100,300), QSize(50,50)));
    connect(tecka_button, SIGNAL(released()), this, SLOT(tecka()));

    faktorial_button = new QPushButton("!", this);
    faktorial_button -> setGeometry(QRect(QPoint(200,150), QSize(50,50)));
    connect(faktorial_button, SIGNAL(released()), this, SLOT(faktorial()));

    mocnina_button = new QPushButton("^", this);
    mocnina_button -> setGeometry(QRect(QPoint(200,200), QSize(50,50)));
    connect(mocnina_button, SIGNAL(released()), this, SLOT(mocnina()));

    odmocnina_button = new QPushButton("sqrt", this);
    odmocnina_button -> setGeometry(QRect(QPoint(200,250), QSize(50,50)));
    connect(odmocnina_button, SIGNAL(released()), this, SLOT(odmocnina()));

    }

/**
 * @brief Tlacitko pro vymazani aktualne zadavaneho cisla
 */
void MainWindow::clear() {
    value = "";
    lcd -> display("0");
}

/**
 * @brief Tlacitko pro rovna se - provede se vypocet operaci o dvou operandech
 */
void MainWindow::rovno() {


    druhyNum = value.toDouble();
    switch (proces) {

    /* pouze cislo */

    case -1:
        total = QString::number(druhyNum);
        lcd -> display(total);
        break;

    case 0:
        total = QString::number(druhyNum);
        lcd -> display(total);
        break;

    /* scitani */
    case 1:
        total = QString::number(add_f( prvniNum, druhyNum), 'g');
        lcd -> display(total);

        break;

    /* odcitani */
    case 2:
        total = QString::number(sub_f( prvniNum, druhyNum), 'g');
        lcd -> display(total);

        break;

    /* nasobeni */
    case 3:
        total = QString::number(mul_f( prvniNum, druhyNum), 'g');
        lcd -> display(total);

        break;

    /* deleni */
    case 4:
        if(druhyNum != 0) {
            total = QString::number(div_f( prvniNum, druhyNum), 'g');
            lcd -> display(total);
        } else {
            total = "0";
            lcd -> display("ERR");
        }

        break;

    /* mocnina */
    case 5:
        if((druhyNum - int(druhyNum)) != 0) {
            total = "0";
            lcd -> display("ERR");
        } else {
            druhyNum_int = int(druhyNum);
            total = QString::number(pow_f( prvniNum, druhyNum_int), 'g');
            lcd -> display(total);

        }

        break;

    /* default = error */
    default:
        lcd -> display("ERROR");


    }

    prvniNum = total.toDouble();
    if (total == "0")
        total = "";

    value = total;
    proces = -1;
    total = "";

}

/**
 * @brief Tlacitko pro scitani
 */
void MainWindow::scitani() {

        prvniNum = value.toDouble();
        value = "" ;
        lcd -> display("0");
        proces = 1;

}

/**
 * @brief Tlacitko pro odcitani
 */
void MainWindow::odcitani() {

    prvniNum = value.toDouble();
    value = "" ;
    lcd -> display("0");
    proces = 2;
}

/**
 * @brief Tlacitko pro nasobeni
 */
void MainWindow::nasobeni() {

    prvniNum = value.toDouble();
    value = "" ;
    lcd -> display("0");
    proces = 3;
}

/**
 * @brief Tlacitko pro deleni
 */
void MainWindow::deleni() {

    prvniNum = value.toDouble();
    value = "" ;
    lcd -> display("0");
    proces = 4;
}

/**
 * @brief Tlacitko pro faktorial
 */
void MainWindow::faktorial() {

    prvniNum = value.toDouble();
    total = QString::number(fact_f( prvniNum), 'g');
    lcd -> display(total);
    value = total;
    proces = -1;
    total = "";

}

/**
 * @brief Tlacitko pro mocninu
 */
void MainWindow::mocnina() {

    prvniNum = value.toDouble();
    value = "" ;
    lcd -> display("0");
    proces = 5;
}

/**
 * @brief Tlacitko pro odmocninu
 */
void MainWindow::odmocnina() {

    prvniNum = value.toDouble();
    total = QString::number(sqrt_f( prvniNum), 'g');
    lcd -> display(total);
    value = total;
    proces = -1;
    total = "";
}

/**
 * @brief Tlacitko pro cislo 0
 */
void MainWindow::nula() {

    if (proces == -1) {
        value = "0";
        proces = 0;
    }
    else
        value = value + "0";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 1
 */
void MainWindow::jedna() {

    if (proces == -1) {
        value = "1";
        proces = 0;
    }
    else
        value = value + "1";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 2
 */
void MainWindow::dva() {

    if (proces == -1) {
        value = "2";
        proces = 0;
    }
    else
        value = value + "2";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 3
 */
void MainWindow::tri() {

    if (proces == -1) {
        value = "3";
        proces = 0;
    }
    else
        value = value + "3";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 4
 */
void MainWindow::ctyri() {

    if (proces == -1) {
        value = "4";
        proces = 0;
    }
    else
        value = value + "4";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 5
 */
void MainWindow::pet() {

    if (proces == -1) {
        value = "5";
        proces = 0;
    }
    else
        value = value + "5";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 6
 */
void MainWindow::sest() {

    if (proces == -1) {
        value = "6";
        proces = 0;
    }
    else
        value = value + "6";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 7
 */
void MainWindow::sedm() {

    if (proces == -1) {
        value = "7";
        proces = 0;
    }
    else
        value = value + "7";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 8
 */
void MainWindow::osm() {

    if (proces == -1) {
        value = "8";
        proces = 0;
    }
    else
        value = value + "8";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro cislo 9
 */
void MainWindow::devet() {

    if (proces == -1) {
        value = "9";
        proces = 0;
    }
    else
        value = value + "9";
    lcd -> display(value);
}

/**
 * @brief Tlacitko pro desetinou carku
 */
void MainWindow::tecka() {

    if (proces == -1) {
        value = ".";
        proces = 0;
    }
    else
        value = value + ".";
    lcd -> display(value);
}




MainWindow::~MainWindow()
{
}
