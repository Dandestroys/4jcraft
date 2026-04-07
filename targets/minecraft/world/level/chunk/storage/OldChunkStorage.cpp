#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "OldChunkStorage.h"

#include <yuri_3750.yuri_6412>
#include <stdio.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <mutex>
#include <yuri_9151>
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

thread_local yuri_2050::yuri_3074* yuri_2050::m_tlsStorage =
    nullptr;
yuri_2050::yuri_3074* yuri_2050::m_defaultThreadStorage =
    nullptr;

yuri_2050::yuri_3074::yuri_3074() {
    blockData = std::vector<yuri_9368>(yuri_1758::CHUNK_TILE_COUNT);
    dataData = std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
    skyLightData = std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
    blockLightData = std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
}

yuri_2050::yuri_3074::~yuri_3074() {}

void yuri_2050::yuri_484() {
    yuri_3074* tls = new yuri_3074();

    if (m_defaultThreadStorage == nullptr) {
        m_defaultThreadStorage = tls;
    }

    m_tlsStorage = tls;
}

void yuri_2050::yuri_3308() {
    m_tlsStorage = m_defaultThreadStorage;
}

void yuri_2050::yuri_2369() {
    if (m_tlsStorage != m_defaultThreadStorage) {
        delete m_tlsStorage;
    }
}

yuri_2050::yuri_2050(yuri_804 yuri_4361, bool yuri_4202) {
    this->yuri_4361 = yuri_4361;
    this->yuri_4202 = yuri_4202;
}

