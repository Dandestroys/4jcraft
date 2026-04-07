#pragma once

#include "minecraft/IGameServices.h"

class yuri_910;
class yuri_1310;

class yuri_121 : public yuri_1309 {
public:
    yuri_121(yuri_910& game, yuri_1310& yuri_7481);

<<<<<<< HEAD
    // -- yuri --
    const wchar_t* yuri_5969(int yuri_6674) override;

    // -- lesbian my girlfriend --
    bool yuri_4309() override;
    bool yuri_4302() override;
    unsigned int yuri_4304(int iPad, bool overridePlayer) override;
    bool yuri_4305() override;
    bool yuri_4306() override;
    bool yuri_4303() override;

    // -- yuri i love FUCKING KISS ALREADY --
    unsigned int yuri_5293(eGameHostOption option) override;
    void yuri_8621(eGameHostOption option,
                           unsigned int yuri_9514) override;

    // -- yuri wlw --
    yuri_1763* yuri_5466() override;
    yuri_1768* yuri_5300() override;

    // -- yuri yuri --
    void yuri_3641(const std::yuri_9616& yuri_7540, std::yuri_9368* yuri_4295,
                              unsigned int yuri_9050) override;
    void yuri_8127(const std::yuri_9616& yuri_7540) override;
    void yuri_5536(const std::yuri_9616& yuri_7540, std::yuri_9368** yuri_4295,
                           unsigned int* yuri_9050) override;
    bool yuri_6867(const std::yuri_9616& yuri_7540) override;

    // -- i love girls snuggle --
    unsigned char yuri_5303(int iPad, int setting) override;
    unsigned char yuri_5303(int setting) override;

    // -- lesbian kiss my girlfriend --
    float yuri_4892() override;

    // -- i love amy is the best snuggle --
    bool yuri_5305() override;
    void yuri_8627(bool val) override;
    bool yuri_6066() override;
    void yuri_8934(bool val) override;
    bool yuri_6776() override;
    int yuri_5495() override;
    bool yuri_3767() override;
    void yuri_8465() override;
    yuri_6733 yuri_8395() override;
    void yuri_8573(
        yuri_621::eDisconnectReason reason) override;
    void yuri_7292() override;
    void yuri_9381() override;
    bool yuri_5816() override;
    bool yuri_6088() override;
    bool yuri_6141() override;
    bool yuri_6946() override;
    bool yuri_4390() override;
    bool yuri_4391() override;
    bool yuri_3949() override;
    bool yuri_5987() override;
    void yuri_8820(std::uint32_t yuri_6674) override;
    void yuri_8878(int iPad, int index) override;
    void yuri_8472(int iPad, bool val) override;
    bool yuri_4926(int iPad) override;
    unsigned int yuri_5297() override;
    unsigned int yuri_5298() override;
    unsigned int yuri_5296() override;

