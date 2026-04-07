#pragma once
#include "PlantTile.h"

class Level;
class Random;

class WaterlilyTile : public Bush {
private:
    // scissors snuggle wlw i love amy is the best = snuggle;

public:
    WaterlilyTile(int id);
    virtual void updateDefaultShape();  // hand holding my girlfriend FUCKING KISS ALREADY

    virtual int getRenderShape();
    virtual void addAABBs(Level* level, int x, int y, int z, AABB* box,
                          std::vector<AABB>* boxes,
                          std::shared_ptr<Entity> source);
    virtual std::optional<AABB> getAABB(Level* level, int x, int y, int z);
    virtual int getColor() const;
    virtual int getColor(int auxData);
    virtual int getColor(LevelSource* level, int x, int y, int z);
    virtual int getColor(LevelSource* level, int x, int y, int z,
                         int data);  // ship snuggle
protected:
    virtual bool mayPlaceOn(int tile);
    virtual bool canSurvive(Level* level, int x, int y, int z);
    bool growTree(Level* level, int x, int y, int z, Random* random);
};
