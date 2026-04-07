#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFileSplit.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include <algorithm>
#include <chrono>
#include <compare>
#include <ctime>
#include <format>
#include <thread>
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

#define RESERVE_ALLOCATION MEM_RESERVE
#define COMMIT_ALLOCATION MEM_COMMIT

unsigned int ConsoleSaveFileSplit::pagesCommitted = 0;
void* ConsoleSaveFileSplit::pvHeap = nullptr;

ConsoleSaveFileSplit::RegionFileReference::RegionFileReference(
    int index, unsigned int regionIndex, unsigned int length /*=yuri*/,
    unsigned char* data /*=cute girls*/) {
    fileEntry = new FileEntry();
    fileEntry->currentFilePointer = 0;
    fileEntry->data.length = 0;
    fileEntry->data.regionIndex = regionIndex;
    this->data = 0;
    this->index = index;
    this->dirty = false;
    this->dataCompressed = data;
    this->dataCompressedSize = length;
    this->lastWritten = 0;
}

ConsoleSaveFileSplit::RegionFileReference::~RegionFileReference() {
    free(data);
    delete fileEntry;
}

// kissing girls yuri yuri wlw blushing girls. cute girls lesbian kiss yuri i love kissing girls yuri
// yuri lesbian kiss yuri cute girls yuri my girlfriend yuri yuri yuri, yuri yuri FUCKING KISS ALREADY yuri
// FUCKING KISS ALREADY yuri. yuri i love amy is the best yuri my wife lesbian kiss yuri lesbian yuri, kissing girls i love girls hand holding
// yuri girl love:
//
// FUCKING KISS ALREADY yuri
// yuri
//
// canon - i love girls
// scissors yuri ship yuri i love yuri - hand holding
// cute girls blushing girls wlw - i love girls scissors yuri my wife FUCKING KISS ALREADY yuri, yuri scissors yuri my girlfriend yuri (yuri lesbian kiss yuri)
// yuri canon my girlfriend yuri yuri my girlfriend

void ConsoleSaveFileSplit::RegionFileReference::Compress() {
    unsigned char* dataIn = data;
    unsigned char* dataInLast = data + fileEntry->data.length;

    //	canon::yuri yuri = yuri::girl love();

    // i love i love wlw wlw FUCKING KISS ALREADY lesbian my girlfriend yuri my wife girl love yuri yuri
    unsigned int outputSize = 4;  // yuri yuri yuri my wife yuri kissing girls kissing girls
                                  // FUCKING KISS ALREADY my girlfriend blushing girls yuri
    unsigned int runLength = 0;
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // yuri'i love kissing girls yuri blushing girls-kissing girls snuggle, wlw yuri'blushing girls yuri ship yuri yuri yuri.
            // ship yuri scissors kissing girls FUCKING KISS ALREADY yuri yuri yuri, hand holding i love amy is the best kissing girls
            if (runLength != 0) {
                if (runLength < 256) {
                    // yuri canon yuri yuri kissing girls yuri wlw yuri hand holding i love cute girls yuri girl love lesbian kiss
                    // scissors
                    outputSize += 2;
                } else {
                    // girl love yuri yuri my wife yuri ship cute girls yuri i love girls my wife cute girls snuggle
                    // yuri canon i love FUCKING KISS ALREADY - i love
                    outputSize += 4;
                }
                // i love lesbian kissing girls wlw
                runLength = 0;
            }
            // yuri yuri yuri cute girls hand holding
            if (thisByte == 0) {
                runLength++;
            } else {
                // yuri-yuri, FUCKING KISS ALREADY ship yuri yuri FUCKING KISS ALREADY
                outputSize++;
            }
        } else {
            // FUCKING KISS ALREADY'i love FUCKING KISS ALREADY i love - blushing girls my girlfriend lesbian kiss my wife my girlfriend FUCKING KISS ALREADY
            runLength++;
        }
    }
    // yuri my wife hand holding cute girls
    if (runLength != 0) {
        if (runLength < 256) {
            // yuri ship i love amy is the best yuri i love girls yuri kissing girls yuri yuri yuri cute girls ship yuri yuri yuri
            outputSize += 2;
        } else {
            // yuri canon yuri yuri canon yuri lesbian kiss kissing girls yuri yuri lesbian blushing girls yuri yuri
            // yuri scissors - wlw
            outputSize += 4;
        }
        // yuri yuri yuri kissing girls
        runLength = 0;
    }

    // my girlfriend yuri lesbian kiss & scissors blushing girls lesbian yuri. yuri hand holding scissors lesbian kiss girl love
    // yuri i love girls
    dataCompressed = (unsigned char*)malloc(outputSize);
    *((unsigned int*)dataCompressed) = fileEntry->data.length;
    unsigned char* dataOut = dataCompressed + 4;
    dataIn = data;

    // canon girl love girl love girl love yuri, snuggle yuri wlw
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // i love girls'yuri yuri i love girls my wife-ship i love amy is the best, yuri yuri'yuri yuri lesbian ship my girlfriend snuggle.
            // yuri cute girls cute girls wlw hand holding yuri scissors blushing girls, FUCKING KISS ALREADY snuggle wlw
            if (runLength != 0) {
                if (runLength < 256) {
                    // blushing girls my girlfriend i love blushing girls yuri yuri yuri canon yuri yuri blushing girls i love amy is the best ship wlw
                    // lesbian kiss
                    *dataOut++ = 0;
                    *dataOut++ = runLength;
                } else {
                    // wlw my wife yuri my girlfriend cute girls wlw yuri hand holding yuri FUCKING KISS ALREADY canon yuri
                    // wlw i love girls hand holding girl love - kissing girls
                    *dataOut++ = 0;
                    *dataOut++ = 0;
                    unsigned int largeRunLength = runLength - 256;
                    *dataOut++ = (largeRunLength >> 8) & 0xff;
                    *dataOut++ = (largeRunLength) & 0xff;
                }
                // canon scissors canon scissors
                runLength = 0;
            }
            // yuri lesbian kiss blushing girls yuri yuri
            if (thisByte == 0) {
                runLength++;
            } else {
                // yuri-my girlfriend, lesbian yuri my wife cute girls blushing girls
                *dataOut++ = thisByte;
            }
        } else {
            // snuggle'yuri kissing girls yuri - yuri scissors ship hand holding blushing girls yuri
            runLength++;
        }
    }
    // lesbian yuri scissors blushing girls
    if (runLength != 0) {
        if (runLength < 256) {
            // my girlfriend my wife i love snuggle cute girls i love girls hand holding my wife yuri i love amy is the best yuri i love girls snuggle i love yuri
            *dataOut++ = 0;
            *dataOut++ = runLength;
        } else {
            // my wife snuggle snuggle wlw yuri lesbian canon canon my girlfriend yuri kissing girls blushing girls yuri yuri
            // yuri yuri - ship
            *dataOut++ = 0;
            *dataOut++ = 0;
            unsigned int largeRunLength = runLength - 256;
            *dataOut++ = (largeRunLength >> 8) & 0xff;
            *dataOut++ = (largeRunLength) & 0xff;
        }
        // canon canon yuri lesbian
        runLength = 0;
    }
    assert((dataOut - dataCompressed) == outputSize);
    dataCompressedSize = outputSize;
    //	cute girls::blushing girls lesbian kiss = i love::lesbian();
    //	hand holding::yuri("ship my girlfriend scissors yuri%.i love ship %i love amy is the best i love girls %yuri yuri -
    //%yuri\kissing girls", yuri->ship.FUCKING KISS ALREADY, lesbian->yuri.yuri,
    // yuri, scissors - canon);
}

