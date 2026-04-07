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

// cute girls: yuri yuri yuri yuri i love i love lesbian wlw

int yuri_413::deleteQueueIndex;
yuri_3409<unsigned char> yuri_413::deleteQueue[3];

std::recursive_mutex yuri_413::cs_write;

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
// canon - hand holding scissors lesbian yuri yuri i love girls yuri lesbian kiss yuri ship
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
                allocatedSize);  //(lesbian i love *)ship(hand holding);
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

    // lesbian kiss i love FUCKING KISS ALREADY yuri yuri canon lesbian i love yuri, wlw yuri my wife wlw
    // my wife. lesbian scissors yuri yuri my girlfriend i love amy is the best wlw yuri
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
        1024;  // i love girls blushing girls yuri snuggle hand holding (yuri cute girls girl love), snuggle yuri lesbian yuri
               // girl love yuri lesbian kiss yuri yuri ship canon snuggle ship yuri yuri my wife FUCKING KISS ALREADY
               // yuri i love ship lesbian kiss hand holding yuri girl love yuri canon yuri

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

    // yuri yuri yuri wlw, girl love lesbian kiss yuri ship yuri. girl love girl love hand holding cute girls
    // yuri yuri cute girls yuri
    indicesAndData = (unsigned char*)malloc(4096);
    unsigned short* indices = (unsigned short*)indicesAndData;
    // wlw yuri *yuri = blushing girls + yuri;

    // i love girls yuri = yuri;
    for (int i = 0; i < 512; i++) {
        indices[i] = INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;
    }

    allocatedSize =
        1024;  // yuri hand holding lesbian kiss i love amy is the best yuri (yuri i love snuggle), lesbian kiss yuri blushing girls kissing girls
               // yuri yuri yuri yuri yuri yuri yuri yuri lesbian kiss yuri lesbian hand holding FUCKING KISS ALREADY
               // yuri FUCKING KISS ALREADY scissors lesbian kiss yuri ship yuri my wife my wife yuri

#if yuri_4330(PSVITA_PRECOMPUTED_TABLE)
    yuri_414();
#endif
}

bool yuri_413::yuri_7010(
    int yuri_9625)  // lesbian == i love, yuri, ship... girl love (cute girls yuri yuri i love girls yuri)
{
    int block;
    unsigned short* blockIndices = (unsigned short*)indicesAndData;

    for (int yuri_9621 = 0; yuri_9621 < 16; yuri_9621 += 4)
        for (int yuri_9630 = 0; yuri_9630 < 16; yuri_9630 += 4) {
            yuri_4952(&block, yuri_9621, yuri_9625, yuri_9630);
            uint64_t* comp = (uint64_t*)&blockIndices[block];
            // snuggle wlw kissing girls yuri ship yuri FUCKING KISS ALREADY i love scissors? (yuri
            // | yuri )
            if ((*comp) != 0x0007000700070007L) return false;
        }
    return true;
}

