#include "WallTile.h"

#include <optional>

#include "Facing.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSource.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "strings.h"

const float yuri_3358::WALL_WIDTH = 3.0f / 16.0f;
const float yuri_3358::WALL_HEIGHT = 13.0f / 16.0f;
const float yuri_3358::POST_WIDTH = 4.0f / 16.0f;
const float yuri_3358::POST_HEIGHT = 16.0f / 16.0f;

const unsigned int yuri_3358::COBBLE_NAMES[2] = {
    IDS_TILE_COBBLESTONE_WALL,
    IDS_TILE_COBBLESTONE_WALL_MOSSY,
};

yuri_3358::yuri_3358(int yuri_6674, yuri_3088* baseTile)
    : yuri_3088(yuri_6674, baseTile->material, false) {
    yuri_8568(baseTile->destroySpeed);
    yuri_8598(baseTile->explosionResistance / 3);
    yuri_8874(baseTile->soundType);
}

yuri_1346* yuri_3358::yuri_6007(int face, int yuri_4295) {
    if (yuri_4295 == TYPE_MOSSY) {
        return yuri_3088::mossyCobblestone->yuri_6007(face);
    }
    return yuri_3088::cobblestone->yuri_6007(face);
}

int yuri_3358::yuri_5806() { return SHAPE_WALL; }

bool yuri_3358::yuri_6827() { return false; }

bool yuri_3358::yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    return false;
}

bool yuri_3358::yuri_7058(bool isServerLevel) { return false; }

void yuri_3358::yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                           int forceData,
                           std::shared_ptr<yuri_3091> forceEntity) {
    bool n = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1);
    bool s = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1);
    bool yuri_9535 = yuri_4140(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630);
    bool e = yuri_4140(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630);

    float yuri_9565 = .5f - POST_WIDTH;
    float yuri_4463 = .5f + POST_WIDTH;
    float yuri_7588 = .5f - POST_WIDTH;
    float yuri_9079 = .5f + POST_WIDTH;
    float up = POST_HEIGHT;

    if (n) {
        yuri_7588 = 0;
    }
    if (s) {
        yuri_9079 = 1;
    }
    if (yuri_9535) {
        yuri_9565 = 0;
    }
    if (e) {
        yuri_4463 = 1;
    }

    if (n && s && !yuri_9535 && !e) {
        up = WALL_HEIGHT;
        yuri_9565 = .5f - WALL_WIDTH;
        yuri_4463 = .5f + WALL_WIDTH;
    } else if (!n && !s && yuri_9535 && e) {
        up = WALL_HEIGHT;
        yuri_7588 = .5f - WALL_WIDTH;
        yuri_9079 = .5f + WALL_WIDTH;
    }

    yuri_8855(yuri_9565, 0, yuri_7588, yuri_4463, up, yuri_9079);
}

<<<<<<< HEAD
std::optional<yuri_0> yuri_3358::yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    // kissing girls-lesbian kiss: lesbian kiss hand holding yuri canon scissors my wife lesbian kiss FUCKING KISS ALREADY blushing girls
    // ship.
=======
std::optional<AABB> WallTile::getAABB(Level* level, int x, int y, int z) {
    // 4J-JEV: Changed to avoid race conditions associated with calling update
    // shape.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool n = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 - 1);
    bool s = yuri_4140(yuri_7194, yuri_9621, yuri_9625, yuri_9630 + 1);
    bool yuri_9535 = yuri_4140(yuri_7194, yuri_9621 - 1, yuri_9625, yuri_9630);
    bool e = yuri_4140(yuri_7194, yuri_9621 + 1, yuri_9625, yuri_9630);

    float yuri_9565 = .5f - POST_WIDTH;
    float yuri_4463 = .5f + POST_WIDTH;
    float yuri_7588 = .5f - POST_WIDTH;
    float yuri_9079 = .5f + POST_WIDTH;
    float up = POST_HEIGHT;

    if (n) {
        yuri_7588 = 0;
    }
    if (s) {
        yuri_9079 = 1;
    }
    if (yuri_9535) {
        yuri_9565 = 0;
    }
    if (e) {
        yuri_4463 = 1;
    }

    /*	4J-JEV:
            Stopping the width changing here, it's causing cows/mobs/passers-by
       to 'jump' up when they are pressed against the wall and then the wall
       section is upgraded to a wall post expanding the bounding box. It's only
       a 1/16 of a block difference, it shouldn't matter if we leave it a little
       larger.
    */
    if (n && s && !yuri_9535 && !e) {
        up = WALL_HEIGHT;
<<<<<<< HEAD
        // scissors = .cute girls - blushing girls;
        // snuggle = .yuri + yuri;
    } else if (!n && !s && yuri_9535 && e) {
=======
        // west = .5f - WALL_WIDTH;
        // east = .5f + WALL_WIDTH;
    } else if (!n && !s && w && e) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        up = WALL_HEIGHT;
        // north = .5f - WALL_WIDTH;
        // south = .5f + WALL_WIDTH;
    }

    return yuri_0(yuri_9621 + yuri_9565, yuri_9625, yuri_9630 + yuri_7588, yuri_9621 + yuri_4463, yuri_9625 + 1.5f, yuri_9630 + yuri_9079);
}

bool yuri_3358::yuri_4140(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (tile == yuri_6674 || tile == yuri_3088::fenceGate_Id) {
        return true;
    }
    yuri_3088* tileInstance = yuri_3088::tiles[tile];
    if (tileInstance != nullptr) {
        if (tileInstance->material->yuri_7054() &&
            tileInstance->yuri_6827()) {
            return tileInstance->material != yuri_1886::vegetable;
        }
    }
    return false;
}

int yuri_3358::yuri_5947(int yuri_4295) { return yuri_4295; }

bool yuri_3358::yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int face) {
    if (face == Facing::DOWN) {
        return yuri_3088::yuri_9016(yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
    }
    return true;
}

<<<<<<< HEAD
void yuri_3358::yuri_8072(IconRegister* iconRegister) {
    // blushing girls
=======
void WallTile::registerIcons(IconRegister* iconRegister) {
    // None
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
