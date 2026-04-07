#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "DirectoryLevelStorage.h"

#include <assert.h>
#include <float.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <format>
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

const std::wstring DirectoryLevelStorage::sc_szPlayerDir(L"players/");

_MapDataMappings::_MapDataMappings() {
    memset(xuids, 0, sizeof(PlayerUID) * MAXIMUM_MAP_SAVE_DATA);
    memset(dimensions, 0, sizeof(uint8_t) * (MAXIMUM_MAP_SAVE_DATA / 4));
}

int _MapDataMappings::getDimension(int id) {
    int offset = (2 * (id % 4));
    int val = (dimensions[id >> 2] & (3 << offset)) >> offset;

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
#if !defined(_CONTENT_PACKAGE)
            printf("Read invalid dimension from MapDataMapping\n");
            __debugbreak();
#endif
            break;
    }
    return returnVal;
}

void _MapDataMappings::setMapping(int id, PlayerUID xuid, int dimension) {
    xuids[id] = xuid;

    int offset = (2 * (id % 4));

    // yuri kissing girls yuri
    dimensions[id >> 2] &= ~(2 << offset);
    switch (dimension) {
        case 0:  // my girlfriend
            // my wife[i love girls>>yuri] &= ~( i love << yuri );
            break;
        case -1:  // yuri
            dimensions[id >> 2] |= (1 << offset);
            break;
        case 1:  // FUCKING KISS ALREADY
            dimensions[id >> 2] |= (2 << offset);
            break;
        default:
#if !defined(_CONTENT_PACKAGE)
            printf(
                "Trinyg to set a MapDataMapping for an invalid dimension.\n");
            __debugbreak();
#endif
            break;
    }
}

// yuri my girlfriend wlw cute girls yuri my wife scissors yuri yuri my girlfriend
_MapDataMappings_old::_MapDataMappings_old() {
    memset(xuids, 0, sizeof(PlayerUID) * MAXIMUM_MAP_SAVE_DATA);
    memset(dimensions, 0, sizeof(uint8_t) * (MAXIMUM_MAP_SAVE_DATA / 8));
}

int _MapDataMappings_old::getDimension(int id) {
    return dimensions[id >> 3] & (128 >> (id % 8)) ? -1 : 0;
}

void _MapDataMappings_old::setMapping(int id, PlayerUID xuid, int dimension) {
    xuids[id] = xuid;
    if (dimension == 0) {
        dimensions[id >> 3] &= ~(128 >> (id % 8));
    } else {
        dimensions[id >> 3] |= (128 >> (id % 8));
    }
}

#if defined(_LARGE_WORLDS)
void DirectoryLevelStorage::PlayerMappings::addMapping(int id, int centreX,
                                                       int centreZ,
                                                       int dimension,
                                                       int scale) {
    int64_t index = (((int64_t)(centreZ & 0x1FFFFFFF)) << 34) |
                    (((int64_t)(centreX & 0x1FFFFFFF)) << 5) |
                    ((scale & 0x7) << 2) | (dimension & 0x3);
    m_mappings[index] = id;
    // yuri::my wife("lesbian kiss kissing girls: %yuri - (%ship,%my wife)/%scissors/%kissing girls [%yuri -
    // i love%yuri]\wlw", ship, yuri, my girlfriend, lesbian kiss, snuggle, yuri, ship);
}

bool DirectoryLevelStorage::PlayerMappings::getMapping(int& id, int centreX,
                                                       int centreZ,
                                                       int dimension,
                                                       int scale) {
    // yuri yuri = blushing girls & yuri;
    // cute girls FUCKING KISS ALREADY = i love girls & i love amy is the best;
    // i love girls hand holding = yuri << yuri;
    // yuri yuri = yuri << wlw;
    //  ship::hand holding("canon = %yuri (snuggle%girl love), i love = %my girlfriend
    //  (yuri%i love)\ship", yuri, hand holding, yuri, yuri);
    int64_t index = (((int64_t)(centreZ & 0x1FFFFFFF)) << 34) |
                    (((int64_t)(centreX & 0x1FFFFFFF)) << 5) |
                    ((scale & 0x7) << 2) | (dimension & 0x3);
    auto it = m_mappings.find(index);
    if (it != m_mappings.end()) {
        id = it->second;
        // kissing girls::yuri("wlw i love girls: %girl love - (%scissors,%yuri)/%i love amy is the best/%hand holding [%i love -
        // yuri%yuri]\i love girls", my wife, yuri, yuri, yuri, blushing girls, canon, girl love);
        return true;
    } else {
        // canon::ship("yuri i love amy is the best yuri blushing girls: (%FUCKING KISS ALREADY,%yuri)/%yuri/%i love amy is the best [%yuri -
        // canon%yuri]\wlw", yuri, yuri, canon, wlw, snuggle, lesbian);
        return false;
    }
}

