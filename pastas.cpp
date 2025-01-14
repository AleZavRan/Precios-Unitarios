#include "pastas.h"
#include "ui_pastas.h"
#include "costosdirectos.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Pastas::Pastas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pastas)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_Material->addItem("Cemento gris - agua");
    ui->comboBox_Material->addItem("Cemento blanco - agua");
    ui->comboBox_Material->addItem("Yeso - agua");
    ui->comboBox_Material->addItem("Textuco - agua");
    ui->comboBox_Material->addItem("3");
    ui->comboBox_Material->addItem("6");
    ui->lineEdit_propMat3->setHidden(1);
}


Pastas::~Pastas()
{
    delete ui;
}

void Pastas::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables
    concepto_ = concepto_ + ui->comboBox_Material->currentData().toString();
    proporcionMat1Mat2_[0] = ui->lineEdit_propMat1->text().toFloat();
    proporcionMat1Mat2_[1] = ui->lineEdit_propMat2->text().toFloat();
    puAgCem_[0] = AGUA_CONSTRUCCION;
    mmEspesor_ = ui->comboBox_mmEspesor->currentData().toInt();
    m2_ = ui->lineEdit_metros2->text().toFloat();
    percWasteWater_ = ui->lineEdit_porcentajeDesperdicioAgua->text().toFloat();
    percWasteBinder_ = ui->lineEdit_porcentajeDesperdicioAglutin->text().toFloat();

    //Assigning unit prices depending on the selected supplier
    //Getting the required amount of materials
    //Writing the summary table
    if(ui->comboBox_provedor->currentData().toString() == "Prov 1"){

        if(ui->comboBox_Material->currentData() == "Cemento gris - agua"){
            puAgCem_[1] = CEMENTO_BLANCO;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Cemento blanco - agua"){
            puAgCem_[1] = CEMENTO_NORMAL;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Yeso - agua"){
            puAgCem_[1] = YESO_ENLUCIDOS;
            calculaCantidadAguaYeso(ui->lineEdit_metros2->text().toFloat(), mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgYeso_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Textuco - agua"){
            puAgCem_[1] = TEXTUCO;
            calculaCantidadAguaTextuco(m2_, mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgTextuco_, puAgCem_);
        }


    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 2"){

        if(ui->comboBox_Material->currentData() == "Cemento gris - agua"){
            puAgCem_[1] = CEMENTO_BLANCO;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Cemento blanco - agua"){
            puAgCem_[1] = CEMENTO_NORMAL;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Yeso - agua"){
            puAgCem_[1] = YESO_ENLUCIDOS;
            calculaCantidadAguaYeso(ui->lineEdit_metros2->text().toFloat(), mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgYeso_, puAgCem_);


        } else if(ui->comboBox_Material->currentData() == "Textuco - agua"){
            puAgCem_[1] = TEXTUCO;
            calculaCantidadAguaTextuco(m2_, mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgTextuco_, puAgCem_);
        }


    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 3"){

        if(ui->comboBox_Material->currentData() == "Cemento gris - agua"){
            puAgCem_[1] = CEMENTO_BLANCO;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Cemento blanco - agua"){
            puAgCem_[1] = CEMENTO_NORMAL;
            cantidadAgCem_ = getCantidadAguaCemento(ui->lineEdit_metros2->text().toFloat());
            writeTable(concepto_, unidad_, material_, cantidadAgCem_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Yeso - agua"){
            puAgCem_[1] = YESO_ENLUCIDOS;
            calculaCantidadAguaYeso(ui->lineEdit_metros2->text().toFloat(), mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgYeso_, puAgCem_);

        } else if(ui->comboBox_Material->currentData() == "Textuco - agua"){
            puAgCem_[1] = TEXTUCO;
            calculaCantidadAguaTextuco(m2_, mmEspesor_, percWasteWater_, percWasteBinder_);
            writeTable(concepto_, unidad_, material_, cantidadAgTextuco_, puAgCem_);
        }
    }

    //De-allocating heap memory of cantidadAgCem_[]
    delete[] cantidadAgCem_;
    cantidadAgCem_ = nullptr;

}

void Pastas::on_comboBox_Material_currentIndexChanged(int index)
{
    if(index >= 4){   //  For those cases in which there are more than one binder
        ui->lineEdit_propMat3->show();
    }
}

float* Pastas::getCantidadAguaCemento(float m2){
    float* cantidadAgCem = new float[2];   //Heap memory allocated

    cantidadAgCem[0] = m2*1;
    cantidadAgCem[1] = m2*1;

    return cantidadAgCem;
}
void Pastas::calculaCantidadAguaYeso(float m2, int mmEspesor, float percWasteWater, float percWasteBinder){

    float kilosBulto = 40; //Using 40kg bags
    float rendiM2 = 6;  // production in m2 per rendiKilos
    float rendiKilos = 40; // amount of binder required per rendiM2 m2
    float propAgua = 1; // ratio of water (in lts.) per 1 kg of textuco

    if (mmEspesor == 3){
        rendiM2 = 6;

        cantidadAgYeso_[1] = ((rendiKilos/rendiM2)/(kilosBulto))*(m2); //amount of bags required

    } else if (mmEspesor == 6){
        rendiM2 = 3;

        cantidadAgYeso_[1] = ((rendiKilos/rendiM2)/(kilosBulto))*(m2); //amount of bags required
    }
    cantidadAgYeso_[0] = (cantidadAgYeso_[1])*(kilosBulto)*(propAgua); //liters of water required

    //Adding percentage of waste
    cantidadAgYeso_[0] = cantidadAgYeso_[0] + ((cantidadAgYeso_[0])*(percWasteWater/100));
    cantidadAgYeso_[1] = cantidadAgYeso_[1] + ((cantidadAgYeso_[1])*(percWasteBinder/100));


}
void Pastas::calculaCantidadAguaTextuco(float m2, int mmEspesor, float percWasteWater, float percWasteBinder){

    float kilosBulto = 20; //Using 20kg bags
    float rendiM2 = 13;  // production in m2 per rendiKilos
    float rendiKilos = 20; // amount of binder required per rendiM2 m2
    float propAgua = 0.25; // ratio of water (in lts.) per 1 kg of textuco

    if (mmEspesor == 3){
        rendiM2 = 13;

        cantidadAgTextuco_[1] = ((rendiKilos/rendiM2)/(kilosBulto))*(m2); //amount of bags required

    } else if (mmEspesor == 6){
        rendiM2 = 3.5;

        cantidadAgTextuco_[1] = ((rendiKilos/rendiM2)/(kilosBulto))*(m2); //amount of bags required
    }
    cantidadAgTextuco_[0] = (cantidadAgTextuco_[1])*(kilosBulto)*(propAgua); //liters of water required

    //Adding percentage of waste
    cantidadAgTextuco_[0] = cantidadAgTextuco_[0] + ((cantidadAgTextuco_[0])*(percWasteWater/100));
    cantidadAgTextuco_[1] = cantidadAgTextuco_[1] + ((cantidadAgTextuco_[1])*(percWasteBinder/100));

}
void Pastas::writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgCem[], float puAgCem[]){

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    //out << concepto << ". Proporción: " << proporcionMat1Mat2[0] <<":"<<      //Used whenever paste has 2 or more binders
    //proporcionMat1Mat2[1] << ","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

    out << concepto << ","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

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

