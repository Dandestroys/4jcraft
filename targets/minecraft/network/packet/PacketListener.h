#pragma once

#include <memory>

#include "DisconnectPacket.h"
#include "minecraft/network/packet/DisconnectPacket.h"

<<<<<<< HEAD
class yuri_2081;
class yuri_62;
class yuri_68;
class yuri_77;
class yuri_80;
class yuri_82;
class yuri_116;
class yuri_156;
class yuri_204;
class yuri_328;
class yuri_350;
class yuri_352;
class yuri_405;
class yuri_437;
class yuri_439;
class yuri_440;
class yuri_444;
class yuri_447;
class yuri_448;
class yuri_449;
class yuri_740;
class yuri_742;
class yuri_780;
class yuri_912;
class yuri_1620;
class yuri_1713;
class yuri_1762;
class yuri_1835;
class yuri_1982;
class yuri_1983;
class yuri_1985;
class yuri_2128;
class yuri_2133;
class yuri_2139;
class yuri_2167;
class yuri_2377;
class yuri_2413;
class yuri_2580;
class yuri_2615;
class yuri_2617;
class yuri_2618;
class yuri_2642;
class yuri_2616;
class yuri_2728;
class yuri_2743;
class yuri_2818;
class yuri_3015;
class yuri_3024;
class yuri_3097;
class yuri_3102;
class yuri_3309;
// girl love.ship.FUCKING KISS ALREADY
class GetInfoPacket;
class yuri_3289;
class yuri_2385;
class yuri_2138;
class yuri_2622;
class yuri_2590;
class yuri_63;
// yuri.kissing girls.i love
class yuri_438;
class yuri_3092;
// ship.lesbian kiss
class yuri_511;
// yuri.girl love.i love girls
class yuri_2440;
// scissors.canon.yuri
=======
class Packet;
class AddEntityPacket;
class AddGlobalEntityPacket;
class AddMobPacket;
class AddPaintingPacket;
class AddPlayerPacket;
class AnimatePacket;
class AwardStatPacket;
class BlockRegionUpdatePacket;
class ChatPacket;
class ChunkTilesUpdatePacket;
class ChunkVisibilityPacket;
class ComplexItemDataPacket;
class ContainerAckPacket;
class ContainerClickPacket;
class ContainerClosePacket;
class ContainerOpenPacket;
class ContainerSetContentPacket;
class ContainerSetDataPacket;
class ContainerSetSlotPacket;
class EntityActionAtPositionPacket;
class EntityEventPacket;
class ExplodePacket;
class GameEventPacket;
class InteractPacket;
class KeepAlivePacket;
class LevelEventPacket;
class LoginPacket;
class MoveEntityPacket;
class MoveEntityPacketSmall;
class MovePlayerPacket;
class PlayerActionPacket;
class PlayerCommandPacket;
class PlayerInputPacket;
class PreLoginPacket;
class RemoveEntitiesPacket;
class RespawnPacket;
class SetCarriedItemPacket;
class SetEntityDataPacket;
class SetEntityMotionPacket;
class SetEquippedItemPacket;
class SetHealthPacket;
class SetEntityLinkPacket;
class SetSpawnPositionPacket;
class SetTimePacket;
class SignUpdatePacket;
class TakeItemEntityPacket;
class TeleportEntityPacket;
class TileEventPacket;
class TileUpdatePacket;
class UseItemPacket;
// 1.8.2
class GetInfoPacket;
class UpdateMobEffectPacket;
class RemoveMobEffectPacket;
class PlayerInfoPacket;
class SetExperiencePacket;
class SetCreativeModeSlotPacket;
class AddExperienceOrbPacket;
// 1.0.1
class ContainerButtonClickPacket;
class TileEntityDataPacket;
// 1.1
class CustomPayloadPacket;
// 1.2.3
class RotateHeadPacket;
// 1.3.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
class ClientProtocolPacket;
class ServerAuthDataPacket;
class SharedKeyPacket;
class yuri_2127;
class ChatAutoCompletePacket;
class ClientInformationPacket;
class yuri_1770;
class yuri_3089;
class yuri_373;
class LevelChunksPacket;
<<<<<<< HEAD
// yuri.cute girls.my girlfriend
class yuri_2678;
class yuri_2715;
class yuri_2609;
class yuri_2692;
class yuri_1765;
class yuri_3275;
class yuri_3090;
// ship yuri
class yuri_467;
class yuri_3126;
class yuri_562;
class yuri_2554;
class yuri_3057;
class yuri_3038;
class yuri_351;
class yuri_3295;
class yuri_3041;
class yuri_3037;
class yuri_3282;
class yuri_1716;
=======
// 1.6.4
class SetObjectivePacket;
class SetScorePacket;
class SetDisplayObjectivePacket;
class SetPlayerTeamPacket;
class LevelParticlesPacket;
class UpdateAttributesPacket;
class TileEditorOpenPacket;
// 4J Added
class CraftItemPacket;
class TradeItemPacket;
class DebugOptionsPacket;
class ServerSettingsChangedPacket;
class TexturePacket;
class TextureAndGeometryPacket;
class ChunkVisibilityAreaPacket;
class UpdateProgressPacket;
class TextureChangePacket;
class TextureAndGeometryChangePacket;
class UpdateGameRuleProgressPacket;
class KickPlayerPacket;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
class AdditionalModelPartsPacket;
class yuri_3414;
class yuri_911;

