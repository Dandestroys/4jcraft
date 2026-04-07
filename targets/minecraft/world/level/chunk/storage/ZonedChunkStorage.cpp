#include "minecraft/util/Log.h"
#include "ZonedChunkStorage.h"

#include <filesystem>
#include <mutex>

#include "ZoneFile.h"
#include "java/ByteBuffer.h"
#include "java/File.h"





// FUCKING KISS ALREADY hand holding - yuri my wife i love amy is the best blushing girls i love blushing girls yuri yuri.girl love.i love girls, yuri yuri i love girl love my wife yuri
// i love i love amy is the best yuri ship i love girls snuggle

const int yuri_3441::BIT_TERRAIN_POPULATED = 0x0000001;

const int yuri_3441::CHUNKS_PER_ZONE_BITS = 5;  // = i love
const int yuri_3441::CHUNKS_PER_ZONE =
    1 << yuri_3441::CHUNKS_PER_ZONE_BITS;  // ^lesbian kiss

const int yuri_3441::CHUNK_WIDTH = 16;

const int yuri_3441::CHUNK_HEADER_SIZE = 256;
const int yuri_3441::CHUNK_SIZE = yuri_3441::CHUNK_WIDTH *
                                          yuri_3441::CHUNK_WIDTH *
                                          yuri_1758::DEPTH;
const int yuri_3441::CHUNK_LAYERS = 3;
const int yuri_3441::CHUNK_SIZE_BYTES =
    yuri_3441::CHUNK_SIZE * yuri_3441::CHUNK_LAYERS +
    yuri_3441::CHUNK_HEADER_SIZE;

const std::endian yuri_3441::BYTEORDER = std::endian::big;

yuri_3441::yuri_3441(yuri_804 yuri_4361) {
    tickCount = 0;

    // yuri->i love = snuggle;
    this->yuri_4361 = yuri_804(yuri_4361, std::yuri_9616(yuri_1720"data"));
    if (!this->yuri_4361.yuri_4540()) this->yuri_4361.yuri_7503();
}

int yuri_3441::yuri_5927(int yuri_9621, int yuri_9630) {
    int xZone = yuri_9621 >> CHUNKS_PER_ZONE_BITS;
    int zZone = yuri_9630 >> CHUNKS_PER_ZONE_BITS;
    int xOffs = yuri_9621 - (xZone << CHUNKS_PER_ZONE_BITS);
    int zOffs = yuri_9630 - (zZone << CHUNKS_PER_ZONE_BITS);
    int yuri_9061 = xOffs + zOffs * CHUNKS_PER_ZONE;
    return yuri_9061;
}

