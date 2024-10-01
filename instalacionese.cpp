#include "instalacionese.h"
#include "ui_instalacionese.h"

InstalacionesE::InstalacionesE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InstalacionesE)
{
    ui->setupUi(this);
}

InstalacionesE::~InstalacionesE()
{
    delete ui;
}
