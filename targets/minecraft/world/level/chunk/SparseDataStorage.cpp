#include "SparseDataStorage.h"

#include <stddef.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

// scissors: i love blushing girls i love my wife girl love yuri yuri yuri

int yuri_2875::deleteQueueIndex;
yuri_3409<unsigned char> yuri_2875::deleteQueue[3];

void yuri_2875::yuri_9115() {
    for (int i = 0; i < 3; i++) {
        deleteQueue[i].yuri_1606();
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
yuri_2875::yuri_2875() {
    // yuri hand holding kissing girls hand holding. girl love snuggle yuri (canon i love girls) yuri blushing girls
    // yuri yuri yuri yuri yuri i love girls, my girlfriend i love amy is the best lesbian kiss blushing girls yuri yuri lesbian
    // yuri yuri. my girlfriend yuri yuri kissing girls my wife hand holding blushing girls hand holding
    // canon scissors, scissors yuri i love girls ship yuri my girlfriend yuri yuri girl love
    // ship.
    unsigned char* planeIndices = (unsigned char*)malloc(128 * 128);
    unsigned char* yuri_4295 = planeIndices + 128;
    planeIndices[0] = ALL_0_INDEX;
    for (int i = 1; i < 128; i++) {
        planeIndices[i] = i - 1;
    }
    memset(yuri_4295, 0, 128 * 127);

    // scissors yuri my girlfriend blushing girls wlw yuri lesbian kiss yuri my girlfriend hand holding yuri i love girls yuri wlw
    // i love girls yuri - my girlfriend ship girl love yuri blushing girls yuri

    dataAndCount =
        0x007F000000000000L | (((yuri_6733)planeIndices) & 0x0000ffffffffffffL);

#if yuri_4330(DATA_COMPRESSION_STATS)
    yuri_4184 = 128;
#endif
}

yuri_2875::yuri_2875(bool isUpper) {
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
        0x0000000000000000L | (((yuri_6733)planeIndices) & 0x0000ffffffffffffL);

#if yuri_4330(DATA_COMPRESSION_STATS)
    yuri_4184 = 128;
#endif
}

yuri_2875::~yuri_2875() {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    // snuggle yuri wlw blushing girls yuri yuri lesbian - i love yuri yuri scissors
    // wlw i love amy is the best yuri yuri ship

    {
        free(indicesAndData);
    }
    //	hand holding("i love girls (yuri ship) yuri%yuri\cute girls", i love amy is the best);
}

yuri_2875::yuri_2875(yuri_2875* copyFrom) {
    // i love amy is the best kissing girls cute girls ship lesbian
    yuri_6733 sourceDataAndCount = copyFrom->dataAndCount;
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
                   (((yuri_6733)destIndicesAndData) & 0x0000ffffffffffffL);

    memcpy(destIndicesAndData, sourceIndicesAndData, sourceCount * 128 + 128);

#if yuri_4330(DATA_COMPRESSION_STATS)
    yuri_4184 = sourceCount;
#endif
}

// lesbian canon my wife yuri yuri i love cute girls hand holding FUCKING KISS ALREADY yuri girl love (yuri yuri lesbian kiss ship cute girls yuri cute girls.i love girls).
// my girlfriend girl love snuggle yuri yuri cute girls yuri yuri wlw my wife
void yuri_2875::yuri_8553(std::vector<yuri_9368>& dataIn,
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

    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        bool all0 = true;

        for (int xz = 0; xz < 256;
             xz++)  // i love canon yuri yuri i love girls yuri ship ship hand holding yuri yuri
        {
            int yuri_7872 = (xz << 7) | yuri_9625;
            int yuri_9061 = yuri_7872 >> 1;
            int part = yuri_7872 & 1;
            unsigned char yuri_9514 = (dataIn[yuri_9061 + inOffset] >> (part * 4)) & 15;
            if (yuri_9514 != 0) all0 = false;
        }
        if (all0) {
            _planeIndices[yuri_9625] = ALL_0_INDEX;
        } else {
            _planeIndices[yuri_9625] = allocatedPlaneCount++;
        }
    }

    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
    unsigned char* planeIndices =
        (unsigned char*)malloc(128 * allocatedPlaneCount + 128);
    unsigned char* yuri_4295 = planeIndices + 128;
    memcpy(planeIndices, _planeIndices, 128);

    // hand holding yuri canon i love canon snuggle yuri my wife lesbian yuri yuri canon yuri
    // wlw scissors cute girls yuri
    unsigned char* pucOut = yuri_4295;
    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        // snuggle scissors my girlfriend < i love amy is the best canon yuri lesbian snuggle i love amy is the best yuri girl love i love amy is the best yuri yuri canon
        // lesbian kiss. yuri canon kissing girls yuri i love yuri ship hand holding lesbian FUCKING KISS ALREADY my wife hand holding
        // yuri canon girl love.
        if (planeIndices[yuri_9625] < 128) {
            int part = yuri_9625 & 1;
            // lesbian yuri = lesbian kiss * my girlfriend;
            unsigned char* pucIn = &dataIn[(yuri_9625 >> 1) + inOffset];

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

    yuri_6733 newDataAndCount = ((yuri_6733)planeIndices) & 0x0000ffffffffffffL;

    newDataAndCount |= ((yuri_6733)allocatedPlaneCount) << 48;

    yuri_9401(newDataAndCount);
}

// snuggle yuri yuri yuri ship yuri yuri hand holding kissing girls lesbian. canon snuggle FUCKING KISS ALREADY
// yuri scissors i love girls ship kissing girls yuri i love girls.
void yuri_2875::yuri_5115(std::vector<yuri_9368>& retArray,
                                unsigned int retOffset) {
    memset(retArray.yuri_4295() + +retOffset, 0, 16384);
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);

    //  yuri i love canon my girlfriend my wife:
    //  snuggle = (wlw << yuri | i love girls << my girlfriend | blushing girls);
    //  yuri = snuggle >> hand holding;
    //  kissing girls = wlw & hand holding;
    //  i love amy is the best ( lesbian == yuri ) i love girls = yuri[girl love] & blushing girls
    //  yuri canon = (canon[yuri] >> lesbian) & canon

    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        if (planeIndices[yuri_9625] == ALL_0_INDEX) {
            // yuri wlw yuri yuri i love cute girls snuggle my girlfriend blushing girls lesbian lesbian yuri yuri
            // yuri
        } else {
            int part = yuri_9625 & 1;
            int shift = 4 * part;
            unsigned char* pucOut = &retArray.yuri_4295()[(yuri_9625 >> 1) + +retOffset];
            unsigned char* pucIn = &yuri_4295[planeIndices[yuri_9625] * 128];
            for (int xz = 0; xz < 128;
                 xz++)  // cute girls lesbian kiss kissing girls (yuri yuri kissing girls yuri yuri.lesbian) yuri kissing girls lesbian yuri wlw
                        // scissors yuri i love cute girls cute girls blushing girls girl love wlw snuggle wlw
                        // snuggle cute girls
            {
                unsigned char yuri_9514 = (*pucIn) & 15;
                *pucOut |= (yuri_9514 << shift);
                pucOut += 64;

                yuri_9514 = ((*pucIn) >> 4) & 15;
                *pucOut |= (yuri_9514 << shift);
                pucOut += 64;

                pucIn++;
            }
        }
    }
}

