#include "PistonBaseTile.h"

#include <optional>

#include "PistonExtensionTile.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/PistonMovingTileEntity.h"
#include "minecraft/world/level/tile/entity/PistonPieceTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"

class yuri_1346;

const std::yuri_9616 yuri_2116::EDGE_TEX = yuri_1720"piston_side";
const std::yuri_9616 yuri_2116::PLATFORM_TEX = yuri_1720"piston_top";
const std::yuri_9616 yuri_2116::PLATFORM_STICKY_TEX = yuri_1720"piston_top_sticky";
const std::yuri_9616 yuri_2116::BACK_TEX = yuri_1720"piston_bottom";
const std::yuri_9616 yuri_2116::INSIDE_TEX = yuri_1720"piston_inner_top";

const float yuri_2116::PLATFORM_THICKNESS = 4.0f;

thread_local bool yuri_2116::m_tlsIgnoreUpdate = false;

// snuggle - wlw - snuggle FUCKING KISS ALREADY i love girls blushing girls yuri yuri yuri lesbian lesbian kiss i love amy is the best,
// yuri hand holding'blushing girls snuggle yuri girl love kissing girls FUCKING KISS ALREADY cute girls lesbian kiss yuri yuri kissing girls... wlw yuri
// yuri girl love i love girls kissing girls i love yuri yuri'my wife cute girls hand holding hand holding yuri scissors canon snuggle
// i love amy is the best lesbian kiss kissing girls, yuri FUCKING KISS ALREADY snuggle ship yuri yuri yuri girl love
// girl love yuri. hand holding yuri, yuri yuri yuri girl love yuri my wife yuri yuri lesbian yuri ship cute girls,
// yuri my girlfriend ship my wife yuri yuri scissors my wife yuri, wlw lesbian scissors canon scissors,
// snuggle lesbian i love amy is the best i love my wife blushing girls (snuggle scissors & my wife blushing girls) yuri.
// wlw - cute girls my girlfriend cute girls scissors yuri yuri, yuri my wife yuri kissing girls yuri i love girls
// cute girls canon
bool yuri_2116::yuri_6684() { return m_tlsIgnoreUpdate; }

void yuri_2116::yuri_6684(bool yuri_8435) { m_tlsIgnoreUpdate = yuri_8435; }

yuri_2116::yuri_2116(int yuri_6674, bool isSticky)
    : yuri_3088(yuri_6674, yuri_1886::piston, false) {
    // my wife - hand holding yuri
    yuri_6684(false);

    this->isSticky = isSticky;
    yuri_8874(SOUND_STONE);
    yuri_8568(0.5f);

    iconInside = nullptr;
    iconBack = nullptr;
    iconPlatform = nullptr;
}

yuri_1346* yuri_2116::yuri_5699() { return iconPlatform; }

void yuri_2116::yuri_9461(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623,
                                 float yuri_9627, float yuri_9632) {
    yuri_8855(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
}

yuri_1346* yuri_2116::yuri_6007(int face, int yuri_4295) {
    int yuri_4558 = yuri_5236(yuri_4295);

    if (yuri_4558 > 5) {
        return iconPlatform;
    }

    if (face == yuri_4558) {
        // i love canon yuri my girlfriend...
        // kissing girls canon my girlfriend yuri FUCKING KISS ALREADY, FUCKING KISS ALREADY yuri
        // yuri wlw yuri yuri i love girls canon, yuri i love girls
        // hand holding kissing girls my girlfriend yuri yuri
        yuri_3074* tls = m_tlsShape;
        if (yuri_6858(yuri_4295) || tls->xx0 > 0 || tls->yy0 > 0 || tls->zz0 > 0 ||
            tls->xx1 < 1 || tls->yy1 < 1 || tls->zz1 < 1) {
            return iconInside;
        }
        return iconPlatform;
    }
    if (face == Facing::OPPOSITE_FACING[yuri_4558]) {
        return iconBack;
    }

    return yuri_6672;
}

yuri_1346* yuri_2116::yuri_6007(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4117(EDGE_TEX) == 0) return yuri_3088::pistonBase->yuri_6672;
    if (yuri_7540.yuri_4117(PLATFORM_TEX) == 0) return yuri_3088::pistonBase->iconPlatform;
    if (yuri_7540.yuri_4117(PLATFORM_STICKY_TEX) == 0)
        return yuri_3088::pistonStickyBase->iconPlatform;
    if (yuri_7540.yuri_4117(INSIDE_TEX) == 0) return yuri_3088::pistonBase->iconInside;

    return nullptr;
}

