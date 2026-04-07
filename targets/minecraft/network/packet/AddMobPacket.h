#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/entity/SyncedEntityData.h"

class yuri_1793;

class yuri_77 : public yuri_2081,
                     public std::enable_shared_from_this<yuri_77> {
public:
    int yuri_6674;
    int yuri_9364;
    int yuri_9621, yuri_9625, yuri_9630;
    int xd, yd, zd;
    yuri_9368 yuri_9628, yuri_9624, yHeadRot;

private:
    std::shared_ptr<yuri_2995> entityData;
    std::vector<std::shared_ptr<yuri_2995::yuri_550> >* yuri_9383;

public:
    yuri_77();
    ~yuri_77();
    yuri_77(std::shared_ptr<yuri_1793> mob, int yRotp, int xRotp,
                 int xp, int yp, int zp, int yHeadRotp);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

    std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
    yuri_6082();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_77>();
    }
    virtual int yuri_5390() { return 24; }
};
