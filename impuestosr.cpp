#include "impuestosr.h"
#include "ui_impuestosr.h"

ImpuestosR::ImpuestosR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImpuestosR)
{
    ui->setupUi(this);
}

ImpuestosR::~ImpuestosR()
{
    delete ui;
}
