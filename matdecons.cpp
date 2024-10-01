#include "matdecons.h"
#include "ui_matdecons.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

MatdeCons::MatdeCons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MatdeCons)
{
    ui->setupUi(this);
    ui->checkBox_cla->setChecked(true);
    ui->checkBox_iof->setChecked(true);
    ui->checkBox_pof->setChecked(true);
    ui->checkBox_cof->setChecked(true);
    ui->checkBox_p->setChecked(true);
    ui->checkBox_v->setChecked(true);
}

MatdeCons::~MatdeCons()
{
    delete ui;
}

void MatdeCons::on_checkBox_cla_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_cla->show();
        ui->lineEdit_claBr->show();
    }else{
        ui->lineEdit_cla->hide();
        ui->lineEdit_claBr->hide();
    }

}


void MatdeCons::on_checkBox_iof_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_iof->show();
        ui->lineEdit_iofBr->show();
    }else{
        ui->lineEdit_iof->hide();
        ui->lineEdit_iofBr->hide();
    }
}


void MatdeCons::on_checkBox_pof_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_pof->show();
        ui->lineEdit_pofBr->show();
    }else{
        ui->lineEdit_pof->hide();
        ui->lineEdit_pofBr->hide();
    }
}


void MatdeCons::on_checkBox_cof_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_cof->show();
        ui->lineEdit_cofBr->show();
    }else{
        ui->lineEdit_cof->hide();
        ui->lineEdit_cofBr->hide();
    }
}


void MatdeCons::on_checkBox_p_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_p->show();
        ui->lineEdit_pBr->show();
    }else{
        ui->lineEdit_p->hide();
        ui->lineEdit_pBr->hide();
    }
}


void MatdeCons::on_checkBox_v_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_v->show();
        ui->lineEdit_vBr->show();
    }else{
        ui->lineEdit_v->hide();
        ui->lineEdit_vBr->hide();
    }
}


void MatdeCons::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "MATERIALES DE CONSUMO" << Qt::endl;

    if(!ui->lineEdit_cla->isHidden()){
        cla = ui->lineEdit_cla->text().toFloat();
        out << "Combustibles y Lubricantes,"<< cla << Qt::endl;
    }
    if(!ui->lineEdit_iof->isHidden()){
        iof = ui->lineEdit_iof->text().toFloat();
        out << "Impresos oficina, "<< iof << Qt::endl;
    }
    if(!ui->lineEdit_cof->isHidden()){
        cof = ui->lineEdit_cof->text().toFloat();
        out << "Comida oficina, "<< cof << Qt::endl;
    }
    if(!ui->lineEdit_iof->isHidden()){
        pof = ui->lineEdit_pof->text().toFloat();
        out << "Papelería oficina, "<< pof << Qt::endl;
    }
    if(!ui->lineEdit_p->isHidden()){
        p = ui->lineEdit_p->text().toFloat();
        out << "Pasajes, "<< p << Qt::endl;
    }
    if(!ui->lineEdit_v->isHidden()){
        v = ui->lineEdit_v->text().toFloat();
        out << "Varios, "<< v << Qt::endl;
    }

    out << "Total: " << getTotalMatdeCons() << Qt::endl;

    file.flush();
    file.close();

}


void MatdeCons::on_pushButton_regresar_clicked()
{
    hide();
}

float MatdeCons::getTotalMatdeCons(){

    totalMatdeCons = cla + iof + pof + cof + p + v;

    return totalMatdeCons;
}
