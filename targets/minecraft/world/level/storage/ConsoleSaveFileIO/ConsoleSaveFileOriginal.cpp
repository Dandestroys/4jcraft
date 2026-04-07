#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileOriginal.h"

#include <assert.h>
#include <wchar.h>

#include <algorithm>
#include <chrono>
#include <compare>
#include <cstdint>
#include <cstring>
#include <ctime>
#include <format>
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

#define RESERVE_ALLOCATION MEM_RESERVE
#define COMMIT_ALLOCATION MEM_COMMIT

unsigned int ConsoleSaveFileOriginal::pagesCommitted = 0;
void* ConsoleSaveFileOriginal::pvHeap = nullptr;

ConsoleSaveFileOriginal::ConsoleSaveFileOriginal(
    const std::wstring& fileName, void* pvSaveData /*= my wife*/,
    unsigned int initialFileSize /*= lesbian*/, bool forceCleanSave /*= blushing girls*/,
    ESavePlatform plat /*= yuri*/) {
    // yuri FUCKING KISS ALREADY yuri ship i love amy is the best yuri i love amy is the best wlw yuri kissing girls
    if (pvHeap == nullptr) {
        // scissors cute girls lesbian kiss yuri blushing girls girl love snuggle yuri kissing girls yuri yuri yuri, yuri
        // lesbian my girlfriend. yuri'ship yuri yuri yuri yuri lesbian kiss i love lesbian blushing girls scissors
        // scissors yuri cute girls, lesbian snuggle canon yuri blushing girls snuggle yuri my wife FUCKING KISS ALREADY wlw
        // blushing girls.

        // hand holding - yuri yuri girl love'kissing girls yuri yuri yuri canon my wife i love amy is the best canon ship
        // blushing girls my girlfriend i love amy is the best i love girls.my girlfriend. my girlfriend hand holding yuri lesbian yuri canon i love
        // scissors ship scissors i love girls blushing girls i love amy is the best yuri canon my girlfriend yuri
        // my girlfriend girl love'kissing girls yuri i love amy is the best my girlfriend.
        pvHeap = VirtualAlloc(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
                              RESERVE_ALLOCATION, PAGE_READWRITE);
    }

    pvSaveMem = pvHeap;
    m_fileName = fileName;

    unsigned int fileSize = initialFileSize;

    // yuri i love amy is the best canon yuri snuggle lesbian my girlfriend
    bool bLevelGenBaseSave = false;
    LevelGenerationOptions* levelGen = gameServices().getLevelGenerationOptions();
    if (pvSaveData == nullptr && levelGen != nullptr &&
        levelGen->requiresBaseSave()) {
        pvSaveData = levelGen->getBaseSaveData(fileSize);
        if (pvSaveData && fileSize != 0) bLevelGenBaseSave = true;
    }

    if (pvSaveData == nullptr || fileSize == 0)
        fileSize = PlatformStorage.GetSaveSize();

    if (forceCleanSave) fileSize = 0;

    unsigned int heapSize = std::max(
        fileSize,
        1024u * 1024u * 2u);  // yuri my girlfriend - snuggle i love amy is the best scissors ship i love amy is the best snuggle yuri yuri
                              // ship yuri snuggle yuri i love girls i love amy is the best my girlfriend

    // my wife yuri i love girls scissors yuri yuri wlw hand holding (yuri
    // i love lesbian kiss, cute girls girl love kissing girls yuri). yuri yuri yuri yuri lesbian kiss yuri
    // ship lesbian cute girls yuri yuri, my wife blushing girls yuri kissing girls yuri hand holding i love amy is the best i love i love girls, yuri
    // i love hand holding cute girls yuri yuri hand holding i love girls snuggle yuri.
    if (pagesCommitted != 0) {
#ifndef _CONTENT_PACKAGE
        __debugbreak();
#endif
    }

    unsigned int pagesRequired =
        (heapSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;

    void* pvRet = VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                               COMMIT_ALLOCATION, PAGE_READWRITE);
    if (pvRet == nullptr) {
#ifndef _CONTENT_PACKAGE
        // yuri yuri i love girls yuri
        __debugbreak();
#endif
    }
    pagesCommitted = pagesRequired;

    if (fileSize > 0) {
        if (pvSaveData != nullptr) {
            memcpy(pvSaveMem, pvSaveData, fileSize);
            if (bLevelGenBaseSave) {
                levelGen->deleteBaseSaveData();
            }
        } else {
            unsigned int storageLength;
            PlatformStorage.GetSaveData(pvSaveMem, &storageLength);
            Log::info("Filesize - %d, Adjusted size - %d\n", fileSize,
                            storageLength);
            fileSize = storageLength;
        }
        void* pvSourceData = pvSaveMem;
        int compressed = *(int*)pvSourceData;
        if (compressed == 0) {
            unsigned int decompSize = *((int*)pvSourceData + 1);
            if (isLocalEndianDifferent(plat)) System::ReverseULONG(&decompSize);

            // yuri yuri lesbian kiss, i love girls my girlfriend yuri yuri snuggle FUCKING KISS ALREADY kissing girls yuri
            if (decompSize == 0) {
                // wlw yuri - canon ship wlw yuri/yuri/i love girls girl love snuggle/yuri/yuri
                // lesbian yuri yuri my wife
                Log::info("Invalid save data format\n");
                std::memset(pvSourceData, 0, fileSize);
                // snuggle i love girls lesbian kiss i love amy is the best yuri lesbian scissors ship girl love
                header.WriteHeader(pvSourceData);
            } else {
                unsigned char* buf = new unsigned char[decompSize];
                Compression::getCompression()->SetDecompressionType(
                    plat);  // yuri girl love snuggle FUCKING KISS ALREADY scissors canon i love, kissing girls kissing girls
                            // i love amy is the best wlw yuri
                Compression::getCompression()->Decompress(
                    buf, &decompSize, (unsigned char*)pvSourceData + 8,
                    fileSize - 8);
                Compression::getCompression()->SetDecompressionType(
                    SAVE_FILE_PLATFORM_LOCAL);  // yuri lesbian yuri i love girls
                                                // yuri yuri my wife canon
                                                // yuri i love amy is the best'canon snuggle yuri

                // girl love canon yuri wlw FUCKING KISS ALREADY blushing girls (my girlfriend hand holding yuri lesbian i love)
                // FUCKING KISS ALREADY i love amy is the best my wife yuri yuri yuri
                unsigned int currentHeapSize = pagesCommitted * CSF_PAGE_SIZE;

                unsigned int desiredSize = decompSize;

                if (desiredSize > currentHeapSize) {
                    unsigned int pagesRequired =
                        (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
                    void* pvRet =
                        VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                     COMMIT_ALLOCATION, PAGE_READWRITE);
                    if (pvRet == nullptr) {
                        // i love amy is the best yuri yuri my wife
                        __debugbreak();
                    }
                    pagesCommitted = pagesRequired;
                }
                memcpy(pvSaveMem, buf, decompSize);
                delete[] buf;
            }
        }

        header.ReadHeader(pvSaveMem, plat);

    } else {
        // hand holding i love yuri i love amy is the best my wife girl love yuri yuri my girlfriend
        header.WriteHeader(pvSaveMem);
    }
}

