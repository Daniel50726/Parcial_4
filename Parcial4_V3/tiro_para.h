#ifndef TIRO_PARA_H
#define TIRO_PARA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>

class Tiro_para:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double pos_inicial;
    double g= -9.8;
    double delta =0.1;
    double posy,posx, ang=50, vel, vel_x=30, vel_y=30;
    int r,con=0,tipo1;
public:
    Tiro_para(int tipo,double x, double y, double v, double a,QGraphicsItem * parent=0);

    void ActualizarVelocidad();


    double getPosy() const;
    void setPosy(double value);

    double getPosx() const;
    void setPosx(double value);

private slots:
    void ActualizarPosicion();
};

#endif // TIRO_PARA_H
