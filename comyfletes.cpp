#include "comyfletes.h"
#include "ui_comyfletes.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

ComyFletes::ComyFletes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComyFletes)
{
    ui->setupUi(this);
    ui->checkBox_cel->setChecked(true);
    ui->checkBox_transeq->setChecked(true);
    ui->checkBox_auto->setChecked(true);
    ui->checkBox_cam->setChecked(true);
}

ComyFletes::~ComyFletes()
{
    delete ui;
}

void ComyFletes::on_checkBox_cel_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_celobra->show();
    }else{
        ui->lineEdit_celobra->hide();
    }
}


void ComyFletes::on_checkBox_transeq_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_transeq->show();
    }else{
        ui->lineEdit_transeq->hide();
    }
}


void ComyFletes::on_checkBox_auto_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_auto->show();
    }else{
        ui->lineEdit_auto->hide();
    }
}


void ComyFletes::on_checkBox_cam_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_camioneta->show();
    }else{
        ui->lineEdit_camioneta->hide();
    }
}


void ComyFletes::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "COMUNICACIONES Y FLETES," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_celobra->isHidden()){
        cel = ui->lineEdit_celobra->text().toFloat();
        out << "Celular de Obra, "<< cel << Qt::endl;
    }
    if(!ui->lineEdit_transeq->isHidden()){
        transeq = ui->lineEdit_transeq->text().toFloat();
        out << "Transporte de equipo, "<< transeq << Qt::endl;
    }
    if(!ui->lineEdit_auto->isHidden()){
        autom = ui->lineEdit_auto->text().toFloat();
        out << "Automóvil, " << autom << Qt::endl;
    }
    if(!ui->lineEdit_camioneta->isHidden()){
        cam = ui->lineEdit_camioneta->text().toFloat();
        out << "Camioneta, " << cam <<Qt::endl;
    }

    out << "Total: " << getTotalComyFletes() << Qt::endl;

    file.flush();
    file.close();

}


void ComyFletes::on_pushButton_regresar_clicked()
{
    hide();
}

float ComyFletes::getTotalComyFletes(){

    totalComyFletes = cel + transeq + autom + cam;

    return totalComyFletes;
}

