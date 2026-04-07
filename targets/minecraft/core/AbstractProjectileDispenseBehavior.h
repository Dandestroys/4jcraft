#pragma once
#include <memory>

#include "DefaultDispenseItemBehavior.h"

class Projectile;
class yuri_2155;
class yuri_1758;

class AbstractProjectileDispenseBehavior : public yuri_578 {
public:
    virtual std::shared_ptr<yuri_1693> yuri_4539(
        BlockSource* yuri_9075, std::shared_ptr<yuri_1693> dispensed,
        eOUTCOME& outcome);

protected:
    virtual void yuri_7833(BlockSource* yuri_9075, eOUTCOME outcome);
    virtual float yuri_6075();
    virtual float yuri_5748();
    virtual std::shared_ptr<Projectile> yuri_5758(yuri_1758* world,
                                                      yuri_2155* yuri_7874) = 0;
};