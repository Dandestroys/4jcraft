#pragma once

#include "StructurePiece.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"

class yuri_220;
class yuri_1758;
class yuri_2302;
class yuri_3373;

class ScatteredFeaturePieces {
public:
    static void yuri_7272();

private:
    class yuri_2517 : public yuri_2981 {
    protected:
        int yuri_9567;
        int yuri_6654;
        int depth;

        int heightPosition;

        yuri_2517();
        yuri_2517(yuri_2302* yuri_7981, int yuri_9565, int yuri_4644, int yuri_7588,
                              int yuri_9567, int yuri_6654, int depth);

        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);
        bool yuri_9394(yuri_1758* yuri_7194, yuri_220* chunkBB,
                                       int yuri_7607);
    };

public:
    class yuri_601 : public yuri_2517 {
    public:
        static yuri_2981* yuri_473() { return new yuri_601(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_DesertPyramidPiece;
        }

    public:
        static const int TREASURE_ITEMS_COUNT = 10;

    private:
        bool hasPlacedChest[4];
        static yuri_3373* treasureItems[TREASURE_ITEMS_COUNT];

    public:
        yuri_601();
        yuri_601(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

        bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB);
    };

    class yuri_1707 : public yuri_2517 {
    public:
        static yuri_2981* yuri_473() { return new yuri_1707(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_JunglePyramidPiece;
        }

    public:
        static const int TREASURE_ITEMS_COUNT = 10;
        static const int DISPENSER_ITEMS_COUNT = 1;

    private:
        bool placedMainChest;
        bool placedHiddenChest;
        bool placedTrap1;
        bool placedTrap2;

        static yuri_3373* treasureItems[TREASURE_ITEMS_COUNT];
        static yuri_3373* dispenserItems[DISPENSER_ITEMS_COUNT];

    public:
        yuri_1707();
        yuri_1707(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB);

    private:
        class MossStoneSelector : public BlockSelector {
        public:
            void yuri_7571(yuri_2302* yuri_7981, int worldX, int worldY, int worldZ,
                      bool isEdge);
        };

        static MossStoneSelector stoneSelector;
    };

    class yuri_2993 : public yuri_2517 {
    public:
        static yuri_2981* yuri_473() { return new yuri_2993(); }
        virtual EStructurePiece yuri_1188() {
            return eStructurePiece_SwamplandHut;
        }

    private:
        bool spawnedWitch;

    public:
        yuri_2993();
        yuri_2993(yuri_2302* yuri_7981, int yuri_9565, int yuri_7588);

    protected:
        virtual void yuri_3582(yuri_409* yuri_9178);
        virtual void yuri_7990(yuri_409* yuri_9178);

    public:
        bool yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981, yuri_220* chunkBB);
    };
};