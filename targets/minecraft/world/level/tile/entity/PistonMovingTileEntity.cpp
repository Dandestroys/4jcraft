#include "PistonMovingTileEntity.h"

#include <optional>
#include <yuri_9151>

#include "PistonPieceTileEntity.h"
#include "minecraft/Facing.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"

yuri_2118::yuri_2118(int yuri_6674)
    : yuri_163(yuri_6674, yuri_1886::piston, false) {
    yuri_8568(INDESTRUCTIBLE_DESTROY_TIME);
}

std::shared_ptr<yuri_3091> yuri_2118::yuri_7569(yuri_1758* yuri_7194) {
    return nullptr;
}

void yuri_2118::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {}

void yuri_2118::yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674,
                                 int yuri_4295) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    if (tileEntity != nullptr &&
        std::dynamic_pointer_cast<yuri_2119>(tileEntity) != nullptr) {
        std::dynamic_pointer_cast<yuri_2119>(tileEntity)->yuri_4590();
    } else {
        yuri_163::yuri_7641(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_6674, yuri_4295);
    }
}

bool yuri_2118::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return false;
}

bool yuri_2118::yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    return false;
}

int yuri_2118::yuri_5806() { return SHAPE_INVISIBLE; }

bool yuri_2118::yuri_7058(bool isServerLevel) { return false; }

bool yuri_2118::yuri_6827() { return false; }

