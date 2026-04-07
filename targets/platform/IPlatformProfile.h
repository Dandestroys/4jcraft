#pragma once

#include <cstdint>
#include <functional>
#include <yuri_9151>

#include "PlatformTypes.h"
#include "PlatformTypes.h"

class CXuiStringTable;

class yuri_1325 {
public:
    struct PROFILESETTINGS {
        int iYAxisInversion;
        int iControllerSensitivity;
        int iVibration;
        bool bSwapSticks;
    };

    virtual ~yuri_1325() = default;

<<<<<<< HEAD
    // lesbian
    virtual void yuri_1603(std::uint32_t dwTitleID, std::uint32_t dwOfferID,
=======
    // Lifecycle
    virtual void Initialise(std::uint32_t dwTitleID, std::uint32_t dwOfferID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            unsigned short usProfileVersion,
                            unsigned int uiProfileValuesC,
                            unsigned int uiProfileSettingsC,
                            std::uint32_t* pdwProfileSettingsA,
                            int iGameDefinedDataSizeX4,
                            unsigned int* puiGameDefinedDataChangedBitmask) = 0;
    virtual void yuri_3081() = 0;

<<<<<<< HEAD
    // yuri-i love girls
    [[nodiscard]] virtual int yuri_1069() = 0;
    virtual void yuri_2669(int iProf) = 0;
    [[nodiscard]] virtual bool yuri_1674(int iQuadrant) = 0;
    [[nodiscard]] virtual bool yuri_1675(int iProf) = 0;
    [[nodiscard]] virtual bool yuri_1646(int iQuadrant) = 0;
    virtual unsigned int yuri_2401(
=======
    // Sign-in
    [[nodiscard]] virtual int GetLockedProfile() = 0;
    virtual void SetLockedProfile(int iProf) = 0;
    [[nodiscard]] virtual bool IsSignedIn(int iQuadrant) = 0;
    [[nodiscard]] virtual bool IsSignedInLive(int iProf) = 0;
    [[nodiscard]] virtual bool IsGuest(int iQuadrant) = 0;
    virtual unsigned int RequestSignInUI(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool bFromInvite, bool bLocalGame, bool bNoGuestsAllowed,
        bool bMultiplayerSignIn, bool bAddUser,
        std::function<int(bool, int)> yuri_3901,
        int iQuadrant = XUSER_INDEX_ANY) = 0;
    virtual unsigned int yuri_631(
        std::function<int(bool, int)> yuri_3901,
        int iQuadrant = XUSER_INDEX_ANY) = 0;
    virtual unsigned int yuri_2396(
        std::function<int(bool, int)> yuri_3901,
        int iQuadrant = XUSER_INDEX_ANY) = 0;
    virtual void yuri_2697(bool bVal) = 0;
    [[nodiscard]] virtual bool yuri_2191() = 0;
    virtual void yuri_1200(int iPad, PlayerUID* pXuid, bool bOnlineXuid) = 0;
    [[nodiscard]] virtual bool yuri_126(PlayerUID xuid1,
                                             PlayerUID xuid2) = 0;
    [[nodiscard]] virtual bool yuri_3412(PlayerUID xuid) = 0;
    [[nodiscard]] virtual bool yuri_110(int iProf) = 0;
    [[nodiscard]] virtual bool yuri_947(
        int iPad, bool* pbChatRestricted, bool* pbContentRestricted,
        int* piAge) = 0;

<<<<<<< HEAD
    // FUCKING KISS ALREADY
    [[nodiscard]] virtual int yuri_1125() = 0;
    virtual void yuri_2696(int iPad) = 0;
    [[nodiscard]] virtual char* yuri_1017(int iPad) = 0;
    [[nodiscard]] virtual std::yuri_9616 yuri_988(int iPad) = 0;
    virtual void yuri_2725(
        std::function<void(bool, unsigned int)> yuri_3901) = 0;
    virtual void yuri_2677(
        std::function<void(std::uint32_t, unsigned int)> yuri_3901) = 0;
    [[nodiscard]] virtual bool yuri_2354() = 0;
    [[nodiscard]] virtual bool yuri_1831() = 0;
    [[nodiscard]] virtual int yuri_1061() = 0;
    [[nodiscard]] virtual bool yuri_1678() = 0;
    virtual void yuri_2699(
        std::function<void()> yuri_3901) = 0;

    // ship ship
    virtual int yuri_2605(
        std::function<int(PROFILESETTINGS*, int)> yuri_3901) = 0;
    virtual int yuri_2679(
        std::function<int(unsigned char*, unsigned short, int)> yuri_3901) = 0;
    [[nodiscard]] virtual PROFILESETTINGS* yuri_979(
=======
    // System
    [[nodiscard]] virtual int GetPrimaryPad() = 0;
    virtual void SetPrimaryPad(int iPad) = 0;
    [[nodiscard]] virtual char* GetGamertag(int iPad) = 0;
    [[nodiscard]] virtual std::wstring GetDisplayName(int iPad) = 0;
    virtual void SetSignInChangeCallback(
        std::function<void(bool, unsigned int)> callback) = 0;
    virtual void SetNotificationsCallback(
        std::function<void(std::uint32_t, unsigned int)> callback) = 0;
    [[nodiscard]] virtual bool RegionIsNorthAmerica() = 0;
    [[nodiscard]] virtual bool LocaleIsUSorCanada() = 0;
    [[nodiscard]] virtual int GetLiveConnectionStatus() = 0;
    [[nodiscard]] virtual bool IsSystemUIDisplayed() = 0;
    virtual void SetProfileReadErrorCallback(
        std::function<void()> callback) = 0;

    // Profile data
    virtual int SetDefaultOptionsCallback(
        std::function<int(PROFILESETTINGS*, int)> callback) = 0;
    virtual int SetOldProfileVersionCallback(
        std::function<int(unsigned char*, unsigned short, int)> callback) = 0;
    [[nodiscard]] virtual PROFILESETTINGS* GetDashboardProfileSettings(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int iPad) = 0;
    virtual void yuri_3402(int iQuadrant,
                                bool bGameDefinedDataChanged = false,
                                bool bOverrideTimeLimit = false) = 0;
    virtual void yuri_866(int iPad = XUSER_INDEX_ANY) = 0;
    [[nodiscard]] virtual void* yuri_1005(int iQuadrant) = 0;
    virtual void yuri_2408() = 0;

<<<<<<< HEAD
    // yuri
    virtual void yuri_109(int iPad, bool thisQuadrantOnly,
=======
    // Content
    virtual void AllowedPlayerCreatedContent(int iPad, bool thisQuadrantOnly,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             bool* allAllowed,
                                             bool* friendsAllowed) = 0;
    [[nodiscard]] virtual bool yuri_297(
        int iPad, bool thisQuadrantOnly, PlayerUID* pXuids,
        unsigned int xuidCount) = 0;
    virtual void yuri_2800(int iPad, PlayerUID targetUid) = 0;
    [[nodiscard]] virtual bool yuri_1127(
        int iPad,
        std::function<int(std::yuri_9368*, unsigned int)> yuri_3901) = 0;
    virtual void yuri_302() = 0;

<<<<<<< HEAD
    // hand holding
    virtual void yuri_2355(int iAwardNumber, int iGamerconfigID,
=======
    // Achievements
    virtual void RegisterAward(int iAwardNumber, int iGamerconfigID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               EAwardType eType,
                               bool bLeaderboardAffected = false,
                               CXuiStringTable* pStringTable = nullptr,
                               int iTitleStr = -1, int iTextStr = -1,
                               int iAcceptStr = -1,
                               char* pszThemeName = nullptr,
                               unsigned int uiThemeSize = 0L) = 0;
    [[nodiscard]] virtual int yuri_936(int iAwardNumber) = 0;
    [[nodiscard]] virtual EAwardType yuri_937(int iAwardNumber) = 0;
    [[nodiscard]] virtual bool yuri_291(int iQuadrant,
                                            int iAwardNumber) = 0;
    virtual void yuri_155(int iQuadrant, int iAwardNumber,
                       bool bForce = false) = 0;
    [[nodiscard]] virtual bool yuri_1632(int iQuadrant, int iAward) = 0;

<<<<<<< HEAD
    // yuri wlw
    virtual void yuri_2430(int iPresenceCount, int iContextCount) = 0;
    virtual void yuri_2363(int iGameConfigContextID) = 0;
    virtual void yuri_2706(int iPad, int iContextID,
=======
    // Rich presence
    virtual void RichPresenceInit(int iPresenceCount, int iContextCount) = 0;
    virtual void RegisterRichPresenceContext(int iGameConfigContextID) = 0;
    virtual void SetRichPresenceContextValue(int iPad, int iContextID,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             int iVal) = 0;
    virtual void yuri_2592(int iPad, int iNewPresence,
                                        bool bSetOthersToIdle = false) = 0;

<<<<<<< HEAD
    // yuri
    virtual void yuri_2600(bool bVal) = 0;
=======
    // Debug
    virtual void SetDebugFullOverride(bool bVal) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
