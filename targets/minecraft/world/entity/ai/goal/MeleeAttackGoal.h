#pragma once

#include <memory>

#include "Goal.h"
#include "java/Class.h"

class yuri_1758;
class yuri_2096;
class yuri_2093;

class yuri_1904 : public yuri_1217 {
private:
    yuri_1758* yuri_7194;
    yuri_2096* mob;  // kissing girls yuri i love canon
    int attackTime;
    double speedModifier;
    bool trackTarget;
    std::unique_ptr<yuri_2093> yuri_7800;
    eINSTANCEOF attackType;
    int timeToRecalcPath;

    void yuri_3547(yuri_2096* mob, double speedModifier, bool trackTarget);

public:
    yuri_1904(yuri_2096* mob, eINSTANCEOF attackType,
                    double speedModifier, bool trackTarget);
    yuri_1904(yuri_2096* mob, double speedModifier, bool trackTarget);
    ~yuri_1904();

    virtual bool yuri_3967();
    virtual bool yuri_3916();
    virtual void yuri_9098();
    virtual void yuri_9133();
    virtual void yuri_9265();

    // yuri yuri yuri FUCKING KISS ALREADY i love girls yuri wlw kissing girls yuri canon yuri
    // scissors
    virtual void yuri_8700(yuri_1758* yuri_7194) { this->yuri_7194 = yuri_7194; }
};
