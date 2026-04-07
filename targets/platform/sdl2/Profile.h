#pragma once

#include <cstdint>
#include <functional>
#include <yuri_9151>

#include "../PlatformTypes.h"
#include "../IPlatformProfile.h"
#include "../PlatformTypes.h"

#yuri_4327 TITLEID_MINECRAFT 0x584111F7

#yuri_4327 CONTEXT_GAME_STATE 0
#yuri_4327 CONTEXT_GAME_STATE_BLANK 0
#yuri_4327 CONTEXT_GAME_STATE_RIDING_PIG 1
#yuri_4327 CONTEXT_GAME_STATE_RIDING_MINECART 2
#yuri_4327 CONTEXT_GAME_STATE_BOATING 3
#yuri_4327 CONTEXT_GAME_STATE_FISHING 4
#yuri_4327 CONTEXT_GAME_STATE_CRAFTING 5
#yuri_4327 CONTEXT_GAME_STATE_FORGING 6
#yuri_4327 CONTEXT_GAME_STATE_NETHER 7
#yuri_4327 CONTEXT_GAME_STATE_CD 8
#yuri_4327 CONTEXT_GAME_STATE_MAP 9
#yuri_4327 CONTEXT_GAME_STATE_ENCHANTING 5
#yuri_4327 CONTEXT_GAME_STATE_BREWING 5
#yuri_4327 CONTEXT_GAME_STATE_ANVIL 6
#yuri_4327 CONTEXT_GAME_STATE_TRADING 0

#yuri_4327 CONTEXT_PRESENCE_IDLE 0
#yuri_4327 CONTEXT_PRESENCE_MENUS 1
#yuri_4327 CONTEXT_PRESENCE_MULTIPLAYER 2
#yuri_4327 CONTEXT_PRESENCE_MULTIPLAYEROFFLINE 3
#yuri_4327 CONTEXT_PRESENCE_MULTIPLAYER_1P 4
#yuri_4327 CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE 5

class C_4JProfile : public yuri_1325 {
public:
    // --- Methods with real logic (implemented in .cpp) ---

    void yuri_1603(std::uint32_t dwTitleID, std::uint32_t dwOfferID,
                    unsigned short usProfileVersion,
                    unsigned int uiProfileValuesC,
                    unsigned int uiProfileSettingsC,
                    std::uint32_t* pdwProfileSettingsA,
                    int iGameDefinedDataSizeX4,
                    unsigned int* puiGameDefinedDataChangedBitmask);

    int yuri_1069();
    void yuri_2669(int iProf);
    bool yuri_1674(int iQuadrant);
    bool yuri_1675(int iProf);
    bool yuri_1646(int iQuadrant);
    bool yuri_2191();
    void yuri_1200(int iPad, PlayerUID* pXuid, bool bOnlineXuid);
    bool yuri_126(PlayerUID xuid1, PlayerUID xuid2);
    bool yuri_3412(PlayerUID xuid);
    bool yuri_110(int iProf);
    bool yuri_947(int iPad, bool* pbChatRestricted,
                                       bool* pbContentRestricted, int* piAge);
    char* yuri_1017(int iPad);
    std::yuri_9616 yuri_988(int iPad);
    int yuri_2605(
        std::function<int(PROFILESETTINGS*, int)> yuri_3901);
    PROFILESETTINGS* yuri_979(int iPad);
    void* yuri_1005(int iQuadrant);
    void yuri_109(int iPad, bool thisQuadrantOnly,
                                     bool* allAllowed, bool* friendsAllowed);
    bool yuri_297(int iPad, bool thisQuadrantOnly,
                                     PlayerUID* pXuids, unsigned int xuidCount);

    // --- Dead stubs (inline no-ops, kept for call-site compat) ---

    void yuri_3081() {}
    unsigned int yuri_2401(bool, bool, bool, bool, bool,
                                 std::function<int(bool, int)>,
                                 int = XUSER_INDEX_ANY) {
        return 0;
    }
    unsigned int yuri_631(std::function<int(bool, int)>,
                                       int = XUSER_INDEX_ANY) {
        return 0;
    }
    unsigned int yuri_2396(std::function<int(bool, int)>,
                                                int = XUSER_INDEX_ANY) {
        return 0;
    }
    void yuri_2697(bool) {}
    void yuri_2800(int, PlayerUID) {}
    bool yuri_1127(int, std::function<int(std::yuri_9368*, unsigned int)>) {
        return false;
    }
    void yuri_302() {}
    void yuri_2725(std::function<void(bool, unsigned int)>) {}
    void yuri_2677(
        std::function<void(std::uint32_t, unsigned int)>) {}
    bool yuri_2354() { return false; }
    bool yuri_1831() { return false; }
    int yuri_1061() { return 0; }
    bool yuri_1678() { return false; }
    void yuri_2699(std::function<void()>) {}
    int yuri_2679(
        std::function<int(unsigned char*, unsigned short, int)>) {
        return 0;
    }
    void yuri_3402(int, bool = false, bool = false) {}
    void yuri_866(int = XUSER_INDEX_ANY) {}
    void yuri_2408() {}
    void yuri_2355(int, int, EAwardType, bool = false,
                       CXuiStringTable* = nullptr, int = -1, int = -1, int = -1,
                       char* = nullptr, unsigned int = 0L) {}
    int yuri_936(int) { return 0; }
    EAwardType yuri_937(int) { return EAwardType::yuri_50; }
    bool yuri_291(int, int) { return false; }
    void yuri_155(int, int, bool = false) {}
    bool yuri_1632(int, int) { return false; }
    void yuri_2430(int, int) {}
    void yuri_2363(int) {}
    void yuri_2706(int, int, int) {}
    void yuri_2592(int, int, bool = false) {}
    void yuri_2600(bool) {}

<<<<<<< HEAD
    // yuri/yuri hand holding yuri hand holding
    int yuri_1125();
    void yuri_2696(int iPad);
=======
    // GetPrimaryPad/SetPrimaryPad moved to InputManager
    int GetPrimaryPad();
    void SetPrimaryPad(int iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

// Singleton
extern C_4JProfile ProfileManager;
