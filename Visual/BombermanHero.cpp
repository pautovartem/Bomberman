#include "BombermanHero.h"
#include "WallDestroy.h"

#include <QPainter>
#include <QDebug>
#include <windows.h>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>

BombermanHero::BombermanHero(QObject *parent) : GameItem(parent)
{
    sizeCell.width = 32;
    sizeCell.height = 32;

    speedMotion = 4;

    texturesMap[Direction::Up] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/up.png", 3, 32, 32);
    texturesMap[Direction::Down] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/down.png", 3, 32, 32);
    texturesMap[Direction::Left] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/left.png", 3, 32, 32);
    texturesMap[Direction::Right] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/right.png", 3, 32, 32);
    texturesMap[Direction::Destroy] = new TextureInfo(":/hero/Bomberman/models/bomberman/blue/destroy.png", 9, 32, 32);

    setDirection(Direction::Down);

    motionTimer = new QTimer(this);
    connect(motionTimer, &QTimer::timeout, this, &BombermanHero::onMotionTimer);
    motionTimer->start(15);

    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &BombermanHero::onAnimationTimer);
    animationTimer->setInterval(200);

    bombs = new QVector<Bomb *>();
}

BombermanHero::~BombermanHero()
{
    disconnect(this);

    delete motionTimer;
    delete animationTimer;
    delete bombs;
}

QRectF BombermanHero::boundingRect() const
{
    return QRectF(- sizeCell.width / 2, - sizeCell.height / 2, sizeCell.width, sizeCell.height);
}

void BombermanHero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(- sizeCell.width / 2, - sizeCell.height / 2, *texture, currentTextureX, 0, sizeCell.width, sizeCell.height);
//    painter->drawRect(- sizeCell.width / 2, - sizeCell.height / 2, 32, 32);
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
}

void BombermanHero::addCurrentTextureX()
{
    currentTextureX += currentTextureInfo->widthElement;
    if(currentTextureX >= currentTextureInfo->widthElement * currentTextureInfo->countElement)
        currentTextureX = 0;
}

bool BombermanHero::collide()
{
    auto collideList = this->scene()->collidingItems(this);

    if(lastBomb)
    {
        bool find = false;
        for(auto item : collideList)
        {
            if(item == lastBomb)
                find = true;
        }

        if(!find)
            lastBomb = nullptr;
    }

    for(auto item : collideList)
    {
        if(item->type() == WallType)
            return true;

        if(item->type() == WallDestroyType)
            return true;
//            qgraphicsitem_cast<WallDestroy *> (item)->destroyWall();

        if(item->type() == BombType)
            if(item != lastBomb)
                return true;
    }

    return false;
}

bool BombermanHero::stayAtLastBomb()
{
    auto collideList = this->scene()->collidingItems(this);

    bool find = false;

    if(lastBomb)
    {
        for(auto item : collideList)
        {
            if(item == lastBomb)
                find = true;
        }

        if(!find)
            lastBomb = nullptr;
    }

    return find;
}

void BombermanHero::onMotionTimer()
{
    if(keyPressMap.contains(Qt::Key_W) || keyPressMap.contains(Qt::Key_S) || keyPressMap.contains(Qt::Key_A) || keyPressMap.contains(Qt::Key_D))
    {
        // Start animation timer if contains W, S, A, D
        if(!animationTimer->isActive())
            animationTimer->start();

        // Check key and set current direction and
        if(keyPressMap.contains(Qt::Key_W))
        {
            setDirection(Direction::Up);
            this->setY(this->y() - speedMotion);

            // Check collide after change position
            if(collide())
                this->setY(this->y() + speedMotion);
        }

        if(keyPressMap.contains(Qt::Key_S))
        {
            setDirection(Direction::Down);
            this->setY(this->y() + speedMotion);

            if(collide())
                this->setY(this->y() - speedMotion);
        }

        if(keyPressMap.contains(Qt::Key_A))
        {
            setDirection(Direction::Left);
            this->setX(this->x() - speedMotion);

            if(collide())
                this->setX(this->x() + speedMotion);
        }

        if(keyPressMap.contains(Qt::Key_D))
        {
            setDirection(Direction::Right);
            this->setX(this->x() + speedMotion);

            if(collide())
                this->setX(this->x() - speedMotion);
        }

        scene()->views().at(0)->centerOn(this);
    }
    else
    {
        // Stop animation timer
        animationTimer->stop();
    }

    // Set the bomb
    if(keyPressMap.contains(Qt::Key_Space))
    {
        qDebug() << "Enter to space handler";

        if(stayAtLastBomb())
            return;

        qDebug() << "Skip collide in space handler";

        Bomb *currentBomb = new Bomb(this->scene());
        currentBomb->setPos(this->pos());

        this->scene()->addItem(currentBomb);
        bombs->push_back(currentBomb);
        lastBomb = currentBomb;

        qDebug() << "Bomb is created:" << currentBomb->pos();
    }
}

void BombermanHero::onAnimationTimer()
{
    addCurrentTextureX();
    update();
}

void BombermanHero::onBombDestroy(Bomb *bomb)
{
    bombs->removeOne(bomb);
}

void BombermanHero::keyPressEvent(QKeyEvent *event)
{
    keyPressMap[event->key()] = true;
}

void BombermanHero::keyReleaseEvent(QKeyEvent *event)
{
    keyPressMap.remove(event->key());
}

int BombermanHero::type() const
{
    return BombermanType;
}
