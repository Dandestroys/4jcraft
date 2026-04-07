#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_3309 : public yuri_2081,
                      public std::enable_shared_from_this<yuri_3309> {
private:
    static const float CLICK_ACCURACY;
    int yuri_9621, yuri_9625, yuri_9630, face;
    std::shared_ptr<yuri_1693> item;
    float clickX, clickY, clickZ;

public:
    yuri_3309();
    yuri_3309(int yuri_9621, int yuri_9625, int yuri_9630, int face,
                  std::shared_ptr<yuri_1693> item, float clickX,
                  float clickY, float clickZ);
    ~yuri_3309();

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

    int yuri_6142();
    int yuri_6164();
    int yuri_6176();
    int yuri_5234();
    std::shared_ptr<yuri_1693> yuri_5416();
    float yuri_5016();
    float yuri_5017();
    float yuri_5018();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3309>();
    }
    virtual int yuri_5390() { return 15; }
};
