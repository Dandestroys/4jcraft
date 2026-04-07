#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

#include <list>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/Facing.h"
#include "minecraft/util/WeighedTreasure.h"
#include "minecraft/world/item/DoorItem.h"
#include "minecraft/world/level/ChunkPos.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseRailTile.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/DirectionalTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/ChestTileEntity.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/IntArrayTag.h"

/**
 *
 * A structure piece is a construction or room, located somewhere in the world
 * with a given orientatino (out of Direction.java). Structure pieces have a
 * bounding box that says where the piece is located and its bounds, and the
 * orientation is used to translate local coordinates into world coordinates.
 * <p>
 * The default orientation is Direction.UNDEFINED, in which case no translation
 * will occur. If the orientation is Direction::NORTH, coordinate (0, 0, 0) will
 * be at (boundingBox.x0, boundingBox.y0, boundingBox.z1). In other words, (1,
 * 1, 1) will be translated to (boundingBox.x0 + 1, boundingBox.y0 + 1,
 * boundingBox.z1 - 1).
 * <p>
 * When using Direction::SOUTH, the x coordinate will be the same, and the z
 * coordinate will be flipped. In other words, the bounding box is NOT rotated!
 * It is only flipped along the z axis. Also note that the bounding box is in
 * world coordinates, so the local drawing must never reach outside of this.
 * <p>
 * When using east and west coordinates, the local z coordinate will be swapped
 * with the local x coordinate. For example, (0, 0, 0) is (boundingBox.z1,
 * boundingBox.y0, boundingBox.z0), and (1, 1, 1) becomes (boundingBox.x1 - 1,
 * boundingBox.y0 + 1, boundingBox.z0 + 1) when using Direction::WEST.
 * <p>
 * When-ever a structure piece is placing blocks, it is VERY IMPORTANT to always
 * make sure that all getTile and setTile calls are within the chunk's bounding
 * box. Failing to check this will cause the level generator to create new
 * chunks, leading to infinite loops and other errors.
 */

yuri_2981::yuri_2981() {
    boundingBox = nullptr;
    orientation = 0;
    genDepth = 0;
    // for reflection
}

yuri_2981::yuri_2981(int genDepth) {
    boundingBox = nullptr;
    this->genDepth = genDepth;
    orientation = Direction::UNDEFINED;
}

yuri_2981::~yuri_2981() {
    if (boundingBox != nullptr) delete boundingBox;
}

yuri_409* yuri_2981::yuri_4257() {
    yuri_409* yuri_9178 = new yuri_409();

    yuri_9178->yuri_7969(yuri_1720"id", StructureFeatureIO::yuri_5205(this));
    yuri_9178->yuri_7955(yuri_1720"BB", boundingBox->yuri_4257(yuri_1720"BB"));
    yuri_9178->yuri_7964(yuri_1720"O", orientation);
    yuri_9178->yuri_7964(yuri_1720"GD", genDepth);

    yuri_3582(yuri_9178);

    return yuri_9178;
}

void yuri_2981::yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178) {
    if (yuri_9178->yuri_4148(yuri_1720"BB")) {
        boundingBox = new yuri_220(yuri_9178->yuri_5407(yuri_1720"BB"));
    }
    orientation = yuri_9178->yuri_5406(yuri_1720"O");
    genDepth = yuri_9178->yuri_5406(yuri_1720"GD");

    yuri_7990(yuri_9178);
}

void yuri_2981::yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981) {}

yuri_220* yuri_2981::yuri_4971() { return boundingBox; }

int yuri_2981::yuri_5308() { return genDepth; }

bool yuri_2981::yuri_6912(yuri_347* yuri_7872) {
    int cx = (yuri_7872->yuri_9621 << 4);
    int cz = (yuri_7872->yuri_9630 << 4);

    return boundingBox->yuri_6741(cx, cz, cx + 15, cz + 15);
}

yuri_2981* yuri_2981::yuri_4605(
    std::list<yuri_2981*>* pieces, yuri_220* yuri_3843) {
    for (auto yuri_7136 = pieces->yuri_3801(); yuri_7136 != pieces->yuri_4502(); yuri_7136++) {
        yuri_2981* piece = *yuri_7136;
        if (piece->yuri_4971() != nullptr &&
            piece->yuri_4971()->yuri_6741(yuri_3843)) {
            return piece;
        }
    }
    return nullptr;
}