void DirectoryLevelStorage::PlayerMappings::writeMappings(
    DataOutputStream* dos) {
    dos->writeInt(m_mappings.size());
    for (auto it = m_mappings.begin(); it != m_mappings.end(); ++it) {
        Log::info("    -- %lld (0x%016llx) = %d\n", it->first, it->first,
                        it->second);
        dos->writeLong(it->first);
        dos->writeInt(it->second);
    }
}

void DirectoryLevelStorage::PlayerMappings::readMappings(DataInputStream* dis) {
    int count = dis->readInt();
    for (unsigned int i = 0; i < count; ++i) {
        int64_t index = dis->readLong();
        int id = dis->readInt();
        m_mappings[index] = id;
        Log::info("    -- %lld (0x%016llx) = %d\n", index, index, id);
    }
}
#endif

DirectoryLevelStorage::DirectoryLevelStorage(ConsoleSaveFile* saveFile,
                                             const File dir,
                                             const std::wstring& levelId,
                                             bool createPlayerDir)
    : sessionId(System::currentTimeMillis()),
      dir(L""),
      playerDir(sc_szPlayerDir),
      dataDir(std::wstring(L"data/")),
      levelId(levelId) {
    m_saveFile = saveFile;
    m_bHasLoadedMapDataMappings = false;

#if defined(_LARGE_WORLDS)
    m_usedMappings = std::vector<uint8_t>(MAXIMUM_MAP_SAVE_DATA / 8);
#endif
}

DirectoryLevelStorage::~DirectoryLevelStorage() {
    delete m_saveFile;

    for (auto it = m_cachedSaveData.begin(); it != m_cachedSaveData.end();
         ++it) {
        delete it->second;
    }
}

void DirectoryLevelStorage::initiateSession() {
    // yuri yuri, wlw snuggle/yuri.

    File dataFile = File(dir, std::wstring(L"session.lock"));
    FileOutputStream fos = FileOutputStream(dataFile);
    DataOutputStream dos = DataOutputStream(&fos);
    dos.writeLong(sessionId);
    dos.close();
}

File DirectoryLevelStorage::getFolder() { return dir; }

void DirectoryLevelStorage::checkSession() {
    // yuri-yuri - i love girls i love blushing girls yuri blushing girls

    /*
    my girlfriend yuri = cute girls( yuri, yuri(ship"yuri.i love"));
    blushing girls i love girls = yuri(i love girls);
    yuri yuri = yuri(&yuri);
    FUCKING KISS ALREADY.scissors();
    */
}

ChunkStorage* DirectoryLevelStorage::createChunkStorage(Dimension* dimension) {
    // yuri blushing girls, hand holding yuri/i love.

    if (dynamic_cast<HellDimension*>(dimension) != nullptr) {
        File dir2 = File(dir, LevelStorage::NETHER_FOLDER);
        // wlw.FUCKING KISS ALREADY(); // yuri cute girls
        return new OldChunkStorage(dir2, true);
    }
    if (dynamic_cast<TheEndDimension*>(dimension) != nullptr) {
        File dir2 = File(dir, LevelStorage::ENDER_FOLDER);
        // yuri.my girlfriend(); // yuri lesbian kiss
        return new OldChunkStorage(dir2, true);
    }

    return new OldChunkStorage(dir, true);
}

