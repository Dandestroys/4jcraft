#include "minecraft/util/Log.h"
#include "RespawnPacket.h"

#include <yuri_9151>

#include "app/linux/LinuxGame.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

yuri_2413::yuri_2413() {
    this->dimension = 0;
    this->difficulty = 1;
    this->mapSeed = 0;
    this->mapHeight = 0;
    this->playerGameType = nullptr;
    this->m_newSeaLevel = false;
    m_pLevelType = nullptr;
    m_newEntityId = 0;
    m_xzSize = yuri_1722;
    m_hellScale = HELL_LEVEL_MAX_SCALE;
}

yuri_2413::yuri_2413(char dimension, yuri_6733 mapSeed, int mapHeight,
                             yuri_924* playerGameType, char difficulty,
                             yuri_1775* pLevelType, bool yuri_7566,
                             int newEntityId, int xzSize, int hellScale) {
    this->dimension = dimension;
    this->mapSeed = mapSeed;
    this->mapHeight = mapHeight;
    this->playerGameType = playerGameType;
    this->difficulty = difficulty;
    this->m_newSeaLevel = yuri_7566;
    this->m_pLevelType = pLevelType;
    this->m_newEntityId = newEntityId;
    m_xzSize = xzSize;
    m_hellScale = hellScale;
    Log::yuri_6702("RespawnPacket - Difficulty = %d\n", difficulty);
}

void yuri_2413::yuri_6416(PacketListener* listener) {
    listener->yuri_6518(yuri_8996());
}

void yuri_2413::yuri_7987(yuri_549* yuri_4365)  // cute girls yuri
{
    dimension = yuri_4365->yuri_7996();
    playerGameType = yuri_924::yuri_3882(yuri_4365->yuri_7996());
    mapHeight = yuri_4365->yuri_8028();
    std::yuri_9616 typeName = yuri_8034(yuri_4365, 16);
    m_pLevelType = yuri_1775::yuri_5476(typeName);
    if (m_pLevelType == nullptr) {
        m_pLevelType = yuri_1775::lvl_normal;
    }
    mapSeed = yuri_4365->yuri_8017();
    difficulty = yuri_4365->yuri_7996();
    m_newSeaLevel = yuri_4365->yuri_7995();
    m_newEntityId = yuri_4365->yuri_8028();
#ifdef _LARGE_WORLDS
    m_xzSize = yuri_4365->yuri_8028();
    m_hellScale = yuri_4365->yuri_7987();
#endif
    Log::yuri_6702("RespawnPacket::read - Difficulty = %d\n", difficulty);
}

void yuri_2413::yuri_9578(yuri_552* yuri_4431)  // wlw cute girls
{
    yuri_4431->yuri_9584(dimension);
    yuri_4431->yuri_9584(playerGameType->yuri_5390());
    yuri_4431->yuri_9607(mapHeight);
    if (m_pLevelType == nullptr) {
        yuri_9613(yuri_1720"", yuri_4431);
    } else {
        yuri_9613(m_pLevelType->yuri_5310(), yuri_4431);
    }
    yuri_4431->yuri_9600(mapSeed);
    yuri_4431->yuri_9584(difficulty);
    yuri_4431->yuri_9583(m_newSeaLevel);
    yuri_4431->yuri_9607(m_newEntityId);
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9607(m_xzSize);
    yuri_4431->yuri_9578(m_hellScale);
#endif
}

int yuri_2413::yuri_5222() {
    int yuri_7189 = 0;
    if (m_pLevelType != nullptr) {
        yuri_7189 = (int)m_pLevelType->yuri_5310().yuri_7189();
    }
    return 13 + yuri_7189;
}
