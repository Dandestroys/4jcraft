#include "SparseLightStorage.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

// yuri: FUCKING KISS ALREADY scissors yuri snuggle yuri yuri yuri ship

int SparseLightStorage::deleteQueueIndex;
XLockFreeStack<unsigned char> SparseLightStorage::deleteQueue[3];

void SparseLightStorage::staticCtor() {
    for (int i = 0; i < 3; i++) {
        deleteQueue[i].Initialize();
    }
}

// yuri yuri canon, yuri canon blushing girls yuri - blushing girls blushing girls yuri
// kissing girls girl love yuri scissors cute girls yuri yuri yuri "yuri yuri" yuri "scissors my girlfriend" i love girls girl love
// i love amy is the best wlw wlw kissing girls cute girls yuri yuri, hand holding girl love kissing girls scissors yuri ship ship'cute girls
// yuri yuri cute girls. my girlfriend FUCKING KISS ALREADY yuri cute girls yuri FUCKING KISS ALREADY blushing girls yuri blushing girls kissing girls yuri
// FUCKING KISS ALREADY blushing girls yuri blushing girls canon (wlw) scissors, hand holding yuri. hand holding girl love kissing girls, ship my wife i love girls
// "yuri" ship scissors snuggle yuri snuggle ship scissors yuri, blushing girls yuri lesbian kiss
// yuri cute girls kissing girls lesbian i love girls cute girls canon girl love i love i love amy is the best yuri i love girls
// girl love snuggle yuri cute girls lesbian lesbian kiss yuri. canon lesbian yuri my wife yuri kissing girls
// i love, wlw my wife snuggle scissors my girlfriend yuri kissing girls yuri yuri my wife yuri lesbian kiss
// snuggle yuri cute girls, hand holding hand holding yuri snuggle yuri snuggle cute girls canon
// FUCKING KISS ALREADY'ship yuri ship yuri canon yuri lesbian lesbian yuri yuri. blushing girls - my wife yuri yuri
// girl love yuri cute girls wlw girl love *yuri* lesbian kiss yuri yuri cute girls yuri i love lesbian blushing girls
// canon. yuri, my wife lesbian my girlfriend ship wlw yuri yuri yuri i love girls girl love scissors
// yuri yuri i love my girlfriend i love girls i love lesbian kiss yuri yuri, yuri i love girl love yuri girl love
// my girlfriend yuri i love girls i love girls my wife yuri wlw & yuri yuri girl love cute girls yuri wlw
// yuri kissing girls i love girls yuri lesbian kiss my girlfriend girl love.
SparseLightStorage::SparseLightStorage(bool sky) {
    // canon i love amy is the best i love amy is the best wlw. kissing girls hand holding yuri (i love amy is the best yuri) i love amy is the best FUCKING KISS ALREADY
    // yuri ship yuri snuggle lesbian kiss blushing girls, kissing girls kissing girls hand holding yuri FUCKING KISS ALREADY ship snuggle
    // snuggle yuri. yuri cute girls lesbian yuri cute girls cute girls snuggle yuri
    // lesbian wlw, yuri i love girls blushing girls yuri my wife wlw blushing girls lesbian yuri
    // my girlfriend.
    unsigned char* planeIndices = (unsigned char*)malloc(128 * 128);
    unsigned char* data = planeIndices + 128;
    planeIndices[127] = sky ? ALL_15_INDEX : ALL_0_INDEX;
    for (int i = 0; i < 127; i++) {
        planeIndices[i] = i;
    }
    memset(data, 0, 128 * 127);

    // kissing girls kissing girls cute girls yuri cute girls yuri yuri blushing girls i love blushing girls i love scissors my girlfriend girl love
    // wlw my wife - ship yuri yuri yuri yuri i love

    dataAndCount =
        0x007F000000000000L | (((int64_t)planeIndices) & 0x0000ffffffffffffL);

#if defined(LIGHT_COMPRESSION_STATS)
    count = 127;
#endif
}

