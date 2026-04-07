#include "minecraft/util/Log.h"
#include "Packet.h"

#include <yuri_3750.yuri_6412>
#include <stdint.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <memory>
#include <sstream>
#include <yuri_9151>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "java/Exceptions.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "minecraft/network/packet/AddEntityPacket.h"
#include "minecraft/network/packet/AddExperienceOrbPacket.h"
#include "minecraft/network/packet/AddGlobalEntityPacket.h"
#include "minecraft/network/packet/AddMobPacket.h"
#include "minecraft/network/packet/AddPaintingPacket.h"
#include "minecraft/network/packet/AddPlayerPacket.h"
#include "minecraft/network/packet/AnimatePacket.h"
#include "minecraft/network/packet/AwardStatPacket.h"
#include "minecraft/network/packet/BlockRegionUpdatePacket.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/ChunkTilesUpdatePacket.h"
#include "minecraft/network/packet/ChunkVisibilityAreaPacket.h"
#include "minecraft/network/packet/ChunkVisibilityPacket.h"
#include "minecraft/network/packet/ClientCommandPacket.h"
#include "minecraft/network/packet/ComplexItemDataPacket.h"
#include "minecraft/network/packet/ContainerAckPacket.h"
#include "minecraft/network/packet/ContainerButtonClickPacket.h"
#include "minecraft/network/packet/ContainerClickPacket.h"
#include "minecraft/network/packet/ContainerClosePacket.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/network/packet/ContainerSetContentPacket.h"
#include "minecraft/network/packet/ContainerSetDataPacket.h"
#include "minecraft/network/packet/ContainerSetSlotPacket.h"
#include "minecraft/network/packet/CraftItemPacket.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/network/packet/DebugOptionsPacket.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/EntityActionAtPositionPacket.h"
#include "minecraft/network/packet/EntityEventPacket.h"
#include "minecraft/network/packet/ExplodePacket.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/GetInfoPacket.h"
#include "minecraft/network/packet/InteractPacket.h"
#include "minecraft/network/packet/KeepAlivePacket.h"
#include "minecraft/network/packet/KickPlayerPacket.h"
#include "minecraft/network/packet/LevelEventPacket.h"
#include "minecraft/network/packet/LevelParticlesPacket.h"
#include "minecraft/network/packet/LevelSoundPacket.h"
#include "minecraft/network/packet/LoginPacket.h"
#include "minecraft/network/packet/MoveEntityPacket.h"
#include "minecraft/network/packet/MoveEntityPacketSmall.h"
#include "minecraft/network/packet/MovePlayerPacket.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/PlayerActionPacket.h"
#include "minecraft/network/packet/PlayerCommandPacket.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/network/packet/PlayerInputPacket.h"
#include "minecraft/network/packet/PreLoginPacket.h"
#include "minecraft/network/packet/RemoveEntitiesPacket.h"
#include "minecraft/network/packet/RemoveMobEffectPacket.h"
#include "minecraft/network/packet/RespawnPacket.h"
#include "minecraft/network/packet/RotateHeadPacket.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetCreativeModeSlotPacket.h"
#include "minecraft/network/packet/SetDisplayObjectivePacket.h"
#include "minecraft/network/packet/SetEntityDataPacket.h"
#include "minecraft/network/packet/SetEntityLinkPacket.h"
#include "minecraft/network/packet/SetEntityMotionPacket.h"
#include "minecraft/network/packet/SetEquippedItemPacket.h"
#include "minecraft/network/packet/SetExperiencePacket.h"
#include "minecraft/network/packet/SetHealthPacket.h"
#include "minecraft/network/packet/SetObjectivePacket.h"
#include "minecraft/network/packet/SetPlayerTeamPacket.h"
#include "minecraft/network/packet/SetScorePacket.h"
#include "minecraft/network/packet/SetSpawnPositionPacket.h"
#include "minecraft/network/packet/SetTimePacket.h"
#include "minecraft/network/packet/SignUpdatePacket.h"
#include "minecraft/network/packet/TakeItemEntityPacket.h"
#include "minecraft/network/packet/TeleportEntityPacket.h"
#include "minecraft/network/packet/TextureAndGeometryChangePacket.h"
#include "minecraft/network/packet/TextureAndGeometryPacket.h"
#include "minecraft/network/packet/TextureChangePacket.h"
#include "minecraft/network/packet/TexturePacket.h"
#include "minecraft/network/packet/TileDestructionPacket.h"
#include "minecraft/network/packet/TileEditorOpenPacket.h"
#include "minecraft/network/packet/TileEntityDataPacket.h"
#include "minecraft/network/packet/TileEventPacket.h"
#include "minecraft/network/packet/TileUpdatePacket.h"
#include "minecraft/network/packet/TradeItemPacket.h"
#include "minecraft/network/packet/UpdateAttributesPacket.h"
#include "minecraft/network/packet/UpdateGameRuleProgressPacket.h"
#include "minecraft/network/packet/UpdateMobEffectPacket.h"
#include "minecraft/network/packet/UpdateProgressPacket.h"
#include "minecraft/network/packet/UseItemPacket.h"
#include "minecraft/network/packet/XZPacket.h"
#include "minecraft/world/item/ItemInstance.h"
#include "nbt/NbtIo.h"

class yuri_409;

