#pragma once

#include "Monster.h"
#include "java/Class.h"
#include "minecraft/world/entity/MobGroupData.h"
#include "minecraft/world/entity/MobType.h"

class yuri_739;
class yuri_1758;
class yuri_2302;

class yuri_2882 : public yuri_1966 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_SPIDER; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2882(yuri_7194); }

private:
    static const int DATA_FLAGS_ID = 16;

public:
    yuri_2882(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_9265();

protected:
    virtual void yuri_8067();
    virtual std::shared_ptr<yuri_739> yuri_4601();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);
    virtual void yuri_4009(std::shared_ptr<yuri_739> target, float d);
    virtual int yuri_5128();
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_7624();

    virtual void yuri_7435();
    virtual MobType yuri_5555();
    virtual bool yuri_3906(yuri_1954* newEffect);
    virtual bool yuri_6804();
    virtual void yuri_8521(bool yuri_9514);
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // 4J Added extraData param

private:
    static const float SPIDER_SPECIAL_EFFECT_CHANCE;

public:
    class yuri_2883 : public MobGroupData {
    public:
        int effectId;

        yuri_2883();
        void yuri_8803(yuri_2302* yuri_7981);
    };
};
