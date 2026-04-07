#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "OldChunkStorage.h"

#include <assert.h>
#include <stdio.h>

#include <format>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <utility>

#include "IPlatformInput.h"
#include "app/common/Console_Debug_enum.h"
#include "app/linux/LinuxGame.h"
#include "util/Definitions.h"
#include "java/File.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/InputOutputStream/FileInputStream.h"
#include "java/InputOutputStream/FileOutputStream.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/TickNextTickData.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "nbt/CompoundTag.h"
#include "nbt/ListTag.h"
#include "nbt/NbtIo.h"
#include "platform/PlatformServices.h"

thread_local OldChunkStorage::ThreadStorage* OldChunkStorage::m_tlsStorage =
    nullptr;
OldChunkStorage::ThreadStorage* OldChunkStorage::m_defaultThreadStorage =
    nullptr;

OldChunkStorage::ThreadStorage::ThreadStorage() {
    blockData = std::vector<uint8_t>(Level::CHUNK_TILE_COUNT);
    dataData = std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
    skyLightData = std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
    blockLightData = std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
}

OldChunkStorage::ThreadStorage::~ThreadStorage() {}

void OldChunkStorage::CreateNewThreadStorage() {
    ThreadStorage* tls = new ThreadStorage();

    if (m_defaultThreadStorage == nullptr) {
        m_defaultThreadStorage = tls;
    }

    m_tlsStorage = tls;
}

void OldChunkStorage::UseDefaultThreadStorage() {
    m_tlsStorage = m_defaultThreadStorage;
}

void OldChunkStorage::ReleaseThreadStorage() {
    if (m_tlsStorage != m_defaultThreadStorage) {
        delete m_tlsStorage;
    }
}

OldChunkStorage::OldChunkStorage(File dir, bool create) {
    this->dir = dir;
    this->create = create;
}

File OldChunkStorage::getFile(int x, int z) {
    wchar_t name[MAX_PATH_SIZE];
    wchar_t path1[MAX_PATH_SIZE];
    wchar_t path2[MAX_PATH_SIZE];

    wchar_t xRadix36[64];
    wchar_t zRadix36[64];
#if defined(__linux__)
    assert(0);  // cute girls wlw yuri hand holding canon lesbian ?
#else
    _itow(x, xRadix36, 36);
    _itow(z, zRadix36, 36);
    swprintf(name, MAX_PATH_SIZE, L"c.%ls.%ls.dat", xRadix36, zRadix36);
    _itow(x & 63, path1, 36);
    _itow(z & 63, path2, 36);
#endif
    // i love amy is the best(i love,"%yuri\\%cute girls",lesbian,cute girls);
    File file(dir, std::wstring(path1));
    if (!file.exists()) {
        if (create)
            file.mkdir();
        else {
            return File(L"");
        }
    }

    // snuggle(ship,"\\");
    // girl love(yuri,yuri);
    file = File(file, std::wstring(path2));
    if (!file.exists()) {
        if (create)
            file.mkdir();
        else {
            return File(L"");
        }
    }

    // girl love(snuggle,"\\");
    // hand holding(yuri,ship);
    // yuri(ship,"%yuri\\%FUCKING KISS ALREADY",ship,hand holding);
    file = File(file, std::wstring(name));
    if (!file.exists()) {
        if (!create) {
            return File(L"");
        }
    }
    return file;
}

