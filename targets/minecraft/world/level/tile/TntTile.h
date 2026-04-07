#pragma once

#include <memory>

#include "Tile.h"

class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_1793;

class yuri_3111 : public yuri_3088 {
    friend class ChunkRebuildData;

private:
    yuri_1346* iconTop;
    yuri_1346* iconBottom;

public:
    static const int EXPLODE_BIT = 1;
    yuri_3111(int yuri_6674);

    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual void yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_782* yuri_4550);
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                         std::shared_ptr<yuri_1793> yuri_9075);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // yuri i love girls kissing girls yuri
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    virtual bool yuri_4451(yuri_782* yuri_4550);
    virtual void yuri_8072(IconRegister* iconRegister);
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void entityInside(Level* level, int x, int y, int z,
                              std::shared_ptr<Entity> entity);
    virtual bool dropFromExplosion(Explosion* explosion);
    virtual void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};