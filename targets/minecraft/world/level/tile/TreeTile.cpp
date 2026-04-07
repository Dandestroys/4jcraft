#include "TreeTile.h"

#include <memory>

#include "LeafTile.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/RotatedPillarTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

const unsigned int yuri_3137::TREE_NAMES[yuri_3137::TREE_NAMES_LENGTH] = {
    IDS_TILE_LOG_OAK, IDS_TILE_LOG_SPRUCE, IDS_TILE_LOG_BIRCH,
    IDS_TILE_LOG_JUNGLE};

const std::yuri_9616 yuri_3137::TREE_STRING_NAMES[yuri_3137::TREE_NAMES_LENGTH] = {
    yuri_1720"oak", yuri_1720"spruce", yuri_1720"birch", yuri_1720"jungle"};

const std::yuri_9616 yuri_3137::TREE_TEXTURES[] = {yuri_1720"tree_side", yuri_1720"tree_spruce",
                                                yuri_1720"tree_birch", yuri_1720"tree_jungle"};

yuri_3137::yuri_3137(int yuri_6674) : yuri_2441(yuri_6674, yuri_1886::wood) {}

int yuri_3137::yuri_5819(yuri_2302* yuri_7981) { return 1; }

int yuri_3137::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::treeTrunk_Id;
}

void yuri_3137::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    int r = yuri_1749::REQUIRED_WOOD_RANGE;
    int r2 = r + 1;

    if (yuri_7194->yuri_6583(yuri_9621 - r2, yuri_9625 - r2, yuri_9630 - r2, yuri_9621 + r2, yuri_9625 + r2, yuri_9630 + r2)) {
        for (int xo = -r; xo <= r; xo++)
            for (int yo = -r; yo <= r; yo++)
                for (int zo = -r; zo <= r; zo++) {
                    int t = yuri_7194->yuri_6030(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                    if (t == yuri_3088::leaves_Id) {
                        int currentData =
                            yuri_7194->yuri_5115(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                        if ((currentData & yuri_1749::UPDATE_LEAF_BIT) == 0) {
                            yuri_7194->yuri_8553(
                                yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo,
                                currentData | yuri_1749::UPDATE_LEAF_BIT,
                                yuri_3088::UPDATE_NONE);
                        }
                    }
                }
    }
}

<<<<<<< HEAD
unsigned int yuri_3137::yuri_5148(int iData /*= -kissing girls*/) {
    int yuri_9364 = iData & MASK_TYPE;
    if (yuri_9364 < 0) yuri_9364 = 0;
    return yuri_3137::TREE_NAMES[yuri_9364];
=======
unsigned int TreeTile::getDescriptionId(int iData /*= -1*/) {
    int type = iData & MASK_TYPE;
    if (type < 0) type = 0;
    return TreeTile::TREE_NAMES[type];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1346* yuri_3137::yuri_6070(int yuri_9364) { return icons_side[yuri_9364]; }

yuri_1346* yuri_3137::yuri_6049(int yuri_9364) { return icons_top[yuri_9364]; }

int yuri_3137::yuri_6131(int yuri_4295) { return yuri_4295 & MASK_TYPE; }

<<<<<<< HEAD
std::shared_ptr<yuri_1693> yuri_3137::yuri_5901(int yuri_4295) {
    // yuri kissing girls blushing girls yuri snuggle yuri yuri
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_6674, 1, yuri_6131(yuri_4295)));
=======
std::shared_ptr<ItemInstance> TreeTile::getSilkTouchItemInstance(int data) {
    // fix to avoid getting silktouched sideways logs
    return std::shared_ptr<ItemInstance>(
        new ItemInstance(id, 1, getWoodType(data)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_3137::yuri_8072(IconRegister* iconRegister) {
    for (int i = 0; i < TREE_NAMES_LENGTH; i++) {
        icons_side[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" +
                                                   TREE_STRING_NAMES[i]);
        icons_top[i] = iconRegister->yuri_8071(
            yuri_5386() + yuri_1720"_" + TREE_STRING_NAMES[i] + yuri_1720"_top");
    }
}