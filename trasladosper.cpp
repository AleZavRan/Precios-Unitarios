#include "trasladosper.h"
#include "ui_trasladosper.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


TrasladosPer::TrasladosPer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrasladosPer)
{
    ui->setupUi(this);
    ui->checkBox_super->setChecked(true);
}

TrasladosPer::~TrasladosPer()
{
    delete ui;
}

void TrasladosPer::on_checkBox_super_stateChanged(int arg1)
{
    if(arg1){
        ui->lineEdit_super->show();
    }else{
        ui->lineEdit_super->hide();
    }

}


void TrasladosPer::on_pushButton_agregar_clicked()
{
    QMessageBox::information(this,"Info","Campos agregados exitosamente!");

    QFile file("/home/jano/Documents/QtApps/Tutorials/prueba1.csv");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"guarnin","archivo no abierto");
    }

    QTextStream out(&file);

    out << "TRASLADOS DE PERSONAL," << "Costo Mensual," << "Costo Bruto" << Qt::endl;

    if(!ui->lineEdit_super->isHidden()){
        supervision = ui->lineEdit_super->text().toFloat();
        out << "Supervisión, "<< supervision << Qt::endl;
    }

    out << "Total: " << getTotalTrasladosPer() << Qt::endl;

    file.flush();
    file.close();

}


void TrasladosPer::on_pushButton_regresar_clicked()
{
    hide();
}

float TrasladosPer::getTotalTrasladosPer(){

    totalTraslados = supervision;


    return totalTraslados;
}