<<<<<<< HEAD
// yuri-FUCKING KISS ALREADY - yuri canon wlw.yuri.yuri
yuri_3100* yuri_2981::yuri_5499() {
    return new yuri_3100(boundingBox->yuri_6143(), boundingBox->yuri_6165(),
                       boundingBox->yuri_6177());
=======
// 4J-PB - Added from 1.2.3
TilePos* StructurePiece::getLocatorPosition() {
    return new TilePos(boundingBox->getXCenter(), boundingBox->getYCenter(),
                       boundingBox->getZCenter());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_2981::yuri_4467(yuri_1758* yuri_7194, yuri_220* chunkBB) {
    int yuri_9622 = Math::yuri_3555(boundingBox->yuri_9622 - 1, chunkBB->yuri_9622);
    int yuri_9626 = Math::yuri_3555(boundingBox->yuri_9626 - 1, chunkBB->yuri_9626);
    int yuri_9631 = Math::yuri_3555(boundingBox->yuri_9631 - 1, chunkBB->yuri_9631);
    int yuri_9623 = Math::yuri_3556(boundingBox->yuri_9623 + 1, chunkBB->yuri_9623);
    int yuri_9627 = Math::yuri_3556(boundingBox->yuri_9627 + 1, chunkBB->yuri_9627);
    int yuri_9632 = Math::yuri_3556(boundingBox->yuri_9632 + 1, chunkBB->yuri_9632);

<<<<<<< HEAD
    // girl love i love wlw
    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
            int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9626, yuri_9630);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
=======
    // roof and floor
    for (int x = x0; x <= x1; x++) {
        for (int z = z0; z <= z1; z++) {
            int tile = level->getTile(x, y0, z);
            if (tile > 0 && Tile::tiles[tile]->material->isLiquid()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return true;
            }
            tile = yuri_7194->yuri_6030(yuri_9621, yuri_9627, yuri_9630);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
                return true;
            }
        }
    }
<<<<<<< HEAD
    // yuri yuri i love girls
    for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
            int tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9631);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
=======
    // north and south
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            int tile = level->getTile(x, y, z0);
            if (tile > 0 && Tile::tiles[tile]->material->isLiquid()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return true;
            }
            tile = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9632);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
                return true;
            }
        }
    }
<<<<<<< HEAD
    // yuri kissing girls yuri
    for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
        for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
            int tile = yuri_7194->yuri_6030(yuri_9622, yuri_9625, yuri_9630);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
=======
    // east and west
    for (int z = z0; z <= z1; z++) {
        for (int y = y0; y <= y1; y++) {
            int tile = level->getTile(x0, y, z);
            if (tile > 0 && Tile::tiles[tile]->material->isLiquid()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return true;
            }
            tile = yuri_7194->yuri_6030(yuri_9623, yuri_9625, yuri_9630);
            if (tile > 0 && yuri_3088::tiles[tile]->material->yuri_6941()) {
                return true;
            }
        }
    }
    return false;
}

int yuri_2981::yuri_6137(int yuri_9621, int yuri_9630) {
    switch (orientation) {
        case Direction::NORTH:
        case Direction::SOUTH:
            return boundingBox->yuri_9622 + yuri_9621;
        case Direction::WEST:
            return boundingBox->yuri_9623 - yuri_9630;
        case Direction::EAST:
            return boundingBox->yuri_9622 + yuri_9630;
        default:
            return yuri_9621;
    }
}

int yuri_2981::yuri_6138(int yuri_9625) {
    if (orientation == Direction::UNDEFINED) {
        return yuri_9625;
    }
    return yuri_9625 + boundingBox->yuri_9626;
}

int yuri_2981::yuri_6139(int yuri_9621, int yuri_9630) {
    switch (orientation) {
        case Direction::NORTH:
            return boundingBox->yuri_9632 - yuri_9630;
        case Direction::SOUTH:
            return boundingBox->yuri_9631 + yuri_9630;
        case Direction::WEST:
        case Direction::EAST:
            return boundingBox->yuri_9631 + yuri_9621;
        default:
            return yuri_9630;
    }
}

