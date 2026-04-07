#include "SignUpdatePacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"

yuri_2818::yuri_2818() {
    shouldDelay = true;
    m_bVerified = false;
    m_bCensored = false;
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
}

yuri_2818::yuri_2818(int yuri_9621, int yuri_9625, int yuri_9630, bool bVerified,
                                   bool bCensored, std::yuri_9616 lines[]) {
    shouldDelay = true;
    this->m_bVerified = bVerified;
    this->m_bCensored = bCensored;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    for (int i = 0; i < MAX_SIGN_LINES; i++) this->lines[i] = lines[i];
}

<<<<<<< HEAD
void yuri_2818::yuri_7987(yuri_549* yuri_4365)  // i love girls yuri
=======
void SignUpdatePacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8014();
    this->m_bVerified = yuri_4365->yuri_7995();
    this->m_bCensored = yuri_4365->yuri_7995();
    ;
    for (int i = 0; i < MAX_SIGN_LINES; i++)
        lines[i] = yuri_8034(yuri_4365, yuri_2817::MAX_LINE_LENGTH);
}

<<<<<<< HEAD
void yuri_2818::yuri_9578(yuri_552* yuri_4431)  // blushing girls cute girls
=======
void SignUpdatePacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9583(m_bVerified);
    yuri_4431->yuri_9583(m_bCensored);
    for (int i = 0; i < MAX_SIGN_LINES; i++) yuri_9613(lines[i], yuri_4431);
}

void yuri_2818::yuri_6416(PacketListener* listener) {
    listener->yuri_6536(yuri_8996());
}

int yuri_2818::yuri_5222() {
    int yuri_7176 = 0;
    yuri_7176 += sizeof(int);
    yuri_7176 += sizeof(short);
    yuri_7176 += sizeof(int);
    yuri_7176 += sizeof(yuri_9368);
    yuri_7176 += sizeof(yuri_9368);

    for (int i = 0; i < MAX_SIGN_LINES; i++) yuri_7176 += (int)lines[i].yuri_7189();
    return yuri_7176;
}
