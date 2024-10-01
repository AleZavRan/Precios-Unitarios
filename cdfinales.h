#ifndef CDFINALES_H
#define CDFINALES_H

#include <QDialog>
#include "cdfpreliminares.h"
#include "cimentaciones.h"
#include "drenajes.h"
#include "estructuras.h"
#include "murosdalascastillos.h"
#include "pisos.h"
#include "recubrimientos.h"
#include "colocaciones.h"
#include "azoteas.h"
#include "subcontratos.h"

namespace Ui {
class CDFinales;
}

class CDFinales : public QDialog
{
    Q_OBJECT

public:
    explicit CDFinales(QWidget *parent = nullptr);
    ~CDFinales();

private slots:
    void on_pushButton_cdfpreliminares_clicked();

    void on_pushButton_cimentaciones_clicked();

    void on_pushButton_drenajes_clicked();

    void on_pushButton_estructuras_clicked();

    void on_pushButton_murosdc_clicked();

    void on_pushButton_pisos_clicked();

    void on_pushButton_recubrimientos_clicked();

    void on_pushButton_colocaciones_clicked();

    void on_pushButton_azoteas_clicked();

    void on_pushButton_subcontratos_clicked();

private:
    Ui::CDFinales *ui;
    CDFPreliminares *cDFPreliminares;
    Cimentaciones *cimentaciones;
    Drenajes *drenajes;
    Estructuras *estructuras;
    MurosDalasCastillos *murosDalasCastillos;
    Pisos *pisos;
    Recubrimientos *recubrimientos;
    Colocaciones *colocaciones;
    Azoteas *azoteas;
    Subcontratos *subcontratos;
};

#endif // CDFINALES_H
