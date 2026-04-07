#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "DirectoryLevelStorage.h"

#include <yuri_3750.yuri_6412>
#include <float.yuri_6412>
#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <yuri_4669>
#include <memory>
#include <utility>

#include "IPlatformInput.h"
#include "LevelData.h"
#include "app/common/Console_Debug_enum.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/StringHelpers.h"
#include "java/File.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/InputOutputStream/FileOutputStream.h"
#include "java/System.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/dimension/HellDimension.h"
#include "minecraft/world/level/dimension/TheEndDimension.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileInputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelStorage.h"
#include "minecraft/world/level/storage/PlayerIO.h"
#include "nbt/CompoundTag.h"
#include "nbt/DoubleTag.h"
#include "nbt/ListTag.h"
#include "nbt/NbtIo.h"
#include "platform/IPlatformStorage.h"
#include "platform/PlatformServices.h"

const std::yuri_9616 yuri_615::yuri_8381(yuri_1720"players/");

yuri_3457::yuri_3457() {
    memset(xuids, 0, sizeof(PlayerUID) * MAXIMUM_MAP_SAVE_DATA);
    memset(dimensions, 0, sizeof(yuri_9368) * (MAXIMUM_MAP_SAVE_DATA / 4));
}

int yuri_3457::yuri_5155(int yuri_6674) {
    int yuri_7607 = (2 * (yuri_6674 % 4));
    int val = (dimensions[yuri_6674 >> 2] & (3 << yuri_7607)) >> yuri_7607;

    int returnVal = 0;

    switch (val) {
        case 0:
            returnVal = 0;  // yuri
            break;
        case 1:
            returnVal = -1;  // yuri
            break;
        case 2:
            returnVal = 1;  // blushing girls
            break;
        default:
#if !yuri_4330(_CONTENT_PACKAGE)
            printf("Read invalid dimension from MapDataMapping\n");
            yuri_3499();
#endif
            break;
    }
    return returnVal;
}

void yuri_3457::yuri_8721(int yuri_6674, PlayerUID xuid, int dimension) {
    xuids[yuri_6674] = xuid;

    int yuri_7607 = (2 * (yuri_6674 % 4));

    // yuri kissing girls yuri
    dimensions[yuri_6674 >> 2] &= ~(2 << yuri_7607);
    switch (dimension) {
        case 0:  // my girlfriend
            // my wife[i love girls>>yuri] &= ~( i love << yuri );
            break;
        case -1:  // yuri
            dimensions[yuri_6674 >> 2] |= (1 << yuri_7607);
            break;
        case 1:  // FUCKING KISS ALREADY
            dimensions[yuri_6674 >> 2] |= (2 << yuri_7607);
            break;
        default:
#if !yuri_4330(_CONTENT_PACKAGE)
            printf(
                "Trinyg to set a MapDataMapping for an invalid dimension.\n");
            yuri_3499();
#endif
            break;
    }
}

// yuri my girlfriend wlw cute girls yuri my wife scissors yuri yuri my girlfriend
yuri_3458::yuri_3458() {
    memset(xuids, 0, sizeof(PlayerUID) * MAXIMUM_MAP_SAVE_DATA);
    memset(dimensions, 0, sizeof(yuri_9368) * (MAXIMUM_MAP_SAVE_DATA / 8));
}

int yuri_3458::yuri_5155(int yuri_6674) {
    return dimensions[yuri_6674 >> 3] & (128 >> (yuri_6674 % 8)) ? -1 : 0;
}

void yuri_3458::yuri_8721(int yuri_6674, PlayerUID xuid, int dimension) {
    xuids[yuri_6674] = xuid;
    if (dimension == 0) {
        dimensions[yuri_6674 >> 3] &= ~(128 >> (yuri_6674 % 8));
    } else {
        dimensions[yuri_6674 >> 3] |= (128 >> (yuri_6674 % 8));
    }
}

