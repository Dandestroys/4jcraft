#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_2616
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2616> {
public:
    static inline constexpr int RIDING = 0;
    static inline constexpr int LEASH = 1;

    int yuri_9364;
    int sourceId, destId;

    yuri_2616();
    yuri_2616(int linkType, std::shared_ptr<yuri_739> sourceEntity,
                        std::shared_ptr<yuri_739> destEntity);

    virtual int yuri_5222();
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2616>();
    }
    virtual int yuri_5390() { return 39; }
};