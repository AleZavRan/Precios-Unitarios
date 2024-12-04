#include "concretos.h"
#include "ui_concretos.h"
#include "costosdirectos.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Concretos::Concretos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Concretos)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_tipoDeMezcla->addItem("Muros y Pisos");
    ui->comboBox_tipoDeMezcla->addItem("Trabes, Castillos y Dalas");
    ui->comboBox_tipoDeMezcla->addItem("Losas y Zapatas");
    ui->comboBox_tipoDeMezcla->addItem("Columnas y Losas Especiales");
    ui->comboBox_tipoDeMezcla->addItem("Alta Resistencia");

}

Concretos::~Concretos()
{
    delete ui;
}

void Concretos::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables

    m3_ = ui->lineEdit_metros3->text().toFloat();
    percWasteBlend_ = ui->lineEdit_porcentajeDesperdicioMezcla->text().toFloat();
    tipoDeMezcla_ = ui->comboBox_tipoDeMezcla->currentData().toString();
    concepto_ += tipoDeMezcla_;

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
    calculaCantidadAgArGrCem(m3_,percWasteBlend_, tipoDeMezcla_);

    //Writing the summary table
    writeTable(concepto_, unidad_, material_, cantidadAgArGrCem_,puAgArGrCem_);

}


void Concretos::on_pushButton_regresar_clicked()
{
    hide();
}

void Concretos::calculaCantidadAgArGrCem(float m3, float percWasteBlend, QString tipoDeMezcla){
    //Values taken from bag's table (Using 50kg bags) (Cemento portland compuesto CPC 30 R Cementos Moctezuma)
    float boteLts = 18; //Bottle's capacity
    float vecespm3 = 0; //Times for 1m3
    float tom3 = 0.001;  // Factor to convert lts to m3

    if (tipoDeMezcla == "Muros y Pisos"){
        vecespm3 = 5;
        cantidadAgArGrCem_[0] = m3*vecespm3*boteLts*2.5;    //Amount of water required in lts
        cantidadAgArGrCem_[1] = m3*vecespm3*boteLts*tom3*7; //Amount of sand required in m3
        cantidadAgArGrCem_[2] = m3*vecespm3*boteLts*tom3*8; //Amount of gravel required in m3
        cantidadAgArGrCem_[3] = 1;  //Amount of cement required in bags of 50kg

    } else if(tipoDeMezcla == "Trabes, Castillos y Dalas"){
        vecespm3 = 6;
        cantidadAgArGrCem_[0] = m3*vecespm3*boteLts*2;    //Amount of water required in lts
        cantidadAgArGrCem_[1] = m3*vecespm3*boteLts*tom3*5.5; //Amount of sand required in m3
        cantidadAgArGrCem_[2] = m3*vecespm3*boteLts*tom3*6.5; //Amount of gravel required in m3
        cantidadAgArGrCem_[3] = 1;  //Amount of cement required in bags of 50kg

    } else if(tipoDeMezcla == "Losas y Zapatas"){
        vecespm3 = 7;
        cantidadAgArGrCem_[0] = m3*vecespm3*boteLts*1.75;    //Amount of water required in lts
        cantidadAgArGrCem_[1] = m3*vecespm3*boteLts*tom3*4.5; //Amount of sand required in m3
        cantidadAgArGrCem_[2] = m3*vecespm3*boteLts*tom3*5.5; //Amount of gravel required in m3
        cantidadAgArGrCem_[3] = 1;  //Amount of cement required in bags of 50kg

    } else if(tipoDeMezcla == "Columnas y Losas Especiales"){
        vecespm3 = 8;
        cantidadAgArGrCem_[0] = m3*vecespm3*boteLts*1.5;    //Amount of water required in lts
        cantidadAgArGrCem_[1] = m3*vecespm3*boteLts*tom3*3.5; //Amount of sand required in m3
        cantidadAgArGrCem_[2] = m3*vecespm3*boteLts*tom3*5; //Amount of gravel required in m3
        cantidadAgArGrCem_[3] = 1;  //Amount of cement required in bags of 50kg

    } else if(tipoDeMezcla == "Alta Resistencia"){
        vecespm3 = 9;
        cantidadAgArGrCem_[0] = m3*vecespm3*boteLts*1.25;    //Amount of water required in lts
        cantidadAgArGrCem_[1] = m3*vecespm3*boteLts*tom3*3; //Amount of sand required in m3
        cantidadAgArGrCem_[2] = m3*vecespm3*boteLts*tom3*4; //Amount of gravel required in m3
        cantidadAgArGrCem_[3] = 1;  //Amount of cement required in bags of 50kg
    }

    //Adding percentage of waste
    cantidadAgArGrCem_[0] = cantidadAgArGrCem_[0] + (cantidadAgArGrCem_[0]*percWasteBlend*0.01);
    cantidadAgArGrCem_[1] += (cantidadAgArGrCem_[1]*percWasteBlend*0.01);
    cantidadAgArGrCem_[2] += (cantidadAgArGrCem_[2]*percWasteBlend*0.01);
    cantidadAgArGrCem_[3] += (cantidadAgArGrCem_[3]*percWasteBlend*0.01);

}

void Concretos::writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgArGrCem[], float puAgArGrCem[]){

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << concepto << ","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

    float total = 0;
    for(int i = 0; i < 4; i++){
        out << cantidadAgArGrCem[i] << unidad[i] << material[i] << cantidadAgArGrCem[i]
            <<","<<puAgArGrCem[i]<<","<<puAgArGrCem[i]*cantidadAgArGrCem[i] <<Qt::endl;
       total += (puAgArGrCem[i]*cantidadAgArGrCem[i]);
    }

    out << "TOTAL: "<< total << Qt::endl;

    out << Qt::endl;    //blank line

    file.flush();
    file.close();
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");


}