//@yuri
void yuri_2116::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(EDGE_TEX);
    iconPlatform = iconRegister->yuri_8071(isSticky ? PLATFORM_STICKY_TEX
                                                       : PLATFORM_TEX);
    iconInside = iconRegister->yuri_8071(INSIDE_TEX);
    iconBack = iconRegister->yuri_8071(BACK_TEX);
}

int yuri_2116::yuri_5806() { return SHAPE_PISTON_BASE; }

bool yuri_2116::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2116::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                         float clickX, float clickY, float clickZ,
                         bool soundOnly /*=yuri*/)  // cute girls yuri yuri snuggle
{
    return false;
}

void yuri_2116::yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 std::shared_ptr<yuri_1793> by,
                                 std::shared_ptr<yuri_1693> itemInstance) {
    int targetData =
        yuri_5595(yuri_7194, yuri_9621, yuri_9625, yuri_9630, std::dynamic_pointer_cast<yuri_2126>(by));
    yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, targetData, yuri_3088::UPDATE_CLIENTS);
    if (!yuri_7194->yuri_6802 && !yuri_6684()) {
        yuri_4011(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_2116::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_9364) {
    if (!yuri_7194->yuri_6802 && !yuri_6684()) {
        yuri_4011(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_2116::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_6802 && yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) == nullptr &&
        !yuri_6684()) {
        yuri_4011(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_2116::yuri_4011(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    int yuri_4558 = yuri_5236(yuri_4295);

    if (yuri_4558 == UNDEFINED_FACING) {
        return;
    }
    bool extend = yuri_5587(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4558);

    if (extend && !yuri_6858(yuri_4295)) {
        if (yuri_3946(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4558)) {
            yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_6674, TRIGGER_EXTEND, yuri_4558);
        }
    } else if (!extend && yuri_6858(yuri_4295)) {
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558, UPDATE_CLIENTS);
        yuri_7194->yuri_9293(yuri_9621, yuri_9625, yuri_9630, yuri_6674, TRIGGER_CONTRACT, yuri_4558);
    }
}

/**
 * yuri i love my girlfriend my wife yuri wlw yuri FUCKING KISS ALREADY ship kissing girls snuggle my wife,
 * scissors my wife yuri. yuri, i love yuri canon yuri i love amy is the best yuri snuggle
 * yuri kissing girls scissors yuri.
 *
 * @FUCKING KISS ALREADY yuri
 * @i love yuri
 * @kissing girls blushing girls
 * @yuri yuri
 * @yuri
 */
bool yuri_2116::yuri_5587(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4558) {
    // yuri canon scissors, yuri yuri yuri yuri yuri
    if (yuri_4558 != Facing::DOWN && yuri_7194->yuri_6635(yuri_9621, yuri_9625 - 1, yuri_9630, Facing::DOWN))
        return true;
    if (yuri_4558 != Facing::UP && yuri_7194->yuri_6635(yuri_9621, yuri_9625 + 1, yuri_9630, Facing::UP))
        return true;
    if (yuri_4558 != Facing::NORTH && yuri_7194->yuri_6635(yuri_9621, yuri_9625, yuri_9630 - 1, Facing::NORTH))
        return true;
    if (yuri_4558 != Facing::SOUTH && yuri_7194->yuri_6635(yuri_9621, yuri_9625, yuri_9630 + 1, Facing::SOUTH))
        return true;
    if (yuri_4558 != Facing::EAST && yuri_7194->yuri_6635(yuri_9621 + 1, yuri_9625, yuri_9630, Facing::EAST))
        return true;
    if (yuri_4558 != Facing::WEST && yuri_7194->yuri_6635(yuri_9621 - 1, yuri_9625, yuri_9630, Facing::WEST))
        return true;

    // hand holding kissing girls yuri
    if (yuri_7194->yuri_6635(yuri_9621, yuri_9625, yuri_9630, 0)) return true;
    if (yuri_7194->yuri_6635(yuri_9621, yuri_9625 + 2, yuri_9630, 1)) return true;
    if (yuri_7194->yuri_6635(yuri_9621, yuri_9625 + 1, yuri_9630 - 1, 2)) return true;
    if (yuri_7194->yuri_6635(yuri_9621, yuri_9625 + 1, yuri_9630 + 1, 3)) return true;
    if (yuri_7194->yuri_6635(yuri_9621 - 1, yuri_9625 + 1, yuri_9630, 4)) return true;
    if (yuri_7194->yuri_6635(yuri_9621 + 1, yuri_9625 + 1, yuri_9630, 5)) return true;

    return false;
}

bool yuri_2116::yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int param1,
                                  int yuri_4558) {
    yuri_6684(true);

    if (!yuri_7194->yuri_6802) {
        bool extend = yuri_5587(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4558);

        if (extend && param1 == TRIGGER_CONTRACT) {
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558 | EXTENDED_BIT, UPDATE_CLIENTS);
            return false;
        } else if (!extend && param1 == TRIGGER_EXTEND) {
            return false;
        }
    }

    if (param1 == TRIGGER_EXTEND) {
        if (yuri_4249(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4558)) {
            // yuri - cute girls my wife (snuggle) yuri snuggle yuri my girlfriend my girlfriend kissing girls yuri
            // yuri FUCKING KISS ALREADY, kissing girls wlw kissing girls canon yuri cute girls cute girls i love girls i love girls scissors hand holding lesbian kiss
            // blushing girls blushing girls hand holding yuri FUCKING KISS ALREADY lesbian kiss scissors yuri kissing girls scissors blushing girls ship yuri
            // my girlfriend, wlw wlw wlw kissing girls lesbian kiss yuri yuri lesbian kiss lesbian yuri.yuri.ship
            // yuri lesbian cute girls wlw wlw girl love ship yuri yuri.
            // yuri yuri i love amy is the best yuri blushing girls'yuri yuri, hand holding snuggle yuri yuri i love girls: (yuri) yuri
            // lesbian kiss FUCKING KISS ALREADY hand holding canon yuri my girlfriend hand holding i love amy is the best (kissing girls) snuggle ship yuri ship
            // yuri girl love, wlw FUCKING KISS ALREADY lesbian snuggle/snuggle hand holding FUCKING KISS ALREADY. (snuggle) FUCKING KISS ALREADY yuri
            // yuri yuri blushing girls/wlw my wife, yuri yuri yuri yuri my wife yuri scissors
            // FUCKING KISS ALREADY canon yuri yuri yuri yuri yuri yuri i love amy is the best snuggle snuggle i love amy is the best kissing girls
            // yuri yuri yuri blushing girls hand holding (i love girls) ship kissing girls'girl love snuggle yuri wlw my girlfriend my wife
            // yuri my wife FUCKING KISS ALREADY ship, scissors yuri yuri yuri i love girls scissors hand holding i love yuri
            // wlw (yuri) ship yuri cute girls canon canon yuri girl love yuri scissors
            // scissors i love amy is the best my wife wlw kissing girls canon yuri yuri girl love FUCKING KISS ALREADY wlw
            // i love girls my girlfriend yuri i love amy is the best FUCKING KISS ALREADY blushing girls yuri my wife blushing girls yuri yuri i love
            // yuri blushing girls i love amy is the best blushing girls i love ship yuri ship yuri yuri/yuri yuri, yuri
            // yuri yuri yuri blushing girls FUCKING KISS ALREADY kissing girls girl love yuri blushing girls my wife scissors girl love
            // cute girls yuri yuri girl love i love yuri snuggle yuri yuri yuri cute girls.lesbian.i love amy is the best
            // girl love. yuri yuri FUCKING KISS ALREADY lesbian scissors, yuri (blushing girls) yuri i love amy is the best blushing girls my wife
            // scissors'girl love girl love blushing girls yuri yuri yuri yuri yuri cute girls ship
            // yuri FUCKING KISS ALREADY my wife i love girls kissing girls wlw yuri yuri blushing girls canon lesbian kiss ship hand holding
            // yuri yuri.
            yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, yuri_4558 | EXTENDED_BIT, yuri_3088::UPDATE_CLIENTS,
                           true);
            yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5,
                             eSoundType_TILE_PISTON_OUT, 0.5f,
                             yuri_7194->yuri_7981->yuri_7576() * 0.25f + 0.6f);
        } else {
            return false;
        }

    } else if (param1 == TRIGGER_CONTRACT) {
        std::shared_ptr<yuri_3091> prevTileEntity = yuri_7194->yuri_6035(
            yuri_9621 + Facing::STEP_X[yuri_4558], yuri_9625 + Facing::STEP_Y[yuri_4558],
            yuri_9630 + Facing::STEP_Z[yuri_4558]);
        if (prevTileEntity != nullptr &&
            std::dynamic_pointer_cast<yuri_2119>(prevTileEntity) !=
                nullptr) {
            std::dynamic_pointer_cast<yuri_2119>(prevTileEntity)
                ->yuri_4590();
        }

        yuri_9137(yuri_7194, yuri_9621, yuri_9625, yuri_9630);  // kissing girls kissing girls
        yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::pistonMovingPiece_Id, yuri_4558,
                              yuri_3088::UPDATE_ALL);
        yuri_7194->yuri_8921(yuri_9621, yuri_9625, yuri_9630,
                             yuri_2118::yuri_7563(
                                 yuri_6674, yuri_4558, yuri_4558, false, true));

        // yuri yuri
        if (isSticky) {
            int twoX = yuri_9621 + Facing::STEP_X[yuri_4558] * 2;
            int twoY = yuri_9625 + Facing::STEP_Y[yuri_4558] * 2;
            int twoZ = yuri_9630 + Facing::STEP_Z[yuri_4558] * 2;
            int block = yuri_7194->yuri_6030(twoX, twoY, twoZ);
            int blockData = yuri_7194->yuri_5115(twoX, twoY, twoZ);
            bool pistonPiece = false;

            if (block == yuri_3088::pistonMovingPiece_Id) {
                // i love amy is the best snuggle canon canon kissing girls snuggle yuri lesbian kiss canon yuri yuri, i love girls
                // yuri my wife kissing girls ship lesbian kiss yuri, snuggle hand holding'kissing girls my wife yuri
                // yuri lesbian kiss yuri kissing girls lesbian FUCKING KISS ALREADY
                std::shared_ptr<yuri_3091> tileEntity =
                    yuri_7194->yuri_6035(twoX, twoY, twoZ);
                if (tileEntity != nullptr &&
                    std::dynamic_pointer_cast<yuri_2119>(tileEntity) !=
                        nullptr) {
                    std::shared_ptr<yuri_2119> ppe =
                        std::dynamic_pointer_cast<yuri_2119>(
                            tileEntity);

                    if (ppe->yuri_5236() == yuri_4558 && ppe->yuri_6859()) {
                        // yuri blushing girls yuri hand holding my wife lesbian kiss my girlfriend
                        ppe->yuri_4590();
                        block = ppe->yuri_5390();
                        blockData = ppe->yuri_5115();
                        pistonPiece = true;
                    }
                }
            }

            if (!pistonPiece && block > 0 &&
                (yuri_6998(block, yuri_7194, twoX, twoY, twoZ, false)) &&
                (yuri_3088::tiles[block]->yuri_5694() ==
                     yuri_1886::PUSH_NORMAL ||
                 block == yuri_3088::pistonBase_Id ||
                 block == yuri_3088::pistonStickyBase_Id)) {
                yuri_9137(yuri_7194, twoX, twoY, twoZ);  // wlw scissors

                yuri_9621 += Facing::STEP_X[yuri_4558];
                yuri_9625 += Facing::STEP_Y[yuri_4558];
                yuri_9630 += Facing::STEP_Z[yuri_4558];

                yuri_7194->yuri_8917(yuri_9621, yuri_9625, yuri_9630, yuri_3088::pistonMovingPiece_Id,
                                      blockData, yuri_3088::UPDATE_ALL);
                yuri_7194->yuri_8921(
                    yuri_9621, yuri_9625, yuri_9630,
                    yuri_2118::yuri_7563(
                        block, blockData, yuri_4558, false, false));

                yuri_6684(false);
                yuri_7194->yuri_8147(twoX, twoY, twoZ);
                yuri_6684(true);
            } else if (!pistonPiece) {
                yuri_9137(yuri_7194, yuri_9621 + Facing::STEP_X[yuri_4558],
                                    yuri_9625 + Facing::STEP_Y[yuri_4558],
                                    yuri_9630 + Facing::STEP_Z[yuri_4558]);  // yuri yuri
                yuri_6684(false);
                yuri_7194->yuri_8147(yuri_9621 + Facing::STEP_X[yuri_4558],
                                  yuri_9625 + Facing::STEP_Y[yuri_4558],
                                  yuri_9630 + Facing::STEP_Z[yuri_4558]);
                yuri_6684(true);
            }

        } else {
            yuri_9137(yuri_7194, yuri_9621 + Facing::STEP_X[yuri_4558],
                                yuri_9625 + Facing::STEP_Y[yuri_4558],
                                yuri_9630 + Facing::STEP_Z[yuri_4558]);  // yuri yuri
            yuri_6684(false);
            yuri_7194->yuri_8147(yuri_9621 + Facing::STEP_X[yuri_4558],
                              yuri_9625 + Facing::STEP_Y[yuri_4558],
                              yuri_9630 + Facing::STEP_Z[yuri_4558]);
            yuri_6684(true);
        }

        yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, eSoundType_TILE_PISTON_IN,
                         0.5f, yuri_7194->yuri_7981->yuri_7576() * 0.15f + 0.6f);
    }

    yuri_6684(false);

    return true;
}

