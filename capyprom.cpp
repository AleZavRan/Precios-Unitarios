#include "capyprom.h"
#include "ui_capyprom.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

CapyProm::CapyProm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CapyProm)
{
    ui->setupUi(this);
    ui->checkBox_obr->setChecked(true);
    ui->checkBox_emp->setChecked(true);
    ui->checkBox_celof->setChecked(true);
    ui->checkBox_regcli->setChecked(true);
    ui->checkBox_con->setChecked(true);
    ui->checkBox_agui->setChecked(true);
    ui->checkBox_honext->setChecked(true);
}

CapyProm::~CapyProm()
{
    delete ui;
}

void CapyProm::on_checkBox_obr_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_obr->show();
        ui->lineEdit_obrBr->show();
    }else{
        ui->lineEdit_obr->hide();
        ui->lineEdit_obrBr->hide();
    }
}


void CapyProm::on_checkBox_emp_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_emp->show();
        ui->lineEdit_empBr->show();
    }else{
        ui->lineEdit_emp->hide();
        ui->lineEdit_empBr->hide();
    }
}


void CapyProm::on_checkBox_celof_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_celof->show();
        ui->lineEdit_celofBr->show();
    }else{
        ui->lineEdit_celof->hide();
        ui->lineEdit_celofBr->hide();
    }
}


void CapyProm::on_checkBox_regcli_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_regcli->show();
        ui->lineEdit_regcliBr->show();
    }else{
        ui->lineEdit_regcli->hide();
        ui->lineEdit_regcliBr->hide();
    }
}


void CapyProm::on_checkBox_con_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_con->show();
        ui->lineEdit_conBr->show();
    }else{
        ui->lineEdit_con->hide();
        ui->lineEdit_conBr->hide();
    }
}


void CapyProm::on_checkBox_agui_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_agui->show();
        ui->lineEdit_aguiBr->show();
    }else{
        ui->lineEdit_agui->hide();
        ui->lineEdit_aguiBr->hide();
    }
}


void CapyProm::on_checkBox_honext_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_hon->show();
        ui->lineEdit_honBr->show();
    }else{
        ui->lineEdit_hon->hide();
        ui->lineEdit_honBr->hide();
    }
}


void CapyProm::on_pushButton_regresar_clicked()
{
    hide();
}


void CapyProm::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "CAPACITACIÓN Y PROMOCIÓN" << Qt::endl;

    if(!ui->lineEdit_obr->isHidden()){
        obr = ui->lineEdit_obr->text().toFloat();
        out << "Obreros,"<< obr << Qt::endl;
    }
    if(!ui->lineEdit_emp->isHidden()){
        emp = ui->lineEdit_emp->text().toFloat();
        out << "Empleados, "<< emp << Qt::endl;
    }
    if(!ui->lineEdit_celof->isHidden()){
        celof = ui->lineEdit_celof->text().toFloat();
        out << "Celebraciones oficina, "<< celof << Qt::endl;
    }
    if(!ui->lineEdit_regcli->isHidden()){
        regcli = ui->lineEdit_regcli->text().toFloat();
        out << "Regalos Clientes, "<< regcli << Qt::endl;
    }
    if(!ui->lineEdit_con->isHidden()){
        con = ui->lineEdit_con->text().toFloat();
        out << "Concursos, "<< con << Qt::endl;
    }
    if(!ui->lineEdit_agui->isHidden()){
        agui = ui->lineEdit_agui->text().toFloat();
        out << "Aguinaldos, "<< agui << Qt::endl;
    }

    out << "Total: " << getTotalCapyProm() << Qt::endl;

    file.flush();
    file.close();
}

float CapyProm::getTotalCapyProm(){

    totalCapyProm = obr + emp + celof + regcli + con + agui;

    return totalCapyProm;
}

