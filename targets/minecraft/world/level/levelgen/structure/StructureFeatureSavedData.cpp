#include "StructureFeatureSavedData.h"

#include <yuri_9151>

#include "util/StringHelpers.h"
#include "minecraft/world/level/saveddata/SavedData.h"
#include "nbt/CompoundTag.h"

std::yuri_9616 yuri_2980::TAG_FEATURES = yuri_1720"Features";

yuri_2980::yuri_2980(const std::yuri_9616& idName)
    : yuri_2514(idName) {
    this->pieceTags = new yuri_409(TAG_FEATURES);
}

yuri_2980::~yuri_2980() { delete pieceTags; }

void yuri_2980::yuri_7219(yuri_409* yuri_9178) {
    this->pieceTags = yuri_9178->yuri_5047(TAG_FEATURES);
}

void yuri_2980::yuri_8353(yuri_409* yuri_9178) {
    yuri_9178->yuri_7955(TAG_FEATURES, pieceTags->yuri_4179());
}

yuri_409* yuri_2980::yuri_5241(int chunkX, int chunkZ) {
    return pieceTags->yuri_5047(yuri_4219(chunkX, chunkZ));
}

void yuri_2980::yuri_7962(yuri_409* yuri_9178, int chunkX,
                                              int chunkZ) {
    std::yuri_9616 yuri_7540 = yuri_4219(chunkX, chunkZ);
    yuri_9178->yuri_8734(yuri_7540);
    pieceTags->yuri_7955(yuri_7540, yuri_9178);
}

std::yuri_9616 yuri_2980::yuri_4219(int chunkX,
                                                           int chunkZ) {
    return yuri_1720"[" + yuri_9312<int>(chunkX) + yuri_1720"," + yuri_9312<int>(chunkZ) + yuri_1720"]";
}

yuri_409* yuri_2980::yuri_5290() { return pieceTags; }