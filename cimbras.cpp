#include "cimbras.h"
#include "ui_cimbras.h"

Cimbras::Cimbras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cimbras)
{
    ui->setupUi(this);
    ui->comboBox_provedor->addItem("Prov 1");
    ui->comboBox_provedor->addItem("Prov 2");
    ui->comboBox_provedor->addItem("Prov 3");
    ui->comboBox_trabes->addItem("Tabla pino 3ra. 3/4x8");
    ui->comboBox_trabes->addItem("Tablon pino cepillado #2 2x10x8");
    ui->comboBox_castillos->addItem("Tabla pino 3ra. 3/4x8");
    ui->comboBox_castillos->addItem("Tablon pino cepillado #2 2x10x8");
    ui->comboBox_cadenas->addItem("Tabla pino 3ra. 3/4x8");
    ui->comboBox_cadenas->addItem("Tablon pino cepillado #2 2x10x8");
    ui->comboBox_dalas->addItem("Tabla pino 3ra. 3/4x8");
    ui->comboBox_dalas->addItem("Tablon pino cepillado #2 2x10x8");
    ui->comboBox_zapatas->addItem("");
    ui->comboBox_zapatas->addItem("");
    ui->comboBox_zapatas->addItem("");
    ui->checkBox_tarima->setChecked(true);
}

Cimbras::~Cimbras()
{
    delete ui;
}

void Cimbras::on_pushButton_agregar_clicked()
{
    //Assigning values captured from interface to variables
    mTrabes_ = ui->lineEdit_trabes->text().toFloat();       //Lineal meters captured
    mCastillos_ = ui->lineEdit_castillos->text().toFloat();
    mCadenas_ = ui->lineEdit_cadenas->text().toFloat();
    mDalas_ = ui->lineEdit_dalas->text().toFloat();
    m2Losas_ = ui->lineEdit_losas->text().toFloat();
    mZapatas_ = ui->lineEdit_zapatas->text().toFloat();

    //Assigning unit prices depending on the selected supplier
    if(ui->comboBox_provedor->currentData().toString() == "Prov 1"){

    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 2"){

    } else if(ui->comboBox_provedor->currentData().toString() == "Prov 3"){

    }

    //Getting the required amount of materials depending type of configuration

    //Writing the summary table
}


void Cimbras::on_pushButton_regresar_clicked()
{
    hide();

}

float* Cimbras::calculaCantidadCimbraLosas(float m2, float percWaste, bool tarima, bool tabla, bool tablon){

    float* cantidadTarimaTablaTablon = new float[3](); //Initializing values to 0
    //Quantifying depending  wood configuration selected (7 possible combinations)

    if(tarima && !tabla && !tablon){          //Sólo tarima

    } else if(!tarima && tabla && !tablon){   //Sólo tabla

    } else if(!tarima && !tabla && tablon){   //Sólo tablón

    } else if(tarima && tabla && !tablon){    //tarima y tabla

    } else if(tarima && !tabla && tablon){    //tarima y tablón

    } else if(!tarima && tabla && tablon){    //tabla y tablón

    } else if(tarima && tabla && tablon){     //Tarima, tabla y tablón

    } else{   //ERROR. No item selected

    }

    return cantidadTarimaTablaTablon;
}

void Cimbras::writeTable(QString concepto, QStringList unidad, QStringList material){

}
