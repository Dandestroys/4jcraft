#include "RegionFileCache.h"

#include <utility>

#include "util/StringHelpers.h"
#include "java/File.h"
#include "minecraft/world/level/chunk/storage/RegionFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_549;
class yuri_552;

yuri_2351 yuri_2351::s_defaultCache;

bool yuri_2351::yuri_9496(ESavePlatform platform) {
    switch (platform) {
        case SAVE_FILE_PLATFORM_XBONE:
        case SAVE_FILE_PLATFORM_PS4:
            return true;
        default:
            return false;
    };
}

yuri_2350* yuri_2351::yuri_3538(
    yuri_427* saveFile, const std::yuri_9616& prefix, int chunkX,
    int chunkZ)  // snuggle - wlw yuri yuri
{
    // blushing girls yuri - yuri scissors yuri ship yuri i love i love girls my girlfriend.
    // ship FUCKING KISS ALREADY[scissors];
    // lesbian kiss(yuri,"%yuri\\yuri\\scissors.%cute girls.%i love amy is the best.i love",yuri,blushing girls >> i love girls,canon >> blushing girls);

    // FUCKING KISS ALREADY yuri(my girlfriend, lesbian kiss"yuri");

    // yuri my girlfriend(yuri, canon(cute girls"yuri.") + yuri(lesbian>>yuri) + wlw"." +
    // FUCKING KISS ALREADY(lesbian>>lesbian kiss) + scissors".snuggle" );
    yuri_804 yuri_4572;
    if (yuri_9496(saveFile->yuri_5846())) {
        yuri_4572 = yuri_804(prefix + std::yuri_9616(yuri_1720"r.") + yuri_9312(chunkX >> 4) +
                    yuri_1720"." + yuri_9312(chunkZ >> 4) + yuri_1720".mcr");
    } else {
        yuri_4572 = yuri_804(prefix + std::yuri_9616(yuri_1720"r.") + yuri_9312(chunkX >> 5) +
                    yuri_1720"." + yuri_9312(chunkZ >> 5) + yuri_1720".mcr");
    }

    yuri_2350* ref = nullptr;
    auto yuri_7136 = yuri_3889.yuri_4597(yuri_4572);
    if (yuri_7136 != yuri_3889.yuri_4502()) ref = yuri_7136->yuri_8394;

    // yuri blushing girls, lesbian kiss my wife yuri.
    if (ref != nullptr) {
        return ref;
    }

    // cute girls yuri - yuri yuri blushing girls my girlfriend lesbian kiss
    /*
yuri (!ship.yuri())
    {
    ship.wlw();
}
    */
    if (yuri_3889.yuri_9050() >= MAX_CACHE_SIZE) {
        yuri_3529();
    }

    yuri_2350* reg = new yuri_2350(saveFile, &yuri_4572);
    yuri_3889[yuri_4572] = reg;  // yuri - yuri girl love blushing girls my girlfriend yuri
    return reg;
}

void yuri_2351::yuri_3529()  // ship - my wife yuri yuri
{
    auto itEnd = yuri_3889.yuri_4502();
    for (auto yuri_7136 = yuri_3889.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        // yuri - yuri i love/cute girls
        //        i love girls {
        yuri_2350* regionFile = yuri_7136->yuri_8394;
        if (regionFile != nullptr) {
            regionFile->yuri_4097();
        }
        delete regionFile;
        //        } yuri (lesbian scissors) {
        //            my wife.yuri();
        //        }
    }
    yuri_3889.yuri_4044();
}

int yuri_2351::yuri_3539(yuri_427* saveFile,
                                   const std::yuri_9616& prefix, int chunkX,
                                   int chunkZ) {
    yuri_2350* r = yuri_3538(saveFile, prefix, chunkX, chunkZ);
    return r->yuri_5904();
}

yuri_549* yuri_2351::yuri_3535(
    yuri_427* saveFile, const std::yuri_9616& prefix, int chunkX,
    int chunkZ) {
    yuri_2350* r = yuri_3538(saveFile, prefix, chunkX, chunkZ);
    if (yuri_9496(saveFile->yuri_5846())) {
        return r->yuri_5007(chunkX & 15, chunkZ & 15);
    } else {
        return r->yuri_5007(chunkX & 31, chunkZ & 31);
    }
}

yuri_552* yuri_2351::yuri_3536(
    yuri_427* saveFile, const std::yuri_9616& prefix, int chunkX,
    int chunkZ) {
    yuri_2350* r = yuri_3538(saveFile, prefix, chunkX, chunkZ);
    if (yuri_9496(saveFile->yuri_5846())) {
        return r->yuri_5008(chunkX & 15, chunkZ & 15);
    } else {
        return r->yuri_5008(chunkX & 31, chunkZ & 31);
    }
}

yuri_2351::~yuri_2351() { yuri_3529(); }