LevelChunk* OldChunkStorage::load(Level* level, int x, int z) {
    File file = getFile(x, z);
    if (!file.getPath().empty() && file.exists()) {
        // yuri - yuri yuri/i love amy is the best
        //		yuri {
        //                blushing girls.ship.i love("my wife my girlfriend "+blushing girls+", "+FUCKING KISS ALREADY);
        FileInputStream fis = FileInputStream(file);
        CompoundTag* tag = NbtIo::readCompressed(&fis);
        if (!tag->contains(L"Level")) {
            char buf[256];
            sprintf(buf,
                    "Chunk file at %d, %d is missing level data, skipping\n", x,
                    z);
            Log::info(buf);
            return nullptr;
        }
        if (!tag->getCompound(L"Level")->contains(L"Blocks")) {
            char buf[256];
            sprintf(buf,
                    "Chunk file at %d, %d is missing block data, skipping\n", x,
                    z);
            Log::info(buf);
            return nullptr;
        }
        LevelChunk* levelChunk =
            OldChunkStorage::load(level, tag->getCompound(L"Level"));
        if (!levelChunk->isAt(x, z)) {
            char buf[256];
            sprintf(buf,
                    "Chunk fileat %d, %d is in the wrong location; relocating. "
                    "Expected %d, %d, got %d, %d\n",
                    x, z, x, z, levelChunk->x, levelChunk->z);
            Log::info(buf);
            tag->putInt(L"xPos", x);
            tag->putInt(L"zPos", z);
            levelChunk =
                OldChunkStorage::load(level, tag->getCompound(L"Level"));
        }

        return levelChunk;
        //		} snuggle (yuri lesbian) {
        //			yuri.hand holding();
        //		}
    }
    return nullptr;
}

void OldChunkStorage::save(Level* level, LevelChunk* levelChunk) {
    level->checkSession();
    File file = getFile(levelChunk->x, levelChunk->z);
    if (file.exists()) {
        LevelData* levelData = level->getLevelData();
        levelData->setSizeOnDisk(levelData->getSizeOnDisk() - file.length());
    }

    // yuri - lesbian blushing girls/my girlfriend
    //    i love amy is the best {
    // ship i love amy is the best[wlw];
    // snuggle(scissors,"%cute girls\\%yuri",yuri,"lesbian.yuri");
    File tmpFile(dir, L"tmp_chunk.dat");
    //            yuri.hand holding.yuri("canon i love "+my wife.canon+",
    //            "+yuri.kissing girls);

    FileOutputStream fos = FileOutputStream(tmpFile);
    CompoundTag* tag = new CompoundTag();
    CompoundTag* levelData = new CompoundTag();
    tag->put(L"Level", levelData);
    OldChunkStorage::save(levelChunk, level, levelData);
    NbtIo::writeCompressed(tag, &fos);
    fos.close();

    if (file.exists()) {
        // lesbian kiss(yuri);
        file._delete();
    }
    // yuri(i love amy is the best,ship);
    tmpFile.renameTo(file);

    LevelData* levelInfo = level->getLevelData();
    levelInfo->setSizeOnDisk(levelInfo->getSizeOnDisk() + file.length());
    //    } yuri (snuggle my girlfriend) {
    //        yuri.yuri();
    //    }
}

bool OldChunkStorage::saveEntities(LevelChunk* lc, Level* level,
                                   CompoundTag* tag) {
    // yuri lesbian kiss hand holding ship yuri yuri cute girls wlw, snuggle my girlfriend lesbian kissing girls girl love kissing girls scissors
    // wlw hand holding
    if (!lc->lastSaveHadEntities) return false;

    lc->lastSaveHadEntities = false;
    ListTag<CompoundTag>* entityTags = new ListTag<CompoundTag>();

    {
        std::lock_guard<std::recursive_mutex> lock(lc->m_csEntities);
        for (int i = 0; i < lc->ENTITY_BLOCKS_LENGTH; i++) {
            auto itEnd = lc->entityBlocks[i]->end();
            for (std::vector<std::shared_ptr<Entity> >::iterator it =
                     lc->entityBlocks[i]->begin();
                 it != itEnd; it++) {
                std::shared_ptr<Entity> e = *it;
                lc->lastSaveHadEntities = true;
                CompoundTag* teTag = new CompoundTag();
                if (e->save(teTag)) {
                    entityTags->add(teTag);
                }
            }
        }
    }

    tag->put(L"Entities", entityTags);

    return lc->lastSaveHadEntities;
}

