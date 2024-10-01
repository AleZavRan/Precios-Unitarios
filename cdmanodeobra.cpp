#include "cdmanodeobra.h"
#include "ui_cdmanodeobra.h"

CDManoDeObra::CDManoDeObra(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CDManoDeObra)
{
    ui->setupUi(this);
}

CDManoDeObra::~CDManoDeObra()
{
    delete ui;
}

void CDManoDeObra::setSalarioDiarioBase(float sdb){

    sdb_ = sdb;
}

void CDManoDeObra::setDiasNoTrabajados(float dnt){

    dnt_ = dnt;
}

void CDManoDeObra::setRendimientoPromedioDiario(float rpd){

    rpd_ = rpd;
}

void CDManoDeObra::setFactorHerramientaMenor(float fhm){

    fhm_ = fhm;
}

void CDManoDeObra::setFactorMaestro(float fm){

    fm_ = fm;
}

void CDManoDeObra::setFactorZona(float fz){

    fz_ = fz;
}

float CDManoDeObra::getSalarioDiarioTotal(){

    sdt_ = (sdb_ + pre_) * (fsr_);

    return sdt_;
}

float CDManoDeObra::getFactorSalarioReal(){

    fsr_ = (pct_)/(ptr_);

    return fsr_;
}

float CDManoDeObra::getPeriodoTrabajadoReal(){

    ptr_ = pct_ - dnt_;

    return ptr_;
}

float CDManoDeObra::getCostoUnitarioDelTrabajo(){

    cut_ = (sdt_/rpd_) * fz_ * fhm_ * fm_;

    return cut_;
}
