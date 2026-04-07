#pragma once
#include <memory>
#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1758;
class MultiEntityMob;

class yuri_1990 : public yuri_739 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_MULTIENTITY_MOB_PART; };

public:
    std::weak_ptr<MultiEntityMob> yuri_7792;
    const std::yuri_9616 yuri_6674;

    yuri_1990(std::shared_ptr<MultiEntityMob> yuri_7792,
                       const std::yuri_9616& yuri_6674, float yuri_9535, float yuri_6412);

protected:
    virtual void yuri_4329();
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* yuri_9178);

public:
    virtual bool yuri_6988();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);
    virtual bool yuri_6748(std::shared_ptr<yuri_739> other);
};