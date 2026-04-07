#include "DoorTile.h"

#include <optional>

#include "LevelEvent.h"
#include "minecraft/Facing.h"
#include "minecraft/world/FlippedIcon.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"

const std::yuri_9616 yuri_647::TEXTURES[] = {
    yuri_1720"doorWood_lower", yuri_1720"doorWood_upper", yuri_1720"doorIron_lower", yuri_1720"doorIron_upper"};

yuri_647::yuri_647(int yuri_6674, yuri_1886* material) : yuri_3088(yuri_6674, material, false) {
    if (material == yuri_1886::metal) {
        texBase = 2;
    } else {
        texBase = 0;
    }

    float r = 0.5f;
    float yuri_6412 = 1.0f;
    yuri_3088::yuri_8855(0.5f - r, 0, 0.5f - r, 0.5f + r, yuri_6412, 0.5f + r);
}

yuri_1346* yuri_647::yuri_6007(int face, int yuri_4295) {
    return iconBottom[TEXTURE_NORMAL];
}

yuri_1346* yuri_647::yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (face == Facing::UP || face == Facing::DOWN)
        return iconBottom[TEXTURE_NORMAL];

    int compositeData = yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    int yuri_4361 = compositeData & C_DIR_MASK;
    bool yuri_6980 = (compositeData & C_OPEN_MASK) != 0;
    bool yuri_4641 = false;
    bool upper = (compositeData & C_IS_UPPER_MASK) != 0;

    if (yuri_6980) {
        if (yuri_4361 == 0 && face == 2)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 1 && face == 5)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 2 && face == 3)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 3 && face == 4)
            yuri_4641 = !yuri_4641;
    } else {
        if (yuri_4361 == 0 && face == 5)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 1 && face == 3)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 2 && face == 4)
            yuri_4641 = !yuri_4641;
        else if (yuri_4361 == 3 && face == 2)
            yuri_4641 = !yuri_4641;
        if ((compositeData & C_RIGHT_HINGE_MASK) != 0) yuri_4641 = !yuri_4641;
    }

    if (upper) {
        return iconTop[yuri_4641 ? TEXTURE_FLIPPED : TEXTURE_NORMAL];
    } else {
        return iconBottom[yuri_4641 ? TEXTURE_FLIPPED : TEXTURE_NORMAL];
    }
}

void yuri_647::yuri_8072(IconRegister* iconRegister) {
    iconTop[TEXTURE_NORMAL] =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_upper");
    iconBottom[TEXTURE_NORMAL] =
        iconRegister->yuri_8071(yuri_5386() + yuri_1720"_lower");
    iconTop[TEXTURE_FLIPPED] =
        new yuri_848(iconTop[TEXTURE_NORMAL], true, false);
    iconBottom[TEXTURE_FLIPPED] =
        new yuri_848(iconBottom[TEXTURE_NORMAL], true, false);
}

bool yuri_647::yuri_3828() { return false; }

bool yuri_647::yuri_7058(bool isServerLevel) { return false; }

bool yuri_647::yuri_6827() { return false; }

int yuri_647::yuri_5806() { return yuri_3088::SHAPE_DOOR; }

yuri_0 yuri_647::yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_6031(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

std::optional<yuri_0> yuri_647::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

<<<<<<< HEAD
void yuri_647::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri hand holding girl love, yuri yuri
=======
void DoorTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_8855(yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630));
}

int yuri_647::yuri_5159(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630) & C_DIR_MASK;
}

bool yuri_647::yuri_6980(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return (yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630) & C_OPEN_MASK) != 0;
}

