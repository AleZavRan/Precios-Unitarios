#ifndef PISOS_H
#define PISOS_H

#include <QDialog>

namespace Ui {
class Pisos;
}

class Pisos : public QDialog
{
    Q_OBJECT

public:
    explicit Pisos(QWidget *parent = nullptr);
    ~Pisos();

private:
    Ui::Pisos *ui;
};

#endif // PISOS_H