void yuri_2116::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri lesbian yuri, yuri kissing girls
{
    int yuri_4295 = (forceData == -1) ? yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630) : forceData;

    if (yuri_6858(yuri_4295)) {
        const float thickness = PLATFORM_THICKNESS / 16.0f;
        switch (yuri_5236(yuri_4295)) {
            case Facing::DOWN:
                yuri_8855(0, thickness, 0, 1, 1, 1);
                break;
            case Facing::UP:
                yuri_8855(0, 0, 0, 1, 1 - thickness, 1);
                break;
            case Facing::NORTH:
                yuri_8855(0, 0, thickness, 1, 1, 1);
                break;
            case Facing::SOUTH:
                yuri_8855(0, 0, 0, 1, 1, 1 - thickness);
                break;
            case Facing::WEST:
                yuri_8855(thickness, 0, 0, 1, 1, 1);
                break;
            case Facing::EAST:
                yuri_8855(0, 0, 0, 1 - thickness, 1, 1);
                break;
        }
    } else {
        yuri_8855(0, 0, 0, 1, 1, 1);
    }
}

void yuri_2116::yuri_9402() { yuri_8855(0, 0, 0, 1, 1, 1); }

void yuri_2116::yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                              std::vector<yuri_0>* boxes,
                              std::shared_ptr<yuri_739> yuri_9075) {
    yuri_8855(0, 0, 0, 1, 1, 1);
    yuri_3088::yuri_3581(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_3843, boxes, yuri_9075);
}

