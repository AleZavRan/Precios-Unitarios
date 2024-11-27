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
    void writeTable(QString concepto, int proporcionMat1Mat2[], QStringList unidad, QStringList material, float cantidadAgCem[], float puAgCem[]);

private slots:
    void on_pushButton_agregar_clicked();
    void on_comboBox_Material_currentIndexChanged(int index);

private:
    Ui::Pastas *ui;

    QString concepto_ = "Pasta de";
    QStringList unidad_ = {"m3", "bulto", "bulto"};
    QStringList material_ = {"de agua", "de cemento"};
    float* cantidadAgCem_ = new float[2]; //Declared in this way for practicing heap memory allocation
    float cantidadAgYeso_[2] = {0,0};
    float cantidadAgTextuco_[2] = {0,0};
    float puAgCem_[2] = {0,0};           //Unit prices water - binder
    int proporcionMat1Mat2_[2] = {0,0};


    void calculaCantidadAguaYeso(float m2);
    void calculaCantidadAguaTextuco(float m2);
};

#endif // PASTAS_H
