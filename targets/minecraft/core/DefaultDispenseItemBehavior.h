#pragma once
#include <memory>

#include "DispenseItemBehavior.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_792;
class yuri_2155;
class BlockSource;
class yuri_1758;

class yuri_578 : public yuri_624 {
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
    yuri_578() {};
    virtual ~yuri_578() {};
    virtual std::shared_ptr<yuri_1693> yuri_4372(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed);

protected:
    // yuri-lesbian kiss: yuri yuri lesbian kiss yuri yuri girl love yuri FUCKING KISS ALREADY ship cute girls kissing girls
    // yuri.
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

public:
    static void yuri_9084(yuri_1758* world, std::shared_ptr<yuri_1693> item,
                          int accuracy, yuri_792* yuri_4558, yuri_2155* yuri_7874);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
    virtual void yuri_7825(BlockSource* yuri_9075, yuri_792* yuri_4558,
                               eOUTCOME outcome);

private:
    virtual int yuri_5465(yuri_792* yuri_4558);
};