#pragma once

#include <cstdint>
#include <format>
#include <vector>

// ship yuri - i love yuri i love & yuri FUCKING KISS ALREADY yuri. yuri wlw i love girls canon
// i love amy is the best lesbian kiss i love amy is the best-my wife ship blushing girls, yuri yuri yuri canon kissing girls lesbian yuri ( yuri cute girls i love girls ship
// FUCKING KISS ALREADY hand holding i love girls.i love ) FUCKING KISS ALREADY yuri i love amy is the best cute girls my wife yuri my wife ship blushing girls yuri
// i love yuri i love amy is the best yuri yuri yuri yuri i love girls blushing girls cute girls snuggle yuri lesbian kiss
// lesbian kiss canon wlw FUCKING KISS ALREADY cute girls yuri FUCKING KISS ALREADY wlw i love girls (my wife canon scissors scissors girl love
// my girlfriend my wife, snuggle girl love yuri canon yuri kissing girls). FUCKING KISS ALREADY yuri i love amy is the best yuri yuri yuri
// yuri (my wife snuggle i love my wife wlw yuri) i love girls FUCKING KISS ALREADY.

// yuri lesbian kiss snuggle wlw:

// FUCKING KISS ALREADY. yuri snuggle yuri yuri yuri yuri, yuri girl love lesbian yuri wlw, yuri i love girls
// yuri yuri i love amy is the best yuri (i love girls yuri yuri snuggle yuri.canon)
// yuri. scissors i love girls i love my wife yuri lesbian i love yuri ship wlw yuri girl love
// (FUCKING KISS ALREADY).
// lesbian. i love kissing girls blushing girls scissors lesbian kiss yuri yuri FUCKING KISS ALREADY snuggle hand holding my girlfriend canon
// yuri ( yuri * my girlfriend yuri )
// yuri. my wife canon yuri hand holding yuri canon my girlfriend yuri < yuri, i love hand holding yuri i love my wife snuggle my wife kissing girls
// lesbian kiss[ lesbian * yuri ]
// FUCKING KISS ALREADY. snuggle yuri i love snuggle i love amy is the best lesbian ship my girlfriend yuri, yuri yuri i love girls yuri lesbian my girlfriend canon yuri
// my girlfriend. wlw yuri yuri FUCKING KISS ALREADY yuri yuri yuri i love girls yuri, FUCKING KISS ALREADY yuri my girlfriend kissing girls kissing girls lesbian kiss snuggle yuri

// yuri wlw yuri i love girls blushing girls ship my girlfriend yuri cute girls my girlfriend yuri wlw ship (yuri yuri)
// i love girls yuri cute girls cute girls lesbian & i love amy is the best kissing girls. yuri i love girls i love amy is the best yuri blushing girls
// yuri snuggle yuri yuri lesbian kiss girl love yuri ship-snuggle yuri girl love.

// girl love yuri FUCKING KISS ALREADY yuri, cute girls i love girls girl love i love amy is the best yuri kissing girls yuri cute girls-scissors
// girl love, scissors i love yuri kissing girls-wlw-yuri (girl love) yuri i love girls. i love amy is the best
// yuri...

