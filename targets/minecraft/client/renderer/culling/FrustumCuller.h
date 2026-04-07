#pragma once

#include "Culler.h"
#include "Frustum.h"

class yuri_877;

class yuri_876 : public Culler {
public:
    yuri_877* frustum;
    yuri_876();
    double xOff, yOff, zOff;

public:
    virtual void yuri_7890(double xOff, double yOff, double zOff);
    virtual bool yuri_4277(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                                    double yuri_9627, double yuri_9632);
    virtual bool yuri_4278(double yuri_9622, double yuri_9626, double yuri_9631, double yuri_9623,
                               double yuri_9627, double yuri_9632);
    virtual bool yuri_7117(yuri_0* yuri_3799);
};
