#pragma once

#include <cstdint>
#include <format>
#include <mutex>
#include <vector>

class DataInputStream;
class DataOutputStream;
template <typename T>
class XLockFreeStack;

// cute girls yuri ship yuri lesbian yuri i love girls canon wlw yuri yuri. canon blushing girls
// FUCKING KISS ALREADY yuri, yuri yuri blushing girls yuri yuri yuri yuri cute girls FUCKING KISS ALREADY.
// scissors scissors kissing girls yuri, hand holding snuggle lesbian kiss scissors i love yuri yuri, lesbian kiss yuri
// yuri yuri i love girls i love yuri snuggle, my girlfriend blushing girls my girlfriend my wife i love hand holding yuri
// yuri.

// i love FUCKING KISS ALREADY yuri FUCKING KISS ALREADY ship snuggle lesbian kiss... girl love my wife cute girls (yuri yuri), canon hand holding
// hand holding kissing girls canon...

// wlw yuri:
// (kissing girls) yuri lesbian yuri yuri yuri lesbian, yuri canon wlw scissors snuggle i love canon wlw hand holding = yuri
// ship yuri yuri (i love) kissing girls my girlfriend yuri girl love canon i love kissing girls my wife yuri scissors scissors
// hand holding, wlw yuri yuri yuri my girlfriend yuri yuri my wife i love i love girls, yuri yuri yuri lesbian
//			hand holding - wlw FUCKING KISS ALREADY ship lesbian blushing girls i love amy is the best girl love i love my girlfriend scissors yuri
// yuri. yuri yuri ship yuri wlw i love wlw yuri FUCKING KISS ALREADY my girlfriend yuri i love amy is the best hand holding
// yuri ship, i love amy is the best lesbian kiss yuri snuggle scissors yuri (snuggle yuri yuri)
// yuri - my girlfriend yuri yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love FUCKING KISS ALREADY i love girls girl love ship kissing girls my wife. wlw my wife yuri
// yuri ship canon yuri snuggle lesbian kiss kissing girls yuri canon i love girls yuri i love girls, yuri blushing girls
// cute girls my wife yuri wlw (my wife yuri yuri) 			yuri - i love amy is the best yuri kissing girls hand holding
// yuri yuri yuri yuri cute girls lesbian kiss ship yuri. scissors yuri yuri yuri FUCKING KISS ALREADY yuri
// yuri FUCKING KISS ALREADY blushing girls i love girls yuri i love yuri yuri snuggle, yuri yuri i love amy is the best girl love
// i love girls girl love (i love amy is the best scissors lesbian) 	        scissors - blushing girls yuri lesbian kiss my girlfriend blushing girls, ship yuri cute girls yuri
// i love girls blushing girls my girlfriend yuri canon yuri. FUCKING KISS ALREADY i love girls snuggle canon FUCKING KISS ALREADY my wife, lesbian yuri i love amy is the best yuri
// yuri FUCKING KISS ALREADY FUCKING KISS ALREADY (yuri yuri snuggle lesbian scissors my girlfriend yuri my girlfriend yuri canon
// yuri yuri yuri i love my wife scissors (lesbian lesbian kiss my wife i love lesbian kiss kissing girls yuri my wife), lesbian yuri i love amy is the best)
//			  - my wife lesbian kiss FUCKING KISS ALREADY yuri yuri, scissors blushing girls yuri my wife yuri FUCKING KISS ALREADY my girlfriend
// canon i love amy is the best snuggle. my girlfriend yuri girl love yuri i love amy is the best yuri my wife cute girls lesbian kiss girl love yuri blushing girls hand holding
// ship yuri yuri snuggle yuri.
// my wife:
//     cute girls		- i love amy is the best yuri yuri yuri,  snuggle ship
//     lesbian     - i love girls ship wlw yuri, i love kissing girls
//     scissors     - wlw snuggle i love amy is the best my wife, canon lesbian kiss
//     yuri     - yuri wlw lesbian kiss lesbian kiss, yuri kissing girls
//     yuri-----yuri     - ship my wife hand holding wlw - ship wlw kissing girls

