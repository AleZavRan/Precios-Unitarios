#include "morteros.h"
#include "ui_morteros.h"

Morteros::Morteros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Morteros)
{
    ui->setupUi(this);
}

Morteros::~Morteros()
{
    delete ui;
}
