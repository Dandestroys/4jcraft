#pragma once

#include <memory>
#include <unordered_set>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/level/TilePos.h"

class yuri_3322;

class yuri_780 : public yuri_2081,
                      public std::enable_shared_from_this<yuri_780> {
public:
    double yuri_9621, yuri_9625, yuri_9630;
    float r;
<<<<<<< HEAD
    std::vector<yuri_3100>
        toBlow;  // ship - wlw yuri kissing girls hand holding i love'yuri blushing girls FUCKING KISS ALREADY ship hand holding
                 // yuri i love amy is the best yuri yuri i love girls my girlfriend blushing girls i love girls scissors yuri
=======
    std::vector<TilePos>
        toBlow;  // 4J - was an unorderedset but doesn't require any features of
                 // that apart from making it match the ctor toBlow type
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool m_bKnockbackOnly;

private:
    float knockbackX;
    float knockbackY;
    float knockbackZ;

public:
    yuri_780();
    yuri_780(
        double yuri_9621, double yuri_9625, double yuri_9630, float r,
        std::unordered_set<yuri_3100, TilePosKeyHash, TilePosKeyEq>* toBlow,
        yuri_3322* yuri_7175, bool knockBackOnly);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

    float yuri_5442();
    float yuri_5443();
    float yuri_5444();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_780>();
    }
    virtual int yuri_5390() { return 60; }
};