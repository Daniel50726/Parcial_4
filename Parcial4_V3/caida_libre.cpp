#include "caida_libre.h"

Caida_libre::Caida_libre(int x,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=10;
    h=10;

    setPixmap(QPixmap(":/new/prefix1/Imagenes/Ball.png").scaled(w,h));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);

}

void Caida_libre::actu_vel()
{
   Vel=Vel-g*delta;
}

void Caida_libre::move()
{
    if(con==0){
        pos_inicial=PosY;
        con=2;
    }

    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();
}
