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

    void keyPressEvent(QKeyEvent *event);               // Handler key press event
    void keyReleaseEvent(QKeyEvent *event);             // Handler key release event

    Direction getDirection() const;                     // Get current direction
    void setDirection(const Direction &value);          // Set current direction

    void addCurrentTextureX();                          // Change current texture

signals:

private slots:
    void onMotionTimer();                               // Movement timer handler
    void onMoveTimer();                                 // Animation timer handler

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
    QTimer *moveTimer;                                  // Timer for animations

    QMap<int, bool> keyPressMap;                        // Map keys pressed
    QMap<Direction, TextureInfo*> texturesMap;          // Textures
    Direction direction;                                // Current direction


    // QGraphicsItem interface
private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // BOMBERMANHERO_H
