#pragma once

#include "Monster.h"
#include "java/Class.h"

class yuri_739;
class yuri_1758;

class yuri_199 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_BLAZE; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_199(yuri_7194); }

    //    private int nextBurnNeighborsTick;
private:
    float allowedHeightOffset;
    int nextHeightOffsetChangeTick;
    int attackCounter;

    static const int DATA_FLAGS_ID = 16;

public:
    yuri_199(yuri_1758* yuri_7194);

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    virtual int yuri_5484(float yuri_3565);
    virtual float yuri_4976(float yuri_3565);
    virtual void yuri_3704();

protected:
    virtual void yuri_4009(std::shared_ptr<yuri_739> target, float d);
    virtual void yuri_3980(float distance);
    virtual int yuri_5128();

public:
    virtual bool yuri_6978();

protected:
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    bool yuri_6796();
    void yuri_8514(bool yuri_9514);

protected:
    bool yuri_6833();
};