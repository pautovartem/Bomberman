#include "MapGenerator.h"
#include "Wall.h"

#include <QDebug>

MapGenerator::MapGenerator()
{
    mapIsGenerated = false;
}

MapGenerator::~MapGenerator()
{
    mapType.clear();
}

bool MapGenerator::generateDefault(int colCount, int rowCount)
{
    this->rowCount = rowCount;
    this->colCount = colCount;

    try {
        listWallDestroy->clear();
        listWallNoDestroy->clear();

        mapType.clear();
        mapType.resize(rowCount);

        for(int row = 0; row < rowCount; row++)
        {
            mapType[row].resize(colCount);

            for(int col = 0; col < colCount; col++)
                mapType[row][col] = MapType::NoneType;
        }

        mapType[1][1] = MapType::RespawnType;
        mapType[1][2] = MapType::RespawnType;
        mapType[2][1] = MapType::RespawnType;
    }
    catch(...)
    {
        return false;
    }

//    mapIsGenerated = generateWallDefault();
    mapIsGenerated = generateWallD(60);

    return mapIsGenerated;
}

bool MapGenerator::generateWallDefault()
{
    try {
        Wall *wall1;
        Wall *wall2;

        for(int col = 0; col < colCount; col++)
        {
            wall1 = new Wall(parent);
            wall2 = new Wall(parent);

            wall1->setPos(32 * col, 0);
            wall2->setPos(32 * col, (rowCount - 1) * 32);

            listWallNoDestroy->push_back(wall1);
            listWallNoDestroy->push_back(wall2);

            mapType[0][col] = MapType::WallType;
            mapType[rowCount - 1][col] = MapType::WallType;
        }

        for(int row = 1; row < rowCount; row++)
        {
            wall1 = new Wall(parent);
            wall2 = new Wall(parent);

            wall1->setPos(0, 32 * row);
            wall2->setPos((colCount - 1) * 32, 32 * row);

            listWallNoDestroy->push_back(wall1);
            listWallNoDestroy->push_back(wall2);

            mapType[row][0] = MapType::WallType;
            mapType[row][colCount - 1] = MapType::WallType;
        }

        for(int row = 2; row < rowCount; row += 2)
        {
            for(int col = 2; col < colCount; col += 2)
            {
                wall1 = new Wall(parent);
                wall1->setPos(32 * col, 32 * row);

                listWallNoDestroy->push_back(wall1);

                mapType[row][col] = MapType::WallType;
            }
        }

        return true;
    }
    catch(...)
    {
        return false;
    }
}

bool MapGenerator::generateWallD(int percent)
{
    WallDestroy *tmp;

    try
    {
        for(int row = 1; row < rowCount - 1; row++)
            for(int col = 1; col < colCount - 1; col++)
                if(mapType[row][col] == MapType::NoneType && rand() % 100 <= percent)
                {
                    tmp = new WallDestroy(parent);
                    tmp->setPos(32 * col, 32 * row);

                    listWallDestroy->push_back(tmp);

                    mapType[row][col] = MapType::WallDestroyType;
                }

        return true;
    }
    catch(...)
    {
        return false;
    }
}

bool MapGenerator::toScene(QGraphicsScene *scene)
{
    try
    {
        scene->clear();

        for(GameItem *item : *listWallNoDestroy)
            scene->addItem(item);

        for(GameItem *item : *listWallDestroy)
            scene->addItem(item);

        return true;
    }
    catch(...)
    {
        return false;
    }
}

void MapGenerator::setParent(QObject *value)
{
    parent = value;
}

void MapGenerator::setListWallNoDestroy(QVector<Wall *> *value)
{
    listWallNoDestroy = value;
}

void MapGenerator::setListWallDestroy(QVector<WallDestroy *> *value)
{
    listWallDestroy = value;
}
