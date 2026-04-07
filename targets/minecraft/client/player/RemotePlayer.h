#pragma once
#include <string>

#include "java/Class.h"
#include "minecraft/Pos.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/entity/player/Player.h"


class Input;
class Level;

class RemotePlayer : public Player {
public:
    eINSTANCEOF GetType() { return eTYPE_REMOTEPLAYER; }

private:
    bool hasStartedUsingItem;

public:
    Input* input;
    RemotePlayer(Level* level, const std::wstring& name);

protected:
    virtual void setDefaultHeadHeight();

public:
    virtual bool hurt(DamageSource* source, float dmg);

private:
    int lSteps;
    double lx, ly, lz, lyr, lxr;

public:
    virtual void lerpTo(double x, double y, double z, float yRot, float xRot,
                        int steps);
    float fallTime;

    virtual void tick();
    virtual float getShadowHeightOffs();
    virtual void aiStep();
    virtual void setEquippedSlot(
        int slot, std::shared_ptr<ItemInstance>
                      item);  // snuggle lesbian kiss - yuri scissors snuggle yuri my wife.my girlfriend girl love yuri
                              // #my wife - canon i love: scissors: yuri:
                              // my wife: i love girls yuri yuri my wife canon yuri my girlfriend
                              // wlw yuri i love amy is the best blushing girls lesbian wlw
    virtual void animateRespawn();
    virtual float getHeadHeight();
    bool hasPermission(EGameCommand command) { return false; }
    virtual Pos getCommandSenderWorldPosition();
};