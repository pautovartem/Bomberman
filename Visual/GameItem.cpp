#include "GameItem.h"

GameItem::GameItem(QObject *parent) : QObject(parent), QGraphicsItem()
{
    sizeCell.height = 32;
    sizeCell.width = 32;

    texture = new QPixmap;
}

GameItem::~GameItem()
{
    delete texture;
}


int GameItem::type() const
{
    return GameItemType;
}

QRectF GameItem::boundingRect() const
{
    return QRectF(0, 0, 0, 0);
}

void GameItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void GameItem::onAnimationTimer()
{

}
