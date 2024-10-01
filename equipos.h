#ifndef EQUIPOS_H
#define EQUIPOS_H

#include <QDialog>

namespace Ui {
class Equipos;
}

class Equipos : public QDialog
{
    Q_OBJECT

public:
    explicit Equipos(QWidget *parent = nullptr);
    ~Equipos();

private:
    Ui::Equipos *ui;
};

#endif // EQUIPOS_H
