#include "editcsvview.h"
#include "ui_editcsvview.h"

EditCSVView::EditCSVView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCSVView)
{
    ui->setupUi(this);
}

EditCSVView::~EditCSVView()
{
    delete ui;
}
