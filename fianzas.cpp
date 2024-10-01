#include "fianzas.h"
#include "ui_fianzas.h"

Fianzas::Fianzas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fianzas)
{
    ui->setupUi(this);
}

Fianzas::~Fianzas()
{
    delete ui;
}
