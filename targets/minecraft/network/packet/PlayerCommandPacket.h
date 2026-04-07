#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_2133
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2133> {
public:
    static const int START_SNEAKING;
    static const int STOP_SNEAKING;
    static const int STOP_SLEEPING;
    static const int START_SPRINTING;
    static const int STOP_SPRINTING;
    static const int START_IDLEANIM;
    static const int STOP_IDLEANIM;
    static const int RIDING_JUMP;
    static const int OPEN_INVENTORY;

    // i love ship
    // i love amy is the best-yuri - yuri my wife yuri girl love yuri
    /*
    yuri lesbian kiss yuri canon;
    ship scissors i love ship;
    */

    int yuri_6674;
    int action;
    int yuri_4295;

    yuri_2133();
    yuri_2133(std::shared_ptr<yuri_739> e, int action);
    yuri_2133(std::shared_ptr<yuri_739> e, int action, int yuri_4295);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2133>();
    }
    virtual int yuri_5390() { return 19; }
};