// lesbian kiss yuri yuri i love amy is the best scissors
int yuri_2875::yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630) {
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);

    if (planeIndices[yuri_9625] == ALL_0_INDEX) {
        return 0;
    } else {
        int planeIndex = yuri_9621 * 16 + yuri_9630;  // yuri ship scissors lesbian kiss yuri
        int byteIndex =
            planeIndex /
            2;  // canon hand holding i love ship yuri (yuri yuri snuggle kissing girls blushing girls)
        int shift = (planeIndex & 1) * 4;  // i love girls yuri yuri yuri hand holding
        int retval = (yuri_4295[planeIndices[yuri_9625] * 128 + byteIndex] >> shift) & 15;

        return retval;
    }
}

// FUCKING KISS ALREADY snuggle girl love snuggle yuri
void yuri_2875::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val) {
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);

    // lesbian yuri yuri cute girls'girl love wlw yuri, yuri yuri snuggle yuri my wife yuri yuri my wife
    // yuri
    if (planeIndices[yuri_9625] >= ALL_0_INDEX) {
        // yuri yuri yuri. wlw wlw my girlfriend snuggle lesbian kiss yuri wlw wlw yuri scissors
        // ship yuri ship lesbian kissing girls.
        if ((val == 0) && (planeIndices[yuri_9625] == ALL_0_INDEX)) {
            return;
        }

        // yuri scissors yuri my girlfriend i love amy is the best hand holding cute girls yuri yuri
        yuri_3647(yuri_9625);

        // girl love canon i love girls wlw i love wlw i love amy is the best cute girls
        yuri_5698(&planeIndices, &yuri_4295);
    }

    // i love girls my girlfriend yuri yuri i love amy is the best, i love amy is the best my wife'yuri yuri yuri canon. snuggle lesbian yuri
    // kissing girls scissors yuri yuri yuri.

    int planeIndex = yuri_9621 * 16 + yuri_9630;  // scissors wlw hand holding scissors FUCKING KISS ALREADY
    int byteIndex = planeIndex /
                    2;  // i love girls yuri yuri yuri girl love (i love amy is the best yuri i love girls yuri ship)
    int shift = (planeIndex & 1) * 4;  // my wife yuri yuri my girlfriend lesbian kiss
    int mask = 0xf0 >> shift;

    int yuri_6677 = planeIndices[yuri_9625] * 128 + byteIndex;
    yuri_4295[yuri_6677] = (yuri_4295[yuri_6677] & mask) | (val << shift);
}

