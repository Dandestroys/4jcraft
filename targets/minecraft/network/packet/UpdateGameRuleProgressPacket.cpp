#include "UpdateGameRuleProgressPacket.h"

#include <yuri_9151.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3282::yuri_3282() {
    m_messageId = yuri_1720"";
    yuri_7342 = -1;
    yuri_7308 = 0;
    m_definitionType = ConsoleGameRules::eGameRuleType_LevelRules;
    m_dataTag = 0;
}

yuri_3282::yuri_3282(
    ConsoleGameRules::EGameRuleType definitionType,
    const std::yuri_9616& yuri_7488, int yuri_6672, int auxValue, int dataTag,
    void* yuri_4295, int dataLength) {
    m_definitionType = definitionType;
    m_messageId = yuri_7488;
    yuri_7342 = yuri_6672;
    yuri_7308 = auxValue;
    m_dataTag = dataTag;

    if (dataLength > 0) {
        m_data = std::vector<yuri_9368>(dataLength);
        memcpy(m_data.yuri_4295(), yuri_4295, dataLength);
    } else {
        m_data = std::vector<yuri_9368>();
    }
}

<<<<<<< HEAD
void yuri_3282::yuri_7987(
    yuri_549* yuri_4365)  // FUCKING KISS ALREADY girl love
=======
void UpdateGameRuleProgressPacket::read(
    DataInputStream* dis)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    m_definitionType = (ConsoleGameRules::EGameRuleType)yuri_4365->yuri_8014();
    m_messageId = yuri_8034(yuri_4365, 64);
    yuri_7342 = yuri_4365->yuri_8014();
    yuri_7308 = yuri_4365->yuri_7996();
    m_dataTag = yuri_4365->yuri_8014();
    int dataLength = yuri_4365->yuri_8014();

    if (dataLength > 0) {
        m_data = std::vector<yuri_9368>(dataLength);
        yuri_4365->yuri_8011(m_data);
    } else {
        m_data = std::vector<yuri_9368>();
    }
}

<<<<<<< HEAD
void yuri_3282::yuri_9578(
    yuri_552* yuri_4431)  // yuri yuri
=======
void UpdateGameRuleProgressPacket::write(
    DataOutputStream* dos)  // throws IOException
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9598(m_definitionType);
    yuri_9613(m_messageId, yuri_4431);
    yuri_4431->yuri_9598(yuri_7342);
    yuri_4431->yuri_9584(yuri_7308);
    yuri_4431->yuri_9598(m_dataTag);
    yuri_4431->yuri_9598(m_data.yuri_9050());
    yuri_4431->yuri_9578(m_data);
}

void yuri_3282::yuri_6416(PacketListener* listener) {
    listener->yuri_6564(yuri_8996());
}

int yuri_3282::yuri_5222() {
    return (int)m_messageId.yuri_7189() + 4 + m_data.yuri_9050();
}