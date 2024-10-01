#ifndef COLOCACIONES_H
#define COLOCACIONES_H

#include <QDialog>

namespace Ui {
class Colocaciones;
}

class Colocaciones : public QDialog
{
    Q_OBJECT

public:
    explicit Colocaciones(QWidget *parent = nullptr);
    ~Colocaciones();

private:
    Ui::Colocaciones *ui;
};

#endif // COLOCACIONES_H
