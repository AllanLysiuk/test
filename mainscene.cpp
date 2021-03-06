#include "mainscene.h"
#include "creator_of_map.h"
MainScene::MainScene(QWidget *parent)
    : QGraphicsView(parent) {

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Отключим скроллбар по горизонтали
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Отключим скроллбар по вертикали
    this->setAlignment(Qt::AlignCenter);                        // Делаем привязку содержимого к центру
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    scene = new QGraphicsScene();   // Initialize the scene for rendering


    //QImage back_image(":/images/vova.jpg");
    //back_image = back_image.scaled(size());
    //QBrush back_brush(Qt::TexturePattern);
    //back_brush.setTextureImage(back_image);
    //scene->setBackgroundBrush(back_brush);

    scene->addLine(-700,-380, 700,-380, QPen(Qt::black));//верхняя граница
    scene->addLine(-700, 370, 700, 370, QPen(Qt::black));//нижняя граница
    scene->addLine(-700,-380,-700, 370, QPen(Qt::black));//левая
    scene->addLine( 700,-380,700,370, QPen(Qt::black));//правая

    printMap("D:\\Qt\\tanks\\map.txt",scene);

    tank = new Tank();
    tank2 = new Tank2();

    scene->addItem(tank);   /// Добавляем на сцену треугольник
    tank->setPos(-675,-340);      /// Устанавливаем треугольник в центр сцены
    scene->addItem(tank2);   /// Добавляем на сцену треугольник
    tank2->setPos(675,340);
    /* Инициализируем таймер и вызываем слот обработки сигнала таймера
     * у Треугольника 20 раз в секунду.
     * Управляя скоростью отсчётов, соответственно управляем скоростью
     * изменения состояния графической сцены
     * */
    timer = new QTimer();
    connect(timer, &QTimer::timeout, tank, &Tank::slotGameTimer);
    timer->start(1000 / 50);
    timer2 = new QTimer();
    connect(timer2, &QTimer::timeout, tank2, &Tank2::slotGameTimer);
    timer2->start(1000 / 50);
    this->setScene(scene);
}
