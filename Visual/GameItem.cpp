#include "GameItem.h"

GameItem::GameItem(QObject *parent) : QObject(parent), QGraphicsItem()
{

}

GameItem::~GameItem()
{

}


int GameItem::type() const
{
    return GameItem;
}
