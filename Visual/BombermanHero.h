#ifndef BOMBERMANHERO_H
#define BOMBERMANHERO_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>

enum Direction {
    Up,
    Down,
    Right,
    Left,
    Destroy
};

struct TextureInfo {
    TextureInfo(QString p_source, int p_countElement, int p_widthElement, int p_heightElement)
    {
        source = p_source;
        countElement = p_countElement;
        widthElement = p_widthElement;
        heightElement = p_heightElement;
    }

    QString source;
    int countElement;

    int widthElement;
    int heightElement;
};

class BombermanHero : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit BombermanHero(QObject *parent = nullptr);
    ~BombermanHero();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

    Direction getDirection() const;
    void setDirection(const Direction &value);

    int addCurrentTextureX();

signals:

private slots:
    void onMotionTimer();
    void onMoveTimer();

private:
    struct
    {
        int width;
        int height;
    } sizeCell;                                         // Size sell for bomberman

    int speedMotion;

    QPixmap *texture;
    int currentTextureX;
    TextureInfo *currentTextureInfo;
    QTimer *motionTimer;                                // Timer to process keystrokes
    QTimer *moveTimer;
    QMap<int, bool> keyPressMap;
    QMap<Direction, TextureInfo*> texturesMap;
    Direction direction;


    // QGraphicsItem interface
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOMBERMANHERO_H