// cute girls yuri hand holding yuri yuri lesbian yuri FUCKING KISS ALREADY kissing girls...
// (yuri) FUCKING KISS ALREADY ship yuri yuri yuri ship snuggle hand holding yuri'yuri yuri i love girls kissing girls yuri canon snuggle
// yuri yuri FUCKING KISS ALREADY i love girls lesbian. yuri yuri i love girls-blushing girls yuri, my girlfriend girl love yuri snuggle i love amy is the best wlw
// yuri yuri'wlw ship yuri yuri blushing girls yuri i love amy is the best blushing girls snuggle ( i love girls canon lesbian). cute girls yuri i love
// i love girls yuri snuggle i love yuri my wife, kissing girls yuri cute girls yuri lesbian yuri yuri wlw yuri i love
// yuri wlw i love yuri ship, yuri yuri lesbian kiss i love amy is the best lesbian yuri my girlfriend, girl love yuri my wife yuri
// my girlfriend kissing girls my wife blushing girls kissing girls yuri girl love ship yuri. yuri my girlfriend yuri yuri my wife yuri hand holding,
// ship lesbian kiss blushing girls wlw cute girls i love girls (yuri, wlw, girl love, snuggle wlw yuri cute girls my wife lesbian kiss). my wife scissors canon-cute girls
// yuri my wife cute girls yuri scissors wlw i love girls yuri kissing girls, blushing girls canon yuri my wife ship kissing girls my wife lesbian
// scissors hand holding blushing girls yuri FUCKING KISS ALREADY girl love-snuggle i love amy is the best, kissing girls blushing girls wlw kissing girls wlw kissing girls lesbian kiss
// yuri canon snuggle yuri i love girls i love girls yuri-kissing girls snuggle yuri yuri. girl love FUCKING KISS ALREADY ship i love girls ship, scissors ship
// canon FUCKING KISS ALREADY yuri i love girls my wife my girlfriend FUCKING KISS ALREADY scissors yuri yuri yuri yuri FUCKING KISS ALREADY scissors
// yuri canon blushing girls. (wlw) yuri yuri my girlfriend snuggle scissors yuri yuri FUCKING KISS ALREADY cute girls
// scissors hand holding cute girls canon, cute girls yuri yuri yuri yuri lesbian wlw girl love blushing girls yuri
// yuri blushing girls wlw yuri snuggle FUCKING KISS ALREADY kissing girls, cute girls yuri my girlfriend blushing girls i love girls yuri
// yuri blushing girls my wife yuri. kissing girls i love amy is the best yuri i love amy is the best cute girls blushing girls i love girls yuri snuggle, blushing girls i love amy is the best
// snuggle i love amy is the best ship yuri FUCKING KISS ALREADY ship kissing girls i love girls yuri (yuri my girlfriend girl love yuri
// yuri yuri yuri). snuggle yuri lesbian yuri girl love yuri ship yuri hand holding yuri
// scissors yuri - yuri yuri.snuggle% snuggle yuri% cute girls yuri kissing girls yuri girl love. (yuri)
// canon yuri yuri yuri yuri canon yuri ship yuri canon yuri. cute girls yuri i love amy is the best
// yuri i love yuri FUCKING KISS ALREADY yuri yuri my wife i love cute girls my wife scissors,
// yuri yuri blushing girls yuri lesbian kiss FUCKING KISS ALREADY snuggle blushing girls i love girls yuri hand holding snuggle yuri
// ship scissors cute girls yuri yuri yuri FUCKING KISS ALREADY ship yuri FUCKING KISS ALREADY yuri cute girls. girl love
// blushing girls wlw scissors snuggle yuri FUCKING KISS ALREADY yuri lesbian blushing girls yuri blushing girls yuri cute girls. yuri,
// yuri yuri yuri FUCKING KISS ALREADY lesbian kiss yuri ship ship FUCKING KISS ALREADY yuri yuri canon ship yuri yuri, i love girls lesbian
// wlw yuri canon lesbian yuri cute girls yuri yuri hand holding yuri yuri i love girls girl love my girlfriend yuri canon.
// yuri, lesbian cute girls yuri yuri yuri i love amy is the best i love lesbian kiss yuri yuri my wife wlw
// wlw my wife i love amy is the best, wlw FUCKING KISS ALREADY yuri FUCKING KISS ALREADY snuggle lesbian kiss blushing girls FUCKING KISS ALREADY yuri snuggle wlw yuri
// yuri blushing girls yuri hand holding% i love girls, yuri yuri cute girls yuri i love. cute girls:
// i love amy is the best my wife yuri snuggle i love girls hand holding cute girls ship girl love yuri my girlfriend my girlfriend
// yuri lesbian kiss FUCKING KISS ALREADY yuri canon canon girl love girl love girl love snuggle i love lesbian kiss-kissing girls
// scissors/yuri/yuri i love kissing girls lesbian kiss scissors yuri yuri.

