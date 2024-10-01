#include "subcontratos.h"
#include "ui_subcontratos.h"

Subcontratos::Subcontratos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Subcontratos)
{
    ui->setupUi(this);
}

Subcontratos::~Subcontratos()
{
    delete ui;
}

void Subcontratos::on_pushButton_canceleria_clicked()
{

}


void Subcontratos::on_pushButton_carpinteria_clicked()
{

}


void Subcontratos::on_pushButton_herreria_clicked()
{

}


void Subcontratos::on_pushButton_paisajismo_clicked()
{

}


void Subcontratos::on_pushButton_instalaionese_clicked()
{

}

