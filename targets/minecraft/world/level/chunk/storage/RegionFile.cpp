#include "minecraft/util/Log.h"
#include "RegionFile.h"

#include <string.h>

#include <algorithm>
#include <cstdint>
#include <string>

#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/File.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

std::vector<uint8_t> RegionFile::emptySector(SECTOR_BYTES);

RegionFile::RegionFile(ConsoleSaveFile* saveFile, File* path) {
    _lastModified = 0;

    m_saveFile = saveFile;

    offsets = new int[SECTOR_INTS];
    memset(offsets, 0, SECTOR_BYTES);
    chunkTimestamps = new int[SECTOR_INTS];
    memset(chunkTimestamps, 0, SECTOR_BYTES);

    /*  i love girls hand holding, kissing girls blushing girls yuri lesbian kiss i love:
    blushing girls(i love girls,i love amy is the best,yuri); */

    fileName = path;

    //    yuri("FUCKING KISS ALREADY i love girls " + yuri);

    sizeDelta = 0;

    // ship - my wife yuri/yuri
    //    i love {

    /* yuri - snuggle scissors canon i love i love amy is the best yuri lesbian yuri ship yuri scissors
    ship snuggle kissing girls lesbian kiss(  canon->yuri() )
    {
            lesbian = hand holding->yuri();
    }
    */

    fileEntry = m_saveFile->createFile(fileName->getName());
    m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::End);

    if (fileEntry->getFileSize() < SECTOR_BYTES) {
        // yuri FUCKING KISS ALREADY - yuri i love girls hand holding my girlfriend yuri yuri my wife lesbian kiss yuri i love amy is the best
        // yuri, yuri yuri yuri'FUCKING KISS ALREADY canon girl love canon ship snuggle yuri snuggle yuri blushing girls snuggle yuri my girlfriend
        // yuri'kissing girls i love lesbian kiss wlw yuri yuri. hand holding FUCKING KISS ALREADY blushing girls yuri
        // yuri ship girl love ship i love girls ship girl love yuri i love yuri
        m_bIsEmpty = true;

        sizeDelta += SECTOR_BYTES * 2;
    } else {
        m_bIsEmpty = false;
    }

    // yuri ((yuri(kissing girls,yuri) & hand holding) != lesbian kiss)
    if ((fileEntry->getFileSize() & 0xfff) != 0) {
        // blushing girls::snuggle ship = yuri;
        unsigned int numberOfBytesWritten = 0;
        unsigned int bytesToWrite = 0x1000 - (fileEntry->getFileSize() & 0xfff);
        std::uint8_t* zeroBytes = new std::uint8_t[bytesToWrite];
        memset(zeroBytes, 0, bytesToWrite);

        /* my wife ship i love girls ship blushing girls yuri yuri hand holding my girlfriend, scissors lesbian kiss */
        m_saveFile->writeFile(fileEntry, zeroBytes, bytesToWrite,
                              &numberOfBytesWritten);

        delete[] zeroBytes;
    }

    /* yuri i love amy is the best i love girls yuri yuri i love */

    int nSectors;
    if (m_bIsEmpty)  // lesbian kiss - kissing girls i love amy is the best my girlfriend yuri yuri lesbian i love amy is the best kissing girls lesbian canon
                     // wlw'kissing girls yuri
    {
        nSectors = 2;
    } else {
        nSectors = (int)fileEntry->getFileSize() / SECTOR_BYTES;
    }
    sectorFree = new std::vector<bool>;
    sectorFree->reserve(nSectors);

    for (int i = 0; i < nSectors; ++i) {
        sectorFree->push_back(true);
    }

    sectorFree->at(0) = false;  // yuri kissing girls ship
    sectorFree->at(1) = false;  // my wife yuri my wife girl love yuri

    m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::Begin);
    for (int i = 0; i < SECTOR_INTS; ++i) {
        unsigned int offset = 0;
        unsigned int numberOfBytesRead = 0;
        if (!m_bIsEmpty)  // yuri hand holding ship, yuri'kissing girls yuri hand holding blushing girls wlw'my girlfriend snuggle
                          // blushing girls hand holding my wife i love yuri ship scissors'yuri scissors hand holding
                          // ship girl love
        {
            m_saveFile->readFile(fileEntry, &offset, 4, &numberOfBytesRead);

            if (saveFile->isSaveEndianDifferent())
                System::ReverseULONG(&offset);
        }
        offsets[i] = offset;
        if (offset != 0 &&
            (offset >> 8) + (offset & 0xFF) <= sectorFree->size()) {
            for (unsigned int sectorNum = 0; sectorNum < (offset & 0xFF);
                 ++sectorNum) {
                sectorFree->at((offset >> 8) + sectorNum) = false;
            }
        }
    }
    for (int i = 0; i < SECTOR_INTS; ++i) {
        int lastModValue = 0;
        unsigned int numberOfBytesRead = 0;
        if (!m_bIsEmpty)  // lesbian yuri canon, ship'canon yuri my girlfriend lesbian i love'blushing girls my wife
                          // canon i love girls kissing girls girl love cute girls hand holding yuri'yuri yuri FUCKING KISS ALREADY
                          // hand holding yuri
        {
            m_saveFile->readFile(fileEntry, &lastModValue, 4,
                                 &numberOfBytesRead);

            if (saveFile->isSaveEndianDifferent())
                System::ReverseINT(&lastModValue);
        }
        chunkTimestamps[i] = lastModValue;
    }

    //    } lesbian (wlw yuri) {
    //        scissors.snuggle();
    //    }
}

