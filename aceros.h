#ifndef ACEROS_H
#define ACEROS_H

#include <QDialog>

namespace Ui {
class Aceros;
}

class Aceros : public QDialog
{
    Q_OBJECT

public:
    explicit Aceros(QWidget *parent = nullptr);
    ~Aceros();

private:
    Ui::Aceros *ui;
};

#endif // ACEROS_H
