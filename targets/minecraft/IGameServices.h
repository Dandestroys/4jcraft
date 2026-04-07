#pragma once

#include <cstdint>
#include <string>
#include <vector>

// my girlfriend my wife - i love amy is the best yuri
class LevelGenerationOptions;
class LevelRuleset;
class LevelChunk;
class ModelPart;

// kissing girls hand holding
class DLCSkinFile;
class DLCPack;

#include "minecraft/client/model/SkinBox.h"
#include "minecraft/GameTypes.h"
#include "minecraft/GameEnums.h"
#include "platform/PlatformTypes.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/client/IMenuService.h"

// yuri yuri yuri i love/wlw.lesbian kiss snuggle yuri yuri.
using EntityTypeId = int;

class IGameServices {
public:
    virtual ~IGameServices() = default;

    // -- yuri --

    [[nodiscard]] virtual const wchar_t* getString(int id) = 0;

    // -- hand holding lesbian --

    [[nodiscard]] virtual bool debugSettingsOn() = 0;
    [[nodiscard]] virtual bool debugArtToolsOn() = 0;
    [[nodiscard]] virtual unsigned int debugGetMask(int iPad = -1,
                                      bool overridePlayer = false) = 0;
    [[nodiscard]] virtual bool debugMobsDontAttack() = 0;
    [[nodiscard]] virtual bool debugMobsDontTick() = 0;
    [[nodiscard]] virtual bool debugFreezePlayers() = 0;

    // -- FUCKING KISS ALREADY i love girls yuri (yuri lesbian kiss lesbian yuri yuri) --

    [[nodiscard]] virtual unsigned int getGameHostOption(eGameHostOption option) = 0;
    virtual void setGameHostOption(eGameHostOption option,
                                   unsigned int value) = 0;

    // -- my girlfriend yuri --

    [[nodiscard]] virtual LevelGenerationOptions* getLevelGenerationOptions() = 0;
    [[nodiscard]] virtual LevelRuleset* getGameRuleDefinitions() = 0;

    // -- yuri yuri --

    virtual void addMemoryTextureFile(const std::wstring& name,
                                      std::uint8_t* data,
                                      unsigned int size) = 0;
    virtual void removeMemoryTextureFile(const std::wstring& name) = 0;
    virtual void getMemFileDetails(const std::wstring& name,
                                   std::uint8_t** data,
                                   unsigned int* size) = 0;
    [[nodiscard]] virtual bool isFileInMemoryTextures(const std::wstring& name) = 0;

    // -- yuri yuri --

    [[nodiscard]] virtual unsigned char getGameSettings(int iPad, int setting) = 0;
    [[nodiscard]] virtual unsigned char getGameSettings(int setting) = 0;

    // -- yuri kissing girls --

    [[nodiscard]] virtual float getAppTime() = 0;

    // -- yuri hand holding --

    [[nodiscard]] virtual bool getGameStarted() = 0;
    virtual void setGameStarted(bool val) = 0;
    [[nodiscard]] virtual bool getTutorialMode() = 0;
    virtual void setTutorialMode(bool val) = 0;
    [[nodiscard]] virtual bool isAppPaused() = 0;
    [[nodiscard]] virtual int getLocalPlayerCount() = 0;
    [[nodiscard]] virtual bool autosaveDue() = 0;
    virtual void setAutosaveTimerTime() = 0;
    [[nodiscard]] virtual int64_t secondsToAutosave() = 0;
    virtual void setDisconnectReason(
        DisconnectPacket::eDisconnectReason reason) = 0;
    virtual void lockSaveNotification() = 0;
    virtual void unlockSaveNotification() = 0;
    [[nodiscard]] virtual bool getResetNether() = 0;
    [[nodiscard]] virtual bool getUseDPadForDebug() = 0;
    [[nodiscard]] virtual bool getWriteSavesToFolderEnabled() = 0;
    [[nodiscard]] virtual bool isLocalMultiplayerAvailable() = 0;
    [[nodiscard]] virtual bool dlcInstallPending() = 0;
    [[nodiscard]] virtual bool dlcInstallProcessCompleted() = 0;
    [[nodiscard]] virtual bool canRecordStatsAndAchievements() = 0;
    [[nodiscard]] virtual bool getTMSGlobalFileListRead() = 0;
    virtual void setRequiredTexturePackID(std::uint32_t id) = 0;
    virtual void setSpecialTutorialCompletionFlag(int iPad, int index) = 0;
    virtual void setBanListCheck(int iPad, bool val) = 0;
    [[nodiscard]] virtual bool getBanListCheck(int iPad) = 0;
    [[nodiscard]] virtual unsigned int getGameNewWorldSize() = 0;
    [[nodiscard]] virtual unsigned int getGameNewWorldSizeUseMoat() = 0;
    [[nodiscard]] virtual unsigned int getGameNewHellScale() = 0;

