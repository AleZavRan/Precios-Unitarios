#ifndef CONSTRUCPROV_H
#define CONSTRUCPROV_H

#include <QDialog>

namespace Ui {
class ConstrucProv;
}

class ConstrucProv : public QDialog
{
    Q_OBJECT

public:
    explicit ConstrucProv(QWidget *parent = nullptr);
    ~ConstrucProv();
    float getTotalConstrucProv();

private slots:
    void on_checkBox_cerca_stateChanged(int arg1);

    void on_checkBox_caseta_stateChanged(int arg1);

    void on_checkBox_oficina_stateChanged(int arg1);

    void on_checkBox_bodega_stateChanged(int arg1);

    void on_checkBox_dormit_stateChanged(int arg1);

    void on_checkBox_sanitario_stateChanged(int arg1);

    void on_checkBox_comedores_stateChanged(int arg1);

    void on_checkBox_hidra_stateChanged(int arg1);

    void on_checkBox_elect_stateChanged(int arg1);

    void on_checkBox_camino_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::ConstrucProv *ui;
    float cerca = 0;
    float caseta = 0;
    float oficina = 0;
    float bodega = 0;
    float dormit = 0;
    float sanitario = 0;
    float comedores = 0;
    float hidra = 0;
    float elect = 0;
    float camino = 0;
    float totalConstrucProv = 0;

};

#endif // CONSTRUCPROV_H
