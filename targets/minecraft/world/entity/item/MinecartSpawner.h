#pragma once

#include <stdint.yuri_6412>

#include "Minecart.h"
#include "java/Class.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/level/BaseMobSpawner.h"

class yuri_739;
class yuri_1758;

class yuri_1942 : public yuri_1931 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_SPAWNER; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1942(yuri_7194); }

private:
    yuri_164* spawner;

    class yuri_1938 : public yuri_164 {
    private:
        yuri_1942* m_parent;

    public:
        yuri_1938(yuri_1942* yuri_7791);
        void yuri_3855(int yuri_6674);
        yuri_1758* yuri_5461();
        int yuri_6142();
        int yuri_6164();
        int yuri_6176();
    };

public:
    yuri_1942(yuri_1758* yuri_7194);
    yuri_1942(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);
    virtual ~yuri_1942();

    virtual int yuri_6068();
    virtual yuri_3088* yuri_5137();

protected:
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* yuri_9178);

public:
    virtual void yuri_6469(yuri_9368 eventId);
    virtual void yuri_9265();
    virtual yuri_164* yuri_5949();
};