#include "colocaciones.h"
#include "ui_colocaciones.h"

Colocaciones::Colocaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Colocaciones)
{
    ui->setupUi(this);
}

Colocaciones::~Colocaciones()
{
    delete ui;
}
