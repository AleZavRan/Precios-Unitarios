#ifndef CONSUMOSVARIOS_H
#define CONSUMOSVARIOS_H

#include <QDialog>

namespace Ui {
class ConsumosVarios;
}

class ConsumosVarios : public QDialog
{
    Q_OBJECT

public:
    explicit ConsumosVarios(QWidget *parent = nullptr);
    ~ConsumosVarios();
    float getTotalConsumosVarios();

private slots:
    void on_checkBoxconselec_stateChanged(int arg1);

    void on_checkBox_consagua_stateChanged(int arg1);

    void on_checkBox_eqofdepr_stateChanged(int arg1);

    void on_checkBox_foto_stateChanged(int arg1);

    void on_checkBox_papeleria_stateChanged(int arg1);

    void on_checkBox_varios_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::ConsumosVarios *ui;
    float conselec = 0;
    float consagua = 0;
    float eqofdepr = 0;
    float foto = 0;
    float papeleria = 0;
    float varios = 0;
    float totalConsumosV = 0;
};

#endif // CONSUMOSVARIOS_H
