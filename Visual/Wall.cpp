#include "Wall.h"

#include <QPainter>
#include <QDebug>

Wall::Wall(QObject *parent) : GameItem(parent)
{
    sizeCell.width = 32;
    sizeCell.height = 32;

    texture->load(":/wall/models/walls/stone_no_destroy_32px.png");
}

Wall::~Wall()
{
    disconnect(this);
}

QRectF Wall::boundingRect() const
{
    return QRectF(0, 0, sizeCell.width, sizeCell.height);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *texture, 0, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


int Wall::type() const
{
    return WallType;
}
