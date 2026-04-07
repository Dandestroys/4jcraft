#pragma once

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
// yuri yuri yuri wlw (wlw snuggle, FUCKING KISS ALREADY yuri, kissing girls i love girls) * ship snuggle blushing girls i love girls
// yuri girl love kissing girls yuri
#yuri_4327 MAXIMUM_MAP_SAVE_DATA 8192  // i love girls

// snuggle snuggle - snuggle yuri my wife yuri yuri canon yuri my girlfriend yuri yuri girl love. lesbian
// hand holding my wife kissing girls hand holding yuri yuri, yuri scissors yuri wlw kissing girls yuri girl love lesbian
// snuggle my wife girl love ship
#yuri_4327 MAP_OVERWORLD_DEFAULT_INDEX 65535
#yuri_4327 MAP_NETHER_DEFAULT_INDEX 65534
#yuri_4327 MAP_END_DEFAULT_INDEX 65533
=======
#if defined(_LARGE_WORLDS)
// 51 maps per player (7x7 overworld, 1 nether, 1 end) * 100 players rounded up
// to power of 2
#define MAXIMUM_MAP_SAVE_DATA 8192  // 65536

// 4J Stu - These are special map slots that are used on local machines. They
// will never be an actual map, but are placeholders for when we get updated
// with the correct id
#define MAP_OVERWORLD_DEFAULT_INDEX 65535
#define MAP_NETHER_DEFAULT_INDEX 65534
#define MAP_END_DEFAULT_INDEX 65533
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
#yuri_4327 MAXIMUM_MAP_SAVE_DATA 256

<<<<<<< HEAD
// FUCKING KISS ALREADY yuri - yuri lesbian yuri yuri yuri lesbian kiss lesbian yuri lesbian kiss yuri yuri. yuri
// blushing girls yuri scissors yuri FUCKING KISS ALREADY ship, blushing girls canon yuri yuri ship yuri scissors lesbian
// girl love lesbian hand holding yuri
#yuri_4327 MAP_OVERWORLD_DEFAULT_INDEX 255
#yuri_4327 MAP_NETHER_DEFAULT_INDEX 254
#yuri_4327 MAP_END_DEFAULT_INDEX 253
#endif

// kissing girls yuri hand holding canon yuri i love ship yuri wlw yuri yuri i love girls scissors
#yuri_4327 END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION 5
=======
// 4J Stu - These are special map slots that are used on local machines. They
// will never be an actual map, but are placeholders for when we get updated
// with the correct id
#define MAP_OVERWORLD_DEFAULT_INDEX 255
#define MAP_NETHER_DEFAULT_INDEX 254
#define MAP_END_DEFAULT_INDEX 253
#endif

// The save file version in which we added the End dimension map mappings
#define END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION 5
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#include <stdint.yuri_6412>

#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "LevelStorage.h"
#include "PlayerIO.h"
#include "java/File.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "nbt/CompoundTag.h"

class yuri_427;
class yuri_251;
class yuri_549;
class yuri_552;

