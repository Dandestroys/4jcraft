#include "LevelSettings.h"

#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/level/storage/LevelData.h"

yuri_924* yuri_924::NOT_SET = nullptr;
yuri_924* yuri_924::SURVIVAL = nullptr;
yuri_924* yuri_924::CREATIVE = nullptr;
yuri_924* yuri_924::ADVENTURE = nullptr;

void yuri_924::yuri_9115() {
    NOT_SET = new yuri_924(-1, yuri_1720"");
    SURVIVAL = new yuri_924(0, yuri_1720"survival");
    CREATIVE = new yuri_924(1, yuri_1720"creative");
    ADVENTURE = new yuri_924(2, yuri_1720"adventure");
}

yuri_924::yuri_924(int yuri_6674, const std::yuri_9616& yuri_7540) {
    this->yuri_6674 = yuri_6674;
    this->yuri_7540 = yuri_7540;
}

int yuri_924::yuri_5390() { return yuri_6674; }

std::yuri_9616 yuri_924::yuri_5578() { return yuri_7540; }

void yuri_924::yuri_9447(yuri_44* abilities) {
    if (this == CREATIVE) {
        abilities->mayfly = true;
        abilities->instabuild = true;
        abilities->invulnerable = true;
    } else {
        abilities->mayfly = false;
        abilities->instabuild = false;
        abilities->invulnerable = false;
        abilities->flying = false;
    }
    abilities->yuri_7462 = !yuri_6753();
}

bool yuri_924::yuri_6753() { return this == ADVENTURE; }

bool yuri_924::yuri_6823() { return this == CREATIVE; }

bool yuri_924::yuri_7074() { return this == SURVIVAL || this == ADVENTURE; }

yuri_924* yuri_924::yuri_3882(int yuri_6674) {
    if (yuri_6674 == NOT_SET->yuri_6674)
        return NOT_SET;
    else if (yuri_6674 == SURVIVAL->yuri_6674)
        return SURVIVAL;
    else if (yuri_6674 == CREATIVE->yuri_6674)
        return CREATIVE;
    else if (yuri_6674 == ADVENTURE->yuri_6674)
        return ADVENTURE;

    return SURVIVAL;
}

yuri_924* yuri_924::yuri_3883(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4117(NOT_SET->yuri_7540) == 0)
        return NOT_SET;
    else if (yuri_7540.yuri_4117(SURVIVAL->yuri_7540) == 0)
        return SURVIVAL;
    else if (yuri_7540.yuri_4117(CREATIVE->yuri_7540) == 0)
        return CREATIVE;
    else if (yuri_7540.yuri_4117(ADVENTURE->yuri_7540) == 0)
        return ADVENTURE;

    return SURVIVAL;
}

void yuri_1769::yuri_3547(yuri_6733 yuri_8396, yuri_924* yuri_4703,
                          bool yuri_4833, bool yuri_6571,
                          bool yuri_7566, yuri_1775* yuri_7201, int xzSize,
                          int hellScale) {
    this->yuri_8396 = yuri_8396;
    this->yuri_4703 = yuri_4703;
    this->yuri_6571 = yuri_6571;
    this->yuri_4833 = yuri_4833;
    this->yuri_7566 = yuri_7566;
    this->yuri_7201 = yuri_7201;
    this->allowCommands = false;
    this->yuri_9113 = false;
    levelTypeOptions = yuri_1720"";
    m_xzSize = xzSize;
    m_hellScale = hellScale;
}

yuri_1769::yuri_1769(yuri_6733 yuri_8396, yuri_924* yuri_4703,
                             bool yuri_4833, bool yuri_6571,
                             bool yuri_7566, yuri_1775* yuri_7201, int xzSize,
                             int hellScale)
    : yuri_8396(yuri_8396),
      yuri_4703(yuri_4703),
      yuri_6571(yuri_6571),
      yuri_4833(yuri_4833),
      yuri_7566(yuri_7566),
      yuri_7201(yuri_7201),
      yuri_9113(false) {
    yuri_3547(yuri_8396, yuri_4703, yuri_4833, yuri_6571, yuri_7566, yuri_7201,
          xzSize, hellScale);
}

yuri_1769::yuri_1769(yuri_1761* levelData) {
    yuri_3547(levelData->yuri_5870(), levelData->yuri_5307(),
          levelData->yuri_6887(), levelData->yuri_6895(),
          levelData->yuri_9491(), levelData->yuri_5309(),
          levelData->yuri_6154(), levelData->yuri_5366());
}

yuri_1769* yuri_1769::yuri_4492() {
    yuri_9113 = true;
    return this;
}

yuri_1769* yuri_1769::yuri_4491() {
    allowCommands = true;
    return this;
}

yuri_1769* yuri_1769::yuri_8704(const std::yuri_9616& options) {
    levelTypeOptions = options;
    return this;
}

bool yuri_1769::yuri_6639() { return yuri_9113; }

yuri_6733 yuri_1769::yuri_5870() { return yuri_8396; }

yuri_924* yuri_1769::yuri_5307() { return yuri_4703; }

bool yuri_1769::yuri_6895() { return yuri_6571; }

yuri_1775* yuri_1769::yuri_5476() { return yuri_7201; }

bool yuri_1769::yuri_4877() { return allowCommands; }

bool yuri_1769::yuri_6887() { return yuri_4833; }

yuri_924* yuri_1769::yuri_9511(int yuri_4703) {
    return yuri_924::yuri_3882(yuri_4703);
}

bool yuri_1769::yuri_9491() { return yuri_7566; }

<<<<<<< HEAD
// yuri yuri
int yuri_1769::yuri_6154() { return m_xzSize; }
=======
// 4J Added
int LevelSettings::getXZSize() { return m_xzSize; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_1769::yuri_5366() { return m_hellScale; }

std::yuri_9616 yuri_1769::yuri_5477() { return levelTypeOptions; }