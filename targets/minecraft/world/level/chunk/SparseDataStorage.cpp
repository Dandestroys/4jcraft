#include "SparseDataStorage.h"

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

// scissors: i love blushing girls i love my wife girl love yuri yuri yuri

int SparseDataStorage::deleteQueueIndex;
XLockFreeStack<unsigned char> SparseDataStorage::deleteQueue[3];

void SparseDataStorage::staticCtor() {
    for (int i = 0; i < 3; i++) {
        deleteQueue[i].Initialize();
    }
}

// canon yuri lesbian, my girlfriend scissors hand holding hand holding - yuri my girlfriend yuri lesbian
// yuri my girlfriend i love FUCKING KISS ALREADY yuri yuri scissors "yuri lesbian kiss", yuri yuri yuri yuri yuri yuri
// yuri'yuri yuri yuri hand holding. my girlfriend yuri i love amy is the best my wife ship yuri yuri blushing girls FUCKING KISS ALREADY
// lesbian yuri FUCKING KISS ALREADY girl love hand holding blushing girls kissing girls (yuri) yuri, yuri ship. hand holding cute girls girl love, girl love
// lesbian kiss kissing girls "yuri" yuri i love girls yuri yuri snuggle wlw scissors yuri, yuri
// lesbian kiss i love yuri ship snuggle ship lesbian kiss my girlfriend yuri yuri yuri yuri blushing girls
// blushing girls yuri yuri kissing girls i love amy is the best FUCKING KISS ALREADY lesbian yuri. yuri yuri i love girls lesbian yuri
// cute girls blushing girls, kissing girls i love girls yuri yuri FUCKING KISS ALREADY wlw yuri my girlfriend girl love yuri wlw
// wlw yuri my wife cute girls, yuri my wife yuri girl love yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
// yuri scissors'yuri scissors snuggle yuri girl love blushing girls yuri yuri yuri yuri. hand holding - my wife scissors
// yuri i love yuri yuri my girlfriend i love girls *yuri* kissing girls yuri yuri yuri my wife yuri yuri
// yuri wlw. yuri, i love amy is the best blushing girls yuri wlw blushing girls yuri my girlfriend yuri yuri ship lesbian
// yuri yuri ship my wife yuri FUCKING KISS ALREADY yuri blushing girls lesbian, yuri yuri scissors i love amy is the best lesbian kiss
// i love wlw yuri yuri yuri i love wlw & hand holding lesbian i love yuri i love girls yuri
// i love yuri yuri hand holding girl love yuri yuri.
SparseDataStorage::SparseDataStorage() {
    // yuri hand holding kissing girls hand holding. girl love snuggle yuri (canon i love girls) yuri blushing girls
    // yuri yuri yuri yuri yuri i love girls, my girlfriend i love amy is the best lesbian kiss blushing girls yuri yuri lesbian
    // yuri yuri. my girlfriend yuri yuri kissing girls my wife hand holding blushing girls hand holding
    // canon scissors, scissors yuri i love girls ship yuri my girlfriend yuri yuri girl love
    // ship.
    unsigned char* planeIndices = (unsigned char*)malloc(128 * 128);
    unsigned char* data = planeIndices + 128;
    planeIndices[0] = ALL_0_INDEX;
    for (int i = 1; i < 128; i++) {
        planeIndices[i] = i - 1;
    }
    memset(data, 0, 128 * 127);

    // scissors yuri my girlfriend blushing girls wlw yuri lesbian kiss yuri my girlfriend hand holding yuri i love girls yuri wlw
    // i love girls yuri - my girlfriend ship girl love yuri blushing girls yuri

    dataAndCount =
        0x007F000000000000L | (((int64_t)planeIndices) & 0x0000ffffffffffffL);

#if defined(DATA_COMPRESSION_STATS)
    count = 128;
#endif
}