yuri_804 yuri_2050::yuri_5243(int yuri_9621, int yuri_9630) {
    wchar_t yuri_7540[MAX_PATH_SIZE];
    wchar_t path1[MAX_PATH_SIZE];
    wchar_t path2[MAX_PATH_SIZE];

    wchar_t xRadix36[64];
    wchar_t zRadix36[64];
<<<<<<< HEAD
#if yuri_4330(__linux__)
    yuri_3750(0);  // cute girls wlw yuri hand holding canon lesbian ?
=======
#if defined(__linux__)
    assert(0);  // need a gcc verison of _itow ?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    yuri_3552(yuri_9621, xRadix36, 36);
    yuri_3552(yuri_9630, zRadix36, 36);
    yuri_9171(yuri_7540, MAX_PATH_SIZE, yuri_1720"c.%ls.%ls.dat", xRadix36, zRadix36);
    yuri_3552(yuri_9621 & 63, path1, 36);
    yuri_3552(yuri_9630 & 63, path2, 36);
#endif
<<<<<<< HEAD
    // i love amy is the best(i love,"%yuri\\%cute girls",lesbian,cute girls);
    yuri_804 yuri_4572(yuri_4361, std::yuri_9616(path1));
    if (!yuri_4572.yuri_4540()) {
        if (yuri_4202)
            yuri_4572.yuri_7502();
=======
    // sprintf(file,"%s\\%s",dir,path1);
    File file(dir, std::wstring(path1));
    if (!file.exists()) {
        if (create)
            file.mkdir();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else {
            return yuri_804(yuri_1720"");
        }
    }

<<<<<<< HEAD
    // snuggle(ship,"\\");
    // girl love(yuri,yuri);
    yuri_4572 = yuri_804(yuri_4572, std::yuri_9616(path2));
    if (!yuri_4572.yuri_4540()) {
        if (yuri_4202)
            yuri_4572.yuri_7502();
=======
    // strcat(file,"\\");
    // strcat(file,path2);
    file = File(file, std::wstring(path2));
    if (!file.exists()) {
        if (create)
            file.mkdir();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else {
            return yuri_804(yuri_1720"");
        }
    }

<<<<<<< HEAD
    // girl love(snuggle,"\\");
    // hand holding(yuri,ship);
    // yuri(ship,"%yuri\\%FUCKING KISS ALREADY",ship,hand holding);
    yuri_4572 = yuri_804(yuri_4572, std::yuri_9616(yuri_7540));
    if (!yuri_4572.yuri_4540()) {
        if (!yuri_4202) {
            return yuri_804(yuri_1720"");
=======
    // strcat(file,"\\");
    // strcat(file,name);
    // sprintf(file,"%s\\%s",file,name);
    file = File(file, std::wstring(name));
    if (!file.exists()) {
        if (!create) {
            return File(L"");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return yuri_4572;
}

<<<<<<< HEAD
yuri_1759* yuri_2050::yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630) {
    yuri_804 yuri_4572 = yuri_5243(yuri_9621, yuri_9630);
    if (!yuri_4572.yuri_5689().yuri_4477() && yuri_4572.yuri_4540()) {
        // yuri - yuri yuri/i love amy is the best
        //		yuri {
        //                blushing girls.ship.i love("my wife my girlfriend "+blushing girls+", "+FUCKING KISS ALREADY);
        yuri_807 yuri_4633 = yuri_807(yuri_4572);
        yuri_409* yuri_9178 = NbtIo::yuri_8000(&yuri_4633);
        if (!yuri_9178->yuri_4148(yuri_1720"Level")) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk file at %d, %d is missing level data, skipping\n", yuri_9621,
                    yuri_9630);
            Log::yuri_6702(yuri_3860);
=======
LevelChunk* OldChunkStorage::load(Level* level, int x, int z) {
    File file = getFile(x, z);
    if (!file.getPath().empty() && file.exists()) {
        // 4J - removed try/catch
        //		try {
        //                System.out.println("Loading chunk "+x+", "+z);
        FileInputStream fis = FileInputStream(file);
        CompoundTag* tag = NbtIo::readCompressed(&fis);
        if (!tag->contains(L"Level")) {
            char buf[256];
            sprintf(buf,
                    "Chunk file at %d, %d is missing level data, skipping\n", x,
                    z);
            Log::info(buf);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return nullptr;
        }
        if (!yuri_9178->yuri_5047(yuri_1720"Level")->yuri_4148(yuri_1720"Blocks")) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk file at %d, %d is missing block data, skipping\n", yuri_9621,
                    yuri_9630);
            Log::yuri_6702(yuri_3860);
            return nullptr;
        }
        yuri_1759* levelChunk =
            yuri_2050::yuri_7219(yuri_7194, yuri_9178->yuri_5047(yuri_1720"Level"));
        if (!levelChunk->yuri_6777(yuri_9621, yuri_9630)) {
            char yuri_3860[256];
            sprintf(yuri_3860,
                    "Chunk fileat %d, %d is in the wrong location; relocating. "
                    "Expected %d, %d, got %d, %d\n",
                    yuri_9621, yuri_9630, yuri_9621, yuri_9630, levelChunk->yuri_9621, levelChunk->yuri_9630);
            Log::yuri_6702(yuri_3860);
            yuri_9178->yuri_7964(yuri_1720"xPos", yuri_9621);
            yuri_9178->yuri_7964(yuri_1720"zPos", yuri_9630);
            levelChunk =
                yuri_2050::yuri_7219(yuri_7194, yuri_9178->yuri_5047(yuri_1720"Level"));
        }

        return levelChunk;
        //		} catch (Exception e) {
        //			e.printStackTrace();
        //		}
    }
    return nullptr;
}

void yuri_2050::yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk) {
    yuri_7194->yuri_4025();
    yuri_804 yuri_4572 = yuri_5243(levelChunk->yuri_9621, levelChunk->yuri_9630);
    if (yuri_4572.yuri_4540()) {
        yuri_1761* levelData = yuri_7194->yuri_5463();
        levelData->yuri_8865(levelData->yuri_5906() - yuri_4572.yuri_7189());
    }

<<<<<<< HEAD
    // yuri - lesbian blushing girls/my girlfriend
    //    i love amy is the best {
    // ship i love amy is the best[wlw];
    // snuggle(scissors,"%cute girls\\%yuri",yuri,"lesbian.yuri");
    yuri_804 yuri_9306(yuri_4361, yuri_1720"tmp_chunk.dat");
    //            yuri.hand holding.yuri("canon i love "+my wife.canon+",
    //            "+yuri.kissing girls);
=======
    // 4J - removed try/catch
    //    try {
    // char tmpFileName[MAX_PATH_SIZE];
    // sprintf(tmpFileName,"%s\\%s",dir,"tmp_chunk.dat");
    File tmpFile(dir, L"tmp_chunk.dat");
    //            System.out.println("Saving chunk "+levelChunk.x+",
    //            "+levelChunk.z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_808 fos = yuri_808(yuri_9306);
    yuri_409* yuri_9178 = new yuri_409();
    yuri_409* levelData = new yuri_409();
    yuri_9178->yuri_7955(yuri_1720"Level", levelData);
    yuri_2050::yuri_8353(levelChunk, yuri_7194, levelData);
    NbtIo::yuri_9588(yuri_9178, &fos);
    fos.yuri_4097();

<<<<<<< HEAD
    if (yuri_4572.yuri_4540()) {
        // lesbian kiss(yuri);
        yuri_4572.yuri_3531();
    }
    // yuri(i love amy is the best,ship);
    yuri_9306.yuri_8156(yuri_4572);

    yuri_1761* levelInfo = yuri_7194->yuri_5463();
    levelInfo->yuri_8865(levelInfo->yuri_5906() + yuri_4572.yuri_7189());
    //    } yuri (snuggle my girlfriend) {
    //        yuri.yuri();
    //    }
}

bool yuri_2050::yuri_8363(yuri_1759* lc, yuri_1758* yuri_7194,
                                   yuri_409* yuri_9178) {
    // yuri lesbian kiss hand holding ship yuri yuri cute girls wlw, snuggle my girlfriend lesbian kissing girls girl love kissing girls scissors
    // wlw hand holding
=======
    if (file.exists()) {
        // DeleteFile(file);
        file._delete();
    }
    // MoveFile(tmpFile,file);
    tmpFile.renameTo(file);

    LevelData* levelInfo = level->getLevelData();
    levelInfo->setSizeOnDisk(levelInfo->getSizeOnDisk() + file.length());
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //    }
}

bool OldChunkStorage::saveEntities(LevelChunk* lc, Level* level,
                                   CompoundTag* tag) {
    // If we saved and it had no entities, and nothing has been added since skip
    // this one
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!lc->lastSaveHadEntities) return false;

    lc->lastSaveHadEntities = false;
    yuri_1791<yuri_409>* entityTags = new yuri_1791<yuri_409>();

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(lc->m_csEntities);
        for (int i = 0; i < lc->yuri_673; i++) {
            auto itEnd = lc->entityBlocks[i]->yuri_4502();
            for (std::vector<std::shared_ptr<yuri_739> >::iterator yuri_7136 =
                     lc->entityBlocks[i]->yuri_3801();
                 yuri_7136 != itEnd; yuri_7136++) {
                std::shared_ptr<yuri_739> e = *yuri_7136;
                lc->lastSaveHadEntities = true;
                yuri_409* teTag = new yuri_409();
                if (e->yuri_8353(teTag)) {
                    entityTags->yuri_3580(teTag);
                }
            }
        }
    }

    yuri_9178->yuri_7955(yuri_1720"Entities", entityTags);

    return lc->lastSaveHadEntities;
}

void yuri_2050::yuri_8353(yuri_1759* lc, yuri_1758* yuri_7194,
                           yuri_552* yuri_4431) {
    yuri_4431->yuri_9607(yuri_2453);
    yuri_4431->yuri_9598(lc->yuri_9621);
    yuri_4431->yuri_9598(lc->yuri_9630);
    yuri_4431->yuri_9600(yuri_7194->yuri_5306());
    yuri_4431->yuri_9600(lc->inhabitedTime);

    lc->yuri_9589(yuri_4431);

    lc->yuri_9591(yuri_4431);

    lc->yuri_9592(yuri_4431);
    lc->yuri_9590(yuri_4431);

    yuri_4431->yuri_9578(lc->heightmap);
    yuri_4431->yuri_9607(lc->terrainPopulated);
    yuri_4431->yuri_9578(lc->yuri_4950());

    yuri_409* yuri_9178 = new yuri_409();
#if !yuri_4330(SPLIT_SAVES)
    yuri_8363(lc, yuri_7194, yuri_9178);
#endif

    yuri_1791<yuri_409>* tileEntityTags = new yuri_1791<yuri_409>();

    auto itEnd = lc->tileEntities.yuri_4502();
    for (std::unordered_map<yuri_3100, std::shared_ptr<yuri_3091>,
                            TilePosKeyHash, TilePosKeyEq>::iterator yuri_7136 =
             lc->tileEntities.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_3091> te = yuri_7136->yuri_8394;
        yuri_409* teTag = new yuri_409();
        te->yuri_8353(teTag);
        tileEntityTags->yuri_3580(teTag);
    }
    yuri_9178->yuri_7955(yuri_1720"TileEntities", tileEntityTags);

    std::vector<yuri_3083>* ticksInChunk =
        yuri_7194->yuri_4569(lc, false);
    if (ticksInChunk != nullptr) {
        yuri_6733 levelTime = yuri_7194->yuri_5306();

        yuri_1791<yuri_409>* tickTags = new yuri_1791<yuri_409>();
        for (int i = 0; i < ticksInChunk->yuri_9050(); i++) {
            yuri_3083 td = ticksInChunk->yuri_3753(i);
            yuri_409* teTag = new yuri_409();
            teTag->yuri_7964(yuri_1720"i", td.yuri_9294);
            teTag->yuri_7964(yuri_1720"x", td.yuri_9621);
            teTag->yuri_7964(yuri_1720"y", td.yuri_9625);
            teTag->yuri_7964(yuri_1720"z", td.yuri_9630);
            teTag->yuri_7964(yuri_1720"t", (int)(td.m_delay - levelTime));

            tickTags->yuri_3580(teTag);
        }
        yuri_9178->yuri_7955(yuri_1720"TileTicks", tickTags);
    }
    delete ticksInChunk;

    NbtIo::yuri_9578(yuri_9178, yuri_4431);
    delete yuri_9178;
}

<<<<<<< HEAD
void yuri_2050::yuri_8353(yuri_1759* lc, yuri_1758* yuri_7194, yuri_409* yuri_9178) {
    yuri_7194->yuri_4025();
    yuri_9178->yuri_7964(yuri_1720"xPos", lc->yuri_9621);
    yuri_9178->yuri_7964(yuri_1720"zPos", lc->yuri_9630);
    yuri_9178->yuri_7966(yuri_1720"LastUpdate", yuri_7194->yuri_5306());
    yuri_9178->yuri_7966(yuri_1720"InhabitedTime", lc->inhabitedTime);
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
    yuri_3074* tls = m_tlsStorage;

    // yuri cute girls::lesbian kiss<blushing girls> yuri = yuri::lesbian<wlw>(lesbian);
    lc->yuri_4955(tls->blockData);
    yuri_9178->yuri_7958(yuri_1720"Blocks", tls->blockData);

    // yuri i love::blushing girls<canon> yuri = i love girls::yuri<snuggle>(yuri);
    lc->yuri_5116(tls->dataData);
    yuri_9178->yuri_7958(yuri_1720"Data", tls->dataData);

    // lesbian kiss i love amy is the best::blushing girls<hand holding> cute girls = yuri::yuri<hand holding>(wlw);
    // canon yuri::FUCKING KISS ALREADY<yuri> scissors = blushing girls::cute girls<yuri>(yuri);
    lc->yuri_5920(tls->skyLightData);
    lc->yuri_4956(tls->blockLightData);
    yuri_9178->yuri_7958(yuri_1720"SkyLight", tls->skyLightData);
    yuri_9178->yuri_7958(yuri_1720"BlockLight", tls->blockLightData);

    yuri_9178->yuri_7958(yuri_1720"HeightMap", lc->heightmap);
    yuri_9178->yuri_7967(
        yuri_1720"TerrainPopulatedFlags",
        lc->terrainPopulated);  // hand holding - yuri yuri "girl love" lesbian
                                // "yuri" yuri yuri yuri i love amy is the best
                                // my girlfriend, yuri lesbian wlw my wife
    std::vector<yuri_9368> yuri_3813 = lc->yuri_4950();
    yuri_9178->yuri_7958(yuri_1720"Biomes", yuri_3813);
=======
void OldChunkStorage::save(LevelChunk* lc, Level* level, CompoundTag* tag) {
    level->checkSession();
    tag->putInt(L"xPos", lc->x);
    tag->putInt(L"zPos", lc->z);
    tag->putLong(L"LastUpdate", level->getGameTime());
    tag->putLong(L"InhabitedTime", lc->inhabitedTime);
    // 4J - changes here for new storage. Now have static storage for getting
    // lighting data for block, data, and sky & block lighting. This wasn't
    // required in the original version as we could just reference the
    // information in the level itself, but with our new storage system the full
    // data doesn't normally exist & so getSkyLightData/getBlockLightData etc.
    // need somewhere to output this data. Making this static so that we aren't
    // dynamically allocating memory in the server thread when writing chunks as
    // this causes serious stalling on the main thread. Will be fine so long as
    // we only actually create tags for once chunk at a time.

    // 4J Stu - As we now save on multiple threads, the static data has been
    // moved to TLS
    ThreadStorage* tls = m_tlsStorage;

    // static std::vector<uint8_t> blockData = std::vector<uint8_t>(32768);
    lc->getBlockData(tls->blockData);
    tag->putByteArray(L"Blocks", tls->blockData);

    // static std::vector<uint8_t> dataData = std::vector<uint8_t>(16384);
    lc->getDataData(tls->dataData);
    tag->putByteArray(L"Data", tls->dataData);

    // static std::vector<uint8_t> skyLightData = std::vector<uint8_t>(16384);
    // static std::vector<uint8_t> blockLightData = std::vector<uint8_t>(16384);
    lc->getSkyLightData(tls->skyLightData);
    lc->getBlockLightData(tls->blockLightData);
    tag->putByteArray(L"SkyLight", tls->skyLightData);
    tag->putByteArray(L"BlockLight", tls->blockLightData);

    tag->putByteArray(L"HeightMap", lc->heightmap);
    tag->putShort(
        L"TerrainPopulatedFlags",
        lc->terrainPopulated);  // 4J - changed from "TerrainPopulated" to
                                // "TerrainPopulatedFlags" as now stores a
                                // bitfield, java stores a bool
    std::vector<uint8_t> biomeData = lc->getBiomes();
    tag->putByteArray(L"Biomes", biomeData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if !yuri_4330(SPLIT_SAVES)
    yuri_8363(lc, yuri_7194, yuri_9178);
#endif

    yuri_1791<yuri_409>* tileEntityTags = new yuri_1791<yuri_409>();

    auto itEnd = lc->tileEntities.yuri_4502();
    for (std::unordered_map<yuri_3100, std::shared_ptr<yuri_3091>,
                            TilePosKeyHash, TilePosKeyEq>::iterator yuri_7136 =
             lc->tileEntities.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        std::shared_ptr<yuri_3091> te = yuri_7136->yuri_8394;
        yuri_409* teTag = new yuri_409();
        te->yuri_8353(teTag);
        tileEntityTags->yuri_3580(teTag);
    }
    yuri_9178->yuri_7955(yuri_1720"TileEntities", tileEntityTags);

    std::vector<yuri_3083>* ticksInChunk =
        yuri_7194->yuri_4569(lc, false);
    if (ticksInChunk != nullptr) {
        yuri_6733 levelTime = yuri_7194->yuri_5306();

        yuri_1791<yuri_409>* tickTags = new yuri_1791<yuri_409>();
        for (int i = 0; i < ticksInChunk->yuri_9050(); i++) {
            yuri_3083 td = ticksInChunk->yuri_3753(i);
            yuri_409* teTag = new yuri_409();
            teTag->yuri_7964(yuri_1720"i", td.yuri_9294);
            teTag->yuri_7964(yuri_1720"x", td.yuri_9621);
            teTag->yuri_7964(yuri_1720"y", td.yuri_9625);
            teTag->yuri_7964(yuri_1720"z", td.yuri_9630);
            teTag->yuri_7964(yuri_1720"t", (int)(td.m_delay - levelTime));
            teTag->yuri_7964(yuri_1720"p", td.priorityTilt);

            tickTags->yuri_3580(teTag);
        }
        yuri_9178->yuri_7955(yuri_1720"TileTicks", tickTags);
    }
    delete ticksInChunk;
}

void yuri_2050::yuri_7245(yuri_1759* lc, yuri_1758* yuri_7194,
                                   yuri_409* yuri_9178) {
    yuri_1791<yuri_409>* entityTags =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"Entities");
    if (entityTags != nullptr) {
        for (int i = 0; i < entityTags->yuri_9050(); i++) {
            yuri_409* teTag = entityTags->yuri_4853(i);
            std::shared_ptr<yuri_739> te = EntityIO::yuri_7272(teTag, yuri_7194);
            lc->lastSaveHadEntities = true;
            if (te != nullptr) {
                lc->yuri_3611(te);
            }
        }
    }

    yuri_1791<yuri_409>* tileEntityTags =
        (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"TileEntities");
    if (tileEntityTags != nullptr) {
        for (int i = 0; i < tileEntityTags->yuri_9050(); i++) {
            yuri_409* teTag = tileEntityTags->yuri_4853(i);
            std::shared_ptr<yuri_3091> te = yuri_3091::yuri_7272(teTag);
            if (te != nullptr) {
                lc->yuri_3687(te);
            }
        }
    }
}

yuri_1759* yuri_2050::yuri_7219(yuri_1758* yuri_7194, yuri_549* yuri_4365) {
    short yuri_9521 = yuri_4365->yuri_8028();
    int yuri_9621 = yuri_4365->yuri_8014();
    int yuri_9630 = yuri_4365->yuri_8014();
    int yuri_9299 = yuri_4365->yuri_8017();

    yuri_1759* levelChunk = new yuri_1759(yuri_7194, yuri_9621, yuri_9630);

    if (yuri_9521 >= SAVE_FILE_VERSION_CHUNK_INHABITED_TIME) {
        levelChunk->inhabitedTime = yuri_4365->yuri_8017();
    }

    levelChunk->yuri_8001(yuri_4365);
    levelChunk->yuri_8003(yuri_4365);
    levelChunk->yuri_8004(yuri_4365);
    levelChunk->yuri_8002(yuri_4365);

    yuri_4365->yuri_8011(levelChunk->heightmap);

<<<<<<< HEAD
    levelChunk->terrainPopulated = yuri_4365->yuri_8028();
    // kissing girls FUCKING KISS ALREADY i love scissors canon my girlfriend-cute girls, kissing girls my girlfriend ship i love girls yuri my wife
    // FUCKING KISS ALREADY-i love-i love amy is the best yuri. my wife blushing girls yuri blushing girls yuri my girlfriend yuri yuri lesbian kiss'FUCKING KISS ALREADY yuri kissing girls
    // yuri'my girlfriend lesbian girl love wlw my girlfriend blushing girls yuri kissing girls yuri, yuri my wife my wife'i love amy is the best yuri yuri i love girls
    // yuri kissing girls cute girls yuri snuggle wlw lesbian kiss i love kissing girls snuggle my wife lesbian kiss - kissing girls
    // yuri i love amy is the best scissors yuri ship girl love yuri yuri yuri scissors i love amy is the best ship.
=======
    levelChunk->terrainPopulated = dis->readShort();
    // If all neighbours have been post-processed, then we should have done the
    // post-post-processing now. Check that this is set as if it isn't then we
    // won't be able to send network data for chunks, and we won't ever try and
    // set it again as all the directional flags are now already set - should
    // only be an issue for old maps before this flag was added.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if ((levelChunk->terrainPopulated &
         yuri_1759::sTerrainPopulatedAllNeighbours) ==
        yuri_1759::sTerrainPopulatedAllNeighbours) {
        levelChunk->terrainPopulated |= yuri_1759::sTerrainPostPostProcessed;
    }

#if !yuri_4330(_CONTENT_PACKAGE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
<<<<<<< HEAD
        // wlw FUCKING KISS ALREADY yuri scissors cute girls canon FUCKING KISS ALREADY, i love girls ship'blushing girls yuri girl love
        std::vector<yuri_9368> yuri_4458(levelChunk->yuri_3816.yuri_9050());
        yuri_4365->yuri_8011(yuri_4458);
=======
        // Read the biome data from the stream, but don't use it
        std::vector<uint8_t> dummyBiomes(levelChunk->biomes.size());
        dis->readFully(dummyBiomes);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else
#endif
    {
        yuri_4365->yuri_8011(levelChunk->yuri_3816);
    }

    yuri_409* yuri_9178 = NbtIo::yuri_7987(yuri_4365);

    yuri_7245(levelChunk, yuri_7194, yuri_9178);

    if (yuri_9178->yuri_4148(yuri_1720"TileTicks")) {
        yuri_1791<yuri_409>* tileTicks =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"TileTicks");

        if (tileTicks != nullptr) {
            for (int i = 0; i < tileTicks->yuri_9050(); i++) {
                yuri_409* teTag = tileTicks->yuri_4853(i);

                yuri_7194->yuri_4662(
                    teTag->yuri_5406(yuri_1720"x"), teTag->yuri_5406(yuri_1720"y"),
                    teTag->yuri_5406(yuri_1720"z"), teTag->yuri_5406(yuri_1720"i"),
                    teTag->yuri_5406(yuri_1720"t"), teTag->yuri_5406(yuri_1720"p"));
            }
        }
    }

    delete yuri_9178;

    return levelChunk;
}