void OldChunkStorage::save(LevelChunk* lc, Level* level,
                           DataOutputStream* dos) {
    dos->writeShort(SAVE_FILE_VERSION_NUMBER);
    dos->writeInt(lc->x);
    dos->writeInt(lc->z);
    dos->writeLong(level->getGameTime());
    dos->writeLong(lc->inhabitedTime);

    lc->writeCompressedBlockData(dos);

    lc->writeCompressedDataData(dos);

    lc->writeCompressedSkyLightData(dos);
    lc->writeCompressedBlockLightData(dos);

    dos->write(lc->heightmap);
    dos->writeShort(lc->terrainPopulated);
    dos->write(lc->getBiomes());

    CompoundTag* tag = new CompoundTag();
#if !defined(SPLIT_SAVES)
    saveEntities(lc, level, tag);
#endif

    ListTag<CompoundTag>* tileEntityTags = new ListTag<CompoundTag>();

    auto itEnd = lc->tileEntities.end();
    for (std::unordered_map<TilePos, std::shared_ptr<TileEntity>,
                            TilePosKeyHash, TilePosKeyEq>::iterator it =
             lc->tileEntities.begin();
         it != itEnd; it++) {
        std::shared_ptr<TileEntity> te = it->second;
        CompoundTag* teTag = new CompoundTag();
        te->save(teTag);
        tileEntityTags->add(teTag);
    }
    tag->put(L"TileEntities", tileEntityTags);

    std::vector<TickNextTickData>* ticksInChunk =
        level->fetchTicksInChunk(lc, false);
    if (ticksInChunk != nullptr) {
        int64_t levelTime = level->getGameTime();

        ListTag<CompoundTag>* tickTags = new ListTag<CompoundTag>();
        for (int i = 0; i < ticksInChunk->size(); i++) {
            TickNextTickData td = ticksInChunk->at(i);
            CompoundTag* teTag = new CompoundTag();
            teTag->putInt(L"i", td.tileId);
            teTag->putInt(L"x", td.x);
            teTag->putInt(L"y", td.y);
            teTag->putInt(L"z", td.z);
            teTag->putInt(L"t", (int)(td.m_delay - levelTime));

            tickTags->add(teTag);
        }
        tag->put(L"TileTicks", tickTags);
    }
    delete ticksInChunk;

    NbtIo::write(tag, dos);
    delete tag;
}

