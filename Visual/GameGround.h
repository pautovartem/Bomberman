#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include "BombermanHero.h"
#include "Wall.h"

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
    Wall *wall;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // GAMEGROUND_H
