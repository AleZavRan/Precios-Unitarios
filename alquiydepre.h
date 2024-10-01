#ifndef ALQUIYDEPRE_H
#define ALQUIYDEPRE_H

#include <QDialog>

namespace Ui {
class AlquiyDepre;
}

class AlquiyDepre : public QDialog
{
    Q_OBJECT

public:
    explicit AlquiyDepre(QWidget *parent = nullptr);
    ~AlquiyDepre();
    float getTotalAlquiyDepre();

private slots:

    void on_checkBox_Oficinas_stateChanged(int arg1);

    void on_checkBox_luz_stateChanged(int arg1);

    void on_checkBox_tel_stateChanged(int arg1);

    void on_checkBox_eqOf_stateChanged(int arg1);

    void on_checkBox_eqTrans_stateChanged(int arg1);

    void on_checkBox_deprEqOf_stateChanged(int arg1);

    void on_checkBox_deprEqTransp_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::AlquiyDepre *ui;
    float oficinas_m = 0;
    float luz_m = 0;
    float tel_m = 0;
    float eqOf_m = 0;
    float eqOf_br = 0;
    float eqTrans_m = 0;
    float eqTrans_br = 0;
    float deprEqOf_m = 0;
    float deprEqTransp_m = 0;
    float totalAlquiyDepre = 0;
};

#endif // ALQUIYDEPRE_H