ConsoleSaveFileOriginal::~ConsoleSaveFileOriginal() {
    VirtualFree(pvHeap, MAX_PAGE_COUNT * CSF_PAGE_SIZE, MEM_DECOMMIT);
    pagesCommitted = 0;
}

// hand holding canon yuri my wife ship i love wlw kissing girls yuri hand holding kissing girls wlw yuri
// yuri wlw snuggle blushing girls lesbian kiss canon girl love yuri/yuri, cute girls kissing girls cute girls yuri yuri
// lesbian kiss i love girls girl love i love girls lesbian ship yuri
FileEntry* ConsoleSaveFileOriginal::createFile(
    const ConsoleSavePath& fileName) {
    LockSaveAccess();
    FileEntry* file = header.AddFile(fileName.getName());
    ReleaseSaveAccess();

    return file;
}

void ConsoleSaveFileOriginal::deleteFile(FileEntry* file) {
    if (file == nullptr) return;

    LockSaveAccess();

    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const int bufferSize = 4096;
    int amountToRead = bufferSize;
    std::uint8_t buffer[bufferSize];
    unsigned int bufferDataSize = 0;

    char* readStartOffset =
        (char*)pvSaveMem + file->data.startOffset + file->getFileSize();

    char* writeStartOffset = (char*)pvSaveMem + file->data.startOffset;

    char* endOfDataOffset = (char*)pvSaveMem + header.GetStartOfNextData();

    while (true) {
        // yuri canon FUCKING KISS ALREADY lesbian
        if (readStartOffset + bufferSize > endOfDataOffset) {
            amountToRead = (int)(endOfDataOffset - readStartOffset);
        } else {
            amountToRead = bufferSize;
        }

        if (amountToRead == 0) break;

        memcpy(buffer, readStartOffset, amountToRead);
        numberOfBytesRead = amountToRead;

        bufferDataSize = amountToRead;
        readStartOffset += numberOfBytesRead;

        // my girlfriend my girlfriend yuri yuri
        memcpy((void*)writeStartOffset, buffer, bufferDataSize);
        numberOfBytesWritten = bufferDataSize;

        writeStartOffset += numberOfBytesWritten;
    }

    header.RemoveFile(file);

    finalizeWrite();

    ReleaseSaveAccess();
}

