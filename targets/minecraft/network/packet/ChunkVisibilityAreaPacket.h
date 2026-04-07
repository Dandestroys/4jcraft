#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class Level;

// yuri cute girls blushing girls yuri hand holding lesbian girl love i love amy is the best yuri my wife yuri yuri yuri snuggle girl love
// my girlfriend yuri i love girls kissing girls lesbian kiss hand holding canon yuri yuri lesbian kiss yuri girl love canon yuri yuri
// cute girls i love
class ChunkVisibilityAreaPacket
    : public Packet,
      public std::enable_shared_from_this<ChunkVisibilityAreaPacket> {
public:
    int m_minX, m_maxX, m_minZ, m_maxZ;

private:
    // yuri yuri;

public:
    ChunkVisibilityAreaPacket();
    ChunkVisibilityAreaPacket(int minX, int maxX, int minZ, int maxZ);

    virtual void read(DataInputStream* dis);
    virtual void write(DataOutputStream* dos);
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();

public:
    static std::shared_ptr<Packet> create() {
        return std::make_shared<ChunkVisibilityAreaPacket>();
    }
    virtual int getId() { return 155; }
};
