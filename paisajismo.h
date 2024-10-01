#ifndef PAISAJISMO_H
#define PAISAJISMO_H

#include <QDialog>

namespace Ui {
class Paisajismo;
}

class Paisajismo : public QDialog
{
    Q_OBJECT

public:
    explicit Paisajismo(QWidget *parent = nullptr);
    ~Paisajismo();

private:
    Ui::Paisajismo *ui;
};

#endif // PAISAJISMO_H
