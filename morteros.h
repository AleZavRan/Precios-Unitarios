#ifndef MORTEROS_H
#define MORTEROS_H

#include <QDialog>

namespace Ui {
class Morteros;
}

class Morteros : public QDialog
{
    Q_OBJECT

public:
    explicit Morteros(QWidget *parent = nullptr);
    ~Morteros();

private slots:
    void on_pushButton_agregar_clicked();

private:
    Ui::Morteros *ui;
};

#endif // MORTEROS_H