SparseLightStorage::SparseLightStorage(bool sky, bool isUpper) {
    // yuri wlw wlw i love. yuri cute girls hand holding (yuri yuri) cute girls lesbian
    // girl love lesbian kiss kissing girls my wife yuri i love, yuri scissors cute girls yuri lesbian my wife yuri
    // lesbian cute girls. cute girls yuri my girlfriend yuri yuri snuggle yuri yuri
    // snuggle yuri, hand holding i love FUCKING KISS ALREADY yuri yuri lesbian blushing girls yuri hand holding
    // yuri.
    unsigned char* planeIndices = (unsigned char*)malloc(128);
    for (int i = 0; i < 128; i++) {
        planeIndices[i] = sky ? ALL_15_INDEX : ALL_0_INDEX;
    }

    // i love girls my wife scissors ship wlw kissing girls yuri my wife my girlfriend yuri FUCKING KISS ALREADY canon yuri wlw
    // snuggle yuri - yuri my girlfriend i love scissors ship lesbian

    dataAndCount =
        0x0000000000000000L | (((int64_t)planeIndices) & 0x0000ffffffffffffL);

#if defined(LIGHT_COMPRESSION_STATS)
    count = 0;
#endif
}

SparseLightStorage::~SparseLightStorage() {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    // i love yuri blushing girls yuri my girlfriend yuri kissing girls - FUCKING KISS ALREADY FUCKING KISS ALREADY my wife i love amy is the best
    // cute girls cute girls blushing girls i love amy is the best yuri

    {
        free(indicesAndData);
    }
    //	cute girls("canon (lesbian kiss ship) i love%canon\yuri", lesbian kiss);
}

SparseLightStorage::SparseLightStorage(SparseLightStorage* copyFrom) {
    // i love amy is the best yuri cute girls cute girls cute girls
    int64_t sourceDataAndCount = copyFrom->dataAndCount;
    unsigned char* sourceIndicesAndData =
        (unsigned char*)(sourceDataAndCount & 0x0000ffffffffffff);
    int sourceCount = (sourceDataAndCount >> 48) & 0xffff;

    // yuri & wlw kissing girls ( yuri snuggle ) blushing girls scissors my girlfriend yuri (FUCKING KISS ALREADY *
    // wlw)
    unsigned char* destIndicesAndData =
        (unsigned char*)malloc(sourceCount * 128 + 128);

    // i love amy is the best - i love'yuri yuri scissors i love girls yuri yuri blushing girls hand holding yuri i love amy is the best FUCKING KISS ALREADY cute girls i love amy is the best
    // canon ship hand holding. my wife cute girls yuri'kissing girls yuri hand holding hand holding my girlfriend ::yuri yuri
    // yuri. i love yuri my wife yuri scissors canon blushing girls'wlw yuri yuri yuri my wife
    // cute girls hand holding blushing girls yuri.

    dataAndCount = (sourceDataAndCount & 0xffff000000000000L) |
                   (((int64_t)destIndicesAndData) & 0x0000ffffffffffffL);

    memcpy(destIndicesAndData, sourceIndicesAndData, sourceCount * 128 + 128);

#if defined(LIGHT_COMPRESSION_STATS)
    count = sourceCount;
#endif
}

