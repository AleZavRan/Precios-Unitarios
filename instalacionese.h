#ifndef INSTALACIONESE_H
#define INSTALACIONESE_H

#include <QDialog>

namespace Ui {
class InstalacionesE;
}

class InstalacionesE : public QDialog
{
    Q_OBJECT

public:
    explicit InstalacionesE(QWidget *parent = nullptr);
    ~InstalacionesE();

private:
    Ui::InstalacionesE *ui;
};

#endif // INSTALACIONESE_H
