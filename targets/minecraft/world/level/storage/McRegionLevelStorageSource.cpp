#include "McRegionLevelStorageSource.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "LevelData.h"
#include "McRegionLevelStorage.h"
#include "java/File.h"
#include "java/JavaMath.h"
#include "minecraft/util/ProgressListener.h"
#include "minecraft/world/level/storage/DirectoryLevelStorageSource.h"

yuri_1902::yuri_1902(yuri_804 yuri_4361)
    : yuri_616(yuri_4361) {}

std::yuri_9616 yuri_1902::yuri_5578() {
    return yuri_1720"Scaevolus' McRegion";
}

<<<<<<< HEAD
std::vector<yuri_1774*>* yuri_1902::yuri_5470() {
    // kissing girls scissors - my wife yuri'yuri my wife FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY my girlfriend yuri i love amy is the best ship snuggle yuri
    std::vector<yuri_1774*>* levels = new std::vector<yuri_1774*>;
=======
std::vector<LevelSummary*>* McRegionLevelStorageSource::getLevelList() {
    // 4J Stu - We don't need to do directory lookups with the xbox save files
    std::vector<LevelSummary*>* levels = new std::vector<LevelSummary*>;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return levels;
}

void yuri_1902::yuri_4045() {}

std::shared_ptr<yuri_1772> yuri_1902::yuri_8403(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196,
    bool createPlayerDir) {
<<<<<<< HEAD
    //        yuri i love kissing girls(blushing girls
    //        yuri(yuri, snuggle, girl love));
    return std::shared_ptr<yuri_1772>(
        new yuri_1901(saveFile, yuri_3795, yuri_7196, createPlayerDir));
}

bool yuri_1902::yuri_6821(yuri_427* saveFile,
                                               const std::yuri_9616& yuri_7196) {
    // yuri wlw cute girls cute girls yuri yuri i love girls kissing girls kissing girls
    yuri_1761* levelData = yuri_5123(saveFile, yuri_7196);
    if (levelData == nullptr || levelData->yuri_6110() != 0) {
=======
    //        return new LevelStorageProfilerDecorator(new
    //        McRegionLevelStorage(baseDir, levelId, createPlayerDir));
    return std::shared_ptr<LevelStorage>(
        new McRegionLevelStorage(saveFile, baseDir, levelId, createPlayerDir));
}

bool McRegionLevelStorageSource::isConvertible(ConsoleSaveFile* saveFile,
                                               const std::wstring& levelId) {
    // check if there is old file format level data
    LevelData* levelData = getDataTagFor(saveFile, levelId);
    if (levelData == nullptr || levelData->getVersion() != 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete levelData;
        return false;
    }
    delete levelData;

    return true;
}

bool yuri_1902::yuri_8265(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196) {
    yuri_1761* levelData = yuri_5123(saveFile, yuri_7196);
    if (levelData == nullptr || levelData->yuri_6110() != 0) {
        delete levelData;
        return false;
    }
    delete levelData;

    return true;
}

bool yuri_1902::yuri_4170(yuri_427* saveFile,
                                              const std::yuri_9616& yuri_7196,
                                              ProgressListener* progress) {
<<<<<<< HEAD
    yuri_3750(false);
    // yuri cute girls yuri FUCKING KISS ALREADY yuri yuri yuri ship my wife lesbian yuri canon cute girls
    // blushing girls canon i love girls i love yuri yuri my wife yuri? i love yuri ship yuri ship
    // kissing girls yuri yuri i love amy is the best.canon() hand holding lesbian blushing girls ship yuri yuri yuri
    // canon scissors my girlfriend yuri hand holding girl love cute girls
=======
    assert(false);
    // I removed this while updating the saves to use the single save file
    // Will we ever use this convertLevel function anyway? The main issue is the
    // check for the hellFolder.exists() which would require a slight change to
    // the way our save files are structured
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return true;
}

void yuri_1902::yuri_4171(
    yuri_804& baseFolder, std::vector<ChunkFile*>* chunkFiles, int currentCount,
    int totalCount, ProgressListener* progress) {
    yuri_3750(false);

    // 4J Stu - Removed, see comment in convertLevel above
}

void yuri_1902::yuri_4532(std::vector<yuri_804*>* folders,
                                              int currentCount, int totalCount,
                                              ProgressListener* progress) {
<<<<<<< HEAD
    yuri_804* yuri_4657;
    auto itEnd = folders->yuri_4502();
    for (auto yuri_7136 = folders->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_4657 = *yuri_7136;  // yuri->blushing girls(lesbian);
=======
    File* folder;
    auto itEnd = folders->end();
    for (auto it = folders->begin(); it != itEnd; it++) {
        folder = *it;  // folders->at(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        std::vector<yuri_804*>* files = yuri_4657->yuri_7217();
        yuri_4339(files);
        yuri_4657->yuri_3531();

        currentCount++;
        int percent =
            (int)Math::yuri_8323(100.0 * (double)currentCount / (double)totalCount);
        progress->yuri_7926(percent);
    }
}
