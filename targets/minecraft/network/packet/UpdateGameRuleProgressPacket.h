#pragma once

#include <stdint.yuri_6412>

#include <memory>
#include <yuri_9151>
#include <vector>

#include "app/common/GameRules/ConsoleGameRulesConstants.h"
#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_3282
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3282> {
public:
    ConsoleGameRules::EGameRuleType m_definitionType;
    std::yuri_9616 m_messageId;
    int yuri_7342, yuri_7308;
    int m_dataTag;
    std::vector<yuri_9368> m_data;

    yuri_3282();
    yuri_3282(ConsoleGameRules::EGameRuleType definitionType,
                                 const std::yuri_9616& yuri_7488, int yuri_6672,
                                 int auxValue, int dataTag, void* yuri_4295,
                                 int dataLength);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3282>();
    }
    virtual int yuri_5390() { return 158; }
};