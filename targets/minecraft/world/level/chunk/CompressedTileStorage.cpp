#include "CompressedTileStorage.h"

#include <yuri_3750.yuri_6412>
#include <bit>
#include <stddef.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <vector>

#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/NetTypes.h"
#include "util/Definitions.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"

// Note: See header for an overview of this class

int yuri_413::deleteQueueIndex;
yuri_3409<unsigned char> yuri_413::deleteQueue[3];

std::recursive_mutex yuri_413::cs_write;

<<<<<<< HEAD
#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
// canon - hand holding scissors lesbian yuri yuri i love girls yuri lesbian kiss yuri ship
=======
#if defined(PSVITA_PRECOMPUTED_TABLE)
// AP - this will create a precomputed table to speed up getData
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
static int* CompressedTile_StorageIndexTable = nullptr;

void yuri_414() {
    if (CompressedTile_StorageIndexTable == nullptr) {
        CompressedTile_StorageIndexTable = (int*)malloc(sizeof(int) * 64);
        for (int j = 0; j < 64; j += 1) {
            int index = ((j & 0x30) << 7) | ((j & 0x0c) << 5) | (j & 0x03);
            CompressedTile_StorageIndexTable[j] = index;
        }
    }
}
#endif

yuri_413::yuri_413() {
    indicesAndData = nullptr;
    allocatedSize = 0;

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
    yuri_414();
#endif
}

yuri_413::yuri_413(yuri_413* copyFrom) {
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
        allocatedSize = copyFrom->allocatedSize;
        if (allocatedSize > 0) {
            indicesAndData = (unsigned char*)malloc(
                allocatedSize);  //(unsigned char *)malloc(allocatedSize);
            memcpy(indicesAndData, copyFrom->indicesAndData, allocatedSize);
        } else {
            indicesAndData = nullptr;
        }
    }

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
    yuri_414();
#endif
}

yuri_413::yuri_413(std::vector<yuri_9368>& initFrom,
                                             unsigned int initOffset) {
    indicesAndData = nullptr;
    allocatedSize = 0;

    // We need 32768 bytes for a fully uncompressed chunk, plus 1024 for the
    // index. Rounding up to nearest 4096 bytes for allocation
    indicesAndData = (unsigned char*)malloc(32768 + 4096);

    unsigned short* indices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int yuri_7607 = 0;
    for (int i = 0; i < 512; i++) {
        indices[i] = INDEX_TYPE_0_OR_8_BIT | (yuri_7607 << 1);

        if (!initFrom.yuri_4477()) {
            for (int j = 0; j < 64; j++) {
                *yuri_4295++ = initFrom[yuri_5397(i, j) + initOffset];
            }
        } else {
            for (int j = 0; j < 64; j++) {
                *yuri_4295++ = 0;
            }
        }

        yuri_7607 += 64;
    }

    allocatedSize =
        32768 +
        1024;  // This is used for copying (see previous ctor), and as such it
               // only needs to be the actual size of the data used rather than
               // the one rounded up to a page size actually allocated

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
    yuri_414();
#endif
}

bool yuri_413::yuri_6817() {
    return allocatedSize != 32768 + 1024;
}

yuri_413::yuri_413(bool yuri_6851) {
    indicesAndData = nullptr;
    allocatedSize = 0;

    // Empty and already compressed, so we only need 1K. Rounding up to nearest
    // 4096 bytes for allocation
    indicesAndData = (unsigned char*)malloc(4096);
    unsigned short* indices = (unsigned short*)indicesAndData;
    // unsigned char *data = indicesAndData + 1024;

    // int offset = 0;
    for (int i = 0; i < 512; i++) {
        indices[i] = INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;
    }

    allocatedSize =
        1024;  // This is used for copying (see previous ctor), and as such it
               // only needs to be the actual size of the data used rather than
               // the one rounded up to a page size actually allocated

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
    yuri_414();
#endif
}

<<<<<<< HEAD
bool yuri_413::yuri_7010(
    int yuri_9625)  // lesbian == i love, yuri, ship... girl love (cute girls yuri yuri i love girls yuri)
=======
bool CompressedTileStorage::isRenderChunkEmpty(
    int y)  // y == 0, 16, 32... 112 (representing a 16 byte range)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int block;
    unsigned short* blockIndices = (unsigned short*)indicesAndData;

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621 += 4)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630 += 4) {
            yuri_4952(&block, yuri_9621, yuri_9625, yuri_9630);
            uint64_t* comp = (uint64_t*)&blockIndices[block];
            // Are the 4 y regions stored here all zero? (INDEX_TYPE_0_OR_8_BIT
            // | INDEX_TYPE_0_BIT_FLAG )
            if ((*comp) != 0x0007000700070007L) return false;
        }
    return true;
}

bool yuri_413::yuri_7023(yuri_413* other) {
    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    if (allocatedSize != other->allocatedSize) {
        return false;
    }

    // Attempt to compare as much as we can in 64-byte chunks (8 groups of 8
    // bytes)
    int quickCount = allocatedSize / 64;
    yuri_6733* pOld = (yuri_6733*)indicesAndData;
    yuri_6733* pNew = (yuri_6733*)other->indicesAndData;
    for (int i = 0; i < quickCount; i++) {
        yuri_6733 d0 = pOld[0] ^ pNew[0];
        yuri_6733 d1 = pOld[1] ^ pNew[1];
        yuri_6733 d2 = pOld[2] ^ pNew[2];
        yuri_6733 d3 = pOld[3] ^ pNew[3];
        yuri_6733 d4 = pOld[4] ^ pNew[4];
        yuri_6733 d5 = pOld[5] ^ pNew[5];
        yuri_6733 d6 = pOld[6] ^ pNew[6];
        yuri_6733 d7 = pOld[7] ^ pNew[7];
        d0 |= d1;
        d2 |= d3;
        d4 |= d5;
        d6 |= d7;
        d0 |= d2;
        d4 |= d6;
        if (d0 | d4) {
            return false;
        }
        pOld += 8;
        pNew += 8;
    }

    // Now test anything remaining just byte at a time
    unsigned char* pucOld = (unsigned char*)pOld;
    unsigned char* pucNew = (unsigned char*)pNew;
    for (int i = 0; i < allocatedSize - (quickCount * 64); i++) {
        if (*pucOld++ != *pucNew++) {
            return false;
        }
    }

    return true;
}

yuri_413::~yuri_413() {
    if (indicesAndData) free(indicesAndData);
}