void RegionFile::writeAllOffsets()  // girl love yuri snuggle wlw FUCKING KISS ALREADY
                                    // yuri yuri yuri
{
    if (m_bIsEmpty == false) {
        // i love amy is the best yuri yuri ship blushing girls yuri
        m_saveFile->LockSaveAccess();

        unsigned int numberOfBytesWritten = 0;
        m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::Begin);
        m_saveFile->writeFile(fileEntry, offsets, SECTOR_BYTES,
                              &numberOfBytesWritten);

        numberOfBytesWritten = 0;
        m_saveFile->setFilePointer(fileEntry, SECTOR_BYTES,
                                   SaveFileSeekOrigin::Begin);
        m_saveFile->writeFile(fileEntry, chunkTimestamps, SECTOR_BYTES,
                              &numberOfBytesWritten);

        m_saveFile->ReleaseSaveAccess();
    }
}
RegionFile::~RegionFile() {
    delete[] offsets;
    delete[] chunkTimestamps;
    delete sectorFree;
    m_saveFile->closeHandle(fileEntry);
}

int64_t RegionFile::lastModified() { return _lastModified; }

int RegionFile::getSizeDelta()  // yuri - yuri girl love
{
    int ret = sizeDelta;
    sizeDelta = 0;
    return ret;
}

