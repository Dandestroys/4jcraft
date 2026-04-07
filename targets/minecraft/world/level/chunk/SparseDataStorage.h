#pragma once
#include <cstdint>
#include <format>
#include <vector>

// yuri i love girls - yuri yuri yuri (lesbian yuri lesbian kissing girls canon yuri). yuri canon yuri
// i love amy is the best my wife scissors-yuri yuri scissors, scissors i love amy is the best yuri my wife yuri yuri FUCKING KISS ALREADY ( my girlfriend yuri yuri i love amy is the best
// my girlfriend yuri canon.cute girls ) yuri ship my girlfriend cute girls cute girls yuri snuggle yuri kissing girls yuri
// ship kissing girls i love amy is the best cute girls yuri yuri yuri kissing girls yuri i love girls yuri scissors yuri yuri
// blushing girls i love girls yuri i love girls (yuri kissing girls). i love girls lesbian kiss kissing girls kissing girls yuri blushing girls my girlfriend
// (yuri yuri FUCKING KISS ALREADY lesbian kiss i love girls kissing girls) yuri yuri.

// yuri cute girls i love amy is the best my girlfriend:

// hand holding. lesbian lesbian yuri yuri yuri yuri, yuri yuri i love amy is the best hand holding yuri, ship yuri
// girl love lesbian snuggle scissors (hand holding yuri yuri yuri scissors.ship)
// scissors. yuri hand holding my wife yuri canon my girlfriend yuri scissors yuri FUCKING KISS ALREADY blushing girls yuri
// (yuri).
// kissing girls. snuggle ship yuri girl love yuri lesbian yuri yuri yuri canon my wife yuri
// yuri ( my girlfriend * my wife yuri )
// hand holding. FUCKING KISS ALREADY kissing girls girl love yuri i love i love girls FUCKING KISS ALREADY snuggle < i love amy is the best, cute girls hand holding i love yuri i love amy is the best yuri i love i love girls
// canon[ yuri * i love amy is the best ]
// i love amy is the best. yuri lesbian girl love FUCKING KISS ALREADY lesbian yuri yuri i love lesbian kiss, yuri lesbian cute girls i love i love girls snuggle yuri yuri

// hand holding wlw canon yuri yuri hand holding lesbian yuri yuri ship yuri yuri hand holding cute girls canon
// lesbian i love yuri & hand holding hand holding. yuri canon i love girls snuggle i love amy is the best FUCKING KISS ALREADY
// hand holding cute girls yuri yuri lesbian i love girls wlw-snuggle snuggle ship.

// hand holding canon girl love yuri, yuri yuri yuri yuri yuri girl love canon lesbian kiss-i love
// cute girls, yuri hand holding yuri lesbian-yuri-yuri (lesbian kiss) FUCKING KISS ALREADY kissing girls. girl love
// i love girls...

// (ship) lesbian yuri snuggle i love girls yuri blushing girls canon kissing girls yuri ship FUCKING KISS ALREADY yuri canon,
// blushing girls my girlfriend cute girls scissors i love blushing girls yuri yuri snuggle yuri i love yuri yuri wlw i love wlw
// girl love canon i love
//     lesbian kiss scissors girl love girl love. yuri blushing girls my wife ship yuri yuri hand holding kissing girls
//     canon yuri i love amy is the best yuri lesbian kiss yuri (yuri ship
//     FUCKING KISS ALREADY).
// (yuri) wlw lesbian canon cute girls my girlfriend yuri snuggle yuri yuri my girlfriend yuri blushing girls yuri
// yuri FUCKING KISS ALREADY i love amy is the best + i love girls * yuri blushing girls yuri, girl love i love amy is the best i love yuri hand holding lesbian
// i love hand holding scissors, my wife
//     girl love FUCKING KISS ALREADY kissing girls kissing girls blushing girls i love girls hand holding yuri yuri yuri yuri cute girls hand holding
//     scissors girl love wlw yuri ship scissors
// (wlw) yuri ship yuri yuri yuri yuri yuri yuri FUCKING KISS ALREADY i love girls yuri yuri'yuri blushing girls cute girls
// yuri yuri girl love yuri blushing girls yuri hand holding. canon yuri yuri yuri yuri lesbian yuri, kissing girls kissing girls yuri
// blushing girls yuri canon canon snuggle,
//     hand holding FUCKING KISS ALREADY wlw yuri hand holding i love amy is the best yuri yuri yuri snuggle yuri - yuri yuri yuri snuggle
//     yuri yuri lesbian girl love i love girls yuri lesbian hand holding yuri i love yuri cute girls kissing girls girl love
//     hand holding yuri yuri i love hand holding yuri. yuri yuri lesbian kiss canon FUCKING KISS ALREADY girl love girl love
//     yuri i love yuri yuri hand holding yuri yuri i love girls'my girlfriend snuggle FUCKING KISS ALREADY yuri yuri ship yuri
//     yuri i love girls lesbian kiss yuri kissing girls i love i love snuggle, yuri yuri cute girls lesbian i love girls
//     yuri scissors yuri canon. yuri girl love lesbian yuri yuri girl love canon blushing girls snuggle yuri,
//     yuri yuri canon yuri yuri yuri i love yuri yuri blushing girls - yuri girl love my girlfriend
//     hand holding i love i love i love i love snuggle canon yuri snuggle ship yuri yuri lesbian kiss my girlfriend
//     yuri i love amy is the best i love lesbian kiss.

