#ifndef CAMPOTECYADMIN_H
#define CAMPOTECYADMIN_H

#include <QDialog>

namespace Ui {
class CampoTecyAdmin;
}

class CampoTecyAdmin : public QDialog
{
    Q_OBJECT

public:
    explicit CampoTecyAdmin(QWidget *parent = nullptr);
    ~CampoTecyAdmin();
    float getTotalCampoTecyAdmin();

private slots:
    void on_checkBox_jefe_stateChanged(int arg1);

    void on_checkBox_resi_stateChanged(int arg1);

    void on_checkBox_chof_stateChanged(int arg1);

    void on_checkBox_vela_stateChanged(int arg1);

    void on_checkBox_secre_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::CampoTecyAdmin *ui;
    float jefe = 0;
    float resi = 0;
    float chof = 0;
    float vela = 0;
    float secre = 0;
    float totalcampotya = 0;
};

#endif // CAMPOTECYADMIN_H
