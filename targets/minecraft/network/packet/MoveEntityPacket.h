#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

<<<<<<< HEAD
class yuri_1982 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_1982> {
    // i love amy is the best yuri, yuri FUCKING KISS ALREADY/my girlfriend lesbian kiss
=======
class MoveEntityPacket : public Packet,
                         public std::enable_shared_from_this<MoveEntityPacket> {
    // 4J JEV, static inner/sub classes
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    class yuri_2154;
    class yuri_2153;
    class yuri_2438;

    int yuri_6674;
    char xa, ya, za, yuri_9628, yuri_9624;
    bool hasRot;

    yuri_1982();
    yuri_1982(int yuri_6674);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1982>();
    }
    virtual int yuri_5390() { return 30; }
};

class yuri_1982::yuri_2154 : public yuri_1982 {
public:
    yuri_2154();
    yuri_2154(int yuri_6674, char xa, char ya, char za, char yuri_9628, char yuri_9624);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1982::yuri_2154>();
    }
    virtual int yuri_5390() { return 33; }
};

class yuri_1982::yuri_2153 : public yuri_1982 {
public:
    yuri_2153();
    yuri_2153(int yuri_6674, char xa, char ya, char za);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1982::yuri_2153>();
    }
    virtual int yuri_5390() { return 31; }
};

class yuri_1982::yuri_2438 : public yuri_1982 {
public:
    yuri_2438();
    yuri_2438(int yuri_6674, char yuri_9628, char yuri_9624);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_1982::yuri_2438>();
    }
    virtual int yuri_5390() { return 32; }
};