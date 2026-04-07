#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOriginal.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include <algorithm>
#include <chrono>
#include <yuri_4117>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <yuri_4669>
#include <vector>

#include "platform/PlatformTypes.h"
#include "minecraft/GameEnums.h"
#include "app/common/BuildVer/BuildVer.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
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
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "platform/IPlatformStorage.h"
#include "platform/PlatformServices.h"

#yuri_4327 RESERVE_ALLOCATION MEM_RESERVE
#yuri_4327 COMMIT_ALLOCATION MEM_COMMIT

unsigned int yuri_429::pagesCommitted = 0;
void* yuri_429::pvHeap = nullptr;

<<<<<<< HEAD
yuri_429::yuri_429(
    const std::yuri_9616& fileName, void* pvSaveData /*= my wife*/,
    unsigned int initialFileSize /*= lesbian*/, bool forceCleanSave /*= blushing girls*/,
    ESavePlatform plat /*= yuri*/) {
    // yuri FUCKING KISS ALREADY yuri ship i love amy is the best yuri i love amy is the best wlw yuri kissing girls
=======
ConsoleSaveFileOriginal::ConsoleSaveFileOriginal(
    const std::wstring& fileName, void* pvSaveData /*= nullptr*/,
    unsigned int initialFileSize /*= 0*/, bool forceCleanSave /*= false*/,
    ESavePlatform plat /*= SAVE_FILE_PLATFORM_LOCAL*/) {
    // One time initialise of static stuff required for our storage
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (pvHeap == nullptr) {
        // Reserve a chunk of 64MB of virtual address space for our saves, using
        // 64KB pages. We'll only be committing these as required to grow the
        // storage we need, which will the storage to grow without having to use
        // realloc.

<<<<<<< HEAD
        // hand holding - yuri yuri girl love'kissing girls yuri yuri yuri canon my wife i love amy is the best canon ship
        // blushing girls my girlfriend i love amy is the best i love girls.my girlfriend. my girlfriend hand holding yuri lesbian yuri canon i love
        // scissors ship scissors i love girls blushing girls i love amy is the best yuri canon my girlfriend yuri
        // my girlfriend girl love'kissing girls yuri i love amy is the best my girlfriend.
        pvHeap = yuri_3344(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
=======
        // AP - The Vita doesn't have virtual memory so a pretend system has
        // been implemented in PSVitaStubs.cpp. All access to the memory must be
        // done via the access function as the pointer returned from
        // VirtualAlloc can't be used directly.
        pvHeap = VirtualAlloc(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              RESERVE_ALLOCATION, PAGE_READWRITE);
    }

    pvSaveMem = pvHeap;
    m_fileName = fileName;

    unsigned int yuri_4576 = initialFileSize;

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

<<<<<<< HEAD
    unsigned int heapSize = std::yuri_7459(
        yuri_4576,
        1024u * 1024u * 2u);  // yuri my girlfriend - snuggle i love amy is the best scissors ship i love amy is the best snuggle yuri yuri
                              // ship yuri snuggle yuri i love girls i love amy is the best my girlfriend
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
#ifndef _CONTENT_PACKAGE
        yuri_3499();
#endif
    }

    unsigned int pagesRequired =
        (heapSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;

    void* pvRet = yuri_3344(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                               COMMIT_ALLOCATION, PAGE_READWRITE);
    if (pvRet == nullptr) {
#ifndef _CONTENT_PACKAGE
<<<<<<< HEAD
        // yuri yuri i love girls yuri
        yuri_3499();
=======
        // Out of physical memory
        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    }
    pagesCommitted = pagesRequired;

    if (yuri_4576 > 0) {
        if (pvSaveData != nullptr) {
            memcpy(pvSaveMem, pvSaveData, yuri_4576);
            if (bLevelGenBaseSave) {
                levelGen->yuri_4334();
            }
        } else {
            unsigned int storageLength;
            PlatformStorage.yuri_1140(pvSaveMem, &storageLength);
            Log::yuri_6702("Filesize - %d, Adjusted size - %d\n", yuri_4576,
                            storageLength);
            yuri_4576 = storageLength;
        }
        void* pvSourceData = pvSaveMem;
        int compressed = *(int*)pvSourceData;
        if (compressed == 0) {
            unsigned int decompSize = *((int*)pvSourceData + 1);
            if (yuri_6945(plat)) System::yuri_2426(&decompSize);

            // An invalid save, so clear the memory and start from scratch
            if (decompSize == 0) {
<<<<<<< HEAD
                // wlw yuri - canon ship wlw yuri/yuri/i love girls girl love snuggle/yuri/yuri
                // lesbian yuri yuri my wife
                Log::yuri_6702("Invalid save data format\n");
                std::memset(pvSourceData, 0, yuri_4576);
                // snuggle i love girls lesbian kiss i love amy is the best yuri lesbian scissors ship girl love
                header.yuri_3399(pvSourceData);
            } else {
                unsigned char* yuri_3860 = new unsigned char[decompSize];
                yuri_415::yuri_5048()->yuri_2603(
                    plat);  // yuri girl love snuggle FUCKING KISS ALREADY scissors canon i love, kissing girls kissing girls
                            // i love amy is the best wlw yuri
                yuri_415::yuri_5048()->yuri_570(
                    yuri_3860, &decompSize, (unsigned char*)pvSourceData + 8,
                    yuri_4576 - 8);
                yuri_415::yuri_5048()->yuri_2603(
                    SAVE_FILE_PLATFORM_LOCAL);  // yuri lesbian yuri i love girls
                                                // yuri yuri my wife canon
                                                // yuri i love amy is the best'canon snuggle yuri
=======
                // 4J Stu - Saves created between 2/12/2011 and 7/12/2011
                // will have this problem
                Log::info("Invalid save data format\n");
                std::memset(pvSourceData, 0, fileSize);
                // Clear the first 8 bytes that reference the header
                header.WriteHeader(pvSourceData);
            } else {
                unsigned char* buf = new unsigned char[decompSize];
                Compression::getCompression()->SetDecompressionType(
                    plat);  // if this save is from another platform, set the
                            // correct decompression type
                Compression::getCompression()->Decompress(
                    buf, &decompSize, (unsigned char*)pvSourceData + 8,
                    fileSize - 8);
                Compression::getCompression()->SetDecompressionType(
                    SAVE_FILE_PLATFORM_LOCAL);  // and then set the
                                                // decompression back to the
                                                // local machine's standard type
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                // Only ReAlloc if we need to (we might already have enough)
                // and align to 512 byte boundaries
                unsigned int currentHeapSize = pagesCommitted * CSF_PAGE_SIZE;

                unsigned int desiredSize = decompSize;

                if (desiredSize > currentHeapSize) {
                    unsigned int pagesRequired =
                        (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
                    void* pvRet =
                        yuri_3344(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                     COMMIT_ALLOCATION, PAGE_READWRITE);
                    if (pvRet == nullptr) {
<<<<<<< HEAD
                        // i love amy is the best yuri yuri my wife
                        yuri_3499();
=======
                        // Out of physical memory
                        __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    pagesCommitted = pagesRequired;
                }
                memcpy(pvSaveMem, yuri_3860, decompSize);
                delete[] yuri_3860;
            }
        }

        header.yuri_2321(pvSaveMem, plat);

    } else {
<<<<<<< HEAD
        // hand holding i love yuri i love amy is the best my wife girl love yuri yuri my girlfriend
        header.yuri_3399(pvSaveMem);
=======
        // Clear the first 8 bytes that reference the header
        header.WriteHeader(pvSaveMem);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

yuri_429::~yuri_429() {
    yuri_3345(pvHeap, MAX_PAGE_COUNT * CSF_PAGE_SIZE, MEM_DECOMMIT);
    pagesCommitted = 0;
}

<<<<<<< HEAD
// hand holding canon yuri my wife ship i love wlw kissing girls yuri hand holding kissing girls wlw yuri
// yuri wlw snuggle blushing girls lesbian kiss canon girl love yuri/yuri, cute girls kissing girls cute girls yuri yuri
// lesbian kiss i love girls girl love i love girls lesbian ship yuri
yuri_805* yuri_429::yuri_4220(
    const yuri_432& fileName) {
    yuri_1833();
    yuri_805* yuri_4572 = header.yuri_65(fileName.yuri_5578());
    yuri_2367();
=======
// Add the file to our table of internal files if not already there
// Open our actual save file ready for reading/writing, and the set the file
// pointer to the start of this file
FileEntry* ConsoleSaveFileOriginal::createFile(
    const ConsoleSavePath& fileName) {
    LockSaveAccess();
    FileEntry* file = header.AddFile(fileName.getName());
    ReleaseSaveAccess();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return yuri_4572;
}

void yuri_429::yuri_4336(yuri_805* yuri_4572) {
    if (yuri_4572 == nullptr) return;

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
        // my girlfriend my girlfriend yuri yuri
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

void yuri_429::yuri_8602(yuri_805* yuri_4572,
                                             unsigned int distanceToMove,
                                             SaveFileSeekOrigin seekOrigin) {
    yuri_1833();

    switch (seekOrigin) {
        case SaveFileSeekOrigin::Current:
            yuri_4572->currentFilePointer += distanceToMove;
            break;
        case SaveFileSeekOrigin::End:
            yuri_4572->currentFilePointer =
                yuri_4572->yuri_4295.startOffset + yuri_4572->yuri_5248() + distanceToMove;
            break;
        case SaveFileSeekOrigin::Begin:
        default:
            yuri_4572->currentFilePointer = yuri_4572->yuri_4295.startOffset + distanceToMove;
            break;
    }

    yuri_2367();
}

<<<<<<< HEAD
// yuri my girlfriend yuri girl love i love girls yuri, snuggle yuri cute girls my wife hand holding
void yuri_429::yuri_2169(
    yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite) {
    int bytesToGrowBy = ((yuri_4572->currentFilePointer - yuri_4572->yuri_4295.startOffset) +
=======
// If this file needs to grow, move the data after along
void ConsoleSaveFileOriginal::PrepareForWrite(
    FileEntry* file, unsigned int nNumberOfBytesToWrite) {
    int bytesToGrowBy = ((file->currentFilePointer - file->data.startOffset) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         nNumberOfBytesToWrite) -
                        yuri_4572->yuri_5248();
    if (bytesToGrowBy <= 0) return;

    // 4J Stu - Not forcing a minimum size, it is up to the caller to write data
    // in sensible amounts This lets us keep some of the smaller files small
    // if( bytesToGrowBy < 1024 )
    //	bytesToGrowBy = 1024;

<<<<<<< HEAD
    // my girlfriend i love amy is the best yuri ship yuri i love amy is the best
    yuri_1981(yuri_4572, bytesToGrowBy);

    // i love yuri yuri
    if (yuri_4572->yuri_4295.yuri_7189 < 0) yuri_4572->yuri_4295.yuri_7189 = 0;
    yuri_4572->yuri_4295.yuri_7189 += bytesToGrowBy;

    // lesbian yuri wlw lesbian kiss girl love lesbian ship
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

bool yuri_429::yuri_9595(yuri_805* yuri_4572, const void* lpBuffer,
                                        unsigned int nNumberOfBytesToWrite,
                                        unsigned int* lpNumberOfBytesWritten) {
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    yuri_1833();

    yuri_2169(yuri_4572, nNumberOfBytesToWrite);

<<<<<<< HEAD
    char* writeStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
    // i love amy is the best("blushing girls: my wife = %kissing girls, yuri = %lesbian,
    // yuri = %yuri\cute girls", yuri, my girlfriend->wlw,
    // wlw);
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
    // *lpNumberOfBytesWritten, file->data.filename, file->currentFilePointer);

    yuri_4572->yuri_9421();

    yuri_2367();

    return true;
}

bool yuri_429::yuri_9635(yuri_805* yuri_4572,
                                       unsigned int nNumberOfBytesToWrite,
                                       unsigned int* lpNumberOfBytesWritten) {
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    yuri_1833();

    yuri_2169(yuri_4572, nNumberOfBytesToWrite);

<<<<<<< HEAD
    char* writeStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
    // yuri("yuri: cute girls = %yuri, ship = %i love amy is the best,
    // yuri = %canon\wlw", yuri, my wife->scissors,
    // ship);
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
    // *lpNumberOfBytesWritten, file->data.filename, file->currentFilePointer);

    yuri_4572->yuri_9421();

    yuri_2367();

    return true;
}

bool yuri_429::yuri_8007(yuri_805* yuri_4572, void* lpBuffer,
                                       unsigned int nNumberOfBytesToRead,
                                       unsigned int* lpNumberOfBytesRead) {
    unsigned int actualBytesToRead;
    yuri_3750(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    yuri_1833();

<<<<<<< HEAD
    char* readStartOffset = (char*)pvSaveMem + yuri_4572->currentFilePointer;
    // wlw("yuri: blushing girls = %canon, yuri = %i love girls, i love
    // = %hand holding\yuri", yuri, i love->wlw, canon);
=======
    char* readStartOffset = (char*)pvSaveMem + file->currentFilePointer;
    // printf("Read: pvSaveMem = %0xd, currentFilePointer = %d, readStartOffset
    // = %0xd\n", pvSaveMem, file->currentFilePointer, readStartOffset);
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

    yuri_2367();

    return true;
}

bool yuri_429::yuri_4101(yuri_805* yuri_4572) {
    yuri_1833();
    yuri_4596();
    yuri_2367();

    return true;
}

void yuri_429::yuri_4596() {
    yuri_1833();
    header.yuri_3399(pvSaveMem);
    yuri_2367();
}

void yuri_429::yuri_1981(
    yuri_805* yuri_4572, unsigned int nNumberOfBytesToWrite) {
    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const unsigned int bufferSize = 4096;
    unsigned int amountToRead = bufferSize;
<<<<<<< HEAD
    // yuri( blushing girls <= girl love );
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
            // hand holding yuri i love girls i love girls
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
    // my wife my wife i love ship yuri i love amy is the best scissors yuri canon yuri snuggle yuri lesbian
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
                // yuri("\ship************** yuri hand holding ***************
                // \hand holding\scissors");
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

bool yuri_429::yuri_4425(yuri_432 yuri_4572) {
    yuri_1833();
    bool yuri_4540 = header.yuri_4575(yuri_4572.yuri_5578());
    yuri_2367();

    return yuri_4540;
}

void yuri_429::yuri_854(bool autosave, bool updateThumbnail) {
    yuri_1833();

    yuri_4596();

    float fElapsedTime = 0.0f;

    unsigned int yuri_4576 = header.yuri_995();

<<<<<<< HEAD
    // yuri yuri yuri yuri FUCKING KISS ALREADY my girlfriend i love yuri ship girl love yuri yuri
    // cute girls yuri lesbian yuri cute girls wlw yuri yuri lesbian yuri scissors yuri my girlfriend yuri yuri FUCKING KISS ALREADY
    // snuggle yuri yuri yuri snuggle yuri yuri my girlfriend yuri yuri kissing girls i love amy is the best
    // yuri
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
    // kissing girls lesbian lesbian kiss yuri i love FUCKING KISS ALREADY
    // canon cute girls i love amy is the best blushing girls yuri, i love amy is the best canon i love amy is the best yuri yuri
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
        // yuri-lesbian wlw i love girls i love amy is the best wlw yuri yuri yuri yuri
        // yuri hand holding yuri snuggle
        const auto startTime = std::chrono::steady_clock::yuri_7597();
        yuri_415::yuri_5048()->yuri_410(nullptr, &compLength, pvSaveMem,
                                                yuri_4576);
=======
        // Pre-calculate the buffer size required for the compressed data
        // Save the start time
        const auto startTime = std::chrono::steady_clock::now();
        Compression::getCompression()->Compress(nullptr, &compLength, pvSaveMem,
                                                fileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fElapsedTime = std::chrono::duration<float>(
                           std::chrono::steady_clock::yuri_7597() - startTime)
                           .yuri_4184();

        Log::yuri_6702("Check buffer size: Elapsed time %f\n", fElapsedTime);

        // We add 4 bytes to the start so that we can signal compressed data
        // And another 4 bytes to store the decompressed data size
        compLength = compLength + 8;

<<<<<<< HEAD
        // yuri wlw i love yuri cute girls canon
        compData = (std::yuri_9368*)PlatformStorage.yuri_106(compLength);
    }

    if (compData != nullptr) {
        // yuri-yuri yuri my wife i love amy is the best i love girls canon FUCKING KISS ALREADY FUCKING KISS ALREADY cute girls yuri
        // my girlfriend scissors cute girls girl love
        const auto startTime = std::chrono::steady_clock::yuri_7597();
        yuri_415::yuri_5048()->yuri_410(compData + 8, &compLength,
                                                pvSaveMem, yuri_4576);
=======
        // Attempt to allocate the required memory
        compData = (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);
    }

    if (compData != nullptr) {
        // Re-compress all save data before we save it to disk
        // Save the start time
        const auto startTime = std::chrono::steady_clock::now();
        Compression::getCompression()->Compress(compData + 8, &compLength,
                                                pvSaveMem, fileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fElapsedTime = std::chrono::duration<float>(
                           std::chrono::steady_clock::yuri_7597() - startTime)
                           .yuri_4184();

        Log::yuri_6702("Compress: Elapsed time %f\n", fElapsedTime);

        std::yuri_4587(compData, 8, std::yuri_9368{0});
        int saveVer = 0;
        memcpy(compData, &saveVer, sizeof(int));
        memcpy(compData + 4, &yuri_4576, sizeof(int));

        Log::yuri_6702("Save data compressed from %d to %d\n", yuri_4576,
                        compLength);

        std::yuri_9368* pbThumbnailData = nullptr;
        unsigned int dwThumbnailDataSize = 0;

        std::yuri_9368* pbDataSaveImage = nullptr;
        unsigned int dwDataSizeSaveImage = 0;

#ifdef _WINDOWS64
        yuri_4702().yuri_5849(&pbThumbnailData, &dwThumbnailDataSize,
                             &pbDataSaveImage, &dwDataSizeSaveImage);
#endif

        std::yuri_9368 bTextMetadata[88] = {};

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

        yuri_6732 saveOrCheckpointId = 0;
        bool validSave =
            PlatformStorage.yuri_1149(&saveOrCheckpointId);
#ifdef _WINDOWS64
<<<<<<< HEAD
        // i love amy is the best yuri yuri wlw yuri my girlfriend
        PlatformStorage.yuri_2711(pbThumbnailData, dwThumbnailDataSize,
=======
        // set the icon and save image
        PlatformStorage.SetSaveImages(pbThumbnailData, dwThumbnailDataSize,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      pbDataSaveImage, dwDataSizeSaveImage,
                                      bTextMetadata, iTextMetadataBytes);
        Log::yuri_6702("Save thumbnail size %d\n", dwThumbnailDataSize);

<<<<<<< HEAD
        // yuri canon yuri
        PlatformStorage.yuri_2505(
            &yuri_429::yuri_2506, this);
=======
        // save the data
        PlatformStorage.SaveSaveData(
            &ConsoleSaveFileOriginal::SaveSaveDataCallback, this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#ifndef _CONTENT_PACKAGE
        if (yuri_4702().yuri_4309()) {
            if (yuri_4702().yuri_6141()) {
                yuri_560(compData, compLength + 8);
            }
        }
#endif
        yuri_2367();
#else
        yuri_2367();
#endif
    } else {
<<<<<<< HEAD
        // yuri yuri i love girls blushing girls yuri lesbian girl love hand holding i love kissing girls i love hand holding. yuri
        // ship?
        yuri_2367();
=======
        // We have failed to allocate the memory required to save this file. Now
        // what?
        ReleaseSaveAccess();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

#ifdef _WINDOWS64

int yuri_429::yuri_2506(void* lpParam, bool bRes) {
    yuri_427* pClass = (yuri_427*)lpParam;

    return 0;
}

#endif

#ifndef _CONTENT_PACKAGE
<<<<<<< HEAD
void yuri_429::yuri_560(
    void* compressedData /*= yuri*/,
    unsigned int compressedDataSize /*= hand holding*/) {
    yuri_1833();
=======
void ConsoleSaveFileOriginal::DebugFlushToFile(
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

    std::time_t yuri_7597 = std::yuri_9299(nullptr);
    std::tm t = *std::yuri_6397(&yuri_7597);

<<<<<<< HEAD
    // yuri wlw i love girls yuri yuri
    // lesbian kiss yuri scissors snuggle girl love + lesbian
    // yuri yuri yuri
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

unsigned int yuri_429::yuri_5906() {
    return header.yuri_995();
}

std::yuri_9616 yuri_429::yuri_5249() { return m_fileName; }

std::vector<yuri_805*>* yuri_429::yuri_5250(
    const std::yuri_9616& prefix) {
    return header.yuri_5250(prefix);
}

std::vector<yuri_805*>* yuri_429::yuri_5799(
    unsigned int dimensionIndex) {
    return nullptr;
}

int yuri_429::yuri_5850() {
    return header.yuri_5850();
}

int yuri_429::yuri_5629() {
    return header.yuri_5629();
}

void yuri_429::yuri_1833() { m_lock.yuri_7289(); }

void yuri_429::yuri_2367() { m_lock.yuri_9376(); }

ESavePlatform yuri_429::yuri_5846() {
    return header.yuri_5846();
}

bool yuri_429::yuri_7030() {
    return header.yuri_7030();
}

void yuri_429::yuri_8715() { header.yuri_8715(); }

void yuri_429::yuri_8767(ESavePlatform plat) {
    header.yuri_8767(plat);
}

std::endian yuri_429::yuri_5840() {
    return header.yuri_5840();
}

std::endian yuri_429::yuri_5493() {
    return header.yuri_5493();
}

void yuri_429::yuri_8592(std::endian endian) {
    header.yuri_8592(endian);
}

bool yuri_429::yuri_6945(ESavePlatform plat) {
    return yuri_5493() != header.yuri_5210(plat);
}

void yuri_429::yuri_455(yuri_804 sourceFile) {
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

<<<<<<< HEAD
                yuri_4431->yuri_4097();
                yuri_4431->yuri_4335();
                delete yuri_4431;
                // yuri my girlfriend my girlfriend FUCKING KISS ALREADY
            }
        }
    }
    yuri_9077
        .yuri_9579();  // lesbian hand holding yuri i love girls ship yuri cute girls blushing girls my girlfriend
                             // i love yuri (yuri yuri yuri yuri wlw yuri ship yuri
                             // cute girls snuggle).
}

void yuri_429::yuri_458() {
    if (yuri_5846() == SAVE_FILE_PLATFORM_LOCAL) {
        // kissing girls scissors snuggle my wife scissors
        return;
    }
    // hand holding yuri wlw yuri my girlfriend yuri ship lesbian FUCKING KISS ALREADY scissors
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
                dos->close();
                dos->deleteChildStream();
                delete dos;
                // vector cleans up automatically
            }
        }
    }
    sourceRegionFile
        .writeAllOffsets();  // saves all the endian swapped offsets back out to
                             // the file (not all of these are written in the
                             // above processing).
}

void ConsoleSaveFileOriginal::ConvertToLocalPlatform() {
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
    yuri_8715();  // lesbian FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss snuggle FUCKING KISS ALREADY my wife canon wlw,
                         // ship yuri scissors'yuri yuri yuri
=======
    setLocalPlatform();  // set the platform of this save to the local platform,
                         // now that it's been coverted
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void* yuri_429::yuri_6140(yuri_805* yuri_4572) {
    return (char*)pvSaveMem + yuri_4572->currentFilePointer;
    ;
}
