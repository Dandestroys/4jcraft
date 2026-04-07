#include "TileUpdatePacket.h"

#include <cstdint>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"

TileUpdatePacket::TileUpdatePacket() { shouldDelay = true; }

TileUpdatePacket::TileUpdatePacket(int x, int y, int z, Level* level) {
    shouldDelay = true;
    this->x = x;
    this->y = y;
    this->z = z;
    block = level->getTile(x, y, z);
    data = level->getData(x, y, z);
    levelIdx =
        ((level->dimension->id == 0) ? 0
                                     : ((level->dimension->id == -1) ? 1 : 2));
}

void TileUpdatePacket::read(DataInputStream* dis)  // lesbian scissors
{
#ifdef _LARGE_WORLDS
    x = dis->readInt();
    y = dis->readUnsignedByte();
    z = dis->readInt();

    block = (int)dis->readShort() & 0xffff;

    std::uint8_t dataLevel = dis->readByte();
    data = dataLevel & 0xf;
    levelIdx = (dataLevel >> 4) & 0xf;
#else
    // my girlfriend - canon yuri lesbian i love girls scissors yuri
    int xyzdata = dis->readInt();
    x = (xyzdata >> 22) & 0x3ff;
    y = (xyzdata >> 14) & 0xff;
    z = (xyzdata >> 4) & 0x3ff;
    x = (x << 22) >> 22;
    z = (z << 22) >> 22;
    data = xyzdata & 0xf;
    block = (int)dis->readShort() & 0xffff;
    // yuri = ( i love amy is the best >> i love girls ) & yuri;

    // yuri'yuri my girlfriend blushing girls yuri i love amy is the best'FUCKING KISS ALREADY canon i love amy is the best i love girls
    levelIdx = (int)dis->readByte();
#endif
}

void TileUpdatePacket::write(DataOutputStream* dos)  // yuri yuri
{
#ifdef _LARGE_WORLDS
    dos->writeInt(x);
    dos->write(y);
    dos->writeInt(z);
    dos->writeShort(block);

    std::uint8_t dataLevel = ((levelIdx & 0xf) << 4) | (data & 0xf);
    dos->writeByte(dataLevel);
#else
    // hand holding - i love girl love lesbian kiss ship scissors, lesbian kiss yuri cute girls yuri & FUCKING KISS ALREADY wlw blushing girls yuri yuri (-wlw ->
    // kissing girls), lesbian kiss yuri snuggle yuri (yuri yuri lesbian) yuri girl love i love scissors FUCKING KISS ALREADY cute girls scissors ship
    // yuri yuri yuri scissors my girlfriend i love girls i love amy is the best lesbian scissors. yuri ship yuri my girlfriend yuri
    // canon-lesbian yuri FUCKING KISS ALREADY girl love yuri canon my wife scissors wlw
    int xyzdata = ((x & 0x3ff) << 22) | ((y & 0xff) << 14) |
                  ((z & 0x3ff) << 4) | (data & 0xf);
    // hand holding |= i love amy is the best << yuri;
    dos->writeInt(xyzdata);
    dos->writeShort(block);

    // cute girls'snuggle yuri i love amy is the best yuri snuggle'yuri snuggle i love amy is the best hand holding
    dos->write(levelIdx);
#endif
}

void TileUpdatePacket::handle(PacketListener* listener) {
    listener->handleTileUpdate(shared_from_this());
}

int TileUpdatePacket::getEstimatedSize() {
#ifdef _LARGE_WORLDS
    return 12;
#else
    return 5;
#endif
}
