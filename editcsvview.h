#ifndef EDITCSVVIEW_H
#define EDITCSVVIEW_H

#include <QDialog>

namespace Ui {
class EditCSVView;
}

class EditCSVView : public QDialog
{
    Q_OBJECT

public:
    explicit EditCSVView(QWidget *parent = nullptr);
    ~EditCSVView();

private:
    Ui::EditCSVView *ui;
};

#endif // EDITCSVVIEW_H