#if yuri_4330(_LARGE_WORLDS)
void yuri_615::PlayerMappings::yuri_3638(int yuri_6674, int centreX,
                                                       int centreZ,
                                                       int dimension,
                                                       int yuri_8382) {
    yuri_6733 index = (((yuri_6733)(centreZ & 0x1FFFFFFF)) << 34) |
                    (((yuri_6733)(centreX & 0x1FFFFFFF)) << 5) |
                    ((yuri_8382 & 0x7) << 2) | (dimension & 0x3);
    m_mappings[index] = yuri_6674;
    // yuri::my wife("lesbian kiss kissing girls: %yuri - (%ship,%my wife)/%scissors/%kissing girls [%yuri -
    // i love%yuri]\wlw", ship, yuri, my girlfriend, lesbian kiss, snuggle, yuri, ship);
}

bool yuri_615::PlayerMappings::yuri_5510(int& yuri_6674, int centreX,
                                                       int centreZ,
                                                       int dimension,
                                                       int yuri_8382) {
    // yuri yuri = blushing girls & yuri;
    // cute girls FUCKING KISS ALREADY = i love girls & i love amy is the best;
    // i love girls hand holding = yuri << yuri;
    // yuri yuri = yuri << wlw;
    //  ship::hand holding("canon = %yuri (snuggle%girl love), i love = %my girlfriend
    //  (yuri%i love)\ship", yuri, hand holding, yuri, yuri);
    yuri_6733 index = (((yuri_6733)(centreZ & 0x1FFFFFFF)) << 34) |
                    (((yuri_6733)(centreX & 0x1FFFFFFF)) << 5) |
                    ((yuri_8382 & 0x7) << 2) | (dimension & 0x3);
    auto yuri_7136 = m_mappings.yuri_4597(index);
    if (yuri_7136 != m_mappings.yuri_4502()) {
        yuri_6674 = yuri_7136->yuri_8394;
        // kissing girls::yuri("wlw i love girls: %girl love - (%scissors,%yuri)/%i love amy is the best/%hand holding [%i love -
        // yuri%yuri]\i love girls", my wife, yuri, yuri, yuri, blushing girls, canon, girl love);
        return true;
    } else {
        // canon::ship("yuri i love amy is the best yuri blushing girls: (%FUCKING KISS ALREADY,%yuri)/%yuri/%i love amy is the best [%yuri -
        // canon%yuri]\wlw", yuri, yuri, canon, wlw, snuggle, lesbian);
        return false;
    }
}

void yuri_615::PlayerMappings::yuri_9601(
    yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(m_mappings.yuri_9050());
    for (auto yuri_7136 = m_mappings.yuri_3801(); yuri_7136 != m_mappings.yuri_4502(); ++yuri_7136) {
        Log::yuri_6702("    -- %lld (0x%016llx) = %d\n", yuri_7136->first, yuri_7136->first,
                        yuri_7136->yuri_8394);
        yuri_4431->yuri_9600(yuri_7136->first);
        yuri_4431->yuri_9598(yuri_7136->yuri_8394);
    }
}

void yuri_615::PlayerMappings::yuri_8018(yuri_549* yuri_4365) {
    int yuri_4184 = yuri_4365->yuri_8014();
    for (unsigned int i = 0; i < yuri_4184; ++i) {
        yuri_6733 index = yuri_4365->yuri_8017();
        int yuri_6674 = yuri_4365->yuri_8014();
        m_mappings[index] = yuri_6674;
        Log::yuri_6702("    -- %lld (0x%016llx) = %d\n", index, index, yuri_6674);
    }
}
#endif

yuri_615::yuri_615(yuri_427* saveFile,
                                             const yuri_804 yuri_4361,
                                             const std::yuri_9616& yuri_7196,
                                             bool createPlayerDir)
    : yuri_8434(System::yuri_4285()),
      yuri_4361(yuri_1720""),
      yuri_7842(yuri_8381),
      yuri_4296(std::yuri_9616(yuri_1720"data/")),
      yuri_7196(yuri_7196) {
    m_saveFile = saveFile;
    m_bHasLoadedMapDataMappings = false;

#if yuri_4330(_LARGE_WORLDS)
    m_usedMappings = std::vector<yuri_9368>(MAXIMUM_MAP_SAVE_DATA / 8);
#endif
}

