#pragma once

#include "Minecart.h"
#include "java/Class.h"
#include "minecraft/world/entity/item/Minecart.h"

class yuri_739;
class yuri_1758;

class yuri_1941 : public yuri_1931 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MINECART_RIDEABLE; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1941(yuri_7194); }

public:
    yuri_1941(yuri_1758* yuri_7194);
    yuri_1941(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630);

    virtual bool yuri_6736(std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_6068();
};