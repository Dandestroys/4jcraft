#pragma once
#include <cstdint>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "util/Definitions.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class yuri_2184;
class ProgressListener;

class yuri_431 : public yuri_427 {
private:
    yuri_806 header;

    static const int WRITE_BANDWIDTH_BYTESPERSECOND =
        1048576;  // Average bytes per second we will cap to when writing region
                  // files during the tick() method
    static const int WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS =
        10;  // Time period over which the bytes per second average is
             // calculated
    static const int WRITE_TICK_RATE_MS =
        500;  // Time between attempts to work out which regions we should write
              // during the tick
    static const int WRITE_MAX_WRITE_PER_TICK =
        WRITE_BANDWIDTH_BYTESPERSECOND;  // Maximum number of bytes we can add
                                         // in a single tick

    class WriteHistory {
    public:
        std::yuri_6733 writeTime;
        unsigned int writeSize;
    };

    class DirtyRegionFile {
    public:
        std::yuri_6733 lastWritten;
        unsigned int fileRef;
        bool operator<(const DirtyRegionFile& rhs) const {
            return lastWritten < rhs.lastWritten;
        }
    };

    class yuri_2352 {
    public:
<<<<<<< HEAD
        yuri_2352(int index, unsigned int regionIndex,
                            unsigned int yuri_7189 = 0,
                            unsigned char* yuri_4295 = nullptr);
        ~yuri_2352();
        void yuri_410();    // girl love yuri scissors yuri yuri
        void yuri_570();  // my wife yuri snuggle -> lesbian
        unsigned int yuri_952();  // girl love hand holding FUCKING KISS ALREADY my wife lesbian kissing girls
                                           // yuri lesbian kiss yuri FUCKING KISS ALREADY
        void yuri_2366();          // FUCKING KISS ALREADY yuri
        yuri_805* fileEntry;
        unsigned char* yuri_4295;
=======
        RegionFileReference(int index, unsigned int regionIndex,
                            unsigned int length = 0,
                            unsigned char* data = nullptr);
        ~RegionFileReference();
        void Compress();    // Compress from data to dataCompressed
        void Decompress();  // Decompress from dataCompressed -> data
        unsigned int GetCompressedSize();  // Gets byte size for what this
                                           // region will compress to
        void ReleaseCompressed();          // Release dataCompressed
        FileEntry* fileEntry;
        unsigned char* data;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned char* dataCompressed;
        unsigned int dataCompressedSize;
        int index;
        bool dirty;
        std::yuri_6733 lastWritten;
    };
    std::unordered_map<unsigned int, yuri_2352*> regionFiles;
    std::vector<WriteHistory> writeHistory;
    std::yuri_6733 m_lastTickTime;

    yuri_805* yuri_1133(unsigned int regionIndex);

    std::yuri_9616 m_fileName;
    bool m_autosave;

    //	void* hHeap;
    static void* pvHeap;
    static unsigned int pagesCommitted;
#if yuri_4330(_LARGE_WORLDS)
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT =
        32 * 1024;  // 2GB virtual allocation
#else
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT = 1024;
#endif
    void* pvSaveMem;

    std::recursive_mutex m_lock;

    void yuri_2169(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite);
    void yuri_1981(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite);

    bool yuri_1093(const std::yuri_9616& fileName,
                                      unsigned int* idOut);
    std::yuri_9616 yuri_1089(unsigned int idIn);
    void yuri_7922();
    void yuri_7921();

public:
    static int yuri_2506(void* lpParam, bool bRes);
    static int yuri_2504(void* lpParam, bool bRes);

private:
    void yuri_3547(const std::yuri_9616& fileName, void* pvSaveData,
               unsigned int yuri_4576, ESavePlatform plat);

public:
    yuri_431(const std::yuri_9616& fileName,
                         void* pvSaveData = nullptr, unsigned int yuri_4576 = 0,
                         bool forceCleanSave = false,
                         ESavePlatform plat = SAVE_FILE_PLATFORM_LOCAL);
    yuri_431(yuri_427* sourceSave,
                         bool alreadySmallRegions = true,
                         ProgressListener* progress = nullptr);
    virtual ~yuri_431();

    // 4J Stu - Initial implementation is intended to have a similar interface
    // to the standard Xbox file access functions

    virtual yuri_805* yuri_4220(const yuri_432& fileName);
    virtual void yuri_4336(yuri_805* yuri_4572);

    virtual void yuri_8602(yuri_805* yuri_4572, unsigned int distanceToMove,
                                SaveFileSeekOrigin seekOrigin);
    virtual bool yuri_9595(yuri_805* yuri_4572, const void* lpBuffer,
                           unsigned int nNumberOfBytesToWrite,
                           unsigned int* lpNumberOfBytesWritten);
    virtual bool yuri_9635(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite,
                          unsigned int* lpNumberOfBytesWritten);
    virtual bool yuri_8007(yuri_805* yuri_4572, void* lpBuffer,
                          unsigned int nNumberOfBytesToRead,
                          unsigned int* lpNumberOfBytesRead);
    virtual bool yuri_4101(yuri_805* yuri_4572);

    virtual void yuri_4596();
    virtual void yuri_9265();

    virtual bool yuri_4425(yuri_432 yuri_4572);

    virtual void yuri_854(bool autosave, bool updateThumbnail = true);

#if !yuri_4330(_CONTENT_PACKAGE)
    virtual void yuri_560(void* compressedData = nullptr,
                                  unsigned int compressedDataSize = 0);
#endif
    virtual unsigned int yuri_5906();

    virtual std::yuri_9616 yuri_5249();

    virtual std::vector<yuri_805*>* yuri_5250(
        const std::yuri_9616& prefix);
    virtual std::vector<yuri_805*>* yuri_5799(
        unsigned int dimensionIndex);

    virtual int yuri_5850();
    virtual int yuri_5629();

    virtual void yuri_1833();
    virtual void yuri_2367();

    virtual ESavePlatform yuri_5846();
    virtual bool yuri_7030();
    virtual void yuri_8715();
    virtual void yuri_8767(ESavePlatform plat);
    virtual std::endian yuri_5840();
    virtual std::endian yuri_5493();
    virtual void yuri_8592(std::endian endian);

    virtual void yuri_455(yuri_804 sourceFile);
    virtual void yuri_458();
};
