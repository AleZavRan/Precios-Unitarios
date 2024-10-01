#ifndef CDFPRELIMINARES_H
#define CDFPRELIMINARES_H

#include <QDialog>

namespace Ui {
class CDFPreliminares;
}

class CDFPreliminares : public QDialog
{
    Q_OBJECT

public:
    explicit CDFPreliminares(QWidget *parent = nullptr);
    ~CDFPreliminares();

private:
    Ui::CDFPreliminares *ui;
};

#endif // CDFPRELIMINARES_H
