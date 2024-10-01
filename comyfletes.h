#ifndef COMYFLETES_H
#define COMYFLETES_H

#include <QDialog>

namespace Ui {
class ComyFletes;
}

class ComyFletes : public QDialog
{
    Q_OBJECT

public:
    explicit ComyFletes(QWidget *parent = nullptr);
    ~ComyFletes();
    float getTotalComyFletes();

private slots:
    void on_checkBox_cel_stateChanged(int arg1);

    void on_checkBox_transeq_stateChanged(int arg1);

    void on_checkBox_auto_stateChanged(int arg1);

    void on_checkBox_cam_stateChanged(int arg1);

    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::ComyFletes *ui;
    float cel = 0;
    float transeq = 0;
    float autom = 0;
    float cam = 0;
    float totalComyFletes = 0;

};

#endif // COMYFLETES_H
