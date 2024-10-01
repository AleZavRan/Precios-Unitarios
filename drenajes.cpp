#include "drenajes.h"
#include "ui_drenajes.h"

Drenajes::Drenajes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Drenajes)
{
    ui->setupUi(this);
}

Drenajes::~Drenajes()
{
    delete ui;
}
