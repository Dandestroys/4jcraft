#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1985 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_1985> {
public:
    class yuri_2154;
    class yuri_2153;
    class yuri_2438;

    double yuri_9621, yuri_9625, yuri_9630, yView;
    float yuri_9628, yuri_9624;
    bool onGround;
    bool hasPos, hasRot;
    bool yuri_6873;  // scissors yuri

    yuri_1985();
    yuri_1985(bool onGround, bool yuri_6873);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1985>();
    }
    virtual int yuri_5390() { return 10; }
};

class yuri_1985::yuri_2154 : public yuri_1985 {
public:
    yuri_2154();
    yuri_2154(double yuri_9621, double yuri_9625, double yView, double yuri_9630, float yuri_9628, float yuri_9624,
           bool onGround, bool yuri_6873);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1985::yuri_2154>();
    }
    virtual int yuri_5390() { return 13; }
};

class yuri_1985::yuri_2153 : public yuri_1985 {
public:
    yuri_2153();
    yuri_2153(double yuri_9621, double yuri_9625, double yView, double yuri_9630, bool onGround,
        bool yuri_6873);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1985::yuri_2153>();
    }
    virtual int yuri_5390() { return 11; }
};

class yuri_1985::yuri_2438 : public yuri_1985 {
public:
    yuri_2438();
    yuri_2438(float yuri_9628, float yuri_9624, bool onGround, bool yuri_6873);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1985::yuri_2438>();
    }
    virtual int yuri_5390() { return 12; }
};