#ifndef ACEROS_H
#define ACEROS_H

#include <QDialog>

namespace Ui {
class Aceros;
}

class Aceros : public QDialog
{
    Q_OBJECT

public:
    explicit Aceros(QWidget *parent = nullptr);
    ~Aceros();
    void writeTable(QString concepto, QStringList unidad, QStringList material);

private slots:
    void on_pushButton_agregar_clicked();

    void on_pushButton_regresar_clicked();

private:
    Ui::Aceros *ui;

    QString concepto_ = "Acero de refuerzo";
    QStringList unidad_ = {"rollos","kg","piezas"};
    QStringList material_ = {"de rejilla electrosoldada", "de varilla 3/8", "de alambrón 1/4"};
    QString tipoArmadoPisos_ = "";  //Configuration selected on interface
    QString tipoArmadoTrabes_ = "";
    QString tipoArmadoCastillos_ = "";
    QString tipoArmadoCadenas_ = "";
    QString tipoArmadoDalas_ = "";
    QString tipoArmadoLosas_ = "";
    QString tipoArmadoZapatas_ = "";
    float cantidadRejillaElectroPisos_ = 0;      //Amount of rod and wire rod required in kg
    float cantidadArmexCastillos_ = 0;           //Amount of Armex for castles
    float* cantidadVarillaAlambronTrabes_ = nullptr;
    float* cantidadVarillaAlambronCastillos_ = nullptr;
    float* cantidadVarillaAlambronCadenas_ = nullptr;
    float* cantidadVarillaAlambronDalas_ = nullptr;
    float* cantidadVarillaAlambronLosas_ = nullptr;
    float* cantidadVarillaAlambronZapatas_ = nullptr;
    float puVarillaAlambron_[2] = {0,0};                 //Unit prices of rod and wire rod
    float puArmex10x10_ = 0;
    float puArmex10x16_ = 0;
    float puArmex10x20_ = 0;
    float puRejillaElectro10x10_ = 0;
    float puRejillaElectro12x12_ = 0;
    float mPisos_ = 0;              //Lineal meters
    float mTrabes_ = 0;
    float mCastillos_ = 0;
    float mCadenas_ = 0;
    float mDalas_ = 0;
    float mLosas_ = 0;
    float mZapatas_ = 0;
    float percWaste_ = 0;                            //Percentage of waste of rod and wire rod
    QStringList tipoDeEstructura_ = {"para Pisos", "para Trabes", "para Castillos", "para Cadenas",
                                     "para Dalas", "para Losas", "para Zapatas"}; //Use of rod and wire rod

    float* calculaCantidadVarillaAlambron(float m, float percWaste, QString tipoDeArmado);
    float calculaCantidadArmex(float m, float percWaste);
    float calculaCantidadRejillaElectro(float m2, float percWaste);
};

#endif // ACEROS_H
