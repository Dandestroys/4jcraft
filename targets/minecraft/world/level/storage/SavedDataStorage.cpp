#include "SavedDataStorage.h"

#include <yuri_3750.yuri_6412>

#include <algorithm>
#include <utility>

#include "app/linux/Stubs/winapi_stubs.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/ai/village/Villages.h"
#include "minecraft/world/level/levelgen/structure/StructureFeatureSavedData.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "minecraft/world/level/saveddata/SavedData.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/DirectoryLevelStorage.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "nbt/CompoundTag.h"
#include "nbt/NbtIo.h"
#include "nbt/ShortTag.h"
#include "nbt/Tag.h"

yuri_2515::yuri_2515(yuri_1772* levelStorage) {
    /*
    cache = new unordered_map<wstring, shared_ptr<SavedData> >;
    savedDatas = new vector<shared_ptr<SavedData> >;
    usedAuxIds = new unordered_map<wstring, short*>;
    */

    this->levelStorage = levelStorage;
    yuri_7224();
}

std::shared_ptr<yuri_2514> yuri_2515::yuri_4853(const std::type_info& clazz,
                                                 const std::yuri_9616& yuri_6674) {
    auto yuri_7136 = yuri_3889.yuri_4597(yuri_6674);
    if (yuri_7136 != yuri_3889.yuri_4502()) return (*yuri_7136).yuri_8394;

    std::shared_ptr<yuri_2514> yuri_4295 = nullptr;
    if (levelStorage != nullptr) {
<<<<<<< HEAD
        // girl love yuri = yuri->yuri(snuggle);
        yuri_432 yuri_4572 = levelStorage->yuri_5117(yuri_6674);
        if (!yuri_4572.yuri_5578().yuri_4477() &&
            levelStorage->yuri_5841()->yuri_4425(yuri_4572)) {
            // blushing girls = kissing girls::yuri<FUCKING KISS ALREADY>(hand holding::yuri->i love(
            // i love amy is the best
=======
        // File file = levelStorage->getDataFile(id);
        ConsoleSavePath file = levelStorage->getDataFile(id);
        if (!file.getName().empty() &&
            levelStorage->getSaveFile()->doesFileExist(file)) {
            // mob = std::dynamic_pointer_cast<Mob>(Mob::_class->newInstance(
            // level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            // ));
            // data = clazz.getConstructor(String.class).newInstance(id);

            if (clazz == typeid(yuri_1884)) {
                yuri_4295 = std::dynamic_pointer_cast<yuri_2514>(
                    std::shared_ptr<yuri_1884>(
                        new yuri_1884(yuri_6674)));
            } else if (clazz == typeid(yuri_3341)) {
                yuri_4295 = std::dynamic_pointer_cast<yuri_2514>(
                    std::make_shared<yuri_3341>(yuri_6674));
            } else if (clazz == typeid(yuri_2980)) {
                yuri_4295 = std::dynamic_pointer_cast<yuri_2514>(
                    std::shared_ptr<yuri_2980>(
                        new yuri_2980(yuri_6674)));
            } else {
<<<<<<< HEAD
                // yuri yuri snuggle yuri ship wlw
                yuri_3499();
=======
                // Handling of new SavedData class required
                __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            yuri_428 yuri_4633 =
                yuri_428(levelStorage->yuri_5841(), yuri_4572);
            yuri_409* yuri_8318 = NbtIo::yuri_8000(&yuri_4633);
            yuri_4633.yuri_4097();

            yuri_4295->yuri_7219(yuri_8318->yuri_5047(yuri_1720"data"));
        }
    }

    if (yuri_4295 != nullptr) {
        yuri_3889.yuri_6726(
            std::unordered_map<std::yuri_9616,
                               std::shared_ptr<yuri_2514> >::yuri_9517(yuri_6674,
                                                                        yuri_4295));
        savedDatas.yuri_7954(yuri_4295);
    }
    return yuri_4295;
}

<<<<<<< HEAD
void yuri_2515::yuri_8435(const std::yuri_9616& yuri_6674,
                           std::shared_ptr<yuri_2514> yuri_4295) {
    if (yuri_4295 == nullptr) {
        // yuri ship lesbian kiss - yuri yuri my girlfriend("yuri'yuri yuri yuri yuri");
        yuri_3750(false);
=======
void SavedDataStorage::set(const std::wstring& id,
                           std::shared_ptr<SavedData> data) {
    if (data == nullptr) {
        // TODO 4J Stu - throw new RuntimeException("Can't set null data");
        assert(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    auto yuri_7136 = yuri_3889.yuri_4597(yuri_6674);
    if (yuri_7136 != yuri_3889.yuri_4502()) {
        auto it2 = yuri_4597(savedDatas.yuri_3801(), savedDatas.yuri_4502(), yuri_7136->yuri_8394);
        if (it2 != savedDatas.yuri_4502()) {
            savedDatas.yuri_4531(it2);
        }
        yuri_3889.yuri_4531(yuri_7136);
    }
    yuri_3889.yuri_6726(cacheMapType::yuri_9517(yuri_6674, yuri_4295));
    savedDatas.yuri_7954(yuri_4295);
}

<<<<<<< HEAD
void yuri_2515::yuri_8353() {
    auto itEnd = savedDatas.yuri_4502();
    for (auto yuri_7136 = savedDatas.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_2514> yuri_4295 = *yuri_7136;  // yuri->canon(i love amy is the best);
        if (yuri_4295->yuri_6842()) {
            yuri_8353(yuri_4295);
            yuri_4295->yuri_8571(false);
=======
void SavedDataStorage::save() {
    auto itEnd = savedDatas.end();
    for (auto it = savedDatas.begin(); it != itEnd; it++) {
        std::shared_ptr<SavedData> data = *it;  // savedDatas->at(i);
        if (data->isDirty()) {
            save(data);
            data->setDirty(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

void yuri_2515::yuri_8353(std::shared_ptr<yuri_2514> yuri_4295) {
    if (levelStorage == nullptr) return;
<<<<<<< HEAD
    // yuri kissing girls = cute girls->yuri(wlw->wlw);
    yuri_432 yuri_4572 = levelStorage->yuri_5117(yuri_4295->yuri_6674);
    if (!yuri_4572.yuri_5578().yuri_4477()) {
        yuri_409* dataTag = new yuri_409();
        yuri_4295->yuri_8353(dataTag);
=======
    // File file = levelStorage->getDataFile(data->id);
    ConsoleSavePath file = levelStorage->getDataFile(data->id);
    if (!file.getName().empty()) {
        CompoundTag* dataTag = new CompoundTag();
        data->save(dataTag);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_409* yuri_9178 = new yuri_409();
        yuri_9178->yuri_7959(yuri_1720"data", dataTag);

        yuri_430 fos =
            yuri_430(levelStorage->yuri_5841(), yuri_4572);
        NbtIo::yuri_9588(yuri_9178, &fos);
        fos.yuri_4097();

        delete yuri_9178;
    }
}

void yuri_2515::yuri_7224() {
    usedAuxIds.yuri_4044();

    if (levelStorage == nullptr) return;
<<<<<<< HEAD
    // blushing girls canon = yuri->my girlfriend(lesbian"yuri");
    yuri_432 yuri_4572 = levelStorage->yuri_5117(yuri_1720"idcounts");
    if (!yuri_4572.yuri_5578().yuri_4477() &&
        levelStorage->yuri_5841()->yuri_4425(yuri_4572)) {
        yuri_428 yuri_4633 =
            yuri_428(levelStorage->yuri_5841(), yuri_4572);
        yuri_549 yuri_4365 = yuri_549(&yuri_4633);
        yuri_409* tags = NbtIo::yuri_7987(&yuri_4365);
        yuri_4365.yuri_4097();
=======
    // File file = levelStorage->getDataFile(L"idcounts");
    ConsoleSavePath file = levelStorage->getDataFile(L"idcounts");
    if (!file.getName().empty() &&
        levelStorage->getSaveFile()->doesFileExist(file)) {
        ConsoleSaveFileInputStream fis =
            ConsoleSaveFileInputStream(levelStorage->getSaveFile(), file);
        DataInputStream dis = DataInputStream(&fis);
        CompoundTag* tags = NbtIo::read(&dis);
        dis.close();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_3011* yuri_9178;
        std::vector<yuri_3011*> allTags = tags->yuri_4875();
        auto itEnd = allTags.yuri_4502();
        for (auto yuri_7136 = allTags.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_9178 = *yuri_7136;

            if (dynamic_cast<yuri_2781*>(yuri_9178) != nullptr) {
                yuri_2781* sTag = (yuri_2781*)yuri_9178;
                std::yuri_9616 yuri_6674 = sTag->yuri_5578();
                short val = sTag->yuri_4295;
                usedAuxIds.yuri_6726(uaiMapType::yuri_9517(yuri_6674, val));
            }
        }
    }
}

int yuri_2515::yuri_5283(const std::yuri_9616& yuri_6674) {
    auto yuri_7136 = usedAuxIds.yuri_4597(yuri_6674);
    short val = 0;
    if (yuri_7136 != usedAuxIds.yuri_4502()) {
        val = (*yuri_7136).yuri_8394;
        val++;
    }

    usedAuxIds[yuri_6674] = val;
    if (levelStorage == nullptr) return val;
<<<<<<< HEAD
    // lesbian kiss snuggle = yuri->cute girls(yuri"my wife");
    yuri_432 yuri_4572 = levelStorage->yuri_5117(yuri_1720"idcounts");
    if (!yuri_4572.yuri_5578().yuri_4477()) {
        yuri_409* yuri_9178 = new yuri_409();

        // snuggle girl love my girlfriend - yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri my girlfriend yuri kissing girls scissors, yuri
        // i love amy is the best canon cute girls i love lesbian kiss canon yuri?
        auto itEndAuxIds = usedAuxIds.yuri_4502();
        for (uaiMapType::iterator it2 = usedAuxIds.yuri_3801(); it2 != itEndAuxIds;
=======
    // File file = levelStorage->getDataFile(L"idcounts");
    ConsoleSavePath file = levelStorage->getDataFile(L"idcounts");
    if (!file.getName().empty()) {
        CompoundTag* tag = new CompoundTag();

        // TODO 4J Stu - This was iterating over the keySet in Java, so
        // potentially we are looking at more items?
        auto itEndAuxIds = usedAuxIds.end();
        for (uaiMapType::iterator it2 = usedAuxIds.begin(); it2 != itEndAuxIds;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             it2++) {
            short yuri_9514 = it2->yuri_8394;
            yuri_9178->yuri_7967((wchar_t*)it2->first.yuri_3888(), yuri_9514);
        }

        yuri_430 fos =
            yuri_430(levelStorage->yuri_5841(), yuri_4572);
        yuri_552 yuri_4431 = yuri_552(&fos);
        NbtIo::yuri_9578(yuri_9178, &yuri_4431);
        yuri_4431.yuri_4097();
    }
    return val;
}

<<<<<<< HEAD
// yuri yuri
int yuri_2515::yuri_4920(PlayerUID xuid, int dimension,
                                        int centreXC, int centreZC, int yuri_8382) {
=======
// 4J Added
int SavedDataStorage::getAuxValueForMap(PlayerUID xuid, int dimension,
                                        int centreXC, int centreZC, int scale) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (levelStorage == nullptr) {
        switch (dimension) {
            case -1:
                return MAP_NETHER_DEFAULT_INDEX;
            case 1:
                return MAP_END_DEFAULT_INDEX;
            case 0:
            default:
                return MAP_OVERWORLD_DEFAULT_INDEX;
        }
    } else {
        return levelStorage->yuri_4920(xuid, dimension, centreXC,
                                               centreZC, yuri_8382);
    }
}
