#ifndef TRASLADOSPER_H
#define TRASLADOSPER_H

#include <QDialog>

namespace Ui {
class TrasladosPer;
}

class TrasladosPer : public QDialog
{
    Q_OBJECT

public:
    explicit TrasladosPer(QWidget *parent = nullptr);
    ~TrasladosPer();
    float getTotalTrasladosPer();

private slots:
    void on_checkBox_super_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::TrasladosPer *ui;
    float supervision = 0;
    float totalTraslados = 0;
};

#endif // TRASLADOSPER_H
