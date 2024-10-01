#include "ciobra.h"
#include "ui_ciobra.h"

CIObra::CIObra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CIObra)
{
    ui->setupUi(this);
}

CIObra::~CIObra()
{
    delete ui;
}

void CIObra::on_pushButton_CargosDeCampo_clicked()
{

    cargosDeCampo = new CargosDeCampo(this);
    cargosDeCampo->show();
}


void CIObra::on_pushButton_Imprevistos_clicked()
{

    imprevistos = new Imprevistos(this);
    imprevistos->show();
}


void CIObra::on_pushButton_Financiamiento_clicked()
{
    financiamiento = new Financiamiento(this);
    financiamiento->show();
}


void CIObra::on_pushButton_Utilidad_clicked()
{

    utilidad = new Utilidad(this);
    utilidad->show();
}


void CIObra::on_pushButton_Fianzas_clicked()
{

    fianzas = new Fianzas(this);
    fianzas->show();
}


void CIObra::on_pushButton_ImpuestosR_clicked()
{

    impuestosR = new ImpuestosR(this);
    impuestosR->show();
}

