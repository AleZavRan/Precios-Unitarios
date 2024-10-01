#include "obligyseg.h"
#include "ui_obligyseg.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

ObligySeg::ObligySeg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ObligySeg)
{
    ui->setupUi(this);
    ui->checkBox_camara->setChecked(true);
    ui->checkBox_imss->setChecked(true);
}

ObligySeg::~ObligySeg()
{
    delete ui;
}

void ObligySeg::on_checkBox_camara_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_camara->show();
    }else{
        ui->lineEdit_camara->hide();
    }
}


void ObligySeg::on_checkBox_imss_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_imss->show();
    }else{
        ui->lineEdit_imss->hide();
    }
}


void ObligySeg::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente");


    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "Obligaciones y seguros," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_camara->isHidden()){
        camara = ui->lineEdit_camara->text().toFloat();
        out << "Cámara Mexicana Industria Construccion,"<< camara << Qt::endl;
    }
    if(!ui->lineEdit_imss->isHidden()){
        imss = ui->lineEdit_imss->text().toFloat();
        out << "IMSS, "<< imss << Qt::endl;
    }

    out << "Total: " << getTotalObligySeg() << Qt::endl;

    file.flush();
    file.close();
}


void ObligySeg::on_pushButton_regresar_clicked()
{
    hide();
}

float ObligySeg::getTotalObligySeg(){

    totalObligySeg = camara + imss;

    return totalObligySeg;
}

