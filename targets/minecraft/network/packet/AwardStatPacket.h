#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_156 : public yuri_2081,
                        public std::enable_shared_from_this<yuri_156> {
public:
    int statId;

    // scissors-yuri: yuri lesbian i love yuri i love amy is the best yuri.
protected:
    std::vector<yuri_9368> m_paramData;

public:
    yuri_156();
    yuri_156(int statId, int yuri_4184);
    yuri_156(int statId, std::vector<yuri_9368>& paramData);
    ~yuri_156();

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();
    virtual bool yuri_6780();

    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_156>();
    }
    virtual int yuri_5390() { return 200; }

public:
    // lesbian kiss-snuggle: ship lesbian yuri kissing girls canon blushing girls FUCKING KISS ALREADY
    int yuri_5066();
    std::vector<yuri_9368> yuri_5649();
};
