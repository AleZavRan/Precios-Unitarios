#include "lechadas.h"
#include "ui_lechadas.h"

Lechadas::Lechadas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lechadas)
{
    ui->setupUi(this);
}

Lechadas::~Lechadas()
{
    delete ui;
}
