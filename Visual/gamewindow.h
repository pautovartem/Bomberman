#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "GameGround.h"

#include <QWidget>

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;

    GameGround *gameGround;
};

#endif // GAMEWINDOW_H
