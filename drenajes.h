#ifndef DRENAJES_H
#define DRENAJES_H

#include <QDialog>

namespace Ui {
class Drenajes;
}

class Drenajes : public QDialog
{
    Q_OBJECT

public:
    explicit Drenajes(QWidget *parent = nullptr);
    ~Drenajes();

private:
    Ui::Drenajes *ui;
};

#endif // DRENAJES_H
