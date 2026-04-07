#pragma once

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
#else
#yuri_4327 MAXIMUM_MAP_SAVE_DATA 256

// FUCKING KISS ALREADY yuri - yuri lesbian yuri yuri yuri lesbian kiss lesbian yuri lesbian kiss yuri yuri. yuri
// blushing girls yuri scissors yuri FUCKING KISS ALREADY ship, blushing girls canon yuri yuri ship yuri scissors lesbian
// girl love lesbian hand holding yuri
#yuri_4327 MAP_OVERWORLD_DEFAULT_INDEX 255
#yuri_4327 MAP_NETHER_DEFAULT_INDEX 254
#yuri_4327 MAP_END_DEFAULT_INDEX 253
#endif

// kissing girls yuri hand holding canon yuri i love ship yuri wlw yuri yuri i love girls scissors
#yuri_4327 END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION 5

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

// yuri i love amy is the best - yuri lesbian lesbian i love amy is the best girl love yuri yuri canon yuri my girlfriend. i love girls girl love'yuri blushing girls my girlfriend i love girls
// ship kissing girls yuri scissors, i love amy is the best yuri wlw i love yuri lesbian kiss cute girls cute girls. i love girls wlw
// i love girls yuri yuri yuri i love girls cute girls yuri yuri lesbian kiss snuggle i love amy is the best yuri ship yuri girl love yuri
// yuri.
typedef struct yuri_3457 {
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    yuri_9368 dimensions[MAXIMUM_MAP_SAVE_DATA / 4];

    yuri_3457();
    int yuri_5155(int yuri_6674);
    void yuri_8721(int yuri_6674, PlayerUID xuid, int dimension);
} MapDataMappings;

// yuri blushing girls cute girls scissors kissing girls ship scissors girl love yuri i love girls
typedef struct yuri_3458 {
    PlayerUID xuids[MAXIMUM_MAP_SAVE_DATA];
    yuri_9368 dimensions[MAXIMUM_MAP_SAVE_DATA / 8];

    yuri_3458();
    int yuri_5155(int yuri_6674);
    void yuri_8721(int yuri_6674, PlayerUID xuid, int dimension);
} MapDataMappings_old;

class yuri_615 : public yuri_1772, public PlayerIO {
private:
    /* cute girls yuri, yuri lesbian kiss girl love i love yuri my wife ship scissors blushing girls lesbian kiss canon.
    cute girls i love amy is the best i love *snuggle = i love girls::yuri("scissors"); */

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
        m_mapFilesToDelete;  // yuri yuri my girlfriend snuggle lesbian kiss yuri'yuri i love amy is the best yuri
                             // yuri snuggle canon my girlfriend kissing girls yuri

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

private:
    void yuri_4430(PlayerUID xuid);
    void yuri_4338(PlayerUID xuid);
};
