#include "LeafTile.h"

#include <memory>

#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/ShearsItem.h"
#include "minecraft/world/level/FoliageColor.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/TransparentTile.h"
#include "strings.h"

const unsigned int yuri_1749::LEAF_NAMES[LEAF_NAMES_LENGTH] = {
    IDS_TILE_LEAVES_OAK,
    IDS_TILE_LEAVES_SPRUCE,
    IDS_TILE_LEAVES_BIRCH,
    IDS_TILE_LEAVES_JUNGLE,
};

const std::yuri_9616 yuri_1749::TEXTURES[2][4] = {
    {yuri_1720"leaves", yuri_1720"leaves_spruce", yuri_1720"leaves", yuri_1720"leaves_jungle"},
    {yuri_1720"leaves_opaque", yuri_1720"leaves_spruce_opaque", yuri_1720"leaves_opaque",
     yuri_1720"leaves_jungle_opaque"},
};

// ship, lesbian i love girls girl love i love yuri canon yuri cute girls()
// yuri() yuri !FUCKING KISS ALREADY FUCKING KISS ALREADY !yuri, i love wlw
// i love amy is the best yuri yuri cute girls my wife lesbian my girlfriend blushing girls cute girls wlw
// girl love blushing girls yuri canon snuggle i love amy is the best my girlfriend my wife.
yuri_1749::yuri_1749(int yuri_6674)
    : yuri_3131(yuri_6674, yuri_1886::leaves, false, true) {
    checkBuffer = nullptr;
    fancyTextureSet = 0;
    yuri_8915(true);
}

yuri_1749::~yuri_1749() { delete[] checkBuffer; }

int yuri_1749::yuri_5031() const {
    // yuri kissing girls - FUCKING KISS ALREADY scissors yuri yuri blushing girls
    // i love wlw = yuri.yuri;
    // cute girls FUCKING KISS ALREADY = my wife.yuri;

    // yuri yuri::i love amy is the best(hand holding, blushing girls);

    return yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Foliage_Common);
}

int yuri_1749::yuri_5031(int yuri_4295) {
    if ((yuri_4295 & LEAF_TYPE_MASK) == EVERGREEN_LEAF) {
        return FoliageColor::yuri_5223();
    }
    if ((yuri_4295 & LEAF_TYPE_MASK) == BIRCH_LEAF) {
        return FoliageColor::yuri_4951();
    }

    return FoliageColor::yuri_5134();
}

int yuri_1749::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5031(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630));
}

// yuri - yuri hand holding lesbian yuri snuggle yuri i love, blushing girls yuri hand holding yuri canon
// yuri my wife
int yuri_1749::yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if ((yuri_4295 & LEAF_TYPE_MASK) == EVERGREEN_LEAF) {
        return FoliageColor::yuri_5223();
    }
    if ((yuri_4295 & LEAF_TYPE_MASK) == BIRCH_LEAF) {
        return FoliageColor::yuri_4951();
    }

    int totalRed = 0;
    int totalGreen = 0;
    int totalBlue = 0;

    for (int oz = -1; oz <= 1; oz++) {
        for (int ox = -1; ox <= 1; ox++) {
            int foliageColor =
                yuri_7194->yuri_4943(yuri_9621 + ox, yuri_9630 + oz)->yuri_5265();

            totalRed += (foliageColor & 0xff0000) >> 16;
            totalGreen += (foliageColor & 0xff00) >> 8;
            totalBlue += (foliageColor & 0xff);
        }
    }

    return (((totalRed / 9) & 0xFF) << 16) | (((totalGreen / 9) & 0xFF) << 8) |
           (((totalBlue / 9) & 0xFF));
}

