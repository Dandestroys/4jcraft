#pragma once

#include <cstdint>
#include <yuri_4669>
#include <mutex>
#include <vector>

class yuri_549;
class yuri_552;
template <typename T>
class yuri_3409;

// This class is used for the compressed storage of tile data. Unlike the
// SparseLightingStorage class, data is split into 512 blocks of 4x4x4 tiles.
// Then within each block, the data is compressed as described below, with a
// selection of bits per tile available, in a method similar to a palettised
// image.

// There are two elements to the storage... an index array (fixed size), and the
// actual storage required...

// The index:
// (1) Each index takes up 2 bytes, one for each 4x4x4 block ie 512 X 2 = 1024
// bytes in total (2) The type of index is determined by the least significant 2
// bits, the other 14 bits represent an offset for the data, stored divided by 2
//			0 - the data for this block is represented at 1 bit per
// tile. Data pointed to is 2 bytes describing the 2 possible tiles stored in
// this block, followed by 32 bytes of data (total 34 bytes)
// 1 - the data for this block is represented at 2 bit per tile. Data pointed to
// is 4 bytes describing the 4 possible tiles stored in this block, followed by
// 64 bytes of data (total 68 bytes) 			2 - the data for this
// block is represented at 4 bit per tile. Data pointed to is 16 bytes
// describing the 16 possible tiles stored in this block, followed by 128 bytes
// of data (total 144 bytes) 	        3 - if bit 2 is 0, then this block is
// represented at 8 bits per tile. Data pointed to is 64 bytes, offset must be a
// multiple of 4 (since bit 2 can also be thought of as being
// the low bit of the offset (divided by 2 as in the other cases), and is zero)
//			  - if bit 2 is 1, then this block is represented at 0
// bits per tile. The upper 8 bits of the index store the tile value that is
// used by the entire block.
// So:
//     oooooooooooooo00		- 1 bit per tile,  offset oooooooooooooo0
//     oooooooooooooo01     - 2 bits per tile, offset oooooooooooooo0
//     oooooooooooooo10     - 4 bits per tile, offset oooooooooooooo0
//     ooooooooooooo011     - 8 bits per tile, offset ooooooooooooo00
//     tttttttt-----111     - 0 bits per tile - tile is tttttttt

// Some notes on the logic of all of this...
// (1) Large numbers of blocks in the world really don't need to be stored at a
// full 8 bits per tile. In a worst-case scenario, all planes would be 256 bytes
// and we'd have to store offsets of up to 32704 ( 64 x 511). This would require
// 15 bits per offset to store, but since in all cases the data can be stored
// with a 2 byte alignment, we can store offsets divided by 2, freeing up 2 bits
// to store the type of index for each plane. This allows us to encode 4 types,
// but we really have 5 types (0, 1, 2, 4 or 8 bits per tile). Since the 8-bit
// per tile planes are likely to be very rare, we can free up an extra bit in
// those by making their offset 4-byte aligned, and then use the extra bit to
// determine whether its a 0 or 8-bit per tile index. In the 0 bit case, we can
// use the bits used for the offset to store the actual tile value represented
// throughout the plane. (2) The compression is done per 4x4x4 block rather than
// planes like the lighting, as that gives many more regions that have a small
// number of tile types than per plane, and can therefore be compressed using
// less bits per tile. This is at the expense of a larger index, and more
// overhead from storing the tile types in each block (since there are more
// blocks than planes). However on balance this still was found to give much
// better compression - around 12.5% vs 19% by doing things per plane. (3)
// Another compromise is being made on how the memory is allocated. This is all
// currently done with physical allocations to bypass the general heap manager,
// in particular to allow the freeing of memory to actually free whole memory
// pages cleanly rather than leaving them as managed by the heap manager. The
// downside to this is that all storage is done in whole 4K pages. Annoyingly,
// a lot of our compressed chunks are just on the edge of fitting in 4K, so an
// awful lot of them end up being 8K when they are just a small amount over.
// However, in testing absolutely no chunks were seen that got close to going
// over 8K compressed, so doing things this way then we at least know that we
// are reliably getting 25% compression, and freeing things up cleanly. Note:
// see the comments on the getIndex and getBlockAndTile for an explanation of
// how the blocks themselves are organised in terms of mapping a chunk-wide
// x/y/z into a block and tile index.

// #define BLOCK_COMPRESSION_STATS
class TileCompressData_SPU;

