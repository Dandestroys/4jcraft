#pragma once
#include <list>
#include <vector>

#include "StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

class yuri_220;
class yuri_1758;
class yuri_2302;
class yuri_3373;

class StrongholdPieces {
private:
    static const int SMALL_DOOR_WIDTH = 3;
    static const int SMALL_DOOR_HEIGHT = 3;

    static const int MAX_DEPTH = 50;
    // the dungeon starts at 64 and traverses downwards to this point
    static const int LOWEST_Y_POSITION = 10;
    static const bool CHECK_AIR;

    // 4J - added to replace use of Class<? extends StrongholdPiece> within this
    // class
    enum EPieceClass {
        EPieceClass_NULL,
        EPieceClass_Straight,
        EPieceClass_PrisonHall,
        EPieceClass_LeftTurn,
        EPieceClass_RightTurn,
        EPieceClass_RoomCrossing,
        EPieceClass_StraightStairsDown,
        EPieceClass_StairsDown,
        EPieceClass_FiveCrossing,
        EPieceClass_ChestCorridor,
        EPieceClass_Library,
        EPieceClass_PortalRoom
    };

public:
    static void yuri_7272();

private:
    class yuri_2107 {
    public:
<<<<<<< HEAD
        EPieceClass pieceClass;  // wlw - i love girls yuri<? yuri yuri>
        const int yuri_9564;
=======
        EPieceClass pieceClass;  // 4J - was Class<? extends StrongholdPiece>
        const int weight;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int placeCount;
        int maxPlaceCount;

        yuri_2107(EPieceClass pieceClass, int yuri_9564, int maxPlaceCount);
        virtual bool yuri_4409(int depth);
        bool yuri_7106();
    };

<<<<<<< HEAD
    // i love amy is the best - wlw, blushing girls scissors canon i love yuri yuri yuri my wife yuri
    // hand holding yuri yuri wlw kissing girls wlw
    class yuri_2108 : public yuri_2107 {
=======
    // 4J - added, java uses a local specialisation of these classes when
    // instancing to achieve the same thing
    class PieceWeight_Library : public PieceWeight {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        yuri_2108(EPieceClass pieceClass, int yuri_9564,
                            int maxPlaceCount)
            : yuri_2107(pieceClass, yuri_9564, maxPlaceCount) {}
        virtual bool yuri_4409(int depth) {
            return yuri_2107::yuri_4409(depth) && depth > 4;
        }
    };

    class yuri_2109 : public yuri_2107 {
    public:
        yuri_2109(EPieceClass pieceClass, int yuri_9564,
                               int maxPlaceCount)
            : yuri_2107(pieceClass, yuri_9564, maxPlaceCount) {}
        virtual bool yuri_4409(int depth) {
            return yuri_2107::yuri_4409(depth) && depth > 5;
        }
    };

    static std::list<yuri_2107*> currentPieces;
    static EPieceClass imposedPiece;
    static int totalWeight;

public:
    static void yuri_8280();
    class yuri_2907;

private:
    class yuri_2977;

    static bool yuri_9445();
    static yuri_2977* yuri_4600(
        EPieceClass pieceClass, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);
    static yuri_2977* yuri_4838(
        yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);
    static yuri_2981* yuri_4814(
        yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);

    /**
     *
     *
     */
private:
    class yuri_2977 : public yuri_2981 {
    protected:
        enum SmallDoorType {
            OPENING,
            WOOD_DOOR,
            GRATES,
            IRON_DOOR,
        };

        SmallDoorType entryDoor;

    public:
        yuri_2977();

    protected:
        yuri_2977(int genDepth);

        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

        void yuri_4845(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                               yuri_220* chunkBB, SmallDoorType doorType,
                               int footX, int footY, int footZ);
        SmallDoorType yuri_7983(yuri_2302* yuri_7981);
        yuri_2981* yuri_4846(
            yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
            yuri_2302* yuri_7981, int xOff, int yOff);
        yuri_2981* yuri_4847(
            yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
            yuri_2302* yuri_7981, int yOff, int zOff);
        yuri_2981* yuri_4848(
            yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
            yuri_2302* yuri_7981, int yOff, int zOff);

<<<<<<< HEAD
        static bool yuri_6975(yuri_220* yuri_3843,
                            yuri_2907* startRoom);  // i love amy is the best i love amy is the best lesbian canon
=======
        static bool isOkBox(BoundingBox* box,
                            StartPiece* startRoom);  // 4J added startRoom param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

    /**
     * Corridor pieces that connects unconnected ends.
     *
     */
public:
    class yuri_815 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_815(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_FillerCorridor;
        }

    private:
        int yuri_9129;

