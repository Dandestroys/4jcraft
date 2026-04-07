#pragma once

#include <memory>

#include "Fireball.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_1733 : public yuri_822 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_LARGE_FIREBALL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_1733(yuri_7194); }

public:
    int explosionPower;

    yuri_1733(yuri_1758* yuri_7194);
    yuri_1733(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                  double ya, double za);
    yuri_1733(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
                  double ya, double za);

protected:
    void yuri_7623(yuri_1278* res);

public:
    void yuri_3582(yuri_409* yuri_9178);
    void yuri_7989(yuri_409* yuri_9178);
};