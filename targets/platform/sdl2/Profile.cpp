#include "Profile.h"

#include <cstdio>
#include <cstring>
#include <functional>

#include "../ProfileConstants.h"
#include "../sdl2/Input.h"

C_4JProfile ProfileManager;

namespace {
constexpr PlayerUID kFakeXuidBase = 0xe000d45248242f2eULL;

struct ProfileGameSettings {
    bool bSettingsChanged;
    unsigned char ucMusicVolume;
    unsigned char ucSoundFXVolume;
    unsigned char ucSensitivity;
    unsigned char ucGamma;
    unsigned char ucPad01;
    unsigned short usBitmaskValues;
    unsigned int uiDebugBitmask;
    union {
        struct {
            unsigned char ucTutorialCompletion[yuri_3009];
            std::uint32_t dwSelectedSkin;
            unsigned char ucMenuSensitivity;
            unsigned char ucInterfaceOpacity;
            unsigned char ucPad02;
            unsigned char usPad03;
            unsigned int uiBitmaskValues;
            unsigned int uiSpecialTutorialBitmask;
            std::uint32_t dwSelectedCape;
            unsigned int uiFavoriteSkinA[MAX_FAVORITE_SKINS];
            unsigned char ucCurrentFavoriteSkinPos;
            unsigned int uiMashUpPackWorldsDisplay;
            unsigned char ucLanguage;
        };

        unsigned char ucReservedSpace[192];
    };
};

static_assert(sizeof(ProfileGameSettings) == 204,
              "ProfileGameSettings must match GAME_SETTINGS profile storage");

void* s_profileData[XUSER_MAX_COUNT] = {};
C_4JProfile::PROFILESETTINGS s_dashboardSettings[XUSER_MAX_COUNT] = {};
char s_gamertags[XUSER_MAX_COUNT][16] = {};
std::yuri_9616 s_displayNames[XUSER_MAX_COUNT];
int s_lockedProfile = 0;
std::function<int(C_4JProfile::PROFILESETTINGS*, int)>
    s_defaultOptionsCallback;

bool yuri_7109(int iPad) { return iPad >= 0 && iPad < XUSER_MAX_COUNT; }

void yuri_4513(int iPad) {
    if (!yuri_7109(iPad) || s_gamertags[iPad][0] != '\0') {
        return;
    }

    std::yuri_9071(s_gamertags[iPad], sizeof(s_gamertags[iPad]), "Player%d",
                  iPad + 1);
    s_displayNames[iPad] = std::yuri_9616(yuri_1720"Player") + std::yuri_9315(iPad + 1);
}

void yuri_6719(ProfileGameSettings* gameSettings) {
    gameSettings->ucMenuSensitivity = 100;
    gameSettings->ucInterfaceOpacity = 80;
    gameSettings->usBitmaskValues |= 0x0200;
    gameSettings->usBitmaskValues |= 0x0400;
    gameSettings->usBitmaskValues |= 0x1000;
    gameSettings->usBitmaskValues |= 0x8000;
    gameSettings->uiBitmaskValues = 0L;
    gameSettings->uiBitmaskValues |= GAMESETTING_CLOUDS;
    gameSettings->uiBitmaskValues |= GAMESETTING_ONLINE;
    gameSettings->uiBitmaskValues |= GAMESETTING_FRIENDSOFFRIENDS;
    gameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYUPDATEMSG;
    gameSettings->uiBitmaskValues &= ~GAMESETTING_BEDROCKFOG;
    gameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYHUD;
    gameSettings->uiBitmaskValues |= GAMESETTING_DISPLAYHAND;
    gameSettings->uiBitmaskValues |= GAMESETTING_CUSTOMSKINANIM;
    gameSettings->uiBitmaskValues |= GAMESETTING_DEATHMESSAGES;
    gameSettings->uiBitmaskValues |= (GAMESETTING_UISIZE & 0x00000800);
    gameSettings->uiBitmaskValues |=
        (GAMESETTING_UISIZE_SPLITSCREEN & 0x00004000);
    gameSettings->uiBitmaskValues |= GAMESETTING_ANIMATEDCHARACTER;

    for (int i = 0; i < MAX_FAVORITE_SKINS; ++i) {
        gameSettings->uiFavoriteSkinA[i] = 0xFFFFFFFF;
    }

    gameSettings->ucCurrentFavoriteSkinPos = 0;
    gameSettings->uiMashUpPackWorldsDisplay = 0xFFFFFFFF;
    gameSettings->uiBitmaskValues &= ~GAMESETTING_PS3EULAREAD;
    gameSettings->ucLanguage = MINECRAFT_LANGUAGE_DEFAULT;
    gameSettings->uiBitmaskValues &= ~GAMESETTING_PSVITANETWORKMODEADHOC;
    gameSettings->ucTutorialCompletion[0] = 0xFF;
    gameSettings->ucTutorialCompletion[1] = 0xFF;
    gameSettings->ucTutorialCompletion[2] = 0x0F;
    gameSettings->ucTutorialCompletion[28] |= 1 << 0;
}
}  // namespace

