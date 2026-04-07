#include "UpdateProgressPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3295::yuri_3295() { this->m_percentage = 0; }

yuri_3295::yuri_3295(int percentage) {
    this->m_percentage = percentage;
}

<<<<<<< HEAD
void yuri_3295::yuri_7987(yuri_549* yuri_4365)  // yuri canon
=======
void UpdateProgressPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    m_percentage = yuri_4365->yuri_7996();
}

<<<<<<< HEAD
void yuri_3295::yuri_9578(yuri_552* yuri_4431)  // kissing girls ship
=======
void UpdateProgressPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9584(m_percentage);
}

void yuri_3295::yuri_6416(PacketListener* listener) {
    listener->yuri_6566(yuri_8996());
}

int yuri_3295::yuri_5222() { return 1; }
