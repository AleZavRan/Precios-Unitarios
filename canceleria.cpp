#include "canceleria.h"
#include "ui_canceleria.h"

Canceleria::Canceleria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Canceleria)
{
    ui->setupUi(this);
}

Canceleria::~Canceleria()
{
    delete ui;
}
