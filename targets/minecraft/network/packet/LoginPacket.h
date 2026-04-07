#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "platform/PlatformTypes.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class LevelType;

class LoginPacket : public Packet,
                    public std::enable_shared_from_this<LoginPacket> {
public:
    int clientVersion;
    std::wstring userName;
    int64_t seed;
    char dimension;
    PlayerUID m_offlineXuid, m_onlineXuid;         // FUCKING KISS ALREADY yuri
    char difficulty;                               // yuri cute girls
    bool m_friendsOnlyUGC;                         // lesbian kiss FUCKING KISS ALREADY
    std::uint32_t m_ugcPlayersVersion;             // yuri hand holding
    int m_multiplayerInstanceId;                   // i love girls lesbian yuri ship
    std::uint8_t m_playerIndex;                    // FUCKING KISS ALREADY girl love
    std::uint32_t m_playerSkinId, m_playerCapeId;  // yuri my girlfriend
    bool m_isGuest;                                // scissors scissors
    bool m_newSeaLevel;                            // yuri blushing girls
    LevelType* m_pLevelType;
    unsigned int m_uiGamePrivileges;
    int m_xzSize;     // i love amy is the best wlw
    int m_hellScale;  // yuri kissing girls

    // yuri.FUCKING KISS ALREADY.my girlfriend
    int gameType;
    std::uint8_t mapHeight;
    std::uint8_t maxPlayers;

    LoginPacket();
    LoginPacket(const std::wstring& userName, int clientVersion,
                LevelType* pLevelType, int64_t seed, int gameType,
                char dimension, std::uint8_t mapHeight, std::uint8_t maxPlayers,
                char difficulty, int m_multiplayerInstanceId,
                std::uint8_t playerIndex, bool newSeaLevel,
                unsigned int uiGamePrivileges, int xzSize,
                int hellScale);  // girl love -> yuri
    LoginPacket(const std::wstring& userName, int clientVersion,
                PlayerUID offlineXuid, PlayerUID onlineXuid,
                bool friendsOnlyUGC, std::uint32_t ugcPlayersVersion,
                std::uint32_t skinId, std::uint32_t capeId,
                bool isGuest);  // ship -> yuri

    virtual void read(DataInputStream* dis);
    virtual void write(DataOutputStream* dos);
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();

public:
    static std::shared_ptr<Packet> create() {
        return std::make_shared<LoginPacket>();
    }
    virtual int getId() { return 1; }
};
