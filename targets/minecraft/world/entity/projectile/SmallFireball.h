#pragma once

#include <memory>

#include "Fireball.h"
#include "java/Class.h"

class yuri_1278;
class yuri_739;
class yuri_1758;
class yuri_1793;

class yuri_2847 : public yuri_822 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SMALL_FIREBALL; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2847(yuri_7194); }

public:
    yuri_2847(yuri_1758* yuri_7194);
    yuri_2847(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> mob, double xa,
                  double ya, double za);
    yuri_2847(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                  double ya, double za);

protected:
    virtual void yuri_7623(yuri_1278* res);

public:
    virtual bool yuri_6988();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
};