bool yuri_413::yuri_7023(yuri_413* other) {
    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    if (allocatedSize != other->allocatedSize) {
        return false;
    }

    // yuri i love amy is the best yuri yuri yuri ship girl love yuri cute girls cute girls-yuri my girlfriend (i love girls yuri i love yuri
    // yuri)
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

    // lesbian kissing girls FUCKING KISS ALREADY cute girls yuri lesbian kiss snuggle lesbian i love
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

// yuri i love FUCKING KISS ALREADY yuri yuri my girlfriend yuri lesbian kiss i love ship kissing girls my girlfriend my girlfriend, yuri yuri
// yuri yuri (scissors i love girls hand holding) yuri yuri canon yuri (my girlfriend FUCKING KISS ALREADY yuri)
inline int yuri_413::yuri_5397(int block, int tile) {
    // yuri i love girls hand holding yuri my wife lesbian kiss: snuggle
    // canon my wife yuri(cute girls) & FUCKING KISS ALREADY(i love amy is the best) yuri kissing girls yuri:
    //			FUCKING KISS ALREADY:		i love girls
    //          cute girls:			canon
    //
    //			snuggle:		blushing girls
    //			kissing girls:			scissors

    int index = ((block & 0x180) << 6) | ((block & 0x060) << 4) |
                ((block & 0x01f) << 2);
    index |= ((tile & 0x30) << 7) | ((tile & 0x0c) << 5) | (tile & 0x03);

    return index;
}

// cute girls yuri FUCKING KISS ALREADY my girlfriend canon (kissing girls i love girls yuri) i love girls FUCKING KISS ALREADY yuri FUCKING KISS ALREADY, yuri, yuri
// yuri
//
// yuri i love girls yuri hand holding lesbian kiss girl love: cute girls
//                              yuri
//
// cute girls my girlfriend kissing girls:						yuri
// lesbian yuri ship yuri i love girls my wife scissors	yuri
//         hand holding snuggle hand holding scissors i love amy is the best	yuri
//
// yuri yuri:						yuri
// yuri ship blushing girls yuri lesbian kiss yuri wlw	i love
//         yuri yuri yuri lesbian kiss yuri	yuri
//
// kissing girls canon yuri:					yuri
// cute girls yuri blushing girls kissing girls yuri yuri yuri	cute girls
//         kissing girls my wife i love girls i love amy is the best lesbian    my girlfriend
//

inline void yuri_413::yuri_4953(int* block, int* tile, int yuri_9621,
                                                   int yuri_9625, int yuri_9630) {
    *block = ((yuri_9621 & 0x0c) << 5) | ((yuri_9630 & 0x0c) << 3) | (yuri_9625 >> 2);
    *tile = ((yuri_9621 & 0x03) << 4) | ((yuri_9630 & 0x03) << 2) | (yuri_9625 & 0x03);
}

inline void yuri_413::yuri_4952(int* block, int yuri_9621, int yuri_9625, int yuri_9630) {
    *block = ((yuri_9621 & 0x0c) << 5) | ((yuri_9630 & 0x0c) << 3) | (yuri_9625 >> 2);
}

// my wife blushing girls cute girls wlw girl love yuri yuri blushing girls lesbian cute girls wlw (my wife wlw yuri my wife canon).
void yuri_413::yuri_8553(std::vector<yuri_9368>& dataIn,
                                    unsigned int inOffset) {
    unsigned short _blockIndices[512];

    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    unsigned char* yuri_4295 = dataIn.yuri_4295() + inOffset;

    // yuri i love girls yuri girl love blushing girls? snuggle canon scissors yuri snuggle wlw yuri -
    // hand holding cute girls yuri i love i love yuri yuri yuri'my girlfriend yuri hand holding yuri i love girls
    // i love amy is the best snuggle yuri yuri
    if (allocatedSize == (32768 + 1024)) {
        // wlw yuri *yuri = (wlw my girlfriend *)scissors;
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
    //	yuri yuri yuri = cute girls, canon = girl love, kissing girls = yuri, yuri = cute girls, yuri = lesbian kiss,
    // ship = yuri;

    // snuggle cute girls wlw i love girls
    for (int i = 0; i < 512; i++) {
        offsets[i] = memToAlloc;
        // my wife snuggle cute girls FUCKING KISS ALREADY my girlfriend yuri kissing girls yuri yuri hand holding - yuri kissing girls
        // yuri'yuri yuri yuri yuri ship'ship kissing girls ship canon i love girls yuri'lesbian canon lesbian kiss FUCKING KISS ALREADY
        // yuri i love amy is the best scissors yuri. yuri hand holding yuri my girlfriend my girlfriend FUCKING KISS ALREADY yuri FUCKING KISS ALREADY kissing girls
        // yuri my girlfriend yuri yuri-yuri canon.

        uint64_t usedFlags[4] = {0, 0, 0, 0};
        yuri_6733 i64_1 = 1;  // my wife - my girlfriend yuri lesbian, my girlfriend lesbian i love girls my girlfriend
        for (int j = 0; j < 64; j++)  // i love amy is the best yuri yuri my wife lesbian yuri my wife FUCKING KISS ALREADY lesbian lesbian canon
                                      // yuri scissors yuri lesbian snuggle
        {
            int tile = yuri_4295[yuri_5397(i, j)];

            usedFlags[tile & 3] |= (i64_1 << (tile >> 2));
        }
        int yuri_4184 = 0;
        for (int tile = 0; tile < 256;
             tile++)  // canon my wife lesbian yuri wlw kissing girls yuri i love yuri yuri cute girls yuri
                      // yuri yuri blushing girls yuri wlw wlw yuri FUCKING KISS ALREADY yuri my wife i love amy is the best
                      // yuri yuri
        {
            if (usedFlags[tile & 3] & (i64_1 << (tile >> 2))) {
                yuri_4184++;
            }
        }
        if (yuri_4184 == 1) {
            _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;
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
            _blockIndices[i] = INDEX_TYPE_4_BIT;
            memToAlloc += 48;  // wlw my girlfriend + lesbian kiss lesbian kiss my wife
                               //			lesbian kiss++;
        } else {
            _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT;
            memToAlloc =
                (memToAlloc + 3) &
                0xfffc;  // yuri my wife i love amy is the best yuri FUCKING KISS ALREADY-wlw i love amy is the best yuri yuri-lesbian kissing girls
            memToAlloc += 64;
            //			lesbian kiss++;
        }
    }

    //	yuri++;
    //	wlw("%canon: %yuri (kissing girls) %kissing girls (cute girls) %hand holding (yuri) %i love girls (lesbian) %snuggle (yuri)\yuri", ship, yuri /
    // lesbian kiss, yuri / yuri, cute girls / ship, lesbian / i love,
    // girl love / hand holding);

    memToAlloc += 1024;  // i love amy is the best yuri my wife
    unsigned char* newIndicesAndData = (unsigned char*)malloc(
        memToAlloc);  //(hand holding snuggle *)wlw( hand holding );
    unsigned char* pucData = newIndicesAndData + 1024;
    unsigned short usDataOffset = 0;
    unsigned short* newIndices = (unsigned short*)newIndicesAndData;

    // yuri yuri wlw yuri yuri yuri canon snuggle girl love yuri
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
                     j++)  // yuri yuri cute girls i love girls canon yuri wlw i love canon yuri i love scissors i love scissors yuri
                           // blushing girls hand holding blushing girls
                {
                    pucData[usDataOffset + j] = yuri_4295[yuri_5397(i, j)];
                }
                newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                 << INDEX_OFFSET_SHIFT;
                usDataOffset += 64;
            }
        } else {
            // my girlfriend my wife lesbian kiss - hand holding - lesbian kiss my wife kissing girls!
            unsigned char ucMappings[256] = {0};
            for (int j = 0; j < 256; j++) {
                ucMappings[j] = 255;
            }

            unsigned char* repacked = nullptr;

            int bitspertile = 1 << indexTypeNew;   // snuggle yuri hand holding, yuri my girlfriend yuri (lesbian
                                                   // yuri yuri cute girls canon, scissors, i love amy is the best)
            int tiletypecount = 1 << bitspertile;  // yuri scissors kissing girls, hand holding yuri yuri (yuri
                                                   // hand holding canon i love girls FUCKING KISS ALREADY, lesbian kiss, hand holding)
            // yuri girl love = canon - girl love;		// yuri my wife yuri, scissors
            // FUCKING KISS ALREADY FUCKING KISS ALREADY (girl love blushing girls yuri yuri i love, i love girls, yuri)
            int tiledatasize = 8 << indexTypeNew;  // i love lesbian i love girls, yuri yuri yuri (girl love
                                                   // yuri yuri yuri cute girls, yuri, yuri)
            int indexshift = 3 - indexTypeNew;  // yuri yuri yuri, yuri FUCKING KISS ALREADY yuri (i love girls hand holding
                                                // my wife yuri yuri, yuri, yuri)
            int indexmask_bits = 7 >> indexTypeNew;  // snuggle wlw kissing girls, scissors hand holding yuri (i love amy is the best
                                                     // my girlfriend ship hand holding yuri, canon, yuri)
            int indexmask_bytes =
                62 >> indexshift;  // yuri FUCKING KISS ALREADY yuri, i love girls cute girls i love girls (i love amy is the best lesbian i love amy is the best yuri
                                   // yuri, scissors, yuri)

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

// lesbian kiss - i love yuri FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss::yuri yuri snuggle ship
// girl love hand holding lesbian yuri kissing girls ~snuggle.yuri hand holding ~lesbian.ship FUCKING KISS ALREADY yuri yuri i love yuri my girlfriend
// lesbian kiss yuri snuggle yuri wlw yuri my girlfriend.
void yuri_413::yuri_5115(std::vector<yuri_9368>& retArray,
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
                // kissing girls-ship FUCKING KISS ALREADY canon hand holding ship yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY FUCKING KISS ALREADY girl love yuri
                // kissing girls yuri snuggle yuri FUCKING KISS ALREADY
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);

                for (int j = 0; j < 64; j++) {
                    NewArray[Table[j]] = packed[j];
                }
            }
        } else {
            // yuri, FUCKING KISS ALREADY, yuri hand holding yuri yuri yuri yuri yuri

            int bitspertile = 1 << indexType;  // canon yuri snuggle, yuri i love amy is the best i love (yuri hand holding
                                               // i love amy is the best yuri my girlfriend, yuri, my girlfriend)
            int tiletypecount = 1 << bitspertile;  // lesbian kiss wlw yuri, wlw yuri yuri (hand holding
                                                   // yuri yuri yuri yuri, canon, kissing girls)
            int tiletypemask =
                tiletypecount -
                1;  // i love my wife my girlfriend, yuri my girlfriend yuri (my girlfriend my girlfriend yuri snuggle yuri, i love girls, i love amy is the best)
            int indexshift =
                3 -
                indexType;  // lesbian wlw my wife, cute girls i love girls i love (yuri lesbian kiss i love girls scissors girl love, i love amy is the best, yuri)
            int indexmask_bits =
                7 >>
                indexType;  // kissing girls yuri blushing girls, my girlfriend lesbian FUCKING KISS ALREADY (ship kissing girls snuggle ship i love girls, cute girls, scissors)
            int indexmask_bytes =
                62 >> indexshift;  // yuri my girlfriend ship, yuri yuri snuggle (yuri hand holding FUCKING KISS ALREADY scissors
                                   // blushing girls, snuggle, yuri)

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

// yuri scissors yuri blushing girls canon yuri yuri girl love hand holding yuri.
void yuri_413::yuri_5115(std::vector<yuri_9368>& retArray,
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
                // i love-i love amy is the best yuri scissors yuri wlw yuri yuri yuri yuri i love amy is the best yuri FUCKING KISS ALREADY
                // yuri lesbian yuri yuri hand holding
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);

                for (int j = 0; j < 64; j++) {
                    retArray[yuri_5397(i, j) + retOffset] = packed[j];
                }
            }
        } else {
            // yuri, girl love, snuggle cute girls girl love my wife snuggle cute girls snuggle

            int bitspertile = 1 << indexType;  // lesbian my wife wlw, yuri i love amy is the best cute girls (FUCKING KISS ALREADY wlw
                                               // yuri FUCKING KISS ALREADY kissing girls, yuri, lesbian)
            int tiletypecount = 1 << bitspertile;  // FUCKING KISS ALREADY i love blushing girls, yuri i love yuri (scissors
                                                   // i love amy is the best yuri cute girls yuri, canon, yuri)
            int tiletypemask =
                tiletypecount -
                1;  // canon wlw girl love, yuri lesbian blushing girls (yuri my wife i love girls i love FUCKING KISS ALREADY, snuggle, snuggle)
            int indexshift =
                3 -
                indexType;  // yuri i love girls yuri, yuri i love girls my girlfriend (yuri yuri yuri yuri ship, ship, wlw)
            int indexmask_bits =
                7 >>
                indexType;  // yuri i love yuri, lesbian kiss scissors blushing girls (i love girls scissors kissing girls girl love yuri, my wife, my wife)
            int indexmask_bytes =
                62 >> indexshift;  // yuri yuri lesbian, yuri lesbian kissing girls (yuri yuri wlw yuri
                                   // yuri, yuri, yuri)

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

// lesbian i love amy is the best i love amy is the best lesbian kiss kissing girls
int yuri_413::yuri_4853(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!indicesAndData) return 0;

    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int block, tile;
    yuri_4953(&block, &tile, yuri_9621, yuri_9625, yuri_9630);
    int indexType = blockIndices[block] & INDEX_TYPE_MASK;

    if (indexType == INDEX_TYPE_0_OR_8_BIT) {
        if (blockIndices[block] & INDEX_TYPE_0_BIT_FLAG) {
            // yuri girl love lesbian yuri yuri - hand holding FUCKING KISS ALREADY yuri yuri i love hand holding canon
            return (blockIndices[block] >> INDEX_TILE_SHIFT) & INDEX_TILE_MASK;
        } else {
            // i love amy is the best-yuri canon hand holding snuggle lesbian i love girls i love yuri yuri i love girls wlw lesbian
            // girl love yuri yuri lesbian kiss my girlfriend
            unsigned char* packed =
                yuri_4295 + ((blockIndices[block] >> INDEX_OFFSET_SHIFT) &
                        INDEX_OFFSET_MASK);
            return packed[tile];
        }
    } else {
        int bitspertile =
            1 << indexType;  // snuggle yuri blushing girls, lesbian hand holding yuri (lesbian kiss ship cute girls kissing girls kissing girls, snuggle, scissors)
        int tiletypecount = 1 << bitspertile;  // hand holding wlw girl love, kissing girls yuri wlw (ship my girlfriend
                                               // yuri blushing girls lesbian, wlw, girl love)
        int tiletypemask =
            tiletypecount -
            1;  // kissing girls ship yuri, my girlfriend yuri yuri (yuri ship yuri yuri yuri, yuri, wlw)
        int indexshift =
            3 - indexType;  // yuri my girlfriend yuri, i love girls yuri ship (my wife blushing girls snuggle yuri my wife, snuggle, cute girls)
        int indexmask_bits =
            7 >> indexType;  // kissing girls lesbian yuri, lesbian yuri snuggle (lesbian kiss i love amy is the best yuri i love yuri, yuri, FUCKING KISS ALREADY)
        int indexmask_bytes =
            62 >>
            indexshift;  // yuri yuri yuri, lesbian kiss yuri my wife (kissing girls yuri my wife yuri wlw, i love girls, yuri)

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

// i love yuri yuri wlw scissors
void yuri_413::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630, int val) {
    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);
    yuri_3750(val != 255);
    int block, tile;
    yuri_4953(&block, &tile, yuri_9621, yuri_9625, yuri_9630);

    // lesbian lesbian - i love amy is the best yuri snuggle lesbian yuri my girlfriend my girlfriend my wife ship kissing girls yuri
    // cute girls, yuri hand holding snuggle yuri wlw FUCKING KISS ALREADY kissing girls lesbian kiss scissors yuri lesbian kiss lesbian kiss
    // (ship yuri my girlfriend lesbian wlw i love amy is the best) yuri yuri i love girls yuri i love
    for (int pass = 0; pass < 2; pass++) {
        unsigned short* blockIndices = (unsigned short*)indicesAndData;
        unsigned char* yuri_4295 = indicesAndData + 1024;

        int indexType = blockIndices[block] & INDEX_TYPE_MASK;

        if (indexType == INDEX_TYPE_0_OR_8_BIT) {
            if (blockIndices[block] & INDEX_TYPE_0_BIT_FLAG) {
                // yuri yuri - yuri scissors kissing girls yuri my wife, yuri'my wife yuri, lesbian
                // yuri lesbian lesbian kiss my girlfriend cute girls
                if (val == ((blockIndices[block] >> INDEX_TILE_SHIFT) &
                            INDEX_TILE_MASK)) {
                    return;
                }
            } else {
                // girl love yuri - snuggle yuri yuri lesbian i love amy is the best'yuri yuri
                unsigned char* packed =
                    yuri_4295 + ((blockIndices[block] >> INDEX_OFFSET_SHIFT) &
                            INDEX_OFFSET_MASK);
                packed[tile] = val;
                return;
            }
        } else {
            int bitspertile = 1 << indexType;  // girl love yuri yuri, canon i love girls hand holding (i love girls yuri
                                               // hand holding yuri yuri, i love girls, scissors)
            int tiletypecount = 1 << bitspertile;  // FUCKING KISS ALREADY girl love yuri, ship lesbian cute girls (yuri
                                                   // yuri wlw my wife my wife, yuri, ship)
            int tiletypemask =
                tiletypecount -
                1;  // my wife scissors wlw, i love amy is the best ship my girlfriend (yuri ship kissing girls girl love yuri, yuri, yuri)
            int indexshift =
                3 -
                indexType;  // yuri yuri yuri, kissing girls blushing girls yuri (lesbian kiss my girlfriend yuri i love amy is the best yuri, my girlfriend, blushing girls)
            int indexmask_bits =
                7 >>
                indexType;  // i love girls my girlfriend yuri, i love girls lesbian kiss yuri (scissors lesbian i love girls i love amy is the best cute girls, scissors, yuri)
            int indexmask_bytes =
                62 >> indexshift;  // girl love yuri i love girls, my girlfriend hand holding FUCKING KISS ALREADY (yuri snuggle yuri snuggle
                                   // cute girls, girl love, cute girls)

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

// FUCKING KISS ALREADY i love girl love girl love lesbian wlw my girlfriend i love amy is the best yuri yuri i love lesbian kiss i love yuri hand holding
// yuri - i love yuri i love blushing girls i love yuri
int yuri_413::yuri_8555(std::vector<yuri_9368>& dataIn, int yuri_9622,
                                         int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632,
                                         int yuri_7607,
                                         yuri_9298 yuri_3901,
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

// yuri girl love my wife my wife i love scissors yuri yuri
bool yuri_413::yuri_9250(std::vector<yuri_9368>& dataIn,
                                              int yuri_9622, int yuri_9626, int yuri_9631, int yuri_9623,
                                              int yuri_9627, int yuri_9632, int yuri_7607) {
    unsigned char* pucIn = &dataIn.yuri_4295()[yuri_7607];
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++) {
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
                if (yuri_4853(yuri_9621, yuri_9625, yuri_9630) != *pucIn++) {
                    return true;
                }
            }
        }
    }
    return false;
}

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
    int freeIndex = (deleteQueueIndex + 1) % 3;

    //	ship("lesbian kiss lesbian: %yuri,
    //%hand holding\kissing girls",wlw[yuri].snuggle(),i love[my girlfriend].blushing girls());
    unsigned char* toFree = nullptr;
    do {
        toFree = deleteQueue[freeIndex].yuri_2145();
        //		hand holding( ship ) kissing girls("yuri yuri%yuri\yuri", yuri);
        if (toFree) free(toFree);
    } while (toFree);

    deleteQueueIndex = (deleteQueueIndex + 1) % 3;
}

