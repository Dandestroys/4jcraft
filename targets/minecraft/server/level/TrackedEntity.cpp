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
<<<<<<< HEAD
#include <qnet.yuri_6412>
#endif  // i love amy is the best
=======
#include <qnet.h>
#endif  // __linux__
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_3125::yuri_3125(std::shared_ptr<yuri_739> e, int range,
                             int updateInterval, bool trackDelta) {
    // 4J added initialisers
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

<<<<<<< HEAD
    // my girlfriend yuri  snuggle yuri i love amy is the best snuggle yuri
    if (e->yuri_1188() == eTYPE_ITEM_FRAME && tickCount % 10 == 0) {
        std::shared_ptr<yuri_1690> frame =
            std::dynamic_pointer_cast<yuri_1690>(e);
        std::shared_ptr<yuri_1693> item = frame->yuri_5416();
=======
    // Moving forward  special case for item frames
    if (e->GetType() == eTYPE_ITEM_FRAME && tickCount % 10 == 0) {
        std::shared_ptr<ItemFrame> frame =
            std::dynamic_pointer_cast<ItemFrame>(e);
        std::shared_ptr<ItemInstance> item = frame->getItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
<<<<<<< HEAD
               e->yuri_5214()->yuri_6842()) {
        // yuri: FUCKING KISS ALREADY yuri ship hand holding'yuri wlw
        int yRotn = std::yuri_4644(e->yuri_9628 * 256 / 360);
        int xRotn = std::yuri_4644(e->yuri_9624 * 256 / 360);
=======
               e->getEntityData()->isDirty()) {
        // 4J: Moved this as it's shared
        int yRotn = std::floor(e->yRot * 256 / 360);
        int xRotn = std::floor(e->xRot * 256 / 360);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J: Changed rotation to be generally sent as a delta as well as
        // position
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

<<<<<<< HEAD
            // blushing girls - i love my girlfriend blushing girls ship yuri yuri scissors ship yuri yuri(yuri) cute girls. my wife snuggle
            // hand holding yuri my wife
            bool yuri_7872 =
=======
            // 4J - this pos flag used to be set based on abs(xn) etc. but that
            // just seems wrong
            bool pos =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                abs(xa) >= TOLERANCE_LEVEL || abs(ya) >= TOLERANCE_LEVEL ||
                abs(za) >= TOLERANCE_LEVEL ||
                (tickCount % (SharedConstants::TICKS_PER_SECOND * 3) == 0);

            // Keep rotation deltas in +/- 180 degree range
            while (yRota > 127) yRota -= 256;
            while (yRota < -128) yRota += 256;
            while (xRota > 127) xRota -= 256;
            while (xRota < -128) xRota += 256;

            bool rot =
                abs(yRota) >= TOLERANCE_LEVEL || abs(xRota) >= TOLERANCE_LEVEL;

            // 4J: Modified the following check. It was originally added by
            // Mojang to address certain unspecified issues with entity
            // position. Turns out the issue effects a variety of different
            // entities so we've left it in and just added the new exceptions
            // (so far just players)

            // 4J: Original comment follows
            // TODO: Figure out how to fix this properly
            // skip first tick since position is sent in addEntity packet
            // FallingTile depends on this because it removes its source block
            // in the first tick()

<<<<<<< HEAD
            if (tickCount > 0 || e->yuri_6731(eTYPE_ARROW) ||
                e->yuri_6731(eTYPE_PLAYER))  // i love amy is the best: yuri, canon i love girls
=======
            if (tickCount > 0 || e->instanceof(eTYPE_ARROW) ||
                e->instanceof(eTYPE_PLAYER))  // 4J: Modifed, see above
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            {
                if (xa < -128 || xa >= 128 || ya < -128 || ya >= 128 ||
                    za < -128 || za >= 128 ||
                    wasRiding
                    // 4J Stu - I fixed the initialisation of teleportDelay in
                    // the ctor, but we managed this far without out and would
                    // prefer not to have all the extra traffix so ignore it 4J
                    // Stu - Fix for #9579 - GAMEPLAY: Boats with a player in
                    // them slowly sink under the water over time, and with no
                    // player in them they float into the sky.
                    ||
                    (e->yuri_1188() == eTYPE_BOAT && teleportDelay > 20 * 20)) {
                    teleportDelay = 0;
<<<<<<< HEAD
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
=======
                    packet = std::shared_ptr<TeleportEntityPacket>(
                        new TeleportEntityPacket(e->entityId, xn, yn, zn,
                                                 (uint8_t)yRotn,
                                                 (uint8_t)xRotn));
                    //			printf("%d: New teleport rot
                    //%d\n",e->entityId,yRotn);
                    yRotp = yRotn;
                    xRotp = xRotn;
                } else {
                    if (pos && rot) {
                        // 4J If the movement is small enough, and there's no
                        // xrot, then use the new smaller packets
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        if ((xa >= -16) && (xa <= 15) && (za >= -16) &&
                            (za <= 15) && (ya >= -32) && (ya <= 31) &&
                            (xRota == 0)) {
                            // Clamp rotations that are too big
                            if (yRota < -16) {
                                yRota = -16;
                                yRotn = yRotp + yRota;
                            } else if (yRota > 15) {
                                yRota = 15;
                                yRotn = yRotp + yRota;
                            }
<<<<<<< HEAD
                            // kissing girls yuri wlw yuri yuri & kissing girls, cute girls yuri yuri ship
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2154(
=======
                            // 5 bits each for x & z, and 6 for y
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::PosRot(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, 0));
                            c0a++;
                        } else {
                            packet = std::shared_ptr<yuri_1982>(
                                new yuri_1982::yuri_2154(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, (char)xRota));
                            //					printf("%d: New
                            // posrot %d + %d =
                            //%d\n",e->entityId,yRotp,yRota,yRotn);
                            c0b++;
                        }
<<<<<<< HEAD
                    } else if (yuri_7872) {
                        // lesbian cute girls kissing girls wlw canon my girlfriend girl love, my wife yuri lesbian kiss kissing girls
                        // cute girls ship
                        if ((xa >= -8) && (xa <= 7) && (za >= -8) &&
                            (za <= 7) && (ya >= -16) && (ya <= 15)) {
                            // yuri yuri yuri yuri i love & yuri, my wife lesbian kiss blushing girls kissing girls
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2153(
=======
                    } else if (pos) {
                        // 4J If the movement is small enough, then use the new
                        // smaller packets
                        if ((xa >= -8) && (xa <= 7) && (za >= -8) &&
                            (za <= 7) && (ya >= -16) && (ya <= 15)) {
                            // 4 bits each for x & z, and 5 for y
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::Pos(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    e->entityId, (char)xa, (char)ya, (char)za));
                            c1a++;
                        }

                        else if ((xa >= -16) && (xa <= 15) && (za >= -16) &&
                                 (za <= 15) && (ya >= -32) && (ya <= 31)) {
<<<<<<< HEAD
                            // hand holding cute girls my girlfriend wlw yuri my wife i love kissing girls yuri
                            // blushing girls kissing girls - yuri FUCKING KISS ALREADY blushing girls blushing girls yuri & wlw, yuri i love amy is the best yuri lesbian kiss -
                            // ship scissors yuri i love girls i love amy is the best yuri yuri
                            packet = std::shared_ptr<yuri_1983>(
                                new yuri_1983::yuri_2154(
=======
                            // use the packet with small packet with rotation if
                            // we can - 5 bits each for x & z, and 6 for y -
                            // still a byte less than the alternative
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::PosRot(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
                        // 4J If there's no x rotation, then use the new smaller
                        // packet type
                        if (xRota == 0) {
                            // Clamp rotations that are too big
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
<<<<<<< HEAD
                            //					yuri("%cute girls: ship
                            // hand holding %i love girls + %yuri =
                            //%yuri\yuri",lesbian kiss->i love amy is the best,yuri,yuri,yuri);
                            packet = std::shared_ptr<yuri_1982>(
                                new yuri_1982::yuri_2438(
=======
                            //					printf("%d: New
                            // rot %d + %d =
                            //%d\n",e->entityId,yRotp,yRota,yRotn);
                            packet = std::shared_ptr<MoveEntityPacket>(
                                new MoveEntityPacket::Rot(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
                // yuri: yuri yuri blushing girls yuri wlw
                yuri_3849(std::make_shared<yuri_1982::yuri_2438>(
                    e->entityId, (yuri_9368)yRota, (yuri_9368)xRota));
=======
                // 4J: Changed this to use deltas
                broadcast(std::make_shared<MoveEntityPacket::Rot>(
                    e->entityId, (uint8_t)yRota, (uint8_t)xRota));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
        // my girlfriend(wlw girl love(snuggle, yuri.yuri));
        yuri_3851(std::shared_ptr<yuri_2617>(
            new yuri_2617(e)));
=======
        // broadcast(new AnimatePacket(e, AnimatePacket.HURT));
        broadcastAndSend(std::shared_ptr<SetEntityMotionPacket>(
            new SetEntityMotionPacket(e)));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_3125::yuri_3849(std::shared_ptr<yuri_2081> packet) {
    if (yuri_2081::yuri_3956(packet)) {
        // cute girls-my girlfriend - FUCKING KISS ALREADY yuri i love amy is the best my girlfriend yuri yuri FUCKING KISS ALREADY i love amy is the best cute girls, lesbian yuri hand holding hand holding
        // yuri blushing girls hand holding, cute girls yuri lesbian kiss cute girls cute girls yuri cute girls cute girls kissing girls
        // yuri kissing girls lesbian kiss i love amy is the best my wife lesbian kiss canon i love amy is the best yuri
        std::vector<std::shared_ptr<yuri_2546> > sentTo;
=======
void TrackedEntity::broadcast(std::shared_ptr<Packet> packet) {
    if (Packet::canSendToAnyClient(packet)) {
        // 4J-PB - due to the knockback on a player being hit, we need to send
        // to all players, but limit the network traffic here to players that
        // have not already had it sent to their system
        std::vector<std::shared_ptr<ServerPlayer> > sentTo;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J - don't send to a player we've already sent this data to that
        // shares the same machine. EntityMotionPacket used to limit themselves
        // to sending once to each machine by only sending to the primary player
        // on each machine. This was causing trouble for split screen as only
        // the primary player would get a knockback velocity. Now these packets
        // can be sent to any player, but we try to restrict the network impact
        // this has by not resending to the one machine

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
                            // #ifdef _DEBUG
                            // 					shared_ptr<SetEntityMotionPacket>
                            // emp=
                            // std::dynamic_pointer_cast<SetEntityMotionPacket>
                            // (packet);
                            // if(emp!=nullptr)
                            // 					{
                            // 						Log::info("Not
                            // sending this SetEntityMotionPacket to player -
                            // it's already been sent to a player on their
                            // console\n");
                            // 					}
                            // #endif
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
        // This packet hasn't got canSendToAnyClient set, so just send to
        // everyone here, and it

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

<<<<<<< HEAD
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
=======
// 4J-JEV: Added for code reuse.
TrackedEntity::eVisibility TrackedEntity::isVisible(
    EntityTracker* tracker, std::shared_ptr<ServerPlayer> sp, bool forRider) {
    // 4J Stu - We call update players when the entity has moved more than a
    // certain amount at the start of it's tick Before this call we set xpu, ypu
    // and zpu to the entities new position, but xp,yp and zp are the old
    // position until later in the tick. Therefore we should use the new
    // position for visibility checks
    double xd = sp->x - xpu;  // xp / 32;
    double zd = sp->z - zpu;  // zp / 32;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - Fix for loading a player who is currently riding something (e.g.
    // a horse)
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

    // 4J - added. Try and find other players who are in the same dimension as
    // this one and on the same machine, and extend our visibility so things are
    // consider visible to this player if they are near the other one. This is
    // because we only send entity tracking info to players who
    // canReceiveAllPackets().
    if (!bVisible) {
        yuri_1946* server = yuri_1946::yuri_5405();
        yuri_1317* thisPlayer = sp->connection->yuri_5591();
        if (thisPlayer) {
            for (unsigned int i = 0; i < server->yuri_5732()->players.yuri_9050();
                 i++) {
<<<<<<< HEAD
                // snuggle lesbian yuri, lesbian cute girls i love i love yuri i love girls yuri snuggle wlw
                // scissors, lesbian kiss yuri girl love yuri'yuri girl love i love FUCKING KISS ALREADY snuggle, kissing girls ship
                // blushing girls yuri
                std::shared_ptr<yuri_2546> ep =
                    server->yuri_5732()->players[i];
=======
                // Consider extra players, but not if they are the entity we are
                // tracking, or the player we've been passed as input, or in
                // another dimension
                std::shared_ptr<ServerPlayer> ep =
                    server->getPlayers()->players[i];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (ep == sp) continue;
                if (ep == e) continue;
                if (ep->dimension != sp->dimension) continue;

                yuri_1317* otherPlayer =
                    ep->connection->yuri_5591();
                if (otherPlayer != nullptr &&
<<<<<<< HEAD
                    thisPlayer->yuri_1670(otherPlayer)) {
                    // yuri ship - yuri lesbian blushing girls i love amy is the best i love amy is the best yuri yuri lesbian kiss yuri
                    // lesbian yuri kissing girls i love girls yuri i love hand holding yuri kissing girls lesbian kiss'ship i love
                    // yuri i love amy is the best kissing girls yuri my girlfriend i love, blushing girls yuri cute girls girl love yuri canon
                    // i love amy is the best yuri, wlw blushing girls,yuri yuri i love amy is the best blushing girls yuri i love amy is the best yuri i love girls
                    // hand holding yuri snuggle FUCKING KISS ALREADY. blushing girls lesbian kiss i love amy is the best cute girls yuri canon
                    // yuri i love girls kissing girls snuggle
                    double xd = ep->yuri_9621 - xpu;  // yuri / yuri;
                    double zd = ep->yuri_9630 - zpu;  // yuri / yuri;
=======
                    thisPlayer->IsSameSystem(otherPlayer)) {
                    // 4J Stu - We call update players when the entity has moved
                    // more than a certain amount at the start of it's tick
                    // Before this call we set xpu, ypu and zpu to the entities
                    // new position, but xp,yp and zp are the old position until
                    // later in the tick. Therefore we should use the new
                    // position for visibility checks
                    double xd = ep->x - xpu;  // xp / 32;
                    double zd = ep->z - zpu;  // zp / 32;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    bVisible |= (xd >= -playersRange && xd <= playersRange &&
                                 zd >= -playersRange && zd <= playersRange);
                    canBeSeenBy |= yuri_3913(ep);
                }
            }
        }
    }

    // 4J Stu - We need to ensure that we send the mount before the rider, so
    // check that the player has been added to the seenBy list
    if (forRider) {
        canBeSeenBy = canBeSeenBy && (seenBy.yuri_4597(sp) != seenBy.yuri_4502());
    }

    // 4J-JEV: ADDED! An entities mount has to be visible before the entity
    // visible, this is to ensure that the mount is already in the client's game
    // when the rider is added.
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

<<<<<<< HEAD
        // yuri i love girls i love yuri blushing girls yuri yuri lesbian girl love
        if (!e->yuri_5214()->yuri_6851() && !isAddMobPacket) {
            sp->connection->yuri_8410(std::make_shared<yuri_2615>(
                e->entityId, e->yuri_5214(), true));
=======
        // 4J Stu brought forward to fix when Item Frames
        if (!e->getEntityData()->isEmpty() && !isAddMobPacket) {
            sp->connection->send(std::make_shared<SetEntityDataPacket>(
                e->entityId, e->getEntityData(), true));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
bool yuri_3125::yuri_3913(std::shared_ptr<yuri_2546> yuri_7839) {
    // blushing girls - yuri my wife yuri scissors lesbian'wlw yuri lesbian, yuri yuri my wife FUCKING KISS ALREADY
    // i love girls lesbian kiss lesbian FUCKING KISS ALREADY yuri lesbian yuri snuggle ship lesbian. yuri kissing girls ship yuri
    // yuri i love amy is the best ship FUCKING KISS ALREADY girl love & girl love kissing girls, kissing girls my wife my wife yuri yuri my girlfriend hand holding
    // blushing girls i love amy is the best my girlfriend yuri cute girls'wlw *yuri* yuri yuri
    // lesbian - wlw yuri
=======
bool TrackedEntity::canBySeenBy(std::shared_ptr<ServerPlayer> player) {
    // 4J - for some reason this isn't currently working, and is causing players
    // to not appear until we are really close to them. Not sure what the
    // conflict is between the java & our version, but removing for now as it is
    // causing issues and we shouldn't *really* need it
    // TODO - investigate further
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return true;
    //	return player->getLevel()->getChunkMap()->isPlayerIn(player, e->xChunk,
    // e->zChunk);
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

<<<<<<< HEAD
    // my girlfriend-i love girls - yuri i love my girlfriend wlw, canon lesbian kiss yuri i love girls my girlfriend
    if (std::dynamic_pointer_cast<yuri_496>(e) != nullptr) {
        yHeadRotp = std::yuri_4644(e->yuri_6167() * 256 / 360);
        return std::shared_ptr<yuri_77>(
            new yuri_77(std::dynamic_pointer_cast<yuri_1950>(e), yRotp, xRotp,
=======
    // 4J-PB - replacing with a switch, rather than tons of ifs
    if (std::dynamic_pointer_cast<Creature>(e) != nullptr) {
        yHeadRotp = std::floor(e->getYHeadRot() * 256 / 360);
        return std::shared_ptr<AddMobPacket>(
            new AddMobPacket(std::dynamic_pointer_cast<Mob>(e), yRotp, xRotp,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
        // 4J Added yHeadRotp param to fix #102563 - TU12: Content: Gameplay:
        // When one of the Players is idle for a few minutes his head turns 180
        // degrees.
        return std::make_shared<AddPlayerPacket>(
            player, xuid, OnlineXuid, xp, yp, zp, yRotp, xRotp, yHeadRotp);
    } else if (e->instanceof(eTYPE_MINECART)) {
        std::shared_ptr<Minecart> minecart =
            std::dynamic_pointer_cast<Minecart>(e);
        return std::shared_ptr<AddEntityPacket>(
            new AddEntityPacket(e, AddEntityPacket::MINECART,
                                minecart->getType(), yRotp, xRotp, xp, yp, zp));
    } else if (e->instanceof(eTYPE_BOAT)) {
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::BOAT,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
