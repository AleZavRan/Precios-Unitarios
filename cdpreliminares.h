#ifndef CDPRELIMINARES_H
#define CDPRELIMINARES_H

#include <QDialog>
#include "lechadas.h"
#include "pastas.h"
#include "morteros.h"
#include "concretos.h"
#include "aceros.h"
#include "cimbras.h"
#include "equipos.h"

namespace Ui {
class CDPreliminares;
}

class CDPreliminares : public QDialog
{
    Q_OBJECT

public:
    explicit CDPreliminares(QWidget *parent = nullptr);
    ~CDPreliminares();

private slots:
    void on_pushButton_lechadas_clicked();

    void on_pushButton_pastas_clicked();

    void on_pushButton_morteros_clicked();

    void on_pushButton_concretos_clicked();

    void on_pushButton_aceros_clicked();

    void on_pushButton_cimbras_clicked();

    void on_pushButton_equipos_clicked();

private:
    Ui::CDPreliminares *ui;
    Lechadas *lechadas;
    Pastas *pastas;
    Morteros *morteros;
    Concretos *concretos;
    Aceros *aceros;
    Cimbras *cimbras;
    Equipos *equipos;
};

#endif // CDPRELIMINARES_H