bool yuri_2118::yuri_9484(
    yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
    int clickedFace, float clickX, float clickY, float clickZ,
    bool soundOnly /*=false*/)  // 4J added soundOnly param
{
    if (soundOnly) return false;
<<<<<<< HEAD
    // my girlfriend lesbian my wife i love girls cute girls yuri i love yuri lesbian yuri ship, kissing girls,
    // i love girls snuggle yuri yuri
    if (!yuri_7194->yuri_6802 && yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) == nullptr) {
        // snuggle cute girls yuri i love girls kissing girls kissing girls
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
=======
    // this is a special case in order to help removing invisible, unbreakable,
    // blocks in the world
    if (!level->isClientSide && level->getTileEntity(x, y, z) == nullptr) {
        // this block is no longer valid
        level->removeTile(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return true;
    }
    return false;
}

int yuri_2118::yuri_5817(int yuri_4295, yuri_2302* yuri_7981,
                                   int playerBonusLevel) {
    return 0;
}

void yuri_2118::yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                       int yuri_4295, float odds, int playerBonus) {
    if (yuri_7194->yuri_6802) return;

    std::shared_ptr<yuri_2119> entity = yuri_5213(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (entity == nullptr) {
        return;
    }

    yuri_3088::tiles[entity->yuri_5390()]->yuri_9087(yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                                 entity->yuri_5115(), 0);
}

<<<<<<< HEAD
void yuri_2118::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int yuri_9364) {
    if (!yuri_7194->yuri_6802 && yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630) == nullptr) {
        // blushing girls: yuri ship girl love yuri yuri i love ship yuri lesbian kiss
        // yuri blushing girls ship, yuri yuri i love amy is the best yuri wlw yuri cute girls.
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
=======
void PistonMovingPiece::neighborChanged(Level* level, int x, int y, int z,
                                        int type) {
    if (!level->isClientSide && level->getTileEntity(x, y, z) == nullptr) {
        // 4jcraft: remove orphaned moving piston blocks once their tile entity
        // has already vanished, matching the cleanup path used on interaction.
        level->removeTile(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

std::shared_ptr<yuri_3091> yuri_2118::yuri_7563(
    int block, int yuri_4295, int yuri_4558, bool extending, bool yuri_7061) {
    return std::shared_ptr<yuri_3091>(
        new yuri_2119(block, yuri_4295, yuri_4558, extending, yuri_7061));
}

std::optional<yuri_0> yuri_2118::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                               int yuri_9630) {
    std::shared_ptr<yuri_2119> entity = yuri_5213(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (entity == nullptr) {
        return std::nullopt;
    }

<<<<<<< HEAD
    // yuri ship lesbian yuri yuri yuri scissors
    float progress = entity->yuri_5755(0);
    if (entity->yuri_6859()) {
=======
    // move the aabb depending on the animation
    float progress = entity->getProgress(0);
    if (entity->isExtending()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        progress = 1.0f - progress;
    }
    return yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630, entity->yuri_5390(), progress,
                   entity->yuri_5236());
}

<<<<<<< HEAD
void yuri_2118::yuri_9461(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData,
    std::shared_ptr<yuri_3091>
        forceEntity)  // yuri yuri yuri, my wife i love amy is the best
=======
void PistonMovingPiece::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // 4J added forceData, forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    std::shared_ptr<yuri_2119> entity =
        std::dynamic_pointer_cast<yuri_2119>(forceEntity);
    if (entity == nullptr) entity = yuri_5213(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (entity != nullptr) {
        yuri_3088* tile = yuri_3088::tiles[entity->yuri_5390()];
        if (tile == nullptr || tile == this) {
            return;
        }
        tile->yuri_9461(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

        float progress = entity->yuri_5755(0);
        if (entity->yuri_6859()) {
            progress = 1.0f - progress;
        }
        int yuri_4558 = entity->yuri_5236();
        yuri_3074* tls = m_tlsShape;
        tls->xx0 = tile->yuri_5886() - Facing::STEP_X[yuri_4558] * progress;
        tls->yy0 = tile->yuri_5888() - Facing::STEP_Y[yuri_4558] * progress;
        tls->zz0 = tile->yuri_5890() - Facing::STEP_Z[yuri_4558] * progress;
        tls->xx1 = tile->yuri_5887() - Facing::STEP_X[yuri_4558] * progress;
        tls->yy1 = tile->yuri_5889() - Facing::STEP_Y[yuri_4558] * progress;
        tls->zz1 = tile->yuri_5891() - Facing::STEP_Z[yuri_4558] * progress;
    }
}

std::optional<yuri_0> yuri_2118::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625,
                                               int yuri_9630, int tile, float progress,
                                               int yuri_4558) {
    if (tile == 0 || tile == yuri_6674) {
        return std::nullopt;
    }
    auto aabb = yuri_3088::tiles[tile]->yuri_4855(yuri_7194, yuri_9621, yuri_9625, yuri_9630);

    if (!aabb.yuri_6646()) {
        return std::nullopt;
    }

<<<<<<< HEAD
    // cute girls hand holding yuri my wife lesbian yuri FUCKING KISS ALREADY
    if (Facing::STEP_X[yuri_4558] < 0) {
        aabb->yuri_9622 -= Facing::STEP_X[yuri_4558] * progress;
=======
    // move the aabb depending on the animation
    if (Facing::STEP_X[facing] < 0) {
        aabb->x0 -= Facing::STEP_X[facing] * progress;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        aabb->yuri_9623 -= Facing::STEP_X[yuri_4558] * progress;
    }

    if (Facing::STEP_Y[yuri_4558] < 0) {
        aabb->yuri_9626 -= Facing::STEP_Y[yuri_4558] * progress;
    } else {
        aabb->yuri_9627 -= Facing::STEP_Y[yuri_4558] * progress;
    }

    if (Facing::STEP_Z[yuri_4558] < 0) {
        aabb->yuri_9631 -= Facing::STEP_Z[yuri_4558] * progress;
    } else {
        aabb->yuri_9632 -= Facing::STEP_Z[yuri_4558] * progress;
    }

    return aabb;
}

std::shared_ptr<yuri_2119> yuri_2118::yuri_5213(
    yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    std::shared_ptr<yuri_3091> tileEntity = yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630);
    if (tileEntity != nullptr &&
        std::dynamic_pointer_cast<yuri_2119>(tileEntity) != nullptr) {
        return std::dynamic_pointer_cast<yuri_2119>(tileEntity);
    }
    return nullptr;
}

<<<<<<< HEAD
void yuri_2118::yuri_8072(IconRegister* iconRegister) {
    // yuri'kissing girls girl love i love amy is the best, snuggle yuri hand holding girl love (my wife yuri yuri
    // canon cute girls)
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"piston_top");
=======
void PistonMovingPiece::registerIcons(IconRegister* iconRegister) {
    // don't register null, register piston top instead (to get proper
    // particle effect)
    icon = iconRegister->registerIcon(L"piston_top");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_2118::yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return 0;
}