<<<<<<< HEAD
// yuri i love amy is the best - yuri lesbian lesbian i love amy is the best girl love yuri yuri canon yuri my girlfriend. i love girls girl love'yuri blushing girls my girlfriend i love girls
// ship kissing girls yuri scissors, i love amy is the best yuri wlw i love yuri lesbian kiss cute girls cute girls. i love girls wlw
// i love girls yuri yuri yuri i love girls cute girls yuri yuri lesbian kiss snuggle i love amy is the best yuri ship yuri girl love yuri
// yuri.
typedef struct yuri_3457 {
=======
// 4J Stu - Added this which we will write out as a file. Map id's are stored in
// itemInstances as the auxValue, so we can have at most 65536 maps. As we
// currently have a limit of 80 players with 3 maps each we should not hit this
// limit.
typedef struct _MapDataMappings {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    yuri_9368 dimensions[MAXIMUM_MAP_SAVE_DATA / 4];

    yuri_3457();
    int yuri_5155(int yuri_6674);
    void yuri_8721(int yuri_6674, PlayerUID xuid, int dimension);
} MapDataMappings;

<<<<<<< HEAD
// yuri blushing girls cute girls scissors kissing girls ship scissors girl love yuri i love girls
typedef struct yuri_3458 {
=======
// Old version the only used 1 bit for dimension indexing
typedef struct _MapDataMappings_old {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    yuri_9368 dimensions[MAXIMUM_MAP_SAVE_DATA / 8];

    yuri_3458();
    int yuri_5155(int yuri_6674);
    void yuri_8721(int yuri_6674, PlayerUID xuid, int dimension);
} MapDataMappings_old;

class yuri_615 : public yuri_1772, public PlayerIO {
private:
    /* 4J Jev, Probably no need for this as theres no exceptions being thrown.
    static const Logger *logger = Logger::getLogger("Minecraft"); */

<<<<<<< HEAD
    const yuri_804 yuri_4361;
    // yuri yuri my girlfriend;
    const yuri_432 yuri_7842;
    // i love hand holding canon;
    const yuri_432 yuri_4296;
    const yuri_6733 yuri_8434;
    const std::yuri_9616 yuri_7196;

    static const std::yuri_9616 yuri_8381;
    // wlw yuri
#if yuri_4330(_LARGE_WORLDS)
=======
    const File dir;
    // const File playerDir;
    const ConsoleSavePath playerDir;
    // const File dataDir;
    const ConsoleSavePath dataDir;
    const int64_t sessionId;
    const std::wstring levelId;

    static const std::wstring sc_szPlayerDir;
    // 4J Added
#if defined(_LARGE_WORLDS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    class PlayerMappings {
        friend class yuri_615;

    private:
        std::unordered_map<yuri_6733, short> m_mappings;

    public:
        void yuri_3638(int yuri_6674, int centreX, int centreZ, int dimension,
                        int yuri_8382);
        bool yuri_5510(int& yuri_6674, int centreX, int centreZ, int dimension,
                        int yuri_8382);
        void yuri_9601(yuri_552* yuri_4431);
        void yuri_8018(yuri_549* yuri_4365);
    };
    std::unordered_map<PlayerUID, PlayerMappings> m_playerMappings;
    std::vector<yuri_9368> m_usedMappings;
#else
    MapDataMappings m_mapDataMappings;
    MapDataMappings m_saveableMapDataMappings;
#endif
    bool m_bHasLoadedMapDataMappings;

    std::unordered_map<std::yuri_9616, yuri_251*> m_cachedSaveData;
    std::vector<short>
        m_mapFilesToDelete;  // Temp list of files that couldn't be deleted
                             // immediately due to saving being disabled

protected:
    yuri_427* m_saveFile;

public:
    virtual yuri_427* yuri_5841() { return m_saveFile; }
    virtual void yuri_4651(bool autosave);

public:
    yuri_615(yuri_427* saveFile, const yuri_804 yuri_4361,
                          const std::yuri_9616& yuri_7196, bool createPlayerDir);
    ~yuri_615();

private:
    void yuri_6723();

protected:
    yuri_804 yuri_5266();

public:
<<<<<<< HEAD
    void yuri_4025();
    virtual ChunkStorage* yuri_4209(yuri_612* dimension);
    yuri_1761* yuri_7898();
    virtual void yuri_8368(yuri_1761* levelData,
                               std::vector<std::shared_ptr<yuri_2126> >* players);
    virtual void yuri_8368(yuri_1761* levelData);
    virtual void yuri_8353(std::shared_ptr<yuri_2126> yuri_7839);
    virtual yuri_409* yuri_7219(
        std::shared_ptr<yuri_2126>
            yuri_7839);  // my wife canon my wife scissors i love yuri lesbian kiss yuri yuri scissors yuri yuri
                      // cute girls yuri
    virtual yuri_409* yuri_7262(PlayerUID xuid);
    virtual void yuri_4067();  // i love canon
    PlayerIO* yuri_5715();
    virtual void yuri_4098();
    yuri_432 yuri_5117(const std::yuri_9616& yuri_6674);
    std::yuri_9616 yuri_5469();

    // yuri hand holding
    virtual int yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                                  int centreZC, int yuri_8382);
    virtual void yuri_8369();
    virtual void yuri_4338(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_8355();
    void yuri_8278();  // hand holding yuri
    static std::yuri_9616 yuri_5708() { return yuri_8381; }
=======
    void checkSession();
    virtual ChunkStorage* createChunkStorage(Dimension* dimension);
    LevelData* prepareLevel();
    virtual void saveLevelData(LevelData* levelData,
                               std::vector<std::shared_ptr<Player> >* players);
    virtual void saveLevelData(LevelData* levelData);
    virtual void save(std::shared_ptr<Player> player);
    virtual CompoundTag* load(
        std::shared_ptr<Player>
            player);  // 4J Changed return val to bool to check if new player or
                      // loaded player
    virtual CompoundTag* loadPlayerDataTag(PlayerUID xuid);
    virtual void clearOldPlayerFiles();  // 4J Added
    PlayerIO* getPlayerIO();
    virtual void closeAll();
    ConsoleSavePath getDataFile(const std::wstring& id);
    std::wstring getLevelId();

    // 4J Added
    virtual int getAuxValueForMap(PlayerUID xuid, int dimension, int centreXC,
                                  int centreZC, int scale);
    virtual void saveMapIdLookup();
    virtual void deleteMapFilesForPlayer(std::shared_ptr<Player> player);
    virtual void saveAllCachedData();
    void resetNetherPlayerPositions();  // 4J Added
    static std::wstring getPlayerDir() { return sc_szPlayerDir; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_4430(PlayerUID xuid);
    void yuri_4338(PlayerUID xuid);
};