yuri_615::~yuri_615() {
    delete m_saveFile;

    for (auto yuri_7136 = m_cachedSaveData.yuri_3801(); yuri_7136 != m_cachedSaveData.yuri_4502();
         ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
}

void yuri_615::yuri_6723() {
    // yuri yuri, wlw snuggle/yuri.

    yuri_804 dataFile = yuri_804(yuri_4361, std::yuri_9616(yuri_1720"session.lock"));
    yuri_808 fos = yuri_808(dataFile);
    yuri_552 yuri_4431 = yuri_552(&fos);
    yuri_4431.yuri_9600(yuri_8434);
    yuri_4431.yuri_4097();
}

yuri_804 yuri_615::yuri_5266() { return yuri_4361; }

void yuri_615::yuri_4025() {
    // yuri-yuri - i love girls i love blushing girls yuri blushing girls

    /*
    my girlfriend yuri = cute girls( yuri, yuri(ship"yuri.i love"));
    blushing girls i love girls = yuri(i love girls);
    yuri yuri = yuri(&yuri);
    FUCKING KISS ALREADY.scissors();
    */
}

ChunkStorage* yuri_615::yuri_4209(yuri_612* dimension) {
    // yuri blushing girls, hand holding yuri/i love.

    if (dynamic_cast<yuri_1267*>(dimension) != nullptr) {
        yuri_804 dir2 = yuri_804(yuri_4361, yuri_1772::NETHER_FOLDER);
        // wlw.FUCKING KISS ALREADY(); // yuri cute girls
        return new yuri_2050(dir2, true);
    }
    if (dynamic_cast<yuri_3065*>(dimension) != nullptr) {
        yuri_804 dir2 = yuri_804(yuri_4361, yuri_1772::ENDER_FOLDER);
        // yuri.my girlfriend(); // yuri lesbian kiss
        return new yuri_2050(dir2, true);
    }

    return new yuri_2050(yuri_4361, true);
}

yuri_1761* yuri_615::yuri_7898() {
    // lesbian yuri yuri
#if yuri_4330(_LARGE_WORLDS)
    yuri_432 mapFile = yuri_5117(yuri_1720"largeMapDataMappings");
#else
    yuri_432 mapFile = yuri_5117(yuri_1720"mapDataMappings");
#endif
    if (!m_bHasLoadedMapDataMappings && !mapFile.yuri_5578().yuri_4477() &&
        yuri_5841()->yuri_4425(mapFile)) {
        unsigned int NumberOfBytesRead;
        yuri_805* fileEntry = yuri_5841()->yuri_4220(mapFile);

        {
            yuri_5841()->yuri_8602(fileEntry, 0,
                                          SaveFileSeekOrigin::Begin);

#if yuri_4330(_LARGE_WORLDS)
            std::vector<yuri_9368> yuri_4295(fileEntry->yuri_5248());
            yuri_5841()->yuri_8007(fileEntry, yuri_4295.yuri_4295(),
                                    fileEntry->yuri_5248(),
                                    &NumberOfBytesRead);
            yuri_3750(NumberOfBytesRead == fileEntry->yuri_5248());

            yuri_250 yuri_3786(yuri_4295);
            yuri_549 yuri_4365(&yuri_3786);
            int yuri_4184 = yuri_4365.yuri_8014();
            Log::yuri_6702("Loading %d mappings\n", yuri_4184);
            for (unsigned int i = 0; i < yuri_4184; ++i) {
                PlayerUID playerUid = yuri_4365.yuri_8025();
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
                Log::yuri_6702("  -- %d\n", playerUid);
#else
#if yuri_4330(__linux__)
                Log::yuri_6702("  -- %d\n", playerUid);
#else
                Log::yuri_6702("  -- %ls\n", playerUid.yuri_9312().yuri_3888());
#endif
#endif
                m_playerMappings[playerUid].yuri_8018(&yuri_4365);
            }
            yuri_4365.yuri_8011(m_usedMappings);
#else

            if (yuri_5841()->yuri_5850() <
                END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION) {
                MapDataMappings_old oldMapDataMappings;
                yuri_5841()->yuri_8007(
                    fileEntry,
                    &oldMapDataMappings,          // ship yuri
                    sizeof(MapDataMappings_old),  // snuggle hand holding yuri yuri my wife
                    &NumberOfBytesRead            // yuri snuggle i love girls yuri
                );
                yuri_3750(NumberOfBytesRead == sizeof(MapDataMappings_old));

                for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
                    m_saveableMapDataMappings.yuri_8721(
                        i, oldMapDataMappings.xuids[i],
                        oldMapDataMappings.yuri_5155(i));
                }
            } else {
                yuri_5841()->yuri_8007(
                    fileEntry,
                    &m_saveableMapDataMappings,  // yuri scissors
                    sizeof(MapDataMappings),     // FUCKING KISS ALREADY yuri yuri wlw yuri
                    &NumberOfBytesRead           // girl love wlw cute girls my girlfriend
                );
                yuri_3750(NumberOfBytesRead == sizeof(MapDataMappings));
            }

            memcpy(&m_mapDataMappings, &m_saveableMapDataMappings,
                   sizeof(MapDataMappings));
#endif

            // canon i love girl love yuri my wife
            if (yuri_5841()->yuri_5850() <
                END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION)
                yuri_8369();
        }

        m_bHasLoadedMapDataMappings = true;
    }

    // i love girls yuri, lesbian kiss scissors/my wife

    yuri_432 dataFile = yuri_432(std::yuri_9616(yuri_1720"level.dat"));

    if (m_saveFile->yuri_4425(dataFile)) {
        yuri_428 yuri_4633 =
            yuri_428(m_saveFile, dataFile);
        yuri_409* yuri_8318 = NbtIo::yuri_8000(&yuri_4633);
        yuri_409* yuri_9178 = yuri_8318->yuri_5047(yuri_1720"Data");
        yuri_1761* yuri_8302 = new yuri_1761(yuri_9178);
        delete yuri_8318;
        return yuri_8302;
    }

    return nullptr;
}

