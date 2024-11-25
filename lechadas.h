#ifndef LECHADAS_H
#define LECHADAS_H

#include <QDialog>


namespace Ui {
class Lechadas;
}

class Lechadas : public QDialog
{
    Q_OBJECT

public:
    explicit Lechadas(QWidget *parent = nullptr);
    ~Lechadas();
    void writeTable(QString concepto, QStringList unidad, QStringList material, float cantidadAgCem[], float puAgCem[]);

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::Lechadas *ui;
    float metros2_ = 0;
    float total_ = 0;

    QString concepto_ = "Lechada cemento ";
    QStringList unidad_ = {"bulto", "m3"};
    QStringList material_ = {"de agua", "de cemento"};
    float cantidadAgCem_[2] = {0,0};
    float puAgCem_[2] = {0,0};

    float getCantidadAguaCemento();
    float getTotalLechadas();
};

#endif // LECHADAS_H