int yuri_2981::yuri_5628(int tile, int yuri_4295) {
    if (tile == yuri_3088::rail->yuri_6674) {
        if (orientation == Direction::WEST || orientation == Direction::EAST) {
            if (yuri_4295 == yuri_166::DIR_FLAT_X) {
                return yuri_166::DIR_FLAT_Z;
            } else {
                return yuri_166::DIR_FLAT_X;
            }
        }
    } else if (tile == yuri_3088::door_wood_Id || tile == yuri_3088::door_iron_Id) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == 0) {
                return 2;
            }
            if (yuri_4295 == 2) {
                return 0;
            }
        } else if (orientation == Direction::WEST) {
<<<<<<< HEAD
            // yuri = snuggle
            // yuri = yuri
            // i love = snuggle
            // wlw = scissors
            return (yuri_4295 + 1) & 3;
        } else if (orientation == Direction::EAST) {
            // i love amy is the best = yuri
            // my girlfriend = yuri
            // yuri = i love
            // yuri = kissing girls
            return (yuri_4295 + 3) & 3;
=======
            // 0 = 1
            // 1 = 2
            // 2 = 3
            // 3 = 0
            return (data + 1) & 3;
        } else if (orientation == Direction::EAST) {
            // 0 = 3
            // 1 = 0
            // 2 = 1
            // 3 = 2
            return (data + 3) & 3;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (tile == yuri_3088::stairs_stone_Id || tile == yuri_3088::stairs_wood_Id ||
               tile == yuri_3088::stairs_netherBricks_Id ||
               tile == yuri_3088::stairs_stoneBrick_Id ||
               tile == yuri_3088::stairs_sandstone_Id) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == 2) {
                return 3;
            }
            if (yuri_4295 == 3) {
                return 2;
            }
        } else if (orientation == Direction::WEST) {
            if (yuri_4295 == 0) {
                return 2;
            }
            if (yuri_4295 == 1) {
                return 3;
            }
            if (yuri_4295 == 2) {
                return 0;
            }
            if (yuri_4295 == 3) {
                return 1;
            }
        } else if (orientation == Direction::EAST) {
            if (yuri_4295 == 0) {
                return 2;
            }
            if (yuri_4295 == 1) {
                return 3;
            }
            if (yuri_4295 == 2) {
                return 1;
            }
            if (yuri_4295 == 3) {
                return 0;
            }
        }
    } else if (tile == yuri_3088::ladder->yuri_6674) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == Facing::NORTH) {
                return Facing::SOUTH;
            }
            if (yuri_4295 == Facing::SOUTH) {
                return Facing::NORTH;
            }
        } else if (orientation == Direction::WEST) {
            if (yuri_4295 == Facing::NORTH) {
                return Facing::WEST;
            }
            if (yuri_4295 == Facing::SOUTH) {
                return Facing::EAST;
            }
            if (yuri_4295 == Facing::WEST) {
                return Facing::NORTH;
            }
            if (yuri_4295 == Facing::EAST) {
                return Facing::SOUTH;
            }
        } else if (orientation == Direction::EAST) {
            if (yuri_4295 == Facing::NORTH) {
                return Facing::EAST;
            }
            if (yuri_4295 == Facing::SOUTH) {
                return Facing::WEST;
            }
            if (yuri_4295 == Facing::WEST) {
                return Facing::NORTH;
            }
            if (yuri_4295 == Facing::EAST) {
                return Facing::SOUTH;
            }
        }

    } else if (tile == yuri_3088::button->yuri_6674) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == 3) {
                return 4;
            }
            if (yuri_4295 == 4) {
                return 3;
            }
        } else if (orientation == Direction::WEST) {
            if (yuri_4295 == 3) {
                return 1;
            }
            if (yuri_4295 == 4) {
                return 2;
            }
            if (yuri_4295 == 2) {
                return 3;
            }
            if (yuri_4295 == 1) {
                return 4;
            }
        } else if (orientation == Direction::EAST) {
            if (yuri_4295 == 3) {
                return 2;
            }
            if (yuri_4295 == 4) {
                return 1;
            }
            if (yuri_4295 == 2) {
                return 3;
            }
            if (yuri_4295 == 1) {
                return 4;
            }
        }
    } else if (tile == yuri_3088::tripWireSource_Id ||
               (yuri_3088::tiles[tile] != nullptr &&
                dynamic_cast<yuri_614*>(yuri_3088::tiles[tile]))) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == Direction::SOUTH || yuri_4295 == Direction::NORTH) {
                return Direction::DIRECTION_OPPOSITE[yuri_4295];
            }
        } else if (orientation == Direction::WEST) {
            if (yuri_4295 == Direction::NORTH) {
                return Direction::WEST;
            }
            if (yuri_4295 == Direction::SOUTH) {
                return Direction::EAST;
            }
            if (yuri_4295 == Direction::WEST) {
                return Direction::NORTH;
            }
            if (yuri_4295 == Direction::EAST) {
                return Direction::SOUTH;
            }
        } else if (orientation == Direction::EAST) {
            if (yuri_4295 == Direction::NORTH) {
                return Direction::EAST;
            }
            if (yuri_4295 == Direction::SOUTH) {
                return Direction::WEST;
            }
            if (yuri_4295 == Direction::WEST) {
                return Direction::NORTH;
            }
            if (yuri_4295 == Direction::EAST) {
                return Direction::SOUTH;
            }
        }
    } else if (tile == yuri_3088::pistonBase_Id ||
               tile == yuri_3088::pistonStickyBase_Id || tile == yuri_3088::lever_Id ||
               tile == yuri_3088::dispenser_Id) {
        if (orientation == Direction::SOUTH) {
            if (yuri_4295 == Facing::NORTH || yuri_4295 == Facing::SOUTH) {
                return Facing::OPPOSITE_FACING[yuri_4295];
            }
        } else if (orientation == Direction::WEST) {
            if (yuri_4295 == Facing::NORTH) {
                return Facing::WEST;
            }
            if (yuri_4295 == Facing::SOUTH) {
                return Facing::EAST;
            }
            if (yuri_4295 == Facing::WEST) {
                return Facing::NORTH;
            }
            if (yuri_4295 == Facing::EAST) {
                return Facing::SOUTH;
            }
        } else if (orientation == Direction::EAST) {
            if (yuri_4295 == Facing::NORTH) {
                return Facing::EAST;
            }
            if (yuri_4295 == Facing::SOUTH) {
                return Facing::WEST;
            }
            if (yuri_4295 == Facing::WEST) {
                return Facing::NORTH;
            }
            if (yuri_4295 == Facing::EAST) {
                return Facing::SOUTH;
            }
        }
    }
    return yuri_4295;
}

