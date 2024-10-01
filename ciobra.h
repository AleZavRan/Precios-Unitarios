#ifndef CIOBRA_H
#define CIOBRA_H

#include <QDialog>
#include "cargosdecampo.h"
#include "imprevistos.h"
#include "financiamiento.h"
#include "utilidad.h"
#include "fianzas.h"
#include "impuestosr.h"

namespace Ui {
class CIObra;
}

class CIObra : public QDialog
{
    Q_OBJECT

public:
    explicit CIObra(QWidget *parent = nullptr);
    ~CIObra();

private slots:
    void on_pushButton_CargosDeCampo_clicked();

    void on_pushButton_Imprevistos_clicked();

    void on_pushButton_Financiamiento_clicked();

    void on_pushButton_Utilidad_clicked();

    void on_pushButton_Fianzas_clicked();

    void on_pushButton_ImpuestosR_clicked();

private:
    Ui::CIObra *ui;
    CargosDeCampo *cargosDeCampo;
    Imprevistos *imprevistos;
    Financiamiento *financiamiento;
    Utilidad *utilidad;
    Fianzas *fianzas;
    ImpuestosR *impuestosR;
};

#endif // CIOBRA_H