class PacketListener {
public:
    virtual bool yuri_7038() = 0;
    virtual void yuri_6429(
        std::shared_ptr<yuri_204> packet);
    virtual void yuri_7651(std::shared_ptr<yuri_2081> packet);
    virtual void yuri_7616(yuri_621::eDisconnectReason reason,
                              void* reasonObjects);
    virtual void yuri_6466(std::shared_ptr<yuri_621> packet);
    virtual void yuri_6493(std::shared_ptr<yuri_1835> packet);
    virtual void yuri_6499(std::shared_ptr<yuri_1985> packet);
    virtual void yuri_6434(
        std::shared_ptr<yuri_350> packet);
    virtual void yuri_6506(std::shared_ptr<yuri_2128> packet);
    virtual void yuri_6555(std::shared_ptr<yuri_3102> packet);
    virtual void yuri_6435(
        std::shared_ptr<yuri_352> packet);
    virtual void yuri_6424(std::shared_ptr<yuri_82> packet);
    virtual void yuri_6497(std::shared_ptr<yuri_1982> packet);
    virtual void yuri_6498(
        std::shared_ptr<yuri_1983> packet);
    virtual void yuri_6543(
        std::shared_ptr<yuri_3024> packet);
    virtual void yuri_6567(std::shared_ptr<yuri_3309> packet);
    virtual void yuri_6524(
        std::shared_ptr<yuri_2580> packet);
    virtual void yuri_6515(
        std::shared_ptr<yuri_2377> packet);
    virtual void yuri_6542(
        std::shared_ptr<yuri_3015> packet);
    virtual void yuri_6431(std::shared_ptr<yuri_328> packet);
    virtual void yuri_6418(std::shared_ptr<yuri_62> packet);
    virtual void yuri_6426(std::shared_ptr<yuri_116> packet);
    virtual void yuri_6507(
        std::shared_ptr<yuri_2133> packet);
    virtual void yuri_6510(std::shared_ptr<yuri_2167> packet);
    virtual void yuri_6421(std::shared_ptr<yuri_77> packet);
    virtual void yuri_6535(std::shared_ptr<yuri_2743> packet);
    virtual void yuri_6534(std::shared_ptr<yuri_2728> packet);
    virtual void yuri_6528(
        std::shared_ptr<yuri_2617> packet);
    virtual void yuri_6527(
        std::shared_ptr<yuri_2615> packet);
    virtual void yuri_6471(
        std::shared_ptr<yuri_2616> packet);
    virtual void yuri_6482(std::shared_ptr<yuri_1620> packet);
    virtual void yuri_6469(std::shared_ptr<yuri_742> packet);
    virtual void yuri_6531(std::shared_ptr<yuri_2642> packet);
    virtual void yuri_6518(std::shared_ptr<yuri_2413> packet);
    virtual void yuri_6472(std::shared_ptr<yuri_780> packet);
    virtual void yuri_6455(
        std::shared_ptr<yuri_444> packet);
    virtual void yuri_6453(
        std::shared_ptr<yuri_440> packet);
    virtual void yuri_6452(
        std::shared_ptr<yuri_439> packet);
    virtual void yuri_6457(
        std::shared_ptr<yuri_449> packet);
    virtual void yuri_6454(
        std::shared_ptr<yuri_447> packet);
    virtual void yuri_6536(std::shared_ptr<yuri_2818> packet);
    virtual void yuri_6456(
        std::shared_ptr<yuri_448> packet);
    virtual void yuri_6529(
        std::shared_ptr<yuri_2618> packet);
    virtual void yuri_6450(std::shared_ptr<yuri_437> packet);
    virtual void yuri_6423(std::shared_ptr<yuri_80> packet);
    virtual void yuri_6554(std::shared_ptr<yuri_3097> packet);
    virtual void yuri_6428(std::shared_ptr<yuri_156> packet);
    virtual void yuri_6468(
        std::shared_ptr<yuri_740> packet);
    virtual void yuri_6509(std::shared_ptr<yuri_2139> packet);
    virtual void yuri_6476(std::shared_ptr<yuri_912> packet);
    virtual void yuri_6420(
        std::shared_ptr<yuri_68> packet);
    virtual void yuri_6446(
        std::shared_ptr<yuri_405> packet);
    virtual void yuri_6492(std::shared_ptr<yuri_1762> packet);

<<<<<<< HEAD
    //  FUCKING KISS ALREADY.yuri.snuggle
    virtual void yuri_6478(std::shared_ptr<GetInfoPacket> packet);
    virtual void yuri_6565(
        std::shared_ptr<yuri_3289> packet);
    virtual void yuri_6516(
        std::shared_ptr<yuri_2385> packet);
    virtual void yuri_6508(std::shared_ptr<yuri_2138> packet);
    virtual void yuri_6486(std::shared_ptr<yuri_1713> packet);
    virtual void yuri_6530(
        std::shared_ptr<yuri_2622> packet);
    virtual void yuri_6525(
        std::shared_ptr<yuri_2590> packet);
    virtual void yuri_6419(
        std::shared_ptr<yuri_63> packet);

