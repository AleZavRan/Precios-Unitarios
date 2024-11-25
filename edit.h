#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include "editcsvview.h"
#include <QListWidgetItem>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = nullptr);
    ~Edit();

private slots:


    void on_pushButton_open_clicked();

    void on_pushButton_edit_clicked();


    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::Edit *ui;
    EditCSVView *editCSVView;
    QString selection;


};

#endif // EDIT_H
