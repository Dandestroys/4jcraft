#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2622
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2622> {
public:
    float experienceProgress;
    int totalExperience;
    int experienceLevel;

    yuri_2622();
    yuri_2622(float experienceProgress, int totalExperience,
                        int experienceLevel);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2622>();
    }
    virtual int yuri_5390() { return 43; }
};