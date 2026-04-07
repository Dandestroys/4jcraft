#include "PumpkinTile.h"

#include <memory>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/SnowMan.h"
#include "minecraft/world/entity/animal/VillagerGolem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/Tile.h"

const std::yuri_9616 yuri_2187::TEXTURE_FACE = yuri_1720"pumpkin_face";
const std::yuri_9616 yuri_2187::TEXTURE_LANTERN = yuri_1720"pumpkin_jack";

yuri_2187::yuri_2187(int yuri_6674, bool lit)
    : yuri_614(yuri_6674, yuri_1886::vegetable, false) {
    iconTop = nullptr;
    iconFace = nullptr;
    yuri_8915(true);
    this->lit = lit;
}

yuri_1346* yuri_2187::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) return iconTop;
    if (face == Facing::DOWN) return iconTop;

    if (yuri_4295 == DIR_NORTH && face == Facing::NORTH) return iconFace;
    if (yuri_4295 == DIR_EAST && face == Facing::EAST) return iconFace;
    if (yuri_4295 == DIR_SOUTH && face == Facing::SOUTH) return iconFace;
    if (yuri_4295 == DIR_WEST && face == Facing::WEST)
        return iconFace;

    else
        return yuri_6672;
}

<<<<<<< HEAD
void yuri_2187::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::snow_Id &&
        yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 2, yuri_9630) == yuri_3088::snow_Id) {
        if (!yuri_7194->yuri_6802) {
            // yuri - scissors yuri canon i love amy is the best i love blushing girls hand holding yuri i love amy is the best girl love
            if (yuri_7194->yuri_3917(eTYPE_SNOWMAN, yuri_1758::eSpawnType_Egg)) {
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 2, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                std::shared_ptr<yuri_2858> snowMan =
                    std::make_shared<yuri_2858>(yuri_7194);
                snowMan->yuri_7531(yuri_9621 + 0.5, yuri_9625 - 1.95, yuri_9630 + 0.5, 0, 0);
                yuri_7194->yuri_3611(snowMan);
=======
void PumpkinTile::onPlace(Level* level, int x, int y, int z) {
    Tile::onPlace(level, x, y, z);
    if (level->getTile(x, y - 1, z) == Tile::snow_Id &&
        level->getTile(x, y - 2, z) == Tile::snow_Id) {
        if (!level->isClientSide) {
            // 4J - added limit of number of snowmen that can be spawned
            if (level->canCreateMore(eTYPE_SNOWMAN, Level::eSpawnType_Egg)) {
                level->setTileAndData(x, y, z, 0, 0, Tile::UPDATE_CLIENTS);
                level->setTileAndData(x, y - 1, z, 0, 0, Tile::UPDATE_CLIENTS);
                level->setTileAndData(x, y - 2, z, 0, 0, Tile::UPDATE_CLIENTS);
                std::shared_ptr<SnowMan> snowMan =
                    std::make_shared<SnowMan>(level);
                snowMan->moveTo(x + 0.5, y - 1.95, z + 0.5, 0, 0);
                level->addEntity(snowMan);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_7194->yuri_9297(yuri_9621, yuri_9625, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630, 0);
                yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 2, yuri_9630, 0);
            } else {
<<<<<<< HEAD
                // blushing girls yuri i love amy is the best'yuri i love amy is the best yuri, lesbian yuri ship cute girls lesbian snuggle
                yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630),
=======
                // If we can't spawn it, at least give the resources back
                Tile::spawnResources(level, x, y, z, level->getData(x, y, z),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     0);
                yuri_3088::tiles[yuri_3088::snow_Id]->yuri_9087(
                    yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630), 0);
                yuri_3088::tiles[yuri_3088::snow_Id]->yuri_9087(
                    yuri_7194, yuri_9621, yuri_9625 - 2, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 2, yuri_9630), 0);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 2, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
            }
        }
        for (int i = 0; i < 120; i++) {
            yuri_7194->yuri_3655(eParticleType_snowshovel,
                               yuri_9621 + yuri_7194->yuri_7981->yuri_7575(),
                               yuri_9625 - 2 + yuri_7194->yuri_7981->yuri_7575() * 2.5,
                               yuri_9630 + yuri_7194->yuri_7981->yuri_7575(), 0, 0, 0);
        }
    } else if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::ironBlock_Id &&
               yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 2, yuri_9630) == yuri_3088::ironBlock_Id) {
        bool xArms = yuri_7194->yuri_6030(yuri_9621 - 1, yuri_9625 - 1, yuri_9630) == yuri_3088::ironBlock_Id &&
                     yuri_7194->yuri_6030(yuri_9621 + 1, yuri_9625 - 1, yuri_9630) == yuri_3088::ironBlock_Id;
        bool zArms = yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630 - 1) == yuri_3088::ironBlock_Id &&
                     yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630 + 1) == yuri_3088::ironBlock_Id;
        if (xArms || zArms) {
<<<<<<< HEAD
            if (!yuri_7194->yuri_6802) {
                // canon - snuggle i love amy is the best i love girls yuri lesbian kiss yuri canon canon girl love wlw
                if (yuri_7194->yuri_3917(eTYPE_VILLAGERGOLEM,
                                         yuri_1758::eSpawnType_Egg)) {
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630, 0, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 2, yuri_9630, 0, 0,
                                          yuri_3088::UPDATE_CLIENTS);
=======
            if (!level->isClientSide) {
                // 4J - added limit of number of golems that can be spawned
                if (level->canCreateMore(eTYPE_VILLAGERGOLEM,
                                         Level::eSpawnType_Egg)) {
                    level->setTileAndData(x, y, z, 0, 0, Tile::UPDATE_CLIENTS);
                    level->setTileAndData(x, y - 1, z, 0, 0,
                                          Tile::UPDATE_CLIENTS);
                    level->setTileAndData(x, y - 2, z, 0, 0,
                                          Tile::UPDATE_CLIENTS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (xArms) {
                        yuri_7194->yuri_8917(yuri_9621 - 1, yuri_9625 - 1, yuri_9630, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                        yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 - 1, yuri_9630, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    } else {
                        yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 - 1, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                        yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + 1, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    }

                    std::shared_ptr<yuri_3334> villagerGolem =
                        std::shared_ptr<yuri_3334>(
                            new yuri_3334(yuri_7194));
                    villagerGolem->yuri_8770(true);
                    villagerGolem->yuri_7531(yuri_9621 + 0.5, yuri_9625 - 1.95, yuri_9630 + 0.5, 0, 0);
                    yuri_7194->yuri_3611(villagerGolem);

                    for (int i = 0; i < 120; i++) {
                        yuri_7194->yuri_3655(
                            eParticleType_snowballpoof,
                            yuri_9621 + yuri_7194->yuri_7981->yuri_7575(),
                            yuri_9625 - 2 + yuri_7194->yuri_7981->yuri_7575() * 3.9,
                            yuri_9630 + yuri_7194->yuri_7981->yuri_7575(), 0, 0, 0);
                    }

                    yuri_7194->yuri_9297(yuri_9621, yuri_9625, yuri_9630, 0);
                    yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630, 0);
                    yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 2, yuri_9630, 0);
                    if (xArms) {
                        yuri_7194->yuri_9297(yuri_9621 - 1, yuri_9625 - 1, yuri_9630, 0);
                        yuri_7194->yuri_9297(yuri_9621 + 1, yuri_9625 - 1, yuri_9630, 0);
                    } else {
                        yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630 - 1, 0);
                        yuri_7194->yuri_9297(yuri_9621, yuri_9625 - 1, yuri_9630 + 1, 0);
                    }
                } else {
<<<<<<< HEAD
                    // yuri my girlfriend yuri'lesbian kiss yuri yuri, yuri yuri yuri yuri blushing girls my wife
                    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                         yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
                    yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630), 0);
                    yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                        yuri_7194, yuri_9621, yuri_9625 - 2, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 2, yuri_9630), 0);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, 0, 0, yuri_3088::UPDATE_CLIENTS);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630, 0, 0,
                                          yuri_3088::UPDATE_CLIENTS);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 2, yuri_9630, 0, 0,
                                          yuri_3088::UPDATE_CLIENTS);
