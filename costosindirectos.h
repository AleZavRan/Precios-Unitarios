#ifndef COSTOSINDIRECTOS_H
#define COSTOSINDIRECTOS_H

#include <QDialog>
#include "cioperacion.h"
#include "ciobra.h"



namespace Ui {
class CostosIndirectos;
}

class CostosIndirectos : public QDialog
{
    Q_OBJECT

public:
    explicit CostosIndirectos(QWidget *parent = nullptr);
    ~CostosIndirectos();

private slots:
    void on_pushButton_CIOperacion_clicked();

    void on_pushButton_CIObra_clicked();

private:
    Ui::CostosIndirectos *ui;
    CIOperacion *cioperacion;
    CIObra *ciobra;
};

#endif // COSTOSINDIRECTOS_H
