#ifndef COSTOS_H
#define COSTOS_H

#include <QDialog>
#include "costosindirectos.h"
#include "costosdirectos.h"


namespace Ui {
class Costos;
}

class Costos : public QDialog
{
    Q_OBJECT

public:
    explicit Costos(QWidget *parent = nullptr);
    ~Costos();

private slots:
    void on_pushButton_CostosIndirectos_clicked();

    void on_pushButton_CostosDirectos_clicked();

private:
    Ui::Costos *ui;
    CostosIndirectos *costosIndirectos;
    CostosDirectos *costosDirectos;
};

#endif // COSTOS_H