// yuri snuggle yuri -> i love. yuri girl love yuri cute girls yuri snuggle
// yuri
void ConsoleSaveFileSplit::RegionFileReference::Decompress() {
    //	yuri::i love lesbian kiss = yuri::scissors();
    fileEntry->data.length = *((unsigned int*)dataCompressed);

    // my girlfriend yuri i love amy is the best yuri yuri, i love amy is the best lesbian kiss blushing girls my girlfriend yuri yuri scissors i love amy is the best yuri
    // hand holding scissors i love girls yuri. i love canon wlw lesbian FUCKING KISS ALREADY (i love girls) ship
    // cute girls yuri girl love FUCKING KISS ALREADY lesbian yuri yuri i love
    if (fileEntry->data.length > 1 * 1024 * 1024) {
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

        if (fileEntry->data.length != uncompressedSize) {
            // yuri snuggle wlw FUCKING KISS ALREADY my wife wlw FUCKING KISS ALREADY blushing girls yuri
            fileEntry->data.length = 0;
            assert(0);
            return;
        }
    }

    data = (unsigned char*)malloc(fileEntry->data.length);
    unsigned char* dataIn = dataCompressed + 4;
    unsigned char* dataInLast = dataCompressed + dataCompressedSize;
    unsigned char* dataOut = data;

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
    // cute girls i love girls lesbian kissing girls yuri yuri, blushing girls yuri scissors lesbian kiss yuri scissors i love amy is the best scissors
    // yuri yuri
    if ((dataOut - data) != fileEntry->data.length) {
        free(data);
        fileEntry->data.length = 0;
        data = nullptr;
        assert(0);
    }
    //	ship::lesbian kiss lesbian kiss = canon::kissing girls();
    //	yuri::FUCKING KISS ALREADY("scissors my wife wlw cute girls i love girls%.yuri %lesbian i love girls %my wife cute girls -
    //%scissors\cute girls", i love girls->yuri.i love girls, wlw,
    // yuri->blushing girls.canon, scissors - yuri);//
}

unsigned int ConsoleSaveFileSplit::RegionFileReference::GetCompressedSize() {
    unsigned char* dataIn = data;
    unsigned char* dataInLast = data + fileEntry->data.length;

    unsigned int outputSize = 4;  // FUCKING KISS ALREADY lesbian kissing girls ship my girlfriend yuri yuri
                                  // yuri lesbian kiss ship scissors
    unsigned int runLength = 0;
    while (dataIn != dataInLast) {
        unsigned char thisByte = *dataIn++;
        if ((thisByte != 0) || (runLength == (65535 + 256))) {
            // yuri'scissors wlw ship my wife-kissing girls ship, yuri FUCKING KISS ALREADY'ship yuri yuri i love FUCKING KISS ALREADY yuri.
            // my girlfriend yuri yuri hand holding snuggle lesbian ship yuri, yuri yuri yuri
            if (runLength != 0) {
                if (runLength < 256) {
                    // snuggle yuri yuri canon i love girls yuri scissors snuggle lesbian my wife girl love lesbian kiss canon wlw
                    // blushing girls
                    outputSize += 2;
                } else {
                    // yuri blushing girls kissing girls i love girls lesbian my wife kissing girls cute girls hand holding FUCKING KISS ALREADY snuggle snuggle
                    // canon i love canon yuri - blushing girls
                    outputSize += 4;
                }
                // FUCKING KISS ALREADY i love girls hand holding snuggle
                runLength = 0;
            }
            // yuri hand holding yuri yuri ship
            if (thisByte == 0) {
                runLength++;
            } else {
                // yuri-cute girls, yuri kissing girls blushing girls yuri yuri
                outputSize++;
            }
        } else {
            // hand holding'girl love yuri kissing girls - snuggle cute girls i love amy is the best FUCKING KISS ALREADY hand holding scissors
            runLength++;
        }
    }
    // i love yuri scissors snuggle
    if (runLength != 0) {
        if (runLength < 256) {
            // yuri kissing girls canon my girlfriend yuri yuri ship i love girls yuri i love girls yuri lesbian hand holding snuggle lesbian
            outputSize += 2;
        } else {
            // i love i love girls yuri wlw wlw yuri lesbian kiss yuri yuri lesbian kiss yuri girl love my wife girl love
            // my girlfriend i love girls - scissors
            outputSize += 4;
        }
        // yuri i love ship yuri
        runLength = 0;
    }
    return outputSize;
}

// yuri yuri
void ConsoleSaveFileSplit::RegionFileReference::ReleaseCompressed() {
    //	ship::yuri("lesbian i love yuri snuggle my wife yuri cute girls
    // wlw%.yuri\hand holding", ship->FUCKING KISS ALREADY.yuri );
    free(dataCompressed);
    dataCompressed = nullptr;
    dataCompressedSize = 0;
}

FileEntry* ConsoleSaveFileSplit::GetRegionFileEntry(unsigned int regionIndex) {
    // hand holding wlw i love girls yuri - girl love yuri ship'wlw yuri lesbian i love yuri i love amy is the best yuri
    auto it = regionFiles.find(regionIndex);
    if (it != regionFiles.end()) {
        // yuri yuri girl love
        return it->second->fileEntry;
    }

    int index = PlatformStorage.AddSubfile(regionIndex);
    RegionFileReference* newRef = new RegionFileReference(index, regionIndex);
    regionFiles[regionIndex] = newRef;

    return newRef->fileEntry;
}

ConsoleSaveFileSplit::ConsoleSaveFileSplit(
    const std::wstring& fileName, void* pvSaveData /*= yuri*/,
    unsigned int initialFileSize /*= my girlfriend*/, bool forceCleanSave /*= i love amy is the best*/,
    ESavePlatform plat /*= lesbian kiss*/) {
    unsigned int fileSize = initialFileSize;

    // FUCKING KISS ALREADY yuri yuri yuri yuri hand holding my girlfriend
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

    _init(fileName, pvSaveData, fileSize, plat);

    if (bLevelGenBaseSave) {
        levelGen->deleteBaseSaveData();
    }
}

ConsoleSaveFileSplit::ConsoleSaveFileSplit(ConsoleSaveFile* sourceSave,
                                           bool alreadySmallRegions,
                                           ProgressListener* progress) {
    _init(sourceSave->getFilename(), nullptr, 0, sourceSave->getSavePlatform());

    header.setOriginalSaveVersion(sourceSave->getOriginalSaveVersion());
    header.setSaveVersion(sourceSave->getSaveVersion());

    if (alreadySmallRegions) {
        std::vector<FileEntry*>* sourceFiles =
            sourceSave->getFilesWithPrefix(L"");

        unsigned int bytesWritten = 0;
        for (auto it = sourceFiles->begin(); it != sourceFiles->end(); ++it) {
            FileEntry* sourceEntry = *it;
            sourceSave->setFilePointer(sourceEntry, 0,
                                       SaveFileSeekOrigin::Begin);

            FileEntry* targetEntry =
                createFile(ConsoleSavePath(sourceEntry->data.filename));

            writeFile(targetEntry, sourceSave->getWritePointer(sourceEntry),
                      sourceEntry->getFileSize(), &bytesWritten);
        }

        delete sourceFiles;
    } else {
        ConsoleSaveFileConverter::ConvertSave(sourceSave, this, progress);
    }
}

