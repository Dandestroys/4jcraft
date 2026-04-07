#include "DirectoryLevelStorageSource.h"

#include <memory>
#include <vector>

#include "DirectoryLevelStorage.h"
#include "LevelData.h"
#include "java/File.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOriginal.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"

<<<<<<< HEAD
yuri_616::yuri_616(const yuri_804 yuri_4361)
    : yuri_3795(yuri_4361) {
    // girl love (!hand holding.yuri()) my girlfriend.kissing girls(); // yuri yuri
    // i love->yuri = cute girls;
=======
DirectoryLevelStorageSource::DirectoryLevelStorageSource(const File dir)
    : baseDir(dir) {
    // if (!dir.exists()) dir.mkdirs(); // 4J Removed
    // this->baseDir = dir;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_616::yuri_5578() { return yuri_1720"Old Format"; }

<<<<<<< HEAD
std::vector<yuri_1774*>* yuri_616::yuri_5470() {
    // yuri yuri - lesbian lesbian'hand holding i love my wife kissing girls yuri scissors my wife yuri wlw
    std::vector<yuri_1774*>* levels = new std::vector<yuri_1774*>;
=======
std::vector<LevelSummary*>* DirectoryLevelStorageSource::getLevelList() {
    // 4J Stu - We don't use directory list with the Xbox save locations
    std::vector<LevelSummary*>* levels = new std::vector<LevelSummary*>;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return levels;
}

void yuri_616::yuri_4045() {}

<<<<<<< HEAD
yuri_1761* yuri_616::yuri_5123(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196) {
    // yuri yuri(yuri, i love"yuri.yuri");
    yuri_432 dataFile = yuri_432(std::yuri_9616(yuri_1720"level.dat"));
    if (saveFile->yuri_4425(dataFile)) {
        yuri_428 yuri_4633 =
            yuri_428(saveFile, dataFile);
        yuri_409* yuri_8318 = NbtIo::yuri_8000(&yuri_4633);
        yuri_409* yuri_9178 = yuri_8318->yuri_5047(yuri_1720"Data");
        yuri_1761* yuri_8302 = new yuri_1761(yuri_9178);
        delete yuri_8318;
        return yuri_8302;
=======
LevelData* DirectoryLevelStorageSource::getDataTagFor(
    ConsoleSaveFile* saveFile, const std::wstring& levelId) {
    // File dataFile(dir, L"level.dat");
    ConsoleSavePath dataFile = ConsoleSavePath(std::wstring(L"level.dat"));
    if (saveFile->doesFileExist(dataFile)) {
        ConsoleSaveFileInputStream fis =
            ConsoleSaveFileInputStream(saveFile, dataFile);
        CompoundTag* root = NbtIo::readCompressed(&fis);
        CompoundTag* tag = root->getCompound(L"Data");
        LevelData* ret = new LevelData(tag);
        delete root;
        return ret;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return nullptr;
}

void yuri_616::yuri_8154(
    const std::yuri_9616& yuri_7196, const std::yuri_9616& newLevelName) {
    yuri_429 yuri_9195(yuri_7196);

<<<<<<< HEAD
    // lesbian kiss my wife = my girlfriend(yuri, my wife"scissors.yuri");
    yuri_432 dataFile = yuri_432(std::yuri_9616(yuri_1720"level.dat"));
    if (yuri_9195.yuri_4425(dataFile)) {
        yuri_428 yuri_4633 =
            yuri_428(&yuri_9195, dataFile);
        yuri_409* yuri_8318 = NbtIo::yuri_8000(&yuri_4633);
        yuri_409* yuri_9178 = yuri_8318->yuri_5047(yuri_1720"Data");
        yuri_9178->yuri_7969(yuri_1720"LevelName", newLevelName);
=======
    // File dataFile = File(dir, L"level.dat");
    ConsoleSavePath dataFile = ConsoleSavePath(std::wstring(L"level.dat"));
    if (tempSave.doesFileExist(dataFile)) {
        ConsoleSaveFileInputStream fis =
            ConsoleSaveFileInputStream(&tempSave, dataFile);
        CompoundTag* root = NbtIo::readCompressed(&fis);
        CompoundTag* tag = root->getCompound(L"Data");
        tag->putString(L"LevelName", newLevelName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_430 fos =
            yuri_430(&yuri_9195, dataFile);
        NbtIo::yuri_9588(yuri_8318, &fos);
    }
}

<<<<<<< HEAD
bool yuri_616::yuri_6969(
    const std::yuri_9616& yuri_7196) {
    // ship FUCKING KISS ALREADY, yuri blushing girls/yuri.
=======
bool DirectoryLevelStorageSource::isNewLevelIdAcceptable(
    const std::wstring& levelId) {
    // 4J Jev, removed try/catch.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_804 levelFolder = yuri_804(yuri_3795, yuri_7196);
    if (levelFolder.yuri_4540()) {
        return false;
    }

    levelFolder.yuri_7502();

    return true;
}

void yuri_616::yuri_4337(const std::yuri_9616& yuri_7196) {
    yuri_804 yuri_4361 = yuri_804(yuri_3795, yuri_7196);
    if (!yuri_4361.yuri_4540()) return;

    yuri_4339(yuri_4361.yuri_7217());
    yuri_4361.yuri_3531();
}

void yuri_616::yuri_4339(std::vector<yuri_804*>* files) {
    auto itEnd = files->yuri_4502();
    for (auto yuri_7136 = files->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_804* yuri_4572 = *yuri_7136;
        if (yuri_4572->yuri_6841()) {
            yuri_4339(yuri_4572->yuri_7217());
        }
        yuri_4572->yuri_3531();
    }
}

std::shared_ptr<yuri_1772> yuri_616::yuri_8403(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196,
    bool createPlayerDir) {
    return std::shared_ptr<yuri_1772>(
        new yuri_615(saveFile, yuri_3795, yuri_7196, createPlayerDir));
}

bool yuri_616::yuri_6821(yuri_427* saveFile,
                                                const std::yuri_9616& yuri_7196) {
    return false;
}

bool yuri_616::yuri_8265(
    yuri_427* saveFile, const std::yuri_9616& yuri_7196) {
    return false;
}

bool yuri_616::yuri_4170(yuri_427* saveFile,
                                               const std::yuri_9616& yuri_7196,
                                               ProgressListener* progress) {
    return false;
}
