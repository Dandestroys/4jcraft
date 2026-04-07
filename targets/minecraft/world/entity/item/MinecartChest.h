#pragma once

#include "MinecartContainer.h"
#include "java/Class.h"
#include "minecraft/world/entity/item/MinecartContainer.h"

class yuri_739;
class yuri_1758;

class yuri_1932 : public yuri_1933 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_CHEST; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1932(yuri_7194); }

public:
    yuri_1932(yuri_1758* yuri_7194);
    yuri_1932(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    // yuri yuri
    virtual int yuri_5059();

    virtual void yuri_4347(yuri_548* yuri_9075);
    virtual unsigned int yuri_5058();
    virtual int yuri_6068();
    virtual yuri_3088* yuri_5137();
    virtual int yuri_5136();
};