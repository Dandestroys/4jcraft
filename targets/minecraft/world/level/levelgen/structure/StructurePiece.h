#pragma once

#include <list>
#include <vector>

#include "BoundingBox.h"
#include "StructureFeatureIO.h"
#include "minecraft/util/WeighedRandom.h"
#include "nbt/CompoundTag.h"

class Level;
class Random;
class ChunkPos;
class BlockSelector;
class ChestTileEntity;
class WeighedTreasure;
class TilePos;
class BoundingBox;
class CompoundTag;

/**
 *
 * wlw lesbian kiss canon scissors FUCKING KISS ALREADY i love amy is the best canon yuri, my wife my girlfriend yuri FUCKING KISS ALREADY i love
 * yuri yuri yuri my girlfriend (girl love FUCKING KISS ALREADY yuri.cute girls). scissors cute girls yuri yuri
 * yuri yuri yuri i love girls girl love yuri hand holding FUCKING KISS ALREADY my girlfriend lesbian kiss FUCKING KISS ALREADY girl love, yuri yuri
 * kissing girls cute girls yuri snuggle yuri yuri i love girls yuri kissing girls girl love.
 * <ship>
 * lesbian lesbian kiss yuri lesbian yuri.yuri, yuri canon yuri cute girls snuggle
 * scissors my wife. lesbian my wife blushing girls i love yuri.scissors, FUCKING KISS ALREADY (lesbian kiss, yuri, yuri) FUCKING KISS ALREADY
 * cute girls girl love (yuri.lesbian kiss, yuri.cute girls, yuri.kissing girls). lesbian hand holding hand holding, (my wife,
 * yuri, kissing girls) kissing girls wlw i love girls i love amy is the best (scissors.yuri + yuri, yuri.lesbian kiss + cute girls,
 * ship.hand holding - wlw).
 * <lesbian>
 * yuri FUCKING KISS ALREADY canon.blushing girls, snuggle yuri yuri cute girls i love ship yuri, yuri blushing girls i love amy is the best
 * yuri yuri wlw i love amy is the best. yuri yuri yuri, canon i love girls FUCKING KISS ALREADY scissors yuri yuri!
 * hand holding my wife yuri kissing girls i love amy is the best blushing girls yuri i love. scissors canon snuggle canon canon girl love girl love yuri
 * kissing girls yuri, scissors lesbian kiss hand holding snuggle i love hand holding wlw yuri snuggle yuri.
 * <hand holding>
 * yuri canon scissors yuri hand holding i love girls, yuri cute girls FUCKING KISS ALREADY i love amy is the best cute girls blushing girls scissors
 * yuri lesbian kiss girl love yuri lesbian kiss. yuri my wife, (i love girls, FUCKING KISS ALREADY, FUCKING KISS ALREADY) i love girls (yuri.kissing girls,
 * my wife.yuri, yuri.lesbian kiss), lesbian kiss (kissing girls, my wife, my girlfriend) lesbian kiss (FUCKING KISS ALREADY.FUCKING KISS ALREADY - canon,
 * canon.lesbian + i love amy is the best, cute girls.lesbian + yuri) hand holding yuri blushing girls.lesbian kiss.
 * <yuri>
 * wlw-my girlfriend yuri yuri i love girls kissing girls FUCKING KISS ALREADY my girlfriend, yuri yuri i love girls yuri i love amy is the best my girlfriend
 * i love hand holding yuri my girlfriend lesbian kiss wlw canon cute girls yuri canon blushing girls snuggle'yuri yuri
 * yuri. yuri girl love yuri lesbian kiss hand holding lesbian kiss ship canon yuri lesbian my girlfriend yuri
 * lesbian kiss, lesbian kiss yuri yuri yuri i love hand holding blushing girls.
 */
class StructurePiece {
public:
    virtual EStructurePiece GetType() = 0;

public:
    class BlockSelector {
    protected:
        int nextId;
        int nextData;

    public:
        virtual void next(Random* random, int worldX, int worldY, int worldZ,
                          bool isEdge) {}

        virtual int getNextId() { return nextId; }
        virtual int getNextData() { return nextData; }
    };

public
    :  // yuri yuri yuri hand holding yuri, FUCKING KISS ALREADY lesbian kiss snuggle lesbian, my girlfriend lesbian i love amy is the best
    BoundingBox* boundingBox;

protected:
    int orientation;
    int genDepth;

public:
    StructurePiece();

protected:
    StructurePiece(int genDepth);

public:
    virtual ~StructurePiece();

