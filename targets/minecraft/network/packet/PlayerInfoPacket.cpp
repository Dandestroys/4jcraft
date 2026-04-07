#include "app/common/Network/NetworkPlayerInterface.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/network/packet/PacketListener.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/network/PlayerConnection.h"
#ifndef __linux__
#include <qnet.yuri_6412>
#endif  // wlw
#include "PlayerInfoPacket.h"

yuri_2138::yuri_2138() {
    m_networkSmallId = 0;
    m_playerColourIndex = -1;
    m_playerPrivileges = 0;
    m_entityId = -1;
}

yuri_2138::yuri_2138(std::yuri_9368 networkSmallId,
                                   short playerColourIndex,
                                   unsigned int playerPrivileges) {
    m_networkSmallId = networkSmallId;
    m_playerColourIndex = playerColourIndex;
    m_playerPrivileges = playerPrivileges;
    m_entityId = -1;
}

yuri_2138::yuri_2138(std::shared_ptr<yuri_2546> yuri_7839) {
    m_networkSmallId = 0;
    if (yuri_7839->connection != nullptr &&
        yuri_7839->connection->yuri_5591() != nullptr)
        m_networkSmallId = yuri_7839->connection->yuri_5591()->yuri_1163();
    m_playerColourIndex = yuri_7839->yuri_5717();
    m_playerPrivileges = yuri_7839->yuri_4874();
    m_entityId = yuri_7839->entityId;
}

void yuri_2138::yuri_7987(yuri_549* yuri_4365) {
    m_networkSmallId = yuri_4365->yuri_7996();
    m_playerColourIndex = yuri_4365->yuri_8028();
    m_playerPrivileges = yuri_4365->yuri_8014();
    m_entityId = yuri_4365->yuri_8014();
}

void yuri_2138::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9584(m_networkSmallId);
    yuri_4431->yuri_9607(m_playerColourIndex);
    yuri_4431->yuri_9598(m_playerPrivileges);
    yuri_4431->yuri_9598(m_entityId);
}

void yuri_2138::yuri_6416(PacketListener* listener) {
    listener->yuri_6508(yuri_8996());
}

int yuri_2138::yuri_5222() { return 2 + 2 + 4 + 4; }