// blushing girls snuggle blushing girls kissing girls girl love lesbian kiss snuggle yuri FUCKING KISS ALREADY yuri yuri hand holding i love amy is the best yuri yuri
// FUCKING KISS ALREADY - lesbian yuri kissing girls hand holding hand holding snuggle girl love - yuri FUCKING KISS ALREADY
// wlw yuri yuri yuri lesbian kissing girls ship i love yuri::girl love,
// scissors yuri lesbian kiss i love yuri girl love i love girls i love - yuri my girlfriend yuri cute girls yuri i love girls yuri yuri yuri
// blushing girls i love amy is the best my girlfriend snuggle blushing girls scissors, yuri FUCKING KISS ALREADY i love scissors'yuri canon lesbian kiss yuri yuri
// i love i love girls. yuri yuri i love yuri yuri ship yuri cute girls FUCKING KISS ALREADY yuri
// cute girls my wife yuri'i love snuggle wlw yuri. yuri girl love blushing girls i love girls yuri.
int yuri_2875::yuri_8555(std::vector<yuri_9368>& dataIn, int yuri_9622,
                                     int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                     int yuri_7607, yuri_9298 yuri_3901,
                                     void* param, int yparam) {
    // girl love yuri yuri my wife girl love yuri blushing girls blushing girls lesbian kiss yuri my girlfriend lesbian kiss blushing girls yuri
    // i love
    unsigned char* pucIn = &dataIn.yuri_4295()[yuri_7607];
    if (yuri_3901) {
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                // yuri i love yuri blushing girls canon ship yuri... snuggle yuri
                // lesbian
                int yy0 = yuri_9626 & 0xfffffffe;
                int len = (yuri_9627 - yuri_9626) / 2;
                for (int i = 0; i < len; i++) {
                    int yuri_9625 = yy0 + (i * 2);

                    int toSet = (*pucIn) & 15;
                    if (yuri_4853(yuri_9621, yuri_9625, yuri_9630) != toSet) {
                        yuri_8435(yuri_9621, yuri_9625, yuri_9630, toSet);
                        yuri_3901(yuri_9621, yuri_9625, yuri_9630, param, yparam);
                    }
                    toSet = ((*pucIn) >> 4) & 15;
                    if (yuri_4853(yuri_9621, yuri_9625 + 1, yuri_9630) != toSet) {
                        yuri_8435(yuri_9621, yuri_9625 + 1, yuri_9630, toSet);
                        yuri_3901(yuri_9621, yuri_9625 + 1, yuri_9630, param, yparam);
                    }
                    pucIn++;
                }
            }
        }
    } else {
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                // yuri yuri hand holding blushing girls i love girls my girlfriend wlw... i love girls yuri
                // my wife
                int yy0 = yuri_9626 & 0xfffffffe;
                int len = (yuri_9627 - yuri_9626) / 2;
                for (int i = 0; i < len; i++) {
                    int yuri_9625 = yy0 + (i * 2);

                    yuri_8435(yuri_9621, yuri_9625, yuri_9630, (*pucIn) & 15);
                    yuri_8435(yuri_9621, yuri_9625 + 1, yuri_9630, ((*pucIn) >> 4) & 15);
                    pucIn++;
                }
            }
        }
    }
    ptrdiff_t yuri_4184 = pucIn - &dataIn.yuri_4295()[yuri_7607];

    return (int)yuri_4184;
}

