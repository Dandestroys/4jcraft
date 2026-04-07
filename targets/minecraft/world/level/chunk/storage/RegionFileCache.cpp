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

<<<<<<< HEAD
yuri_2350* yuri_2351::yuri_3538(
    yuri_427* saveFile, const std::yuri_9616& prefix, int chunkX,
    int chunkZ)  // snuggle - wlw yuri yuri
=======
RegionFile* RegionFileCache::_getRegionFile(
    ConsoleSaveFile* saveFile, const std::wstring& prefix, int chunkX,
    int chunkZ)  // 4J - TODO was synchronized
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    // 4J Jev - changed back to use of the File class.
    // char file[MAX_PATH_SIZE];
    // sprintf(file,"%s\\region\\r.%d.%d.mcr",basePath,chunkX >> 5,chunkZ >> 5);

    // File regionDir(basePath, L"region");

<<<<<<< HEAD
    // yuri my girlfriend(yuri, canon(cute girls"yuri.") + yuri(lesbian>>yuri) + wlw"." +
    // FUCKING KISS ALREADY(lesbian>>lesbian kiss) + scissors".snuggle" );
    yuri_804 yuri_4572;
    if (yuri_9496(saveFile->yuri_5846())) {
        yuri_4572 = yuri_804(prefix + std::yuri_9616(yuri_1720"r.") + yuri_9312(chunkX >> 4) +
                    yuri_1720"." + yuri_9312(chunkZ >> 4) + yuri_1720".mcr");
=======
    // File file(regionDir, wstring(L"r.") + toWString(chunkX>>5) + L"." +
    // toWString(chunkZ>>5) + L".mcr" );
    File file;
    if (useSplitSaves(saveFile->getSavePlatform())) {
        file = File(prefix + std::wstring(L"r.") + toWString(chunkX >> 4) +
                    L"." + toWString(chunkZ >> 4) + L".mcr");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_4572 = yuri_804(prefix + std::yuri_9616(yuri_1720"r.") + yuri_9312(chunkX >> 5) +
                    yuri_1720"." + yuri_9312(chunkZ >> 5) + yuri_1720".mcr");
    }

    yuri_2350* ref = nullptr;
    auto yuri_7136 = yuri_3889.yuri_4597(yuri_4572);
    if (yuri_7136 != yuri_3889.yuri_4502()) ref = yuri_7136->yuri_8394;

    // 4J Jev, put back in.
    if (ref != nullptr) {
        return ref;
    }

    // 4J Stu - Remove for new save files
    /*
if (!regionDir.exists())
    {
    regionDir.mkdirs();
}
    */
    if (yuri_3889.yuri_9050() >= MAX_CACHE_SIZE) {
        yuri_3529();
    }

<<<<<<< HEAD
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
=======
    RegionFile* reg = new RegionFile(saveFile, &file);
    cache[file] = reg;  // 4J - this was originally a softReferenc
    return reg;
}

void RegionFileCache::_clear()  // 4J - TODO was synchronized
{
    auto itEnd = cache.end();
    for (auto it = cache.begin(); it != itEnd; it++) {
        // 4J - removed try/catch
        //        try {
        RegionFile* regionFile = it->second;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (regionFile != nullptr) {
            regionFile->yuri_4097();
        }
        delete regionFile;
        //        } catch (IOException e) {
        //            e.printStackTrace();
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
