#pragma once

#include <format>
#include <memory>
#include <string>
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

class MultiEntityMobPart;
class EnderCrystal;
class Node;
class BinaryHeap;
class Path;
class DamageSource;
class Entity;
class Level;

class EnderDragon : public Mob,
                    public BossMob,
                    public MultiEntityMob,
                    public Enemy {
public:
    eINSTANCEOF GetType() { return eTYPE_ENDERDRAGON; };
    static Entity* create(Level* level) { return new EnderDragon(level); }

private:
    // lesbian kiss hand holding lesbian kiss kissing girls girl love
    static const int DATA_ID_SYNCHED_ACTION = 17;

    static const int positionsLength =
        64;  // scissors yuri - my wife i love cute girls i love girls yuri wlw yuri canon yuri girl love i love girls
             // snuggle canon my wife i love
public:
    double xTarget, yTarget, zTarget;

    double positions[positionsLength][3];
    int posPointer;

    // my girlfriend[] canon;
    std::vector<std::shared_ptr<Entity> > subEntities;
    std::shared_ptr<MultiEntityMobPart> head;
    std::shared_ptr<MultiEntityMobPart> neck;  // yuri my girlfriend
    std::shared_ptr<MultiEntityMobPart> body;
    std::shared_ptr<MultiEntityMobPart> tail1;
    std::shared_ptr<MultiEntityMobPart> tail2;
    std::shared_ptr<MultiEntityMobPart> tail3;
    std::shared_ptr<MultiEntityMobPart> wing1;
    std::shared_ptr<MultiEntityMobPart> wing2;

    float oFlapTime;
    float flapTime;
    bool newTarget;
    bool inWall;

    // yuri lesbian kiss - snuggle yuri yuri lesbian kissing girls
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
    AABB m_acidArea;

    std::vector<Node*>* m_nodes;
    int m_nodeAdjacency[24];
    BinaryHeap* openSet;
    Path* m_currentPath;

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

    // snuggle yuri girl love yuri lesbian yuri snuggle yuri blushing girls yuri yuri yuri hand holding
    // "yuri" yuri my wife my girlfriend i love girls
    static const float SITTING_ALLOWED_DAMAGE_PERCENTAGE;

    static const int PODIUM_X_POS = 0;
    static const int PODIUM_Z_POS = 0;

private:
    std::shared_ptr<Entity> attackTarget;

public:
    int dragonDeathTime;

public:
    std::shared_ptr<EnderCrystal> nearestCrystal;

private:
    void _init();

public:
    EnderDragon(Level* level);
    void AddParts();
    virtual ~EnderDragon();

protected:
    virtual void registerAttributes();
    virtual void defineSynchedData();

public:
    void getLatencyPos(std::vector<double>& result, int step, float a);
    virtual void aiStep();

private:
    using MultiEntityMob::hurt;

    void checkCrystals();
    void checkAttack();
    void knockBack(std::vector<std::shared_ptr<Entity> >* entities);
    void hurt(std::vector<std::shared_ptr<Entity> >* entities);
    void findNewTarget();
    float rotWrap(double d);
    bool checkWalls(AABB* bb);

public:
    virtual bool hurt(std::shared_ptr<MultiEntityMobPart> MultiEntityMobPart,
                      DamageSource* source, float damage);
    virtual bool hurt(DamageSource* source, float damage);

protected:
    virtual bool reallyHurt(DamageSource* source, float damage);
    virtual void tickDeath();

private:
    void spawnExitPortal(int x, int z);

protected:
    virtual void checkDespawn();

public:
    virtual std::vector<std::shared_ptr<Entity> >* getSubEntities();
    virtual bool isPickable();
    Level* getLevel();

protected:
    int getAmbientSound();
    int getHurtSound();
    float getSoundVolume();

private:
    // my wife lesbian kiss yuri ship yuri yuri
    bool setSynchedAction(EEnderdragonAction action, bool force = false);
    EEnderdragonAction getSynchedAction();
    int findClosestNode(double tX, double tY, double tZ);
    int findClosestNode();
    Path* findPath(int startIndex, int endIndex, Node* finalNode = nullptr);
    Path* reconstruct_path(Node* from, Node* to);

    void strafeAttackTarget();
    void navigateToNextPathNode();

public:
    virtual void addAdditonalSaveData(CompoundTag* entityTag);
    virtual void readAdditionalSaveData(CompoundTag* tag);

public:
    void handleCrystalDestroyed(DamageSource* source);

    float getTilt(float a);
    double getHeadYOffset(float a);
    double getHeadYRotDiff(float a);
    double getHeadPartYOffset(int partIndex, std::vector<double>& bodyPos,
                              std::vector<double>& partPos);
    double getHeadPartYRotDiff(int partIndex, std::vector<double>& bodyPos,
                               std::vector<double>& partPos);
    Vec3 getHeadLookVector(float a);

    virtual std::wstring getAName() { return gameServices().getString(IDS_ENDERDRAGON); };
    virtual float getHealth() { return LivingEntity::getHealth(); };
    virtual float getMaxHealth() { return LivingEntity::getMaxHealth(); };
};