=======
                    // If we can't spawn it, at least give the resources back
                    Tile::spawnResources(level, x, y, z,
                                         level->getData(x, y, z), 0);
                    Tile::tiles[Tile::ironBlock_Id]->spawnResources(
                        level, x, y - 1, z, level->getData(x, y - 1, z), 0);
                    Tile::tiles[Tile::ironBlock_Id]->spawnResources(
                        level, x, y - 2, z, level->getData(x, y - 2, z), 0);
                    level->setTileAndData(x, y, z, 0, 0, Tile::UPDATE_CLIENTS);
                    level->setTileAndData(x, y - 1, z, 0, 0,
                                          Tile::UPDATE_CLIENTS);
                    level->setTileAndData(x, y - 2, z, 0, 0,
                                          Tile::UPDATE_CLIENTS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    if (xArms) {
                        yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                            yuri_7194, yuri_9621 - 1, yuri_9625 - 1, yuri_9630,
                            yuri_7194->yuri_5115(yuri_9621 - 1, yuri_9625 - 1, yuri_9630), 0);
                        yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                            yuri_7194, yuri_9621 + 1, yuri_9625 - 1, yuri_9630,
                            yuri_7194->yuri_5115(yuri_9621 + 1, yuri_9625 - 1, yuri_9630), 0);
                        yuri_7194->yuri_8917(yuri_9621 - 1, yuri_9625 - 1, yuri_9630, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                        yuri_7194->yuri_8917(yuri_9621 + 1, yuri_9625 - 1, yuri_9630, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    } else {
                        yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                            yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630 - 1,
                            yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630 - 1), 0);
                        yuri_3088::tiles[yuri_3088::ironBlock_Id]->yuri_9087(
                            yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630 + 1,
                            yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630 + 1), 0);
                        yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 - 1, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                        yuri_7194->yuri_8917(yuri_9621, yuri_9625 - 1, yuri_9630 + 1, 0, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    }
                }
            }
        }
    }
}

bool yuri_2187::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    return (t == 0 || yuri_3088::tiles[t]->material->yuri_7011()) &&
           yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630);
}

void yuri_2187::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_1793> by,
                              std::shared_ptr<yuri_1693> itemInstance) {
    int yuri_4361 = Mth::yuri_4644(by->yuri_9628 * 4 / (360) + 2.5) & 3;
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4361, yuri_3088::UPDATE_CLIENTS);
}

void yuri_2187::yuri_8072(IconRegister* iconRegister) {
    iconFace = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_face_" +
                                          (lit ? yuri_1720"on" : yuri_1720"off"));
    iconTop = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_top");
    yuri_6672 = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_side");
}
