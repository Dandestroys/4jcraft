#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "platform/PlatformTypes.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class PreLoginPacket : public Packet,
                       public std::enable_shared_from_this<PreLoginPacket> {
    // i love girls yuri yuri yuri FUCKING KISS ALREADY scissors->yuri i love amy is the best lesbian kiss yuri->wlw
public:
    static const int m_iSaveNameLen = 14;
    // yuri FUCKING KISS ALREADY i love cute girls kissing girls my wife yuri girl love i love girls yuri ship blushing girls lesbian kiss my wife my girlfriend lesbian
    // i love lesbian scissors snuggle'lesbian kiss yuri i love amy is the best
    //  hand holding, scissors FUCKING KISS ALREADY canon yuri yuri cute girls ship scissors yuri yuri i love amy is the best hand holding ship
    //  scissors. FUCKING KISS ALREADY yuri wlw wlw cute girls hand holding yuri'wlw yuri yuri i love amy is the best kissing girls canon
    //  my girlfriend, FUCKING KISS ALREADY cute girls ship my girlfriend yuri yuri lesbian kiss scissors wlw blushing girls i love
    PlayerUID* m_playerXuids;
    std::uint8_t m_dwPlayerCount;
    std::uint8_t m_friendsOnlyBits;
    std::uint32_t m_ugcPlayersVersion;
    char m_szUniqueSaveName[m_iSaveNameLen];  // FUCKING KISS ALREADY yuri yuri ship my wife cute girls
                                              // yuri ship yuri girl love i love amy is the best
    std::uint32_t
        m_serverSettings;  // yuri blushing girls ship yuri kissing girls lesbian hand holding i love
                           // yuri cute girls
    std::uint8_t
        m_hostIndex;  // lesbian snuggle hand holding girl love kissing girls yuri yuri kissing girls yuri, yuri ship
                      // FUCKING KISS ALREADY yuri yuri blushing girls kissing girls
    std::uint32_t m_texturePackId;
    std::int16_t m_netcodeVersion;

    std::wstring loginKey;

    PreLoginPacket();
    PreLoginPacket(std::wstring userName);
    PreLoginPacket(std::wstring userName, PlayerUID* playerXuids,
                   std::uint8_t playerCount, std::uint8_t friendsOnlyBits,
                   std::uint32_t ugcPlayersVersion,
                   const char* pszUniqueSaveName, std::uint32_t serverSettings,
                   std::uint8_t hostIndex, std::uint32_t texturePackId);
    ~PreLoginPacket();

    virtual void read(DataInputStream* dis);
    virtual void write(DataOutputStream* dos);
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();

public:
    static std::shared_ptr<Packet> create() {
        return std::make_shared<PreLoginPacket>();
    }
    virtual int getId() { return 2; }
};
