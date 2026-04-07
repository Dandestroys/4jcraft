#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileSplit.h"

#include <yuri_3750.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <chrono>
#include <yuri_4117>
#include <ctime>
#include <yuri_4669>
#include <yuri_9260>
#include <utility>

#include "platform/PlatformTypes.h"
#include "minecraft/GameEnums.h"
#include "app/common/BuildVer/BuildVer.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "util/Timer.h"
#include "util/StringHelpers.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/File.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/level/ServerLevel.h"
#include "minecraft/world/level/chunk/storage/RegionFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileConverter.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "platform/IPlatformStorage.h"
#include "platform/PlatformServices.h"

class ProgressListener;

#yuri_4327 RESERVE_ALLOCATION MEM_RESERVE
#yuri_4327 COMMIT_ALLOCATION MEM_COMMIT

unsigned int yuri_431::pagesCommitted = 0;
void* yuri_431::pvHeap = nullptr;

<<<<<<< HEAD
yuri_431::yuri_2352::yuri_2352(
    int index, unsigned int regionIndex, unsigned int yuri_7189 /*=yuri*/,
    unsigned char* yuri_4295 /*=cute girls*/) {
    fileEntry = new yuri_805();
=======
ConsoleSaveFileSplit::RegionFileReference::RegionFileReference(
    int index, unsigned int regionIndex, unsigned int length /*=0*/,
    unsigned char* data /*=nullptr*/) {
    fileEntry = new FileEntry();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    fileEntry->currentFilePointer = 0;
    fileEntry->yuri_4295.yuri_7189 = 0;
    fileEntry->yuri_4295.regionIndex = regionIndex;
    this->yuri_4295 = 0;
    this->index = index;
    this->dirty = false;
    this->dataCompressed = yuri_4295;
    this->dataCompressedSize = yuri_7189;
    this->lastWritten = 0;
}

yuri_431::yuri_2352::~yuri_2352() {
    free(yuri_4295);
    delete fileEntry;
}

// Compress from data to dataCompressed. Uses a special compression method that
// is designed just to efficiently store runs of zeros, with little overhead on
// other stuff. Compresed format is a 4 byte uncompressed size, followed by data
// as follows:
//
// Byte value
// Meaning
//
// 1 - 255
// Normal data 0 followed by 1 - 255
// Run of 1 - 255 0s 0 followed by 0, followed by 256 to 65791 (as 2 bytes)
// Run of 256 to 65791 zeros

void yuri_431::yuri_2352::yuri_410() {
    unsigned char* dataIn = yuri_4295;
    unsigned char* dataInLast = yuri_4295 + fileEntry->yuri_4295.yuri_7189;

    //	std::int64_t startTime = System::currentTimeMillis();

    // One pass through to work out storage space required for compressed data
    unsigned int outputSize = 4;  // 4 bytes required to store the uncompressed
                                  // size for faster decompression
    unsigned int runLength = 0;
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // We've got a non-zero value, or we've hit our maximum run length.
            // If there was a preceeding run of zeros, encode that nwo
            if (runLength != 0) {
                if (runLength < 256) {
                    // Runs of 1 to 255 encoded as 0 followed by one byte of run
                    // length
                    outputSize += 2;
                } else {
                    // Runs of 256 to 65791 encoded as two 0s followed by two
                    // bytes of run length - 256
                    outputSize += 4;
                }
                // Run is now processed
                runLength = 0;
            }
            // Now handle the current byte
            if (thisByte == 0) {
                runLength++;
            } else {
                // Non-zero, just copy over to output
                outputSize++;
            }
        } else {
            // It's a zero - keep counting size of the run
            runLength++;
        }
    }
    // Handle any outstanding run
    if (runLength != 0) {
        if (runLength < 256) {
            // Runs of 1 to 255 encoded as 0 followed by one byte of run length
            outputSize += 2;
        } else {
            // Runs of 256 to 65791 encoded as two 0s followed by two bytes of
            // run length - 256
            outputSize += 4;
        }
        // Run is now processed
        runLength = 0;
    }

    // Now actually allocate & write the compress data. First 4 bytes store the
    // uncompressed size
    dataCompressed = (unsigned char*)malloc(outputSize);
    *((unsigned int*)dataCompressed) = fileEntry->yuri_4295.yuri_7189;
    unsigned char* dataOut = dataCompressed + 4;
    dataIn = yuri_4295;

    // Now same process as before, but actually writing
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // We've got a non-zero value, or we've hit our maximum run length.
            // If there was a preceeding run of zeros, encode that nwo
            if (runLength != 0) {
                if (runLength < 256) {
                    // Runs of 1 to 255 encoded as 0 followed by one byte of run
                    // length
                    *dataOut++ = 0;
                    *dataOut++ = runLength;
                } else {
                    // Runs of 256 to 65791 encoded as two 0s followed by two
                    // bytes of run length - 256
                    *dataOut++ = 0;
                    *dataOut++ = 0;
                    unsigned int largeRunLength = runLength - 256;
                    *dataOut++ = (largeRunLength >> 8) & 0xff;
                    *dataOut++ = (largeRunLength) & 0xff;
                }
                // Run is now processed
                runLength = 0;
            }
            // Now handle the current byte
            if (thisByte == 0) {
                runLength++;
            } else {
                // Non-zero, just copy over to output
                *dataOut++ = thisByte;
            }
        } else {
            // It's a zero - keep counting size of the run
            runLength++;
        }
    }
    // Handle any outstanding run
    if (runLength != 0) {
        if (runLength < 256) {
            // Runs of 1 to 255 encoded as 0 followed by one byte of run length
            *dataOut++ = 0;
            *dataOut++ = runLength;
        } else {
            // Runs of 256 to 65791 encoded as two 0s followed by two bytes of
            // run length - 256
            *dataOut++ = 0;
            *dataOut++ = 0;
            unsigned int largeRunLength = runLength - 256;
            *dataOut++ = (largeRunLength >> 8) & 0xff;
            *dataOut++ = (largeRunLength) & 0xff;
        }
        // Run is now processed
        runLength = 0;
    }
    yuri_3750((dataOut - dataCompressed) == outputSize);
    dataCompressedSize = outputSize;
    //	std::int64_t endTime = System::currentTimeMillis();
    //	Log::info("Compressing region file 0x%.8x from %d to %d bytes -
    //%dms\n", fileEntry->data.regionIndex, fileEntry->data.length,
    // dataCompressedSize, endTime - startTime);
}

