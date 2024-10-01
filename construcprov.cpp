#include "construcprov.h"
#include "ui_construcprov.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ConstrucProv::ConstrucProv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConstrucProv)
{
    ui->setupUi(this);
    ui->checkBox_cerca->setChecked(true);
    ui->checkBox_caseta->setChecked(true);
    ui->checkBox_oficina->setChecked(true);
    ui->checkBox_bodega->setChecked(true);
    ui->checkBox_dormit->setChecked(true);
    ui->checkBox_sanitario->setChecked(true);
    ui->checkBox_comedores->setChecked(true);
    ui->checkBox_hidra->setChecked(true);
    ui->checkBox_elect->setChecked(true);
    ui->checkBox_camino->setChecked(true);
}

ConstrucProv::~ConstrucProv()
{
    delete ui;
}

void ConstrucProv::on_checkBox_cerca_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_cerca->show();
    }else{
        ui->lineEdit_cerca->hide();
    }
}


void ConstrucProv::on_checkBox_caseta_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_caseta->show();
    }else{
        ui->lineEdit_caseta->hide();
    }
}


void ConstrucProv::on_checkBox_oficina_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_oficina->show();
    }else{
        ui->lineEdit_oficina->hide();
    }
}


void ConstrucProv::on_checkBox_bodega_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_bodega->show();
    }else{
        ui->lineEdit_bodega->hide();
    }
}


void ConstrucProv::on_checkBox_dormit_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_dormit->show();
    }else{
        ui->lineEdit_dormit->hide();
    }
}


void ConstrucProv::on_checkBox_sanitario_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_sanitarios->show();
    }else{
        ui->lineEdit_sanitarios->hide();
    }
}


void ConstrucProv::on_checkBox_comedores_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_comedores->show();
    }else{
        ui->lineEdit_comedores->hide();
    }
}


void ConstrucProv::on_checkBox_hidra_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_hidra->show();
    }else{
        ui->lineEdit_hidra->hide();
    }
}


void ConstrucProv::on_checkBox_elect_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_elect->show();
    }else{
        ui->lineEdit_elect->hide();
    }
}


void ConstrucProv::on_checkBox_camino_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_camino->show();
    }else{
        ui->lineEdit_camino->hide();
    }
}


void ConstrucProv::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "COMUNICACIONES Y FLETES," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_cerca->isHidden()){
        cerca = ui->lineEdit_cerca->text().toFloat();
        out << "Cerca y puertas, "<< cerca << Qt::endl;
    }
    if(!ui->lineEdit_caseta->isHidden()){
        caseta = ui->lineEdit_caseta->text().toFloat();
        out << "Caseta, "<< caseta << Qt::endl;
    }
    if(!ui->lineEdit_oficina->isHidden()){
        oficina = ui->lineEdit_oficina->text().toFloat();
        out << "Oficina, " << oficina << Qt::endl;
    }
    if(!ui->lineEdit_bodega->isHidden()){
        bodega = ui->lineEdit_bodega->text().toFloat();
        out << "Bodega cubierta, " << bodega <<Qt::endl;
    }
    if(!ui->lineEdit_dormit->isHidden()){
        dormit = ui->lineEdit_dormit->text().toFloat();
        out << "Dormitorios, "<< dormit << Qt::endl;
    }
    if(!ui->lineEdit_sanitarios->isHidden()){
        sanitario = ui->lineEdit_sanitarios->text().toFloat();
        out << "Sanitarios, "<< sanitario << Qt::endl;
    }
    if(!ui->lineEdit_comedores->isHidden()){
        comedores = ui->lineEdit_comedores->text().toFloat();
        out << "Comedores y cocinas, " << comedores << Qt::endl;
    }
    if(!ui->lineEdit_hidra->isHidden()){
        hidra = ui->lineEdit_hidra->text().toFloat();
        out << "Instalaciones Hidráulicas, " << hidra <<Qt::endl;
    }
    if(!ui->lineEdit_elect->isHidden()){
        elect = ui->lineEdit_elect->text().toFloat();
        out << "Instalaciones eléctricas, "<< elect << Qt::endl;
    }


    out << "Total: " << getTotalConstrucProv() << Qt::endl;

    file.flush();
    file.close();

}


void ConstrucProv::on_pushButton_regresar_clicked()
{

}

float ConstrucProv::getTotalConstrucProv(){

    totalConstrucProv = cerca + caseta + oficina + bodega + dormit + sanitario
                            + comedores + hidra + elect + camino;
    return totalConstrucProv;
}

