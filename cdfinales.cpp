#include "cdfinales.h"
#include "ui_cdfinales.h"

CDFinales::CDFinales(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDFinales)
{
    ui->setupUi(this);
}

CDFinales::~CDFinales()
{
    delete ui;
}

void CDFinales::on_pushButton_cdfpreliminares_clicked()
{
    cDFPreliminares = new CDFPreliminares(this);
    cDFPreliminares->show();

}


void CDFinales::on_pushButton_cimentaciones_clicked()
{
    cimentaciones = new Cimentaciones(this);
    cimentaciones->show();
}


void CDFinales::on_pushButton_drenajes_clicked()
{
    drenajes = new Drenajes(this);
    drenajes->show();
}


void CDFinales::on_pushButton_estructuras_clicked()
{
    estructuras = new Estructuras(this);
    estructuras->show();
}


void CDFinales::on_pushButton_murosdc_clicked()
{
   murosDalasCastillos = new MurosDalasCastillos(this);
   murosDalasCastillos->show();
}


void CDFinales::on_pushButton_pisos_clicked()
{
    pisos = new Pisos(this);
    pisos->show();
}


void CDFinales::on_pushButton_recubrimientos_clicked()
{
    recubrimientos = new Recubrimientos(this);
    recubrimientos->show();
}


void CDFinales::on_pushButton_colocaciones_clicked()
{
    colocaciones = new Colocaciones(this);
    colocaciones->show();
}


void CDFinales::on_pushButton_azoteas_clicked()
{
    azoteas = new Azoteas(this);
    azoteas->show();
}


void CDFinales::on_pushButton_subcontratos_clicked()
{
    subcontratos = new Subcontratos(this);
    subcontratos->show();
}

