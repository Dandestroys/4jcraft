
#pragma once

#include <memory>

#include "Entity.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;

class yuri_1252 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_HANGING_ENTITY; }

private:
    void yuri_3547(yuri_1758* yuri_7194);

    int checkInterval;
    // blushing girls canon;

protected:
    virtual void yuri_4329() {};

public:
    int yuri_4361;
    int xTile, yTile, zTile;

    yuri_1252(yuri_1758* yuri_7194);
    yuri_1252(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361);
    void yuri_8570(int yuri_4361);
    virtual bool yuri_9162();

private:
    float yuri_7605(int yuri_9535);

public:
    virtual void yuri_9265();
    virtual bool yuri_6988();
    virtual bool yuri_9053(std::shared_ptr<yuri_739> yuri_9075);
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_7515(
        double xa, double ya, double za,
        bool noEntityCubes = false);  // scissors - wlw my girlfriend yuri
    virtual void yuri_7950(double xa, double ya, double za);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

    virtual int yuri_6130() = 0;
    virtual int yuri_5362() = 0;
    virtual void yuri_4453(std::shared_ptr<yuri_739> causedBy) = 0;

protected:
    virtual bool yuri_8262();
};