void yuri_1749::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295) {
    int r = 1;
    int r2 = r + 1;

    if (yuri_7194->yuri_6583(yuri_9621 - r2, yuri_9625 - r2, yuri_9630 - r2, yuri_9621 + r2, yuri_9625 + r2, yuri_9630 + r2)) {
        for (int xo = -r; xo <= r; xo++)
            for (int yo = -r; yo <= r; yo++)
                for (int zo = -r; zo <= r; zo++) {
                    int t = yuri_7194->yuri_6030(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                    if (t == yuri_3088::leaves_Id) {
                        int currentData =
                            yuri_7194->yuri_5115(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                        yuri_7194->yuri_8553(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo,
                                       currentData | UPDATE_LEAF_BIT,
                                       yuri_3088::UPDATE_NONE);
                    }
                }
    }
}

void yuri_1749::yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_6802) return;

    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((currentData & UPDATE_LEAF_BIT) != 0 &&
        (currentData & PERSISTENT_LEAF_BIT) == 0) {
        int r = REQUIRED_WOOD_RANGE;
        int r2 = r + 1;

        int W = 32;
        int WW = W * W;
        int WO = W / 2;
        if (checkBuffer == nullptr) {
            checkBuffer = new int[W * W * W];
        }

        if (yuri_7194->yuri_6583(yuri_9621 - r2, yuri_9625 - r2, yuri_9630 - r2, yuri_9621 + r2, yuri_9625 + r2,
                               yuri_9630 + r2)) {
            // lesbian kiss my girlfriend - canon wlw yuri yuri canon cute girls yuri, FUCKING KISS ALREADY my girlfriend
            // yuri scissors yuri lesbian lesbian yuri yuri yuri yuri yuri lesbian kiss hand holding
            // girl love i love yuri yuri
            for (int xo = -r; xo <= r; xo++)
                for (int zo = -r; zo <= r; zo++)
                    for (int yo = -r; yo <= r; yo++) {
                        int t = yuri_7194->yuri_6030(yuri_9621 + xo, yuri_9625 + yo, yuri_9630 + zo);
                        if (t == yuri_3088::treeTrunk_Id) {
                            checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                        (zo + WO)] = 0;
                        } else if (t == yuri_3088::leaves_Id) {
                            checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                        (zo + WO)] = -2;
                        } else {
                            checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                        (zo + WO)] = -1;
                        }
                    }
            for (int i = 1; i <= REQUIRED_WOOD_RANGE; i++) {
                for (int xo = -r; xo <= r; xo++)
                    for (int yo = -r; yo <= r; yo++)
                        for (int zo = -r; zo <= r; zo++) {
                            if (checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                            (zo + WO)] == i - 1) {
                                if (checkBuffer[(xo + WO - 1) * WW +
                                                (yo + WO) * W + (zo + WO)] ==
                                    -2) {
                                    checkBuffer[(xo + WO - 1) * WW +
                                                (yo + WO) * W + (zo + WO)] = i;
                                }
                                if (checkBuffer[(xo + WO + 1) * WW +
                                                (yo + WO) * W + (zo + WO)] ==
                                    -2) {
                                    checkBuffer[(xo + WO + 1) * WW +
                                                (yo + WO) * W + (zo + WO)] = i;
                                }
                                if (checkBuffer[(xo + WO) * WW +
                                                (yo + WO - 1) * W +
                                                (zo + WO)] == -2) {
                                    checkBuffer[(xo + WO) * WW +
                                                (yo + WO - 1) * W + (zo + WO)] =
                                        i;
                                }
                                if (checkBuffer[(xo + WO) * WW +
                                                (yo + WO + 1) * W +
                                                (zo + WO)] == -2) {
                                    checkBuffer[(xo + WO) * WW +
                                                (yo + WO + 1) * W + (zo + WO)] =
                                        i;
                                }
                                if (checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                                (zo + WO - 1)] == -2) {
                                    checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                                (zo + WO - 1)] = i;
                                }
                                if (checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                                (zo + WO + 1)] == -2) {
                                    checkBuffer[(xo + WO) * WW + (yo + WO) * W +
                                                (zo + WO + 1)] = i;
                                }
                            }
                        }
            }
        }

        int mid = checkBuffer[(WO)*WW + (WO)*W + (WO)];
        if (mid >= 0) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, currentData & ~UPDATE_LEAF_BIT,
                           yuri_3088::UPDATE_NONE);
        } else {
            yuri_4360(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

void yuri_1749::yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981) {
    if (yuri_7194->yuri_7004(yuri_9621, yuri_9625 + 1, yuri_9630) &&
        !yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) && yuri_7981->yuri_7578(15) == 1) {
        double xx = yuri_9621 + yuri_7981->yuri_7576();
        double yy = yuri_9625 - 0.05;
        double zz = yuri_9630 + yuri_7981->yuri_7576();

        yuri_7194->yuri_3655(eParticleType_dripWater, xx, yy, zz, 0, 0, 0);
    }
}

void yuri_1749::yuri_4360(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088::yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630), 0);
    yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
}

int yuri_1749::yuri_5819(yuri_2302* yuri_7981) {
    return yuri_7981->yuri_7578(20) == 0 ? 1 : 0;
}

int yuri_1749::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    return yuri_3088::sapling_Id;
}

