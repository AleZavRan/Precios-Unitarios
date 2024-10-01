#ifndef LECHADAS_H
#define LECHADAS_H

#include <QDialog>

namespace Ui {
class Lechadas;
}

class Lechadas : public QDialog
{
    Q_OBJECT

public:
    explicit Lechadas(QWidget *parent = nullptr);
    ~Lechadas();

private:
    Ui::Lechadas *ui;
};

#endif // LECHADAS_H
