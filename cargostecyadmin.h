#ifndef CARGOSTECYADMIN_H
#define CARGOSTECYADMIN_H

#include <QDialog>

namespace Ui {
class CargosTecyAdmin;
}

class CargosTecyAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit CargosTecyAdmin(QWidget *parent = nullptr);
    ~CargosTecyAdmin();
    float getTotalCargosTecyAdmin();

private slots:
    void on_checkBox_al_stateChanged(int arg1);

    void on_checkBox_ae_stateChanged(int arg1);

    void on_checkBox_adp_stateChanged(int arg1);

    void on_checkBox_ddp_stateChanged(int arg1);

    void on_checkBox_jc_stateChanged(int arg1);

    void on_checkBox_c_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::CargosTecyAdmin *ui;
    float al = 0;
    float ae = 0;
    float adp = 0;
    float ddp = 0;
    float jc = 0;
    float c = 0;
    float total = 0;
};

#endif // CARGOSTECYADMIN_H
