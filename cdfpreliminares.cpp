#include "cdfpreliminares.h"
#include "ui_cdfpreliminares.h"

CDFPreliminares::CDFPreliminares(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDFPreliminares)
{
    ui->setupUi(this);
}

CDFPreliminares::~CDFPreliminares()
{
    delete ui;
}
