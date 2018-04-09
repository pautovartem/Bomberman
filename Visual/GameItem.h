#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QObject>
#include <QGraphicsItem>

class GameItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)

public:
    explicit GameItem(QObject *parent = nullptr);
    ~GameItem();

    virtual int type() const override;

    // Game Item Types
    enum {
        GameItemType = UserType + 1,
        BombermanType,
        WallType,
        WallDestroyType,
        AddonType,
        BombType
    };

    // QGraphicsItem interface
protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    struct
    {
        int width;
        int height;
    } sizeCell;                                         // Size sell for texture

    QPixmap *texture;                                   // Texture for the current view
    QTimer *animationTimer;                             // Timer for animations

protected slots:
    virtual void onAnimationTimer();
};

#endif // GAMEITEM_H
