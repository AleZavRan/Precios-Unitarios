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
    //Assigning values captured from interface to variables
    mTrabes_ = ui->lineEdit_trabes->text().toFloat();       //Lineal meters captured
    mCastillos_ = ui->lineEdit_castillos->text().toFloat();
    mDalas_ = ui->lineEdit_dalas->text().toFloat();
    mLosas_ = ui->lineEdit_losas->text().toFloat();
    mZapatas_ = ui->lineEdit_zapatas->text().toFloat();

    //Assigning unit prices depending on the selected supplier

    //Getting the required amount of materials depending type of configuration

    //Writing the summary table
}


void Cimbras::on_pushButton_regresar_clicked()
{
    hide();

}

void Cimbras::writeTable(QString concepto, QStringList unidad, QStringList material){

}
