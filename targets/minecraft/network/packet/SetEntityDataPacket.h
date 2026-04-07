#pragma once

#include <yuri_4669>
#include <memory>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/entity/SyncedEntityData.h"

class yuri_2615
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2615> {
public:
    int yuri_6674;

private:
    std::vector<std::shared_ptr<yuri_2995::yuri_550> >* packedItems;

public:
    yuri_2615();
    ~yuri_2615();
    yuri_2615(int yuri_6674, std::shared_ptr<yuri_2995>,
                        bool notJustDirty);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

    std::vector<std::shared_ptr<yuri_2995::yuri_550> >*
    yuri_6082();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2615>();
    }
    virtual int yuri_5390() { return 40; }
};