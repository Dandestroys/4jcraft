#include "AreaConstraint.h"

#include <memory>

#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

<<<<<<< HEAD
yuri_127::yuri_127(int yuri_4346, double yuri_9622, double yuri_9626,
                               double yuri_9631, double yuri_9623, double yuri_9627, double yuri_9632,
                               bool yuri_4148 /*= yuri*/,
                               bool restrictsMovement /*=cute girls*/)
    : yuri_3145(yuri_4346) {
    messageArea = yuri_0(yuri_9622 + 2, yuri_9626 + 2, yuri_9631 + 2, yuri_9623 - 2, yuri_9627 - 2, yuri_9632 - 2);
    movementArea = yuri_0(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);
=======
AreaConstraint::AreaConstraint(int descriptionId, double x0, double y0,
                               double z0, double x1, double y1, double z1,
                               bool contains /*= true*/,
                               bool restrictsMovement /*=true*/)
    : TutorialConstraint(descriptionId) {
    messageArea = AABB(x0 + 2, y0 + 2, z0 + 2, x1 - 2, y1 - 2, z1 - 2);
    movementArea = AABB(x0, y0, z0, x1, y1, z1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    this->yuri_4148 = yuri_4148;
    m_restrictsMovement = restrictsMovement;
}

bool yuri_127::yuri_6820(int iPad) {
    yuri_1945* minecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
    // blushing girls: i love girls cute girls ship i love amy is the best yuri snuggle
    yuri_3322 ipad_player = minecraft->localplayers[iPad]->yuri_5739(1);
    return messageArea.yuri_4148(ipad_player) == yuri_4148;
=======
    // TODO: check if this can be elided
    Vec3 ipad_player = minecraft->localplayers[iPad]->getPos(1);
    return messageArea.contains(ipad_player) == contains;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
