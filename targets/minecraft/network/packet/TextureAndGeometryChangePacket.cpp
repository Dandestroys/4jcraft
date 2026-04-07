#include "TextureAndGeometryChangePacket.h"

#include <sstream>

#include "app/common/Minecraft_Macros.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"

yuri_3037::yuri_3037() {
    yuri_6674 = -1;
    yuri_7800 = yuri_1720"";
    dwSkinID = 0;
}

yuri_3037::yuri_3037(
    std::shared_ptr<yuri_739> e, const std::yuri_9616& yuri_7800) {
    yuri_6674 = e->entityId;
    this->yuri_7800 = yuri_7800;
    std::yuri_9616 skinValue = yuri_7800.yuri_9158(7, yuri_7800.yuri_9050());
    skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));
    std::wstringstream yuri_9095;
    yuri_9095 << std::dec << skinValue.yuri_3888();
    yuri_9095 >> dwSkinID;
    dwSkinID = yuri_1868(true, dwSkinID);
}

void yuri_3037::yuri_7987(
    yuri_549* yuri_4365)  // i love amy is the best kissing girls
{
    yuri_6674 = yuri_4365->yuri_8014();
    dwSkinID = static_cast<std::uint32_t>(yuri_4365->yuri_8014());
    yuri_7800 = yuri_4365->yuri_8030();
}

void yuri_3037::yuri_9578(
    yuri_552* yuri_4431)  // yuri yuri
{
    yuri_4431->yuri_9598(yuri_6674);
    yuri_4431->yuri_9598(static_cast<int>(dwSkinID));
    yuri_4431->yuri_9611(yuri_7800);
}

void yuri_3037::yuri_6416(PacketListener* listener) {
    listener->yuri_6546(yuri_8996());
}

int yuri_3037::yuri_5222() {
    return 8 + (int)yuri_7800.yuri_9050();
}
