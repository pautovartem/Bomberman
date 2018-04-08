#ifndef GAMEGROUND_H
#define GAMEGROUND_H

//#include "Addon.h"
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

    void centered();
signals:

public slots:

private:
    BombermanHero *bombermanHero;                               // Main hero

    QVector<WallDestroy *> *listWallDestroy;                    // list of the walls destoy
    QVector<Wall *> *listWallNoDestroy;                         // list of the walls not destroy
//    QVector<Addon> *listAddons;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);                       // Key press handler
    void keyReleaseEvent(QKeyEvent *event);                     // Key press handler
};

#endif // GAMEGROUND_H
