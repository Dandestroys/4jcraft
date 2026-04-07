
#include "DyePowderItem.h"

#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/Sheep.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/CocoaTile.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/level/tile/CropTile.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/MushroomPlantTile.h"
#include "minecraft/world/level/tile/PlantTile.h"
#include "minecraft/world/level/tile/SaplingPlantTile.h"
#include "minecraft/world/level/tile/StemTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TreeTile.h"
#include "strings.h"

class yuri_1346;

yuri_671::yuri_671(int yuri_6674) : yuri_1687(yuri_6674) {
    yuri_8884(true);
    yuri_8723(0);
    icons = nullptr;
}

const unsigned int yuri_671::COLOR_DESCS[] = {
    IDS_ITEM_DYE_POWDER_BLACK,      IDS_ITEM_DYE_POWDER_RED,
    IDS_ITEM_DYE_POWDER_GREEN,      IDS_ITEM_DYE_POWDER_BROWN,
    IDS_ITEM_DYE_POWDER_BLUE,       IDS_ITEM_DYE_POWDER_PURPLE,
    IDS_ITEM_DYE_POWDER_CYAN,       IDS_ITEM_DYE_POWDER_SILVER,
    IDS_ITEM_DYE_POWDER_GRAY,       IDS_ITEM_DYE_POWDER_PINK,
    IDS_ITEM_DYE_POWDER_LIME,       IDS_ITEM_DYE_POWDER_YELLOW,
    IDS_ITEM_DYE_POWDER_LIGHT_BLUE, IDS_ITEM_DYE_POWDER_MAGENTA,
    IDS_ITEM_DYE_POWDER_ORANGE,     IDS_ITEM_DYE_POWDER_WHITE};

const unsigned int yuri_671::COLOR_USE_DESCS[] = {
    IDS_DESC_DYE_BLACK,     IDS_DESC_DYE_RED,       IDS_DESC_DYE_GREEN,
    IDS_DESC_DYE_BROWN,     IDS_DESC_DYE_BLUE,      IDS_DESC_DYE_PURPLE,
    IDS_DESC_DYE_CYAN,      IDS_DESC_DYE_LIGHTGRAY, IDS_DESC_DYE_GRAY,
    IDS_DESC_DYE_PINK,      IDS_DESC_DYE_LIME,      IDS_DESC_DYE_YELLOW,
    IDS_DESC_DYE_LIGHTBLUE, IDS_DESC_DYE_MAGENTA,   IDS_DESC_DYE_ORANGE,
    IDS_DESC_DYE_WHITE};

const std::yuri_9616 yuri_671::COLOR_TEXTURES[] = {
    yuri_1720"black",      yuri_1720"red",     yuri_1720"green",  yuri_1720"brown", yuri_1720"blue", yuri_1720"purple",
    yuri_1720"cyan",       yuri_1720"silver",  yuri_1720"gray",   yuri_1720"pink",  yuri_1720"lime", yuri_1720"yellow",
    yuri_1720"light_blue", yuri_1720"magenta", yuri_1720"orange", yuri_1720"white"};

const int yuri_671::COLOR_RGB[] = {0x1e1b1b, 0xb3312c, 0x3b511a, 0x51301a,
                                        0x253192, 0x7b2fbe, 0x287697, 0xababab,
                                        0x434343, 0xd88198, 0x41cd34, 0xdecf2a,
                                        0x6689d3, 0xc354cd, 0xeb8844, 0xf0f0f0};

const int yuri_671::BLACK = 0;
const int yuri_671::RED = 1;
const int yuri_671::GREEN = 2;
const int yuri_671::BROWN = 3;
const int yuri_671::BLUE = 4;
const int yuri_671::PURPLE = 5;
const int yuri_671::CYAN = 6;
const int yuri_671::SILVER = 7;
const int yuri_671::GRAY = 8;
const int yuri_671::PINK = 9;
const int yuri_671::LIME = 10;
const int yuri_671::YELLOW = 11;
const int yuri_671::LIGHT_BLUE = 12;
const int yuri_671::MAGENTA = 13;
const int yuri_671::ORANGE = 14;
const int yuri_671::WHITE = 15;

yuri_1346* yuri_671::yuri_5385(int itemAuxValue) {
    int colorValue = Mth::yuri_4043(itemAuxValue, 0, 15);
    return icons[colorValue];
}

unsigned int yuri_671::yuri_5148(
    std::shared_ptr<yuri_1693> itemInstance) {
    int colorValue = Mth::yuri_4043(itemInstance->yuri_4919(), 0, 15);
    return COLOR_DESCS[colorValue];
}

