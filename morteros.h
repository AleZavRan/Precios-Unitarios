#ifndef MORTEROS_H
#define MORTEROS_H

#include <QDialog>

namespace Ui {
class Morteros;
}

class Morteros : public QDialog
{
    Q_OBJECT

public:
    explicit Morteros(QWidget *parent = nullptr);
    ~Morteros();
    void writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgArCem[], float puAgArCem[]);

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::Morteros *ui;

    QString concepto_ = "Mortero";
    QStringList unidad_ = {"lts", "m3", "bulto 20kg"};
    QStringList material_ = {"de agua", "de arena", "de cemento"};
    float cantidadAgArCem_[3] = {0,0,0};    //Amount of water, sand, cement
    float puAgArCem_[4] = {0,0,0};           //Unit prices of water, sand, cement
    float m2_ = 0;
    int mmEspesorIndex_ = 0; //Index of mm de Espesor parameter (5mm,10m,15m,20mm)
    float percWasteBlend_ = 0; //Percentage of blend waste
    QString tipoDeMezcla_ = "";

    void calculaCantidadAgArCem(float m2, int mmEspesorIndex, float percWasteBlend, QString tipoDeMezcla);
};

#endif // MORTEROS_H
