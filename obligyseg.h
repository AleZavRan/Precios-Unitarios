#ifndef OBLIGYSEG_H
#define OBLIGYSEG_H

#include <QDialog>

namespace Ui {
class ObligySeg;
}

class ObligySeg : public QDialog
{
    Q_OBJECT

public:
    explicit ObligySeg(QWidget *parent = nullptr);
    ~ObligySeg();
    float getTotalObligySeg();

private slots:
    void on_checkBox_camara_stateChanged(int arg1);

    void on_checkBox_imss_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::ObligySeg *ui;
    float imss = 0;
    float camara = 0;
    float totalObligySeg = 0;
};

#endif // OBLIGYSEG_H
