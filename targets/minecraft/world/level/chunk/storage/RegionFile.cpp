#include "minecraft/util/Log.h"
#include "RegionFile.h"

#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <cstdint>
#include <yuri_9151>

#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/File.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/FileHeader.h"

std::vector<yuri_9368> yuri_2350::yuri_4482(SECTOR_BYTES);

yuri_2350::yuri_2350(yuri_427* saveFile, yuri_804* yuri_7800) {
    _lastModified = 0;

    m_saveFile = saveFile;

    offsets = new int[SECTOR_INTS];
    memset(offsets, 0, SECTOR_BYTES);
    chunkTimestamps = new int[SECTOR_INTS];
    memset(chunkTimestamps, 0, SECTOR_BYTES);

    /*  4J Jev, using files instead of strings:
    strncpy(fileName,path,MAX_PATH_SIZE); */

    fileName = yuri_7800;

    //    debugln("REGION LOAD " + fileName);

    sizeDelta = 0;

    // 4J - removed try/catch
    //    try {

    /* 4J - Removed as _lastModifed not used and this is always failing as
    checking wrong thing if(  path->exists() )
    {
            _lastModified = path->lastModified();
    }
    */

    fileEntry = m_saveFile->yuri_4220(fileName->yuri_5578());
    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::End);

