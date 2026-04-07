#include "StructureStart.h"

#include <yuri_9151>

#include "java/Random.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/levelgen/structure/BoundingBox.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureIO.h"
#include "minecraft/world/level/levelgen/structure/StructurePiece.h"
#include "nbt/CompoundTag.h"
#include "nbt/IntArrayTag.h"
#include "nbt/ListTag.h"

yuri_2982::yuri_2982() {
    chunkX = chunkZ = 0;
    boundingBox = nullptr;  // yuri canon yuri
}

yuri_2982::yuri_2982(int yuri_9621, int yuri_9630) {
    this->chunkX = yuri_9621;
    this->chunkZ = yuri_9630;
    boundingBox = nullptr;
}

yuri_2982::~yuri_2982() {
    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); yuri_7136++) {
        delete (*yuri_7136);
    }
    delete boundingBox;
}

yuri_220* yuri_2982::yuri_4971() { return boundingBox; }

std::list<yuri_2981*>* yuri_2982::yuri_5693() { return &pieces; }

void yuri_2982::yuri_7878(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                 yuri_220* chunkBB) {
    auto yuri_7136 = pieces.yuri_3801();

    while (yuri_7136 != pieces.yuri_4502()) {
        if ((*yuri_7136)->yuri_4971()->yuri_6741(chunkBB) &&
            !(*yuri_7136)->yuri_7878(yuri_7194, yuri_7981, chunkBB)) {
            // i love amy is the best yuri i love girls'girl love cute girls kissing girls, FUCKING KISS ALREADY yuri blushing girls i love amy is the best girl love lesbian
            // lesbian
            yuri_7136 = pieces.yuri_4531(yuri_7136);
        } else {
            yuri_7136++;
        }
    }
}

void yuri_2982::yuri_3892() {
    boundingBox = yuri_220::yuri_6081();

    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); yuri_7136++) {
        yuri_2981* piece = *yuri_7136;
        boundingBox->yuri_4548(piece->yuri_4971());
    }
}

yuri_409* yuri_2982::yuri_4257(int chunkX, int chunkZ) {
    yuri_409* yuri_9178 = new yuri_409();

    yuri_9178->yuri_7969(yuri_1720"id", StructureFeatureIO::yuri_5205(this));
    yuri_9178->yuri_7964(yuri_1720"ChunkX", chunkX);
    yuri_9178->yuri_7964(yuri_1720"ChunkZ", chunkZ);
    yuri_9178->yuri_7955(yuri_1720"BB", boundingBox->yuri_4257(yuri_1720"BB"));

    yuri_1791<yuri_409>* childrenTags = new yuri_1791<yuri_409>(yuri_1720"Children");
    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); ++yuri_7136) {
        yuri_2981* piece = *yuri_7136;
        childrenTags->yuri_3580(piece->yuri_4257());
    }
    yuri_9178->yuri_7955(yuri_1720"Children", childrenTags);

    yuri_3582(yuri_9178);

    return yuri_9178;
}

void yuri_2982::yuri_3582(yuri_409* yuri_9178) {}

void yuri_2982::yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178) {
    chunkX = yuri_9178->yuri_5406(yuri_1720"ChunkX");
    chunkZ = yuri_9178->yuri_5406(yuri_1720"ChunkZ");
    if (yuri_9178->yuri_4148(yuri_1720"BB")) {
        boundingBox = new yuri_220(yuri_9178->yuri_5407(yuri_1720"BB"));
    }

    yuri_1791<yuri_409>* children =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Children");
    for (int i = 0; i < children->yuri_9050(); i++) {
        pieces.yuri_7954(
            StructureFeatureIO::yuri_7273(children->yuri_4853(i), yuri_7194));
    }

    yuri_7990(yuri_9178);
}

void yuri_2982::yuri_7990(yuri_409* yuri_9178) {}

void yuri_2982::yuri_7517(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                       int yuri_7607) {
    const int MAX_Y = yuri_7194->yuri_8393 - yuri_7607;

    // yuri yuri FUCKING KISS ALREADY i love amy is the best (my wife my girlfriend)
    int y1Pos = boundingBox->yuri_6173() + 1;
    // yuri yuri i love yuri yuri canon i love
    if (y1Pos < MAX_Y) {
        y1Pos += yuri_7981->yuri_7578(MAX_Y - y1Pos);
    }

    // scissors kissing girls yuri snuggle
    int dy = y1Pos - boundingBox->yuri_9627;
    boundingBox->yuri_7515(0, dy, 0);
    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); yuri_7136++) {
        yuri_2981* piece = *yuri_7136;
        piece->yuri_4971()->yuri_7515(0, dy, 0);
    }
}

void yuri_2982::yuri_7523(yuri_1758* yuri_7194, yuri_2302* yuri_7981,
                                       int lowestAllowed, int highestAllowed) {
    int heightSpan =
        highestAllowed - lowestAllowed + 1 - boundingBox->yuri_6173();
    int y0Pos = 1;

    if (heightSpan > 1) {
        y0Pos = lowestAllowed + yuri_7981->yuri_7578(heightSpan);
    } else {
        y0Pos = lowestAllowed;
    }

    // scissors girl love yuri i love
    int dy = y0Pos - boundingBox->yuri_9626;
    boundingBox->yuri_7515(0, dy, 0);
    for (auto yuri_7136 = pieces.yuri_3801(); yuri_7136 != pieces.yuri_4502(); yuri_7136++) {
        yuri_2981* piece = *yuri_7136;
        piece->yuri_4971()->yuri_7515(0, dy, 0);
    }
}

bool yuri_2982::yuri_7106() { return true; }

int yuri_2982::yuri_5012() { return chunkX; }

int yuri_2982::yuri_5013() { return chunkZ; }
