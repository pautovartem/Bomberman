#ifndef BOMB_H
#define BOMB_H

#include <GameItem.h>

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

class Bomb : public GameItem
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);
    ~Bomb();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int type() const override;

signals:
    void destroyedBomb(Bomb *bomb);

private slots:
    void onAnimationTimer() override;
    void onDestroyTimer();

private:
//    BombermanHero *m_heroParent;
    int currentTextureX;                                // Current position texture
    const int timeDestroy = 3000;
};

#endif // BOMB_H