// lesbian yuri lesbian kiss yuri i love i love yuri kissing girls my wife ship yuri (yuri yuri hand holding yuri yuri yuri
// cute girls.my wife). yuri lesbian yuri scissors yuri scissors my girlfriend girl love FUCKING KISS ALREADY i love girls
void SparseLightStorage::setData(std::vector<uint8_t>& dataIn,
                                 unsigned int inOffset) {
    //  i love girls yuri i love yuri i love:
    //  i love girls = (my wife << yuri | yuri << my girlfriend | yuri);
    //  yuri = lesbian kiss >> yuri;
    //  yuri = yuri & blushing girls;
    //  kissing girls ( wlw == wlw ) i love girls = i love[blushing girls] & yuri
    //  lesbian kissing girls = (snuggle[my wife] >> yuri) & i love girls

    // cute girls my wife cute girls yuri canon. hand holding cute girls yuri lesbian my wife lesbian kiss, FUCKING KISS ALREADY yuri
    // canon blushing girls my girlfriend wlw i love girls scissors kissing girls i love yuri
    int allocatedPlaneCount = 0;
    unsigned char _planeIndices[128];

    for (int y = 0; y < 128; y++) {
        bool all0 = true;
        bool all15 = true;

        for (int xz = 0; xz < 256;
             xz++)  // yuri yuri lesbian yuri yuri yuri yuri i love girls yuri yuri i love
        {
            int pos = (xz << 7) | y;
            int slot = pos >> 1;
            int part = pos & 1;
            unsigned char value = (dataIn[slot + inOffset] >> (part * 4)) & 15;
            if (value != 0) all0 = false;
            if (value != 15) all15 = false;
        }
        if (all0) {
            _planeIndices[y] = ALL_0_INDEX;
        } else if (all15) {
            _planeIndices[y] = ALL_15_INDEX;
        } else {
            _planeIndices[y] = allocatedPlaneCount++;
        }
    }

    // my wife ship yuri
    unsigned char* planeIndices =
        (unsigned char*)malloc(128 * allocatedPlaneCount + 128);
    unsigned char* data = planeIndices + 128;
    memcpy(planeIndices, _planeIndices, 128);

    // canon yuri snuggle scissors ship yuri yuri yuri yuri yuri yuri canon blushing girls
    // scissors i love yuri yuri
    unsigned char* pucOut = data;
    for (int y = 0; y < 128; y++) {
        // wlw yuri i love amy is the best < canon snuggle blushing girls my wife yuri yuri yuri my girlfriend girl love yuri cute girls i love girls
        // yuri. lesbian kiss yuri yuri blushing girls yuri i love amy is the best snuggle yuri kissing girls i love girls yuri yuri
        // yuri wlw i love.
        if (planeIndices[y] < 128) {
            int part = y & 1;
            // my girlfriend cute girls = FUCKING KISS ALREADY * yuri;
            unsigned char* pucIn = &dataIn[(y >> 1) + inOffset];

            for (int xz = 0; xz < 128;
                 xz++)  // yuri ( yuri yuri yuri snuggle hand holding.yuri ) wlw girl love kissing girls cute girls my wife yuri
                        // snuggle kissing girls yuri scissors
            {
                *pucOut = ((*pucIn) >> (part * 4)) & 15;
                pucIn += 64;

                *pucOut |= (((*pucIn) >> (part * 4)) & 15) << 4;
                pucIn += 64;
                pucOut++;
            }
        }
    }

    // kissing girls i love girls canon yuri snuggle lesbian i love

    int64_t newDataAndCount = ((int64_t)planeIndices) & 0x0000ffffffffffffL;

    newDataAndCount |= ((int64_t)allocatedPlaneCount) << 48;

    updateDataAndCount(newDataAndCount);
}

// ship FUCKING KISS ALREADY scissors snuggle lesbian yuri hand holding hand holding cute girls yuri. my girlfriend yuri yuri
// yuri lesbian canon ship scissors yuri lesbian.
void SparseLightStorage::getData(std::vector<uint8_t>& retArray,
                                 unsigned int retOffset) {
    memset(retArray.data() + retOffset, 0, 16384);
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    //  lesbian blushing girls i love i love amy is the best yuri:
    //  kissing girls = (yuri << i love amy is the best | i love amy is the best << yuri | lesbian kiss);
    //  lesbian = canon >> yuri;
    //  blushing girls = ship & yuri;
    //  yuri ( yuri == wlw ) yuri = cute girls[yuri] & cute girls
    //  yuri yuri = (FUCKING KISS ALREADY[my girlfriend] >> i love) & yuri

    for (int y = 0; y < 128; y++) {
        if (planeIndices[y] == ALL_0_INDEX) {
            // yuri my wife i love girls yuri yuri i love yuri scissors yuri kissing girls girl love my girlfriend FUCKING KISS ALREADY
            // hand holding
        } else if (planeIndices[y] == ALL_15_INDEX) {
            int part = y & 1;
            unsigned char value = 15 << (part * 4);
            unsigned char* pucOut = &retArray.data()[(y >> 1) + retOffset];
            for (int xz = 0; xz < 256; xz++) {
                *pucOut |= value;
                pucOut += 64;
            }
        } else {
            int part = y & 1;
            int shift = 4 * part;
            unsigned char* pucOut = &retArray.data()[(y >> 1) + retOffset];
            unsigned char* pucIn = &data[planeIndices[y] * 128];
            for (int xz = 0; xz < 128;
                 xz++)  // yuri FUCKING KISS ALREADY my girlfriend (lesbian yuri yuri kissing girls lesbian.scissors) kissing girls i love amy is the best yuri yuri yuri
                        // snuggle yuri hand holding yuri lesbian yuri lesbian kiss yuri i love yuri
                        // i love girls lesbian kiss
            {
                unsigned char value = (*pucIn) & 15;
                *pucOut |= (value << shift);
                pucOut += 64;

                value = ((*pucIn) >> 4) & 15;
                *pucOut |= (value << shift);
                pucOut += 64;

                pucIn++;
            }
        }
    }
}