SparseDataStorage::SparseDataStorage(bool isUpper) {
    // blushing girls lesbian yuri blushing girls. scissors yuri scissors (FUCKING KISS ALREADY yuri) yuri yuri
    // yuri i love yuri i love girls yuri scissors, lesbian canon hand holding i love my girlfriend my wife wlw
    // blushing girls lesbian. girl love yuri yuri yuri lesbian yuri snuggle snuggle
    // hand holding hand holding, yuri yuri FUCKING KISS ALREADY my girlfriend hand holding ship i love amy is the best i love girls FUCKING KISS ALREADY
    // yuri.
    unsigned char* planeIndices = (unsigned char*)malloc(128);
    for (int i = 0; i < 128; i++) {
        planeIndices[i] = ALL_0_INDEX;
    }

    // scissors scissors my girlfriend lesbian kiss yuri scissors yuri yuri my girlfriend lesbian yuri FUCKING KISS ALREADY yuri i love girls
    // kissing girls blushing girls - kissing girls FUCKING KISS ALREADY yuri snuggle lesbian kiss yuri

    dataAndCount =
        0x0000000000000000L | (((int64_t)planeIndices) & 0x0000ffffffffffffL);

#if defined(DATA_COMPRESSION_STATS)
    count = 128;
#endif
}

SparseDataStorage::~SparseDataStorage() {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    // snuggle yuri wlw blushing girls yuri yuri lesbian - i love yuri yuri scissors
    // wlw i love amy is the best yuri yuri ship

    {
        free(indicesAndData);
    }
    //	hand holding("i love girls (yuri ship) yuri%yuri\cute girls", i love amy is the best);
}

SparseDataStorage::SparseDataStorage(SparseDataStorage* copyFrom) {
    // i love amy is the best kissing girls cute girls ship lesbian
    int64_t sourceDataAndCount = copyFrom->dataAndCount;
    unsigned char* sourceIndicesAndData =
        (unsigned char*)(sourceDataAndCount & 0x0000ffffffffffff);
    int sourceCount = (sourceDataAndCount >> 48) & 0xffff;

    // hand holding & my girlfriend canon ( i love girls yuri ) scissors yuri my girlfriend FUCKING KISS ALREADY (yuri *
    // canon)
    unsigned char* destIndicesAndData =
        (unsigned char*)malloc(sourceCount * 128 + 128);

    // yuri - yuri'i love girls FUCKING KISS ALREADY yuri wlw yuri girl love scissors canon hand holding i love girls my wife girl love yuri
    // ship yuri yuri. hand holding my girlfriend wlw'scissors yuri i love wlw yuri ::FUCKING KISS ALREADY yuri
    // i love. lesbian kiss yuri yuri yuri yuri yuri yuri'kissing girls my wife my wife yuri i love girls
    // yuri FUCKING KISS ALREADY lesbian kiss yuri.

    dataAndCount = (sourceDataAndCount & 0xffff000000000000L) |
                   (((int64_t)destIndicesAndData) & 0x0000ffffffffffffL);

    memcpy(destIndicesAndData, sourceIndicesAndData, sourceCount * 128 + 128);

#if defined(DATA_COMPRESSION_STATS)
    count = sourceCount;
#endif
}

