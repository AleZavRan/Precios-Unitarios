#ifndef FINANCIAMIENTO_H
#define FINANCIAMIENTO_H

#include <QDialog>

namespace Ui {
class Financiamiento;
}

class Financiamiento : public QDialog
{
    Q_OBJECT

public:
    explicit Financiamiento(QWidget *parent = nullptr);
    ~Financiamiento();

private:
    Ui::Financiamiento *ui;
};

#endif // FINANCIAMIENTO_H