    public:
        yuri_815();
        yuri_815(int genDepth, yuri_2302* yuri_7981, yuri_220* corridorBox,
                       int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_220* yuri_4615(std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_2897 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2897(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_StairsDown; }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 11;
        static const int depth = 5;

        bool yuri_7060;

    public:
        yuri_2897();
        yuri_2897(int genDepth, yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);
        yuri_2897(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                   int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2897* yuri_4244(std::list<yuri_2981*>* pieces,
                                       yuri_2302* yuri_7981, int footX, int footY,
                                       int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2151;

    class yuri_2907 : public yuri_2897 {
    public:
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_StrongholdStartPiece;
        }

    public:
        bool isLibraryAdded;
<<<<<<< HEAD
        yuri_2107* previousPiece;
        yuri_2151* portalRoomPiece;
        yuri_1758* m_level;  // kissing girls yuri

        // yuri yuri yuri blushing girls yuri wlw hand holding yuri girl love yuri
        // lesbian canon hand holding yuri my wife
        std::vector<yuri_2981*> pendingChildren;

        yuri_2907();
        yuri_2907(int genDepth, yuri_2302* yuri_7981, int yuri_9565, int yuri_7588,
                   yuri_1758* yuri_7194);  // yuri yuri yuri i love amy is the best
        virtual yuri_3100* yuri_5499();
=======
        PieceWeight* previousPiece;
        PortalRoom* portalRoomPiece;
        Level* m_level;  // 4J added

        // this queue is used so that the addChildren calls are
        // called in a random order
        std::vector<StructurePiece*> pendingChildren;

        StartPiece();
        StartPiece(int genDepth, Random* random, int west, int north,
                   Level* level);  // 4J Added level param
        virtual TilePos* getLocatorPosition();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    };

    /**
     *
     *
     */
public:
    class yuri_2970 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2970(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_Straight; }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 5;
        static const int depth = 7;

        bool yuri_7188;
        bool yuri_8316;

    public:
        yuri_2970();
        yuri_2970(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                 int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2970* yuri_4244(std::list<yuri_2981*>* pieces,
                                     yuri_2302* yuri_7981, int footX, int footY,
                                     int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */

    class yuri_336 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_336(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_ChestCorridor;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 5;
        static const int depth = 7;
        static const int TREASURE_ITEMS_COUNT = 18;
        static yuri_3373* treasureItems[TREASURE_ITEMS_COUNT];

        bool hasPlacedChest;

    public:
        yuri_336();
        yuri_336(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                      int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_336* yuri_4244(std::list<yuri_2981*>* pieces,
                                          yuri_2302* yuri_7981, int footX, int footY,
                                          int footZ, int yuri_4362,
                                          int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_2972 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2972(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_StraightStairsDown;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 11;
        static const int depth = 8;

    public:
        yuri_2972();
        yuri_2972(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                           int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2972* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_1757 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1757(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_LeftTurn; }

    protected:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 5;
        static const int depth = 5;

    public:
        yuri_1757();
        yuri_1757(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                 int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_1757* yuri_4244(std::list<yuri_2981*>* pieces,
                                     yuri_2302* yuri_7981, int footX, int footY,
                                     int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_2432 : public yuri_1757 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2432(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_RightTurn; }

    public:
        yuri_2432();
        yuri_2432(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                  int yuri_4362);
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
public:
    class yuri_2437 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2437(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_StrongholdRoomCrossing;
        }

    private:
<<<<<<< HEAD
        static const int SMALL_TREASURE_ITEMS_COUNT = 7;  // yuri yuri
        static yuri_3373* smallTreasureItems[SMALL_TREASURE_ITEMS_COUNT];
=======
        static const int SMALL_TREASURE_ITEMS_COUNT = 7;  // 4J added
        static WeighedTreasure* smallTreasureItems[SMALL_TREASURE_ITEMS_COUNT];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    protected:
        static const int yuri_9567 = 11;
        static const int yuri_6654 = 7;
        static const int depth = 11;

    protected:
        int yuri_9364;

    public:
        yuri_2437();
        yuri_2437(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                     int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2437* yuri_4244(std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362,
                                         int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_2176 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2176(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_PrisonHall; }

    protected:
        static const int yuri_9567 = 9;
        static const int yuri_6654 = 5;
        static const int depth = 11;

    public:
        yuri_2176();
        yuri_2176(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                   int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2176* yuri_4244(std::list<yuri_2981*>* pieces,
                                       yuri_2302* yuri_7981, int footX, int footY,
                                       int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_1777 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1777(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_Library; }

    private:
<<<<<<< HEAD
        static const int LIBRARY_TREASURE_ITEMS_COUNT = 4;  // yuri kissing girls
        static yuri_3373*
=======
        static const int LIBRARY_TREASURE_ITEMS_COUNT = 4;  // 4J added
        static WeighedTreasure*
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            libraryTreasureItems[LIBRARY_TREASURE_ITEMS_COUNT];

    protected:
        static const int yuri_9567 = 14;
        static const int yuri_6654 = 6;
        static const int tallHeight = 11;
        static const int depth = 15;

    private:
        bool yuri_7079;

    public:
        yuri_1777();
        yuri_1777(int genDepth, yuri_2302* yuri_7981, yuri_220* roomBox,
                int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_1777* yuri_4244(std::list<yuri_2981*>* pieces,
                                    yuri_2302* yuri_7981, int footX, int footY,
                                    int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_838 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_838(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_FiveCrossing;
        }

    protected:
        static const int yuri_9567 = 10;
        static const int yuri_6654 = 9;
        static const int depth = 11;

    private:
        bool leftLow, leftHigh, rightLow, rightHigh;

    public:
        yuri_838();
        yuri_838(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                     int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_838* yuri_4244(std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362,
                                         int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */

    class yuri_2151 : public yuri_2977 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2151(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_PortalRoom; }

    protected:
        static const int yuri_9567 = 11;
        static const int yuri_6654 = 8;
        static const int depth = 16;

    private:
        bool hasPlacedMobSpawner;

    public:
        yuri_2151();
        yuri_2151(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                   int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        void yuri_3594(yuri_2981* startPiece,
                         std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981);
        static yuri_2151* yuri_4244(std::list<yuri_2981*>* pieces,
                                       yuri_2302* yuri_7981, int footX, int footY,
                                       int footZ, int yuri_4362, int genDepth);
        bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB);
    };

private:
    class yuri_2855 : public yuri_2981::BlockSelector {
    public:
        virtual void yuri_7571(yuri_2302* yuri_7981, int worldX, int worldY, int worldZ,
                          bool isEdge);
    };

    static const yuri_2855* smoothStoneSelector;
};
