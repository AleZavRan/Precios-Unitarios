#include "costos.h"
#include "ui_costos.h"

Costos::Costos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Costos)
{
    ui->setupUi(this);
}

Costos::~Costos()
{
    delete ui;
}

void Costos::on_pushButton_CostosIndirectos_clicked()
{
    costosIndirectos = new CostosIndirectos(this);
    costosIndirectos->show();
}


void Costos::on_pushButton_CostosDirectos_clicked()
{
    costosDirectos = new CostosDirectos(this);
    costosDirectos->show();

}

