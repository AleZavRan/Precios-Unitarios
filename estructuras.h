#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include <QDialog>

namespace Ui {
class Estructuras;
}

class Estructuras : public QDialog
{
    Q_OBJECT

public:
    explicit Estructuras(QWidget *parent = nullptr);
    ~Estructuras();

private:
    Ui::Estructuras *ui;
};

#endif // ESTRUCTURAS_H
