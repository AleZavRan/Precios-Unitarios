#include "cargosdecampo.h"
#include "ui_cargosdecampo.h"
#include <QMessageBox>

CargosDeCampo::CargosDeCampo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargosDeCampo)
{
    ui->setupUi(this);
}

CargosDeCampo::~CargosDeCampo()
{
    delete ui;
}

void CargosDeCampo::on_pushButton_tecyadmin_clicked()
{
    campoTecyAdmin = new CampoTecyAdmin(this);
    campoTecyAdmin->show();

}


void CargosDeCampo::on_pushButton_trasper_clicked()
{
    trasladosPer = new TrasladosPer(this);
    trasladosPer->show();
}


void CargosDeCampo::on_pushButton_comyfle_clicked()
{
    comyFletes = new ComyFletes(this);
    comyFletes->show();
}


void CargosDeCampo::on_pushButton_constprov_clicked()
{
    construcProv = new ConstrucProv(this);
    construcProv->show();
}


void CargosDeCampo::on_pushButton_vario_clicked()
{
    consumosVarios = new ConsumosVarios(this);
    consumosVarios->show();
}

