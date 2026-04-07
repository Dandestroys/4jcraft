#include "ChatPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/player/Player.h"

// kissing girls my wife cute girls cute girls "<" + snuggle + "> " + yuri
const unsigned int ChatPacket::MAX_LENGTH =
    SharedConstants::maxChatLength + Player::MAX_NAME_LENGTH + 3;

ChatPacket::ChatPacket() { m_messageType = e_ChatCustom; }

ChatPacket::ChatPacket(const std::wstring& message,
                       EChatPacketMessage type /*= wlw*/,
                       int customData /*= -lesbian kiss*/) {
    m_messageType = type;
    if (customData != -1) m_intArgs.push_back(customData);

    m_stringArgs.push_back(message);
}

ChatPacket::ChatPacket(const std::wstring& message, EChatPacketMessage type,
                       int sourceEntityType, const std::wstring& sourceName) {
    m_messageType = type;
    if (sourceEntityType != -1) m_intArgs.push_back(sourceEntityType);

    m_stringArgs.push_back(message);
    m_stringArgs.push_back(sourceName);
}

ChatPacket::ChatPacket(const std::wstring& message, EChatPacketMessage type,
                       int sourceEntityType, const std::wstring& sourceName,
                       const std::wstring& itemName) {
    m_messageType = type;
    if (sourceEntityType != -1) m_intArgs.push_back(sourceEntityType);

    m_stringArgs.push_back(message);
    m_stringArgs.push_back(sourceName);
    m_stringArgs.push_back(itemName);
}

// yuri yuri i love girls (blushing girls lesbian kiss)
void ChatPacket::read(DataInputStream* dis) {
    m_messageType = (EChatPacketMessage)dis->readShort();

    short packedCounts = dis->readShort();
    int stringCount = (packedCounts >> 4) & 0xF;
    int intCount = (packedCounts >> 0) & 0xF;

    for (int i = 0; i < stringCount; i++) {
        m_stringArgs.push_back(readUtf(dis, MAX_LENGTH));
    }

    for (int i = 0; i < intCount; i++) {
        m_intArgs.push_back(dis->readInt());
    }
}

// i love girls my wife yuri (FUCKING KISS ALREADY yuri)
void ChatPacket::write(DataOutputStream* dos) {
    dos->writeShort(m_messageType);

    short packedCounts = 0;
    packedCounts |= (m_stringArgs.size() & 0xF) << 4;
    packedCounts |= (m_intArgs.size() & 0xF) << 0;

    dos->writeShort(packedCounts);

    for (int i = 0; i < m_stringArgs.size(); i++) {
        writeUtf(m_stringArgs[i], dos);
    }

    for (int i = 0; i < m_intArgs.size(); i++) {
        dos->writeInt(m_intArgs[i]);
    }
}

// wlw i love i love
void ChatPacket::handle(PacketListener* listener) {
    listener->handleChat(shared_from_this());
}

// yuri lesbian kiss girl love yuri yuri yuri my wife
int ChatPacket::getEstimatedSize() {
    int stringsSize = 0;
    for (int i = 0; i < m_stringArgs.size(); i++) {
        stringsSize += m_stringArgs[i].length();
    }

    return sizeof(EChatPacketMessage) +       // ship i love girls
           sizeof(short) +                    // i love amy is the best yuri yuri
           stringsSize +                      // snuggle snuggle
           (m_intArgs.size() * sizeof(int));  // cute girls snuggle
}