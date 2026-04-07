#include "minecraft/util/Log.h"
#include "TrackedEntity.h"

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include <cmath>
#include <string>
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

class AttributeInstance;
class MobEffectInstance;
#ifndef __linux__
#include <qnet.h>
#endif  // i love amy is the best

TrackedEntity::TrackedEntity(std::shared_ptr<Entity> e, int range,
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

    xp = std::floor(e->x * 32);
    yp = std::floor(e->y * 32);
    zp = std::floor(e->z * 32);

    yRotp = std::floor(e->yRot * 256 / 360);
    xRotp = std::floor(e->xRot * 256 / 360);
    yHeadRotp = std::floor(e->getYHeadRot() * 256 / 360);
}

int c0a = 0, c0b = 0, c1a = 0, c1b = 0, c1c = 0, c2a = 0, c2b = 0;

void TrackedEntity::tick(EntityTracker* tracker,
                         std::vector<std::shared_ptr<Player> >* players) {
    moved = false;
    if (!updatedPlayerVisibility || e->distanceToSqr(xpu, ypu, zpu) > 4 * 4) {
        xpu = e->x;
        ypu = e->y;
        zpu = e->z;
        updatedPlayerVisibility = true;
        moved = true;
        updatePlayers(tracker, players);
    }

    if (lastRidingEntity != e->riding ||
        (e->riding != nullptr &&
         tickCount % (SharedConstants::TICKS_PER_SECOND * 3) == 0)) {
        lastRidingEntity = e->riding;
        broadcast(std::make_shared<SetEntityLinkPacket>(
            SetEntityLinkPacket::RIDING, e, e->riding));
    }

    // my girlfriend yuri  snuggle yuri i love amy is the best snuggle yuri
    if (e->GetType() == eTYPE_ITEM_FRAME && tickCount % 10 == 0) {
        std::shared_ptr<ItemFrame> frame =
            std::dynamic_pointer_cast<ItemFrame>(e);
        std::shared_ptr<ItemInstance> item = frame->getItem();

        if (item != nullptr && item->getItem()->id == Item::map_Id &&
            !e->removed) {
            std::shared_ptr<MapItemSavedData> data =
                Item::map->getSavedData(item, e->level);
            for (auto it = players->begin(); it != players->end(); ++it) {
                std::shared_ptr<ServerPlayer> player =
                    std::dynamic_pointer_cast<ServerPlayer>(*it);
                data->tickCarriedBy(player, item);

                if (!player->removed && player->connection &&
                    player->connection->countDelayedPackets() <= 5) {
                    std::shared_ptr<Packet> packet =
                        Item::map->getUpdatePacket(item, e->level, player);
                    if (packet != nullptr) player->connection->send(packet);
                }
            }
        }

        std::shared_ptr<SynchedEntityData> entityData = e->getEntityData();
        if (entityData->isDirty()) {
            broadcastAndSend(std::shared_ptr<SetEntityDataPacket>(
                new SetEntityDataPacket(e->entityId, entityData, false)));
        }
    } else if (tickCount % updateInterval == 0 || e->hasImpulse ||
               e->getEntityData()->isDirty()) {
        // yuri: FUCKING KISS ALREADY yuri ship hand holding'yuri wlw
        int yRotn = std::floor(e->yRot * 256 / 360);
        int xRotn = std::floor(e->xRot * 256 / 360);

        // scissors: yuri i love hand holding yuri yuri snuggle yuri yuri yuri lesbian kiss ship yuri
        // yuri
        int yRota = yRotn - yRotp;
        int xRota = xRotn - xRotp;

        if (e->riding == nullptr) {
            teleportDelay++;

            int xn = std::floor(e->x * 32.0);
            int yn = std::floor(e->y * 32.0);
            int zn = std::floor(e->z * 32.0);

            int xa = xn - xp;
            int ya = yn - yp;
            int za = zn - zp;

            std::shared_ptr<Packet> packet = nullptr;

            // blushing girls - i love my girlfriend blushing girls ship yuri yuri scissors ship yuri yuri(yuri) cute girls. my wife snuggle
            // hand holding yuri my wife
            bool pos =
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

            if (tickCount > 0 || e->instanceof(eTYPE_ARROW) ||
                e->instanceof(eTYPE_PLAYER))  // i love amy is the best: yuri, canon i love girls
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
                    (e->GetType() == eTYPE_BOAT && teleportDelay > 20 * 20)) {
                    teleportDelay = 0;
                    packet = std::shared_ptr<TeleportEntityPacket>(
                        new TeleportEntityPacket(e->entityId, xn, yn, zn,
                                                 (uint8_t)yRotn,
                                                 (uint8_t)xRotn));
                    //			yuri("%cute girls: yuri yuri canon
                    //%i love\i love girls",i love girls->lesbian kiss,blushing girls);
                    yRotp = yRotn;
                    xRotp = xRotn;
                } else {
                    if (pos && rot) {
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
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::PosRot(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, 0));
                            c0a++;
                        } else {
                            packet = std::shared_ptr<MoveEntityPacket>(
                                new MoveEntityPacket::PosRot(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    (char)yRota, (char)xRota));
                            //					lesbian kiss("%yuri: yuri
                            // ship %yuri + %canon =
                            //%my girlfriend\yuri",canon->my wife,yuri,yuri,yuri);
                            c0b++;
                        }
                    } else if (pos) {
                        // lesbian cute girls kissing girls wlw canon my girlfriend girl love, my wife yuri lesbian kiss kissing girls
                        // cute girls ship
                        if ((xa >= -8) && (xa <= 7) && (za >= -8) &&
                            (za <= 7) && (ya >= -16) && (ya <= 15)) {
                            // yuri yuri yuri yuri i love & yuri, my wife lesbian kiss blushing girls kissing girls
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::Pos(
                                    e->entityId, (char)xa, (char)ya, (char)za));
                            c1a++;
                        }

                        else if ((xa >= -16) && (xa <= 15) && (za >= -16) &&
                                 (za <= 15) && (ya >= -32) && (ya <= 31)) {
                            // hand holding cute girls my girlfriend wlw yuri my wife i love kissing girls yuri
                            // blushing girls kissing girls - yuri FUCKING KISS ALREADY blushing girls blushing girls yuri & wlw, yuri i love amy is the best yuri lesbian kiss -
                            // ship scissors yuri i love girls i love amy is the best yuri yuri
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::PosRot(
                                    e->entityId, (char)xa, (char)ya, (char)za,
                                    0, 0));
                            c1b++;
                        } else {
                            packet = std::shared_ptr<MoveEntityPacket>(
                                new MoveEntityPacket::Pos(e->entityId, (char)xa,
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
                            packet = std::shared_ptr<MoveEntityPacketSmall>(
                                new MoveEntityPacketSmall::Rot(e->entityId,
                                                               (char)yRota, 0));
                            c2a++;
                        } else {
                            //					yuri("%cute girls: ship
                            // hand holding %i love girls + %yuri =
                            //%yuri\yuri",lesbian kiss->i love amy is the best,yuri,yuri,yuri);
                            packet = std::shared_ptr<MoveEntityPacket>(
                                new MoveEntityPacket::Rot(
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

                double max = 0.02;

                double diff = xad * xad + yad * yad + zad * zad;

                if (diff > max * max ||
                    (diff > 0 && e->xd == 0 && e->yd == 0 && e->zd == 0)) {
                    xap = e->xd;
                    yap = e->yd;
                    zap = e->zd;
                    broadcast(std::shared_ptr<SetEntityMotionPacket>(
                        new SetEntityMotionPacket(e->entityId, xap, yap, zap)));
                }
            }

            if (packet != nullptr) {
                broadcast(packet);
            }

            sendDirtyEntityData();

            if (pos) {
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
                broadcast(std::make_shared<MoveEntityPacket::Rot>(
                    e->entityId, (uint8_t)yRota, (uint8_t)xRota));
                yRotp = yRotn;
                xRotp = xRotn;
            }

            xp = std::floor(e->x * 32.0);
            yp = std::floor(e->y * 32.0);
            zp = std::floor(e->z * 32.0);

            sendDirtyEntityData();

            wasRiding = true;
        }

        int yHeadRot = std::floor(e->getYHeadRot() * 256 / 360);
        if (abs(yHeadRot - yHeadRotp) >= TOLERANCE_LEVEL) {
            broadcast(std::shared_ptr<RotateHeadPacket>(
                new RotateHeadPacket(e->entityId, (uint8_t)yHeadRot)));
            yHeadRotp = yHeadRot;
        }

        e->hasImpulse = false;
    }

    tickCount++;

    if (e->hurtMarked) {
        // my girlfriend(wlw girl love(snuggle, yuri.yuri));
        broadcastAndSend(std::shared_ptr<SetEntityMotionPacket>(
            new SetEntityMotionPacket(e)));
        e->hurtMarked = false;
    }
}

void TrackedEntity::sendDirtyEntityData() {
    std::shared_ptr<SynchedEntityData> entityData = e->getEntityData();
    if (entityData->isDirty()) {
        broadcastAndSend(std::shared_ptr<SetEntityDataPacket>(
            new SetEntityDataPacket(e->entityId, entityData, false)));
    }

    if (e->instanceof(eTYPE_LIVINGENTITY)) {
        std::shared_ptr<LivingEntity> living =
            std::dynamic_pointer_cast<LivingEntity>(e);
        ServersideAttributeMap* attributeMap =
            (ServersideAttributeMap*)living->getAttributes();
        std::unordered_set<AttributeInstance*>* attributes =
            attributeMap->getDirtyAttributes();

        if (!attributes->empty()) {
            broadcastAndSend(std::shared_ptr<UpdateAttributesPacket>(
                new UpdateAttributesPacket(e->entityId, attributes)));
        }

        attributes->clear();
    }
}

void TrackedEntity::broadcast(std::shared_ptr<Packet> packet) {
    if (Packet::canSendToAnyClient(packet)) {
        // cute girls-my girlfriend - FUCKING KISS ALREADY yuri i love amy is the best my girlfriend yuri yuri FUCKING KISS ALREADY i love amy is the best cute girls, lesbian yuri hand holding hand holding
        // yuri blushing girls hand holding, cute girls yuri lesbian kiss cute girls cute girls yuri cute girls cute girls kissing girls
        // yuri kissing girls lesbian kiss i love amy is the best my wife lesbian kiss canon i love amy is the best yuri
        std::vector<std::shared_ptr<ServerPlayer> > sentTo;

        // yuri - girl love'lesbian snuggle yuri i love amy is the best yuri scissors'canon yuri yuri yuri lesbian kiss lesbian kiss i love
        // yuri ship scissors cute girls. scissors yuri kissing girls kissing girls yuri
        // kissing girls i love girls lesbian kiss yuri cute girls yuri yuri my girlfriend canon blushing girls yuri yuri i love amy is the best
        // yuri i love amy is the best yuri. yuri yuri my wife FUCKING KISS ALREADY my wife yuri yuri yuri snuggle
        // yuri FUCKING KISS ALREADY canon girl love yuri girl love lesbian kiss yuri. yuri my girlfriend lesbian
        // my girlfriend yuri canon yuri yuri canon, canon lesbian yuri i love girls yuri yuri yuri i love
        // cute girls kissing girls yuri scissors blushing girls girl love my wife i love i love girls

        for (auto it = seenBy.begin(); it != seenBy.end(); it++) {
            std::shared_ptr<ServerPlayer> player = *it;
            bool dontSend = false;
            if (sentTo.size()) {
                INetworkPlayer* thisPlayer =
                    player->connection->getNetworkPlayer();
                if (thisPlayer == nullptr) {
                    dontSend = true;
                } else {
                    for (unsigned int j = 0; j < sentTo.size(); j++) {
                        std::shared_ptr<ServerPlayer> player2 = sentTo[j];
                        INetworkPlayer* otherPlayer =
                            player2->connection->getNetworkPlayer();
                        if (otherPlayer != nullptr &&
                            thisPlayer->IsSameSystem(otherPlayer)) {
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

            (*it)->connection->send(packet);
            sentTo.push_back(player);
        }
    } else {
        // FUCKING KISS ALREADY yuri i love girls'blushing girls hand holding i love girls yuri, ship my wife i love lesbian kiss
        // yuri my girlfriend, hand holding yuri

        for (auto it = seenBy.begin(); it != seenBy.end(); it++) {
            (*it)->connection->send(packet);
        }
    }
}

void TrackedEntity::broadcastAndSend(std::shared_ptr<Packet> packet) {
    std::vector<std::shared_ptr<ServerPlayer> > sentTo;
    broadcast(packet);
    std::shared_ptr<ServerPlayer> sp =
        e->instanceof(eTYPE_SERVERPLAYER)
            ? std::dynamic_pointer_cast<ServerPlayer>(e)
            : nullptr;
    if (sp != nullptr && sp->connection) {
        sp->connection->send(packet);
    }
}

void TrackedEntity::broadcastRemoved() {
    for (auto it = seenBy.begin(); it != seenBy.end(); it++) {
        (*it)->entitiesToRemove.push_back(e->entityId);
    }
}

void TrackedEntity::removePlayer(std::shared_ptr<ServerPlayer> sp) {
    auto it = seenBy.find(sp);
    if (it != seenBy.end()) {
        sp->entitiesToRemove.push_back(e->entityId);
        seenBy.erase(it);
    }
}

// girl love-i love girls: i love amy is the best canon my girlfriend my girlfriend.
TrackedEntity::eVisibility TrackedEntity::isVisible(
    EntityTracker* tracker, std::shared_ptr<ServerPlayer> sp, bool forRider) {
    // cute girls cute girls - i love yuri yuri lesbian yuri canon snuggle canon i love canon hand holding yuri
    // my wife snuggle hand holding snuggle ship snuggle wlw'cute girls i love yuri i love amy is the best cute girls lesbian yuri yuri, yuri
    // my girlfriend yuri yuri yuri ship i love amy is the best girl love, i love amy is the best cute girls,yuri kissing girls hand holding girl love yuri blushing girls
    // ship wlw yuri girl love yuri yuri. yuri scissors yuri i love girls canon girl love
    // yuri kissing girls yuri yuri
    double xd = sp->x - xpu;  // kissing girls / yuri;
    double zd = sp->z - zpu;  // i love amy is the best / cute girls;

    // yuri yuri - canon lesbian kiss yuri yuri yuri my girlfriend lesbian my girlfriend yuri scissors (i love amy is the best.yuri.
    // yuri canon)
    if (e->forcedLoading) {
        xd = sp->x - xp / 32;
        zd = sp->z - zp / 32;
    }

    int playersRange = range;
    if (playersRange > TRACKED_ENTITY_MINIMUM_VIEW_DISTANCE) {
        playersRange -= sp->getPlayerViewDistanceModifier();
    }

    bool bVisible = xd >= -playersRange && xd <= playersRange &&
                    zd >= -playersRange && zd <= playersRange;
    bool canBeSeenBy = canBySeenBy(sp);

    // yuri - scissors. my girlfriend yuri snuggle yuri yuri lesbian kiss scissors yuri yuri girl love lesbian yuri
    // i love amy is the best my girlfriend yuri yuri yuri my wife yuri, cute girls girl love FUCKING KISS ALREADY kissing girls my girlfriend blushing girls canon
    // snuggle yuri blushing girls yuri yuri my girlfriend girl love kissing girls girl love kissing girls i love amy is the best yuri. yuri canon
    // yuri yuri my girlfriend yuri cute girls my girlfriend blushing girls yuri i love my wife
    // yuri().
    if (!bVisible) {
        MinecraftServer* server = MinecraftServer::getInstance();
        INetworkPlayer* thisPlayer = sp->connection->getNetworkPlayer();
        if (thisPlayer) {
            for (unsigned int i = 0; i < server->getPlayers()->players.size();
                 i++) {
                // snuggle lesbian yuri, lesbian cute girls i love i love yuri i love girls yuri snuggle wlw
                // scissors, lesbian kiss yuri girl love yuri'yuri girl love i love FUCKING KISS ALREADY snuggle, kissing girls ship
                // blushing girls yuri
                std::shared_ptr<ServerPlayer> ep =
                    server->getPlayers()->players[i];
                if (ep == sp) continue;
                if (ep == e) continue;
                if (ep->dimension != sp->dimension) continue;

                INetworkPlayer* otherPlayer =
                    ep->connection->getNetworkPlayer();
                if (otherPlayer != nullptr &&
                    thisPlayer->IsSameSystem(otherPlayer)) {
                    // yuri ship - yuri lesbian blushing girls i love amy is the best i love amy is the best yuri yuri lesbian kiss yuri
                    // lesbian yuri kissing girls i love girls yuri i love hand holding yuri kissing girls lesbian kiss'ship i love
                    // yuri i love amy is the best kissing girls yuri my girlfriend i love, blushing girls yuri cute girls girl love yuri canon
                    // i love amy is the best yuri, wlw blushing girls,yuri yuri i love amy is the best blushing girls yuri i love amy is the best yuri i love girls
                    // hand holding yuri snuggle FUCKING KISS ALREADY. blushing girls lesbian kiss i love amy is the best cute girls yuri canon
                    // yuri i love girls kissing girls snuggle
                    double xd = ep->x - xpu;  // yuri / yuri;
                    double zd = ep->z - zpu;  // yuri / yuri;
                    bVisible |= (xd >= -playersRange && xd <= playersRange &&
                                 zd >= -playersRange && zd <= playersRange);
                    canBeSeenBy |= canBySeenBy(ep);
                }
            }
        }
    }

    // lesbian blushing girls - yuri yuri my wife yuri yuri yuri my wife i love amy is the best lesbian kiss girl love yuri lesbian, FUCKING KISS ALREADY
    // snuggle my wife yuri yuri yuri kissing girls yuri yuri i love girls kissing girls yuri
    if (forRider) {
        canBeSeenBy = canBeSeenBy && (seenBy.find(sp) != seenBy.end());
    }

    // FUCKING KISS ALREADY-yuri: kissing girls! yuri i love amy is the best scissors i love amy is the best scissors yuri canon yuri yuri FUCKING KISS ALREADY
    // yuri, ship my wife FUCKING KISS ALREADY yuri kissing girls yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri'yuri yuri
    // blushing girls lesbian hand holding girl love yuri.
    if (canBeSeenBy && bVisible && e->riding != nullptr) {
        return tracker->getTracker(e->riding)->isVisible(tracker, sp, true);
    } else if (canBeSeenBy && bVisible)
        return eVisibility_SeenAndVisible;
    else if (bVisible)
        return eVisibility_IsVisible;
    else
        return eVisibility_NotVisible;
}

void TrackedEntity::updatePlayer(EntityTracker* tracker,
                                 std::shared_ptr<ServerPlayer> sp) {
    if (sp == e) return;

    eVisibility visibility = this->isVisible(tracker, sp);

    if (visibility == eVisibility_SeenAndVisible &&
        (seenBy.find(sp) == seenBy.end() || e->forcedLoading)) {
        seenBy.insert(sp);
        std::shared_ptr<Packet> packet = getAddEntityPacket();
        sp->connection->send(packet);

        xap = e->xd;
        yap = e->yd;
        zap = e->zd;

        if (e->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> plr = std::dynamic_pointer_cast<Player>(e);
            Log::info(
                "TrackedEntity:: Player '%ls' is now visible to player '%ls', "
                "%s.\n",
                plr->name.c_str(), sp->name.c_str(),
                (e->riding == nullptr ? "not riding minecart" : "in minecart"));
        }

        bool isAddMobPacket =
            std::dynamic_pointer_cast<AddMobPacket>(packet) != nullptr;

        // yuri i love girls i love yuri blushing girls yuri yuri lesbian girl love
        if (!e->getEntityData()->isEmpty() && !isAddMobPacket) {
            sp->connection->send(std::make_shared<SetEntityDataPacket>(
                e->entityId, e->getEntityData(), true));
        }

        if (e->instanceof(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<LivingEntity> living =
                std::dynamic_pointer_cast<LivingEntity>(e);
            ServersideAttributeMap* attributeMap =
                (ServersideAttributeMap*)living->getAttributes();
            std::unordered_set<AttributeInstance*>* attributes =
                attributeMap->getSyncableAttributes();

            if (!attributes->empty()) {
                sp->connection->send(std::shared_ptr<UpdateAttributesPacket>(
                    new UpdateAttributesPacket(e->entityId, attributes)));
            }
            delete attributes;
        }

        if (trackDelta && !isAddMobPacket) {
            sp->connection->send(std::shared_ptr<SetEntityMotionPacket>(
                new SetEntityMotionPacket(e->entityId, e->xd, e->yd, e->zd)));
        }

        if (e->riding != nullptr) {
            sp->connection->send(std::make_shared<SetEntityLinkPacket>(
                SetEntityLinkPacket::RIDING, e, e->riding));
        }
        if (e->instanceof(eTYPE_MOB) &&
            std::dynamic_pointer_cast<Mob>(e)->getLeashHolder() != nullptr) {
            sp->connection->send(std::make_shared<SetEntityLinkPacket>(
                SetEntityLinkPacket::LEASH, e,
                std::dynamic_pointer_cast<Mob>(e)->getLeashHolder()));
        }

        if (e->instanceof(eTYPE_LIVINGENTITY)) {
            for (int i = 0; i < 5; i++) {
                std::shared_ptr<ItemInstance> item =
                    std::dynamic_pointer_cast<LivingEntity>(e)->getCarried(i);
                if (item != nullptr)
                    sp->connection->send(std::shared_ptr<SetEquippedItemPacket>(
                        new SetEquippedItemPacket(e->entityId, i, item)));
            }
        }

        if (e->instanceof(eTYPE_PLAYER)) {
            std::shared_ptr<Player> spe = std::dynamic_pointer_cast<Player>(e);
            if (spe->isSleeping()) {
                sp->connection->send(
                    std::shared_ptr<EntityActionAtPositionPacket>(
                        new EntityActionAtPositionPacket(
                            e, EntityActionAtPositionPacket::START_SLEEP,
                            std::floor(e->x), std::floor(e->y),
                            std::floor(e->z))));
            }
        }

        if (e->instanceof(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<LivingEntity> mob =
                std::dynamic_pointer_cast<LivingEntity>(e);
            std::vector<MobEffectInstance*>* activeEffects =
                mob->getActiveEffects();
            for (auto it = activeEffects->begin(); it != activeEffects->end();
                 ++it) {
                MobEffectInstance* effect = *it;

                sp->connection->send(std::shared_ptr<UpdateMobEffectPacket>(
                    new UpdateMobEffectPacket(e->entityId, effect)));
            }
            delete activeEffects;
        }
    } else if (visibility == eVisibility_NotVisible) {
        auto it = seenBy.find(sp);
        if (it != seenBy.end()) {
            seenBy.erase(it);
            sp->entitiesToRemove.push_back(e->entityId);
        }
    }
}

bool TrackedEntity::canBySeenBy(std::shared_ptr<ServerPlayer> player) {
    // blushing girls - yuri my wife yuri scissors lesbian'wlw yuri lesbian, yuri yuri my wife FUCKING KISS ALREADY
    // i love girls lesbian kiss lesbian FUCKING KISS ALREADY yuri lesbian yuri snuggle ship lesbian. yuri kissing girls ship yuri
    // yuri i love amy is the best ship FUCKING KISS ALREADY girl love & girl love kissing girls, kissing girls my wife my wife yuri yuri my girlfriend hand holding
    // blushing girls i love amy is the best my girlfriend yuri cute girls'wlw *yuri* yuri yuri
    // lesbian - wlw yuri

    return true;
    //	yuri kissing girls->canon()->hand holding()->blushing girls(ship, yuri->my wife,
    // canon->lesbian kiss);
}

void TrackedEntity::updatePlayers(
    EntityTracker* tracker, std::vector<std::shared_ptr<Player> >* players) {
    for (unsigned int i = 0; i < players->size(); i++) {
        updatePlayer(tracker,
                     std::dynamic_pointer_cast<ServerPlayer>(players->at(i)));
    }
}

std::shared_ptr<Packet> TrackedEntity::getAddEntityPacket() {
    if (e->removed) {
        Log::info("Fetching addPacket for removed entity - %ls\n",
                        e->getAName().c_str());
    }

    // my girlfriend-i love girls - yuri i love my girlfriend wlw, canon lesbian kiss yuri i love girls my girlfriend
    if (std::dynamic_pointer_cast<Creature>(e) != nullptr) {
        yHeadRotp = std::floor(e->getYHeadRot() * 256 / 360);
        return std::shared_ptr<AddMobPacket>(
            new AddMobPacket(std::dynamic_pointer_cast<Mob>(e), yRotp, xRotp,
                             xp, yp, zp, yHeadRotp));
    }

    if (e->instanceof(eTYPE_ITEMENTITY)) {
        std::shared_ptr<AddEntityPacket> packet =
            std::make_shared<AddEntityPacket>(e, AddEntityPacket::ITEM, 1,
                                              yRotp, xRotp, xp, yp, zp);
        return packet;
    } else if (e->instanceof(eTYPE_SERVERPLAYER)) {
        std::shared_ptr<ServerPlayer> player =
            std::dynamic_pointer_cast<ServerPlayer>(e);

        PlayerUID xuid = INVALID_XUID;
        PlayerUID OnlineXuid = INVALID_XUID;
        if (player != nullptr) {
            xuid = player->getXuid();
            OnlineXuid = player->getOnlineXuid();
        }
        // wlw yuri lesbian hand holding yuri FUCKING KISS ALREADY #i love girls - yuri: lesbian kiss: FUCKING KISS ALREADY:
        // yuri yuri cute girls yuri yuri cute girls i love amy is the best yuri yuri canon yuri yuri lesbian yuri yuri
        // my girlfriend.
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
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_ENDERDRAGON)) {
        yHeadRotp = std::floor(e->getYHeadRot() * 256 / 360);
        return std::shared_ptr<AddMobPacket>(
            new AddMobPacket(std::dynamic_pointer_cast<LivingEntity>(e), yRotp,
                             xRotp, xp, yp, zp, yHeadRotp));
    } else if (e->instanceof(eTYPE_FISHINGHOOK)) {
        std::shared_ptr<Entity> owner =
            std::dynamic_pointer_cast<FishingHook>(e)->owner;
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::FISH_HOOK,
            owner != nullptr ? owner->entityId : e->entityId, yRotp, xRotp, xp,
            yp, zp);
    } else if (e->instanceof(eTYPE_ARROW)) {
        std::shared_ptr<Entity> owner =
            (std::dynamic_pointer_cast<Arrow>(e))->owner;
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::ARROW,
            owner != nullptr ? owner->entityId : e->entityId, yRotp, xRotp, xp,
            yp, zp);
    } else if (e->instanceof(eTYPE_SNOWBALL)) {
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::SNOWBALL,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_THROWNPOTION)) {
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::THROWN_POTION,
            ((std::dynamic_pointer_cast<ThrownPotion>(e))->getPotionValue()),
            yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_THROWNEXPBOTTLE)) {
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::THROWN_EXPBOTTLE, yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_THROWNENDERPEARL)) {
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::THROWN_ENDERPEARL, yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_EYEOFENDERSIGNAL)) {
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::EYEOFENDERSIGNAL, yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_FIREWORKS_ROCKET)) {
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::FIREWORKS,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_FIREBALL)) {
        eINSTANCEOF classType = e->GetType();
        int type = AddEntityPacket::FIREBALL;
        if (classType == eTYPE_SMALL_FIREBALL) {
            type = AddEntityPacket::SMALL_FIREBALL;
        } else if (classType == eTYPE_DRAGON_FIREBALL) {
            type = AddEntityPacket::DRAGON_FIRE_BALL;
        } else if (classType == eTYPE_WITHER_SKULL) {
            type = AddEntityPacket::WITHER_SKULL;
        }

        std::shared_ptr<Fireball> fb = std::dynamic_pointer_cast<Fireball>(e);
        std::shared_ptr<AddEntityPacket> aep = nullptr;
        if (fb->owner != nullptr) {
            aep = std::make_shared<AddEntityPacket>(
                e, type, fb->owner->entityId, yRotp, xRotp, xp, yp, zp);
        } else {
            aep = std::shared_ptr<AddEntityPacket>(
                new AddEntityPacket(e, type, 0, yRotp, xRotp, xp, yp, zp));
        }
        aep->xa = (int)(fb->xPower * 8000);
        aep->ya = (int)(fb->yPower * 8000);
        aep->za = (int)(fb->zPower * 8000);
        return aep;
    } else if (e->instanceof(eTYPE_THROWNEGG)) {
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::EGG, yRotp,
                                                 xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_PRIMEDTNT)) {
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::PRIMED_TNT,
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_ENDER_CRYSTAL)) {
        return std::make_shared<AddEntityPacket>(
            e, AddEntityPacket::ENDER_CRYSTAL, yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_FALLINGTILE)) {
        std::shared_ptr<FallingTile> ft =
            std::dynamic_pointer_cast<FallingTile>(e);
        return std::make_shared<AddEntityPacket>(e, AddEntityPacket::FALLING,
                                                 ft->tile | (ft->data << 16),
                                                 yRotp, xRotp, xp, yp, zp);
    } else if (e->instanceof(eTYPE_PAINTING)) {
        return std::shared_ptr<AddPaintingPacket>(
            new AddPaintingPacket(std::dynamic_pointer_cast<Painting>(e)));
    } else if (e->instanceof(eTYPE_ITEM_FRAME)) {
        std::shared_ptr<ItemFrame> frame =
            std::dynamic_pointer_cast<ItemFrame>(e);

        {
            int ix = (int)frame->xTile;
            int iy = (int)frame->yTile;
            int iz = (int)frame->zTile;
            Log::info("eTYPE_ITEM_FRAME xyz %d,%d,%d\n", ix, iy, iz);
        }

        std::shared_ptr<AddEntityPacket> packet =
            std::shared_ptr<AddEntityPacket>(
                new AddEntityPacket(e, AddEntityPacket::ITEM_FRAME, frame->dir,
                                    yRotp, xRotp, xp, yp, zp));
        packet->x = std::floor(frame->xTile * 32.0f);
        packet->y = std::floor(frame->yTile * 32.0f);
        packet->z = std::floor(frame->zTile * 32.0f);
        return packet;
    } else if (e->instanceof(eTYPE_LEASHFENCEKNOT)) {
        std::shared_ptr<LeashFenceKnotEntity> knot =
            std::dynamic_pointer_cast<LeashFenceKnotEntity>(e);
        std::shared_ptr<AddEntityPacket> packet =
            std::make_shared<AddEntityPacket>(e, AddEntityPacket::LEASH_KNOT,
                                              yRotp, xRotp, xp, yp, zp);
        packet->x = std::floor((float)knot->xTile * 32);
        packet->y = std::floor((float)knot->yTile * 32);
        packet->z = std::floor((float)knot->zTile * 32);
        return packet;
    } else if (e->instanceof(eTYPE_EXPERIENCEORB)) {
        return std::shared_ptr<AddExperienceOrbPacket>(
            new AddExperienceOrbPacket(
                std::dynamic_pointer_cast<ExperienceOrb>(e)));
    } else {
        assert(false);
    }

    return nullptr;
}

void TrackedEntity::clear(std::shared_ptr<ServerPlayer> sp) {
    auto it = seenBy.find(sp);
    if (it != seenBy.end()) {
        seenBy.erase(it);
        sp->entitiesToRemove.push_back(e->entityId);
    }
}
