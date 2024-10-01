#include "estructuras.h"
#include "ui_estructuras.h"

Estructuras::Estructuras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Estructuras)
{
    ui->setupUi(this);
}

Estructuras::~Estructuras()
{
    delete ui;
}