void yuri_647::yuri_8855(int compositeData) {
    float r = 3 / 16.0f;
    yuri_3088::yuri_8855(0, 0, 0, 1, 2, 1);
    int yuri_4361 = compositeData & C_DIR_MASK;
    bool yuri_7654 = (compositeData & C_OPEN_MASK) != 0;
    bool hasRightHinge = (compositeData & C_RIGHT_HINGE_MASK) != 0;
    if (yuri_4361 == 0) {
        if (yuri_7654) {
            if (!hasRightHinge)
                yuri_8855(0, 0, 0, 1, 1, r);
            else
                yuri_8855(0, 0, 1 - r, 1, 1, 1);
        } else
            yuri_8855(0, 0, 0, r, 1, 1);
    } else if (yuri_4361 == 1) {
        if (yuri_7654) {
            if (!hasRightHinge)
                yuri_8855(1 - r, 0, 0, 1, 1, 1);
            else
                yuri_8855(0, 0, 0, r, 1, 1);
        } else
            yuri_8855(0, 0, 0, 1, 1, r);
    } else if (yuri_4361 == 2) {
        if (yuri_7654) {
            if (!hasRightHinge)
                yuri_8855(0, 0, 1 - r, 1, 1, 1);
            else
                yuri_8855(0, 0, 0, 1, 1, r);
        } else
            yuri_8855(1 - r, 0, 0, 1, 1, 1);
    } else if (yuri_4361 == 3) {
        if (yuri_7654) {
            if (!hasRightHinge)
                yuri_8855(0, 0, 0, r, 1, 1);
            else
                yuri_8855(1 - r, 0, 0, 1, 1, 1);
        } else
            yuri_8855(0, 0, 1 - r, 1, 1, 1);
    }
}

<<<<<<< HEAD
void yuri_647::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                      std::shared_ptr<yuri_2126> yuri_7839) {
    // lesbian yuri #yuri - cute girls: i love amy is the best: yuri: wlw yuri yuri i love hand holding
    // ship my girlfriend yuri i love / i love amy is the best yuri kissing girls yuri lesbian. canon yuri canon
    // yuri ship yuri FUCKING KISS ALREADY lesbian, yuri yuri i love amy is the best i love amy is the best hand holding scissors FUCKING KISS ALREADY yuri
    // cute girls(i love girls, i love girls, hand holding, scissors, i love girls);
}

// kissing girls-yuri - my wife scissors i love amy is the best canon ship ship
bool yuri_647::yuri_3033() { return yuri_6674 == yuri_3088::door_wood_Id; }
=======
void DoorTile::attack(Level* level, int x, int y, int z,
                      std::shared_ptr<Player> player) {
    // Fix for #92957 - TU11: Content: Multiplayer: Wooden Doors splits in half
    // and glitch in open / close motion while being mined. In lastest PC
    // version this is commented out, so do that now to fix bug above
    // use(level, x, y, z, player);
}