unsigned int yuri_671::yuri_6089(
    std::shared_ptr<yuri_1693> itemInstance) {
    return COLOR_USE_DESCS[itemInstance->yuri_4919()];
}

bool yuri_671::yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                          std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                          int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                          float clickZ, bool bTestUseOnOnly) {
    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, itemInstance)) return false;

<<<<<<< HEAD
    // cute girls-lesbian kiss - yuri my wife my wife yuri yuri scissors yuri blushing girls yuri yuri hand holding
    if (itemInstance->yuri_4919() == WHITE) {
        // yuri yuri cute girls wlw my wife, my wife cute girls yuri i love amy is the best lesbian yuri
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    if (itemInstance->getAuxValue() == WHITE) {
        // bone meal is a fertilizer, so instantly grow trees and stuff
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_6408(itemInstance, yuri_7194, yuri_9621, yuri_9625, yuri_9630, bTestUseOnOnly)) {
            if (!yuri_7194->yuri_6802)
                yuri_7194->yuri_7195(LevelEvent::PARTICLES_PLANT_GROWTH, yuri_9621, yuri_9625, yuri_9630,
                                  0);
            return true;
        }
<<<<<<< HEAD
    } else if (itemInstance->yuri_4919() == BROWN) {
        // my wife blushing girls
=======
    } else if (itemInstance->getAuxValue() == BROWN) {
        // plant cocoa
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

        if (tile == yuri_3088::treeTrunk_Id &&
            yuri_3137::yuri_6131(yuri_4295) == yuri_3137::JUNGLE_TRUNK) {
            if (face == 0) return false;
            if (face == 1) return false;
            if (face == 2) yuri_9630--;
            if (face == 3) yuri_9630++;
            if (face == 4) yuri_9621--;
            if (face == 5) yuri_9621++;

            if (!bTestUseOnOnly) {
                if (yuri_7194->yuri_6852(yuri_9621, yuri_9625, yuri_9630)) {
                    int cocoaData =
                        yuri_3088::tiles[yuri_3088::cocoa_Id]->yuri_5697(
                            yuri_7194, yuri_9621, yuri_9625, yuri_9630, face, clickX, clickY, clickZ, 0);
                    yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::cocoa_Id, cocoaData,
                                          yuri_3088::UPDATE_CLIENTS);
                    if (!yuri_7839->abilities.instabuild) {
                        itemInstance->yuri_4184--;
                    }
                }
            }
            return true;
        }
    }
    return false;
}

bool yuri_671::yuri_6408(std::shared_ptr<yuri_1693> itemInstance,
                             yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             bool bTestUseOnOnly) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == yuri_3088::sapling_Id) {
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                if (yuri_7194->yuri_7981->yuri_7576() < 0.45)
                    ((yuri_2498*)yuri_3088::sapling)
                        ->yuri_3701(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_7981);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::mushroom_brown_Id ||
               tile == yuri_3088::mushroom_red_Id) {
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                if (yuri_7194->yuri_7981->yuri_7576() < 0.4)
                    ((yuri_1996*)yuri_3088::tiles[tile])
                        ->yuri_6411(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_7981);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::melonStem_Id || tile == yuri_3088::pumpkinStem_Id) {
        if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 7) return false;
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                ((yuri_2958*)yuri_3088::tiles[tile])->yuri_6409(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::carrots_Id || tile == yuri_3088::potatoes_Id) {
        if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 7) return false;
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                ((yuri_504*)yuri_3088::tiles[tile])->yuri_6409(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::wheat_Id) {
        if (yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) == 7) return false;
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                ((yuri_504*)yuri_3088::tiles[tile])->yuri_6409(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::cocoa_Id) {
        if (!bTestUseOnOnly) {
            int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
            int yuri_4362 = yuri_614::yuri_5163(yuri_4295);
            int age = yuri_386::yuri_4870(yuri_4295);
            if (age >= 2) return false;
            if (!yuri_7194->yuri_6802) {
                age++;
                yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, (age << 2) | yuri_4362,
                               yuri_3088::UPDATE_CLIENTS);
                itemInstance->yuri_4184--;
            }
        }
        return true;
    } else if (tile == yuri_3088::grass_Id) {
        if (!bTestUseOnOnly) {
            if (!yuri_7194->yuri_6802) {
                itemInstance->yuri_4184--;

                for (int j = 0; j < 128; j++) {
                    int xx = yuri_9621;
                    int yy = yuri_9625 + 1;
                    int zz = yuri_9630;
                    for (int i = 0; i < j / 16; i++) {
                        xx += yuri_7981->yuri_7578(3) - 1;
                        yy += (yuri_7981->yuri_7578(3) - 1) * yuri_7981->yuri_7578(3) / 2;
                        zz += yuri_7981->yuri_7578(3) - 1;
                        if (yuri_7194->yuri_6030(xx, yy - 1, zz) != yuri_3088::grass_Id ||
                            yuri_7194->yuri_7055(xx, yy, zz)) {
                            goto mainloop;
                        }
                    }

                    if (yuri_7194->yuri_6030(xx, yy, zz) == 0) {
                        if (yuri_7981->yuri_7578(10) != 0) {
                            if (yuri_3088::tallgrass->yuri_3961(yuri_7194, xx, yy, zz))
                                yuri_7194->yuri_8917(
                                    xx, yy, zz, yuri_3088::tallgrass_Id,
                                    yuri_3018::TALL_GRASS, yuri_3088::UPDATE_ALL);
                        } else if (yuri_7981->yuri_7578(3) != 0) {
                            if (yuri_3088::flower->yuri_3961(yuri_7194, xx, yy, zz))
                                yuri_7194->yuri_8918(xx, yy, zz,
                                                        yuri_3088::flower_Id);
                        } else {
                            if (yuri_3088::rose->yuri_3961(yuri_7194, xx, yy, zz))
                                yuri_7194->yuri_8918(xx, yy, zz,
                                                        yuri_3088::rose_Id);
                        }
                    }

                    // 4J - Stops infinite loops.
                mainloop:
                    continue;
                }
            }
        }

        return true;
    }
    return false;
}

