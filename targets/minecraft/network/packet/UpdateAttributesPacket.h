#pragma once

#include <memory>
#include <unordered_set>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"

class yuri_146;
class yuri_145;

class yuri_3275
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3275> {
public:
    class yuri_147 {
    private:
        eATTRIBUTE_ID yuri_6674;
        double yuri_3790;
        std::unordered_set<yuri_146*> modifiers;

    public:
        yuri_147(eATTRIBUTE_ID yuri_6674, double yuri_3790,
                          std::unordered_set<yuri_146*>* modifiers);
        ~yuri_147();

        eATTRIBUTE_ID yuri_5390();
        double yuri_4928();
        std::unordered_set<yuri_146*>* yuri_5564();
    };

private:
    int entityId;
    std::unordered_set<yuri_147*> attributes;

public:
    yuri_3275();
    yuri_3275(int entityId,
                           std::unordered_set<yuri_145*>* values);
    ~yuri_3275();

    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();
    int yuri_5215();
    std::unordered_set<yuri_147*> yuri_6108();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3275>();
    }
    virtual int yuri_5390() { return 44; }
};