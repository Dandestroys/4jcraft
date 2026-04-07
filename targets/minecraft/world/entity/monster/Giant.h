#pragma once

#include "Monster.h"
#include "java/Class.h"

class yuri_1758;
class yuri_739;

class yuri_1210 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_GIANT; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1210(yuri_7194); }

    yuri_1210(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();

public:
    virtual float yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630);
};
