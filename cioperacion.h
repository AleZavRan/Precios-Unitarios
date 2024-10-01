#ifndef CIOPERACION_H
#define CIOPERACION_H

#include <QDialog>
#include "cargostecyadmin.h"
#include "alquiydepre.h"
#include "obligyseg.h"
#include "matdecons.h"
#include "capyprom.h"

namespace Ui {
class CIOperacion;
}

class CIOperacion : public QDialog
{
    Q_OBJECT

public:
    explicit CIOperacion(QWidget *parent = nullptr);
    ~CIOperacion();

private slots:
    void on_pushButton_ctya_clicked();

    void on_pushButton_ayd_clicked();

    void on_pushButton_oys_clicked();

    void on_pushButton_mdec_clicked();

    void on_pushButton_cyp_clicked();

private:
    Ui::CIOperacion *ui;
    CargosTecyAdmin *cargosTecYAdmin;
    AlquiyDepre *alquiyDepre;
    ObligySeg *obligySeg;
    MatdeCons *matdeCons;
    CapyProm *capyProm;

};

#endif // CIOPERACION_H
