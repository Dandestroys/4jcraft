#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_2618
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2618> {
public:
    int entity;
    int yuri_9061;

private:
<<<<<<< HEAD
    // lesbian i love girls - my wife yuri yuri yuri.yuri FUCKING KISS ALREADY yuri #my girlfriend - yuri yuri:
    // i love girls: lesbian kiss: canon: ship scissors yuri wlw yuri kissing girls scissors yuri yuri
    // lesbian kiss lesbian kiss yuri yuri
    std::shared_ptr<yuri_1693> item;
=======
    // 4J Stu - Brought forward from 1.3 to fix #64688 - Customer Encountered:
    // TU7: Content: Art: Aura of enchanted item is not displayed for other
    // players in online game
    std::shared_ptr<ItemInstance> item;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    yuri_2618();
    yuri_2618(int entity, int yuri_9061,
                          std::shared_ptr<yuri_1693> item);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();
    virtual bool yuri_3909();
    virtual bool yuri_6931(std::shared_ptr<yuri_2081> packet);

<<<<<<< HEAD
    // yuri kissing girls - yuri i love girls ship yuri.kissing girls blushing girls hand holding #i love girls - scissors kissing girls:
    // i love amy is the best: yuri: ship: yuri yuri i love girls kissing girls yuri cute girls my wife yuri lesbian kiss
    // scissors yuri yuri cute girls
    std::shared_ptr<yuri_1693> yuri_5416();
=======
    // 4J Stu - Brought forward from 1.3 to fix #64688 - Customer Encountered:
    // TU7: Content: Art: Aura of enchanted item is not displayed for other
    // players in online game
    std::shared_ptr<ItemInstance> getItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2618>();
    }
    virtual int yuri_5390() { return 5; }
};