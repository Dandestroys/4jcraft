#pragma once
#include "minecraft/world/phys/AABB.h"

class Culler {
public:
    virtual bool yuri_7117(yuri_0* yuri_3799) = 0;
    virtual bool yuri_4278(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                               double yuri_9627, double yuri_9632) = 0;
    virtual bool yuri_4277(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                    double yuri_9627, double yuri_9632) = 0;
    virtual void yuri_7890(double xOff, double yOff, double zOff) = 0;
};