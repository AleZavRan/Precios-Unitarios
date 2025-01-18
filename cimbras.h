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
    float mDalas_ = 0;
    float mLosas_ = 0;
    float mZapatas_ = 0;
    float percWaste_ = 0;                            //Percentage of waste of wood
    QStringList tipoDeEstructura_ = {"para Trabes", "para Castillos",
                                     "para Dalas", "para Losas", "para Zapatas"}; //Use of wood
};

#endif // CIMBRAS_H