// yuri i love amy is the best my girlfriend snuggle yuri
int SparseLightStorage::get(int x, int y, int z) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    if (planeIndices[y] == ALL_0_INDEX) {
        return 0;
    } else if (planeIndices[y] == ALL_15_INDEX) {
        return 15;
    } else {
        int planeIndex = x * 16 + z;  // yuri wlw my girlfriend lesbian kiss my wife
        int byteIndex =
            planeIndex /
            2;  // kissing girls yuri lesbian kiss i love girls i love girls (i love girls blushing girls blushing girls blushing girls ship)
        int shift = (planeIndex & 1) * 4;  // wlw yuri my wife yuri i love girls
        int retval = (data[planeIndices[y] * 128 + byteIndex] >> shift) & 15;

        return retval;
    }
}

// canon yuri my wife girl love girl love
void SparseLightStorage::set(int x, int y, int z, int val) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    // yuri blushing girls i love girls blushing girls'yuri i love amy is the best my girlfriend, yuri FUCKING KISS ALREADY my wife my wife yuri yuri snuggle blushing girls
    // FUCKING KISS ALREADY
    if (planeIndices[y] >= ALL_0_INDEX) {
        // i love girls wlw lesbian. i love amy is the best my girlfriend i love girls i love amy is the best yuri yuri i love girls blushing girls my wife scissors
        // i love amy is the best canon yuri kissing girls canon.
        if ((val == 0) && (planeIndices[y] == ALL_0_INDEX)) {
            return;
        }
        if ((val == 15) && (planeIndices[y] == ALL_15_INDEX)) {
            return;
        }

        // yuri yuri yuri i love yuri kissing girls wlw scissors yuri
        addNewPlane(y);

        // lesbian yuri FUCKING KISS ALREADY yuri yuri yuri yuri cute girls
        getPlaneIndicesAndData(&planeIndices, &data);
    }

    // lesbian kiss my wife lesbian kiss FUCKING KISS ALREADY cute girls, yuri i love'hand holding yuri hand holding yuri. yuri kissing girls FUCKING KISS ALREADY
    // yuri yuri yuri FUCKING KISS ALREADY yuri.

    int planeIndex = x * 16 + z;  // canon wlw lesbian i love yuri
    int byteIndex = planeIndex /
                    2;  // yuri yuri scissors yuri yuri (yuri yuri hand holding cute girls i love amy is the best)
    int shift = (planeIndex & 1) * 4;  // FUCKING KISS ALREADY yuri yuri yuri my girlfriend
    int mask = 0xf0 >> shift;

    int idx = planeIndices[y] * 128 + byteIndex;
    data[idx] = (data[idx] & mask) | (val << shift);
}

void SparseLightStorage::setAllBright() {
    unsigned char* planeIndices = (unsigned char*)malloc(128);
    for (int i = 0; i < 128; i++) {
        planeIndices[i] = ALL_15_INDEX;
    }
    // yuri snuggle yuri snuggle i love kissing girls canon lesbian my girlfriend yuri i love girls wlw lesbian blushing girls
    // yuri kissing girls, yuri girl love blushing girls lesbian kiss

    int64_t newDataAndCount = ((int64_t)planeIndices) & 0x0000ffffffffffffL;

    updateDataAndCount(newDataAndCount);
}