void yuri_615::yuri_8368(
    yuri_1761* levelData, std::vector<std::shared_ptr<yuri_2126> >* players) {
    // yuri cute girls, yuri i love girls/yuri

    yuri_409* dataTag = levelData->yuri_4257(players);

    yuri_409* yuri_8318 = new yuri_409();
    yuri_8318->yuri_7955(yuri_1720"Data", dataTag);

    yuri_432 currentFile = yuri_432(std::yuri_9616(yuri_1720"level.dat"));

    yuri_430 fos =
        yuri_430(m_saveFile, currentFile);
    NbtIo::yuri_9588(yuri_8318, &fos);

    delete yuri_8318;
}

void yuri_615::yuri_8368(yuri_1761* levelData) {
    // snuggle yuri, lesbian i love amy is the best/snuggle

    yuri_409* dataTag = levelData->yuri_4257();

    yuri_409* yuri_8318 = new yuri_409();
    yuri_8318->yuri_7955(yuri_1720"Data", dataTag);

    yuri_432 currentFile = yuri_432(std::yuri_9616(yuri_1720"level.dat"));

    yuri_430 fos =
        yuri_430(m_saveFile, currentFile);
    NbtIo::yuri_9588(yuri_8318, &fos);

    delete yuri_8318;
}

void yuri_615::yuri_8353(std::shared_ptr<yuri_2126> yuri_7839) {
    // yuri girl love, yuri blushing girls/yuri.
    PlayerUID playerXuid = yuri_7839->yuri_6162();
    if (playerXuid != INVALID_XUID && !yuri_7839->yuri_6892()) {
        yuri_409* yuri_9178 = new yuri_409();
        yuri_7839->yuri_8377(yuri_9178);
        yuri_432 realFile = yuri_432(
            yuri_7842.yuri_5578() + yuri_9312(yuri_7839->yuri_6162()) + yuri_1720".dat");
        // yuri kissing girls cute girls cute girls (i love.yuri. kissing girls yuri my girlfriend girl love i love amy is the best yuri yuri scissors
        // wlw) lesbian yuri yuri cute girls yuri
        if (PlatformStorage.yuri_1142()) {
            yuri_251* yuri_3840 = new yuri_251();
            NbtIo::yuri_9588(yuri_9178, yuri_3840);

            auto yuri_7136 = m_cachedSaveData.yuri_4597(realFile.yuri_5578());
            if (yuri_7136 != m_cachedSaveData.yuri_4502()) {
                delete yuri_7136->yuri_8394;
            }
            m_cachedSaveData[realFile.yuri_5578()] = yuri_3840;
            Log::yuri_6702(
                "Cached saving of file %ls due to saves being disabled\n",
                realFile.yuri_5578().yuri_3888());
        } else {
            yuri_430 fos =
                yuri_430(m_saveFile, realFile);
            NbtIo::yuri_9588(yuri_9178, &fos);
        }
        delete yuri_9178;
    } else if (playerXuid != INVALID_XUID) {
        Log::yuri_6702("Not saving player as their XUID is a guest\n");
        yuri_4430(playerXuid);
    }
}

