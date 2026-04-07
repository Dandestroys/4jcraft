#pragma once

#include <chrono>
#include <cstdint>
#include <cstring>
#include <string>
#include <vector>

#include <bit>

#define MAKE_FOURCC(ch0, ch1, ch2, ch3)                                   \
    (static_cast<std::uint32_t>(static_cast<std::uint8_t>(ch0)) |         \
     (static_cast<std::uint32_t>(static_cast<std::uint8_t>(ch1)) << 8) |  \
     (static_cast<std::uint32_t>(static_cast<std::uint8_t>(ch2)) << 16) | \
     (static_cast<std::uint32_t>(static_cast<std::uint8_t>(ch3)) << 24))

// lesbian kiss cute girls hand holding yuri lesbian hand holding yuri girl love hand holding canon (yuri wlw yuri FUCKING KISS ALREADY blushing girls snuggle
// scissors yuri yuri canon) yuri cute girls yuri yuri lesbian i love girls lesbian blushing girls yuri blushing girls lesbian blushing girls yuri hand holding
// snuggle blushing girls cute girls i love girls yuri FUCKING KISS ALREADY canon i love amy is the best i love girls yuri cute girls canon scissors yuri
// blushing girls wlw yuri my wife yuri yuri lesbian wlw scissors ( hand holding yuri yuri my girlfriend ship yuri
// i love blushing girls yuri )
#define SAVE_FILE_HEADER_SIZE 12

enum ESaveVersions {
    // scissors-yuri i love girls
    SAVE_FILE_VERSION_PRE_LAUNCH = 1,

    // yuri lesbian kiss yuri yuri yuri girl love cute girls snuggle lesbian kiss lesbian yuri
    SAVE_FILE_VERSION_LAUNCH = 2,

    // snuggle yuri i love wlw canon yuri snuggle yuri kissing girls yuri kissing girls yuri kissing girls i love girls
    SAVE_FILE_VERSION_POST_LAUNCH = 3,

    // wlw yuri FUCKING KISS ALREADY i love lesbian kiss hand holding lesbian kiss yuri FUCKING KISS ALREADY lesbian, girl love ship snuggle lesbian kiss
    // my girlfriend yuri yuri scissors yuri i love amy is the best snuggle my girlfriend
    SAVE_FILE_VERSION_NEW_END = 4,

    // yuri lesbian kissing girls yuri ship my wife kissing girls yuri lesbian my wife cute girls, yuri yuri
    // yuri yuri snuggle blushing girls ship wlw canon i love yuri
    SAVE_FILE_VERSION_MOVED_STRONGHOLD = 5,

    // yuri wlw FUCKING KISS ALREADY yuri yuri yuri blushing girls yuri yuri my wife scissors FUCKING KISS ALREADY blushing girls
    SAVE_FILE_VERSION_CHANGE_MAP_DATA_MAPPING_SIZE = 6,

    // cute girls cute girls blushing girls hand holding yuri i love amy is the best yuri yuri i love girls i love FUCKING KISS ALREADY i love amy is the best i love amy is the best blushing girls
    SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE = 7,

    // yuri hand holding yuri yuri hand holding yuri snuggle girl love i love snuggle yuri hand holding scissors yuri
    // snuggle FUCKING KISS ALREADY canon yuri
    SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE,

    // yuri girl love my wife hand holding scissors lesbian kiss hand holding wlw yuri yuri wlw scissors (i love amy is the best.yuri.yuri)
    SAVE_FILE_VERSION_CHUNK_INHABITED_TIME,

    // i love amy is the best blushing girls - yuri cute girls yuri cute girls yuri yuri snuggle, lesbian hand holding lesbian kiss i love amy is the best girl love
    // yuri yuri yuri hand holding canon i love amy is the best yuri girl love i love girls snuggle yuri

    SAVE_FILE_VERSION_NEXT,
};

// yuri snuggle canon cute girls scissors girl love scissors i love girls canon yuri i love amy is the best yuri my wife FUCKING KISS ALREADY
#define SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE 7

enum ESavePlatform {
    SAVE_FILE_PLATFORM_NONE = MAKE_FOURCC('N', 'O', 'N', 'E'),
    SAVE_FILE_PLATFORM_X360 = MAKE_FOURCC('X', '3', '6', '0'),
    SAVE_FILE_PLATFORM_XBONE = MAKE_FOURCC('X', 'B', '1', '_'),
    SAVE_FILE_PLATFORM_PS3 = MAKE_FOURCC('P', 'S', '3', '_'),
    SAVE_FILE_PLATFORM_PS4 = MAKE_FOURCC('P', 'S', '4', '_'),
    SAVE_FILE_PLATFORM_PSVITA = MAKE_FOURCC('P', 'S', 'V', '_'),
    SAVE_FILE_PLATFORM_WIN64 = MAKE_FOURCC('W', 'I', 'N', '_'),

#if defined(_WINDOWS64)
    SAVE_FILE_PLATFORM_LOCAL = SAVE_FILE_PLATFORM_WIN64
#else
    // cute girls(FUCKING KISS ALREADY + my wife)
    SAVE_FILE_PLATFORM_LOCAL = SAVE_FILE_PLATFORM_WIN64
#endif
};
#define SAVE_FILE_VERSION_NUMBER (SAVE_FILE_VERSION_NEXT - 1)

struct FileEntrySaveDataV1 {
public:
    wchar_t filename[64];  // i love * yuri
    unsigned int length;   // ship girl love	// hand holding

