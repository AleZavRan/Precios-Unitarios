#include "aceros.h"
#include "ui_aceros.h"
#include "costosdirectos.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

Aceros::Aceros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aceros)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_pisos->addItem("Rejilla electrosoldada 10 x 10");
    ui->comboBox_pisos->addItem("Rejilla electrosoldada 12 x 12");
    ui->comboBox_trabes->addItem("10 x 10");
    ui->comboBox_trabes->addItem("10 x 16");
    ui->comboBox_trabes->addItem("10 x 20");
    ui->comboBox_castillos->addItem("10 x 10");
    ui->comboBox_castillos->addItem("10 x 16");
    ui->comboBox_castillos->addItem("10 x 20");
    ui->comboBox_castillos->addItem("Armex 10 x 10");
    ui->comboBox_castillos->addItem("Armex 10 x 16");
    ui->comboBox_castillos->addItem("Armex 10 x 20");
    ui->comboBox_dalas->addItem("10 x 10");
    ui->comboBox_dalas->addItem("10 x 16");
    ui->comboBox_dalas->addItem("10 x 20");
    ui->comboBox_losas->addItem("c 15");
    ui->comboBox_losas->addItem("c 10");
    ui->comboBox_zapatas->addItem("10 x 10");
    ui->comboBox_zapatas->addItem("10 x 16");
    ui->comboBox_zapatas->addItem("10 x 20");
}

Aceros::~Aceros()
{
    delete ui;
}

void Aceros::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables
    mPisos_ = ui->lineEdit_pisos->text().toFloat();     //Lineal meters captured
    mTrabes_ = ui->lineEdit_trabes->text().toFloat();
    mCastillos_ = ui->lineEdit_castillos->text().toFloat();
    mDalas_ = ui->lineEdit_dalas->text().toFloat();
    mLosas_ = ui->lineEdit_losas->text().toFloat();
    mZapatas_ = ui->lineEdit_zapatas->text().toFloat();
    tipoArmadoPisos_ = ui->comboBox_pisos->currentData().toString();    //Configurations selected
    tipoArmadoTrabes_ = ui->comboBox_trabes->currentData().toString();
    tipoArmadoCastillos_ = ui->comboBox_castillos->currentData().toString();
    tipoArmadoDalas_ = ui->comboBox_dalas->currentData().toString();
    tipoArmadoLosas_ = ui->comboBox_losas->currentData().toString();
    tipoArmadoZapatas_ = ui->comboBox_zapatas->currentData().toString();
    percWaste_ = ui->lineEdit_percWaste->text().toFloat();

    //Assigning unit prices depending on the selected supplier
    if(ui->comboBox_provedor->currentData().toString() == "Prov 1"){
        puVarillaAlambron_[0] = ACERO_NORMAL_3_8_A_1_1_2;
        puVarillaAlambron_[1] = ALAMBRON_1_4;
        puRejillaElectro10x10_ = REJILLA_ELECTROSOLDADA_10_10;
        puRejillaElectro12x12_ = REJILLA_ELECTROSOLDADA_12_12;
        puArmex10x10_ = ARMEX_10_10;
        puArmex10x16_ = ARMEX_10_16;
        puArmex10x20_ = ARMEX_10_20;

    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 2"){
        puVarillaAlambron_[0] = ACERO_NORMAL_3_8_A_1_1_2;
        puVarillaAlambron_[1] = ALAMBRON_1_4;

    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 3"){
        puVarillaAlambron_[0] = ACERO_NORMAL_3_8_A_1_1_2;
        puVarillaAlambron_[1] = ALAMBRON_1_4;

    }

    //Getting the required amount of materials depending type of configuration

    cantidadRejillaElectroPisos_ = calculaCantidadRejillaElectro(mPisos_, percWaste_);
    cantidadVarillaAlambronTrabes_ = calculaCantidadVarillaAlambron(mTrabes_, percWaste_, tipoArmadoTrabes_);

    if(tipoArmadoCastillos_ == "10 x 10" || tipoArmadoCastillos_== "10 x 16" || tipoArmadoCastillos_ == "10 x 20"){
        cantidadVarillaAlambronCastillos_ = calculaCantidadVarillaAlambron(mCastillos_, percWaste_, tipoArmadoCastillos_);

    } else{
        cantidadArmexCastillos_ = calculaCantidadArmex(mCastillos_, percWaste_);
    }

    cantidadVarillaAlambronDalas_ = calculaCantidadVarillaAlambron(mDalas_, percWaste_, tipoArmadoDalas_);
    cantidadVarillaAlambronLosas_ = calculaCantidadVarillaAlambron(mLosas_, percWaste_, tipoArmadoLosas_);
    cantidadVarillaAlambronZapatas_ = calculaCantidadVarillaAlambron(mZapatas_, percWaste_, tipoArmadoZapatas_);

    //Writing the summary table
    writeTable(concepto_, unidad_, material_);

    //De-allocating heap memory
    delete[] cantidadVarillaAlambronTrabes_;
    cantidadVarillaAlambronTrabes_ = nullptr;
    delete[] cantidadVarillaAlambronCastillos_;
    cantidadVarillaAlambronCastillos_ = nullptr;
    delete[] cantidadVarillaAlambronDalas_;
    cantidadVarillaAlambronDalas_ = nullptr;
    delete[] cantidadVarillaAlambronLosas_;
    cantidadVarillaAlambronLosas_ = nullptr;
    delete[] cantidadVarillaAlambronZapatas_;
    cantidadVarillaAlambronZapatas_ = nullptr;
}

