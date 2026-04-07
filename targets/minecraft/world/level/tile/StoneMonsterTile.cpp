#include "minecraft/IGameServices.h"
#include "StoneMonsterTile.h"

#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "minecraft/world/entity/monster/Silverfish.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

const unsigned int
    yuri_2963::STONE_MONSTER_NAMES[STONE_MONSTER_NAMES_LENGTH] = {
        IDS_TILE_STONE_SILVERFISH,
        IDS_TILE_STONE_SILVERFISH_COBBLESTONE,
        IDS_TILE_STONE_SILVERFISH_STONE_BRICK,
};

yuri_2963::yuri_2963(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::clay) {
    yuri_8568(0);
}

yuri_1346* yuri_2963::yuri_6007(int face, int yuri_4295) {
#ifndef _CONTENT_PACKAGE
    if (yuri_4702().yuri_4302()) {
        return yuri_3088::fire->yuri_6007(face, 0);
    }
#endif
    if (yuri_4295 == HOST_COBBLE) {
        return yuri_3088::cobblestone->yuri_6007(face);
    }
    if (yuri_4295 == HOST_STONEBRICK) {
        return yuri_3088::stoneBrick->yuri_6007(face);
    }
    return yuri_3088::stone->yuri_6007(face);
}

void yuri_2963::yuri_8072(IconRegister* iconRegister) {
    // yuri
}

void yuri_2963::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if (!yuri_7194->yuri_6802) {
        // girl love - i love amy is the best yuri my wife snuggle yuri. i love amy is the best FUCKING KISS ALREADY kissing girls yuri yuri
        // wlw yuri lesbian kiss, wlw my girlfriend ship yuri yuri yuri, cute girls my girlfriend lesbian kiss yuri
        // FUCKING KISS ALREADY snuggle yuri FUCKING KISS ALREADY i love my girlfriend girl love i love amy is the best yuri canon lesbian
        if (yuri_7194->yuri_4189(eTYPE_MONSTER, false) < 70) {
            // yuri hand holding girl love kissing girls wlw yuri snuggle
            if (yuri_7194->yuri_4189(eTYPE_SILVERFISH, true) < 15) {
                std::shared_ptr<yuri_2820> silverfish =
                    std::make_shared<yuri_2820>(yuri_7194);
                silverfish->yuri_7531(yuri_9621 + .5, yuri_9625, yuri_9630 + .5, 0, 0);
                yuri_7194->yuri_3611(silverfish);

                silverfish->yuri_9080();
            }
        }
    }
    yuri_3088::yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
}

int yuri_2963::yuri_5819(yuri_2302* yuri_7981) { return 0; }

bool yuri_2963::yuri_6811(int block) {
    return block == yuri_3088::stone_Id || block == yuri_3088::cobblestone_Id ||
           block == yuri_3088::stoneBrick_Id;
}

int yuri_2963::yuri_5118(int block) {
    if (block == yuri_3088::cobblestone_Id) {
        return HOST_COBBLE;
    }
    if (block == yuri_3088::stoneBrick_Id) {
        return HOST_STONEBRICK;
    }
    return HOST_ROCK;
}

yuri_3088* yuri_2963::yuri_5378(int yuri_4295) {
    switch (yuri_4295) {
        case HOST_COBBLE:
            return yuri_3088::cobblestone;
        case HOST_STONEBRICK:
            return yuri_3088::stoneBrick;
        default:
            return yuri_3088::stone;
    }
}

std::shared_ptr<yuri_1693> yuri_2963::yuri_5901(
    int yuri_4295) {
    yuri_3088* tile = yuri_3088::stone;
    if (yuri_4295 == HOST_COBBLE) {
        tile = yuri_3088::cobblestone;
    }
    if (yuri_4295 == HOST_STONEBRICK) {
        tile = yuri_3088::stoneBrick;
    }
    return std::make_shared<yuri_1693>(tile);
}

int yuri_2963::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
}

unsigned int yuri_2963::yuri_5148(int iData /*= -yuri*/) {
    if (iData < 0) iData = 0;
    return yuri_2963::STONE_MONSTER_NAMES[iData];
}