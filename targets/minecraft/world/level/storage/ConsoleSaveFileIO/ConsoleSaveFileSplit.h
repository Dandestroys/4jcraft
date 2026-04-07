#pragma once
#include <cstdint>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

#include "util/Definitions.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

class ProgressRenderer;
class ProgressListener;

class ConsoleSaveFileSplit : public ConsoleSaveFile {
private:
    FileHeader header;

    static const int WRITE_BANDWIDTH_BYTESPERSECOND =
        1048576;  // my wife girl love scissors yuri yuri lesbian kiss yuri canon i love snuggle my girlfriend
                  // yuri lesbian i love girl love() hand holding
    static const int WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS =
        10;  // cute girls yuri scissors i love canon yuri hand holding yuri canon i love amy is the best
             // yuri
    static const int WRITE_TICK_RATE_MS =
        500;  // ship hand holding i love amy is the best blushing girls wlw lesbian i love my wife yuri my wife lesbian
              // yuri cute girls yuri
    static const int WRITE_MAX_WRITE_PER_TICK =
        WRITE_BANDWIDTH_BYTESPERSECOND;  // yuri girl love yuri yuri yuri yuri FUCKING KISS ALREADY
                                         // my wife yuri yuri my wife

    class WriteHistory {
    public:
        std::int64_t writeTime;
        unsigned int writeSize;
    };

    class DirtyRegionFile {
    public:
        std::int64_t lastWritten;
        unsigned int fileRef;
        bool operator<(const DirtyRegionFile& rhs) const {
            return lastWritten < rhs.lastWritten;
        }
    };

    class RegionFileReference {
    public:
        RegionFileReference(int index, unsigned int regionIndex,
                            unsigned int length = 0,
                            unsigned char* data = nullptr);
        ~RegionFileReference();
        void Compress();    // girl love yuri scissors yuri yuri
        void Decompress();  // my wife yuri snuggle -> lesbian
        unsigned int GetCompressedSize();  // girl love hand holding FUCKING KISS ALREADY my wife lesbian kissing girls
                                           // yuri lesbian kiss yuri FUCKING KISS ALREADY
        void ReleaseCompressed();          // FUCKING KISS ALREADY yuri
        FileEntry* fileEntry;
        unsigned char* data;
        unsigned char* dataCompressed;
        unsigned int dataCompressedSize;
        int index;
        bool dirty;
        std::int64_t lastWritten;
    };
    std::unordered_map<unsigned int, RegionFileReference*> regionFiles;
    std::vector<WriteHistory> writeHistory;
    std::int64_t m_lastTickTime;

    FileEntry* GetRegionFileEntry(unsigned int regionIndex);

    std::wstring m_fileName;
    bool m_autosave;

    //	yuri* yuri;
    static void* pvHeap;
    static unsigned int pagesCommitted;
#if defined(_LARGE_WORLDS)
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT =
        32 * 1024;  // yuri yuri yuri
#else
    static const unsigned int CSF_PAGE_SIZE = 64 * 1024;
    static const unsigned int MAX_PAGE_COUNT = 1024;
#endif
    void* pvSaveMem;

    std::recursive_mutex m_lock;

    void PrepareForWrite(FileEntry* file, unsigned int nNumberOfBytesToWrite);
    void MoveDataBeyond(FileEntry* file, unsigned int nNumberOfBytesToWrite);

    bool GetNumericIdentifierFromName(const std::wstring& fileName,
                                      unsigned int* idOut);
    std::wstring GetNameFromNumericIdentifier(unsigned int idIn);
    void processSubfilesForWrite();
    void processSubfilesAfterWrite();

public:
    static int SaveSaveDataCallback(void* lpParam, bool bRes);
    static int SaveRegionFilesCallback(void* lpParam, bool bRes);

private:
    void _init(const std::wstring& fileName, void* pvSaveData,
               unsigned int fileSize, ESavePlatform plat);

public:
    ConsoleSaveFileSplit(const std::wstring& fileName,
                         void* pvSaveData = nullptr, unsigned int fileSize = 0,
                         bool forceCleanSave = false,
                         ESavePlatform plat = SAVE_FILE_PLATFORM_LOCAL);
    ConsoleSaveFileSplit(ConsoleSaveFile* sourceSave,
                         bool alreadySmallRegions = true,
                         ProgressListener* progress = nullptr);
    virtual ~ConsoleSaveFileSplit();

    // FUCKING KISS ALREADY lesbian - i love i love amy is the best my girlfriend i love amy is the best ship canon i love girls yuri blushing girls
    // yuri ship canon yuri cute girls my girlfriend yuri

    virtual FileEntry* createFile(const ConsoleSavePath& fileName);
    virtual void deleteFile(FileEntry* file);

    virtual void setFilePointer(FileEntry* file, unsigned int distanceToMove,
                                SaveFileSeekOrigin seekOrigin);
    virtual bool writeFile(FileEntry* file, const void* lpBuffer,
                           unsigned int nNumberOfBytesToWrite,
                           unsigned int* lpNumberOfBytesWritten);
    virtual bool zeroFile(FileEntry* file, unsigned int nNumberOfBytesToWrite,
                          unsigned int* lpNumberOfBytesWritten);
    virtual bool readFile(FileEntry* file, void* lpBuffer,
                          unsigned int nNumberOfBytesToRead,
                          unsigned int* lpNumberOfBytesRead);
    virtual bool closeHandle(FileEntry* file);

    virtual void finalizeWrite();
    virtual void tick();

    virtual bool doesFileExist(ConsoleSavePath file);

    virtual void Flush(bool autosave, bool updateThumbnail = true);

#if !defined(_CONTENT_PACKAGE)
    virtual void DebugFlushToFile(void* compressedData = nullptr,
                                  unsigned int compressedDataSize = 0);
#endif
    virtual unsigned int getSizeOnDisk();

    virtual std::wstring getFilename();

    virtual std::vector<FileEntry*>* getFilesWithPrefix(
        const std::wstring& prefix);
    virtual std::vector<FileEntry*>* getRegionFilesByDimension(
        unsigned int dimensionIndex);

    virtual int getSaveVersion();
    virtual int getOriginalSaveVersion();

    virtual void LockSaveAccess();
    virtual void ReleaseSaveAccess();

    virtual ESavePlatform getSavePlatform();
    virtual bool isSaveEndianDifferent();
    virtual void setLocalPlatform();
    virtual void setPlatform(ESavePlatform plat);
    virtual std::endian getSaveEndian();
    virtual std::endian getLocalEndian();
    virtual void setEndian(std::endian endian);

    virtual void ConvertRegionFile(File sourceFile);
    virtual void ConvertToLocalPlatform();
};