void Aceros::on_pushButton_regresar_clicked()
{
    hide();
}

float* Aceros::calculaCantidadVarillaAlambron(float m, float percWaste, QString tipoDeArmado){

    float pesoVarilla = 0.560; //Weight (kg.) of rod per meter
    float pesoAlambron = 0.251; //Weight (kg.) of wire rod per meter
    float mAmarre10x10 = 0.50; //meters of wire rod used per tie
    float mAmarre10x16 = 0.62; //meters of wire rod used per tie
    float mAmarre10x20 = 0.70; //meters of wire rod used per tie
    float mAmarreLosa = 0.15; //meters of wire rod used per tie in a slab
    float distEntreAmarres = 0.15; //Distance between ties in meters
    //Allocating heap memory
    float* cantidadVarillaAlambron = new float[2]; //Amount of rod and wire rod required in kg

    if(tipoDeArmado == "10 x 10"){
        cantidadVarillaAlambron[0] = 4*m*pesoVarilla;   //(4 rods required for this config)
        cantidadVarillaAlambron[1] = mAmarre10x10*(m/distEntreAmarres)*pesoAlambron;

    } else if(tipoDeArmado == "10 x 16"){
        cantidadVarillaAlambron[0] = 4*m*pesoVarilla;   //(4 rods required for this config)
        cantidadVarillaAlambron[1] = mAmarre10x16*(m/distEntreAmarres)*pesoAlambron;

    } else if(tipoDeArmado == "10 x 20"){
        cantidadVarillaAlambron[0] = 6*m*pesoVarilla;   //(6 rods required for this config)
        cantidadVarillaAlambron[1] = mAmarre10x20*(m/distEntreAmarres)*pesoAlambron;

    } else if("c 15"){
        cantidadVarillaAlambron[0] = (m/0.15)*2*m*pesoVarilla;
        cantidadVarillaAlambron[1] = (((m/0.15)*(m/0.15)) + ((m/0.15)*(4))) * (mAmarreLosa*pesoAlambron);

    } else if("c 10"){
        cantidadVarillaAlambron[0] = (m/0.10)*2*m*pesoVarilla;
        cantidadVarillaAlambron[1] = (((m/0.10)*(m/0.10)) + ((m/0.10)*(4))) * (mAmarreLosa*pesoAlambron);

    } else{                              //Used for debugging purposes
        cantidadVarillaAlambron[0] = -1;
        cantidadVarillaAlambron[1] = -1;
    }

    cantidadVarillaAlambron[0] += ((cantidadVarillaAlambron[0])*(percWaste/100)); //Adding waste
    cantidadVarillaAlambron[1] += ((cantidadVarillaAlambron[1])*(percWaste/100));

    return cantidadVarillaAlambron;
}

float Aceros::calculaCantidadArmex(float m, float percWaste){

    float mPorPieza = 6.0;
    float piezasNecesarias = 0;

    piezasNecesarias = m/mPorPieza;
    piezasNecesarias += ((piezasNecesarias)*(percWaste/100));

    return piezasNecesarias;
}

float Aceros::calculaCantidadRejillaElectro(float m2, float percWaste){

    float m2PorRollo = 100; //(using 40m x 2.5m rolls)
    float rollosNecesarios= 0;

    rollosNecesarios = m2/m2PorRollo;
    rollosNecesarios += ((rollosNecesarios)*(percWaste/100));

    return rollosNecesarios;
}