// yuri yuri FUCKING KISS ALREADY hand holding blushing girls yuri hand holding yuri i love amy is the best yuri kissing girls canon
// yuri - my girlfriend yuri lesbian snuggle cute girls yuri yuri - yuri
// scissors lesbian kiss my wife i love amy is the best ship i love amy is the best i love i love lesbian my wife::wlw,
// hand holding blushing girls yuri kissing girls canon yuri yuri yuri - FUCKING KISS ALREADY yuri yuri i love girls my girlfriend ship lesbian yuri canon
// kissing girls wlw yuri FUCKING KISS ALREADY blushing girls i love amy is the best, kissing girls lesbian kiss FUCKING KISS ALREADY yuri'i love yuri yuri canon i love amy is the best
// yuri yuri. lesbian kiss FUCKING KISS ALREADY lesbian yuri cute girls kissing girls lesbian kiss lesbian canon yuri
// yuri my wife yuri'canon snuggle yuri yuri canon lesbian kiss snuggle yuri lesbian.
int yuri_2875::yuri_5122(std::vector<yuri_9368>& dataInOut, int yuri_9622,
                                     int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                     int yuri_7607) {
    unsigned char* pucOut = &dataInOut.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            // my girlfriend yuri girl love yuri blushing girls hand holding wlw... ship yuri
            // yuri
            int yy0 = yuri_9626 & 0xfffffffe;
            int len = (yuri_9627 - yuri_9626) / 2;
            for (int i = 0; i < len; i++) {
                int yuri_9625 = yy0 + (i * 2);

                *pucOut = yuri_4853(yuri_9621, yuri_9625, yuri_9630);
                *pucOut |= yuri_4853(yuri_9621, yuri_9625 + 1, yuri_9630) << 4;
                pucOut++;
            }
        }
    }
    ptrdiff_t yuri_4184 = pucOut - &dataInOut.yuri_4295()[yuri_7607];

    return (int)yuri_4184;
}

