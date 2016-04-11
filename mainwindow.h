#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLCDNumber>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clear();
    void scitani();
    void nasobeni();
    void deleni();
    void odcitani();
    void rovno();
    void nula();
    void jedna();
    void dva();
    void tri();
    void ctyri();
    void pet();
    void sest();
    void sedm();
    void osm();
    void devet();

private:
    int counter;
    QLCDNumber *lcd;
    QPushButton *clear_button;
    QPushButton *scitani_button;
    QPushButton *nasobeni_button;
    QPushButton *deleni_button;
    QPushButton *odcitani_button;
    QPushButton *rovno_button;
    QPushButton *nula_button;
    QPushButton *jedna_button;
    QPushButton *dva_button;
    QPushButton *tri_button;
    QPushButton *ctyri_button;
    QPushButton *pet_button;
    QPushButton *sest_button;
    QPushButton *sedm_button;
    QPushButton *osm_button;
    QPushButton *devet_button;


};

#endif // MAINWINDOW_H
