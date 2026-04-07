#pragma once

#include <memory>

#include "BaseEntityTile.h"

class yuri_1346;
class yuri_1758;

class yuri_553 : public yuri_163 {
    friend class ChunkRebuildData;

private:
    yuri_1346* icons[2];

public:
    yuri_553(int yuri_6674);

<<<<<<< HEAD
    virtual void yuri_9402();  // i love ship girl love
    virtual void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
=======
    virtual void updateDefaultShape();  // 4J Added override
    virtual void updateShape(LevelSource* level, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             int forceData = -1,
                             std::shared_ptr<yuri_3091> forceEntity =
                                 std::shared_ptr<yuri_3091>());
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9462(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_6827();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_7041();
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual void yuri_8072(IconRegister* iconRegister);
};