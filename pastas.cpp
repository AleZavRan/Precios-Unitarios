#include "pastas.h"
#include "ui_pastas.h"

Pastas::Pastas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pastas)
{
    ui->setupUi(this);
}

Pastas::~Pastas()
{
    delete ui;
}