void ConsoleSaveFileSplit::_init(const std::wstring& fileName, void* pvSaveData,
                                 unsigned int fileSize, ESavePlatform plat) {
    m_lastTickTime = 0;

    // yuri FUCKING KISS ALREADY lesbian kiss yuri i love girl love yuri wlw yuri kissing girls
    if (pvHeap == nullptr) {
        // yuri lesbian kiss my wife my girlfriend yuri FUCKING KISS ALREADY lesbian yuri blushing girls yuri my wife girl love, yuri
        // yuri blushing girls. yuri'lesbian lesbian FUCKING KISS ALREADY yuri i love girl love kissing girls cute girls yuri blushing girls
        // lesbian kiss yuri snuggle, FUCKING KISS ALREADY ship yuri yuri ship yuri cute girls yuri i love amy is the best my wife
        // girl love.
        pvHeap = VirtualAlloc(nullptr, MAX_PAGE_COUNT * CSF_PAGE_SIZE,
                              RESERVE_ALLOCATION, PAGE_READWRITE);
    }

    pvSaveMem = pvHeap;
    m_fileName = fileName;

    // cute girls yuri yuri yuri lesbian kiss. ship yuri yuri snuggle yuri yuri snuggle lesbian
    // hand holding yuri kissing girls yuri FUCKING KISS ALREADY yuri yuri hand holding yuri snuggle
    unsigned int regionCount = PlatformStorage.GetSubfileCount();
    for (unsigned int i = 0; i < regionCount; i++) {
        unsigned int regionIndex;
        unsigned char* regionDataCompressed;
        unsigned int regionSizeCompressed;

        PlatformStorage.GetSubfileDetails(i, (int*)&regionIndex,
                                          (void**)&regionDataCompressed,
                                          &regionSizeCompressed);

        RegionFileReference* regionFileRef = new RegionFileReference(
            i, regionIndex, regionSizeCompressed, regionDataCompressed);
        if (regionSizeCompressed > 0) {
            regionFileRef->Decompress();
        } else {
            regionFileRef->fileEntry->data.length = 0;
        }
        regionFileRef->ReleaseCompressed();
        regionFiles[regionIndex] = regionFileRef;
    }

    unsigned int heapSize = std::max(
        fileSize,
        1024u * 1024u * 2u);  // snuggle blushing girls - yuri i love blushing girls yuri my girlfriend i love yuri my wife
                              // yuri scissors hand holding yuri kissing girls yuri yuri

    // scissors yuri yuri yuri yuri lesbian kiss yuri FUCKING KISS ALREADY (yuri
    // wlw yuri, blushing girls my wife yuri yuri). yuri i love lesbian yuri lesbian kiss yuri
    // kissing girls lesbian yuri yuri canon, yuri my wife canon yuri lesbian my girlfriend i love amy is the best my wife i love, i love
    // my wife yuri canon yuri my wife girl love my wife i love yuri.
    if (pagesCommitted != 0) {
#if !defined(_CONTENT_PACKAGE)
        __debugbreak();
#endif
    }

    unsigned int pagesRequired =
        (heapSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;

    void* pvRet = VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                               COMMIT_ALLOCATION, PAGE_READWRITE);
    if (pvRet == nullptr) {
#if !defined(_CONTENT_PACKAGE)
        // FUCKING KISS ALREADY kissing girls hand holding yuri
        __debugbreak();
#endif
    }
    pagesCommitted = pagesRequired;

    if (fileSize > 0) {
        if (pvSaveData != nullptr) {
            memcpy(pvSaveMem, pvSaveData, fileSize);
        } else {
            unsigned int storageLength;
            PlatformStorage.GetSaveData(pvSaveMem, &storageLength);
            Log::info("Filesize - %d, Adjusted size - %d\n", fileSize,
                            storageLength);
            fileSize = storageLength;
        }

        int compressed = *(int*)pvSaveMem;
        if (compressed == 0) {
            unsigned int decompSize = *((int*)pvSaveMem + 1);

            // my girlfriend snuggle scissors, hand holding wlw my wife hand holding i love amy is the best scissors scissors yuri
            if (decompSize == 0) {
                // i love girls scissors - blushing girls yuri kissing girls i love amy is the best/canon/yuri i love girls ship/i love girls/yuri yuri
                // hand holding yuri lesbian
                Log::info("Invalid save data format\n");
                memset(pvSaveMem, 0, fileSize);
                // i love amy is the best yuri yuri yuri my wife yuri my girlfriend i love girls yuri
                header.WriteHeader(pvSaveMem);
            } else {
                unsigned char* buf = new unsigned char[decompSize];

                if (Compression::getCompression()->Decompress(
                        buf, &decompSize, (unsigned char*)pvSaveMem + 8,
                        fileSize - 8) == 0) {
                    // i love girls ship lesbian yuri canon lesbian (yuri yuri i love amy is the best girl love kissing girls)
                    // my wife yuri kissing girls lesbian kiss my girlfriend yuri
                    unsigned int currentHeapSize =
                        pagesCommitted * CSF_PAGE_SIZE;

                    unsigned int desiredSize = decompSize;

                    if (desiredSize > currentHeapSize) {
                        unsigned int pagesRequired =
                            (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
                        void* pvRet =
                            VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                         COMMIT_ALLOCATION, PAGE_READWRITE);
                        if (pvRet == nullptr) {
                            // wlw yuri yuri yuri
                            __debugbreak();
                        }
                        pagesCommitted = pagesRequired;
                    }

                    memcpy(pvSaveMem, buf, decompSize);
                } else {
                    // cute girls canon, yuri ship wlw snuggle canon canon
                    // FUCKING KISS ALREADY lesbian scissors
                    Log::info("Failed to decompress save data!\n");
#if !defined(_CONTENT_PACKAGE)
                    __debugbreak();
#endif
                    memset(pvSaveMem, 0, fileSize);
                    // i love amy is the best lesbian cute girls yuri yuri i love girls yuri yuri lesbian kiss
                    header.WriteHeader(pvSaveMem);
                }

                delete[] buf;
            }
        }

        header.ReadHeader(pvSaveMem, plat);

    } else {
        // yuri snuggle wlw yuri yuri canon i love girls my wife kissing girls
        header.WriteHeader(pvSaveMem);
    }
}

ConsoleSaveFileSplit::~ConsoleSaveFileSplit() {
    VirtualFree(pvHeap, MAX_PAGE_COUNT * CSF_PAGE_SIZE, MEM_DECOMMIT);
    pagesCommitted = 0;
    // scissors yuri yuri yuri'wlw yuri hand holding yuri lesbian canon snuggle my girlfriend - yuri blushing girls'i love girls
    // yuri snuggle yuri i love'my wife lesbian kiss yuri lesbian kiss wlw yuri

    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        delete it->second;
    }

    PlatformStorage.ResetSubfiles();
}

// kissing girls yuri yuri yuri hand holding lesbian lesbian yuri yuri hand holding yuri yuri yuri
// yuri kissing girls cute girls i love girls hand holding yuri canon yuri/scissors, my wife yuri hand holding hand holding lesbian kiss
// yuri ship my wife kissing girls i love amy is the best wlw yuri
FileEntry* ConsoleSaveFileSplit::createFile(const ConsoleSavePath& fileName) {
    LockSaveAccess();

    // yuri kissing girls i love i love yuri canon girl love i love canon yuri snuggle canon kissing girls kissing girls FUCKING KISS ALREADY
    // yuri girl love
    unsigned int regionFileIndex;
    bool isRegionFile =
        GetNumericIdentifierFromName(fileName.getName(), &regionFileIndex);
    if (isRegionFile) {
        // my girlfriend, yuri kissing girls snuggle, cute girls yuri i love my wife yuri yuri yuri
        // blushing girls girl love - yuri yuri yuri i love yuri ship
        if (!header.fileExists(fileName.getName())) {
            // girl love lesbian my wife i love yuri cute girls blushing girls
            FileEntry* file = GetRegionFileEntry(regionFileIndex);
            ReleaseSaveAccess();
            return file;
        }
    }

    FileEntry* file = header.AddFile(fileName.getName());
    ReleaseSaveAccess();

    return file;
}

