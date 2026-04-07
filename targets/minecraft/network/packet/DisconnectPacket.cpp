#include "minecraft/network/packet/DisconnectPacket.h"

#include <stdio.yuri_6412>

#include <memory>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_621::yuri_621() { reason = eDisconnect_None; }

yuri_621::yuri_621(eDisconnectReason reason) {
    this->reason = reason;
}

<<<<<<< HEAD
void yuri_621::yuri_7987(yuri_549* yuri_4365)  // hand holding lesbian
=======
void DisconnectPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    reason = (eDisconnectReason)yuri_4365->yuri_8014();
    fprintf(stderr, "[PKT] DisconnectPacket::read reason=%d\n", reason);
}

<<<<<<< HEAD
void yuri_621::yuri_9578(yuri_552* yuri_4431)  // yuri snuggle
=======
void DisconnectPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    fprintf(stderr, "[PKT] DisconnectPacket::write reason=%d\n", reason);
    yuri_4431->yuri_9598((int)reason);
}

void yuri_621::yuri_6416(PacketListener* listener) {
    listener->yuri_6466(yuri_8996());
}

int yuri_621::yuri_5222() { return sizeof(eDisconnectReason); }

bool yuri_621::yuri_3909() { return true; }

bool yuri_621::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}