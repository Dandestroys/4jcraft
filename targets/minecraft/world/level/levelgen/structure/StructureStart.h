#pragma once
#include <list>

#include "StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"

class yuri_2981;
class yuri_220;
class yuri_409;
class yuri_1758;
class yuri_2302;

class yuri_2982 {
public:
    std::list<yuri_2981*> pieces;

protected:
    yuri_220* boundingBox;

private:
    int chunkX, chunkZ;

public:
    yuri_2982();
    yuri_2982(int yuri_9621, int yuri_9630);
    virtual ~yuri_2982();
    yuri_220* yuri_4971();
    std::list<yuri_2981*>* yuri_5693();
    void yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB);

protected:
    void yuri_3892();

public:
    virtual yuri_409* yuri_4257(int chunkX, int chunkZ);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178);
    virtual void yuri_7990(yuri_409* yuri_9178);

protected:
    void yuri_7517(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_7607);
    void yuri_7523(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int lowestAllowed,
                           int highestAllowed);

public:
    bool yuri_7106();
    int yuri_5012();
    int yuri_5013();

    virtual EStructureStart yuri_1188() = 0;
};
