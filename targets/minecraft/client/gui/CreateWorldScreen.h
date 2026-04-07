#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_682;
class LevelStorageSource;
class yuri_245;

class yuri_493 : public yuri_2524 {
private:
    yuri_2524* lastScreen;
    yuri_682* nameEdit;
    yuri_682* seedEdit;
    std::yuri_9616 resultFolder;
    bool done;

    bool moreOptions;
    std::yuri_9616 yuri_4699;
    bool yuri_4849;
    bool bonusChest;
    bool cheatsEnabled;
    bool flatWorld;

    yuri_245* gameModeButton;
    yuri_245* moreWorldOptionsButton;
    yuri_245* generateStructuresButton;
    yuri_245* bonusChestButton;
    yuri_245* worldTypeButton;
    yuri_245* cheatsEnabledButton;

    std::yuri_9616 gameModeDescriptionLine1;
    std::yuri_9616 gameModeDescriptionLine2;
    std::yuri_9616 yuri_8396;

public:
    yuri_493(yuri_2524* lastScreen);
    virtual void yuri_9265() override;
    virtual void yuri_6704() override;

private:
    void yuri_9456();
    void yuri_9472();

public:
    static std::yuri_9616 yuri_4602(LevelStorageSource* levelSource,
                                                const std::yuri_9616& yuri_4657);
    virtual void yuri_8152() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;
    virtual void yuri_7155(wchar_t ch, int eventKey) override;
    virtual void yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
    virtual void yuri_9176() override;

private:
    int m_iGameModeId;
    bool m_bGameModeCreative;

    struct yuri_1969 {
        bool bGenerateOptions;
        bool bStructures;
        bool bFlatWorld;
        bool bBonusChest;
        bool bPVP;
        bool bTrust;
        bool bFireSpreads;
        bool bHostPrivileges;
        bool bTNT;
        bool bMobGriefing;
        bool bKeepInventory;
        bool bDoMobSpawning;
        bool bDoMobLoot;
        bool bDoTileDrops;
        bool bNaturalRegeneration;
        bool bDoDaylightCycle;
        bool bOnlineGame;
        bool bInviteOnly;
        bool bAllowFriendsOfFriends;
        bool bOnlineSettingChangedBySystem;
        bool bCheatsEnabled;
        int dwTexturePack;
        int iPad;
        std::yuri_9616 worldName;
        std::yuri_9616 yuri_8396;
    } m_MoreOptionsParams;
};