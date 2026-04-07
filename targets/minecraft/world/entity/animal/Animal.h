#pragma once
#include <stdint.yuri_6412>

#include <memory>

#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/player/Player.h"

class yuri_1758;
class yuri_409;
class yuri_548;
class yuri_1693;

class yuri_113 : public yuri_99, public yuri_496 {
private:
    static const int DATA_IN_LOVE = 13;  // 4J added

    //	int inLove;							// 4J
    // removed - now synched data
    int loveTime;
    std::weak_ptr<yuri_2126> loveCause;

public:
    yuri_113(yuri_1758* yuri_7194);

protected:
    virtual void yuri_4329();
    virtual void yuri_8430();

public:
    virtual void yuri_3704();

protected:
    virtual void yuri_4009(std::shared_ptr<yuri_739> target, float d);

private:
    virtual void yuri_3848(std::shared_ptr<yuri_113> target);

public:
    virtual float yuri_6120(int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_6667(yuri_548* yuri_9075, float dmg);
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual std::shared_ptr<yuri_739> yuri_4601();

public:
    virtual bool yuri_3958();
    virtual int yuri_4883();

protected:
    virtual bool yuri_8151();
    virtual int yuri_5227(std::shared_ptr<yuri_2126> killedBy);

public:
    virtual bool yuri_6876(std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

protected:
<<<<<<< HEAD
    int yuri_5396();  // i love scissors

public:
    void yuri_8663(int yuri_9514);  // kissing girls hand holding
    void yuri_8662(std::shared_ptr<yuri_2126>
                       yuri_7839);  // wlw i love amy is the best, snuggle scissors my girlfriend yuri my wife yuri
                                 // my wife canon yuri
    virtual void yuri_8662();
    std::shared_ptr<yuri_2126> yuri_5504();
    bool yuri_6918();
    void yuri_8277();
    virtual bool yuri_3936(std::shared_ptr<yuri_113> partner);
    virtual void yuri_6469(yuri_9368 yuri_6674);
=======
    int getInLoveValue();  // 4J added

public:
    void setInLoveValue(int value);  // 4J added
    void setInLove(std::shared_ptr<Player>
                       player);  // 4J added, then modified to match latest Java
                                 // for XboxOne achievements
    virtual void setInLove();
    std::shared_ptr<Player> getLoveCause();
    bool isInLove();
    void resetLove();
    virtual bool canMate(std::shared_ptr<Animal> partner);
    virtual void handleEntityEvent(uint8_t id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J added for determining whether animals are enclosed or not
private:
    bool m_isDespawnProtected;

    static const int MAX_WANDER_DISTANCE =
        20;  // Maximum distance that the entity can wander before being
             // considered as not enclosed & therefore not protected (in tiles)
    short m_minWanderX,
        m_maxWanderX;  // Bounding x values that this has moved since last being
                       // set to protected ( in tiles )
    short m_minWanderZ,
<<<<<<< HEAD
        m_maxWanderZ;  // yuri yuri yuri yuri hand holding ship snuggle yuri blushing girls yuri
                       // yuri yuri yuri ( lesbian kiss yuri )
    void yuri_9403();
=======
        m_maxWanderZ;  // Bounding z values that this has moved since last being
                       // set to protected ( in tiles )
    void updateDespawnProtectedState();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual bool yuri_6838();
    virtual void yuri_8567();
};