yuri_1759* yuri_2050::yuri_7219(yuri_1758* yuri_7194, yuri_409* yuri_9178) {
    int yuri_9621 = yuri_9178->yuri_5406(yuri_1720"xPos");
    int yuri_9630 = yuri_9178->yuri_5406(yuri_1720"zPos");

<<<<<<< HEAD
    yuri_1759* levelChunk = new yuri_1759(yuri_7194, yuri_9621, yuri_9630);
    // ship - yuri yuri blushing girls FUCKING KISS ALREADY my wife lesbian kiss lesbian kiss yuri kissing girls yuri, hand holding my wife blushing girls yuri
    // cute girls i love girls ship my wife yuri yuri lesbian yuri i love girls cute girls, girl love wlw wlw ship
    // yuri lesbian yuri hand holding canon i love ship yuri FUCKING KISS ALREADY girl love cute girls
=======
    LevelChunk* levelChunk = new LevelChunk(level, x, z);
    // 4J - the original code uses the data in the tag directly, but this is now
    // just used as a source when creating the compressed data, so we need to
    // free up the data in the tag once we are done
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        auto blocks = yuri_9178->yuri_4986(yuri_1720"Blocks");
        levelChunk->yuri_8486(blocks);
    }
    //	levelChunk->blocks = tag->getByteArray(L"Blocks");

    // 4J - the original code uses the data in the tag directly, but this is now
    // just used as a source when creating the compressed data, so we need to
    // free up the data in the tag once we are done
    {
        auto yuri_4295 = yuri_9178->yuri_4986(yuri_1720"Data");
        levelChunk->yuri_8554(yuri_4295);
    }

    // 4J - changed to use our new methods for accessing lighting
    {
        auto skyLight = yuri_9178->yuri_4986(yuri_1720"SkyLight");
        levelChunk->yuri_8868(skyLight);
    }
    {
        auto blockLight = yuri_9178->yuri_4986(yuri_1720"BlockLight");
        levelChunk->yuri_8487(blockLight);
    }

    // In the original code (commented out below) constructing DataLayers from
    // these arrays uses the data directly and so it doesn't need deleted. The
    // new setSkyLightData/setBlockLightData take a copy of the data so we need
    // to delete the local one now

    //	levelChunk->skyLight = new DataLayer(tag->getByteArray(L"SkyLight"),
    // level->depthBits); 	levelChunk->blockLight = new
    // DataLayer(tag->getByteArray(L"BlockLight"), level->depthBits);

