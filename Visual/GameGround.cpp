#include "GameGround.h"
#include <QDebug>
#include <QTime>
#include <QGraphicsView>

GameGround::GameGround(QObject *parent) : QGraphicsScene()
{
    bombermanHero = new BombermanHero(this);

    this->addItem(bombermanHero);
    bombermanHero->setPos(60, 60);
//    bombermanHero->setScale(5);

    wall = new Wall;
    addItem(wall);
    wall->setPos(0, 0);
}

GameGround::~GameGround()
{
    delete bombermanHero;
}


void GameGround::keyPressEvent(QKeyEvent *event)
{
    bombermanHero->keyPressEvent(event);
    QGraphicsScene::keyPressEvent(event);
}

void GameGround::keyReleaseEvent(QKeyEvent *event)
{
    bombermanHero->keyReleaseEvent(event);
    QGraphicsScene::keyReleaseEvent(event);
}
