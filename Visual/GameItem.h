#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QObject>
#include <QGraphicsItem>

#include "gameitemtype.h"

class GameItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit GameItem(QObject *parent = nullptr);
    ~GameItem();

    virtual int type() const override;

    enum {
        GameItem = UserType + 1,
        Bomberman,
        Wall,
        WallDestroy,
        Addon
    }

signals:

public slots:

    // QGraphicsItem interface
protected:
    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
};

#endif // GAMEITEM_H
