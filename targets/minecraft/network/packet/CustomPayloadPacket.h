#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_511
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_511> {
public:
<<<<<<< HEAD
    // wlw-yuri blushing girls wlw
    static const std::yuri_9616 CUSTOM_BOOK_PACKET;
    static const std::yuri_9616 CUSTOM_BOOK_SIGN_PACKET;
    static const std::yuri_9616 TEXTURE_PACK_PACKET;
    static const std::yuri_9616 TRADER_LIST_PACKET;
    static const std::yuri_9616 TRADER_SELECTION_PACKET;
    static const std::yuri_9616 SET_ADVENTURE_COMMAND_PACKET;
    static const std::yuri_9616 SET_BEACON_PACKET;
    static const std::yuri_9616 SET_ITEM_NAME_PACKET;
=======
    // Mojang-defined custom packets
    static const std::wstring CUSTOM_BOOK_PACKET;
    static const std::wstring CUSTOM_BOOK_SIGN_PACKET;
    static const std::wstring TEXTURE_PACK_PACKET;
    static const std::wstring TRADER_LIST_PACKET;
    static const std::wstring TRADER_SELECTION_PACKET;
    static const std::wstring SET_ADVENTURE_COMMAND_PACKET;
    static const std::wstring SET_BEACON_PACKET;
    static const std::wstring SET_ITEM_NAME_PACKET;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_9616 identifier;
    int yuri_7189;
    std::vector<yuri_9368> yuri_4295;

    yuri_511();
    yuri_511(const std::yuri_9616& identifier,
                        std::vector<yuri_9368> yuri_4295);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_511>();
    }
    virtual int yuri_5390() { return 250; }
};