#include "costosdirectos.h"
#include "ui_costosdirectos.h"

CostosDirectos::CostosDirectos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CostosDirectos)
{
    ui->setupUi(this);
}

CostosDirectos::~CostosDirectos()
{
    delete ui;
}

void CostosDirectos::on_pushButton_preliminares_clicked()
{
    cDPreliminares = new CDPreliminares(this);
    cDPreliminares->show();

}

void CostosDirectos::on_pushButton_Finales_clicked()
{
    cDFinales = new CDFinales(this);
    cDFinales->show();

}


void CostosDirectos::on_pushButton_ManoDeObra_clicked()
{
    cDManoDeObra = new CDManoDeObra(this);
    cDManoDeObra->show();
}