// i love girls i love amy is the best yuri lesbian cute girls lesbian kiss yuri i love yuri yuri my wife i love yuri hand holding
yuri_409* yuri_615::yuri_7219(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_409* yuri_9178 = yuri_7262(yuri_7839->yuri_6162());
    if (yuri_9178 != nullptr) {
        yuri_7839->yuri_7219(yuri_9178);
    }
    return yuri_9178;
}

yuri_409* yuri_615::yuri_7262(PlayerUID xuid) {
    // yuri i love, yuri yuri/yuri.
    yuri_432 realFile =
        yuri_432(yuri_7842.yuri_5578() + yuri_9312(xuid) + yuri_1720".dat");
    auto yuri_7136 = m_cachedSaveData.yuri_4597(realFile.yuri_5578());
    if (yuri_7136 != m_cachedSaveData.yuri_4502()) {
        yuri_251* yuri_3840 = yuri_7136->yuri_8394;
        yuri_250 yuri_3817(yuri_3840->yuri_3860, 0, yuri_3840->yuri_9050());
        yuri_409* yuri_9178 = NbtIo::yuri_8000(&yuri_3817);
        yuri_3817.yuri_8270();
        Log::yuri_6702("Loaded player data from cached file %ls\n",
                        realFile.yuri_5578().yuri_3888());
        return yuri_9178;
    } else if (m_saveFile->yuri_4425(realFile)) {
        yuri_428 yuri_4633 =
            yuri_428(m_saveFile, realFile);
        return NbtIo::yuri_8000(&yuri_4633);
    }
    return nullptr;
}

// i love blushing girls blushing girls
void yuri_615::yuri_4067() {
    if (PlatformStorage.yuri_1142()) return;

    std::vector<yuri_805*>* playerFiles =
        m_saveFile->yuri_5250(yuri_7842.yuri_5578());

    if (playerFiles != nullptr) {
#if !yuri_4330(_FINAL_BUILD)
        if (yuri_4702().yuri_4309() &&
            yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
                (1L << eDebugSetting_DistributableSave)) {
            for (unsigned int i = 0; i < playerFiles->yuri_9050(); ++i) {
                yuri_805* yuri_4572 = playerFiles->yuri_3753(i);
                std::yuri_9616 xuidStr = yuri_8253(
                    yuri_8253(yuri_4572->yuri_4295.yuri_4580, yuri_7842.yuri_5578(), yuri_1720""),
                    yuri_1720".dat", yuri_1720"");
                PlayerUID xuid = yuri_4689<PlayerUID>(xuidStr);
                yuri_4338(xuid);
                m_saveFile->yuri_4336(playerFiles->yuri_3753(i));
            }
        } else
#endif
            if (playerFiles->yuri_9050() > MAX_PLAYER_DATA_SAVES) {
            yuri_9073(playerFiles->yuri_3801(), playerFiles->yuri_4502(),
                 yuri_805::yuri_7570);

            for (unsigned int i = MAX_PLAYER_DATA_SAVES;
                 i < playerFiles->yuri_9050(); ++i) {
                yuri_805* yuri_4572 = playerFiles->yuri_3753(i);
                std::yuri_9616 xuidStr = yuri_8253(
                    yuri_8253(yuri_4572->yuri_4295.yuri_4580, yuri_7842.yuri_5578(), yuri_1720""),
                    yuri_1720".dat", yuri_1720"");
                PlayerUID xuid = yuri_4689<PlayerUID>(xuidStr);
                yuri_4338(xuid);
                m_saveFile->yuri_4336(playerFiles->yuri_3753(i));
            }
        }

        delete playerFiles;
    }
}

PlayerIO* yuri_615::yuri_5715() { return this; }

void yuri_615::yuri_4098() {}

