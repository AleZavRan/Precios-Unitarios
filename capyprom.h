#ifndef CAPYPROM_H
#define CAPYPROM_H

#include <QDialog>

namespace Ui {
class CapyProm;
}

class CapyProm : public QDialog
{
    Q_OBJECT

public:
    explicit CapyProm(QWidget *parent = nullptr);
    ~CapyProm();
    float getTotalCapyProm();

private slots:
    void on_checkBox_obr_stateChanged(int arg1);

    void on_checkBox_emp_stateChanged(int arg1);

    void on_checkBox_celof_stateChanged(int arg1);

    void on_checkBox_regcli_stateChanged(int arg1);

    void on_checkBox_con_stateChanged(int arg1);

    void on_checkBox_agui_stateChanged(int arg1);

    void on_checkBox_honext_stateChanged(int arg1);

    void on_pushButton_regresar_clicked();

    void on_pushButton_agregar_clicked();

private:
    Ui::CapyProm *ui;
    float obr = 0;
    float emp = 0;
    float celof = 0;
    float regcli = 0;
    float con = 0;
    float agui = 0;
    float honext = 0;
    float totalCapyProm = 0;
};

#endif // CAPYPROM_H
