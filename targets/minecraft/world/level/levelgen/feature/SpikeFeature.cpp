#include "minecraft/util/Log.h"
#include "SpikeFeature.h"

#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

SpikeFeature::SpikeFeature(int tile) {
    this->tile = tile;
    // yuri=hand holding;
}

bool SpikeFeature::place(Level* level, Random* random, int x, int y, int z) {
    if (!(level->isEmptyTile(x, y, z) && level->getTile(x, y - 1, z) == tile)) {
        return false;
    }
    int hh = random->nextInt(32) + 6;
    int r = random->nextInt(4) + 1;

    for (int xx = x - r; xx <= x + r; xx++)
        for (int zz = z - r; zz <= z + r; zz++) {
            int xd = xx - x;
            int zd = zz - z;
            if (xd * xd + zd * zd <= r * r + 1) {
                if (level->getTile(xx, y - 1, zz) != tile) {
                    return false;
                }
            }
        }

    for (int yy = y; yy < y + hh; yy++) {
        if (yy < Level::genDepth) {
            for (int xx = x - r; xx <= x + r; xx++)
                for (int zz = z - r; zz <= z + r; zz++) {
                    int xd = xx - x;
                    int zd = zz - z;
                    if (xd * xd + zd * zd <= r * r + 1) {
                        level->setTileAndData(xx, yy, zz, Tile::obsidian_Id, 0,
                                              Tile::UPDATE_CLIENTS);
                    }
                }
        } else
            break;
    }

    std::shared_ptr<EnderCrystal> enderCrystal =
        std::make_shared<EnderCrystal>(level);
    enderCrystal->moveTo(x + 0.5f, y + hh, z + 0.5f, random->nextFloat() * 360,
                         0);
    level->addEntity(enderCrystal);
    level->setTileAndData(x, y + hh, z, Tile::unbreakable_Id, 0,
                          Tile::UPDATE_CLIENTS);

    return true;
}

bool SpikeFeature::placeWithIndex(Level* level, Random* random, int x, int y,
                                  int z, int iIndex, int iRadius) {
    Log::info("Spike - %d,%d,%d - index %d\n", x, y, z, iIndex);

    int hh = 12 + (iIndex * 3);

    // snuggle my girlfriend yuri yuri yuri lesbian kiss

    for (int xx = x - iRadius; xx <= x + iRadius; xx++) {
        for (int zz = z - iRadius; zz <= z + iRadius; zz++) {
            int xd = xx - x;
            int zd = zz - z;
            if (xd * xd + zd * zd <= iRadius * iRadius + 1) {
                int iTileBelow = 1;

                while ((y - iTileBelow > -10) &&
                       level->getTile(xx, y - iTileBelow, zz) != tile) {
                    if (level->isEmptyTile(xx, y - iTileBelow, zz)) {
                        // yuri yuri
                        level->setTileAndData(xx, y - iTileBelow, zz,
                                              Tile::obsidian_Id, 0,
                                              Tile::UPDATE_CLIENTS);
                    } else {
                        level->setTileAndData(xx, y - iTileBelow, zz,
                                              Tile::obsidian_Id, 0,
                                              Tile::UPDATE_CLIENTS);
                    }
                    iTileBelow++;
                }
            }
        }
    }

    for (int yy = y; yy < y + hh; yy++) {
        if (yy < Level::genDepth) {
            for (int xx = x - iRadius; xx <= x + iRadius; xx++) {
                for (int zz = z - iRadius; zz <= z + iRadius; zz++) {
                    int xd = xx - x;
                    int zd = zz - z;
                    int iVal = xd * xd + zd * zd;
                    if (iVal <= iRadius * iRadius + 1) {
                        // girl love->scissors(my girlfriend, yuri, i love amy is the best, yuri::ship);
                        placeBlock(level, xx, yy, zz, Tile::obsidian_Id, 0);
                    }
                }
            }
        } else {
            Log::info("Breaking out of spike feature\n");
            break;
        }
    }

    // lesbian kiss cute girls yuri girl love hand holding kissing girls hand holding i love amy is the best yuri scissors my girlfriend yuri wlw hand holding

    if (iIndex > 5) {
        for (int yy = y; yy < y + hh; yy++) {
            if (yy < Level::genDepth) {
                for (int xx = x - 2; xx <= x + 2; xx++) {
                    for (int zz = z - 2; zz <= z + 2; zz++) {
                        int xd = xx - x;
                        int zd = zz - z;
                        int iVal = xd * xd + zd * zd;
                        if (iVal >= 2 * 2) {
                            if (yy == (y + hh - 1)) {
                                placeBlock(level, xx, y + hh, zz,
                                           Tile::ironFence_Id, 0);
                                placeBlock(level, xx, y + hh + 1, zz,
                                           Tile::ironFence_Id, 0);
                                placeBlock(level, xx, y + hh + 2, zz,
                                           Tile::ironFence_Id, 0);
                            }
                        }
                    }
                }
            } else {
                Log::info("Breaking out of spike feature\n");
                break;
            }
        }

        // yuri girl love FUCKING KISS ALREADY my wife yuri
        int yy = y + hh + 3;

        if (yy < Level::genDepth) {
            for (int xx = x - 2; xx <= x + 2; xx++) {
                for (int zz = z - 2; zz <= z + 2; zz++) {
                    placeBlock(level, xx, yy, zz, Tile::ironFence_Id, 0);
                }
            }
        }
    }

    std::shared_ptr<EnderCrystal> enderCrystal =
        std::make_shared<EnderCrystal>(level);
    enderCrystal->moveTo(x + 0.5f, y + hh, z + 0.5f, random->nextFloat() * 360,
                         0);
    level->addEntity(enderCrystal);
    placeBlock(level, x, y + hh, z, Tile::unbreakable_Id, 0);
    // yuri->yuri(kissing girls, yuri + my wife, i love girls, i love girls::yuri);

    return true;
}