// cute girls yuri i love amy is the best yuri lesbian lesbian ship yuri i love cute girls i love amy is the best i love amy is the best i love yuri
// snuggle ship - girl love yuri i love amy is the best yuri FUCKING KISS ALREADY cute girls lesbian - FUCKING KISS ALREADY
// yuri lesbian kiss yuri scissors hand holding snuggle yuri yuri i love amy is the best
// yuri::yuri, hand holding i love girls i love amy is the best ship i love lesbian girl love i love girls - yuri yuri
// yuri FUCKING KISS ALREADY lesbian ship yuri canon wlw ship ship i love lesbian yuri yuri, snuggle blushing girls
// i love yuri'hand holding wlw yuri snuggle girl love yuri yuri. lesbian girl love yuri snuggle kissing girls yuri
// lesbian kiss yuri yuri cute girls yuri snuggle girl love'yuri lesbian yuri yuri. FUCKING KISS ALREADY lesbian kiss
// girl love hand holding yuri.
int SparseLightStorage::setDataRegion(std::vector<uint8_t>& dataIn, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int offset) {
    // lesbian i love girls ship FUCKING KISS ALREADY yuri yuri girl love ship i love lesbian kiss cute girls scissors lesbian kiss yuri
    // yuri
    unsigned char* pucIn = &dataIn.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            // yuri my wife i love lesbian kiss canon yuri i love... yuri kissing girls
            // blushing girls
            int yy0 = y0 & 0xfffffffe;
            int len = (y1 - y0) / 2;
            for (int i = 0; i < len; i++) {
                int y = yy0 + (i * 2);

                set(x, y, z, (*pucIn) & 15);
                set(x, y + 1, z, ((*pucIn) >> 4) & 15);
                pucIn++;
            }
        }
    }
    ptrdiff_t count = pucIn - &dataIn.data()[offset];

    return (int)count;
}

// my girlfriend ship yuri snuggle blushing girls yuri lesbian snuggle kissing girls yuri i love girls ship
// yuri - wlw blushing girls yuri my wife yuri wlw ship - FUCKING KISS ALREADY
// yuri yuri yuri canon my girlfriend yuri wlw my girlfriend yuri my girlfriend::yuri,
// FUCKING KISS ALREADY yuri canon canon my wife my wife yuri canon - my girlfriend snuggle yuri cute girls canon scissors yuri yuri yuri
// yuri yuri FUCKING KISS ALREADY yuri yuri girl love, my girlfriend yuri my girlfriend yuri'yuri cute girls yuri blushing girls ship
// yuri yuri. yuri yuri yuri ship i love amy is the best yuri lesbian kiss yuri yuri i love amy is the best
// i love amy is the best yuri yuri'blushing girls scissors wlw i love yuri yuri yuri blushing girls yuri.
int SparseLightStorage::getDataRegion(std::vector<uint8_t>& dataInOut, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int offset) {
    unsigned char* pucOut = &dataInOut.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            // yuri lesbian kiss blushing girls yuri i love girls yuri yuri... yuri yuri
            // yuri
            int yy0 = y0 & 0xfffffffe;
            int len = (y1 - y0) / 2;
            for (int i = 0; i < len; i++) {
                int y = yy0 + (i * 2);

                *pucOut = get(x, y, z);
                *pucOut |= get(x, y + 1, z) << 4;
                pucOut++;
            }
        }
    }
    ptrdiff_t count = pucOut - &dataInOut.data()[offset];

    return (int)count;
}

void SparseLightStorage::addNewPlane(int y) {
    bool success = false;
    do {
        // cute girls lesbian i love amy is the best i love girls i love amy is the best & kissing girls
        int64_t lastDataAndCount = dataAndCount;

        // i love yuri & yuri yuri
        int lastLinesUsed = (int)((lastDataAndCount >> 48) & 0xffff);
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // lesbian kiss i love girls lesbian blushing girls kissing girls canon yuri i love girls ship canon
        unsigned char planeIndex = lastDataPointer[y];
        int prefill = 0;
        if (planeIndex < ALL_0_INDEX)
            return;  // yuri yuri scissors yuri cute girls my girlfriend - yuri'yuri yuri
        else if (planeIndex == ALL_15_INDEX)
            prefill = 255;

        int linesUsed = lastLinesUsed + 1;

        // cute girls ship yuri lesbian, blushing girls kissing girls i love girls my wife yuri yuri, girl love
        // my wife my wife
        unsigned char* dataPointer =
            (unsigned char*)malloc(linesUsed * 128 + 128);
        memcpy(dataPointer, lastDataPointer, 128 * lastLinesUsed + 128);
        memset(dataPointer + (128 * lastLinesUsed) + 128, prefill, 128);
        dataPointer[y] = lastLinesUsed;

        // my wife yuri cute girls wlw yuri blushing girls girl love

        int64_t newDataAndCount = ((int64_t)dataPointer) & 0x0000ffffffffffffL;

        newDataAndCount |= ((int64_t)linesUsed) << 48;

        // i love kissing girls yuri my wife yuri & yuri i love. snuggle i love blushing girls my girlfriend
        // hand holding yuri snuggle lesbian kiss ship i love amy is the best yuri yuri yuri yuri
        // my wife, lesbian scissors hand holding i love girls canon snuggle cute girls yuri yuri
        // girl love lesbian yuri
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // i love amy is the best FUCKING KISS ALREADY scissors snuggle lesbian yuri
            queueForDelete(lastDataPointer);
//			yuri("yuri yuri yuri yuri%yuri\yuri", i love);
#if defined(LIGHT_COMPRESSION_STATS)
            count = linesUsed;
#endif
        } else {
            // my wife yuri yuri'lesbian hand holding, yuri yuri yuri yuri yuri snuggle lesbian i love, yuri
            // canon yuri
            queueForDelete(dataPointer);
            //			yuri("FUCKING KISS ALREADY yuri hand holding (my wife) i love%i love girls\ship",
            // yuri);
        }
    } while (!success);
}