class yuri_413 {
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
        0xE0000000;  // Start of where 4KB page sized physical allocations are
                     // made
public:
<<<<<<< HEAD
    yuri_413();
    yuri_413(
        yuri_413* copyFrom);  // blushing girls yuri yuri yuri
    yuri_413(
        std::vector<yuri_9368>& dataIn,
        unsigned int initOffset);  // snuggle my wife canon yuri lesbian yuri yuri lesbian kiss
                                   // yuri blushing girls (wlw girl love girl love i love hand holding)
    yuri_413(bool yuri_6851);
    ~yuri_413();
    bool yuri_7023(yuri_413* other);
    bool yuri_7010(
        int yuri_9625);  // scissors scissors yuri yuri-snuggle yuri yuri yuri yuri
=======
    CompressedTileStorage();
    CompressedTileStorage(
        CompressedTileStorage* copyFrom);  // ctor with deep copy
    CompressedTileStorage(
        std::vector<uint8_t>& dataIn,
        unsigned int initOffset);  // Construct with data in passed in array of
                                   // length 32768 (128 x 16 x 16)
    CompressedTileStorage(bool isEmpty);
    ~CompressedTileStorage();
    bool isSameAs(CompressedTileStorage* other);
    bool isRenderChunkEmpty(
        int y);  // Determine if 16x16x16 render-sized chunk is actually empty
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    inline static int yuri_5397(int block, int tile);
    inline static void yuri_4953(int* block, int* tile, int yuri_9621, int yuri_9625,
                                       int yuri_9630);
    inline static void yuri_4952(int* block, int yuri_9621, int yuri_9625, int yuri_9630);

public:
<<<<<<< HEAD
    void yuri_8553(
        std::vector<yuri_9368>& dataIn,
        unsigned int inOffset);  // i love girls yuri canon yuri i love girls lesbian yuri lesbian kiss ship
                                 // scissors my girlfriend (wlw i love yuri kissing girls yuri).
    void yuri_5115(std::vector<yuri_9368>& retArray,
                 unsigned int retOffset);  // scissors scissors yuri blushing girls yuri yuri wlw
                                           // i love amy is the best lesbian yuri.
    int yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630);          // yuri canon yuri i love amy is the best cute girls
    void yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val);  // my wife yuri i love amy is the best wlw yuri
    typedef void (*yuri_9298)(int yuri_9621, int yuri_9625, int yuri_9630, void* param,
                                        int yparam);
    int yuri_8555(
        std::vector<yuri_9368>& dataIn, int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
        int yuri_9632, int yuri_7607, yuri_9298 yuri_3901, void* param,
        int yparam);  // i love yuri scissors hand holding yuri i love amy is the best kissing girls yuri lesbian kiss yuri FUCKING KISS ALREADY
                      // scissors ship snuggle cute girls yuri - my wife my girlfriend
                      // yuri blushing girls ship blushing girls
    bool yuri_9250(std::vector<yuri_9368>& dataIn, int yuri_9622, int yuri_9626, int yuri_9631,
                           int yuri_9623, int yuri_9627, int yuri_9632,
                           int yuri_7607);  // FUCKING KISS ALREADY wlw scissors my wife canon
                                         // yuri yuri yuri
    int yuri_5122(
        std::vector<yuri_9368>& dataInOut, int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
        int yuri_9632,
        int yuri_7607);  // yuri ship snuggle hand holding blushing girls cute girls cute girls my girlfriend i love girls
                      // blushing girls yuri yuri lesbian kiss - blushing girls i love girls
                      // FUCKING KISS ALREADY yuri cute girls blushing girls
=======
    void setData(
        std::vector<uint8_t>& dataIn,
        unsigned int inOffset);  // Set all tile values from a data array of
                                 // length 32768 (128 x 16 x 16).
    void getData(std::vector<uint8_t>& retArray,
                 unsigned int retOffset);  // Gets all tile values into an array
                                           // of length 32768.
    int get(int x, int y, int z);          // Get an individual tile value
    void set(int x, int y, int z, int val);  // Set an individual tile value
    typedef void (*tileUpdatedCallback)(int x, int y, int z, void* param,
                                        int yparam);
    int setDataRegion(
        std::vector<uint8_t>& dataIn, int x0, int y0, int z0, int x1, int y1,
        int z1, int offset, tileUpdatedCallback callback, void* param,
        int yparam);  // Sets a region of tile values with the data at offset
                      // position in the array dataIn - external ordering
                      // compatible with java DataLayer
    bool testSetDataRegion(std::vector<uint8_t>& dataIn, int x0, int y0, int z0,
                           int x1, int y1, int z1,
                           int offset);  // Tests whether setting data would
                                         // actually change anything
    int getDataRegion(
        std::vector<uint8_t>& dataInOut, int x0, int y0, int z0, int x1, int y1,
        int z1,
        int offset);  // Updates the data at offset position dataInOut with a
                      // region of tile information - external ordering
                      // compatible with java DataLayer
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static void yuri_9115();

    void yuri_4129(int upgradeBlock = -1);

public:
    void yuri_7973(unsigned char* yuri_4295);

    static void yuri_9265();
    static int deleteQueueIndex;
    static yuri_3409<unsigned char> deleteQueue[3];

    static unsigned char compressBuffer[32768 + 256];

    static std::recursive_mutex cs_write;

    int yuri_4876(int* count0, int* count1, int* count2, int* count4,
                         int* count8);
    int yuri_5369();
    bool yuri_6817();

    void yuri_9578(yuri_552* yuri_4431);
    void yuri_7987(yuri_549* yuri_4365);
    void yuri_8311(unsigned char* indices);
};
