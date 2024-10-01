#ifndef SUBCONTRATOS_H
#define SUBCONTRATOS_H

#include <QDialog>

namespace Ui {
class Subcontratos;
}

class Subcontratos : public QDialog
{
    Q_OBJECT

public:
    explicit Subcontratos(QWidget *parent = nullptr);
    ~Subcontratos();

private slots:
    void on_pushButton_canceleria_clicked();

    void on_pushButton_carpinteria_clicked();

    void on_pushButton_herreria_clicked();

    void on_pushButton_paisajismo_clicked();

    void on_pushButton_instalaionese_clicked();

private:
    Ui::Subcontratos *ui;
};

#endif // SUBCONTRATOS_H