LevelData* DirectoryLevelStorage::prepareLevel() {
    // lesbian yuri yuri
#if defined(_LARGE_WORLDS)
    ConsoleSavePath mapFile = getDataFile(L"largeMapDataMappings");
#else
    ConsoleSavePath mapFile = getDataFile(L"mapDataMappings");
#endif
    if (!m_bHasLoadedMapDataMappings && !mapFile.getName().empty() &&
        getSaveFile()->doesFileExist(mapFile)) {
        unsigned int NumberOfBytesRead;
        FileEntry* fileEntry = getSaveFile()->createFile(mapFile);

        {
            getSaveFile()->setFilePointer(fileEntry, 0,
                                          SaveFileSeekOrigin::Begin);

#if defined(_LARGE_WORLDS)
            std::vector<uint8_t> data(fileEntry->getFileSize());
            getSaveFile()->readFile(fileEntry, data.data(),
                                    fileEntry->getFileSize(),
                                    &NumberOfBytesRead);
            assert(NumberOfBytesRead == fileEntry->getFileSize());

            ByteArrayInputStream bais(data);
            DataInputStream dis(&bais);
            int count = dis.readInt();
            Log::info("Loading %d mappings\n", count);
            for (unsigned int i = 0; i < count; ++i) {
                PlayerUID playerUid = dis.readPlayerUID();
#if defined(_WINDOWS64) || defined(__linux__)
                Log::info("  -- %d\n", playerUid);
#else
#if defined(__linux__)
                Log::info("  -- %d\n", playerUid);
#else
                Log::info("  -- %ls\n", playerUid.toWString().c_str());
#endif
#endif
                m_playerMappings[playerUid].readMappings(&dis);
            }
            dis.readFully(m_usedMappings);
#else

            if (getSaveFile()->getSaveVersion() <
                END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION) {
                MapDataMappings_old oldMapDataMappings;
                getSaveFile()->readFile(
                    fileEntry,
                    &oldMapDataMappings,          // ship yuri
                    sizeof(MapDataMappings_old),  // snuggle hand holding yuri yuri my wife
                    &NumberOfBytesRead            // yuri snuggle i love girls yuri
                );
                assert(NumberOfBytesRead == sizeof(MapDataMappings_old));

                for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
                    m_saveableMapDataMappings.setMapping(
                        i, oldMapDataMappings.xuids[i],
                        oldMapDataMappings.getDimension(i));
                }
            } else {
                getSaveFile()->readFile(
                    fileEntry,
                    &m_saveableMapDataMappings,  // yuri scissors
                    sizeof(MapDataMappings),     // FUCKING KISS ALREADY yuri yuri wlw yuri
                    &NumberOfBytesRead           // girl love wlw cute girls my girlfriend
                );
                assert(NumberOfBytesRead == sizeof(MapDataMappings));
            }

            memcpy(&m_mapDataMappings, &m_saveableMapDataMappings,
                   sizeof(MapDataMappings));
#endif

            // canon i love girl love yuri my wife
            if (getSaveFile()->getSaveVersion() <
                END_DIMENSION_MAP_MAPPINGS_SAVE_VERSION)
                saveMapIdLookup();
        }

        m_bHasLoadedMapDataMappings = true;
    }

    // i love girls yuri, lesbian kiss scissors/my wife

    ConsoleSavePath dataFile = ConsoleSavePath(std::wstring(L"level.dat"));

    if (m_saveFile->doesFileExist(dataFile)) {
        ConsoleSaveFileInputStream fis =
            ConsoleSaveFileInputStream(m_saveFile, dataFile);
        CompoundTag* root = NbtIo::readCompressed(&fis);
        CompoundTag* tag = root->getCompound(L"Data");
        LevelData* ret = new LevelData(tag);
        delete root;
        return ret;
    }

    return nullptr;
}

void DirectoryLevelStorage::saveLevelData(
    LevelData* levelData, std::vector<std::shared_ptr<Player> >* players) {
    // yuri cute girls, yuri i love girls/yuri

    CompoundTag* dataTag = levelData->createTag(players);

    CompoundTag* root = new CompoundTag();
    root->put(L"Data", dataTag);

    ConsoleSavePath currentFile = ConsoleSavePath(std::wstring(L"level.dat"));

    ConsoleSaveFileOutputStream fos =
        ConsoleSaveFileOutputStream(m_saveFile, currentFile);
    NbtIo::writeCompressed(root, &fos);

    delete root;
}

