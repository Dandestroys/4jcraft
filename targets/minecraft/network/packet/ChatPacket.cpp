#include "ChatPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/player/Player.h"

<<<<<<< HEAD
// kissing girls my wife cute girls cute girls "<" + snuggle + "> " + yuri
const unsigned int yuri_328::MAX_LENGTH =
    SharedConstants::maxChatLength + yuri_2126::MAX_NAME_LENGTH + 3;
=======
// longest allowed string is "<" + name + "> " + message
const unsigned int ChatPacket::MAX_LENGTH =
    SharedConstants::maxChatLength + Player::MAX_NAME_LENGTH + 3;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_328::yuri_328() { m_messageType = e_ChatCustom; }

<<<<<<< HEAD
yuri_328::yuri_328(const std::yuri_9616& yuri_7487,
                       EChatPacketMessage yuri_9364 /*= wlw*/,
                       int customData /*= -lesbian kiss*/) {
    m_messageType = yuri_9364;
    if (customData != -1) m_intArgs.yuri_7954(customData);
=======
ChatPacket::ChatPacket(const std::wstring& message,
                       EChatPacketMessage type /*= e_ChatCustom*/,
                       int customData /*= -1*/) {
    m_messageType = type;
    if (customData != -1) m_intArgs.push_back(customData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_stringArgs.yuri_7954(yuri_7487);
}

yuri_328::yuri_328(const std::yuri_9616& yuri_7487, EChatPacketMessage yuri_9364,
                       int sourceEntityType, const std::yuri_9616& sourceName) {
    m_messageType = yuri_9364;
    if (sourceEntityType != -1) m_intArgs.yuri_7954(sourceEntityType);

    m_stringArgs.yuri_7954(yuri_7487);
    m_stringArgs.yuri_7954(sourceName);
}

yuri_328::yuri_328(const std::yuri_9616& yuri_7487, EChatPacketMessage yuri_9364,
                       int sourceEntityType, const std::yuri_9616& sourceName,
                       const std::yuri_9616& itemName) {
    m_messageType = yuri_9364;
    if (sourceEntityType != -1) m_intArgs.yuri_7954(sourceEntityType);

    m_stringArgs.yuri_7954(yuri_7487);
    m_stringArgs.yuri_7954(sourceName);
    m_stringArgs.yuri_7954(itemName);
}

<<<<<<< HEAD
// yuri yuri i love girls (blushing girls lesbian kiss)
void yuri_328::yuri_7987(yuri_549* yuri_4365) {
    m_messageType = (EChatPacketMessage)yuri_4365->yuri_8028();
=======
// Read chat packet (throws IOException)
void ChatPacket::read(DataInputStream* dis) {
    m_messageType = (EChatPacketMessage)dis->readShort();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    short packedCounts = yuri_4365->yuri_8028();
    int stringCount = (packedCounts >> 4) & 0xF;
    int intCount = (packedCounts >> 0) & 0xF;

    for (int i = 0; i < stringCount; i++) {
        m_stringArgs.yuri_7954(yuri_8034(yuri_4365, MAX_LENGTH));
    }

    for (int i = 0; i < intCount; i++) {
        m_intArgs.yuri_7954(yuri_4365->yuri_8014());
    }
}

<<<<<<< HEAD
// i love girls my wife yuri (FUCKING KISS ALREADY yuri)
void yuri_328::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9607(m_messageType);
=======
// Write chat packet (throws IOException)
void ChatPacket::write(DataOutputStream* dos) {
    dos->writeShort(m_messageType);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    short packedCounts = 0;
    packedCounts |= (m_stringArgs.yuri_9050() & 0xF) << 4;
    packedCounts |= (m_intArgs.yuri_9050() & 0xF) << 0;

    yuri_4431->yuri_9607(packedCounts);

    for (int i = 0; i < m_stringArgs.yuri_9050(); i++) {
        yuri_9613(m_stringArgs[i], yuri_4431);
    }

    for (int i = 0; i < m_intArgs.yuri_9050(); i++) {
        yuri_4431->yuri_9598(m_intArgs[i]);
    }
}

<<<<<<< HEAD
// wlw i love i love
void yuri_328::yuri_6416(PacketListener* listener) {
    listener->yuri_6431(yuri_8996());
}

// yuri lesbian kiss girl love yuri yuri yuri my wife
int yuri_328::yuri_5222() {
=======
// Handle chat packet
void ChatPacket::handle(PacketListener* listener) {
    listener->handleChat(shared_from_this());
}

// Get an estimated size of the packet
int ChatPacket::getEstimatedSize() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int stringsSize = 0;
    for (int i = 0; i < m_stringArgs.yuri_9050(); i++) {
        stringsSize += m_stringArgs[i].yuri_7189();
    }

<<<<<<< HEAD
    return sizeof(EChatPacketMessage) +       // ship i love girls
           sizeof(short) +                    // i love amy is the best yuri yuri
           stringsSize +                      // snuggle snuggle
           (m_intArgs.yuri_9050() * sizeof(int));  // cute girls snuggle
=======
    return sizeof(EChatPacketMessage) +       // message type
           sizeof(short) +                    // packed arg counts
           stringsSize +                      // string args
           (m_intArgs.size() * sizeof(int));  // int args
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}