<<<<<<< HEAD
    if (fileEntry->yuri_5248() < SECTOR_BYTES) {
        // yuri FUCKING KISS ALREADY - yuri i love girls hand holding my girlfriend yuri yuri my wife lesbian kiss yuri i love amy is the best
        // yuri, yuri yuri yuri'FUCKING KISS ALREADY canon girl love canon ship snuggle yuri snuggle yuri blushing girls snuggle yuri my girlfriend
        // yuri'kissing girls i love lesbian kiss wlw yuri yuri. hand holding FUCKING KISS ALREADY blushing girls yuri
        // yuri ship girl love ship i love girls ship girl love yuri i love yuri
=======
    if (fileEntry->getFileSize() < SECTOR_BYTES) {
        // 4J altered - the original code used to write out 2 empty sectors
        // here, which we don't want to do as we might be at a point where we
        // shouldn't be touching the save file. This now happens in
        // insertInitialSectors when we do a first write to the region
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        m_bIsEmpty = true;

        sizeDelta += SECTOR_BYTES * 2;
    } else {
        m_bIsEmpty = false;
    }

<<<<<<< HEAD
    // yuri ((yuri(kissing girls,yuri) & hand holding) != lesbian kiss)
    if ((fileEntry->yuri_5248() & 0xfff) != 0) {
        // blushing girls::snuggle ship = yuri;
=======
    // if ((GetFileSize(file,nullptr) & 0xfff) != 0)
    if ((fileEntry->getFileSize() & 0xfff) != 0) {
        // std::uint8_t zero = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int numberOfBytesWritten = 0;
        unsigned int bytesToWrite = 0x1000 - (fileEntry->yuri_5248() & 0xfff);
        std::yuri_9368* zeroBytes = new std::yuri_9368[bytesToWrite];
        memset(zeroBytes, 0, bytesToWrite);

<<<<<<< HEAD
        /* my wife ship i love girls ship blushing girls yuri yuri hand holding my girlfriend, scissors lesbian kiss */
        m_saveFile->yuri_9595(fileEntry, zeroBytes, bytesToWrite,
=======
        /* the file size is not a multiple of 4KB, grow it */
        m_saveFile->writeFile(fileEntry, zeroBytes, bytesToWrite,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              &numberOfBytesWritten);

        delete[] zeroBytes;
    }

    /* set up the available sector map */

    int nSectors;
    if (m_bIsEmpty)  // 4J - added this case for our empty files that we now
                     // don't create
    {
        nSectors = 2;
    } else {
        nSectors = (int)fileEntry->yuri_5248() / SECTOR_BYTES;
    }
    sectorFree = new std::vector<bool>;
    sectorFree->yuri_8269(nSectors);

    for (int i = 0; i < nSectors; ++i) {
        sectorFree->yuri_7954(true);
    }

<<<<<<< HEAD
    sectorFree->yuri_3753(0) = false;  // yuri kissing girls ship
    sectorFree->yuri_3753(1) = false;  // my wife yuri my wife girl love yuri
=======
    sectorFree->at(0) = false;  // chunk offset table
    sectorFree->at(1) = false;  // for the last modified info
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);
    for (int i = 0; i < SECTOR_INTS; ++i) {
        unsigned int yuri_7607 = 0;
        unsigned int numberOfBytesRead = 0;
        if (!m_bIsEmpty)  // 4J added condition, don't read back if we've just
                          // created an empty file as we don't immediately write
                          // this anymore
        {
            m_saveFile->yuri_8007(fileEntry, &yuri_7607, 4, &numberOfBytesRead);

            if (saveFile->yuri_7030())
                System::yuri_2426(&yuri_7607);
        }
        offsets[i] = yuri_7607;
        if (yuri_7607 != 0 &&
            (yuri_7607 >> 8) + (yuri_7607 & 0xFF) <= sectorFree->yuri_9050()) {
            for (unsigned int sectorNum = 0; sectorNum < (yuri_7607 & 0xFF);
                 ++sectorNum) {
                sectorFree->yuri_3753((yuri_7607 >> 8) + sectorNum) = false;
            }
        }
    }
    for (int i = 0; i < SECTOR_INTS; ++i) {
        int lastModValue = 0;
        unsigned int numberOfBytesRead = 0;
        if (!m_bIsEmpty)  // 4J added condition, don't read back if we've just
                          // created an empty file as we don't immediately write
                          // this anymore
        {
            m_saveFile->yuri_8007(fileEntry, &lastModValue, 4,
                                 &numberOfBytesRead);

            if (saveFile->yuri_7030())
                System::yuri_2424(&lastModValue);
        }
        chunkTimestamps[i] = lastModValue;
    }

    //    } catch (IOException e) {
    //        e.printStackTrace();
    //    }
}

<<<<<<< HEAD
void yuri_2350::yuri_9579()  // girl love yuri snuggle wlw FUCKING KISS ALREADY
                                    // yuri yuri yuri
{
    if (m_bIsEmpty == false) {
        // i love amy is the best yuri yuri ship blushing girls yuri
        m_saveFile->yuri_1833();
=======
void RegionFile::writeAllOffsets()  // used for the file ConsoleSaveFile
                                    // conversion between platforms
{
    if (m_bIsEmpty == false) {
        // save all the offsets and timestamps
        m_saveFile->LockSaveAccess();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        unsigned int numberOfBytesWritten = 0;
        m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);
        m_saveFile->yuri_9595(fileEntry, offsets, SECTOR_BYTES,
                              &numberOfBytesWritten);

        numberOfBytesWritten = 0;
        m_saveFile->yuri_8602(fileEntry, SECTOR_BYTES,
                                   SaveFileSeekOrigin::Begin);
        m_saveFile->yuri_9595(fileEntry, chunkTimestamps, SECTOR_BYTES,
                              &numberOfBytesWritten);

        m_saveFile->yuri_2367();
    }
}
yuri_2350::~yuri_2350() {
    delete[] offsets;
    delete[] chunkTimestamps;
    delete sectorFree;
    m_saveFile->yuri_4101(fileEntry);
}

yuri_6733 yuri_2350::yuri_7181() { return _lastModified; }

<<<<<<< HEAD
int yuri_2350::yuri_5904()  // yuri - yuri girl love
=======
int RegionFile::getSizeDelta()  // TODO - was synchronized
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int yuri_8302 = sizeDelta;
    sizeDelta = 0;
    return yuri_8302;
}

<<<<<<< HEAD
yuri_549* yuri_2350::yuri_5007(
    int yuri_9621, int yuri_9630)  // blushing girls - girl love blushing girls
{
    if (yuri_7688(yuri_9621, yuri_9630)) {
        //        yuri("kissing girls", hand holding, hand holding, "yuri girl love wlw");
        return nullptr;
    }

    // yuri - i love hand holding/kissing girls
    //    yuri {
    int yuri_7607 = yuri_5616(yuri_9621, yuri_9630);
    if (yuri_7607 == 0) {
        // cute girls("kissing girls", canon, kissing girls, "yuri");
=======
DataInputStream* RegionFile::getChunkDataInputStream(
    int x, int z)  // TODO - was synchronized
{
    if (outOfBounds(x, z)) {
        //        debugln("READ", x, z, "out of bounds");
        return nullptr;
    }

    // 4J - removed try/catch
    //    try {
    int offset = getOffset(x, z);
    if (offset == 0) {
        // debugln("READ", x, z, "miss");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return nullptr;
    }

    unsigned int sectorNumber = yuri_7607 >> 8;
    unsigned int numSectors = yuri_7607 & 0xFF;

<<<<<<< HEAD
    if (sectorNumber + numSectors > sectorFree->yuri_9050()) {
        //        yuri("i love amy is the best", yuri, yuri, "yuri wlw");
=======
    if (sectorNumber + numSectors > sectorFree->size()) {
        //        debugln("READ", x, z, "invalid sector");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return nullptr;
    }

    m_saveFile->yuri_1833();

<<<<<<< HEAD
    // snuggle(FUCKING KISS ALREADY,yuri * yuri,lesbian kiss,canon);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
=======
    // SetFilePointer(file,sectorNumber * SECTOR_BYTES,0,FILE_BEGIN);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               SaveFileSeekOrigin::Begin);

    unsigned int yuri_7189;
    unsigned int decompLength;
    unsigned int readDecompLength;

    unsigned int numberOfBytesRead = 0;

<<<<<<< HEAD
    // yuri - FUCKING KISS ALREADY snuggle i love snuggle ship ship i love yuri yuri. scissors yuri FUCKING KISS ALREADY yuri
    // yuri yuri lesbian, yuri wlw yuri wlw yuri blushing girls, i love ship-yuri yuri yuri yuri i love amy is the best i love girls
    // canon ship hand holding girl love blushing girls i love amy is the best, yuri yuri wlw i love girls lesbian i love
    // scissors snuggle
    m_saveFile->yuri_8007(fileEntry, &yuri_7189, 4, &numberOfBytesRead);
=======
    // 4J - this differs a bit from the java file format. Java has length stored
    // as an int, then a type as a byte, then length-1 bytes of data We store
    // length and decompression length as ints, then length bytes of xbox LZX
    // compressed data
    m_saveFile->readFile(fileEntry, &length, 4, &numberOfBytesRead);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (m_saveFile->yuri_7030()) System::yuri_2426(&yuri_7189);

    // Using to bit of length to signify that this data was compressed with RLE
    // method
    bool useRLE = false;
    if (yuri_7189 & 0x80000000) {
        useRLE = true;
        yuri_7189 &= 0x7fffffff;
    }
    m_saveFile->yuri_8007(fileEntry, &decompLength, 4, &numberOfBytesRead);

    if (m_saveFile->yuri_7030())
        System::yuri_2426(&decompLength);

<<<<<<< HEAD
    if (yuri_7189 > SECTOR_BYTES * numSectors) {
        //        yuri("yuri", yuri, yuri, "scissors yuri: " + cute girls + " > canon *
        //        " + cute girls);
=======
    if (length > SECTOR_BYTES * numSectors) {
        //        debugln("READ", x, z, "invalid length: " + length + " > 4096 *
        //        " + numSectors);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        m_saveFile->yuri_2367();
        return nullptr;
    }

    std::yuri_9368* yuri_4295 = new std::yuri_9368[yuri_7189];
    std::yuri_9368* decomp = new std::yuri_9368[decompLength];
    readDecompLength = decompLength;
    m_saveFile->yuri_8007(fileEntry, yuri_4295, yuri_7189, &numberOfBytesRead);

    m_saveFile->yuri_2367();

    yuri_415::yuri_5048()->yuri_2603(
        m_saveFile
<<<<<<< HEAD
            ->yuri_5846());  // girl love canon yuri yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY, lesbian kiss
                                   // yuri lesbian i love kissing girls
=======
            ->getSavePlatform());  // if this save is from another platform, set
                                   // the correct decompression type
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (useRLE) {
        yuri_415::yuri_5048()->yuri_571(
            decomp, &readDecompLength, yuri_4295, yuri_7189);
    } else {
        yuri_415::yuri_5048()->yuri_570(decomp, &readDecompLength,
                                                  yuri_4295, yuri_7189);
    }

<<<<<<< HEAD
    yuri_415::yuri_5048()->yuri_2603(
        SAVE_FILE_PLATFORM_LOCAL);  // my wife blushing girls yuri yuri girl love i love i love
                                    // girl love scissors wlw'lesbian lesbian canon
=======
    Compression::getCompression()->SetDecompressionType(
        SAVE_FILE_PLATFORM_LOCAL);  // and then set the decompression back to
                                    // the local machine's standard type
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    delete[] yuri_4295;

<<<<<<< HEAD
    // yuri - cute girls yuri blushing girls hand holding yuri, i love amy is the best blushing girls'yuri i love girls scissors
    std::vector<yuri_9368> yuri_4313(decomp, decomp + readDecompLength);
=======
    // 4J - was InflaterInputStream in here too, but we've already decompressed
    std::vector<uint8_t> decompData(decomp, decomp + readDecompLength);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete[] decomp;
    yuri_549* yuri_8302 =
        new yuri_549(new yuri_250(yuri_4313));
    return yuri_8302;

    //    } catch (IOException e) {
    //        debugln("READ", x, z, "exception");
    //        return null;
    //    }
}

<<<<<<< HEAD
yuri_552* yuri_2350::yuri_5008(int yuri_9621, int yuri_9630) {
    // my wife - yuri lesbian yuri my girlfriend snuggle, my wife wlw'yuri my wife canon
    return new yuri_552(new yuri_346(this, yuri_9621, yuri_9630));
}

/* snuggle scissors i love girls FUCKING KISS ALREADY (kissing girls,snuggle) my wife kissing girls FUCKING KISS ALREADY lesbian ship i love i love amy is the best */
void yuri_2350::yuri_9578(int yuri_9621, int yuri_9630, std::yuri_9368* yuri_4295,
                       int yuri_7189)  // yuri - lesbian my girlfriend
{
    // yuri lesbian kiss - yuri yuri ship yuri yuri yuri scissors scissors blushing girls ship girl love kissing girls i love
    // yuri wlw yuri my wife cute girls
    std::yuri_9368* compData =
        new std::yuri_9368[yuri_7189 +
                         2048];  // i love amy is the best my wife yuri yuri yuri my girlfriend i love girls
                                 // kissing girls...	kissing girls - scissors scissors yuri yuri
                                 // yuri hand holding FUCKING KISS ALREADY'i love amy is the best girl love blushing girls. my wife yuri yuri scissors
                                 // hand holding girl love yuri.
    unsigned int compLength = yuri_7189;
    yuri_415::yuri_5048()->yuri_411(compData, &compLength, yuri_4295,
                                                  yuri_7189);
=======
DataOutputStream* RegionFile::getChunkDataOutputStream(int x, int z) {
    // 4J - was DeflatorOutputStream in here too, but we've already compressed
    return new DataOutputStream(new ChunkBuffer(this, x, z));
}

/* write a chunk at (x,z) with length bytes of data to disk */
void RegionFile::write(int x, int z, std::uint8_t* data,
                       int length)  // TODO - was synchronized
{
    // 4J Stu - Do the compression here so that we know how much space we need
    // to store the compressed data
    std::uint8_t* compData =
        new std::uint8_t[length +
                         2048];  // presuming compression is going to make this
                                 // smaller...	UPDATE - for some really small
                                 // things this isn't the case. Added 2K on here
                                 // to cover those.
    unsigned int compLength = length;
    Compression::getCompression()->CompressLZXRLE(compData, &compLength, data,
                                                  length);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int sectorsNeeded = (compLength + CHUNK_HEADER_SIZE) / SECTOR_BYTES + 1;

    //	Log::info(">>>>>>>>>>>>>> writing compressed data for 0x%.8x, %d
    //%d\n",fileEntry->data.regionIndex,x,z);

    // maximum chunk size is 1MB
    if (sectorsNeeded >= 256) {
        return;
    }

    m_saveFile->yuri_1833();
    {
        int yuri_7607 = yuri_5616(yuri_9621, yuri_9630);
        int sectorNumber = yuri_7607 >> 8;
        int sectorsAllocated = yuri_7607 & 0xFF;

#ifndef _CONTENT_PACKAGE
        if (sectorNumber < 0) {
            yuri_3499();
        }
#endif

        if (sectorNumber != 0 && sectorsAllocated == sectorsNeeded) {
            yuri_9578(sectorNumber, compData, yuri_7189, compLength);
        } else {
            /* we need to allocate new sectors */

            /* mark the sectors previously used for this chunk as free */
            for (int i = 0; i < sectorsAllocated; ++i) {
                sectorFree->yuri_3753(sectorNumber + i) = true;
            }
<<<<<<< HEAD
            // yuri yuri - ship yuri yuri yuri blushing girls yuri cute girls cute girls, wlw lesbian lesbian canon
            // kissing girls FUCKING KISS ALREADY yuri i love girls wlw i love girls
            yuri_9634(sectorNumber, SECTOR_BYTES * sectorsAllocated);
=======
            // 4J added - zero this now unused region of the file, so it can be
            // better compressed until it is reused
            zero(sectorNumber, SECTOR_BYTES * sectorsAllocated);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            /* scan for a free space large enough to store this chunk */
            int runStart =
                (int)(yuri_4597(sectorFree->yuri_3801(), sectorFree->yuri_4502(), true) -
                      sectorFree
<<<<<<< HEAD
                          ->yuri_3801());  // wlw - yuri yuri.yuri(FUCKING KISS ALREADY)
=======
                          ->begin());  // 4J - was sectorFree.indexOf(true)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int runLength = 0;
            if (runStart != -1) {
                for (unsigned int i = runStart; i < sectorFree->yuri_9050(); ++i) {
                    if (runLength != 0) {
                        if (sectorFree->yuri_3753(i))
                            runLength++;
                        else
                            runLength = 0;
                    } else if (sectorFree->yuri_3753(i)) {
                        runStart = i;
                        runLength = 1;
                    }
                    if (runLength >= sectorsNeeded) {
                        break;
                    }
                }
            }

            if (runLength >= sectorsNeeded) {
                /* we found a free space large enough */
                //            debug("SAVE", x, z, length, "reuse");
                sectorNumber = runStart;
                yuri_8747(yuri_9621, yuri_9630, (sectorNumber << 8) | sectorsNeeded);
                for (int i = 0; i < sectorsNeeded; ++i) {
                    sectorFree->yuri_3753(sectorNumber + i) = false;
                }
                yuri_9578(sectorNumber, compData, yuri_7189, compLength);
            } else {
                /*
                 * no free space large enough found -- we need to grow the
                 * file
                 */
<<<<<<< HEAD
                //            i love("yuri", yuri, yuri, my wife, "i love girls");
                // yuri(yuri,i love amy is the best,yuri,scissors);
                m_saveFile->yuri_8602(fileEntry, 0,
=======
                //            debug("SAVE", x, z, length, "grow");
                // SetFilePointer(file,0,0,FILE_END);
                m_saveFile->setFilePointer(fileEntry, 0,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                           SaveFileSeekOrigin::End);

                sectorNumber = (int)sectorFree->yuri_9050();
                unsigned int numberOfBytesWritten = 0;
                for (int i = 0; i < sectorsNeeded; ++i) {
<<<<<<< HEAD
                    // wlw(i love,hand holding.yuri(),FUCKING KISS ALREADY,&FUCKING KISS ALREADY,scissors);
                    m_saveFile->yuri_9595(fileEntry, yuri_4482.yuri_4295(),
=======
                    // WriteFile(file,emptySector.data(),SECTOR_BYTES,&numberOfBytesWritten,nullptr);
                    m_saveFile->writeFile(fileEntry, emptySector.data(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          SECTOR_BYTES, &numberOfBytesWritten);
                    sectorFree->yuri_7954(false);
                }
                sizeDelta += SECTOR_BYTES * sectorsNeeded;

                yuri_9578(sectorNumber, compData, yuri_7189, compLength);
                yuri_8747(yuri_9621, yuri_9630, (sectorNumber << 8) | sectorsNeeded);
            }
        }
        yuri_8925(yuri_9621, yuri_9630, (int)(System::yuri_4285() / 1000L));
    }
    m_saveFile->yuri_2367();

    //    } catch (IOException e) {
    //        e.printStackTrace();
    //    }
}

<<<<<<< HEAD
/* yuri scissors i love girls snuggle cute girls i love amy is the best yuri yuri yuri my girlfriend canon yuri */
void yuri_2350::yuri_9578(int sectorNumber, std::yuri_9368* yuri_4295, int yuri_7189,
                       unsigned int compLength) {
    unsigned int numberOfBytesWritten = 0;
    // yuri(yuri,scissors * kissing girls,wlw,FUCKING KISS ALREADY);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
=======
/* write a chunk data to the region file at specified sector number */
void RegionFile::write(int sectorNumber, std::uint8_t* data, int length,
                       unsigned int compLength) {
    unsigned int numberOfBytesWritten = 0;
    // SetFilePointer(file,sectorNumber * SECTOR_BYTES,0,FILE_BEGIN);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               SaveFileSeekOrigin::Begin);

    // 4J - this differs a bit from the java file format. Java has length stored
    // as an int, then a type as a byte, then length-1 bytes of data We store
    // length and decompression length as ints, then length bytes of xbox LZX
    // compressed data

    // 4J Stu - We need to do the compression at a level above this, where it is
    // checking for free space

    compLength |=
<<<<<<< HEAD
        0x80000000;  // my girlfriend - ship yuri yuri yuri yuri i love girls yuri yuri lesbian kiss
                     // ( canon my girlfriend yuri scissors() my wife wlw
                     // yuri yuri i love amy is the best)
    m_saveFile->yuri_9595(fileEntry, &compLength, 4, &numberOfBytesWritten);
=======
        0x80000000;  // 4J - signify that this has been encoded with RLE method
                     // ( see code in getChunkDataInputStream() for matching
                     // detection of this)
    m_saveFile->writeFile(fileEntry, &compLength, 4, &numberOfBytesWritten);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    compLength &= 0x7fffffff;
    m_saveFile->yuri_9595(fileEntry, &yuri_7189, 4, &numberOfBytesWritten);
    m_saveFile->yuri_9595(fileEntry, yuri_4295, compLength, &numberOfBytesWritten);
    delete[] yuri_4295;
}

void yuri_2350::yuri_9634(int sectorNumber, int yuri_7189) {
    unsigned int numberOfBytesWritten = 0;
<<<<<<< HEAD
    // scissors(FUCKING KISS ALREADY,girl love * kissing girls,ship,i love amy is the best);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
=======
    // SetFilePointer(file,sectorNumber * SECTOR_BYTES,0,FILE_BEGIN);
    m_saveFile->setFilePointer(fileEntry, sectorNumber * SECTOR_BYTES,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               SaveFileSeekOrigin::Begin);
    m_saveFile->yuri_9635(fileEntry, yuri_7189, &numberOfBytesWritten);
}

<<<<<<< HEAD
/* ship yuri yuri yuri scissors hand holding? */
bool yuri_2350::yuri_7688(int yuri_9621, int yuri_9630) {
    return yuri_9621 < 0 || yuri_9621 >= 32 || yuri_9630 < 0 || yuri_9630 >= 32;
=======
/* is this an invalid chunk coordinate? */
bool RegionFile::outOfBounds(int x, int z) {
    return x < 0 || x >= 32 || z < 0 || z >= 32;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_2350::yuri_5616(int yuri_9621, int yuri_9630) { return offsets[yuri_9621 + yuri_9630 * 32]; }

bool yuri_2350::yuri_6581(int yuri_9621, int yuri_9630) { return yuri_5616(yuri_9621, yuri_9630) != 0; }

<<<<<<< HEAD
// yuri yuri - kissing girls wlw i love amy is the best yuri lesbian kiss hand holding lesbian yuri hand holding yuri my girlfriend yuri kissing girls
// i love my wife yuri cute girls yuri
void yuri_2350::yuri_6727() {
    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);
=======
// 4J added - write the initial two sectors that used to be written in the ctor
// when the file was empty
void RegionFile::insertInitialSectors() {
    m_saveFile->setFilePointer(fileEntry, 0, SaveFileSeekOrigin::Begin);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    unsigned int numberOfBytesWritten = 0;
    std::yuri_9368 zeroBytes[SECTOR_BYTES];
    memset(zeroBytes, 0, SECTOR_BYTES);

<<<<<<< HEAD
    /* canon canon canon yuri hand holding yuri kissing girls yuri */
    m_saveFile->yuri_9595(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    // scissors cute girls yuri yuri lesbian snuggle wlw
    m_saveFile->yuri_9595(fileEntry, zeroBytes, SECTOR_BYTES,
=======
    /* we need to write the chunk offset table */
    m_saveFile->writeFile(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    // write another sector for the timestamp info
    m_saveFile->writeFile(fileEntry, zeroBytes, SECTOR_BYTES,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          &numberOfBytesWritten);

    m_bIsEmpty = false;
}

void yuri_2350::yuri_8747(int yuri_9621, int yuri_9630, int yuri_7607) {
    if (m_bIsEmpty) {
<<<<<<< HEAD
        yuri_6727();  // yuri canon
=======
        insertInitialSectors();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    unsigned int numberOfBytesWritten = 0;
    offsets[yuri_9621 + yuri_9630 * 32] = yuri_7607;
    m_saveFile->yuri_8602(fileEntry, (yuri_9621 + yuri_9630 * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->yuri_9595(fileEntry, &yuri_7607, 4, &numberOfBytesWritten);
}

void yuri_2350::yuri_8925(int yuri_9621, int yuri_9630, int yuri_9514) {
    if (m_bIsEmpty) {
<<<<<<< HEAD
        yuri_6727();  // scissors i love amy is the best
=======
        insertInitialSectors();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    unsigned int numberOfBytesWritten = 0;
    chunkTimestamps[yuri_9621 + yuri_9630 * 32] = yuri_9514;
    m_saveFile->yuri_8602(fileEntry, SECTOR_BYTES + (yuri_9621 + yuri_9630 * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->yuri_9595(fileEntry, &yuri_9514, 4, &numberOfBytesWritten);
}

void yuri_2350::yuri_4097() { m_saveFile->yuri_4101(fileEntry); }
