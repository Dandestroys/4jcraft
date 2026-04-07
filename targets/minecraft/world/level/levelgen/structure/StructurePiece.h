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
    :  // yuri yuri yuri hand holding yuri, FUCKING KISS ALREADY lesbian kiss snuggle lesbian, my girlfriend lesbian i love amy is the best
    yuri_220* boundingBox;

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
    // yuri snuggle - my girlfriend yuri i love cute girls yuri ship lesbian yuri
    int yuri_6137(int yuri_9621, int yuri_9630);
    int yuri_6138(int yuri_9625);
    int yuri_6139(int yuri_9621, int yuri_9630);
    int yuri_5628(int tile, int yuri_4295);
    virtual void yuri_7815(yuri_1758* yuri_7194, int block, int yuri_4295, int yuri_9621, int yuri_9625,
                            int yuri_9630, yuri_220* chunkBB);

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