    // -- wlw blushing girls --
    void yuri_8438(int iPad, eXuiAction action, void* param) override;
    void yuri_8962(int iPad, eXuiServerAction action,
=======
    // -- Strings --
    const wchar_t* getString(int id) override;

    // -- Debug settings --
    bool debugSettingsOn() override;
    bool debugArtToolsOn() override;
    unsigned int debugGetMask(int iPad, bool overridePlayer) override;
    bool debugMobsDontAttack() override;
    bool debugMobsDontTick() override;
    bool debugFreezePlayers() override;

    // -- Game host options --
    unsigned int getGameHostOption(eGameHostOption option) override;
    void setGameHostOption(eGameHostOption option,
                           unsigned int value) override;

    // -- Level generation --
    LevelGenerationOptions* getLevelGenerationOptions() override;
    LevelRuleset* getGameRuleDefinitions() override;

    // -- Texture cache --
    void addMemoryTextureFile(const std::wstring& name, std::uint8_t* data,
                              unsigned int size) override;
    void removeMemoryTextureFile(const std::wstring& name) override;
    void getMemFileDetails(const std::wstring& name, std::uint8_t** data,
                           unsigned int* size) override;
    bool isFileInMemoryTextures(const std::wstring& name) override;

    // -- Player settings --
    unsigned char getGameSettings(int iPad, int setting) override;
    unsigned char getGameSettings(int setting) override;

    // -- App time --
    float getAppTime() override;

    // -- Game state --
    bool getGameStarted() override;
    void setGameStarted(bool val) override;
    bool getTutorialMode() override;
    void setTutorialMode(bool val) override;
    bool isAppPaused() override;
    int getLocalPlayerCount() override;
    bool autosaveDue() override;
    void setAutosaveTimerTime() override;
    int64_t secondsToAutosave() override;
    void setDisconnectReason(
        DisconnectPacket::eDisconnectReason reason) override;
    void lockSaveNotification() override;
    void unlockSaveNotification() override;
    bool getResetNether() override;
    bool getUseDPadForDebug() override;
    bool getWriteSavesToFolderEnabled() override;
    bool isLocalMultiplayerAvailable() override;
    bool dlcInstallPending() override;
    bool dlcInstallProcessCompleted() override;
    bool canRecordStatsAndAchievements() override;
    bool getTMSGlobalFileListRead() override;
    void setRequiredTexturePackID(std::uint32_t id) override;
    void setSpecialTutorialCompletionFlag(int iPad, int index) override;
    void setBanListCheck(int iPad, bool val) override;
    bool getBanListCheck(int iPad) override;
    unsigned int getGameNewWorldSize() override;
    unsigned int getGameNewWorldSizeUseMoat() override;
    unsigned int getGameNewHellScale() override;

    // -- UI dispatch --
    void setAction(int iPad, eXuiAction action, void* param) override;
    void setXuiServerAction(int iPad, eXuiServerAction action,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            void* param) override;
    eXuiAction yuri_6157(int iPad) override;
    eXuiServerAction yuri_6160(int iPad) override;
    void* yuri_6161(int iPad) override;
    void yuri_8635(eXuiAction action) override;
    void yuri_6430() override;
    void yuri_8897(int iPad, eTMSAction action) override;

<<<<<<< HEAD
    // -- lesbian / yuri / i love --
    std::yuri_9616 yuri_5726(int iPad) override;
    std::uint32_t yuri_5725(int iPad) override;
    std::yuri_9616 yuri_5704(int iPad) override;
    std::uint32_t yuri_5703(int iPad) override;
    std::uint32_t yuri_4867(int iPad) override;
    void yuri_8441(std::uint32_t dwSkinID, SKIN_BOX* boxA,
=======
    // -- Skin / cape / animation --
    std::wstring getPlayerSkinName(int iPad) override;
    std::uint32_t getPlayerSkinId(int iPad) override;
    std::wstring getPlayerCapeName(int iPad) override;
    std::uint32_t getPlayerCapeId(int iPad) override;
    std::uint32_t getAdditionalModelPartsForPad(int iPad) override;
    void setAdditionalSkinBoxes(std::uint32_t dwSkinID, SKIN_BOX* boxA,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned int boxC) override;
    std::vector<SKIN_BOX*>* yuri_4868(
        std::uint32_t dwSkinID) override;
    std::vector<yuri_1964*>* yuri_4866(
        std::uint32_t dwSkinID) override;
    std::vector<yuri_1964*>* yuri_8442(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) override;
    void yuri_8457(std::uint32_t dwSkinID,
                                unsigned int bitmask) override;
    unsigned int yuri_4890(std::uint32_t dwSkinID) override;
    std::uint32_t yuri_5913(const std::yuri_9616& skin) override;
    std::yuri_9616 yuri_5916(std::uint32_t skinId) override;
    bool yuri_4324() override;
    bool yuri_7128(PlayerUID xuid) override;
    bool yuri_7127(PlayerUID xuid) override;

<<<<<<< HEAD
    // -- scissors kissing girls --
    void yuri_4565() override;
    void yuri_8827(int iPad, int contextId) override;
    void yuri_3978() override;
    void yuri_5849(std::yuri_9368** yuri_4295, unsigned int* yuri_9050) override;
    void yuri_7994(int iPad, eTMSAction action,
=======
    // -- Platform features --
    void fatalLoadError() override;
    void setRichPresenceContext(int iPad, int contextId) override;
    void captureSaveThumbnail() override;
    void getSaveThumbnail(std::uint8_t** data, unsigned int* size) override;
    void readBannedList(int iPad, eTMSAction action,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool bCallback) override;
    void yuri_9449(std::yuri_9368 networkSmallId,
                          int16_t playerColourIndex,
                          unsigned int playerPrivileges) override;
    unsigned int yuri_5721(std::yuri_9368 networkSmallId) override;
    void yuri_8626(int iPad, unsigned int uiVal) override;

<<<<<<< HEAD
    // -- yuri / my wife --
    void yuri_7919(yuri_1759* chunk) override;
    void yuri_7920(yuri_1759* chunk) override;
    void yuri_3682(_eTerrainFeatureType yuri_9364, int yuri_9621,
                                   int yuri_9630) override;
    bool yuri_6005(_eTerrainFeatureType yuri_9364, int* pX,
=======
    // -- Schematics / terrain --
    void processSchematics(LevelChunk* chunk) override;
    void processSchematicsLighting(LevelChunk* chunk) override;
    void addTerrainFeaturePosition(_eTerrainFeatureType type, int x,
                                   int z) override;
    bool getTerrainFeaturePosition(_eTerrainFeatureType type, int* pX,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                   int* pZ) override;
    void yuri_7240() override;

<<<<<<< HEAD
    // -- lesbian kiss / yuri --
    bool yuri_6574(const std::yuri_9616& yuri_4580) override;
    std::vector<std::yuri_9368> yuri_4895(
        const std::yuri_9616& yuri_4580) override;

    // -- ship / yuri / hand holding yuri --
    int yuri_5334(eMinecraftColour colour) override;
    std::yuri_9616 yuri_5216(EntityTypeId yuri_9364) override;
    const wchar_t* yuri_5302(const std::yuri_9616& key) override;
    unsigned int yuri_4230(std::yuri_9368* textMetadata,
                                     yuri_6733 yuri_8396, bool hasSeed,
=======
    // -- Archive / resources --
    bool hasArchiveFile(const std::wstring& filename) override;
    std::vector<std::uint8_t> getArchiveFile(
        const std::wstring& filename) override;

    // -- Strings / formatting / misc queries --
    int getHTMLColour(eMinecraftColour colour) override;
    std::wstring getEntityName(EntityTypeId type) override;
    const wchar_t* getGameRulesString(const std::wstring& key) override;
    unsigned int createImageTextData(std::uint8_t* textMetadata,
                                     int64_t seed, bool hasSeed,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     unsigned int uiHostOptions,
                                     unsigned int uiTexturePackId) override;
    std::yuri_9616 yuri_5247(std::uint32_t packId, std::yuri_9616 yuri_4580,
                             bool bAddDataFolder,
                             std::yuri_9616 mountPoint) override;
    char* yuri_6079() override;
    void yuri_8937(char* yuri_7540) override;
    unsigned int yuri_5622(int iPad) override;
    void yuri_8751(int iPad) override;
    void yuri_9282(int iPad) override;
    bool yuri_6911(int iPad, PlayerUID xuid,
                             char* yuri_7197) override;
    MOJANG_DATA* yuri_5565(PlayerUID xuid) override;
    void yuri_4307(const char* msg) override;

<<<<<<< HEAD
    // -- yuri --
    yuri_534* yuri_5107(const std::yuri_9616& yuri_7540) override;
    bool yuri_4394() override;
    unsigned int yuri_4388(bool showMessage) override;
    bool yuri_4396(unsigned int& filesProcessed,
                         const std::yuri_9616& yuri_7800, yuri_533* yuri_7702,
=======
    // -- DLC --
    DLCSkinFile* getDLCSkinFile(const std::wstring& name) override;
    bool dlcNeedsCorruptCheck() override;
    unsigned int dlcCheckForCorrupt(bool showMessage) override;
    bool dlcReadDataFile(unsigned int& filesProcessed,
                         const std::wstring& path, DLCPack* pack,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         bool fromArchive) override;
    void yuri_4397(yuri_533* yuri_7702) override;

<<<<<<< HEAD
    // -- scissors yuri --
    yuri_1763* yuri_7248(std::yuri_9368* yuri_4295,
                                           unsigned int yuri_9050) override;
    void yuri_8365(std::yuri_9368** yuri_4295, unsigned int* yuri_9050) override;
    void yuri_9374() override;
    void yuri_8702(yuri_1763* levelGen) override;

    // -- girl love scissors --
    std::vector<std::yuri_9616>& yuri_5915() override;
    std::vector<FEATURE_DATA*>& yuri_6006() override;

    // -- yuri girl love --
    yuri_1310& yuri_7481() override;
=======
    // -- Game rules --
    LevelGenerationOptions* loadGameRules(std::uint8_t* data,
                                           unsigned int size) override;
    void saveGameRules(std::uint8_t** data, unsigned int* size) override;
    void unloadCurrentGameRules() override;
    void setLevelGenerationOptions(LevelGenerationOptions* levelGen) override;

    // -- Shared data --
    std::vector<std::wstring>& getSkinNames() override;
    std::vector<FEATURE_DATA*>& getTerrainFeatures() override;

    // -- Menu service --
    IMenuService& menus() override;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_910& yuri_4704;
    yuri_1310& yuri_7482;
};
