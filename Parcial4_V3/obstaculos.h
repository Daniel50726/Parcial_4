#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <math.h>
#include <QDebug>


class Obstaculos:public QObject, public QGraphicsPixmapItem
{
public:
    Obstaculos();
};

#endif // OBSTACULOS_H
