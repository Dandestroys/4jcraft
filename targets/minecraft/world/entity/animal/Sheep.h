#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Animal.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

class yuri_2302;
class yuri_680;
class yuri_469;
class yuri_739;
class yuri_1758;

class yuri_2775 : public yuri_113 {
private:
    class yuri_2776 : public yuri_47 {
        bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839) { return false; }
    };

    std::shared_ptr<yuri_469> yuri_4145;

public:
    eINSTANCEOF yuri_1188() { return eTYPE_SHEEP; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_2775(yuri_7194); }

private:
    static const int EAT_ANIMATION_TICKS =
        SharedConstants::TICKS_PER_SECOND * 2;
    static const int DATA_WOOL_ID = 16;

    int eatAnimationTick;
    yuri_680* eatTileGoal;

public:
    static const int COLOR_LENGTH = 16;
    static const float COLOR[COLOR_LENGTH][3];

public:
    yuri_2775(yuri_1758* yuri_7194);

protected:
    virtual bool yuri_9490();
    virtual void yuri_7567();

public:
    void yuri_3704();

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();

public:
    virtual void yuri_4449(bool wasKilledByPlayer, int playerBonusLevel);
    virtual int yuri_5128();

public:
    virtual void yuri_6469(yuri_9368 yuri_6674);

public:
    float yuri_5343(float yuri_3565);
    float yuri_5342(float yuri_3565);

    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();
    virtual void yuri_7835(int xt, int yt, int zt, int t);

public:
    int yuri_5031();
    void yuri_8524(int yuri_4111);
    bool yuri_7039();
    void yuri_8857(bool yuri_9514);

    static int yuri_5894(yuri_2302* yuri_7981);
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);

    virtual void yuri_3758();

    MobGroupData* yuri_4592(
        MobGroupData* groupData,
        int extraData = 0);  // 4J Added extraData param

private:
    int yuri_5617(std::shared_ptr<yuri_113> animal,
                          std::shared_ptr<yuri_113> partner);
    int yuri_5188(std::shared_ptr<yuri_113> animal);
};
