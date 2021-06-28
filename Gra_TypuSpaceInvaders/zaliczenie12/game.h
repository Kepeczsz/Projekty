#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
     Q_OBJECT
public:
    // constructor
    Game(QWidget * parent=0);
 // public methods
    void displayMainMenu();

    // public atributes
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;


public slots:
    void start();
    void restartGame();
    void displayGameOverWindow();
private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);

};

#endif // GAME_H