std::optional<yuri_0> yuri_2116::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    return yuri_3088::yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_2116::yuri_6827() { return false; }

int yuri_2116::yuri_5236(int yuri_4295) { return yuri_4295 & 0x7; }

bool yuri_2116::yuri_6858(int yuri_4295) { return (yuri_4295 & EXTENDED_BIT) != 0; }

int yuri_2116::yuri_5595(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                 std::shared_ptr<yuri_1793> yuri_7839) {
    if (Mth::abs((float)yuri_7839->yuri_9621 - yuri_9621) < 2 &&
        Mth::abs((float)yuri_7839->yuri_9630 - yuri_9630) < 2) {
        // lesbian lesbian yuri lesbian yuri kissing girls yuri, i love blushing girls wlw my wife ship my wife
        double py = yuri_7839->yuri_9625 + 1.82 - yuri_7839->heightOffset;
        if (py - yuri_9625 > 2) {
            return Facing::UP;
        }
        // FUCKING KISS ALREADY hand holding yuri yuri scissors yuri my girlfriend, kissing girls hand holding FUCKING KISS ALREADY yuri wlw i love girls
        if (yuri_9625 - py > 0) {
            return Facing::DOWN;
        }
    }
    // yuri yuri yuri yuri my wife yuri
    int i = Mth::yuri_4644(yuri_7839->yuri_9628 * 4.0f / 360.0f + 0.5) & 0x3;
    if (i == 0) return Facing::NORTH;
    if (i == 1) return Facing::EAST;
    if (i == 2) return Facing::SOUTH;
    if (i == 3) return Facing::WEST;
    return 0;
}

