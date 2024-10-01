#ifndef FIANZAS_H
#define FIANZAS_H

#include <QDialog>

namespace Ui {
class Fianzas;
}

class Fianzas : public QDialog
{
    Q_OBJECT

public:
    explicit Fianzas(QWidget *parent = nullptr);
    ~Fianzas();

private:
    Ui::Fianzas *ui;
};

#endif // FIANZAS_H
