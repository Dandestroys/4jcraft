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

class NetherBridgePieces {
private:
    static const int MAX_DEPTH = 30;
    // the dungeon starts at 64 and traverses downwards to this point
    static const int LOWEST_Y_POSITION = 10;

    // 4J - added to replace use of Class<? extends NetherBridgePiece> within
    // this class
    enum EPieceClass {
        EPieceClass_BridgeStraight,
        EPieceClass_BridgeEndFiller,
        EPieceClass_BridgeCrossing,
        EPieceClass_RoomCrossing,
        EPieceClass_StairsRoom,
        EPieceClass_MonsterThrone,
        EPieceClass_CastleEntrance,
        EPieceClass_CastleStalkRoom,
        EPieceClass_CastleSmallCorridorPiece,
        EPieceClass_CastleSmallCorridorCrossingPiece,
        EPieceClass_CastleSmallCorridorRightTurnPiece,
        EPieceClass_CastleSmallCorridorLeftTurnPiece,
        EPieceClass_CastleCorridorStairsPiece,
        EPieceClass_CastleCorridorTBalconyPiece
    };

public:
    static void yuri_7272();

private:
    class yuri_2107 {
    public:
        EPieceClass pieceClass;
        const int yuri_9564;
        int placeCount;
        int maxPlaceCount;
        bool allowInRow;

        yuri_2107(EPieceClass pieceClass, int yuri_9564, int maxPlaceCount,
                    bool allowInRow);
        yuri_2107(EPieceClass pieceClass, int yuri_9564, int maxPlaceCount);
        bool yuri_4409(int depth);
        bool yuri_7106();
    };

    static const int BRIDGE_PIECEWEIGHTS_COUNT = 6;
    static const int CASTLE_PIECEWEIGHTS_COUNT = 7;
    static NetherBridgePieces::yuri_2107*
        bridgePieceWeights[BRIDGE_PIECEWEIGHTS_COUNT];
    static NetherBridgePieces::yuri_2107*
        castlePieceWeights[CASTLE_PIECEWEIGHTS_COUNT];

private:
    class yuri_2016;

    static yuri_2016* yuri_4599(
        NetherBridgePieces::yuri_2107* piece,
        std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
        int footY, int footZ, int yuri_4362, int depth);

    /**
     *
     *
     */
public:
    class yuri_2907;

private:
    class yuri_2016 : public yuri_2981 {
    protected:
        static const int FORTRESS_TREASURE_ITEMS_COUNT = 11;
        static yuri_3373*
            fortressTreasureItems[FORTRESS_TREASURE_ITEMS_COUNT];

    public:
        yuri_2016();

    protected:
        yuri_2016(int genDepth);

        virtual void yuri_7990(yuri_409* yuri_9178);
        virtual void yuri_3582(yuri_409* yuri_9178);

    private:
        int yuri_9445(std::list<yuri_2107*>* currentPieces);

        yuri_2016* yuri_4837(
            yuri_2907* startPiece,
            std::list<NetherBridgePieces::yuri_2107*>* currentPieces,
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int depth);
        yuri_2981* yuri_4814(yuri_2907* startPiece,
                                            std::list<yuri_2981*>* pieces,
                                            yuri_2302* yuri_7981, int footX,
                                            int footY, int footZ, int yuri_4362,
                                            int depth, bool isCastle);