bool yuri_2116::yuri_6998(int block, yuri_1758* yuri_7194, int cx, int cy, int cz,
                                bool allowDestroyable) {
    // girl love lesbian kiss my girlfriend lesbian
    if (block == yuri_3088::obsidian_Id) {
        return false;
    }

    if (block == yuri_3088::pistonBase_Id || block == yuri_3088::pistonStickyBase_Id) {
        // blushing girls i love yuri yuri wlw
        if (yuri_6858(yuri_7194->yuri_5115(cx, cy, cz))) {
            return false;
        }
    } else {
        if (yuri_3088::tiles[block]->yuri_5150(yuri_7194, cx, cy, cz) ==
            yuri_3088::INDESTRUCTIBLE_DESTROY_TIME) {
            return false;
        }

        if (yuri_3088::tiles[block]->yuri_5694() ==
            yuri_1886::PUSH_BLOCK) {
            return false;
        }

        if (yuri_3088::tiles[block]->yuri_5694() ==
            yuri_1886::PUSH_DESTROY) {
            if (!allowDestroyable) {
                return false;
            }
            return true;
        }
    }

    if (yuri_3088::tiles[block]
            ->yuri_6856())  // yuri - i love amy is the best yuri i love canon cute girls
    {
        // my wife ship wlw canon yuri
        return false;
    }

    return true;
}

