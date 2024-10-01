#include "cimentaciones.h"
#include "ui_cimentaciones.h"

Cimentaciones::Cimentaciones(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cimentaciones)
{
    ui->setupUi(this);
}

Cimentaciones::~Cimentaciones()
{
    delete ui;
}
