#include "tank2.h"

Tank2::Tank2(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
    angle = 0;     // Задаём угол поворота графического объекта
    setRotation(angle);     // Устанавилваем угол поворота графического объекта
}

Tank2::~Tank2()
{

}

QRectF Tank2::boundingRect() const
{
    return QRectF(-20, -20, 40, 50);   /// Ограничиваем область, в которой лежит треугольник
}

QPainterPath Tank2::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void Tank2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
        /// Помещаем координаты точек в полигональную модель
        polygon << QPoint(15, 15) << QPoint(0, 25) << QPoint(-15, 15) << QPoint(-15, -15) << QPoint(15, -15);
        painter->setBrush(Qt::yellow);     /// Устанавливаем кисть, которой будем отрисовывать объект
        painter->drawPolygon(polygon); /// Рисуем треугольник по полигональной модели

        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Tank2::slotGameTimer()
{
    /* Поочерёдно выполняем проверку на нажатие клавиш
     * с помощью функции асинхронного получения состояния клавиш,
     * которая предоставляется WinAPI
     * */
    if(GetAsyncKeyState('A')){
        angle -= 10;        // Задаём поворот на 10 градусов влево
        setRotation(angle); // Поворачиваем объект
        //setPos(mapToParent(-5, 0));
        if(!(this->scene()->collidingItems(this).isEmpty())){
            angle -= 10;        // Задаём поворот на 10 градусов вправо
            setRotation(angle); // Поворачиваем объект
        }
    }
    if(GetAsyncKeyState('D')){
        angle += 10;        // Задаём поворот на 10 градусов вправо
        setRotation(angle); // Поворачиваем объект
        //setPos(mapToParent(5, 0));
                /* Проверяем на столкновение,
                 * если столкновение произошло,
                 * то возвращаем героя обратно в исходную точку
                 * */
                if(!scene()->collidingItems(this).isEmpty()){
                    angle -= 10;        // Задаём поворот на 10 градусов вправо
                    setRotation(angle); // Поворачиваем объект
                }
    }
    if(GetAsyncKeyState('W')){
        setPos(mapToParent(0, 5));     /* Продвигаем объект на 5 пискселей вперёд
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
                    setPos(mapToParent(0, -5));
        }
    }
    if(GetAsyncKeyState('S')){
        setPos(mapToParent(0, -5));      /* Продвигаем объект на 5 пискселей назад
                                         * перетранслировав их в координатную систему
                                         * графической сцены
                                         * */
        if(!scene()->collidingItems(this).isEmpty()){
              setPos(mapToParent(0, 5));
        }
    }

    /* Проверка выхода за границы поля
     * Если объект выходит за заданные границы, то возвращаем его назад
     * */
    if(this->x() - 10 < -690){
        this->setX(-689);       // слева
    }
    if(this->x() + 10 > 690){
        this->setX(689);        // справа
    }

    if(this->y() - 10 < -690){
        this->setY(-689);       // сверху
    }
    if(this->y() + 10 > 690){
        this->setY(689);        // снизу
    }
}
