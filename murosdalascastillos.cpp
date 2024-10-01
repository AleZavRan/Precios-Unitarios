#include "murosdalascastillos.h"
#include "ui_murosdalascastillos.h"

MurosDalasCastillos::MurosDalasCastillos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MurosDalasCastillos)
{
    ui->setupUi(this);
}

MurosDalasCastillos::~MurosDalasCastillos()
{
    delete ui;
}
