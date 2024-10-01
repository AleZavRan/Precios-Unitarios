#include "cioperacion.h"
#include "ui_cioperacion.h"

CIOperacion::CIOperacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CIOperacion)
{
    ui->setupUi(this);
}

CIOperacion::~CIOperacion()
{
    delete ui;
}

void CIOperacion::on_pushButton_ctya_clicked()
{
    cargosTecYAdmin = new CargosTecyAdmin(this);
    cargosTecYAdmin->show();
}


void CIOperacion::on_pushButton_ayd_clicked()
{
    alquiyDepre = new AlquiyDepre(this);
    alquiyDepre->show();
}


void CIOperacion::on_pushButton_oys_clicked()
{
    obligySeg = new ObligySeg(this);
    obligySeg->show();
}


void CIOperacion::on_pushButton_mdec_clicked()
{
    matdeCons = new MatdeCons(this);
    matdeCons->show();
}


void CIOperacion::on_pushButton_cyp_clicked()
{
    capyProm = new CapyProm(this);
    capyProm->show();
}

