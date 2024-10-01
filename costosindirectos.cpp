#include "costosindirectos.h"
#include "ui_costosindirectos.h"

CostosIndirectos::CostosIndirectos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CostosIndirectos)
{
    ui->setupUi(this);
}

CostosIndirectos::~CostosIndirectos()
{
    delete ui;
}

void CostosIndirectos::on_pushButton_CIOperacion_clicked()
{
    cioperacion = new CIOperacion(this);
    cioperacion->show();
}


void CostosIndirectos::on_pushButton_CIObra_clicked()
{
    ciobra = new CIObra(this);
    ciobra->show();

}

