#ifndef CARPINTERIA_H
#define CARPINTERIA_H

#include <QDialog>

namespace Ui {
class Carpinteria;
}

class Carpinteria : public QDialog
{
    Q_OBJECT

public:
    explicit Carpinteria(QWidget *parent = nullptr);
    ~Carpinteria();

private:
    Ui::Carpinteria *ui;
};

#endif // CARPINTERIA_H
