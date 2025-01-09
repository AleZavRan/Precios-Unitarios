#ifndef COSTOSDIRECTOS_H
#define COSTOSDIRECTOS_H

#include <QDialog>
#include "cdpreliminares.h"
#include "cdfinales.h"
#include "cdmanodeobra.h"

/*******************************************************************
 * DEFINICION DE COSTOS BASE DE MATERIALES
 *******************************************************************/
//@AGLUTINANTES
#define CAL_HIDRATADA           0       //Mortero Blanco
#define MORTERO_GRIS            0
#define CEMENTO_NORMAL          0
#define CEMENTO_RR              0
#define CEMENTO_BLANCO          0
#define YESO_ENLUCIDOS          0
#define TEXTUCO                 0


//@AGREGADOS
#define ARENA_MINA              0
#define AGUA_CONSTRUCCION       0
#define GRAVA_MINA              0
#define POLVO_MARMOL_00_0       0
#define PIEDRA_BRAZA            0
#define PIEDRA_BOLA             0
#define TEZONTLE                0

//@ACEROS
#define ALAMBRON_1_4                    0
#define ALAMBRE_RECOCIDO_18             0
#define ACERO_NORMAL_3_8_A_1_1_2        0
#define ACERO_ALTA_R_5_16_A_3_8         0
#define ACERO_ALTA_R_1_2_A_1_1_2        0
#define CLAVO_2_1_2_Y_3_1_2             0
#define CLAVO_4                         0
#define REJILLA_ELECTROSOLDADA_10_10    0
#define REJILLA_ELECTROSOLDADA_12_12    0
#define ARMEX_10_10                     0
#define ARMEX_10_16                     0
#define ARMEX_10_20                     0

//@RENTA DE EQUIPO MAYOR
#define CAMION_VOLTEO               0
#define RETROEXCAVADORA             0
#define MOTOCONFORMADORA            0
#define APLANADORA                  0
#define ASFALTADORA                 0

//@RENTA DE EQUIPO MENOR
#define REVOLVEDORA_1_2SACO_4HP         0
#define REVOLVEDORA_1SACO_8HP           0
#define REVOLVEDORA_2SACO_11HP          0

//@HERRAMIENTA
#define CUNAS_1_1_2                 0
#define MARROS_8LB                  0
#define PICOS                       0
#define PALAS                       0
#define CARRETILLA                  0
#define DIENTES_CORTADORA           0
#define BOTES_ALCOHOLEROS_18LTS     0
#define CORTADORA_3_4               0
#define DOBLADORA_3_4               0

//@COMBUSTIBLES Y LUBRICANTES
#define GASOLINA_REGULAR            0
#define DIESEL                      0

//@MADERA DE CIMBRA
#define DUELA_1_1_2_X_2             0
#define DUELA_1_X_4                 0
#define BARROTE_2_X_4               0
#define POLIN_4_X_4                 0
#define TABLON_2_X_12               0
#define VIGA_4_X_8                  0
#define CHAFLANES_1                 0
#define TRIPLAY_CIMBRA_16MM         0
#define ASERRIN                     0

//@MUROS


//@DRENAJES
#define TUBO_PVC_10D_80CM           0

//@PISOS NATURALES
#define PISO_NATURAL_BAJO           0
#define PISO_NATURAL_MEDIO          0
#define PISO_NATURAL_ALTO           0


//@PISOS ARTIFICIALES
#define PISO_ARTIFICIAL_BAJO           0
#define PISO_ARTIFICIAL_MEDIO          0
#define PISO_ARTIFICIAL_ALTO           0

//@RECUBRIMIENTOS NATURALES
#define MARMOL_TRAVERTINO           0
#define MARMOL_BLANCO_DURANGO       0
#define MARMOL_ONIX                 0
#define MARMOL_NEGRO_MONTERREY      0
#define MARMOL_TEPEACA              0
#define MARMOL_PENUELA              0

//@RECUBRIMIENTOS ARTIFICIALES
#define RECUBRIMIENTO_ART_BAJO      0
#define RECUBRIMIENTO_ART_MEDIO     0
#define RECUBRIMIENTO_ART_ALTO      0

//@VARIOS
#define LADRILLO_MANO_BARRO         0
#define CARTON_ASFALTICO            0
#define LAMINA_022                  0

namespace Ui {
class CostosDirectos;
}

class CostosDirectos : public QDialog
{
    Q_OBJECT

public:
    explicit CostosDirectos(QWidget *parent = nullptr);
    ~CostosDirectos();

private slots:
    void on_pushButton_preliminares_clicked();

    void on_pushButton_Finales_clicked();

    void on_pushButton_ManoDeObra_clicked();

private:
    Ui::CostosDirectos *ui;
    CDPreliminares *cDPreliminares;
    CDFinales *cDFinales;
    CDManoDeObra *cDManoDeObra;
};

#endif // COSTOSDIRECTOS_H
