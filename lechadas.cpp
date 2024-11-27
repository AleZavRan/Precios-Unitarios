#include "lechadas.h"
#include "ui_lechadas.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


#include "costosdirectos.h"

Lechadas::Lechadas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lechadas)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_Material->addItem("Cemento gris");
    ui->comboBox_Material->addItem("Cemento blanco");
}

Lechadas::~Lechadas()
{
    delete ui;
}

void Lechadas::on_pushButton_agregar_clicked()
{
    puAgCem_[0] = AGUA_CONSTRUCCION;

    if(ui->comboBox_provedor->currentData() == "Prov 1"){
        if(ui->comboBox_Material->currentData() == "Cemento Blanco"){

            puAgCem_[1] = CEMENTO_BLANCO;
        } else if(ui->comboBox_Material->currentData() == "Cemento Gris"){
            puAgCem_[1] = CEMENTO_NORMAL;
        }


    } else if(ui->comboBox_provedor->currentData() == "Prov 2"){
        if(ui->comboBox_Material->currentData() == "Cemento Blanco"){

            puAgCem_[1] = CEMENTO_BLANCO;
        } else if(ui->comboBox_Material->currentData() == "Cemento gris"){
            puAgCem_[1] = CEMENTO_NORMAL;
        }

    } else {
        if(ui->comboBox_Material->currentData() == "Cemento Blanco"){

            puAgCem_[1] = CEMENTO_BLANCO;
        } else if(ui->comboBox_Material->currentData() == "Cemento gris"){
            puAgCem_[1] = CEMENTO_NORMAL;
        }
    }


    total_ = getTotalLechadas();

    writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);


}

float Lechadas::getTotalLechadas(){

    metros2_ = ui->lineEdit_metros2->text().toFloat();
    cantidadAgCem_[0] = metros2_*3;     //Cálculo de cantidad de agua necesaria
    cantidadAgCem_[1] = metros2_*2;     //Cálculo de cantidad de cemento necesaria


    float total = cantidadAgCem_[0]*puAgCem_[0] + cantidadAgCem_[1]*puAgCem_[1];
    return total;
}


void Lechadas::on_pushButton_regresar_clicked()
{

    hide();
}

void Lechadas::writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgCem[], float puAgCem[]){

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << concepto <<","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

    out << cantidadAgCem[0] << unidad[0] << material[0] << cantidadAgCem[0]
        <<","<<puAgCem[0]<<","<<puAgCem[0]*cantidadAgCem[0] <<Qt::endl;

    out << cantidadAgCem[1] << unidad[1] << material[1] << cantidadAgCem[1]
        <<","<<puAgCem[1]<<","<<puAgCem[1]*cantidadAgCem[1] <<Qt::endl;

    out << "TOTAL: "<<puAgCem[1]*cantidadAgCem[1] + puAgCem[0]*cantidadAgCem[0] << Qt::endl;

    out << Qt::endl;    //blank line

    file.flush();
    file.close();
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");
}