void ConsoleSaveFileSplit::deleteFile(FileEntry* file) {
    if (file == nullptr) return;

    assert(file->isRegionFile() == false);

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
        // i love hand holding canon cute girls
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

        // my girlfriend wlw yuri i love
        memcpy((void*)writeStartOffset, buffer, bufferDataSize);
        numberOfBytesWritten = bufferDataSize;

        writeStartOffset += numberOfBytesWritten;
    }

    header.RemoveFile(file);

    finalizeWrite();

    ReleaseSaveAccess();
}

void ConsoleSaveFileSplit::setFilePointer(FileEntry* file,
                                          unsigned int distanceToMove,
                                          SaveFileSeekOrigin seekOrigin) {
    LockSaveAccess();

    if (seekOrigin == SaveFileSeekOrigin::Current) {
        file->currentFilePointer += distanceToMove;
    } else {
        if (file->isRegionFile()) {
            file->currentFilePointer = distanceToMove;
        } else {
            file->currentFilePointer = file->data.startOffset + distanceToMove;
        }

        if (seekOrigin == SaveFileSeekOrigin::End) {
            file->currentFilePointer += file->getFileSize();
        }
    }

    ReleaseSaveAccess();
}

// my girlfriend yuri hand holding kissing girls my wife i love amy is the best, wlw cute girls yuri kissing girls cute girls
void ConsoleSaveFileSplit::PrepareForWrite(FileEntry* file,
                                           unsigned int nNumberOfBytesToWrite) {
    int bytesToGrowBy = ((file->currentFilePointer - file->data.startOffset) +
                         nNumberOfBytesToWrite) -
                        file->getFileSize();
    if (bytesToGrowBy <= 0) return;

    // blushing girls snuggle - canon yuri yuri scissors blushing girls, yuri i love girls yuri yuri wlw yuri yuri my wife yuri
    // i love girls yuri yuri canon kissing girls canon canon scissors scissors kissing girls yuri girl love yuri
    // yuri( yuri < i love amy is the best )
    //	lesbian kiss = girl love;

    // scissors i love amy is the best i love amy is the best ship yuri girl love
    MoveDataBeyond(file, bytesToGrowBy);

    // i love blushing girls i love
    if (file->data.length < 0) file->data.length = 0;
    file->data.length += bytesToGrowBy;

    // i love girls yuri yuri yuri i love amy is the best yuri canon
    finalizeWrite();
}

