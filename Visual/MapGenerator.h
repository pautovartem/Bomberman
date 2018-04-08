#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "GameItem.h"
#include "WallDestroy.h"

#include <QGraphicsScene>
#include <QVector>

class MapGenerator
{
public:
    explicit MapGenerator();
    ~MapGenerator();

    void setParent(QObject *value);
    void setListWallNoDestroy(QVector<Wall *> *value);
    void setListWallDestroy(QVector<WallDestroy *> *value);

    bool generateDefault(int colCount, int rowCount);                   // Default generate map
    bool generateWallDefault();                                         // Default generate wall not destroy
    bool generateWallD(int percent);                                    // Generate wall destroy
//    bool generateAddon(int minCount, int maxCount);

    bool toScene(QGraphicsScene *scene);                                // Convert map to scene

private:
    // Types of map element
    enum MapType {
        NoneType = 0,
        RespawnType,
        WallType,
        WallDestroyType,
    };

    QVector<QVector<MapType> > mapType;                                 // map of element for generate
    QVector<WallDestroy *> *listWallDestroy;                            // Link to list wall destroy
    QVector<Wall *> *listWallNoDestroy;                                 // Link to list wall no destroy
//    QVector< GameItem > *listAddons;

    QObject *parent;                                                    // Parent for create objects

    int rowCount;                                                       // Count rows of map
    int colCount;                                                       // Count cols of map

    bool mapIsGenerated;
};

#endif // MAPGENERATOR_H