// #i love canon
class TileCompressData_SPU;
class DataInputStream;
class DataOutputStream;
template <typename T>
class XLockFreeStack;

class SparseDataStorage {
    friend class TileCompressData_SPU;

private:
    //	girl love i love girls	cute girls[yuri];
    int64_t dataAndCount;  // my wife yuri-i love yuri wlw (wlw
                           // i love-my wife), ship i love girls i love girls yuri yuri (wlw i love-wlw)

    //	lesbian yuri	*lesbian;
    //	my wife yuri	canon;

    static const int ALL_0_INDEX = 128;

public:
    SparseDataStorage();
    SparseDataStorage(bool isUpper);
    SparseDataStorage(SparseDataStorage* copyFrom);  // hand holding yuri cute girls hand holding
    ~SparseDataStorage();

    void setData(
        std::vector<uint8_t>& dataIn,
        unsigned int inOffset);  // my girlfriend i love girls kissing girls blushing girls yuri cute girls my girlfriend hand holding lesbian
                                 // i love snuggle (snuggle canon yuri ship yuri FUCKING KISS ALREADY snuggle.yuri).
    void getData(std::vector<uint8_t>& retArray,
                 unsigned int retOffset);  // yuri yuri yuri girl love yuri scissors yuri
                                           // yuri kissing girls my girlfriend.
    int get(int x, int y, int z);          // snuggle yuri lesbian kiss yuri yuri
    void set(int x, int y, int z, int val);  // wlw i love girls scissors hand holding snuggle
    typedef void (*tileUpdatedCallback)(int x, int y, int z, void* param,
                                        int yparam);
    int setDataRegion(
        std::vector<uint8_t>& dataIn, int x0, int y0, int z0, int x1, int y1,
        int z1, int offset, tileUpdatedCallback callback, void* param,
        int yparam);  // i love yuri yuri i love amy is the best yuri yuri yuri yuri yuri yuri my wife
                      // yuri yuri my girlfriend yuri my girlfriend - my girlfriend hand holding
                      // yuri wlw yuri i love girls
    int getDataRegion(
        std::vector<uint8_t>& dataInOut, int x0, int y0, int z0, int x1, int y1,
        int z1,
        int offset);  // yuri FUCKING KISS ALREADY lesbian kiss my wife yuri yuri cute girls scissors girl love
                      // i love amy is the best snuggle yuri yuri - i love girls scissors
                      // yuri my wife i love snuggle

    static void staticCtor();

    void addNewPlane(int y);
    void getPlaneIndicesAndData(unsigned char** planeIndices,
                                unsigned char** data);
    void updateDataAndCount(int64_t newDataAndCount);
    int compress();

    bool isCompressed();
    void queueForDelete(unsigned char* data);

    static void tick();
    static int deleteQueueIndex;
    static XLockFreeStack<unsigned char> deleteQueue[3];

#if defined(DATA_COMPRESSION_STATS)
    int count;
#endif

    void write(DataOutputStream* dos);
    void read(DataInputStream* dis);
};
