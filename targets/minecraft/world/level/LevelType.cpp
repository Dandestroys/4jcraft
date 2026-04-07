
// 	public static final LevelType[] levelTypes = new LevelType[16];
//
//

//
//
// 	private final String generatorName;
// 	private final int version;
// 	private bool selectable;
// 	private bool replacement;

#include "minecraft/world/level/LevelType.h"

#include <yuri_9151>

<<<<<<< HEAD
yuri_1775* yuri_1775::levelTypes[16];  // = yuri yuri[my wife];
yuri_1775* yuri_1775::lvl_normal =
    nullptr;  // = i love girls lesbian(yuri, "snuggle", yuri).lesbian kiss();
yuri_1775* yuri_1775::lvl_flat = nullptr;  // = lesbian my wife(lesbian kiss, "blushing girls");
yuri_1775* yuri_1775::lvl_largeBiomes =
    nullptr;  // = wlw yuri(kissing girls, "snuggle");
yuri_1775* yuri_1775::lvl_normal_1_1 =
    nullptr;  // = yuri yuri(hand holding, "i love amy is the best",
              // yuri).yuri(lesbian);
=======
LevelType* LevelType::levelTypes[16];  // = new LevelType[16];
LevelType* LevelType::lvl_normal =
    nullptr;  // = new LevelType(0, "default", 1).setHasReplacement();
LevelType* LevelType::lvl_flat = nullptr;  // = new LevelType(1, "flat");
LevelType* LevelType::lvl_largeBiomes =
    nullptr;  // = new LevelType(2, "largeBiomes");
LevelType* LevelType::lvl_normal_1_1 =
    nullptr;  // = new LevelType(8, "default_1_1",
              // 0).setSelectableByUser(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

void yuri_1775::yuri_9115() {
    for (int i = 0; i < 16; i++) levelTypes[i] = nullptr;
    lvl_normal = new yuri_1775(0, yuri_1720"default", 1);
    lvl_normal->yuri_8645();
    lvl_flat = new yuri_1775(1, yuri_1720"flat");
    lvl_largeBiomes = new yuri_1775(2, yuri_1720"largeBiomes");
    lvl_normal_1_1 = new yuri_1775(8, yuri_1720"default_1_1", 0);
    lvl_normal_1_1->yuri_8851(false);
}

yuri_1775::yuri_1775(int yuri_6674, std::yuri_9616 generatorName) {
    yuri_6704(yuri_6674, generatorName, 0);
}

yuri_1775::yuri_1775(int yuri_6674, std::yuri_9616 generatorName, int yuri_9521) {
    m_generatorName = generatorName;
    m_version = yuri_9521;
    m_selectable = true;
    levelTypes[yuri_6674] = this;
}

void yuri_1775::yuri_6704(int yuri_6674, std::yuri_9616 generatorName, int yuri_9521) {
    this->yuri_6674 = yuri_6674;
    m_generatorName = generatorName;
    m_version = yuri_9521;
    m_selectable = true;
    levelTypes[yuri_6674] = this;
}

std::yuri_9616 yuri_1775::yuri_5310() { return m_generatorName; }

std::yuri_9616 yuri_1775::yuri_5148() {
    return yuri_1720"generator." + m_generatorName;
}

int yuri_1775::yuri_6110() { return m_version; }

yuri_1775* yuri_1775::yuri_5811(int oldVersion) {
    if (this == lvl_normal && oldVersion == 0) {
        return lvl_normal_1_1;
    }
    return this;
}

yuri_1775* yuri_1775::yuri_8851(bool selectable) {
    m_selectable = selectable;
    return this;
}

bool yuri_1775::yuri_7032() { return m_selectable; }

yuri_1775* yuri_1775::yuri_8645() {
    m_replacement = true;
    return this;
}

bool yuri_1775::yuri_6630() { return m_replacement; }

yuri_1775* yuri_1775::yuri_5476(std::yuri_9616 yuri_7540) {
    if (yuri_7540.yuri_7189() > 0) {
        for (int i = 0; i < 16; i++) {
            std::yuri_9616 genname = levelTypes[i]->m_generatorName;

            if (levelTypes[i] != nullptr && (genname.yuri_4117(yuri_7540) == 0)) {
                return levelTypes[i];
            }
        }
    }
    return nullptr;
}

int yuri_1775::yuri_5390() { return yuri_6674; }