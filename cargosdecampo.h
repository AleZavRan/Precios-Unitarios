#ifndef CARGOSDECAMPO_H
#define CARGOSDECAMPO_H

#include <QDialog>
#include "campotecyadmin.h"
#include "trasladosper.h"
#include "comyfletes.h"
#include "construcprov.h"
#include "consumosvarios.h"

namespace Ui {
class CargosDeCampo;
}

class CargosDeCampo : public QDialog
{
    Q_OBJECT

public:
    explicit CargosDeCampo(QWidget *parent = nullptr);
    ~CargosDeCampo();

private slots:
    void on_pushButton_tecyadmin_clicked();

    void on_pushButton_trasper_clicked();

    void on_pushButton_comyfle_clicked();

    void on_pushButton_constprov_clicked();

    void on_pushButton_vario_clicked();

private:
    Ui::CargosDeCampo *ui;
    CampoTecyAdmin *campoTecyAdmin;
    TrasladosPer *trasladosPer;
    ComyFletes *comyFletes;
    ConstrucProv *construcProv;
    ConsumosVarios * consumosVarios;
};

#endif // CARGOSDECAMPO_H
