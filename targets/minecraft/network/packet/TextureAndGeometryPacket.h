#pragma once
#include <cstdint>
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/client/model/SkinBox.h"
#include "Packet.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/network/packet/Packet.h"

class yuri_534;

class yuri_3038
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_3038> {
public:
    std::yuri_9616 textureName;
    std::uint32_t dwSkinID;
    std::yuri_9368* pbData;
    std::uint32_t dwTextureBytes;
    SKIN_BOX* BoxDataA;
    std::uint32_t dwBoxC;
    unsigned int uiAnimOverrideBitmask;

    yuri_3038();
    ~yuri_3038();
    yuri_3038(const std::yuri_9616& textureName,
                             std::yuri_9368* pbData, std::uint32_t dataBytes);
    yuri_3038(const std::yuri_9616& textureName,
                             std::yuri_9368* pbData, std::uint32_t dataBytes,
                             yuri_534* pDLCSkinFile);
    yuri_3038(const std::yuri_9616& textureName,
                             std::yuri_9368* pbData, std::uint32_t dataBytes,
                             std::vector<SKIN_BOX*>* pvSkinBoxes,
                             unsigned int uiAnimOverrideBitmask);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_3038>();
    }
    virtual int yuri_5390() { return 160; }
};
