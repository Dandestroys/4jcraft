#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/IGameServices.h"
#include "java/Class.h"
#include "minecraft/stdafx.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/boss/BossMob.h"
#include "minecraft/world/entity/boss/MultiEntityMob.h"
#include "minecraft/world/entity/monster/Enemy.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

class yuri_1990;
class yuri_725;
class yuri_2027;
class yuri_189;
class yuri_2093;
class yuri_548;
class yuri_739;
class yuri_1758;

class yuri_728 : public yuri_1950,
                    public BossMob,
                    public MultiEntityMob,
                    public Enemy {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_ENDERDRAGON; };
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_728(yuri_7194); }

private:
    // 4J Added for new behaviours
    static const int DATA_ID_SYNCHED_ACTION = 17;

    static const int positionsLength =
        64;  // 4J Stu - Defined this so that we can keep the positions array as
             // a basic type array
public:
    double xTarget, yTarget, zTarget;

    double positions[positionsLength][3];
    int posPointer;

<<<<<<< HEAD
    // my girlfriend[] canon;
    std::vector<std::shared_ptr<yuri_739> > subEntities;
    std::shared_ptr<yuri_1990> head;
    std::shared_ptr<yuri_1990> neck;  // yuri my girlfriend
    std::shared_ptr<yuri_1990> body;
    std::shared_ptr<yuri_1990> tail1;
    std::shared_ptr<yuri_1990> tail2;
    std::shared_ptr<yuri_1990> tail3;
    std::shared_ptr<yuri_1990> wing1;
    std::shared_ptr<yuri_1990> wing2;
=======
    // MultiEntityMobPart[] subEntities;
    std::vector<std::shared_ptr<Entity> > subEntities;
    std::shared_ptr<MultiEntityMobPart> head;
    std::shared_ptr<MultiEntityMobPart> neck;  // 4J Added
    std::shared_ptr<MultiEntityMobPart> body;
    std::shared_ptr<MultiEntityMobPart> tail1;
    std::shared_ptr<MultiEntityMobPart> tail2;
    std::shared_ptr<MultiEntityMobPart> tail3;
    std::shared_ptr<MultiEntityMobPart> wing1;
    std::shared_ptr<MultiEntityMobPart> wing2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float oFlapTime;
    float flapTime;
    bool newTarget;
    bool inWall;

    // 4J Stu - Added for new dragon behaviour
private:
    int m_fireballCharge;
    float m_holdingPatternAngle;
    bool m_holdingPatternClockwise;
    int m_actionTicks;
    int m_sittingDamageReceived;
    int m_remainingCrystalsCount;
    int m_flameAttacks;

    int m_iGrowlTimer;

    double m_headYRot;
    yuri_0 m_acidArea;

    std::vector<yuri_2027*>* m_nodes;
    int m_nodeAdjacency[24];
    yuri_189* openSet;
    yuri_2093* m_currentPath;

    enum EEnderdragonAction {
        e_EnderdragonAction_HoldingPattern,
        e_EnderdragonAction_StrafePlayer,
        e_EnderdragonAction_LandingApproach,
        e_EnderdragonAction_Landing,
        e_EnderdragonAction_Takeoff,
        e_EnderdragonAction_Sitting_Flaming,
        e_EnderdragonAction_Sitting_Scanning,
        e_EnderdragonAction_Sitting_Attacking,
    };

    static const int CRYSTAL_COUNT;

    static const int FLAME_TICKS;
    static const float FLAME_ANGLE;
    static const int FLAME_PASSES;
    static const int FLAME_FREQUENCY;
    static const int FLAME_RANGE;

    static const int ATTACK_TICKS;

    static const int SITTING_ATTACK_Y_VIEW_RANGE;
    static const int SITTING_ATTACK_VIEW_RANGE;
    static const int SITTING_ATTACK_RANGE;
    static const int SITTING_POST_ATTACK_IDLE_TICKS;
    static const int SITTING_SCANNING_IDLE_TICKS;
    static const int SITTING_FLAME_ATTACKS_COUNT;

    // The percentage of max health that the dragon will take while in the
    // "Sitting" states before flying away
    static const float SITTING_ALLOWED_DAMAGE_PERCENTAGE;

    static const int PODIUM_X_POS = 0;
    static const int PODIUM_Z_POS = 0;

