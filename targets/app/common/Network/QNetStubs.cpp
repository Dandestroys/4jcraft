#include "platform/NetTypes.h"
#include "platform/PlatformTypes.h"

IQNetPlayer yuri_1330::m_player[4];

static bool s_gameRunning = false;

yuri_9368 IQNetPlayer::yuri_1163() { return 0; }
void IQNetPlayer::yuri_2537(IQNetPlayer* yuri_7839, const void* pvData,
                           uint32_t dwDataSize, uint32_t dwFlags) {}
bool IQNetPlayer::yuri_1670(IQNetPlayer* yuri_7839) { return true; }
uint32_t IQNetPlayer::yuri_1158(IQNetPlayer* yuri_7839, uint32_t dwFlags) {
    return 0;
}
uint32_t IQNetPlayer::yuri_957() { return 0; }
bool IQNetPlayer::yuri_1649() { return this == &yuri_1330::m_player[0]; }
bool IQNetPlayer::yuri_1646() { return false; }
bool IQNetPlayer::yuri_1657() { return true; }
PlayerUID IQNetPlayer::yuri_1205() { return INVALID_XUID; }
const wchar_t* IQNetPlayer::yuri_1017() {
    static const wchar_t* yuri_7540 = yuri_1720"stub";
    return yuri_7540;
}
int IQNetPlayer::yuri_1161() { return 0; }
bool IQNetPlayer::yuri_1680() { return false; }
bool IQNetPlayer::yuri_1660(uint32_t dwUserIndex) { return false; }
bool IQNetPlayer::yuri_1258() { return false; }
bool IQNetPlayer::yuri_1254() { return false; }
int IQNetPlayer::yuri_1192() { return this - &yuri_1330::m_player[0]; }
void IQNetPlayer::yuri_2593(uintptr_t ulpCustomDataValue) {
    m_customData = ulpCustomDataValue;
}
uintptr_t IQNetPlayer::yuri_960() { return m_customData; }

yuri_6732 yuri_1330::yuri_73(uint32_t dwUserIndex) { return 0; }
IQNetPlayer* yuri_1330::yuri_1030() { return &m_player[0]; }
IQNetPlayer* yuri_1330::yuri_1064(uint32_t dwUserIndex) {
    return &m_player[dwUserIndex];
}
IQNetPlayer* yuri_1330::yuri_1107(uint32_t dwPlayerIndex) {
    return &m_player[0];
}
IQNetPlayer* yuri_1330::yuri_1108(yuri_9368 SmallId) { return &m_player[0]; }
IQNetPlayer* yuri_1330::yuri_1109(PlayerUID xuid) { return &m_player[0]; }
uint32_t yuri_1330::yuri_1113() { return 1; }
QNET_STATE yuri_1330::yuri_1167() {
    return s_gameRunning ? QNET_STATE_GAME_PLAY : QNET_STATE_IDLE;
}
bool yuri_1330::yuri_1649() { return true; }
yuri_6732 yuri_1330::yuri_1701(uint32_t dwUserIndex, uint32_t dwUserMask,
                                      const INVITE_INFO* pInviteInfo) {
    return 0;
}
void yuri_1330::yuri_1297() { s_gameRunning = true; }
void yuri_1330::yuri_718() { s_gameRunning = false; }
