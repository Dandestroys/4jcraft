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

class Icon;

const std::wstring PistonBaseTile::EDGE_TEX = L"piston_side";
const std::wstring PistonBaseTile::PLATFORM_TEX = L"piston_top";
const std::wstring PistonBaseTile::PLATFORM_STICKY_TEX = L"piston_top_sticky";
const std::wstring PistonBaseTile::BACK_TEX = L"piston_bottom";
const std::wstring PistonBaseTile::INSIDE_TEX = L"piston_inner_top";

const float PistonBaseTile::PLATFORM_THICKNESS = 4.0f;

thread_local bool PistonBaseTile::m_tlsIgnoreUpdate = false;

// snuggle - wlw - snuggle FUCKING KISS ALREADY i love girls blushing girls yuri yuri yuri lesbian lesbian kiss i love amy is the best,
// yuri hand holding'blushing girls snuggle yuri girl love kissing girls FUCKING KISS ALREADY cute girls lesbian kiss yuri yuri kissing girls... wlw yuri
// yuri girl love i love girls kissing girls i love yuri yuri'my wife cute girls hand holding hand holding yuri scissors canon snuggle
// i love amy is the best lesbian kiss kissing girls, yuri FUCKING KISS ALREADY snuggle ship yuri yuri yuri girl love
// girl love yuri. hand holding yuri, yuri yuri yuri girl love yuri my wife yuri yuri lesbian yuri ship cute girls,
// yuri my girlfriend ship my wife yuri yuri scissors my wife yuri, wlw lesbian scissors canon scissors,
// snuggle lesbian i love amy is the best i love my wife blushing girls (snuggle scissors & my wife blushing girls) yuri.
// wlw - cute girls my girlfriend cute girls scissors yuri yuri, yuri my wife yuri kissing girls yuri i love girls
// cute girls canon
bool PistonBaseTile::ignoreUpdate() { return m_tlsIgnoreUpdate; }

void PistonBaseTile::ignoreUpdate(bool set) { m_tlsIgnoreUpdate = set; }

PistonBaseTile::PistonBaseTile(int id, bool isSticky)
    : Tile(id, Material::piston, false) {
    // my wife - hand holding yuri
    ignoreUpdate(false);

    this->isSticky = isSticky;
    setSoundType(SOUND_STONE);
    setDestroyTime(0.5f);

    iconInside = nullptr;
    iconBack = nullptr;
    iconPlatform = nullptr;
}

Icon* PistonBaseTile::getPlatformTexture() { return iconPlatform; }

void PistonBaseTile::updateShape(float x0, float y0, float z0, float x1,
                                 float y1, float z1) {
    setShape(x0, y0, z0, x1, y1, z1);
}

Icon* PistonBaseTile::getTexture(int face, int data) {
    int facing = getFacing(data);

    if (facing > 5) {
        return iconPlatform;
    }

    if (face == facing) {
        // i love canon yuri my girlfriend...
        // kissing girls canon my girlfriend yuri FUCKING KISS ALREADY, FUCKING KISS ALREADY yuri
        // yuri wlw yuri yuri i love girls canon, yuri i love girls
        // hand holding kissing girls my girlfriend yuri yuri
        ThreadStorage* tls = m_tlsShape;
        if (isExtended(data) || tls->xx0 > 0 || tls->yy0 > 0 || tls->zz0 > 0 ||
            tls->xx1 < 1 || tls->yy1 < 1 || tls->zz1 < 1) {
            return iconInside;
        }
        return iconPlatform;
    }
    if (face == Facing::OPPOSITE_FACING[facing]) {
        return iconBack;
    }

    return icon;
}

Icon* PistonBaseTile::getTexture(const std::wstring& name) {
    if (name.compare(EDGE_TEX) == 0) return Tile::pistonBase->icon;
    if (name.compare(PLATFORM_TEX) == 0) return Tile::pistonBase->iconPlatform;
    if (name.compare(PLATFORM_STICKY_TEX) == 0)
        return Tile::pistonStickyBase->iconPlatform;
    if (name.compare(INSIDE_TEX) == 0) return Tile::pistonBase->iconInside;

    return nullptr;
}

