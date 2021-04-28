#ifndef TANK2_H
#define TANK2_H
#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>
#include <QPainterPath>
#include <QGraphicsScene>

#include "windows.h"

class Tank2 : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Tank2(QObject *parent = 0);
    ~Tank2();

signals:

public slots:
    void slotGameTimer(); // Слот, который отвечает за обработку перемещения треугольника

protected:
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal angle;    // Угол поворота графического объекта

};
#endif // TANK2_H
