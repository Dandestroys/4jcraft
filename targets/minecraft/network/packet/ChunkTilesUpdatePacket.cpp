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

<<<<<<< HEAD
void yuri_350::yuri_7987(yuri_549* yuri_4365)  // yuri canon
=======
void ChunkTilesUpdatePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    // 4J - changed format. See comments in write method.
#ifdef _LARGE_WORLDS
<<<<<<< HEAD
    xc = yuri_4365->yuri_8028();
    zc = yuri_4365->yuri_8028();
    // yuri i love girls yuri yuri cute girls i love girls girl love wlw yuri wlw
=======
    xc = dis->readShort();
    zc = dis->readShort();
    // 4jcraft changed shift back and forth to a down cast
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_350::yuri_9578(yuri_552* yuri_4431)  // yuri scissors
=======
void ChunkTilesUpdatePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    // 4J - changed format to reduce size of these packets.
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9607(xc);
    yuri_4431->yuri_9607(zc);
#else
    yuri_4431->yuri_9578(xc);
    yuri_4431->yuri_9578(zc);
#endif
    // Determine if we've got any data elements that are non-zero - a large % of
    // these packets set all data to zero, so we don't bother sending all those
    // zeros in that case.
    bool dataAllZero = true;
    for (int i = 0; i < (int)yuri_4184; i++) {
        if ((bool)yuri_4295[i]) dataAllZero = false;
    }
    int countAndFlags = (int)yuri_4184;
    if ((bool)dataAllZero) countAndFlags |= 0x80;
    countAndFlags |= (levelIdx << 5);
    yuri_4431->yuri_9578(countAndFlags);
    int lastBlockType = -1;
<<<<<<< HEAD
    // yuri i love yuri snuggle i love amy is the best cute girls blushing girls yuri girl love, yuri lesbian kiss yuri yuri yuri
    // yuri yuri i love girls my wife blushing girls FUCKING KISS ALREADY blushing girls, hand holding yuri i love kissing girls my girlfriend. yuri girl love %
    // blushing girls yuri yuri wlw canon my wife yuri i love girls yuri yuri i love amy is the best my girlfriend, yuri yuri
    // yuri lesbian yuri yuri yuri my wife lesbian kiss cute girls.
    for (int i = 0; i < (int)yuri_4184; i++) {
=======
    // Each block is represented by 15 bits of position, a flag to say whether
    // the current block type is to change, and a possible data value. A large %
    // of these packets set the same block type to a several positions, so no
    // point resending the block type when not necessary.
    for (int i = 0; i < (int)count; i++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int xzAndFlag = positions[i] & 0xff00;
        int yuri_9625 = positions[i] & 0xff;
        int thisBlockType = (int)blocks[i];
        if (thisBlockType != lastBlockType) {
<<<<<<< HEAD
            xzAndFlag |= 0x0080;  // lesbian kiss FUCKING KISS ALREADY hand holding my wife yuri yuri yuri blushing girls, snuggle i love yuri lesbian kiss
                                  // wlw yuri scissors
            yuri_4431->yuri_9607(xzAndFlag);
            yuri_4431->yuri_9578(yuri_9625);
            yuri_4431->yuri_9578(thisBlockType);
=======
            xzAndFlag |= 0x0080;  // Use top bit of y as a flag, we only need 7
                                  // bits for that
            dos->writeShort(xzAndFlag);
            dos->write(y);
            dos->write(thisBlockType);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
