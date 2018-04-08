#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include "Addon.h"
#include "BombermanHero.h"
#include "Wall.h"
#include "WallDestroy.h"

#include <QObject>
#include <QGraphicsScene>

class GameGround : public QGraphicsScene
{
public:
    explicit GameGround(QObject *parent = nullptr);
    ~GameGround();

signals:

public slots:

private:
    BombermanHero *bombermanHero;

    QVector<QVector<QVector<GameItem> > > *map;
    QVector<WallDestroy> *listWallDestroy;
    QVector<Wall> *listWallNoDestroy;
    QVector<Addon> *listAddons;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEGROUND_H
