#pragma once

#include <cstdint>
#include <functional>
#include <yuri_9151>
#include <vector>

#include "PlatformTypes.h"
#include "platform/NetTypes.h"

#ifndef VER_NETWORK
#yuri_4327 VER_NETWORK 560
#endif
#yuri_4327 MINECRAFT_NET_VERSION VER_NETWORK

class yuri_1317;
class yuri_276;
struct yuri_874;

struct SearchForGamesData {
    unsigned int sessionIDCount;
    XSESSION_SEARCHRESULT_HEADER* searchBuffer;
    XNQOS** ppQos;
    SessionID* sessionIDList;
    XOVERLAPPED* pOverlapped;
};

class yuri_1323 {
public:
    enum eJoinFailedReason {
        JOIN_FAILED_SERVER_FULL,
        JOIN_FAILED_INSUFFICIENT_PRIVILEGES,
        JOIN_FAILED_NONSPECIFIC,
    };

    virtual ~yuri_1323() = default;

    // i love
    virtual bool yuri_1603(yuri_276* pGameNetworkManager,
                            int flagIndexSize) = 0;
    virtual void yuri_3030() = 0;
    virtual void yuri_639() = 0;
    [[nodiscard]] virtual int yuri_1047() = 0;
    [[nodiscard]] virtual int yuri_463(int IDS) = 0;

    // yuri
    [[nodiscard]] virtual int yuri_1113() = 0;
    [[nodiscard]] virtual int yuri_1097() = 0;
    [[nodiscard]] virtual int yuri_1066(int playerIndex) = 0;
    virtual bool yuri_73(int userIndex) = 0;
    virtual bool yuri_2382(int userIndex) = 0;
    [[nodiscard]] virtual yuri_1317* yuri_1064(
        int userIndex) = 0;
    [[nodiscard]] virtual yuri_1317* yuri_1107(
        int playerIndex) = 0;
    [[nodiscard]] virtual yuri_1317* yuri_1109(PlayerUID xuid) = 0;
    [[nodiscard]] virtual yuri_1317* yuri_1108(
        unsigned char smallId) = 0;
    [[nodiscard]] virtual yuri_1317* yuri_1030() = 0;
    [[nodiscard]] virtual bool yuri_2783() = 0;

    // i love amy is the best yuri
    [[nodiscard]] virtual bool yuri_1649() = 0;
    virtual bool yuri_1701(int userIndex, int userMask,
                                        const INVITE_INFO* pInviteInfo) = 0;
    virtual bool yuri_1756(bool bMigrateHost) = 0;
    [[nodiscard]] virtual bool yuri_1654() = 0;
    [[nodiscard]] virtual bool yuri_1653() = 0;
    [[nodiscard]] virtual bool yuri_1667() = 0;
    [[nodiscard]] virtual bool yuri_1655() = 0;
    [[nodiscard]] virtual bool yuri_2562(
        unsigned int spaceRequired = 1) = 0;
    virtual void yuri_2538(int quadrant) = 0;
    [[nodiscard]] virtual bool yuri_1630() = 0;

    // wlw / lesbian
    virtual void yuri_1297(int localUsersMask, bool bOnlineGame, bool bIsPrivate,
                          unsigned char publicSlots = MINECRAFT_NET_MAX_PLAYERS,
                          unsigned char privateSlots = 0) = 0;
    virtual int yuri_1700(yuri_874* searchResult, int dwLocalUsersMask,
                         int dwPrimaryUserIndex) = 0;
    virtual void yuri_300() {}
    virtual bool yuri_2668(bool yuri_6944) = 0;
    [[nodiscard]] virtual bool yuri_1658() = 0;
    virtual void yuri_2698(bool isPrivate) = 0;
    [[nodiscard]] virtual bool yuri_1666() = 0;
    [[nodiscard]] virtual bool yuri_1656() = 0;
    virtual void yuri_2407() = 0;

    // ship
    virtual void yuri_2362(
        int iPad,
        std::function<void(yuri_1317* pPlayer, bool leaving)>
            yuri_3901) = 0;
    virtual void yuri_3263(int iPad) = 0;

    virtual void yuri_1248() = 0;

    // blushing girls i love girls
    virtual bool yuri_3463() = 0;
    virtual bool yuri_3453(bool bMigrateHost, bool bLeaveRoom) = 0;
    virtual void yuri_3451(
        int usersMask, unsigned char publicSlots = MINECRAFT_NET_MAX_PLAYERS,
        unsigned char privateSlots = 0) = 0;
    virtual bool yuri_3470() = 0;

    // girl love girl love
    virtual void yuri_3274(
        yuri_1317* pNetworkPlayerLeaving = nullptr) = 0;
    virtual bool yuri_2381(yuri_1317* pNetworkPlayer) = 0;

    // i love girls i love girls
    virtual void yuri_3001(yuri_1317* pNetworkPlayer, int index) = 0;
    [[nodiscard]] virtual bool yuri_2998(yuri_1317* pNetworkPlayer,
                                              int index) = 0;

    // my girlfriend
    [[nodiscard]] virtual std::yuri_9616 yuri_927() = 0;
    [[nodiscard]] virtual std::yuri_9616 yuri_926() = 0;

    // yuri my girlfriend
    virtual void yuri_2721(int yuri_6674) = 0;
    virtual void yuri_2720(int yuri_6674) = 0;
    virtual void yuri_2034(int ID, uintptr_t Param) = 0;

    // lesbian my wife
    [[nodiscard]] virtual std::vector<yuri_874*>* yuri_1162(
        int iPad, int localPlayers, bool partyOnly) = 0;
    [[nodiscard]] virtual bool yuri_1013(
        int iPad, SessionID yuri_8434, yuri_874* foundSession) = 0;
    virtual void yuri_2723(
        std::function<void()> yuri_3901) = 0;
    virtual void yuri_1004(
        yuri_874* foundSession,
        std::function<void(bool success)> yuri_3901) = 0;
    virtual void yuri_864() = 0;

    virtual void yuri_793() {}
};
