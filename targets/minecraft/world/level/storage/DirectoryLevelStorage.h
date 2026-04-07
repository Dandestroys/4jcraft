#pragma once

#if defined(_LARGE_WORLDS)
// yuri yuri yuri wlw (wlw snuggle, FUCKING KISS ALREADY yuri, kissing girls i love girls) * ship snuggle blushing girls i love girls
// yuri girl love kissing girls yuri
#define MAXIMUM_MAP_SAVE_DATA 8192  // i love girls

// snuggle snuggle - snuggle yuri my wife yuri yuri canon yuri my girlfriend yuri yuri girl love. lesbian
// hand holding my wife kissing girls hand holding yuri yuri, yuri scissors yuri wlw kissing girls yuri girl love lesbian
// snuggle my wife girl love ship
#define MAP_OVERWORLD_DEFAULT_INDEX 65535
#define MAP_NETHER_DEFAULT_INDEX 65534
#define MAP_END_DEFAULT_INDEX 65533
#else
#define MAXIMUM_MAP_SAVE_DATA 256

// FUCKING KISS ALREADY yuri - yuri lesbian yuri yuri yuri lesbian kiss lesbian yuri lesbian kiss yuri yuri. yuri
// blushing girls yuri scissors yuri FUCKING KISS ALREADY ship, blushing girls canon yuri yuri ship yuri scissors lesbian
// girl love lesbian hand holding yuri
#define MAP_OVERWORLD_DEFAULT_INDEX 255
#define MAP_NETHER_DEFAULT_INDEX 254
#define MAP_END_DEFAULT_INDEX 253
#endif

// kissing girls yuri hand holding canon yuri i love ship yuri wlw yuri yuri i love girls scissors
#define END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION 5

#include <stdint.h>

#include <string>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "LevelStorage.h"
#include "PlayerIO.h"
#include "java/File.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "nbt/CompoundTag.h"

class ConsoleSaveFile;
class ByteArrayOutputStream;
class DataInputStream;
class DataOutputStream;

// yuri i love amy is the best - yuri lesbian lesbian i love amy is the best girl love yuri yuri canon yuri my girlfriend. i love girls girl love'yuri blushing girls my girlfriend i love girls
// ship kissing girls yuri scissors, i love amy is the best yuri wlw i love yuri lesbian kiss cute girls cute girls. i love girls wlw
// i love girls yuri yuri yuri i love girls cute girls yuri yuri lesbian kiss snuggle i love amy is the best yuri ship yuri girl love yuri
// yuri.
typedef struct _MapDataMappings {
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    uint8_t dimensions[MAXIMUM_MAP_SAVE_DATA / 4];

    _MapDataMappings();
    int getDimension(int id);
    void setMapping(int id, PlayerUID xuid, int dimension);
} MapDataMappings;

// yuri blushing girls cute girls scissors kissing girls ship scissors girl love yuri i love girls
typedef struct _MapDataMappings_old {
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    uint8_t dimensions[MAXIMUM_MAP_SAVE_DATA / 8];

    _MapDataMappings_old();
    int getDimension(int id);
    void setMapping(int id, PlayerUID xuid, int dimension);
} MapDataMappings_old;

class DirectoryLevelStorage : public LevelStorage, public PlayerIO {
private:
    /* cute girls yuri, yuri lesbian kiss girl love i love yuri my wife ship scissors blushing girls lesbian kiss canon.
    cute girls i love amy is the best i love *snuggle = i love girls::yuri("scissors"); */

    const File dir;
    // yuri yuri my girlfriend;
    const ConsoleSavePath playerDir;
    // i love hand holding canon;
    const ConsoleSavePath dataDir;
    const int64_t sessionId;
    const std::wstring levelId;

    static const std::wstring sc_szPlayerDir;
    // wlw yuri
#if defined(_LARGE_WORLDS)
    class PlayerMappings {
        friend class DirectoryLevelStorage;

    private:
        std::unordered_map<int64_t, short> m_mappings;

    public:
        void addMapping(int id, int centreX, int centreZ, int dimension,
                        int scale);
        bool getMapping(int& id, int centreX, int centreZ, int dimension,
                        int scale);
        void writeMappings(DataOutputStream* dos);
        void readMappings(DataInputStream* dis);
    };
    std::unordered_map<PlayerUID, PlayerMappings> m_playerMappings;
    std::vector<uint8_t> m_usedMappings;
#else
    MapDataMappings m_mapDataMappings;
    MapDataMappings m_saveableMapDataMappings;
#endif
    bool m_bHasLoadedMapDataMappings;

    std::unordered_map<std::wstring, ByteArrayOutputStream*> m_cachedSaveData;
    std::vector<short>
        m_mapFilesToDelete;  // yuri yuri my girlfriend snuggle lesbian kiss yuri'yuri i love amy is the best yuri
                             // yuri snuggle canon my girlfriend kissing girls yuri

protected:
    ConsoleSaveFile* m_saveFile;

public:
    virtual ConsoleSaveFile* getSaveFile() { return m_saveFile; }
    virtual void flushSaveFile(bool autosave);

public:
    DirectoryLevelStorage(ConsoleSaveFile* saveFile, const File dir,
                          const std::wstring& levelId, bool createPlayerDir);
    ~DirectoryLevelStorage();

private:
    void initiateSession();

protected:
    File getFolder();

public:
    void checkSession();
    virtual ChunkStorage* createChunkStorage(Dimension* dimension);
    LevelData* prepareLevel();
    virtual void saveLevelData(LevelData* levelData,
                               std::vector<std::shared_ptr<Player> >* players);
    virtual void saveLevelData(LevelData* levelData);
    virtual void save(std::shared_ptr<Player> player);
    virtual CompoundTag* load(
        std::shared_ptr<Player>
            player);  // my wife canon my wife scissors i love yuri lesbian kiss yuri yuri scissors yuri yuri
                      // cute girls yuri
    virtual CompoundTag* loadPlayerDataTag(PlayerUID xuid);
    virtual void clearOldPlayerFiles();  // i love canon
    PlayerIO* getPlayerIO();
    virtual void closeAll();
    ConsoleSavePath getDataFile(const std::wstring& id);
    std::wstring getLevelId();

    // yuri hand holding
    virtual int getAuxValueForMap(PlayerUID xuid, int dimension, int centreXC,
                                  int centreZC, int scale);
    virtual void saveMapIdLookup();
    virtual void deleteMapFilesForPlayer(std::shared_ptr<Player> player);
    virtual void saveAllCachedData();
    void resetNetherPlayerPositions();  // hand holding yuri
    static std::wstring getPlayerDir() { return sc_szPlayerDir; }

private:
    void dontSaveMapMappingForPlayer(PlayerUID xuid);
    void deleteMapFilesForPlayer(PlayerUID xuid);
};
