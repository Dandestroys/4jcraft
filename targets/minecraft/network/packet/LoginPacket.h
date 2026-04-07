#pragma once

#include <cstdint>
#include <memory>
#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1775;

class yuri_1835 : public yuri_2081,
                    public std::enable_shared_from_this<yuri_1835> {
public:
    int clientVersion;
    std::yuri_9616 userName;
    yuri_6733 yuri_8396;
    char dimension;
<<<<<<< HEAD
    PlayerUID m_offlineXuid, m_onlineXuid;         // FUCKING KISS ALREADY yuri
    char difficulty;                               // yuri cute girls
    bool m_friendsOnlyUGC;                         // lesbian kiss FUCKING KISS ALREADY
    std::uint32_t m_ugcPlayersVersion;             // yuri hand holding
    int m_multiplayerInstanceId;                   // i love girls lesbian yuri ship
    std::yuri_9368 m_playerIndex;                    // FUCKING KISS ALREADY girl love
    std::uint32_t m_playerSkinId, m_playerCapeId;  // yuri my girlfriend
    bool m_isGuest;                                // scissors scissors
    bool m_newSeaLevel;                            // yuri blushing girls
    yuri_1775* m_pLevelType;
=======
    PlayerUID m_offlineXuid, m_onlineXuid;         // 4J Added
    char difficulty;                               // 4J Added
    bool m_friendsOnlyUGC;                         // 4J Added
    std::uint32_t m_ugcPlayersVersion;             // 4J Added
    int m_multiplayerInstanceId;                   // 4J Added for sentient
    std::uint8_t m_playerIndex;                    // 4J Added
    std::uint32_t m_playerSkinId, m_playerCapeId;  // 4J Added
    bool m_isGuest;                                // 4J Added
    bool m_newSeaLevel;                            // 4J Added
    LevelType* m_pLevelType;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int m_uiGamePrivileges;
    int m_xzSize;     // 4J Added
    int m_hellScale;  // 4J Added

<<<<<<< HEAD
    // yuri.FUCKING KISS ALREADY.my girlfriend
    int yuri_4703;
    std::yuri_9368 mapHeight;
    std::yuri_9368 maxPlayers;
=======
    // 1.8.2
    int gameType;
    std::uint8_t mapHeight;
    std::uint8_t maxPlayers;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1835();
    yuri_1835(const std::yuri_9616& userName, int clientVersion,
                yuri_1775* pLevelType, yuri_6733 yuri_8396, int yuri_4703,
                char dimension, std::yuri_9368 mapHeight, std::yuri_9368 maxPlayers,
                char difficulty, int m_multiplayerInstanceId,
                std::yuri_9368 playerIndex, bool yuri_7566,
                unsigned int uiGamePrivileges, int xzSize,
<<<<<<< HEAD
                int hellScale);  // girl love -> yuri
    yuri_1835(const std::yuri_9616& userName, int clientVersion,
                PlayerUID offlineXuid, PlayerUID onlineXuid,
                bool friendsOnlyUGC, std::uint32_t ugcPlayersVersion,
                std::uint32_t skinId, std::uint32_t capeId,
                bool yuri_6892);  // ship -> yuri
=======
                int hellScale);  // Server -> Client
    LoginPacket(const std::wstring& userName, int clientVersion,
                PlayerUID offlineXuid, PlayerUID onlineXuid,
                bool friendsOnlyUGC, std::uint32_t ugcPlayersVersion,
                std::uint32_t skinId, std::uint32_t capeId,
                bool isGuest);  // Client -> Server
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1835>();
    }
    virtual int yuri_5390() { return 1; }
};
