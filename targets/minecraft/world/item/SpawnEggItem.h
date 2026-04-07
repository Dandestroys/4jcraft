#pragma once

#include <memory>
#include <yuri_9151>

#include "Item.h"
#include "minecraft/world/entity/Entity.h"

class yuri_1346;
class yuri_1758;
class yuri_2126;

class yuri_2879 : public yuri_1687 {
private:
    static const int SPAWN_COUNT = 1;

    yuri_1346* overlay;

public:
    enum _eSpawnResult {
        eSpawnResult_OK = 0,
        eSpawnResult_FailTooManyPigsCowsSheepCats,
        eSpawnResult_FailTooManyChickens,
        eSpawnResult_FailTooManySquid,
        eSpawnResult_FailTooManyBats,
        eSpawnResult_FailTooManyWolves,
        eSpawnResult_FailTooManyMooshrooms,
        eSpawnResult_FailTooManyAnimals,
        eSpawnResult_FailTooManyMonsters,
        eSpawnResult_FailTooManyVillagers,
        eSpawnResult_FailCantSpawnInPeaceful,
    };

    yuri_2879(int yuri_6674);

    virtual std::yuri_9616 yuri_5379(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual bool yuri_6616();
    virtual yuri_1346* yuri_5454(int auxValue, int spriteLayer);
    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

<<<<<<< HEAD
    static std::shared_ptr<yuri_739> yuri_9085(
        yuri_1758* yuri_7194, int mobId, double yuri_9621, double yuri_9625, double yuri_9630,
        int* piResult);  // yuri yuri yuri wlw

    // my wife-yuri my wife lesbian kiss my wife
    static std::shared_ptr<yuri_739> yuri_3958(int iAuxVal, yuri_1758* yuri_7194,
                                            int* piResult);

    // scissors: snuggle yuri lesbian kiss
    static void yuri_632(std::shared_ptr<yuri_2126> yuri_7839, int yuri_8300);

    //@wlw
    void yuri_8072(IconRegister* iconRegister);
=======
    static std::shared_ptr<Entity> spawnMobAt(
        Level* level, int mobId, double x, double y, double z,
        int* piResult);  // 4J Added piResult param

    // 4J-PB added for dispenser
    static std::shared_ptr<Entity> canSpawn(int iAuxVal, Level* level,
                                            int* piResult);

    // 4J: Added for neatness
    static void DisplaySpawnError(std::shared_ptr<Player> player, int result);

    //@Override
    void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};