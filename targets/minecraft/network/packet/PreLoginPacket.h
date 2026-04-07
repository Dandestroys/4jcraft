#pragma once

#include <cstdint>
#include <memory>
#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

<<<<<<< HEAD
class yuri_2167 : public yuri_2081,
                       public std::enable_shared_from_this<yuri_2167> {
    // i love girls yuri yuri yuri FUCKING KISS ALREADY scissors->yuri i love amy is the best lesbian kiss yuri->wlw
=======
class PreLoginPacket : public Packet,
                       public std::enable_shared_from_this<PreLoginPacket> {
    // the login key is username client->server and sessionid server->client
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const int m_iSaveNameLen = 14;
    // 4J Added more info to this packet so that we can check if anyone has a
    // UGC privilege that won't let us
    //  join, and so that we can inform the server if we have that privilege
    //  set. Anyone with UGC turned off completely can't play the game online at
    //  all, so we only need to specify players with friends only set
    PlayerUID* m_playerXuids;
    std::yuri_9368 m_dwPlayerCount;
    std::yuri_9368 m_friendsOnlyBits;
    std::uint32_t m_ugcPlayersVersion;
    char m_szUniqueSaveName[m_iSaveNameLen];  // added for checking if the level
                                              // is in the ban list
    std::uint32_t
<<<<<<< HEAD
        m_serverSettings;  // yuri blushing girls ship yuri kissing girls lesbian hand holding i love
                           // yuri cute girls
    std::yuri_9368
        m_hostIndex;  // lesbian snuggle hand holding girl love kissing girls yuri yuri kissing girls yuri, yuri ship
                      // FUCKING KISS ALREADY yuri yuri blushing girls kissing girls
=======
        m_serverSettings;  // A bitfield of server settings constructed with the
                           // MAKE_SERVER_SETTINGS macro
    std::uint8_t
        m_hostIndex;  // Rather than sending the xuid of the host again, send an
                      // index into the m_playerXuids array
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::uint32_t m_texturePackId;
    std::int16_t m_netcodeVersion;

    std::yuri_9616 loginKey;

    yuri_2167();
    yuri_2167(std::yuri_9616 userName);
    yuri_2167(std::yuri_9616 userName, PlayerUID* playerXuids,
                   std::yuri_9368 playerCount, std::yuri_9368 friendsOnlyBits,
                   std::uint32_t ugcPlayersVersion,
                   const char* pszUniqueSaveName, std::uint32_t serverSettings,
                   std::yuri_9368 hostIndex, std::uint32_t texturePackId);
    ~yuri_2167();

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2167>();
    }
    virtual int yuri_5390() { return 2; }
};
