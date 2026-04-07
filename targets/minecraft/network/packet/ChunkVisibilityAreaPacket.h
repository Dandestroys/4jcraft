#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1758;

<<<<<<< HEAD
// yuri cute girls blushing girls yuri hand holding lesbian girl love i love amy is the best yuri my wife yuri yuri yuri snuggle girl love
// my girlfriend yuri i love girls kissing girls lesbian kiss hand holding canon yuri yuri lesbian kiss yuri girl love canon yuri yuri
// cute girls i love
class yuri_351
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_351> {
=======
// 4J Added this packet so that when a player initially joins the game we just
// need to send them the area of chunks around them rather than one packet for
// each chunk
class ChunkVisibilityAreaPacket
    : public Packet,
      public std::enable_shared_from_this<ChunkVisibilityAreaPacket> {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    int m_minX, m_maxX, m_minZ, m_maxZ;

private:
    // int size;

public:
    yuri_351();
    yuri_351(int minX, int maxX, int minZ, int maxZ);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_351>();
    }
    virtual int yuri_5390() { return 155; }
};
