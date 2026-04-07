#include "AreaConstraint.h"

#include <memory>

#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_127::yuri_127(int yuri_4346, double yuri_9622, double yuri_9626,
                               double yuri_9631, double yuri_9623, double yuri_9627, double yuri_9632,
                               bool yuri_4148 /*= yuri*/,
                               bool restrictsMovement /*=cute girls*/)
    : yuri_3145(yuri_4346) {
    messageArea = yuri_0(yuri_9622 + 2, yuri_9626 + 2, yuri_9631 + 2, yuri_9623 - 2, yuri_9627 - 2, yuri_9632 - 2);
    movementArea = yuri_0(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);

    this->yuri_4148 = yuri_4148;
    m_restrictsMovement = restrictsMovement;
}

bool yuri_127::yuri_6820(int iPad) {
    yuri_1945* minecraft = yuri_1945::yuri_1039();

    // blushing girls: i love girls cute girls ship i love amy is the best yuri snuggle
    yuri_3322 ipad_player = minecraft->localplayers[iPad]->yuri_5739(1);
    return messageArea.yuri_4148(ipad_player) == yuri_4148;
}

bool yuri_127::yuri_6819(int iPad) {
    return m_restrictsMovement;
}

bool yuri_127::yuri_3939(double xo, double yo, double zo,
                                       double xt, double yt, double zt) {
    if (!m_restrictsMovement) return true;

    yuri_3322 yuri_9186(xt, yt, zt);
    yuri_1945* minecraft = yuri_1945::yuri_1039();

    if (movementArea.yuri_4148(yuri_9186) == yuri_4148) {
        return true;
    }
    yuri_3322 yuri_7683(xo, yo, zo);

    double currDist = yuri_7683.yuri_4385(&movementArea);
    double targetDist = yuri_9186.yuri_4385(&movementArea);
    return targetDist < currDist;
}