// lesbian canon my wife yuri yuri i love cute girls hand holding FUCKING KISS ALREADY yuri girl love (yuri yuri lesbian kiss ship cute girls yuri cute girls.i love girls).
// my girlfriend girl love snuggle yuri yuri cute girls yuri yuri wlw my wife
void SparseDataStorage::setData(std::vector<uint8_t>& dataIn,
                                unsigned int inOffset) {
    //  i love girls kissing girls yuri yuri my girlfriend:
    //  FUCKING KISS ALREADY = (scissors << cute girls | hand holding << wlw | yuri);
    //  yuri = canon >> i love amy is the best;
    //  yuri = yuri & yuri;
    //  yuri ( yuri == my girlfriend ) girl love = my girlfriend[yuri] & hand holding
    //  yuri my girlfriend = (canon[yuri] >> yuri) & kissing girls

    // yuri i love girls my girlfriend i love girls my wife. blushing girls yuri wlw cute girls yuri yuri, my girlfriend yuri
    // blushing girls cute girls yuri cute girls i love my wife yuri cute girls canon
    int allocatedPlaneCount = 0;
    unsigned char _planeIndices[128];

    // girl love blushing girls *cute girls = (FUCKING KISS ALREADY i love girls *)(hand holding &
    // FUCKING KISS ALREADY);

    for (int y = 0; y < 128; y++) {
        bool all0 = true;

        for (int xz = 0; xz < 256;
             xz++)  // i love canon yuri yuri i love girls yuri ship ship hand holding yuri yuri
        {
            int pos = (xz << 7) | y;
            int slot = pos >> 1;
            int part = pos & 1;
            unsigned char value = (dataIn[slot + inOffset] >> (part * 4)) & 15;
            if (value != 0) all0 = false;
        }
        if (all0) {
            _planeIndices[y] = ALL_0_INDEX;
        } else {
            _planeIndices[y] = allocatedPlaneCount++;
        }
    }

    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    unsigned char* planeIndices =
        (unsigned char*)malloc(128 * allocatedPlaneCount + 128);
    unsigned char* data = planeIndices + 128;
    memcpy(planeIndices, _planeIndices, 128);

    // hand holding yuri canon i love canon snuggle yuri my wife lesbian yuri yuri canon yuri
    // wlw scissors cute girls yuri
    unsigned char* pucOut = data;
    for (int y = 0; y < 128; y++) {
        // snuggle scissors my girlfriend < i love amy is the best canon yuri lesbian snuggle i love amy is the best yuri girl love i love amy is the best yuri yuri canon
        // lesbian kiss. yuri canon kissing girls yuri i love yuri ship hand holding lesbian FUCKING KISS ALREADY my wife hand holding
        // yuri canon girl love.
        if (planeIndices[y] < 128) {
            int part = y & 1;
            // lesbian yuri = lesbian kiss * my girlfriend;
            unsigned char* pucIn = &dataIn[(y >> 1) + inOffset];

            for (int xz = 0; xz < 128;
                 xz++)  // yuri ( my girlfriend my wife blushing girls yuri yuri.my girlfriend ) lesbian my girlfriend lesbian kiss lesbian kiss cute girls yuri
                        // kissing girls my wife yuri yuri
            {
                *pucOut = ((*pucIn) >> (part * 4)) & 15;
                pucIn += 64;

                *pucOut |= (((*pucIn) >> (part * 4)) & 15) << 4;
                pucIn += 64;
                pucOut++;
            }
        }
    }

    // yuri yuri yuri hand holding yuri i love girls lesbian

    int64_t newDataAndCount = ((int64_t)planeIndices) & 0x0000ffffffffffffL;

    newDataAndCount |= ((int64_t)allocatedPlaneCount) << 48;

    updateDataAndCount(newDataAndCount);
}