    protected:
        yuri_2981* yuri_4819(yuri_2907* startPiece,
                                             std::list<yuri_2981*>* pieces,
                                             yuri_2302* yuri_7981, int xOff, int yOff,
                                             bool isCastle);
        yuri_2981* yuri_4820(yuri_2907* startPiece,
                                          std::list<yuri_2981*>* pieces,
                                          yuri_2302* yuri_7981, int yOff, int zOff,
                                          bool isCastle);
        yuri_2981* yuri_4821(yuri_2907* startPiece,
                                           std::list<yuri_2981*>* pieces,
                                           yuri_2302* yuri_7981, int yOff, int zOff,
                                           bool isCastle);

<<<<<<< HEAD
        static bool yuri_6975(yuri_220* yuri_3843,
                            yuri_2907* startRoom);  // yuri yuri i love my girlfriend
        void yuri_4827(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                               yuri_220* chunkBB, int yuri_9621, int yuri_9625, int yuri_9630,
=======
        static bool isOkBox(BoundingBox* box,
                            StartPiece* startRoom);  // 4J added startRoom param
        void generateLightPost(Level* level, Random* random,
                               BoundingBox* chunkBB, int x, int y, int z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               int xOff, int zOff);

        void yuri_4830(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                          yuri_220* chunkBB, int yuri_9621, int yuri_9625,
                                          int yuri_9630);
        void yuri_4829(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                         yuri_220* chunkBB, int yuri_9621, int yuri_9625,
                                         int yuri_9630);
        void yuri_4831(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                       yuri_220* chunkBB, int yuri_9621, int yuri_9625,
                                       int yuri_9630);
        void yuri_4828(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                         yuri_220* chunkBB, int yuri_9621, int yuri_9625,
                                         int yuri_9630);
    };