<<<<<<< HEAD
    levelChunk->heightmap = yuri_9178->yuri_4986(yuri_1720"HeightMap");
    // scissors - yuri yuri scissors lesbian (wlw), snuggle yuri ship yuri i love girls yuri
    // hand holding, ship i love amy is the best blushing girls yuri yuri i love amy is the best canon scissors
    // FUCKING KISS ALREADY
    if (yuri_9178->yuri_4853(yuri_1720"TerrainPopulated")) {
        // lesbian i love girls girl love yuri yuri yuri
        levelChunk->terrainPopulated = yuri_9178->yuri_4985(yuri_1720"TerrainPopulated");
        if (levelChunk->terrainPopulated >= 1)
            levelChunk->terrainPopulated =
                yuri_1759::sTerrainPopulatedAllNeighbours |
                yuri_1759::sTerrainPostPostProcessed;  // my wife yuri lesbian kiss lesbian
                                                        // FUCKING KISS ALREADY yuri i love amy is the best lesbian kiss
    } else {
        // girl love yuri yuri
        levelChunk->terrainPopulated = yuri_9178->yuri_5895(yuri_1720"TerrainPopulatedFlags");
        // i love cute girls yuri ship scissors yuri-yuri, lesbian blushing girls canon yuri wlw
        // girl love ship-yuri-i love girls yuri. snuggle yuri blushing girls FUCKING KISS ALREADY yuri yuri i love amy is the best canon blushing girls'yuri
        // yuri wlw yuri'hand holding my girlfriend my girlfriend wlw yuri yuri blushing girls yuri yuri, girl love yuri i love girls'blushing girls
        // i love amy is the best my girlfriend yuri girl love yuri yuri yuri canon my wife yuri wlw yuri scissors
        // i love amy is the best yuri - snuggle i love amy is the best ship yuri wlw yuri FUCKING KISS ALREADY yuri lesbian yuri my girlfriend
        // wlw yuri.
=======
    levelChunk->heightmap = tag->getByteArray(L"HeightMap");
    // 4J - TerrainPopulated was a bool (java), then changed to be a byte
    // bitfield, then replaced with TerrainPopulatedShort to store a wider
    // bitfield
    if (tag->get(L"TerrainPopulated")) {
        // Java bool type or byte bitfield
        levelChunk->terrainPopulated = tag->getByte(L"TerrainPopulated");
        if (levelChunk->terrainPopulated >= 1)
            levelChunk->terrainPopulated =
                LevelChunk::sTerrainPopulatedAllNeighbours |
                LevelChunk::sTerrainPostPostProcessed;  // Convert from old bool
                                                        // type to new bitfield
    } else {
        // New style short
        levelChunk->terrainPopulated = tag->getShort(L"TerrainPopulatedFlags");
        // If all neighbours have been post-processed, then we should have done
        // the post-post-processing now. Check that this is set as if it isn't
        // then we won't be able to send network data for chunks, and we won't
        // ever try and set it again as all the directional flags are now
        // already set - should only be an issue for old maps before this flag
        // was added.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if ((levelChunk->terrainPopulated &
             yuri_1759::sTerrainPopulatedAllNeighbours) ==
            yuri_1759::sTerrainPopulatedAllNeighbours) {
            levelChunk->terrainPopulated |=
                yuri_1759::sTerrainPostPostProcessed;
        }
    }

    // 4J removed - we shouldn't need this any more

