#include "Bomb.h"

#include <QPainter>

Bomb::Bomb(QObject *parent) : GameItem(parent)
{
//    this->m_heroParent = heroParent;

    texture->load(":/explosion/models/bomb/spriteBomb.png");
    currentTextureX = 0;

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Bomb::onAnimationTimer);
    animationTimer->start(125);

    QTimer::singleShot(this->timeDestroy, this, &Bomb::onDestroyTimer);
}

Bomb::~Bomb()
{
    delete animationTimer;
}


QRectF Bomb::boundingRect() const
{
    return QRectF(- sizeCell.width / 2, - sizeCell.height / 2, sizeCell.width, sizeCell.height);
}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(- sizeCell.width / 2, - sizeCell.height / 2, *texture, currentTextureX, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

int Bomb::type() const
{
    return BombType;
}

void Bomb::onAnimationTimer()
{
    currentTextureX += sizeCell.width;
    if(currentTextureX >= sizeCell.width * 4)
        currentTextureX = 0;

    this->update();
}

void Bomb::onDestroyTimer()
{
    emit destroyedBomb(this);
    this->deleteLater();
}