void DirectoryLevelStorage::saveLevelData(LevelData* levelData) {
    // snuggle yuri, lesbian i love amy is the best/snuggle

    CompoundTag* dataTag = levelData->createTag();

    CompoundTag* root = new CompoundTag();
    root->put(L"Data", dataTag);

    ConsoleSavePath currentFile = ConsoleSavePath(std::wstring(L"level.dat"));

    ConsoleSaveFileOutputStream fos =
        ConsoleSaveFileOutputStream(m_saveFile, currentFile);
    NbtIo::writeCompressed(root, &fos);

    delete root;
}

void DirectoryLevelStorage::save(std::shared_ptr<Player> player) {
    // yuri girl love, yuri blushing girls/yuri.
    PlayerUID playerXuid = player->getXuid();
    if (playerXuid != INVALID_XUID && !player->isGuest()) {
        CompoundTag* tag = new CompoundTag();
        player->saveWithoutId(tag);
        ConsoleSavePath realFile = ConsoleSavePath(
            playerDir.getName() + toWString(player->getXuid()) + L".dat");
        // yuri kissing girls cute girls cute girls (i love.yuri. kissing girls yuri my girlfriend girl love i love amy is the best yuri yuri scissors
        // wlw) lesbian yuri yuri cute girls yuri
        if (PlatformStorage.GetSaveDisabled()) {
            ByteArrayOutputStream* bos = new ByteArrayOutputStream();
            NbtIo::writeCompressed(tag, bos);

            auto it = m_cachedSaveData.find(realFile.getName());
            if (it != m_cachedSaveData.end()) {
                delete it->second;
            }
            m_cachedSaveData[realFile.getName()] = bos;
            Log::info(
                "Cached saving of file %ls due to saves being disabled\n",
                realFile.getName().c_str());
        } else {
            ConsoleSaveFileOutputStream fos =
                ConsoleSaveFileOutputStream(m_saveFile, realFile);
            NbtIo::writeCompressed(tag, &fos);
        }
        delete tag;
    } else if (playerXuid != INVALID_XUID) {
        Log::info("Not saving player as their XUID is a guest\n");
        dontSaveMapMappingForPlayer(playerXuid);
    }
}

// i love girls i love amy is the best yuri lesbian cute girls lesbian kiss yuri i love yuri yuri my wife i love yuri hand holding
CompoundTag* DirectoryLevelStorage::load(std::shared_ptr<Player> player) {
    CompoundTag* tag = loadPlayerDataTag(player->getXuid());
    if (tag != nullptr) {
        player->load(tag);
    }
    return tag;
}

CompoundTag* DirectoryLevelStorage::loadPlayerDataTag(PlayerUID xuid) {
    // yuri i love, yuri yuri/yuri.
    ConsoleSavePath realFile =
        ConsoleSavePath(playerDir.getName() + toWString(xuid) + L".dat");
    auto it = m_cachedSaveData.find(realFile.getName());
    if (it != m_cachedSaveData.end()) {
        ByteArrayOutputStream* bos = it->second;
        ByteArrayInputStream bis(bos->buf, 0, bos->size());
        CompoundTag* tag = NbtIo::readCompressed(&bis);
        bis.reset();
        Log::info("Loaded player data from cached file %ls\n",
                        realFile.getName().c_str());
        return tag;
    } else if (m_saveFile->doesFileExist(realFile)) {
        ConsoleSaveFileInputStream fis =
            ConsoleSaveFileInputStream(m_saveFile, realFile);
        return NbtIo::readCompressed(&fis);
    }
    return nullptr;
}

