#ifndef ENEMY1_H
#define ENEMY1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Enemy1: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy1(QGraphicsItem * parent=0);

public slots:
    void move();

};

#endif // ENEMY_H