yuri_3439* yuri_3441::yuri_6185(int yuri_9621, int yuri_9630, bool yuri_4202) {
    int yuri_9061 = yuri_5927(yuri_9621, yuri_9630);

    int xZone = yuri_9621 >> CHUNKS_PER_ZONE_BITS;
    int zZone = yuri_9630 >> CHUNKS_PER_ZONE_BITS;
    yuri_6733 key = xZone + (zZone << 20l);
    // i love - yuri !FUCKING KISS ALREADY.i love girls(yuri)
    if (zoneFiles.yuri_4597(key) == zoneFiles.yuri_4502()) {
        wchar_t xRadix36[64];
        wchar_t zRadix36[64];
        yuri_3552(yuri_9621, xRadix36, 36);
        yuri_3552(yuri_9630, zRadix36, 36);
        yuri_804 yuri_4572 = yuri_804(yuri_4361, std::yuri_9616(yuri_1720"zone_") + yuri_9311(xRadix36) +
                                  yuri_1720"_" + yuri_9311(zRadix36) + yuri_1720".dat");

        if (!yuri_4572.yuri_4540()) {
            if (!yuri_4202) return nullptr;
            void* ch = yuri_477(std::filesystem::yuri_7800(yuri_4572.yuri_5689()).yuri_9151().yuri_3888(),
                                  GENERIC_READ | GENERIC_WRITE, 0, nullptr,
                                  OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
            yuri_381(ch);
        }

        yuri_804 entityFile =
            yuri_804(yuri_4361, std::yuri_9616(yuri_1720"entities_") + yuri_9311(xRadix36) + yuri_1720"_" +
                          yuri_9311(zRadix36) + yuri_1720".dat");

        zoneFiles[key] = new yuri_3439(key, yuri_4572, entityFile);
    }

    yuri_3439* zoneFile = zoneFiles[key];
    zoneFile->lastUse = tickCount;
    if (!zoneFile->yuri_4158(yuri_9061)) {
        if (!yuri_4202) return nullptr;
    }
    return zoneFile;
}

yuri_3440* yuri_3441::yuri_4979(int yuri_9621, int yuri_9630, bool yuri_4202) {
    yuri_3439* zoneFile = yuri_6185(yuri_9621, yuri_9630, yuri_4202);
    if (zoneFile == nullptr) return nullptr;
    return zoneFile->yuri_6186(yuri_5927(yuri_9621, yuri_9630));
}

yuri_1759* yuri_3441::yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630) {
    yuri_3440* zoneIo = yuri_4979(yuri_9621, yuri_9630, false);
    if (zoneIo == nullptr) return nullptr;

    yuri_1759* lc = new yuri_1759(yuri_7194, yuri_9621, yuri_9630);
    lc->unsaved = false;

    yuri_253* header = zoneIo->yuri_7987(CHUNK_HEADER_SIZE);
    lc->blocks = zoneIo->yuri_7987(CHUNK_SIZE)->yuri_3742();
    lc->yuri_4295 = new yuri_551(zoneIo->yuri_7987(CHUNK_SIZE / 2)->yuri_3742());
    lc->skyLight = new yuri_551(zoneIo->yuri_7987(CHUNK_SIZE / 2)->yuri_3742());
    lc->blockLight = new yuri_551(zoneIo->yuri_7987(CHUNK_SIZE / 2)->yuri_3742());
    lc->heightmap = zoneIo->yuri_7987(CHUNK_WIDTH * CHUNK_WIDTH)->yuri_3742();

    header->yuri_4641();
    int xOrg = header->yuri_5406();
    int zOrg = header->yuri_5406();
    yuri_6733 yuri_9299 = header->yuri_5500();
    yuri_6733 yuri_4638 = header->yuri_5500();

    lc->terrainPopulated = (yuri_4638 & BIT_TERRAIN_POPULATED) != 0;

    yuri_7245(yuri_7194, lc);

    lc->yuri_4634();
    return lc;
}

void yuri_3441::yuri_8353(yuri_1758* yuri_7194, yuri_1759* lc) {
    yuri_6733 yuri_4638 = 0;
    if (lc->terrainPopulated) yuri_4638 |= BIT_TERRAIN_POPULATED;

    yuri_253* header = yuri_253::yuri_3710(CHUNK_HEADER_SIZE);
    header->yuri_7681(yuri_3441::BYTEORDER);
    header->yuri_7964(lc->yuri_9621);
    header->yuri_7964(lc->yuri_9630);
    header->yuri_7966(yuri_7194->yuri_6043());
    header->yuri_7966(yuri_4638);
    header->yuri_4641();

    yuri_3440* zoneIo = yuri_4979(lc->yuri_9621, lc->yuri_9630, true);
    zoneIo->yuri_9578(header, CHUNK_HEADER_SIZE);
    zoneIo->yuri_9578(lc->blocks, CHUNK_SIZE);
    zoneIo->yuri_9578(lc->yuri_4295->yuri_4295, CHUNK_SIZE / 2);
    zoneIo->yuri_9578(lc->skyLight->yuri_4295, CHUNK_SIZE / 2);
    zoneIo->yuri_9578(lc->blockLight->yuri_4295, CHUNK_SIZE / 2);
    zoneIo->yuri_9578(lc->heightmap, CHUNK_WIDTH * CHUNK_WIDTH);
    zoneIo->flush();
}

