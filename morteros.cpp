#include "morteros.h"
#include "ui_morteros.h"
#include "costosdirectos.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>


Morteros::Morteros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Morteros)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_tipoDeMezcla->addItem("Plantillas");
    ui->comboBox_tipoDeMezcla->addItem("Aplanados Alta Resistencia (Zarpeo)");
    ui->comboBox_tipoDeMezcla->addItem("Junteo Piedra Braza");
    ui->comboBox_tipoDeMezcla->addItem("Enjarres, Repellados, Aplanados");
    ui->comboBox_tipoDeMezcla->addItem("Junteo de Tabique, Block y Tabicón");
    ui->comboBox_mmEspesor->addItem("5");
    ui->comboBox_mmEspesor->addItem("10");
    ui->comboBox_mmEspesor->addItem("15");
    ui->comboBox_mmEspesor->addItem("20");
}

Morteros::~Morteros()
{
    delete ui;
}

void Morteros::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables

    m2_ = ui->lineEdit_metros2->text().toFloat();
    percWasteBlend_ = ui->lineEdit_porcentajeDesperdicioMezcla->text().toFloat();
    tipoDeMezcla_ = ui->comboBox_tipoDeMezcla->currentData().toString();
    mmEspesorIndex_ = ui->comboBox_mmEspesor->currentIndex();
    concepto_ += tipoDeMezcla_;

    //Assigning unit prices depending on the selected supplier

    if(ui->comboBox_provedor->currentData() == "Prov 1"){
        puAgArCem_[0] = AGUA_CONSTRUCCION;
        puAgArCem_[1] = ARENA_MINA;
        puAgArCem_[2] = CEMENTO_NORMAL;

    } else if(ui->comboBox_provedor->currentData() == "Prov 2"){
        puAgArCem_[0] = AGUA_CONSTRUCCION;
        puAgArCem_[1] = ARENA_MINA;
        puAgArCem_[2] = CEMENTO_NORMAL;

    } else if(ui->comboBox_provedor->currentData() == "Prov 3"){
        puAgArCem_[0] = AGUA_CONSTRUCCION;
        puAgArCem_[1] = ARENA_MINA;
        puAgArCem_[2] = CEMENTO_NORMAL;

    }

    //Getting the required amount of materials
    calculaCantidadAgArCem(m2_,mmEspesorIndex_, percWasteBlend_, tipoDeMezcla_);

    //Writing the summary table

    writeTable(concepto_, unidad_, material_, cantidadAgArCem_,puAgArCem_);

}


void Morteros::on_pushButton_regresar_clicked()
{
    hide();
}

void Morteros::calculaCantidadAgArCem(float m2, int mmEspesorIndex, float percWasteBlend, QString tipoDeMezcla){
    //Values taken from bag's table (Using 50kg bags) (MORTERO CEMENTO PARA ALBAÑILERÍA Cementos Moctezuma)
    //(Complies with mexican standard NMX-C-021-ONNCCE-(in Force))
    float boteLts = 18; //Bottle's capacity
    //float kilosBulto = 50; //Using 50kg bags
    float outputPerBag = 10; //Output in m2 per bag of 50kg
    float tom3 = 0.001;  // Factor to convert lts to m3
    float propAgua = 18; // Ratio of water in lts per bag of kilosBulto kg of cement

    if (tipoDeMezcla == "Plantillas"){

        cantidadAgArCem_[2] = (m2/outputPerBag)*(mmEspesorIndex+1);  //Amount of cement required in bags of 50kg
        cantidadAgArCem_[1] = (cantidadAgArCem_[2])*(boteLts)*(tom3)*(8)*(mmEspesorIndex+1); //Amount of sand required in m3
        cantidadAgArCem_[0] = (cantidadAgArCem_[2])*(propAgua)*(mmEspesorIndex+1);    //Amount of water required in lts

    } else if(tipoDeMezcla == "Aplanados Alta Resistencia (Zarpeo)"){

        cantidadAgArCem_[2] = (m2/outputPerBag)*(mmEspesorIndex+1);  //Amount of cement required in bags of 50kg
        cantidadAgArCem_[1] = (cantidadAgArCem_[2])*(boteLts)*(tom3)*(3)*(mmEspesorIndex+1); //Amount of sand required in m3
        cantidadAgArCem_[0] = (cantidadAgArCem_[2])*(propAgua)*(mmEspesorIndex+1);    //Amount of water required in lts

    } else if(tipoDeMezcla == "Junteo Piedra Braza"){

        cantidadAgArCem_[2] = (m2/outputPerBag)*(mmEspesorIndex+1);  //Amount of cement required in bags of 50kg
        cantidadAgArCem_[1] = (cantidadAgArCem_[2])*(boteLts)*(tom3)*(6)*(mmEspesorIndex+1); //Amount of sand required in m3
        cantidadAgArCem_[0] = (cantidadAgArCem_[2])*(propAgua)*(mmEspesorIndex+1);    //Amount of water required in lts

    } else if(tipoDeMezcla == "Enjarres, Repellados, Aplanados"){

        cantidadAgArCem_[2] = (m2/outputPerBag)*(mmEspesorIndex+1);  //Amount of cement required in bags of 50kg
        cantidadAgArCem_[1] = (cantidadAgArCem_[2])*(boteLts)*(tom3)*(6)*(mmEspesorIndex+1); //Amount of sand required in m3
        cantidadAgArCem_[0] = (cantidadAgArCem_[2])*(propAgua)*(mmEspesorIndex+1);    //Amount of water required in lts

    } else if(tipoDeMezcla == "Junteo de Tabique, Block y Tabicón"){

        cantidadAgArCem_[2] = (m2/outputPerBag)*(mmEspesorIndex+1);  //Amount of cement required in bags of 50kg
        cantidadAgArCem_[1] = (cantidadAgArCem_[2])*(boteLts)*(tom3)*(6)*(mmEspesorIndex+1); //Amount of sand required in m3
        cantidadAgArCem_[0] = (cantidadAgArCem_[2])*(propAgua)*(mmEspesorIndex+1);    //Amount of water required in lts
    }

    //Adding percentage of waste
    cantidadAgArCem_[0] = cantidadAgArCem_[0] + (cantidadAgArCem_[0]*percWasteBlend*0.01);
    cantidadAgArCem_[1] += (cantidadAgArCem_[1]*percWasteBlend*0.01);
    cantidadAgArCem_[2] += (cantidadAgArCem_[2]*percWasteBlend*0.01);

}

void Morteros::writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgArCem[], float puAgArCem[]){

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << concepto << ","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

    float total = 0;
    for(int i = 0; i < 3; i++){
        out << cantidadAgArCem[i] << unidad[i] << material[i] << cantidadAgArCem[i]
            <<","<<puAgArCem[i]<<","<<puAgArCem[i]*cantidadAgArCem[i] <<Qt::endl;
       total += (puAgArCem[i]*cantidadAgArCem[i]);
    }

    out << "TOTAL: "<< total << Qt::endl;

    out << Qt::endl;    //blank line

    file.flush();
    file.close();
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");
}
