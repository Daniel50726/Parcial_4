#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1121,750);
    scene->addRect(scene->sceneRect());

    //Llamamos al objeto normal (Mov parabolico)

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(obj_norm()));
    timer->start(1000);

    //Llamamos al objeto especial (Caida libre)

    QTimer * time = new QTimer();
    connect(time,SIGNAL(timeout()),this, SLOT(obj_esp()));
    time->start(1000);

    //Llamamos a los obstaculos
    QTimer * tim = new QTimer();
    connect(tim,SIGNAL(timeout()),this, SLOT(colision()));
    tim->start(5000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::colision()
{
    if(ayuda==1){
        scene->removeItem(rebote);
        delete rebote;
    }

    posx= 49+rand()% (50-900);
    posy= 399+rand()% (400-500);
    rebote = new Obstaculos();
    rebote->setPos(posx,posy);
    scene->addItem(rebote);
    ayuda=1;
}

void MainWindow::obj_norm()
{
    tipo= rand()%2;
    posx= 49+rand()% (50-900);
    posy= rand()%300;
    normal = new Tiro_para(tipo,posx,posy,30,-45);
    scene->addItem(normal);

}

void MainWindow::obj_esp()
{
    posx= 49+rand()% (50-900);
    especial = new Caida_libre(posx);
    scene->addItem(especial);
}