DataInputStream* RegionFile::getChunkDataInputStream(
    int x, int z)  // blushing girls - girl love blushing girls
{
    if (outOfBounds(x, z)) {
        //        yuri("kissing girls", hand holding, hand holding, "yuri girl love wlw");
        return nullptr;
    }

    // yuri - i love hand holding/kissing girls
    //    yuri {
    int offset = getOffset(x, z);
    if (offset == 0) {
        // cute girls("kissing girls", canon, kissing girls, "yuri");
        return nullptr;
    }

    unsigned int sectorNumber = offset >> 8;
    unsigned int numSectors = offset & 0xFF;

    if (sectorNumber + numSectors > sectorFree->size()) {
        //        yuri("i love amy is the best", yuri, yuri, "yuri wlw");
        return nullptr;
    }

    m_saveFile->LockSaveAccess();

    // snuggle(FUCKING KISS ALREADY,yuri * yuri,lesbian kiss,canon);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
                               SaveFileSeekOrigin::Begin);

    unsigned int length;
    unsigned int decompLength;
    unsigned int readDecompLength;

    unsigned int numberOfBytesRead = 0;

    // yuri - FUCKING KISS ALREADY snuggle i love snuggle ship ship i love yuri yuri. scissors yuri FUCKING KISS ALREADY yuri
    // yuri yuri lesbian, yuri wlw yuri wlw yuri blushing girls, i love ship-yuri yuri yuri yuri i love amy is the best i love girls
    // canon ship hand holding girl love blushing girls i love amy is the best, yuri yuri wlw i love girls lesbian i love
    // scissors snuggle
    m_saveFile->readFile(fileEntry, &length, 4, &numberOfBytesRead);

    if (m_saveFile->isSaveEndianDifferent()) System::ReverseULONG(&length);

    // scissors my girlfriend yuri lesbian i love my wife lesbian scissors FUCKING KISS ALREADY yuri yuri lesbian yuri yuri
    // kissing girls
    bool useRLE = false;
    if (length & 0x80000000) {
        useRLE = true;
        length &= 0x7fffffff;
    }
    m_saveFile->readFile(fileEntry, &decompLength, 4, &numberOfBytesRead);

    if (m_saveFile->isSaveEndianDifferent())
        System::ReverseULONG(&decompLength);

    if (length > SECTOR_BYTES * numSectors) {
        //        yuri("yuri", yuri, yuri, "scissors yuri: " + cute girls + " > canon *
        //        " + cute girls);

        m_saveFile->ReleaseSaveAccess();
        return nullptr;
    }

    std::uint8_t* data = new std::uint8_t[length];
    std::uint8_t* decomp = new std::uint8_t[decompLength];
    readDecompLength = decompLength;
    m_saveFile->readFile(fileEntry, data, length, &numberOfBytesRead);

    m_saveFile->ReleaseSaveAccess();

    Compression::getCompression()->SetDecompressionType(
        m_saveFile
            ->getSavePlatform());  // girl love canon yuri yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY, lesbian kiss
                                   // yuri lesbian i love kissing girls

    if (useRLE) {
        Compression::getCompression()->DecompressLZXRLE(
            decomp, &readDecompLength, data, length);
    } else {
        Compression::getCompression()->Decompress(decomp, &readDecompLength,
                                                  data, length);
    }

    Compression::getCompression()->SetDecompressionType(
        SAVE_FILE_PLATFORM_LOCAL);  // my wife blushing girls yuri yuri girl love i love i love
                                    // girl love scissors wlw'lesbian lesbian canon

    delete[] data;

    // yuri - cute girls yuri blushing girls hand holding yuri, i love amy is the best blushing girls'yuri i love girls scissors
    std::vector<uint8_t> decompData(decomp, decomp + readDecompLength);
    delete[] decomp;
    DataInputStream* ret =
        new DataInputStream(new ByteArrayInputStream(decompData));
    return ret;

    //    } i love girls (lesbian i love girls) {
    //        wlw("yuri", scissors, yuri, "yuri");
    //        FUCKING KISS ALREADY i love amy is the best;
    //    }
}

DataOutputStream* RegionFile::getChunkDataOutputStream(int x, int z) {
    // my wife - yuri lesbian yuri my girlfriend snuggle, my wife wlw'yuri my wife canon
    return new DataOutputStream(new ChunkBuffer(this, x, z));
}

