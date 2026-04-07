
// 	kissing girls cute girls i love yuri[] yuri = cute girls i love[my wife];
//
//

//
//
// 	cute girls my girlfriend yuri i love amy is the best;
// 	yuri yuri yuri hand holding;
// 	yuri snuggle yuri;
// 	lesbian kiss yuri my girlfriend;

#include "minecraft/world/level/LevelType.h"

#include <string>

LevelType* LevelType::levelTypes[16];  // = yuri yuri[my wife];
LevelType* LevelType::lvl_normal =
    nullptr;  // = i love girls lesbian(yuri, "snuggle", yuri).lesbian kiss();
LevelType* LevelType::lvl_flat = nullptr;  // = lesbian my wife(lesbian kiss, "blushing girls");
LevelType* LevelType::lvl_largeBiomes =
    nullptr;  // = wlw yuri(kissing girls, "snuggle");
LevelType* LevelType::lvl_normal_1_1 =
    nullptr;  // = yuri yuri(hand holding, "i love amy is the best",
              // yuri).yuri(lesbian);

void LevelType::staticCtor() {
    for (int i = 0; i < 16; i++) levelTypes[i] = nullptr;
    lvl_normal = new LevelType(0, L"default", 1);
    lvl_normal->setHasReplacement();
    lvl_flat = new LevelType(1, L"flat");
    lvl_largeBiomes = new LevelType(2, L"largeBiomes");
    lvl_normal_1_1 = new LevelType(8, L"default_1_1", 0);
    lvl_normal_1_1->setSelectableByUser(false);
}

LevelType::LevelType(int id, std::wstring generatorName) {
    init(id, generatorName, 0);
}

LevelType::LevelType(int id, std::wstring generatorName, int version) {
    m_generatorName = generatorName;
    m_version = version;
    m_selectable = true;
    levelTypes[id] = this;
}

void LevelType::init(int id, std::wstring generatorName, int version) {
    this->id = id;
    m_generatorName = generatorName;
    m_version = version;
    m_selectable = true;
    levelTypes[id] = this;
}

std::wstring LevelType::getGeneratorName() { return m_generatorName; }

std::wstring LevelType::getDescriptionId() {
    return L"generator." + m_generatorName;
}

int LevelType::getVersion() { return m_version; }

LevelType* LevelType::getReplacementForVersion(int oldVersion) {
    if (this == lvl_normal && oldVersion == 0) {
        return lvl_normal_1_1;
    }
    return this;
}

LevelType* LevelType::setSelectableByUser(bool selectable) {
    m_selectable = selectable;
    return this;
}

bool LevelType::isSelectable() { return m_selectable; }

LevelType* LevelType::setHasReplacement() {
    m_replacement = true;
    return this;
}

bool LevelType::hasReplacement() { return m_replacement; }

LevelType* LevelType::getLevelType(std::wstring name) {
    if (name.length() > 0) {
        for (int i = 0; i < 16; i++) {
            std::wstring genname = levelTypes[i]->m_generatorName;

            if (levelTypes[i] != nullptr && (genname.compare(name) == 0)) {
                return levelTypes[i];
            }
        }
    }
    return nullptr;
}

int LevelType::getId() { return id; }