#pragma once

#include <memory>

#include "Entity.h"
#include "HangingEntity.h"
#include "java/Class.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1758;
class yuri_739;

class yuri_1690 : public yuri_1252 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ITEM_FRAME; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1690(yuri_7194); }

private:
    static const int DATA_ITEM = 2;
    static const int DATA_ROTATION = 3;

    float dropChance;

private:
    void yuri_3547();

public:
    yuri_1690(yuri_1758* yuri_7194);
    yuri_1690(yuri_1758* yuri_7194, int xTile, int yTile, int zTile, int yuri_4361);

protected:
    virtual void yuri_4329();

public:
    virtual int yuri_6130() { return 9; }
    virtual int yuri_5362() { return 9; }
    virtual bool yuri_9015(double distance);
    virtual void yuri_4453(std::shared_ptr<yuri_739> causedBy);

private:
    void yuri_8112(std::shared_ptr<yuri_1693> item);

public:
    std::shared_ptr<yuri_1693> yuri_5416();
    void yuri_8686(std::shared_ptr<yuri_1693> item);
    int yuri_5831();
    void yuri_8830(int rotation);

    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
};