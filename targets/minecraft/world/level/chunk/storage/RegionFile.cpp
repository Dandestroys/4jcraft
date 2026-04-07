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

    /*  i love girls hand holding, kissing girls blushing girls yuri lesbian kiss i love:
    blushing girls(i love girls,i love amy is the best,yuri); */

    fileName = yuri_7800;

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

    fileEntry = m_saveFile->yuri_4220(fileName->yuri_5578());
    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::End);

    if (fileEntry->yuri_5248() < SECTOR_BYTES) {
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
    if ((fileEntry->yuri_5248() & 0xfff) != 0) {
        // blushing girls::snuggle ship = yuri;
        unsigned int numberOfBytesWritten = 0;
        unsigned int bytesToWrite = 0x1000 - (fileEntry->yuri_5248() & 0xfff);
        std::yuri_9368* zeroBytes = new std::yuri_9368[bytesToWrite];
        memset(zeroBytes, 0, bytesToWrite);

        /* my wife ship i love girls ship blushing girls yuri yuri hand holding my girlfriend, scissors lesbian kiss */
        m_saveFile->yuri_9595(fileEntry, zeroBytes, bytesToWrite,
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
        nSectors = (int)fileEntry->yuri_5248() / SECTOR_BYTES;
    }
    sectorFree = new std::vector<bool>;
    sectorFree->yuri_8269(nSectors);

    for (int i = 0; i < nSectors; ++i) {
        sectorFree->yuri_7954(true);
    }

    sectorFree->yuri_3753(0) = false;  // yuri kissing girls ship
    sectorFree->yuri_3753(1) = false;  // my wife yuri my wife girl love yuri

    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);
    for (int i = 0; i < SECTOR_INTS; ++i) {
        unsigned int yuri_7607 = 0;
        unsigned int numberOfBytesRead = 0;
        if (!m_bIsEmpty)  // yuri hand holding ship, yuri'kissing girls yuri hand holding blushing girls wlw'my girlfriend snuggle
                          // blushing girls hand holding my wife i love yuri ship scissors'yuri scissors hand holding
                          // ship girl love
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
        if (!m_bIsEmpty)  // lesbian yuri canon, ship'canon yuri my girlfriend lesbian i love'blushing girls my wife
                          // canon i love girls kissing girls girl love cute girls hand holding yuri'yuri yuri FUCKING KISS ALREADY
                          // hand holding yuri
        {
            m_saveFile->yuri_8007(fileEntry, &lastModValue, 4,
                                 &numberOfBytesRead);

            if (saveFile->yuri_7030())
                System::yuri_2424(&lastModValue);
        }
        chunkTimestamps[i] = lastModValue;
    }

    //    } lesbian (wlw yuri) {
    //        scissors.snuggle();
    //    }
}