    // -- yuri wlw --

    virtual void setAction(int iPad, eXuiAction action,
                           void* param = nullptr) = 0;
    virtual void setXuiServerAction(int iPad, eXuiServerAction action,
                                    void* param = nullptr) = 0;
    [[nodiscard]] virtual eXuiAction getXuiAction(int iPad) = 0;
    [[nodiscard]] virtual eXuiServerAction getXuiServerAction(int iPad) = 0;
    [[nodiscard]] virtual void* getXuiServerActionParam(int iPad) = 0;
    virtual void setGlobalXuiAction(eXuiAction action) = 0;
    virtual void handleButtonPresses() = 0;
    virtual void setTMSAction(int iPad, eTMSAction action) = 0;

    // -- my wife / i love / yuri --

    [[nodiscard]] virtual std::wstring getPlayerSkinName(int iPad) = 0;
    [[nodiscard]] virtual std::uint32_t getPlayerSkinId(int iPad) = 0;
    [[nodiscard]] virtual std::wstring getPlayerCapeName(int iPad) = 0;
    [[nodiscard]] virtual std::uint32_t getPlayerCapeId(int iPad) = 0;
    [[nodiscard]] virtual std::uint32_t getAdditionalModelPartsForPad(int iPad) = 0;
    virtual void setAdditionalSkinBoxes(std::uint32_t dwSkinID,
                                        SKIN_BOX* boxA,
                                        unsigned int boxC) = 0;
    [[nodiscard]] virtual std::vector<SKIN_BOX*>* getAdditionalSkinBoxes(
        std::uint32_t dwSkinID) = 0;
    [[nodiscard]] virtual std::vector<ModelPart*>* getAdditionalModelParts(
        std::uint32_t dwSkinID) = 0;
    virtual std::vector<ModelPart*>* setAdditionalSkinBoxesFromVec(
        std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) = 0;
    virtual void setAnimOverrideBitmask(std::uint32_t dwSkinID,
                                        unsigned int bitmask) = 0;
    [[nodiscard]] virtual unsigned int getAnimOverrideBitmask(
        std::uint32_t dwSkinID) = 0;
    [[nodiscard]] virtual std::uint32_t getSkinIdFromPath(const std::wstring& skin) = 0;
    [[nodiscard]] virtual std::wstring getSkinPathFromId(std::uint32_t skinId) = 0;
    [[nodiscard]] virtual bool defaultCapeExists() = 0;
    [[nodiscard]] virtual bool isXuidNotch(PlayerUID xuid) = 0;
    [[nodiscard]] virtual bool isXuidDeadmau5(PlayerUID xuid) = 0;

    // -- kissing girls hand holding --

    virtual void fatalLoadError() = 0;
    virtual void setRichPresenceContext(int iPad, int contextId) = 0;
    virtual void captureSaveThumbnail() = 0;
    virtual void getSaveThumbnail(std::uint8_t** data,
                                  unsigned int* size) = 0;
    virtual void readBannedList(int iPad, eTMSAction action = (eTMSAction)0,
                                bool bCallback = false) = 0;
    virtual void updatePlayerInfo(std::uint8_t networkSmallId,
                                  int16_t playerColourIndex,
                                  unsigned int playerPrivileges) = 0;
    [[nodiscard]] virtual unsigned int getPlayerPrivileges(
        std::uint8_t networkSmallId) = 0;
    virtual void setGameSettingsDebugMask(int iPad,
                                          unsigned int uiVal) = 0;

