#include "cimbras.h"
#include "ui_cimbras.h"

Cimbras::Cimbras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cimbras)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_trabes->addItem("");
    ui->comboBox_trabes->addItem("");
    ui->comboBox_trabes->addItem("");
    ui->comboBox_castillos->addItem("");
    ui->comboBox_castillos->addItem("");
    ui->comboBox_castillos->addItem("");
    ui->comboBox_dalas->addItem("");
    ui->comboBox_dalas->addItem("");
    ui->comboBox_dalas->addItem("");
    ui->comboBox_losas->addItem("");
    ui->comboBox_losas->addItem("");
    ui->comboBox_zapatas->addItem("");
    ui->comboBox_zapatas->addItem("");
    ui->comboBox_zapatas->addItem("");
}

Cimbras::~Cimbras()
{
    delete ui;
}

void Cimbras::on_pushButton_agregar_clicked()
{

}


void Cimbras::on_pushButton_regresar_clicked()
{
    hide();

}