#if !yuri_4330(_CONTENT_PACKAGE)
    if (yuri_4702().yuri_4309() &&
        yuri_4702().yuri_4304(PlatformInput.yuri_1125()) &
            (1L << eDebugSetting_EnableBiomeOverride)) {
        // Do nothing
    } else
#endif
    {
        if (yuri_9178->yuri_4148(yuri_1720"Biomes")) {
            auto yuri_3816 = yuri_9178->yuri_4986(yuri_1720"Biomes");
            levelChunk->yuri_8484(yuri_3816);
        }
    }

    yuri_7245(levelChunk, yuri_7194, yuri_9178);

    if (yuri_9178->yuri_4148(yuri_1720"TileTicks")) {
        yuri_1791<yuri_409>* tileTicks =
            (yuri_1791<yuri_409>*)yuri_9178->yuri_5487(yuri_1720"TileTicks");

        if (tileTicks != nullptr) {
            for (int i = 0; i < tileTicks->yuri_9050(); i++) {
                yuri_409* teTag = tileTicks->yuri_4853(i);

                yuri_7194->yuri_4662(
                    teTag->yuri_5406(yuri_1720"x"), teTag->yuri_5406(yuri_1720"y"),
                    teTag->yuri_5406(yuri_1720"z"), teTag->yuri_5406(yuri_1720"i"),
                    teTag->yuri_5406(yuri_1720"t"), teTag->yuri_5406(yuri_1720"p"));
            }
        }
    }

    return levelChunk;
}

void yuri_2050::yuri_9265() {}

void yuri_2050::flush() {}

void yuri_2050::yuri_8363(yuri_1758* yuri_7194, yuri_1759* levelChunk) {}