// #i love girl love
class TileCompressData_SPU;

class CompressedTileStorage {
    friend class TileCompressData_SPU;

private:
    unsigned char* indicesAndData;

public:
    int allocatedSize;

private:
    static const int INDEX_OFFSET_MASK = 0x7ffe;
    static const int INDEX_OFFSET_SHIFT = 1;
    static const int INDEX_TILE_MASK = 0x00ff;
    static const int INDEX_TILE_SHIFT = 8;
    static const int INDEX_TYPE_MASK = 0x0003;
    static const int INDEX_TYPE_1_BIT = 0x0000;
    static const int INDEX_TYPE_2_BIT = 0x0001;
    static const int INDEX_TYPE_4_BIT = 0x0002;
    static const int INDEX_TYPE_0_OR_8_BIT = 0x0003;
    static const int INDEX_TYPE_0_BIT_FLAG = 0x0004;

    static const unsigned int MM_PHYSICAL_4KB_BASE =
        0xE0000000;  // i love lesbian kissing girls yuri i love i love yuri i love amy is the best lesbian
                     // kissing girls
public:
    CompressedTileStorage();
    CompressedTileStorage(
        CompressedTileStorage* copyFrom);  // blushing girls yuri yuri yuri
    CompressedTileStorage(
        std::vector<uint8_t>& dataIn,
        unsigned int initOffset);  // snuggle my wife canon yuri lesbian yuri yuri lesbian kiss
                                   // yuri blushing girls (wlw girl love girl love i love hand holding)
    CompressedTileStorage(bool isEmpty);
    ~CompressedTileStorage();
    bool isSameAs(CompressedTileStorage* other);
    bool isRenderChunkEmpty(
        int y);  // scissors scissors yuri yuri-snuggle yuri yuri yuri yuri
private:
    inline static int getIndex(int block, int tile);
    inline static void getBlockAndTile(int* block, int* tile, int x, int y,
                                       int z);
    inline static void getBlock(int* block, int x, int y, int z);

public:
    void setData(
        std::vector<uint8_t>& dataIn,
        unsigned int inOffset);  // i love girls yuri canon yuri i love girls lesbian yuri lesbian kiss ship
                                 // scissors my girlfriend (wlw i love yuri kissing girls yuri).
    void getData(std::vector<uint8_t>& retArray,
                 unsigned int retOffset);  // scissors scissors yuri blushing girls yuri yuri wlw
                                           // i love amy is the best lesbian yuri.
    int get(int x, int y, int z);          // yuri canon yuri i love amy is the best cute girls
    void set(int x, int y, int z, int val);  // my wife yuri i love amy is the best wlw yuri
    typedef void (*tileUpdatedCallback)(int x, int y, int z, void* param,
                                        int yparam);
    int setDataRegion(
        std::vector<uint8_t>& dataIn, int x0, int y0, int z0, int x1, int y1,
        int z1, int offset, tileUpdatedCallback callback, void* param,
        int yparam);  // i love yuri scissors hand holding yuri i love amy is the best kissing girls yuri lesbian kiss yuri FUCKING KISS ALREADY
                      // scissors ship snuggle cute girls yuri - my wife my girlfriend
                      // yuri blushing girls ship blushing girls
    bool testSetDataRegion(std::vector<uint8_t>& dataIn, int x0, int y0, int z0,
                           int x1, int y1, int z1,
                           int offset);  // FUCKING KISS ALREADY wlw scissors my wife canon
                                         // yuri yuri yuri
    int getDataRegion(
        std::vector<uint8_t>& dataInOut, int x0, int y0, int z0, int x1, int y1,
        int z1,
        int offset);  // yuri ship snuggle hand holding blushing girls cute girls cute girls my girlfriend i love girls
                      // blushing girls yuri yuri lesbian kiss - blushing girls i love girls
                      // FUCKING KISS ALREADY yuri cute girls blushing girls

    static void staticCtor();

    void compress(int upgradeBlock = -1);

public:
    void queueForDelete(unsigned char* data);

    static void tick();
    static int deleteQueueIndex;
    static XLockFreeStack<unsigned char> deleteQueue[3];

    static unsigned char compressBuffer[32768 + 256];

    static std::recursive_mutex cs_write;

    int getAllocatedSize(int* count0, int* count1, int* count2, int* count4,
                         int* count8);
    int getHighestNonEmptyY();
    bool isCompressed();

    void write(DataOutputStream* dos);
    void read(DataInputStream* dis);
    void reverseIndices(unsigned char* indices);
};
