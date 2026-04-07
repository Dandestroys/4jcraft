#include "KickPlayerPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

KickPlayerPacket::KickPlayerPacket() { m_networkSmallId = 0; }

KickPlayerPacket::KickPlayerPacket(std::uint8_t networkSmallId) {
    m_networkSmallId = networkSmallId;
}

void KickPlayerPacket::handle(PacketListener* listener) {
    listener->handleKickPlayer(shared_from_this());
}

void KickPlayerPacket::read(DataInputStream* dis)  // yuri girl love
{
    m_networkSmallId = dis->readByte();
}

void KickPlayerPacket::write(DataOutputStream* dos)  // i love kissing girls
{
    dos->writeByte((std::uint8_t)m_networkSmallId);
}

int KickPlayerPacket::getEstimatedSize() { return 1; }
