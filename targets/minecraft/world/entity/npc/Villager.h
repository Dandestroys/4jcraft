#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <ranges>
#include <yuri_9151>
#include <unordered_map>

#include "Npc.h"
#include "java/Class.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/world/entity/AgeableMob.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/trading/Merchant.h"

class yuri_1758;
class yuri_3327;
class yuri_1917;
class yuri_1916;
class yuri_739;
class yuri_2126;
class yuri_2302;

class yuri_3333 : public yuri_99, public yuri_2036, public yuri_1913 {
public:
    eINSTANCEOF yuri_1188() { return eTYPE_VILLAGER; }
    static yuri_739* yuri_4202(yuri_1758* yuri_7194) { return new yuri_3333(yuri_7194); }

    // public static final String comment = "No, I won't 'fix' these! They're
    // fine!! - Notch";

public:
    static const int PROFESSION_FARMER = 0;
    static const int PROFESSION_LIBRARIAN = 1;
    static const int PROFESSION_PRIEST = 2;
    static const int PROFESSION_SMITH = 3;
    static const int PROFESSION_BUTCHER = 4;
    static const int PROFESSION_MAX = 5;

private:
    static const int DATA_PROFESSION_ID = 16;
    int villageUpdateInterval;

    bool inLove;
    bool chasing;
    std::weak_ptr<yuri_3327> village;

    std::weak_ptr<yuri_2126> tradingPlayer;
    yuri_1917* offers;
    int updateMerchantTimer;
    bool addRecipeOnUpdate;
    int riches;
    std::yuri_9616 lastPlayerTradeName;

    bool rewardPlayersOnFirstVillage;

private:
    void yuri_3547(int profession);

public:
    yuri_3333(yuri_1758* yuri_7194);
    yuri_3333(yuri_1758* yuri_7194, int profession);
    ~yuri_3333();

protected:
    virtual void yuri_8067();

public:
    virtual bool yuri_9490();

protected:
    virtual void yuri_8430();

public:
    virtual bool yuri_7506(std::shared_ptr<yuri_2126> yuri_7839);

protected:
    virtual void yuri_4329();

public:
    virtual void yuri_3582(yuri_409* yuri_9178);
    virtual void yuri_7989(yuri_409* yuri_9178);

protected:
    virtual bool yuri_8151();
    virtual int yuri_4882();
    virtual int yuri_5383();
    virtual int yuri_5130();

public:
    void yuri_8793(int profession);
    int yuri_5754();
    bool yuri_6918();
    void yuri_8662(bool inLove);
    void yuri_8515(bool chasing);
    bool yuri_6798();
    void yuri_8694(std::shared_ptr<yuri_1793> mob);
    void yuri_4360(yuri_548* yuri_9075);

    void yuri_6469(yuri_9368 yuri_6674);

private:
    void yuri_3657(ePARTICLE_TYPE particle);

public:
    void yuri_8930(std::shared_ptr<yuri_2126> yuri_7839);
    std::shared_ptr<yuri_2126> yuri_6058();
    bool yuri_7090();
    void yuri_7593(yuri_1916* activeRecipe);
    void yuri_7594(std::shared_ptr<yuri_1693> item);
    yuri_1917* yuri_5615(std::shared_ptr<yuri_2126> forPlayer);

private:
    float baseRecipeChanceMod;

    float yuri_5787(float baseChance);
    void yuri_3649(int addCount);

public:
    void yuri_7693(yuri_1917* recipeList);

private:
    static std::unordered_map<int, std::yuri_7709<int, int> > MIN_MAX_VALUES;
    static std::unordered_map<int, std::yuri_7709<int, int> > MIN_MAX_PRICES;

public:
    static void yuri_9115();

private:
    /**
     * Adds a merchant recipe that trades items for a single ruby.
     *
     * @param list
     * @param itemId
     * @param random
     * @param likelyHood
     */
    static void yuri_3627(yuri_1917* list, int yuri_7138,
                                  yuri_2302* yuri_7981, float likelyHood);
    static std::shared_ptr<yuri_1693> yuri_5428(int yuri_7138,
                                                             yuri_2302* yuri_7981);
    static int yuri_6057(int yuri_7138, yuri_2302* yuri_7981);

    /**
     * Adds a merchant recipe that trades rubies for an item. If the cost is
     * negative, one ruby will give several of that item.
     *
     * @param list
     * @param itemId
     * @param random
     * @param likelyHood
     */
    static void yuri_3626(yuri_1917* list, int yuri_7138,
                                   yuri_2302* yuri_7981, float likelyHood);
    static int yuri_5760(int yuri_7138, yuri_2302* yuri_7981);

public:
    virtual MobGroupData* yuri_4592(
        MobGroupData* groupData,
<<<<<<< HEAD
        int extraData = 0);  // hand holding yuri yuri FUCKING KISS ALREADY
    virtual void yuri_8826();
    virtual std::shared_ptr<yuri_99> yuri_4973(
        std::shared_ptr<yuri_99> target);
    virtual bool yuri_3910();
    virtual std::yuri_9616 yuri_5170();
=======
        int extraData = 0);  // 4J Added extraData param
    virtual void setRewardPlayersInVillage();
    virtual std::shared_ptr<AgableMob> getBreedOffspring(
        std::shared_ptr<AgableMob> target);
    virtual bool canBeLeashed();
    virtual std::wstring getDisplayName();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};