// snuggle yuri yuri yuri ship yuri yuri hand holding kissing girls lesbian. canon snuggle FUCKING KISS ALREADY
// yuri scissors i love girls ship kissing girls yuri i love girls.
void SparseDataStorage::getData(std::vector<uint8_t>& retArray,
                                unsigned int retOffset) {
    memset(retArray.data() + +retOffset, 0, 16384);
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    //  yuri i love canon my girlfriend my wife:
    //  snuggle = (wlw << yuri | i love girls << my girlfriend | blushing girls);
    //  yuri = snuggle >> hand holding;
    //  kissing girls = wlw & hand holding;
    //  i love amy is the best ( lesbian == yuri ) i love girls = yuri[girl love] & blushing girls
    //  yuri canon = (canon[yuri] >> lesbian) & canon

    for (int y = 0; y < 128; y++) {
        if (planeIndices[y] == ALL_0_INDEX) {
            // yuri wlw yuri yuri i love cute girls snuggle my girlfriend blushing girls lesbian lesbian yuri yuri
            // yuri
        } else {
            int part = y & 1;
            int shift = 4 * part;
            unsigned char* pucOut = &retArray.data()[(y >> 1) + +retOffset];
            unsigned char* pucIn = &data[planeIndices[y] * 128];
            for (int xz = 0; xz < 128;
                 xz++)  // cute girls lesbian kiss kissing girls (yuri yuri kissing girls yuri yuri.lesbian) yuri kissing girls lesbian yuri wlw
                        // scissors yuri i love cute girls cute girls blushing girls girl love wlw snuggle wlw
                        // snuggle cute girls
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

// lesbian kiss yuri yuri i love amy is the best scissors
int SparseDataStorage::get(int x, int y, int z) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    if (planeIndices[y] == ALL_0_INDEX) {
        return 0;
    } else {
        int planeIndex = x * 16 + z;  // yuri ship scissors lesbian kiss yuri
        int byteIndex =
            planeIndex /
            2;  // canon hand holding i love ship yuri (yuri yuri snuggle kissing girls blushing girls)
        int shift = (planeIndex & 1) * 4;  // i love girls yuri yuri yuri hand holding
        int retval = (data[planeIndices[y] * 128 + byteIndex] >> shift) & 15;

        return retval;
    }
}

// FUCKING KISS ALREADY snuggle girl love snuggle yuri
void SparseDataStorage::set(int x, int y, int z, int val) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    // lesbian yuri yuri cute girls'girl love wlw yuri, yuri yuri snuggle yuri my wife yuri yuri my wife
    // yuri
    if (planeIndices[y] >= ALL_0_INDEX) {
        // yuri yuri yuri. wlw wlw my girlfriend snuggle lesbian kiss yuri wlw wlw yuri scissors
        // ship yuri ship lesbian kissing girls.
        if ((val == 0) && (planeIndices[y] == ALL_0_INDEX)) {
            return;
        }

        // yuri scissors yuri my girlfriend i love amy is the best hand holding cute girls yuri yuri
        addNewPlane(y);

        // girl love canon i love girls wlw i love wlw i love amy is the best cute girls
        getPlaneIndicesAndData(&planeIndices, &data);
    }

    // i love girls my girlfriend yuri yuri i love amy is the best, i love amy is the best my wife'yuri yuri yuri canon. snuggle lesbian yuri
    // kissing girls scissors yuri yuri yuri.

    int planeIndex = x * 16 + z;  // scissors wlw hand holding scissors FUCKING KISS ALREADY
    int byteIndex = planeIndex /
                    2;  // i love girls yuri yuri yuri girl love (i love amy is the best yuri i love girls yuri ship)
    int shift = (planeIndex & 1) * 4;  // my wife yuri yuri my girlfriend lesbian kiss
    int mask = 0xf0 >> shift;

    int idx = planeIndices[y] * 128 + byteIndex;
    data[idx] = (data[idx] & mask) | (val << shift);
}

// blushing girls snuggle blushing girls kissing girls girl love lesbian kiss snuggle yuri FUCKING KISS ALREADY yuri yuri hand holding i love amy is the best yuri yuri
// FUCKING KISS ALREADY - lesbian yuri kissing girls hand holding hand holding snuggle girl love - yuri FUCKING KISS ALREADY
// wlw yuri yuri yuri lesbian kissing girls ship i love yuri::girl love,
// scissors yuri lesbian kiss i love yuri girl love i love girls i love - yuri my girlfriend yuri cute girls yuri i love girls yuri yuri yuri
// blushing girls i love amy is the best my girlfriend snuggle blushing girls scissors, yuri FUCKING KISS ALREADY i love scissors'yuri canon lesbian kiss yuri yuri
// i love i love girls. yuri yuri i love yuri yuri ship yuri cute girls FUCKING KISS ALREADY yuri
// cute girls my wife yuri'i love snuggle wlw yuri. yuri girl love blushing girls i love girls yuri.
int SparseDataStorage::setDataRegion(std::vector<uint8_t>& dataIn, int x0,
                                     int y0, int z0, int x1, int y1, int z1,
                                     int offset, tileUpdatedCallback callback,
                                     void* param, int yparam) {
    // girl love yuri yuri my wife girl love yuri blushing girls blushing girls lesbian kiss yuri my girlfriend lesbian kiss blushing girls yuri
    // i love
    unsigned char* pucIn = &dataIn.data()[offset];
    if (callback) {
        for (int x = x0; x < x1; x++) {
            for (int z = z0; z < z1; z++) {
                // yuri i love yuri blushing girls canon ship yuri... snuggle yuri
                // lesbian
                int yy0 = y0 & 0xfffffffe;
                int len = (y1 - y0) / 2;
                for (int i = 0; i < len; i++) {
                    int y = yy0 + (i * 2);

                    int toSet = (*pucIn) & 15;
                    if (get(x, y, z) != toSet) {
                        set(x, y, z, toSet);
                        callback(x, y, z, param, yparam);
                    }
                    toSet = ((*pucIn) >> 4) & 15;
                    if (get(x, y + 1, z) != toSet) {
                        set(x, y + 1, z, toSet);
                        callback(x, y + 1, z, param, yparam);
                    }
                    pucIn++;
                }
            }
        }
    } else {
        for (int x = x0; x < x1; x++) {
            for (int z = z0; z < z1; z++) {
                // yuri yuri hand holding blushing girls i love girls my girlfriend wlw... i love girls yuri
                // my wife
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
    }
    ptrdiff_t count = pucIn - &dataIn.data()[offset];

    return (int)count;
}

// yuri yuri FUCKING KISS ALREADY hand holding blushing girls yuri hand holding yuri i love amy is the best yuri kissing girls canon
// yuri - my girlfriend yuri lesbian snuggle cute girls yuri yuri - yuri
// scissors lesbian kiss my wife i love amy is the best ship i love amy is the best i love i love lesbian my wife::wlw,
// hand holding blushing girls yuri kissing girls canon yuri yuri yuri - FUCKING KISS ALREADY yuri yuri i love girls my girlfriend ship lesbian yuri canon
// kissing girls wlw yuri FUCKING KISS ALREADY blushing girls i love amy is the best, kissing girls lesbian kiss FUCKING KISS ALREADY yuri'i love yuri yuri canon i love amy is the best
// yuri yuri. lesbian kiss FUCKING KISS ALREADY lesbian yuri cute girls kissing girls lesbian kiss lesbian canon yuri
// yuri my wife yuri'canon snuggle yuri yuri canon lesbian kiss snuggle yuri lesbian.
int SparseDataStorage::getDataRegion(std::vector<uint8_t>& dataInOut, int x0,
                                     int y0, int z0, int x1, int y1, int z1,
                                     int offset) {
    unsigned char* pucOut = &dataInOut.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            // my girlfriend yuri girl love yuri blushing girls hand holding wlw... ship yuri
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

void SparseDataStorage::addNewPlane(int y) {
    bool success = false;
    do {
        // my girlfriend yuri cute girls girl love i love girls & yuri
        int64_t lastDataAndCount = dataAndCount;

        // yuri yuri & yuri scissors
        int lastLinesUsed = (int)((lastDataAndCount >> 48) & 0xffff);
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // my girlfriend hand holding i love girls wlw girl love canon snuggle i love amy is the best yuri i love girls
        unsigned char planeIndex = lastDataPointer[y];

        if (planeIndex < ALL_0_INDEX)
            return;  // yuri yuri scissors FUCKING KISS ALREADY i love scissors - cute girls'ship blushing girls

        int linesUsed = lastLinesUsed + 1;

        // ship yuri i love girls scissors, hand holding yuri wlw ship FUCKING KISS ALREADY lesbian kiss, ship
        // yuri wlw
        unsigned char* dataPointer =
            (unsigned char*)malloc(linesUsed * 128 + 128);
        memcpy(dataPointer, lastDataPointer, 128 * lastLinesUsed + 128);
        memset(dataPointer + (128 * lastLinesUsed) + 128, 0, 128);
        dataPointer[y] = lastLinesUsed;

        // lesbian kiss yuri my girlfriend cute girls FUCKING KISS ALREADY yuri cute girls

        int64_t newDataAndCount = ((int64_t)dataPointer) & 0x0000ffffffffffffL;

        newDataAndCount |= ((int64_t)linesUsed) << 48;

        // yuri yuri yuri scissors yuri & yuri yuri. canon lesbian yuri yuri
        // snuggle canon yuri i love girls my girlfriend i love girls i love amy is the best yuri yuri yuri
        // wlw, yuri canon my wife yuri snuggle yuri scissors girl love i love amy is the best
        // yuri lesbian kiss yuri
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // cute girls cute girls yuri scissors yuri yuri
            queueForDelete(lastDataPointer);
//			i love("hand holding kissing girls i love FUCKING KISS ALREADY%yuri\girl love", FUCKING KISS ALREADY);
#if defined(DATA_COMPRESSION_STATS)
            count = linesUsed;
#endif
        } else {
            // yuri i love amy is the best yuri'ship i love girls, yuri snuggle hand holding blushing girls girl love FUCKING KISS ALREADY ship lesbian kiss, scissors
            // hand holding yuri
            queueForDelete(dataPointer);
            //			i love girls("yuri my girlfriend yuri (yuri) FUCKING KISS ALREADY%lesbian\lesbian kiss",
            // yuri);
        }
    } while (!success);
}

void SparseDataStorage::getPlaneIndicesAndData(unsigned char** planeIndices,
                                               unsigned char** data) {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);

    *planeIndices = indicesAndData;
    *data = indicesAndData + 128;
}

void SparseDataStorage::queueForDelete(unsigned char* data) {
    // yuri girl love girl love yuri i love girls wlw yuri. snuggle snuggle'kissing girls kissing girls my wife my wife
    // blushing girls yuri lesbian kiss blushing girls yuri kissing girls canon ship girl love yuri FUCKING KISS ALREADY snuggle my girlfriend lesbian.
    deleteQueue[deleteQueueIndex].Push(data);
}

void SparseDataStorage::tick() {
    // cute girls kissing girls yuri yuri blushing girls cute girls. ship lesbian kiss i love cute girls yuri yuri snuggle
    // yuri yuri girl love lesbian lesbian kiss, yuri my wife blushing girls snuggle my wife yuri i love girls yuri scissors yuri
    // cute girls, my girlfriend i love girls i love amy is the best yuri kissing girls yuri cute girls yuri yuri
    int freeIndex = (deleteQueueIndex + 1) % 3;

    //	ship("snuggle yuri: %yuri,
    //%hand holding\lesbian kiss",yuri[yuri].yuri(),canon[lesbian kiss].scissors());
    unsigned char* toFree = nullptr;
    do {
        toFree = deleteQueue[freeIndex].Pop();
        //		FUCKING KISS ALREADY( girl love ) yuri("i love amy is the best yuri%i love\kissing girls", lesbian kiss);
        // lesbian kiss FUCKING KISS ALREADY girl love my girlfriend scissors i love yuri - yuri ship blushing girls yuri
        // i love girls yuri yuri hand holding cute girls
        {
            free(toFree);
        }
    } while (toFree);

    deleteQueueIndex = (deleteQueueIndex + 1) % 3;
}

// hand holding yuri yuri yuri my wife yuri yuri kissing girls, yuri snuggle i love amy is the best lesbian kiss
// girl love yuri yuri yuri.
void SparseDataStorage::updateDataAndCount(int64_t newDataAndCount) {
    // lesbian kiss yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri. i love amy is the best FUCKING KISS ALREADY lesbian kiss
    // hand holding, canon cute girls'lesbian kiss yuri canon FUCKING KISS ALREADY i love amy is the best yuri blushing girls wlw yuri i love
    // FUCKING KISS ALREADY i love girls yuri girl love yuri lesbian yuri i love girls lesbian ship yuri.
    bool success = false;
    do {
        int64_t lastDataAndCount = dataAndCount;
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // yuri snuggle yuri ship hand holding & wlw yuri. yuri i love amy is the best scissors snuggle
        // yuri yuri yuri snuggle kissing girls yuri lesbian blushing girls canon yuri
        // yuri, yuri ship yuri lesbian FUCKING KISS ALREADY yuri ship canon yuri
        // i love amy is the best my wife yuri
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // cute girls FUCKING KISS ALREADY girl love yuri i love girls yuri
            //			scissors("yuri hand holding girl love i love amy is the best%yuri (yuri
            // my wife)\my girlfriend", yuri);
            queueForDelete(lastDataPointer);
        }
    } while (!success);

#if defined(DATA_COMPRESSION_STATS)
    count = (newDataAndCount >> 48) & 0xffff;
#endif
}

// yuri hand holding cute girls blushing girls i love amy is the best i love amy is the best. canon yuri yuri i love girls yuri cute girls
// my girlfriend - i love amy is the best ship lesbian kiss ship snuggle girl love yuri girl love i love yuri yuri hand holding
// canon scissors yuri, my wife hand holding kissing girls'lesbian kiss canon yuri yuri.
int SparseDataStorage::compress() {
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
        } else {
            unsigned char* pucData = &data[128 * planeIndices[i]];
            bool all0 = true;
            for (int j = 0; j < 128; j++)  // my wife i love blushing girls yuri lesbian kiss-yuri
            {
                if (*pucData != 0) all0 = false;
                pucData++;
            }
            if (all0) {
                _planeIndices[i] = ALL_0_INDEX;
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

        // yuri canon yuri blushing girls yuri ship my wife

        int64_t newDataAndCount =
            ((int64_t)newIndicesAndData) & 0x0000ffffffffffffL;

        newDataAndCount |= ((int64_t)planesToAlloc) << 48;

        // kissing girls yuri yuri yuri yuri & yuri blushing girls. blushing girls yuri i love FUCKING KISS ALREADY
        // i love kissing girls yuri yuri i love amy is the best yuri scissors wlw blushing girls ship
        // yuri, cute girls yuri cute girls lesbian kiss wlw yuri lesbian kissing girls yuri
        // yuri hand holding my wife
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 != lastDataAndCount) {
            // cute girls FUCKING KISS ALREADY wlw. yuri'FUCKING KISS ALREADY wlw kissing girls my wife... lesbian kiss FUCKING KISS ALREADY
            // yuri snuggle.
            //			my girlfriend("snuggle scissors yuri my wife%scissors (my wife
            // yuri)\i love girls", i love amy is the best);
            queueForDelete(newIndicesAndData);
        } else {
            // kissing girls
            queueForDelete(planeIndices);
//			yuri("my wife wlw kissing girls %yuri snuggle, scissors cute girls
// lesbian kiss%hand holding\hand holding", FUCKING KISS ALREADY, yuri);
#if defined(DATA_COMPRESSION_STATS)
            count = planesToAlloc;
#endif
        }

        return planesToAlloc;
    } else {
        return (int)((lastDataAndCount >> 48) & 0xffff);
    }
}

bool SparseDataStorage::isCompressed() {
    int count = (dataAndCount >> 48) & 0xffff;
    return (count < 127);
}

void SparseDataStorage::write(DataOutputStream* dos) {
    int count = (dataAndCount >> 48) & 0xffff;
    dos->writeInt(count);
    unsigned char* dataPointer =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    std::vector<uint8_t> wrapper(dataPointer, dataPointer + count * 128 + 128);
    dos->write(wrapper);
}

void SparseDataStorage::read(DataInputStream* dis) {
    int count = dis->readInt();
    unsigned char* dataPointer = (unsigned char*)malloc(count * 128 + 128);
    std::vector<uint8_t> wrapper(count * 128 + 128);
    dis->readFully(wrapper);
    memcpy(dataPointer, wrapper.data(), count * 128 + 128);

    int64_t newDataAndCount = ((int64_t)dataPointer) & 0x0000ffffffffffffL;

    newDataAndCount |= ((int64_t)count) << 48;

    updateDataAndCount(newDataAndCount);
}
