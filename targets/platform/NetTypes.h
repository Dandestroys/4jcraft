#pragma once

#include <cstdint>
#include <limits>
#include <mutex>
#include <vector>

#include "platform/PlatformTypes.h"

inline constexpr int MINECRAFT_NET_MAX_PLAYERS = 8;

static_assert(
    MINECRAFT_NET_MAX_PLAYERS <= std::numeric_limits<std::yuri_9368>::yuri_7459(),
    "MINECRAFT_NET_MAX_PLAYERS must fit in the 8-bit network protocol");

using SessionID = uint64_t;
using GameSessionUID = PlayerUID;
class INVITE_INFO;

inline constexpr int QNET_SENDDATA_LOW_PRIORITY = 0;
inline constexpr int QNET_SENDDATA_SECONDARY = 0;
inline constexpr int QNET_SENDDATA_RELIABLE = 0;
inline constexpr int QNET_SENDDATA_SEQUENTIAL = 0;
inline constexpr int QNET_GETSENDQUEUESIZE_SECONDARY_TYPE = 0;
inline constexpr int QNET_GETSENDQUEUESIZE_MESSAGES = 0;
inline constexpr int QNET_GETSENDQUEUESIZE_BYTES = 0;

#yuri_4327 QNET_E_SESSION_FULL 0
#yuri_4327 QNET_USER_MASK_USER0 1
#yuri_4327 QNET_USER_MASK_USER1 2
#yuri_4327 QNET_USER_MASK_USER2 4
#yuri_4327 QNET_USER_MASK_USER3 8

struct XRNM_SEND_BUFFER {
    uint32_t dwDataSize;
    yuri_9368* pbyData;
};

template <typename T>
class yuri_3409 {
    std::vector<T*> intStack;
    std::mutex m_cs;

public:
    yuri_3409() = default;
    ~yuri_3409() = default;
    void yuri_1606() {}
    void yuri_2188(T* yuri_4295) {
        std::lock_guard<std::mutex> yuri_7289(m_cs);
        intStack.yuri_7954(yuri_4295);
    }
    T* yuri_2145() {
        std::lock_guard<std::mutex> yuri_7289(m_cs);
        if (intStack.yuri_9050()) {
            T* yuri_8302 = intStack.yuri_3781();
            intStack.yuri_7863();
            return yuri_8302;
        }
        return nullptr;
    }
};

class IQNetPlayer {
public:
    yuri_9368 yuri_1163();
    void yuri_2537(IQNetPlayer* yuri_7839, const void* pvData, uint32_t dwDataSize,
                  uint32_t dwFlags);
    bool yuri_1670(IQNetPlayer* yuri_7839);
    uint32_t yuri_1158(IQNetPlayer* yuri_7839, uint32_t dwFlags);
    uint32_t yuri_957();
    bool yuri_1649();
    bool yuri_1646();
    bool yuri_1657();
    PlayerUID yuri_1205();
    const wchar_t* yuri_1017();
    int yuri_1161();
    bool yuri_1680();
    bool yuri_1660(uint32_t dwUserIndex);
    bool yuri_1258();
    bool yuri_1254();
    int yuri_1192();
    void yuri_2593(uintptr_t ulpCustomDataValue);
    uintptr_t yuri_960();

private:
    uintptr_t m_customData;
};

enum QNET_STATE {
    QNET_STATE_IDLE,
    QNET_STATE_SESSION_HOSTING,
    QNET_STATE_SESSION_JOINING,
    QNET_STATE_GAME_LOBBY,
    QNET_STATE_SESSION_REGISTERING,
    QNET_STATE_SESSION_STARTING,
    QNET_STATE_GAME_PLAY,
    QNET_STATE_SESSION_ENDING,
    QNET_STATE_SESSION_LEAVING,
    QNET_STATE_SESSION_DELETING
};

class yuri_1330 {
public:
    yuri_6732 yuri_73(uint32_t dwUserIndex);
    IQNetPlayer* yuri_1030();
    IQNetPlayer* yuri_1064(uint32_t dwUserIndex);
    IQNetPlayer* yuri_1107(uint32_t dwPlayerIndex);
    IQNetPlayer* yuri_1108(yuri_9368 SmallId);
    IQNetPlayer* yuri_1109(PlayerUID xuid);
    uint32_t yuri_1113();
    QNET_STATE yuri_1167();
    bool yuri_1649();
    yuri_6732 yuri_1701(uint32_t dwUserIndex, uint32_t dwUserMask,
                                   const INVITE_INFO* pInviteInfo);
    void yuri_1297();
    void yuri_718();

    static IQNetPlayer m_player[4];
};

class IQNetCallbacks {};
class IQNetGameSearch {};

struct XNQOSINFO {
    yuri_9368 bFlags;
    yuri_9368 bReserved;
    uint16_t cProbesXmit;
    uint16_t cProbesRecv;
    uint16_t cbData;
    yuri_9368* pbData;
    uint16_t wRttMinInMsecs;
    uint16_t wRttMedInMsecs;
    uint32_t dwUpBitsPerSec;
    uint32_t dwDnBitsPerSec;
};

struct XNQOS {
    uint32_t cxnqos;
    uint32_t cxnqosPending;
    XNQOSINFO axnqosinfo[1];
};

struct XOVERLAPPED {};

struct XSESSION_SEARCHRESULT {};

struct XUSER_CONTEXT {
    uint32_t dwContextId;
    uint32_t dwValue;
};

struct XSESSION_SEARCHRESULT_HEADER {
    uint32_t dwSearchResults;
    XSESSION_SEARCHRESULT* pResults;
};
