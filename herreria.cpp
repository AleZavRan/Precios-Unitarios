#include "herreria.h"
#include "ui_herreria.h"

Herreria::Herreria(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Herreria)
{
    ui->setupUi(this);
}

Herreria::~Herreria()
{
    delete ui;
}
