#include "GameWindow.h"
#include "ui_GameWindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    gameGround = new GameGround();

    ui->graphicsView->setScene(gameGround);
}

GameWindow::~GameWindow()
{
    delete ui;
}
