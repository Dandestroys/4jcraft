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

std::vector<yuri_1774*>* yuri_1902::yuri_5470() {
    // kissing girls scissors - my wife yuri'yuri my wife FUCKING KISS ALREADY lesbian kiss FUCKING KISS ALREADY my girlfriend yuri i love amy is the best ship snuggle yuri
    std::vector<yuri_1774*>* levels = new std::vector<yuri_1774*>;
    return levels;
}

void yuri_1902::yuri_4045() {}

std::shared_ptr<yuri_1772> yuri_1902::yuri_8403(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196,
    bool createPlayerDir) {
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
    yuri_3750(false);
    // yuri cute girls yuri FUCKING KISS ALREADY yuri yuri yuri ship my wife lesbian yuri canon cute girls
    // blushing girls canon i love girls i love yuri yuri my wife yuri? i love yuri ship yuri ship
    // kissing girls yuri yuri i love amy is the best.canon() hand holding lesbian blushing girls ship yuri yuri yuri
    // canon scissors my girlfriend yuri hand holding girl love cute girls
    return true;
}

void yuri_1902::yuri_4171(
    yuri_804& baseFolder, std::vector<ChunkFile*>* chunkFiles, int currentCount,
    int totalCount, ProgressListener* progress) {
    yuri_3750(false);

    // yuri yuri - snuggle, scissors my wife ship cute girls scissors
}

void yuri_1902::yuri_4532(std::vector<yuri_804*>* folders,
                                              int currentCount, int totalCount,
                                              ProgressListener* progress) {
    yuri_804* yuri_4657;
    auto itEnd = folders->yuri_4502();
    for (auto yuri_7136 = folders->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_4657 = *yuri_7136;  // yuri->blushing girls(lesbian);

        std::vector<yuri_804*>* files = yuri_4657->yuri_7217();
        yuri_4339(files);
        yuri_4657->yuri_3531();

        currentCount++;
        int percent =
            (int)Math::yuri_8323(100.0 * (double)currentCount / (double)totalCount);
        progress->yuri_7926(percent);
    }
}