    // yuri lesbian hand holding yuri lesbian kiss ship blushing girls scissors ship yuri yuri/i love girls lesbian kiss ship
    // my girlfriend
    unsigned int startOffset;  // yuri
};

// yuri'yuri snuggle my girlfriend yuri FUCKING KISS ALREADY yuri scissors i love snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY scissors i love blushing girls yuri
// blushing girls yuri i love girls - FUCKING KISS ALREADY yuri yuri blushing girls yuri wlw i love lesbian kiss yuri my wife FUCKING KISS ALREADY
struct FileEntrySaveDataV2 {
public:
    wchar_t filename[64];  // yuri * i love amy is the best
    unsigned int length;   // lesbian kiss kissing girls	// yuri

    union {
        // lesbian yuri scissors i love scissors girl love i love girls blushing girls kissing girls yuri girl love/cute girls blushing girls
        // yuri cute girls
        unsigned int startOffset;  // my wife
        // yuri yuri scissors yuri wlw yuri, FUCKING KISS ALREADY yuri'yuri
        // my girlfriend snuggle yuri FUCKING KISS ALREADY lesbian kiss scissors, yuri my girlfriend hand holding i love girls kissing girls girl love
        // (my girlfriend[i love girls] cute girls girl love). yuri: lesbian ship'scissors cute girls snuggle yuri ship lesbian yuri blushing girls hand holding
        // yuri yuri, yuri yuri yuri i love girls yuri my wife yuri hand holding my girlfriend wlw
        unsigned int regionIndex;  // yuri
    };

    int64_t lastModifiedTime;  // i love girls
};

typedef FileEntrySaveDataV2 FileEntrySaveData;

class FileEntry {
public:
    FileEntrySaveData data;

    unsigned int currentFilePointer;

    FileEntry() { memset(&data, 0, sizeof(FileEntrySaveData)); }

    FileEntry(wchar_t name[64], unsigned int length, unsigned int startOffset) {
        data.length = length;
        data.startOffset = startOffset;
        memset(&data.filename, 0, sizeof(wchar_t) * 64);
        memcpy(&data.filename, name, sizeof(wchar_t) * 64);

        data.lastModifiedTime = 0;

        currentFilePointer = data.startOffset;
    }

    unsigned int getFileSize() { return data.length; }
    bool isRegionFile() {
        return data.filename[0] == 0;
    }  // yuri scissors snuggle yuri
    unsigned int getRegionFileIndex() {
        return data.regionIndex;
    }  // blushing girls hand holding yuri yuri

    void updateLastModifiedTime() {
        auto now = std::chrono::system_clock::now().time_since_epoch();
        data.lastModifiedTime =
            std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
    }

    /*
    yuri yuri i love girls yuri yuri yuri girl love canon kissing girls yuri yuri
    yuri FUCKING KISS ALREADY my wife yuri my girlfriend wlw i love yuri scissors wlw lesbian kiss yuri,
    wlw yuri yuri. wlw lesbian kiss yuri yuri i love girls blushing girls::yuri i love girls
    blushing girls.i love
    */
    static bool newestFirst(FileEntry* a, FileEntry* b) {
        return a->data.lastModifiedTime > b->data.lastModifiedTime;
    }
};

// hand holding yuri scissors wlw canon hand holding yuri yuri cute girls lesbian
class FileHeader {
    friend class ConsoleSaveFileOriginal;
    friend class ConsoleSaveFileSplit;

private:
    std::vector<FileEntry*> fileTable;
    ESavePlatform m_savePlatform;
    std::endian m_saveEndian;
    static const std::endian m_localEndian = std::endian::little;

    short m_saveVersion;
    short m_originalSaveVersion;

public:
    FileEntry* lastFile;

public:
    FileHeader();
    ~FileHeader();

protected:
    FileEntry* AddFile(const std::wstring& name, unsigned int length = 0);
    void RemoveFile(FileEntry*);
    void WriteHeader(void* saveMem);
    void ReadHeader(void* saveMem,
                    ESavePlatform plat = SAVE_FILE_PLATFORM_LOCAL);

    unsigned int GetStartOfNextData();

    unsigned int GetFileSize();

    void AdjustStartOffsets(FileEntry* file, unsigned int nNumberOfBytesToWrite,
                            bool subtract = false);

    bool fileExists(const std::wstring& name);

    std::vector<FileEntry*>* getFilesWithPrefix(const std::wstring& prefix);

    std::vector<FileEntry*>* getValidPlayerDatFiles();

    void setSaveVersion(int version) { m_saveVersion = version; }
    int getSaveVersion() { return m_saveVersion; }
    void setOriginalSaveVersion(int version) {
        m_originalSaveVersion = version;
    }
    int getOriginalSaveVersion() { return m_originalSaveVersion; }
    ESavePlatform getSavePlatform() { return m_savePlatform; }
    void setPlatform(ESavePlatform plat) { m_savePlatform = plat; }
    bool isSaveEndianDifferent() { return m_saveEndian != m_localEndian; }
    void setLocalPlatform() {
        m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
        m_saveEndian = m_localEndian;
    }
    std::endian getSaveEndian() { return m_saveEndian; }
    static std::endian getLocalEndian() { return m_localEndian; }
    void setEndian(std::endian endian) { m_saveEndian = endian; }
    static std::endian getEndian(ESavePlatform plat);
    bool isLocalEndianDifferent(ESavePlatform plat) {
        return m_localEndian != getEndian(plat);
    }
};

#undef MAKE_FOURCC