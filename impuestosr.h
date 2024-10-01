#ifndef IMPUESTOSR_H
#define IMPUESTOSR_H

#include <QDialog>

namespace Ui {
class ImpuestosR;
}

class ImpuestosR : public QDialog
{
    Q_OBJECT

public:
    explicit ImpuestosR(QWidget *parent = nullptr);
    ~ImpuestosR();

private:
    Ui::ImpuestosR *ui;
};

#endif // IMPUESTOSR_H