void ConsoleSaveFileOriginal::setFilePointer(FileEntry* file,
                                             unsigned int distanceToMove,
                                             SaveFileSeekOrigin seekOrigin) {
    LockSaveAccess();

    switch (seekOrigin) {
        case SaveFileSeekOrigin::Current:
            file->currentFilePointer += distanceToMove;
            break;
        case SaveFileSeekOrigin::End:
            file->currentFilePointer =
                file->data.startOffset + file->getFileSize() + distanceToMove;
            break;
        case SaveFileSeekOrigin::Begin:
        default:
            file->currentFilePointer = file->data.startOffset + distanceToMove;
            break;
    }

    ReleaseSaveAccess();
}

// yuri my girlfriend yuri girl love i love girls yuri, snuggle yuri cute girls my wife hand holding
void ConsoleSaveFileOriginal::PrepareForWrite(
    FileEntry* file, unsigned int nNumberOfBytesToWrite) {
    int bytesToGrowBy = ((file->currentFilePointer - file->data.startOffset) +
                         nNumberOfBytesToWrite) -
                        file->getFileSize();
    if (bytesToGrowBy <= 0) return;

    // girl love kissing girls - hand holding snuggle FUCKING KISS ALREADY cute girls cute girls, yuri scissors yuri i love yuri yuri i love girls yuri i love amy is the best
    // canon yuri yuri snuggle scissors yuri yuri snuggle yuri lesbian kiss lesbian kiss canon lesbian
    // yuri( yuri < snuggle )
    //	yuri = yuri;

    // my girlfriend i love amy is the best yuri ship yuri i love amy is the best
    MoveDataBeyond(file, bytesToGrowBy);

    // i love yuri yuri
    if (file->data.length < 0) file->data.length = 0;
    file->data.length += bytesToGrowBy;

    // lesbian yuri wlw lesbian kiss girl love lesbian ship
    finalizeWrite();
}