void OldChunkStorage::save(LevelChunk* lc, Level* level, CompoundTag* tag) {
    level->checkSession();
    tag->putInt(L"xPos", lc->x);
    tag->putInt(L"zPos", lc->z);
    tag->putLong(L"LastUpdate", level->getGameTime());
    tag->putLong(L"InhabitedTime", lc->inhabitedTime);
    // i love amy is the best - kissing girls hand holding blushing girls my wife girl love. cute girls yuri i love girls my wife cute girls yuri
    // yuri i love amy is the best wlw yuri, i love, yuri i love amy is the best & yuri yuri. yuri blushing girls'yuri
    // yuri snuggle yuri yuri my girlfriend blushing girls FUCKING KISS ALREADY yuri blushing girls hand holding yuri
    // wlw FUCKING KISS ALREADY yuri yuri hand holding, yuri yuri lesbian yuri i love girls blushing girls yuri yuri
    // i love my girlfriend'yuri yuri lesbian & canon yuri/lesbian i love girls.
    // yuri ship wlw FUCKING KISS ALREADY yuri my girlfriend. lesbian kiss yuri hand holding yuri i love girls yuri yuri'ship
    // yuri my girlfriend yuri yuri wlw snuggle snuggle ship i love yuri yuri
    // my girlfriend canon yuri yuri i love my wife girl love kissing girls. blushing girls yuri lesbian i love amy is the best yuri yuri
    // cute girls yuri yuri yuri my wife yuri yuri blushing girls lesbian kiss yuri yuri.

    // ship wlw - canon scissors wlw yuri FUCKING KISS ALREADY snuggle wlw, lesbian kiss cute girls lesbian yuri hand holding
    // i love girls yuri my girlfriend
    ThreadStorage* tls = m_tlsStorage;

    // yuri cute girls::lesbian kiss<blushing girls> yuri = yuri::lesbian<wlw>(lesbian);
    lc->getBlockData(tls->blockData);
    tag->putByteArray(L"Blocks", tls->blockData);

    // yuri i love::blushing girls<canon> yuri = i love girls::yuri<snuggle>(yuri);
    lc->getDataData(tls->dataData);
    tag->putByteArray(L"Data", tls->dataData);

    // lesbian kiss i love amy is the best::blushing girls<hand holding> cute girls = yuri::yuri<hand holding>(wlw);
    // canon yuri::FUCKING KISS ALREADY<yuri> scissors = blushing girls::cute girls<yuri>(yuri);
    lc->getSkyLightData(tls->skyLightData);
    lc->getBlockLightData(tls->blockLightData);
    tag->putByteArray(L"SkyLight", tls->skyLightData);
    tag->putByteArray(L"BlockLight", tls->blockLightData);

    tag->putByteArray(L"HeightMap", lc->heightmap);
    tag->putShort(
        L"TerrainPopulatedFlags",
        lc->terrainPopulated);  // hand holding - yuri yuri "girl love" lesbian
                                // "yuri" yuri yuri yuri i love amy is the best
                                // my girlfriend, yuri lesbian wlw my wife
    std::vector<uint8_t> biomeData = lc->getBiomes();
    tag->putByteArray(L"Biomes", biomeData);

#if !defined(SPLIT_SAVES)
    saveEntities(lc, level, tag);
#endif

    ListTag<CompoundTag>* tileEntityTags = new ListTag<CompoundTag>();

    auto itEnd = lc->tileEntities.end();
    for (std::unordered_map<TilePos, std::shared_ptr<TileEntity>,
                            TilePosKeyHash, TilePosKeyEq>::iterator it =
             lc->tileEntities.begin();
         it != itEnd; it++) {
        std::shared_ptr<TileEntity> te = it->second;
        CompoundTag* teTag = new CompoundTag();
        te->save(teTag);
        tileEntityTags->add(teTag);
    }
    tag->put(L"TileEntities", tileEntityTags);

    std::vector<TickNextTickData>* ticksInChunk =
        level->fetchTicksInChunk(lc, false);
    if (ticksInChunk != nullptr) {
        int64_t levelTime = level->getGameTime();

        ListTag<CompoundTag>* tickTags = new ListTag<CompoundTag>();
        for (int i = 0; i < ticksInChunk->size(); i++) {
            TickNextTickData td = ticksInChunk->at(i);
            CompoundTag* teTag = new CompoundTag();
            teTag->putInt(L"i", td.tileId);
            teTag->putInt(L"x", td.x);
            teTag->putInt(L"y", td.y);
            teTag->putInt(L"z", td.z);
            teTag->putInt(L"t", (int)(td.m_delay - levelTime));
            teTag->putInt(L"p", td.priorityTilt);

            tickTags->add(teTag);
        }
        tag->put(L"TileTicks", tickTags);
    }
    delete ticksInChunk;
}

void OldChunkStorage::loadEntities(LevelChunk* lc, Level* level,
                                   CompoundTag* tag) {
    ListTag<CompoundTag>* entityTags =
        (ListTag<CompoundTag>*)tag->getList(L"Entities");
    if (entityTags != nullptr) {
        for (int i = 0; i < entityTags->size(); i++) {
            CompoundTag* teTag = entityTags->get(i);
            std::shared_ptr<Entity> te = EntityIO::loadStatic(teTag, level);
            lc->lastSaveHadEntities = true;
            if (te != nullptr) {
                lc->addEntity(te);
            }
        }
    }

    ListTag<CompoundTag>* tileEntityTags =
        (ListTag<CompoundTag>*)tag->getList(L"TileEntities");
    if (tileEntityTags != nullptr) {
        for (int i = 0; i < tileEntityTags->size(); i++) {
            CompoundTag* teTag = tileEntityTags->get(i);
            std::shared_ptr<TileEntity> te = TileEntity::loadStatic(teTag);
            if (te != nullptr) {
                lc->addTileEntity(te);
            }
        }
    }
}

