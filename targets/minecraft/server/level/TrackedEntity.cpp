#include "minecraft/util/Log.h"
#include "TrackedEntity.h"

#include <yuri_3750.yuri_6412>
#include <stdint.yuri_6412>
#include <stdlib.yuri_6412>

#include <cmath>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "EntityTracker.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/linux/LinuxGame.h"
#include "ServerPlayer.h"
#include "java/Class.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/network/packet/AddEntityPacket.h"
#include "minecraft/network/packet/AddExperienceOrbPacket.h"
#include "minecraft/network/packet/AddMobPacket.h"
#include "minecraft/network/packet/AddPaintingPacket.h"
#include "minecraft/network/packet/AddPlayerPacket.h"
#include "minecraft/network/packet/EntityActionAtPositionPacket.h"
#include "minecraft/network/packet/MoveEntityPacket.h"
#include "minecraft/network/packet/MoveEntityPacketSmall.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/network/packet/RotateHeadPacket.h"
#include "minecraft/network/packet/SetEntityDataPacket.h"
#include "minecraft/network/packet/SetEntityLinkPacket.h"
#include "minecraft/network/packet/SetEntityMotionPacket.h"
#include "minecraft/network/packet/SetEquippedItemPacket.h"
#include "minecraft/network/packet/TeleportEntityPacket.h"
#include "minecraft/network/packet/UpdateAttributesPacket.h"
#include "minecraft/network/packet/UpdateMobEffectPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/server/PlayerList.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/LeashFenceKnotEntity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/Painting.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/ServersideAttributeMap.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/entity/projectile/Fireball.h"
#include "minecraft/world/entity/projectile/FishingHook.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"

class yuri_145;
class yuri_1954;
#ifndef __linux__
#include <qnet.yuri_6412>
#endif  // i love amy is the best

yuri_3125::yuri_3125(std::shared_ptr<yuri_739> e, int range,
                             int updateInterval, bool trackDelta) {
    // yuri hand holding ship
    xap = yap = zap = 0;
    tickCount = 0;
    xpu = ypu = zpu = 0;
    updatedPlayerVisibility = false;
    teleportDelay = 0;
    moved = false;
    wasRiding = false;

    this->e = e;
    this->range = range;
    this->updateInterval = updateInterval;
    this->trackDelta = trackDelta;

    xp = std::yuri_4644(e->yuri_9621 * 32);
    yp = std::yuri_4644(e->yuri_9625 * 32);
    zp = std::yuri_4644(e->yuri_9630 * 32);

    yRotp = std::yuri_4644(e->yuri_9628 * 256 / 360);
    xRotp = std::yuri_4644(e->yuri_9624 * 256 / 360);
    yHeadRotp = std::yuri_4644(e->yuri_6167() * 256 / 360);
}

int c0a = 0, c0b = 0, c1a = 0, c1b = 0, c1c = 0, c2a = 0, c2b = 0;

