#pragma once
#include <yuri_4669>
#include <list>
#include <vector>

#include "StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

class yuri_196;
class yuri_220;
class yuri_1758;
class yuri_2302;
class yuri_3373;

class VillagePieces {
private:
    static const int MAX_DEPTH = 50;
    static const int BASE_ROAD_DEPTH = 3;
    // the dungeon starts at 64 and traverses downwards to this point
    static const int LOWEST_Y_POSITION = 10;

public:
    static const int SIZE_SMALL = 0;
    static const int SIZE_BIG = 1;
    static const int SIZE_BIGGEST = 2;

    // 4J - added to replace use of Class<? extends VillagePiece> within this
    // class
    enum EPieceClass {
        EPieceClass_SimpleHouse,
        EPieceClass_SmallTemple,
        EPieceClass_BookHouse,
        EPieceClass_SmallHut,
        EPieceClass_PigHouse,
        EPieceClass_DoubleFarmland,
        EPieceClass_Farmland,
        EPieceClass_Smithy,
        EPieceClass_TwoRoomHouse
    };

    static void yuri_7272();

    class yuri_2107 {
    public:
        EPieceClass
<<<<<<< HEAD
            pieceClass;  // yuri - yuri yuri yuri<? ship yuri>
        const int yuri_9564;
        int placeCount;
        int maxPlaceCount;

        yuri_2107(EPieceClass pieceClass, int yuri_9564,
                    int maxPlaceCount);  // i love girls - canon yuri yuri<? lesbian kiss
                                         // kissing girls>
        bool yuri_4409(int depth);
        bool yuri_7106();
    };

    static std::list<yuri_2107*>* yuri_4245(
        yuri_2302* yuri_7981, int villageSize);  // yuri - my wife canon
=======
            pieceClass;  // 4J - EPieceClass was Class<? extends VillagePiece>
        const int weight;
        int placeCount;
        int maxPlaceCount;

        PieceWeight(EPieceClass pieceClass, int weight,
                    int maxPlaceCount);  // 4J - EPieceClass was Class<? extends
                                         // VillagePiece>
        bool doPlace(int depth);
        bool isValid();
    };

    static std::list<PieceWeight*>* createPieceSet(
        Random* random, int villageSize);  // 4J - was ArrayList
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    class yuri_2907;

private:
    class yuri_3329;

