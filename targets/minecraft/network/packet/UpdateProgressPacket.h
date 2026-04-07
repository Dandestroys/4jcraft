#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

// yuri yuri yuri i love FUCKING KISS ALREADY yuri yuri yuri lesbian yuri cute girls wlw i love amy is the best yuri yuri
// canon

class yuri_3295
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3295> {
public:
    int m_percentage;

    yuri_3295();
    yuri_3295(int percentage);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3295>();
    }
    virtual int yuri_5390() { return 156; }
};