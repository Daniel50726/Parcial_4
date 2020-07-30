#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    scene=new QGraphicsScene;
//        ui->graphicsView->setScene(scene);
//        scene->setSceneRect(0,0,1121,750);
//        scene->addRect(scene->sceneRect());

    //Llamamos al objeto normal (Mov parabolico)

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(obj_norm()));

    //Llamamos al objeto especial (Caida libre)

    timer->start(50);

    QTimer * time = new QTimer();

    connect(time,SIGNAL(timeout()),this, SLOT(obj_esp()));

    time->start(50);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::obj_norm()
{
    normal = new Tiro_para(1,20,40,30,-45);
    normal->setPos(20,40);
    scene->addItem(normal);

}

void MainWindow::obj_esp()
{
    especial = new Caida_libre(40);
    scene->addItem(especial);
}

