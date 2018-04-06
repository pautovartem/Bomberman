#include "BombermanHero.h"

#include <QPainter>
#include <QDebug>
#include <windows.h>
#include <QKeyEvent>

BombermanHero::BombermanHero(QObject *parent) : QObject(parent), QGraphicsItem()
{
    sizeCell.width = 32;
    sizeCell.height = 32;

    speedMotion = 3;

    texturesMap[Direction::Up] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/up.png", 3, 32, 32);
    texturesMap[Direction::Down] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/down.png", 3, 32, 32);
    texturesMap[Direction::Left] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/left.png", 3, 32, 32);
    texturesMap[Direction::Right] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/right.png", 3, 32, 32);
    texturesMap[Direction::Destroy] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/destroy.png", 9, 32, 32);

    texture = new QPixmap;

    setDirection(Direction::Down);

    motionTimer = new QTimer(this);
    connect(motionTimer, &QTimer::timeout, this, &BombermanHero::onMotionTimer);
    motionTimer->start(15);

    moveTimer = new QTimer(this);
    connect(moveTimer, &QTimer::timeout, this, &BombermanHero::onMoveTimer);
    moveTimer->start(200);
}

BombermanHero::~BombermanHero()
{
    disconnect(this);

    delete motionTimer;
}

QRectF BombermanHero::boundingRect() const
{
    return QRectF(- sizeCell.width / 2, - sizeCell.height / 2, sizeCell.width, sizeCell.height);
}

void BombermanHero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(- sizeCell.width / 2, - sizeCell.height / 2, *texture, currentTextureX, 0, sizeCell.width, sizeCell.height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Direction BombermanHero::getDirection() const
{
    return direction;
}

void BombermanHero::setDirection(const Direction &value)
{
    if (direction == value)
        return;

    direction = value;
    currentTextureInfo = texturesMap[value];
    texture->load(currentTextureInfo->source);
    currentTextureX = 0;

    if(direction == Direction::Up)
    {

    }
    else if(direction == Direction::Down)
    {

    }
    else if(direction == Direction::Left)
    {

    }
    else if(direction == Direction::Right)
    {

    }
}

int BombermanHero::addCurrentTextureX()
{
    currentTextureX += currentTextureInfo->widthElement;
    if(currentTextureX >= currentTextureInfo->widthElement * currentTextureInfo->countElement)
        currentTextureX = 0;
}

void BombermanHero::onMotionTimer()
{
    if (keyPressmap.containts()){
    if(keyPressMap.contains(Qt::Key_W))
    {
        qDebug() << "UP";

        setDirection(Direction::Up);
        this->setY(this->y() - speedMotion);
    }

    if(keyPressMap.contains(Qt::Key_S))
    {
        qDebug() << "DOWN";

        setDirection(Direction::Down);
        this->setY(this->y() + speedMotion);
    }

    if(keyPressMap.contains(Qt::Key_A))
    {
        qDebug() << "LEFT";

        setDirection(Direction::Left);
        this->setX(this->x() - speedMotion);
    }

    if(keyPressMap.contains(Qt::Key_D))
    {
        qDebug() << "RIGHT";

        setDirection(Direction::Right);
        this->setX(this->x() + speedMotion);
    }
  }
}

void BombermanHero::onMoveTimer()
{
    addCurrentTextureX();
    update();
}

void BombermanHero::keyPressEvent(QKeyEvent *event)
{
    keyPressMap[event->key()] = true;
}

void BombermanHero::keyReleaseEvent(QKeyEvent *event)
{
    keyPressMap.remove(event->key());
}
