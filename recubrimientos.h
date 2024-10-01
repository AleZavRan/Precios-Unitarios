#ifndef RECUBRIMIENTOS_H
#define RECUBRIMIENTOS_H

#include <QDialog>

namespace Ui {
class Recubrimientos;
}

class Recubrimientos : public QDialog
{
    Q_OBJECT

public:
    explicit Recubrimientos(QWidget *parent = nullptr);
    ~Recubrimientos();

private:
    Ui::Recubrimientos *ui;
};

#endif // RECUBRIMIENTOS_H