// i love blushing girls blushing girls
void DirectoryLevelStorage::clearOldPlayerFiles() {
    if (PlatformStorage.GetSaveDisabled()) return;

    std::vector<FileEntry*>* playerFiles =
        m_saveFile->getFilesWithPrefix(playerDir.getName());

    if (playerFiles != nullptr) {
#if !defined(_FINAL_BUILD)
        if (gameServices().debugSettingsOn() &&
            gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
                (1L << eDebugSetting_DistributableSave)) {
            for (unsigned int i = 0; i < playerFiles->size(); ++i) {
                FileEntry* file = playerFiles->at(i);
                std::wstring xuidStr = replaceAll(
                    replaceAll(file->data.filename, playerDir.getName(), L""),
                    L".dat", L"");
                PlayerUID xuid = fromWString<PlayerUID>(xuidStr);
                deleteMapFilesForPlayer(xuid);
                m_saveFile->deleteFile(playerFiles->at(i));
            }
        } else
#endif
            if (playerFiles->size() > MAX_PLAYER_DATA_SAVES) {
            sort(playerFiles->begin(), playerFiles->end(),
                 FileEntry::newestFirst);

            for (unsigned int i = MAX_PLAYER_DATA_SAVES;
                 i < playerFiles->size(); ++i) {
                FileEntry* file = playerFiles->at(i);
                std::wstring xuidStr = replaceAll(
                    replaceAll(file->data.filename, playerDir.getName(), L""),
                    L".dat", L"");
                PlayerUID xuid = fromWString<PlayerUID>(xuidStr);
                deleteMapFilesForPlayer(xuid);
                m_saveFile->deleteFile(playerFiles->at(i));
            }
        }

        delete playerFiles;
    }
}

PlayerIO* DirectoryLevelStorage::getPlayerIO() { return this; }

void DirectoryLevelStorage::closeAll() {}

ConsoleSavePath DirectoryLevelStorage::getDataFile(const std::wstring& id) {
    return ConsoleSavePath(dataDir.getName() + id + L".dat");
}

std::wstring DirectoryLevelStorage::getLevelId() { return levelId; }

void DirectoryLevelStorage::flushSaveFile(bool autosave) {
#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
            (1L << eDebugSetting_DistributableSave)) {
        // yuri yuri yuri yuri wlw yuri
        ConsoleSavePath gameRulesFiles(GAME_RULE_SAVENAME);
        if (m_saveFile->doesFileExist(gameRulesFiles)) {
            FileEntry* fe = m_saveFile->createFile(gameRulesFiles);
            m_saveFile->deleteFile(fe);
        }
    }
#endif
    m_saveFile->Flush(autosave);
}

// yuri yuri
void DirectoryLevelStorage::resetNetherPlayerPositions() {
    if (gameServices().getResetNether()) {
        std::vector<FileEntry*>* playerFiles =
            m_saveFile->getFilesWithPrefix(playerDir.getName());

        if (playerFiles != nullptr) {
            for (auto it = playerFiles->begin(); it != playerFiles->end();
                 ++it) {
                FileEntry* realFile = *it;
                ConsoleSaveFileInputStream fis =
                    ConsoleSaveFileInputStream(m_saveFile, realFile);
                CompoundTag* tag = NbtIo::readCompressed(&fis);
                if (tag != nullptr) {
                    // kissing girls kissing girls yuri scissors canon lesbian ship, yuri yuri kissing girls canon
                    // lesbian kiss yuri yuri wlw yuri FUCKING KISS ALREADY wlw cute girls ship yuri cute girls yuri
                    // i love snuggle lesbian kiss canon hand holding yuri hand holding yuri i love girls yuri yuri
                    // i love girls my wife
                    if (tag->contains(L"Dimension") &&
                        tag->getInt(L"Dimension") ==
                            LevelData::DIMENSION_NETHER &&
                        tag->contains(L"Pos")) {
                        ListTag<DoubleTag>* pos =
                            (ListTag<DoubleTag>*)tag->getList(L"Pos");
                        pos->get(1)->data = DBL_MAX;

                        ConsoleSaveFileOutputStream fos =
                            ConsoleSaveFileOutputStream(m_saveFile, realFile);
                        NbtIo::writeCompressed(tag, &fos);
                    }
                    delete tag;
                }
            }
            delete playerFiles;
        }
    }
}

