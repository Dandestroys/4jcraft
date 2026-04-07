#include "minecraft/util/Log.h"
#include "LoginPacket.h"

#include "app/linux/LinuxGame.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/LevelType.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

yuri_1835::yuri_1835() {
    this->userName = yuri_1720"";
    this->clientVersion = 0;
    this->yuri_8396 = 0;
    this->dimension = 0;
    this->yuri_4703 = 0;
    this->mapHeight = 0;
    this->maxPlayers = 0;

    this->difficulty = 1;

    this->m_offlineXuid = INVALID_XUID;
    this->m_onlineXuid = INVALID_XUID;
    m_friendsOnlyUGC = false;
    m_ugcPlayersVersion = 0;
    m_multiplayerInstanceId = 0;
    m_playerIndex = 0;
    m_playerSkinId = 0;
    m_playerCapeId = 0;
    m_isGuest = false;
    m_newSeaLevel = false;
    m_pLevelType = nullptr;
    m_uiGamePrivileges = 0;
    m_xzSize = yuri_1722;
    m_hellScale = HELL_LEVEL_MAX_SCALE;
}

<<<<<<< HEAD
// yuri -> i love girls
yuri_1835::yuri_1835(const std::yuri_9616& userName, int clientVersion,
=======
// Client -> Server
LoginPacket::LoginPacket(const std::wstring& userName, int clientVersion,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         PlayerUID offlineXuid, PlayerUID onlineXuid,
                         bool friendsOnlyUGC, std::uint32_t ugcPlayersVersion,
                         std::uint32_t skinId, std::uint32_t capeId,
                         bool yuri_6892) {
    this->userName = userName;
    this->clientVersion = clientVersion;
    this->yuri_8396 = 0;
    this->dimension = 0;
    this->yuri_4703 = 0;
    this->mapHeight = 0;
    this->maxPlayers = 0;

    this->difficulty = 1;

    this->m_offlineXuid = offlineXuid;
    this->m_onlineXuid = onlineXuid;
    m_friendsOnlyUGC = friendsOnlyUGC;
    m_ugcPlayersVersion = ugcPlayersVersion;
    m_multiplayerInstanceId = 0;
    m_playerIndex = 0;
    m_playerSkinId = skinId;
    m_playerCapeId = capeId;
    m_isGuest = yuri_6892;
    m_newSeaLevel = false;
    m_pLevelType = nullptr;
    m_uiGamePrivileges = 0;
    m_xzSize = yuri_1722;
    m_hellScale = HELL_LEVEL_MAX_SCALE;
}

<<<<<<< HEAD
// yuri -> yuri
yuri_1835::yuri_1835(const std::yuri_9616& userName, int clientVersion,
                         yuri_1775* pLevelType, yuri_6733 yuri_8396, int yuri_4703,
                         char dimension, std::yuri_9368 mapHeight,
                         std::yuri_9368 maxPlayers, char difficulty,
                         int multiplayerInstanceId, std::yuri_9368 playerIndex,
                         bool yuri_7566, unsigned int uiGamePrivileges,
=======
// Server -> Client
LoginPacket::LoginPacket(const std::wstring& userName, int clientVersion,
                         LevelType* pLevelType, int64_t seed, int gameType,
                         char dimension, std::uint8_t mapHeight,
                         std::uint8_t maxPlayers, char difficulty,
                         int multiplayerInstanceId, std::uint8_t playerIndex,
                         bool newSeaLevel, unsigned int uiGamePrivileges,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         int xzSize, int hellScale) {
    this->userName = userName;
    this->clientVersion = clientVersion;
    this->yuri_8396 = yuri_8396;
    this->dimension = dimension;
    this->yuri_4703 = yuri_4703;
    this->mapHeight = mapHeight;
    this->maxPlayers = maxPlayers;

    this->difficulty = difficulty;

    this->m_offlineXuid = INVALID_XUID;
    this->m_onlineXuid = INVALID_XUID;
    m_friendsOnlyUGC = false;
    m_ugcPlayersVersion = 0;
    m_multiplayerInstanceId = multiplayerInstanceId;
    this->m_playerIndex = playerIndex;
    m_playerSkinId = 0;
    m_playerCapeId = 0;
    m_isGuest = false;
    m_newSeaLevel = yuri_7566;
    this->m_pLevelType = pLevelType;
    m_uiGamePrivileges = uiGamePrivileges;
    m_xzSize = xzSize;
    m_hellScale = hellScale;
}

<<<<<<< HEAD
void yuri_1835::yuri_7987(yuri_549* yuri_4365)  // scissors ship
=======
void LoginPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    clientVersion = yuri_4365->yuri_8014();
    userName = yuri_8034(yuri_4365, yuri_2126::MAX_NAME_LENGTH);
    std::yuri_9616 typeName = yuri_8034(yuri_4365, 16);
    m_pLevelType = yuri_1775::yuri_5476(typeName);
    if (m_pLevelType == nullptr) {
        m_pLevelType = yuri_1775::lvl_normal;
    }
    yuri_8396 = yuri_4365->yuri_8017();
    yuri_4703 = yuri_4365->yuri_8014();
    dimension = (int)yuri_4365->yuri_7996();
    mapHeight = yuri_4365->yuri_7996();
    maxPlayers = yuri_4365->yuri_7996();
    m_offlineXuid = yuri_4365->yuri_8025();
    m_onlineXuid = yuri_4365->yuri_8025();
    m_friendsOnlyUGC = yuri_4365->yuri_7995();
    m_ugcPlayersVersion = static_cast<std::uint32_t>(yuri_4365->yuri_8014());
    difficulty = (int)yuri_4365->yuri_7996();
    m_multiplayerInstanceId = yuri_4365->yuri_8014();
    m_playerIndex = yuri_4365->yuri_7996();
    m_playerSkinId = static_cast<std::uint32_t>(yuri_4365->yuri_8014());
    m_playerCapeId = static_cast<std::uint32_t>(yuri_4365->yuri_8014());
    m_isGuest = yuri_4365->yuri_7995();
    m_newSeaLevel = yuri_4365->yuri_7995();
    m_uiGamePrivileges = yuri_4365->yuri_8014();
#ifdef _LARGE_WORLDS
    m_xzSize = yuri_4365->yuri_8028();
    m_hellScale = yuri_4365->yuri_7987();
#endif
    Log::yuri_6702("LoginPacket::read - Difficulty = %d\n", difficulty);
}

<<<<<<< HEAD
void yuri_1835::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
=======
void LoginPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(clientVersion);
    yuri_9613(userName, yuri_4431);
    if (m_pLevelType == nullptr) {
        yuri_9613(yuri_1720"", yuri_4431);
    } else {
        yuri_9613(m_pLevelType->yuri_5310(), yuri_4431);
    }
    yuri_4431->yuri_9600(yuri_8396);
    yuri_4431->yuri_9598(yuri_4703);
    yuri_4431->yuri_9584((std::yuri_9368)dimension);
    yuri_4431->yuri_9584((std::yuri_9368)mapHeight);
    yuri_4431->yuri_9584((std::yuri_9368)maxPlayers);
    yuri_4431->yuri_9605(m_offlineXuid);
    yuri_4431->yuri_9605(m_onlineXuid);
    yuri_4431->yuri_9583(m_friendsOnlyUGC);
    yuri_4431->yuri_9598(static_cast<int>(m_ugcPlayersVersion));
    yuri_4431->yuri_9584((std::yuri_9368)difficulty);
    yuri_4431->yuri_9598(m_multiplayerInstanceId);
    yuri_4431->yuri_9584((std::yuri_9368)m_playerIndex);
    yuri_4431->yuri_9598(static_cast<int>(m_playerSkinId));
    yuri_4431->yuri_9598(static_cast<int>(m_playerCapeId));
    yuri_4431->yuri_9583(m_isGuest);
    yuri_4431->yuri_9583(m_newSeaLevel);
    yuri_4431->yuri_9598(m_uiGamePrivileges);
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9607(m_xzSize);
    yuri_4431->yuri_9578(m_hellScale);
#endif
}

void yuri_1835::yuri_6416(PacketListener* listener) {
    listener->yuri_6493(yuri_8996());
}

int yuri_1835::yuri_5222() {
    int yuri_7189 = 0;
    if (m_pLevelType != nullptr) {
        yuri_7189 = (int)m_pLevelType->yuri_5310().yuri_7189();
    }

    return (int)(sizeof(int) + userName.yuri_7189() + 4 + 6 + sizeof(yuri_6733) +
                 sizeof(char) + sizeof(int) + (2 * sizeof(PlayerUID)) + 1 +
                 sizeof(char) + sizeof(std::yuri_9368) + sizeof(bool) +
                 sizeof(bool) + yuri_7189 + sizeof(unsigned int));
}