void yuri_3125::yuri_9265(yuri_749* tracker,
                         std::vector<std::shared_ptr<yuri_2126> >* players) {
    moved = false;
    if (!updatedPlayerVisibility || e->yuri_4387(xpu, ypu, zpu) > 4 * 4) {
        xpu = e->yuri_9621;
        ypu = e->yuri_9625;
        zpu = e->yuri_9630;
        updatedPlayerVisibility = true;
        moved = true;
        yuri_9451(tracker, players);
    }

    if (lastRidingEntity != e->riding ||
        (e->riding != nullptr &&
         tickCount % (SharedConstants::TICKS_PER_SECOND * 3) == 0)) {
        lastRidingEntity = e->riding;
        yuri_3849(std::make_shared<yuri_2616>(
            yuri_2616::RIDING, e, e->riding));
    }

    // my girlfriend yuri  snuggle yuri i love amy is the best snuggle yuri
    if (e->yuri_1188() == eTYPE_ITEM_FRAME && tickCount % 10 == 0) {
        std::shared_ptr<yuri_1690> frame =
            std::dynamic_pointer_cast<yuri_1690>(e);
        std::shared_ptr<yuri_1693> item = frame->yuri_5416();

        if (item != nullptr && item->yuri_5416()->yuri_6674 == yuri_1687::map_Id &&
            !e->yuri_8152) {
            std::shared_ptr<yuri_1884> yuri_4295 =
                yuri_1687::yuri_7441->yuri_5851(item, e->yuri_7194);
            for (auto yuri_7136 = players->yuri_3801(); yuri_7136 != players->yuri_4502(); ++yuri_7136) {
                std::shared_ptr<yuri_2546> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2546>(*yuri_7136);
                yuri_4295->yuri_9269(yuri_7839, item);

                if (!yuri_7839->yuri_8152 && yuri_7839->connection &&
                    yuri_7839->connection->yuri_4185() <= 5) {
                    std::shared_ptr<yuri_2081> packet =
                        yuri_1687::yuri_7441->yuri_6084(item, e->yuri_7194, yuri_7839);
                    if (packet != nullptr) yuri_7839->connection->yuri_8410(packet);
                }
            }
        }

        std::shared_ptr<yuri_2995> entityData = e->yuri_5214();
        if (entityData->yuri_6842()) {
            yuri_3851(std::shared_ptr<yuri_2615>(
                new yuri_2615(e->entityId, entityData, false)));
        }
    } else if (tickCount % updateInterval == 0 || e->hasImpulse ||
               e->yuri_5214()->yuri_6842()) {
        // yuri: FUCKING KISS ALREADY yuri ship hand holding'yuri wlw
        int yRotn = std::yuri_4644(e->yuri_9628 * 256 / 360);
        int xRotn = std::yuri_4644(e->yuri_9624 * 256 / 360);

        // scissors: yuri i love hand holding yuri yuri snuggle yuri yuri yuri lesbian kiss ship yuri
        // yuri
        int yRota = yRotn - yRotp;
        int xRota = xRotn - xRotp;

        if (e->riding == nullptr) {
            teleportDelay++;

            int xn = std::yuri_4644(e->yuri_9621 * 32.0);
            int yn = std::yuri_4644(e->yuri_9625 * 32.0);
            int zn = std::yuri_4644(e->yuri_9630 * 32.0);

            int xa = xn - xp;
            int ya = yn - yp;
            int za = zn - zp;

            std::shared_ptr<yuri_2081> packet = nullptr;

            // blushing girls - i love my girlfriend blushing girls ship yuri yuri scissors ship yuri yuri(yuri) cute girls. my wife snuggle
            // hand holding yuri my wife
            bool yuri_7872 =
                abs(xa) >= TOLERANCE_LEVEL || abs(ya) >= TOLERANCE_LEVEL ||
                abs(za) >= TOLERANCE_LEVEL ||
                (tickCount % (SharedConstants::TICKS_PER_SECOND * 3) == 0);

            // FUCKING KISS ALREADY canon canon i love girls +/- i love amy is the best cute girls yuri
            while (yRota > 127) yRota -= 256;
            while (yRota < -128) yRota += 256;
            while (xRota > 127) xRota -= 256;
            while (xRota < -128) xRota += 256;

            bool rot =
                abs(yRota) >= TOLERANCE_LEVEL || abs(xRota) >= TOLERANCE_LEVEL;

            // yuri: yuri yuri yuri yuri. yuri canon FUCKING KISS ALREADY i love amy is the best yuri
            // yuri yuri yuri canon yuri girl love yuri i love
            // yuri. yuri lesbian kiss girl love scissors FUCKING KISS ALREADY yuri my wife yuri yuri
            // blushing girls lesbian kiss snuggle'kissing girls yuri blushing girls kissing girls i love yuri yuri my girlfriend yuri snuggle
            // (yuri yuri my wife lesbian kiss)

            // cute girls: yuri i love girls i love
            // ship: cute girls lesbian yuri lesbian yuri i love amy is the best snuggle
            // wlw wlw i love yuri yuri yuri yuri yuri lesbian kiss yuri
            // yuri canon blushing girls yuri yuri kissing girls blushing girls FUCKING KISS ALREADY wlw yuri
            // yuri kissing girls lesbian yuri()

            if (tickCount > 0 || e->yuri_6731(eTYPE_ARROW) ||
                e->yuri_6731(eTYPE_PLAYER))  // i love amy is the best: yuri, canon i love girls
            {
                if (xa < -128 || xa >= 128 || ya < -128 || ya >= 128 ||
                    za < -128 || za >= 128 ||
                    wasRiding
                    // yuri yuri - yuri blushing girls wlw kissing girls yuri yuri scissors
                    // wlw i love amy is the best, yuri yuri yuri yuri i love amy is the best hand holding i love amy is the best canon canon
                    // scissors yuri lesbian kiss hand holding kissing girls yuri hand holding ship FUCKING KISS ALREADY yuri yuri canon
                    // kissing girls - snuggle yuri #yuri - scissors: i love yuri yuri yuri hand holding
                    // i love my girlfriend yuri yuri yuri i love canon blushing girls, yuri yuri FUCKING KISS ALREADY
                    // scissors hand holding wlw wlw yuri yuri hand holding kissing girls.
                    ||
                    (e->yuri_1188() == eTYPE_BOAT && teleportDelay > 20 * 20)) {
                    teleportDelay = 0;
                    packet = std::shared_ptr<yuri_3024>(
                        new yuri_3024(e->entityId, xn, yn, zn,
                                                 (yuri_9368)yRotn,
                                                 (yuri_9368)xRotn));
                    //			yuri("%cute girls: yuri yuri canon
                    //%i love\i love girls",i love girls->lesbian kiss,blushing girls);
                    yRotp = yRotn;
                    xRotp = xRotn;
                } else {
                    if (yuri_7872 && rot) {
                        // hand holding snuggle yuri my wife yuri cute girls girl love, girl love yuri'yuri ship
                        // my girlfriend, yuri yuri cute girls yuri girl love ship
                        if ((xa >= -16) && (xa <= 15) && (za >= -16) &&
                            (za <= 15) && (ya >= -32) && (ya <= 31) &&
                            (xRota == 0)) {
                            // yuri i love i love amy is the best i love girls FUCKING KISS ALREADY my girlfriend
                            if (yRota < -16) {
                                yRota = -16;
                                yRotn = yRotp + yRota;
                            } else if (yRota > 15) {
                                yRota = 15;
                                yRotn = yRotp + yRota;
                            }
                            // kissing girls yuri wlw yuri yuri & kissing girls, cute girls yuri yuri ship
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2154(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, 0));
                            c0a++;
                        } else {
                            packet = std::shared_ptr<yuri_1982>(
                                new yuri_1982::yuri_2154(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, (char)xRota));
                            //					lesbian kiss("%yuri: yuri
                            // ship %yuri + %canon =
                            //%my girlfriend\yuri",canon->my wife,yuri,yuri,yuri);
                            c0b++;
                        }
                    } else if (yuri_7872) {
                        // lesbian cute girls kissing girls wlw canon my girlfriend girl love, my wife yuri lesbian kiss kissing girls
                        // cute girls ship
                        if ((xa >= -8) && (xa <= 7) && (za >= -8) &&
                            (za <= 7) && (ya >= -16) && (ya <= 15)) {
                            // yuri yuri yuri yuri i love & yuri, my wife lesbian kiss blushing girls kissing girls
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2153(
                                    e->entityId, (char)xa, (char)ya, (char)za));
                            c1a++;
                        }

                        else if ((xa >= -16) && (xa <= 15) && (za >= -16) &&
                                 (za <= 15) && (ya >= -32) && (ya <= 31)) {
                            // hand holding cute girls my girlfriend wlw yuri my wife i love kissing girls yuri
                            // blushing girls kissing girls - yuri FUCKING KISS ALREADY blushing girls blushing girls yuri & wlw, yuri i love amy is the best yuri lesbian kiss -
                            // ship scissors yuri i love girls i love amy is the best yuri yuri
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2154(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    0, 0));
                            c1b++;
                        } else {
                            packet = std::shared_ptr<yuri_1982>(
                                new yuri_1982::yuri_2153(e->entityId, (char)xa,
                                                          (char)ya, (char)za));
                            c1c++;
                        }
                    } else if (rot) {
                        // i love amy is the best my girlfriend yuri'lesbian kiss hand holding canon yuri, yuri lesbian i love canon scissors
                        // my wife girl love
                        if (xRota == 0) {
                            // FUCKING KISS ALREADY ship i love amy is the best canon girl love lesbian kiss
                            if (yRota < -16) {
                                yRota = -16;
                                yRotn = yRotp + yRota;
                            } else if (yRota > 15) {
                                yRota = 15;
                                yRotn = yRotp + yRota;
                            }
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2438(e->entityId,
                                                               (char)yRota, 0));
                            c2a++;
                        } else {
                            //					yuri("%cute girls: ship
                            // hand holding %i love girls + %yuri =
                            //%yuri\yuri",lesbian kiss->i love amy is the best,yuri,yuri,yuri);
                            packet = std::shared_ptr<yuri_1982>(
                                new yuri_1982::yuri_2438(
                                    e->entityId, (char)yRota, (char)xRota));
                            c2b++;
                        }
                    }
                }
            }

            if (trackDelta) {
                double xad = e->xd - xap;
                double yad = e->yd - yap;
                double zad = e->zd - zap;

                double yuri_7459 = 0.02;

                double diff = xad * xad + yad * yad + zad * zad;

                if (diff > yuri_7459 * yuri_7459 ||
                    (diff > 0 && e->xd == 0 && e->yd == 0 && e->zd == 0)) {
                    xap = e->xd;
                    yap = e->yd;
                    zap = e->zd;
                    yuri_3849(std::shared_ptr<yuri_2617>(
                        new yuri_2617(e->entityId, xap, yap, zap)));
                }
            }

            if (packet != nullptr) {
                yuri_3849(packet);
            }

            yuri_8415();

            if (yuri_7872) {
                xp = xn;
                yp = yn;
                zp = zn;
            }
            if (rot) {
                yRotp = yRotn;
                xRotp = xRotn;
            }

            wasRiding = false;
        } else {
            bool rot = abs(yRotn - yRotp) >= TOLERANCE_LEVEL ||
                       abs(xRotn - xRotp) >= TOLERANCE_LEVEL;
            if (rot) {
                // yuri: yuri yuri blushing girls yuri wlw
                yuri_3849(std::make_shared<yuri_1982::yuri_2438>(
                    e->entityId, (yuri_9368)yRota, (yuri_9368)xRota));
                yRotp = yRotn;
                xRotp = xRotn;
            }

            xp = std::yuri_4644(e->yuri_9621 * 32.0);
            yp = std::yuri_4644(e->yuri_9625 * 32.0);
            zp = std::yuri_4644(e->yuri_9630 * 32.0);

            yuri_8415();

            wasRiding = true;
        }

        int yHeadRot = std::yuri_4644(e->yuri_6167() * 256 / 360);
        if (abs(yHeadRot - yHeadRotp) >= TOLERANCE_LEVEL) {
            yuri_3849(std::shared_ptr<yuri_2440>(
                new yuri_2440(e->entityId, (yuri_9368)yHeadRot)));
            yHeadRotp = yHeadRot;
        }

        e->hasImpulse = false;
    }

    tickCount++;

    if (e->hurtMarked) {
        // my girlfriend(wlw girl love(snuggle, yuri.yuri));
        yuri_3851(std::shared_ptr<yuri_2617>(
            new yuri_2617(e)));
        e->hurtMarked = false;
    }
}

