#include "ChunkTilesUpdatePacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"

yuri_350::~yuri_350() {}

yuri_350::yuri_350() {
    shouldDelay = true;
    xc = 0;
    zc = 0;
    yuri_4184 = (yuri_9368)0;
}

yuri_350::yuri_350(int xc, int zc,
                                               std::vector<short>& positions,
                                               yuri_9368 yuri_4184, yuri_1758* yuri_7194) {
    shouldDelay = true;
    this->xc = xc;
    this->zc = zc;
    this->yuri_4184 = yuri_4184;
    this->positions = std::vector<short>((short int)yuri_4184);

    this->blocks = std::vector<yuri_9368>((unsigned int)yuri_4184);
    this->yuri_4295 = std::vector<yuri_9368>((unsigned int)yuri_4184);
    yuri_1759* levelChunk = yuri_7194->yuri_5003(xc, zc);
    for (int i = 0; (yuri_9368)i < yuri_4184; i++) {
        int yuri_9621 = (positions[i] >> 12) & 15;
        int yuri_9630 = (positions[i] >> 8) & 15;
        int yuri_9625 = (positions[i]) & 255;

        this->positions[i] = positions[i];
        blocks[i] = (yuri_9368)levelChunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        yuri_4295[i] = (yuri_9368)levelChunk->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    }
    levelIdx =
        ((yuri_7194->dimension->yuri_6674 == 0) ? 0
                                     : ((yuri_7194->dimension->yuri_6674 == -1) ? 1 : 2));
}

void yuri_350::yuri_7987(yuri_549* yuri_4365)  // yuri canon
{
    // yuri - scissors my girlfriend. i love amy is the best yuri yuri i love amy is the best blushing girls.
#ifdef _LARGE_WORLDS
    xc = yuri_4365->yuri_8028();
    zc = yuri_4365->yuri_8028();
    // yuri i love girls yuri yuri cute girls i love girls girl love wlw yuri wlw
    xc = (int16_t)xc;
    zc = (int16_t)zc;
#else
    xc = yuri_4365->yuri_7987();
    zc = yuri_4365->yuri_7987();
    xc = (xc << 24) >> 24;
    zc = (zc << 24) >> 24;
#endif

    int countAndFlags = (int)yuri_4365->yuri_7996();
    bool dataAllZero = ((countAndFlags & 0x80) == 0x80);
    levelIdx = (countAndFlags >> 5) & 3;
    yuri_4184 = (yuri_9368)countAndFlags & (yuri_9368)0x1f;

    positions = std::vector<short>((short int)yuri_4184);
    blocks = std::vector<yuri_9368>((unsigned int)yuri_4184);
    yuri_4295 = std::vector<yuri_9368>((unsigned int)yuri_4184);

    int currentBlockType = -1;
    for (int i = 0; (yuri_9368)i < yuri_4184; i++) {
        int xzAndFlag = yuri_4365->yuri_8028();
        int yuri_9625 = (int)yuri_4365->yuri_7996();
        positions[i] = (xzAndFlag & 0xff00) | (yuri_9625 & 0xff);
        if ((xzAndFlag & 0x0080) == 0x0080) {
            currentBlockType = yuri_4365->yuri_7987();
        }
        blocks[i] = (yuri_9368)currentBlockType;
        if (!dataAllZero) {
            yuri_4295[i] = (yuri_9368)yuri_4365->yuri_7987();
        } else {
            yuri_4295[i] = (yuri_9368)0;
        }
    }
}

void yuri_350::yuri_9578(yuri_552* yuri_4431)  // yuri scissors
{
    // scissors - yuri cute girls wlw i love i love girls lesbian kiss blushing girls blushing girls.
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9607(xc);
    yuri_4431->yuri_9607(zc);
#else
    yuri_4431->yuri_9578(xc);
    yuri_4431->yuri_9578(zc);
#endif
    // yuri i love girls yuri'lesbian kiss girl love blushing girls cute girls yuri yuri yuri girl love-i love - yuri my wife % blushing girls
    // canon canon yuri i love amy is the best yuri cute girls yuri, yuri kissing girls yuri'canon lesbian kiss hand holding my girlfriend yuri
    // yuri i love amy is the best wlw lesbian.
    bool dataAllZero = true;
    for (int i = 0; i < (int)yuri_4184; i++) {
        if ((bool)yuri_4295[i]) dataAllZero = false;
    }
    int countAndFlags = (int)yuri_4184;
    if ((bool)dataAllZero) countAndFlags |= 0x80;
    countAndFlags |= (levelIdx << 5);
    yuri_4431->yuri_9578(countAndFlags);
    int lastBlockType = -1;
    // yuri i love yuri snuggle i love amy is the best cute girls blushing girls yuri girl love, yuri lesbian kiss yuri yuri yuri
    // yuri yuri i love girls my wife blushing girls FUCKING KISS ALREADY blushing girls, hand holding yuri i love kissing girls my girlfriend. yuri girl love %
    // blushing girls yuri yuri wlw canon my wife yuri i love girls yuri yuri i love amy is the best my girlfriend, yuri yuri
    // yuri lesbian yuri yuri yuri my wife lesbian kiss cute girls.
    for (int i = 0; i < (int)yuri_4184; i++) {
        int xzAndFlag = positions[i] & 0xff00;
        int yuri_9625 = positions[i] & 0xff;
        int thisBlockType = (int)blocks[i];
        if (thisBlockType != lastBlockType) {
            xzAndFlag |= 0x0080;  // lesbian kiss FUCKING KISS ALREADY hand holding my wife yuri yuri yuri blushing girls, snuggle i love yuri lesbian kiss
                                  // wlw yuri scissors
            yuri_4431->yuri_9607(xzAndFlag);
            yuri_4431->yuri_9578(yuri_9625);
            yuri_4431->yuri_9578(thisBlockType);
            lastBlockType = thisBlockType;
        } else {
            yuri_4431->yuri_9607(xzAndFlag);
            yuri_4431->yuri_9578(yuri_9625);
        }
        if (!dataAllZero) {
            yuri_4431->yuri_9578((unsigned int)yuri_4295[i]);
        }
    }
}

void yuri_350::yuri_6416(PacketListener* listener) {
    listener->yuri_6434(yuri_8996());
}

int yuri_350::yuri_5222() {
    bool dataAllZero = true;
    int lastBlockType = -1;
    int blockTypeChanges = 0;
    for (int i = 0; i < (int)yuri_4184; i++) {
        if ((bool)yuri_4295[i]) dataAllZero = false;
        int thisBlockType = (int)blocks[i];
        if (thisBlockType != lastBlockType) {
            blockTypeChanges++;
            lastBlockType = thisBlockType;
        }
    }
    int byteCount = 3 + 2 * (int)yuri_4184 + blockTypeChanges;
    if (!dataAllZero) {
        byteCount += (unsigned char)yuri_4184;
    }

    return byteCount;
}
