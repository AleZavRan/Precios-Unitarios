#include "alquiydepre.h"
#include "ui_alquiydepre.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

AlquiyDepre::AlquiyDepre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlquiyDepre)
{
    ui->setupUi(this);
    ui->checkBox_Oficinas->setChecked(true);
    ui->checkBox_luz->setChecked(true);
    ui->checkBox_tel->setChecked(true);
    ui->checkBox_eqOf->setChecked(true);
    ui->checkBox_eqTrans->setChecked(true);
    ui->checkBox_deprEqOf->setChecked(true);
    ui->checkBox_deprEqTransp->setChecked(true);
}

AlquiyDepre::~AlquiyDepre()
{
    delete ui;
}

void AlquiyDepre::on_checkBox_Oficinas_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_oficinas->show();
    }else{
        ui->lineEdit_oficinas->hide();
    }

}


void AlquiyDepre::on_checkBox_luz_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_luz->show();
    }else{
        ui->lineEdit_luz->hide();
    }
}


void AlquiyDepre::on_checkBox_tel_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_telefono->show();
    }else{
        ui->lineEdit_telefono->hide();
    }
}


void AlquiyDepre::on_checkBox_eqOf_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_eqOficina->show();
        ui->lineEdit_eqOficinaBr->show();
    }else{
        ui->lineEdit_eqOficina->hide();
        ui->lineEdit_eqOficinaBr->hide();
    }
}


void AlquiyDepre::on_checkBox_eqTrans_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_eqTransp->show();
        ui->lineEdit_eqTranspBr->show();
    }else{
        ui->lineEdit_eqTransp->hide();
        ui->lineEdit_eqTranspBr->hide();
    }
}


void AlquiyDepre::on_checkBox_deprEqOf_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_deprOf->show();
    }else{
        ui->lineEdit_deprOf->hide();
    }
}


void AlquiyDepre::on_checkBox_deprEqTransp_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_DeprTrans->show();
    }else{
        ui->lineEdit_DeprTrans->hide();
    }
}


void AlquiyDepre::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "ALQUILERES Y DEPRECIACIONES," << Qt::endl;

    if(!ui->lineEdit_oficinas->isHidden()){
        oficinas_m = ui->lineEdit_oficinas->text().toFloat();
        out << "Renta Oficinas, "<< oficinas_m << Qt::endl;
    }
    if(!ui->lineEdit_luz->isHidden()){
        luz_m = ui->lineEdit_luz->text().toFloat();
        out << "Luz, "<< luz_m << Qt::endl;
    }
    if(!ui->lineEdit_telefono->isHidden()){
        tel_m = ui->lineEdit_telefono->text().toFloat();
        out << "Teléfono, " << tel_m << Qt::endl;
    }
    if(!ui->lineEdit_eqTransp->isHidden()){
        eqTrans_m = ui->lineEdit_eqTransp->text().toFloat();
        out << "Equipo de Transporte, " << eqTrans_m <<Qt::endl;
    }
    if(!ui->lineEdit_eqOficina->isHidden()){
        eqOf_m = ui->lineEdit_eqOficina->text().toFloat();
        out << "Equipo de oficina, " << eqOf_m <<Qt::endl;
    }
    if(!ui->lineEdit_deprOf->isHidden()){
        deprEqOf_m = ui->lineEdit_deprOf->text().toFloat();
        out << "Depreciaciones eq. oficina, " << deprEqOf_m << Qt::endl;
    }
    if(!ui->lineEdit_DeprTrans->isHidden()){
        deprEqTransp_m = ui->lineEdit_DeprTrans->text().toFloat();
        out << "Depreciaciones eq. Transporte, " << deprEqTransp_m << Qt::endl;
    }

    out << "Total: " << getTotalAlquiyDepre() << Qt::endl;

    file.flush();
    file.close();

}


void AlquiyDepre::on_pushButton_regresar_clicked()
{
    hide();
}

float AlquiyDepre::getTotalAlquiyDepre(){

    totalAlquiyDepre = oficinas_m + luz_m + tel_m + eqOf_m + eqTrans_m + deprEqOf_m + deprEqTransp_m;

    return totalAlquiyDepre;
}