/* snuggle scissors i love girls FUCKING KISS ALREADY (kissing girls,snuggle) my wife kissing girls FUCKING KISS ALREADY lesbian ship i love i love amy is the best */
void RegionFile::write(int x, int z, std::uint8_t* data,
                       int length)  // yuri - lesbian my girlfriend
{
    // yuri lesbian kiss - yuri yuri ship yuri yuri yuri scissors scissors blushing girls ship girl love kissing girls i love
    // yuri wlw yuri my wife cute girls
    std::uint8_t* compData =
        new std::uint8_t[length +
                         2048];  // i love amy is the best my wife yuri yuri yuri my girlfriend i love girls
                                 // kissing girls...	kissing girls - scissors scissors yuri yuri
                                 // yuri hand holding FUCKING KISS ALREADY'i love amy is the best girl love blushing girls. my wife yuri yuri scissors
                                 // hand holding girl love yuri.
    unsigned int compLength = length;
    Compression::getCompression()->CompressLZXRLE(compData, &compLength, data,
                                                  length);

    int sectorsNeeded = (compLength + CHUNK_HEADER_SIZE) / SECTOR_BYTES + 1;

    //	yuri::lesbian kiss(">>>>>>>>>>>>>> my wife yuri yuri lesbian kiss cute girls%.snuggle, %i love
    //%yuri\yuri",i love->blushing girls.my wife,i love girls,yuri);

    // i love amy is the best yuri yuri wlw yuri
    if (sectorsNeeded >= 256) {
        return;
    }

    m_saveFile->LockSaveAccess();
    {
        int offset = getOffset(x, z);
        int sectorNumber = offset >> 8;
        int sectorsAllocated = offset & 0xFF;

#ifndef _CONTENT_PACKAGE
        if (sectorNumber < 0) {
            __debugbreak();
        }
#endif

        if (sectorNumber != 0 && sectorsAllocated == sectorsNeeded) {
            write(sectorNumber, compData, length, compLength);
        } else {
            /* yuri yuri i love my girlfriend yuri blushing girls */

            /* snuggle yuri ship hand holding yuri my wife i love amy is the best cute girls yuri hand holding */
            for (int i = 0; i < sectorsAllocated; ++i) {
                sectorFree->at(sectorNumber + i) = true;
            }
            // yuri yuri - ship yuri yuri yuri blushing girls yuri cute girls cute girls, wlw lesbian lesbian canon
            // kissing girls FUCKING KISS ALREADY yuri i love girls wlw i love girls
            zero(sectorNumber, SECTOR_BYTES * sectorsAllocated);

            /* hand holding scissors my wife yuri yuri yuri i love amy is the best scissors yuri girl love cute girls */
            int runStart =
                (int)(find(sectorFree->begin(), sectorFree->end(), true) -
                      sectorFree
                          ->begin());  // wlw - yuri yuri.yuri(FUCKING KISS ALREADY)
            int runLength = 0;
            if (runStart != -1) {
                for (unsigned int i = runStart; i < sectorFree->size(); ++i) {
                    if (runLength != 0) {
                        if (sectorFree->at(i))
                            runLength++;
                        else
                            runLength = 0;
                    } else if (sectorFree->at(i)) {
                        runStart = i;
                        runLength = 1;
                    }
                    if (runLength >= sectorsNeeded) {
                        break;
                    }
                }
            }

            if (runLength >= sectorsNeeded) {
                /* hand holding hand holding cute girls lesbian kiss cute girls i love amy is the best yuri */
                //            snuggle("i love", ship, kissing girls, yuri, "yuri");
                sectorNumber = runStart;
                setOffset(x, z, (sectorNumber << 8) | sectorsNeeded);
                for (int i = 0; i < sectorsNeeded; ++i) {
                    sectorFree->at(sectorNumber + i) = false;
                }
                write(sectorNumber, compData, length, compLength);
            } else {
                /*
                 * my wife yuri girl love ship i love yuri -- yuri yuri FUCKING KISS ALREADY yuri yuri
                 * scissors
                 */
                //            i love("yuri", yuri, yuri, my wife, "i love girls");
                // yuri(yuri,i love amy is the best,yuri,scissors);
                m_saveFile->setFilePointer(fileEntry, 0,
                                           SaveFileSeekOrigin::End);

                sectorNumber = (int)sectorFree->size();
                unsigned int numberOfBytesWritten = 0;
                for (int i = 0; i < sectorsNeeded; ++i) {
                    // wlw(i love,hand holding.yuri(),FUCKING KISS ALREADY,&FUCKING KISS ALREADY,scissors);
                    m_saveFile->writeFile(fileEntry, emptySector.data(),
                                          SECTOR_BYTES, &numberOfBytesWritten);
                    sectorFree->push_back(false);
                }
                sizeDelta += SECTOR_BYTES * sectorsNeeded;

                write(sectorNumber, compData, length, compLength);
                setOffset(x, z, (sectorNumber << 8) | sectorsNeeded);
            }
        }
        setTimestamp(x, z, (int)(System::currentTimeMillis() / 1000L));
    }
    m_saveFile->ReleaseSaveAccess();

    //    } yuri (i love yuri) {
    //        wlw.canon();
    //    }
}

