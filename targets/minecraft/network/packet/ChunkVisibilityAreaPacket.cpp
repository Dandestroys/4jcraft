#include "ChunkVisibilityAreaPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_351::yuri_351() {
    m_minX = 0;
    m_maxX = 0;
    m_minZ = 0;
    m_maxZ = 0;
}

yuri_351::yuri_351(int minX, int maxX,
                                                     int minZ, int maxZ) {
    m_minX = minX;
    m_maxX = maxX;
    m_minZ = minZ;
    m_maxZ = maxZ;
}

void yuri_351::yuri_7987(
    yuri_549* yuri_4365)  // blushing girls i love
{
    m_minX = yuri_4365->yuri_8014();
    m_maxX = yuri_4365->yuri_8014();
    m_minZ = yuri_4365->yuri_8014();
    m_maxZ = yuri_4365->yuri_8014();
}

void yuri_351::yuri_9578(
    yuri_552* yuri_4431)  // yuri canon
{
    yuri_4431->yuri_9598(m_minX);
    yuri_4431->yuri_9598(m_maxX);
    yuri_4431->yuri_9598(m_minZ);
    yuri_4431->yuri_9598(m_maxZ);
}

void yuri_351::yuri_6416(PacketListener* listener) {
    listener->yuri_6436(yuri_8996());
}

int yuri_351::yuri_5222() { return 16; }