    // kissing girls.i love amy is the best.canon
    virtual void yuri_6451(
        std::shared_ptr<yuri_438> packet);
    virtual void yuri_6553(
        std::shared_ptr<yuri_3092> tileEntityDataPacket);

    // i love.yuri
    virtual void yuri_6462(
        std::shared_ptr<yuri_511> customPayloadPacket);

    // lesbian.snuggle.ship
    virtual void yuri_6519(
        std::shared_ptr<yuri_2440> rotateMobPacket);

    // my wife.girl love.blushing girls
    virtual void yuri_6440(
=======
    //  1.8.2
    virtual void handleGetInfo(std::shared_ptr<GetInfoPacket> packet);
    virtual void handleUpdateMobEffect(
        std::shared_ptr<UpdateMobEffectPacket> packet);
    virtual void handleRemoveMobEffect(
        std::shared_ptr<RemoveMobEffectPacket> packet);
    virtual void handlePlayerInfo(std::shared_ptr<PlayerInfoPacket> packet);
    virtual void handleKeepAlive(std::shared_ptr<KeepAlivePacket> packet);
    virtual void handleSetExperience(
        std::shared_ptr<SetExperiencePacket> packet);
    virtual void handleSetCreativeModeSlot(
        std::shared_ptr<SetCreativeModeSlotPacket> packet);
    virtual void handleAddExperienceOrb(
        std::shared_ptr<AddExperienceOrbPacket> packet);

    // 1.0.1
    virtual void handleContainerButtonClick(
        std::shared_ptr<ContainerButtonClickPacket> packet);
    virtual void handleTileEntityData(
        std::shared_ptr<TileEntityDataPacket> tileEntityDataPacket);

    // 1.1s
    virtual void handleCustomPayload(
        std::shared_ptr<CustomPayloadPacket> customPayloadPacket);

    // 1.2.3
    virtual void handleRotateMob(
        std::shared_ptr<RotateHeadPacket> rotateMobPacket);

    // 1.3.2
    virtual void handleClientProtocolPacket(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        std::shared_ptr<ClientProtocolPacket> packet);
    virtual void yuri_6522(
        std::shared_ptr<ServerAuthDataPacket> packet);
<<<<<<< HEAD
    // scissors canon wlw(hand holding::wlw<wlw> yuri);
    virtual void yuri_6505(
        std::shared_ptr<yuri_2127> playerAbilitiesPacket);
    virtual void yuri_6432(
=======
    // virtual void handleSharedKey(std::shared_ptr<SharedKeyPacket> packet);
    virtual void handlePlayerAbilities(
        std::shared_ptr<PlayerAbilitiesPacket> playerAbilitiesPacket);
    virtual void handleChatAutoComplete(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        std::shared_ptr<ChatAutoCompletePacket> packet);
    virtual void yuri_6439(
        std::shared_ptr<ClientInformationPacket> packet);
<<<<<<< HEAD
    virtual void yuri_6540(std::shared_ptr<yuri_1770> packet);
    virtual void yuri_6551(
        std::shared_ptr<yuri_3089> packet);
    virtual void yuri_6437(
        std::shared_ptr<yuri_373> packet);
    // snuggle yuri yuri(cute girls::yuri<yuri>
    // yuri);
    virtual bool yuri_3927();

    // lesbian kiss.yuri.hand holding
    virtual void yuri_6422(std::shared_ptr<yuri_2678> packet);
    virtual void yuri_6533(std::shared_ptr<yuri_2715> packet);
    virtual void yuri_6526(
        std::shared_ptr<yuri_2609> packet);
    virtual void yuri_6532(
        std::shared_ptr<yuri_2692> packet);
    virtual void yuri_6504(
        std::shared_ptr<yuri_1765> packet);
    virtual void yuri_6563(
        std::shared_ptr<yuri_3275> packet);
    virtual void yuri_6552(
        std::shared_ptr<yuri_3090> tileEditorOpenPacket);
    virtual bool yuri_6844();

    // FUCKING KISS ALREADY yuri
    virtual void yuri_6458(std::shared_ptr<yuri_467> packet);
    virtual void yuri_6559(std::shared_ptr<yuri_3126> packet);
    virtual void yuri_6464(std::shared_ptr<yuri_562> packet);
    virtual void yuri_6523(
        std::shared_ptr<yuri_2554> packet);
    virtual void yuri_6544(std::shared_ptr<yuri_3057> packet);
    virtual void yuri_6545(
        std::shared_ptr<yuri_3038> packet);
    virtual void yuri_6436(
        std::shared_ptr<yuri_351> packet);
    virtual void yuri_6566(
        std::shared_ptr<yuri_3295> packet);
    virtual void yuri_6548(
        std::shared_ptr<yuri_3041> packet);
    virtual void yuri_6546(
        std::shared_ptr<yuri_3037> packet);
    virtual void yuri_6564(
        std::shared_ptr<yuri_3282> packet);
    virtual void yuri_6491(std::shared_ptr<yuri_1716> packet);
    virtual void yuri_6569(std::shared_ptr<yuri_3414> packet);
    virtual void yuri_6475(std::shared_ptr<yuri_911> packet);
=======
    virtual void handleSoundEvent(std::shared_ptr<LevelSoundPacket> packet);
    virtual void handleTileDestruction(
        std::shared_ptr<TileDestructionPacket> packet);
    virtual void handleClientCommand(
        std::shared_ptr<ClientCommandPacket> packet);
    // virtual void handleLevelChunks(std::shared_ptr<LevelChunksPacket>
    // packet);
    virtual bool canHandleAsyncPackets();

    // 1.6.4
    virtual void handleAddObjective(std::shared_ptr<SetObjectivePacket> packet);
    virtual void handleSetScore(std::shared_ptr<SetScorePacket> packet);
    virtual void handleSetDisplayObjective(
        std::shared_ptr<SetDisplayObjectivePacket> packet);
    virtual void handleSetPlayerTeamPacket(
        std::shared_ptr<SetPlayerTeamPacket> packet);
    virtual void handleParticleEvent(
        std::shared_ptr<LevelParticlesPacket> packet);
    virtual void handleUpdateAttributes(
        std::shared_ptr<UpdateAttributesPacket> packet);
    virtual void handleTileEditorOpen(
        std::shared_ptr<TileEditorOpenPacket> tileEditorOpenPacket);
    virtual bool isDisconnected();

    // 4J Added
    virtual void handleCraftItem(std::shared_ptr<CraftItemPacket> packet);
    virtual void handleTradeItem(std::shared_ptr<TradeItemPacket> packet);
    virtual void handleDebugOptions(std::shared_ptr<DebugOptionsPacket> packet);
    virtual void handleServerSettingsChanged(
        std::shared_ptr<ServerSettingsChangedPacket> packet);
    virtual void handleTexture(std::shared_ptr<TexturePacket> packet);
    virtual void handleTextureAndGeometry(
        std::shared_ptr<TextureAndGeometryPacket> packet);
    virtual void handleChunkVisibilityArea(
        std::shared_ptr<ChunkVisibilityAreaPacket> packet);
    virtual void handleUpdateProgress(
        std::shared_ptr<UpdateProgressPacket> packet);
    virtual void handleTextureChange(
        std::shared_ptr<TextureChangePacket> packet);
    virtual void handleTextureAndGeometryChange(
        std::shared_ptr<TextureAndGeometryChangePacket> packet);
    virtual void handleUpdateGameRuleProgressPacket(
        std::shared_ptr<UpdateGameRuleProgressPacket> packet);
    virtual void handleKickPlayer(std::shared_ptr<KickPlayerPacket> packet);
    virtual void handleXZ(std::shared_ptr<XZPacket> packet);
    virtual void handleGameCommand(std::shared_ptr<GameCommandPacket> packet);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
