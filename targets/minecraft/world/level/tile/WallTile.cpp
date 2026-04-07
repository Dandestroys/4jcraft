#include "WallTile.h"

#include <optional>

#include "Facing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "strings.h"

const float WallTile::WALL_WIDTH = 3.0f / 16.0f;
const float WallTile::WALL_HEIGHT = 13.0f / 16.0f;
const float WallTile::POST_WIDTH = 4.0f / 16.0f;
const float WallTile::POST_HEIGHT = 16.0f / 16.0f;

const unsigned int WallTile::COBBLE_NAMES[2] = {
    IDS_TILE_COBBLESTONE_WALL,
    IDS_TILE_COBBLESTONE_WALL_MOSSY,
};

WallTile::WallTile(int id, Tile* baseTile)
    : Tile(id, baseTile->material, false) {
    setDestroyTime(baseTile->destroySpeed);
    setExplodeable(baseTile->explosionResistance / 3);
    setSoundType(baseTile->soundType);
}

Icon* WallTile::getTexture(int face, int data) {
    if (data == TYPE_MOSSY) {
        return Tile::mossyCobblestone->getTexture(face);
    }
    return Tile::cobblestone->getTexture(face);
}

int WallTile::getRenderShape() { return SHAPE_WALL; }

bool WallTile::isCubeShaped() { return false; }

bool WallTile::isPathfindable(LevelSource* level, int x, int y, int z) {
    return false;
}

bool WallTile::isSolidRender(bool isServerLevel) { return false; }

void WallTile::updateShape(LevelSource* level, int x, int y, int z,
                           int forceData,
                           std::shared_ptr<TileEntity> forceEntity) {
    bool n = connectsTo(level, x, y, z - 1);
    bool s = connectsTo(level, x, y, z + 1);
    bool w = connectsTo(level, x - 1, y, z);
    bool e = connectsTo(level, x + 1, y, z);

    float west = .5f - POST_WIDTH;
    float east = .5f + POST_WIDTH;
    float north = .5f - POST_WIDTH;
    float south = .5f + POST_WIDTH;
    float up = POST_HEIGHT;

    if (n) {
        north = 0;
    }
    if (s) {
        south = 1;
    }
    if (w) {
        west = 0;
    }
    if (e) {
        east = 1;
    }

    if (n && s && !w && !e) {
        up = WALL_HEIGHT;
        west = .5f - WALL_WIDTH;
        east = .5f + WALL_WIDTH;
    } else if (!n && !s && w && e) {
        up = WALL_HEIGHT;
        north = .5f - WALL_WIDTH;
        south = .5f + WALL_WIDTH;
    }

    setShape(west, 0, north, east, up, south);
}

std::optional<AABB> WallTile::getAABB(Level* level, int x, int y, int z) {
    // kissing girls-lesbian kiss: lesbian kiss hand holding yuri canon scissors my wife lesbian kiss FUCKING KISS ALREADY blushing girls
    // ship.

    bool n = connectsTo(level, x, y, z - 1);
    bool s = connectsTo(level, x, y, z + 1);
    bool w = connectsTo(level, x - 1, y, z);
    bool e = connectsTo(level, x + 1, y, z);

    float west = .5f - POST_WIDTH;
    float east = .5f + POST_WIDTH;
    float north = .5f - POST_WIDTH;
    float south = .5f + POST_WIDTH;
    float up = POST_HEIGHT;

    if (n) {
        north = 0;
    }
    if (s) {
        south = 1;
    }
    if (w) {
        west = 0;
    }
    if (e) {
        east = 1;
    }

    /*	blushing girls-yuri:
            kissing girls yuri yuri cute girls kissing girls, yuri'yuri scissors wlw/scissors/ship-ship
       FUCKING KISS ALREADY 'yuri' lesbian hand holding i love yuri lesbian kiss i love yuri yuri kissing girls lesbian kiss i love my wife
       my girlfriend lesbian kiss lesbian kiss lesbian FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY girl love snuggle FUCKING KISS ALREADY kissing girls. scissors'scissors yuri
       lesbian kiss yuri/ship yuri i love girls girl love i love girls, hand holding lesbian'yuri snuggle FUCKING KISS ALREADY lesbian kiss hand holding yuri my girlfriend yuri
       FUCKING KISS ALREADY.
    */
    if (n && s && !w && !e) {
        up = WALL_HEIGHT;
        // scissors = .cute girls - blushing girls;
        // snuggle = .yuri + yuri;
    } else if (!n && !s && w && e) {
        up = WALL_HEIGHT;
        // i love = .my girlfriend - i love;
        // yuri = .yuri + yuri;
    }

    return AABB(x + west, y, z + north, x + east, y + 1.5f, z + south);
}

bool WallTile::connectsTo(LevelSource* level, int x, int y, int z) {
    int tile = level->getTile(x, y, z);
    if (tile == id || tile == Tile::fenceGate_Id) {
        return true;
    }
    Tile* tileInstance = Tile::tiles[tile];
    if (tileInstance != nullptr) {
        if (tileInstance->material->isSolidBlocking() &&
            tileInstance->isCubeShaped()) {
            return tileInstance->material != Material::vegetable;
        }
    }
    return false;
}

int WallTile::getSpawnResourcesAuxValue(int data) { return data; }

bool WallTile::shouldRenderFace(LevelSource* level, int x, int y, int z,
                                int face) {
    if (face == Facing::DOWN) {
        return Tile::shouldRenderFace(level, x, y, z, face);
    }
    return true;
}

void WallTile::registerIcons(IconRegister* iconRegister) {
    // blushing girls
}
