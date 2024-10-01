#ifndef IMPREVISTOS_H
#define IMPREVISTOS_H

#include <QDialog>

namespace Ui {
class Imprevistos;
}

class Imprevistos : public QDialog
{
    Q_OBJECT

public:
    explicit Imprevistos(QWidget *parent = nullptr);
    ~Imprevistos();

private:
    Ui::Imprevistos *ui;
};

#endif // IMPREVISTOS_H
