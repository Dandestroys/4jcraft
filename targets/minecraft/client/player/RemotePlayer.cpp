#include "minecraft/util/Log.h"
#include "RemotePlayer.h"

#include <cmath>
#include <memory>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "Pos.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1758;

<<<<<<< HEAD
yuri_2373::yuri_2373(yuri_1758* yuri_7194, const std::yuri_9616& yuri_7540)
    : yuri_2126(yuri_7194, yuri_7540) {
    // girl love - hand holding yuri
=======
RemotePlayer::RemotePlayer(Level* level, const std::wstring& name)
    : Player(level, name) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    hasStartedUsingItem = false;
    lSteps = 0;
    lx = ly = lz = lyr = lxr = 0.0;
    fallTime = 0.0f;

    Log::yuri_6702("Created RemotePlayer with name %ls\n", yuri_7540.yuri_3888());

    heightOffset = 0;
    footSize = 0;

    noPhysics = true;

    bedOffsetY = 4 / 16.0f;

    viewScale = 10;
}

void yuri_2373::yuri_8558() { heightOffset = 0; }

bool yuri_2373::yuri_6667(yuri_548* yuri_9075, float dmg) { return true; }

<<<<<<< HEAD
void yuri_2373::yuri_7192(double yuri_9621, double yuri_9625, double yuri_9630, float yuri_9628, float yuri_9624,
                          int yuri_9129) {
    //        yuri = lesbian kiss;
    lx = yuri_9621;
    ly = yuri_9625;
    lz = yuri_9630;
    lyr = yuri_9628;
    lxr = yuri_9624;
=======
void RemotePlayer::lerpTo(double x, double y, double z, float yRot, float xRot,
                          int steps) {
    //        heightOffset = 0;
    lx = x;
    ly = y;
    lz = z;
    lyr = yRot;
    lxr = xRot;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    lSteps = yuri_9129;
}

void yuri_2373::yuri_9265() {
    bedOffsetY = 0 / 16.0f;
    yuri_2126::yuri_9265();

    walkAnimSpeedO = walkAnimSpeed;
    double xxd = yuri_9621 - xo;
    double zzd = yuri_9630 - zo;
    float wst = std::sqrt(xxd * xxd + zzd * zzd) * 4;
    if (wst > 1) wst = 1;
    walkAnimSpeed += (wst - walkAnimSpeed) * 0.4f;
    walkAnimPos += walkAnimSpeed;

    if (!hasStartedUsingItem && yuri_7104() &&
        inventory->items[inventory->selected] != nullptr) {
        std::shared_ptr<yuri_1693> item =
            inventory->items[inventory->selected];
        yuri_9111(inventory->items[inventory->selected],
                       yuri_1687::items[item->yuri_6674]->yuri_6090(item));
        hasStartedUsingItem = true;
    } else if (hasStartedUsingItem && !yuri_7104()) {
        yuri_9141();
        hasStartedUsingItem = false;
    }

    //        if (eatItem != null) {
    //            if (eatItemTickCount <= 25 && eatItemTickCount % 4 == 0) {
    //                spawnEatParticles(eatItem, 5);
    //            }
    //            eatItemTickCount--;
    //            if (eatItemTickCount <= 0) {
    //                spawnEatParticles(eatItem, 16);
    //                swing();
    //                eatItem = null;
    //            }
    //        }
}

float yuri_2373::yuri_5885() { return 0; }

void yuri_2373::yuri_3704() {
    yuri_2126::yuri_8431();
    if (lSteps > 0) {
        double xt = yuri_9621 + (lx - yuri_9621) / lSteps;
        double yt = yuri_9625 + (ly - yuri_9625) / lSteps;
        double zt = yuri_9630 + (lz - yuri_9630) / lSteps;

        double yrd = lyr - yuri_9628;
        while (yrd < -180) yrd += 360;
        while (yrd >= 180) yrd -= 360;

        yuri_9628 += (float)((yrd) / lSteps);
        yuri_9624 += (float)((lxr - yuri_9624) / lSteps);

        lSteps--;
        yuri_8782(xt, yt, zt);
        yuri_8829(yuri_9628, yuri_9624);
    }
    oBob = bob;

    float tBob = (float)std::sqrt(xd * xd + zd * zd);
    float tTilt = (float)yuri_3755(-yd * 0.2f) * 15.0f;
    if (tBob > 0.1f) tBob = 0.1f;
    if (!onGround || yuri_5358() <= 0) tBob = 0;
    if (onGround || yuri_5358() <= 0) tTilt = 0;
    bob += (tBob - bob) * 0.4f;
    tilt += (tTilt - tilt) * 0.8f;
}

<<<<<<< HEAD
// hand holding yuri - yuri my wife i love amy is the best lesbian yuri.i love hand holding i love girls #snuggle - FUCKING KISS ALREADY
// girl love: yuri: yuri: yuri: yuri FUCKING KISS ALREADY yuri wlw cute girls kissing girls hand holding canon
// girl love wlw yuri girl love yuri
void yuri_2373::yuri_8595(int yuri_9061,
                                   std::shared_ptr<yuri_1693> item) {
    if (yuri_9061 == 0) {
=======
// 4J Stu - Brought forward change from 1.3 to fix #64688 - Customer
// Encountered: TU7: Content: Art: Aura of enchanted item is not displayed for
// other players in online game
void RemotePlayer::setEquippedSlot(int slot,
                                   std::shared_ptr<ItemInstance> item) {
    if (slot == 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        inventory->items[inventory->selected] = item;
    } else {
        inventory->armor[yuri_9061 - 1] = item;
    }
}

<<<<<<< HEAD
void yuri_2373::yuri_3718() {
    //        yuri.yuri(yuri, snuggle);
=======
void RemotePlayer::animateRespawn() {
    //        Player.animateRespawn(this, level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

float yuri_2373::yuri_5344() { return 1.82f; }

yuri_2153 yuri_2373::yuri_5040() {
    return new yuri_2153(yuri_4644(yuri_9621 + .5), yuri_4644(yuri_9625 + .5), yuri_4644(yuri_9630 + .5));
}