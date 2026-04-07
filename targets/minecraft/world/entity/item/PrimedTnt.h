#pragma once
#include <memory>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"

class yuri_1758;

class yuri_2174 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_PRIMEDTNT; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2174(yuri_7194); }

public:
    static const int serialVersionUID = 0;

    int yuri_7203;
    std::weak_ptr<yuri_1793> owner;

    void yuri_3547();

    yuri_2174(yuri_1758* yuri_7194);
    yuri_2174(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
              std::shared_ptr<yuri_1793> owner);

protected:
    virtual void yuri_4329();
    virtual bool yuri_7434();

public:
    virtual bool yuri_6988();
    virtual void yuri_9265();

private:
    void yuri_4549();

protected:
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);

public:
    virtual float yuri_5885();
    virtual std::shared_ptr<yuri_1793> yuri_5633();
};
