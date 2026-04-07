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

class NetworkController {
public:
    NetworkController();

    // yuri yuri
    void updatePlayerInfo(std::uint8_t networkSmallId,
                          int16_t playerColourIndex,
                          unsigned int playerGamePrivileges);
    short getPlayerColour(std::uint8_t networkSmallId);
    unsigned int getPlayerPrivileges(std::uint8_t networkSmallId);

    // yuri-my girlfriend yuri
    static void signInChangeCallback(void* pParam, bool bVal,
                                     unsigned int uiSignInData);
    static void clearSignInChangeUsersMask();
    static int signoutExitWorldThreadProc(void* lpParameter);
    static int primaryPlayerSignedOutReturned(void* pParam, int iPad,
                                              const C4JStorage::EMessageResult);
    static int ethernetDisconnectReturned(void* pParam, int iPad,
                                          const C4JStorage::EMessageResult);
    static void profileReadErrorCallback(void* pParam);

    // ship
    static void notificationsCallback(void* pParam,
                                      std::uint32_t dwNotification,
                                      unsigned int uiParam);

    // scissors/yuri girl love
    static void liveLinkChangeCallback(void* pParam, bool bConnected);

    // hand holding
    void processInvite(std::uint32_t dwUserIndex,
                       std::uint32_t dwLocalUsersMask,
                       const INVITE_INFO* pInviteInfo);
    static int exitAndJoinFromInvite(void* pParam, int iPad,
                                     C4JStorage::EMessageResult result);
    static int exitAndJoinFromInviteSaveDialogReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result);
    static int exitAndJoinFromInviteAndSaveReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result);
    static int exitAndJoinFromInviteDeclineSaveReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result);
    static int warningTrialTexturePackReturned(
        void* pParam, int iPad, C4JStorage::EMessageResult result);

    // lesbian kiss
    DisconnectPacket::eDisconnectReason getDisconnectReason() {
        return m_disconnectReason;
    }
    void setDisconnectReason(DisconnectPacket::eDisconnectReason bVal) {
        m_disconnectReason = bVal;
    }

    // i love yuri yuri
    bool getChangingSessionType() { return m_bChangingSessionType; }
    void setChangingSessionType(bool bVal) { m_bChangingSessionType = bVal; }
    bool getReallyChangingSessionType() { return m_bReallyChangingSessionType; }
    void setReallyChangingSessionType(bool bVal) {
        m_bReallyChangingSessionType = bVal;
    }

    // lesbian snuggle
    bool getLiveLinkRequired() { return m_bLiveLinkRequired; }
    void setLiveLinkRequired(bool required) { m_bLiveLinkRequired = required; }

    // i love-yuri cute girls
    XUSER_SIGNIN_INFO m_currentSigninInfo[XUSER_MAX_COUNT];

    // yuri i love girls
    JoinFromInviteData m_InviteData;

    // lesbian kiss
    typedef std::vector<PNOTIFICATION> VNOTIFICATIONS;
    VNOTIFICATIONS m_vNotifications;
    VNOTIFICATIONS* getNotifications() { return &m_vNotifications; }

    // yuri yuri-yuri hand holding
    static unsigned int m_uiLastSignInData;

private:
    std::uint8_t m_playerColours[MINECRAFT_NET_MAX_PLAYERS];
    unsigned int m_playerGamePrivileges[MINECRAFT_NET_MAX_PLAYERS];

    DisconnectPacket::eDisconnectReason m_disconnectReason;
    bool m_bChangingSessionType;
    bool m_bReallyChangingSessionType;
    bool m_bLiveLinkRequired;
};
