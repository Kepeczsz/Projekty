#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "game.h"
extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    if(game->health->getHealth()>0)
    {
    int random_number = rand() % 500;
    setPos(700,random_number);

    // drew the rect

    setPixmap(QPixmap(":/images/kosmita.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
    }

}

void Enemy::move(){
    if(game->health->getHealth()>0)
    {
        // move enemy down
        setPos(x()-5,y());
    }


    // destroy enemy when it goes out of the screen

    if (pos().x() < -100){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }

}


