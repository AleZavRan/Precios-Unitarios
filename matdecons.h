#ifndef MATDECONS_H
#define MATDECONS_H

#include <QDialog>

namespace Ui {
class MatdeCons;
}

class MatdeCons : public QDialog
{
    Q_OBJECT

public:
    explicit MatdeCons(QWidget *parent = nullptr);
    ~MatdeCons();
    float getTotalMatdeCons();

private slots:
    void on_checkBox_cla_stateChanged(int arg1);

    void on_checkBox_iof_stateChanged(int arg1);

    void on_checkBox_pof_stateChanged(int arg1);

    void on_checkBox_cof_stateChanged(int arg1);

    void on_checkBox_p_stateChanged(int arg1);

    void on_checkBox_v_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::MatdeCons *ui;
    float cla = 0;
    float iof = 0;
    float pof = 0;
    float cof = 0;
    float p = 0;
    float v = 0;
    float totalMatdeCons = 0;
};

#endif // MATDECONS_H