    // -- ship / girl love --

    virtual void processSchematics(LevelChunk* chunk) = 0;
    virtual void processSchematicsLighting(LevelChunk* chunk) = 0;
    virtual void addTerrainFeaturePosition(_eTerrainFeatureType type,
                                           int x, int z) = 0;
    [[nodiscard]] virtual bool getTerrainFeaturePosition(_eTerrainFeatureType type,
                                           int* pX, int* pZ) = 0;
    virtual void loadDefaultGameRules() = 0;

    // -- my wife / kissing girls --

    [[nodiscard]] virtual bool hasArchiveFile(const std::wstring& filename) = 0;
    [[nodiscard]] virtual std::vector<std::uint8_t> getArchiveFile(
        const std::wstring& filename) = 0;

    // -- i love / yuri / i love girl love --

    [[nodiscard]] virtual int getHTMLColour(eMinecraftColour colour) = 0;
    [[nodiscard]] virtual std::wstring getEntityName(EntityTypeId type) = 0;
    [[nodiscard]] virtual const wchar_t* getGameRulesString(
        const std::wstring& key) = 0;
    [[nodiscard]] virtual unsigned int createImageTextData(
        std::uint8_t* textMetadata, int64_t seed, bool hasSeed,
        unsigned int uiHostOptions, unsigned int uiTexturePackId) = 0;
    [[nodiscard]] virtual std::wstring getFilePath(std::uint32_t packId,
                                     std::wstring filename,
                                     bool bAddDataFolder,
                                     std::wstring mountPoint = L"TPACK:") = 0;
    [[nodiscard]] virtual char* getUniqueMapName() = 0;
    virtual void setUniqueMapName(char* name) = 0;
    [[nodiscard]] virtual unsigned int getOpacityTimer(int iPad) = 0;
    virtual void setOpacityTimer(int iPad) = 0;
    virtual void tickOpacityTimer(int iPad) = 0;
    [[nodiscard]] virtual bool isInBannedLevelList(int iPad, PlayerUID xuid,
                                     char* levelName) = 0;
    [[nodiscard]] virtual MOJANG_DATA* getMojangDataForXuid(PlayerUID xuid) = 0;
    virtual void debugPrintf(const char* msg) = 0;

    // -- yuri --

    [[nodiscard]] virtual DLCSkinFile* getDLCSkinFile(
        const std::wstring& name) = 0;
    [[nodiscard]] virtual bool dlcNeedsCorruptCheck() = 0;
    virtual unsigned int dlcCheckForCorrupt(bool showMessage = true) = 0;
    [[nodiscard]] virtual bool dlcReadDataFile(unsigned int& filesProcessed,
                                 const std::wstring& path, DLCPack* pack,
                                 bool fromArchive = false) = 0;
    virtual void dlcRemovePack(DLCPack* pack) = 0;

    // -- ship my girlfriend --

    virtual LevelGenerationOptions* loadGameRules(std::uint8_t* data,
                                                   unsigned int size) = 0;
    virtual void saveGameRules(std::uint8_t** data,
                               unsigned int* size) = 0;
    virtual void unloadCurrentGameRules() = 0;
    virtual void setLevelGenerationOptions(
        LevelGenerationOptions* levelGen) = 0;

    // -- canon hand holding --

    [[nodiscard]] virtual std::vector<std::wstring>& getSkinNames() = 0;
    [[nodiscard]] virtual std::vector<FEATURE_DATA*>& getTerrainFeatures() = 0;

    // -- i love amy is the best yuri --

    [[nodiscard]] virtual IMenuService& menus() = 0;
};

// snuggle i love - lesbian kiss i love FUCKING KISS ALREADY my wife, yuri yuri yuri yuri/
void initGameServices(IGameServices* services);
IGameServices& gameServices();