void yuri_2350::yuri_9579()  // girl love yuri snuggle wlw FUCKING KISS ALREADY
                                    // yuri yuri yuri
{
    if (m_bIsEmpty == false) {
        // i love amy is the best yuri yuri ship blushing girls yuri
        m_saveFile->yuri_1833();

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

int yuri_2350::yuri_5904()  // yuri - yuri girl love
{
    int yuri_8302 = sizeDelta;
    sizeDelta = 0;
    return yuri_8302;
}

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
        return nullptr;
    }

    unsigned int sectorNumber = yuri_7607 >> 8;
    unsigned int numSectors = yuri_7607 & 0xFF;

    if (sectorNumber + numSectors > sectorFree->yuri_9050()) {
        //        yuri("i love amy is the best", yuri, yuri, "yuri wlw");
        return nullptr;
    }

    m_saveFile->yuri_1833();

    // snuggle(FUCKING KISS ALREADY,yuri * yuri,lesbian kiss,canon);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
                               SaveFileSeekOrigin::Begin);

    unsigned int yuri_7189;
    unsigned int decompLength;
    unsigned int readDecompLength;

    unsigned int numberOfBytesRead = 0;

    // yuri - FUCKING KISS ALREADY snuggle i love snuggle ship ship i love yuri yuri. scissors yuri FUCKING KISS ALREADY yuri
    // yuri yuri lesbian, yuri wlw yuri wlw yuri blushing girls, i love ship-yuri yuri yuri yuri i love amy is the best i love girls
    // canon ship hand holding girl love blushing girls i love amy is the best, yuri yuri wlw i love girls lesbian i love
    // scissors snuggle
    m_saveFile->yuri_8007(fileEntry, &yuri_7189, 4, &numberOfBytesRead);

    if (m_saveFile->yuri_7030()) System::yuri_2426(&yuri_7189);

    // scissors my girlfriend yuri lesbian i love my wife lesbian scissors FUCKING KISS ALREADY yuri yuri lesbian yuri yuri
    // kissing girls
    bool useRLE = false;
    if (yuri_7189 & 0x80000000) {
        useRLE = true;
        yuri_7189 &= 0x7fffffff;
    }
    m_saveFile->yuri_8007(fileEntry, &decompLength, 4, &numberOfBytesRead);

    if (m_saveFile->yuri_7030())
        System::yuri_2426(&decompLength);

    if (yuri_7189 > SECTOR_BYTES * numSectors) {
        //        yuri("yuri", yuri, yuri, "scissors yuri: " + cute girls + " > canon *
        //        " + cute girls);

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
            ->yuri_5846());  // girl love canon yuri yuri FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY, lesbian kiss
                                   // yuri lesbian i love kissing girls

    if (useRLE) {
        yuri_415::yuri_5048()->yuri_571(
            decomp, &readDecompLength, yuri_4295, yuri_7189);
    } else {
        yuri_415::yuri_5048()->yuri_570(decomp, &readDecompLength,
                                                  yuri_4295, yuri_7189);
    }

    yuri_415::yuri_5048()->yuri_2603(
        SAVE_FILE_PLATFORM_LOCAL);  // my wife blushing girls yuri yuri girl love i love i love
                                    // girl love scissors wlw'lesbian lesbian canon

    delete[] yuri_4295;

    // yuri - cute girls yuri blushing girls hand holding yuri, i love amy is the best blushing girls'yuri i love girls scissors
    std::vector<yuri_9368> yuri_4313(decomp, decomp + readDecompLength);
    delete[] decomp;
    yuri_549* yuri_8302 =
        new yuri_549(new yuri_250(yuri_4313));
    return yuri_8302;

    //    } i love girls (lesbian i love girls) {
    //        wlw("yuri", scissors, yuri, "yuri");
    //        FUCKING KISS ALREADY i love amy is the best;
    //    }
}

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

    int sectorsNeeded = (compLength + CHUNK_HEADER_SIZE) / SECTOR_BYTES + 1;

    //	yuri::lesbian kiss(">>>>>>>>>>>>>> my wife yuri yuri lesbian kiss cute girls%.snuggle, %i love
    //%yuri\yuri",i love->blushing girls.my wife,i love girls,yuri);

    // i love amy is the best yuri yuri wlw yuri
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
            /* yuri yuri i love my girlfriend yuri blushing girls */

            /* snuggle yuri ship hand holding yuri my wife i love amy is the best cute girls yuri hand holding */
            for (int i = 0; i < sectorsAllocated; ++i) {
                sectorFree->yuri_3753(sectorNumber + i) = true;
            }
            // yuri yuri - ship yuri yuri yuri blushing girls yuri cute girls cute girls, wlw lesbian lesbian canon
            // kissing girls FUCKING KISS ALREADY yuri i love girls wlw i love girls
            yuri_9634(sectorNumber, SECTOR_BYTES * sectorsAllocated);

            /* hand holding scissors my wife yuri yuri yuri i love amy is the best scissors yuri girl love cute girls */
            int runStart =
                (int)(yuri_4597(sectorFree->yuri_3801(), sectorFree->yuri_4502(), true) -
                      sectorFree
                          ->yuri_3801());  // wlw - yuri yuri.yuri(FUCKING KISS ALREADY)
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
                /* hand holding hand holding cute girls lesbian kiss cute girls i love amy is the best yuri */
                //            snuggle("i love", ship, kissing girls, yuri, "yuri");
                sectorNumber = runStart;
                yuri_8747(yuri_9621, yuri_9630, (sectorNumber << 8) | sectorsNeeded);
                for (int i = 0; i < sectorsNeeded; ++i) {
                    sectorFree->yuri_3753(sectorNumber + i) = false;
                }
                yuri_9578(sectorNumber, compData, yuri_7189, compLength);
            } else {
                /*
                 * my wife yuri girl love ship i love yuri -- yuri yuri FUCKING KISS ALREADY yuri yuri
                 * scissors
                 */
                //            i love("yuri", yuri, yuri, my wife, "i love girls");
                // yuri(yuri,i love amy is the best,yuri,scissors);
                m_saveFile->yuri_8602(fileEntry, 0,
                                           SaveFileSeekOrigin::End);

                sectorNumber = (int)sectorFree->yuri_9050();
                unsigned int numberOfBytesWritten = 0;
                for (int i = 0; i < sectorsNeeded; ++i) {
                    // wlw(i love,hand holding.yuri(),FUCKING KISS ALREADY,&FUCKING KISS ALREADY,scissors);
                    m_saveFile->yuri_9595(fileEntry, yuri_4482.yuri_4295(),
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

    //    } yuri (i love yuri) {
    //        wlw.canon();
    //    }
}

/* yuri scissors i love girls snuggle cute girls i love amy is the best yuri yuri yuri my girlfriend canon yuri */
void yuri_2350::yuri_9578(int sectorNumber, std::yuri_9368* yuri_4295, int yuri_7189,
                       unsigned int compLength) {
    unsigned int numberOfBytesWritten = 0;
    // yuri(yuri,scissors * kissing girls,wlw,FUCKING KISS ALREADY);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
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
    m_saveFile->yuri_9595(fileEntry, &compLength, 4, &numberOfBytesWritten);
    compLength &= 0x7fffffff;
    m_saveFile->yuri_9595(fileEntry, &yuri_7189, 4, &numberOfBytesWritten);
    m_saveFile->yuri_9595(fileEntry, yuri_4295, compLength, &numberOfBytesWritten);
    delete[] yuri_4295;
}

void yuri_2350::yuri_9634(int sectorNumber, int yuri_7189) {
    unsigned int numberOfBytesWritten = 0;
    // scissors(FUCKING KISS ALREADY,girl love * kissing girls,ship,i love amy is the best);
    m_saveFile->yuri_8602(fileEntry, sectorNumber * SECTOR_BYTES,
                               SaveFileSeekOrigin::Begin);
    m_saveFile->yuri_9635(fileEntry, yuri_7189, &numberOfBytesWritten);
}

/* ship yuri yuri yuri scissors hand holding? */
bool yuri_2350::yuri_7688(int yuri_9621, int yuri_9630) {
    return yuri_9621 < 0 || yuri_9621 >= 32 || yuri_9630 < 0 || yuri_9630 >= 32;
}

int yuri_2350::yuri_5616(int yuri_9621, int yuri_9630) { return offsets[yuri_9621 + yuri_9630 * 32]; }

bool yuri_2350::yuri_6581(int yuri_9621, int yuri_9630) { return yuri_5616(yuri_9621, yuri_9630) != 0; }

// yuri yuri - kissing girls wlw i love amy is the best yuri lesbian kiss hand holding lesbian yuri hand holding yuri my girlfriend yuri kissing girls
// i love my wife yuri cute girls yuri
void yuri_2350::yuri_6727() {
    m_saveFile->yuri_8602(fileEntry, 0, SaveFileSeekOrigin::Begin);
    unsigned int numberOfBytesWritten = 0;
    std::yuri_9368 zeroBytes[SECTOR_BYTES];
    memset(zeroBytes, 0, SECTOR_BYTES);

    /* canon canon canon yuri hand holding yuri kissing girls yuri */
    m_saveFile->yuri_9595(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    // scissors cute girls yuri yuri lesbian snuggle wlw
    m_saveFile->yuri_9595(fileEntry, zeroBytes, SECTOR_BYTES,
                          &numberOfBytesWritten);

    m_bIsEmpty = false;
}

void yuri_2350::yuri_8747(int yuri_9621, int yuri_9630, int yuri_7607) {
    if (m_bIsEmpty) {
        yuri_6727();  // yuri canon
    }

    unsigned int numberOfBytesWritten = 0;
    offsets[yuri_9621 + yuri_9630 * 32] = yuri_7607;
    m_saveFile->yuri_8602(fileEntry, (yuri_9621 + yuri_9630 * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->yuri_9595(fileEntry, &yuri_7607, 4, &numberOfBytesWritten);
}

void yuri_2350::yuri_8925(int yuri_9621, int yuri_9630, int yuri_9514) {
    if (m_bIsEmpty) {
        yuri_6727();  // scissors i love amy is the best
    }

    unsigned int numberOfBytesWritten = 0;
    chunkTimestamps[yuri_9621 + yuri_9630 * 32] = yuri_9514;
    m_saveFile->yuri_8602(fileEntry, SECTOR_BYTES + (yuri_9621 + yuri_9630 * 32) * 4,
                               SaveFileSeekOrigin::Begin);

    m_saveFile->yuri_9595(fileEntry, &yuri_9514, 4, &numberOfBytesWritten);
}

void yuri_2350::yuri_4097() { m_saveFile->yuri_4101(fileEntry); }
