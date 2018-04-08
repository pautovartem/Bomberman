//#include "Addon.h"
#include "GameGround.h"
#include "MapGenerator.h"
#include "WallDestroy.h"
#include <QDebug>
#include <QTime>
#include <QGraphicsView>

GameGround::GameGround(QObject *parent) : QGraphicsScene(parent)
{
    listWallDestroy = new QVector<WallDestroy *>;
    listWallNoDestroy = new QVector<Wall *>;

    this->setSceneRect(0, 0, 32 * 35, 32 * 35);

    // Generate map
    MapGenerator mapGenerator;
    mapGenerator.setParent(this);
    mapGenerator.setListWallDestroy(listWallDestroy);
    mapGenerator.setListWallNoDestroy(listWallNoDestroy);
    mapGenerator.generateDefault(35, 35);
    mapGenerator.toScene(this);

    // Generate hero
    bombermanHero = new BombermanHero(this);
    this->addItem(bombermanHero);
    bombermanHero->setPos(48, 48);
}

GameGround::~GameGround()
{
    delete bombermanHero;

    delete listWallDestroy;
    delete listWallNoDestroy;
    //    delete listAddons;
}

void GameGround::centered()
{
    views().at(0)->centerOn(bombermanHero);
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
