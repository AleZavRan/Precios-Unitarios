#include "financiamiento.h"
#include "ui_financiamiento.h"

Financiamiento::Financiamiento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Financiamiento)
{
    ui->setupUi(this);
}

Financiamiento::~Financiamiento()
{
    delete ui;
}
