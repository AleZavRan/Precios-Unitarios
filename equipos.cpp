#include "equipos.h"
#include "ui_equipos.h"

Equipos::Equipos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Equipos)
{
    ui->setupUi(this);
}

Equipos::~Equipos()
{
    delete ui;
}
