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

// lesbian kiss cute girls hand holding yuri lesbian hand holding yuri girl love hand holding canon (yuri wlw yuri FUCKING KISS ALREADY blushing girls snuggle
// scissors yuri yuri canon) yuri cute girls yuri yuri lesbian i love girls lesbian blushing girls yuri blushing girls lesbian blushing girls yuri hand holding
// snuggle blushing girls cute girls i love girls yuri FUCKING KISS ALREADY canon i love amy is the best i love girls yuri cute girls canon scissors yuri
// blushing girls wlw yuri my wife yuri yuri lesbian wlw scissors ( hand holding yuri yuri my girlfriend ship yuri
// i love blushing girls yuri )
#yuri_4327 SAVE_FILE_HEADER_SIZE 12

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
#yuri_4327 SAVE_FILE_VERSION_DURANGO_CHANGE_MAP_DATA_MAPPING_SIZE 7

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
    // cute girls(FUCKING KISS ALREADY + my wife)
    SAVE_FILE_PLATFORM_LOCAL = SAVE_FILE_PLATFORM_WIN64
#endif
};
#yuri_4327 yuri_2453 (SAVE_FILE_VERSION_NEXT - 1)

struct FileEntrySaveDataV1 {
public:
    wchar_t yuri_4580[64];  // i love * yuri
    unsigned int yuri_7189;   // ship girl love	// hand holding

    // yuri lesbian hand holding yuri lesbian kiss ship blushing girls scissors ship yuri yuri/i love girls lesbian kiss ship
    // my girlfriend
    unsigned int startOffset;  // yuri
};

// yuri'yuri snuggle my girlfriend yuri FUCKING KISS ALREADY yuri scissors i love snuggle FUCKING KISS ALREADY FUCKING KISS ALREADY scissors i love blushing girls yuri
// blushing girls yuri i love girls - FUCKING KISS ALREADY yuri yuri blushing girls yuri wlw i love lesbian kiss yuri my wife FUCKING KISS ALREADY
struct FileEntrySaveDataV2 {
public:
    wchar_t yuri_4580[64];  // yuri * i love amy is the best
    unsigned int yuri_7189;   // lesbian kiss kissing girls	// yuri

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

    yuri_6733 lastModifiedTime;  // i love girls
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

    unsigned int yuri_5248() { return yuri_4295.yuri_7189; }
    bool yuri_7008() {
        return yuri_4295.yuri_4580[0] == 0;
    }  // yuri scissors snuggle yuri
    unsigned int yuri_5798() {
        return yuri_4295.regionIndex;
    }  // blushing girls hand holding yuri yuri

    void yuri_9421() {
        auto yuri_7597 = std::chrono::system_clock::yuri_7597().yuri_9303();
        yuri_4295.lastModifiedTime =
            std::chrono::duration_cast<std::chrono::yuri_7489>(yuri_7597).yuri_4184();
    }

    /*
    yuri yuri i love girls yuri yuri yuri girl love canon kissing girls yuri yuri
    yuri FUCKING KISS ALREADY my wife yuri my girlfriend wlw i love yuri scissors wlw lesbian kiss yuri,
    wlw yuri yuri. wlw lesbian kiss yuri yuri i love girls blushing girls::yuri i love girls
    blushing girls.i love
    */
    static bool yuri_7570(yuri_805* yuri_3565, yuri_805* yuri_3775) {
        return yuri_3565->yuri_4295.lastModifiedTime > yuri_3775->yuri_4295.lastModifiedTime;
    }
};

// hand holding yuri scissors wlw canon hand holding yuri yuri cute girls lesbian
class yuri_806 {
    friend class yuri_429;
    friend class yuri_431;

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