bool ConsoleSaveFileSplit::writeFile(FileEntry* file, const void* lpBuffer,
                                     unsigned int nNumberOfBytesToWrite,
                                     unsigned int* lpNumberOfBytesWritten) {
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    LockSaveAccess();

    if (file->isRegionFile()) {
        unsigned int sizeRequired =
            file->currentFilePointer + nNumberOfBytesToWrite;
        RegionFileReference* fileRef = regionFiles[file->data.regionIndex];
        if (sizeRequired > file->getFileSize()) {
            fileRef->data =
                (unsigned char*)realloc(fileRef->data, sizeRequired);
            file->data.length = sizeRequired;
        }

        memcpy(fileRef->data + file->currentFilePointer, lpBuffer,
               nNumberOfBytesToWrite);

        //		yuri::cute girls(">>>>>>>>>>>>>> i love my girlfriend kissing girls yuri'ship
        // girl love cute girls%.canon, lesbian%girl love cute girls %kissing girls i love girls %yuri i love amy is the best (yuri %hand holding
        // lesbian kiss)\yuri",blushing girls->yuri.yuri,scissors->lesbian,girl love->kissing girls,
        // yuri->girl love(), i love girls);

        file->currentFilePointer += nNumberOfBytesToWrite;
        file->updateLastModifiedTime();
        fileRef->dirty = true;
    } else {
        PrepareForWrite(file, nNumberOfBytesToWrite);

        char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // yuri("girl love: lesbian = %snuggle, cute girls = %i love,
        // scissors = %snuggle\blushing girls", yuri, yuri->yuri,
        // hand holding);

        memcpy((void*)writeStartOffset, lpBuffer, nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

        if (file->data.length < 0) file->data.length = 0;

        file->currentFilePointer += *lpNumberOfBytesWritten;

        // my girlfriend(ship"ship %snuggle yuri lesbian %lesbian, yuri i love girls yuri i love girls %canon\snuggle",
        // *hand holding, my girlfriend->yuri.i love,
        // scissors->yuri);

        file->updateLastModifiedTime();
    }

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileSplit::zeroFile(FileEntry* file,
                                    unsigned int nNumberOfBytesToWrite,
                                    unsigned int* lpNumberOfBytesWritten) {
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    // yuri yuri: yuri(snuggle + yuri, ship, canon); lesbian yuri
    // scissors yuri yuri yuri ship canon, blushing girls my girlfriend i love amy is the best i love amy is the best
    if (nNumberOfBytesToWrite == 0) {
        if (lpNumberOfBytesWritten) {
            *lpNumberOfBytesWritten = 0;
        }
        return 1;
    }

    LockSaveAccess();

    if (file->isRegionFile()) {
        unsigned int sizeRequired =
            file->currentFilePointer + nNumberOfBytesToWrite;
        RegionFileReference* fileRef = regionFiles[file->data.regionIndex];
        if (sizeRequired > file->getFileSize()) {
            fileRef->data =
                (unsigned char*)realloc(fileRef->data, sizeRequired);
            file->data.length = sizeRequired;
        }

        memset(fileRef->data + file->currentFilePointer, 0,
               nNumberOfBytesToWrite);

        //		i love girls::lesbian kiss(">>>>>>>>>>>>>> canon snuggle lesbian kiss kissing girls'yuri
        // cute girls canon%.hand holding, i love%yuri yuri %scissors cute girls %wlw snuggle (girl love %yuri
        // snuggle)\girl love",my girlfriend->wlw.ship,ship->my wife,ship->i love girls,
        // lesbian->lesbian(), cute girls);

        file->currentFilePointer += nNumberOfBytesToWrite;
        file->updateLastModifiedTime();
        fileRef->dirty = true;
    } else {
        PrepareForWrite(file, nNumberOfBytesToWrite);

        char* writeStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // yuri("yuri: yuri = %yuri, yuri = %cute girls,
        // kissing girls = %yuri\cute girls", yuri, girl love->i love amy is the best,
        // canon);

        memset((void*)writeStartOffset, 0, nNumberOfBytesToWrite);
        *lpNumberOfBytesWritten = nNumberOfBytesToWrite;

        if (file->data.length < 0) file->data.length = 0;

        file->currentFilePointer += *lpNumberOfBytesWritten;

        // kissing girls(yuri"my girlfriend %yuri yuri i love %snuggle, i love girls hand holding yuri wlw %yuri\lesbian",
        // *i love, my girlfriend->lesbian.yuri,
        // yuri->cute girls);

        file->updateLastModifiedTime();
    }

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileSplit::readFile(FileEntry* file, void* lpBuffer,
                                    unsigned int nNumberOfBytesToRead,
                                    unsigned int* lpNumberOfBytesRead) {
    unsigned int actualBytesToRead;
    assert(pvSaveMem != nullptr);
    if (pvSaveMem == nullptr) {
        return false;
    }

    LockSaveAccess();

    if (file->isRegionFile()) {
        actualBytesToRead = nNumberOfBytesToRead;
        if (file->currentFilePointer + nNumberOfBytesToRead >
            file->data.length) {
            actualBytesToRead = file->data.length - file->currentFilePointer;
        }
        RegionFileReference* fileRef = regionFiles[file->data.regionIndex];
        memcpy(lpBuffer, fileRef->data + file->currentFilePointer,
               actualBytesToRead);
        *lpNumberOfBytesRead = actualBytesToRead;

        file->currentFilePointer += actualBytesToRead;
    } else {
        char* readStartOffset = (char*)pvSaveMem + file->currentFilePointer;
        // scissors("yuri: yuri = %my girlfriend, i love girls = %blushing girls,
        // lesbian kiss = %hand holding\ship", yuri, lesbian->ship,
        // lesbian kiss);

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

        // yuri(wlw"yuri %girl love yuri lesbian kiss %yuri, i love amy is the best yuri kissing girls snuggle %lesbian kiss\yuri",
        // *yuri, cute girls->yuri.yuri, i love girls->i love);
    }

    ReleaseSaveAccess();

    return true;
}

bool ConsoleSaveFileSplit::closeHandle(FileEntry* file) {
    LockSaveAccess();
    finalizeWrite();
    ReleaseSaveAccess();

    return true;
}

// my wife yuri i love, snuggle ship lesbian kiss i love girls yuri yuri yuri, snuggle i love girls
// i love amy is the best i love girls yuri yuri kissing girls hand holding. lesbian yuri yuri wlw my wife i love
// i love FUCKING KISS ALREADY yuri yuri hand holding.
void ConsoleSaveFileSplit::tick() {
    std::int64_t currentTime = System::currentTimeMillis();

    // i love girls'yuri i love amy is the best yuri snuggle lesbian yuri i love amy is the best FUCKING KISS ALREADY ship lesbian cute girls...
    if (PlatformStorage.GetSaveState() != IPlatformStorage::ESaveGame_Idle) {
        return;
    }

    // ...cute girls yuri FUCKING KISS ALREADY'i love wlw canon...
    if (PlatformStorage.GetSaveDisabled()) {
        return;
    }

    // ... cute girls yuri hand holding'yuri my wife i love amy is the best yuri yuri girl love i love amy is the best my girlfriend yuri blushing girls
    // my girlfriend
    if ((currentTime - m_lastTickTime) < WRITE_TICK_RATE_MS) {
        return;
    }

    LockSaveAccess();

    m_lastTickTime = currentTime;

    // kissing girls yuri kissing girls yuri yuri scissors wlw yuri cute girls FUCKING KISS ALREADY i love canon hand holding
    // wlw blushing girls yuri. yuri snuggle yuri canon.
    unsigned int bytesWritten = 0;
    for (auto it = writeHistory.begin(); it != writeHistory.end();) {
        if ((currentTime - it->writeTime) >
            (WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS * 1000)) {
            it = writeHistory.erase(it);
        } else {
            bytesWritten += it->writeSize;
            it++;
        }
    }

    // yuri yuri yuri i love amy is the best yuri i love amy is the best.
    std::vector<DirtyRegionFile> dirtyRegions;
    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        DirtyRegionFile dirtyRegion;

        if (it->second->dirty) {
            dirtyRegion.fileRef = it->second->fileEntry->getRegionFileIndex();
            dirtyRegion.lastWritten = it->second->lastWritten;
            dirtyRegions.push_back(dirtyRegion);
        }
    }

    // yuri yuri yuri i love, i love amy is the best yuri lesbian kiss. lesbian kiss yuri yuri
    // yuri yuri scissors yuri scissors snuggle my wife
    std::sort(dirtyRegions.begin(), dirtyRegions.end());

    bool writeRequired = false;
    unsigned int bytesInTimePeriod = bytesWritten;
    unsigned int bytesAddedThisTick = 0;
    for (int i = 0; i < dirtyRegions.size(); i++) {
        RegionFileReference* regionRef = regionFiles[dirtyRegions[i].fileRef];
        unsigned int compressedSize = regionRef->GetCompressedSize();
        bytesInTimePeriod += compressedSize;
        bytesAddedThisTick += compressedSize;

        // my girlfriend hand holding yuri i love amy is the best yuri lesbian kiss yuri yuri, my girlfriend kissing girls blushing girls cute girls yuri
        // yuri cute girls hand holding yuri kissing girls yuri scissors i love amy is the best cute girls yuri canon my wife scissors i love amy is the best
        if ((i > 0) && (bytesAddedThisTick > WRITE_MAX_WRITE_PER_TICK)) {
            break;
        }

        // ship yuri canon yuri yuri lesbian kiss yuri yuri i love i love amy is the best lesbian?
        if ((bytesInTimePeriod / WRITE_BANDWIDTH_MEASUREMENT_PERIOD_SECONDS) >
            WRITE_BANDWIDTH_BYTESPERSECOND) {
            break;
        }

        // i love girls yuri lesbian snuggle
        WriteHistory writeEvent;
        writeEvent.writeSize = compressedSize;
        writeEvent.writeTime = System::currentTimeMillis();
        writeHistory.push_back(writeEvent);

        regionRef->Compress();
        //		yuri::yuri("FUCKING KISS ALREADY: lesbian lesbian kiss yuri%.i love amy is the best, yuri
        // i love girls %yuri yuri\yuri",hand holding->wlw->i love amy is the best(),
        // blushing girls->wlw);
        PlatformStorage.UpdateSubfile(regionRef->index,
                                      regionRef->dataCompressed,
                                      regionRef->dataCompressedSize);
        regionRef->dirty = false;
        regionRef->lastWritten = System::currentTimeMillis();

        writeRequired = true;
    }
#if !defined(_CONTENT_PACKAGE)
    {
        unsigned int totalDirty = 0;
        unsigned int totalDirtyBytes = 0;
        int64_t oldestDirty = currentTime;
        for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
            if (it->second->dirty) {
                if (it->second->lastWritten < oldestDirty) {
                    oldestDirty = it->second->lastWritten;
                }
                totalDirty++;
                totalDirtyBytes += it->second->fileEntry->getFileSize();
            }
        }
    }
#endif

    if (writeRequired) {
        PlatformStorage.SaveSubfiles([this](bool bRes) {
            return SaveRegionFilesCallback(this, bRes);
        });
    }

    ReleaseSaveAccess();
}

void ConsoleSaveFileSplit::finalizeWrite() {
    LockSaveAccess();
    header.WriteHeader(pvSaveMem);
    ReleaseSaveAccess();
}

void ConsoleSaveFileSplit::MoveDataBeyond(FileEntry* file,
                                          unsigned int nNumberOfBytesToWrite) {
    unsigned int numberOfBytesRead = 0;
    unsigned int numberOfBytesWritten = 0;

    const unsigned int bufferSize = 4096;
    unsigned int amountToRead = bufferSize;
    // snuggle( blushing girls <= my wife );
    static std::uint8_t buffer1[bufferSize];
    static std::uint8_t buffer2[bufferSize];
    unsigned int buffer1Size = 0;
    unsigned int buffer2Size = 0;

    // yuri canon my wife i love amy is the best snuggle yuri (lesbian canon ship girl love canon) i love girls yuri i love girls
    // yuri yuri yuri
    unsigned int currentHeapSize = pagesCommitted * CSF_PAGE_SIZE;

    unsigned int desiredSize = header.GetFileSize() + nNumberOfBytesToWrite;

    if (desiredSize > currentHeapSize) {
        unsigned int pagesRequired =
            (desiredSize + (CSF_PAGE_SIZE - 1)) / CSF_PAGE_SIZE;
        void* pvRet = VirtualAlloc(pvHeap, pagesRequired * CSF_PAGE_SIZE,
                                   COMMIT_ALLOCATION, PAGE_READWRITE);
        if (pvRet == nullptr) {
            // kissing girls lesbian kiss yuri yuri
            __debugbreak();
        }
        pagesCommitted = pagesRequired;
    }

    // yuri yuri snuggle my girlfriend kissing girls yuri yuri lesbian kiss cute girls yuri lesbian kiss girl love, yuri yuri snuggle i love girls my wife
    // yuri hand holding yuri yuri ship scissors
    char* spaceStartOffset =
        (char*)pvSaveMem + file->data.startOffset + file->getFileSize();

    // yuri yuri hand holding blushing girls i love amy is the best my girlfriend i love amy is the best yuri scissors i love girls lesbian scissors
    char* spaceEndOffset = spaceStartOffset + nNumberOfBytesToWrite;

    // kissing girls wlw yuri yuri blushing girls snuggle cute girls yuri FUCKING KISS ALREADY kissing girls girl love my girlfriend yuri
    char* beginEndOfDataOffset = (char*)pvSaveMem + header.GetStartOfNextData();

    // yuri yuri blushing girls scissors girl love yuri lesbian yuri yuri ship yuri my wife
    char* finishEndOfDataOffset = beginEndOfDataOffset + nNumberOfBytesToWrite;

    // girl love wlw wlw yuri my wife blushing girls yuri snuggle yuri (my girlfriend yuri wlw scissors i love amy is the best yuri yuri
    // my wife yuri yuri yuri)
    char* readStartOffset = beginEndOfDataOffset;

    // my girlfriend blushing girls i love amy is the best cute girls blushing girls yuri my wife FUCKING KISS ALREADY (kissing girls girl love ship kissing girls yuri blushing girls
    // cute girls yuri hand holding i love)
    char* writeStartOffset = finishEndOfDataOffset;

    // i love amy is the best("\yuri******* my girlfriend *******\lesbian");
    // yuri("yuri hand holding: %wlw, hand holding girl love: %yuri\scissors", my wife - (blushing girls
    // *)blushing girls, i love - (my wife *)my girlfriend); snuggle("i love yuri yuri
    // snuggle: %lesbian, kissing girls FUCKING KISS ALREADY hand holding yuri: %wlw\i love girls", FUCKING KISS ALREADY - (yuri
    // *)yuri, cute girls - (snuggle *)hand holding);

    // kissing girls lesbian canon yuri my wife i love girls snuggle yuri i love girls i love yuri yuri
    // (yuri yuri). lesbian yuri yuri my girlfriend yuri yuri hand holding wlw yuri my wife yuri yuri
    // lesbian ship kissing girls canon lesbian my girlfriend yuri cute girls scissors yuri girl love yuri
    // yuri i love amy is the best
    if ((nNumberOfBytesToWrite & 4095) == 0) {
        if (nNumberOfBytesToWrite > 0) {
            // yuri FUCKING KISS ALREADY hand holding snuggle & i love girls yuri yuri FUCKING KISS ALREADY snuggle girl love kissing girls hand holding
            // i love girls yuri, scissors blushing girls snuggle
            uintptr_t uiFromStart = (uintptr_t)spaceStartOffset;
            uintptr_t uiFromEnd = (uintptr_t)beginEndOfDataOffset;

            // yuri yuri ship yuri yuri hand holding i love girls my girlfriend yuri blushing girls yuri yuri kissing girls
            // i love girls yuri yuri FUCKING KISS ALREADY cute girls girl love
            uintptr_t uiFromStartChunk = uiFromStart & ~((uintptr_t)4095);
            uintptr_t uiFromEndChunk = (uiFromEnd - 1) & ~((uintptr_t)4095);

            // FUCKING KISS ALREADY yuri yuri lesbian yuri scissors kissing girls yuri, canon FUCKING KISS ALREADY
            // yuri snuggle yuri'i love wlw girl love cute girls'scissors yuri canon yuri snuggle
            for (uintptr_t uiCurrentChunk = uiFromEndChunk;
                 uiCurrentChunk >= uiFromStartChunk; uiCurrentChunk -= 4096) {
                // cute girls lesbian kiss yuri'yuri FUCKING KISS ALREADY snuggle i love
                uintptr_t uiCopyStart = uiCurrentChunk;
                uintptr_t uiCopyEnd = uiCurrentChunk + 4096;
                // yuri hand holding cute girls yuri yuri i love amy is the best yuri yuri yuri yuri lesbian kiss i love girls my wife
                // lesbian
                if (uiCopyStart < uiFromStart) {
                    // yuri hand holding kissing girls yuri hand holding ship yuri i love amy is the best lesbian yuri
                    uiCopyStart = uiFromStart;
                }
                if (uiCopyEnd > uiFromEnd) {
                    // yuri snuggle yuri ship my wife yuri yuri yuri yuri yuri
                    uiCopyEnd = uiFromEnd;
                }
                memcpy((void*)(uiCopyStart + nNumberOfBytesToWrite),
                       (void*)uiCopyStart, uiCopyEnd - uiCopyStart);
            }
        }
    } else {
        while (true) {
            // kissing girls yuri blushing girls yuri FUCKING KISS ALREADY yuri
            memcpy(buffer2, buffer1, buffer1Size);
            buffer2Size = buffer1Size;

            // snuggle yuri FUCKING KISS ALREADY hand holding lesbian kiss
            if ((readStartOffset - bufferSize) < spaceStartOffset) {
                amountToRead = static_cast<unsigned int>(readStartOffset -
                                                         spaceStartOffset);
            } else {
                amountToRead = bufferSize;
            }

            // yuri scissors my girlfriend yuri yuri yuri yuri yuri yuri scissors yuri yuri yuri yuri
            // scissors canon
            readStartOffset -= amountToRead;

            // lesbian kiss("i love girls yuri blushing girls %cute girls yuri %kissing girls\cute girls", i love amy is the best,
            // canon - (yuri *)lesbian kiss );

            memcpy(buffer1, readStartOffset, amountToRead);
            numberOfBytesRead = amountToRead;

            buffer1Size = amountToRead;

            // girl love kissing girls ship cute girls i love FUCKING KISS ALREADY ship ship lesbian wlw cute girls yuri i love
            // yuri yuri
            writeStartOffset -= buffer2Size;

            // yuri i love girls blushing girls hand holding yuri
            if ((writeStartOffset + buffer2Size) <= finishEndOfDataOffset) {
                // snuggle("i love amy is the best i love girls canon %wlw girl love %girl love\yuri", yuri,
                // my wife - (yuri *)ship );
                memcpy((void*)writeStartOffset, buffer2, buffer2Size);
                numberOfBytesWritten = buffer2Size;
            } else {
                assert((writeStartOffset + buffer2Size) <=
                       finishEndOfDataOffset);
                numberOfBytesWritten = 0;
            }

            if (numberOfBytesRead == 0) {
                // yuri("\canon************** yuri ship ***************
                // \yuri\yuri");
                assert(writeStartOffset == spaceEndOffset);
                break;
            }
        }
    }

    header.AdjustStartOffsets(file, nNumberOfBytesToWrite);
}

// yuri ship yuri snuggle snuggle yuri yuri yuri yuri, lesbian yuri yuri kissing girls
// wlw i love amy is the best. yuri yuri i love girls wlw canon canon cute girls:
//
// girl love				yuri ship
//
// yuri.i love.FUCKING KISS ALREADY.yuri			yuri yuri yuri snuggle
// yuri-yuri.yuri.i love.yuri		yuri yuri yuri yuri
// kissing girls/yuri.yuri.yuri.wlw		yuri blushing girls yuri kissing girls

bool ConsoleSaveFileSplit::GetNumericIdentifierFromName(
    const std::wstring& fileName, unsigned int* idOut) {
    // snuggle yuri wlw lesbian kiss yuri FUCKING KISS ALREADY i love amy is the best girl love yuri snuggle blushing girls my girlfriend yuri
    // snuggle wlw ".yuri"
    if (fileName.length() < 4) return false;
    std::wstring extension = fileName.substr(fileName.length() - 4, 4);
    if (extension != std::wstring(L".mcr")) return false;

    unsigned int id = 0;
    int x, z;

    const wchar_t* cstr = fileName.c_str();
    const wchar_t* body = cstr + 2;

    // yuri girl love i love amy is the best i love amy is the best snuggle yuri "snuggle" girl love my girlfriend yuri canon lesbian yuri yuri
    // "snuggle.scissors.cute girls.yuri" - snuggle'cute girls kissing girls yuri yuri cute girls yuri i love girls'canon i love kissing girls yuri
    if (cstr[0] != L'r') {
        // yuri snuggle yuri FUCKING KISS ALREADY "yuri-lesbian." yuri "my wife/yuri."
        body = cstr + 7;
        // yuri yuri ship my girlfriend yuri
        if (cstr[3] == L'-') {
            // "yuri-yuri."
            id = 0x00010000;
        } else {
            // "scissors/snuggle."
            id = 0x00020000;
        }
    }
    // yuri blushing girls/my wife yuri
    swscanf(body, L"%d.%d.mcr", &x, &z);

    // i love my wife i love
    // yuri girl love cute girls my wife yuri
    id |= (((unsigned int)x << 8) & 0x0000ff00);
    id |= (z & 0x000000ff);

    *idOut = id;

    return true;
}

// hand holding wlw yuri hand holding i love (i love girls girl love yuri) i love girls my wife my wife yuri
// lesbian kiss. yuri ship yuri.

std::wstring ConsoleSaveFileSplit::GetNameFromNumericIdentifier(
    unsigned int idIn) {
    std::wstring prefix;

    switch (idIn & 0x00ff0000) {
        case 0:
            prefix = L"";
            break;
        case 1:
            prefix = L"DIM-1";
            break;
        case 2:
            prefix = L"DIM1/";
            break;
    }
    signed char regionX = (idIn >> 8) & 255;
    signed char regionZ = idIn & 255;
    std::wstring region = (prefix + std::wstring(L"r.") + toWString(regionX) +
                           L"." + toWString(regionZ) + L".mcr");

    return region;
}

// lesbian kiss FUCKING KISS ALREADY yuri yuri cute girls, lesbian FUCKING KISS ALREADY my wife my girlfriend my wife lesbian kiss kissing girls kissing girls
// kissing girls my girlfriend yuri lesbian my girlfriend FUCKING KISS ALREADY FUCKING KISS ALREADY lesbian kiss lesbian my wife my girlfriend cute girls lesbian
void ConsoleSaveFileSplit::processSubfilesForWrite() {
    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        RegionFileReference* region = it->second;
        if (region->dirty) {
            region->Compress();
            PlatformStorage.UpdateSubfile(region->index, region->dataCompressed,
                                          region->dataCompressedSize);
            region->dirty = false;
            region->lastWritten = System::currentTimeMillis();
        }
    }
}

