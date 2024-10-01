#include "cargostecyadmin.h"
#include "ui_cargostecyadmin.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

CargosTecyAdmin::CargosTecyAdmin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargosTecyAdmin)
{
    ui->setupUi(this);
    ui->checkBox_al->setChecked(true);
    ui->checkBox_ae->setChecked(true);
    ui->checkBox_adp->setChecked(true);
    ui->checkBox_ddp->setChecked(true);
    ui->checkBox_jc->setChecked(true);
    ui->checkBox_c->setChecked(true);
}

CargosTecyAdmin::~CargosTecyAdmin()
{
    delete ui;
}

void CargosTecyAdmin::on_checkBox_al_stateChanged(int arg1)
{

    if(arg1){
        ui->label_al->show();
        ui->lineEdit_al->show();
    }else{
        ui->label_al->hide();
        ui->lineEdit_al->hide();
    }

}


void CargosTecyAdmin::on_checkBox_ae_stateChanged(int arg1)
{
    if(arg1){
        ui->label_ae->show();
        ui->lineEdit_ae->show();
    }else{
        ui->label_ae->hide();
        ui->lineEdit_ae->hide();
    }
}




void CargosTecyAdmin::on_checkBox_adp_stateChanged(int arg1)
{
    if(arg1){
        ui->label_adp->show();
        ui->lineEdit_adp->show();
    }else{
        ui->label_adp->hide();
        ui->lineEdit_adp->hide();
    }
}


void CargosTecyAdmin::on_checkBox_ddp_stateChanged(int arg1)
{
    if(arg1){
        ui->label_ddp->show();
        ui->lineEdit_ddp->show();
    }else{
        ui->label_ddp->hide();
        ui->lineEdit_ddp->hide();
    }
}


void CargosTecyAdmin::on_checkBox_jc_stateChanged(int arg1)
{
    if(arg1){
        ui->label_jc->show();
        ui->lineEdit_jc->show();
    }else{
        ui->label_jc->hide();
        ui->lineEdit_jc->hide();
    }
}


void CargosTecyAdmin::on_checkBox_c_stateChanged(int arg1)
{
    if(arg1){
        ui->label_c->show();
        ui->lineEdit_c->show();
    }else{
        ui->label_c->hide();
        ui->lineEdit_c->hide();
    }
}


void CargosTecyAdmin::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "CARGOS TÉCNICOS Y ADMINISTRATIVOS," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_al->isHidden()){
        al = ui->lineEdit_al->text().toFloat();
        out << "Asesoría Legal, "<< al << Qt::endl;
    }
    if(!ui->lineEdit_ae->isHidden()){
        ae = ui->lineEdit_ae->text().toFloat();
        out << "Asesoría externa, "<< ae << Qt::endl;
    }
    if(!ui->lineEdit_adp->isHidden()){
        adp = ui->lineEdit_adp->text().toFloat();
        out << "Ayudante dpto. de proyectos, " << adp << Qt::endl;
    }
    if(!ui->lineEdit_ddp->isHidden()){
        ddp = ui->lineEdit_ddp->text().toFloat();
        out << "Dibujante dpto. de proyectos, " << ddp <<Qt::endl;
    }
    if(!ui->lineEdit_jc->isHidden()){
        jc = ui->lineEdit_jc->text().toFloat();
        out << "Jefe de compras, " << jc <<Qt::endl;
    }
    if(!ui->lineEdit_c->isHidden()){
        c = ui->lineEdit_c->text().toFloat();
        out << "contador, " << c << Qt::endl;
    }

    out << "Total: " << getTotalCargosTecyAdmin() << Qt::endl;

    file.flush();
    file.close();
}


void CargosTecyAdmin::on_pushButton_regresar_clicked()
{

    hide();
}

float CargosTecyAdmin::getTotalCargosTecyAdmin(){

    total = al + ae+ adp + ddp + jc + c;

    return total;
}

