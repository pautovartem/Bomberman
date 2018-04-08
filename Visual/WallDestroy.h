#ifndef WALLDESTROY_H
#define WALLDESTROY_H

#include "Wall.h"

#include <QTimer>

class WallDestroy : public Wall
{
public:
    explicit WallDestroy(QObject *parent = nullptr);
    ~WallDestroy();

    void destroyWall();

public slots:
    void onAnimationTimer();                                        // Handler animation timer

private:
    void addCurrentTextureX();                                      // Iteration current X destroy texture

private:
    QString textureDestroySource;                                   // Destroy wall texture source
    int textureDestroyWidth;                                        // Destroy wall texture width
    int textureDestroyCount;                                        // Destroy wall texture count elements

    int currentDestroyTextureX;                                     // Current X destroy texture
    int currentDestroyTextureIndex;                                 // Current index destroy texture

    QTimer *animationTimer;                                         // Animation timer

    // QGraphicsItem interface
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // WALLDESTROY_H
