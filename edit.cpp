#include "edit.h"
#include "ui_edit.h"
#include <QDir>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QString>

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(40);
  /*  QDir qdir("/home/jano/Documents/QtApps/Tutorials");

    foreach(QFileInfo var, qdir.entryInfoList()){
        ui->listWidget->addItem(var.fileName());

    }*/
}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_pushButton_open_clicked()
{
    QString filter = "All File (*.*);; Text File (*.txt);; XML File (*.xml);; CSV File (*.csv)";
    QString file_name = QFileDialog::getOpenFileName(this,"Abre un archivo","/home/jano/Documents/QtApps/Tutorials",filter);
    QFile file(file_name);

    if(file.open(QIODevice::ReadWrite)){

        QTextStream Stream(&file);
        int rowNumber = 0;
        while(Stream.atEnd() == false){
            QString LineData = Stream.readLine();
            QStringList Data = LineData.split(",");

            rowNumber += 1;
            for(int i = 0; i < Data.length(); i++){
                ui->tableWidget->setItem(rowNumber,i + 1, new QTableWidgetItem(QString(Data.at(i))));
                qDebug() << "ROW" << rowNumber << "Column" << i + 1 << "data: " << Data.at(i);
            }



        }

    }

    /*
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"abre un archivo","");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    */
    //ui->plainTextEdit->setPlainText(text);
    //ui->tableView->setModel();
    file.close();
}




void Edit::on_pushButton_edit_clicked()
{

}



void Edit::on_tableWidget_cellDoubleClicked(int row, int column)
{
    qDebug() << ui->tableWidget->item(row, column)->text();
}