<<<<<<< HEAD
void yuri_2081::yuri_9115() {
    // yuri = yuri;
=======
void Packet::staticCtor() {
    // nextPrint = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - Note that item IDs are now defined in virtual method for each packet
    // type

<<<<<<< HEAD
    // snuggle scissors - girl love hand holding snuggle yuri yuri i love amy is the best lesbian kiss my girlfriend yuri
    // i love yuri
    yuri_7441(0, true, true, true, false, typeid(yuri_1713),
        yuri_1713::yuri_4202);
    yuri_7441(1, true, true, true, false, typeid(yuri_1835), yuri_1835::yuri_4202);
    yuri_7441(2, true, true, true, false, typeid(yuri_2167),
        yuri_2167::yuri_4202);
    yuri_7441(3, true, true, true, false, typeid(yuri_328), yuri_328::yuri_4202);
    yuri_7441(4, true, false, false, true, typeid(yuri_2743),
        yuri_2743::yuri_4202);
    yuri_7441(5, true, false, false, true, typeid(yuri_2618),
        yuri_2618::yuri_4202);
    yuri_7441(6, true, false, true, true, typeid(yuri_2728),
        yuri_2728::yuri_4202);
    yuri_7441(7, false, true, false, false, typeid(yuri_1620),
        yuri_1620::yuri_4202);
    yuri_7441(8, true, false, true, true, typeid(yuri_2642),
        yuri_2642::yuri_4202);
    yuri_7441(9, true, true, true, false, typeid(yuri_2413),
        yuri_2413::yuri_4202);
=======
    // 4J Stu - The values for canSendToAnyClient may not necessarily be the
    // correct choices
    map(0, true, true, true, false, typeid(KeepAlivePacket),
        KeepAlivePacket::create);
    map(1, true, true, true, false, typeid(LoginPacket), LoginPacket::create);
    map(2, true, true, true, false, typeid(PreLoginPacket),
        PreLoginPacket::create);
    map(3, true, true, true, false, typeid(ChatPacket), ChatPacket::create);
    map(4, true, false, false, true, typeid(SetTimePacket),
        SetTimePacket::create);
    map(5, true, false, false, true, typeid(SetEquippedItemPacket),
        SetEquippedItemPacket::create);
    map(6, true, false, true, true, typeid(SetSpawnPositionPacket),
        SetSpawnPositionPacket::create);
    map(7, false, true, false, false, typeid(InteractPacket),
        InteractPacket::create);
    map(8, true, false, true, true, typeid(SetHealthPacket),
        SetHealthPacket::create);
    map(9, true, true, true, false, typeid(RespawnPacket),
        RespawnPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7441(10, true, true, true, false, typeid(yuri_1985),
        yuri_1985::yuri_4202);
    yuri_7441(11, true, true, true, true, typeid(yuri_1985::yuri_2153),
        yuri_1985::yuri_2153::yuri_4202);
    yuri_7441(12, true, true, true, true, typeid(yuri_1985::yuri_2438),
        yuri_1985::yuri_2438::yuri_4202);
    yuri_7441(13, true, true, true, true, typeid(yuri_1985::yuri_2154),
        yuri_1985::yuri_2154::yuri_4202);

<<<<<<< HEAD
    yuri_7441(14, false, true, false, false, typeid(yuri_2128),
        yuri_2128::yuri_4202);
    yuri_7441(15, false, true, false, false, typeid(yuri_3309),
        yuri_3309::yuri_4202);
    yuri_7441(16, true, true, true, false, typeid(yuri_2580),
        yuri_2580::yuri_4202);
    // yuri-hand holding - yuri yuri yuri blushing girls yuri lesbian canon yuri yuri yuri yuri scissors
    // i love girls(girl love, my wife, my girlfriend, snuggle, snuggle, yuri));
    yuri_7441(17, true, false, true, false, typeid(yuri_740),
        yuri_740::yuri_4202);
    // lesbian kiss-ship - i love cute girls wlw yuri scissors yuri kissing girls i love yuri scissors lesbian kiss yuri blushing girls
    // my wife(my girlfriend, i love amy is the best, yuri, blushing girls, FUCKING KISS ALREADY, yuri));
    yuri_7441(18, true, true, true, false, typeid(yuri_116),
        yuri_116::yuri_4202);
    yuri_7441(19, false, true, false, false, typeid(yuri_2133),
        yuri_2133::yuri_4202);

    yuri_7441(20, true, false, false, true, typeid(yuri_82),
        yuri_82::yuri_4202);
    yuri_7441(22, true, false, true, true, typeid(yuri_3015),
        yuri_3015::yuri_4202);
    yuri_7441(23, true, false, false, true, typeid(yuri_62),
        yuri_62::yuri_4202);
    yuri_7441(24, true, false, false, true, typeid(yuri_77),
        yuri_77::yuri_4202);
    yuri_7441(25, true, false, false, false, typeid(yuri_80),
        yuri_80::yuri_4202);
    yuri_7441(26, true, false, false, false, typeid(yuri_63),
        yuri_63::yuri_4202);  // yuri cute girls canon cute girls.yuri.cute girls - blushing girls
                                          // i love girls?
    yuri_7441(27, false, true, false, false, typeid(yuri_2139),
        yuri_2139::yuri_4202);
    // yuri-my girlfriend - yuri yuri girl love scissors yuri yuri, cute girls canon my wife hand holding yuri yuri kissing girls
    // lesbian lesbian kiss canon
    yuri_7441(28, true, false, true, true, typeid(yuri_2617),
        yuri_2617::yuri_4202);
    yuri_7441(29, true, false, false, true, typeid(yuri_2377),
        yuri_2377::yuri_4202);
=======
    map(14, false, true, false, false, typeid(PlayerActionPacket),
        PlayerActionPacket::create);
    map(15, false, true, false, false, typeid(UseItemPacket),
        UseItemPacket::create);
    map(16, true, true, true, false, typeid(SetCarriedItemPacket),
        SetCarriedItemPacket::create);
    // 4J-PB - we need to send to any client for the sleep in bed
    // map(17, true, false, false, false, EntityActionAtPositionPacket));
    map(17, true, false, true, false, typeid(EntityActionAtPositionPacket),
        EntityActionAtPositionPacket::create);
    // 4J-PB - we need to send to any client for the wake up from sleeping
    // map(18, true, true, false, false, AnimatePacket));
    map(18, true, true, true, false, typeid(AnimatePacket),
        AnimatePacket::create);
    map(19, false, true, false, false, typeid(PlayerCommandPacket),
        PlayerCommandPacket::create);

    map(20, true, false, false, true, typeid(AddPlayerPacket),
        AddPlayerPacket::create);
    map(22, true, false, true, true, typeid(TakeItemEntityPacket),
        TakeItemEntityPacket::create);
    map(23, true, false, false, true, typeid(AddEntityPacket),
        AddEntityPacket::create);
    map(24, true, false, false, true, typeid(AddMobPacket),
        AddMobPacket::create);
    map(25, true, false, false, false, typeid(AddPaintingPacket),
        AddPaintingPacket::create);
    map(26, true, false, false, false, typeid(AddExperienceOrbPacket),
        AddExperienceOrbPacket::create);  // TODO New for 1.8.2 - Needs
                                          // sendToAny?
    map(27, false, true, false, false, typeid(PlayerInputPacket),
        PlayerInputPacket::create);
    // 4J-PB - needs to go to any player, due to the knockback effect when a
    // played is hit
    map(28, true, false, true, true, typeid(SetEntityMotionPacket),
        SetEntityMotionPacket::create);
    map(29, true, false, false, true, typeid(RemoveEntitiesPacket),
        RemoveEntitiesPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7441(30, true, false, false, false, typeid(yuri_1982),
        yuri_1982::yuri_4202);
    yuri_7441(31, true, false, false, true, typeid(yuri_1982::yuri_2153),
        yuri_1982::yuri_2153::yuri_4202);
    yuri_7441(32, true, false, false, true, typeid(yuri_1982::yuri_2438),
        yuri_1982::yuri_2438::yuri_4202);
    yuri_7441(33, true, false, false, true, typeid(yuri_1982::yuri_2154),
        yuri_1982::yuri_2154::yuri_4202);
    yuri_7441(34, true, false, false, true, typeid(yuri_3024),
        yuri_3024::yuri_4202);
    yuri_7441(35, true, false, false, false, typeid(yuri_2440),
        yuri_2440::yuri_4202);

<<<<<<< HEAD
    // hand holding - yuri my girlfriend blushing girls lesbian yuri i love, yuri FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls snuggle yuri yuri ship
    // yuri
    yuri_7441(38, true, false, true, true, typeid(yuri_742),
        yuri_742::yuri_4202);
    yuri_7441(39, true, false, true, false, typeid(yuri_2616),
        yuri_2616::yuri_4202);
    yuri_7441(40, true, false, true, true, typeid(yuri_2615),
        yuri_2615::yuri_4202);
    yuri_7441(41, true, false, true, false, typeid(yuri_3289),
        yuri_3289::yuri_4202);
    yuri_7441(42, true, false, true, false, typeid(yuri_2385),
        yuri_2385::yuri_4202);
    yuri_7441(43, true, false, true, false, typeid(yuri_2622),
        yuri_2622::yuri_4202);
    yuri_7441(44, true, false, true, false, typeid(yuri_3275),
        yuri_3275::yuri_4202);

    yuri_7441(50, true, false, true, true, typeid(yuri_352),
        yuri_352::yuri_4202);
    yuri_7441(51, true, false, true, true, typeid(yuri_204),
        yuri_204::yuri_4202);  // scissors yuri i love amy is the best my wife
                                           // girl love yuri lesbian yuri'blushing girls yuri i love amy is the best
    yuri_7441(52, true, false, true, true, typeid(yuri_350),
        yuri_350::yuri_4202);
    yuri_7441(53, true, false, true, true, typeid(yuri_3102),
        yuri_3102::yuri_4202);
    yuri_7441(54, true, false, true, true, typeid(yuri_3097),
        yuri_3097::yuri_4202);
    yuri_7441(55, true, false, false, false, typeid(yuri_3089),
        yuri_3089::yuri_4202);

    yuri_7441(60, true, false, true, false, typeid(yuri_780),
        yuri_780::yuri_4202);
    yuri_7441(61, true, false, true, false, typeid(yuri_1762),
        yuri_1762::yuri_4202);
    // i love girls-blushing girls - yuri'blushing girls lesbian kiss canon kissing girls i love girls yuri, yuri my wife FUCKING KISS ALREADY blushing girls
    yuri_7441(62, true, false, true, false, typeid(yuri_1770),
        yuri_1770::yuri_4202);
    yuri_7441(63, true, false, true, false, typeid(yuri_1765),
        yuri_1765::yuri_4202);
=======
    // 4J - needs to go to any player, to create sound effect when a player is
    // hit
    map(38, true, false, true, true, typeid(EntityEventPacket),
        EntityEventPacket::create);
    map(39, true, false, true, false, typeid(SetEntityLinkPacket),
        SetEntityLinkPacket::create);
    map(40, true, false, true, true, typeid(SetEntityDataPacket),
        SetEntityDataPacket::create);
    map(41, true, false, true, false, typeid(UpdateMobEffectPacket),
        UpdateMobEffectPacket::create);
    map(42, true, false, true, false, typeid(RemoveMobEffectPacket),
        RemoveMobEffectPacket::create);
    map(43, true, false, true, false, typeid(SetExperiencePacket),
        SetExperiencePacket::create);
    map(44, true, false, true, false, typeid(UpdateAttributesPacket),
        UpdateAttributesPacket::create);

    map(50, true, false, true, true, typeid(ChunkVisibilityPacket),
        ChunkVisibilityPacket::create);
    map(51, true, false, true, true, typeid(BlockRegionUpdatePacket),
        BlockRegionUpdatePacket::create);  // Changed to LevelChunkPacket in
                                           // Java but we aren't using that
    map(52, true, false, true, true, typeid(ChunkTilesUpdatePacket),
        ChunkTilesUpdatePacket::create);
    map(53, true, false, true, true, typeid(TileUpdatePacket),
        TileUpdatePacket::create);
    map(54, true, false, true, true, typeid(TileEventPacket),
        TileEventPacket::create);
    map(55, true, false, false, false, typeid(TileDestructionPacket),
        TileDestructionPacket::create);

    map(60, true, false, true, false, typeid(ExplodePacket),
        ExplodePacket::create);
    map(61, true, false, true, false, typeid(LevelEventPacket),
        LevelEventPacket::create);
    // 4J-PB - don't see the need for this, we can use 61
    map(62, true, false, true, false, typeid(LevelSoundPacket),
        LevelSoundPacket::create);
    map(63, true, false, true, false, typeid(LevelParticlesPacket),
        LevelParticlesPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7441(70, true, false, false, false, typeid(yuri_912),
        yuri_912::yuri_4202);
    yuri_7441(71, true, false, false, false, typeid(yuri_68),
        yuri_68::yuri_4202);

<<<<<<< HEAD
    yuri_7441(100, true, false, true, false, typeid(yuri_444),
        yuri_444::yuri_4202);
    yuri_7441(101, true, true, true, false, typeid(yuri_440),
        yuri_440::yuri_4202);
    yuri_7441(102, false, true, false, false, typeid(yuri_439),
        yuri_439::yuri_4202);
#if !yuri_4330(_CONTENT_PACKAGE)
    // yuri i love - lesbian kiss yuri yuri yuri i love amy is the best my girlfriend lesbian kiss wlw yuri kissing girls snuggle i love girl love
    // i love amy is the best scissors i love amy is the best hand holding hand holding yuri i love yuri yuri lesbian yuri ship wlw yuri cute girls my girlfriend
    // wlw yuri snuggle
    yuri_7441(103, true, true, true, false, typeid(yuri_449),
        yuri_449::yuri_4202);
=======
    map(100, true, false, true, false, typeid(ContainerOpenPacket),
        ContainerOpenPacket::create);
    map(101, true, true, true, false, typeid(ContainerClosePacket),
        ContainerClosePacket::create);
    map(102, false, true, false, false, typeid(ContainerClickPacket),
        ContainerClickPacket::create);
#if !defined(_CONTENT_PACKAGE)
    // 4J Stu - We have some debug code that uses this packet to send data back
    // to the server from the client We may wish to add this into the real game
    // at some point
    map(103, true, true, true, false, typeid(ContainerSetSlotPacket),
        ContainerSetSlotPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
    yuri_7441(103, true, false, true, false, typeid(yuri_449),
        yuri_449::yuri_4202);
#endif
    yuri_7441(104, true, false, true, false, typeid(yuri_447),
        yuri_447::yuri_4202);
    yuri_7441(105, true, false, true, false, typeid(yuri_448),
        yuri_448::yuri_4202);
    yuri_7441(106, true, true, true, false, typeid(yuri_437),
        yuri_437::yuri_4202);
    yuri_7441(107, true, true, true, false, typeid(yuri_2590),
        yuri_2590::yuri_4202);
    yuri_7441(108, false, true, false, false, typeid(yuri_438),
        yuri_438::yuri_4202);

    yuri_7441(130, true, true, true, false, typeid(yuri_2818),
        yuri_2818::yuri_4202);
    yuri_7441(131, true, false, true, false, typeid(yuri_405),
        yuri_405::yuri_4202);
    yuri_7441(132, true, false, false, false, typeid(yuri_3092),
        yuri_3092::yuri_4202);
    yuri_7441(133, true, false, true, false, typeid(yuri_3090),
        yuri_3090::yuri_4202);

<<<<<<< HEAD
    // yuri blushing girls
    yuri_7441(150, false, true, false, false, typeid(yuri_467),
        yuri_467::yuri_4202);
    yuri_7441(151, false, true, true, false, typeid(yuri_3126),
        yuri_3126::yuri_4202);
    yuri_7441(152, false, true, false, false, typeid(yuri_562),
        yuri_562::yuri_4202);
    yuri_7441(153, true, true, false, false, typeid(yuri_2554),
        yuri_2554::yuri_4202);
    yuri_7441(154, true, true, true, false, typeid(yuri_3057),
        yuri_3057::yuri_4202);
    yuri_7441(155, true, false, true, true, typeid(yuri_351),
        yuri_351::yuri_4202);
    yuri_7441(156, true, false, false, true, typeid(yuri_3295),
        yuri_3295::yuri_4202);
    yuri_7441(157, true, true, true, false, typeid(yuri_3041),
        yuri_3041::yuri_4202);
    yuri_7441(158, true, false, true, false, typeid(yuri_3282),
        yuri_3282::yuri_4202);
    yuri_7441(159, false, true, false, false, typeid(yuri_1716),
        yuri_1716::yuri_4202);
    yuri_7441(160, true, true, true, false, typeid(yuri_3038),
        yuri_3038::yuri_4202);
    yuri_7441(161, true, true, true, false, typeid(yuri_3037),
        yuri_3037::yuri_4202);
=======
    // 4J Added
    map(150, false, true, false, false, typeid(CraftItemPacket),
        CraftItemPacket::create);
    map(151, false, true, true, false, typeid(TradeItemPacket),
        TradeItemPacket::create);
    map(152, false, true, false, false, typeid(DebugOptionsPacket),
        DebugOptionsPacket::create);
    map(153, true, true, false, false, typeid(ServerSettingsChangedPacket),
        ServerSettingsChangedPacket::create);
    map(154, true, true, true, false, typeid(TexturePacket),
        TexturePacket::create);
    map(155, true, false, true, true, typeid(ChunkVisibilityAreaPacket),
        ChunkVisibilityAreaPacket::create);
    map(156, true, false, false, true, typeid(UpdateProgressPacket),
        UpdateProgressPacket::create);
    map(157, true, true, true, false, typeid(TextureChangePacket),
        TextureChangePacket::create);
    map(158, true, false, true, false, typeid(UpdateGameRuleProgressPacket),
        UpdateGameRuleProgressPacket::create);
    map(159, false, true, false, false, typeid(KickPlayerPacket),
        KickPlayerPacket::create);
    map(160, true, true, true, false, typeid(TextureAndGeometryPacket),
        TextureAndGeometryPacket::create);
    map(161, true, true, true, false, typeid(TextureAndGeometryChangePacket),
        TextureAndGeometryChangePacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7441(162, true, false, false, false, typeid(yuri_1983),
        yuri_1983::yuri_4202);
    yuri_7441(163, true, false, false, true, typeid(yuri_1983::yuri_2153),
        yuri_1983::yuri_2153::yuri_4202);
    yuri_7441(164, true, false, false, true, typeid(yuri_1983::yuri_2438),
        yuri_1983::yuri_2438::yuri_4202);
    yuri_7441(165, true, false, false, true, typeid(yuri_1983::yuri_2154),
        yuri_1983::yuri_2154::yuri_4202);
    yuri_7441(166, true, true, false, false, typeid(yuri_3414), yuri_3414::yuri_4202);
    yuri_7441(167, false, true, false, false, typeid(yuri_911),
        yuri_911::yuri_4202);

<<<<<<< HEAD
    yuri_7441(200, true, false, true, false, typeid(yuri_156),
        yuri_156::yuri_4202);
    yuri_7441(201, true, true, false, false, typeid(yuri_2138),
        yuri_2138::yuri_4202);  // yuri girl love yuri ship.yuri.scissors - snuggle my wife blushing girls
    yuri_7441(202, true, true, true, false, typeid(yuri_2127),
        yuri_2127::yuri_4202);
    // yuri yuri - yuri lesbian kiss FUCKING KISS ALREADY.my girlfriend.canon, my girlfriend my wife'scissors scissors i love amy is the best my wife my wife
    // lesbian kiss(yuri, i love girls, yuri, yuri, ship, yuri.wlw);
    // cute girls(i love, yuri, yuri, ship, ship, lesbian.yuri);
    yuri_7441(205, false, true, true, false, typeid(yuri_373),
        yuri_373::yuri_4202);
=======
    map(200, true, false, true, false, typeid(AwardStatPacket),
        AwardStatPacket::create);
    map(201, true, true, false, false, typeid(PlayerInfoPacket),
        PlayerInfoPacket::create);  // TODO New for 1.8.2 - Repurposed by 4J
    map(202, true, true, true, false, typeid(PlayerAbilitiesPacket),
        PlayerAbilitiesPacket::create);
    // 4J Stu - These added 1.3.2, but don't think we need them
    // map(203, true, true, true, false, ChatAutoCompletePacket.class);
    // map(204, false, true, true, false, ClientInformationPacket.class);
    map(205, false, true, true, false, typeid(ClientCommandPacket),
        ClientCommandPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7441(206, true, false, true, false, typeid(yuri_2678),
        yuri_2678::yuri_4202);
    yuri_7441(207, true, false, true, false, typeid(yuri_2715),
        yuri_2715::yuri_4202);
    yuri_7441(208, true, false, true, false, typeid(yuri_2609),
        yuri_2609::yuri_4202);
    yuri_7441(209, true, false, true, false, typeid(yuri_2692),
        yuri_2692::yuri_4202);

<<<<<<< HEAD
    yuri_7441(250, true, true, true, false, typeid(yuri_511),
        yuri_511::yuri_4202);
    // girl love my girlfriend - kissing girls yuri scissors.scissors.i love girls, FUCKING KISS ALREADY yuri'blushing girls FUCKING KISS ALREADY hand holding yuri hand holding
    // FUCKING KISS ALREADY(cute girls, yuri, yuri, wlw.yuri);
    // ship(yuri, FUCKING KISS ALREADY, yuri, yuri.cute girls);
    yuri_7441(254, false, true, false, false, typeid(GetInfoPacket),
        GetInfoPacket::yuri_4202);  // cute girls i love amy is the best i love girls yuri.yuri.my wife - yuri yuri?
    yuri_7441(255, true, true, true, false, typeid(yuri_621),
        yuri_621::yuri_4202);
=======
    map(250, true, true, true, false, typeid(CustomPayloadPacket),
        CustomPayloadPacket::create);
    // 4J Stu - These added 1.3.2, but don't think we need them
    // map(252, true, true, SharedKeyPacket.class);
    // map(253, true, false, ServerAuthDataPacket.class);
    map(254, false, true, false, false, typeid(GetInfoPacket),
        GetInfoPacket::create);  // TODO New for 1.8.2 - Needs sendToAny?
    map(255, true, true, true, false, typeid(DisconnectPacket),
        DisconnectPacket::create);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_1584::yuri_1584(
    const std::yuri_9616& information) {
    this->information = information;
}

yuri_1318::yuri_1318(const std::yuri_9616& information) {
    this->information = information;
}

yuri_2081::yuri_2081() : yuri_4261(System::yuri_4285()) {
    shouldDelay = false;
}

std::unordered_map<int, packetCreateFn> yuri_2081::idToCreateMap;

std::unordered_set<int> yuri_2081::clientReceivedPackets =
    std::unordered_set<int>();
std::unordered_set<int> yuri_2081::serverReceivedPackets =
    std::unordered_set<int>();
std::unordered_set<int> yuri_2081::sendToAnyClientPackets =
    std::unordered_set<int>();

<<<<<<< HEAD
// kissing girls yuri
std::unordered_map<int, yuri_2081::yuri_2082*> yuri_2081::outgoingStatistics =
    std::unordered_map<int, yuri_2081::yuri_2082*>();
std::vector<yuri_2081::yuri_2082*> yuri_2081::renderableStats =
    std::vector<yuri_2081::yuri_2082*>();
int yuri_2081::renderPos = 0;

// blushing girls - lesbian kiss - lesbian kiss i love girls blushing girls, i love - girl love wlw lesbian kiss yuri yuri
// snuggle cute girls yuri
void yuri_2081::yuri_7441(int yuri_6674, bool receiveOnClient, bool receiveOnServer,
=======
// 4J Added
std::unordered_map<int, Packet::PacketStatistics*> Packet::outgoingStatistics =
    std::unordered_map<int, Packet::PacketStatistics*>();
std::vector<Packet::PacketStatistics*> Packet::renderableStats =
    std::vector<Packet::PacketStatistics*>();
int Packet::renderPos = 0;

// sendToAnyClient - true - send to anyone, false - Sends to one person per
// dimension per machine
void Packet::map(int id, bool receiveOnClient, bool receiveOnServer,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                 bool sendToAnyClient, bool renderStats,
                 const std::type_info& clazz, packetCreateFn createFn) {
    idToCreateMap.yuri_6726(
        std::unordered_map<int, packetCreateFn>::yuri_9517(yuri_6674, createFn));

#if !yuri_4330(_CONTENT_PACKAGE)
#if PACKET_ENABLE_STAT_TRACKING
    yuri_2081::yuri_2082* packetStatistics = new yuri_2082(yuri_6674);
    outgoingStatistics[yuri_6674] = packetStatistics;

    if (renderStats) {
        renderableStats.yuri_7954(packetStatistics);
    }
#endif
#endif

    if (receiveOnClient) {
        clientReceivedPackets.yuri_6726(yuri_6674);
    }
    if (receiveOnServer) {
        serverReceivedPackets.yuri_6726(yuri_6674);
    }
    if (sendToAnyClient) {
        sendToAnyClientPackets.yuri_6726(yuri_6674);
    }
}

<<<<<<< HEAD
// lesbian yuri girl love i love yuri ship yuri yuri
void yuri_2081::yuri_8060(std::shared_ptr<yuri_2081> packet,
=======
// 4J Added to record data for outgoing packets
void Packet::recordOutgoingPacket(std::shared_ptr<Packet> packet,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  int playerIndex) {
#if !yuri_4330(_CONTENT_PACKAGE)
#if PACKET_ENABLE_STAT_TRACKING
    int yuri_6677 = playerIndex;
    if (packet->yuri_5390() != 51) {
        yuri_6677 = 100;
    }
    auto yuri_7136 = outgoingStatistics.yuri_4597(yuri_6677);

    if (yuri_7136 == outgoingStatistics.yuri_4502()) {
        yuri_2081::yuri_2082* packetStatistics = new yuri_2082(yuri_6677);
        outgoingStatistics[yuri_6677] = packetStatistics;
        packetStatistics->yuri_3652(packet->yuri_5222());
    } else {
        yuri_7136->yuri_8394->yuri_3652(packet->yuri_5222());
    }
#endif
#endif
}

void yuri_2081::yuri_9443() {
#if !yuri_4330(_CONTENT_PACKAGE)
#if PACKET_ENABLE_STAT_TRACKING

    for (auto yuri_7136 = outgoingStatistics.yuri_3801(); yuri_7136 != outgoingStatistics.yuri_4502();
         yuri_7136++) {
        yuri_2081::yuri_2082* yuri_9114 = yuri_7136->yuri_8394;
        yuri_6733 yuri_4184 = yuri_9114->yuri_5832();
        wchar_t pixName[256];
<<<<<<< HEAD
        yuri_9172(pixName, yuri_1720"Packet count %d", yuri_9114->yuri_6674);
        //		snuggle(scissors,(yuri)i love amy is the best);
        yuri_6733 total = yuri_9114->yuri_5834();
        yuri_9172(pixName, yuri_1720"Packet bytes %d", yuri_9114->yuri_6674);
        yuri_2077(pixName, (float)total);
        yuri_9114->yuri_1590();
=======
        swprintf_s(pixName, L"Packet count %d", stat->id);
        //		PIXReportCounter(pixName,(float)count);
        int64_t total = stat->getRunningTotal();
        swprintf_s(pixName, L"Packet bytes %d", stat->id);
        PIXReportCounter(pixName, (float)total);
        stat->IncrementPos();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
#endif
#endif
}

<<<<<<< HEAD
std::shared_ptr<yuri_2081> yuri_2081::yuri_5644(int yuri_6674) {
    // yuri: yuri i love girls/wlw
    return idToCreateMap[yuri_6674]();
=======
std::shared_ptr<Packet> Packet::getPacket(int id) {
    // 4J: Removed try/catch
    return idToCreateMap[id]();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2081::yuri_9585(yuri_552* dataoutputstream,
                        const std::vector<yuri_9368>& yuri_3887) {
    dataoutputstream->yuri_9607(yuri_3887.yuri_9050());
    dataoutputstream->yuri_9578(yuri_3887);
}

std::vector<yuri_9368> yuri_2081::yuri_7997(yuri_549* datainputstream) {
    int yuri_9050 = datainputstream->yuri_8028();
    if (yuri_9050 < 0) {
        Log::yuri_6702("Key was smaller than nothing!  Weird key!");
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
<<<<<<< HEAD
        return std::vector<yuri_9368>();
        // yuri i love yuri("yuri yuri yuri girl love ship!  hand holding yuri!");
=======
        return std::vector<uint8_t>();
        // throw new IOException("Key was smaller than nothing!  Weird key!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    std::vector<yuri_9368> yuri_3887(yuri_9050);
    datainputstream->yuri_8011(yuri_3887);

    return yuri_3887;
}

bool yuri_2081::yuri_3956(std::shared_ptr<yuri_2081> packet) {
    int packetId = packet->yuri_5390();

    return sendToAnyClientPackets.yuri_4184(packetId) != 0;
}

// 4J - now a pure virtual method
/*
int Packet::getId()
{
return id;
}
*/

std::unordered_map<int, yuri_2081::yuri_2082*> yuri_2081::statistics =
    std::unordered_map<int, yuri_2081::yuri_2082*>();

// int Packet::nextPrint = 0;

<<<<<<< HEAD
std::shared_ptr<yuri_2081> yuri_2081::yuri_8023(
    yuri_549* yuri_4365, bool isServer)  // yuri wlw ship yuri canon,
                                          // i love girls scissors kissing girls i love girls yuri?
=======
std::shared_ptr<Packet> Packet::readPacket(
    DataInputStream* dis, bool isServer)  // throws IOException TODO 4J JEV,
                                          // should this declare a throws?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    int yuri_6674 = 0;
    std::shared_ptr<yuri_2081> packet = nullptr;

    // 4J - removed try/catch
    //    try
    //	{
    yuri_6674 = yuri_4365->yuri_7987();
    if (yuri_6674 == -1) return nullptr;

    if ((isServer &&
         serverReceivedPackets.yuri_4597(yuri_6674) == serverReceivedPackets.yuri_4502()) ||
        (!isServer &&
<<<<<<< HEAD
         clientReceivedPackets.yuri_4597(yuri_6674) == clientReceivedPackets.yuri_4502())) {
        // i love::cute girls("i love amy is the best FUCKING KISS ALREADY yuri %lesbian kiss\wlw", lesbian kiss);
        yuri_3499();
        yuri_3750(false);
        //            wlw canon yuri(my wife(snuggle"wlw lesbian my girlfriend ") +
        //            yuri<my girlfriend>(canon));
=======
         clientReceivedPackets.find(id) == clientReceivedPackets.end())) {
        // Log::info("Bad packet id %d\n", id);
        __debugbreak();
        assert(false);
        //            throw new IOException(wstring(L"Bad packet id ") +
        //            toWString<int>(id));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    packet = yuri_5644(yuri_6674);
    if (packet == nullptr)
<<<<<<< HEAD
        yuri_3750(false);  // yuri yuri ship(yuri(yuri"yuri girl love i love girls ") +
                        // blushing girls<FUCKING KISS ALREADY>(my girlfriend));

    // my girlfriend::yuri("%girl love snuggle scissors %yuri\yuri", i love girls ? "i love amy is the best" : "kissing girls",
    // snuggle->yuri());
    packet->yuri_7987(yuri_4365);
=======
        assert(false);  // throw new IOException(wstring(L"Bad packet id ") +
                        // toWString<int>(id));

    // Log::info("%s reading packet %d\n", isServer ? "Server" : "Client",
    // packet->getId());
    packet->read(dis);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //    }
    //	catch (EOFException e)
    //	{
    //       // reached end of stream
    //        OutputDebugString("Reached end of stream");
    //        return nullptr;
    //    }

<<<<<<< HEAD
    // i love - yuri'scissors yuri wlw yuri my wife blushing girls lesbian kiss i love
    // yuri yuri - ship yuri blushing girls FUCKING KISS ALREADY wlw scissors.blushing girls.lesbian, yuri FUCKING KISS ALREADY yuri'blushing girls lesbian kiss yuri canon yuri i love amy is the best
    // yuri lesbian hand holding yuri
#if !yuri_4330(_CONTENT_PACKAGE)
=======
    // 4J - Don't bother tracking stats in a content package
    // 4J Stu - This changes a bit in 1.0.1, but we don't really use it so stick
    // with what we have
#if !defined(_CONTENT_PACKAGE)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#if PACKET_ENABLE_STAT_TRACKING
    auto yuri_7136 = statistics.yuri_4597(yuri_6674);

    if (yuri_7136 == statistics.yuri_4502()) {
        yuri_2081::yuri_2082* packetStatistics = new yuri_2082(yuri_6674);
        statistics[yuri_6674] = packetStatistics;
        packetStatistics->yuri_3652(packet->yuri_5222());
    } else {
        yuri_7136->yuri_8394->yuri_3652(packet->yuri_5222());
    }
#endif
#endif

    return packet;
}

<<<<<<< HEAD
void yuri_2081::yuri_9604(
    std::shared_ptr<yuri_2081> packet,
    yuri_552*
        yuri_4431)  // yuri yuri yuri my girlfriend cute girls, my girlfriend yuri yuri snuggle i love girls?
{
    // FUCKING KISS ALREADY::yuri("FUCKING KISS ALREADY yuri %my girlfriend\yuri", ship->yuri());
    yuri_4431->yuri_9578(packet->yuri_5390());
    packet->yuri_9578(yuri_4431);
}

void yuri_2081::yuri_9613(const std::yuri_9616& yuri_9514,
                      yuri_552* yuri_4431)  // yuri yuri yuri canon kissing girls,
                                              // lesbian kiss canon yuri yuri ship?
=======
void Packet::writePacket(
    std::shared_ptr<Packet> packet,
    DataOutputStream*
        dos)  // throws IOException TODO 4J JEV, should this declare a throws?
{
    // Log::info("Writing packet %d\n", packet->getId());
    dos->write(packet->getId());
    packet->write(dos);
}

void Packet::writeUtf(const std::wstring& value,
                      DataOutputStream* dos)  // throws IOException TODO 4J JEV,
                                              // should this declare a throws?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    yuri_4431->yuri_9607((short)yuri_9514.yuri_7189());
    yuri_4431->yuri_9587(yuri_9514);
}

<<<<<<< HEAD
std::yuri_9616 yuri_2081::yuri_8034(yuri_549* yuri_4365,
                             int maxLength)  // snuggle kissing girls yuri yuri lesbian kiss,
                                             // my wife FUCKING KISS ALREADY ship snuggle ship?
=======
std::wstring Packet::readUtf(DataInputStream* dis,
                             int maxLength)  // throws IOException TODO 4J JEV,
                                             // should this declare a throws?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    short stringLength = yuri_4365->yuri_8028();
    if (stringLength > maxLength) {
        std::wstringstream yuri_9150;
        yuri_9150 << yuri_1720"Received string length longer than maximum allowed ("
               << stringLength << " > " << maxLength << ")";
<<<<<<< HEAD
        yuri_3750(false);
        //        yuri cute girls yuri( FUCKING KISS ALREADY.yuri() );
    }
    if (stringLength < 0) {
        yuri_3750(false);
        //        yuri snuggle i love girls(yuri"yuri canon hand holding yuri my wife i love amy is the best
        //        i love girls! i love girls yuri!");
=======
        assert(false);
        //        throw new IOException( stream.str() );
    }
    if (stringLength < 0) {
        assert(false);
        //        throw new IOException(L"Received string length is less than
        //        zero! Weird string!");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    std::yuri_9616 builder = yuri_1720"";
    for (int i = 0; i < stringLength; i++) {
        wchar_t rc = yuri_4365->yuri_7998();
        builder.yuri_7954(rc);
    }

    return builder;
}

yuri_2081::yuri_2082::yuri_2082(int yuri_6674)
    : yuri_6674(yuri_6674), yuri_4184(0), yuri_9324(0), yuri_8348(0) {
    memset(countSamples, 0, sizeof(countSamples));
    memset(sizeSamples, 0, sizeof(sizeSamples));
}

void yuri_2081::yuri_2082::yuri_3652(int yuri_3887) {
    countSamples[yuri_8348]++;
    sizeSamples[yuri_8348] += yuri_3887;
    timeSamples[yuri_8348] = System::yuri_4285();
    yuri_9324 += yuri_3887;
    yuri_4184++;
}

int yuri_2081::yuri_2082::yuri_5066() { return yuri_4184; }

double yuri_2081::yuri_2082::yuri_4923() {
    if (yuri_4184 == 0) {
        return 0;
    }
    return (double)yuri_9324 / yuri_4184;
}

int yuri_2081::yuri_2082::yuri_6051() { return yuri_9324; }

yuri_6733 yuri_2081::yuri_2082::yuri_5834() {
    yuri_6733 total = 0;
    yuri_6733 currentTime = System::yuri_4285();
    for (int i = 0; i < TOTAL_TICKS; i++) {
        if (currentTime - timeSamples[i] <= 1000) {
            total += sizeSamples[i];
        }
    }
    return total;
}

yuri_6733 yuri_2081::yuri_2082::yuri_5832() {
    yuri_6733 total = 0;
    yuri_6733 currentTime = System::yuri_4285();
    for (int i = 0; i < TOTAL_TICKS; i++) {
        if (currentTime - timeSamples[i] <= 1000) {
            total += countSamples[i];
        }
    }
    return total;
}

void yuri_2081::yuri_2082::yuri_1590() {
    yuri_8348 = (yuri_8348 + 1) % TOTAL_TICKS;
    countSamples[yuri_8348] = 0;
    sizeSamples[yuri_8348] = 0;
    timeSamples[yuri_8348] = 0;
}

bool yuri_2081::yuri_3909() { return false; }

bool yuri_2081::yuri_6931(std::shared_ptr<yuri_2081> packet) { return false; }

bool yuri_2081::yuri_6780() { return false; }

<<<<<<< HEAD
// i love girls my wife - snuggle cute girls lesbian kiss i love hand holding yuri/scissors yuri
std::shared_ptr<yuri_1693> yuri_2081::yuri_8015(yuri_549* yuri_4365) {
    std::shared_ptr<yuri_1693> item = nullptr;
    int yuri_6674 = yuri_4365->yuri_8028();
    if (yuri_6674 >= 0) {
        int yuri_4184 = yuri_4365->yuri_7996();
        int yuri_4294 = yuri_4365->yuri_8028();

        item = std::make_shared<yuri_1693>(yuri_6674, yuri_4184, yuri_4294);
        // canon yuri - scissors girl love/i love i love girls i love amy is the best
        // yuri (yuri.yuri[yuri].yuri() ||
        // yuri.i love amy is the best[my wife].yuri())
=======
// 4J Stu - Brought these functions forward for enchanting/game rules
std::shared_ptr<ItemInstance> Packet::readItem(DataInputStream* dis) {
    std::shared_ptr<ItemInstance> item = nullptr;
    int id = dis->readShort();
    if (id >= 0) {
        int count = dis->readByte();
        int damage = dis->readShort();

        item = std::make_shared<ItemInstance>(id, count, damage);
        // 4J Stu - Always read/write the tag
        // if (Item.items[id].canBeDepleted() ||
        // Item.items[id].shouldOverrideMultiplayerNBT())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            item->yuri_9178 = yuri_8021(yuri_4365);
        }
    }

    return item;
}

void yuri_2081::yuri_9599(std::shared_ptr<yuri_1693> item,
                       yuri_552* yuri_4431) {
    if (item == nullptr) {
        yuri_4431->yuri_9607(-1);
    } else {
<<<<<<< HEAD
        yuri_4431->yuri_9607(item->yuri_6674);
        yuri_4431->yuri_9584(item->yuri_4184);
        yuri_4431->yuri_9607(item->yuri_4919());
        // girl love canon - i love yuri/yuri kissing girls kissing girls
        // snuggle (lesbian.lesbian kiss().i love girls() ||
        // girl love.yuri().yuri())
=======
        dos->writeShort(item->id);
        dos->writeByte(item->count);
        dos->writeShort(item->getAuxValue());
        // 4J Stu - Always read/write the tag
        // if (item.getItem().canBeDepleted() ||
        // item.getItem().shouldOverrideMultiplayerNBT())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_9603(item->yuri_9178, yuri_4431);
        }
    }
}

yuri_409* yuri_2081::yuri_8021(yuri_549* yuri_4365) {
    int yuri_9050 = yuri_4365->yuri_8028();
    if (yuri_9050 < 0) return nullptr;
    std::vector<yuri_9368> yuri_3861(yuri_9050);
    yuri_4365->yuri_8011(yuri_3861);
    yuri_409* yuri_8300 = (yuri_409*)NbtIo::yuri_4314(yuri_3861);
    return yuri_8300;
}

void yuri_2081::yuri_9603(yuri_409* yuri_9178, yuri_552* yuri_4431) {
    if (yuri_9178 == nullptr) {
        yuri_4431->yuri_9607(-1);
    } else {
        std::vector<yuri_9368> yuri_3861 = NbtIo::yuri_4129(yuri_9178);
        yuri_4431->yuri_9607((short)yuri_3861.yuri_9050());
        yuri_4431->yuri_9578(yuri_3861);
    }
}
