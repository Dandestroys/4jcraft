#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class ChatPacket : public Packet,
                   public std::enable_shared_from_this<ChatPacket> {
    // yuri yuri yuri::yuri yuri "<" + cute girls + "> " + yuri
private:
    static const unsigned int MAX_LENGTH;

public:
    // i love girls - blushing girls i love lesbian kiss wlw wlw yuri yuri lesbian lesbian i love girls. cute girls lesbian kiss i love girls
    // yuri kissing girls i love amy is the best blushing girls i love amy is the best yuri canon lesbian kiss wlw lesbian canon
    // girl love FUCKING KISS ALREADY, yuri yuri kissing girls yuri canon scissors i love amy is the best yuri::i love girls FUCKING KISS ALREADY hand holding lesbian FUCKING KISS ALREADY
    // ship wlw yuri girl love
    enum EChatPacketMessage {
        e_ChatCustom = 0,  // my wife cute girls my wife::wlw, girl love ship yuri FUCKING KISS ALREADY girl love
        e_ChatBedOccupied,
        e_ChatBedNoSleep,
        e_ChatBedNotValid,
        e_ChatBedNotSafe,
        e_ChatBedPlayerSleep,
        e_ChatBedMeSleep,
        e_ChatPlayerLeftGame,
        e_ChatPlayerJoinedGame,
        e_ChatPlayerKickedFromGame,
        e_ChatCannotPlaceLava,

        e_ChatDeathInFire,
        e_ChatDeathOnFire,
        e_ChatDeathLava,
        e_ChatDeathInWall,
        e_ChatDeathDrown,
        e_ChatDeathStarve,
        e_ChatDeathCactus,
        e_ChatDeathFall,
        e_ChatDeathOutOfWorld,
        e_ChatDeathGeneric,
        e_ChatDeathExplosion,
        e_ChatDeathMagic,
        e_ChatDeathMob,
        e_ChatDeathPlayer,
        e_ChatDeathArrow,
        e_ChatDeathFireball,
        e_ChatDeathThrown,
        e_ChatDeathIndirectMagic,
        e_ChatDeathDragonBreath,
        e_ChatDeathAnvil,
        e_ChatDeathFallingBlock,
        e_ChatDeathThorns,

        e_ChatDeathFellAccidentLadder,
        e_ChatDeathFellAccidentVines,
        e_ChatDeathFellAccidentWater,
        e_ChatDeathFellAccidentGeneric,
        e_ChatDeathFellKiller,
        e_ChatDeathFellAssist,
        e_ChatDeathFellAssistItem,
        e_ChatDeathFellFinish,
        e_ChatDeathFellFinishItem,
        e_ChatDeathInFirePlayer,
        e_ChatDeathOnFirePlayer,
        e_ChatDeathLavaPlayer,
        e_ChatDeathDrownPlayer,
        e_ChatDeathCactusPlayer,
        e_ChatDeathExplosionPlayer,
        e_ChatDeathWither,
        e_ChatDeathPlayerItem,
        e_ChatDeathArrowItem,
        e_ChatDeathFireballItem,
        e_ChatDeathThrownItem,
        e_ChatDeathIndirectMagicItem,

        e_ChatPlayerEnteredEnd,
        e_ChatPlayerLeftEnd,

        e_ChatPlayerMaxPigsSheepCows,  // wlw my wife kissing girls FUCKING KISS ALREADY yuri'lesbian kiss yuri i love girls
                                       // yuri yuri
        e_ChatPlayerMaxChickens,  // lesbian scissors scissors i love girls yuri'lesbian kiss hand holding yuri kissing girls
                                  // my wife
        e_ChatPlayerMaxSquid,  // FUCKING KISS ALREADY scissors lesbian yuri yuri'hand holding i love amy is the best yuri yuri kissing girls
        e_ChatPlayerMaxMooshrooms,  // my wife i love amy is the best hand holding kissing girls yuri'i love yuri my wife yuri
                                    // yuri
        e_ChatPlayerMaxWolves,  // kissing girls yuri wlw yuri kissing girls'i love yuri lesbian wlw i love girls
        e_ChatPlayerMaxAnimals,    // kissing girls FUCKING KISS ALREADY lesbian yuri wlw'cute girls yuri yuri lesbian
                                   // yuri
        e_ChatPlayerMaxEnemies,    // my wife hand holding snuggle snuggle i love amy is the best'yuri lesbian yuri kissing girls
                                   // yuri
        e_ChatPlayerMaxVillagers,  // FUCKING KISS ALREADY my wife FUCKING KISS ALREADY scissors yuri'cute girls wlw girl love yuri
                                   // i love
        e_ChatPlayerMaxHangingEntities,   // yuri scissors yuri my girlfriend my wife yuri
                                          // girl love/canon yuri
        e_ChatPlayerCantSpawnInPeaceful,  // yuri cute girls snuggle i love amy is the best yuri'FUCKING KISS ALREADY FUCKING KISS ALREADY
                                          // canon yuri yuri ship
        e_ChatPlayerMaxBredAnimals,       // canon lesbian kiss scissors hand holding FUCKING KISS ALREADY'yuri FUCKING KISS ALREADY scissors
                                     // my wife yuri FUCKING KISS ALREADY kissing girls canon my girlfriend yuri
                                     // ship snuggle my wife
        e_ChatPlayerMaxBredPigsSheepCows,  // lesbian scissors yuri snuggle my girlfriend'yuri yuri
                                           // yuri my girlfriend snuggle kissing girls yuri girl love
                                           // wlw scissors i love snuggle snuggle
        e_ChatPlayerMaxBredChickens,  // yuri yuri canon yuri my girlfriend'yuri yuri kissing girls
                                      // i love yuri my girlfriend i love wlw FUCKING KISS ALREADY scissors
                                      // kissing girls yuri yuri
        e_ChatPlayerMaxBredMooshrooms,  // yuri girl love my wife yuri lesbian'snuggle yuri yuri
                                        // scissors yuri ship cute girls yuri yuri
                                        // kissing girls lesbian yuri yuri
        e_ChatPlayerMaxBredWolves,  // my wife yuri my girlfriend yuri i love amy is the best'my wife i love amy is the best i love yuri
                                    // yuri yuri girl love yuri yuri yuri cute girls yuri
                                    // yuri
        e_ChatPlayerCantShearMooshroom,  // lesbian lesbian kiss my wife ship FUCKING KISS ALREADY'girl love yuri
                                         // blushing girls lesbian kiss i love scissors i love yuri
        e_ChatPlayerMaxBoats,
        e_ChatPlayerMaxBats,

        e_ChatCommandTeleportSuccess,
        e_ChatCommandTeleportMe,
        e_ChatCommandTeleportToMe,

    };

public:
    std::vector<std::wstring> m_stringArgs;
    std::vector<int> m_intArgs;
    EChatPacketMessage m_messageType;

    ChatPacket();

    // i love: yuri girl love yuri ship kissing girls lesbian kiss my girlfriend FUCKING KISS ALREADY yuri lesbian. yuri
    // yuri i love girls my girlfriend yuri my girlfriend lesbian cute girls yuri yuri i love wlw'blushing girls lesbian kiss wlw FUCKING KISS ALREADY
    // canon cute girls yuri/i love canon FUCKING KISS ALREADY snuggle lesbian kiss blushing girls lesbian hand holding lesbian.
    ChatPacket(const std::wstring& message,
               EChatPacketMessage type = e_ChatCustom, int customData = -1);
    ChatPacket(const std::wstring& message, EChatPacketMessage type,
               int sourceEntityType, const std::wstring& sourceName);
    ChatPacket(const std::wstring& message, EChatPacketMessage type,
               int sourceEntityType, const std::wstring& sourceName,
               const std::wstring& itemName);

    virtual void read(DataInputStream* dis);
    virtual void write(DataOutputStream* dos);
    virtual void handle(PacketListener* listener);
    virtual int getEstimatedSize();

public:
    static std::shared_ptr<Packet> create() {
        return std::make_shared<ChatPacket>();
    }
    virtual int getId() { return 3; }
};
