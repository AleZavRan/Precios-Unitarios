#include "carpinteria.h"
#include "ui_carpinteria.h"

Carpinteria::Carpinteria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Carpinteria)
{
    ui->setupUi(this);
}

Carpinteria::~Carpinteria()
{
    delete ui;
}
