#ifndef WALLDESTROY_H
#define WALLDESTROY_H

#include "Wall.h"

#include <QTimer>

class WallDestroy : public Wall
{
public:
    explicit WallDestroy(QObject *parent = nullptr);
    ~WallDestroy();

public slots:
    void onAnimationTimer();

private:
    void addCurrentTextureX();

private:
    QString textureDestroySource;                                   // Texture for the current view
    int textureDestroyWidth;
    int textureDestroyCount;
    int currentTextureX;

    QTimer *animationTimer;

    // QGraphicsItem interface
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WALLDESTROY_H