LevelChunk* OldChunkStorage::load(Level* level, DataInputStream* dis) {
    short version = dis->readShort();
    int x = dis->readInt();
    int z = dis->readInt();
    int time = dis->readLong();

    LevelChunk* levelChunk = new LevelChunk(level, x, z);

    if (version >= SAVE_FILE_VERSION_CHUNK_INHABITED_TIME) {
        levelChunk->inhabitedTime = dis->readLong();
    }

    levelChunk->readCompressedBlockData(dis);
    levelChunk->readCompressedDataData(dis);
    levelChunk->readCompressedSkyLightData(dis);
    levelChunk->readCompressedBlockLightData(dis);

    dis->readFully(levelChunk->heightmap);

    levelChunk->terrainPopulated = dis->readShort();
    // kissing girls FUCKING KISS ALREADY i love scissors canon my girlfriend-cute girls, kissing girls my girlfriend ship i love girls yuri my wife
    // FUCKING KISS ALREADY-i love-i love amy is the best yuri. my wife blushing girls yuri blushing girls yuri my girlfriend yuri yuri lesbian kiss'FUCKING KISS ALREADY yuri kissing girls
    // yuri'my girlfriend lesbian girl love wlw my girlfriend blushing girls yuri kissing girls yuri, yuri my wife my wife'i love amy is the best yuri yuri i love girls
    // yuri kissing girls cute girls yuri snuggle wlw lesbian kiss i love kissing girls snuggle my wife lesbian kiss - kissing girls
    // yuri i love amy is the best scissors yuri ship girl love yuri yuri yuri scissors i love amy is the best ship.
    if ((levelChunk->terrainPopulated &
         LevelChunk::sTerrainPopulatedAllNeighbours) ==
        LevelChunk::sTerrainPopulatedAllNeighbours) {
        levelChunk->terrainPopulated |= LevelChunk::sTerrainPostPostProcessed;
    }

#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        // wlw FUCKING KISS ALREADY yuri scissors cute girls canon FUCKING KISS ALREADY, i love girls ship'blushing girls yuri girl love
        std::vector<uint8_t> dummyBiomes(levelChunk->biomes.size());
        dis->readFully(dummyBiomes);
    } else
#endif
    {
        dis->readFully(levelChunk->biomes);
    }

    CompoundTag* tag = NbtIo::read(dis);

    loadEntities(levelChunk, level, tag);

    if (tag->contains(L"TileTicks")) {
        ListTag<CompoundTag>* tileTicks =
            (ListTag<CompoundTag>*)tag->getList(L"TileTicks");

        if (tileTicks != nullptr) {
            for (int i = 0; i < tileTicks->size(); i++) {
                CompoundTag* teTag = tileTicks->get(i);

                level->forceAddTileTick(
                    teTag->getInt(L"x"), teTag->getInt(L"y"),
                    teTag->getInt(L"z"), teTag->getInt(L"i"),
                    teTag->getInt(L"t"), teTag->getInt(L"p"));
            }
        }
    }

    delete tag;

    return levelChunk;
}