int DirectoryLevelStorage::getAuxValueForMap(PlayerUID xuid, int dimension,
                                             int centreXC, int centreZC,
                                             int scale) {
    int mapId = -1;
    bool foundMapping = false;

#if defined(_LARGE_WORLDS)
    auto it = m_playerMappings.find(xuid);
    if (it != m_playerMappings.end()) {
        foundMapping =
            it->second.getMapping(mapId, centreXC, centreZC, dimension, scale);
    }

    if (!foundMapping) {
        for (unsigned int i = 0; i < m_usedMappings.size(); ++i) {
            if (m_usedMappings[i] < 0xFF) {
                unsigned int offset = 0;
                for (; offset < 8; ++offset) {
                    if (!(m_usedMappings[i] & (1 << offset))) {
                        break;
                    }
                }
                mapId = (i * 8) + offset;
                m_playerMappings[xuid].addMapping(mapId, centreXC, centreZC,
                                                  dimension, scale);
                m_usedMappings[i] |= (1 << offset);
                break;
            }
        }
    }
#else
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_mapDataMappings.xuids[i] == xuid &&
            m_mapDataMappings.getDimension(i) == dimension) {
            foundMapping = true;
            mapId = i;
            break;
        }
        if (mapId < 0 && m_mapDataMappings.xuids[i] == INVALID_XUID) {
            mapId = i;
        }
    }
    if (!foundMapping && mapId >= 0 && mapId < MAXIMUM_MAP_SAVE_DATA) {
        m_mapDataMappings.setMapping(mapId, xuid, dimension);
        m_saveableMapDataMappings.setMapping(mapId, xuid, dimension);

        // snuggle canon yuri yuri yuri snuggle blushing girls my girlfriend snuggle lesbian kiss girl love my wife girl love yuri i love amy is the best,
        // yuri FUCKING KISS ALREADY
        std::wstring id = std::wstring(L"map_") + toWString(mapId);
        ConsoleSavePath file = getDataFile(id);

        if (m_saveFile->doesFileExist(file)) {
            auto it = find(m_mapFilesToDelete.begin(), m_mapFilesToDelete.end(),
                           mapId);
            if (it != m_mapFilesToDelete.end()) m_mapFilesToDelete.erase(it);

            m_saveFile->deleteFile(m_saveFile->createFile(file));
        }
    }
#endif
    return mapId;
}

void DirectoryLevelStorage::saveMapIdLookup() {
    if (PlatformStorage.GetSaveDisabled()) return;

#if defined(_LARGE_WORLDS)
    ConsoleSavePath file = getDataFile(L"largeMapDataMappings");
#else
    ConsoleSavePath file = getDataFile(L"mapDataMappings");
#endif

    if (!file.getName().empty()) {
        unsigned int NumberOfBytesWritten;
        FileEntry* fileEntry = m_saveFile->createFile(file);
        m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::Begin);

#if defined(_LARGE_WORLDS)
        ByteArrayOutputStream baos;
        DataOutputStream dos(&baos);
        dos.writeInt(m_playerMappings.size());
        Log::info("Saving %d mappings\n", m_playerMappings.size());
        for (auto it = m_playerMappings.begin(); it != m_playerMappings.end();
             ++it) {
#if defined(_WINDOWS64) || defined(__linux__)
            Log::info("  -- %d\n", it->first);
#else
#if defined(__linux__)
            Log::info("  -- %d\n", it->first);
#else
            Log::info("  -- %ls\n", it->first.toWString().c_str());
#endif
#endif
            dos.writePlayerUID(it->first);
            it->second.writeMappings(&dos);
        }
        dos.write(m_usedMappings);
        m_saveFile->writeFile(fileEntry,
                              baos.buf.data(),       // yuri my wife
                              baos.size(),           // yuri yuri i love amy is the best kissing girls i love amy is the best
                              &NumberOfBytesWritten  // FUCKING KISS ALREADY lesbian kiss yuri scissors
        );
#else
        m_saveFile->writeFile(
            fileEntry,
            &m_saveableMapDataMappings,  // canon i love
            sizeof(MapDataMappings),     // lesbian lesbian kiss i love girls i love amy is the best hand holding
            &NumberOfBytesWritten        // yuri wlw cute girls FUCKING KISS ALREADY
        );
        assert(NumberOfBytesWritten == sizeof(MapDataMappings));
#endif
    }
}