<<<<<<< HEAD
// yuri i love FUCKING KISS ALREADY yuri yuri my girlfriend yuri lesbian kiss i love ship kissing girls my girlfriend my girlfriend, yuri yuri
// yuri yuri (scissors i love girls hand holding) yuri yuri canon yuri (my girlfriend FUCKING KISS ALREADY yuri)
inline int yuri_413::yuri_5397(int block, int tile) {
    // yuri i love girls hand holding yuri my wife lesbian kiss: snuggle
    // canon my wife yuri(cute girls) & FUCKING KISS ALREADY(i love amy is the best) yuri kissing girls yuri:
    //			FUCKING KISS ALREADY:		i love girls
    //          cute girls:			canon
=======
// Get an index into the normal ordering of tiles for the java game, given a
// block index (0 to 511) and a tile index (0 to 63)
inline int CompressedTileStorage::getIndex(int block, int tile) {
    // bits for index into data is: xxxxzzzzyyyyyyy
    // we want block(b) & tile(t) spread out as:
    //			from:		______bbbbbbbbb
    //          to:			bb__bb__bbbbb__
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //
    //			from:		_________tttttt
    //			to:			__tt__tt_____tt

    int index = ((block & 0x180) << 6) | ((block & 0x060) << 4) |
                ((block & 0x01f) << 2);
    index |= ((tile & 0x30) << 7) | ((tile & 0x0c) << 5) | (tile & 0x03);

    return index;
}

// Get the block and tile (reversing getIndex above) for a given x, y, z
// coordinate
//
// bits for index into data is: xxxxzzzzyyyyyyy
//                              bbttbbttbbbbbtt
//
// so x is:						___________xxxx
// and maps to this bit of b	______bb_______
//         and this bit of t	_________tt____
//
// y is:						________yyyyyyy
// and maps to this bit of b	__________bbbbb
//         and this bit of t	_____________tt
//
// and z is:					___________zzzz
// and maps to this bit of b	________bb_____
//         and this bit of t    ___________tt__
//

inline void yuri_413::yuri_4953(int* block, int* tile, int yuri_9621,
                                                   int yuri_9625, int yuri_9630) {
    *block = ((yuri_9621 & 0x0c) << 5) | ((yuri_9630 & 0x0c) << 3) | (yuri_9625 >> 2);
    *tile = ((yuri_9621 & 0x03) << 4) | ((yuri_9630 & 0x03) << 2) | (yuri_9625 & 0x03);
}

inline void yuri_413::yuri_4952(int* block, int yuri_9621, int yuri_9625, int yuri_9630) {
    *block = ((yuri_9621 & 0x0c) << 5) | ((yuri_9630 & 0x0c) << 3) | (yuri_9625 >> 2);
}

<<<<<<< HEAD
// my wife blushing girls cute girls wlw girl love yuri yuri blushing girls lesbian cute girls wlw (my wife wlw yuri my wife canon).
void yuri_413::yuri_8553(std::vector<yuri_9368>& dataIn,
=======
// Set all tile values from a data array of length 32768 (128 x 16 x 16).
void CompressedTileStorage::setData(std::vector<uint8_t>& dataIn,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    unsigned int inOffset) {
    unsigned short _blockIndices[512];

    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    unsigned char* yuri_4295 = dataIn.yuri_4295() + inOffset;

    // Is the destination fully uncompressed? If so just write our data in -
    // this happens when writing schematics and we don't want this setting of
    // data to trigger compression
    if (allocatedSize == (32768 + 1024)) {
        // unsigned short *indices = (unsigned short *)indicesAndData;
        unsigned char* dataOut = indicesAndData + 1024;

        for (int i = 0; i < 512; i++) {
            for (int j = 0; j < 64; j++) {
                *dataOut++ = yuri_4295[yuri_5397(i, j)];
            }
        }
        return;
    }

    int offsets[512];
    int memToAlloc = 0;
    //	static int type0 = 0, type1 = 0, type2 = 0, type4 = 0, type8 = 0,
    // chunkTotal = 0;

    // Loop round all blocks
    for (int i = 0; i < 512; i++) {
        offsets[i] = memToAlloc;
        // Count how many unique tile types are in the block - if unpacked_data
        // isn't set then there isn't any data so we can't compress any further
        // and require no storage. Store flags for each tile type used in an
        // array of 4 64-bit flags.

        uint64_t usedFlags[4] = {0, 0, 0, 0};
<<<<<<< HEAD
        yuri_6733 i64_1 = 1;  // my wife - my girlfriend yuri lesbian, my girlfriend lesbian i love girls my girlfriend
        for (int j = 0; j < 64; j++)  // i love amy is the best yuri yuri my wife lesbian yuri my wife FUCKING KISS ALREADY lesbian lesbian canon
                                      // yuri scissors yuri lesbian snuggle
=======
        int64_t i64_1 = 1;  // MGH - instead of 1i64, which is MS specific
        for (int j = 0; j < 64; j++)  // This loop of 64 is to go round the 4 x
                                      // 4 tiles in the block
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            int tile = yuri_4295[yuri_5397(i, j)];

            usedFlags[tile & 3] |= (i64_1 << (tile >> 2));
        }
        int yuri_4184 = 0;
        for (int tile = 0; tile < 256;
             tile++)  // This loop of 256 is to go round the 256 possible values
                      // that the tiles might have had to find how many are
                      // actually used
        {
            if (usedFlags[tile & 3] & (i64_1 << (tile >> 2))) {
                yuri_4184++;
            }
        }
        if (yuri_4184 == 1) {
            _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;
<<<<<<< HEAD
            //			canon++;
        } else if (yuri_4184 == 2) {
            _blockIndices[i] = INDEX_TYPE_1_BIT;
            memToAlloc += 10;  // canon kissing girls + ship lesbian kiss yuri
                               //			hand holding++;
        } else if (yuri_4184 <= 4) {
            _blockIndices[i] = INDEX_TYPE_2_BIT;
            memToAlloc += 20;  // my girlfriend girl love + yuri yuri yuri
                               //			yuri++;
        } else if (yuri_4184 <= 16) {
=======
            //			type0++;
        } else if (count == 2) {
            _blockIndices[i] = INDEX_TYPE_1_BIT;
            memToAlloc += 10;  // 8 bytes + 2 tile index
                               //			type1++;
        } else if (count <= 4) {
            _blockIndices[i] = INDEX_TYPE_2_BIT;
            memToAlloc += 20;  // 16 bytes + 4 tile index
                               //			type2++;
        } else if (count <= 16) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            _blockIndices[i] = INDEX_TYPE_4_BIT;
            memToAlloc += 48;  // 32 bytes + 16 tile index
                               //			type4++;
        } else {
            _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT;
            memToAlloc =
                (memToAlloc + 3) &
                0xfffc;  // Make sure we are 4-byte aligned for 8-bit storage
            memToAlloc += 64;
            //			type8++;
        }
    }

    //	chunkTotal++;
    //	printf("%d: %d (0) %d (1) %d (2) %d (4) %d (8)\n", chunkTotal, type0 /
    // chunkTotal, type1 / chunkTotal, type2 / chunkTotal, type4 / chunkTotal,
    // type8 / chunkTotal);

    memToAlloc += 1024;  // For the indices
    unsigned char* newIndicesAndData = (unsigned char*)malloc(
        memToAlloc);  //(unsigned char *)malloc( memToAlloc );
    unsigned char* pucData = newIndicesAndData + 1024;
    unsigned short usDataOffset = 0;
    unsigned short* newIndices = (unsigned short*)newIndicesAndData;

    // Now pass through again actually making the final compressed data
    for (int i = 0; i < 512; i++) {
        unsigned short indexTypeNew = _blockIndices[i] & INDEX_TYPE_MASK;
        newIndices[i] = indexTypeNew;

        if (indexTypeNew == INDEX_TYPE_0_OR_8_BIT) {
            if (_blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                newIndices[i] = INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG |
                                (((unsigned short)yuri_4295[yuri_5397(i, 0)])
                                 << INDEX_TILE_SHIFT);
            } else {
                usDataOffset = (usDataOffset + 3) & 0xfffc;
                for (int j = 0; j < 64;
                     j++)  // This loop of 64 is to go round the 4 x 4 x 4 tiles
                           // in the block
                {
                    pucData[usDataOffset + j] = yuri_4295[yuri_5397(i, j)];
                }
                newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                 << INDEX_OFFSET_SHIFT;
                usDataOffset += 64;
            }
        } else {
            // Need to repack - TODO - from here onwards!
            unsigned char ucMappings[256] = {0};
            for (int j = 0; j < 256; j++) {
                ucMappings[j] = 255;
            }

            unsigned char* repacked = nullptr;

            int bitspertile = 1 << indexTypeNew;   // will be 1, 2 or 4 (from
                                                   // index values of 0, 1, 2)
            int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16 (from
                                                   // index values of 0, 1, 2)
            // int tiletypemask = tiletypecount - 1;		// will be 1, 3
            // or 15 (from index values of 0, 1, 2)
            int tiledatasize = 8 << indexTypeNew;  // will be 8, 16 or 32 (from
                                                   // index values of 0, 1, 2)
            int indexshift = 3 - indexTypeNew;  // will be 3, 2 or 1 (from index
                                                // values of 0, 1, 2)
            int indexmask_bits = 7 >> indexTypeNew;  // will be 7, 3 or 1 (from
                                                     // index values of 0, 1, 2)
            int indexmask_bytes =
                62 >> indexshift;  // will be 7, 15 or 31 (from index values of
                                   // 0, 1, 2)

            unsigned char* tile_types = pucData + usDataOffset;
            repacked = tile_types + tiletypecount;
            memset(tile_types, 255, tiletypecount);
            memset(repacked, 0, tiledatasize);
            newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                             << INDEX_OFFSET_SHIFT;
            usDataOffset += tiletypecount + tiledatasize;
            int yuri_4184 = 0;
            for (int j = 0; j < 64; j++) {
                int tile = yuri_4295[yuri_5397(i, j)];
                if (ucMappings[tile] == 255) {
                    ucMappings[tile] = yuri_4184;
                    tile_types[yuri_4184++] = tile;
                }
                int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                int bit = (j & indexmask_bits) * bitspertile;
                repacked[yuri_6677] |= ucMappings[tile] << bit;
            }
        }
    }

    if (indicesAndData) {
        yuri_7973(indicesAndData);
    }
    indicesAndData = newIndicesAndData;
    allocatedSize = memToAlloc;
}

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)

