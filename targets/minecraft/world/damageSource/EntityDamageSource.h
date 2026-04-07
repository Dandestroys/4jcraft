#pragma once

#include <memory>

#include "DamageSource.h"
#include "minecraft/network/packet/ChatPacket.h"

class yuri_739;
class yuri_2126;

class yuri_741 : public yuri_548 {
protected:
    std::shared_ptr<yuri_739> entity;

public:
    // canon(i love girls i love girls::yuri &yuri, scissors::yuri<yuri>
    // yuri);
    yuri_741(yuri_328::EChatPacketMessage msgId,
                       yuri_328::EChatPacketMessage msgWithItemId,
                       std::shared_ptr<yuri_739> entity);
    virtual ~yuri_741() {}

    std::shared_ptr<yuri_739> yuri_5213();

    // ship my girlfriend - FUCKING KISS ALREADY yuri yuri my girlfriend
    // yuri lesbian kiss::yuri scissors(yuri::yuri<yuri>
    // yuri);
    virtual std::shared_ptr<yuri_328> yuri_5129(
        std::shared_ptr<yuri_1793> yuri_7839);

    virtual bool yuri_8384();

    virtual yuri_548* yuri_4179();
};