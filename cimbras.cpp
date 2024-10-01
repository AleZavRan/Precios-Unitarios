#include "cimbras.h"
#include "ui_cimbras.h"

Cimbras::Cimbras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cimbras)
{
    ui->setupUi(this);
}

Cimbras::~Cimbras()
{
    delete ui;
}