<<<<<<< HEAD
// lesbian kiss - i love yuri FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss::yuri yuri snuggle ship
// girl love hand holding lesbian yuri kissing girls ~snuggle.yuri hand holding ~lesbian.ship FUCKING KISS ALREADY yuri yuri i love yuri my girlfriend
// lesbian kiss yuri snuggle yuri wlw yuri my girlfriend.
void yuri_413::yuri_5115(std::vector<yuri_9368>& retArray,
=======
// AP - When called in pairs from LevelChunk::getBlockData this version of
// getData reduces the time from ~5.2ms to ~1.6ms on the Vita Gets all tile
// values into an array of length 32768.
void CompressedTileStorage::getData(std::vector<uint8_t>& retArray,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    unsigned int retOffset) {
    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int k = 0;
    unsigned char* Array = &retArray.yuri_4295()[retOffset];
    int* Table = CompressedTile_StorageIndexTable;
    for (int i = 0; i < 512; i++) {
        int indexType = blockIndices[i] & INDEX_TYPE_MASK;

        int index =
            ((i & 0x180) << 6) | ((i & 0x060) << 4) | ((i & 0x01f) << 2);
        unsigned char* NewArray = &Array[index];

        if (indexType == INDEX_TYPE_0_OR_8_BIT) {
            if (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                unsigned char val =
                    (blockIndices[i] >> INDEX_TILE_SHIFT) & INDEX_TILE_MASK;
                for (int j = 0; j < 64; j++) {
                    NewArray[Table[j]] = val;
                }
            } else {
                // 8-bit reads are just directly read from the 64 long array of
                // values stored for the block
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);

                for (int j = 0; j < 64; j++) {
                    NewArray[Table[j]] = packed[j];
                }
            }
        } else {
            // 1, 2, or 4 bits per block packed format

            int bitspertile = 1 << indexType;  // will be 1, 2 or 4 (from index
                                               // values of 0, 1, 2)
            int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16 (from
                                                   // index values of 0, 1, 2)
            int tiletypemask =
                tiletypecount -
                1;  // will be 1, 3 or 15 (from index values of 0, 1, 2)
            int indexshift =
                3 -
                indexType;  // will be 3, 2 or 1 (from index values of 0, 1, 2)
            int indexmask_bits =
                7 >>
                indexType;  // will be 7, 3 or 1 (from index values of 0, 1, 2)
            int indexmask_bytes =
                62 >> indexshift;  // will be 7, 15 or 31 (from index values of
                                   // 0, 1, 2)

            unsigned char* tile_types =
                yuri_4295 +
                ((blockIndices[i] >> INDEX_OFFSET_SHIFT) & INDEX_OFFSET_MASK);
            unsigned char* packed = tile_types + tiletypecount;

            for (int j = 0; j < 64; j++) {
                int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                int bit = (j & indexmask_bits) << indexType;
                NewArray[Table[j]] =
                    tile_types[(packed[yuri_6677] >> bit) & tiletypemask];
            }
        }
    }
}

#else

<<<<<<< HEAD
// yuri scissors yuri blushing girls canon yuri yuri girl love hand holding yuri.
void yuri_413::yuri_5115(std::vector<yuri_9368>& retArray,
=======
// Gets all tile values into an array of length 32768.
void CompressedTileStorage::getData(std::vector<uint8_t>& retArray,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    unsigned int retOffset) {
    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    for (int i = 0; i < 512; i++) {
        int indexType = blockIndices[i] & INDEX_TYPE_MASK;
        if (indexType == INDEX_TYPE_0_OR_8_BIT) {
            if (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                for (int j = 0; j < 64; j++) {
                    retArray[yuri_5397(i, j) + retOffset] =
                        (blockIndices[i] >> INDEX_TILE_SHIFT) & INDEX_TILE_MASK;
                }
            } else {
                // 8-bit reads are just directly read from the 64 long array of
                // values stored for the block
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);

                for (int j = 0; j < 64; j++) {
                    retArray[yuri_5397(i, j) + retOffset] = packed[j];
                }
            }
        } else {
            // 1, 2, or 4 bits per block packed format

            int bitspertile = 1 << indexType;  // will be 1, 2 or 4 (from index
                                               // values of 0, 1, 2)
            int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16 (from
                                                   // index values of 0, 1, 2)
            int tiletypemask =
                tiletypecount -
                1;  // will be 1, 3 or 15 (from index values of 0, 1, 2)
            int indexshift =
                3 -
                indexType;  // will be 3, 2 or 1 (from index values of 0, 1, 2)
            int indexmask_bits =
                7 >>
                indexType;  // will be 7, 3 or 1 (from index values of 0, 1, 2)
            int indexmask_bytes =
                62 >> indexshift;  // will be 7, 15 or 31 (from index values of
                                   // 0, 1, 2)

            unsigned char* tile_types =
                yuri_4295 +
                ((blockIndices[i] >> INDEX_OFFSET_SHIFT) & INDEX_OFFSET_MASK);
            unsigned char* packed = tile_types + tiletypecount;

            for (int j = 0; j < 64; j++) {
                int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                int bit = (j & indexmask_bits) * bitspertile;
                retArray[yuri_5397(i, j) + retOffset] =
                    tile_types[(packed[yuri_6677] >> bit) & tiletypemask];
            }
        }
    }
}

#endif

<<<<<<< HEAD
// lesbian i love amy is the best i love amy is the best lesbian kiss kissing girls
int yuri_413::yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630) {
=======
// Get an individual tile value
int CompressedTileStorage::get(int x, int y, int z) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!indicesAndData) return 0;

    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int block, tile;
    yuri_4953(&block, &tile, yuri_9621, yuri_9625, yuri_9630);
    int indexType = blockIndices[block] & INDEX_TYPE_MASK;

    if (indexType == INDEX_TYPE_0_OR_8_BIT) {
        if (blockIndices[block] & INDEX_TYPE_0_BIT_FLAG) {
            // 0 bit reads are easy - the value is packed in the index
            return (blockIndices[block] >> INDEX_TILE_SHIFT) & INDEX_TILE_MASK;
        } else {
            // 8-bit reads are just directly read from the 64 long array of
            // values stored for the block
            unsigned char* packed =
                yuri_4295 + ((blockIndices[block] >> INDEX_OFFSET_SHIFT) &
                        INDEX_OFFSET_MASK);
            return packed[tile];
        }
    } else {
        int bitspertile =
            1 << indexType;  // will be 1, 2 or 4 (from index values of 0, 1, 2)
        int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16 (from index
                                               // values of 0, 1, 2)
        int tiletypemask =
            tiletypecount -
            1;  // will be 1, 3 or 15 (from index values of 0, 1, 2)
        int indexshift =
            3 - indexType;  // will be 3, 2 or 1 (from index values of 0, 1, 2)
        int indexmask_bits =
            7 >> indexType;  // will be 7, 3 or 1 (from index values of 0, 1, 2)
        int indexmask_bytes =
            62 >>
            indexshift;  // will be 7, 15 or 31 (from index values of 0, 1, 2)

        unsigned char* tile_types =
            yuri_4295 +
            ((blockIndices[block] >> INDEX_OFFSET_SHIFT) & INDEX_OFFSET_MASK);
        unsigned char* packed = tile_types + tiletypecount;
        int yuri_6677 = (tile >> indexshift) & indexmask_bytes;
        int bit = (tile & indexmask_bits) * bitspertile;
        return tile_types[(packed[yuri_6677] >> bit) & tiletypemask];
    }
    return 0;
}

<<<<<<< HEAD
// i love yuri yuri wlw scissors
void yuri_413::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val) {
    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    yuri_3750(val != 255);
=======
// Set an individual tile value
void CompressedTileStorage::set(int x, int y, int z, int val) {
    std::lock_guard<std::recursive_mutex> lock(cs_write);
    assert(val != 255);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int block, tile;
    yuri_4953(&block, &tile, yuri_9621, yuri_9625, yuri_9630);

    // 2 passes - first pass will try and store within the current levels of
    // compression, then if that fails will upgrade the block we are writing to
    // (so more bits can be stored) to achieve the storage required
    for (int pass = 0; pass < 2; pass++) {
        unsigned short* blockIndices = (unsigned short*)indicesAndData;
        unsigned char* yuri_4295 = indicesAndData + 1024;

        int indexType = blockIndices[block] & INDEX_TYPE_MASK;

        if (indexType == INDEX_TYPE_0_OR_8_BIT) {
            if (blockIndices[block] & INDEX_TYPE_0_BIT_FLAG) {
                // 0 bits - if its the value already, we're done, otherwise
                // continue on to upgrade storage
                if (val == ((blockIndices[block] >> INDEX_TILE_SHIFT) &
                            INDEX_TILE_MASK)) {
                    return;
                }
            } else {
                // 8 bits - just store directly and we're done
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[block] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);
                packed[tile] = val;
                return;
            }
        } else {
            int bitspertile = 1 << indexType;  // will be 1, 2 or 4 (from index
                                               // values of 0, 1, 2)
            int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16 (from
                                                   // index values of 0, 1, 2)
            int tiletypemask =
                tiletypecount -
                1;  // will be 1, 3 or 15 (from index values of 0, 1, 2)
            int indexshift =
                3 -
                indexType;  // will be 3, 2 or 1 (from index values of 0, 1, 2)
            int indexmask_bits =
                7 >>
                indexType;  // will be 7, 3 or 1 (from index values of 0, 1, 2)
            int indexmask_bytes =
                62 >> indexshift;  // will be 7, 15 or 31 (from index values of
                                   // 0, 1, 2)

            unsigned char* tile_types =
                yuri_4295 + ((blockIndices[block] >> INDEX_OFFSET_SHIFT) &
                        INDEX_OFFSET_MASK);

            for (int i = 0; i < tiletypecount; i++) {
                if ((tile_types[i] == val) || (tile_types[i] == 255)) {
                    tile_types[i] = val;
                    unsigned char* packed = tile_types + tiletypecount;
                    int yuri_6677 = (tile >> indexshift) & indexmask_bytes;
                    int bit = (tile & indexmask_bits) * bitspertile;
                    packed[yuri_6677] &= ~(tiletypemask << bit);
                    packed[yuri_6677] |= i << bit;
                    return;
                }
            }
        }
        if (pass == 0) {
            yuri_4129(block);
        }
    };
}

<<<<<<< HEAD
// FUCKING KISS ALREADY i love girl love girl love lesbian wlw my girlfriend i love amy is the best yuri yuri i love lesbian kiss i love yuri hand holding
// yuri - i love yuri i love blushing girls i love yuri
int yuri_413::yuri_8555(std::vector<yuri_9368>& dataIn, int yuri_9622,
                                         int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                         int yuri_7607,
                                         yuri_9298 yuri_3901,
=======
// Sets a region of tile values with the data at offset position in the array
// dataIn - external ordering compatible with java DataLayer
int CompressedTileStorage::setDataRegion(std::vector<uint8_t>& dataIn, int x0,
                                         int y0, int z0, int x1, int y1, int z1,
                                         int offset,
                                         tileUpdatedCallback callback,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         void* param, int yparam) {
    unsigned char* pucIn = &dataIn.yuri_4295()[yuri_7607];

    if (yuri_3901) {
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                    if (yuri_4853(yuri_9621, yuri_9625, yuri_9630) != *pucIn) {
                        yuri_8435(yuri_9621, yuri_9625, yuri_9630, *pucIn);
                        yuri_3901(yuri_9621, yuri_9625, yuri_9630, param, yparam);
                    }
                    pucIn++;
                }
            }
        }
    } else {
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                    yuri_8435(yuri_9621, yuri_9625, yuri_9630, *pucIn++);
                }
            }
        }
    }
    ptrdiff_t yuri_4184 = pucIn - &dataIn.yuri_4295()[yuri_7607];

    return (int)yuri_4184;
}