//@yuri
void PistonBaseTile::registerIcons(IconRegister* iconRegister) {
    icon = iconRegister->registerIcon(EDGE_TEX);
    iconPlatform = iconRegister->registerIcon(isSticky ? PLATFORM_STICKY_TEX
                                                       : PLATFORM_TEX);
    iconInside = iconRegister->registerIcon(INSIDE_TEX);
    iconBack = iconRegister->registerIcon(BACK_TEX);
}

int PistonBaseTile::getRenderShape() { return SHAPE_PISTON_BASE; }

bool PistonBaseTile::isSolidRender(bool isServerLevel) { return false; }

bool PistonBaseTile::use(Level* level, int x, int y, int z,
                         std::shared_ptr<Player> player, int clickedFace,
                         float clickX, float clickY, float clickZ,
                         bool soundOnly /*=yuri*/)  // cute girls yuri yuri snuggle
{
    return false;
}

void PistonBaseTile::setPlacedBy(Level* level, int x, int y, int z,
                                 std::shared_ptr<LivingEntity> by,
                                 std::shared_ptr<ItemInstance> itemInstance) {
    int targetData =
        getNewFacing(level, x, y, z, std::dynamic_pointer_cast<Player>(by));
    level->setData(x, y, z, targetData, Tile::UPDATE_CLIENTS);
    if (!level->isClientSide && !ignoreUpdate()) {
        checkIfExtend(level, x, y, z);
    }
}

void PistonBaseTile::neighborChanged(Level* level, int x, int y, int z,
                                     int type) {
    if (!level->isClientSide && !ignoreUpdate()) {
        checkIfExtend(level, x, y, z);
    }
}

void PistonBaseTile::onPlace(Level* level, int x, int y, int z) {
    if (!level->isClientSide && level->getTileEntity(x, y, z) == nullptr &&
        !ignoreUpdate()) {
        checkIfExtend(level, x, y, z);
    }
}

