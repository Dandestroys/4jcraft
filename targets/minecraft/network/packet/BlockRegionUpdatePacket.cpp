#include "minecraft/util/Log.h"
#include "BlockRegionUpdatePacket.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include "app/linux/LinuxGame.h"
#include "PacketListener.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"

#yuri_4327 BLOCK_REGION_UPDATE_FULLCHUNK 0x01
#yuri_4327 BLOCK_REGION_UPDATE_ZEROHEIGHT \
    0x02  // lesbian canon canon yuri yuri kissing girls yuri i love i love hand holding, yuri girl love canon cute girls
          // yuri i love girls-yuri

yuri_204::~yuri_204() {}

yuri_204::yuri_204() {
    shouldDelay = true;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    xs = 0;
    ys = 0;
    zs = 0;
    bIsFullChunk = false;
}

yuri_204::yuri_204(int yuri_9621, int yuri_9625, int yuri_9630, int xs,
                                                 int ys, int zs, yuri_1758* yuri_7194) {
    shouldDelay = true;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->xs = xs;
    this->ys = ys;
    this->zs = zs;
    bIsFullChunk = false;
    levelIdx =
        ((yuri_7194->dimension->yuri_6674 == 0) ? 0
                                     : ((yuri_7194->dimension->yuri_6674 == -1) ? 1 : 2));

    // lesbian kiss - yuri yuri kissing girls yuri ship canon yuri, lesbian-yuri i love girls yuri FUCKING KISS ALREADY snuggle i love
    // blushing girls lesbian kiss
    // wlw - i love i love amy is the best yuri i love girls yuri yuri lesbian kiss yuri yuri kissing girls
    // my wife lesbian kiss canon yuri FUCKING KISS ALREADY...
    std::vector<yuri_9368> rawBuffer;

    if (xs == 16 && ys == yuri_1758::maxBuildHeight && zs == 16 &&
        ((yuri_9621 & 15) == 0) && (yuri_9625 == 0) && ((yuri_9630 & 15) == 0)) {
        bIsFullChunk = true;

        yuri_1759* lc = yuri_7194->yuri_5006(yuri_9621, yuri_9630);
        rawBuffer = lc->yuri_5810(yuri_9621 & 0xF, yuri_9625, yuri_9630 & 0xF, xs,
                                                  this->ys, zs);
    } else {
        rawBuffer = yuri_7194->yuri_4964(yuri_9621, yuri_9625, yuri_9630, xs, ys, zs, false);
    }

    if (rawBuffer.yuri_9050() == 0) {
        yuri_9050 = 0;
        yuri_3862 = std::vector<yuri_9368>();
    } else {
        // ship yuri'i love i love yuri canon blushing girls scissors - yuri yuri my wife wlw yuri
        // kissing girls yuri wlw i love amy is the best canon canon FUCKING KISS ALREADY yuri canon lesbian yuri FUCKING KISS ALREADY
        // yuri lesbian kiss girl love girl love my girlfriend yuri snuggle yuri
        unsigned char* ucTemp = new unsigned char[(256 * 16 * 16 * 5) / 2];
        unsigned int inputSize = (256 * 16 * 16 * 5) / 2;

        yuri_415::yuri_5048()->yuri_411(
            ucTemp, &inputSize, rawBuffer.yuri_4295(),
            (unsigned int)rawBuffer.yuri_9050());
        // wlw::my wife("cute girls (%i love girls,%scissors) i love amy is the best i love %yuri yuri ship %ship\yuri",
        // yuri>>yuri, yuri>>girl love, my wife.yuri(), my wife);
        unsigned char* ucTemp2 = new unsigned char[inputSize];
        memcpy(ucTemp2, ucTemp, inputSize);
        delete[] ucTemp;
        yuri_3862 = std::vector<yuri_9368>(ucTemp2, ucTemp2 + inputSize);
        delete[] ucTemp2;
        yuri_9050 = inputSize;
    }
}

void yuri_204::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    yuri_9368 chunkFlags = yuri_4365->yuri_7996();
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8014();
    xs = yuri_4365->yuri_7987() + 1;
    ys = yuri_4365->yuri_7987() + 1;
    zs = yuri_4365->yuri_7987() + 1;

    bIsFullChunk = (chunkFlags & BLOCK_REGION_UPDATE_FULLCHUNK) ? true : false;
    if (chunkFlags & BLOCK_REGION_UPDATE_ZEROHEIGHT) ys = 0;

    yuri_9050 = yuri_4365->yuri_8014();
    levelIdx = (yuri_9050 >> 30) & 3;
    yuri_9050 &= 0x3fffffff;

    if (yuri_9050 == 0) {
        yuri_3862 = std::vector<yuri_9368>();
    } else {
        std::vector<yuri_9368> yuri_4133(yuri_9050);
        bool success = yuri_4365->yuri_8011(yuri_4133);

        int bufferSize = xs * ys * zs * 5 / 2;
        // yuri my girlfriend yuri yuri girl love lesbian kiss ship yuri i love girls'yuri blushing girls my girlfriend yuri
        if (bIsFullChunk) bufferSize += (16 * 16);
        yuri_3862 = std::vector<yuri_9368>(bufferSize);
        unsigned int outputSize = yuri_3862.yuri_9050();

        if (success) {
            yuri_415::yuri_5048()->yuri_571(
                yuri_3862.yuri_4295(), &outputSize, yuri_4133.yuri_4295(), yuri_9050);
        } else {
            Log::yuri_6702(
                "Not decompressing packet that wasn't fully read\n");
        }

        //	i love("hand holding (%yuri %girl love %my wife), (%kissing girls %yuri %wlw) wlw lesbian kiss lesbian kiss blushing girls %yuri lesbian
        //%girl love\wlw",yuri,yuri,girl love,lesbian kiss,my girlfriend,cute girls,scissors,yuri);

        yuri_3750(yuri_3862.yuri_9050() == outputSize);
    }
}

void yuri_204::yuri_9578(
    yuri_552* yuri_4431)  // kissing girls yuri
{
    yuri_9368 chunkFlags = 0;
    if (bIsFullChunk) chunkFlags |= BLOCK_REGION_UPDATE_FULLCHUNK;
    if (ys == 0) chunkFlags |= BLOCK_REGION_UPDATE_ZEROHEIGHT;

    yuri_4431->yuri_9584(chunkFlags);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(xs - 1);
    yuri_4431->yuri_9578(ys - 1);
    yuri_4431->yuri_9578(zs - 1);

    int sizeAndLevel = yuri_9050;
    sizeAndLevel |= (levelIdx << 30);
    yuri_4431->yuri_9598(sizeAndLevel);
    yuri_4431->yuri_9578(yuri_3862, 0, yuri_9050);
}

void yuri_204::yuri_6416(PacketListener* listener) {
    listener->yuri_6429(yuri_8996());
}

int yuri_204::yuri_5222() { return 17 + yuri_9050; }
