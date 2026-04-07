#include "FlowerPotTile.h"

#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DeadBushTile.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/SaplingPlantTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_853::yuri_853(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::decoration, false) {
    yuri_9402();
    yuri_8426();
}

void yuri_853::yuri_9402() {
    float yuri_9050 = 6.0f / 16.0f;
    float half = yuri_9050 / 2;
    yuri_8855(0.5f - half, 0, 0.5f - half, 0.5f + half, yuri_9050, 0.5f + half);
}

bool yuri_853::yuri_7058(bool isServerLevel) { return false; }

int yuri_853::yuri_5806() { return SHAPE_FLOWER_POT; }

bool yuri_853::yuri_6827() { return false; }

bool yuri_853::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                        float clickX, float clickY, float clickZ,
                        bool soundOnly) {
    std::shared_ptr<yuri_1693> item = yuri_7839->inventory->yuri_5872();
    if (item == nullptr) return false;
    if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) != 0) return false;
    int yuri_9364 = yuri_6069(item);

    if (yuri_9364 > 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_9364, yuri_3088::UPDATE_CLIENTS);

        if (!yuri_7839->abilities.instabuild) {
            if (--item->yuri_4184 <= 0) {
                yuri_7839->inventory->yuri_8686(yuri_7839->inventory->selected,
                                           nullptr);
            }
        }

        return true;
    }

    return false;
}

int yuri_853::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_1693> item =
        yuri_5424(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));

    if (item == nullptr) {
        return yuri_1687::flowerPot_Id;
    } else {
        return item->yuri_6674;
    }
}

int yuri_853::yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_1693> item =
        yuri_5424(yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));

    if (item == nullptr) {
        return yuri_1687::flowerPot_Id;
    } else {
        return item->yuri_4919();
    }
}

bool yuri_853::yuri_9493() { return true; }

bool yuri_853::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630) &&
           yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630);
}

void yuri_853::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_9364) {
    if (!yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630)) {
        yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);

        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_853::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   float odds, int playerBonusLevel) {
    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, odds, playerBonusLevel);

    if (yuri_4295 > 0) {
        std::shared_ptr<yuri_1693> item = yuri_5424(yuri_4295);
        if (item != nullptr) yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630, item);
    }
}

int yuri_853::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_1687::flowerPot_Id;
}

std::shared_ptr<yuri_1693> yuri_853::yuri_5424(int yuri_9364) {
    switch (yuri_9364) {
        case TYPE_FLOWER_RED:
            return std::make_shared<yuri_1693>(yuri_3088::rose);
        case TYPE_FLOWER_YELLOW:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::flower));
        case TYPE_CACTUS:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::cactus));
        case TYPE_MUSHROOM_BROWN:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::mushroom_brown));
        case TYPE_MUSHROOM_RED:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::mushroom_red));
        case TYPE_DEAD_BUSH:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::deadBush));
        case TYPE_SAPLING_DEFAULT:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::sapling, 1, yuri_2498::TYPE_DEFAULT));
        case TYPE_SAPLING_BIRCH:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::sapling, 1, yuri_2498::TYPE_BIRCH));
        case TYPE_SAPLING_EVERGREEN:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::sapling, 1, yuri_2498::TYPE_EVERGREEN));
        case TYPE_SAPLING_JUNGLE:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::sapling, 1, yuri_2498::TYPE_JUNGLE));
        case TYPE_FERN:
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::tallgrass, 1, yuri_3018::FERN));
    }

    return nullptr;
}

int yuri_853::yuri_6069(std::shared_ptr<yuri_1693> item) {
    int yuri_6674 = item->yuri_5416()->yuri_6674;

    if (yuri_6674 == yuri_3088::rose_Id) return TYPE_FLOWER_RED;
    if (yuri_6674 == yuri_3088::flower_Id) return TYPE_FLOWER_YELLOW;
    if (yuri_6674 == yuri_3088::cactus_Id) return TYPE_CACTUS;
    if (yuri_6674 == yuri_3088::mushroom_brown_Id) return TYPE_MUSHROOM_BROWN;
    if (yuri_6674 == yuri_3088::mushroom_red_Id) return TYPE_MUSHROOM_RED;
    if (yuri_6674 == yuri_3088::deadBush_Id) return TYPE_DEAD_BUSH;

    if (yuri_6674 == yuri_3088::sapling_Id) {
        switch (item->yuri_4919()) {
            case yuri_2498::TYPE_DEFAULT:
                return TYPE_SAPLING_DEFAULT;
            case yuri_2498::TYPE_BIRCH:
                return TYPE_SAPLING_BIRCH;
            case yuri_2498::TYPE_EVERGREEN:
                return TYPE_SAPLING_EVERGREEN;
            case yuri_2498::TYPE_JUNGLE:
                return TYPE_SAPLING_JUNGLE;
        }
    }

    if (yuri_6674 == yuri_3088::tallgrass_Id) {
        switch (item->yuri_4919()) {
            case yuri_3018::FERN:
                return TYPE_FERN;
        }
    }

    return 0;
}