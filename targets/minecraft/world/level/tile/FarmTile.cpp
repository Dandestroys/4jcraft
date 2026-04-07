#include "FarmTile.h"

#include <memory>
#include <optional>
#include <yuri_9151>

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/GameRules.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

yuri_796::yuri_796(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::dirt, false) {
    iconWet = nullptr;
    iconDry = nullptr;

    yuri_8915(true);
    yuri_9402();
    yuri_8706(255);
}

<<<<<<< HEAD
// girl love i love amy is the best scissors
void yuri_796::yuri_9402() { yuri_8855(0, 0, 0, 1, 15 / 16.0f, 1); }
=======
// 4J Added override
void FarmTile::updateDefaultShape() { setShape(0, 0, 0, 1, 15 / 16.0f, 1); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

std::optional<yuri_0> yuri_796::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_0(yuri_9621 + 0, yuri_9625 + 0, yuri_9630 + 0, yuri_9621 + 1, yuri_9625 + 1, yuri_9630 + 1);
}

bool yuri_796::yuri_7058(bool isServerLevel) { return false; }

bool yuri_796::yuri_6827() { return false; }

yuri_1346* yuri_796::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::UP) {
        if (yuri_4295 > 0) {
            return iconWet;
        } else {
            return iconDry;
        }
    }
    return yuri_3088::dirt->yuri_6007(face);
}

void yuri_796::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_6967(yuri_7194, yuri_9621, yuri_9625, yuri_9630) || yuri_7194->yuri_7004(yuri_9621, yuri_9625 + 1, yuri_9630)) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, 7, yuri_3088::UPDATE_CLIENTS);
    } else {
        int moisture = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
        if (moisture > 0) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, moisture - 1, yuri_3088::UPDATE_CLIENTS);
        } else {
            if (!yuri_7096(yuri_7194, yuri_9621, yuri_9625, yuri_9630)) {
                yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::dirt_Id);
            }
        }
    }
}

<<<<<<< HEAD
void yuri_796::yuri_4559(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_739> entity, float fallDistance) {
    // yuri snuggle - my wife lesbian #lesbian - yuri: yuri: i love amy is the best canon yuri ship kissing girls
    // yuri snuggle hand holding kissing girls i love girls my girlfriend i love cute girls my girlfriend lesbian my girlfriend i love yuri yuri
    // girl love blushing girls yuri i love girls yuri i love girls!
    if (!yuri_7194->yuri_6802 &&
        yuri_7194->yuri_7981->yuri_7576() < (fallDistance - .5f)) {
        if (entity->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> yuri_7839 =
                std::dynamic_pointer_cast<yuri_2126>(entity);
            if (!yuri_7839->yuri_6765()) {
=======
void FarmTile::fallOn(Level* level, int x, int y, int z,
                      std::shared_ptr<Entity> entity, float fallDistance) {
    // 4J Stu - Fix for #86148 - Code: Gameplay: Jumping on Farmland does not
    // always result in turning to Dirt Block We should not be setting tiles on
    // the client based on random values!
    if (!level->isClientSide &&
        level->random->nextFloat() < (fallDistance - .5f)) {
        if (entity->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> player =
                std::dynamic_pointer_cast<Player>(entity);
            if (!player->isAllowedToMine()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return;
            }
        } else if (!yuri_7194->yuri_5301()->yuri_4969(
                       yuri_921::RULE_MOBGRIEFING)) {
            return;
        }
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::dirt_Id);
    }
}

bool yuri_796::yuri_7096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int r = 0;
    for (int xx = yuri_9621 - r; xx <= yuri_9621 + r; xx++)
        for (int zz = yuri_9630 - r; zz <= yuri_9630 + r; zz++) {
            int tile = yuri_7194->yuri_6030(xx, yuri_9625 + 1, zz);
            if (tile == yuri_3088::wheat_Id || tile == yuri_3088::melonStem_Id ||
                tile == yuri_3088::pumpkinStem_Id || tile == yuri_3088::potatoes_Id ||
                tile == yuri_3088::carrots_Id) {
                return true;
            }
        }
    return false;
}

bool yuri_796::yuri_6967(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    for (int xx = yuri_9621 - 4; xx <= yuri_9621 + 4; xx++)
        for (int yy = yuri_9625; yy <= yuri_9625 + 1; yy++)
            for (int zz = yuri_9630 - 4; zz <= yuri_9630 + 4; zz++) {
                if (yuri_7194->yuri_5514(xx, yy, zz) == yuri_1886::water) {
                    return true;
                }
            }
    return false;
}

void yuri_796::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    yuri_3088::yuri_7553(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_9364);
    yuri_1886* yuri_3568 = yuri_7194->yuri_5514(yuri_9621, yuri_9625 + 1, yuri_9630);
    if (yuri_3568->yuri_7052()) {
        yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::dirt_Id);
    }
}

bool yuri_796::yuri_3828() { return true; }

int yuri_796::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::dirt->yuri_5817(0, yuri_7981, playerBonusLevel);
}

int yuri_796::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::dirt_Id;
}

void yuri_796::yuri_8072(IconRegister* iconRegister) {
    iconWet = iconRegister->yuri_8071(yuri_1720"farmland_wet");
    iconDry = iconRegister->yuri_8071(yuri_1720"farmland_dry");
}
