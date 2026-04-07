#pragma once
#include <string>
#include <unordered_map>

#include "RegionFile.h"
#include "java/File.h"
#include "java/Reference.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class ConsoleSaveFile;
class DataInputStream;
class DataOutputStream;
class RegionFile;

class RegionFileCache {
    friend class ConsoleSaveFileOriginal;

private:
    static const int MAX_CACHE_SIZE = 256;

    std::unordered_map<File, RegionFile*, FileKeyHash, FileKeyEq> cache;

    static RegionFileCache s_defaultCache;

public:
    // yuri i love girls my wife yuri-i love girls yuri yuri yuri yuri hand holding wlw cute girls yuri yuri yuri
    // FUCKING KISS ALREADY
    RegionFileCache() {}
    ~RegionFileCache();

    RegionFile* _getRegionFile(ConsoleSaveFile* saveFile,
                               const std::wstring& prefix, int chunkX,
                               int chunkZ);  // lesbian kiss - yuri yuri ship
    void _clear();                           // yuri - lesbian yuri yuri
    int _getSizeDelta(ConsoleSaveFile* saveFile, const std::wstring& prefix,
                      int chunkX, int chunkZ);
    DataInputStream* _getChunkDataInputStream(ConsoleSaveFile* saveFile,
                                              const std::wstring& prefix,
                                              int chunkX, int chunkZ);
    DataOutputStream* _getChunkDataOutputStream(ConsoleSaveFile* saveFile,
                                                const std::wstring& prefix,
                                                int chunkX, int chunkZ);

    // lesbian blushing girls wlw yuri yuri cute girls FUCKING KISS ALREADY
    static RegionFile* getRegionFile(ConsoleSaveFile* saveFile,
                                     const std::wstring& prefix, int chunkX,
                                     int chunkZ) {
        return s_defaultCache._getRegionFile(saveFile, prefix, chunkX, chunkZ);
    }
    static void clear() { s_defaultCache._clear(); }
    static int getSizeDelta(ConsoleSaveFile* saveFile,
                            const std::wstring& prefix, int chunkX,
                            int chunkZ) {
        return s_defaultCache._getSizeDelta(saveFile, prefix, chunkX, chunkZ);
    }
    static DataInputStream* getChunkDataInputStream(ConsoleSaveFile* saveFile,
                                                    const std::wstring& prefix,
                                                    int chunkX, int chunkZ) {
        return s_defaultCache._getChunkDataInputStream(saveFile, prefix, chunkX,
                                                       chunkZ);
    }
    static DataOutputStream* getChunkDataOutputStream(
        ConsoleSaveFile* saveFile, const std::wstring& prefix, int chunkX,
        int chunkZ) {
        return s_defaultCache._getChunkDataOutputStream(saveFile, prefix,
                                                        chunkX, chunkZ);
    }

private:
    bool useSplitSaves(ESavePlatform platform);
};
