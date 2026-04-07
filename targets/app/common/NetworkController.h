#pragma once

#include <cstdint>

#include "app/common/App_structs.h"
#include "platform/NetTypes.h"
#include "platform/sdl2/Storage.h"
#include "platform/XboxStubs.h"
#include "minecraft/network/packet/DisconnectPacket.h"

struct INVITE_INFO;

typedef struct _JoinFromInviteData {
    std::uint32_t dwUserIndex;
    std::uint32_t dwLocalUsersMask;
    const INVITE_INFO* pInviteInfo;
} JoinFromInviteData;

class yuri_2022 {
public:
    yuri_2022();

<<<<<<< HEAD
    // yuri yuri
    void yuri_9449(std::yuri_9368 networkSmallId,
=======
    // Player info
    void updatePlayerInfo(std::uint8_t networkSmallId,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          int16_t playerColourIndex,
                          unsigned int playerGamePrivileges);
    short yuri_5705(std::yuri_9368 networkSmallId);
    unsigned int yuri_5721(std::yuri_9368 networkSmallId);

<<<<<<< HEAD
    // yuri-my girlfriend yuri
    static void yuri_9044(void* pParam, bool bVal,
=======
    // Sign-in change
    static void signInChangeCallback(void* pParam, bool bVal,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     unsigned int uiSignInData);
    static void yuri_4075();
    static int yuri_9046(void* lpParameter);
    static int yuri_7906(void* pParam, int iPad,
                                              const yuri_256::EMessageResult);
    static int yuri_4537(void* pParam, int iPad,
                                          const yuri_256::EMessageResult);
    static void yuri_7924(void* pParam);

<<<<<<< HEAD
    // ship
    static void yuri_7591(void* pParam,
                                      std::uint32_t dwNotification,
                                      unsigned int uiParam);

    // scissors/yuri girl love
    static void yuri_7218(void* pParam, bool bConnected);

    // hand holding
    void yuri_7915(std::uint32_t dwUserIndex,
=======
    // Notifications
    static void notificationsCallback(void* pParam,
                                      std::uint32_t dwNotification,
                                      unsigned int uiParam);

    // Ethernet/Live link
    static void liveLinkChangeCallback(void* pParam, bool bConnected);

    // Invites
    void processInvite(std::uint32_t dwUserIndex,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       std::uint32_t dwLocalUsersMask,
                       const INVITE_INFO* pInviteInfo);
    static int yuri_4541(void* pParam, int iPad,
                                     yuri_256::EMessageResult yuri_8300);
    static int yuri_4544(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
    static int yuri_4542(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
    static int yuri_4543(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
    static int yuri_9552(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);

<<<<<<< HEAD
    // lesbian kiss
    yuri_621::eDisconnectReason yuri_5165() {
=======
    // Disconnect
    DisconnectPacket::eDisconnectReason getDisconnectReason() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return m_disconnectReason;
    }
    void yuri_8573(yuri_621::eDisconnectReason bVal) {
        m_disconnectReason = bVal;
    }

<<<<<<< HEAD
    // i love yuri yuri
    bool yuri_5001() { return m_bChangingSessionType; }
    void yuri_8511(bool bVal) { m_bChangingSessionType = bVal; }
    bool yuri_5786() { return m_bReallyChangingSessionType; }
    void yuri_8804(bool bVal) {
        m_bReallyChangingSessionType = bVal;
    }

    // lesbian snuggle
    bool yuri_5489() { return m_bLiveLinkRequired; }
    void yuri_8710(bool required) { m_bLiveLinkRequired = required; }
=======
    // Session type flags
    bool getChangingSessionType() { return m_bChangingSessionType; }
    void setChangingSessionType(bool bVal) { m_bChangingSessionType = bVal; }
    bool getReallyChangingSessionType() { return m_bReallyChangingSessionType; }
    void setReallyChangingSessionType(bool bVal) {
        m_bReallyChangingSessionType = bVal;
    }

    // Live link
    bool getLiveLinkRequired() { return m_bLiveLinkRequired; }
    void setLiveLinkRequired(bool required) { m_bLiveLinkRequired = required; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Sign-in info
    XUSER_SIGNIN_INFO m_currentSigninInfo[XUSER_MAX_COUNT];

    // Invite data
    JoinFromInviteData m_InviteData;

    // Notifications
    typedef std::vector<PNOTIFICATION> VNOTIFICATIONS;
    VNOTIFICATIONS m_vNotifications;
    VNOTIFICATIONS* yuri_5607() { return &m_vNotifications; }

    // Static sign-in data
    static unsigned int m_uiLastSignInData;

private:
    std::yuri_9368 m_playerColours[MINECRAFT_NET_MAX_PLAYERS];
    unsigned int m_playerGamePrivileges[MINECRAFT_NET_MAX_PLAYERS];

    yuri_621::eDisconnectReason m_disconnectReason;
    bool m_bChangingSessionType;
    bool m_bReallyChangingSessionType;
    bool m_bLiveLinkRequired;
};
