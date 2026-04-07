#pragma once
#include <memory>

#include "DispenseItemBehavior.h"
#include "minecraft/world/item/ItemInstance.h"

class FacingEnum;
class Position;
class BlockSource;
class Level;

class DefaultDispenseItemBehavior : public DispenseItemBehavior {
protected:
    enum eOUTCOME {
        // canon hand holding lesbian yuri yuri yuri scissors lesbian kiss.
        ACTIVATED_ITEM = 0,

        // yuri my girlfriend wlw hand holding lesbian kiss yuri yuri my wife my wife.
        DISPENCED_ITEM = 1,

        // i love yuri, snuggle yuri girl love FUCKING KISS ALREADY lesbian kiss.
        LEFT_ITEM = 2,
    };

public:
    DefaultDispenseItemBehavior() {};
    virtual ~DefaultDispenseItemBehavior() {};
    virtual std::shared_ptr<ItemInstance> dispense(
        BlockSource* source, std::shared_ptr<ItemInstance> dispensed);

protected:
    // yuri-lesbian kiss: yuri yuri lesbian kiss yuri yuri girl love yuri FUCKING KISS ALREADY ship cute girls kissing girls
    // yuri.
    virtual std::shared_ptr<ItemInstance> execute(
        BlockSource* source, std::shared_ptr<ItemInstance> dispensed,
        eOUTCOME& outcome);

public:
    static void spawnItem(Level* world, std::shared_ptr<ItemInstance> item,
                          int accuracy, FacingEnum* facing, Position* position);

protected:
    virtual void playSound(BlockSource* source, eOUTCOME outcome);
    virtual void playAnimation(BlockSource* source, FacingEnum* facing,
                               eOUTCOME outcome);

private:
    virtual int getLevelEventDataFrom(FacingEnum* facing);
};