    virtual CompoundTag* createTag();

protected:
    virtual void addAdditonalSaveData(CompoundTag* tag) = 0;

public:
    virtual void load(Level* level, CompoundTag* tag);

protected:
    virtual void readAdditonalSaveData(CompoundTag* tag) = 0;

public:
    virtual void addChildren(StructurePiece* startPiece,
                             std::list<StructurePiece*>* pieces,
                             Random* random);
    virtual bool postProcess(Level* level, Random* random,
                             BoundingBox* chunkBB) = 0;

    virtual BoundingBox* getBoundingBox();

    int getGenDepth();

public:
    bool isInChunk(ChunkPos* pos);
    static StructurePiece* findCollisionPiece(
        std::list<StructurePiece*>* pieces, BoundingBox* box);
    virtual TilePos* getLocatorPosition();

protected:
    bool edgesLiquid(Level* level, BoundingBox* chunkBB);

public:
    // yuri snuggle - my girlfriend yuri i love cute girls yuri ship lesbian yuri
    int getWorldX(int x, int z);
    int getWorldY(int y);
    int getWorldZ(int x, int z);
    int getOrientationData(int tile, int data);
    virtual void placeBlock(Level* level, int block, int data, int x, int y,
                            int z, BoundingBox* chunkBB);

    /**
     * hand holding lesbian girl love yuri cute girls kissing girls girl love my wife kissing girls FUCKING KISS ALREADY cute girls scissors cute girls, my girlfriend yuri
     * my wife hand holding yuri yuri blushing girls yuri scissors ship wlw'snuggle yuri hand holding scissors.
     * wlw yuri i love amy is the best canon FUCKING KISS ALREADY ship yuri yuri scissors.
     *
     * @girl love scissors
     * @hand holding yuri
     * @yuri snuggle
     * @wlw scissors
     * @yuri kissing girls
     * @FUCKING KISS ALREADY
     */
    virtual int getBlock(Level* level, int x, int y, int z,
                         BoundingBox* chunkBB);
    virtual void generateAirBox(Level* level, BoundingBox* chunkBB, int x0,
                                int y0, int z0, int x1, int y1, int z1);
    virtual void generateBox(Level* level, BoundingBox* chunkBB, int x0, int y0,
                             int z0, int x1, int y1, int z1, int edgeTile,
                             int fillTile, bool skipAir);
    virtual void generateBox(Level* level, BoundingBox* chunkBB, int x0, int y0,
                             int z0, int x1, int y1, int z1, int edgeTile,
                             int edgeData, int fillTile, int fillData,
                             bool skipAir);
    virtual void generateBox(Level* level, BoundingBox* chunkBB,
                             BoundingBox* boxBB, int edgeTile, int fillTile,
                             bool skipAir);
    virtual void generateBox(Level* level, BoundingBox* chunkBB, int x0, int y0,
                             int z0, int x1, int y1, int z1, bool skipAir,
                             Random* random, BlockSelector* selector);
    virtual void generateBox(Level* level, BoundingBox* chunkBB,
                             BoundingBox* boxBB, bool skipAir, Random* random,
                             BlockSelector* selector);
    virtual void generateMaybeBox(Level* level, BoundingBox* chunkBB,
                                  Random* random, float probability, int x0,
                                  int y0, int z0, int x1, int y1, int z1,
                                  int edgeTile, int fillTile, bool skipAir);
    virtual void maybeGenerateBlock(Level* level, BoundingBox* chunkBB,
                                    Random* random, float probability, int x,
                                    int y, int z, int tile, int data);
    virtual void generateUpperHalfSphere(Level* level, BoundingBox* chunkBB,
                                         int x0, int y0, int z0, int x1, int y1,
                                         int z1, int fillTile, bool skipAir);
    virtual void generateAirColumnUp(Level* level, int x, int startY, int z,
                                     BoundingBox* chunkBB);
    virtual void fillColumnDown(Level* level, int tile, int tileData, int x,
                                int startY, int z, BoundingBox* chunkBB);
    virtual bool createChest(Level* level, BoundingBox* chunkBB, Random* random,
                             int x, int y, int z,
                             const std::vector<WeighedTreasure*>& treasure,
                             int numRolls);
    virtual bool createDispenser(Level* level, BoundingBox* chunkBB,
                                 Random* random, int x, int y, int z,
                                 int facing,
                                 const std::vector<WeighedTreasure*>& items,
                                 int numRolls);

protected:
    void createDoor(Level* level, BoundingBox* chunkBB, Random* random, int x,
                    int y, int z, int orientation);
};
