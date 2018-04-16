#include "WallDestroy.h"

#include <QPainter>
#include <QDebug>

WallDestroy::WallDestroy(QObject *parent) : Wall(parent)
{
    currentDestroyTextureX = 0;
    texture->load(":/wall/models/walls/stone_destroy_32px.png");

    textureDestroySource = ":/wall/models/walls/stone_destroy_sprite_32.png";
    textureDestroyWidth = sizeCell.width;
    textureDestroyCount = 6;

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &WallDestroy::onAnimationTimer);
    animationTimer->setInterval(500 / textureDestroyCount);

    returnType = WallDestroyType;
}

WallDestroy::~WallDestroy()
{
    disconnect(this);

    delete animationTimer;
}

void WallDestroy::destroyWall()
{
    texture->load(textureDestroySource);
    currentDestroyTextureX = 0;

    returnType = GameItemType;

    animationTimer->start();
}

void WallDestroy::onAnimationTimer()
{
    addCurrentTextureX();
    update();
}

void WallDestroy::addCurrentTextureX()
{
    currentDestroyTextureX += 32;

    // Destroy wall after end sprite
    if(currentDestroyTextureX >= textureDestroyWidth * textureDestroyCount)
        this->deleteLater();
}

void WallDestroy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0, 0, *texture, currentDestroyTextureX, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}


int WallDestroy::type() const
{
    return returnType;
}