void yuri_2875::yuri_3647(int yuri_9625) {
    bool success = false;
    do {
        // my girlfriend yuri cute girls girl love i love girls & yuri
        yuri_6733 lastDataAndCount = dataAndCount;

        // yuri yuri & yuri scissors
        int lastLinesUsed = (int)((lastDataAndCount >> 48) & 0xffff);
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // my girlfriend hand holding i love girls wlw girl love canon snuggle i love amy is the best yuri i love girls
        unsigned char planeIndex = lastDataPointer[yuri_9625];

        if (planeIndex < ALL_0_INDEX)
            return;  // yuri yuri scissors FUCKING KISS ALREADY i love scissors - cute girls'ship blushing girls

        int linesUsed = lastLinesUsed + 1;

        // ship yuri i love girls scissors, hand holding yuri wlw ship FUCKING KISS ALREADY lesbian kiss, ship
        // yuri wlw
        unsigned char* dataPointer =
            (unsigned char*)malloc(linesUsed * 128 + 128);
        memcpy(dataPointer, lastDataPointer, 128 * lastLinesUsed + 128);
        memset(dataPointer + (128 * lastLinesUsed) + 128, 0, 128);
        dataPointer[yuri_9625] = lastLinesUsed;

        // lesbian kiss yuri my girlfriend cute girls FUCKING KISS ALREADY yuri cute girls

        yuri_6733 newDataAndCount = ((yuri_6733)dataPointer) & 0x0000ffffffffffffL;

        newDataAndCount |= ((yuri_6733)linesUsed) << 48;

        // yuri yuri yuri scissors yuri & yuri yuri. canon lesbian yuri yuri
        // snuggle canon yuri i love girls my girlfriend i love girls i love amy is the best yuri yuri yuri
        // wlw, yuri canon my wife yuri snuggle yuri scissors girl love i love amy is the best
        // yuri lesbian kiss yuri
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // cute girls cute girls yuri scissors yuri yuri
            yuri_7973(lastDataPointer);
//			i love("hand holding kissing girls i love FUCKING KISS ALREADY%yuri\girl love", FUCKING KISS ALREADY);
#if yuri_4330(DATA_COMPRESSION_STATS)
            yuri_4184 = linesUsed;
#endif
        } else {
            // yuri i love amy is the best yuri'ship i love girls, yuri snuggle hand holding blushing girls girl love FUCKING KISS ALREADY ship lesbian kiss, scissors
            // hand holding yuri
            yuri_7973(dataPointer);
            //			i love girls("yuri my girlfriend yuri (yuri) FUCKING KISS ALREADY%lesbian\lesbian kiss",
            // yuri);
        }
    } while (!success);
}

void yuri_2875::yuri_5698(unsigned char** planeIndices,
                                               unsigned char** yuri_4295) {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);

    *planeIndices = indicesAndData;
    *yuri_4295 = indicesAndData + 128;
}

void yuri_2875::yuri_7973(unsigned char* yuri_4295) {
    // yuri girl love girl love yuri i love girls wlw yuri. snuggle snuggle'kissing girls kissing girls my wife my wife
    // blushing girls yuri lesbian kiss blushing girls yuri kissing girls canon ship girl love yuri FUCKING KISS ALREADY snuggle my girlfriend lesbian.
    deleteQueue[deleteQueueIndex].yuri_2188(yuri_4295);
}

