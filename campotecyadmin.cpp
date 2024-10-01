#include "campotecyadmin.h"
#include "ui_campotecyadmin.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

CampoTecyAdmin::CampoTecyAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CampoTecyAdmin)
{
    ui->setupUi(this);
    ui->checkBox_jefe->setChecked(true);
    ui->checkBox_resi->setChecked(true);
    ui->checkBox_chof->setChecked(true);
    ui->checkBox_vela->setChecked(true);
    ui->checkBox_secre->setChecked(true);
}

CampoTecyAdmin::~CampoTecyAdmin()
{
    delete ui;
}

void CampoTecyAdmin::on_checkBox_jefe_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_jefe->show();
    }else{
        ui->lineEdit_jefe->hide();
    }
}


void CampoTecyAdmin::on_checkBox_resi_stateChanged(int arg1)
{

    if(arg1){
        ui->lineEdit_resi->show();
    }else{
        ui->lineEdit_resi->hide();
    }
}


void CampoTecyAdmin::on_checkBox_chof_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_chof->show();
    }else{
        ui->lineEdit_chof->hide();
    }
}


void CampoTecyAdmin::on_checkBox_vela_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_vela->show();
    }else{
        ui->lineEdit_vela->hide();
    }
}


void CampoTecyAdmin::on_checkBox_secre_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_secre->show();
    }else{
        ui->lineEdit_secre->hide();
    }
}


void CampoTecyAdmin::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "CARGOS DE CAMPO TÉCNICOS Y ADMINISTRATIVOS," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_jefe->isHidden()){
        jefe = ui->lineEdit_jefe->text().toFloat();
        out << "Jefe de Obra, "<< jefe << Qt::endl;
    }
    if(!ui->lineEdit_resi->isHidden()){
        resi = ui->lineEdit_resi->text().toFloat();
        out << "Residente frente 1, "<< resi << Qt::endl;
    }
    if(!ui->lineEdit_chof->isHidden()){
        chof = ui->lineEdit_chof->text().toFloat();
        out << "Chofer, " << chof << Qt::endl;
    }
    if(!ui->lineEdit_vela->isHidden()){
        vela = ui->lineEdit_vela->text().toFloat();
        out << "Velador, " << vela <<Qt::endl;
    }
    if(!ui->lineEdit_secre->isHidden()){
        secre = ui->lineEdit_secre->text().toFloat();
        out << "Secretaria, " << secre <<Qt::endl;
    }

    out << "Total: " << getTotalCampoTecyAdmin() << Qt::endl;

    file.flush();
    file.close();
}


void CampoTecyAdmin::on_pushButton_regresar_clicked()
{
    hide();
}

float CampoTecyAdmin::getTotalCampoTecyAdmin(){

    totalcampotya = jefe + resi+ chof + vela + secre;

    return totalcampotya;
}

