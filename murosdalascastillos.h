#ifndef MUROSDALASCASTILLOS_H
#define MUROSDALASCASTILLOS_H

#include <QDialog>

namespace Ui {
class MurosDalasCastillos;
}

class MurosDalasCastillos : public QDialog
{
    Q_OBJECT

public:
    explicit MurosDalasCastillos(QWidget *parent = nullptr);
    ~MurosDalasCastillos();

private:
    Ui::MurosDalasCastillos *ui;
};

#endif // MUROSDALASCASTILLOS_H
