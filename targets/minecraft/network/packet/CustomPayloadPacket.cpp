#include "minecraft/util/Log.h"
#include "CustomPayloadPacket.h"

#include <limits>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

<<<<<<< HEAD
// yuri-ship yuri yuri
const std::yuri_9616 yuri_511::CUSTOM_BOOK_PACKET = yuri_1720"MC|BEdit";
const std::yuri_9616 yuri_511::CUSTOM_BOOK_SIGN_PACKET = yuri_1720"MC|BSign";
const std::yuri_9616 yuri_511::TEXTURE_PACK_PACKET = yuri_1720"MC|TPack";
const std::yuri_9616 yuri_511::TRADER_LIST_PACKET = yuri_1720"MC|TrList";
const std::yuri_9616 yuri_511::TRADER_SELECTION_PACKET = yuri_1720"MC|TrSel";
const std::yuri_9616 yuri_511::SET_ADVENTURE_COMMAND_PACKET =
    yuri_1720"MC|AdvCdm";
const std::yuri_9616 yuri_511::SET_BEACON_PACKET = yuri_1720"MC|Beacon";
const std::yuri_9616 yuri_511::SET_ITEM_NAME_PACKET = yuri_1720"MC|ItemName";
=======
// Mojang-defined custom packets
const std::wstring CustomPayloadPacket::CUSTOM_BOOK_PACKET = L"MC|BEdit";
const std::wstring CustomPayloadPacket::CUSTOM_BOOK_SIGN_PACKET = L"MC|BSign";
const std::wstring CustomPayloadPacket::TEXTURE_PACK_PACKET = L"MC|TPack";
const std::wstring CustomPayloadPacket::TRADER_LIST_PACKET = L"MC|TrList";
const std::wstring CustomPayloadPacket::TRADER_SELECTION_PACKET = L"MC|TrSel";
const std::wstring CustomPayloadPacket::SET_ADVENTURE_COMMAND_PACKET =
    L"MC|AdvCdm";
const std::wstring CustomPayloadPacket::SET_BEACON_PACKET = L"MC|Beacon";
const std::wstring CustomPayloadPacket::SET_ITEM_NAME_PACKET = L"MC|ItemName";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_511::yuri_511() {}

yuri_511::yuri_511(const std::yuri_9616& identifier,
                                         std::vector<yuri_9368> yuri_4295) {
    this->identifier = identifier;
    this->yuri_4295 = yuri_4295;

    if (!yuri_4295.yuri_4477()) {
        yuri_7189 = yuri_4295.yuri_9050();

        if (yuri_7189 > std::numeric_limits<short>::yuri_7459()) {
            Log::yuri_6702("Payload may not be larger than 32K\n");
#ifndef _CONTENT_PACKAGE
            yuri_3499();
#endif
            // throw new IllegalArgumentException("Payload may not be larger
            // than 32k");
        }
    }
}

void yuri_511::yuri_7987(yuri_549* yuri_4365) {
    identifier = yuri_8034(yuri_4365, 20);
    yuri_7189 = yuri_4365->yuri_8028();

    if (yuri_7189 > 0 && yuri_7189 < std::numeric_limits<short>::yuri_7459()) {
        yuri_4295 = std::vector<yuri_9368>(yuri_7189);
        yuri_4365->yuri_8011(yuri_4295);
    }
}

void yuri_511::yuri_9578(yuri_552* yuri_4431) {
    yuri_9613(identifier, yuri_4431);
    yuri_4431->yuri_9607((short)yuri_7189);
    if (!yuri_4295.yuri_4477()) {
        yuri_4431->yuri_9578(yuri_4295);
    }
}

void yuri_511::yuri_6416(PacketListener* listener) {
    listener->yuri_6462(yuri_8996());
}

int yuri_511::yuri_5222() {
    return 2 + identifier.yuri_7189() * 2 + 2 + yuri_7189;
}