    /**
     *
     *
     */
    class yuri_233 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_233(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_BridgeStraight;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 10;
        static const int depth = 19;

    public:
        yuri_233();
        yuri_233(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                       int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_233* yuri_4244(std::list<yuri_2981*>* pieces,
                                           yuri_2302* yuri_7981, int footX, int footY,
                                           int footZ, int yuri_4362,
                                           int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    class yuri_232 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_232(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_BridgeEndFiller;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 10;
        static const int depth = 8;

        int selfSeed;

    public:
        yuri_232();
        yuri_232(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                        int yuri_4362);

        static yuri_232* yuri_4244(std::list<yuri_2981*>* pieces,
                                            yuri_2302* yuri_7981, int footX,
                                            int footY, int footZ, int yuri_4362,
                                            int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);

    protected:
        void yuri_7990(yuri_409* yuri_9178);
        void yuri_3582(yuri_409* yuri_9178);
    };

    class yuri_231 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_231(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_BridgeCrossing;
        }

    private:
        static const int yuri_9567 = 19;
        static const int yuri_6654 = 10;
        static const int depth = 19;

    public:
        yuri_231();
        yuri_231(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                       int yuri_4362);

    protected:
        yuri_231(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_231* yuri_4244(std::list<yuri_2981*>* pieces,
                                           yuri_2302* yuri_7981, int footX, int footY,
                                           int footZ, int yuri_4362,
                                           int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2907 : public yuri_231 {
    public:
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_NetherBridgeStartPiece;
        }

    public:
        yuri_2107* previousPiece;
        yuri_1758* m_level;

        std::list<yuri_2107*> availableBridgePieces;
        std::list<yuri_2107*> availableCastlePieces;

<<<<<<< HEAD
        // yuri girl love blushing girls my girlfriend yuri kissing girls yuri kissing girls snuggle i love girls
        // FUCKING KISS ALREADY yuri my girlfriend kissing girls i love girls
        std::vector<yuri_2981*> pendingChildren;

        yuri_2907();
        yuri_2907(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588,
                   yuri_1758* yuri_7194);  // yuri yuri yuri snuggle
=======
        // this queue is used so that the addChildren calls are
        // called in a random order
        std::vector<StructurePiece*> pendingChildren;

        StartPiece();
        StartPiece(Random* random, int west, int north,
                   Level* level);  // 4J Added level param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    protected:
        virtual void yuri_7990(yuri_409* yuri_9178);
        virtual void yuri_3582(yuri_409* yuri_9178);
    };

private:
    class yuri_2437 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2437(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_RoomCrossing;
        }

    private:
        static const int yuri_9567 = 7;
        static const int yuri_6654 = 9;
        static const int depth = 7;

    public:
        yuri_2437();
        yuri_2437(int genDepth, yuri_2302* yuri_7981, yuri_220* yuri_3843,
                     int yuri_4362);
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

    class yuri_2898 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2898(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_StairsRoom; }

    private:
        static const int yuri_9567 = 7;
        static const int yuri_6654 = 11;
        static const int depth = 7;

    public:
        yuri_2898();
        yuri_2898(int genDepth, yuri_2302* yuri_7981, yuri_220* yuri_3843,
                   int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_2898* yuri_4244(std::list<yuri_2981*>* pieces,
                                       yuri_2302* yuri_7981, int footX, int footY,
                                       int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    class yuri_1968 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1968(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_MonsterThrone;
        }

    private:
        static const int yuri_9567 = 7;
        static const int yuri_6654 = 8;
        static const int depth = 9;

        bool hasPlacedMobSpawner;

    public:
        yuri_1968();
        yuri_1968(int genDepth, yuri_2302* yuri_7981, yuri_220* yuri_3843,
                      int yuri_4362);

    protected:
        virtual void yuri_7990(yuri_409* yuri_9178);
        virtual void yuri_3582(yuri_409* yuri_9178);

    public:
        static yuri_1968* yuri_4244(std::list<yuri_2981*>* pieces,
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
    class yuri_315 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_315(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleEntrance;
        }

    private:
        static const int yuri_9567 = 13;
        static const int yuri_6654 = 14;
        static const int depth = 13;

    public:
        yuri_315();
        yuri_315(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                       int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_315* yuri_4244(std::list<yuri_2981*>* pieces,
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
    class yuri_320 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() { return new yuri_320(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleStalkRoom;
        }

    private:
        static const int yuri_9567 = 13;
        static const int yuri_6654 = 14;
        static const int depth = 13;

    public:
        yuri_320();
        yuri_320(int genDepth, yuri_2302* yuri_7981, yuri_220* stairsBox,
                        int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_320* yuri_4244(std::list<yuri_2981*>* pieces,
                                            yuri_2302* yuri_7981, int footX,
                                            int footY, int footZ, int yuri_4362,
                                            int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_318 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_318();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleSmallCorridorPiece;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 7;
        static const int depth = 5;

    public:
        yuri_318();
        yuri_318(int genDepth, yuri_2302* yuri_7981,
                                 yuri_220* stairsBox, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_318* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_316 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_316();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleSmallCorridorCrossingPiece;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 7;
        static const int depth = 5;

    public:
        yuri_316();
        yuri_316(int genDepth, yuri_2302* yuri_7981,
                                         yuri_220* stairsBox, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_316* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_319 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_319();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleSmallCorridorRightTurnPiece;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 7;
        static const int depth = 5;

        bool isNeedingChest;

    public:
        yuri_319();
        yuri_319(int genDepth, yuri_2302* yuri_7981,
                                          yuri_220* stairsBox,
                                          int yuri_4362);

    protected:
        virtual void yuri_7990(yuri_409* yuri_9178);
        virtual void yuri_3582(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_319* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_317 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_317();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleSmallCorridorLeftTurnPiece;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 7;
        static const int depth = 5;
        bool isNeedingChest;

    public:
        yuri_317();
        yuri_317(int genDepth, yuri_2302* yuri_7981,
                                         yuri_220* stairsBox, int yuri_4362);

    protected:
        virtual void yuri_7990(yuri_409* yuri_9178);
        virtual void yuri_3582(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_317* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_313 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_313();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleCorridorStairsPiece;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 14;
        static const int depth = 10;

    public:
        yuri_313();
        yuri_313(int genDepth, yuri_2302* yuri_7981,
                                  yuri_220* stairsBox, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_313* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

    /**
     *
     *
     */
    class yuri_314 : public yuri_2016 {
    public:
        static yuri_2981* yuri_473() {
            return new yuri_314();
        }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_CastleCorridorTBalconyPiece;
        }

    private:
        static const int yuri_9567 = 9;
        static const int yuri_6654 = 7;
        static const int depth = 9;

    public:
        yuri_314();
        yuri_314(int genDepth, yuri_2302* yuri_7981,
                                    yuri_220* stairsBox, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_314* yuri_4244(
            std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
            int footY, int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };
};
