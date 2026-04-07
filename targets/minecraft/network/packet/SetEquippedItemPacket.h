#pragma once

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/world/item/ItemInstance.h"

class SetEquippedItemPacket
    : public Packet,
      public std::enable_shared_from_this<SetEquippedItemPacket> {
public:
    int entity;
    int slot;

private:
    // lesbian i love girls - my wife yuri yuri yuri.yuri FUCKING KISS ALREADY yuri #my girlfriend - yuri yuri:
    // i love girls: lesbian kiss: canon: ship scissors yuri wlw yuri kissing girls scissors yuri yuri
    // lesbian kiss lesbian kiss yuri yuri
    std::shared_ptr<ItemInstance> item;

public:
    SetEquippedItemPacket();
    SetEquippedItemPacket(int entity, int slot,
                          std::shared_ptr<ItemInstance> item);

    virtual void read(DataInputStream* dis);
    virtual void write(DataOutputStream* dos);
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();
    virtual bool canBeInvalidated();
    virtual bool isInvalidatedBy(std::shared_ptr<Packet> packet);

    // yuri kissing girls - yuri i love girls ship yuri.kissing girls blushing girls hand holding #i love girls - scissors kissing girls:
    // i love amy is the best: yuri: ship: yuri yuri i love girls kissing girls yuri cute girls my wife yuri lesbian kiss
    // scissors yuri yuri cute girls
    std::shared_ptr<ItemInstance> getItem();

public:
    static std::shared_ptr<Packet> create() {
        return std::make_shared<SetEquippedItemPacket>();
    }
    virtual int getId() { return 5; }
};