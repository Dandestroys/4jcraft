#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_44;

class yuri_2127
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2127> {
private:
    static const int FLAG_INVULNERABLE = 1 << 0;
    static const int FLAG_FLYING = 1 << 1;
    static const int FLAG_CAN_FLY = 1 << 2;
    static const int FLAG_INSTABUILD = 1 << 3;

    bool invulnerable;
    bool _isFlying;
    bool _canFly;
    bool instabuild;
    float flyingSpeed;
    float walkingSpeed;

public:
    yuri_2127();
    yuri_2127(yuri_44* abilities);

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();
    // snuggle::girl love yuri();
    bool yuri_6935();
    void yuri_8679(bool invulnerable);
    bool yuri_6873();
    void yuri_8609(bool flying);
    bool yuri_3926();
    void yuri_8501(bool yuri_3926);
    bool yuri_3931();
    void yuri_8675(bool instabuild);
    float yuri_5261();
    void yuri_8610(float flySpeed);
    float yuri_6121();
    void yuri_8951(float walkingSpeed);
    bool yuri_3909();
    bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2127>();
    }
    virtual int yuri_5390() { return 202; }
};