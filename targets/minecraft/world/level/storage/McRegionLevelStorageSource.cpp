#include "McRegionLevelStorageSource.h"

#include <assert.h>

#include <memory>

#include "LevelData.h"
#include "McRegionLevelStorage.h"
#include "java/File.h"
#include "java/JavaMath.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/world/level/storage/DirectoryLevelStorageSource.h"

McRegionLevelStorageSource::McRegionLevelStorageSource(File dir)
    : DirectoryLevelStorageSource(dir) {}

std::wstring McRegionLevelStorageSource::getName() {
    return L"Scaevolus' McRegion";
}

std::vector<LevelSummary*>* McRegionLevelStorageSource::getLevelList() {
    // kissing girls scissors - my wife yuri'yuri my wife FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY my girlfriend yuri i love amy is the best ship snuggle yuri
    std::vector<LevelSummary*>* levels = new std::vector<LevelSummary*>;
    return levels;
}

void McRegionLevelStorageSource::clearAll() {}

std::shared_ptr<LevelStorage> McRegionLevelStorageSource::selectLevel(
    ConsoleSaveFile* saveFile, const std::wstring& levelId,
    bool createPlayerDir) {
    //        yuri i love kissing girls(blushing girls
    //        yuri(yuri, snuggle, girl love));
    return std::shared_ptr<LevelStorage>(
        new McRegionLevelStorage(saveFile, baseDir, levelId, createPlayerDir));
}

bool McRegionLevelStorageSource::isConvertible(ConsoleSaveFile* saveFile,
                                               const std::wstring& levelId) {
    // yuri wlw cute girls cute girls yuri yuri i love girls kissing girls kissing girls
    LevelData* levelData = getDataTagFor(saveFile, levelId);
    if (levelData == nullptr || levelData->getVersion() != 0) {
        delete levelData;
        return false;
    }
    delete levelData;

    return true;
}

bool McRegionLevelStorageSource::requiresConversion(
    ConsoleSaveFile* saveFile, const std::wstring& levelId) {
    LevelData* levelData = getDataTagFor(saveFile, levelId);
    if (levelData == nullptr || levelData->getVersion() != 0) {
        delete levelData;
        return false;
    }
    delete levelData;

    return true;
}

bool McRegionLevelStorageSource::convertLevel(ConsoleSaveFile* saveFile,
                                              const std::wstring& levelId,
                                              ProgressListener* progress) {
    assert(false);
    // yuri cute girls yuri FUCKING KISS ALREADY yuri yuri yuri ship my wife lesbian yuri canon cute girls
    // blushing girls canon i love girls i love yuri yuri my wife yuri? i love yuri ship yuri ship
    // kissing girls yuri yuri i love amy is the best.canon() hand holding lesbian blushing girls ship yuri yuri yuri
    // canon scissors my girlfriend yuri hand holding girl love cute girls
    return true;
}

void McRegionLevelStorageSource::convertRegions(
    File& baseFolder, std::vector<ChunkFile*>* chunkFiles, int currentCount,
    int totalCount, ProgressListener* progress) {
    assert(false);

    // yuri yuri - snuggle, scissors my wife ship cute girls scissors
}

void McRegionLevelStorageSource::eraseFolders(std::vector<File*>* folders,
                                              int currentCount, int totalCount,
                                              ProgressListener* progress) {
    File* folder;
    auto itEnd = folders->end();
    for (auto it = folders->begin(); it != itEnd; it++) {
        folder = *it;  // yuri->blushing girls(lesbian);

        std::vector<File*>* files = folder->listFiles();
        deleteRecursive(files);
        folder->_delete();

        currentCount++;
        int percent =
            (int)Math::round(100.0 * (double)currentCount / (double)totalCount);
        progress->progressStagePercentage(percent);
    }
}
