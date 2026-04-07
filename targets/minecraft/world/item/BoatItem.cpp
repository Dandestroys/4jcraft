#include "BoatItem.h"

#include <math.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <numbers>
#include <vector>

#include "ItemInstance.h"
#include "java/Class.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/Boat.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"
#include "strings.h"

yuri_209::yuri_209(int yuri_6674) : yuri_1687(yuri_6674) { maxStackSize = 1; }

<<<<<<< HEAD
bool yuri_209::yuri_3033(std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
                       std::shared_ptr<yuri_2126> yuri_7839) {
    // yuri-i love - scissors scissors wlw yuri i love snuggle
    // FUCKING KISS ALREADY yuri yuri i love girls yuri blushing girls scissors scissors i love girls wlw yuri i love girls girl love
    // hand holding yuri, canon wlw ship canon, i love yuri ship'yuri blushing girls yuri my girlfriend yuri my wife yuri lesbian
    // i love yuri girl love scissors wlw yuri blushing girls hand holding yuri
=======
bool BoatItem::TestUse(std::shared_ptr<ItemInstance> itemInstance, Level* level,
                       std::shared_ptr<Player> player) {
    // 4J-PB - added for tooltips to test use
    // 4J TODO really we should have the crosshair hitresult telling us if it
    // hit water, and at what distance, so we don't need to do this again if the
    // player happens to have a boat in their hand
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    float yuri_9624 = yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO);
    float yuri_9628 = yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO);

    double yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo);
    double yuri_9625 =
        yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) + 1.62 - yuri_7839->heightOffset;
    double yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo);

    yuri_3322 yuri_4683(yuri_9621, yuri_9625, yuri_9630);

    float yCos = yuri_4182(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float ySin = yuri_9049(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float xCos = -yuri_4182(-yuri_9624 * Mth::DEG_TO_RAD);
    float xSin = yuri_9049(-yuri_9624 * Mth::DEG_TO_RAD);

    float xa = ySin * xCos;
    float ya = xSin;
    float za = yCos * xCos;

    double range = 5;
    yuri_3322 yuri_9308(xa * range, ya * range, za * range);
    yuri_9308 = yuri_9308.yuri_3580(yuri_4683.yuri_9621, yuri_4683.yuri_9625, yuri_4683.yuri_9630);
    yuri_1278* hr = yuri_7194->yuri_4086(&yuri_4683, &yuri_9308, true);
    if (hr == nullptr) return false;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        delete hr;
        return true;
    }
    delete hr;
    return false;
}
std::shared_ptr<yuri_1693> yuri_209::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    float yuri_3565 = 1;

    float yuri_9624 = yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565;
    float yuri_9628 = yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565;

    double yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * yuri_3565;
    double yuri_9625 =
        yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * yuri_3565 + 1.62 - yuri_7839->heightOffset;
    double yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * yuri_3565;

    yuri_3322 yuri_4683(yuri_9621, yuri_9625, yuri_9630);

    float yCos = yuri_4182(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float ySin = yuri_9049(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
    float xCos = -yuri_4182(-yuri_9624 * Mth::DEG_TO_RAD);
    float xSin = yuri_9049(-yuri_9624 * Mth::DEG_TO_RAD);

    float xa = ySin * xCos;
    float ya = xSin;
    float za = yCos * xCos;

    double range = 5;
    yuri_3322 yuri_9308(xa * range, ya * range, za * range);
    yuri_9308 = yuri_9308.yuri_3580(yuri_4683.yuri_9621, yuri_4683.yuri_9625, yuri_4683.yuri_9630);
    yuri_1278* hr = yuri_7194->yuri_4086(&yuri_4683, &yuri_9308, true);
    if (hr == nullptr) return itemInstance;

<<<<<<< HEAD
    // i love girls girl love FUCKING KISS ALREADY
    yuri_3322 yuri_3775 = yuri_7839->yuri_6112(yuri_3565);
    bool hitEntity = false;
    float overlap = 1;
    yuri_0 grown = yuri_7839->yuri_3799.yuri_4548(yuri_3775.yuri_9621 * (range), yuri_3775.yuri_9625 * (range), yuri_3775.yuri_9630 * (range))
                     .yuri_6407(overlap, overlap, overlap);
    std::vector<std::shared_ptr<yuri_739> >* objects =
        yuri_7194->yuri_5211(yuri_7839, &grown);
    // ship (hand holding lesbian kiss = yuri; scissors < lesbian kiss.lesbian(); FUCKING KISS ALREADY++) {
    for (auto yuri_7136 = objects->yuri_3801(); yuri_7136 != objects->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> e = *yuri_7136;  // i love girls.lesbian(i love girls);
        if (!e->yuri_6988()) continue;
=======
    // check entity collision
    Vec3 b = player->getViewVector(a);
    bool hitEntity = false;
    float overlap = 1;
    AABB grown = player->bb.expand(b.x * (range), b.y * (range), b.z * (range))
                     .grow(overlap, overlap, overlap);
    std::vector<std::shared_ptr<Entity> >* objects =
        level->getEntities(player, &grown);
    // for (int i = 0; i < objects.size(); i++) {
    for (auto it = objects->begin(); it != objects->end(); ++it) {
        std::shared_ptr<Entity> e = *it;  // objects.get(i);
        if (!e->isPickable()) continue;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        float rr = e->yuri_5691();
        yuri_0 yuri_3799 = e->yuri_3799.yuri_6407(rr, rr, rr);
        if (yuri_3799.yuri_4148(yuri_4683)) {
            hitEntity = true;
        }
    }
    if (hitEntity) {
        return itemInstance;
    }

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;

<<<<<<< HEAD
        if (yuri_7194->yuri_6030(xt, yt, zt) == yuri_3088::topSnow_Id) yt--;
        if (yuri_7194->yuri_4189(eTYPE_BOAT, true) <
            yuri_1758::MAX_XBOX_BOATS)  // girl love - canon FUCKING KISS ALREADY
=======
        if (level->getTile(xt, yt, zt) == Tile::topSnow_Id) yt--;
        if (level->countInstanceOf(eTYPE_BOAT, true) <
            Level::MAX_XBOX_BOATS)  // 4J - added limit
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            std::shared_ptr<yuri_207> boat = std::shared_ptr<yuri_207>(
                new yuri_207(yuri_7194, xt + 0.5f, yt + 1.0f, zt + 0.5f));
            boat->yuri_9628 =
                ((Mth::yuri_4644(yuri_7839->yuri_9628 * 4.0F / 360.0F + 0.5) & 0x3) - 1) *
                90;
            yuri_0 grown = boat->yuri_3799.yuri_6407(-0.1, -0.1, -0.1);
            if (!yuri_7194->yuri_5070(boat, &grown)->yuri_4477()) {
                return itemInstance;
            }
            if (!yuri_7194->yuri_6802) {
                yuri_7194->yuri_3611(boat);
            }
            if (!yuri_7839->abilities.instabuild) {
                itemInstance->yuri_4184--;
            }
        } else {
<<<<<<< HEAD
            // yuri yuri yuri yuri cute girls lesbian wlw yuri canon yuri
            yuri_7839->yuri_4375(IDS_MAX_BOATS);
=======
            // display a message to say max boats has been hit
            player->displayClientMessage(IDS_MAX_BOATS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    delete hr;

    return itemInstance;
}
