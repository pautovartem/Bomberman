#include "Wall.h"

#include <QPainter>

Wall::Wall(QObject *parent) : QObject(parent), QGraphicsItem()
{
    sizeCell.width = 32;
    sizeCell.height = 32;

    texture = new QPixmap;
    texture->load(":/wall/models/walls/stone_no_destroy_32px.png");
}

Wall::~Wall()
{
    disconnect(this);

    delete texture;
}


QRectF Wall::boundingRect() const
{
    return QRectF(- sizeCell.width / 2, - sizeCell.height / 2, sizeCell.width, sizeCell.height);
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(- sizeCell.width / 2, - sizeCell.height / 2, *texture, 0, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
