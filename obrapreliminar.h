#ifndef OBRAPRELIMINAR_H
#define OBRAPRELIMINAR_H

#include <QDialog>

namespace Ui {
class ObraPreliminar;
}

class ObraPreliminar : public QDialog
{
    Q_OBJECT

public:
    explicit ObraPreliminar(QWidget *parent = nullptr);
    ~ObraPreliminar();

private:
    Ui::ObraPreliminar *ui;
};

#endif // OBRAPRELIMINAR_H