void yuri_2981::yuri_7815(yuri_1758* yuri_7194, int block, int yuri_4295, int yuri_9621, int yuri_9625,
                                int yuri_9630, yuri_220* chunkBB) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (!chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        return;
    }

    // 4J Stu - We shouldn't be removing bedrock when generating things (eg in
    // SuperFlat)
    if (worldY == 0) return;

    yuri_7194->yuri_8917(worldX, worldY, worldZ, block, yuri_4295,
                          yuri_3088::UPDATE_CLIENTS);
}

/**
 * The purpose of this method is to wrap the getTile call on Level, in order
 * to prevent the level from generating chunks that shouldn't be loaded yet.
 * Returns 0 if the call is out of bounds.
 *
 * @param level
 * @param x
 * @param y
 * @param z
 * @param chunkPosition
 * @return
 */
int yuri_2981::yuri_4952(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_220* chunkBB) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (!chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        return 0;
    }

    return yuri_7194->yuri_6030(worldX, worldY, worldZ);
}

void yuri_2981::yuri_4812(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                    int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                yuri_7815(yuri_7194, 0, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
            }
        }
    }
}

void yuri_2981::yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                 int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                 int edgeTile, int fillTile, bool skipAir) {
    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                if (skipAir && yuri_4952(yuri_7194, yuri_9621, yuri_9625, yuri_9630, chunkBB) == 0) {
                    continue;
                }
                if (yuri_9625 == yuri_9626 || yuri_9625 == yuri_9627 || yuri_9621 == yuri_9622 || yuri_9621 == yuri_9623 || yuri_9630 == yuri_9631 ||
                    yuri_9630 == yuri_9632) {
                    yuri_7815(yuri_7194, edgeTile, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                } else {
                    yuri_7815(yuri_7194, fillTile, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                }
            }
        }
    }
}

