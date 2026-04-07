#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1770 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_1770> {
public:
    static const float PITCH_ACCURACY;
    static const float LOCATION_ACCURACY;

private:
    int sound;
    int yuri_9621;
    int yuri_9625;
    int yuri_9630;
    float volume;
    // int pitch;
    float pitch;

public:
    yuri_1770();
    yuri_1770(int iSound, double yuri_9621, double yuri_9625, double yuri_9630, float volume,
                     float pitch);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5936();
    double yuri_6142();
    double yuri_6164();
    double yuri_6176();
    float yuri_6119();
    float yuri_5695();
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1770>();
    }
    virtual int yuri_5390() { return 62; }
};
