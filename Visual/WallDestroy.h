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
    int type() const override;

private:
    QString textureDestroySource;                                   // Destroy wall texture source
    int textureDestroyWidth;                                        // Destroy wall texture width
    int textureDestroyCount;                                        // Destroy wall texture count elements

    int currentDestroyTextureX;                                     // Current X destroy texture

    int returnType = WallDestroyType;                               // Type for return

    void addCurrentTextureX();                                      // Iteration current X destroy texture

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private slots:
    void onAnimationTimer() override;
};

#endif // WALLDESTROY_H
