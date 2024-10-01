#include "utilidad.h"
#include "ui_utilidad.h"

Utilidad::Utilidad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Utilidad)
{
    ui->setupUi(this);
}

Utilidad::~Utilidad()
{
    delete ui;
}
