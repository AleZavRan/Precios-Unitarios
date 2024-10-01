#include "consumosvarios.h"
#include "ui_consumosvarios.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


ConsumosVarios::ConsumosVarios(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsumosVarios)
{
    ui->setupUi(this);
    ui->checkBoxconselec->setChecked(true);
    ui->checkBox_consagua->setChecked(true);
    ui->checkBox_eqofdepr->setChecked(true);
    ui->checkBox_foto->setChecked(true);
    ui->checkBox_papeleria->setChecked(true);
    ui->checkBox_varios->setChecked(true);
}

ConsumosVarios::~ConsumosVarios()
{
    delete ui;
}

void ConsumosVarios::on_checkBoxconselec_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_conselect->show();
    }else{
        ui->lineEdit_conselect->hide();
    }

}


void ConsumosVarios::on_checkBox_consagua_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_consagua->show();
    }else{
        ui->lineEdit_consagua->hide();
    }
}


void ConsumosVarios::on_checkBox_eqofdepr_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_eqofdepr->show();
    }else{
        ui->lineEdit_eqofdepr->hide();
    }
}


void ConsumosVarios::on_checkBox_foto_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_foto->show();
    }else{
        ui->lineEdit_foto->hide();
    }
}


void ConsumosVarios::on_checkBox_papeleria_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_papeleria->show();
    }else{
        ui->lineEdit_papeleria->hide();
    }
}


void ConsumosVarios::on_checkBox_varios_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_varios->show();
    }else{
        ui->lineEdit_varios->hide();
    }
}


void ConsumosVarios::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "CONSUMOS Y VARIOS," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_conselect->isHidden()){
        conselec = ui->lineEdit_conselect->text().toFloat();
        out << "Consumo Eléctrico, "<< conselec << Qt::endl;
    }
    if(!ui->lineEdit_consagua->isHidden()){
        consagua = ui->lineEdit_consagua->text().toFloat();
        out << "Consumo Agua, "<< consagua << Qt::endl;
    }
    if(!ui->lineEdit_eqofdepr->isHidden()){
        eqofdepr = ui->lineEdit_eqofdepr->text().toFloat();
        out << "Equipo Oficina Depreciación, " << eqofdepr << Qt::endl;
    }
    if(!ui->lineEdit_foto->isHidden()){
        foto = ui->lineEdit_foto->text().toFloat();
        out << "Fotografía, " << foto <<Qt::endl;
    }
    if(!ui->lineEdit_papeleria->isHidden()){
        papeleria = ui->lineEdit_papeleria->text().toFloat();
        out << "Papelería y copias, "<< papeleria << Qt::endl;
    }
    if(!ui->lineEdit_varios->isHidden()){
        varios = ui->lineEdit_varios->text().toFloat();
        out << "Varios, "<< varios << Qt::endl;
    }


    out << "Total: " << getTotalConsumosVarios() << Qt::endl;

    file.flush();
    file.close();

}


void ConsumosVarios::on_pushButton_regresar_clicked()
{
    hide();
}


float ConsumosVarios::getTotalConsumosVarios(){

    totalConsumosV = conselec + consagua + eqofdepr + foto + papeleria + varios;

    return totalConsumosV;
}
