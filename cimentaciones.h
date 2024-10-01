#ifndef CIMENTACIONES_H
#define CIMENTACIONES_H

#include <QDialog>

namespace Ui {
class Cimentaciones;
}

class Cimentaciones : public QDialog
{
    Q_OBJECT

public:
    explicit Cimentaciones(QWidget *parent = nullptr);
    ~Cimentaciones();

private:
    Ui::Cimentaciones *ui;
};

#endif // CIMENTACIONES_H
