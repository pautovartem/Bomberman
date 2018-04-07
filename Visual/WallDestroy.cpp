#include "WallDestroy.h"

#include <QPainter>

WallDestroy::WallDestroy(QObject *parent) : Wall(parent)
{
    currentTextureX = 0;

    texture->load(":/wall/models/walls/stone_destroy_32px.png");

    textureDestroy = new QPixmap;
    textureDestroy->load(":/wall/models/walls/stone_destroy_sprite_32.png");
    textureDestroyWidth = 192;
    textureDestroyCount = 6;

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &WallDestroy::onAnimationTimer);
}

WallDestroy::~WallDestroy()
{
    disconnect(this);

    delete animationTimer;
}

void WallDestroy::onAnimationTimer()
{
    addCurrentTextureX();
    update();
}

void WallDestroy::addCurrentTextureX()
{
    currentTextureX += textureDestroyWidth;
    if(currentTextureX >= textureDestroyWidth * textureDestroyCount)
        currentTextureX = 0;
}

void WallDestroy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(- sizeCell.width / 2, - sizeCell.height / 2, *texture, currentTextureX, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
