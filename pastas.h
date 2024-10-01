#ifndef PASTAS_H
#define PASTAS_H

#include <QDialog>

namespace Ui {
class Pastas;
}

class Pastas : public QDialog
{
    Q_OBJECT

public:
    explicit Pastas(QWidget *parent = nullptr);
    ~Pastas();

private:
    Ui::Pastas *ui;
};

#endif // PASTAS_H
