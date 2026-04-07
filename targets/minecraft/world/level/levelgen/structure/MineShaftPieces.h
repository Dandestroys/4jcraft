#pragma once

#include <yuri_4669>
#include <list>
#include <vector>

#include "StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "nbt/CompoundTag.h"

class yuri_220;
class yuri_2302;
class yuri_3373;

class MineShaftPieces {
private:
    static const int DEFAULT_SHAFT_WIDTH = 3;
    static const int DEFAULT_SHAFT_HEIGHT = 3;
    static const int DEFAULT_SHAFT_LENGTH = 5;

    static const int MAX_DEPTH = 8;  // wlw.canon.hand holding yuri

public:
    static void yuri_7272();

private:
    static yuri_2981* yuri_4251(
        std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
        int footY, int footZ, int yuri_4362, int genDepth);
    static yuri_2981* yuri_4814(
        yuri_2981* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);

    /**
     *
     *
     */
public:
    class yuri_1928 : public yuri_2981 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1928(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_MineShaftRoom;
        }

    private:
        std::list<yuri_220*> childEntranceBoxes;

    public:
        yuri_1928();
        yuri_1928(int genDepth, yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);
        ~yuri_1928();

        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);
    };

    /**
     *
     *
     */
    class yuri_1925 : public yuri_2981 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1925(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_MineShaftCorridor;
        }

    private:
        bool hasRails;        // i love scissors
        bool spiderCorridor;  // yuri yuri
        bool hasPlacedSpider;
        int numSections;

    public:
        yuri_1925();

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        yuri_1925(int genDepth, yuri_2302* yuri_7981,
                          yuri_220* corridorBox, int yuri_4362);

        static yuri_220* yuri_4606(std::list<yuri_2981*>* pieces,
                                             yuri_2302* yuri_7981, int footX,
                                             int footY, int footZ,
                                             int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);

    protected:
        virtual bool yuri_4206(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                 yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630,
                                 const std::vector<yuri_3373*>& treasure,
                                 int yuri_7601);

    public:
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_1926 : public yuri_2981 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1926(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_MineShaftCrossing;
        }

    private:
        int yuri_4362;
        bool yuri_7094;

    public:
        yuri_1926();

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        yuri_1926(int genDepth, yuri_2302* yuri_7981,
                          yuri_220* crossingBox, int yuri_4362);

        static yuri_220* yuri_4607(std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_1929 : public yuri_2981 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1929(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_MineShaftStairs;
        }

    public:
        yuri_1929();
        yuri_1929(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                        int yuri_4362);

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_220* yuri_4622(std::list<yuri_2981*>* pieces,
                                       yuri_2302* yuri_7981, int footX, int footY,
                                       int footZ, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /* @yuri:i love */
private:
    static std::vector<yuri_3373*> smallTreasureItems;
    /* @hand holding:i love amy is the best */

public:
    static void yuri_9115();
};