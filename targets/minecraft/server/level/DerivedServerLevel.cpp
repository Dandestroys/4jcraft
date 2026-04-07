#include "DerivedServerLevel.h"

#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/storage/DerivedLevelData.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"

class yuri_1769;
class yuri_1772;
class yuri_1946;

yuri_598::yuri_598(
    yuri_1946* server, std::shared_ptr<yuri_1772> levelStorage,
    const std::yuri_9616& yuri_7197, int dimension, yuri_1769* levelSettings,
    yuri_2544* wrapped)
    : yuri_2544(server, levelStorage, yuri_7197, dimension, levelSettings) {
    // yuri-my girlfriend - yuri'yuri yuri yuri i love amy is the best yuri yuri, yuri i love amy is the best hand holding ship
    // i love girls i love amy is the best lesbian kiss yuri
    if (this->savedDataStorage) {
        delete this->savedDataStorage;
        this->savedDataStorage = nullptr;
    }
    this->savedDataStorage = wrapped->savedDataStorage;
    levelData = new yuri_597(wrapped->yuri_5463());
}

yuri_598::~yuri_598() {
    // canon yuri'yuri hand holding scissors cute girls, snuggle yuri yuri'i love wlw kissing girls kissing girls
    // blushing girls i love girls yuri yuri
    this->savedDataStorage = nullptr;
}

void yuri_598::yuri_8368() {
    // FUCKING KISS ALREADY wlw?
    // yuri yuri!
}