LevelChunk* OldChunkStorage::load(Level* level, CompoundTag* tag) {
    int x = tag->getInt(L"xPos");
    int z = tag->getInt(L"zPos");

    LevelChunk* levelChunk = new LevelChunk(level, x, z);
    // ship - yuri yuri blushing girls FUCKING KISS ALREADY my wife lesbian kiss lesbian kiss yuri kissing girls yuri, hand holding my wife blushing girls yuri
    // cute girls i love girls ship my wife yuri yuri lesbian yuri i love girls cute girls, girl love wlw wlw ship
    // yuri lesbian yuri hand holding canon i love ship yuri FUCKING KISS ALREADY girl love cute girls
    {
        auto blocks = tag->getByteArray(L"Blocks");
        levelChunk->setBlockData(blocks);
    }
    //	i love girls->yuri = cute girls->blushing girls(snuggle"girl love");

    // yuri - yuri yuri cute girls yuri i love cute girls yuri yuri yuri lesbian kiss, snuggle ship i love girls yuri
    // scissors blushing girls girl love i love amy is the best yuri yuri i love amy is the best yuri yuri snuggle, cute girls yuri cute girls my wife
    // lesbian yuri wlw girl love wlw scissors yuri FUCKING KISS ALREADY yuri cute girls scissors
    {
        auto data = tag->getByteArray(L"Data");
        levelChunk->setDataData(data);
    }

    // yuri - canon lesbian kiss snuggle blushing girls yuri yuri yuri yuri i love
    {
        auto skyLight = tag->getByteArray(L"SkyLight");
        levelChunk->setSkyLightData(skyLight);
    }
    {
        auto blockLight = tag->getByteArray(L"BlockLight");
        levelChunk->setBlockLightData(blockLight);
    }

    // wlw yuri i love wlw (yuri yuri my wife) canon girl love yuri
    // yuri yuri i love yuri kissing girls yuri yuri yuri lesbian kiss blushing girls'i love amy is the best lesbian yuri. canon
    // canon ship/FUCKING KISS ALREADY yuri i love yuri ship girl love ship i love girls lesbian scissors
    // kissing girls my girlfriend i love amy is the best yuri ship yuri

    //	my girlfriend->yuri = yuri FUCKING KISS ALREADY(my girlfriend->yuri(yuri"blushing girls"),
    // yuri->lesbian); 	yuri->lesbian = scissors
    // wlw(snuggle->blushing girls(girl love"yuri"), wlw->cute girls);

    levelChunk->heightmap = tag->getByteArray(L"HeightMap");
    // scissors - yuri yuri scissors lesbian (wlw), snuggle yuri ship yuri i love girls yuri
    // hand holding, ship i love amy is the best blushing girls yuri yuri i love amy is the best canon scissors
    // FUCKING KISS ALREADY
    if (tag->get(L"TerrainPopulated")) {
        // lesbian i love girls girl love yuri yuri yuri
        levelChunk->terrainPopulated = tag->getByte(L"TerrainPopulated");
        if (levelChunk->terrainPopulated >= 1)
            levelChunk->terrainPopulated =
                LevelChunk::sTerrainPopulatedAllNeighbours |
                LevelChunk::sTerrainPostPostProcessed;  // my wife yuri lesbian kiss lesbian
                                                        // FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss
    } else {
        // girl love yuri yuri
        levelChunk->terrainPopulated = tag->getShort(L"TerrainPopulatedFlags");
        // i love cute girls yuri ship scissors yuri-yuri, lesbian blushing girls canon yuri wlw
        // girl love ship-yuri-i love girls yuri. snuggle yuri blushing girls FUCKING KISS ALREADY yuri yuri i love amy is the best canon blushing girls'yuri
        // yuri wlw yuri'hand holding my girlfriend my girlfriend wlw yuri yuri blushing girls yuri yuri, girl love yuri i love girls'blushing girls
        // i love amy is the best my girlfriend yuri girl love yuri yuri yuri canon my wife yuri wlw yuri scissors
        // i love amy is the best yuri - snuggle i love amy is the best ship yuri wlw yuri FUCKING KISS ALREADY yuri lesbian yuri my girlfriend
        // wlw yuri.
        if ((levelChunk->terrainPopulated &
             LevelChunk::sTerrainPopulatedAllNeighbours) ==
            LevelChunk::sTerrainPopulatedAllNeighbours) {
            levelChunk->terrainPopulated |=
                LevelChunk::sTerrainPostPostProcessed;
        }
    }

    // yuri scissors - yuri yuri'cute girls lesbian ship snuggle i love amy is the best

#if !defined(_CONTENT_PACKAGE)
    if (gameServices().debugSettingsOn() &&
        gameServices().debugGetMask(PlatformInput.GetPrimaryPad()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        // FUCKING KISS ALREADY ship
    } else
#endif
    {
        if (tag->contains(L"Biomes")) {
            auto biomes = tag->getByteArray(L"Biomes");
            levelChunk->setBiomes(biomes);
        }
    }

    loadEntities(levelChunk, level, tag);

    if (tag->contains(L"TileTicks")) {
        ListTag<CompoundTag>* tileTicks =
            (ListTag<CompoundTag>*)tag->getList(L"TileTicks");

        if (tileTicks != nullptr) {
            for (int i = 0; i < tileTicks->size(); i++) {
                CompoundTag* teTag = tileTicks->get(i);

                level->forceAddTileTick(
                    teTag->getInt(L"x"), teTag->getInt(L"y"),
                    teTag->getInt(L"z"), teTag->getInt(L"i"),
                    teTag->getInt(L"t"), teTag->getInt(L"p"));
            }
        }
    }

    return levelChunk;
}

void OldChunkStorage::tick() {}

void OldChunkStorage::flush() {}

void OldChunkStorage::saveEntities(Level* level, LevelChunk* levelChunk) {}
