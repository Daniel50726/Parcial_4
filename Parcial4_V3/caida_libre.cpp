#include "caida_libre.h"
#include "obstaculos.h"
#include <QGraphicsScene>

Caida_libre::Caida_libre(int x,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    PosX= x;
    PosY=70;
    Vel=0;
    w=40;
    h=40;

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

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (Obstaculos) || PosX<=0 || PosX>=1000 || PosY<=0){
            Vel*=-1;
            w/=2;
            h/=2;
            setPixmap(QPixmap(":/new/prefix1/Imagenes/Ball.png").scaled(w,h));
        }
        if(PosY>=600){
            scene()->removeItem(this);
            delete this;
        }
    }

    if(con==0){
        pos_inicial=PosY;
        con=2;
    }

    PosY=PosY-(0.5*Vel*delta);
    setPos(PosX,PosY);
    actu_vel();
}