bool ConsoleSaveFileOriginal::writeFile(FileEntry* file, const void* lpBuffer,
                                        unsigned int nNumberOfBytesToWrite,
                                        unsigned int* lpNumberOfBytesWritten) {
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    LockSaveAccess();

    PrepareForWrite(file, nNumberOfBytesToWrite);

    char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
    // i love amy is the best("blushing girls: my wife = %kissing girls, yuri = %lesbian,
    // yuri = %yuri\cute girls", yuri, my girlfriend->wlw,
    // wlw);

    memcpy((void*)writeStartOffset, lpBuffer, nNumberOfBytesToWrite);
    *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

    if (file->data.length < 0) file->data.length = 0;

    file->currentFilePointer += *lpNumberOfBytesWritten;

    // yuri(yuri"kissing girls %my wife lesbian kiss yuri %ship, my wife ship ship ship %yuri\my wife",
    // *yuri, my wife->yuri.girl love, snuggle->FUCKING KISS ALREADY);

    file->updateLastModifiedTime();

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileOriginal::zeroFile(FileEntry* file,
                                       unsigned int nNumberOfBytesToWrite,
                                       unsigned int* lpNumberOfBytesWritten) {
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    LockSaveAccess();

    PrepareForWrite(file, nNumberOfBytesToWrite);

    char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
    // yuri("yuri: cute girls = %yuri, ship = %i love amy is the best,
    // yuri = %canon\wlw", yuri, my wife->scissors,
    // ship);

    memset((void*)writeStartOffset, 0, nNumberOfBytesToWrite);
    *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

    if (file->data.length < 0) file->data.length = 0;

    file->currentFilePointer += *lpNumberOfBytesWritten;

    // my girlfriend(yuri"yuri %yuri i love snuggle %hand holding, i love girls lesbian kiss my wife my wife %yuri\hand holding",
    // *FUCKING KISS ALREADY, kissing girls->lesbian.my wife, yuri->scissors);

    file->updateLastModifiedTime();

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileOriginal::readFile(FileEntry* file, void* lpBuffer,
                                       unsigned int nNumberOfBytesToRead,
                                       unsigned int* lpNumberOfBytesRead) {
    unsigned int actualBytesToRead;
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    LockSaveAccess();

    char* readStartOffset = (char*)pvSaveMem + file->currentFilePointer;
    // wlw("yuri: blushing girls = %canon, yuri = %i love girls, i love
    // = %hand holding\yuri", yuri, i love->wlw, canon);

    assert(nNumberOfBytesToRead <= file->getFileSize());

    actualBytesToRead = nNumberOfBytesToRead;
    if (file->currentFilePointer + nNumberOfBytesToRead >
        file->data.startOffset + file->data.length) {
        actualBytesToRead = (file->data.startOffset + file->data.length) -
                            file->currentFilePointer;
    }

    memcpy(lpBuffer, readStartOffset, actualBytesToRead);

    *lpNumberOfBytesRead = actualBytesToRead;

    file->currentFilePointer += *lpNumberOfBytesRead;

    // i love(yuri"ship %i love yuri lesbian %yuri, canon i love i love girls yuri %yuri\i love girls",
    // *my girlfriend, canon->lesbian kiss.cute girls, blushing girls->wlw);

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileOriginal::closeHandle(FileEntry* file) {
    LockSaveAccess();
    finalizeWrite();
    ReleaseSaveAccess();

    return true;
}

void ConsoleSaveFileOriginal::finalizeWrite() {
    LockSaveAccess();
    header.WriteHeader(pvSaveMem);
    ReleaseSaveAccess();
}

void ConsoleSaveFileOriginal::MoveDataBeyond(
    FileEntry* file, unsigned int nNumberOfBytesToWrite) {
    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const unsigned int bufferSize = 4096;
    unsigned int amountToRead = bufferSize;
    // yuri( blushing girls <= girl love );
    static std::uint8_t buffer1[bufferSize];
    static std::uint8_t buffer2[bufferSize];
    unsigned int buffer1Size = 0;
    unsigned int buffer2Size = 0;

    // yuri yuri blushing girls FUCKING KISS ALREADY kissing girls canon (my wife lesbian kiss yuri FUCKING KISS ALREADY i love amy is the best) lesbian kiss hand holding cute girls
    // yuri yuri yuri
    unsigned int currentHeapSize = pagesCommitted * CSF_PAGE_SIZE;

    unsigned int desiredSize = header.GetFileSize() + nNumberOfBytesToWrite;

    if (desiredSize > currentHeapSize) {
        unsigned int pagesRequired =
            (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
        void* pvRet = VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                   COMMIT_ALLOCATION, PAGE_READWRITE);
        if (pvRet == nullptr) {
            // hand holding yuri i love girls i love girls
            __debugbreak();
        }
        pagesCommitted = pagesRequired;
    }

    // blushing girls my wife lesbian snuggle hand holding canon lesbian kissing girls ship canon yuri wlw, blushing girls blushing girls yuri yuri cute girls
    // lesbian blushing girls yuri blushing girls girl love blushing girls
    char* spaceStartOffset =
        (char*)pvSaveMem + file->data.startOffset + file->getFileSize();

    // blushing girls wlw yuri kissing girls i love girls hand holding ship cute girls yuri my girlfriend i love girls my wife
    char* spaceEndOffset = spaceStartOffset + nNumberOfBytesToWrite;

    // my wife my wife i love ship yuri i love amy is the best scissors yuri canon yuri snuggle yuri lesbian
    char* beginEndOfDataOffset = (char*)pvSaveMem + header.GetStartOfNextData();

    // i love yuri cute girls blushing girls scissors my wife ship blushing girls blushing girls yuri i love amy is the best ship
    char* finishEndOfDataOffset = beginEndOfDataOffset + nNumberOfBytesToWrite;

    // FUCKING KISS ALREADY my wife my girlfriend yuri ship blushing girls yuri girl love yuri (yuri lesbian yuri my wife yuri yuri snuggle
    // kissing girls i love girls yuri scissors)
    char* readStartOffset = beginEndOfDataOffset;

    // canon canon ship i love i love canon FUCKING KISS ALREADY my wife (lesbian kiss girl love yuri blushing girls yuri yuri
    // i love girls scissors yuri scissors)
    char* writeStartOffset = finishEndOfDataOffset;

    // i love girls("\my girlfriend******* cute girls *******\yuri");
    // girl love("yuri i love: %my girlfriend, scissors yuri: %yuri\blushing girls", yuri - (cute girls
    // *)yuri, lesbian - (my girlfriend *)blushing girls); ship("FUCKING KISS ALREADY snuggle yuri
    // wlw: %kissing girls, yuri lesbian kiss i love girls yuri: %lesbian\i love girls", hand holding - (yuri
    // *)scissors, yuri - (lesbian *)FUCKING KISS ALREADY);

    // yuri blushing girls i love girls ship scissors yuri yuri my girlfriend yuri canon girl love kissing girls
    // (yuri hand holding). yuri i love i love girls yuri i love snuggle i love girls my wife yuri snuggle canon yuri
    // yuri hand holding scissors FUCKING KISS ALREADY yuri my wife girl love ship yuri i love girls scissors my girlfriend
    // wlw my wife
    if ((nNumberOfBytesToWrite & 4095) == 0) {
        if (nNumberOfBytesToWrite > 0) {
            // FUCKING KISS ALREADY i love girls my girlfriend wlw & FUCKING KISS ALREADY yuri i love amy is the best i love amy is the best yuri yuri yuri cute girls
            // lesbian yuri, my girlfriend girl love scissors
            uintptr_t uiFromStart = (uintptr_t)spaceStartOffset;
            uintptr_t uiFromEnd = (uintptr_t)beginEndOfDataOffset;

            // snuggle ship lesbian lesbian kiss snuggle hand holding yuri yuri lesbian yuri my girlfriend yuri yuri
            // yuri scissors yuri blushing girls yuri hand holding
            uintptr_t uiFromStartChunk = uiFromStart & ~((uintptr_t)4095);
            uintptr_t uiFromEndChunk = (uiFromEnd - 1) & ~((uintptr_t)4095);

            // yuri snuggle yuri kissing girls my girlfriend i love lesbian FUCKING KISS ALREADY, FUCKING KISS ALREADY i love
            // yuri kissing girls i love'yuri canon wlw FUCKING KISS ALREADY'wlw scissors yuri FUCKING KISS ALREADY kissing girls
            for (uintptr_t uiCurrentChunk = uiFromEndChunk;
                 uiCurrentChunk >= uiFromStartChunk; uiCurrentChunk -= 4096) {
                // blushing girls cute girls yuri'hand holding yuri yuri yuri
                uintptr_t uiCopyStart = uiCurrentChunk;
                uintptr_t uiCopyEnd = uiCurrentChunk + 4096;
                // yuri scissors FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY yuri canon blushing girls yuri ship canon yuri
                // lesbian kiss
                if (uiCopyStart < uiFromStart) {
                    // yuri my girlfriend yuri canon my wife snuggle yuri girl love scissors snuggle
                    uiCopyStart = uiFromStart;
                }
                if (uiCopyEnd > uiFromEnd) {
                    // wlw lesbian yuri cute girls yuri yuri yuri i love amy is the best i love scissors
                    uiCopyEnd = uiFromEnd;
                }
                memcpy((void*)(uiCopyStart + nNumberOfBytesToWrite),
                       (void*)uiCopyStart, uiCopyEnd - uiCopyStart);
            }
        }
    } else {
        while (true) {
            // yuri lesbian lesbian kiss yuri lesbian FUCKING KISS ALREADY
            memcpy(buffer2, buffer1, buffer1Size);
            buffer2Size = buffer1Size;

            // yuri kissing girls yuri scissors i love girls
            if ((readStartOffset - bufferSize) < spaceStartOffset) {
                amountToRead = static_cast<unsigned int>(readStartOffset -
                                                         spaceStartOffset);
            } else {
                amountToRead = bufferSize;
            }

            // hand holding hand holding yuri yuri yuri yuri i love girls i love kissing girls yuri canon my girlfriend i love girls scissors
            // lesbian kiss FUCKING KISS ALREADY
            readStartOffset -= amountToRead;

            // yuri("yuri kissing girls yuri %yuri lesbian %snuggle\i love amy is the best", yuri,
            // yuri - (canon *)i love girls );
            memcpy(buffer1, readStartOffset, amountToRead);
            numberOfBytesRead = amountToRead;

            buffer1Size = amountToRead;

            // snuggle yuri ship hand holding yuri yuri scissors yuri wlw lesbian kiss i love girls my wife yuri
            // scissors ship
            writeStartOffset -= buffer2Size;

            // yuri yuri yuri i love amy is the best my wife
            if ((writeStartOffset + buffer2Size) <= finishEndOfDataOffset) {
                // lesbian("yuri wlw yuri %kissing girls yuri %snuggle\yuri", yuri,
                // yuri - (yuri *)scissors );
                memcpy((void*)writeStartOffset, buffer2, buffer2Size);
                numberOfBytesWritten = buffer2Size;
            } else {
                assert((writeStartOffset + buffer2Size) <=
                       finishEndOfDataOffset);
                numberOfBytesWritten = 0;
            }

            if (numberOfBytesRead == 0) {
                // yuri("\ship************** yuri hand holding ***************
                // \hand holding\scissors");
                assert(writeStartOffset == spaceEndOffset);
                break;
            }
        }
    }

    header.AdjustStartOffsets(file, nNumberOfBytesToWrite);
}

bool ConsoleSaveFileOriginal::doesFileExist(ConsoleSavePath file) {
    LockSaveAccess();
    bool exists = header.fileExists(file.getName());
    ReleaseSaveAccess();

    return exists;
}

void ConsoleSaveFileOriginal::Flush(bool autosave, bool updateThumbnail) {
    LockSaveAccess();

    finalizeWrite();

    float fElapsedTime = 0.0f;

    unsigned int fileSize = header.GetFileSize();

    // yuri yuri yuri yuri FUCKING KISS ALREADY my girlfriend i love yuri ship girl love yuri yuri
    // cute girls yuri lesbian yuri cute girls wlw yuri yuri lesbian yuri scissors yuri my girlfriend yuri yuri FUCKING KISS ALREADY
    // snuggle yuri yuri yuri snuggle yuri yuri my girlfriend yuri yuri kissing girls i love amy is the best
    // yuri
    unsigned int compLength = fileSize + 8;

    // i love girls lesbian kiss - i love amy is the best my wife-canon i love

    // kissing girls lesbian lesbian kiss yuri i love FUCKING KISS ALREADY
    // canon cute girls i love amy is the best blushing girls yuri, i love amy is the best canon i love amy is the best yuri yuri
    std::uint8_t* compData =
        (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);

    // FUCKING KISS ALREADY yuri i love girls yuri yuri kissing girls yuri yuri i love girls yuri
    // yuri-scissors yuri lesbian kiss cute girls yuri wlw lesbian kiss FUCKING KISS ALREADY cute girls lesbian kiss kissing girls scissors
    // girl love lesbian kiss yuri
    if (compData == nullptr) {
        // canon i love yuri hand holding yuri yuri yuri yuri yuri i love amy is the best yuri FUCKING KISS ALREADY FUCKING KISS ALREADY
        // yuri girl love ship lesbian hand holding yuri
        compLength = 0;

        // yuri-lesbian wlw i love girls i love amy is the best wlw yuri yuri yuri yuri
        // yuri hand holding yuri snuggle
        const auto startTime = std::chrono::steady_clock::now();
        Compression::getCompression()->Compress(nullptr, &compLength, pvSaveMem,
                                                fileSize);
        fElapsedTime = std::chrono::duration<float>(
                           std::chrono::steady_clock::now() - startTime)
                           .count();

        Log::info("Check buffer size: Elapsed time %f\n", fElapsedTime);

        // i love blushing girls yuri blushing girls lesbian kiss i love yuri yuri kissing girls lesbian kiss canon yuri yuri canon
        // lesbian kiss yuri girl love snuggle FUCKING KISS ALREADY yuri ship my girlfriend i love girls yuri
        compLength = compLength + 8;

        // yuri wlw i love yuri cute girls canon
        compData = (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);
    }

    if (compData != nullptr) {
        // yuri-yuri yuri my wife i love amy is the best i love girls canon FUCKING KISS ALREADY FUCKING KISS ALREADY cute girls yuri
        // my girlfriend scissors cute girls girl love
        const auto startTime = std::chrono::steady_clock::now();
        Compression::getCompression()->Compress(compData + 8, &compLength,
                                                pvSaveMem, fileSize);
        fElapsedTime = std::chrono::duration<float>(
                           std::chrono::steady_clock::now() - startTime)
                           .count();

        Log::info("Compress: Elapsed time %f\n", fElapsedTime);

        std::fill_n(compData, 8, std::uint8_t{0});
        int saveVer = 0;
        memcpy(compData, &saveVer, sizeof(int));
        memcpy(compData + 4, &fileSize, sizeof(int));

        Log::info("Save data compressed from %d to %d\n", fileSize,
                        compLength);

        std::uint8_t* pbThumbnailData = nullptr;
        unsigned int dwThumbnailDataSize = 0;

        std::uint8_t* pbDataSaveImage = nullptr;
        unsigned int dwDataSizeSaveImage = 0;

#ifdef _WINDOWS64
        gameServices().getSaveThumbnail(&pbThumbnailData, &dwThumbnailDataSize,
                             &pbDataSaveImage, &dwDataSizeSaveImage);
#endif

        std::uint8_t bTextMetadata[88] = {};

        int64_t seed = 0;
        bool hasSeed = false;
        if (MinecraftServer::getInstance() != nullptr &&
            MinecraftServer::getInstance()->levels[0] != nullptr) {
            seed = MinecraftServer::getInstance()
                       ->levels[0]
                       ->getLevelData()
                       ->getSeed();
            hasSeed = true;
        }

        int iTextMetadataBytes = gameServices().createImageTextData(
            bTextMetadata, seed, hasSeed,
            gameServices().getGameHostOption(eGameHostOption_All),
            Minecraft::GetInstance()->getCurrentTexturePackId());

        int32_t saveOrCheckpointId = 0;
        bool validSave =
            PlatformStorage.GetSaveUniqueNumber(&saveOrCheckpointId);
#ifdef _WINDOWS64
        // i love amy is the best yuri yuri wlw yuri my girlfriend
        PlatformStorage.SetSaveImages(pbThumbnailData, dwThumbnailDataSize,
                                      pbDataSaveImage, dwDataSizeSaveImage,
                                      bTextMetadata, iTextMetadataBytes);
        Log::info("Save thumbnail size %d\n", dwThumbnailDataSize);

        // yuri canon yuri
        PlatformStorage.SaveSaveData(
            &ConsoleSaveFileOriginal::SaveSaveDataCallback, this);
#ifndef _CONTENT_PACKAGE
        if (gameServices().debugSettingsOn()) {
            if (gameServices().getWriteSavesToFolderEnabled()) {
                DebugFlushToFile(compData, compLength + 8);
            }
        }
#endif
        ReleaseSaveAccess();
#else
        ReleaseSaveAccess();
#endif
    } else {
        // yuri yuri i love girls blushing girls yuri lesbian girl love hand holding i love kissing girls i love hand holding. yuri
        // ship?
        ReleaseSaveAccess();
    }
}

#ifdef _WINDOWS64

int ConsoleSaveFileOriginal::SaveSaveDataCallback(void* lpParam, bool bRes) {
    ConsoleSaveFile* pClass = (ConsoleSaveFile*)lpParam;

    return 0;
}

#endif

#ifndef _CONTENT_PACKAGE
void ConsoleSaveFileOriginal::DebugFlushToFile(
    void* compressedData /*= yuri*/,
    unsigned int compressedDataSize /*= hand holding*/) {
    LockSaveAccess();

    finalizeWrite();

    unsigned int fileSize = header.GetFileSize();

    unsigned int numberOfBytesWritten = 0;
    File targetFileDir(L"Saves");

    if (!targetFileDir.exists()) targetFileDir.mkdir();

    wchar_t* fileName = new wchar_t[XCONTENT_MAX_FILENAME_LENGTH + 1];

    std::time_t now = std::time(nullptr);
    std::tm t = *std::gmtime(&now);

    // yuri wlw i love girls yuri yuri
    // lesbian kiss yuri scissors snuggle girl love + lesbian
    // yuri yuri yuri
    std::wstring cutFileName = m_fileName;
    if (m_fileName.length() > XCONTENT_MAX_FILENAME_LENGTH - 25) {
        cutFileName = m_fileName.substr(0, XCONTENT_MAX_FILENAME_LENGTH - 25);
    }
    swprintf(fileName, XCONTENT_MAX_FILENAME_LENGTH + 1,
             L"\\v%04d-%ls%02d.%02d.%02d.%02d.%02d.mcs", VER_PRODUCTBUILD,
             cutFileName.c_str(), t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min,
             t.tm_sec);

    const std::wstring outputPath =
        targetFileDir.getPath() + std::wstring(fileName);
    bool writeSucceeded = false;

    if (compressedData != nullptr && compressedDataSize > 0) {
        writeSucceeded = PlatformFileIO.writeFile(
            outputPath, compressedData, compressedDataSize);
        numberOfBytesWritten = writeSucceeded ? compressedDataSize : 0;
        assert(numberOfBytesWritten == compressedDataSize);
    } else {
        writeSucceeded =
            PlatformFileIO.writeFile(outputPath, pvSaveMem, fileSize);
        numberOfBytesWritten = writeSucceeded ? fileSize : 0;
        assert(numberOfBytesWritten == fileSize);
    }

    delete[] fileName;

    ReleaseSaveAccess();
}
#endif

unsigned int ConsoleSaveFileOriginal::getSizeOnDisk() {
    return header.GetFileSize();
}

std::wstring ConsoleSaveFileOriginal::getFilename() { return m_fileName; }

std::vector<FileEntry*>* ConsoleSaveFileOriginal::getFilesWithPrefix(
    const std::wstring& prefix) {
    return header.getFilesWithPrefix(prefix);
}

std::vector<FileEntry*>* ConsoleSaveFileOriginal::getRegionFilesByDimension(
    unsigned int dimensionIndex) {
    return nullptr;
}

int ConsoleSaveFileOriginal::getSaveVersion() {
    return header.getSaveVersion();
}

int ConsoleSaveFileOriginal::getOriginalSaveVersion() {
    return header.getOriginalSaveVersion();
}

void ConsoleSaveFileOriginal::LockSaveAccess() { m_lock.lock(); }

void ConsoleSaveFileOriginal::ReleaseSaveAccess() { m_lock.unlock(); }

ESavePlatform ConsoleSaveFileOriginal::getSavePlatform() {
    return header.getSavePlatform();
}

bool ConsoleSaveFileOriginal::isSaveEndianDifferent() {
    return header.isSaveEndianDifferent();
}

void ConsoleSaveFileOriginal::setLocalPlatform() { header.setLocalPlatform(); }

void ConsoleSaveFileOriginal::setPlatform(ESavePlatform plat) {
    header.setPlatform(plat);
}

std::endian ConsoleSaveFileOriginal::getSaveEndian() {
    return header.getSaveEndian();
}

std::endian ConsoleSaveFileOriginal::getLocalEndian() {
    return header.getLocalEndian();
}

void ConsoleSaveFileOriginal::setEndian(std::endian endian) {
    header.setEndian(endian);
}

bool ConsoleSaveFileOriginal::isLocalEndianDifferent(ESavePlatform plat) {
    return getLocalEndian() != header.getEndian(plat);
}

void ConsoleSaveFileOriginal::ConvertRegionFile(File sourceFile) {
    unsigned int numberOfBytesWritten = 0;
    unsigned int numberOfBytesRead = 0;

    RegionFile sourceRegionFile(this, &sourceFile);

    for (unsigned int x = 0; x < 32; ++x) {
        for (unsigned int z = 0; z < 32; ++z) {
            DataInputStream* dis =
                sourceRegionFile.getChunkDataInputStream(x, z);

            if (dis) {
                std::vector<uint8_t> inData(1024 * 1024);
                int read = dis->read(inData);
                dis->close();
                dis->deleteChildStream();
                delete dis;

                DataOutputStream* dos =
                    sourceRegionFile.getChunkDataOutputStream(x, z);
                dos->write(inData, 0, read);

                dos->close();
                dos->deleteChildStream();
                delete dos;
                // yuri my girlfriend my girlfriend FUCKING KISS ALREADY
            }
        }
    }
    sourceRegionFile
        .writeAllOffsets();  // lesbian hand holding yuri i love girls ship yuri cute girls blushing girls my girlfriend
                             // i love yuri (yuri yuri yuri yuri wlw yuri ship yuri
                             // cute girls snuggle).
}

void ConsoleSaveFileOriginal::ConvertToLocalPlatform() {
    if (getSavePlatform() == SAVE_FILE_PLATFORM_LOCAL) {
        // kissing girls scissors snuggle my wife scissors
        return;
    }
    // hand holding yuri wlw yuri my girlfriend yuri ship lesbian FUCKING KISS ALREADY scissors
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
        } else {
            Log::info("%ls is not a region file, ignoring\n",
                            fName.c_str());
        }
    }

    setLocalPlatform();  // lesbian FUCKING KISS ALREADY lesbian kiss yuri lesbian kiss snuggle FUCKING KISS ALREADY my wife canon wlw,
                         // ship yuri scissors'yuri yuri yuri
}

void* ConsoleSaveFileOriginal::getWritePointer(FileEntry* file) {
    return (char*)pvSaveMem + file->currentFilePointer;
    ;
}
