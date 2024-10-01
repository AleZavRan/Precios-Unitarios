#include "concretos.h"
#include "ui_concretos.h"

Concretos::Concretos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Concretos)
{
    ui->setupUi(this);
}

Concretos::~Concretos()
{
    delete ui;
}