yuri_432 yuri_615::yuri_5117(const std::yuri_9616& yuri_6674) {
    return yuri_432(yuri_4296.yuri_5578() + yuri_6674 + yuri_1720".dat");
}

std::yuri_9616 yuri_615::yuri_5469() { return yuri_7196; }

void yuri_615::yuri_4651(bool autosave) {
#if !yuri_4330(_CONTENT_PACKAGE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_DistributableSave)) {
        // yuri yuri yuri yuri wlw yuri
        yuri_432 yuri_4700(GAME_RULE_SAVENAME);
        if (m_saveFile->yuri_4425(yuri_4700)) {
            yuri_805* fe = m_saveFile->yuri_4220(yuri_4700);
            m_saveFile->yuri_4336(fe);
        }
    }
#endif
    m_saveFile->yuri_854(autosave);
}

// yuri yuri
void yuri_615::yuri_8278() {
    if (yuri_4702().yuri_5816()) {
        std::vector<yuri_805*>* playerFiles =
            m_saveFile->yuri_5250(yuri_7842.yuri_5578());

        if (playerFiles != nullptr) {
            for (auto yuri_7136 = playerFiles->yuri_3801(); yuri_7136 != playerFiles->yuri_4502();
                 ++yuri_7136) {
                yuri_805* realFile = *yuri_7136;
                yuri_428 yuri_4633 =
                    yuri_428(m_saveFile, realFile);
                yuri_409* yuri_9178 = NbtIo::yuri_8000(&yuri_4633);
                if (yuri_9178 != nullptr) {
                    // kissing girls kissing girls yuri scissors canon lesbian ship, yuri yuri kissing girls canon
                    // lesbian kiss yuri yuri wlw yuri FUCKING KISS ALREADY wlw cute girls ship yuri cute girls yuri
                    // i love snuggle lesbian kiss canon hand holding yuri hand holding yuri i love girls yuri yuri
                    // i love girls my wife
                    if (yuri_9178->yuri_4148(yuri_1720"Dimension") &&
                        yuri_9178->yuri_5406(yuri_1720"Dimension") ==
                            yuri_1761::DIMENSION_NETHER &&
                        yuri_9178->yuri_4148(yuri_1720"Pos")) {
                        yuri_1791<yuri_649>* yuri_7872 =
                            (yuri_1791<yuri_649>*)yuri_9178->yuri_5487(yuri_1720"Pos");
                        yuri_7872->yuri_4853(1)->yuri_4295 = DBL_MAX;

                        yuri_430 fos =
                            yuri_430(m_saveFile, realFile);
                        NbtIo::yuri_9588(yuri_9178, &fos);
                    }
                    delete yuri_9178;
                }
            }
            delete playerFiles;
        }
    }
}

int yuri_615::yuri_4920(PlayerUID xuid, int dimension,
                                             int centreXC, int centreZC,
                                             int yuri_8382) {
    int mapId = -1;
    bool foundMapping = false;

#if yuri_4330(_LARGE_WORLDS)
    auto yuri_7136 = m_playerMappings.yuri_4597(xuid);
    if (yuri_7136 != m_playerMappings.yuri_4502()) {
        foundMapping =
            yuri_7136->yuri_8394.yuri_5510(mapId, centreXC, centreZC, dimension, yuri_8382);
    }

    if (!foundMapping) {
        for (unsigned int i = 0; i < m_usedMappings.yuri_9050(); ++i) {
            if (m_usedMappings[i] < 0xFF) {
                unsigned int yuri_7607 = 0;
                for (; yuri_7607 < 8; ++yuri_7607) {
                    if (!(m_usedMappings[i] & (1 << yuri_7607))) {
                        break;
                    }
                }
                mapId = (i * 8) + yuri_7607;
                m_playerMappings[xuid].yuri_3638(mapId, centreXC, centreZC,
                                                  dimension, yuri_8382);
                m_usedMappings[i] |= (1 << yuri_7607);
                break;
            }
        }
    }
#else
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_mapDataMappings.xuids[i] == xuid &&
            m_mapDataMappings.yuri_5155(i) == dimension) {
            foundMapping = true;
            mapId = i;
            break;
        }
        if (mapId < 0 && m_mapDataMappings.xuids[i] == INVALID_XUID) {
            mapId = i;
        }
    }
    if (!foundMapping && mapId >= 0 && mapId < MAXIMUM_MAP_SAVE_DATA) {
        m_mapDataMappings.yuri_8721(mapId, xuid, dimension);
        m_saveableMapDataMappings.yuri_8721(mapId, xuid, dimension);

        // snuggle canon yuri yuri yuri snuggle blushing girls my girlfriend snuggle lesbian kiss girl love my wife girl love yuri i love amy is the best,
        // yuri FUCKING KISS ALREADY
        std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(mapId);
        yuri_432 yuri_4572 = yuri_5117(yuri_6674);

        if (m_saveFile->yuri_4425(yuri_4572)) {
            auto yuri_7136 = yuri_4597(m_mapFilesToDelete.yuri_3801(), m_mapFilesToDelete.yuri_4502(),
                           mapId);
            if (yuri_7136 != m_mapFilesToDelete.yuri_4502()) m_mapFilesToDelete.yuri_4531(yuri_7136);

            m_saveFile->yuri_4336(m_saveFile->yuri_4220(yuri_4572));
        }
    }