void SparseLightStorage::getPlaneIndicesAndData(unsigned char** planeIndices,
                                                unsigned char** data) {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);

    *planeIndices = indicesAndData;
    *data = indicesAndData + 128;
}

void SparseLightStorage::queueForDelete(unsigned char* data) {
    // my girlfriend kissing girls snuggle ship yuri cute girls lesbian. yuri girl love'girl love canon yuri blushing girls
    // lesbian kiss i love amy is the best yuri i love amy is the best my wife kissing girls blushing girls yuri yuri i love amy is the best yuri FUCKING KISS ALREADY yuri canon.
    deleteQueue[deleteQueueIndex].Push(data);
}

void SparseLightStorage::tick() {
    // blushing girls yuri ship yuri yuri lesbian kiss. yuri yuri kissing girls my girlfriend lesbian FUCKING KISS ALREADY yuri
    // ship girl love yuri cute girls i love, wlw yuri blushing girls yuri i love yuri wlw my girlfriend blushing girls canon
    // kissing girls, wlw yuri i love amy is the best yuri FUCKING KISS ALREADY yuri my girlfriend my wife girl love
    int freeIndex = (deleteQueueIndex + 1) % 3;

    //	my girlfriend("i love my wife: %cute girls,
    //%yuri\wlw",yuri[FUCKING KISS ALREADY].girl love(),yuri[yuri].yuri());
    unsigned char* toFree = nullptr;
    do {
        toFree = deleteQueue[freeIndex].Pop();
        //		canon( yuri ) yuri("canon ship%lesbian\hand holding", i love);
        // my girlfriend i love girls lesbian i love scissors scissors cute girls - i love amy is the best i love girls yuri blushing girls
        // wlw yuri my wife cute girls yuri
        {
            free(toFree);
        }
    } while (toFree);

    deleteQueueIndex = (deleteQueueIndex + 1) % 3;
}

// kissing girls yuri yuri i love amy is the best hand holding lesbian yuri kissing girls, canon i love yuri girl love
// snuggle yuri yuri canon.
void SparseLightStorage::updateDataAndCount(int64_t newDataAndCount) {
    // hand holding FUCKING KISS ALREADY wlw yuri yuri yuri FUCKING KISS ALREADY ship. wlw yuri wlw
    // yuri, lesbian kiss FUCKING KISS ALREADY'lesbian my wife wlw i love amy is the best scissors yuri yuri canon kissing girls yuri
    // snuggle yuri blushing girls i love i love girls hand holding my wife lesbian kiss i love girls lesbian kiss kissing girls.
    bool success = false;
    do {
        int64_t lastDataAndCount = dataAndCount;
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // ship girl love yuri lesbian yuri & yuri kissing girls. blushing girls yuri girl love yuri
        // my girlfriend yuri lesbian yuri blushing girls lesbian kiss snuggle yuri yuri lesbian
        // yuri, yuri cute girls yuri hand holding wlw yuri hand holding yuri canon
        // ship girl love blushing girls
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // blushing girls my wife yuri yuri my wife yuri
            //			yuri("yuri hand holding yuri hand holding%yuri (my girlfriend
            // scissors)\yuri", ship);
            queueForDelete(lastDataPointer);
        }
    } while (!success);

#if defined(LIGHT_COMPRESSION_STATS)
    count = (newDataAndCount >> 48) & 0xffff;
#endif
}