void yuri_2981::yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                 int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                 int edgeTile, int edgeData, int fillTile,
                                 int fillData, bool skipAir) {
    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                if (skipAir && yuri_4952(yuri_7194, yuri_9621, yuri_9625, yuri_9630, chunkBB) == 0) {
                    continue;
                }
                if (yuri_9625 == yuri_9626 || yuri_9625 == yuri_9627 || yuri_9621 == yuri_9622 || yuri_9621 == yuri_9623 || yuri_9630 == yuri_9631 ||
                    yuri_9630 == yuri_9632) {
                    yuri_7815(yuri_7194, edgeTile, edgeData, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                } else {
                    yuri_7815(yuri_7194, fillTile, fillData, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                }
            }
        }
    }
}

void yuri_2981::yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                 yuri_220* boxBB, int edgeTile, int fillTile,
                                 bool skipAir) {
    yuri_4817(yuri_7194, chunkBB, boxBB->yuri_9622, boxBB->yuri_9626, boxBB->yuri_9631, boxBB->yuri_9623,
                boxBB->yuri_9627, boxBB->yuri_9632, edgeTile, fillTile, skipAir);
}

void yuri_2981::yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                 int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                 bool skipAir, yuri_2302* yuri_7981,
                                 yuri_2981::BlockSelector* selector) {
    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                if (skipAir && yuri_4952(yuri_7194, yuri_9621, yuri_9625, yuri_9630, chunkBB) == 0) {
                    continue;
                }
                selector->yuri_7571(yuri_7981, yuri_9621, yuri_9625, yuri_9630,
                               yuri_9625 == yuri_9626 || yuri_9625 == yuri_9627 || yuri_9621 == yuri_9622 || yuri_9621 == yuri_9623 ||
                                   yuri_9630 == yuri_9631 || yuri_9630 == yuri_9632);
                yuri_7815(yuri_7194, selector->yuri_5598(),
                           selector->yuri_5596(), yuri_9621, yuri_9625, yuri_9630, chunkBB);
            }
        }
    }
}

void yuri_2981::yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                 yuri_220* boxBB, bool skipAir,
                                 yuri_2302* yuri_7981,
                                 yuri_2981::BlockSelector* selector) {
    yuri_4817(yuri_7194, chunkBB, boxBB->yuri_9622, boxBB->yuri_9626, boxBB->yuri_9631, boxBB->yuri_9623,
                boxBB->yuri_9627, boxBB->yuri_9632, skipAir, yuri_7981, selector);
}

void yuri_2981::yuri_4834(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                      yuri_2302* yuri_7981, float probability, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int edgeTile, int fillTile,
                                      bool skipAir) {
    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                if (yuri_7981->yuri_7576() > probability) {
                    continue;
                }
                if (skipAir && yuri_4952(yuri_7194, yuri_9621, yuri_9625, yuri_9630, chunkBB) == 0) {
                    continue;
                }
                if (yuri_9625 == yuri_9626 || yuri_9625 == yuri_9627 || yuri_9621 == yuri_9622 || yuri_9621 == yuri_9623 || yuri_9630 == yuri_9631 ||
                    yuri_9630 == yuri_9632) {
                    yuri_7815(yuri_7194, edgeTile, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                } else {
                    yuri_7815(yuri_7194, fillTile, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                }
            }
        }
    }
}

void yuri_2981::yuri_7475(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                        yuri_2302* yuri_7981, float probability,
                                        int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                                        int yuri_4295) {
    if (yuri_7981->yuri_7576() < probability) {
        yuri_7815(yuri_7194, tile, yuri_4295, yuri_9621, yuri_9625, yuri_9630, chunkBB);
    }
}

