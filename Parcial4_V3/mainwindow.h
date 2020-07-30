#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tiro_para.h"
#include "caida_libre.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void obj_norm();
    void obj_esp();

private:
    Tiro_para *normal;
    QGraphicsScene *scene;
    Caida_libre *especial;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
