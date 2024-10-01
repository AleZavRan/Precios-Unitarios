#include "pisos.h"
#include "ui_pisos.h"

Pisos::Pisos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pisos)
{
    ui->setupUi(this);
}

Pisos::~Pisos()
{
    delete ui;
}
