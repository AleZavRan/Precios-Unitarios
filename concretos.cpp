#include "concretos.h"
#include "ui_concretos.h"
#include "costosdirectos.h"

Concretos::Concretos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Concretos)
{
    ui->setupUi(this);
}

Concretos::~Concretos()
{
    delete ui;
}

void Concretos::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables

    m3_ = ui->lineEdit_metros3->text().toFloat();
    percWasteWater_ = ui->lineEdit_porcentajeDesperdicioAgua->text().toFloat();
    percWasteBlend_ = ui->lineEdit_porcentajeDesperdicioMezcla->text().toFloat();

    //Assigning unit prices depending on the selected supplier

    if(ui->comboBox_provedor->currentData() == "Prov 1"){
        puAgArGrCem_[0] = AGUA_CONSTRUCCION;
        puAgArGrCem_[1] = ARENA_MINA;
        puAgArGrCem_[2] = GRAVA_MINA;
        puAgArGrCem_[3] = CEMENTO_NORMAL;
    } else if(ui->comboBox_provedor->currentData() == "Prov 2"){
        puAgArGrCem_[0] = AGUA_CONSTRUCCION;
        puAgArGrCem_[1] = ARENA_MINA;
        puAgArGrCem_[2] = GRAVA_MINA;
        puAgArGrCem_[3] = CEMENTO_NORMAL;
    } else if(ui->comboBox_provedor->currentData() == "Prov 3"){
        puAgArGrCem_[0] = AGUA_CONSTRUCCION;
        puAgArGrCem_[1] = ARENA_MINA;
        puAgArGrCem_[2] = GRAVA_MINA;
        puAgArGrCem_[3] = CEMENTO_NORMAL;
    }

    //Getting the required amount of materials

    //Writing the summary table
}


void Concretos::on_pushButton_regresar_clicked()
{
    hide();
}

