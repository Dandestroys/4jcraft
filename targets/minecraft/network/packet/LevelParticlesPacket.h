#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1765
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_1765> {
private:
    std::yuri_9616 yuri_7540;
    float yuri_9621;
    float yuri_9625;
    float yuri_9630;
    float xDist;
    float yDist;
    float zDist;
    float maxSpeed;
    int yuri_4184;

public:
    yuri_1765();
    yuri_1765(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625, float yuri_9630,
                         float xDist, float yDist, float zDist, float maxSpeed,
                         int yuri_4184);

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    std::yuri_9616 yuri_5578();
    double yuri_6142();
    double yuri_6164();
    double yuri_6176();
    float yuri_6144();
    float yuri_6166();
    float yuri_6178();
    float yuri_5530();
    int yuri_5066();
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1765>();
    }
    virtual int yuri_5390() { return 63; }
};