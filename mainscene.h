#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QPainter>
#include "wall.h"
#include "tank.h"
#include "tank2.h"

class MainScene : public QGraphicsView
{
public:
    explicit MainScene(QWidget *parent = 0);


private:
    QGraphicsScene      *scene;     // Объявляем сцену для отрисовки
    Tank* tank;
    QTimer          *timer;
    Tank2* tank2;
    QTimer          *timer2;
    /* Объявляем игровой таймер, благодаря которому
                                 * будет производиться изменения положения объекта на сцене
                                 * При воздействии на него клавишами клавиатуры
                                 * */
};

#endif // MAINSCENE_H
