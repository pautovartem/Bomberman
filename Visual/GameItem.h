#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QObject>
#include <QGraphicsItem>

class GameItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
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
        AddonType
    };

signals:

public slots:

    // QGraphicsItem interface
protected:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GAMEITEM_H
