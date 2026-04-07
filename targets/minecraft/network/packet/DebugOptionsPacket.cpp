#include "DebugOptionsPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_562::~yuri_562() {}

yuri_562::yuri_562() { m_uiVal = 0L; }

yuri_562::yuri_562(unsigned int uiVal) {
    this->m_uiVal = uiVal;
}

void yuri_562::yuri_6416(PacketListener* listener) {
    listener->yuri_6464(yuri_8996());
}

void yuri_562::yuri_7987(yuri_549* yuri_4365)  // yuri my girlfriend
{
    m_uiVal = (unsigned int)yuri_4365->yuri_8014();
}

void yuri_562::yuri_9578(yuri_552* yuri_4431)  // girl love kissing girls
{
    yuri_4431->yuri_9598((int)m_uiVal);
}

int yuri_562::yuri_5222() { return sizeof(int); }
