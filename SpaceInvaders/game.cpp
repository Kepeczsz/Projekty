#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QApplication>
#include <QString>
#include <typeinfo>
#include <Button.h>
#include<Score.h>
#include <QGraphicsPixmapItem>


Game::Game(QWidget * parent)
{
    // create the scene

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
}
void Game::start()
{   //clear menu

    scene ->clear();
    // create the player
    setBackgroundBrush(QBrush((QImage(":/images/tlo.png"))));
    player = new Player();

    player->setPos(0,500); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    // initialize
    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);
    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

    connect(health,SIGNAL(dead()),this,SLOT(displayGameOverWindow()));



    timer->start(2000);


}

void Game::restartGame()
{
    scene->clear();
    start();
}
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}


void Game::displayGameOverWindow(){
    // disable all scene items

    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }




    // draw panel
    drawPanel(200,150,400,300,Qt::blue,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(300,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(300,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    QGraphicsTextItem* overText = new QGraphicsTextItem(QString("Niestety, Przegrales :("));
    QFont titleFont("Blackadder ITC",16);
    overText ->setFont(titleFont);
        overText->setPos(300,225);
        scene->addItem(overText);



}

void Game::displayMainMenu(){
    // create the title:
    setBackgroundBrush(QBrush((QImage(":/images/tlo.png"))));
    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("Podrobka SpaceInvaders"));
    QFont titleFont("Blackadder ITC",48);
    titleText->setFont(titleFont);
    int txPos = this ->width()/2 - titleText ->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene ->addItem(titleText);
    // create play button

    Button*playButton = new Button(QString("Play"));

    int bxPos = this ->width()/2 - playButton ->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene ->addItem(playButton);

    // create quitbutton

    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this ->width()/2 - quitButton ->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene ->addItem(quitButton);
}
