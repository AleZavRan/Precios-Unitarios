#ifndef CDMANODEOBRA_H
#define CDMANODEOBRA_H

#include <QDialog>

/**************************************************
* Salarios Mínimos 2024
****************************************************/

#define SM_OFICIAL_DE_ALBANILERIA       287.17
#define SM_CARPINTERO                   282.44
#define SM_YESERO                       268.02
#define SM_EBANISTA                     286.51
#define SM_ELECTRICISTA                 281.44
#define SM_ENCARGADO_BODEGA             262.13
#define SM_HERRERO                      277.80
#define SM_PINTOR                       275.93
#define SM_PLOMERO                      276.42
#define SM_VELADOR                      257.88
#define CALCULA_PRIMA(SM)               ((SM)*(12)*(0.25))
#define PRIMA_PRC                       0.82
#define CALCULA_AGUINALDO(SM)           ((SM)*(15))         //REVISAR (SUBIRA A 30 DIAS)
#define AGUINALDO_PRC                   4.11                //Tomando en cuenta 15 días

namespace Ui {
class CDManoDeObra;
}

class CDManoDeObra : public QDialog
{
    Q_OBJECT

public:
    explicit CDManoDeObra(QWidget *parent = nullptr);
    ~CDManoDeObra();
    void setSalarioDiarioBase(float sdb);
    void setDiasNoTrabajados(float dnt);
    void setRendimientoPromedioDiario(float rpd);
    void setFactorZona(float fz);
    void setFactorHerramientaMenor(float fhm);
    void setFactorMaestro(float fm);
    float getCostoUnitarioDelTrabajo();
    float getSalarioDiarioTotal();
    float getFactorSalarioReal();
    float getPeriodoTrabajadoReal();

private:
    Ui::CDManoDeObra *ui;
    float cut_ = 0;  //Costo unitario del trabajo
    float sdt_ = 0;  //Salario diario total
    float rpd_ = 1;  //Rendimiento promedio diario
    float fz_ = 1;   //Factor de zona
    float fhm_ = 1;  //Factor de herramienta menor
    float fm_ = 1;   //Factor de maestro
    float sdb_ = 0;  //Salario Diario Base
    float pre_ = 0;  //Prestaciones
    float fsr_ = 1;  //Factor de salario real
    float pct_ = 0;  //Periodo considerado total
    float ptr_ = 0;  //Periodo trabajado real
    float dnt_ = 0;  //Dias no trabajados
};

#endif // CDMANODEOBRA_H