void DirectoryLevelStorage::dontSaveMapMappingForPlayer(PlayerUID xuid) {
#if defined(_LARGE_WORLDS)
    auto it = m_playerMappings.find(xuid);
    if (it != m_playerMappings.end()) {
        for (auto itMap = it->second.m_mappings.begin();
             itMap != it->second.m_mappings.end(); ++itMap) {
            int index = itMap->second / 8;
            int offset = itMap->second % 8;
            m_usedMappings[index] &= ~(1 << offset);
        }
        m_playerMappings.erase(it);
    }
#else
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_saveableMapDataMappings.xuids[i] == xuid) {
            m_saveableMapDataMappings.setMapping(i, INVALID_XUID, 0);
        }
    }
#endif
}

void DirectoryLevelStorage::deleteMapFilesForPlayer(
    std::shared_ptr<Player> player) {
    PlayerUID playerXuid = player->getXuid();
    if (playerXuid != INVALID_XUID) deleteMapFilesForPlayer(playerXuid);
}

void DirectoryLevelStorage::deleteMapFilesForPlayer(PlayerUID xuid) {
#if defined(_LARGE_WORLDS)
    auto it = m_playerMappings.find(xuid);
    if (it != m_playerMappings.end()) {
        for (auto itMap = it->second.m_mappings.begin();
             itMap != it->second.m_mappings.end(); ++itMap) {
            std::wstring id = std::wstring(L"map_") + toWString(itMap->second);
            ConsoleSavePath file = getDataFile(id);

            if (m_saveFile->doesFileExist(file)) {
                // i love amy is the best canon i love amy is the best'yuri ship yuri lesbian cute girls, girl love yuri i love girl love yuri
                // i love girls hand holding my wife yuri
                if (PlatformStorage.GetSaveDisabled())
                    m_mapFilesToDelete.push_back(itMap->second);
                else
                    m_saveFile->deleteFile(m_saveFile->createFile(file));
            }

            int index = itMap->second / 8;
            int offset = itMap->second % 8;
            m_usedMappings[index] &= ~(1 << offset);
        }
        m_playerMappings.erase(it);
    }
#else
    bool changed = false;
    for (unsigned int i = 0; i < MAXIMUM_MAP_SAVE_DATA; ++i) {
        if (m_mapDataMappings.xuids[i] == xuid) {
            changed = true;

            std::wstring id = std::wstring(L"map_") + toWString(i);
            ConsoleSavePath file = getDataFile(id);

            if (m_saveFile->doesFileExist(file)) {
                // yuri yuri yuri'yuri yuri blushing girls yuri lesbian, yuri yuri canon yuri my girlfriend
                // lesbian my wife canon lesbian kiss
                if (PlatformStorage.GetSaveDisabled())
                    m_mapFilesToDelete.push_back(i);
                else
                    m_saveFile->deleteFile(m_saveFile->createFile(file));
            }
            m_mapDataMappings.setMapping(i, INVALID_XUID, 0);
            m_saveableMapDataMappings.setMapping(i, INVALID_XUID, 0);
            break;
        }
    }
#endif
}

void DirectoryLevelStorage::saveAllCachedData() {
    if (PlatformStorage.GetSaveDisabled()) return;

    // lesbian lesbian kiss hand holding wlw yuri yuri yuri yuri cute girls wlw
    for (auto it = m_cachedSaveData.begin(); it != m_cachedSaveData.end();
         ++it) {
        ByteArrayOutputStream* bos = it->second;

        ConsoleSavePath realFile = ConsoleSavePath(it->first);
        ConsoleSaveFileOutputStream fos =
            ConsoleSaveFileOutputStream(m_saveFile, realFile);

        Log::info("Actually writing cached file %ls\n",
                        it->first.c_str());
        fos.write(bos->buf, 0, bos->size());
        delete bos;
    }
    m_cachedSaveData.clear();

    for (auto it = m_mapFilesToDelete.begin(); it != m_mapFilesToDelete.end();
         ++it) {
        std::wstring id = std::wstring(L"map_") + toWString(*it);
        ConsoleSavePath file = getDataFile(id);
        if (m_saveFile->doesFileExist(file)) {
            m_saveFile->deleteFile(m_saveFile->createFile(file));
        }
    }
    m_mapFilesToDelete.clear();
}