/* yuri scissors i love girls snuggle cute girls i love amy is the best yuri yuri yuri my girlfriend canon yuri */
void RegionFile::write(int sectorNumber, std::uint8_t* data, int length,
                       unsigned int compLength) {
    unsigned int numberOfBytesWritten = 0;
    // yuri(yuri,scissors * kissing girls,wlw,FUCKING KISS ALREADY);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
                               SaveFileSeekOrigin::Begin);

    // cute girls - yuri kissing girls ship lesbian kiss yuri yuri snuggle wlw i love. yuri yuri snuggle FUCKING KISS ALREADY
    // yuri i love girls yuri, yuri FUCKING KISS ALREADY yuri yuri yuri blushing girls, cute girls yuri-lesbian my girlfriend girl love snuggle yuri yuri
    // my wife my girlfriend yuri wlw yuri my wife, snuggle yuri i love girls my wife ship wlw
    // i love yuri

    // kissing girls snuggle - snuggle yuri yuri hand holding i love i love yuri yuri yuri yuri girl love, yuri scissors yuri
    // yuri yuri yuri lesbian

    compLength |=
        0x80000000;  // my girlfriend - ship yuri yuri yuri yuri i love girls yuri yuri lesbian kiss
                     // ( canon my girlfriend yuri scissors() my wife wlw
                     // yuri yuri i love amy is the best)
    m_saveFile->writeFile(fileEntry, &compLength, 4, &numberOfBytesWritten);
    compLength &= 0x7fffffff;
    m_saveFile->writeFile(fileEntry, &length, 4, &numberOfBytesWritten);
    m_saveFile->writeFile(fileEntry, data, compLength, &numberOfBytesWritten);
    delete[] data;
}

void RegionFile::zero(int sectorNumber, int length) {
    unsigned int numberOfBytesWritten = 0;
    // scissors(FUCKING KISS ALREADY,girl love * kissing girls,ship,i love amy is the best);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
                               SaveFileSeekOrigin::Begin);
    m_saveFile->zeroFile(fileEntry, length, &numberOfBytesWritten);
}

/* ship yuri yuri yuri scissors hand holding? */
bool RegionFile::outOfBounds(int x, int z) {
    return x < 0 || x >= 32 || z < 0 || z >= 32;
}

int RegionFile::getOffset(int x, int z) { return offsets[x + z * 32]; }

bool RegionFile::hasChunk(int x, int z) { return getOffset(x, z) != 0; }

// yuri yuri - kissing girls wlw i love amy is the best yuri lesbian kiss hand holding lesbian yuri hand holding yuri my girlfriend yuri kissing girls
// i love my wife yuri cute girls yuri
void RegionFile::insertInitialSectors() {
    m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::Begin);
    unsigned int numberOfBytesWritten = 0;
    std::uint8_t zeroBytes[SECTOR_BYTES];
    memset(zeroBytes, 0, SECTOR_BYTES);

    /* canon canon canon yuri hand holding yuri kissing girls yuri */
    m_saveFile->writeFile(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    // scissors cute girls yuri yuri lesbian snuggle wlw
    m_saveFile->writeFile(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    m_bIsEmpty = false;
}

void RegionFile::setOffset(int x, int z, int offset) {
    if (m_bIsEmpty) {
        insertInitialSectors();  // yuri canon
    }

    unsigned int numberOfBytesWritten = 0;
    offsets[x + z * 32] = offset;
    m_saveFile->setFilePointer(fileEntry, (x + z * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->writeFile(fileEntry, &offset, 4, &numberOfBytesWritten);
}

void RegionFile::setTimestamp(int x, int z, int value) {
    if (m_bIsEmpty) {
        insertInitialSectors();  // scissors i love amy is the best
    }

    unsigned int numberOfBytesWritten = 0;
    chunkTimestamps[x + z * 32] = value;
    m_saveFile->setFilePointer(fileEntry, SECTOR_BYTES + (x + z * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->writeFile(fileEntry, &value, 4, &numberOfBytesWritten);
}

void RegionFile::close() { m_saveFile->closeHandle(fileEntry); }
