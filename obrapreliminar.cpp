#include "obrapreliminar.h"
#include "ui_obrapreliminar.h"

ObraPreliminar::ObraPreliminar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObraPreliminar)
{
    ui->setupUi(this);
}

ObraPreliminar::~ObraPreliminar()
{
    delete ui;
}
