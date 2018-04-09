#ifndef WALL_H
#define WALL_H

#include "GameItem.h"

class Wall : public GameItem
{
    Q_OBJECT
public:
    explicit Wall(QObject *parent = nullptr);
    ~Wall();

    virtual int type() const override;

    // QGraphicsItem interface
protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WALL_H
