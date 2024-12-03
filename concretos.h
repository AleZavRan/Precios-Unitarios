#ifndef CONCRETOS_H
#define CONCRETOS_H

#include <QDialog>

namespace Ui {
class Concretos;
}

class Concretos : public QDialog
{
    Q_OBJECT

public:
    explicit Concretos(QWidget *parent = nullptr);
    ~Concretos();
    void writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgArGrCem[], float puAgArGrCem[]);

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();


private:
    Ui::Concretos *ui;

    QString concepto_ = "Concreto";
    QStringList unidad_ = {"lts", "m3", "m3", "bulto 20kg"};
    QStringList material_ = {"de agua", "de arena", "de grava", "de cemento"};
    float cantidadAgArGrCem_[4] = {0,0,0,0}; //Amount of water, sand, gravel, cement
    float puAgArGrCem_[4] = {0,0,0,0};           //Unit prices of water, sand, gravel, cement
    float m3_ = 0;
    float percWasteBlend_ = 0; //Percentage of blend waste
    QString tipoDeMezcla_ = "";

    void calculaCantidadAgArGrCem(float m3, float percWasteBlend, QString tipoDeMezcla);
};

#endif // CONCRETOS_H
