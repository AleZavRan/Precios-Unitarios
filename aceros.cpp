#include "aceros.h"
#include "ui_aceros.h"

Aceros::Aceros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aceros)
{
    ui->setupUi(this);
}

Aceros::~Aceros()
{
    delete ui;
}