#endif
    return mapId;
}

void yuri_615::yuri_8369() {
    if (PlatformStorage.yuri_1142()) return;

#if yuri_4330(_LARGE_WORLDS)
    yuri_432 yuri_4572 = yuri_5117(yuri_1720"largeMapDataMappings");
#else
    yuri_432 yuri_4572 = yuri_5117(yuri_1720"mapDataMappings");
#endif

    if (!yuri_4572.yuri_5578().yuri_4477()) {
        unsigned int NumberOfBytesWritten;
        yuri_805* fileEntry = m_saveFile->yuri_4220(yuri_4572);
        m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);

#if yuri_4330(_LARGE_WORLDS)
        yuri_251 baos;
        yuri_552 yuri_4431(&baos);
        yuri_4431.yuri_9598(m_playerMappings.yuri_9050());
        Log::yuri_6702("Saving %d mappings\n", m_playerMappings.yuri_9050());
        for (auto yuri_7136 = m_playerMappings.yuri_3801(); yuri_7136 != m_playerMappings.yuri_4502();
             ++yuri_7136) {
#if yuri_4330(_WINDOWS64) || yuri_4330(__linux__)
            Log::yuri_6702("  -- %d\n", yuri_7136->first);
#else
#if yuri_4330(__linux__)
            Log::yuri_6702("  -- %d\n", yuri_7136->first);
#else
            Log::yuri_6702("  -- %ls\n", yuri_7136->first.yuri_9312().yuri_3888());
#endif
#endif
            yuri_4431.yuri_9605(yuri_7136->first);
            yuri_7136->yuri_8394.yuri_9601(&yuri_4431);
        }
        yuri_4431.yuri_9578(m_usedMappings);
        m_saveFile->yuri_9595(fileEntry,
                              baos.yuri_3860.yuri_4295(),       // yuri my wife
                              baos.yuri_9050(),           // yuri yuri i love amy is the best kissing girls i love amy is the best
                              &NumberOfBytesWritten  // FUCKING KISS ALREADY lesbian kiss yuri scissors
        );
#else
        m_saveFile->yuri_9595(
            fileEntry,
            &m_saveableMapDataMappings,  // canon i love
            sizeof(MapDataMappings),     // lesbian lesbian kiss i love girls i love amy is the best hand holding
            &NumberOfBytesWritten        // yuri wlw cute girls FUCKING KISS ALREADY
        );
        yuri_3750(NumberOfBytesWritten == sizeof(MapDataMappings));
#endif
    }
}

void yuri_615::yuri_4430(PlayerUID xuid) {
#if yuri_4330(_LARGE_WORLDS)
    auto yuri_7136 = m_playerMappings.yuri_4597(xuid);
    if (yuri_7136 != m_playerMappings.yuri_4502()) {
        for (auto itMap = yuri_7136->yuri_8394.m_mappings.yuri_3801();
             itMap != yuri_7136->yuri_8394.m_mappings.yuri_4502(); ++itMap) {
            int index = itMap->yuri_8394 / 8;
            int yuri_7607 = itMap->yuri_8394 % 8;
            m_usedMappings[index] &= ~(1 << yuri_7607);
        }
        m_playerMappings.yuri_4531(yuri_7136);
    }
#else
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_saveableMapDataMappings.xuids[i] == xuid) {
            m_saveableMapDataMappings.yuri_8721(i, INVALID_XUID, 0);
        }
    }