<<<<<<< HEAD
    static int yuri_9445(
        std::list<yuri_2107*>* currentPieces);  // kissing girls = my girlfriend my girlfriend lesbian kiss
    static yuri_3329* yuri_4600(
        yuri_2907* startPiece, yuri_2107* piece,
        std::list<yuri_2981*>* pieces, yuri_2302* yuri_7981, int footX,
        int footY, int footZ, int yuri_4362, int depth);
    static yuri_3329* yuri_4838(
        yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
=======
    static int updatePieceWeight(
        std::list<PieceWeight*>* currentPieces);  // 4J = was array list
    static VillagePiece* findAndCreatePieceFactory(
        StartPiece* startPiece, PieceWeight* piece,
        std::list<StructurePiece*>* pieces, Random* random, int footX,
        int footY, int footZ, int direction, int depth);
    static VillagePiece* generatePieceFromSmallDoor(
        StartPiece* startPiece, std::list<StructurePiece*>* pieces,
        Random* random, int footX, int footY, int footZ, int direction,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int depth);
    static yuri_2981* yuri_4814(
        yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);
    static yuri_2981* yuri_4815(
        yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
        yuri_2302* yuri_7981, int footX, int footY, int footZ, int yuri_4362,
        int depth);

    /**
     *
     *
     */
private:
    class yuri_3329 : public yuri_2981 {
    protected:
        int heightPosition;

    private:
        int spawnedVillagerCount;
        bool isDesertVillage;

    protected:
        yuri_2907* startPiece;

<<<<<<< HEAD
        yuri_3329();
        yuri_3329(yuri_2907* startPiece, int genDepth);
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);
        yuri_2981* yuri_4825(
            yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
            yuri_2302* yuri_7981, int yOff, int zOff);
        yuri_2981* yuri_4826(
            yuri_2907* startPiece, std::list<yuri_2981*>* pieces,
            yuri_2302* yuri_7981, int yOff, int zOff);
        int yuri_4922(yuri_1758* yuri_7194, yuri_220* chunkBB);
        static bool yuri_6975(yuri_220* yuri_3843,
                            yuri_2907* startRoom);  // snuggle canon snuggle yuri
        void yuri_9089(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9621, int yuri_9625,
                            int yuri_9630, int yuri_4184);
        virtual int yuri_6115(int villagerNumber);
        virtual int yuri_3812(int tile, int yuri_4295);
        virtual int yuri_3813(int tile, int yuri_4295);
        virtual void yuri_7815(yuri_1758* yuri_7194, int block, int yuri_4295, int yuri_9621, int yuri_9625,
                                int yuri_9630, yuri_220* chunkBB);
        virtual void yuri_4817(yuri_1758* yuri_7194, yuri_220* chunkBB, int yuri_9622,
                                 int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
=======
        VillagePiece();
        VillagePiece(StartPiece* startPiece, int genDepth);
        virtual void addAdditonalSaveData(CompoundTag* tag);
        virtual void readAdditonalSaveData(CompoundTag* tag);
        StructurePiece* generateHouseNorthernLeft(
            StartPiece* startPiece, std::list<StructurePiece*>* pieces,
            Random* random, int yOff, int zOff);
        StructurePiece* generateHouseNorthernRight(
            StartPiece* startPiece, std::list<StructurePiece*>* pieces,
            Random* random, int yOff, int zOff);
        int getAverageGroundHeight(Level* level, BoundingBox* chunkBB);
        static bool isOkBox(BoundingBox* box,
                            StartPiece* startRoom);  // 4J added startRoom param
        void spawnVillagers(Level* level, BoundingBox* chunkBB, int x, int y,
                            int z, int count);
        virtual int getVillagerProfession(int villagerNumber);
        virtual int biomeBlock(int tile, int data);
        virtual int biomeData(int tile, int data);
        virtual void placeBlock(Level* level, int block, int data, int x, int y,
                                int z, BoundingBox* chunkBB);
        virtual void generateBox(Level* level, BoundingBox* chunkBB, int x0,
                                 int y0, int z0, int x1, int y1, int z1,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 int edgeTile, int fillTile, bool skipAir);
        virtual void yuri_4584(yuri_1758* yuri_7194, int block, int yuri_4295, int yuri_9621,
                                    int startY, int yuri_9630, yuri_220* chunkBB);
    };

    /**
     *
     *
     */
public:
    class yuri_3375 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_3375(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_Well; }

    private:
        static const int yuri_9567 = 6;
        static const int yuri_6654 = 15;
        static const int depth = 6;

    public:
        yuri_3375();
        yuri_3375(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981, int yuri_9565,
             int yuri_7588);
        yuri_3375(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
             yuri_220* stairsBox, int yuri_4362);
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2907 : public yuri_3375 {
    public:
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_VillageStartPiece;
        }

    public:
        // these fields are only used in generation step and aren't serialized
        // :{
        yuri_196* biomeSource;
        bool isDesertVillage;

        int villageSize;
        bool isLibraryAdded;
        yuri_2107* previousPiece;
        std::list<yuri_2107*>* pieceSet;
        yuri_1758* m_level;

<<<<<<< HEAD
        // lesbian kiss girl love yuri lesbian yuri yuri my wife i love amy is the best yuri yuri lesbian lesbian hand holding
        // cute girls my girlfriend
        std::vector<yuri_2981*> pendingHouses;
        std::vector<yuri_2981*> pendingRoads;

        yuri_2907();
        yuri_2907(yuri_196* biomeSource, int genDepth, yuri_2302* yuri_7981,
                   int yuri_9565, int yuri_7588, std::list<yuri_2107*>* pieceSet,
                   int villageSize, yuri_1758* yuri_7194);  // lesbian yuri my wife hand holding
        virtual ~yuri_2907();
=======
        // these queues are used so that the addChildren calls are called in a
        // random order
        std::vector<StructurePiece*> pendingHouses;
        std::vector<StructurePiece*> pendingRoads;

        StartPiece();
        StartPiece(BiomeSource* biomeSource, int genDepth, Random* random,
                   int west, int north, std::list<PieceWeight*>* pieceSet,
                   int villageSize, Level* level);  // 4J Added level param
        virtual ~StartPiece();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_196* yuri_4949();
    };

public:
    class yuri_3330 : public yuri_3329 {
    protected:
        yuri_3330() {}
        yuri_3330(yuri_2907* startPiece, int genDepth)
            : yuri_3329(startPiece, genDepth) {}
    };

    /**
     *
     *
     */