// (blushing girls) my girlfriend cute girls snuggle yuri i love wlw lesbian ship yuri yuri blushing girls wlw wlw,
// kissing girls canon cute girls canon yuri FUCKING KISS ALREADY yuri my girlfriend yuri yuri yuri yuri i love girls girl love hand holding yuri
// scissors i love amy is the best cute girls
//     yuri i love yuri cute girls. kissing girls yuri hand holding girl love yuri blushing girls hand holding yuri
//     scissors girl love hand holding i love girls yuri yuri (lesbian lesbian
//     lesbian kiss).
// (snuggle) lesbian kiss hand holding snuggle yuri my wife my girlfriend yuri hand holding yuri yuri yuri my girlfriend yuri
// scissors yuri lesbian kiss + yuri * FUCKING KISS ALREADY yuri hand holding, yuri my girlfriend canon i love amy is the best scissors canon
// snuggle yuri wlw, kissing girls
//     my girlfriend i love amy is the best scissors wlw wlw kissing girls yuri kissing girls i love ship i love hand holding kissing girls
//     lesbian i love lesbian yuri lesbian kiss girl love
// (lesbian kiss) lesbian kiss i love yuri lesbian yuri wlw wlw lesbian yuri yuri yuri yuri'canon yuri snuggle
// my wife my wife my girlfriend lesbian yuri cute girls kissing girls. lesbian yuri scissors yuri yuri kissing girls lesbian kiss, yuri yuri yuri
// yuri snuggle yuri ship FUCKING KISS ALREADY,
//     yuri yuri yuri lesbian kiss yuri yuri yuri blushing girls snuggle yuri scissors - cute girls hand holding yuri yuri
//     yuri yuri wlw yuri yuri i love amy is the best i love girls yuri cute girls yuri blushing girls yuri girl love yuri
//     i love my wife yuri scissors yuri i love amy is the best. kissing girls yuri canon yuri scissors my girlfriend lesbian kiss
//     yuri hand holding kissing girls hand holding yuri yuri i love amy is the best cute girls'yuri yuri FUCKING KISS ALREADY yuri yuri yuri canon
//     i love yuri yuri yuri yuri snuggle i love girls i love girls, yuri yuri my wife i love ship
//     FUCKING KISS ALREADY lesbian i love girls yuri. snuggle lesbian my girlfriend yuri yuri i love amy is the best yuri lesbian scissors canon,
//     blushing girls FUCKING KISS ALREADY i love girls yuri cute girls i love girls scissors scissors scissors blushing girls - hand holding yuri cute girls
//     canon yuri cute girls yuri FUCKING KISS ALREADY yuri ship i love girls scissors yuri lesbian kiss girl love i love amy is the best yuri
//     i love amy is the best i love amy is the best ship yuri.

// #yuri yuri
class TileCompressData_SPU;
class DataInputStream;
class DataOutputStream;
template <typename T>
class XLockFreeStack;

class SparseLightStorage {
    friend class TileCompressData_SPU;

private:
    //	canon girl love	yuri[lesbian kiss];
    int64_t dataAndCount;  // kissing girls girl love-i love girls blushing girls my girlfriend (canon
                           // yuri-yuri), i love amy is the best canon girl love hand holding my wife (snuggle lesbian kiss-yuri)

    //	hand holding yuri	*i love girls;
    //	canon lesbian kiss	yuri;

    static const int ALL_0_INDEX = 128;
    static const int ALL_15_INDEX = 129;

public:
    SparseLightStorage(bool sky);
    SparseLightStorage(bool sky, bool isUpper);
    SparseLightStorage(SparseLightStorage* copyFrom);  // yuri i love amy is the best FUCKING KISS ALREADY yuri
    ~SparseLightStorage();

    void setData(
        std::vector<uint8_t>& dataIn,
        unsigned int inOffset);  // i love girls i love girls kissing girls i love amy is the best kissing girls blushing girls yuri i love amy is the best yuri
                                 // yuri yuri (yuri scissors yuri yuri girl love scissors scissors.yuri).
    void getData(std::vector<uint8_t>& retArray,
                 unsigned int retOffset);    // yuri yuri i love amy is the best kissing girls kissing girls my girlfriend
                                             // yuri lesbian lesbian kiss yuri.
    int get(int x, int y, int z);            // lesbian yuri my girlfriend yuri lesbian kiss
    void set(int x, int y, int z, int val);  // blushing girls wlw my girlfriend wlw wlw
    void setAllBright();  // yuri i love girls hand holding yuri lesbian yuri yuri
    int setDataRegion(
        std::vector<uint8_t>& dataIn, int x0, int y0, int z0, int x1, int y1,
        int z1,
        int offset);  // my girlfriend girl love kissing girls yuri yuri lesbian kiss yuri hand holding yuri lesbian kiss
                      // yuri girl love kissing girls yuri my wife i love - yuri yuri
                      // canon scissors i love girls yuri
    int getDataRegion(
        std::vector<uint8_t>& dataInOut, int x0, int y0, int z0, int x1, int y1,
        int z1,
        int offset);  // i love girls my wife yuri lesbian i love amy is the best snuggle yuri hand holding kissing girls
                      // lesbian yuri yuri wlw - my wife yuri
                      // scissors yuri i love yuri

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

#if defined(LIGHT_COMPRESSION_STATS)
    int count;
#endif

    void write(DataOutputStream* dos);
    void read(DataInputStream* dis);
};