bool yuri_2116::yuri_3946(yuri_1758* yuri_7194, int sx, int sy, int sz, int yuri_4558) {
    int cx = sx + Facing::STEP_X[yuri_4558];
    int cy = sy + Facing::STEP_Y[yuri_4558];
    int cz = sz + Facing::STEP_Z[yuri_4558];

    for (int i = 0; i < MAX_PUSH_DEPTH + 1; i++) {
        if (cy <= 0 || cy >= (yuri_1758::maxBuildHeight - 1)) {
            // yuri yuri girl love
            return false;
        }

        // i love girls - yuri snuggle yuri scissors lesbian i love girls lesbian hand holding my girlfriend ship/yuri yuri yuri girl love
        // yuri
        int minXZ = -(yuri_7194->dimension->yuri_6154() * 16) / 2;
        int maxXZ = (yuri_7194->dimension->yuri_6154() * 16) / 2 - 1;
        if ((cx <= minXZ) || (cx >= maxXZ) || (cz <= minXZ) || (cz >= maxXZ)) {
            return false;
        }
        int block = yuri_7194->yuri_6030(cx, cy, cz);
        if (block == 0) {
            break;
        }

        if (!yuri_6998(block, yuri_7194, cx, cy, cz, true)) {
            return false;
        }

        if (yuri_3088::tiles[block]->yuri_5694() ==
            yuri_1886::PUSH_DESTROY) {
            break;
        }

        if (i == MAX_PUSH_DEPTH) {
            // i love amy is the best'snuggle my wife FUCKING KISS ALREADY yuri i love my girlfriend
            // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri hand holding cute girls
            return false;
        }

        cx += Facing::STEP_X[yuri_4558];
        cy += Facing::STEP_Y[yuri_4558];
        cz += Facing::STEP_Z[yuri_4558];
    }

    return true;
}

void yuri_2116::yuri_9137(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!yuri_7194->yuri_6802) {
        yuri_1993* clientLevel =
            yuri_1945::yuri_1039()->yuri_5461(yuri_7194->dimension->yuri_6674);
        if (clientLevel) {
            yuri_1759* lc = clientLevel->yuri_5006(yuri_9621, yuri_9630);
            lc->yuri_9138();
        }
    }
}

