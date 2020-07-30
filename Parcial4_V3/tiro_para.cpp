#include "tiro_para.h"
#include "mainwindow.h"

extern MainWindow * game;

Tiro_para::Tiro_para(int tipo,double x, double y, double v, double a,QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    tipo1=tipo;
    posx=x;
    posy=y;
    vel=v;
    ang=a;
    r=10;

    setPixmap(QPixmap(":/new/prefix1/Imagenes/Ball.png").scaled(20,20));

    QTimer * timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this, SLOT(ActualizarPosicion()));

    timer->start(50);

}

void Tiro_para::ActualizarVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
    vel= sqrt((vel_x*vel_x) + (vel_y*vel_y));
}

double Tiro_para::getPosx() const
{
    return posx;
}

void Tiro_para::setPosx(double value)
{
    posx = value;
}

void Tiro_para::ActualizarPosicion()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; i++){
        if(typeid(*(colliding_items[i])) == typeid (Obstaculos)){
            vel*=-1;
        }
    }

    if(con==0){
        pos_inicial=posy;
        con=1;
    }

    ActualizarVelocidad();


    //Direccion: (Derecha)
    if(tipo1==1){
        setPosx(getPosx()+vel_x*delta);
    }
    //Direccion: (Izquierda)
    if(tipo1==0){
        setPosx(getPosx()-vel_x*delta);
    }


    setPosy(getPosy()+vel_y*delta-(0.5*g*delta*delta));
    setPos(getPosx(),getPosy());

//    if(getPosy()>pos_inicial+40){

//        delete this;
//    }
}

double Tiro_para::getPosy() const
{
    return posy;
}

void Tiro_para::setPosy(double value)
{
    posy = value;
}
