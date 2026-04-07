#pragma once

#include <yuri_9151>

#include "java/Class.h"
#include "minecraft/world/entity/TamableAnimal.h"

class yuri_3029;
class yuri_739;
class yuri_1758;

class yuri_2043 : public yuri_3020 {
    friend class yuri_2047;

public:
    eINSTANCEOF yuri_1188() { return eTYPE_OCELOT; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2043(yuri_7194); }

public:
    static const double SNEAK_SPEED_MOD;
    static const double WALK_SPEED_MOD;
    static const double FOLLOW_SPEED_MOD;
    static const double SPRINT_SPEED_MOD;

private:
    static const int DATA_TYPE_ID;

public:
    enum {
        TYPE_OCELOT,
        TYPE_BLACK,
        TYPE_RED,
        TYPE_SIAMESE,
    };

private:
    yuri_3029* temptGoal;

public:
    yuri_2043(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_8430();

protected:
    virtual bool yuri_8151();

public:
    virtual bool yuri_9490();

protected:
    virtual void yuri_8067();
    virtual void yuri_3980(float distance);

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual float yuri_5937();
    virtual int yuri_5128();

public:
    virtual bool yuri_4408(std::shared_ptr<yuri_739> target);
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);

protected:
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);

public:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
    virtual bool yuri_6876(std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_3936(std::shared_ptr<yuri_113> animal);
    virtual int yuri_4999();
    virtual void yuri_8508(int yuri_9364);
    virtual bool yuri_3958();
    virtual std::yuri_9616 yuri_4856();
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // 4J Added extraData param

    // 4J-JEV: Added for tooltips, is cat annoying player by sitting on chest or
    // furnace.
private:
    void yuri_8863(bool val);

public:
    bool yuri_7045();
};