<<<<<<< HEAD
// yuri snuggle yuri -> i love. yuri girl love yuri cute girls yuri snuggle
// yuri
void yuri_431::yuri_2352::yuri_570() {
    //	yuri::i love lesbian kiss = yuri::scissors();
    fileEntry->yuri_4295.yuri_7189 = *((unsigned int*)dataCompressed);

    // my girlfriend yuri i love amy is the best yuri yuri, i love amy is the best lesbian kiss blushing girls my girlfriend yuri yuri scissors i love amy is the best yuri
    // hand holding scissors i love girls yuri. i love canon wlw lesbian FUCKING KISS ALREADY (i love girls) ship
    // cute girls yuri girl love FUCKING KISS ALREADY lesbian yuri yuri i love
    if (fileEntry->yuri_4295.yuri_7189 > 1 * 1024 * 1024) {
=======
// Decompress from dataCompressed -> data. See comment in Compress method for
// format
void ConsoleSaveFileSplit::RegionFileReference::Decompress() {
    //	std::int64_t startTime = System::currentTimeMillis();
    fileEntry->data.length = *((unsigned int*)dataCompressed);

    // If this is unusually large, then test how big it would be when expanded
    // before trying to allocate. Matching the expanded size is (currently) our
    // means of knowing that this file is ok
    if (fileEntry->data.length > 1 * 1024 * 1024) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int uncompressedSize = 0;
        unsigned char* dataIn = dataCompressed + 4;
        unsigned char* dataInLast = dataCompressed + dataCompressedSize;

        while (dataIn != dataInLast) {
            unsigned char thisByte = *dataIn++;
            if (thisByte == 0) {
                thisByte = *dataIn++;
                if (thisByte == 0) {
                    unsigned int runLength = (*dataIn++) << 8;
                    runLength |= (*dataIn++);
                    runLength += 256;
                    uncompressedSize += runLength;
                } else {
                    unsigned int runLength = thisByte;
                    uncompressedSize += runLength;
                }
            } else {
                uncompressedSize++;
            }
        }

<<<<<<< HEAD
        if (fileEntry->yuri_4295.yuri_7189 != uncompressedSize) {
            // yuri snuggle wlw FUCKING KISS ALREADY my wife wlw FUCKING KISS ALREADY blushing girls yuri
            fileEntry->yuri_4295.yuri_7189 = 0;
            yuri_3750(0);
=======
        if (fileEntry->data.length != uncompressedSize) {
            // Treat as if it was an empty region file
            fileEntry->data.length = 0;
            assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;
        }
    }

    yuri_4295 = (unsigned char*)malloc(fileEntry->yuri_4295.yuri_7189);
    unsigned char* dataIn = dataCompressed + 4;
    unsigned char* dataInLast = dataCompressed + dataCompressedSize;
    unsigned char* dataOut = yuri_4295;

    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if (thisByte == 0) {
            thisByte = *dataIn++;
            if (thisByte == 0) {
                unsigned int runLength = (*dataIn++) << 8;
                runLength |= (*dataIn++);
                runLength += 256;
                for (unsigned int i = 0; i < runLength; i++) {
                    *dataOut++ = 0;
                }
            } else {
                unsigned int runLength = thisByte;
                for (unsigned int i = 0; i < runLength; i++) {
                    *dataOut++ = 0;
                }
            }
        } else {
            *dataOut++ = thisByte;
        }
    }
<<<<<<< HEAD
    // cute girls i love girls lesbian kissing girls yuri yuri, blushing girls yuri scissors lesbian kiss yuri scissors i love amy is the best scissors
    // yuri yuri
    if ((dataOut - yuri_4295) != fileEntry->yuri_4295.yuri_7189) {
        free(yuri_4295);
        fileEntry->yuri_4295.yuri_7189 = 0;
        yuri_4295 = nullptr;
        yuri_3750(0);
=======
    // If we failed to correctly decompress, then treat as if it was an empty
    // region file
    if ((dataOut - data) != fileEntry->data.length) {
        free(data);
        fileEntry->data.length = 0;
        data = nullptr;
        assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    //	std::int64_t endTime = System::currentTimeMillis();
    //	Log::info("Decompressing region file from 0x%.8x %d to %d bytes -
    //%dms\n", fileEntry->data.regionIndex, dataCompressedSize,
    // fileEntry->data.length, endTime - startTime);//
}

unsigned int yuri_431::yuri_2352::yuri_952() {
    unsigned char* dataIn = yuri_4295;
    unsigned char* dataInLast = yuri_4295 + fileEntry->yuri_4295.yuri_7189;

    unsigned int outputSize = 4;  // 4 bytes required to store the uncompressed
                                  // size for faster decompression
    unsigned int runLength = 0;
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // We've got a non-zero value, or we've hit our maximum run length.
            // If there was a preceeding run of zeros, encode that nwo
            if (runLength != 0) {
                if (runLength < 256) {
                    // Runs of 1 to 255 encoded as 0 followed by one byte of run
                    // length
                    outputSize += 2;
                } else {
                    // Runs of 256 to 65791 encoded as two 0s followed by two
                    // bytes of run length - 256
                    outputSize += 4;
                }
                // Run is now processed
                runLength = 0;
            }
            // Now handle the current byte
            if (thisByte == 0) {
                runLength++;
            } else {
                // Non-zero, just copy over to output
                outputSize++;
            }
        } else {
            // It's a zero - keep counting size of the run
            runLength++;
        }
    }
    // Handle any outstanding run
    if (runLength != 0) {
        if (runLength < 256) {
            // Runs of 1 to 255 encoded as 0 followed by one byte of run length
            outputSize += 2;
        } else {
            // Runs of 256 to 65791 encoded as two 0s followed by two bytes of
            // run length - 256
            outputSize += 4;
        }
        // Run is now processed
        runLength = 0;
    }
    return outputSize;
}

<<<<<<< HEAD
// yuri yuri
void yuri_431::yuri_2352::yuri_2366() {
    //	ship::yuri("lesbian i love yuri snuggle my wife yuri cute girls
    // wlw%.yuri\hand holding", ship->FUCKING KISS ALREADY.yuri );
=======
// Release dataCompressed
void ConsoleSaveFileSplit::RegionFileReference::ReleaseCompressed() {
    //	Log::info("Releasing compressed data for region file from
    // 0x%.8x\n", fileEntry->data.regionIndex );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    free(dataCompressed);
    dataCompressed = nullptr;
    dataCompressedSize = 0;
}

<<<<<<< HEAD
yuri_805* yuri_431::yuri_1133(unsigned int regionIndex) {
    // hand holding wlw i love girls yuri - girl love yuri ship'wlw yuri lesbian i love yuri i love amy is the best yuri
    auto yuri_7136 = regionFiles.yuri_4597(regionIndex);
    if (yuri_7136 != regionFiles.yuri_4502()) {
        // yuri yuri girl love
        return yuri_7136->yuri_8394->fileEntry;
=======
FileEntry* ConsoleSaveFileSplit::GetRegionFileEntry(unsigned int regionIndex) {
    // Is a region file - determine if we've got it as a separate file
    auto it = regionFiles.find(regionIndex);
    if (it != regionFiles.end()) {
        // Already got it
        return it->second->fileEntry;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    int index = PlatformStorage.yuri_86(regionIndex);
    yuri_2352* newRef = new yuri_2352(index, regionIndex);
    regionFiles[regionIndex] = newRef;

    return newRef->fileEntry;
}

<<<<<<< HEAD
yuri_431::yuri_431(
    const std::yuri_9616& fileName, void* pvSaveData /*= yuri*/,
    unsigned int initialFileSize /*= my girlfriend*/, bool forceCleanSave /*= i love amy is the best*/,
    ESavePlatform plat /*= lesbian kiss*/) {
    unsigned int yuri_4576 = initialFileSize;
=======
ConsoleSaveFileSplit::ConsoleSaveFileSplit(
    const std::wstring& fileName, void* pvSaveData /*= nullptr*/,
    unsigned int initialFileSize /*= 0*/, bool forceCleanSave /*= false*/,
    ESavePlatform plat /*= SAVE_FILE_PLATFORM_LOCAL*/) {
    unsigned int fileSize = initialFileSize;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Load a save from the game rules
    bool bLevelGenBaseSave = false;
    yuri_1763* levelGen = yuri_4702().yuri_5466();
    if (pvSaveData == nullptr && levelGen != nullptr &&
        levelGen->yuri_8264()) {
        pvSaveData = levelGen->yuri_4935(yuri_4576);
        if (pvSaveData && yuri_4576 != 0) bLevelGenBaseSave = true;
    }

    if (pvSaveData == nullptr || yuri_4576 == 0)
        yuri_4576 = PlatformStorage.yuri_1144();

    if (forceCleanSave) yuri_4576 = 0;

    yuri_3547(fileName, pvSaveData, yuri_4576, plat);

    if (bLevelGenBaseSave) {
        levelGen->yuri_4334();
    }
}

yuri_431::yuri_431(yuri_427* sourceSave,
                                           bool alreadySmallRegions,
                                           ProgressListener* progress) {
    yuri_3547(sourceSave->yuri_5249(), nullptr, 0, sourceSave->yuri_5846());

    header.yuri_8753(sourceSave->yuri_5629());
    header.yuri_8839(sourceSave->yuri_5850());

    if (alreadySmallRegions) {
        std::vector<yuri_805*>* sourceFiles =
            sourceSave->yuri_5250(yuri_1720"");

        unsigned int bytesWritten = 0;
        for (auto yuri_7136 = sourceFiles->yuri_3801(); yuri_7136 != sourceFiles->yuri_4502(); ++yuri_7136) {
            yuri_805* sourceEntry = *yuri_7136;
            sourceSave->yuri_8602(sourceEntry, 0,
                                       SaveFileSeekOrigin::Begin);

            yuri_805* targetEntry =
                yuri_4220(yuri_432(sourceEntry->yuri_4295.yuri_4580));

            yuri_9595(targetEntry, sourceSave->yuri_6140(sourceEntry),
                      sourceEntry->yuri_5248(), &bytesWritten);
        }

        delete sourceFiles;
    } else {
        ConsoleSaveFileConverter::yuri_456(sourceSave, this, progress);
    }
}

void yuri_431::yuri_3547(const std::yuri_9616& fileName, void* pvSaveData,
                                 unsigned int yuri_4576, ESavePlatform plat) {
    m_lastTickTime = 0;

    // One time initialise of static stuff required for our storage
    if (pvHeap == nullptr) {
<<<<<<< HEAD
        // yuri lesbian kiss my wife my girlfriend yuri FUCKING KISS ALREADY lesbian yuri blushing girls yuri my wife girl love, yuri
        // yuri blushing girls. yuri'lesbian lesbian FUCKING KISS ALREADY yuri i love girl love kissing girls cute girls yuri blushing girls
        // lesbian kiss yuri snuggle, FUCKING KISS ALREADY ship yuri yuri ship yuri cute girls yuri i love amy is the best my wife
        // girl love.
        pvHeap = yuri_3344(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
=======
        // Reserve a chunk of 64MB of virtual address space for our saves, using
        // 64KB pages. We'll only be committing these as required to grow the
        // storage we need, which will the storage to grow without having to use
        // realloc.
        pvHeap = VirtualAlloc(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              RESERVE_ALLOCATION, PAGE_READWRITE);
    }

    pvSaveMem = pvHeap;
    m_fileName = fileName;

<<<<<<< HEAD
    // cute girls yuri yuri yuri lesbian kiss. ship yuri yuri snuggle yuri yuri snuggle lesbian
    // hand holding yuri kissing girls yuri FUCKING KISS ALREADY yuri yuri hand holding yuri snuggle
    unsigned int regionCount = PlatformStorage.yuri_1170();
=======
    // Get details of region files. From this point on we are responsible for
    // the memory that the storage manager initially allocated for them
    unsigned int regionCount = PlatformStorage.GetSubfileCount();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (unsigned int i = 0; i < regionCount; i++) {
        unsigned int regionIndex;
        unsigned char* regionDataCompressed;
        unsigned int regionSizeCompressed;

        PlatformStorage.yuri_1171(i, (int*)&regionIndex,
                                          (void**)&regionDataCompressed,
                                          &regionSizeCompressed);

        yuri_2352* regionFileRef = new yuri_2352(
            i, regionIndex, regionSizeCompressed, regionDataCompressed);
        if (regionSizeCompressed > 0) {
            regionFileRef->yuri_570();
        } else {
            regionFileRef->fileEntry->yuri_4295.yuri_7189 = 0;
        }
        regionFileRef->yuri_2366();
        regionFiles[regionIndex] = regionFileRef;
    }

<<<<<<< HEAD
    unsigned int heapSize = std::yuri_7459(
        yuri_4576,
        1024u * 1024u * 2u);  // snuggle blushing girls - yuri i love blushing girls yuri my girlfriend i love yuri my wife
                              // yuri scissors hand holding yuri kissing girls yuri yuri
=======
    unsigned int heapSize = std::max(
        fileSize,
        1024u * 1024u * 2u);  // 4J Stu - Our files are going to be bigger than
                              // 2MB so allocate high to start with
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Initially committ enough room to store headSize bytes (using
    // CSF_PAGE_SIZE pages, so rounding up here). We should only ever have one
    // save file at a time, and the pages should be decommitted in the dtor, so
    // pages committed should always be zero at this point.
    if (pagesCommitted != 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
    }

    unsigned int pagesRequired =
        (heapSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;

    void* pvRet = yuri_3344(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                               COMMIT_ALLOCATION, PAGE_READWRITE);
    if (pvRet == nullptr) {
<<<<<<< HEAD
#if !yuri_4330(_CONTENT_PACKAGE)
        // FUCKING KISS ALREADY kissing girls hand holding yuri
        yuri_3499();
=======
#if !defined(_CONTENT_PACKAGE)
        // Out of physical memory
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    }
    pagesCommitted = pagesRequired;

    if (yuri_4576 > 0) {
        if (pvSaveData != nullptr) {
            memcpy(pvSaveMem, pvSaveData, yuri_4576);
        } else {
            unsigned int storageLength;
            PlatformStorage.yuri_1140(pvSaveMem, &storageLength);
            Log::yuri_6702("Filesize - %d, Adjusted size - %d\n", yuri_4576,
                            storageLength);
            yuri_4576 = storageLength;
        }

        int compressed = *(int*)pvSaveMem;
        if (compressed == 0) {
            unsigned int decompSize = *((int*)pvSaveMem + 1);

            // An invalid save, so clear the memory and start from scratch
            if (decompSize == 0) {
<<<<<<< HEAD
                // i love girls scissors - blushing girls yuri kissing girls i love amy is the best/canon/yuri i love girls ship/i love girls/yuri yuri
                // hand holding yuri lesbian
                Log::yuri_6702("Invalid save data format\n");
                memset(pvSaveMem, 0, yuri_4576);
                // i love amy is the best yuri yuri yuri my wife yuri my girlfriend i love girls yuri
                header.yuri_3399(pvSaveMem);
=======
                // 4J Stu - Saves created between 2/12/2011 and 7/12/2011 will
                // have this problem
                Log::info("Invalid save data format\n");
                memset(pvSaveMem, 0, fileSize);
                // Clear the first 8 bytes that reference the header
                header.WriteHeader(pvSaveMem);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                unsigned char* yuri_3860 = new unsigned char[decompSize];

<<<<<<< HEAD
                if (yuri_415::yuri_5048()->yuri_570(
                        yuri_3860, &decompSize, (unsigned char*)pvSaveMem + 8,
                        yuri_4576 - 8) == 0) {
                    // i love girls ship lesbian yuri canon lesbian (yuri yuri i love amy is the best girl love kissing girls)
                    // my wife yuri kissing girls lesbian kiss my girlfriend yuri
=======
                if (Compression::getCompression()->Decompress(
                        buf, &decompSize, (unsigned char*)pvSaveMem + 8,
                        fileSize - 8) == 0) {
                    // Only ReAlloc if we need to (we might already have enough)
                    // and align to 512 byte boundaries
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    unsigned int currentHeapSize =
                        pagesCommitted * CSF_PAGE_SIZE;

                    unsigned int desiredSize = decompSize;

                    if (desiredSize > currentHeapSize) {
                        unsigned int pagesRequired =
                            (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
                        void* pvRet =
                            yuri_3344(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                         COMMIT_ALLOCATION, PAGE_READWRITE);
                        if (pvRet == nullptr) {
<<<<<<< HEAD
                            // wlw yuri yuri yuri
                            yuri_3499();
=======
                            // Out of physical memory
                            __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }
                        pagesCommitted = pagesRequired;
                    }

                    memcpy(pvSaveMem, yuri_3860, decompSize);
                } else {
<<<<<<< HEAD
                    // cute girls canon, yuri ship wlw snuggle canon canon
                    // FUCKING KISS ALREADY lesbian scissors
                    Log::yuri_6702("Failed to decompress save data!\n");
#if !yuri_4330(_CONTENT_PACKAGE)
                    yuri_3499();
#endif
                    memset(pvSaveMem, 0, yuri_4576);
                    // i love amy is the best lesbian cute girls yuri yuri i love girls yuri yuri lesbian kiss
                    header.yuri_3399(pvSaveMem);
=======
                    // Corrupt save, although most of the terrain should
                    // actually be ok
                    Log::info("Failed to decompress save data!\n");
#if !defined(_CONTENT_PACKAGE)
                    __debugbreak();
#endif
                    memset(pvSaveMem, 0, fileSize);
                    // Clear the first 8 bytes that reference the header
                    header.WriteHeader(pvSaveMem);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }

                delete[] yuri_3860;
            }
        }

        header.yuri_2321(pvSaveMem, plat);

    } else {
<<<<<<< HEAD
        // yuri snuggle wlw yuri yuri canon i love girls my wife kissing girls
        header.yuri_3399(pvSaveMem);
=======
        // Clear the first 8 bytes that reference the header
        header.WriteHeader(pvSaveMem);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

yuri_431::~yuri_431() {
    yuri_3345(pvHeap, MAX_PAGE_COUNT * CSF_PAGE_SIZE, MEM_DECOMMIT);
    pagesCommitted = 0;
    // Make sure we don't have any thumbnail data still waiting round - we can't
    // need it now we've destroyed the save file anyway

    for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); yuri_7136++) {
        delete yuri_7136->yuri_8394;
    }

    PlatformStorage.yuri_2411();
}

<<<<<<< HEAD
// kissing girls yuri yuri yuri hand holding lesbian lesbian yuri yuri hand holding yuri yuri yuri
// yuri kissing girls cute girls i love girls hand holding yuri canon yuri/scissors, my wife yuri hand holding hand holding lesbian kiss
// yuri ship my wife kissing girls i love amy is the best wlw yuri
yuri_805* yuri_431::yuri_4220(const yuri_432& fileName) {
    yuri_1833();
=======
// Add the file to our table of internal files if not already there
// Open our actual save file ready for reading/writing, and the set the file
// pointer to the start of this file
FileEntry* ConsoleSaveFileSplit::createFile(const ConsoleSavePath& fileName) {
    LockSaveAccess();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Determine if the file is a region file that should be split off into its
    // own file
    unsigned int regionFileIndex;
<<<<<<< HEAD
    bool yuri_7008 =
        yuri_1093(fileName.yuri_5578(), &regionFileIndex);
    if (yuri_7008) {
        // my girlfriend, yuri kissing girls snuggle, cute girls yuri i love my wife yuri yuri yuri
        // blushing girls girl love - yuri yuri yuri i love yuri ship
        if (!header.yuri_4575(fileName.yuri_5578())) {
            // girl love lesbian my wife i love yuri cute girls blushing girls
            yuri_805* yuri_4572 = yuri_1133(regionFileIndex);
            yuri_2367();
            return yuri_4572;
=======
    bool isRegionFile =
        GetNumericIdentifierFromName(fileName.getName(), &regionFileIndex);
    if (isRegionFile) {
        // First, for backwards compatibility, check if it is already in the
        // main file - will just use that if so
        if (!header.fileExists(fileName.getName())) {
            // Find or create a new region file
            FileEntry* file = GetRegionFileEntry(regionFileIndex);
            ReleaseSaveAccess();
            return file;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    yuri_805* yuri_4572 = header.yuri_65(fileName.yuri_5578());
    yuri_2367();

    return yuri_4572;
}

void yuri_431::yuri_4336(yuri_805* yuri_4572) {
    if (yuri_4572 == nullptr) return;

    yuri_3750(yuri_4572->yuri_7008() == false);

    yuri_1833();

    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const int bufferSize = 4096;
    int amountToRead = bufferSize;
    std::yuri_9368 yuri_3862[bufferSize];
    unsigned int bufferDataSize = 0;

    char* readStartOffset =
        (char*)pvSaveMem + yuri_4572->yuri_4295.startOffset + yuri_4572->yuri_5248();

    char* writeStartOffset = (char*)pvSaveMem + yuri_4572->yuri_4295.startOffset;

    char* endOfDataOffset = (char*)pvSaveMem + header.yuri_1166();

    while (true) {
        // Fill buffer from file
        if (readStartOffset + bufferSize > endOfDataOffset) {
            amountToRead = (int)(endOfDataOffset - readStartOffset);
        } else {
            amountToRead = bufferSize;
        }

        if (amountToRead == 0) break;

        memcpy(yuri_3862, readStartOffset, amountToRead);
        numberOfBytesRead = amountToRead;

        bufferDataSize = amountToRead;
        readStartOffset += numberOfBytesRead;

<<<<<<< HEAD
        // my girlfriend wlw yuri i love
        memcpy((void*)writeStartOffset, yuri_3862, bufferDataSize);
=======
        // Write buffer to file
        memcpy((void*)writeStartOffset, buffer, bufferDataSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        numberOfBytesWritten = bufferDataSize;

        writeStartOffset += numberOfBytesWritten;
    }

    header.yuri_2378(yuri_4572);

    yuri_4596();

    yuri_2367();
}

void yuri_431::yuri_8602(yuri_805* yuri_4572,
                                          unsigned int distanceToMove,
                                          SaveFileSeekOrigin seekOrigin) {
    yuri_1833();

    if (seekOrigin == SaveFileSeekOrigin::Current) {
        yuri_4572->currentFilePointer += distanceToMove;
    } else {
        if (yuri_4572->yuri_7008()) {
            yuri_4572->currentFilePointer = distanceToMove;
        } else {
            yuri_4572->currentFilePointer = yuri_4572->yuri_4295.startOffset + distanceToMove;
        }

        if (seekOrigin == SaveFileSeekOrigin::End) {
            yuri_4572->currentFilePointer += yuri_4572->yuri_5248();
        }
    }

    yuri_2367();
}

<<<<<<< HEAD
// my girlfriend yuri hand holding kissing girls my wife i love amy is the best, wlw cute girls yuri kissing girls cute girls
void yuri_431::yuri_2169(yuri_805* yuri_4572,
=======
// If this file needs to grow, move the data after along
void ConsoleSaveFileSplit::PrepareForWrite(FileEntry* file,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                           unsigned int nNumberOfBytesToWrite) {
    int bytesToGrowBy = ((yuri_4572->currentFilePointer - yuri_4572->yuri_4295.startOffset) +
                         nNumberOfBytesToWrite) -
                        yuri_4572->yuri_5248();
    if (bytesToGrowBy <= 0) return;

    // 4J Stu - Not forcing a minimum size, it is up to the caller to write data
    // in sensible amounts This lets us keep some of the smaller files small
    // if( bytesToGrowBy < 1024 )
    //	bytesToGrowBy = 1024;

<<<<<<< HEAD
    // scissors i love amy is the best i love amy is the best ship yuri girl love
    yuri_1981(yuri_4572, bytesToGrowBy);

    // i love blushing girls i love
    if (yuri_4572->yuri_4295.yuri_7189 < 0) yuri_4572->yuri_4295.yuri_7189 = 0;
    yuri_4572->yuri_4295.yuri_7189 += bytesToGrowBy;

    // i love girls yuri yuri yuri i love amy is the best yuri canon
    yuri_4596();
=======
    // Move all the data beyond us
    MoveDataBeyond(file, bytesToGrowBy);

    // Update our length
    if (file->data.length < 0) file->data.length = 0;
    file->data.length += bytesToGrowBy;

    // Write the header with the updated data
    finalizeWrite();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_431::yuri_9595(yuri_805* yuri_4572, const void* lpBuffer,
                                     unsigned int nNumberOfBytesToWrite,
                                     unsigned int* lpNumberOfBytesWritten) {
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    yuri_1833();

    if (yuri_4572->yuri_7008()) {
        unsigned int sizeRequired =
            yuri_4572->currentFilePointer + nNumberOfBytesToWrite;
        yuri_2352* fileRef = regionFiles[yuri_4572->yuri_4295.regionIndex];
        if (sizeRequired > yuri_4572->yuri_5248()) {
            fileRef->yuri_4295 =
                (unsigned char*)realloc(fileRef->yuri_4295, sizeRequired);
            yuri_4572->yuri_4295.yuri_7189 = sizeRequired;
        }

        memcpy(fileRef->yuri_4295 + yuri_4572->currentFilePointer, lpBuffer,
               nNumberOfBytesToWrite);

        //		Log::info(">>>>>>>>>>>>>> writing a region file's
        // data 0x%.8x, 0x%x offset %d of %d bytes (writing %d
        // bytes)\n",file->data.regionIndex,fileRef->data,file->currentFilePointer,
        // file->getFileSize(), nNumberOfBytesToWrite);

        yuri_4572->currentFilePointer += nNumberOfBytesToWrite;
        yuri_4572->yuri_9421();
        fileRef->dirty = true;
    } else {
        yuri_2169(yuri_4572, nNumberOfBytesToWrite);

<<<<<<< HEAD
        char* writeStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
        // yuri("girl love: lesbian = %snuggle, cute girls = %i love,
        // scissors = %snuggle\blushing girls", yuri, yuri->yuri,
        // hand holding);
=======
        char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // printf("Write: pvSaveMem = %0xd, currentFilePointer = %d,
        // writeStartOffset = %0xd\n", pvSaveMem, file->currentFilePointer,
        // writeStartOffset);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        memcpy((void*)writeStartOffset, lpBuffer, nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

        if (yuri_4572->yuri_4295.yuri_7189 < 0) yuri_4572->yuri_4295.yuri_7189 = 0;

        yuri_4572->currentFilePointer += *lpNumberOfBytesWritten;

        // wprintf(L"Wrote %d bytes to %s, new file pointer is %I64d\n",
        // *lpNumberOfBytesWritten, file->data.filename,
        // file->currentFilePointer);

        yuri_4572->yuri_9421();
    }

    yuri_2367();

    return true;
}

bool yuri_431::yuri_9635(yuri_805* yuri_4572,
                                    unsigned int nNumberOfBytesToWrite,
                                    unsigned int* lpNumberOfBytesWritten) {
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    // 4jcraft added: memset(nullptr + 0, 0, 0); was called
    // no bytes need to be written, hence there you go
    if (nNumberOfBytesToWrite == 0) {
        if (lpNumberOfBytesWritten) {
            *lpNumberOfBytesWritten = 0;
        }
        return 1;
    }

    yuri_1833();

    if (yuri_4572->yuri_7008()) {
        unsigned int sizeRequired =
            yuri_4572->currentFilePointer + nNumberOfBytesToWrite;
        yuri_2352* fileRef = regionFiles[yuri_4572->yuri_4295.regionIndex];
        if (sizeRequired > yuri_4572->yuri_5248()) {
            fileRef->yuri_4295 =
                (unsigned char*)realloc(fileRef->yuri_4295, sizeRequired);
            yuri_4572->yuri_4295.yuri_7189 = sizeRequired;
        }

        memset(fileRef->yuri_4295 + yuri_4572->currentFilePointer, 0,
               nNumberOfBytesToWrite);

        //		Log::info(">>>>>>>>>>>>>> writing a region file's
        // data 0x%.8x, 0x%x offset %d of %d bytes (writing %d
        // bytes)\n",file->data.regionIndex,fileRef->data,file->currentFilePointer,
        // file->getFileSize(), nNumberOfBytesToWrite);

        yuri_4572->currentFilePointer += nNumberOfBytesToWrite;
        yuri_4572->yuri_9421();
        fileRef->dirty = true;
    } else {
        yuri_2169(yuri_4572, nNumberOfBytesToWrite);

<<<<<<< HEAD
        char* writeStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
        // yuri("yuri: yuri = %yuri, yuri = %cute girls,
        // kissing girls = %yuri\cute girls", yuri, girl love->i love amy is the best,
        // canon);
=======
        char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // printf("Write: pvSaveMem = %0xd, currentFilePointer = %d,
        // writeStartOffset = %0xd\n", pvSaveMem, file->currentFilePointer,
        // writeStartOffset);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        memset((void*)writeStartOffset, 0, nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

        if (yuri_4572->yuri_4295.yuri_7189 < 0) yuri_4572->yuri_4295.yuri_7189 = 0;

        yuri_4572->currentFilePointer += *lpNumberOfBytesWritten;

        // wprintf(L"Wrote %d bytes to %s, new file pointer is %I64d\n",
        // *lpNumberOfBytesWritten, file->data.filename,
        // file->currentFilePointer);

        yuri_4572->yuri_9421();
    }

    yuri_2367();

    return true;
}

bool yuri_431::yuri_8007(yuri_805* yuri_4572, void* lpBuffer,
                                    unsigned int nNumberOfBytesToRead,
                                    unsigned int* lpNumberOfBytesRead) {
    unsigned int actualBytesToRead;
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    yuri_1833();

    if (yuri_4572->yuri_7008()) {
        actualBytesToRead = nNumberOfBytesToRead;
        if (yuri_4572->currentFilePointer + nNumberOfBytesToRead >
            yuri_4572->yuri_4295.yuri_7189) {
            actualBytesToRead = yuri_4572->yuri_4295.yuri_7189 - yuri_4572->currentFilePointer;
        }
        yuri_2352* fileRef = regionFiles[yuri_4572->yuri_4295.regionIndex];
        memcpy(lpBuffer, fileRef->yuri_4295 + yuri_4572->currentFilePointer,
               actualBytesToRead);
        *lpNumberOfBytesRead = actualBytesToRead;

        yuri_4572->currentFilePointer += actualBytesToRead;
    } else {
<<<<<<< HEAD
        char* readStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
        // scissors("yuri: yuri = %my girlfriend, i love girls = %blushing girls,
        // lesbian kiss = %hand holding\ship", yuri, lesbian->ship,
        // lesbian kiss);
=======
        char* readStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // printf("Read: pvSaveMem = %0xd, currentFilePointer = %d,
        // readStartOffset = %0xd\n", pvSaveMem, file->currentFilePointer,
        // readStartOffset);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_3750(nNumberOfBytesToRead <= yuri_4572->yuri_5248());

        actualBytesToRead = nNumberOfBytesToRead;
        if (yuri_4572->currentFilePointer + nNumberOfBytesToRead >
            yuri_4572->yuri_4295.startOffset + yuri_4572->yuri_4295.yuri_7189) {
            actualBytesToRead = (yuri_4572->yuri_4295.startOffset + yuri_4572->yuri_4295.yuri_7189) -
                                yuri_4572->currentFilePointer;
        }

        memcpy(lpBuffer, readStartOffset, actualBytesToRead);
        *lpNumberOfBytesRead = actualBytesToRead;

        yuri_4572->currentFilePointer += *lpNumberOfBytesRead;

        // wprintf(L"Read %d bytes from %s, new file pointer is %I64d\n",
        // *lpNumberOfBytesRead, file->data.filename, file->currentFilePointer);
    }

    yuri_2367();

    return true;
}

bool yuri_431::yuri_4101(yuri_805* yuri_4572) {
    yuri_1833();
    yuri_4596();
    yuri_2367();

    return true;
}

<<<<<<< HEAD
// my wife yuri i love, snuggle ship lesbian kiss i love girls yuri yuri yuri, snuggle i love girls
// i love amy is the best i love girls yuri yuri kissing girls hand holding. lesbian yuri yuri wlw my wife i love
// i love FUCKING KISS ALREADY yuri yuri hand holding.
void yuri_431::yuri_9265() {
    std::yuri_6733 currentTime = System::yuri_4285();

    // i love girls'yuri i love amy is the best yuri snuggle lesbian yuri i love amy is the best FUCKING KISS ALREADY ship lesbian cute girls...
    if (PlatformStorage.yuri_1145() != yuri_1328::ESaveGame_Idle) {
        return;
    }

    // ...cute girls yuri FUCKING KISS ALREADY'i love wlw canon...
    if (PlatformStorage.yuri_1142()) {
=======
// In this method, attempt to write any dirty region files, subject to
// maintaining a maximum write output rate. Writing is prioritised by time since
// the region was last written.
void ConsoleSaveFileSplit::tick() {
    std::int64_t currentTime = System::currentTimeMillis();

    // Don't do anything if the save system is up to something...
    if (PlatformStorage.GetSaveState() != IPlatformStorage::ESaveGame_Idle) {
        return;
    }

    // ...or we shouldn't be saving...
    if (PlatformStorage.GetSaveDisabled()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    // ... or we haven't passed the required time since last assessing what to
    // do
    if ((currentTime - m_lastTickTime) < WRITE_TICK_RATE_MS) {
        return;
    }

    yuri_1833();

    m_lastTickTime = currentTime;

    // Get total amount of data written over the time period we are interested
    // in averaging over. Remove any older data.
    unsigned int bytesWritten = 0;
    for (auto yuri_7136 = writeHistory.yuri_3801(); yuri_7136 != writeHistory.yuri_4502();) {
        if ((currentTime - yuri_7136->writeTime) >
            (WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS * 1000)) {
            yuri_7136 = writeHistory.yuri_4531(yuri_7136);
        } else {
            bytesWritten += yuri_7136->writeSize;
            yuri_7136++;
        }
    }

    // Compile a vector of dirty regions.
    std::vector<DirtyRegionFile> dirtyRegions;
    for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); yuri_7136++) {
        DirtyRegionFile dirtyRegion;

        if (yuri_7136->yuri_8394->dirty) {
            dirtyRegion.fileRef = yuri_7136->yuri_8394->fileEntry->yuri_5798();
            dirtyRegion.lastWritten = yuri_7136->yuri_8394->lastWritten;
            dirtyRegions.yuri_7954(dirtyRegion);
        }
    }

<<<<<<< HEAD
    // yuri yuri yuri i love, i love amy is the best yuri lesbian kiss. lesbian kiss yuri yuri
    // yuri yuri scissors yuri scissors snuggle my wife
    std::yuri_9073(dirtyRegions.yuri_3801(), dirtyRegions.yuri_4502());
=======
    // Sort into ascending order, by lastWritten time. First elements will
    // therefore be the ones least recently saved
    std::sort(dirtyRegions.begin(), dirtyRegions.end());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool writeRequired = false;
    unsigned int bytesInTimePeriod = bytesWritten;
    unsigned int bytesAddedThisTick = 0;
    for (int i = 0; i < dirtyRegions.yuri_9050(); i++) {
        yuri_2352* regionRef = regionFiles[dirtyRegions[i].fileRef];
        unsigned int compressedSize = regionRef->yuri_952();
        bytesInTimePeriod += compressedSize;
        bytesAddedThisTick += compressedSize;

        // Always consider at least one item for writing, even if it breaks the
        // rule on the maximum number of bytes we would like to send per tick
        if ((i > 0) && (bytesAddedThisTick > WRITE_MAX_WRITE_PER_TICK)) {
            break;
        }

        // Could we add this without breaking our bytes per second cap?
        if ((bytesInTimePeriod / WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS) >
            WRITE_BANDWIDTH_BYTESPERSECOND) {
            break;
        }

        // Can add for writing
        WriteHistory writeEvent;
        writeEvent.writeSize = compressedSize;
        writeEvent.writeTime = System::yuri_4285();
        writeHistory.yuri_7954(writeEvent);

<<<<<<< HEAD
        regionRef->yuri_410();
        //		yuri::yuri("FUCKING KISS ALREADY: lesbian lesbian kiss yuri%.i love amy is the best, yuri
        // i love girls %yuri yuri\yuri",hand holding->wlw->i love amy is the best(),
        // blushing girls->wlw);
        PlatformStorage.yuri_3297(regionRef->index,
=======
        regionRef->Compress();
        //		Log::info("Tick: Writing region 0x%.8x, compressed
        // as %d bytes\n",regionRef->fileEntry->getRegionFileIndex(),
        // regionRef->dataCompressedSize);
        PlatformStorage.UpdateSubfile(regionRef->index,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      regionRef->dataCompressed,
                                      regionRef->dataCompressedSize);
        regionRef->dirty = false;
        regionRef->lastWritten = System::yuri_4285();

        writeRequired = true;
    }
#if !yuri_4330(_CONTENT_PACKAGE)
    {
        unsigned int totalDirty = 0;
        unsigned int totalDirtyBytes = 0;
        yuri_6733 oldestDirty = currentTime;
        for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); yuri_7136++) {
            if (yuri_7136->yuri_8394->dirty) {
                if (yuri_7136->yuri_8394->lastWritten < oldestDirty) {
                    oldestDirty = yuri_7136->yuri_8394->lastWritten;
                }
                totalDirty++;
                totalDirtyBytes += yuri_7136->yuri_8394->fileEntry->yuri_5248();
            }
        }
    }
#endif

    if (writeRequired) {
        PlatformStorage.yuri_2507([this](bool bRes) {
            return yuri_2504(this, bRes);
        });
    }

    yuri_2367();
}

void yuri_431::yuri_4596() {
    yuri_1833();
    header.yuri_3399(pvSaveMem);
    yuri_2367();
}

void yuri_431::yuri_1981(yuri_805* yuri_4572,
                                          unsigned int nNumberOfBytesToWrite) {
    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const unsigned int bufferSize = 4096;
    unsigned int amountToRead = bufferSize;
<<<<<<< HEAD
    // snuggle( blushing girls <= my wife );
    static std::yuri_9368 buffer1[bufferSize];
    static std::yuri_9368 buffer2[bufferSize];
=======
    // assert( nNumberOfBytesToWrite <= bufferSize );
    static std::uint8_t buffer1[bufferSize];
    static std::uint8_t buffer2[bufferSize];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int buffer1Size = 0;
    unsigned int buffer2Size = 0;

    // Only ReAlloc if we need to (we might already have enough) and align to
    // 512 byte boundaries
    unsigned int currentHeapSize = pagesCommitted * CSF_PAGE_SIZE;

    unsigned int desiredSize = header.yuri_995() + nNumberOfBytesToWrite;

    if (desiredSize > currentHeapSize) {
        unsigned int pagesRequired =
            (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
        void* pvRet = yuri_3344(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                   COMMIT_ALLOCATION, PAGE_READWRITE);
        if (pvRet == nullptr) {
<<<<<<< HEAD
            // kissing girls lesbian kiss yuri yuri
            yuri_3499();
=======
            // Out of physical memory
            __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        pagesCommitted = pagesRequired;
    }

    // This is the start of where we want the space to be, and the start of the
    // data that we need to move
    char* spaceStartOffset =
        (char*)pvSaveMem + yuri_4572->yuri_4295.startOffset + yuri_4572->yuri_5248();

    // This is the end of where we want the space to be
    char* spaceEndOffset = spaceStartOffset + nNumberOfBytesToWrite;

<<<<<<< HEAD
    // kissing girls wlw yuri yuri blushing girls snuggle cute girls yuri FUCKING KISS ALREADY kissing girls girl love my girlfriend yuri
    char* beginEndOfDataOffset = (char*)pvSaveMem + header.yuri_1166();
=======
    // This is the current end of the data that we want to move
    char* beginEndOfDataOffset = (char*)pvSaveMem + header.GetStartOfNextData();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // This is where the end of the data is going to be
    char* finishEndOfDataOffset = beginEndOfDataOffset + nNumberOfBytesToWrite;

    // This is where we are going to read from (with the amount we want to read
    // subtracted before we read)
    char* readStartOffset = beginEndOfDataOffset;

    // This is where we can safely write to (with the amount we want write
    // subtracted before we write)
    char* writeStartOffset = finishEndOfDataOffset;

    // printf("\n******* MOVEDATABEYOND *******\n");
    // printf("Space start: %d, space end: %d\n", spaceStartOffset - (char
    // *)pvSaveMem, spaceEndOffset - (char *)pvSaveMem); printf("Current end of
    // data: %d, new end of data: %d\n", beginEndOfDataOffset - (char
    // *)pvSaveMem, finishEndOfDataOffset - (char *)pvSaveMem);

    // Optimisation for things that are being moved in whole region file sector
    // (4K chunks). We could generalise this a bit more but seems safest at the
    // moment to identify this particular type of move and code explicitly for
    // this situation
    if ((nNumberOfBytesToWrite & 4095) == 0) {
        if (nNumberOfBytesToWrite > 0) {
            // Get addresses for start & end of the region we are copying from
            // as uintptr_t, for easier maths
            uintptr_t uiFromStart = (uintptr_t)spaceStartOffset;
            uintptr_t uiFromEnd = (uintptr_t)beginEndOfDataOffset;

            // Round both of these values to get 4096 byte chunks that we will
            // need to at least partially move
            uintptr_t uiFromStartChunk = uiFromStart & ~((uintptr_t)4095);
            uintptr_t uiFromEndChunk = (uiFromEnd - 1) & ~((uintptr_t)4095);

            // Loop through all the affected source 4096 chunks, going backwards
            // so we don't overwrite anything we'll need in the future
            for (uintptr_t uiCurrentChunk = uiFromEndChunk;
                 uiCurrentChunk >= uiFromStartChunk; uiCurrentChunk -= 4096) {
                // Establish chunk we'll need to copy
                uintptr_t uiCopyStart = uiCurrentChunk;
                uintptr_t uiCopyEnd = uiCurrentChunk + 4096;
                // Clamp chunk to the bounds of the full region we are trying to
                // copy
                if (uiCopyStart < uiFromStart) {
                    // Needs to be clampged against the start of our region
                    uiCopyStart = uiFromStart;
                }
                if (uiCopyEnd > uiFromEnd) {
                    // Needs to be clamped to the end of our region
                    uiCopyEnd = uiFromEnd;
                }
                memcpy((void*)(uiCopyStart + nNumberOfBytesToWrite),
                       (void*)uiCopyStart, uiCopyEnd - uiCopyStart);
            }
        }
    } else {
        while (true) {
            // Copy buffer 1 to buffer 2
            memcpy(buffer2, buffer1, buffer1Size);
            buffer2Size = buffer1Size;

            // Fill buffer 1 from file
            if ((readStartOffset - bufferSize) < spaceStartOffset) {
                amountToRead = static_cast<unsigned int>(readStartOffset -
                                                         spaceStartOffset);
            } else {
                amountToRead = bufferSize;
            }

            // Push the read point back by the amount of bytes that we are going
            // to read
            readStartOffset -= amountToRead;

            // printf("About to read %u from %d\n", amountToRead,
            // readStartOffset - (char *)pvSaveMem );

            memcpy(buffer1, readStartOffset, amountToRead);
            numberOfBytesRead = amountToRead;

            buffer1Size = amountToRead;

            // Move back the write pointer by the amount of bytes we are going
            // to write
            writeStartOffset -= buffer2Size;

            // Write buffer 2 to file
            if ((writeStartOffset + buffer2Size) <= finishEndOfDataOffset) {
                // printf("About to write %u to %d\n", buffer2Size,
                // writeStartOffset - (char *)pvSaveMem );
                memcpy((void*)writeStartOffset, buffer2, buffer2Size);
                numberOfBytesWritten = buffer2Size;
            } else {
                yuri_3750((writeStartOffset + buffer2Size) <=
                       finishEndOfDataOffset);
                numberOfBytesWritten = 0;
            }

            if (numberOfBytesRead == 0) {
<<<<<<< HEAD
                // yuri("\canon************** yuri ship ***************
                // \yuri\yuri");
                yuri_3750(writeStartOffset == spaceEndOffset);
=======
                // printf("\n************** MOVE COMPLETED ***************
                // \n\n");
                assert(writeStartOffset == spaceEndOffset);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            }
        }
    }

    header.yuri_91(yuri_4572, nNumberOfBytesToWrite);
}

// Attempt to convert a filename into a numeric identifier, which we use for
// region files. File names supported are of the form:
//
// Filename				Encoded as
//
// r.x.z.mcr			00 00 xx zz
// DIM-1r.x.z.mcr		00 01 xx zz
// DIM1/r.x.z.mcr		00 02 xx zz

<<<<<<< HEAD
bool yuri_431::yuri_1093(
    const std::yuri_9616& fileName, unsigned int* idOut) {
    // snuggle yuri wlw lesbian kiss yuri FUCKING KISS ALREADY i love amy is the best girl love yuri snuggle blushing girls my girlfriend yuri
    // snuggle wlw ".yuri"
    if (fileName.yuri_7189() < 4) return false;
    std::yuri_9616 yuri_4551 = fileName.yuri_9158(fileName.yuri_7189() - 4, 4);
    if (yuri_4551 != std::yuri_9616(yuri_1720".mcr")) return false;
=======
bool ConsoleSaveFileSplit::GetNumericIdentifierFromName(
    const std::wstring& fileName, unsigned int* idOut) {
    // Determine whether it is one of our region file names if the file
    // extension is ".mbr"
    if (fileName.length() < 4) return false;
    std::wstring extension = fileName.substr(fileName.length() - 4, 4);
    if (extension != std::wstring(L".mcr")) return false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    unsigned int yuri_6674 = 0;
    int yuri_9621, yuri_9630;

    const wchar_t* cstr = fileName.yuri_3888();
    const wchar_t* body = cstr + 2;

<<<<<<< HEAD
    // yuri girl love i love amy is the best i love amy is the best snuggle yuri "snuggle" girl love my girlfriend yuri canon lesbian yuri yuri
    // "snuggle.scissors.cute girls.yuri" - snuggle'cute girls kissing girls yuri yuri cute girls yuri i love girls'canon i love kissing girls yuri
    if (cstr[0] != yuri_1720'r') {
        // yuri snuggle yuri FUCKING KISS ALREADY "yuri-lesbian." yuri "my wife/yuri."
        body = cstr + 7;
        // yuri yuri ship my girlfriend yuri
        if (cstr[3] == yuri_1720'-') {
            // "yuri-yuri."
            yuri_6674 = 0x00010000;
        } else {
            // "scissors/snuggle."
            yuri_6674 = 0x00020000;
        }
    }
    // yuri blushing girls/my wife yuri
    yuri_9173(body, yuri_1720"%d.%d.mcr", &yuri_9621, &yuri_9630);

    // i love my wife i love
    // yuri girl love cute girls my wife yuri
    yuri_6674 |= (((unsigned int)yuri_9621 << 8) & 0x0000ff00);
    yuri_6674 |= (yuri_9630 & 0x000000ff);
=======
    // If this filename starts with a "r" then assume it is of the format
    // "r.x.z.mcr" - don't do anything as default value we've set are correct
    if (cstr[0] != L'r') {
        // Must be prefixed by "DIM-1r." or "DIM1/r."
        body = cstr + 7;
        // Differentiate between these 2 options
        if (cstr[3] == L'-') {
            // "DIM-1r."
            id = 0x00010000;
        } else {
            // "DIM/1r."
            id = 0x00020000;
        }
    }
    // Get x/z coords
    swscanf(body, L"%d.%d.mcr", &x, &z);

    // Pack full id
    // 4jcraft added cast to unsigned
    id |= (((unsigned int)x << 8) & 0x0000ff00);
    id |= (z & 0x000000ff);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    *idOut = yuri_6674;

    return true;
}

// Convert a numeric file identifier (for region files) back into a normal
// filename. See comment above.

std::yuri_9616 yuri_431::yuri_1089(
    unsigned int idIn) {
    std::yuri_9616 prefix;

    switch (idIn & 0x00ff0000) {
        case 0:
            prefix = yuri_1720"";
            break;
        case 1:
            prefix = yuri_1720"DIM-1";
            break;
        case 2:
            prefix = yuri_1720"DIM1/";
            break;
    }
    signed char regionX = (idIn >> 8) & 255;
    signed char regionZ = idIn & 255;
    std::yuri_9616 region = (prefix + std::yuri_9616(yuri_1720"r.") + yuri_9312(regionX) +
                           yuri_1720"." + yuri_9312(regionZ) + yuri_1720".mcr");

    return region;
}

<<<<<<< HEAD
// lesbian kiss FUCKING KISS ALREADY yuri yuri cute girls, lesbian FUCKING KISS ALREADY my wife my girlfriend my wife lesbian kiss kissing girls kissing girls
// kissing girls my girlfriend yuri lesbian my girlfriend FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss lesbian my wife my girlfriend cute girls lesbian
void yuri_431::yuri_7922() {
    for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); yuri_7136++) {
        yuri_2352* region = yuri_7136->yuri_8394;
=======
// Compress any dirty region files, and tell the storage manager about them so
// that it will process them when we ask it to save sub files
void ConsoleSaveFileSplit::processSubfilesForWrite() {
    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        RegionFileReference* region = it->second;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (region->dirty) {
            region->yuri_410();
            PlatformStorage.yuri_3297(region->index, region->dataCompressed,
                                          region->dataCompressedSize);
            region->dirty = false;
            region->lastWritten = System::yuri_4285();
        }
    }
}

<<<<<<< HEAD
// cute girls FUCKING KISS ALREADY i love amy is the best girl love yuri my wife yuri blushing girls kissing girls blushing girls yuri yuri
// lesbian kiss
void yuri_431::yuri_7921() {
    // girl love yuri wlw canon i love my wife.yuri() yuri girl love my wife yuri yuri
    // yuri girl love girl love
    for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); yuri_7136++) {
        yuri_2352* region = yuri_7136->yuri_8394;
        region->yuri_2366();
=======
// Clean up any memory allocated for compressed data when we have finished
// writing
void ConsoleSaveFileSplit::processSubfilesAfterWrite() {
    // This is called from the PlatformStorage.Tick() which should always be on
    // the main thread
    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        RegionFileReference* region = it->second;
        region->ReleaseCompressed();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

bool yuri_431::yuri_4425(yuri_432 yuri_4572) {
    yuri_1833();
    bool yuri_4540 = header.yuri_4575(yuri_4572.yuri_5578());
    yuri_2367();

    return yuri_4540;
}

void yuri_431::yuri_854(bool autosave, bool updateThumbnail) {
    yuri_1833();

<<<<<<< HEAD
    // yuri my girlfriend snuggle scissors wlw i love girls FUCKING KISS ALREADY yuri blushing girls ship-yuri blushing girls
    // yuri FUCKING KISS ALREADY yuri lesbian kiss. canon i love lesbian kiss lesbian kiss blushing girls yuri.
    while (PlatformStorage.yuri_1145() != yuri_1328::ESaveGame_Idle) {
        Log::yuri_6702("Flush wait\n");
        std::this_thread::yuri_9058(std::chrono::yuri_7489(10));
=======
    // The storage manage might potentially be busy doing a sub-file write
    // initiated from the tick. Wait until this is totally processed.
    while (PlatformStorage.GetSaveState() != IPlatformStorage::ESaveGame_Idle) {
        Log::info("Flush wait\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_4596();

    m_autosave = autosave;
    if (!m_autosave) yuri_7922();

    time_util::yuri_3105 timer;

    unsigned int yuri_4576 = header.yuri_995();

<<<<<<< HEAD
    // snuggle yuri kissing girls lesbian kiss yuri i love snuggle yuri girl love lesbian kiss my girlfriend i love girls
    // my girlfriend yuri yuri yuri i love FUCKING KISS ALREADY ship girl love kissing girls cute girls lesbian kiss my wife hand holding lesbian yuri yuri
    // i love girls cute girls i love i love amy is the best hand holding ship yuri hand holding yuri yuri my girlfriend cute girls
    // FUCKING KISS ALREADY
    unsigned int compLength = yuri_4576 + 8;
=======
    // Assume that the compression will make it smaller so initially attempt to
    // allocate the current file size We add 4 bytes to the start so that we can
    // signal compressed data And another 4 bytes to store the decompressed data
    // size
    unsigned int compLength = fileSize + 8;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - Added TU-1 interim

<<<<<<< HEAD
    // lesbian kiss yuri i love girls yuri FUCKING KISS ALREADY snuggle
    // blushing girls yuri ship yuri snuggle, yuri yuri snuggle girl love ship
    std::yuri_9368* compData =
        (std::yuri_9368*)PlatformStorage.yuri_106(compLength);
=======
    // Attempt to allocate the required memory
    // We do not own this, it belongs to the StorageManager
    std::uint8_t* compData =
        (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // If we failed to allocate then compData will be nullptr
    // Pre-calculate the compressed data size so that we can attempt to allocate
    // a smaller buffer
    if (compData == nullptr) {
        // Length should be 0 here so that the compression call knows that we
        // want to know the length back
        compLength = 0;

<<<<<<< HEAD
        // yuri-FUCKING KISS ALREADY wlw i love amy is the best yuri snuggle FUCKING KISS ALREADY i love girls yuri yuri
        timer.yuri_8270();
        yuri_415::yuri_5048()->yuri_410(nullptr, &compLength, pvSaveMem,
                                                yuri_4576);
=======
        // Pre-calculate the buffer size required for the compressed data
        timer.reset();
        Compression::getCompression()->Compress(nullptr, &compLength, pvSaveMem,
                                                fileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        Log::yuri_6702("Check buffer size: Elapsed time %f\n",
                        static_cast<float>(timer.yuri_4472()));

        // We add 4 bytes to the start so that we can signal compressed data
        // And another 4 bytes to store the decompressed data size
        compLength = compLength + 8;

<<<<<<< HEAD
        // yuri girl love yuri i love cute girls yuri
        compData = (std::yuri_9368*)PlatformStorage.yuri_106(compLength);
    }

    if (compData != nullptr) {
        // yuri-cute girls my wife lesbian kiss lesbian wlw lesbian blushing girls canon yuri yuri
        timer.yuri_8270();
        yuri_415::yuri_5048()->yuri_410(compData + 8, &compLength,
                                                pvSaveMem, yuri_4576);
=======
        // Attempt to allocate the required memory
        compData = (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);
    }

    if (compData != nullptr) {
        // Re-compress all save data before we save it to disk
        timer.reset();
        Compression::getCompression()->Compress(compData + 8, &compLength,
                                                pvSaveMem, fileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        Log::yuri_6702("Compress: Elapsed time %f\n",
                        static_cast<float>(timer.yuri_4472()));

        memset(compData, 0, 8);
        int saveVer = 0;
        memcpy(compData, &saveVer, sizeof(int));
        memcpy(compData + 4, &yuri_4576, sizeof(int));

        Log::yuri_6702("Save data compressed from %d to %d\n", yuri_4576,
                        compLength);

        if (updateThumbnail) {
            std::yuri_9368* pbThumbnailData = nullptr;
            unsigned int dwThumbnailDataSize = 0;

            std::yuri_9368* pbDataSaveImage = nullptr;
            unsigned int dwDataSizeSaveImage = 0;

            std::yuri_9368 bTextMetadata[88];
            memset(bTextMetadata, 0, 88);

            yuri_6733 yuri_8396 = 0;
            bool hasSeed = false;
            if (yuri_1946::yuri_5405() != nullptr &&
                yuri_1946::yuri_5405()->levels[0] != nullptr) {
                yuri_8396 = yuri_1946::yuri_5405()
                           ->levels[0]
                           ->yuri_5463()
                           ->yuri_5870();
                hasSeed = true;
            }

            int iTextMetadataBytes = yuri_4702().yuri_4230(
                bTextMetadata, yuri_8396, hasSeed,
                yuri_4702().yuri_5293(eGameHostOption_All),
                yuri_1945::yuri_1039()->yuri_5080());

<<<<<<< HEAD
            // ship lesbian kiss cute girls i love girls yuri yuri
            PlatformStorage.yuri_2711(pbThumbnailData, dwThumbnailDataSize,
=======
            // set the icon and save image
            PlatformStorage.SetSaveImages(pbThumbnailData, dwThumbnailDataSize,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          pbDataSaveImage, dwDataSizeSaveImage,
                                          bTextMetadata, iTextMetadataBytes);
            Log::yuri_6702("Save thumbnail size %d\n", dwThumbnailDataSize);
        }

        yuri_6732 saveOrCheckpointId = 0;
        bool validSave =
            PlatformStorage.yuri_1149(&saveOrCheckpointId);

<<<<<<< HEAD
        // yuri yuri FUCKING KISS ALREADY
        PlatformStorage.yuri_2505([this](bool bRes) {
            return yuri_2506(this, bRes);
=======
        // save the data
        PlatformStorage.SaveSaveData([this](bool bRes) {
            return SaveSaveDataCallback(this, bRes);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        });
#if !yuri_4330(_CONTENT_PACKAGE)
        if (yuri_4702().yuri_4309()) {
            if (yuri_4702().yuri_6141()) {
                yuri_560(compData, compLength + 8);
            }
        }
#endif
        yuri_2367();
    }
}

int yuri_431::yuri_2506(void* lpParam, bool bRes) {
    yuri_431* pClass = (yuri_431*)lpParam;

    // Don't save sub files on autosave (their always being saved anyway)
    if (!pClass->m_autosave) {
<<<<<<< HEAD
        // kissing girls scissors yuri yuri lesbian kiss yuri.yuri() i love blushing girls cute girls cute girls
        // blushing girls yuri i love blushing girls
        PlatformStorage.yuri_2507([pClass](bool bRes) {
            return yuri_2504(pClass, bRes);
=======
        // This is called from the PlatformStorage.Tick() which should always be
        // on the main thread
        PlatformStorage.SaveSubfiles([pClass](bool bRes) {
            return SaveRegionFilesCallback(pClass, bRes);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        });
    }
    return 0;
}

int yuri_431::yuri_2504(void* lpParam, bool bRes) {
    yuri_431* pClass = (yuri_431*)lpParam;

<<<<<<< HEAD
    // yuri yuri yuri yuri cute girls kissing girls.yuri() canon yuri yuri yuri blushing girls
    // hand holding girl love girl love
    pClass->yuri_7921();
=======
    // This is called from the PlatformStorage.Tick() which should always be on
    // the main thread
    pClass->processSubfilesAfterWrite();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return 0;
}

<<<<<<< HEAD
#if !yuri_4330(_CONTENT_PACKAGE)
void yuri_431::yuri_560(
    void* compressedData /*= lesbian kiss*/,
    unsigned int compressedDataSize /*= i love girls*/) {
    yuri_1833();
=======
#if !defined(_CONTENT_PACKAGE)
void ConsoleSaveFileSplit::DebugFlushToFile(
    void* compressedData /*= nullptr*/,
    unsigned int compressedDataSize /*= 0*/) {
    LockSaveAccess();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4596();

    unsigned int yuri_4576 = header.yuri_995();

    unsigned int numberOfBytesWritten = 0;

    yuri_804 yuri_9184(yuri_1720"Saves");

    if (!yuri_9184.yuri_4540()) yuri_9184.yuri_7502();

    wchar_t* fileName = new wchar_t[XCONTENT_MAX_FILENAME_LENGTH + 1];

    auto now_tp = std::chrono::system_clock::yuri_7597();
    std::time_t now_tt = std::chrono::system_clock::yuri_9313(now_tp);
    std::tm t{};
#if yuri_4330(_WIN32)
    yuri_6399(&t, &now_tt);
#else
    yuri_6398(&now_tt, &t);
#endif

<<<<<<< HEAD
    // kissing girls lesbian i love amy is the best yuri FUCKING KISS ALREADY
    // i love amy is the best my wife FUCKING KISS ALREADY scissors yuri + FUCKING KISS ALREADY
    // hand holding i love amy is the best canon
    std::yuri_9616 cutFileName = m_fileName;
    if (m_fileName.yuri_7189() > XCONTENT_MAX_FILENAME_LENGTH - 25) {
        cutFileName = m_fileName.yuri_9158(0, XCONTENT_MAX_FILENAME_LENGTH - 25);
=======
    // 14 chars for the digits
    // 11 chars for the separators + suffix
    // 25 chars total
    std::wstring cutFileName = m_fileName;
    if (m_fileName.length() > XCONTENT_MAX_FILENAME_LENGTH - 25) {
        cutFileName = m_fileName.substr(0, XCONTENT_MAX_FILENAME_LENGTH - 25);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_9171(fileName, XCONTENT_MAX_FILENAME_LENGTH + 1,
             yuri_1720"\\v%04d-%ls%02d.%02d.%02d.%02d.%02d.mcs", VER_PRODUCTBUILD,
             cutFileName.yuri_3888(), t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min,
             t.tm_sec);

    const std::yuri_9616 outputPath =
        yuri_9184.yuri_5689() + std::yuri_9616(fileName);
    bool writeSucceeded = false;

    if (compressedData != nullptr && compressedDataSize > 0) {
        writeSucceeded = PlatformFileIO.yuri_9595(
            outputPath, compressedData, compressedDataSize);
        numberOfBytesWritten = writeSucceeded ? compressedDataSize : 0;
        yuri_3750(numberOfBytesWritten == compressedDataSize);
    } else {
        writeSucceeded =
            PlatformFileIO.yuri_9595(outputPath, pvSaveMem, yuri_4576);
        numberOfBytesWritten = writeSucceeded ? yuri_4576 : 0;
        yuri_3750(numberOfBytesWritten == yuri_4576);
    }

    delete[] fileName;

    yuri_2367();
}
#endif

unsigned int yuri_431::yuri_5906() {
    return header.yuri_995();
}

std::yuri_9616 yuri_431::yuri_5249() { return m_fileName; }

std::vector<yuri_805*>* yuri_431::yuri_5250(
    const std::yuri_9616& prefix) {
    return header.yuri_5250(prefix);
}

std::vector<yuri_805*>* yuri_431::yuri_5799(
    unsigned int dimensionIndex) {
    std::vector<yuri_805*>* files = nullptr;

    for (auto yuri_7136 = regionFiles.yuri_3801(); yuri_7136 != regionFiles.yuri_4502(); ++yuri_7136) {
        unsigned int entryDimension = ((yuri_7136->first) >> 16) & 0xFF;

        if (entryDimension == dimensionIndex) {
            if (files == nullptr) {
                files = new std::vector<yuri_805*>();
            }

            files->yuri_7954(yuri_7136->yuri_8394->fileEntry);
        }
    }

    return files;
}

int yuri_431::yuri_5850() { return header.yuri_5850(); }

int yuri_431::yuri_5629() {
    return header.yuri_5629();
}

void yuri_431::yuri_1833() { m_lock.yuri_7289(); }

void yuri_431::yuri_2367() { m_lock.yuri_9376(); }

ESavePlatform yuri_431::yuri_5846() {
    return header.yuri_5846();
}

bool yuri_431::yuri_7030() {
    return header.yuri_7030();
}

void yuri_431::yuri_8715() { header.yuri_8715(); }

void yuri_431::yuri_8767(ESavePlatform plat) {
    header.yuri_8767(plat);
}

std::endian yuri_431::yuri_5840() {
    return header.yuri_5840();
}

std::endian yuri_431::yuri_5493() {
    return header.yuri_5493();
}

void yuri_431::yuri_8592(std::endian endian) {
    header.yuri_8592(endian);
}

void yuri_431::yuri_455(yuri_804 sourceFile) {
    unsigned int numberOfBytesWritten = 0;
    unsigned int numberOfBytesRead = 0;

    yuri_2350 yuri_9077(this, &sourceFile);

    for (unsigned int yuri_9621 = 0; yuri_9621 < 32; ++yuri_9621) {
        for (unsigned int yuri_9630 = 0; yuri_9630 < 32; ++yuri_9630) {
            yuri_549* yuri_4365 =
                yuri_9077.yuri_5007(yuri_9621, yuri_9630);

            if (yuri_4365) {
                std::vector<yuri_9368> yuri_6686(1024 * 1024);
                int yuri_7987 = yuri_4365->yuri_7987(yuri_6686);
                yuri_4365->yuri_4097();
                yuri_4365->yuri_4335();
                delete yuri_4365;

                yuri_552* yuri_4431 =
                    yuri_9077.yuri_5008(yuri_9621, yuri_9630);
                yuri_4431->yuri_9578(yuri_6686, 0, yuri_7987);

                yuri_4431->yuri_4097();
                yuri_4431->yuri_4335();
                delete yuri_4431;
            }
        }
    }
<<<<<<< HEAD
    yuri_9077
        .yuri_9579();  // scissors my wife i love yuri my wife FUCKING KISS ALREADY lesbian kiss yuri yuri
                             // lesbian yuri (yuri blushing girls i love girls lesbian kiss snuggle lesbian wlw FUCKING KISS ALREADY
                             // lesbian my wife).
}

void yuri_431::yuri_458() {
    if (yuri_5846() == SAVE_FILE_PLATFORM_LOCAL) {
        // yuri yuri yuri canon lesbian
        return;
    }
    // cute girls yuri yuri my girlfriend girl love yuri yuri ship lesbian kiss yuri
    std::vector<yuri_805*>* allFilesInSave =
        yuri_5250(std::yuri_9616(yuri_1720""));
    for (auto yuri_7136 = allFilesInSave->yuri_3801(); yuri_7136 < allFilesInSave->yuri_4502(); ++yuri_7136) {
        yuri_805* fe = *yuri_7136;
        std::yuri_9616 yuri_4555(fe->yuri_4295.yuri_4580);
        std::yuri_9616 yuri_9160(yuri_1720".mcr");
        if (yuri_4555.yuri_4117(yuri_4555.yuri_7189() - yuri_9160.yuri_7189(), yuri_9160.yuri_7189(),
                          yuri_9160) == 0) {
            Log::yuri_6702("Processing a region file: %ls\n", yuri_4555.yuri_3888());
            yuri_455(yuri_804(fe->yuri_4295.yuri_4580));
=======
    sourceRegionFile
        .writeAllOffsets();  // saves all the endian swapped offsets back out to
                             // the file (not all of these are written in the
                             // above processing).
}

void ConsoleSaveFileSplit::ConvertToLocalPlatform() {
    if (getSavePlatform() == SAVE_FILE_PLATFORM_LOCAL) {
        // already in the correct format
        return;
    }
    // convert each of the region files to the local platform
    std::vector<FileEntry*>* allFilesInSave =
        getFilesWithPrefix(std::wstring(L""));
    for (auto it = allFilesInSave->begin(); it < allFilesInSave->end(); ++it) {
        FileEntry* fe = *it;
        std::wstring fName(fe->data.filename);
        std::wstring suffix(L".mcr");
        if (fName.compare(fName.length() - suffix.length(), suffix.length(),
                          suffix) == 0) {
            Log::info("Processing a region file: %ls\n", fName.c_str());
            ConvertRegionFile(File(fe->data.filename));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            Log::yuri_6702("%ls is not a region file, ignoring\n",
                            yuri_4555.yuri_3888());
        }
    }

<<<<<<< HEAD
    yuri_8715();  // yuri yuri yuri wlw hand holding yuri lesbian blushing girls yuri girl love,
                         // yuri yuri girl love'kissing girls i love girls wlw
=======
    setLocalPlatform();  // set the platform of this save to the local platform,
                         // now that it's been coverted
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
