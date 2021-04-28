#include "wall.h"

Wall::Wall(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

Wall::~Wall()
{

}

QRectF Wall::boundingRect() const
{
    return QRectF(0, 0, 50, 50);   /// Ограничиваем область, в которой лежит треугольник
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        //QImage texture_image(":/walls/65c32776dff4d7c630adec9a030c7666");
       // QBrush texture_brush(Qt::TexturePattern);
       // painter->drawImage(QRectF(0, 0, 50, 50), texture_image);
        painter->drawRect(0, 0, 50, 50);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}