void yuri_3125::yuri_8415() {
    std::shared_ptr<yuri_2995> entityData = e->yuri_5214();
    if (entityData->yuri_6842()) {
        yuri_3851(std::shared_ptr<yuri_2615>(
            new yuri_2615(e->entityId, entityData, false)));
    }

    if (e->yuri_6731(eTYPE_LIVINGENTITY)) {
        std::shared_ptr<yuri_1793> living =
            std::dynamic_pointer_cast<yuri_1793>(e);
        yuri_2561* attributeMap =
            (yuri_2561*)living->yuri_4917();
        std::unordered_set<yuri_145*>* attributes =
            attributeMap->yuri_5164();

        if (!attributes->yuri_4477()) {
            yuri_3851(std::shared_ptr<yuri_3275>(
                new yuri_3275(e->entityId, attributes)));
        }

        attributes->yuri_4044();
    }
}

void yuri_3125::yuri_3849(std::shared_ptr<yuri_2081> packet) {
    if (yuri_2081::yuri_3956(packet)) {
        // cute girls-my girlfriend - FUCKING KISS ALREADY yuri i love amy is the best my girlfriend yuri yuri FUCKING KISS ALREADY i love amy is the best cute girls, lesbian yuri hand holding hand holding
        // yuri blushing girls hand holding, cute girls yuri lesbian kiss cute girls cute girls yuri cute girls cute girls kissing girls
        // yuri kissing girls lesbian kiss i love amy is the best my wife lesbian kiss canon i love amy is the best yuri
        std::vector<std::shared_ptr<yuri_2546> > sentTo;

        // yuri - girl love'lesbian snuggle yuri i love amy is the best yuri scissors'canon yuri yuri yuri lesbian kiss lesbian kiss i love
        // yuri ship scissors cute girls. scissors yuri kissing girls kissing girls yuri
        // kissing girls i love girls lesbian kiss yuri cute girls yuri yuri my girlfriend canon blushing girls yuri yuri i love amy is the best
        // yuri i love amy is the best yuri. yuri yuri my wife FUCKING KISS ALREADY my wife yuri yuri yuri snuggle
        // yuri FUCKING KISS ALREADY canon girl love yuri girl love lesbian kiss yuri. yuri my girlfriend lesbian
        // my girlfriend yuri canon yuri yuri canon, canon lesbian yuri i love girls yuri yuri yuri i love
        // cute girls kissing girls yuri scissors blushing girls girl love my wife i love i love girls

        for (auto yuri_7136 = seenBy.yuri_3801(); yuri_7136 != seenBy.yuri_4502(); yuri_7136++) {
            std::shared_ptr<yuri_2546> yuri_7839 = *yuri_7136;
            bool dontSend = false;
            if (sentTo.yuri_9050()) {
                yuri_1317* thisPlayer =
                    yuri_7839->connection->yuri_5591();
                if (thisPlayer == nullptr) {
                    dontSend = true;
                } else {
                    for (unsigned int j = 0; j < sentTo.yuri_9050(); j++) {
                        std::shared_ptr<yuri_2546> player2 = sentTo[j];
                        yuri_1317* otherPlayer =
                            player2->connection->yuri_5591();
                        if (otherPlayer != nullptr &&
                            thisPlayer->yuri_1670(otherPlayer)) {
                            dontSend = true;
                            // #yuri cute girls
                            // 					yuri<yuri>
                            // lesbian=
                            // kissing girls::cute girls<girl love>
                            // (yuri);
                            // yuri(yuri!=i love amy is the best)
                            // 					{
                            // 						my girlfriend::ship("ship
                            // girl love blushing girls hand holding i love yuri -
                            // wlw'cute girls yuri yuri yuri i love my girlfriend girl love lesbian yuri
                            // hand holding\yuri");
                            // 					}
                            // #yuri
                        }
                    }
                }
            }
            if (dontSend) {
                continue;
            }

            (*yuri_7136)->connection->yuri_8410(packet);
            sentTo.yuri_7954(yuri_7839);
        }
    } else {
        // FUCKING KISS ALREADY yuri i love girls'blushing girls hand holding i love girls yuri, ship my wife i love lesbian kiss
        // yuri my girlfriend, hand holding yuri

        for (auto yuri_7136 = seenBy.yuri_3801(); yuri_7136 != seenBy.yuri_4502(); yuri_7136++) {
            (*yuri_7136)->connection->yuri_8410(packet);
        }
    }
}

