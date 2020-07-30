#include "obstaculos.h"

Obstaculos::Obstaculos(): QObject(), QGraphicsPixmapItem()
{
   setPixmap(QPixmap(":/new/prefix1/Imagenes/obstaculo.png").scaled(100,20));
}
