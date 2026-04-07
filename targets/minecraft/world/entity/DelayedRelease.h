#pragma once

#include <memory>

#include "Entity.h"
#include "java/Class.h"
#include "minecraft/world/entity/Entity.h"

class yuri_548;
class yuri_1758;

class yuri_587 : public yuri_739 {
public:
    virtual eINSTANCEOF yuri_1188() { return eTYPE_DELAYEDRELEASE; }

private:
    std::shared_ptr<yuri_739> toRelease;
    int yuri_4331;

public:
    yuri_587(yuri_1758* yuri_7194, std::shared_ptr<yuri_739> toRelease, int yuri_4331);

protected:
    virtual bool yuri_7434();

public:
    virtual void yuri_9265();
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);

protected:
    virtual void yuri_4329();
    virtual void yuri_7989(yuri_409* yuri_9178);
    virtual void yuri_3582(yuri_409* yuri_9178);
};