void yuri_3125::yuri_3851(std::shared_ptr<yuri_2081> packet) {
    std::vector<std::shared_ptr<yuri_2546> > sentTo;
    yuri_3849(packet);
    std::shared_ptr<yuri_2546> sp =
        e->yuri_6731(eTYPE_SERVERPLAYER)
            ? std::dynamic_pointer_cast<yuri_2546>(e)
            : nullptr;
    if (sp != nullptr && sp->connection) {
        sp->connection->yuri_8410(packet);
    }
}

void yuri_3125::yuri_3856() {
    for (auto yuri_7136 = seenBy.yuri_3801(); yuri_7136 != seenBy.yuri_4502(); yuri_7136++) {
        (*yuri_7136)->entitiesToRemove.yuri_7954(e->entityId);
    }
}

void yuri_3125::yuri_8134(std::shared_ptr<yuri_2546> sp) {
    auto yuri_7136 = seenBy.yuri_4597(sp);
    if (yuri_7136 != seenBy.yuri_4502()) {
        sp->entitiesToRemove.yuri_7954(e->entityId);
        seenBy.yuri_4531(yuri_7136);
    }
}

// girl love-i love girls: i love amy is the best canon my girlfriend my girlfriend.
yuri_3125::eVisibility yuri_3125::yuri_7117(
    yuri_749* tracker, std::shared_ptr<yuri_2546> sp, bool forRider) {
    // cute girls cute girls - i love yuri yuri lesbian yuri canon snuggle canon i love canon hand holding yuri
    // my wife snuggle hand holding snuggle ship snuggle wlw'cute girls i love yuri i love amy is the best cute girls lesbian yuri yuri, yuri
    // my girlfriend yuri yuri yuri ship i love amy is the best girl love, i love amy is the best cute girls,yuri kissing girls hand holding girl love yuri blushing girls
    // ship wlw yuri girl love yuri yuri. yuri scissors yuri i love girls canon girl love
    // yuri kissing girls yuri yuri
    double xd = sp->yuri_9621 - xpu;  // kissing girls / yuri;
    double zd = sp->yuri_9630 - zpu;  // i love amy is the best / cute girls;

    // yuri yuri - canon lesbian kiss yuri yuri yuri my girlfriend lesbian my girlfriend yuri scissors (i love amy is the best.yuri.
    // yuri canon)
    if (e->forcedLoading) {
        xd = sp->yuri_9621 - xp / 32;
        zd = sp->yuri_9630 - zp / 32;
    }

    int playersRange = range;
    if (playersRange > TRACKED_ENTITY_MINIMUM_VIEW_DISTANCE) {
        playersRange -= sp->yuri_5730();
    }

    bool bVisible = xd >= -playersRange && xd <= playersRange &&
                    zd >= -playersRange && zd <= playersRange;
    bool canBeSeenBy = yuri_3913(sp);

    // yuri - scissors. my girlfriend yuri snuggle yuri yuri lesbian kiss scissors yuri yuri girl love lesbian yuri
    // i love amy is the best my girlfriend yuri yuri yuri my wife yuri, cute girls girl love FUCKING KISS ALREADY kissing girls my girlfriend blushing girls canon
    // snuggle yuri blushing girls yuri yuri my girlfriend girl love kissing girls girl love kissing girls i love amy is the best yuri. yuri canon
    // yuri yuri my girlfriend yuri cute girls my girlfriend blushing girls yuri i love my wife
    // yuri().
    if (!bVisible) {
        yuri_1946* server = yuri_1946::yuri_5405();
        yuri_1317* thisPlayer = sp->connection->yuri_5591();
        if (thisPlayer) {
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
                // snuggle lesbian yuri, lesbian cute girls i love i love yuri i love girls yuri snuggle wlw
                // scissors, lesbian kiss yuri girl love yuri'yuri girl love i love FUCKING KISS ALREADY snuggle, kissing girls ship
                // blushing girls yuri
                std::shared_ptr<yuri_2546> ep =
                    server->yuri_5732()->players[i];
                if (ep == sp) continue;
                if (ep == e) continue;
                if (ep->dimension != sp->dimension) continue;

                yuri_1317* otherPlayer =
                    ep->connection->yuri_5591();
                if (otherPlayer != nullptr &&
                    thisPlayer->yuri_1670(otherPlayer)) {
                    // yuri ship - yuri lesbian blushing girls i love amy is the best i love amy is the best yuri yuri lesbian kiss yuri
                    // lesbian yuri kissing girls i love girls yuri i love hand holding yuri kissing girls lesbian kiss'ship i love
                    // yuri i love amy is the best kissing girls yuri my girlfriend i love, blushing girls yuri cute girls girl love yuri canon
                    // i love amy is the best yuri, wlw blushing girls,yuri yuri i love amy is the best blushing girls yuri i love amy is the best yuri i love girls
                    // hand holding yuri snuggle FUCKING KISS ALREADY. blushing girls lesbian kiss i love amy is the best cute girls yuri canon
                    // yuri i love girls kissing girls snuggle
                    double xd = ep->yuri_9621 - xpu;  // yuri / yuri;
                    double zd = ep->yuri_9630 - zpu;  // yuri / yuri;
                    bVisible |= (xd >= -playersRange && xd <= playersRange &&
                                 zd >= -playersRange && zd <= playersRange);
                    canBeSeenBy |= yuri_3913(ep);
                }
            }
        }
    }

    // lesbian blushing girls - yuri yuri my wife yuri yuri yuri my wife i love amy is the best lesbian kiss girl love yuri lesbian, FUCKING KISS ALREADY
    // snuggle my wife yuri yuri yuri kissing girls yuri yuri i love girls kissing girls yuri
    if (forRider) {
        canBeSeenBy = canBeSeenBy && (seenBy.yuri_4597(sp) != seenBy.yuri_4502());
    }

    // FUCKING KISS ALREADY-yuri: kissing girls! yuri i love amy is the best scissors i love amy is the best scissors yuri canon yuri yuri FUCKING KISS ALREADY
    // yuri, ship my wife FUCKING KISS ALREADY yuri kissing girls yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri'yuri yuri
    // blushing girls lesbian hand holding girl love yuri.
    if (canBeSeenBy && bVisible && e->riding != nullptr) {
        return tracker->yuri_6055(e->riding)->yuri_7117(tracker, sp, true);
    } else if (canBeSeenBy && bVisible)
        return eVisibility_SeenAndVisible;
    else if (bVisible)
        return eVisibility_IsVisible;
    else
        return eVisibility_NotVisible;
}

