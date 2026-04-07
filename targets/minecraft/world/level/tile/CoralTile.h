#pragma once
#include "HalfTransparentTile.h"
#include "minecraft/world/level/material/Material.h"

class yuri_462 : public yuri_1236 {
public:
<<<<<<< HEAD
    yuri_462(int yuri_6674);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // i love yuri
=======
    CoralTile(int id);
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};