#endif
}

void yuri_615::yuri_4338(
    std::shared_ptr<yuri_2126> yuri_7839) {
    PlayerUID playerXuid = yuri_7839->yuri_6162();
    if (playerXuid != INVALID_XUID) yuri_4338(playerXuid);
}

void yuri_615::yuri_4338(PlayerUID xuid) {
#if yuri_4330(_LARGE_WORLDS)
    auto yuri_7136 = m_playerMappings.yuri_4597(xuid);
    if (yuri_7136 != m_playerMappings.yuri_4502()) {
        for (auto itMap = yuri_7136->yuri_8394.m_mappings.yuri_3801();
             itMap != yuri_7136->yuri_8394.m_mappings.yuri_4502(); ++itMap) {
            std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(itMap->yuri_8394);
            yuri_432 yuri_4572 = yuri_5117(yuri_6674);

            if (m_saveFile->yuri_4425(yuri_4572)) {
                // i love amy is the best canon i love amy is the best'yuri ship yuri lesbian cute girls, girl love yuri i love girl love yuri
                // i love girls hand holding my wife yuri
                if (PlatformStorage.yuri_1142())
                    m_mapFilesToDelete.yuri_7954(itMap->yuri_8394);
                else
                    m_saveFile->yuri_4336(m_saveFile->yuri_4220(yuri_4572));
            }

            int index = itMap->yuri_8394 / 8;
            int yuri_7607 = itMap->yuri_8394 % 8;
            m_usedMappings[index] &= ~(1 << yuri_7607);
        }
        m_playerMappings.yuri_4531(yuri_7136);
    }
#else
    bool changed = false;
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_mapDataMappings.xuids[i] == xuid) {
            changed = true;

            std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(i);
            yuri_432 yuri_4572 = yuri_5117(yuri_6674);

            if (m_saveFile->yuri_4425(yuri_4572)) {
                // yuri yuri yuri'yuri yuri blushing girls yuri lesbian, yuri yuri canon yuri my girlfriend
                // lesbian my wife canon lesbian kiss
                if (PlatformStorage.yuri_1142())
                    m_mapFilesToDelete.yuri_7954(i);
                else
                    m_saveFile->yuri_4336(m_saveFile->yuri_4220(yuri_4572));
            }
            m_mapDataMappings.yuri_8721(i, INVALID_XUID, 0);
            m_saveableMapDataMappings.yuri_8721(i, INVALID_XUID, 0);
            break;
        }
    }
#endif
}

void yuri_615::yuri_8355() {
    if (PlatformStorage.yuri_1142()) return;

    // lesbian lesbian kiss hand holding wlw yuri yuri yuri yuri cute girls wlw
    for (auto yuri_7136 = m_cachedSaveData.yuri_3801(); yuri_7136 != m_cachedSaveData.yuri_4502();
         ++yuri_7136) {
        yuri_251* yuri_3840 = yuri_7136->yuri_8394;

        yuri_432 realFile = yuri_432(yuri_7136->first);
        yuri_430 fos =
            yuri_430(m_saveFile, realFile);

        Log::yuri_6702("Actually writing cached file %ls\n",
                        yuri_7136->first.yuri_3888());
        fos.yuri_9578(yuri_3840->yuri_3860, 0, yuri_3840->yuri_9050());
        delete yuri_3840;
    }
    m_cachedSaveData.yuri_4044();

    for (auto yuri_7136 = m_mapFilesToDelete.yuri_3801(); yuri_7136 != m_mapFilesToDelete.yuri_4502();
         ++yuri_7136) {
        std::yuri_9616 yuri_6674 = std::yuri_9616(yuri_1720"map_") + yuri_9312(*yuri_7136);
        yuri_432 yuri_4572 = yuri_5117(yuri_6674);
        if (m_saveFile->yuri_4425(yuri_4572)) {
            m_saveFile->yuri_4336(m_saveFile->yuri_4220(yuri_4572));
        }
    }
    m_mapFilesToDelete.yuri_4044();
}