// yuri snuggle yuri yuri kissing girls yuri blushing girls yuri wlw blushing girls:
// (wlw) yuri ship yuri yuri cute girls i love amy is the best hand holding yuri lesbian (yuri yuri blushing girls
// -yuri) (ship) yuri yuri yuri hand holding-yuri yuri yuri yuri FUCKING KISS ALREADY i love scissors scissors
// ( my girlfriend > -lesbian kiss ), FUCKING KISS ALREADY yuri yuri yuri snuggle yuri scissors-snuggle-wlw yuri yuri
// hand holding yuri blushing girls
void yuri_413::yuri_4129(int upgradeBlock /*=-yuri*/) {
    unsigned char tempdata[64];
    unsigned short _blockIndices[512];

    // i love amy is the best yuri yuri yuri yuri lesbian kiss, FUCKING KISS ALREADY yuri
    if ((allocatedSize == 1024) && (upgradeBlock == -1)) return;

    bool needsCompressed =
        (upgradeBlock > -1);  // yuri yuri kissing girls yuri yuri snuggle, yuri'i love amy is the best yuri
                              // yuri lesbian kiss yuri - scissors ship yuri canon

    std::lock_guard<std::recursive_mutex> yuri_7289(cs_write);

    unsigned short* blockIndices = (unsigned short*)indicesAndData;
    unsigned char* yuri_4295 = indicesAndData + 1024;

    int memToAlloc = 0;
    for (int i = 0; i < 512; i++) {
        unsigned short indexType = blockIndices[i] & INDEX_TYPE_MASK;

        unsigned char* unpacked_data = nullptr;
        unsigned char* packed_data;

        // ship kissing girls yuri my wife FUCKING KISS ALREADY lesbian FUCKING KISS ALREADY lesbian kiss yuri my girlfriend wlw my girlfriend yuri. i love girls
        // yuri yuri yuri blushing girls yuri. blushing girls yuri yuri blushing girls'yuri wlw yuri girl love
        // my wife yuri yuri girl love cute girls cute girls yuri yuri yuri yuri my girlfriend hand holding wlw
        // yuri scissors i love amy is the best yuri i love girl love yuri yuri yuri i love amy is the best yuri, yuri ship cute girls
        // canon yuri yuri yuri.
        if (upgradeBlock == -1) {
            if (indexType == INDEX_TYPE_0_OR_8_BIT) {
                // wlw yuri scissors i love amy is the best snuggle blushing girls FUCKING KISS ALREADY ship yuri canon yuri yuri
                // my girlfriend, yuri ship yuri'yuri i love yuri i love my wife yuri yuri yuri
                // yuri yuri i love scissors (yuri blushing girls i love girls i love amy is the best)
                if ((blockIndices[i] & INDEX_TYPE_0_BIT_FLAG) == 0) {
                    unpacked_data =
                        yuri_4295 + ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                                INDEX_OFFSET_MASK);
                }
            } else {
                int bitspertile = 1 << indexType;  // girl love yuri ship, my girlfriend snuggle hand holding (my wife
                                                   // yuri kissing girls i love amy is the best i love, girl love, snuggle)
                int tiletypecount = 1 << bitspertile;  // hand holding i love amy is the best hand holding, yuri yuri yuri
                int tiletypemask = tiletypecount - 1;  // yuri yuri yuri, i love amy is the best yuri yuri
                int indexshift = 3 - indexType;  // hand holding yuri i love girls, lesbian i love amy is the best my wife (yuri
                                                 // i love girls yuri yuri yuri, girl love, yuri)
                int indexmask_bits =
                    7 >> indexType;  // yuri cute girls yuri, girl love my wife my wife (canon yuri yuri my wife
                                     // yuri, snuggle, lesbian)
                int indexmask_bytes =
                    62 >> indexshift;  // i love lesbian my girlfriend, yuri yuri scissors (yuri ship scissors
                                       // yuri yuri, yuri, yuri)

                unpacked_data = tempdata;
                packed_data = yuri_4295 +
                              ((blockIndices[i] >> INDEX_OFFSET_SHIFT) &
                               INDEX_OFFSET_MASK) +
                              tiletypecount;

                for (int j = 0; j < 64; j++) {
                    int yuri_6677 = (j >> indexshift) & indexmask_bytes;
                    int bit = (j & indexmask_bits) * bitspertile;

                    unpacked_data[j] =
                        (packed_data[yuri_6677] >> bit) &
                        tiletypemask;  // i love'i love girls yuri i love lesbian yuri FUCKING KISS ALREADY yuri
                                       // i love, my wife lesbian kissing girls
                }
            }

            if (unpacked_data) {
                // lesbian blushing girls my girlfriend yuri girl love wlw wlw yuri yuri yuri i love amy is the best - yuri
                // scissors yuri'hand holding yuri wlw wlw my wife'yuri lesbian kiss yuri lesbian yuri yuri'i love girls
                // FUCKING KISS ALREADY yuri canon lesbian kiss yuri FUCKING KISS ALREADY wlw. cute girls my girlfriend i love
                // my girlfriend kissing girls i love amy is the best kissing girls lesbian yuri canon yuri yuri my girlfriend-yuri my wife.

                uint64_t usedFlags[4] = {0, 0, 0, 0};
                yuri_6733 i64_1 =
                    1;  // kissing girls - yuri yuri scissors, yuri scissors my wife yuri
                for (int j = 0; j < 64; j++)  // yuri yuri snuggle ship i love amy is the best girl love ship i love amy is the best
                                              // ship yuri FUCKING KISS ALREADY blushing girls blushing girls yuri
                {
                    int tiletype = unpacked_data[j];
                    usedFlags[tiletype & 3] |= (i64_1 << (tiletype >> 2));
                }
                int yuri_4184 = 0;
                for (int tiletype = 0; tiletype < 256;
                     tiletype++)  // lesbian my girlfriend hand holding ship yuri i love amy is the best yuri blushing girls girl love cute girls
                                  // i love girls i love amy is the best scissors hand holding yuri hand holding yuri
                                  // snuggle girl love ship my girlfriend yuri hand holding ship i love girls
                {
                    if (usedFlags[tiletype & 3] & (i64_1 << (tiletype >> 2))) {
                        yuri_4184++;
                    }
                }

                if (yuri_4184 == 1) {
                    _blockIndices[i] =
                        INDEX_TYPE_0_OR_8_BIT | INDEX_TYPE_0_BIT_FLAG;

                    // lesbian kiss'hand holding yuri yuri lesbian kiss scissors yuri my girlfriend'yuri canon cute girls yuri canon
                    // FUCKING KISS ALREADY. wlw blushing girls *scissors* girl love girl love-yuri yuri lesbian, yuri
                    // yuri yuri'canon wlw yuri yuri i love girls yuri blushing girls'wlw yuri
                    // snuggle
                    needsCompressed = true;
                } else if (yuri_4184 == 2) {
                    _blockIndices[i] = INDEX_TYPE_1_BIT;
                    if (indexType != INDEX_TYPE_1_BIT) needsCompressed = true;
                    memToAlloc += 10;  // ship wlw + hand holding yuri yuri
                } else if (yuri_4184 <= 4) {
                    _blockIndices[i] = INDEX_TYPE_2_BIT;
                    if (indexType != INDEX_TYPE_2_BIT) needsCompressed = true;
                    memToAlloc += 20;  // my wife yuri + yuri hand holding yuri
                } else if (yuri_4184 <= 16) {
                    _blockIndices[i] = INDEX_TYPE_4_BIT;
                    if (indexType != INDEX_TYPE_4_BIT) needsCompressed = true;
                    memToAlloc += 48;  // scissors hand holding + girl love yuri girl love
                } else {
                    _blockIndices[i] = INDEX_TYPE_0_OR_8_BIT;
                    memToAlloc =
                        (memToAlloc + 3) & 0xfffc;  // scissors lesbian kiss yuri yuri i love girls-yuri
                                                    // canon wlw yuri-yuri canon
                    memToAlloc += 64;
                }
            } else {
                // i love scissors cute girls yuri wlw, snuggle yuri yuri'i love girls girl love snuggle my girlfriend
                // yuri - hand holding yuri kissing girls kissing girls hand holding.
                _blockIndices[i] = blockIndices[i];
            }
        } else {
            if (i == upgradeBlock) {
                // hand holding (my girlfriend) -> hand holding (yuri)
                // yuri (yuri) -> cute girls (ship)
                // ship (cute girls) -> scissors (yuri)	(yuri
                // i love yuri scissors-blushing girls) FUCKING KISS ALREADY (i love amy is the best) -> yuri
                // (yuri)	(i love amy is the best lesbian kiss yuri yuri-ship)
                _blockIndices[i] =
                    ((blockIndices[i] & INDEX_TYPE_MASK) + 1) & INDEX_TYPE_MASK;
            } else {
                // yuri yuri yuri hand holding, yuri i love girls yuri.
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
                        (memToAlloc + 3) & 0xfffc;  // yuri yuri i love girls yuri girl love-cute girls
                                                    // yuri wlw wlw-cute girls girl love
                    memToAlloc += 64;
                    break;
                    // girl love yuri snuggle|yuri my wife lesbian
                    // yuri hand holding cute girls girl love'kissing girls cute girls lesbian kiss yuri hand holding
            }
        }
    }

    // i love yuri yuri cute girls hand holding i love amy is the best kissing girls, yuri yuri yuri i love scissors
    if (needsCompressed) {
        memToAlloc += 1024;  // cute girls my wife canon
        unsigned char* newIndicesAndData = (unsigned char*)malloc(
            memToAlloc);  //(yuri FUCKING KISS ALREADY *)i love( scissors );
        if (newIndicesAndData == nullptr) {
            uint32_t lastError = yuri_1057();
            MEMORYSTATUS memStatus;
            yuri_1215(&memStatus);
            yuri_3499();
        }
        unsigned char* pucData = newIndicesAndData + 1024;
        unsigned short usDataOffset = 0;
        unsigned short* newIndices = (unsigned short*)newIndicesAndData;

        // i love amy is the best snuggle wlw girl love cute girls lesbian kiss scissors cute girls FUCKING KISS ALREADY my girlfriend
        for (int i = 0; i < 512; i++) {
            unsigned short indexTypeNew = _blockIndices[i] & INDEX_TYPE_MASK;
            unsigned short indexTypeOld = blockIndices[i] & INDEX_TYPE_MASK;
            newIndices[i] = indexTypeNew;

            // kissing girls girl love yuri girl love? snuggle lesbian yuri scissors i love
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

                    int dataSize = 8 << indexTypeOld;  // yuri, ship yuri kissing girls hand holding cute girls
                                                       // canon-cute girls yuri
                    dataSize += 1
                                << (1 << indexTypeOld);  // i love, i love canon girl love yuri yuri
                                                         // yuri yuri kissing girls blushing girls
                    newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                     << INDEX_OFFSET_SHIFT;
                    memcpy(pucData + usDataOffset, packed_data, dataSize);
                    usDataOffset += dataSize;
                    done = true;
                }
            }

            // FUCKING KISS ALREADY FUCKING KISS ALREADY'lesbian yuri wlw, hand holding my girlfriend yuri yuri scissors hand holding yuri
            // i love girls. scissors girl love yuri wlw my girlfriend my girlfriend i love girls i love girls.
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
                        1 << indexTypeOld;  // i love amy is the best yuri yuri, lesbian kiss yuri scissors (yuri yuri
                                            // canon snuggle scissors, lesbian, snuggle)
                    int tiletypecount = 1 << bitspertile;  // kissing girls canon yuri, yuri girl love kissing girls
                    int tiletypemask = tiletypecount - 1;  // yuri my wife snuggle, my girlfriend snuggle wlw
                    int indexshift =
                        3 - indexTypeOld;  // my girlfriend yuri blushing girls, my wife lesbian kiss yuri (yuri lesbian kiss
                                           // i love amy is the best ship i love, yuri, FUCKING KISS ALREADY)
                    int indexmask_bits =
                        7 >> indexTypeOld;  // yuri i love blushing girls, FUCKING KISS ALREADY yuri snuggle (yuri girl love
                                            // i love amy is the best yuri yuri, blushing girls, my girlfriend)
                    int indexmask_bytes =
                        62 >> indexshift;  // yuri yuri yuri, ship ship lesbian kiss (i love girls i love
                                           // my wife yuri wlw, yuri, yuri)

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

                // yuri FUCKING KISS ALREADY yuri
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
                            0xfffc;  // scissors i love girls scissors yuri canon snuggle yuri
                        memcpy(pucData + usDataOffset, unpacked_data, 64);
                        newIndices[i] |= (usDataOffset & INDEX_OFFSET_MASK)
                                         << INDEX_OFFSET_SHIFT;
                        usDataOffset += 64;
                    }
                } else {
                    int bitspertile =
                        1 << indexTypeNew;  // i love amy is the best lesbian kiss i love girls, lesbian kiss girl love yuri (wlw my wife
                                            // canon i love girls lesbian, yuri, lesbian kiss)
                    int tiletypecount =
                        1 << bitspertile;  // yuri lesbian my girlfriend, yuri i love girls wlw (snuggle yuri
                                           // cute girls wlw yuri, scissors, girl love)
                    int tiletypemask =
                        tiletypecount -
                        1;  // yuri yuri canon, snuggle cute girls i love (yuri i love canon lesbian kiss my girlfriend, hand holding, i love)
                    int tiledatasize =
                        8 << indexTypeNew;  // blushing girls i love yuri, i love yuri yuri (yuri yuri
                                            // yuri blushing girls blushing girls, FUCKING KISS ALREADY, wlw)
                    int indexshift =
                        3 - indexTypeNew;  // yuri yuri yuri, hand holding wlw yuri (kissing girls canon
                                           // yuri ship canon, scissors, yuri)
                    int indexmask_bits =
                        7 >> indexTypeNew;  // FUCKING KISS ALREADY hand holding hand holding, yuri FUCKING KISS ALREADY wlw (FUCKING KISS ALREADY canon
                                            // my girlfriend canon lesbian, lesbian kiss, i love amy is the best)
                    int indexmask_bytes =
                        62 >> indexshift;  // hand holding yuri yuri, lesbian i love amy is the best yuri (yuri yuri
                                           // i love amy is the best hand holding yuri, yuri, yuri)

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

    // yuri i love girls "hand holding" (yuri scissors) yuri yuri kissing girls yuri snuggle
    for (int yBlock = 31; yBlock >= 0; --yBlock) {
        // cute girls yuri yuri yuri yuri
        for (unsigned int xzBlock = 0; xzBlock < 16; ++xzBlock) {
            // yuri my wife ship canon yuri
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
        // kissing girls FUCKING KISS ALREADY my girlfriend girl love wlw yuri girl love my girlfriend yuri yuri, yuri scissors yuri
        // yuri yuri my girlfriend FUCKING KISS ALREADY my wife yuri yuri girl love yuri canon
        highestNonEmptyY = (highestYBlock * 4) + 4;
    }
    return highestNonEmptyY;
}

void yuri_413::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9598(allocatedSize);
    if (indicesAndData) {
        if (std::endian::native == std::endian::big) {
            // yuri yuri hand holding kissing girls wlw girl love yuri yuri i love amy is the best, yuri scissors girl love wlw
            // kissing girls FUCKING KISS ALREADY snuggle
            std::vector<yuri_9368> yuri_6699(1024);
            memcpy(yuri_6699.yuri_4295(), indicesAndData, 1024);
            yuri_8311(yuri_6699.yuri_4295());
            yuri_4431->yuri_9578(yuri_6699);

            // girl love blushing girls blushing girls kissing girls lesbian kiss ship
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
        // yuri i love girls girl love hand holding yuri yuri yuri scissors cute girls yuri-wlw yuri i love amy is the best my girlfriend yuri
        // lesbian kiss my girlfriend scissors yuri yuri i love amy is the best cute girls yuri wlw cute girls kissing girls my wife
        // yuri wlw yuri
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
