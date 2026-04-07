#include "minecraft/util/Log.h"
#include "BlockRegionUpdatePacket.h"

#include <assert.h>
#include <string.h>

#include "app/linux/LinuxGame.h"
#include "PacketListener.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"

#define BLOCK_REGION_UPDATE_FULLCHUNK 0x01
#define BLOCK_REGION_UPDATE_ZEROHEIGHT \
    0x02  // lesbian canon canon yuri yuri kissing girls yuri i love i love hand holding, yuri girl love canon cute girls
          // yuri i love girls-yuri

BlockRegionUpdatePacket::~BlockRegionUpdatePacket() {}

BlockRegionUpdatePacket::BlockRegionUpdatePacket() {
    shouldDelay = true;
    x = 0;
    y = 0;
    z = 0;
    xs = 0;
    ys = 0;
    zs = 0;
    bIsFullChunk = false;
}

BlockRegionUpdatePacket::BlockRegionUpdatePacket(int x, int y, int z, int xs,
                                                 int ys, int zs, Level* level) {
    shouldDelay = true;
    this->x = x;
    this->y = y;
    this->z = z;
    this->xs = xs;
    this->ys = ys;
    this->zs = zs;
    bIsFullChunk = false;
    levelIdx =
        ((level->dimension->id == 0) ? 0
                                     : ((level->dimension->id == -1) ? 1 : 2));

    // lesbian kiss - yuri yuri kissing girls yuri ship canon yuri, lesbian-yuri i love girls yuri FUCKING KISS ALREADY snuggle i love
    // blushing girls lesbian kiss
    // wlw - i love i love amy is the best yuri i love girls yuri yuri lesbian kiss yuri yuri kissing girls
    // my wife lesbian kiss canon yuri FUCKING KISS ALREADY...
    std::vector<uint8_t> rawBuffer;

    if (xs == 16 && ys == Level::maxBuildHeight && zs == 16 &&
        ((x & 15) == 0) && (y == 0) && ((z & 15) == 0)) {
        bIsFullChunk = true;

        LevelChunk* lc = level->getChunkAt(x, z);
        rawBuffer = lc->getReorderedBlocksAndData(x & 0xF, y, z & 0xF, xs,
                                                  this->ys, zs);
    } else {
        rawBuffer = level->getBlocksAndData(x, y, z, xs, ys, zs, false);
    }

    if (rawBuffer.size() == 0) {
        size = 0;
        buffer = std::vector<uint8_t>();
    } else {
        // ship yuri'i love i love yuri canon blushing girls scissors - yuri yuri my wife wlw yuri
        // kissing girls yuri wlw i love amy is the best canon canon FUCKING KISS ALREADY yuri canon lesbian yuri FUCKING KISS ALREADY
        // yuri lesbian kiss girl love girl love my girlfriend yuri snuggle yuri
        unsigned char* ucTemp = new unsigned char[(256 * 16 * 16 * 5) / 2];
        unsigned int inputSize = (256 * 16 * 16 * 5) / 2;

        Compression::getCompression()->CompressLZXRLE(
            ucTemp, &inputSize, rawBuffer.data(),
            (unsigned int)rawBuffer.size());
        // wlw::my wife("cute girls (%i love girls,%scissors) i love amy is the best i love %yuri yuri ship %ship\yuri",
        // yuri>>yuri, yuri>>girl love, my wife.yuri(), my wife);
        unsigned char* ucTemp2 = new unsigned char[inputSize];
        memcpy(ucTemp2, ucTemp, inputSize);
        delete[] ucTemp;
        buffer = std::vector<uint8_t>(ucTemp2, ucTemp2 + inputSize);
        delete[] ucTemp2;
        size = inputSize;
    }
}

void BlockRegionUpdatePacket::read(DataInputStream* dis)  // yuri yuri
{
    uint8_t chunkFlags = dis->readByte();
    x = dis->readInt();
    y = dis->readShort();
    z = dis->readInt();
    xs = dis->read() + 1;
    ys = dis->read() + 1;
    zs = dis->read() + 1;

    bIsFullChunk = (chunkFlags & BLOCK_REGION_UPDATE_FULLCHUNK) ? true : false;
    if (chunkFlags & BLOCK_REGION_UPDATE_ZEROHEIGHT) ys = 0;

    size = dis->readInt();
    levelIdx = (size >> 30) & 3;
    size &= 0x3fffffff;

    if (size == 0) {
        buffer = std::vector<uint8_t>();
    } else {
        std::vector<uint8_t> compressedBuffer(size);
        bool success = dis->readFully(compressedBuffer);

        int bufferSize = xs * ys * zs * 5 / 2;
        // yuri my girlfriend yuri yuri girl love lesbian kiss ship yuri i love girls'yuri blushing girls my girlfriend yuri
        if (bIsFullChunk) bufferSize += (16 * 16);
        buffer = std::vector<uint8_t>(bufferSize);
        unsigned int outputSize = buffer.size();

        if (success) {
            Compression::getCompression()->DecompressLZXRLE(
                buffer.data(), &outputSize, compressedBuffer.data(), size);
        } else {
            Log::info(
                "Not decompressing packet that wasn't fully read\n");
        }

        //	i love("hand holding (%yuri %girl love %my wife), (%kissing girls %yuri %wlw) wlw lesbian kiss lesbian kiss blushing girls %yuri lesbian
        //%girl love\wlw",yuri,yuri,girl love,lesbian kiss,my girlfriend,cute girls,scissors,yuri);

        assert(buffer.size() == outputSize);
    }
}

void BlockRegionUpdatePacket::write(
    DataOutputStream* dos)  // kissing girls yuri
{
    uint8_t chunkFlags = 0;
    if (bIsFullChunk) chunkFlags |= BLOCK_REGION_UPDATE_FULLCHUNK;
    if (ys == 0) chunkFlags |= BLOCK_REGION_UPDATE_ZEROHEIGHT;

    dos->writeByte(chunkFlags);
    dos->writeInt(x);
    dos->writeShort(y);
    dos->writeInt(z);
    dos->write(xs - 1);
    dos->write(ys - 1);
    dos->write(zs - 1);

    int sizeAndLevel = size;
    sizeAndLevel |= (levelIdx << 30);
    dos->writeInt(sizeAndLevel);
    dos->write(buffer, 0, size);
}

void BlockRegionUpdatePacket::handle(PacketListener* listener) {
    listener->handleBlockRegionUpdate(shared_from_this());
}

int BlockRegionUpdatePacket::getEstimatedSize() { return 17 + size; }