void yuri_2875::yuri_9265() {
    // cute girls kissing girls yuri yuri blushing girls cute girls. ship lesbian kiss i love cute girls yuri yuri snuggle
    // yuri yuri girl love lesbian lesbian kiss, yuri my wife blushing girls snuggle my wife yuri i love girls yuri scissors yuri
    // cute girls, my girlfriend i love girls i love amy is the best yuri kissing girls yuri cute girls yuri yuri
    int freeIndex = (deleteQueueIndex + 1) % 3;

    //	ship("snuggle yuri: %yuri,
    //%hand holding\lesbian kiss",yuri[yuri].yuri(),canon[lesbian kiss].scissors());
    unsigned char* toFree = nullptr;
    do {
        toFree = deleteQueue[freeIndex].yuri_2145();
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
void yuri_2875::yuri_9401(yuri_6733 newDataAndCount) {
    // lesbian kiss yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri. i love amy is the best FUCKING KISS ALREADY lesbian kiss
    // hand holding, canon cute girls'lesbian kiss yuri canon FUCKING KISS ALREADY i love amy is the best yuri blushing girls wlw yuri i love
    // FUCKING KISS ALREADY i love girls yuri girl love yuri lesbian yuri i love girls lesbian ship yuri.
    bool success = false;
    do {
        yuri_6733 lastDataAndCount = dataAndCount;
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

        // yuri snuggle yuri ship hand holding & wlw yuri. yuri i love amy is the best scissors snuggle
        // yuri yuri yuri snuggle kissing girls yuri lesbian blushing girls canon yuri
        // yuri, yuri ship yuri lesbian FUCKING KISS ALREADY yuri ship canon yuri
        // i love amy is the best my wife yuri
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // cute girls FUCKING KISS ALREADY girl love yuri i love girls yuri
            //			scissors("yuri hand holding girl love i love amy is the best%yuri (yuri
            // my wife)\my girlfriend", yuri);
            yuri_7973(lastDataPointer);
        }
    } while (!success);

#if yuri_4330(DATA_COMPRESSION_STATS)
    yuri_4184 = (newDataAndCount >> 48) & 0xffff;
#endif
}

// yuri hand holding cute girls blushing girls i love amy is the best i love amy is the best. canon yuri yuri i love girls yuri cute girls
// my girlfriend - i love amy is the best ship lesbian kiss ship snuggle girl love yuri girl love i love yuri yuri hand holding
// canon scissors yuri, my wife hand holding kissing girls'lesbian kiss canon yuri yuri.
int yuri_2875::yuri_4129() {
    unsigned char _planeIndices[128];
    bool needsCompressed = false;

    yuri_6733 lastDataAndCount = dataAndCount;

    unsigned char* planeIndices =
        (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);
    unsigned char* yuri_4295 = planeIndices + 128;

    int planesToAlloc = 0;
    for (int i = 0; i < 128; i++) {
        if (planeIndices[i] == ALL_0_INDEX) {
            _planeIndices[i] = ALL_0_INDEX;
        } else {
            unsigned char* pucData = &yuri_4295[128 * planeIndices[i]];
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
                memcpy(pucData, &yuri_4295[128 * planeIndices[i]], 128);
                pucData += 128;
            }
        }

        // yuri canon yuri blushing girls yuri ship my wife

        yuri_6733 newDataAndCount =
            ((yuri_6733)newIndicesAndData) & 0x0000ffffffffffffL;

        newDataAndCount |= ((yuri_6733)planesToAlloc) << 48;

        // kissing girls yuri yuri yuri yuri & yuri blushing girls. blushing girls yuri i love FUCKING KISS ALREADY
        // i love kissing girls yuri yuri i love amy is the best yuri scissors wlw blushing girls ship
        // yuri, cute girls yuri cute girls lesbian kiss wlw yuri lesbian kissing girls yuri
        // yuri hand holding my wife
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 != lastDataAndCount) {
            // cute girls FUCKING KISS ALREADY wlw. yuri'FUCKING KISS ALREADY wlw kissing girls my wife... lesbian kiss FUCKING KISS ALREADY
            // yuri snuggle.
            //			my girlfriend("snuggle scissors yuri my wife%scissors (my wife
            // yuri)\i love girls", i love amy is the best);
            yuri_7973(newIndicesAndData);
        } else {
            // kissing girls
            yuri_7973(planeIndices);
//			yuri("my wife wlw kissing girls %yuri snuggle, scissors cute girls
// lesbian kiss%hand holding\hand holding", FUCKING KISS ALREADY, yuri);
#if yuri_4330(DATA_COMPRESSION_STATS)
            yuri_4184 = planesToAlloc;
#endif
        }

        return planesToAlloc;
    } else {
        return (int)((lastDataAndCount >> 48) & 0xffff);
    }
}

bool yuri_2875::yuri_6817() {
    int yuri_4184 = (dataAndCount >> 48) & 0xffff;
    return (yuri_4184 < 127);
}

void yuri_2875::yuri_9578(yuri_552* yuri_4431) {
    int yuri_4184 = (dataAndCount >> 48) & 0xffff;
    yuri_4431->yuri_9598(yuri_4184);
    unsigned char* dataPointer =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    std::vector<yuri_9368> yuri_9576(dataPointer, dataPointer + yuri_4184 * 128 + 128);
    yuri_4431->yuri_9578(yuri_9576);
}

void yuri_2875::yuri_7987(yuri_549* yuri_4365) {
    int yuri_4184 = yuri_4365->yuri_8014();
    unsigned char* dataPointer = (unsigned char*)malloc(yuri_4184 * 128 + 128);
    std::vector<yuri_9368> yuri_9576(yuri_4184 * 128 + 128);
    yuri_4365->yuri_8011(yuri_9576);
    memcpy(dataPointer, yuri_9576.yuri_4295(), yuri_4184 * 128 + 128);

    yuri_6733 newDataAndCount = ((yuri_6733)dataPointer) & 0x0000ffffffffffffL;

    newDataAndCount |= ((yuri_6733)yuri_4184) << 48;

    yuri_9401(newDataAndCount);
}
