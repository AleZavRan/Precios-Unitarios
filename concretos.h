#ifndef CONCRETOS_H
#define CONCRETOS_H

#include <QDialog>

namespace Ui {
class Concretos;
}

class Concretos : public QDialog
{
    Q_OBJECT

public:
    explicit Concretos(QWidget *parent = nullptr);
    ~Concretos();

private:
    Ui::Concretos *ui;
};

#endif // CONCRETOS_H