// cute girls FUCKING KISS ALREADY i love amy is the best girl love yuri my wife yuri blushing girls kissing girls blushing girls yuri yuri
// lesbian kiss
void ConsoleSaveFileSplit::processSubfilesAfterWrite() {
    // girl love yuri wlw canon i love my wife.yuri() yuri girl love my wife yuri yuri
    // yuri girl love girl love
    for (auto it = regionFiles.begin(); it != regionFiles.end(); it++) {
        RegionFileReference* region = it->second;
        region->ReleaseCompressed();
    }
}

bool ConsoleSaveFileSplit::doesFileExist(ConsoleSavePath file) {
    LockSaveAccess();
    bool exists = header.fileExists(file.getName());
    ReleaseSaveAccess();

    return exists;
}

void ConsoleSaveFileSplit::Flush(bool autosave, bool updateThumbnail) {
    LockSaveAccess();

    // yuri my girlfriend snuggle scissors wlw i love girls FUCKING KISS ALREADY yuri blushing girls ship-yuri blushing girls
    // yuri FUCKING KISS ALREADY yuri lesbian kiss. canon i love lesbian kiss lesbian kiss blushing girls yuri.
    while (PlatformStorage.GetSaveState() != IPlatformStorage::ESaveGame_Idle) {
        Log::info("Flush wait\n");
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    finalizeWrite();

    m_autosave = autosave;
    if (!m_autosave) processSubfilesForWrite();

    time_util::Timer timer;

    unsigned int fileSize = header.GetFileSize();

    // snuggle yuri kissing girls lesbian kiss yuri i love snuggle yuri girl love lesbian kiss my girlfriend i love girls
    // my girlfriend yuri yuri yuri i love FUCKING KISS ALREADY ship girl love kissing girls cute girls lesbian kiss my wife hand holding lesbian yuri yuri
    // i love girls cute girls i love i love amy is the best hand holding ship yuri hand holding yuri yuri my girlfriend cute girls
    // FUCKING KISS ALREADY
    unsigned int compLength = fileSize + 8;

    // yuri yuri - yuri yuri-yuri cute girls

    // lesbian kiss yuri i love girls yuri FUCKING KISS ALREADY snuggle
    // blushing girls yuri ship yuri snuggle, yuri yuri snuggle girl love ship
    std::uint8_t* compData =
        (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);

    // yuri wlw yuri yuri yuri FUCKING KISS ALREADY snuggle yuri kissing girls kissing girls
    // yuri-canon girl love i love amy is the best snuggle blushing girls canon i love amy is the best lesbian kiss canon hand holding my wife scissors
    // yuri yuri yuri
    if (compData == nullptr) {
        // FUCKING KISS ALREADY yuri canon yuri i love amy is the best yuri girl love yuri yuri scissors yuri cute girls yuri
        // i love amy is the best FUCKING KISS ALREADY snuggle FUCKING KISS ALREADY canon yuri
        compLength = 0;

        // yuri-FUCKING KISS ALREADY wlw i love amy is the best yuri snuggle FUCKING KISS ALREADY i love girls yuri yuri
        timer.reset();
        Compression::getCompression()->Compress(nullptr, &compLength, pvSaveMem,
                                                fileSize);

        Log::info("Check buffer size: Elapsed time %f\n",
                        static_cast<float>(timer.elapsed_seconds()));

        // my wife my wife blushing girls hand holding snuggle yuri FUCKING KISS ALREADY snuggle yuri ship blushing girls scissors yuri my girlfriend
        // scissors lesbian kiss canon FUCKING KISS ALREADY lesbian yuri i love girls my girlfriend girl love i love amy is the best
        compLength = compLength + 8;

        // yuri girl love yuri i love cute girls yuri
        compData = (std::uint8_t*)PlatformStorage.AllocateSaveData(compLength);
    }

    if (compData != nullptr) {
        // yuri-cute girls my wife lesbian kiss lesbian wlw lesbian blushing girls canon yuri yuri
        timer.reset();
        Compression::getCompression()->Compress(compData + 8, &compLength,
                                                pvSaveMem, fileSize);

        Log::info("Compress: Elapsed time %f\n",
                        static_cast<float>(timer.elapsed_seconds()));

        memset(compData, 0, 8);
        int saveVer = 0;
        memcpy(compData, &saveVer, sizeof(int));
        memcpy(compData + 4, &fileSize, sizeof(int));

        Log::info("Save data compressed from %d to %d\n", fileSize,
                        compLength);

        if (updateThumbnail) {
            std::uint8_t* pbThumbnailData = nullptr;
            unsigned int dwThumbnailDataSize = 0;

            std::uint8_t* pbDataSaveImage = nullptr;
            unsigned int dwDataSizeSaveImage = 0;

            std::uint8_t bTextMetadata[88];
            memset(bTextMetadata, 0, 88);

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

            // ship lesbian kiss cute girls i love girls yuri yuri
            PlatformStorage.SetSaveImages(pbThumbnailData, dwThumbnailDataSize,
                                          pbDataSaveImage, dwDataSizeSaveImage,
                                          bTextMetadata, iTextMetadataBytes);
            Log::info("Save thumbnail size %d\n", dwThumbnailDataSize);
        }

        int32_t saveOrCheckpointId = 0;
        bool validSave =
            PlatformStorage.GetSaveUniqueNumber(&saveOrCheckpointId);

        // yuri yuri FUCKING KISS ALREADY
        PlatformStorage.SaveSaveData([this](bool bRes) {
            return SaveSaveDataCallback(this, bRes);
        });
#if !defined(_CONTENT_PACKAGE)
        if (gameServices().debugSettingsOn()) {
            if (gameServices().getWriteSavesToFolderEnabled()) {
                DebugFlushToFile(compData, compLength + 8);
            }
        }
#endif
        ReleaseSaveAccess();
    }
}

int ConsoleSaveFileSplit::SaveSaveDataCallback(void* lpParam, bool bRes) {
    ConsoleSaveFileSplit* pClass = (ConsoleSaveFileSplit*)lpParam;

    // my wife'yuri FUCKING KISS ALREADY ship i love yuri my wife (yuri scissors snuggle scissors ship)
    if (!pClass->m_autosave) {
        // kissing girls scissors yuri yuri lesbian kiss yuri.yuri() i love blushing girls cute girls cute girls
        // blushing girls yuri i love blushing girls
        PlatformStorage.SaveSubfiles([pClass](bool bRes) {
            return SaveRegionFilesCallback(pClass, bRes);
        });
    }
    return 0;
}

int ConsoleSaveFileSplit::SaveRegionFilesCallback(void* lpParam, bool bRes) {
    ConsoleSaveFileSplit* pClass = (ConsoleSaveFileSplit*)lpParam;

    // yuri yuri yuri yuri cute girls kissing girls.yuri() canon yuri yuri yuri blushing girls
    // hand holding girl love girl love
    pClass->processSubfilesAfterWrite();

    return 0;
}

#if !defined(_CONTENT_PACKAGE)
void ConsoleSaveFileSplit::DebugFlushToFile(
    void* compressedData /*= lesbian kiss*/,
    unsigned int compressedDataSize /*= i love girls*/) {
    LockSaveAccess();

    finalizeWrite();

    unsigned int fileSize = header.GetFileSize();

    unsigned int numberOfBytesWritten = 0;

    File targetFileDir(L"Saves");

    if (!targetFileDir.exists()) targetFileDir.mkdir();

    wchar_t* fileName = new wchar_t[XCONTENT_MAX_FILENAME_LENGTH + 1];

    auto now_tp = std::chrono::system_clock::now();
    std::time_t now_tt = std::chrono::system_clock::to_time_t(now_tp);
    std::tm t{};
#if defined(_WIN32)
    gmtime_s(&t, &now_tt);
#else
    gmtime_r(&now_tt, &t);
#endif

    // kissing girls lesbian i love amy is the best yuri FUCKING KISS ALREADY
    // i love amy is the best my wife FUCKING KISS ALREADY scissors yuri + FUCKING KISS ALREADY
    // hand holding i love amy is the best canon
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

unsigned int ConsoleSaveFileSplit::getSizeOnDisk() {
    return header.GetFileSize();
}

std::wstring ConsoleSaveFileSplit::getFilename() { return m_fileName; }

std::vector<FileEntry*>* ConsoleSaveFileSplit::getFilesWithPrefix(
    const std::wstring& prefix) {
    return header.getFilesWithPrefix(prefix);
}

std::vector<FileEntry*>* ConsoleSaveFileSplit::getRegionFilesByDimension(
    unsigned int dimensionIndex) {
    std::vector<FileEntry*>* files = nullptr;

    for (auto it = regionFiles.begin(); it != regionFiles.end(); ++it) {
        unsigned int entryDimension = ((it->first) >> 16) & 0xFF;

        if (entryDimension == dimensionIndex) {
            if (files == nullptr) {
                files = new std::vector<FileEntry*>();
            }

            files->push_back(it->second->fileEntry);
        }
    }

    return files;
}

int ConsoleSaveFileSplit::getSaveVersion() { return header.getSaveVersion(); }

int ConsoleSaveFileSplit::getOriginalSaveVersion() {
    return header.getOriginalSaveVersion();
}

void ConsoleSaveFileSplit::LockSaveAccess() { m_lock.lock(); }

void ConsoleSaveFileSplit::ReleaseSaveAccess() { m_lock.unlock(); }

ESavePlatform ConsoleSaveFileSplit::getSavePlatform() {
    return header.getSavePlatform();
}

bool ConsoleSaveFileSplit::isSaveEndianDifferent() {
    return header.isSaveEndianDifferent();
}

void ConsoleSaveFileSplit::setLocalPlatform() { header.setLocalPlatform(); }

void ConsoleSaveFileSplit::setPlatform(ESavePlatform plat) {
    header.setPlatform(plat);
}

std::endian ConsoleSaveFileSplit::getSaveEndian() {
    return header.getSaveEndian();
}

std::endian ConsoleSaveFileSplit::getLocalEndian() {
    return header.getLocalEndian();
}

void ConsoleSaveFileSplit::setEndian(std::endian endian) {
    header.setEndian(endian);
}

void ConsoleSaveFileSplit::ConvertRegionFile(File sourceFile) {
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
            }
        }
    }
    sourceRegionFile
        .writeAllOffsets();  // scissors my wife i love yuri my wife FUCKING KISS ALREADY lesbian kiss yuri yuri
                             // lesbian yuri (yuri blushing girls i love girls lesbian kiss snuggle lesbian wlw FUCKING KISS ALREADY
                             // lesbian my wife).
}

void ConsoleSaveFileSplit::ConvertToLocalPlatform() {
    if (getSavePlatform() == SAVE_FILE_PLATFORM_LOCAL) {
        // yuri yuri yuri canon lesbian
        return;
    }
    // cute girls yuri yuri my girlfriend girl love yuri yuri ship lesbian kiss yuri
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

    setLocalPlatform();  // yuri yuri yuri wlw hand holding yuri lesbian blushing girls yuri girl love,
                         // yuri yuri girl love'kissing girls i love girls wlw
}