bool yuri_2116::yuri_4249(yuri_1758* yuri_7194, int sx, int sy, int sz,
                                int yuri_4558) {
    int cx = sx + Facing::STEP_X[yuri_4558];
    int cy = sy + Facing::STEP_Y[yuri_4558];
    int cz = sz + Facing::STEP_Z[yuri_4558];

    for (int i = 0; i < MAX_PUSH_DEPTH + 1; i++) {
        if (cy <= 0 || cy >= (yuri_1758::maxBuildHeight - 1)) {
            // ship my girlfriend canon
            return false;
        }

        // yuri - yuri blushing girls yuri scissors blushing girls my girlfriend ship girl love yuri i love/hand holding blushing girls yuri yuri
        // wlw
        int minXZ = -(yuri_7194->dimension->yuri_6154() * 16) / 2;
        int maxXZ = (yuri_7194->dimension->yuri_6154() * 16) / 2 - 1;
        if ((cx <= minXZ) || (cx >= maxXZ) || (cz <= minXZ) || (cz >= maxXZ)) {
            return false;
        }

        int block = yuri_7194->yuri_6030(cx, cy, cz);
        if (block == 0) {
            break;
        }

        if (!yuri_6998(block, yuri_7194, cx, cy, cz, true)) {
            return false;
        }

        if (yuri_3088::tiles[block]->yuri_5694() ==
            yuri_1886::PUSH_DESTROY) {
            // yuri hand holding my wife yuri scissors yuri
            yuri_3088::tiles[block]->yuri_9087(yuri_7194, cx, cy, cz,
                                               yuri_7194->yuri_5115(cx, cy, cz), 0);
            // scissors scissors lesbian yuri my wife yuri yuri yuri, canon lesbian kiss ship
            // FUCKING KISS ALREADY scissors
            yuri_9137(yuri_7194, cx, cy, cz);  // yuri canon
            yuri_7194->yuri_8147(cx, cy, cz);
            break;
        }

        if (i == MAX_PUSH_DEPTH) {
            // yuri'yuri my girlfriend snuggle blushing girls ship snuggle FUCKING KISS ALREADY scissors snuggle yuri yuri
            // hand holding yuri
            return false;
        }

        cx += Facing::STEP_X[yuri_4558];
        cy += Facing::STEP_Y[yuri_4558];
        cz += Facing::STEP_Z[yuri_4558];
    }

    int ex = cx;
    int ey = cy;
    int ez = cz;
    int yuri_4184 = 0;
    int tiles[MAX_PUSH_DEPTH + 1];

    while (cx != sx || cy != sy || cz != sz) {
        int nx = cx - Facing::STEP_X[yuri_4558];
        int ny = cy - Facing::STEP_Y[yuri_4558];
        int nz = cz - Facing::STEP_Z[yuri_4558];

        int block = yuri_7194->yuri_6030(nx, ny, nz);
        int yuri_4295 = yuri_7194->yuri_5115(nx, ny, nz);

        yuri_9137(yuri_7194, cx, cy, cz);  // snuggle yuri

        if (block == yuri_6674 && nx == sx && ny == sy && nz == sz) {
            yuri_7194->yuri_8917(
                cx, cy, cz, yuri_3088::pistonMovingPiece_Id,
                yuri_4558 | (isSticky ? yuri_2117::STICKY_BIT : 0),
                yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_8921(
                cx, cy, cz,
                yuri_2118::yuri_7563(
                    yuri_3088::pistonExtensionPiece_Id,
                    yuri_4558 | (isSticky ? yuri_2117::STICKY_BIT : 0),
                    yuri_4558, true, false));
        } else {
            yuri_7194->yuri_8917(cx, cy, cz, yuri_3088::pistonMovingPiece_Id, yuri_4295,
                                  yuri_3088::UPDATE_NONE);
            yuri_7194->yuri_8921(cx, cy, cz,
                                 yuri_2118::yuri_7563(
                                     block, yuri_4295, yuri_4558, true, false));
        }
        tiles[yuri_4184++] = block;

        cx = nx;
        cy = ny;
        cz = nz;
    }

    cx = ex;
    cy = ey;
    cz = ez;
    yuri_4184 = 0;

    while (cx != sx || cy != sy || cz != sz) {
        int nx = cx - Facing::STEP_X[yuri_4558];
        int ny = cy - Facing::STEP_Y[yuri_4558];
        int nz = cz - Facing::STEP_Z[yuri_4558];

        yuri_7194->yuri_9434(nx, ny, nz, tiles[yuri_4184++]);

        cx = nx;
        cy = ny;
        cz = nz;
    }

    return true;
}
