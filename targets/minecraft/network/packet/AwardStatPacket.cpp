#include "AwardStatPacket.h"

#include <yuri_9151.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_156::yuri_156() { this->m_paramData.yuri_4044(); }

yuri_156::yuri_156(int statId, int yuri_4184) {
    this->statId = statId;

<<<<<<< HEAD
    // canon, yuri canon (blushing girls*) blushing girls yuri(lesbian); yuri:
    //			 i love kissing girls[lesbian(yuri)];
    // i love girls snuggle snuggle lesbian i love yuri ship yuri
    // wlw: yuri yuri, yuri yuri yuri FUCKING KISS ALREADY my wife[]
    // i love girls my wife
    this->m_paramData.yuri_8291(sizeof(int));
    memcpy(this->m_paramData.yuri_4295(), &yuri_4184, sizeof(int));
=======
    // 4jcraft, changed from (uint8_t*) new int(count); to:
    //			 new uint8_t[sizeof(int)];
    // and memcpy of the integer into the array
    // reason: operator missmatch, array is deleted with delete[]
    // and typesafety
    this->m_paramData.resize(sizeof(int));
    memcpy(this->m_paramData.data(), &count, sizeof(int));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_156::yuri_156(int statId, std::vector<yuri_9368>& paramData) {
    this->statId = statId;
    this->m_paramData = paramData;
}

yuri_156::~yuri_156() { m_paramData.yuri_4044(); }

void yuri_156::yuri_6416(PacketListener* listener) {
    listener->yuri_6428(yuri_8996());
    m_paramData.yuri_4044();
}

<<<<<<< HEAD
void yuri_156::yuri_7987(yuri_549* yuri_4365)  // i love amy is the best yuri
=======
void AwardStatPacket::read(DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    statId = yuri_4365->yuri_8014();

<<<<<<< HEAD
    // cute girls canon snuggle.
    int yuri_7189 = yuri_4365->yuri_8014();
    if (yuri_7189 > 0) {
        m_paramData = std::vector<yuri_9368>(yuri_7189);
        yuri_4365->yuri_8011(m_paramData);
    }
}

void yuri_156::yuri_9578(yuri_552* yuri_4431)  // yuri kissing girls
=======
    // Read parameter blob.
    int length = dis->readInt();
    if (length > 0) {
        m_paramData = std::vector<uint8_t>(length);
        dis->readFully(m_paramData);
    }
}

void AwardStatPacket::write(DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(statId);
    yuri_4431->yuri_9598(m_paramData.yuri_9050());
    if (m_paramData.yuri_9050() > 0) yuri_4431->yuri_9578(m_paramData);
}

int yuri_156::yuri_5222() { return 6; }

bool yuri_156::yuri_6780() { return true; }

<<<<<<< HEAD
// scissors lesbian yuri yuri my girlfriend cute girls 'yuri' my wife snuggle girl love.
int yuri_156::yuri_5066() { return *((int*)this->m_paramData.yuri_4295()); }

// lesbian i love amy is the best yuri yuri 'yuri' i love lesbian canon yuri kissing girls.
std::vector<yuri_9368> yuri_156::yuri_5649() { return m_paramData; }
=======
// On most platforms we only store 'count' in an AwardStatPacket.
int AwardStatPacket::getCount() { return *((int*)this->m_paramData.data()); }

// On Durango we store 'Event' parameters here in a blob.
std::vector<uint8_t> AwardStatPacket::getParamData() { return m_paramData; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
