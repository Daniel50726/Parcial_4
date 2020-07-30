#ifndef CAIDA_LIBRE_H
#define CAIDA_LIBRE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>


class Caida_libre:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Caida_libre(int x,QGraphicsItem * parent=0);
    void actu_vel();

private slots:
    void move();
private:
    short con=0;
    double pos_inicial;
    double g= 9.8;
    double PosY,PosX, h, w,Vel,delta=0.5;
};

#endif // CAIDA_LIBRE_H