void Aceros::writeTable(QString concepto, QStringList unidad, QStringList material){

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << concepto << ","<< "Unidad," << "Cantidad," << "P.U.," << "importe" << Qt::endl;

    float total = 0;
    //Pisos
    if(tipoArmadoPisos_ == "Rejilla electrosoldada 10 x 10"){
        out << cantidadRejillaElectroPisos_ << unidad[0] << tipoArmadoPisos_ <<"," <<unidad[0] <<"," << cantidadRejillaElectroPisos_
            <<","<<puRejillaElectro10x10_<<","<<puRejillaElectro10x10_*cantidadRejillaElectroPisos_ <<Qt::endl;

    } else if(tipoArmadoPisos_ == "Rejilla electrosoldada 12 x 12"){
        out << cantidadRejillaElectroPisos_ << unidad[0] << tipoArmadoPisos_ <<"," <<unidad[0] <<"," << cantidadRejillaElectroPisos_
            <<","<<puRejillaElectro12x12_<<","<<puRejillaElectro12x12_*cantidadRejillaElectroPisos_ <<Qt::endl;
    }

    //Trabes
    out << cantidadVarillaAlambronTrabes_[0] << unidad[1] << material[1] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronTrabes_[0]
        <<","<<puVarillaAlambron_[0]<<","<<puVarillaAlambron_[0]*cantidadVarillaAlambronTrabes_[0] <<Qt::endl;

    out << cantidadVarillaAlambronTrabes_[1] << unidad[1] << material[2] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronTrabes_[1]
        <<","<<puVarillaAlambron_[1]<<","<<puVarillaAlambron_[1]*cantidadVarillaAlambronTrabes_[1] <<Qt::endl;

    //Castillos
    if(tipoArmadoCastillos_ == "10 x 10" || tipoArmadoCastillos_== "10 x 16" || tipoArmadoCastillos_ == "10 x 20"){
        out << cantidadVarillaAlambronCastillos_[0] << unidad[1] << material[1] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronCastillos_[0]
            <<","<<puVarillaAlambron_[0]<<","<<puVarillaAlambron_[0]*cantidadVarillaAlambronCastillos_[0] <<Qt::endl;

        out << cantidadVarillaAlambronCastillos_[1] << unidad[1] << material[2] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronCastillos_[1]
            <<","<<puVarillaAlambron_[1]<<","<<puVarillaAlambron_[1]*cantidadVarillaAlambronCastillos_[1] <<Qt::endl;

    } else if(tipoArmadoCastillos_ == "Armex 10 x 10"){
        out << cantidadArmexCastillos_ << unidad[2] << tipoArmadoCastillos_ <<"," <<unidad[2] <<"," << cantidadArmexCastillos_
            <<","<<puArmex10x10_<<","<<puArmex10x10_*cantidadArmexCastillos_ <<Qt::endl;

    } else if(tipoArmadoCastillos_ == "Armex 10 x 16"){
        out << cantidadArmexCastillos_ << unidad[2] << tipoArmadoCastillos_ <<"," <<unidad[2] <<"," << cantidadArmexCastillos_
            <<","<<puArmex10x16_<<","<<puArmex10x16_*cantidadArmexCastillos_ <<Qt::endl;

    } else if(tipoArmadoCastillos_ == "Armex 10 x 20"){
        out << cantidadArmexCastillos_ << unidad[2] << tipoArmadoCastillos_ <<"," <<unidad[2] <<"," << cantidadArmexCastillos_
            <<","<<puArmex10x20_<<","<<puArmex10x20_*cantidadArmexCastillos_ <<Qt::endl;

    }

    //Dalas
    out << cantidadVarillaAlambronDalas_[0] << unidad[1] << material[1] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronDalas_[0]
        <<","<<puVarillaAlambron_[0]<<","<<puVarillaAlambron_[0]*cantidadVarillaAlambronDalas_[0] <<Qt::endl;

    out << cantidadVarillaAlambronDalas_[1] << unidad[1] << material[2] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronDalas_[1]
        <<","<<puVarillaAlambron_[1]<<","<<puVarillaAlambron_[1]*cantidadVarillaAlambronDalas_[1] <<Qt::endl;

    //Losas
    out << cantidadVarillaAlambronLosas_[0] << unidad[1] << material[1] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronLosas_[0]
        <<","<<puVarillaAlambron_[0]<<","<<puVarillaAlambron_[0]*cantidadVarillaAlambronLosas_[0] <<Qt::endl;

    out << cantidadVarillaAlambronLosas_[1] << unidad[1] << material[2] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronLosas_[1]
        <<","<<puVarillaAlambron_[1]<<","<<puVarillaAlambron_[1]*cantidadVarillaAlambronLosas_[1] <<Qt::endl;

    //Zapatas
    out << cantidadVarillaAlambronZapatas_[0] << unidad[1] << material[1] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronZapatas_[0]
        <<","<<puVarillaAlambron_[0]<<","<<puVarillaAlambron_[0]*cantidadVarillaAlambronZapatas_[0] <<Qt::endl;

    out << cantidadVarillaAlambronZapatas_[1] << unidad[1] << material[2] <<"," <<unidad[1] <<"," << cantidadVarillaAlambronZapatas_[1]
        <<","<<puVarillaAlambron_[1]<<","<<puVarillaAlambron_[1]*cantidadVarillaAlambronZapatas_[1] <<Qt::endl;

    out << "TOTAL: "<< total << Qt::endl;

    out << Qt::endl;    //blank line

    file.flush();
    file.close();
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

}
