#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>

#include "OwnableEntity.h"
#include "minecraft/world/entity/animal/Animal.h"

class yuri_2828;
class yuri_1758;
class yuri_1793;

class yuri_3020 : public yuri_113, public OwnableEntity {
protected:
    static const int DATA_FLAGS_ID = 16;
    static const int DATA_OWNERUUID_ID = 17;

    yuri_2828* sitGoal;

public:
    yuri_3020(yuri_1758* yuri_7194);
    virtual ~yuri_3020();

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual void yuri_9088(bool success);

public:
    virtual void yuri_6469(yuri_9368 yuri_6674);
    virtual bool yuri_7080();
    virtual void yuri_8900(bool yuri_9514);
    virtual bool yuri_7044();
    virtual void yuri_8862(bool yuri_9514);
    virtual std::yuri_9616 yuri_5635();
    virtual void yuri_8759(const std::yuri_9616& yuri_7540);
    virtual std::shared_ptr<yuri_739> yuri_5633();
    virtual yuri_2828* yuri_5902();
    bool yuri_9549(std::shared_ptr<yuri_1793> target,
                       std::shared_ptr<yuri_1793> owner);
    Team* yuri_5998();
    bool yuri_6756(std::shared_ptr<yuri_1793> other);
};