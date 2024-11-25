#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "costos.h"
#include "edit.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_Costos_clicked();

    void on_actionNew_triggered();

    void on_actionEdit_triggered();

    void on_actionDelete_triggered();

private:
    Ui::MainWindow *ui;
    Costos *costos;
    Edit *edit;

};
#endif // MAINWINDOW_H
