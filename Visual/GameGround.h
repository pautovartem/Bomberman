#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <QObject>
#include <QGraphicsScene>

class GameGround : public QGraphicsScene
{
public:
    explicit GameGround(QObject *parent = nullptr);
    ~GameGround();

signals:

public slots:
};

#endif // GAMEGROUND_H
