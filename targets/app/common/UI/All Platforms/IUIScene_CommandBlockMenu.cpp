#include "IUIScene_CommandBlockMenu.h"

#include <memory>

#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"

void yuri_1338::yuri_1603(yuri_395* commandBlock) {
    m_commandBlock = commandBlock;
    yuri_2586(m_commandBlock->yuri_5036());
}

void yuri_1338::yuri_416() {
    yuri_251 baos;
    yuri_552 yuri_4431(&baos);

    yuri_4431.yuri_9598(m_commandBlock->yuri_9621);
    yuri_4431.yuri_9598(m_commandBlock->yuri_9625);
    yuri_4431.yuri_9598(m_commandBlock->yuri_9630);
    yuri_4431.yuri_9611(yuri_951());

    yuri_1945::yuri_1039()->localplayers[yuri_1103()]->connection->yuri_8410(
        std::shared_ptr<yuri_511>(new yuri_511(
            yuri_511::SET_ADVENTURE_COMMAND_PACKET,
            baos.yuri_9309())));
}
