#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "edit.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pic(":/resources/img/gaspacho.jpg");
    int w = ui->label_mainpic->width();
    int h = ui->label_mainpic->height();
    ui->label_mainpic->setPixmap(pic.scaled(w, h, Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Costos_clicked()
{
    costos = new Costos(this);
    costos->show();
}


void MainWindow::on_actionNew_triggered()
{
    QString filter = "All File (*.*);; Text File (*.txt);; XML File (*.xml)";
    QString file_name = QFileDialog::getOpenFileName(this,"Abre un archivo","/home/jano/Documents/QtApps/Tutorials",filter);
    QFile file(file_name);

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"abre un archivo","");
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}


void MainWindow::on_actionEdit_triggered()
{
    Edit edit(this);
    edit.setModal(true);
    edit.exec();

}


void MainWindow::on_actionDelete_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Elimina un archivo","/home/jano/Documents/QtApps/Tutorials");
    QMessageBox::information(this,"mensajito", "ya lo borraste (no es cierto)");
}