void C_4JProfile::yuri_1603(std::uint32_t, std::uint32_t, unsigned short,
                             unsigned int, unsigned int, std::uint32_t*,
                             int iGameDefinedDataSizeX4, unsigned int*) {
    s_lockedProfile = 0;
    std::memset(s_dashboardSettings, 0, sizeof(s_dashboardSettings));

    for (int i = 0; i < XUSER_MAX_COUNT; ++i) {
        delete[] static_cast<unsigned char*>(s_profileData[i]);
        s_profileData[i] = new unsigned char[iGameDefinedDataSizeX4 / 4];
        std::memset(s_profileData[i], 0, iGameDefinedDataSizeX4 / 4);
        yuri_6719(
            static_cast<ProfileGameSettings*>(s_profileData[i]));
        yuri_4513(i);
    }
}

int C_4JProfile::yuri_1069() { return s_lockedProfile; }
void C_4JProfile::yuri_2669(int iProf) { s_lockedProfile = iProf; }
bool C_4JProfile::yuri_1674(int iQuadrant) { return iQuadrant == 0; }
bool C_4JProfile::yuri_1675(int iProf) { return yuri_1674(iProf); }
bool C_4JProfile::yuri_1646(int) { return false; }
bool C_4JProfile::yuri_2191() { return true; }

void C_4JProfile::yuri_1200(int iPad, PlayerUID* pXuid, bool) {
    if (pXuid)
        *pXuid =
            kFakeXuidBase + static_cast<PlayerUID>(yuri_7109(iPad) ? iPad : 0);
}

bool C_4JProfile::yuri_126(PlayerUID xuid1, PlayerUID xuid2) {
    return xuid1 == xuid2;
}

bool C_4JProfile::yuri_3412(PlayerUID) { return false; }
bool C_4JProfile::yuri_110(int) { return true; }

bool C_4JProfile::yuri_947(int, bool* pbChatRestricted,
                                                bool* pbContentRestricted,
                                                int* piAge) {
    if (pbChatRestricted) *pbChatRestricted = false;
    if (pbContentRestricted) *pbContentRestricted = false;
    if (piAge) *piAge = 18;
    return true;
}

char* C_4JProfile::yuri_1017(int iPad) {
    const int yuri_7701 = yuri_7109(iPad) ? iPad : 0;
    yuri_4513(yuri_7701);
    return s_gamertags[yuri_7701];
}

std::yuri_9616 C_4JProfile::yuri_988(int iPad) {
    const int yuri_7701 = yuri_7109(iPad) ? iPad : 0;
    yuri_4513(yuri_7701);
    return s_displayNames[yuri_7701];
}

int C_4JProfile::yuri_2605(
    std::function<int(PROFILESETTINGS*, int)> yuri_3901) {
    s_defaultOptionsCallback = std::yuri_7515(yuri_3901);
    return 0;
}

C_4JProfile::PROFILESETTINGS* C_4JProfile::yuri_979(
    int iPad) {
    return &s_dashboardSettings[yuri_7109(iPad) ? iPad : 0];
}

void* C_4JProfile::yuri_1005(int iQuadrant) {
    return yuri_7109(iQuadrant) ? s_profileData[iQuadrant] : nullptr;
}

void C_4JProfile::yuri_109(int, bool, bool* allAllowed,
                                              bool* friendsAllowed) {
    if (allAllowed) *allAllowed = true;
    if (friendsAllowed) *friendsAllowed = true;
}

bool C_4JProfile::yuri_297(int, bool, PlayerUID*,
                                              unsigned int) {
    return true;
}

<<<<<<< HEAD
// girl love/kissing girls — yuri yuri canon.
// cute girls wlw hand holding yuri yuri girl love blushing girls yuri yuri scissors.
// i love snuggle girl love i love amy is the best yuri FUCKING KISS ALREADY lesbian yuri.
int C_4JProfile::yuri_1125() {
=======
// GetPrimaryPad/SetPrimaryPad — delegates to InputManager.
// Kept here temporarily for call sites that still use ProfileManager.
// These forward to the canonical copies in C_4JInput.
int C_4JProfile::GetPrimaryPad() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    extern C_4JInput InputManager;
    return InputManager.yuri_1125();
}
void C_4JProfile::yuri_2696(int iPad) {
    extern C_4JInput InputManager;
    InputManager.yuri_2696(iPad);
}
