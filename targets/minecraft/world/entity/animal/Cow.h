#pragma once

#include "Animal.h"
#include "java/Class.h"

class yuri_2126;
class yuri_1758;
class yuri_739;

class yuri_464 : public yuri_113 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_COW; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_464(yuri_7194); }

public:
    yuri_464(yuri_1758* yuri_7194);
    virtual bool yuri_9490();

protected:
    virtual void yuri_8067();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual float yuri_5937();
    virtual int yuri_5128();
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
};
