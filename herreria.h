#ifndef HERRERIA_H
#define HERRERIA_H

#include <QDialog>

namespace Ui {
class Herreria;
}

class Herreria : public QDialog
{
    Q_OBJECT

public:
    explicit Herreria(QWidget *parent = nullptr);
    ~Herreria();

private:
    Ui::Herreria *ui;
};

#endif // HERRERIA_H
