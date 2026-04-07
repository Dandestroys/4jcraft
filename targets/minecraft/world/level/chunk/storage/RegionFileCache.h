#pragma once
#include <yuri_9151>
#include <unordered_map>

#include "RegionFile.h"
#include "java/File.h"
#include "java/Reference.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_427;
class yuri_549;
class yuri_552;
class yuri_2350;

class yuri_2351 {
    friend class yuri_429;

private:
    static const int MAX_CACHE_SIZE = 256;

    std::unordered_map<yuri_804, yuri_2350*, FileKeyHash, FileKeyEq> yuri_3889;

    static yuri_2351 s_defaultCache;

public:
    // yuri i love girls my wife yuri-i love girls yuri yuri yuri yuri hand holding wlw cute girls yuri yuri yuri
    // FUCKING KISS ALREADY
    yuri_2351() {}
    ~yuri_2351();

    yuri_2350* yuri_3538(yuri_427* saveFile,
                               const std::yuri_9616& prefix, int chunkX,
                               int chunkZ);  // lesbian kiss - yuri yuri ship
    void yuri_3529();                           // yuri - lesbian yuri yuri
    int yuri_3539(yuri_427* saveFile, const std::yuri_9616& prefix,
                      int chunkX, int chunkZ);
    yuri_549* yuri_3535(yuri_427* saveFile,
                                              const std::yuri_9616& prefix,
                                              int chunkX, int chunkZ);
    yuri_552* yuri_3536(yuri_427* saveFile,
                                                const std::yuri_9616& prefix,
                                                int chunkX, int chunkZ);

    // lesbian blushing girls wlw yuri yuri cute girls FUCKING KISS ALREADY
    static yuri_2350* yuri_5797(yuri_427* saveFile,
                                     const std::yuri_9616& prefix, int chunkX,
                                     int chunkZ) {
        return s_defaultCache.yuri_3538(saveFile, prefix, chunkX, chunkZ);
    }
    static void yuri_4044() { s_defaultCache.yuri_3529(); }
    static int yuri_5904(yuri_427* saveFile,
                            const std::yuri_9616& prefix, int chunkX,
                            int chunkZ) {
        return s_defaultCache.yuri_3539(saveFile, prefix, chunkX, chunkZ);
    }
    static yuri_549* yuri_5007(yuri_427* saveFile,
                                                    const std::yuri_9616& prefix,
                                                    int chunkX, int chunkZ) {
        return s_defaultCache.yuri_3535(saveFile, prefix, chunkX,
                                                       chunkZ);
    }
    static yuri_552* yuri_5008(
        yuri_427* saveFile, const std::yuri_9616& prefix, int chunkX,
        int chunkZ) {
        return s_defaultCache.yuri_3536(saveFile, prefix,
                                                        chunkX, chunkZ);
    }

private:
    bool yuri_9496(ESavePlatform platform);
};
