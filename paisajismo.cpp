#include "paisajismo.h"
#include "ui_paisajismo.h"

Paisajismo::Paisajismo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Paisajismo)
{
    ui->setupUi(this);
}

Paisajismo::~Paisajismo()
{
    delete ui;
}