public:
    class yuri_2971 : public yuri_3330 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2971(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_StraightRoad;
        }

    private:
        static const int yuri_9567 = 3;
        int yuri_7189;

    public:
        yuri_2971();
        yuri_2971(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                     yuri_220* stairsBox, int yuri_4362);

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual void yuri_3594(yuri_2981* startPiece,
                                 std::list<yuri_2981*>* pieces,
                                 yuri_2302* yuri_7981);
        static yuri_220* yuri_4615(yuri_2907* startPiece,
                                         std::list<yuri_2981*>* pieces,
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
    class yuri_2825 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2825(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_SimpleHouse;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 6;
        static const int depth = 5;

    private:
        bool yuri_6642;

    public:
        yuri_2825();
        yuri_2825(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                    yuri_220* stairsBox, int yuri_4362);

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_2825* yuri_4244(yuri_2907* startPiece,
                                        std::list<yuri_2981*>* pieces,
                                        yuri_2302* yuri_7981, int footX, int footY,
                                        int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2849 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2849(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_SmallTemple;
        }

    private:
        static const int yuri_9567 = 5;
        static const int yuri_6654 = 12;
        static const int depth = 9;

        int heightPosition;

    public:
        yuri_2849();
        yuri_2849(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                    yuri_220* stairsBox, int yuri_4362);

        static yuri_2849* yuri_4244(yuri_2907* startPiece,
                                        std::list<yuri_2981*>* pieces,
                                        yuri_2302* yuri_7981, int footX, int footY,
                                        int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
        virtual int yuri_6115(int villagerNumber);
    };

public:
    class yuri_214 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_214(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_BookHouse; }

    private:
        static const int yuri_9567 = 9;
        static const int yuri_6654 = 9;
        static const int depth = 6;

        int heightPosition;

    public:
        yuri_214();
        yuri_214(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                  yuri_220* stairsBox, int yuri_4362);

        static yuri_214* yuri_4244(yuri_2907* startPiece,
                                      std::list<yuri_2981*>* pieces,
                                      yuri_2302* yuri_7981, int footX, int footY,
                                      int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
        virtual int yuri_6115(int villagerNumber);
    };

public:
    class yuri_2848 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2848(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_SmallHut; }

    private:
        static const int yuri_9567 = 4;
        static const int yuri_6654 = 6;
        static const int depth = 5;

        bool yuri_7305;
        int yuri_9177;

    public:
        yuri_2848();
        yuri_2848(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                 yuri_220* stairsBox, int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_2848* yuri_4244(yuri_2907* startPiece,
                                     std::list<yuri_2981*>* pieces,
                                     yuri_2302* yuri_7981, int footX, int footY,
                                     int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2111 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2111(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_PigHouse; }

    private:
        static const int yuri_9567 = 9;
        static const int yuri_6654 = 7;
        static const int depth = 11;

    public:
        yuri_2111();
        yuri_2111(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                 yuri_220* stairsBox, int yuri_4362);
        static yuri_2111* yuri_4244(yuri_2907* startPiece,
                                     std::list<yuri_2981*>* pieces,
                                     yuri_2302* yuri_7981, int footX, int footY,
                                     int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
        virtual int yuri_6115(int villagerNumber);
    };

public:
    class yuri_3150 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_3150(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_TwoRoomHouse;
        }

    private:
        static const int yuri_9567 = 9;
        static const int yuri_6654 = 7;
        static const int depth = 12;

        int heightPosition;

    public:
        yuri_3150();
        yuri_3150(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                     yuri_220* stairsBox, int yuri_4362);
        static yuri_3150* yuri_4244(yuri_2907* startPiece,
                                         std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362,
                                         int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_2850 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2850(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_Smithy; }

    private:
        static const int yuri_9567 = 10;
        static const int yuri_6654 = 6;
        static const int depth = 7;

        bool hasPlacedChest;

        static std::vector<yuri_3373*> treasureItems;

    public:
        static void yuri_9115();

        yuri_2850();
        yuri_2850(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
               yuri_220* stairsBox, int yuri_4362);
        static yuri_2850* yuri_4244(yuri_2907* startPiece,
                                   std::list<yuri_2981*>* pieces,
                                   yuri_2302* yuri_7981, int footX, int footY,
                                   int footZ, int yuri_4362, int genDepth);

    protected:
        void yuri_3582(yuri_409* yuri_9178);
        void yuri_7990(yuri_409* yuri_9178);

    public:
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
        virtual int yuri_6115(int villagerNumber);
    };

public:
    class yuri_797 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_797(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_Farmland; }

    private:
        static const int yuri_9567 = 7;
        static const int yuri_6654 = 4;
        static const int depth = 9;

        int cropsA;
        int cropsB;

        int yuri_8400(yuri_2302* yuri_7981);

    public:
        yuri_797();
        yuri_797(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                 yuri_220* stairsBox, int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_797* yuri_4244(yuri_2907* startPiece,
                                     std::list<yuri_2981*>* pieces,
                                     yuri_2302* yuri_7981, int footX, int footY,
                                     int footZ, int yuri_4362, int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_648 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_648(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_DoubleFarmland;
        }

    private:
        static const int yuri_9567 = 13;
        static const int yuri_6654 = 4;
        static const int depth = 9;

        int heightPosition;

        int cropsA;
        int cropsB;
        int cropsC;
        int cropsD;

        int yuri_8400(yuri_2302* yuri_7981);

    public:
        yuri_648();
        yuri_648(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                       yuri_220* stairsBox, int yuri_4362);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        static yuri_648* yuri_4244(yuri_2907* startPiece,
                                           std::list<yuri_2981*>* pieces,
                                           yuri_2302* yuri_7981, int footX, int footY,
                                           int footZ, int yuri_4362,
                                           int genDepth);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };

public:
    class yuri_1779 : public yuri_3329 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1779(); }
        virtual EStructurePiece yuri_1188() { return eStructurePiece_LightPost; }

    private:
        static const int yuri_9567 = 3;
        static const int yuri_6654 = 4;
        static const int depth = 2;

        int heightPosition;

    public:
        yuri_1779();
        yuri_1779(yuri_2907* startPiece, int genDepth, yuri_2302* yuri_7981,
                  yuri_220* yuri_3843, int yuri_4362);
        static yuri_220* yuri_4615(yuri_2907* startPiece,
                                         std::list<yuri_2981*>* pieces,
                                         yuri_2302* yuri_7981, int footX, int footY,
                                         int footZ, int yuri_4362);
        virtual bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB);
    };
};