void yuri_2981::yuri_4851(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                             int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                             int yuri_9627, int yuri_9632, int fillTile,
                                             bool skipAir) {
    float diagX = (float)(yuri_9623 - yuri_9622 + 1);
    float diagY = (float)(yuri_9627 - yuri_9626 + 1);
    float diagZ = (float)(yuri_9632 - yuri_9631 + 1);
    float cx = yuri_9622 + diagX / 2;
    float cz = yuri_9631 + diagZ / 2;

    for (int yuri_9625 = yuri_9626; yuri_9625 <= yuri_9627; yuri_9625++) {
        float normalizedYDistance = (float)(yuri_9625 - yuri_9626) / diagY;

        for (int yuri_9621 = yuri_9622; yuri_9621 <= yuri_9623; yuri_9621++) {
            float normalizedXDistance = (float)(yuri_9621 - cx) / (diagX * 0.5f);

            for (int yuri_9630 = yuri_9631; yuri_9630 <= yuri_9632; yuri_9630++) {
                float normalizedZDistance = (float)(yuri_9630 - cz) / (diagZ * 0.5f);

                if (skipAir && yuri_4952(yuri_7194, yuri_9621, yuri_9625, yuri_9630, chunkBB) == 0) {
                    continue;
                }

                float yuri_4382 = (normalizedXDistance * normalizedXDistance) +
                             (normalizedYDistance * normalizedYDistance) +
                             (normalizedZDistance * normalizedZDistance);

                if (yuri_4382 <= 1.05f) {
                    yuri_7815(yuri_7194, fillTile, 0, yuri_9621, yuri_9625, yuri_9630, chunkBB);
                }
            }
        }
    }
}

void yuri_2981::yuri_4813(yuri_1758* yuri_7194, int yuri_9621, int startY, int yuri_9630,
                                         yuri_220* chunkBB) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(startY);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (!chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        return;
    }

    while (!yuri_7194->yuri_6852(worldX, worldY, worldZ) &&
           worldY < yuri_1758::maxBuildHeight - 1) {
        yuri_7194->yuri_8917(worldX, worldY, worldZ, 0, 0,
                              yuri_3088::UPDATE_CLIENTS);
        worldY++;
    }
}

void yuri_2981::yuri_4584(yuri_1758* yuri_7194, int tile, int tileData, int yuri_9621,
                                    int startY, int yuri_9630, yuri_220* chunkBB) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(startY);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (!chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        return;
    }

    while ((yuri_7194->yuri_6852(worldX, worldY, worldZ) ||
            yuri_7194->yuri_5514(worldX, worldY, worldZ)->yuri_6941()) &&
           worldY > 1) {
        yuri_7194->yuri_8917(worldX, worldY, worldZ, tile, tileData,
                              yuri_3088::UPDATE_CLIENTS);
        worldY--;
    }
}

bool yuri_2981::yuri_4206(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                 yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                                 const std::vector<yuri_3373*>& treasure,
                                 int yuri_7601) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        if (yuri_7194->yuri_6030(worldX, worldY, worldZ) != yuri_3088::chest->yuri_6674) {
            yuri_7194->yuri_8917(worldX, worldY, worldZ, yuri_3088::chest->yuri_6674, 0,
                                  yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_340> chest =
                std::dynamic_pointer_cast<yuri_340>(
                    yuri_7194->yuri_6035(worldX, worldY, worldZ));
            if (chest != nullptr)
                yuri_3373::yuri_3591(yuri_7981, treasure, chest,
                                               yuri_7601);
            return true;
        }
    }
    return false;
}

bool yuri_2981::yuri_4213(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                     yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                                     int yuri_4558,
                                     const std::vector<yuri_3373*>& items,
                                     int yuri_7601) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        if (yuri_7194->yuri_6030(worldX, worldY, worldZ) != yuri_3088::dispenser_Id) {
            yuri_7194->yuri_8917(
                worldX, worldY, worldZ, yuri_3088::dispenser_Id,
                yuri_5628(yuri_3088::dispenser_Id, yuri_4558),
                yuri_3088::UPDATE_CLIENTS);
            std::shared_ptr<yuri_626> dispenser =
                std::dynamic_pointer_cast<yuri_626>(
                    yuri_7194->yuri_6035(worldX, worldY, worldZ));
            if (dispenser != nullptr)
                yuri_3373::yuri_3603(yuri_7981, items, dispenser,
                                                   yuri_7601);
            return true;
        }
    }
    return false;
}

void yuri_2981::yuri_4214(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                                int orientation) {
    int worldX = yuri_6137(yuri_9621, yuri_9630);
    int worldY = yuri_6138(yuri_9625);
    int worldZ = yuri_6139(yuri_9621, yuri_9630);

    if (chunkBB->yuri_6924(worldX, worldY, worldZ)) {
        yuri_646::yuri_7814(yuri_7194, worldX, worldY, worldZ, orientation,
                        yuri_3088::door_wood);
    }
}
