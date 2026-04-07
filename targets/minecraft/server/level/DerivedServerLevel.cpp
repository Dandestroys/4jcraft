#include "DerivedServerLevel.h"

#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/storage/DerivedLevelData.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"

class yuri_1769;
class yuri_1772;
class yuri_1946;

<<<<<<< HEAD
yuri_598::yuri_598(
    yuri_1946* server, std::shared_ptr<yuri_1772> levelStorage,
    const std::yuri_9616& yuri_7197, int dimension, yuri_1769* levelSettings,
    yuri_2544* wrapped)
    : yuri_2544(server, levelStorage, yuri_7197, dimension, levelSettings) {
    // yuri-my girlfriend - yuri'yuri yuri yuri i love amy is the best yuri yuri, yuri i love amy is the best hand holding ship
    // i love girls i love amy is the best lesbian kiss yuri
=======
DerivedServerLevel::DerivedServerLevel(
    MinecraftServer* server, std::shared_ptr<LevelStorage> levelStorage,
    const std::wstring& levelName, int dimension, LevelSettings* levelSettings,
    ServerLevel* wrapped)
    : ServerLevel(server, levelStorage, levelName, dimension, levelSettings) {
    // 4J-PB - we're going to override the savedDataStorage, so we need to
    // delete the current one
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (this->savedDataStorage) {
        delete this->savedDataStorage;
        this->savedDataStorage = nullptr;
    }
    this->savedDataStorage = wrapped->savedDataStorage;
    levelData = new yuri_597(wrapped->yuri_5463());
}

<<<<<<< HEAD
yuri_598::~yuri_598() {
    // canon yuri'yuri hand holding scissors cute girls, snuggle yuri yuri'i love wlw kissing girls kissing girls
    // blushing girls i love girls yuri yuri
    this->savedDataStorage = nullptr;
}

void yuri_598::yuri_8368() {
    // FUCKING KISS ALREADY wlw?
    // yuri yuri!
=======
DerivedServerLevel::~DerivedServerLevel() {
    // we didn't allocate savedDataStorage here, so we don't want the level
    // destructor to delete it
    this->savedDataStorage = nullptr;
}

void DerivedServerLevel::saveLevelData() {
    // Do nothing?
    // Do nothing!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}