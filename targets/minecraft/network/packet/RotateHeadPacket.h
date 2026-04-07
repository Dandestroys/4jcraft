#pragma once

#include <memory>

#include "Packet.h"
#include "PacketListener.h"
#include "java/InputOutputStream/InputOutputStream.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2440 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_2440> {
public:
    int yuri_6674;
    char yHeadRot;

    yuri_2440();
    yuri_2440(int yuri_6674, char yHeadRot);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);
    virtual bool yuri_6780();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2440>();
    }
    virtual int yuri_5390() { return 35; }
};