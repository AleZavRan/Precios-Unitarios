#ifndef CANCELERIA_H
#define CANCELERIA_H

#include <QDialog>

namespace Ui {
class Canceleria;
}

class Canceleria : public QDialog
{
    Q_OBJECT

public:
    explicit Canceleria(QWidget *parent = nullptr);
    ~Canceleria();

private:
    Ui::Canceleria *ui;
};

#endif // CANCELERIA_H
