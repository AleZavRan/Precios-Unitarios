#include "cdpreliminares.h"
#include "ui_cdpreliminares.h"

CDPreliminares::CDPreliminares(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDPreliminares)
{
    ui->setupUi(this);
}

CDPreliminares::~CDPreliminares()
{
    delete ui;
}

void CDPreliminares::on_pushButton_lechadas_clicked()
{
    lechadas = new Lechadas(this);
    lechadas->show();

}


void CDPreliminares::on_pushButton_pastas_clicked()
{
    pastas = new Pastas(this);
    pastas->show();

}


void CDPreliminares::on_pushButton_morteros_clicked()
{
    morteros = new Morteros(this);
    morteros->show();

}


void CDPreliminares::on_pushButton_concretos_clicked()
{
    concretos = new Concretos(this);
    concretos->show();

}


void CDPreliminares::on_pushButton_aceros_clicked()
{
    aceros = new Aceros(this);
    aceros->show();

}


void CDPreliminares::on_pushButton_cimbras_clicked()
{
    cimbras = new Cimbras(this);
    cimbras->show();

}


void CDPreliminares::on_pushButton_equipos_clicked()
{
    equipos = new Equipos(this);
    equipos->show();

}

