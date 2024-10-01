#ifndef CIMBRAS_H
#define CIMBRAS_H

#include <QDialog>

namespace Ui {
class Cimbras;
}

class Cimbras : public QDialog
{
    Q_OBJECT

public:
    explicit Cimbras(QWidget *parent = nullptr);
    ~Cimbras();

private:
    Ui::Cimbras *ui;
};

#endif // CIMBRAS_H
