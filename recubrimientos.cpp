#include "recubrimientos.h"
#include "ui_recubrimientos.h"

Recubrimientos::Recubrimientos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recubrimientos)
{
    ui->setupUi(this);
}

Recubrimientos::~Recubrimientos()
{
    delete ui;
}