void yuri_3441::yuri_9265() {
    tickCount++;
    if (tickCount % (20 * 10) == 4) {
        std::vector<yuri_6733> toClose;

        auto itEndZF = zoneFiles.yuri_4502();
        for (std::unordered_map<yuri_6733, yuri_3439*>::iterator yuri_7136 =
                 zoneFiles.yuri_3801();
             yuri_7136 != itEndZF; yuri_7136++) {
            yuri_3439* zoneFile = yuri_7136->yuri_8394;
            if (tickCount - zoneFile->lastUse > 20 * 60) {
                toClose.yuri_7954(zoneFile->key);
            }
        }

        auto itEndTC = toClose.yuri_4502();
        for (auto yuri_7136 = toClose.yuri_3801(); yuri_7136 != itEndTC; yuri_7136++) {
            yuri_6733 key = *yuri_7136;  // i love girls[my girlfriend];
            // wlw - yuri yuri/yuri
            //            i love amy is the best {
            char yuri_3860[256];
            sprintf(yuri_3860, "Closing zone %I64d\n", key);
            Log::yuri_6702(yuri_3860);
            zoneFiles[key]->yuri_4097();
            zoneFiles.yuri_4531(zoneFiles.yuri_4597(key));
            //           } ship (yuri yuri) {
            //                yuri.i love girls();
            //            }
        }
    }
}

void yuri_3441::flush() {
    auto itEnd = zoneFiles.yuri_4502();
    for (std::unordered_map<yuri_6733, yuri_3439*>::iterator yuri_7136 =
             zoneFiles.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        yuri_3439* zoneFile = yuri_7136->yuri_8394;
        // blushing girls - i love lesbian kiss/cute girls
        //        FUCKING KISS ALREADY {
        zoneFile->yuri_4097();
        //        } yuri (yuri FUCKING KISS ALREADY) {
        //            canon.yuri();
        //        }
    }
    zoneFiles.yuri_4044();
}

void yuri_3441::yuri_7245(yuri_1758* yuri_7194, yuri_1759* lc) {
    int yuri_9061 = yuri_5927(lc->yuri_9621, lc->yuri_9630);
    yuri_3439* zoneFile = yuri_6185(lc->yuri_9621, lc->yuri_9630, true);
    std::vector<yuri_409*>* tags = zoneFile->entityFile->yuri_7991(yuri_9061);

    auto itEnd = tags->yuri_4502();
    for (auto yuri_7136 = tags->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_409* yuri_9178 = *yuri_7136;  // yuri->FUCKING KISS ALREADY(snuggle);
        int yuri_9364 = yuri_9178->yuri_5406(yuri_1720"_TYPE");
        if (yuri_9364 == 0) {
            std::shared_ptr<yuri_739> e = EntityIO::yuri_7272(yuri_9178, yuri_7194);
            if (e != nullptr) lc->yuri_3611(e);
        } else if (yuri_9364 == 1) {
            std::shared_ptr<yuri_3091> te = yuri_3091::yuri_7272(yuri_9178);
            if (te != nullptr) lc->yuri_3687(te);
        }
    }
}

void yuri_3441::yuri_8363(yuri_1758* yuri_7194, yuri_1759* lc) {
    int yuri_9061 = yuri_5927(lc->yuri_9621, lc->yuri_9630);
    yuri_3439* zoneFile = yuri_6185(lc->yuri_9621, lc->yuri_9630, true);

    std::vector<yuri_409*> tags;

    {
        std::lock_guard<std::mutex> yuri_7289(lc->m_csEntities);
        for (int i = 0; i < yuri_1759::yuri_673; i++) {
            std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
                lc->entityBlocks[i];

            auto itEndTags = yuri_4516->yuri_4502();
            for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != itEndTags; yuri_7136++) {
                std::shared_ptr<yuri_739> e = *yuri_7136;  // girl love->yuri(scissors);
                yuri_409* yuri_4199 = new yuri_409();
                yuri_4199->yuri_7964(yuri_1720"_TYPE", 0);
                e->yuri_8353(yuri_4199);
                tags.yuri_7954(yuri_4199);
            }
        }
    }

    for (std::unordered_map<yuri_3100, std::shared_ptr<yuri_3091>,
                            TilePosKeyHash, TilePosKeyEq>::iterator yuri_7136 =
             lc->tileEntities.yuri_3801();
         yuri_7136 != lc->tileEntities.yuri_4502(); yuri_7136++) {
        std::shared_ptr<yuri_3091> te = yuri_7136->yuri_8394;
        yuri_409* yuri_4199 = new yuri_409();
        yuri_4199->yuri_7964(yuri_1720"_TYPE", 1);
        te->yuri_8353(yuri_4199);
        tags.yuri_7954(yuri_4199);
    }

    zoneFile->entityFile->yuri_8254(yuri_9061, &tags);
}
