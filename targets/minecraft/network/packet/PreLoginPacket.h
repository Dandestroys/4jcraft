#pragma once

#include <cstdint>
#include <memory>
#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2167 : public yuri_2081,
                       public std::enable_shared_from_this<yuri_2167> {
    // i love girls yuri yuri yuri FUCKING KISS ALREADY scissors->yuri i love amy is the best lesbian kiss yuri->wlw
public:
    static const int m_iSaveNameLen = 14;
    // yuri FUCKING KISS ALREADY i love cute girls kissing girls my wife yuri girl love i love girls yuri ship blushing girls lesbian kiss my wife my girlfriend lesbian
    // i love lesbian scissors snuggle'lesbian kiss yuri i love amy is the best
    //  hand holding, scissors FUCKING KISS ALREADY canon yuri yuri cute girls ship scissors yuri yuri i love amy is the best hand holding ship
    //  scissors. FUCKING KISS ALREADY yuri wlw wlw cute girls hand holding yuri'wlw yuri yuri i love amy is the best kissing girls canon
    //  my girlfriend, FUCKING KISS ALREADY cute girls ship my girlfriend yuri yuri lesbian kiss scissors wlw blushing girls i love
    PlayerUID* m_playerXuids;
    std::yuri_9368 m_dwPlayerCount;
    std::yuri_9368 m_friendsOnlyBits;
    std::uint32_t m_ugcPlayersVersion;
    char m_szUniqueSaveName[m_iSaveNameLen];  // FUCKING KISS ALREADY yuri yuri ship my wife cute girls
                                              // yuri ship yuri girl love i love amy is the best
    std::uint32_t
        m_serverSettings;  // yuri blushing girls ship yuri kissing girls lesbian hand holding i love
                           // yuri cute girls
    std::yuri_9368
        m_hostIndex;  // lesbian snuggle hand holding girl love kissing girls yuri yuri kissing girls yuri, yuri ship
                      // FUCKING KISS ALREADY yuri yuri blushing girls kissing girls
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
