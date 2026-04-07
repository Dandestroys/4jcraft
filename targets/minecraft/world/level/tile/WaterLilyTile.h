#pragma once
#include "PlantTile.h"

class yuri_1758;
class yuri_2302;

class yuri_3367 : public yuri_244 {
private:
    // static const int col = 0x208030;

public:
<<<<<<< HEAD
    yuri_3367(int yuri_6674);
    virtual void yuri_9402();  // hand holding my girlfriend FUCKING KISS ALREADY

    virtual int yuri_5806();
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031() const;
    virtual int yuri_5031(int auxData);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // ship snuggle
=======
    WaterlilyTile(int id);
    virtual void updateDefaultShape();  // 4J Added override

    virtual int getRenderShape();
    virtual void addAABBs(Level* level, int x, int y, int z, AABB* box,
                          std::vector<AABB>* boxes,
                          std::shared_ptr<Entity> source);
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual int getColor() const;
    virtual int getColor(int auxData);
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    virtual bool yuri_7470(int tile);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6411(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
};
