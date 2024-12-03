#ifndef PASTAS_H
#define PASTAS_H

#include <QDialog>

namespace Ui {
class Pastas;
}

class Pastas : public QDialog
{
    Q_OBJECT

public:
    explicit Pastas(QWidget *parent = nullptr);
    ~Pastas();
    float* getCantidadAguaCemento(float m2);
    void writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgCem[], float puAgCem[]);

private slots:
    void on_pushButton_agregar_clicked();
    void on_comboBox_Material_currentIndexChanged(int index);

private:
    Ui::Pastas *ui;

    QString concepto_ = "Pasta de";
    QStringList unidad_ = {"m3", "bulto 20kg", "bulto 20kg"};
    QStringList material_ = {"de agua", "de cemento"};
    float* cantidadAgCem_ = new float[2]; //Declared in this way for practicing heap memory allocation
    float cantidadAgYeso_[2] = {0,0};
    float cantidadAgTextuco_[2] = {0,0};
    float puAgCem_[2] = {0,0};           //Unit prices water - binder
    int proporcionMat1Mat2_[2] = {0,0};
    int mmEspesor_ = 0;
    float m2_ = 0;
    float percWasteWater_ = 0; //Percentage of water waste
    float percWasteBinder_ = 0; //Percentage of binder waste

    void calculaCantidadAguaYeso(float m2, int mmEspesor, float percWasteWater, float percWasteBinder);
    void calculaCantidadAguaTextuco(float m2, int mmEspesor, float percWasteWater, float percWasteBinder);
};

#endif // PASTAS_H