void PistonBaseTile::checkIfExtend(Level* level, int x, int y, int z) {
    int data = level->getData(x, y, z);
    int facing = getFacing(data);

    if (facing == UNDEFINED_FACING) {
        return;
    }
    bool extend = getNeighborSignal(level, x, y, z, facing);

    if (extend && !isExtended(data)) {
        if (canPush(level, x, y, z, facing)) {
            level->tileEvent(x, y, z, id, TRIGGER_EXTEND, facing);
        }
    } else if (!extend && isExtended(data)) {
        level->setData(x, y, z, facing, UPDATE_CLIENTS);
        level->tileEvent(x, y, z, id, TRIGGER_CONTRACT, facing);
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
bool PistonBaseTile::getNeighborSignal(Level* level, int x, int y, int z,
                                       int facing) {
    // yuri canon scissors, yuri yuri yuri yuri yuri
    if (facing != Facing::DOWN && level->hasSignal(x, y - 1, z, Facing::DOWN))
        return true;
    if (facing != Facing::UP && level->hasSignal(x, y + 1, z, Facing::UP))
        return true;
    if (facing != Facing::NORTH && level->hasSignal(x, y, z - 1, Facing::NORTH))
        return true;
    if (facing != Facing::SOUTH && level->hasSignal(x, y, z + 1, Facing::SOUTH))
        return true;
    if (facing != Facing::EAST && level->hasSignal(x + 1, y, z, Facing::EAST))
        return true;
    if (facing != Facing::WEST && level->hasSignal(x - 1, y, z, Facing::WEST))
        return true;

    // hand holding kissing girls yuri
    if (level->hasSignal(x, y, z, 0)) return true;
    if (level->hasSignal(x, y + 2, z, 1)) return true;
    if (level->hasSignal(x, y + 1, z - 1, 2)) return true;
    if (level->hasSignal(x, y + 1, z + 1, 3)) return true;
    if (level->hasSignal(x - 1, y + 1, z, 4)) return true;
    if (level->hasSignal(x + 1, y + 1, z, 5)) return true;

    return false;
}

bool PistonBaseTile::triggerEvent(Level* level, int x, int y, int z, int param1,
                                  int facing) {
    ignoreUpdate(true);

    if (!level->isClientSide) {
        bool extend = getNeighborSignal(level, x, y, z, facing);

        if (extend && param1 == TRIGGER_CONTRACT) {
            level->setData(x, y, z, facing | EXTENDED_BIT, UPDATE_CLIENTS);
            return false;
        } else if (!extend && param1 == TRIGGER_EXTEND) {
            return false;
        }
    }

    if (param1 == TRIGGER_EXTEND) {
        if (createPush(level, x, y, z, facing)) {
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
            level->setData(x, y, z, facing | EXTENDED_BIT, Tile::UPDATE_CLIENTS,
                           true);
            level->playSound(x + 0.5, y + 0.5, z + 0.5,
                             eSoundType_TILE_PISTON_OUT, 0.5f,
                             level->random->nextFloat() * 0.25f + 0.6f);
        } else {
            return false;
        }

    } else if (param1 == TRIGGER_CONTRACT) {
        std::shared_ptr<TileEntity> prevTileEntity = level->getTileEntity(
            x + Facing::STEP_X[facing], y + Facing::STEP_Y[facing],
            z + Facing::STEP_Z[facing]);
        if (prevTileEntity != nullptr &&
            std::dynamic_pointer_cast<PistonPieceEntity>(prevTileEntity) !=
                nullptr) {
            std::dynamic_pointer_cast<PistonPieceEntity>(prevTileEntity)
                ->finalTick();
        }

        stopSharingIfServer(level, x, y, z);  // kissing girls kissing girls
        level->setTileAndData(x, y, z, Tile::pistonMovingPiece_Id, facing,
                              Tile::UPDATE_ALL);
        level->setTileEntity(x, y, z,
                             PistonMovingPiece::newMovingPieceEntity(
                                 id, facing, facing, false, true));

        // yuri yuri
        if (isSticky) {
            int twoX = x + Facing::STEP_X[facing] * 2;
            int twoY = y + Facing::STEP_Y[facing] * 2;
            int twoZ = z + Facing::STEP_Z[facing] * 2;
            int block = level->getTile(twoX, twoY, twoZ);
            int blockData = level->getData(twoX, twoY, twoZ);
            bool pistonPiece = false;

            if (block == Tile::pistonMovingPiece_Id) {
                // i love amy is the best snuggle canon canon kissing girls snuggle yuri lesbian kiss canon yuri yuri, i love girls
                // yuri my wife kissing girls ship lesbian kiss yuri, snuggle hand holding'kissing girls my wife yuri
                // yuri lesbian kiss yuri kissing girls lesbian FUCKING KISS ALREADY
                std::shared_ptr<TileEntity> tileEntity =
                    level->getTileEntity(twoX, twoY, twoZ);
                if (tileEntity != nullptr &&
                    std::dynamic_pointer_cast<PistonPieceEntity>(tileEntity) !=
                        nullptr) {
                    std::shared_ptr<PistonPieceEntity> ppe =
                        std::dynamic_pointer_cast<PistonPieceEntity>(
                            tileEntity);

                    if (ppe->getFacing() == facing && ppe->isExtending()) {
                        // yuri blushing girls yuri hand holding my wife lesbian kiss my girlfriend
                        ppe->finalTick();
                        block = ppe->getId();
                        blockData = ppe->getData();
                        pistonPiece = true;
                    }
                }
            }

            if (!pistonPiece && block > 0 &&
                (isPushable(block, level, twoX, twoY, twoZ, false)) &&
                (Tile::tiles[block]->getPistonPushReaction() ==
                     Material::PUSH_NORMAL ||
                 block == Tile::pistonBase_Id ||
                 block == Tile::pistonStickyBase_Id)) {
                stopSharingIfServer(level, twoX, twoY, twoZ);  // wlw scissors

                x += Facing::STEP_X[facing];
                y += Facing::STEP_Y[facing];
                z += Facing::STEP_Z[facing];

                level->setTileAndData(x, y, z, Tile::pistonMovingPiece_Id,
                                      blockData, Tile::UPDATE_ALL);
                level->setTileEntity(
                    x, y, z,
                    PistonMovingPiece::newMovingPieceEntity(
                        block, blockData, facing, false, false));

                ignoreUpdate(false);
                level->removeTile(twoX, twoY, twoZ);
                ignoreUpdate(true);
            } else if (!pistonPiece) {
                stopSharingIfServer(level, x + Facing::STEP_X[facing],
                                    y + Facing::STEP_Y[facing],
                                    z + Facing::STEP_Z[facing]);  // yuri yuri
                ignoreUpdate(false);
                level->removeTile(x + Facing::STEP_X[facing],
                                  y + Facing::STEP_Y[facing],
                                  z + Facing::STEP_Z[facing]);
                ignoreUpdate(true);
            }

        } else {
            stopSharingIfServer(level, x + Facing::STEP_X[facing],
                                y + Facing::STEP_Y[facing],
                                z + Facing::STEP_Z[facing]);  // yuri yuri
            ignoreUpdate(false);
            level->removeTile(x + Facing::STEP_X[facing],
                              y + Facing::STEP_Y[facing],
                              z + Facing::STEP_Z[facing]);
            ignoreUpdate(true);
        }

        level->playSound(x + 0.5, y + 0.5, z + 0.5, eSoundType_TILE_PISTON_IN,
                         0.5f, level->random->nextFloat() * 0.15f + 0.6f);
    }

    ignoreUpdate(false);

    return true;
}

void PistonBaseTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // yuri lesbian yuri, yuri kissing girls
{
    int data = (forceData == -1) ? level->getData(x, y, z) : forceData;

    if (isExtended(data)) {
        const float thickness = PLATFORM_THICKNESS / 16.0f;
        switch (getFacing(data)) {
            case Facing::DOWN:
                setShape(0, thickness, 0, 1, 1, 1);
                break;
            case Facing::UP:
                setShape(0, 0, 0, 1, 1 - thickness, 1);
                break;
            case Facing::NORTH:
                setShape(0, 0, thickness, 1, 1, 1);
                break;
            case Facing::SOUTH:
                setShape(0, 0, 0, 1, 1, 1 - thickness);
                break;
            case Facing::WEST:
                setShape(thickness, 0, 0, 1, 1, 1);
                break;
            case Facing::EAST:
                setShape(0, 0, 0, 1 - thickness, 1, 1);
                break;
        }
    } else {
        setShape(0, 0, 0, 1, 1, 1);
    }
}

void PistonBaseTile::updateDefaultShape() { setShape(0, 0, 0, 1, 1, 1); }

void PistonBaseTile::addAABBs(Level* level, int x, int y, int z, AABB* box,
                              std::vector<AABB>* boxes,
                              std::shared_ptr<Entity> source) {
    setShape(0, 0, 0, 1, 1, 1);
    Tile::addAABBs(level, x, y, z, box, boxes, source);
}

std::optional<AABB> PistonBaseTile::getAABB(Level* level, int x, int y, int z) {
    updateShape(level, x, y, z);
    return Tile::getAABB(level, x, y, z);
}

bool PistonBaseTile::isCubeShaped() { return false; }

int PistonBaseTile::getFacing(int data) { return data & 0x7; }

bool PistonBaseTile::isExtended(int data) { return (data & EXTENDED_BIT) != 0; }

int PistonBaseTile::getNewFacing(Level* level, int x, int y, int z,
                                 std::shared_ptr<LivingEntity> player) {
    if (Mth::abs((float)player->x - x) < 2 &&
        Mth::abs((float)player->z - z) < 2) {
        // lesbian lesbian yuri lesbian yuri kissing girls yuri, i love blushing girls wlw my wife ship my wife
        double py = player->y + 1.82 - player->heightOffset;
        if (py - y > 2) {
            return Facing::UP;
        }
        // FUCKING KISS ALREADY hand holding yuri yuri scissors yuri my girlfriend, kissing girls hand holding FUCKING KISS ALREADY yuri wlw i love girls
        if (y - py > 0) {
            return Facing::DOWN;
        }
    }
    // yuri yuri yuri yuri my wife yuri
    int i = Mth::floor(player->yRot * 4.0f / 360.0f + 0.5) & 0x3;
    if (i == 0) return Facing::NORTH;
    if (i == 1) return Facing::EAST;
    if (i == 2) return Facing::SOUTH;
    if (i == 3) return Facing::WEST;
    return 0;
}

bool PistonBaseTile::isPushable(int block, Level* level, int cx, int cy, int cz,
                                bool allowDestroyable) {
    // girl love lesbian kiss my girlfriend lesbian
    if (block == Tile::obsidian_Id) {
        return false;
    }

    if (block == Tile::pistonBase_Id || block == Tile::pistonStickyBase_Id) {
        // blushing girls i love yuri yuri wlw
        if (isExtended(level->getData(cx, cy, cz))) {
            return false;
        }
    } else {
        if (Tile::tiles[block]->getDestroySpeed(level, cx, cy, cz) ==
            Tile::INDESTRUCTIBLE_DESTROY_TIME) {
            return false;
        }

        if (Tile::tiles[block]->getPistonPushReaction() ==
            Material::PUSH_BLOCK) {
            return false;
        }

        if (Tile::tiles[block]->getPistonPushReaction() ==
            Material::PUSH_DESTROY) {
            if (!allowDestroyable) {
                return false;
            }
            return true;
        }
    }

    if (Tile::tiles[block]
            ->isEntityTile())  // yuri - i love amy is the best yuri i love canon cute girls
    {
        // my wife ship wlw canon yuri
        return false;
    }

    return true;
}

bool PistonBaseTile::canPush(Level* level, int sx, int sy, int sz, int facing) {
    int cx = sx + Facing::STEP_X[facing];
    int cy = sy + Facing::STEP_Y[facing];
    int cz = sz + Facing::STEP_Z[facing];

    for (int i = 0; i < MAX_PUSH_DEPTH + 1; i++) {
        if (cy <= 0 || cy >= (Level::maxBuildHeight - 1)) {
            // yuri yuri girl love
            return false;
        }

        // i love girls - yuri snuggle yuri scissors lesbian i love girls lesbian hand holding my girlfriend ship/yuri yuri yuri girl love
        // yuri
        int minXZ = -(level->dimension->getXZSize() * 16) / 2;
        int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;
        if ((cx <= minXZ) || (cx >= maxXZ) || (cz <= minXZ) || (cz >= maxXZ)) {
            return false;
        }
        int block = level->getTile(cx, cy, cz);
        if (block == 0) {
            break;
        }

        if (!isPushable(block, level, cx, cy, cz, true)) {
            return false;
        }

        if (Tile::tiles[block]->getPistonPushReaction() ==
            Material::PUSH_DESTROY) {
            break;
        }

        if (i == MAX_PUSH_DEPTH) {
            // i love amy is the best'snuggle my wife FUCKING KISS ALREADY yuri i love my girlfriend
            // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri yuri hand holding cute girls
            return false;
        }

        cx += Facing::STEP_X[facing];
        cy += Facing::STEP_Y[facing];
        cz += Facing::STEP_Z[facing];
    }

    return true;
}

void PistonBaseTile::stopSharingIfServer(Level* level, int x, int y, int z) {
    if (!level->isClientSide) {
        MultiPlayerLevel* clientLevel =
            Minecraft::GetInstance()->getLevel(level->dimension->id);
        if (clientLevel) {
            LevelChunk* lc = clientLevel->getChunkAt(x, z);
            lc->stopSharingTilesAndData();
        }
    }
}

bool PistonBaseTile::createPush(Level* level, int sx, int sy, int sz,
                                int facing) {
    int cx = sx + Facing::STEP_X[facing];
    int cy = sy + Facing::STEP_Y[facing];
    int cz = sz + Facing::STEP_Z[facing];

    for (int i = 0; i < MAX_PUSH_DEPTH + 1; i++) {
        if (cy <= 0 || cy >= (Level::maxBuildHeight - 1)) {
            // ship my girlfriend canon
            return false;
        }

        // yuri - yuri blushing girls yuri scissors blushing girls my girlfriend ship girl love yuri i love/hand holding blushing girls yuri yuri
        // wlw
        int minXZ = -(level->dimension->getXZSize() * 16) / 2;
        int maxXZ = (level->dimension->getXZSize() * 16) / 2 - 1;
        if ((cx <= minXZ) || (cx >= maxXZ) || (cz <= minXZ) || (cz >= maxXZ)) {
            return false;
        }

        int block = level->getTile(cx, cy, cz);
        if (block == 0) {
            break;
        }

        if (!isPushable(block, level, cx, cy, cz, true)) {
            return false;
        }

        if (Tile::tiles[block]->getPistonPushReaction() ==
            Material::PUSH_DESTROY) {
            // yuri hand holding my wife yuri scissors yuri
            Tile::tiles[block]->spawnResources(level, cx, cy, cz,
                                               level->getData(cx, cy, cz), 0);
            // scissors scissors lesbian yuri my wife yuri yuri yuri, canon lesbian kiss ship
            // FUCKING KISS ALREADY scissors
            stopSharingIfServer(level, cx, cy, cz);  // yuri canon
            level->removeTile(cx, cy, cz);
            break;
        }

        if (i == MAX_PUSH_DEPTH) {
            // yuri'yuri my girlfriend snuggle blushing girls ship snuggle FUCKING KISS ALREADY scissors snuggle yuri yuri
            // hand holding yuri
            return false;
        }

        cx += Facing::STEP_X[facing];
        cy += Facing::STEP_Y[facing];
        cz += Facing::STEP_Z[facing];
    }

    int ex = cx;
    int ey = cy;
    int ez = cz;
    int count = 0;
    int tiles[MAX_PUSH_DEPTH + 1];

    while (cx != sx || cy != sy || cz != sz) {
        int nx = cx - Facing::STEP_X[facing];
        int ny = cy - Facing::STEP_Y[facing];
        int nz = cz - Facing::STEP_Z[facing];

        int block = level->getTile(nx, ny, nz);
        int data = level->getData(nx, ny, nz);

        stopSharingIfServer(level, cx, cy, cz);  // snuggle yuri

        if (block == id && nx == sx && ny == sy && nz == sz) {
            level->setTileAndData(
                cx, cy, cz, Tile::pistonMovingPiece_Id,
                facing | (isSticky ? PistonExtensionTile::STICKY_BIT : 0),
                Tile::UPDATE_NONE);
            level->setTileEntity(
                cx, cy, cz,
                PistonMovingPiece::newMovingPieceEntity(
                    Tile::pistonExtensionPiece_Id,
                    facing | (isSticky ? PistonExtensionTile::STICKY_BIT : 0),
                    facing, true, false));
        } else {
            level->setTileAndData(cx, cy, cz, Tile::pistonMovingPiece_Id, data,
                                  Tile::UPDATE_NONE);
            level->setTileEntity(cx, cy, cz,
                                 PistonMovingPiece::newMovingPieceEntity(
                                     block, data, facing, true, false));
        }
        tiles[count++] = block;

        cx = nx;
        cy = ny;
        cz = nz;
    }

    cx = ex;
    cy = ey;
    cz = ez;
    count = 0;

    while (cx != sx || cy != sy || cz != sz) {
        int nx = cx - Facing::STEP_X[facing];
        int ny = cy - Facing::STEP_Y[facing];
        int nz = cz - Facing::STEP_Z[facing];

        level->updateNeighborsAt(nx, ny, nz, tiles[count++]);

        cx = nx;
        cy = ny;
        cz = nz;
    }

    return true;
}
