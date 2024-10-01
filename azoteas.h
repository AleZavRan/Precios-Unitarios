#ifndef AZOTEAS_H
#define AZOTEAS_H

#include <QDialog>

namespace Ui {
class Azoteas;
}

class Azoteas : public QDialog
{
    Q_OBJECT

public:
    explicit Azoteas(QWidget *parent = nullptr);
    ~Azoteas();

private:
    Ui::Azoteas *ui;
};

#endif // AZOTEAS_H