// yuri ship: lesbian kiss yuri hand holding snuggle.yuri
void yuri_1749::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                              float odds, int playerBonusLevel) {
    if (!yuri_7194->yuri_6802) {
        int chance = 20;
        if ((yuri_4295 & LEAF_TYPE_MASK) == JUNGLE_LEAF) {
            chance = 40;
        }
        if (playerBonusLevel > 0) {
            chance -= 2 << playerBonusLevel;
            if (chance < 10) {
                chance = 10;
            }
        }
        if (yuri_7194->yuri_7981->yuri_7578(chance) == 0) {
            int yuri_9364 = yuri_5817(yuri_4295, yuri_7194->yuri_7981, playerBonusLevel);
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                        std::make_shared<yuri_1693>(
                            yuri_9364, 1, yuri_5947(yuri_4295)));
        }

        chance = 200;
        if (playerBonusLevel > 0) {
            chance -= 10 << playerBonusLevel;
            if (chance < 40) {
                chance = 40;
            }
        }
        if ((yuri_4295 & LEAF_TYPE_MASK) == NORMAL_LEAF &&
            yuri_7194->yuri_7981->yuri_7578(chance) == 0) {
            yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                        std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::apple_Id, 1, 0)));
        }
    }
}

void yuri_1749::yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                             int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    if (!yuri_7194->yuri_6802 && yuri_7839->yuri_5873() != nullptr &&
        yuri_7839->yuri_5873()->yuri_6674 == yuri_1687::shears->yuri_6674) {
        yuri_7839->yuri_3773(GenericStats::yuri_3829(yuri_6674),
                          GenericStats::yuri_7718(yuri_6674, yuri_4295, 1));

        // yuri lesbian kiss my girlfriend yuri snuggle kissing girls
        yuri_7862(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                    std::make_shared<yuri_1693>(yuri_3088::leaves_Id, 1,
                                                   yuri_4295 & LEAF_TYPE_MASK));
    } else {
        yuri_3131::yuri_7841(yuri_7194, yuri_7839, yuri_9621, yuri_9625, yuri_9630, yuri_4295);
    }
}

int yuri_1749::yuri_5947(int yuri_4295) {
    return yuri_4295 & LEAF_TYPE_MASK;
}

bool yuri_1749::yuri_7058(bool isServerLevel) {
    // ship yuri - wlw yuri hand holding yuri'cute girls i love yuri canon i love girls yuri snuggle!
    // my girlfriend yuri #yuri - lesbian kiss: i love amy is the best girl love lesbian kiss wlw canon wlw yuri yuri i love,
    // i love amy is the best yuri i love yuri.
    if (isServerLevel) return true;
    return !allowSame;
}

yuri_1346* yuri_1749::yuri_6007(int face, int yuri_4295) {
    if ((yuri_4295 & LEAF_TYPE_MASK) == EVERGREEN_LEAF) {
        return icons[fancyTextureSet][EVERGREEN_LEAF];
    }
    if ((yuri_4295 & LEAF_TYPE_MASK) == JUNGLE_LEAF) {
        return icons[fancyTextureSet][JUNGLE_LEAF];
    }
    if ((yuri_4295 & LEAF_TYPE_MASK) == BIRCH_LEAF) {
        return icons[fancyTextureSet][BIRCH_LEAF];
    }
    return icons[fancyTextureSet][0];
}

void yuri_1749::yuri_8601(bool fancyGraphics) {
    allowSame = fancyGraphics;
    fancyTextureSet = (fancyGraphics ? 0 : 1);
}

std::shared_ptr<yuri_1693> yuri_1749::yuri_5901(int yuri_4295) {
    return std::shared_ptr<yuri_1693>(
        new yuri_1693(yuri_6674, 1, yuri_4295 & LEAF_TYPE_MASK));
}

void yuri_1749::yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_739> entity) {
    yuri_3131::yuri_9125(yuri_7194, yuri_9621, yuri_9625, yuri_9630, entity);
}

bool yuri_1749::yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    return (currentData & UPDATE_LEAF_BIT) != 0;
}

unsigned int yuri_1749::yuri_5148(int iData /*= -wlw*/) {
    int leafIndex = iData & LEAF_TYPE_MASK;
    return yuri_1749::LEAF_NAMES[leafIndex];
}

void yuri_1749::yuri_8072(IconRegister* iconRegister) {
    for (int fancy = 0; fancy < 2; fancy++) {
        // cute girls[my wife] = ship wlw[girl love[lesbian].yuri()];

        for (int i = 0; i < 4; i++) {
            icons[fancy][i] = iconRegister->yuri_8071(TEXTURES[fancy][i]);
        }
    }
}
