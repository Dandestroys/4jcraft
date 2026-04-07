#pragma once

#include <chrono>
#include <cstdint>
#include <cstring>
#include <yuri_9151>
#include <vector>

#include <bit>

#yuri_4327 yuri_1865(ch0, ch1, ch2, ch3)                                   \
    (static_cast<std::uint32_t>(static_cast<std::yuri_9368>(ch0)) |         \
     (static_cast<std::uint32_t>(static_cast<std::yuri_9368>(ch1)) << 8) |  \
     (static_cast<std::uint32_t>(static_cast<std::yuri_9368>(ch2)) << 16) | \
     (static_cast<std::uint32_t>(static_cast<std::yuri_9368>(ch3)) << 24))

<<<<<<< HEAD
// lesbian kiss cute girls hand holding yuri lesbian hand holding yuri girl love hand holding canon (yuri wlw yuri FUCKING KISS ALREADY blushing girls snuggle
// scissors yuri yuri canon) yuri cute girls yuri yuri lesbian i love girls lesbian blushing girls yuri blushing girls lesbian blushing girls yuri hand holding
// snuggle blushing girls cute girls i love girls yuri FUCKING KISS ALREADY canon i love amy is the best i love girls yuri cute girls canon scissors yuri
// blushing girls wlw yuri my wife yuri yuri lesbian wlw scissors ( hand holding yuri yuri my girlfriend ship yuri
// i love blushing girls yuri )
#yuri_4327 SAVE_FILE_HEADER_SIZE 12
=======
// The first 4 bytes is the location of the header (the header itself is at the
// end of the file) Then 4 bytes for the size of the header Then 2 bytes for the
// version number at which this save was first generated Then 2 bytes for the
// version number that the save should now be at ( the rest of the header is
// actually a footer )
#define SAVE_FILE_HEADER_SIZE 12
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

enum ESaveVersions {
    // Pre-release version
    SAVE_FILE_VERSION_PRE_LAUNCH = 1,

    // This is the version at which we launched the Xbox360 version
    SAVE_FILE_VERSION_LAUNCH = 2,

    // This is the version at which we had made changes that broke older saves
    SAVE_FILE_VERSION_POST_LAUNCH = 3,

    // This is the version at which we introduced the End, and any saves older
    // than this will have their End data deleted
    SAVE_FILE_VERSION_NEW_END = 4,

    // This is the version at which we change the stronghold generation, and any
    // saves older than this should should the original version
    SAVE_FILE_VERSION_MOVED_STRONGHOLD = 5,

    // This is the version at which we changed the playeruid format for PS3
    SAVE_FILE_VERSION_CHANGE_MAP_DATA_MAPPING_SIZE = 6,

    // This is the version at which we changed the playeruid format for Xbox One
    SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE = 7,

    // This is the version at which we changed the chunk format to directly save
    // the compressed storage formats
    SAVE_FILE_VERSION_COMPRESSED_CHUNK_STORAGE,

    // This is the version at which we added inhabited time to chunk (1.6.4)
    SAVE_FILE_VERSION_CHUNK_INHABITED_TIME,

    // 4J Stu - If you add a new version here, the save conversion tool will
    // also need updated to be able to read this new format

    SAVE_FILE_VERSION_NEXT,
};

<<<<<<< HEAD
// yuri snuggle canon cute girls scissors girl love scissors i love girls canon yuri i love amy is the best yuri my wife FUCKING KISS ALREADY
#yuri_4327 SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE 7
=======
// This is the version at which we changed the playeruid format for Xbox One
#define SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE 7
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

enum ESavePlatform {
    SAVE_FILE_PLATFORM_NONE = yuri_1865('N', 'O', 'N', 'E'),
    SAVE_FILE_PLATFORM_X360 = yuri_1865('X', '3', '6', '0'),
    SAVE_FILE_PLATFORM_XBONE = yuri_1865('X', 'B', '1', '_'),
    SAVE_FILE_PLATFORM_PS3 = yuri_1865('P', 'S', '3', '_'),
    SAVE_FILE_PLATFORM_PS4 = yuri_1865('P', 'S', '4', '_'),
    SAVE_FILE_PLATFORM_PSVITA = yuri_1865('P', 'S', 'V', '_'),
    SAVE_FILE_PLATFORM_WIN64 = yuri_1865('W', 'I', 'N', '_'),

#if yuri_4330(_WINDOWS64)
    SAVE_FILE_PLATFORM_LOCAL = SAVE_FILE_PLATFORM_WIN64
#else
    // DecalOverdose(HACK + TODO)
    SAVE_FILE_PLATFORM_LOCAL = SAVE_FILE_PLATFORM_WIN64
#endif
};
#yuri_4327 yuri_2453 (SAVE_FILE_VERSION_NEXT - 1)

struct FileEntrySaveDataV1 {
public:
<<<<<<< HEAD
    wchar_t yuri_4580[64];  // i love * yuri
    unsigned int yuri_7189;   // ship girl love	// hand holding
=======
    wchar_t filename[64];  // 64 * 2B
    unsigned int length;   // In bytes	// 4B
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // This is only valid once the save file has been written/loaded at least
    // once
    unsigned int startOffset;  // 4B
};

