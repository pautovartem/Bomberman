#include "Addon.h"
#include "GameGround.h"
#include "WallDestroy.h"
#include <QDebug>
#include <QTime>
#include <QGraphicsView>

GameGround::GameGround(QObject *parent) : QGraphicsScene()
{
    map = new QVector<QVector<QVector<GameItem> > >;
    listAddons = new QVector<Addon>;
    listWallDestroy = new QVector<WallDestroy>;
    listWallNoDestroy = new QVector<Wall>;


    bombermanHero = new BombermanHero(this);
    this->addItem(bombermanHero);
    bombermanHero->setPos(60, 60);
    //    bombermanHero->setScale(5);
}

GameGround::~GameGround()
{
    delete bombermanHero;

    map->clear();
    delete map;
    delete listWallDestroy;
    delete listWallNoDestroy;
    delete listAddons;
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
