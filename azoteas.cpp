#include "azoteas.h"
#include "ui_azoteas.h"

Azoteas::Azoteas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Azoteas)
{
    ui->setupUi(this);
}

Azoteas::~Azoteas()
{
    delete ui;
}
