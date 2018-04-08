#ifndef BOMBERMANHERO_H
#define BOMBERMANHERO_H

#include "GameItem.h"

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
        this->source = p_source;
        this->countElement = p_countElement;
        this->widthElement = p_widthElement;
        this->heightElement = p_heightElement;
    }

    QString source;
    int countElement;

    int widthElement;
    int heightElement;
};

class BombermanHero : public GameItem
{
    Q_OBJECT
public:
    explicit BombermanHero(QObject *parent = nullptr);
    ~BombermanHero();

    void keyPressEvent(QKeyEvent *event);               // Handler key press event
    void keyReleaseEvent(QKeyEvent *event);             // Handler key release event

    Direction getDirection() const;                     // Get current direction
    void setDirection(const Direction &value);          // Set current direction

    void addCurrentTextureX();                          // Change current texture

signals:

private slots:
    void onMotionTimer();                               // Movement timer handler
    void onAnimationTimer();                            // Animation timer handler

private:
    struct
    {
        int width;
        int height;
    } sizeCell;                                         // Size sell for bomberman

    int speedMotion;                                    // Movement speed

    QPixmap *texture;                                   // Texture for the current view
    int currentTextureX;                                // Current position texture
    TextureInfo *currentTextureInfo;                    // Information about current texture

    QTimer *motionTimer;                                // Timer to process keystrokes
    QTimer *animationTimer;                                  // Timer for animations

    QMap<int, bool> keyPressMap;                        // Map keys pressed
    QMap<Direction, TextureInfo*> texturesMap;          // Textures
    Direction direction;                                // Current direction

    // QGraphicsItem interface
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOMBERMANHERO_H