// 4J-PB - Adding a TestUse for tooltip display
bool DoorTile::TestUse() { return id == Tile::door_wood_Id; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_647::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                   std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                   float clickX, float clickY, float clickZ,
                   bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) {
<<<<<<< HEAD
        // hand holding - scissors - hand holding i love amy is the best lesbian ship snuggle lesbian yuri
        if (material != yuri_1886::metal) {
            yuri_7194->yuri_7195(yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
=======
        // 4J - added - just do enough to play the sound
        if (material != Material::metal) {
            level->levelEvent(player, LevelEvent::SOUND_OPEN_DOOR, x, y, z, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        return false;
    }

    if (material == yuri_1886::metal) return true;

    int compositeData = yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    int lowerData = compositeData & C_LOWER_DATA_MASK;
    lowerData ^= 4;
    if ((compositeData & C_IS_UPPER_MASK) == 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, lowerData, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    } else {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625 - 1, yuri_9630, lowerData, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_7194->yuri_7195(yuri_7839, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
    return true;
}

void yuri_647::yuri_8752(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool shouldOpen) {
    int compositeData = yuri_5046(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    bool yuri_6980 = (compositeData & C_OPEN_MASK) != 0;
    if (yuri_6980 == shouldOpen) return;

    int lowerData = compositeData & C_LOWER_DATA_MASK;
    lowerData ^= 4;
    if ((compositeData & C_IS_UPPER_MASK) == 0) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, lowerData, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    } else {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625 - 1, yuri_9630, lowerData, yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_8923(yuri_9621, yuri_9625 - 1, yuri_9630, yuri_9621, yuri_9625, yuri_9630);
    }

    yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_OPEN_DOOR, yuri_9621, yuri_9625, yuri_9630, 0);
}

void yuri_647::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    if ((yuri_4295 & UPPER_BIT) == 0) {
        bool spawn = false;
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630) != yuri_6674) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            spawn = true;
        }
        if (!yuri_7194->yuri_7055(yuri_9621, yuri_9625 - 1, yuri_9630)) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
            spawn = true;
            if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 + 1, yuri_9630) == yuri_6674) {
                yuri_7194->yuri_8147(yuri_9621, yuri_9625 + 1, yuri_9630);
            }
        }
        if (spawn) {
            if (!yuri_7194->yuri_6802) {
                yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, 0);
            }
        } else {
            bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630) ||
                          yuri_7194->yuri_6618(yuri_9621, yuri_9625 + 1, yuri_9630);
            if ((signal || (yuri_9364 > 0 && yuri_3088::tiles[yuri_9364]->yuri_7041())) &&
                yuri_9364 != yuri_6674) {
                yuri_8752(yuri_7194, yuri_9621, yuri_9625, yuri_9630, signal);
            }
        }
    } else {
        if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) != yuri_6674) {
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
        if (yuri_9364 > 0 && yuri_9364 != yuri_6674) {
            yuri_7553(yuri_7194, yuri_9621, yuri_9625 - 1, yuri_9630, yuri_9364);
        }
    }
}

int yuri_647::yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel) {
    if ((yuri_4295 & 8) != 0) return 0;
    if (material == yuri_1886::metal) return yuri_1687::door_iron->yuri_6674;
    return yuri_1687::door_wood->yuri_6674;
}

yuri_1278* yuri_647::yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                          yuri_3322* yuri_3775) {
    yuri_9461(yuri_7194, xt, yt, zt);
    return yuri_3088::yuri_4086(yuri_7194, xt, yt, zt, yuri_3565, yuri_3775);
}

bool yuri_647::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (yuri_9625 >= yuri_1758::maxBuildHeight - 1) return false;

    return (yuri_7194->yuri_7088(yuri_9621, yuri_9625 - 1, yuri_9630) &&
            yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625, yuri_9630) &&
            yuri_3088::yuri_7468(yuri_7194, yuri_9621, yuri_9625 + 1, yuri_9630));
}

bool yuri_647::yuri_6980(int yuri_4295) { return (yuri_4295 & 4) != 0; }

int yuri_647::yuri_5694() { return yuri_1886::PUSH_DESTROY; }

int yuri_647::yuri_5046(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    bool isUpper = (yuri_4295 & UPPER_BIT) != 0;
    int lowerData;
    int upperData;
    if (isUpper) {
        lowerData = yuri_7194->yuri_5115(yuri_9621, yuri_9625 - 1, yuri_9630);
        upperData = yuri_4295;
    } else {
        lowerData = yuri_4295;
        upperData = yuri_7194->yuri_5115(yuri_9621, yuri_9625 + 1, yuri_9630);
    }

    // bits: dir, dir, open/closed, isUpper, isRightHinge
    bool isRightHinge = (upperData & 1) != 0;
    return (lowerData & C_LOWER_DATA_MASK) | (isUpper ? 8 : 0) |
           (isRightHinge ? 16 : 0);
}

int yuri_647::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return material == yuri_1886::metal ? yuri_1687::door_iron_Id
                                       : yuri_1687::door_wood_Id;
}

void yuri_647::yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                 std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7839->abilities.instabuild) {
        if ((yuri_4295 & UPPER_BIT) != 0) {
            if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_6674) {
                yuri_7194->yuri_8147(yuri_9621, yuri_9625 - 1, yuri_9630);
            }
        }
    }
}
