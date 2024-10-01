#ifndef UTILIDAD_H
#define UTILIDAD_H

#include <QDialog>

namespace Ui {
class Utilidad;
}

class Utilidad : public QDialog
{
    Q_OBJECT

public:
    explicit Utilidad(QWidget *parent = nullptr);
    ~Utilidad();

private:
    Ui::Utilidad *ui;
};

#endif // UTILIDAD_H
