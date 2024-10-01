#include "edit.h"
#include "ui_edit.h"
#include <QDir>

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    QDir qdir("/home/jano/Documents/QtApps/Tutorials");

    foreach(QFileInfo var, qdir.entryInfoList()){
        ui->listWidget->addItem(var.fileName());

    }
}

Edit::~Edit()
{
    delete ui;
}
