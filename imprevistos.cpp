#include "imprevistos.h"
#include "ui_imprevistos.h"

Imprevistos::Imprevistos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Imprevistos)
{
    ui->setupUi(this);
}

Imprevistos::~Imprevistos()
{
    delete ui;
}
