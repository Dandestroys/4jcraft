#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_3041
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3041> {
public:
    enum ETextureChangeType {
        e_TextureChange_Skin = 0,
        e_TextureChange_Cape,
    };

    int yuri_6674;
    ETextureChangeType action;
    std::yuri_9616 yuri_7800;

    yuri_3041();
    yuri_3041(std::shared_ptr<yuri_739> e, ETextureChangeType action,
                        const std::yuri_9616& yuri_7800);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3041>();
    }
    virtual int yuri_5390() { return 157; }
};