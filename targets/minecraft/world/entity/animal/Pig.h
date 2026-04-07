#pragma once

#include "Animal.h"
#include "java/Class.h"

class yuri_2126;
class yuri_1780;
class yuri_451;
class yuri_739;
class yuri_1758;

class yuri_2110 : public yuri_113 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_PIG; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2110(yuri_7194); }

private:
    static const int DATA_SADDLE_ID = 16;
    yuri_451* controlGoal;

public:
    yuri_2110(yuri_1758* yuri_7194);

    virtual bool yuri_9490();

protected:
    virtual void yuri_8067();
    virtual void yuri_7567();

public:
    virtual bool yuri_3907();

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);

public:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    bool yuri_6633();
    void yuri_8831(bool yuri_9514);
    virtual void yuri_9264(const yuri_1780* lightningBolt);

protected:
    virtual void yuri_3980(float distance);

public:
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
    bool yuri_6876(std::shared_ptr<yuri_1693> itemInstance);
    yuri_451* yuri_5062();
};
