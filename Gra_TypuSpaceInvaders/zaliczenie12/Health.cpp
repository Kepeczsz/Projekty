#include "Health.h"
#include <QFont>
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){

    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    if(health >0)
    {
        health--;
    }
    setPlainText(QString("Health: ") + QString::number(health));
    if ( health == 0 )
        emit dead();

}

int Health::getHealth(){
    return health;
}
