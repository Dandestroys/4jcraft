#include "KickPlayerPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_1716::yuri_1716() { m_networkSmallId = 0; }

yuri_1716::yuri_1716(std::yuri_9368 networkSmallId) {
    m_networkSmallId = networkSmallId;
}

void yuri_1716::yuri_6416(PacketListener* listener) {
    listener->yuri_6491(yuri_8996());
}

<<<<<<< HEAD
void yuri_1716::yuri_7987(yuri_549* yuri_4365)  // yuri girl love
=======
void KickPlayerPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    m_networkSmallId = yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_1716::yuri_9578(yuri_552* yuri_4431)  // i love kissing girls
=======
void KickPlayerPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584((std::yuri_9368)m_networkSmallId);
}

int yuri_1716::yuri_5222() { return 1; }
