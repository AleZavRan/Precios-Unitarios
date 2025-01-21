#ifndef CIMBRAS_H
#define CIMBRAS_H

#include <QDialog>

namespace Ui {
class Cimbras;
}

class Cimbras : public QDialog
{
    Q_OBJECT

public:
    explicit Cimbras(QWidget *parent = nullptr);
    ~Cimbras();
    void writeTable(QString concepto, QStringList unidad, QStringList material);

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::Cimbras *ui;

    float mTrabes_ = 0;
    float mCastillos_ = 0;
    float mCadenas_ = 0;
    float mDalas_ = 0;
    float m2Losas_ = 0;
    float mZapatas_ = 0;
    float percWaste_ = 0;                            //Percentage of waste of wood
    QStringList tipoDeEstructura_ = {"para Trabes", "para Castillos",
                                     "para Dalas", "para Losas", "para Zapatas"}; //Use of wood
    float calculaCantidadTabla3ra(float m, float percWaste, QString tipoDeArmado);
    float calculaCantidadTablonCepillado(float m, float percWaste);
    float calculaCantidadTarima(float m2, float percWaste);
    float* calculaCantidadClavosAlambron(float m, float percWaste, QString tipoDeArmado);
    float* calculaCantidadCimbraLosas(float m2, float percWaste, bool tarima, bool tabla, bool tablon);
};

#endif // CIMBRAS_H
