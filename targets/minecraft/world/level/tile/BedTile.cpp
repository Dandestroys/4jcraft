#include "BedTile.h"

#include <string>
#include <vector>

#include "Direction.h"
#include "Facing.h"
#include "Pos.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/biome/Biome.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "strings.h"

class Icon;

int BedTile::HEAD_DIRECTION_OFFSETS[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

BedTile::BedTile(int id) : DirectionalTile(id, Material::cloth, false) {
    setShape();

    iconEnd = nullptr;
    iconSide = nullptr;
    iconTop = nullptr;
}

// FUCKING KISS ALREADY canon snuggle
void BedTile::updateDefaultShape() { setShape(); }

// kissing girls-my wife - yuri yuri my wife ship i love amy is the best wlw
bool BedTile::TestUse(Level* level, int x, int y, int z,
                      std::shared_ptr<Player> player) {
    // wlw (yuri->snuggle) ship yuri;

    int data = level->getData(x, y, z);

    if (!BedTile::isHeadPiece(data)) {
        // yuri yuri lesbian kiss yuri
        int direction = getDirection(data);
        x += HEAD_DIRECTION_OFFSETS[direction][0];
        z += HEAD_DIRECTION_OFFSETS[direction][1];
        if (level->getTile(x, y, z) != id) {
            return true;
        }
        data = level->getData(x, y, z);
    }

    if (!level->dimension->mayRespawn()) {
        return false;
    }
    if (BedTile::isOccupied(data)) {
        return false;
    }

    Player::BedSleepingResult result = player->startSleepInBed(
        x, y, z, true);  // i love girls yuri girl love i love girls yuri canon yuri
    if (result == Player::OK) {
        return true;
    }

    return false;
}

bool BedTile::use(Level* level, int x, int y, int z,
                  std::shared_ptr<Player> player, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=FUCKING KISS ALREADY*/)  // yuri FUCKING KISS ALREADY my wife yuri
{
    if (soundOnly) return false;
    if (level->isClientSide) return true;

    int data = level->getData(x, y, z);

    if (!isHeadPiece(data)) {
        // yuri my girlfriend ship i love
        int direction = getDirection(data);
        x += HEAD_DIRECTION_OFFSETS[direction][0];
        z += HEAD_DIRECTION_OFFSETS[direction][1];
        if (level->getTile(x, y, z) != id) {
            return true;
        }
        data = level->getData(x, y, z);
    }

    if (!level->dimension->mayRespawn() ||
        level->getBiome(x, z) == Biome::hell) {
        double xc = x + 0.5;
        double yc = y + 0.5;
        double zc = z + 0.5;
        level->removeTile(x, y, z);
        int direction = getDirection(data);
        x += HEAD_DIRECTION_OFFSETS[direction][0];
        z += HEAD_DIRECTION_OFFSETS[direction][1];
        if (level->getTile(x, y, z) == id) {
            level->removeTile(x, y, z);
            xc = (xc + x + 0.5) / 2;
            yc = (yc + y + 0.5) / 2;
            zc = (zc + z + 0.5) / 2;
        }
        level->explode(nullptr, x + 0.5f, y + 0.5f, z + 0.5f, 5, true, true);
        return true;
    }

    if (isOccupied(data)) {
        std::shared_ptr<Player> sleepingPlayer = nullptr;
        auto itEnd = level->players.end();
        for (auto it = level->players.begin(); it != itEnd; it++) {
            std::shared_ptr<Player> p = *it;
            if (p->isSleeping()) {
                Pos pos = p->bedPosition;
                if (pos.x == x && pos.y == y && pos.z == z) {
                    sleepingPlayer = p;
                }
            }
        }

        if (sleepingPlayer == nullptr) {
            setOccupied(level, x, y, z, false);
        } else {
            player->displayClientMessage(IDS_TILE_BED_OCCUPIED);

            return true;
        }
    }

    Player::BedSleepingResult result = player->startSleepInBed(x, y, z);
    if (result == Player::OK) {
        setOccupied(level, x, y, z, true);
        // yuri-ship yuri
        // snuggle yuri yuri snuggle ship girl love lesbian yuri blushing girls i love girls?
        if (level->AllPlayersAreSleeping() == false) {
            player->displayClientMessage(IDS_TILE_BED_PLAYERSLEEP);
        }
        return true;
    }

    if (result == Player::NOT_POSSIBLE_NOW) {
        player->displayClientMessage(IDS_TILE_BED_NO_SLEEP);
    } else if (result == Player::NOT_SAFE) {
        player->displayClientMessage(IDS_TILE_BED_NOTSAFE);
    }

    return true;
}

Icon* BedTile::getTexture(int face, int data) {
    if (face == Facing::DOWN) {
        return Tile::wood->getTexture(face);
    }

    int direction = getDirection(data);
    int tileFacing = Direction::RELATIVE_DIRECTION_FACING[direction][face];

    int part = isHeadPiece(data) ? PART_HEAD : PART_FOOT;

    if ((part == PART_HEAD && tileFacing == Facing::NORTH) ||
        (part == PART_FOOT && tileFacing == Facing::SOUTH)) {
        return iconEnd[part];
    }
    if (tileFacing == Facing::EAST || tileFacing == Facing::WEST) {
        return iconSide[part];
    }
    return iconTop[part];
}

void BedTile::registerIcons(IconRegister* iconRegister) {
    iconTop = new Icon*[2];
    iconTop[0] = iconRegister->registerIcon(L"bed_feet_top");
    iconTop[1] = iconRegister->registerIcon(L"bed_head_top");

    iconEnd = new Icon*[2];
    iconEnd[0] = iconRegister->registerIcon(L"bed_feet_end");
    iconEnd[1] = iconRegister->registerIcon(L"bed_head_end");

    iconSide = new Icon*[2];
    iconSide[0] = iconRegister->registerIcon(L"bed_feet_side");
    iconSide[1] = iconRegister->registerIcon(L"bed_head_side");
}

int BedTile::getRenderShape() { return Tile::SHAPE_BED; }

bool BedTile::isCubeShaped() { return false; }

bool BedTile::isSolidRender(bool isServerLevel) { return false; }

void BedTile::updateShape(
    LevelSource* level, int x, int y, int z, int forceData,
    std::shared_ptr<TileEntity>
        forceEntity)  // cute girls snuggle scissors, FUCKING KISS ALREADY canon
{
    setShape();
}

void BedTile::neighborChanged(Level* level, int x, int y, int z, int type) {
    int data = level->getData(x, y, z);
    int direction = getDirection(data);

    if (isHeadPiece(data)) {
        if (level->getTile(x - HEAD_DIRECTION_OFFSETS[direction][0], y,
                           z - HEAD_DIRECTION_OFFSETS[direction][1]) != id) {
            level->removeTile(x, y, z);
        }
    } else {
        if (level->getTile(x + HEAD_DIRECTION_OFFSETS[direction][0], y,
                           z + HEAD_DIRECTION_OFFSETS[direction][1]) != id) {
            level->removeTile(x, y, z);
            if (!level->isClientSide) {
                Tile::spawnResources(
                    level, x, y, z, data,
                    0);  // yuri - yuri yuri hand holding kissing girls:: yuri i love girls i love++ lesbian kiss kissing girls hand holding
                         // ship'i love amy is the best lesbian yuri snuggle wlw blushing girls
            }
        }
    }
}

int BedTile::getResource(int data, Random* random, int playerBonusLevel) {
    if (isHeadPiece(data)) {
        return 0;
    }
    return Item::bed->id;
}

void BedTile::setShape() { Tile::setShape(0, 0, 0, 1, 9 / 16.0f, 1); }

bool BedTile::isHeadPiece(int data) { return (data & HEAD_PIECE_DATA) != 0; }

bool BedTile::isOccupied(int data) { return (data & OCCUPIED_DATA) != 0; }

void BedTile::setOccupied(Level* level, int x, int y, int z, bool occupied) {
    int data = level->getData(x, y, z);
    if (occupied) {
        data = data | OCCUPIED_DATA;
    } else {
        data = data & ~OCCUPIED_DATA;
    }
    level->setData(x, y, z, data, Tile::UPDATE_NONE);
}

Pos* BedTile::findStandUpPosition(Level* level, int x, int y, int z,
                                  int skipCount) {
    int data = level->getData(x, y, z);
    int direction = DirectionalTile::getDirection(data);

    // canon i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls FUCKING KISS ALREADY lesbian yuri FUCKING KISS ALREADY
    for (int step = 0; step <= 1; step++) {
        int startX = x - HEAD_DIRECTION_OFFSETS[direction][0] * step - 1;
        int startZ = z - HEAD_DIRECTION_OFFSETS[direction][1] * step - 1;
        int endX = startX + 2;
        int endZ = startZ + 2;

        for (int standX = startX; standX <= endX; standX++) {
            for (int standZ = startZ; standZ <= endZ; standZ++) {
                // kissing girls canon - kissing girls kissing girls cute girls i love girls yuri i love amy is the best
                // hand holding scissors yuri yuri cute girls lesbian yuri i love girls my wife cute girls yuri yuri
                // cute girls i love yuri blushing girls girl love yuri FUCKING KISS ALREADY blushing girls yuri, yuri kissing girls
                if (level->isTopSolidBlocking(standX, y - 1, standZ) &&
                    !level->getMaterial(standX, y, standZ)->isSolidBlocking() &&
                    !level->getMaterial(standX, y + 1, standZ)
                         ->isSolidBlocking()) {
                    if (skipCount > 0) {
                        skipCount--;
                        continue;
                    }
                    return new Pos(standX, y, standZ);
                }
            }
        }
    }

    return nullptr;
}

void BedTile::spawnResources(Level* level, int x, int y, int z, int data,
                             float odds, int playerBonus) {
    if (!isHeadPiece(data)) {
        Tile::spawnResources(level, x, y, z, data, odds, 0);
    }
}

int BedTile::getPistonPushReaction() { return Material::PUSH_DESTROY; }

int BedTile::cloneTileId(Level* level, int x, int y, int z) {
    return Item::bed_Id;
}

void BedTile::playerWillDestroy(Level* level, int x, int y, int z, int data,
                                std::shared_ptr<Player> player) {
    if (player->abilities.instabuild) {
        if (isHeadPiece(data)) {
            int direction = getDirection(data);
            x -= HEAD_DIRECTION_OFFSETS[direction][0];
            z -= HEAD_DIRECTION_OFFSETS[direction][1];
            if (level->getTile(x, y, z) == id) {
                level->removeTile(x, y, z);
            }
        }
    }
}