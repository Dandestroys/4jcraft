#pragma once
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/Pos.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/entity/player/Player.h"


class yuri_1607;
class yuri_1758;

class yuri_2373 : public yuri_2126 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_REMOTEPLAYER; }

private:
    bool hasStartedUsingItem;

public:
    yuri_1607* yuri_6724;
    yuri_2373(yuri_1758* yuri_7194, const std::yuri_9616& yuri_7540);

protected:
    virtual void yuri_8558();

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);

private:
    int lSteps;
    double lx, ly, lz, lyr, lxr;

public:
    virtual void yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                        int yuri_9129);
    float fallTime;

    virtual void yuri_9265();
    virtual float yuri_5885();
    virtual void yuri_3704();
    virtual void yuri_8595(
        int yuri_9061, std::shared_ptr<yuri_1693>
                      item);  // snuggle lesbian kiss - yuri scissors snuggle yuri my wife.my girlfriend girl love yuri
                              // #my wife - canon i love: scissors: yuri:
                              // my wife: i love girls yuri yuri my wife canon yuri my girlfriend
                              // wlw yuri i love amy is the best blushing girls lesbian wlw
    virtual void yuri_3718();
    virtual float yuri_5344();
    bool yuri_6621(EGameCommand command) { return false; }
    virtual yuri_2153 yuri_5040();
};