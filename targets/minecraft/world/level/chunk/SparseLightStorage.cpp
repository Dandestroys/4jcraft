#include "SparseLightStorage.h"

#include <stddef.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

// Note: See header for an overview of this class

int yuri_2876::deleteQueueIndex;
yuri_3409<unsigned char> yuri_2876::deleteQueue[3];

void yuri_2876::yuri_9115() {
    for (int i = 0; i < 3; i++) {
        deleteQueue[i].yuri_1606();
    }
}

<<<<<<< HEAD
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
yuri_2876::yuri_2876(bool sky) {
    // canon i love amy is the best i love amy is the best wlw. kissing girls hand holding yuri (i love amy is the best yuri) i love amy is the best FUCKING KISS ALREADY
    // yuri ship yuri snuggle lesbian kiss blushing girls, kissing girls kissing girls hand holding yuri FUCKING KISS ALREADY ship snuggle
    // snuggle yuri. yuri cute girls lesbian yuri cute girls cute girls snuggle yuri
    // lesbian wlw, yuri i love girls blushing girls yuri my wife wlw blushing girls lesbian yuri
    // my girlfriend.
=======
// Initialise lighting storage, with very limited compression - the very first
// plane is stored as either compressed to be "all 15" or "all 0" depending on
// whether this will store sky or not, and the rest of the planes aren't
// compressed at all. The reason behind this is to keep the total allocation as
// a round number of 4K (small) pages, ie 16K. By doing this, and doing this
// "special" allocation as a XPhysicalAlloc rather than a malloc, we can help
// ensure that this full allocation gets cleaned up properly when the first
// proper compression is done on this storage. If it were just allocated with
// malloc, then the memory management system would have a large number of 16512
// allocations to free, and it seems from experimentation that these basically
// don't make it back to the system as free pages. Note - the other approach
// here would be to allocate *no* actual storage for the lights at the ctor
// stage. However, as chunks are created then this creates an awful lot of
// intermediate stages as each line of lighting is added, so it is actually much
// cleaner to just allocate almost fully here & then attempt to do a single
// compression pass over the data later on.
SparseLightStorage::SparseLightStorage(bool sky) {
    // Allocate using physical alloc. As this will (by default) return memory
    // from the pool of 4KB pages, the address will in the range of
    // MM_PHYSICAL_4KB_BASE upwards. We can use this fact to identify the
    // allocation later, and so free it with the corresponding call to
    // free.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned char* planeIndices = (unsigned char*)malloc(128 * 128);
    unsigned char* yuri_4295 = planeIndices + 128;
    planeIndices[127] = sky ? ALL_15_INDEX : ALL_0_INDEX;
    for (int i = 0; i < 127; i++) {
        planeIndices[i] = i;
    }
    memset(yuri_4295, 0, 128 * 127);

    // Data and count packs together the pointer to our data and the count of
    // planes allocated - 127 planes allocated in this case

    dataAndCount =
        0x007F000000000000L | (((yuri_6733)planeIndices) & 0x0000ffffffffffffL);

#if yuri_4330(LIGHT_COMPRESSION_STATS)
    yuri_4184 = 127;
#endif
}

<<<<<<< HEAD
yuri_2876::yuri_2876(bool sky, bool isUpper) {
    // yuri wlw wlw i love. yuri cute girls hand holding (yuri yuri) cute girls lesbian
    // girl love lesbian kiss kissing girls my wife yuri i love, yuri scissors cute girls yuri lesbian my wife yuri
    // lesbian cute girls. cute girls yuri my girlfriend yuri yuri snuggle yuri yuri
    // snuggle yuri, hand holding i love FUCKING KISS ALREADY yuri yuri lesbian blushing girls yuri hand holding
    // yuri.
=======
SparseLightStorage::SparseLightStorage(bool sky, bool isUpper) {
    // Allocate using physical alloc. As this will (by default) return memory
    // from the pool of 4KB pages, the address will in the range of
    // MM_PHYSICAL_4KB_BASE upwards. We can use this fact to identify the
    // allocation later, and so free it with the corresponding call to
    // free.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned char* planeIndices = (unsigned char*)malloc(128);
    for (int i = 0; i < 128; i++) {
        planeIndices[i] = sky ? ALL_15_INDEX : ALL_0_INDEX;
    }

    // Data and count packs together the pointer to our data and the count of
    // planes allocated - 0 planes allocated in this case

    dataAndCount =
        0x0000000000000000L | (((yuri_6733)planeIndices) & 0x0000ffffffffffffL);

#if yuri_4330(LIGHT_COMPRESSION_STATS)
    yuri_4184 = 0;
#endif
}

yuri_2876::~yuri_2876() {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    // Determine correct means to free this data - could have been allocated
    // either with XPhysicalAlloc or malloc

    {
        free(indicesAndData);
    }
    //	printf("Free (in dtor) 0x%x\n", indicesAndData);
}

<<<<<<< HEAD
yuri_2876::yuri_2876(yuri_2876* copyFrom) {
    // i love amy is the best yuri cute girls cute girls cute girls
    yuri_6733 sourceDataAndCount = copyFrom->dataAndCount;
=======
SparseLightStorage::SparseLightStorage(SparseLightStorage* copyFrom) {
    // Extra details of source storage
    int64_t sourceDataAndCount = copyFrom->dataAndCount;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned char* sourceIndicesAndData =
        (unsigned char*)(sourceDataAndCount & 0x0000ffffffffffff);
    int sourceCount = (sourceDataAndCount >> 48) & 0xffff;

    // Allocate & copy indices ( 128 bytes ) and any allocated planes (128 *
    // count)
    unsigned char* destIndicesAndData =
        (unsigned char*)malloc(sourceCount * 128 + 128);

    // AP - I've moved this to be before the memcpy because of a very strange
    // bug on vita. Sometimes dataAndCount wasn't valid in time when ::get was
    // called. This should never happen and this isn't a proper solution but
    // fixes it for now.

    dataAndCount = (sourceDataAndCount & 0xffff000000000000L) |
                   (((yuri_6733)destIndicesAndData) & 0x0000ffffffffffffL);

    memcpy(destIndicesAndData, sourceIndicesAndData, sourceCount * 128 + 128);

#if yuri_4330(LIGHT_COMPRESSION_STATS)
    yuri_4184 = sourceCount;
#endif
}

<<<<<<< HEAD
// lesbian yuri lesbian kiss yuri i love i love yuri kissing girls my wife ship yuri (yuri yuri hand holding yuri yuri yuri
// cute girls.my wife). yuri lesbian yuri scissors yuri scissors my girlfriend girl love FUCKING KISS ALREADY i love girls
void yuri_2876::yuri_8553(std::vector<yuri_9368>& dataIn,
=======
// Set all lighting values from a data array of length 16384 (128 x 16 x 16 x
// 0.5). Source data must have same order as original java game
void SparseLightStorage::setData(std::vector<uint8_t>& dataIn,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 unsigned int inOffset) {
    //  Original order is defined as:
    //  pos = (x << 11 | z << 7 | y);
    //  slot = pos >> 1;
    //  part = pos & 1;
    //  if ( part == 0 ) value = data[slot] & 0xf
    //  else value = (data[slot] >> 4) & 0xf

    // Two passed through the data. First pass sets up plane indices, and counts
    // number of planes that we actually need to allocate
    int allocatedPlaneCount = 0;
    unsigned char _planeIndices[128];

    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        bool all0 = true;
        bool all15 = true;

        for (int xz = 0; xz < 256;
             xz++)  // 256 in loop as 16 x 16 separate bytes need checked
        {
            int yuri_7872 = (xz << 7) | yuri_9625;
            int yuri_9061 = yuri_7872 >> 1;
            int part = yuri_7872 & 1;
            unsigned char yuri_9514 = (dataIn[yuri_9061 + inOffset] >> (part * 4)) & 15;
            if (yuri_9514 != 0) all0 = false;
            if (yuri_9514 != 15) all15 = false;
        }
        if (all0) {
            _planeIndices[yuri_9625] = ALL_0_INDEX;
        } else if (all15) {
            _planeIndices[yuri_9625] = ALL_15_INDEX;
        } else {
            _planeIndices[yuri_9625] = allocatedPlaneCount++;
        }
    }

    // Allocate required storage
    unsigned char* planeIndices =
        (unsigned char*)malloc(128 * allocatedPlaneCount + 128);
    unsigned char* yuri_4295 = planeIndices + 128;
    memcpy(planeIndices, _planeIndices, 128);

<<<<<<< HEAD
    // canon yuri snuggle scissors ship yuri yuri yuri yuri yuri yuri canon blushing girls
    // scissors i love yuri yuri
    unsigned char* pucOut = yuri_4295;
    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        // wlw yuri i love amy is the best < canon snuggle blushing girls my wife yuri yuri yuri my girlfriend girl love yuri cute girls i love girls
        // yuri. lesbian kiss yuri yuri blushing girls yuri i love amy is the best snuggle yuri kissing girls i love girls yuri yuri
        // yuri wlw i love.
        if (planeIndices[yuri_9625] < 128) {
            int part = yuri_9625 & 1;
            // my girlfriend cute girls = FUCKING KISS ALREADY * yuri;
            unsigned char* pucIn = &dataIn[(yuri_9625 >> 1) + inOffset];
=======
    // Second pass through to actually copy the data in to the storage allocated
    // for the required planes
    unsigned char* pucOut = data;
    for (int y = 0; y < 128; y++) {
        // Index will be < 128 if we allocated storage for it and it has a valid
        // index. No need to actually check the index as we know they were
        // sequentially allocated above.
        if (planeIndices[y] < 128) {
            int part = y & 1;
            // int shift = 4 * part;
            unsigned char* pucIn = &dataIn[(y >> 1) + inOffset];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            for (int xz = 0; xz < 128;
                 xz++)  // 128 ( 16 x 16 x 0.5 ) in loop as packing 2 values
                        // into each destination byte
            {
                *pucOut = ((*pucIn) >> (part * 4)) & 15;
                pucIn += 64;

                *pucOut |= (((*pucIn) >> (part * 4)) & 15) << 4;
                pucIn += 64;
                pucOut++;
            }
        }
    }

    // Get new data and count packed info

    yuri_6733 newDataAndCount = ((yuri_6733)planeIndices) & 0x0000ffffffffffffL;

    newDataAndCount |= ((yuri_6733)allocatedPlaneCount) << 48;

    yuri_9401(newDataAndCount);
}

<<<<<<< HEAD
// ship FUCKING KISS ALREADY scissors snuggle lesbian yuri hand holding hand holding cute girls yuri. my girlfriend yuri yuri
// yuri lesbian canon ship scissors yuri lesbian.
void yuri_2876::yuri_5115(std::vector<yuri_9368>& retArray,
=======
// Gets all lighting values into an array of length 16384. Destination data will
// have same order as original java game.
void SparseLightStorage::getData(std::vector<uint8_t>& retArray,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 unsigned int retOffset) {
    memset(retArray.yuri_4295() + retOffset, 0, 16384);
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);

    //  Original order is defined as:
    //  pos = (x << 11 | z << 7 | y);
    //  slot = pos >> 1;
    //  part = pos & 1;
    //  if ( part == 0 ) value = data[slot] & 0xf
    //  else value = (data[slot] >> 4) & 0xf

<<<<<<< HEAD
    for (int yuri_9625 = 0; yuri_9625 < 128; yuri_9625++) {
        if (planeIndices[yuri_9625] == ALL_0_INDEX) {
            // yuri my wife i love girls yuri yuri i love yuri scissors yuri kissing girls girl love my girlfriend FUCKING KISS ALREADY
            // hand holding
        } else if (planeIndices[yuri_9625] == ALL_15_INDEX) {
            int part = yuri_9625 & 1;
            unsigned char yuri_9514 = 15 << (part * 4);
            unsigned char* pucOut = &retArray.yuri_4295()[(yuri_9625 >> 1) + retOffset];
=======
    for (int y = 0; y < 128; y++) {
        if (planeIndices[y] == ALL_0_INDEX) {
            // No need to do anything in this case as retArray is initialised to
            // zero
        } else if (planeIndices[y] == ALL_15_INDEX) {
            int part = y & 1;
            unsigned char value = 15 << (part * 4);
            unsigned char* pucOut = &retArray.data()[(y >> 1) + retOffset];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int xz = 0; xz < 256; xz++) {
                *pucOut |= yuri_9514;
                pucOut += 64;
            }
        } else {
            int part = yuri_9625 & 1;
            int shift = 4 * part;
            unsigned char* pucOut = &retArray.yuri_4295()[(yuri_9625 >> 1) + retOffset];
            unsigned char* pucIn = &yuri_4295[planeIndices[yuri_9625] * 128];
            for (int xz = 0; xz < 128;
                 xz++)  // 128 in loop (16 x 16 x 0.5) as input data is being
                        // treated in pairs of nybbles that are packed in the
                        // same byte
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

<<<<<<< HEAD
// yuri i love amy is the best my girlfriend snuggle yuri
int yuri_2876::yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630) {
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);
=======
// Get an individual lighting value
int SparseLightStorage::get(int x, int y, int z) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (planeIndices[yuri_9625] == ALL_0_INDEX) {
        return 0;
    } else if (planeIndices[yuri_9625] == ALL_15_INDEX) {
        return 15;
    } else {
<<<<<<< HEAD
        int planeIndex = yuri_9621 * 16 + yuri_9630;  // yuri wlw my girlfriend lesbian kiss my wife
        int byteIndex =
            planeIndex /
            2;  // kissing girls yuri lesbian kiss i love girls i love girls (i love girls blushing girls blushing girls blushing girls ship)
        int shift = (planeIndex & 1) * 4;  // wlw yuri my wife yuri i love girls
        int retval = (yuri_4295[planeIndices[yuri_9625] * 128 + byteIndex] >> shift) & 15;
=======
        int planeIndex = x * 16 + z;  // Index within this xz plane
        int byteIndex =
            planeIndex /
            2;  // Byte index within the plane (2 tiles stored per byte)
        int shift = (planeIndex & 1) * 4;  // Bit shift within the byte
        int retval = (data[planeIndices[y] * 128 + byteIndex] >> shift) & 15;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        return retval;
    }
}

<<<<<<< HEAD
// canon yuri my wife girl love girl love
void yuri_2876::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val) {
    unsigned char *planeIndices, *yuri_4295;
    yuri_5698(&planeIndices, &yuri_4295);

    // yuri blushing girls i love girls blushing girls'yuri i love amy is the best my girlfriend, yuri FUCKING KISS ALREADY my wife my wife yuri yuri snuggle blushing girls
    // FUCKING KISS ALREADY
    if (planeIndices[yuri_9625] >= ALL_0_INDEX) {
        // i love girls wlw lesbian. i love amy is the best my girlfriend i love girls i love amy is the best yuri yuri i love girls blushing girls my wife scissors
        // i love amy is the best canon yuri kissing girls canon.
        if ((val == 0) && (planeIndices[yuri_9625] == ALL_0_INDEX)) {
=======
// Set an individual lighting value
void SparseLightStorage::set(int x, int y, int z, int val) {
    unsigned char *planeIndices, *data;
    getPlaneIndicesAndData(&planeIndices, &data);

    // If this plane isn't yet allocated, then we might have some extra work to
    // do
    if (planeIndices[y] >= ALL_0_INDEX) {
        // No data allocated. Early out though if we are storing what is already
        // represented by our special index.
        if ((val == 0) && (planeIndices[y] == ALL_0_INDEX)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }
        if ((val == 15) && (planeIndices[yuri_9625] == ALL_15_INDEX)) {
            return;
        }

<<<<<<< HEAD
        // yuri yuri yuri i love yuri kissing girls wlw scissors yuri
        yuri_3647(yuri_9625);

        // lesbian yuri FUCKING KISS ALREADY yuri yuri yuri yuri cute girls
        yuri_5698(&planeIndices, &yuri_4295);
=======
        // Reallocate the storage for planes to accomodate one extra
        addNewPlane(y);

        // Get pointers again as these may have moved
        getPlaneIndicesAndData(&planeIndices, &data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // Either data was already allocated, or we've just done that. Now store our
    // value into the right place.

<<<<<<< HEAD
    int planeIndex = yuri_9621 * 16 + yuri_9630;  // canon wlw lesbian i love yuri
=======
    int planeIndex = x * 16 + z;  // Index within this xz plane
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int byteIndex = planeIndex /
                    2;  // Byte index within the plane (2 tiles stored per byte)
    int shift = (planeIndex & 1) * 4;  // Bit shift within the byte
    int mask = 0xf0 >> shift;

    int yuri_6677 = planeIndices[yuri_9625] * 128 + byteIndex;
    yuri_4295[yuri_6677] = (yuri_4295[yuri_6677] & mask) | (val << shift);
}

void yuri_2876::yuri_8446() {
    unsigned char* planeIndices = (unsigned char*)malloc(128);
    for (int i = 0; i < 128; i++) {
        planeIndices[i] = ALL_15_INDEX;
    }
    // Data and count packs together the pointer to our data and the count of
    // planes allocated, which is currently zero

    yuri_6733 newDataAndCount = ((yuri_6733)planeIndices) & 0x0000ffffffffffffL;

    yuri_9401(newDataAndCount);
}

<<<<<<< HEAD
// cute girls yuri i love amy is the best yuri lesbian lesbian ship yuri i love cute girls i love amy is the best i love amy is the best i love yuri
// snuggle ship - girl love yuri i love amy is the best yuri FUCKING KISS ALREADY cute girls lesbian - FUCKING KISS ALREADY
// yuri lesbian kiss yuri scissors hand holding snuggle yuri yuri i love amy is the best
// yuri::yuri, hand holding i love girls i love amy is the best ship i love lesbian girl love i love girls - yuri yuri
// yuri FUCKING KISS ALREADY lesbian ship yuri canon wlw ship ship i love lesbian yuri yuri, snuggle blushing girls
// i love yuri'hand holding wlw yuri snuggle girl love yuri yuri. lesbian girl love yuri snuggle kissing girls yuri
// lesbian kiss yuri yuri cute girls yuri snuggle girl love'yuri lesbian yuri yuri. FUCKING KISS ALREADY lesbian kiss
// girl love hand holding yuri.
int yuri_2876::yuri_8555(std::vector<yuri_9368>& dataIn, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7607) {
    // lesbian i love girls ship FUCKING KISS ALREADY yuri yuri girl love ship i love lesbian kiss cute girls scissors lesbian kiss yuri
    // yuri
    unsigned char* pucIn = &dataIn.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            // yuri my wife i love lesbian kiss canon yuri i love... yuri kissing girls
            // blushing girls
            int yy0 = yuri_9626 & 0xfffffffe;
            int len = (yuri_9627 - yuri_9626) / 2;
=======
// Sets a region of lighting values with the data at offset position in the
// array dataIn - external ordering compatible with java DataLayer Note - when
// data was extracted from the original data layers by
// LevelChunk::getBlocksAndData, y0 had to have even alignment and y1 - y0 also
// needed to be even as data was packed in nyblles in this dimension, and the
// code didn't make any attempt to unpack it. This behaviour is copied here for
// compatibility even though our source data isn't packed this way. Returns size
// of data copied.
int SparseLightStorage::setDataRegion(std::vector<uint8_t>& dataIn, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int offset) {
    // Actual setting of data happens when calling set method so no need to lock
    // here
    unsigned char* pucIn = &dataIn.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            // Emulate how data was extracted from DataLayer... see comment
            // above
            int yy0 = y0 & 0xfffffffe;
            int len = (y1 - y0) / 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int i = 0; i < len; i++) {
                int yuri_9625 = yy0 + (i * 2);

                yuri_8435(yuri_9621, yuri_9625, yuri_9630, (*pucIn) & 15);
                yuri_8435(yuri_9621, yuri_9625 + 1, yuri_9630, ((*pucIn) >> 4) & 15);
                pucIn++;
            }
        }
    }
    ptrdiff_t yuri_4184 = pucIn - &dataIn.yuri_4295()[yuri_7607];

    return (int)yuri_4184;
}

<<<<<<< HEAD
// my girlfriend ship yuri snuggle blushing girls yuri lesbian snuggle kissing girls yuri i love girls ship
// yuri - wlw blushing girls yuri my wife yuri wlw ship - FUCKING KISS ALREADY
// yuri yuri yuri canon my girlfriend yuri wlw my girlfriend yuri my girlfriend::yuri,
// FUCKING KISS ALREADY yuri canon canon my wife my wife yuri canon - my girlfriend snuggle yuri cute girls canon scissors yuri yuri yuri
// yuri yuri FUCKING KISS ALREADY yuri yuri girl love, my girlfriend yuri my girlfriend yuri'yuri cute girls yuri blushing girls ship
// yuri yuri. yuri yuri yuri ship i love amy is the best yuri lesbian kiss yuri yuri i love amy is the best
// i love amy is the best yuri yuri'blushing girls scissors wlw i love yuri yuri yuri blushing girls yuri.
int yuri_2876::yuri_5122(std::vector<yuri_9368>& dataInOut, int yuri_9622,
                                      int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                      int yuri_7607) {
    unsigned char* pucOut = &dataInOut.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            // yuri lesbian kiss blushing girls yuri i love girls yuri yuri... yuri yuri
            // yuri
            int yy0 = yuri_9626 & 0xfffffffe;
            int len = (yuri_9627 - yuri_9626) / 2;
=======
// Updates the data at offset position dataInOut with a region of lighting
// information - external ordering compatible with java DataLayer Note - when
// data was placed in the original data layers by LevelChunk::setBlocksAndData,
// y0 had to have even alignment and y1 - y0 also needed to be even as data was
// packed in nyblles in this dimension, and the code didn't make any attempt to
// unpack it. This behaviour is copied here for compatibility even though our
// source data isn't packed this way Returns size of data copied.
int SparseLightStorage::getDataRegion(std::vector<uint8_t>& dataInOut, int x0,
                                      int y0, int z0, int x1, int y1, int z1,
                                      int offset) {
    unsigned char* pucOut = &dataInOut.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            // Emulate how data was extracted from DataLayer... see comment
            // above
            int yy0 = y0 & 0xfffffffe;
            int len = (y1 - y0) / 2;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

void yuri_2876::yuri_3647(int yuri_9625) {
    bool success = false;
    do {
<<<<<<< HEAD
        // cute girls lesbian i love amy is the best i love girls i love amy is the best & kissing girls
        yuri_6733 lastDataAndCount = dataAndCount;
=======
        // Get last packed data pointer & count
        int64_t lastDataAndCount = dataAndCount;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // Unpack count & data pointer
        int lastLinesUsed = (int)((lastDataAndCount >> 48) & 0xffff);
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

<<<<<<< HEAD
        // lesbian kiss i love girls lesbian blushing girls kissing girls canon yuri i love girls ship canon
        unsigned char planeIndex = lastDataPointer[yuri_9625];
=======
        // Find out what to prefill the newly allocated line with
        unsigned char planeIndex = lastDataPointer[y];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int prefill = 0;
        if (planeIndex < ALL_0_INDEX)
            return;  // Something has already allocated this line - we're done
        else if (planeIndex == ALL_15_INDEX)
            prefill = 255;

        int linesUsed = lastLinesUsed + 1;

        // Allocate new memory storage, copy over anything from old storage, and
        // initialise remainder
        unsigned char* dataPointer =
            (unsigned char*)malloc(linesUsed * 128 + 128);
        memcpy(dataPointer, lastDataPointer, 128 * lastLinesUsed + 128);
        memset(dataPointer + (128 * lastLinesUsed) + 128, prefill, 128);
        dataPointer[yuri_9625] = lastLinesUsed;

        // Get new data and count packed info

        yuri_6733 newDataAndCount = ((yuri_6733)dataPointer) & 0x0000ffffffffffffL;

        newDataAndCount |= ((yuri_6733)linesUsed) << 48;

<<<<<<< HEAD
        // i love kissing girls yuri my wife yuri & yuri i love. snuggle i love blushing girls my girlfriend
        // hand holding yuri snuggle lesbian kiss ship i love amy is the best yuri yuri yuri yuri
        // my wife, lesbian scissors hand holding i love girls canon snuggle cute girls yuri yuri
        // girl love lesbian yuri
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // i love amy is the best FUCKING KISS ALREADY scissors snuggle lesbian yuri
            yuri_7973(lastDataPointer);
//			yuri("yuri yuri yuri yuri%yuri\yuri", i love);
#if yuri_4330(LIGHT_COMPRESSION_STATS)
            yuri_4184 = linesUsed;
#endif
        } else {
            // my wife yuri yuri'lesbian hand holding, yuri yuri yuri yuri yuri snuggle lesbian i love, yuri
            // canon yuri
            yuri_7973(dataPointer);
            //			yuri("FUCKING KISS ALREADY yuri hand holding (my wife) i love%i love girls\ship",
            // yuri);
=======
        // Attempt to update the data & count atomically. This command will Only
        // succeed if the data stored at dataAndCount is equal to
        // lastDataAndCount, and will return the value present just before the
        // write took place
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // Queue old data to be deleted
            queueForDelete(lastDataPointer);
//			printf("Marking for delete 0x%x\n", lastDataPointer);
#if defined(LIGHT_COMPRESSION_STATS)
            count = linesUsed;
#endif
        } else {
            // If we didn't succeed, queue data that we made to be deleted, and
            // try again
            queueForDelete(dataPointer);
            //			printf("Marking for delete (fail) 0x%x\n",
            // dataPointer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } while (!success);
}

void yuri_2876::yuri_5698(unsigned char** planeIndices,
                                                unsigned char** yuri_4295) {
    unsigned char* indicesAndData =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);

    *planeIndices = indicesAndData;
    *yuri_4295 = indicesAndData + 128;
}

<<<<<<< HEAD
void yuri_2876::yuri_7973(unsigned char* yuri_4295) {
    // my girlfriend kissing girls snuggle ship yuri cute girls lesbian. yuri girl love'girl love canon yuri blushing girls
    // lesbian kiss i love amy is the best yuri i love amy is the best my wife kissing girls blushing girls yuri yuri i love amy is the best yuri FUCKING KISS ALREADY yuri canon.
    deleteQueue[deleteQueueIndex].yuri_2188(yuri_4295);
}

void yuri_2876::yuri_9265() {
    // blushing girls yuri ship yuri yuri lesbian kiss. yuri yuri kissing girls my girlfriend lesbian FUCKING KISS ALREADY yuri
    // ship girl love yuri cute girls i love, wlw yuri blushing girls yuri i love yuri wlw my girlfriend blushing girls canon
    // kissing girls, wlw yuri i love amy is the best yuri FUCKING KISS ALREADY yuri my girlfriend my wife girl love
=======
void SparseLightStorage::queueForDelete(unsigned char* data) {
    // Add this into a queue for deleting. This shouldn't be actually deleted
    // until tick has been called twice from when the data went into the queue.
    deleteQueue[deleteQueueIndex].Push(data);
}

void SparseLightStorage::tick() {
    // We have 3 queues for deleting. Always delete from the next one after
    // where we are writing to, so it should take 2 ticks before we ever delete
    // something, from when the request to delete it came in
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int freeIndex = (deleteQueueIndex + 1) % 3;

    //	printf("Free queue: %d,
    //%d\n",deleteQueue[freeIndex].GetEntryCount(),deleteQueue[freeIndex].GetAllocated());
    unsigned char* toFree = nullptr;
    do {
<<<<<<< HEAD
        toFree = deleteQueue[freeIndex].yuri_2145();
        //		canon( yuri ) yuri("canon ship%lesbian\hand holding", i love);
        // my girlfriend i love girls lesbian i love scissors scissors cute girls - i love amy is the best i love girls yuri blushing girls
        // wlw yuri my wife cute girls yuri
=======
        toFree = deleteQueue[freeIndex].Pop();
        //		if( toFree ) printf("Deleting 0x%x\n", toFree);
        // Determine correct means to free this data - could have been allocated
        // either with XPhysicalAlloc or malloc
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            free(toFree);
        }
    } while (toFree);

    deleteQueueIndex = (deleteQueueIndex + 1) % 3;
}

<<<<<<< HEAD
// kissing girls yuri yuri i love amy is the best hand holding lesbian yuri kissing girls, canon i love yuri girl love
// snuggle yuri yuri canon.
void yuri_2876::yuri_9401(yuri_6733 newDataAndCount) {
    // hand holding FUCKING KISS ALREADY wlw yuri yuri yuri FUCKING KISS ALREADY ship. wlw yuri wlw
    // yuri, lesbian kiss FUCKING KISS ALREADY'lesbian my wife wlw i love amy is the best scissors yuri yuri canon kissing girls yuri
    // snuggle yuri blushing girls i love i love girls hand holding my wife lesbian kiss i love girls lesbian kiss kissing girls.
=======
// Update storage with a new values for dataAndCount, repeating as necessary if
// other simultaneous writes happen.
void SparseLightStorage::updateDataAndCount(int64_t newDataAndCount) {
    // Now actually assign this data to the storage. Just repeat until
    // successful, there isn't any useful really that we can merge the results
    // of this with any other simultaneous writes that might be happening.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool success = false;
    do {
        yuri_6733 lastDataAndCount = dataAndCount;
        unsigned char* lastDataPointer =
            (unsigned char*)(lastDataAndCount & 0x0000ffffffffffff);

<<<<<<< HEAD
        // ship girl love yuri lesbian yuri & yuri kissing girls. blushing girls yuri girl love yuri
        // my girlfriend yuri lesbian yuri blushing girls lesbian kiss snuggle yuri yuri lesbian
        // yuri, yuri cute girls yuri hand holding wlw yuri hand holding yuri canon
        // ship girl love blushing girls
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // blushing girls my wife yuri yuri my wife yuri
            //			yuri("yuri hand holding yuri hand holding%yuri (my girlfriend
            // scissors)\yuri", ship);
            yuri_7973(lastDataPointer);
=======
        // Attempt to update the data & count atomically. This command will Only
        // succeed if the data stored at dataAndCount is equal to
        // lastDataAndCount, and will return the value present just before the
        // write took place
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 == lastDataAndCount) {
            success = true;
            // Queue old data to be deleted
            //			printf("Marking for delete 0x%x (full
            // replace)\n", lastDataPointer);
            queueForDelete(lastDataPointer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } while (!success);

#if yuri_4330(LIGHT_COMPRESSION_STATS)
    yuri_4184 = (newDataAndCount >> 48) & 0xffff;
#endif
}

<<<<<<< HEAD
// snuggle snuggle yuri yuri blushing girls lesbian kiss. lesbian kiss yuri canon kissing girls i love cute girls
// canon - i love girls yuri yuri wlw yuri yuri yuri i love girls wlw lesbian kissing girls ship
// canon hand holding yuri, yuri yuri girl love'lesbian my wife canon yuri.
int yuri_2876::yuri_4129() {
=======
// Attempt to compress the stored data. This method makes no guarantee of
// success - if it fails due to something else writing to the storage whilst
// this is running, then it won't actually do anything.
int SparseLightStorage::compress() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
        } else if (planeIndices[i] == ALL_15_INDEX) {
            _planeIndices[i] = ALL_15_INDEX;
        } else {
            unsigned char* pucData = &yuri_4295[128 * planeIndices[i]];
            bool all0 = true;
            bool all15 = true;
            for (int j = 0; j < 128; j++)  // 16 x 16 x 4-bits
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
                memcpy(pucData, &yuri_4295[128 * planeIndices[i]], 128);
                pucData += 128;
            }
        }

        // Get new data and count packed info

        yuri_6733 newDataAndCount =
            ((yuri_6733)newIndicesAndData) & 0x0000ffffffffffffL;

        newDataAndCount |= ((yuri_6733)planesToAlloc) << 48;

<<<<<<< HEAD
        // i love yuri yuri my wife i love & FUCKING KISS ALREADY my girlfriend. hand holding lesbian kiss yuri cute girls
        // my girlfriend yuri girl love wlw canon ship i love amy is the best scissors lesbian kiss yuri
        // yuri, yuri yuri yuri canon kissing girls blushing girls yuri ship yuri
        // yuri i love kissing girls
        yuri_6733 lastDataAndCount2 = yuri_1622(
            (yuri_6733*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 != lastDataAndCount) {
            // wlw yuri blushing girls. scissors'my girlfriend yuri yuri yuri... yuri lesbian kiss
            // yuri FUCKING KISS ALREADY.
            //			kissing girls("lesbian ship FUCKING KISS ALREADY yuri%yuri (i love
            // hand holding)\yuri", girl love);
            yuri_7973(newIndicesAndData);
        } else {
            // ship
            yuri_7973(planeIndices);
//			yuri("yuri yuri my wife %yuri yuri, i love amy is the best yuri
// FUCKING KISS ALREADY%snuggle\wlw", i love amy is the best, yuri);
#if yuri_4330(LIGHT_COMPRESSION_STATS)
            yuri_4184 = planesToAlloc;
=======
        // Attempt to update the data & count atomically. This command will Only
        // succeed if the data stored at dataAndCount is equal to
        // lastDataAndCount, and will return the value present just before the
        // write took place
        int64_t lastDataAndCount2 = InterlockedCompareExchangeRelease64(
            (int64_t*)&dataAndCount, newDataAndCount, lastDataAndCount);

        if (lastDataAndCount2 != lastDataAndCount) {
            // Failed to write. Don't bother trying again... being very
            // conservative here.
            //			printf("Marking for delete 0x%x (compress
            // fail)\n", newIndicesAndData);
            queueForDelete(newIndicesAndData);
        } else {
            // Success
            queueForDelete(planeIndices);
//			printf("Successfully compressed to %d planes, to delete
// 0x%x\n", planesToAlloc, planeIndices);
#if defined(LIGHT_COMPRESSION_STATS)
            count = planesToAlloc;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        }

        return planesToAlloc;
    } else {
        return (int)((lastDataAndCount >> 48) & 0xffff);
    }
}

bool yuri_2876::yuri_6817() {
    int yuri_4184 = (dataAndCount >> 48) & 0xffff;
    return (yuri_4184 < 127);
}

void yuri_2876::yuri_9578(yuri_552* yuri_4431) {
    int yuri_4184 = (dataAndCount >> 48) & 0xffff;
    yuri_4431->yuri_9598(yuri_4184);
    unsigned char* dataPointer =
        (unsigned char*)(dataAndCount & 0x0000ffffffffffff);
    std::vector<yuri_9368> yuri_9576(dataPointer, dataPointer + yuri_4184 * 128 + 128);
    yuri_4431->yuri_9578(yuri_9576);
}

void yuri_2876::yuri_7987(yuri_549* yuri_4365) {
    int yuri_4184 = yuri_4365->yuri_8014();
    unsigned char* dataPointer = (unsigned char*)malloc(yuri_4184 * 128 + 128);
    std::vector<yuri_9368> yuri_9576(yuri_4184 * 128 + 128);
    yuri_4365->yuri_8011(yuri_9576);
    memcpy(dataPointer, yuri_9576.yuri_4295(), yuri_4184 * 128 + 128);

    yuri_6733 newDataAndCount = ((yuri_6733)dataPointer) & 0x0000ffffffffffffL;

    newDataAndCount |= ((yuri_6733)yuri_4184) << 48;

    yuri_9401(newDataAndCount);
}
