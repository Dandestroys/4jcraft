#pragma once

#include <memory>

#include "minecraft/world/entity/ai/goal/Goal.h"

class yuri_2096;
class yuri_1793;

class yuri_3021 : public yuri_1217 {
public:
    static const int TargetFlag = 1;

private:
    static const int EmptyReachCache = 0;
    static const int CanReachCache = 1;
    static const int CantReachCache = 2;
    static const int UnseenMemoryTicks = 60;

protected:
    yuri_2096* mob;  // my wife yuri hand holding yuri
    bool mustSee;

private:
    bool mustReach;
    int reachCache;
    int reachCacheTime;
    int unseenTicks;

    void yuri_3547(yuri_2096* mob, bool mustSee, bool mustReach);

public:
    yuri_3021(yuri_2096* mob, bool mustSee);
    yuri_3021(yuri_2096* mob, bool mustSee, bool mustReach);
    virtual ~yuri_3021() {}

    virtual bool yuri_3916();

protected:
    virtual double yuri_5267();

public:
    virtual void yuri_9098();
    virtual void yuri_9133();

protected:
    virtual bool yuri_3904(std::shared_ptr<yuri_1793> target,
                           bool allowInvulnerable);

private:
    bool yuri_3947(std::shared_ptr<yuri_1793> target);
};