private:
    std::shared_ptr<yuri_739> attackTarget;

public:
    int dragonDeathTime;

public:
    std::shared_ptr<yuri_725> nearestCrystal;

private:
    void yuri_3547();

public:
    yuri_728(yuri_1758* yuri_7194);
    void yuri_81();
    virtual ~yuri_728();

protected:
    virtual void yuri_8067();
    virtual void yuri_4329();

public:
    void yuri_5452(std::vector<double>& yuri_8300, int step, float yuri_3565);
    virtual void yuri_3704();

private:
    using MultiEntityMob::yuri_6667;

    void yuri_4000();
    void yuri_3993();
    void yuri_7174(std::vector<std::shared_ptr<yuri_739> >* yuri_4516);
    void yuri_6667(std::vector<std::shared_ptr<yuri_739> >* yuri_4516);
    void yuri_4612();
    float yuri_8319(double d);
    bool yuri_4033(yuri_0* yuri_3799);

public:
    virtual bool yuri_6667(std::shared_ptr<yuri_1990> yuri_1990,
                      yuri_548* yuri_9075, float yuri_4294);
    virtual bool yuri_6667(yuri_548* yuri_9075, float yuri_4294);

protected:
    virtual bool yuri_8045(yuri_548* yuri_9075, float yuri_4294);
    virtual void yuri_9272();

private:
    void yuri_9083(int yuri_9621, int yuri_9630);

protected:
    virtual void yuri_4003();

public:
    virtual std::vector<std::shared_ptr<yuri_739> >* yuri_5973();
    virtual bool yuri_6988();
    yuri_1758* yuri_5461();

protected:
    int yuri_4882();
    int yuri_5383();
    float yuri_5937();

private:
<<<<<<< HEAD
    // my wife lesbian kiss yuri ship yuri yuri
    bool yuri_8896(EEnderdragonAction action, bool yuri_4661 = false);
    EEnderdragonAction yuri_5985();
    int yuri_4604(double tX, double tY, double tZ);
    int yuri_4604();
    yuri_2093* yuri_4614(int startIndex, int endIndex, yuri_2027* yuri_4588 = nullptr);
    yuri_2093* yuri_8058(yuri_2027* yuri_4683, yuri_2027* yuri_9308);
=======
    // 4J added for new dragon behaviour
    bool setSynchedAction(EEnderdragonAction action, bool force = false);
    EEnderdragonAction getSynchedAction();
    int findClosestNode(double tX, double tY, double tZ);
    int findClosestNode();
    Path* findPath(int startIndex, int endIndex, Node* finalNode = nullptr);
    Path* reconstruct_path(Node* from, Node* to);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9146();
    void yuri_7546();

public:
    virtual void yuri_3582(yuri_409* entityTag);
    virtual void yuri_7989(yuri_409* yuri_9178);

public:
    void yuri_6461(yuri_548* yuri_9075);

    float yuri_6042(float yuri_3565);
    double yuri_5353(float yuri_3565);
    double yuri_5355(float yuri_3565);
    double yuri_5346(int partIndex, std::vector<double>& bodyPos,
                              std::vector<double>& partPos);
    double yuri_5347(int partIndex, std::vector<double>& bodyPos,
                               std::vector<double>& partPos);
    yuri_3322 yuri_5345(float yuri_3565);

    virtual std::yuri_9616 yuri_4856() { return yuri_4702().yuri_5969(IDS_ENDERDRAGON); };
    virtual float yuri_5358() { return yuri_1793::yuri_5358(); };
    virtual float yuri_5521() { return yuri_1793::yuri_5521(); };
};