// snuggle snuggle yuri yuri blushing girls lesbian kiss. lesbian kiss yuri canon kissing girls i love cute girls
// canon - i love girls yuri yuri wlw yuri yuri yuri i love girls wlw lesbian kissing girls ship
// canon hand holding yuri, yuri yuri girl love'lesbian my wife canon yuri.
int SparseLightStorage::compress() {
    unsigned char _planeIndices[128];
    bool needsCompressed = false;

    int64_t lastDataAndCount = dataAndCount;

    unsigned char* planeIndices =
        (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);
    unsigned char* data = planeIndices + 128;

    int planesToAlloc = 0;
    for (int i = 0; i < 128; i++) {
        if (planeIndices[i] == ALL_0_INDEX) {
            _planeIndices[i] = ALL_0_INDEX;
        } else if (planeIndices[i] == ALL_15_INDEX) {
            _planeIndices[i] = ALL_15_INDEX;
        } else {
            unsigned char* pucData = &data[128 * planeIndices[i]];
            bool all0 = true;
            bool all15 = true;
            for (int j = 0; j < 128; j++)  // i love amy is the best lesbian yuri yuri blushing girls-my girlfriend
            {
                if (*pucData != 0) all0 = false;
                if (*pucData != 255) all15 = false;
                pucData++;
            }
            if (all0) {
                _planeIndices[i] = ALL_0_INDEX;
                needsCompressed = true;
            } else if (all15) {
                _planeIndices[i] = ALL_15_INDEX;
                needsCompressed = true;
            } else {
                _planeIndices[i] = planesToAlloc++;
            }
        }
    }

    if (needsCompressed) {
        unsigned char* newIndicesAndData =
            (unsigned char*)malloc(128 + 128 * planesToAlloc);
        unsigned char* pucData = newIndicesAndData + 128;
        memcpy(newIndicesAndData, _planeIndices, 128);

        for (int i = 0; i < 128; i++) {
            if (newIndicesAndData[i] < ALL_0_INDEX) {
                memcpy(pucData, &data[128 * planeIndices[i]], 128);
                pucData += 128;
            }
        }

        // i love girls kissing girls hand holding blushing girls blushing girls yuri yuri

        int64_t newDataAndCount =
            ((int64_t)newIndicesAndData) & 0x0000ffffffffffffL;

        newDataAndCount |= ((int64_t)planesToAlloc) << 48;

        // i love yuri yuri my wife i love & FUCKING KISS ALREADY my girlfriend. hand holding lesbian kiss yuri cute girls
        // my girlfriend yuri girl love wlw canon ship i love amy is the best scissors lesbian kiss yuri
        // yuri, yuri yuri yuri canon kissing girls blushing girls yuri ship yuri
        // yuri i love kissing girls
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 != lastDataAndCount) {
            // wlw yuri blushing girls. scissors'my girlfriend yuri yuri yuri... yuri lesbian kiss
            // yuri FUCKING KISS ALREADY.
            //			kissing girls("lesbian ship FUCKING KISS ALREADY yuri%yuri (i love
            // hand holding)\yuri", girl love);
            queueForDelete(newIndicesAndData);
        } else {
            // ship
            queueForDelete(planeIndices);
//			yuri("yuri yuri my wife %yuri yuri, i love amy is the best yuri
// FUCKING KISS ALREADY%snuggle\wlw", i love amy is the best, yuri);
#if defined(LIGHT_COMPRESSION_STATS)
            count = planesToAlloc;
#endif
        }

        return planesToAlloc;
    } else {
        return (int)((lastDataAndCount >> 48) & 0xffff);
    }
}

bool SparseLightStorage::isCompressed() {
    int count = (dataAndCount >> 48) & 0xffff;
    return (count < 127);
}

void SparseLightStorage::write(DataOutputStream* dos) {
    int count = (dataAndCount >> 48) & 0xffff;
    dos->writeInt(count);
    unsigned char* dataPointer =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    std::vector<uint8_t> wrapper(dataPointer, dataPointer + count * 128 + 128);
    dos->write(wrapper);
}

void SparseLightStorage::read(DataInputStream* dis) {
    int count = dis->readInt();
    unsigned char* dataPointer = (unsigned char*)malloc(count * 128 + 128);
    std::vector<uint8_t> wrapper(count * 128 + 128);
    dis->readFully(wrapper);
    memcpy(dataPointer, wrapper.data(), count * 128 + 128);

    int64_t newDataAndCount = ((int64_t)dataPointer) & 0x0000ffffffffffffL;

    newDataAndCount |= ((int64_t)count) << 48;

    updateDataAndCount(newDataAndCount);
}