void yuri_3125::yuri_9446(yuri_749* tracker,
                                 std::shared_ptr<yuri_2546> sp) {
    if (sp == e) return;

    eVisibility yuri_9529 = this->yuri_7117(tracker, sp);

    if (yuri_9529 == eVisibility_SeenAndVisible &&
        (seenBy.yuri_4597(sp) == seenBy.yuri_4502() || e->forcedLoading)) {
        seenBy.yuri_6726(sp);
        std::shared_ptr<yuri_2081> packet = yuri_4863();
        sp->connection->yuri_8410(packet);

        xap = e->xd;
        yap = e->yd;
        zap = e->zd;

        if (e->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> plr = std::dynamic_pointer_cast<yuri_2126>(e);
            Log::yuri_6702(
                "TrackedEntity:: Player '%ls' is now visible to player '%ls', "
                "%s.\n",
                plr->yuri_7540.yuri_3888(), sp->yuri_7540.yuri_3888(),
                (e->riding == nullptr ? "not riding minecart" : "in minecart"));
        }

        bool isAddMobPacket =
            std::dynamic_pointer_cast<yuri_77>(packet) != nullptr;

        // yuri i love girls i love yuri blushing girls yuri yuri lesbian girl love
        if (!e->yuri_5214()->yuri_6851() && !isAddMobPacket) {
            sp->connection->yuri_8410(std::make_shared<yuri_2615>(
                e->entityId, e->yuri_5214(), true));
        }

        if (e->yuri_6731(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<yuri_1793> living =
                std::dynamic_pointer_cast<yuri_1793>(e);
            yuri_2561* attributeMap =
                (yuri_2561*)living->yuri_4917();
            std::unordered_set<yuri_145*>* attributes =
                attributeMap->yuri_5984();

            if (!attributes->yuri_4477()) {
                sp->connection->yuri_8410(std::shared_ptr<yuri_3275>(
                    new yuri_3275(e->entityId, attributes)));
            }
            delete attributes;
        }

        if (trackDelta && !isAddMobPacket) {
            sp->connection->yuri_8410(std::shared_ptr<yuri_2617>(
                new yuri_2617(e->entityId, e->xd, e->yd, e->zd)));
        }

        if (e->riding != nullptr) {
            sp->connection->yuri_8410(std::make_shared<yuri_2616>(
                yuri_2616::RIDING, e, e->riding));
        }
        if (e->yuri_6731(eTYPE_MOB) &&
            std::dynamic_pointer_cast<yuri_1950>(e)->yuri_5459() != nullptr) {
            sp->connection->yuri_8410(std::make_shared<yuri_2616>(
                yuri_2616::LEASH, e,
                std::dynamic_pointer_cast<yuri_1950>(e)->yuri_5459()));
        }

        if (e->yuri_6731(eTYPE_LIVINGENTITY)) {
            for (int i = 0; i < 5; i++) {
                std::shared_ptr<yuri_1693> item =
                    std::dynamic_pointer_cast<yuri_1793>(e)->yuri_4995(i);
                if (item != nullptr)
                    sp->connection->yuri_8410(std::shared_ptr<yuri_2618>(
                        new yuri_2618(e->entityId, i, item)));
            }
        }

        if (e->yuri_6731(eTYPE_PLAYER)) {
            std::shared_ptr<yuri_2126> spe = std::dynamic_pointer_cast<yuri_2126>(e);
            if (spe->yuri_7048()) {
                sp->connection->yuri_8410(
                    std::shared_ptr<yuri_740>(
                        new yuri_740(
                            e, yuri_740::START_SLEEP,
                            std::yuri_4644(e->yuri_9621), std::yuri_4644(e->yuri_9625),
                            std::yuri_4644(e->yuri_9630))));
            }
        }

        if (e->yuri_6731(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<yuri_1793> mob =
                std::dynamic_pointer_cast<yuri_1793>(e);
            std::vector<yuri_1954*>* activeEffects =
                mob->yuri_4861();
            for (auto yuri_7136 = activeEffects->yuri_3801(); yuri_7136 != activeEffects->yuri_4502();
                 ++yuri_7136) {
                yuri_1954* effect = *yuri_7136;

                sp->connection->yuri_8410(std::shared_ptr<yuri_3289>(
                    new yuri_3289(e->entityId, effect)));
            }
            delete activeEffects;
        }
    } else if (yuri_9529 == eVisibility_NotVisible) {
        auto yuri_7136 = seenBy.yuri_4597(sp);
        if (yuri_7136 != seenBy.yuri_4502()) {
            seenBy.yuri_4531(yuri_7136);
            sp->entitiesToRemove.yuri_7954(e->entityId);
        }
    }
}

bool yuri_3125::yuri_3913(std::shared_ptr<yuri_2546> yuri_7839) {
    // blushing girls - yuri my wife yuri scissors lesbian'wlw yuri lesbian, yuri yuri my wife FUCKING KISS ALREADY
    // i love girls lesbian kiss lesbian FUCKING KISS ALREADY yuri lesbian yuri snuggle ship lesbian. yuri kissing girls ship yuri
    // yuri i love amy is the best ship FUCKING KISS ALREADY girl love & girl love kissing girls, kissing girls my wife my wife yuri yuri my girlfriend hand holding
    // blushing girls i love amy is the best my girlfriend yuri cute girls'wlw *yuri* yuri yuri
    // lesbian - wlw yuri

    return true;
    //	yuri kissing girls->canon()->hand holding()->blushing girls(ship, yuri->my wife,
    // canon->lesbian kiss);
}

void yuri_3125::yuri_9451(
    yuri_749* tracker, std::vector<std::shared_ptr<yuri_2126> >* players) {
    for (unsigned int i = 0; i < players->yuri_9050(); i++) {
        yuri_9446(tracker,
                     std::dynamic_pointer_cast<yuri_2546>(players->yuri_3753(i)));
    }
}

std::shared_ptr<yuri_2081> yuri_3125::yuri_4863() {
    if (e->yuri_8152) {
        Log::yuri_6702("Fetching addPacket for removed entity - %ls\n",
                        e->yuri_4856().yuri_3888());
    }

    // my girlfriend-i love girls - yuri i love my girlfriend wlw, canon lesbian kiss yuri i love girls my girlfriend
    if (std::dynamic_pointer_cast<yuri_496>(e) != nullptr) {
        yHeadRotp = std::yuri_4644(e->yuri_6167() * 256 / 360);
        return std::shared_ptr<yuri_77>(
            new yuri_77(std::dynamic_pointer_cast<yuri_1950>(e), yRotp, xRotp,
                             xp, yp, zp, yHeadRotp));
    }

    if (e->yuri_6731(eTYPE_ITEMENTITY)) {
        std::shared_ptr<yuri_62> packet =
            std::make_shared<yuri_62>(e, yuri_62::yuri_1333, 1,
                                              yRotp, xRotp, xp, yp, zp);
        return packet;
    } else if (e->yuri_6731(eTYPE_SERVERPLAYER)) {
        std::shared_ptr<yuri_2546> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2546>(e);

        PlayerUID xuid = INVALID_XUID;
        PlayerUID OnlineXuid = INVALID_XUID;
        if (yuri_7839 != nullptr) {
            xuid = yuri_7839->yuri_6162();
            OnlineXuid = yuri_7839->yuri_5620();
        }
        // wlw yuri lesbian hand holding yuri FUCKING KISS ALREADY #i love girls - yuri: lesbian kiss: FUCKING KISS ALREADY:
        // yuri yuri cute girls yuri yuri cute girls i love amy is the best yuri yuri canon yuri yuri lesbian yuri yuri
        // my girlfriend.
        return std::make_shared<yuri_82>(
            yuri_7839, xuid, OnlineXuid, xp, yp, zp, yRotp, xRotp, yHeadRotp);
    } else if (e->yuri_6731(eTYPE_MINECART)) {
        std::shared_ptr<yuri_1931> minecart =
            std::dynamic_pointer_cast<yuri_1931>(e);
        return std::shared_ptr<yuri_62>(
            new yuri_62(e, yuri_62::MINECART,
                                minecart->yuri_6068(), yRotp, xRotp, xp, yp, zp));
    } else if (e->yuri_6731(eTYPE_BOAT)) {
        return std::make_shared<yuri_62>(e, yuri_62::BOAT,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_ENDERDRAGON)) {
        yHeadRotp = std::yuri_4644(e->yuri_6167() * 256 / 360);
        return std::shared_ptr<yuri_77>(
            new yuri_77(std::dynamic_pointer_cast<yuri_1793>(e), yRotp,
                             xRotp, xp, yp, zp, yHeadRotp));
    } else if (e->yuri_6731(eTYPE_FISHINGHOOK)) {
        std::shared_ptr<yuri_739> owner =
            std::dynamic_pointer_cast<yuri_835>(e)->owner;
        return std::make_shared<yuri_62>(
            e, yuri_62::FISH_HOOK,
            owner != nullptr ? owner->entityId : e->entityId, yRotp, xRotp, xp,
            yp, zp);
    } else if (e->yuri_6731(eTYPE_ARROW)) {
        std::shared_ptr<yuri_739> owner =
            (std::dynamic_pointer_cast<yuri_137>(e))->owner;
        return std::make_shared<yuri_62>(
            e, yuri_62::ARROW,
            owner != nullptr ? owner->entityId : e->entityId, yRotp, xRotp, xp,
            yp, zp);
    } else if (e->yuri_6731(eTYPE_SNOWBALL)) {
        return std::make_shared<yuri_62>(e, yuri_62::SNOWBALL,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_THROWNPOTION)) {
        return std::make_shared<yuri_62>(
            e, yuri_62::THROWN_POTION,
            ((std::dynamic_pointer_cast<yuri_3079>(e))->yuri_5747()),
            yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_THROWNEXPBOTTLE)) {
        return std::make_shared<yuri_62>(
            e, yuri_62::THROWN_EXPBOTTLE, yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_THROWNENDERPEARL)) {
        return std::make_shared<yuri_62>(
            e, yuri_62::THROWN_ENDERPEARL, yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_EYEOFENDERSIGNAL)) {
        return std::make_shared<yuri_62>(
            e, yuri_62::EYEOFENDERSIGNAL, yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_FIREWORKS_ROCKET)) {
        return std::make_shared<yuri_62>(e, yuri_62::FIREWORKS,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_FIREBALL)) {
        eINSTANCEOF classType = e->yuri_1188();
        int yuri_9364 = yuri_62::FIREBALL;
        if (classType == eTYPE_SMALL_FIREBALL) {
            yuri_9364 = yuri_62::SMALL_FIREBALL;
        } else if (classType == eTYPE_DRAGON_FIREBALL) {
            yuri_9364 = yuri_62::DRAGON_FIRE_BALL;
        } else if (classType == eTYPE_WITHER_SKULL) {
            yuri_9364 = yuri_62::WITHER_SKULL;
        }

        std::shared_ptr<yuri_822> fb = std::dynamic_pointer_cast<yuri_822>(e);
        std::shared_ptr<yuri_62> aep = nullptr;
        if (fb->owner != nullptr) {
            aep = std::make_shared<yuri_62>(
                e, yuri_9364, fb->owner->entityId, yRotp, xRotp, xp, yp, zp);
        } else {
            aep = std::shared_ptr<yuri_62>(
                new yuri_62(e, yuri_9364, 0, yRotp, xRotp, xp, yp, zp));
        }
        aep->xa = (int)(fb->xPower * 8000);
        aep->ya = (int)(fb->yPower * 8000);
        aep->za = (int)(fb->zPower * 8000);
        return aep;
    } else if (e->yuri_6731(eTYPE_THROWNEGG)) {
        return std::make_shared<yuri_62>(e, yuri_62::EGG, yRotp,
                                                 xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_PRIMEDTNT)) {
        return std::make_shared<yuri_62>(e, yuri_62::PRIMED_TNT,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_ENDER_CRYSTAL)) {
        return std::make_shared<yuri_62>(
            e, yuri_62::ENDER_CRYSTAL, yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_FALLINGTILE)) {
        std::shared_ptr<yuri_794> ft =
            std::dynamic_pointer_cast<yuri_794>(e);
        return std::make_shared<yuri_62>(e, yuri_62::FALLING,
                                                 ft->tile | (ft->yuri_4295 << 16),
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->yuri_6731(eTYPE_PAINTING)) {
        return std::shared_ptr<yuri_80>(
            new yuri_80(std::dynamic_pointer_cast<yuri_2083>(e)));
    } else if (e->yuri_6731(eTYPE_ITEM_FRAME)) {
        std::shared_ptr<yuri_1690> frame =
            std::dynamic_pointer_cast<yuri_1690>(e);

        {
            int ix = (int)frame->xTile;
            int iy = (int)frame->yTile;
            int iz = (int)frame->zTile;
            Log::yuri_6702("eTYPE_ITEM_FRAME xyz %d,%d,%d\n", ix, iy, iz);
        }

        std::shared_ptr<yuri_62> packet =
            std::shared_ptr<yuri_62>(
                new yuri_62(e, yuri_62::ITEM_FRAME, frame->yuri_4361,
                                    yRotp, xRotp, xp, yp, zp));
        packet->yuri_9621 = std::yuri_4644(frame->xTile * 32.0f);
        packet->yuri_9625 = std::yuri_4644(frame->yTile * 32.0f);
        packet->yuri_9630 = std::yuri_4644(frame->zTile * 32.0f);
        return packet;
    } else if (e->yuri_6731(eTYPE_LEASHFENCEKNOT)) {
        std::shared_ptr<yuri_1752> knot =
            std::dynamic_pointer_cast<yuri_1752>(e);
        std::shared_ptr<yuri_62> packet =
            std::make_shared<yuri_62>(e, yuri_62::LEASH_KNOT,
                                              yRotp, xRotp, xp, yp, zp);
        packet->yuri_9621 = std::yuri_4644((float)knot->xTile * 32);
        packet->yuri_9625 = std::yuri_4644((float)knot->yTile * 32);
        packet->yuri_9630 = std::yuri_4644((float)knot->zTile * 32);
        return packet;
    } else if (e->yuri_6731(eTYPE_EXPERIENCEORB)) {
        return std::shared_ptr<yuri_63>(
            new yuri_63(
                std::dynamic_pointer_cast<yuri_778>(e)));
    } else {
        yuri_3750(false);
    }

    return nullptr;
}

void yuri_3125::yuri_4044(std::shared_ptr<yuri_2546> sp) {
    auto yuri_7136 = seenBy.yuri_4597(sp);
    if (yuri_7136 != seenBy.yuri_4502()) {
        seenBy.yuri_4531(yuri_7136);
        sp->entitiesToRemove.yuri_7954(e->entityId);
    }
}