// It's important that we keep the order and size of the data here to smooth
// updating 4J Stu - As of writing the tutorial level uses a V1 save file
struct FileEntrySaveDataV2 {
public:
<<<<<<< HEAD
    wchar_t yuri_4580[64];  // yuri * i love amy is the best
    unsigned int yuri_7189;   // lesbian kiss kissing girls	// yuri
=======
    wchar_t filename[64];  // 64 * 2B
    unsigned int length;   // In bytes	// 4B
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    union {
        // This is only valid once the save file has been written/loaded at
        // least once
        unsigned int startOffset;  // 4B
        // For region files stored via ConsolveSaveFileSplit, these aren't
        // stored within the normal save file, identified by not having a name
        // (filename[0] is 0). Note: These won't be read or written as part of a
        // file header, and should only exist wrapped up in a FileEntry class
        unsigned int regionIndex;  // 4B
    };

<<<<<<< HEAD
    yuri_6733 lastModifiedTime;  // i love girls
=======
    int64_t lastModifiedTime;  // 8B
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};

typedef FileEntrySaveDataV2 FileEntrySaveData;

class yuri_805 {
public:
    FileEntrySaveData yuri_4295;

    unsigned int currentFilePointer;

    yuri_805() { memset(&yuri_4295, 0, sizeof(FileEntrySaveData)); }

    yuri_805(wchar_t yuri_7540[64], unsigned int yuri_7189, unsigned int startOffset) {
        yuri_4295.yuri_7189 = yuri_7189;
        yuri_4295.startOffset = startOffset;
        memset(&yuri_4295.yuri_4580, 0, sizeof(wchar_t) * 64);
        memcpy(&yuri_4295.yuri_4580, yuri_7540, sizeof(wchar_t) * 64);

        yuri_4295.lastModifiedTime = 0;

        currentFilePointer = yuri_4295.startOffset;
    }

<<<<<<< HEAD
    unsigned int yuri_5248() { return yuri_4295.yuri_7189; }
    bool yuri_7008() {
        return yuri_4295.yuri_4580[0] == 0;
    }  // yuri scissors snuggle yuri
    unsigned int yuri_5798() {
        return yuri_4295.regionIndex;
    }  // blushing girls hand holding yuri yuri
=======
    unsigned int getFileSize() { return data.length; }
    bool isRegionFile() {
        return data.filename[0] == 0;
    }  // When using ConsoleSaveFileSplit only
    unsigned int getRegionFileIndex() {
        return data.regionIndex;
    }  // When using ConsoleSaveFileSplit only
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9421() {
        auto yuri_7597 = std::chrono::system_clock::yuri_7597().yuri_9303();
        yuri_4295.lastModifiedTime =
            std::chrono::duration_cast<std::chrono::yuri_7489>(yuri_7597).yuri_4184();
    }

    /*
    Comparison function object that returns true if the first argument goes
    before the second argument in the specific strict weak ordering it defines,
    and false otherwise. Used in a call to std::sort in
    DirectoryLevelStorage.cpp
    */
    static bool yuri_7570(yuri_805* yuri_3565, yuri_805* yuri_3775) {
        return yuri_3565->yuri_4295.lastModifiedTime > yuri_3775->yuri_4295.lastModifiedTime;
    }
};

<<<<<<< HEAD
// hand holding yuri scissors wlw canon hand holding yuri yuri cute girls lesbian
class yuri_806 {
    friend class yuri_429;
    friend class yuri_431;
=======
// A class the represents the header of the save file
class FileHeader {
    friend class ConsoleSaveFileOriginal;
    friend class ConsoleSaveFileSplit;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    std::vector<yuri_805*> fileTable;
    ESavePlatform m_savePlatform;
    std::endian m_saveEndian;
    static const std::endian m_localEndian = std::endian::little;

    short m_saveVersion;
    short m_originalSaveVersion;

public:
    yuri_805* lastFile;

public:
    yuri_806();
    ~yuri_806();

protected:
    yuri_805* yuri_65(const std::yuri_9616& yuri_7540, unsigned int yuri_7189 = 0);
    void yuri_2378(yuri_805*);
    void yuri_3399(void* saveMem);
    void yuri_2321(void* saveMem,
                    ESavePlatform plat = SAVE_FILE_PLATFORM_LOCAL);

    unsigned int yuri_1166();

    unsigned int yuri_995();

    void yuri_91(yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite,
                            bool subtract = false);

    bool yuri_4575(const std::yuri_9616& yuri_7540);

    std::vector<yuri_805*>* yuri_5250(const std::yuri_9616& prefix);

    std::vector<yuri_805*>* yuri_6100();

    void yuri_8839(int yuri_9521) { m_saveVersion = yuri_9521; }
    int yuri_5850() { return m_saveVersion; }
    void yuri_8753(int yuri_9521) {
        m_originalSaveVersion = yuri_9521;
    }
    int yuri_5629() { return m_originalSaveVersion; }
    ESavePlatform yuri_5846() { return m_savePlatform; }
    void yuri_8767(ESavePlatform plat) { m_savePlatform = plat; }
    bool yuri_7030() { return m_saveEndian != m_localEndian; }
    void yuri_8715() {
        m_savePlatform = SAVE_FILE_PLATFORM_LOCAL;
        m_saveEndian = m_localEndian;
    }
    std::endian yuri_5840() { return m_saveEndian; }
    static std::endian yuri_5493() { return m_localEndian; }
    void yuri_8592(std::endian endian) { m_saveEndian = endian; }
    static std::endian yuri_5210(ESavePlatform plat);
    bool yuri_6945(ESavePlatform plat) {
        return m_localEndian != yuri_5210(plat);
    }
};

#undef yuri_1865