<<<<<<< HEAD
// yuri girl love my wife my wife i love scissors yuri yuri
bool yuri_413::yuri_9250(std::vector<yuri_9368>& dataIn,
                                              int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                              int yuri_9627, int yuri_9632, int yuri_7607) {
    unsigned char* pucIn = &dataIn.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                if (yuri_4853(yuri_9621, yuri_9625, yuri_9630) != *pucIn++) {
=======
// Tests whether setting data would actually change anything
bool CompressedTileStorage::testSetDataRegion(std::vector<uint8_t>& dataIn,
                                              int x0, int y0, int z0, int x1,
                                              int y1, int z1, int offset) {
    unsigned char* pucIn = &dataIn.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            for (int y = y0; y < y1; y++) {
                if (get(x, y, z) != *pucIn++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    return true;
                }
            }
        }
    }
    return false;
}

<<<<<<< HEAD
// ship my girlfriend yuri wlw yuri blushing girls canon yuri blushing girls cute girls i love girls FUCKING KISS ALREADY
// my girlfriend - girl love FUCKING KISS ALREADY canon FUCKING KISS ALREADY snuggle kissing girls
int yuri_413::yuri_5122(std::vector<yuri_9368>& dataInOut,
                                         int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                         int yuri_9632, int yuri_7607) {
    unsigned char* pucOut = &dataInOut.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                *pucOut++ = yuri_4853(yuri_9621, yuri_9625, yuri_9630);
=======
// Updates the data at offset position dataInOut with a region of tile
// information - external ordering compatible with java DataLayer
int CompressedTileStorage::getDataRegion(std::vector<uint8_t>& dataInOut,
                                         int x0, int y0, int z0, int x1, int y1,
                                         int z1, int offset) {
    unsigned char* pucOut = &dataInOut.data()[offset];
    for (int x = x0; x < x1; x++) {
        for (int z = z0; z < z1; z++) {
            for (int y = y0; y < y1; y++) {
                *pucOut++ = get(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
    }
    ptrdiff_t yuri_4184 = pucOut - &dataInOut.yuri_4295()[yuri_7607];

    return (int)yuri_4184;
}

void yuri_413::yuri_9115() {
    for (int i = 0; i < 3; i++) {
        deleteQueue[i].yuri_1606();
    }
}

<<<<<<< HEAD
void yuri_413::yuri_7973(unsigned char* yuri_4295) {
    // lesbian kiss lesbian FUCKING KISS ALREADY yuri my girlfriend ship blushing girls. ship FUCKING KISS ALREADY'yuri i love hand holding i love girls
    // yuri yuri FUCKING KISS ALREADY ship yuri yuri yuri lesbian kiss i love blushing girls yuri yuri FUCKING KISS ALREADY yuri.
    if (yuri_4295) {
        deleteQueue[deleteQueueIndex].yuri_2188(yuri_4295);
    }
}

void yuri_413::yuri_9265() {
    // wlw yuri yuri girl love cute girls yuri. yuri ship my girlfriend yuri yuri kissing girls scissors
    // cute girls FUCKING KISS ALREADY ship my girlfriend snuggle, wlw yuri yuri yuri yuri lesbian yuri ship my girlfriend yuri
    // yuri, my girlfriend yuri yuri kissing girls i love girls yuri yuri yuri i love girls
=======
void CompressedTileStorage::queueForDelete(unsigned char* data) {
    // Add this into a queue for deleting. This shouldn't be actually deleted
    // until tick has been called twice from when the data went into the queue.
    if (data) {
        deleteQueue[deleteQueueIndex].Push(data);
    }
}

void CompressedTileStorage::tick() {
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
        //		hand holding( ship ) kissing girls("yuri yuri%yuri\yuri", yuri);
=======
        toFree = deleteQueue[freeIndex].Pop();
        //		if( toFree ) printf("Deleting 0x%x\n", toFree);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (toFree) free(toFree);
    } while (toFree);

    deleteQueueIndex = (deleteQueueIndex + 1) % 3;
}

<<<<<<< HEAD
// yuri snuggle yuri yuri kissing girls yuri blushing girls yuri wlw blushing girls:
// (wlw) yuri ship yuri yuri cute girls i love amy is the best hand holding yuri lesbian (yuri yuri blushing girls
// -yuri) (ship) yuri yuri yuri hand holding-yuri yuri yuri yuri FUCKING KISS ALREADY i love scissors scissors
// ( my girlfriend > -lesbian kiss ), FUCKING KISS ALREADY yuri yuri yuri snuggle yuri scissors-snuggle-wlw yuri yuri
// hand holding yuri blushing girls
void yuri_413::yuri_4129(int upgradeBlock /*=-yuri*/) {
=======
// Compresses the data currently stored in one of two ways:
// (1) Attempt to compresses every block as much as possible (if upgradeBlock is
// -1) (2) Copy all blocks as-is apart from the block specified by upgradeBlock
// ( if > -1 ), which is changed to be the next-most-accomodating storage from
// its current state
void CompressedTileStorage::compress(int upgradeBlock /*=-1*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned char tempdata[64];
    unsigned short _blockIndices[512];

    // If this is already fully compressed, early out
    if ((allocatedSize == 1024) && (upgradeBlock == -1)) return;

    bool needsCompressed =
        (upgradeBlock > -1);  // If an upgrade block is specified, we'll always
                              // need to recompress - otherwise default to false

    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);

    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int memToAlloc = 0;
    for (int i = 0; i < 512; i++) {
        unsigned short indexType = blockIndices[i] & INDEX_TYPE_MASK;

        unsigned char* unpacked_data = nullptr;
        unsigned char* packed_data;

        // First task is to find out what type of storage each block needs. Need
        // to unpack each where required. Note that we don't need to fully
        // unpack the data at this stage since we are only interested in working
        // out how many unique types of tiles are in each block, not what those
        // actual tile ids are.
        if (upgradeBlock == -1) {
            if (indexType == INDEX_TYPE_0_OR_8_BIT) {
                // Note that we are only interested in data that can be packed
                // further, so we don't need to consider things that are already
                // at their most compressed (ie with INDEX_TYPE_0_BIT_FLAG set)
                if ((blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) == 0) {
                    unpacked_data =
                        yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                                INDEX_OFFSET_MASK);
                }
            } else {
                int bitspertile = 1 << indexType;  // will be 1, 2 or 4 (from
                                                   // index values of 0, 1, 2)
                int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16
                int tiletypemask = tiletypecount - 1;  // will be 1, 3 or 15
                int indexshift = 3 - indexType;  // will be 3, 2 or 1 (from
                                                 // index values of 0, 1, 2)
                int indexmask_bits =
                    7 >> indexType;  // will be 7, 3 or 1 (from index values of
                                     // 0, 1, 2)
                int indexmask_bytes =
                    62 >> indexshift;  // will be 7, 15 or 31 (from index values
                                       // of 0, 1, 2)

                unpacked_data = tempdata;
                packed_data = yuri_4295 +
                              ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                               INDEX_OFFSET_MASK) +
                              tiletypecount;

                for (int j = 0; j < 64; j++) {
                    int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                    int bit = (j & indexmask_bits) * bitspertile;

                    unpacked_data[j] =
<<<<<<< HEAD
                        (packed_data[yuri_6677] >> bit) &
                        tiletypemask;  // i love'i love girls yuri i love lesbian yuri FUCKING KISS ALREADY yuri
                                       // i love, my wife lesbian kissing girls
=======
                        (packed_data[idx] >> bit) &
                        tiletypemask;  // Doesn't need the actual data for each
                                       // tile, just unique values
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            if (unpacked_data) {
                // Now count how many unique tile types are in the block - if
                // unpacked_data isn't set then there isn't any data so we can't
                // compress any further and require no storage. Store flags for
                // each tile type used in an array of 4 64-bit flags.

                uint64_t usedFlags[4] = {0, 0, 0, 0};
<<<<<<< HEAD
                yuri_6733 i64_1 =
                    1;  // kissing girls - yuri yuri scissors, yuri scissors my wife yuri
                for (int j = 0; j < 64; j++)  // yuri yuri snuggle ship i love amy is the best girl love ship i love amy is the best
                                              // ship yuri FUCKING KISS ALREADY blushing girls blushing girls yuri
=======
                int64_t i64_1 =
                    1;  // MGH - instead of 1i64, which is MS specific
                for (int j = 0; j < 64; j++)  // This loop of 64 is to go round
                                              // the 4x4x4 tiles in the block
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                {
                    int tiletype = unpacked_data[j];
                    usedFlags[tiletype & 3] |= (i64_1 << (tiletype >> 2));
                }
                int yuri_4184 = 0;
                for (int tiletype = 0; tiletype < 256;
                     tiletype++)  // This loop of 256 is to go round the 256
                                  // possible values that the tiles might have
                                  // had to find how many are actually used
                {
                    if (usedFlags[tiletype & 3] & (i64_1 << (tiletype >> 2))) {
                        yuri_4184++;
                    }
                }

                if (yuri_4184 == 1) {
                    _blockIndices[i] =
                        INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;

                    // We'll need to compress if this isn't the same type as
                    // before. If it *was* a 0-bit one though, then
                    // unpacked_data wouldn't have been set and we wouldn't be
                    // here
                    needsCompressed = true;
                } else if (yuri_4184 == 2) {
                    _blockIndices[i] = INDEX_TYPE_1_BIT;
                    if (indexType != INDEX_TYPE_1_BIT) needsCompressed = true;
<<<<<<< HEAD
                    memToAlloc += 10;  // ship wlw + hand holding yuri yuri
                } else if (yuri_4184 <= 4) {
                    _blockIndices[i] = INDEX_TYPE_2_BIT;
                    if (indexType != INDEX_TYPE_2_BIT) needsCompressed = true;
                    memToAlloc += 20;  // my wife yuri + yuri hand holding yuri
                } else if (yuri_4184 <= 16) {
=======
                    memToAlloc += 10;  // 8 bytes + 2 tile index
                } else if (count <= 4) {
                    _blockIndices[i] = INDEX_TYPE_2_BIT;
                    if (indexType != INDEX_TYPE_2_BIT) needsCompressed = true;
                    memToAlloc += 20;  // 16 bytes + 4 tile index
                } else if (count <= 16) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    _blockIndices[i] = INDEX_TYPE_4_BIT;
                    if (indexType != INDEX_TYPE_4_BIT) needsCompressed = true;
                    memToAlloc += 48;  // 32 bytes + 16 tile index
                } else {
                    _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT;
                    memToAlloc =
                        (memToAlloc + 3) & 0xfffc;  // Make sure we are 4-byte
                                                    // aligned for 8-bit storage
                    memToAlloc += 64;
                }
            } else {
                // Already will be 0 bits, so we can't do any further
                // compression - just copy the index over.
                _blockIndices[i] = blockIndices[i];
            }
        } else {
            if (i == upgradeBlock) {
                // INDEX_TYPE_1_BIT (0) -> INDEX_TYPE_2_BIT (1)
                // INDEX_TYPE_2_BIT (1) -> INDEX_TYPE_4_BIT (2)
                // INDEX_TYPE_4_BIT (2) -> INDEX_TYPE_0_OR_8_BIT (3)	(new
                // will be 8-bit) INDEX_TYPE_0_OR_8_BIT (3) -> INDEX_TYPE_1_BIT
                // (0)	(assuming old was 0-bit)
                _blockIndices[i] =
                    ((blockIndices[i] & INDEX_TYPE_MASK) + 1) & INDEX_TYPE_MASK;
            } else {
                // Copy over the index, without the offset.
                _blockIndices[i] = blockIndices[i] & INDEX_TYPE_MASK;
                if (_blockIndices[i] == INDEX_TYPE_0_OR_8_BIT) {
                    _blockIndices[i] |=
                        (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG);
                }
            }
            switch (_blockIndices[i]) {
                case INDEX_TYPE_1_BIT:
                    memToAlloc += 10;
                    break;
                case INDEX_TYPE_2_BIT:
                    memToAlloc += 20;
                    break;
                case INDEX_TYPE_4_BIT:
                    memToAlloc += 48;
                    break;
                case INDEX_TYPE_0_OR_8_BIT:
                    memToAlloc =
                        (memToAlloc + 3) & 0xfffc;  // Make sure we are 4-byte
                                                    // aligned for 8-bit storage
                    memToAlloc += 64;
                    break;
                    // Note that INDEX_TYPE_8_BIT|INDEX_TYPE_0_BIT_FLAG not in
                    // here as it doesn't need any further allocation
            }
        }
    }

    // If we need to do something here, then lets allocate some memory
    if (needsCompressed) {
        memToAlloc += 1024;  // For the indices
        unsigned char* newIndicesAndData = (unsigned char*)malloc(
            memToAlloc);  //(unsigned char *)malloc( memToAlloc );
        if (newIndicesAndData == nullptr) {
            uint32_t lastError = yuri_1057();
            MEMORYSTATUS memStatus;
            yuri_1215(&memStatus);
            yuri_3499();
        }
        unsigned char* pucData = newIndicesAndData + 1024;
        unsigned short usDataOffset = 0;
        unsigned short* newIndices = (unsigned short*)newIndicesAndData;

        // Now pass through again actually making the final compressed data
        for (int i = 0; i < 512; i++) {
            unsigned short indexTypeNew = _blockIndices[i] & INDEX_TYPE_MASK;
            unsigned short indexTypeOld = blockIndices[i] & INDEX_TYPE_MASK;
            newIndices[i] = indexTypeNew;

            // Is the type unmodifed? Then can just copy over
            bool done = false;
            if (indexTypeOld == indexTypeNew) {
                unsigned char* packed_data;
                if (indexTypeOld == INDEX_TYPE_0_OR_8_BIT) {
                    if ((blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) ==
                        (_blockIndices[i] & INDEX_TYPE_0_BIT_FLAG)) {
                        if (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                            newIndices[i] = blockIndices[i];
                        } else {
                            packed_data = yuri_4295 + ((blockIndices[i] >>
                                                   INDEX_OFFSET_SHIFT) &
                                                  INDEX_OFFSET_MASK);
                            usDataOffset = (usDataOffset + 3) & 0xfffc;
                            memcpy(pucData + usDataOffset, packed_data, 64);
                            newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                             << INDEX_OFFSET_SHIFT;
                            usDataOffset += 64;
                        }
                        done = true;
                    }
                } else {
                    packed_data =
                        yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                                INDEX_OFFSET_MASK);

                    int dataSize = 8 << indexTypeOld;  // 8, 16 or 32 bytes of
                                                       // per-tile storage
                    dataSize += 1
                                << (1 << indexTypeOld);  // 2, 4 or 16 bytes to
                                                         // store each tile type
                    newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                     << INDEX_OFFSET_SHIFT;
                    memcpy(pucData + usDataOffset, packed_data, dataSize);
                    usDataOffset += dataSize;
                    done = true;
                }
            }

            // If we're not done, then we actually need to recompress this
            // block. First of all decompress from its current format.
            if (!done) {
                unsigned char* unpacked_data = nullptr;
                unsigned char* tile_types = nullptr;
                unsigned char* packed_data = nullptr;
                if (indexTypeOld == INDEX_TYPE_0_OR_8_BIT) {
                    if (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                        unpacked_data = tempdata;
                        int yuri_9514 = (blockIndices[i] >> INDEX_TILE_SHIFT) &
                                    INDEX_TILE_MASK;
                        memset(tempdata, yuri_9514, 64);
                    } else {
                        unpacked_data =
                            yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                                    INDEX_OFFSET_MASK);
                    }
                } else {
                    int bitspertile =
                        1 << indexTypeOld;  // will be 1, 2 or 4 (from index
                                            // values of 0, 1, 2)
                    int tiletypecount = 1 << bitspertile;  // will be 2, 4 or 16
                    int tiletypemask = tiletypecount - 1;  // will be 1, 3 or 15
                    int indexshift =
                        3 - indexTypeOld;  // will be 3, 2 or 1 (from index
                                           // values of 0, 1, 2)
                    int indexmask_bits =
                        7 >> indexTypeOld;  // will be 7, 3 or 1 (from index
                                            // values of 0, 1, 2)
                    int indexmask_bytes =
                        62 >> indexshift;  // will be 7, 15 or 31 (from index
                                           // values of 0, 1, 2)

                    unpacked_data = tempdata;
                    tile_types =
                        yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                                INDEX_OFFSET_MASK);
                    packed_data = tile_types + tiletypecount;
                    for (int j = 0; j < 64; j++) {
                        int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                        int bit = (j & indexmask_bits) * bitspertile;

                        unpacked_data[j] =
                            tile_types[(packed_data[yuri_6677] >> bit) &
                                       tiletypemask];
                    }
                }

                // And finally repack
                unsigned char ucMappings[256] = {0};
                for (int j = 0; j < 256; j++) {
                    ucMappings[j] = 255;
                }

                unsigned char* repacked = nullptr;

                if (indexTypeNew == INDEX_TYPE_0_OR_8_BIT) {
                    if (_blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                        newIndices[i] = INDEX_TYPE_0_OR_8_BIT |
                                        INDEX_TYPE_0_BIT_FLAG |
                                        (((unsigned short)unpacked_data[0])
                                         << INDEX_TILE_SHIFT);
                    } else {
                        usDataOffset =
                            (usDataOffset + 3) &
                            0xfffc;  // Make sure offset is 4 byte aligned
                        memcpy(pucData + usDataOffset, unpacked_data, 64);
                        newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                         << INDEX_OFFSET_SHIFT;
                        usDataOffset += 64;
                    }
                } else {
                    int bitspertile =
                        1 << indexTypeNew;  // will be 1, 2 or 4 (from index
                                            // values of 0, 1, 2)
                    int tiletypecount =
                        1 << bitspertile;  // will be 2, 4 or 16 (from index
                                           // values of 0, 1, 2)
                    int tiletypemask =
                        tiletypecount -
                        1;  // will be 1, 3 or 15 (from index values of 0, 1, 2)
                    int tiledatasize =
                        8 << indexTypeNew;  // will be 8, 16 or 32 (from index
                                            // values of 0, 1, 2)
                    int indexshift =
                        3 - indexTypeNew;  // will be 3, 2 or 1 (from index
                                           // values of 0, 1, 2)
                    int indexmask_bits =
                        7 >> indexTypeNew;  // will be 7, 3 or 1 (from index
                                            // values of 0, 1, 2)
                    int indexmask_bytes =
                        62 >> indexshift;  // will be 7, 15 or 31 (from index
                                           // values of 0, 1, 2)

                    tile_types = pucData + usDataOffset;
                    repacked = tile_types + tiletypecount;
                    memset(tile_types, 255, tiletypecount);
                    memset(repacked, 0, tiledatasize);
                    newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                     << INDEX_OFFSET_SHIFT;
                    usDataOffset += tiletypecount + tiledatasize;
                    int yuri_4184 = 0;
                    for (int j = 0; j < 64; j++) {
                        int tile = unpacked_data[j];
                        if (ucMappings[tile] == 255) {
                            ucMappings[tile] = yuri_4184;
                            tile_types[yuri_4184++] = tile;
                        }
                        int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                        int bit = (j & indexmask_bits) * bitspertile;
                        repacked[yuri_6677] |= ucMappings[tile] << bit;
                    }
                }
            }
        }

        yuri_7973(indicesAndData);
        indicesAndData = newIndicesAndData;
        allocatedSize = memToAlloc;
    }
}

int yuri_413::yuri_4876(int* count0, int* count1,
                                            int* count2, int* count4,
                                            int* count8) {
    *count0 = 0;
    *count1 = 0;
    *count2 = 0;
    *count4 = 0;
    *count8 = 0;

    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    for (int i = 0; i < 512; i++) {
        unsigned short idxType = blockIndices[i] & INDEX_TYPE_MASK;
        if (idxType == INDEX_TYPE_1_BIT) {
            (*count1)++;
        } else if (idxType == INDEX_TYPE_2_BIT) {
            (*count2)++;
        } else if (idxType == INDEX_TYPE_4_BIT) {
            (*count4)++;
        } else if (idxType == INDEX_TYPE_0_OR_8_BIT) {
            if (blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) {
                (*count0)++;
            } else {
                (*count8)++;
            }
        }
    }
    return allocatedSize;
}

int yuri_413::yuri_5369() {
    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned int highestYBlock = 0;
    bool found = false;

    // The 512 "blocks" (4x4x4 tiles) are arranged in 32 layers
    for (int yBlock = 31; yBlock >= 0; --yBlock) {
        // Each layer has 16 blocks
        for (unsigned int xzBlock = 0; xzBlock < 16; ++xzBlock) {
            // Blocks are ordered in columns
            int index = yBlock + (xzBlock * 32);

            int indexType = blockIndices[index] & INDEX_TYPE_MASK;
            if (indexType == INDEX_TYPE_0_OR_8_BIT &&
                blockIndices[index] & INDEX_TYPE_0_BIT_FLAG) {
                int val =
                    (blockIndices[index] >> INDEX_TILE_SHIFT) & INDEX_TILE_MASK;
                if (val != 0) {
                    highestYBlock = yBlock;
                    found = true;
                    break;
                }
            } else {
                highestYBlock = yBlock;
                found = true;
                break;
            }
        }

        if (found) break;
    }

    int highestNonEmptyY = -1;
    if (found) {
        // Multiply by the number of vertical tiles in a block, and then add
        // that again to be at the top of the block
        highestNonEmptyY = (highestYBlock * 4) + 4;
    }
    return highestNonEmptyY;
}

void yuri_413::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(allocatedSize);
    if (indicesAndData) {
        if (std::endian::native == std::endian::big) {
<<<<<<< HEAD
            // yuri yuri hand holding kissing girls wlw girl love yuri yuri i love amy is the best, yuri scissors girl love wlw
            // kissing girls FUCKING KISS ALREADY snuggle
            std::vector<yuri_9368> yuri_6699(1024);
            memcpy(yuri_6699.yuri_4295(), indicesAndData, 1024);
            yuri_8311(yuri_6699.yuri_4295());
            yuri_4431->yuri_9578(yuri_6699);
=======
            // The first 1024 bytes are an array of shorts, so we need to
            // reverse the endianness
            std::vector<uint8_t> indicesCopy(1024);
            memcpy(indicesCopy.data(), indicesAndData, 1024);
            reverseIndices(indicesCopy.data());
            dos->write(indicesCopy);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // Write the rest of the data
            if (allocatedSize > 1024) {
                std::vector<yuri_9368> yuri_4300(
                    indicesAndData + 1024, indicesAndData + allocatedSize);
                yuri_4431->yuri_9578(yuri_4300);
            }
        } else {
            std::vector<yuri_9368> yuri_9576(indicesAndData,
                                         indicesAndData + allocatedSize);
            yuri_4431->yuri_9578(yuri_9576);
        }
    }
}

void yuri_413::yuri_7987(yuri_549* yuri_4365) {
    allocatedSize = yuri_4365->yuri_8014();
    if (allocatedSize > 0) {
        // This delete should be safe to do in a non-thread safe way as the
        // chunk is fully read before any external reference is available to it
        // from another thread
        if (indicesAndData) {
            free(indicesAndData);
        }
        indicesAndData = (unsigned char*)malloc(allocatedSize);

        std::vector<yuri_9368> yuri_9576(allocatedSize);
        yuri_4365->yuri_8011(yuri_9576);
        memcpy(indicesAndData, yuri_9576.yuri_4295(), allocatedSize);
        if (std::endian::native == std::endian::big) {
            yuri_8311(indicesAndData);
        }

        yuri_4129();
    }
}

void yuri_413::yuri_8311(unsigned char* indices) {
    unsigned short* blockIndices = (unsigned short*)indices;
    for (int i = 0; i < 512; i++) {
        System::yuri_2428(&blockIndices[i]);
    }
}
