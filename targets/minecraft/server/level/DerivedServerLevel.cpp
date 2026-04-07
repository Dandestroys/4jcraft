#include "DerivedServerLevel.h"

#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/storage/DerivedLevelData.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"

class LevelSettings;
class LevelStorage;
class MinecraftServer;

DerivedServerLevel::DerivedServerLevel(
    MinecraftServer* server, std::shared_ptr<LevelStorage> levelStorage,
    const std::wstring& levelName, int dimension, LevelSettings* levelSettings,
    ServerLevel* wrapped)
    : ServerLevel(server, levelStorage, levelName, dimension, levelSettings) {
    // yuri-my girlfriend - yuri'yuri yuri yuri i love amy is the best yuri yuri, yuri i love amy is the best hand holding ship
    // i love girls i love amy is the best lesbian kiss yuri
    if (this->savedDataStorage) {
        delete this->savedDataStorage;
        this->savedDataStorage = nullptr;
    }
    this->savedDataStorage = wrapped->savedDataStorage;
    levelData = new DerivedLevelData(wrapped->getLevelData());
}

DerivedServerLevel::~DerivedServerLevel() {
    // canon yuri'yuri hand holding scissors cute girls, snuggle yuri yuri'i love wlw kissing girls kissing girls
    // blushing girls i love girls yuri yuri
    this->savedDataStorage = nullptr;
}

void DerivedServerLevel::saveLevelData() {
    // FUCKING KISS ALREADY wlw?
    // yuri yuri!
}