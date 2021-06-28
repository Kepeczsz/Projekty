#include "Player.h"
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include <game.h>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QList>
#include <enemy1.h>

extern Game * game;
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(collide()));
    setPixmap(QPixmap(":/images/samolot.png"));

    // start the timer
    timer->start(50);


}

void Player::keyPressEvent(QKeyEvent *event){

    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().y() +80 < 600)
        setPos(x(),y()+10);
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+102,y()+32);
        scene()->addItem(bullet);
    }

}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}


void Player::collide(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->health->decrease();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);


            // delete them from the heap to save memory
            delete colliding_items[i];


            // return (all code below refers to a non existint bullet)
            return;
        }
    }

}
