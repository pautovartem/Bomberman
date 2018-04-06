#include "GameWindow.h"
#include "ui_GameWindow.h"
#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    gameGround = new GameGround();

    ui->graphicsView->setScene(gameGround);
    ui->graphicsView->scale(5, 5);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

GameWindow::~GameWindow()
{
    delete gameGround;
    delete ui;
}
