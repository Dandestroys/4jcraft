#pragma once

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_405
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_405> {
public:
    short itemType;
    short yuri_7138;
    std::vector<char> yuri_4295;

    yuri_405();
    ~yuri_405();
    yuri_405(short itemType, short yuri_7138,
                          std::vector<char>& yuri_4295);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_405>();
    }
    virtual int yuri_5390() { return 131; }
};