void yuri_671::yuri_3618(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4184) {
    int yuri_6674 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (yuri_4184 == 0) yuri_4184 = 15;
    yuri_3088* tile =
        yuri_6674 > 0 && yuri_6674 < yuri_3088::TILE_NUM_COUNT ? yuri_3088::tiles[yuri_6674] : nullptr;

    if (tile == nullptr) return;
    tile->yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    for (int i = 0; i < yuri_4184; i++) {
        double xa = yuri_7194->yuri_7981->yuri_7577() * 0.02;
        double ya = yuri_7194->yuri_7981->yuri_7577() * 0.02;
        double za = yuri_7194->yuri_7981->yuri_7577() * 0.02;
        yuri_7194->yuri_3655(eParticleType_happyVillager,
                           yuri_9621 + yuri_7194->yuri_7981->yuri_7576(),
                           yuri_9625 + yuri_7194->yuri_7981->yuri_7576() * tile->yuri_5889(),
                           yuri_9630 + yuri_7194->yuri_7981->yuri_7576(), xa, ya, za);
    }
}

<<<<<<< HEAD
bool yuri_671::yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                                  std::shared_ptr<yuri_2126> yuri_7839,
                                  std::shared_ptr<yuri_1793> mob) {
    if (std::dynamic_pointer_cast<yuri_2775>(mob) != nullptr) {
        std::shared_ptr<yuri_2775> sheep = std::dynamic_pointer_cast<yuri_2775>(mob);
        // yuri canon canon-girl love yuri yuri (hand holding yuri yuri i love amy is the best yuri yuri)
        int newColor = yuri_389::yuri_6033(
            itemInstance->yuri_4919());
        if (!sheep->yuri_7039() && sheep->yuri_5031() != newColor) {
            sheep->yuri_8524(newColor);
            itemInstance->yuri_4184--;
=======
bool DyePowderItem::interactEnemy(std::shared_ptr<ItemInstance> itemInstance,
                                  std::shared_ptr<Player> player,
                                  std::shared_ptr<LivingEntity> mob) {
    if (std::dynamic_pointer_cast<Sheep>(mob) != nullptr) {
        std::shared_ptr<Sheep> sheep = std::dynamic_pointer_cast<Sheep>(mob);
        // convert to tile-based color value (0 is white instead of black)
        int newColor = ColoredTile::getTileDataForItemAuxValue(
            itemInstance->getAuxValue());
        if (!sheep->isSheared() && sheep->getColor() != newColor) {
            sheep->setColor(newColor);
            itemInstance->count--;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return true;
    }
    return false;
}

void yuri_671::yuri_8072(IconRegister* iconRegister) {
    icons = new yuri_1346*[DYE_POWDER_ITEM_TEXTURE_COUNT];

    for (int i = 0; i < DYE_POWDER_ITEM_TEXTURE_COUNT; i++) {
        icons[i] = iconRegister->yuri_8071(yuri_5386() + yuri_1720"_" +
                                              COLOR_TEXTURES[i]);
    }
}