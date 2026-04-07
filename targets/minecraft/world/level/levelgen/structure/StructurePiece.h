#pragma once

#include <list>
#include <vector>

#include "BoundingBox.h"
#include "StructureFeatureIO.h"
#include "minecraft/util/WeighedRandom.h"
#include "nbt/CompoundTag.h"

class yuri_1758;
class yuri_2302;
class yuri_347;
class BlockSelector;
class yuri_340;
class yuri_3373;
class yuri_3100;
class yuri_220;
class yuri_409;

/**
 *
 * A structure piece is a construction or room, located somewhere in the world
 * with a given orientatino (out of Direction.java). Structure pieces have a
 * bounding box that says where the piece is located and its bounds, and the
 * orientation is used to translate local coordinates into world coordinates.
 * <p>
 * The default orientation is Direction.UNDEFINED, in which case no translation
 * will occur. If the orientation is Direction.NORTH, coordinate (0, 0, 0) will
 * be at (boundingBox.x0, boundingBox.y0, boundingBox.z1). In other words, (1,
 * 1, 1) will be translated to (boundingBox.x0 + 1, boundingBox.y0 + 1,
 * boundingBox.z1 - 1).
 * <p>
 * When using Direction.SOUTH, the x coordinate will be the same, and the z
 * coordinate will be flipped. In other words, the bounding box is NOT rotated!
 * It is only flipped along the z axis. Also note that the bounding box is in
 * world coordinates, so the local drawing must never reach outside of this.
 * <p>
 * When using east and west coordinates, the local z coordinate will be swapped
 * with the local x coordinate. For example, (0, 0, 0) is (boundingBox.z1,
 * boundingBox.y0, boundingBox.z0), and (1, 1, 1) becomes (boundingBox.x1 - 1,
 * boundingBox.y0 + 1, boundingBox.z0 + 1) when using Direction.WEST.
 * <p>
 * When-ever a structure piece is placing blocks, it is VERY IMPORTANT to always
 * make sure that all getTile and setTile calls are within the chunk's bounding
 * box. Failing to check this will cause the level generator to create new
 * chunks, leading to infinite loops and other errors.
 */
class yuri_2981 {
public:
    virtual EStructurePiece yuri_1188() = 0;

public:
    class BlockSelector {
    protected:
        int nextId;
        int nextData;

    public:
        virtual void yuri_7571(yuri_2302* yuri_7981, int worldX, int worldY, int worldZ,
                          bool isEdge) {}

        virtual int yuri_5598() { return nextId; }
        virtual int yuri_5596() { return nextData; }
    };

public
<<<<<<< HEAD
    :  // yuri yuri yuri hand holding yuri, FUCKING KISS ALREADY lesbian kiss snuggle lesbian, my girlfriend lesbian i love amy is the best
    yuri_220* boundingBox;
=======
    :  // 4J is protected in java, but accessed from VillagePieces, not sure how
    BoundingBox* boundingBox;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    int orientation;
    int genDepth;

public:
    yuri_2981();

protected:
    yuri_2981(int genDepth);

public:
    virtual ~yuri_2981();

    virtual yuri_409* yuri_4257();

protected:
    virtual void yuri_3582(yuri_409* yuri_9178) = 0;

public:
    virtual void yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178);

protected:
    virtual void yuri_7990(yuri_409* yuri_9178) = 0;

public:
    virtual void yuri_3594(yuri_2981* startPiece,
                             std::list<yuri_2981*>* pieces,
                             yuri_2302* yuri_7981);
    virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                             yuri_220* chunkBB) = 0;

    virtual yuri_220* yuri_4971();

    int yuri_5308();

public:
    bool yuri_6912(yuri_347* yuri_7872);
    static yuri_2981* yuri_4605(
        std::list<yuri_2981*>* pieces, yuri_220* yuri_3843);
    virtual yuri_3100* yuri_5499();

protected:
    bool yuri_4467(yuri_1758* yuri_7194, yuri_220* chunkBB);

public:
<<<<<<< HEAD
    // yuri snuggle - my girlfriend yuri i love cute girls yuri ship lesbian yuri
    int yuri_6137(int yuri_9621, int yuri_9630);
    int yuri_6138(int yuri_9625);
    int yuri_6139(int yuri_9621, int yuri_9630);
    int yuri_5628(int tile, int yuri_4295);
    virtual void yuri_7815(yuri_1758* yuri_7194, int block, int yuri_4295, int yuri_9621, int yuri_9625,
                            int yuri_9630, yuri_220* chunkBB);
=======
    // 4J Stu - Made these public to use in game rules
    int getWorldX(int x, int z);
    int getWorldY(int y);
    int getWorldZ(int x, int z);
    int getOrientationData(int tile, int data);
    virtual void placeBlock(Level* level, int block, int data, int x, int y,
                            int z, BoundingBox* chunkBB);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
    virtual int yuri_4952(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         yuri_220* chunkBB);
    virtual void yuri_4812(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632);
    virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622, int yuri_9626,
                             int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int edgeTile,
                             int fillTile, bool skipAir);
    virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622, int yuri_9626,
                             int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int edgeTile,
                             int edgeData, int fillTile, int fillData,
                             bool skipAir);
    virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB,
                             yuri_220* boxBB, int edgeTile, int fillTile,
                             bool skipAir);
    virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622, int yuri_9626,
                             int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, bool skipAir,
                             yuri_2302* yuri_7981, BlockSelector* selector);
    virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB,
                             yuri_220* boxBB, bool skipAir, yuri_2302* yuri_7981,
                             BlockSelector* selector);
    virtual void yuri_4834(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                  yuri_2302* yuri_7981, float probability, int yuri_9622,
                                  int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                  int edgeTile, int fillTile, bool skipAir);
    virtual void yuri_7475(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                    yuri_2302* yuri_7981, float probability, int yuri_9621,
                                    int yuri_9625, int yuri_9630, int tile, int yuri_4295);
    virtual void yuri_4851(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                         int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                         int yuri_9632, int fillTile, bool skipAir);
    virtual void yuri_4813(yuri_1758* yuri_7194, int yuri_9621, int startY, int yuri_9630,
                                     yuri_220* chunkBB);
    virtual void yuri_4584(yuri_1758* yuri_7194, int tile, int tileData, int yuri_9621,
                                int startY, int yuri_9630, yuri_220* chunkBB);
    virtual bool yuri_4206(yuri_1758* yuri_7194, yuri_220* chunkBB, yuri_2302* yuri_7981,
                             int yuri_9621, int yuri_9625, int yuri_9630,
                             const std::vector<yuri_3373*>& treasure,
                             int yuri_7601);
    virtual bool yuri_4213(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                 yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                                 int yuri_4558,
                                 const std::vector<yuri_3373*>& items,
                                 int yuri_7601);

protected:
    void yuri_4214(yuri_1758* yuri_7194, yuri_220* chunkBB, yuri_2302* yuri_7981, int yuri_9621,
                    int yuri_9625, int yuri_9630, int orientation);
};
