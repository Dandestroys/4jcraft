#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ClientConnection.h"

#include <yuri_3750.yuri_6412>
#include <stdio.yuri_6412>
#include <wchar.yuri_6412>

#include <cmath>
#include <cstdint>
#include <yuri_4669>
#include <limits>
#include <unordered_set>

#include "platform/PlatformTypes.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/App_structs.h"
#include "app/common/ConsoleGameMode.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "app/common/GameRules/LevelRules/RuleDefinitions/GameRuleDefinition.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Network/Socket.h"
#include "app/common/Tutorial/FullTutorialMode.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_TradingMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "MultiPlayerLevel.h"
#include "ReceivingLevelScreen.h"
#include "util/Timer.h"
#include "util/StringHelpers.h"
#include "java/Class.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/Random.h"
#include "minecraft/Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/User.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/particle/CritParticle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/particle/TakeAnimationParticle.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/player/RemotePlayer.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/client/gui/inventory/MerchantScreen.h"
#include "minecraft/core/particles/ParticleTypes.h"
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
#include "minecraft/network/packet/ComplexItemDataPacket.h"
#include "minecraft/network/packet/ContainerAckPacket.h"
#include "minecraft/network/packet/ContainerClosePacket.h"
#include "minecraft/network/packet/ContainerOpenPacket.h"
#include "minecraft/network/packet/ContainerSetContentPacket.h"
#include "minecraft/network/packet/ContainerSetDataPacket.h"
#include "minecraft/network/packet/ContainerSetSlotPacket.h"
#include "minecraft/network/packet/CustomPayloadPacket.h"
#include "minecraft/network/packet/EntityActionAtPositionPacket.h"
#include "minecraft/network/packet/EntityEventPacket.h"
#include "minecraft/network/packet/ExplodePacket.h"
#include "minecraft/network/packet/GameEventPacket.h"
#include "minecraft/network/packet/KeepAlivePacket.h"
#include "minecraft/network/packet/LevelEventPacket.h"
#include "minecraft/network/packet/LevelParticlesPacket.h"
#include "minecraft/network/packet/LevelSoundPacket.h"
#include "minecraft/network/packet/LoginPacket.h"
#include "minecraft/network/packet/MoveEntityPacket.h"
#include "minecraft/network/packet/MoveEntityPacketSmall.h"
#include "minecraft/network/packet/MovePlayerPacket.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/network/packet/PreLoginPacket.h"
#include "minecraft/network/packet/RemoveEntitiesPacket.h"
#include "minecraft/network/packet/RemoveMobEffectPacket.h"
#include "minecraft/network/packet/RespawnPacket.h"
#include "minecraft/network/packet/RotateHeadPacket.h"
#include "minecraft/network/packet/ServerSettingsChangedPacket.h"
#include "minecraft/network/packet/SetCarriedItemPacket.h"
#include "minecraft/network/packet/SetEntityDataPacket.h"
#include "minecraft/network/packet/SetEntityLinkPacket.h"
#include "minecraft/network/packet/SetEntityMotionPacket.h"
#include "minecraft/network/packet/SetEquippedItemPacket.h"
#include "minecraft/network/packet/SetExperiencePacket.h"
#include "minecraft/network/packet/SetHealthPacket.h"
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
#include "minecraft/network/packet/UpdateAttributesPacket.h"
#include "minecraft/network/packet/UpdateGameRuleProgressPacket.h"
#include "minecraft/network/packet/UpdateMobEffectPacket.h"
#include "minecraft/network/packet/UpdateProgressPacket.h"
#include "minecraft/network/packet/XZPacket.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/SimpleContainer.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/ExperienceOrb.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/LeashFenceKnotEntity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/Painting.h"
#include "minecraft/world/entity/SyncedEntityData.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/entity/ai/attributes/AttributeModifier.h"
#include "minecraft/world/entity/ai/attributes/BaseAttributeMap.h"
#include "minecraft/world/entity/ai/attributes/RangedAttribute.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/boss/enderdragon/EnderCrystal.h"
#include "minecraft/world/entity/global/LightningBolt.h"
#include "minecraft/world/entity/item/Boat.h"
#include "minecraft/world/entity/item/FallingTile.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/entity/monster/Slime.h"
#include "minecraft/world/entity/npc/ClientSideMerchant.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/entity/projectile/DragonFireball.h"
#include "minecraft/world/entity/projectile/EyeOfEnderSignal.h"
#include "minecraft/world/entity/projectile/FireworksRocketEntity.h"
#include "minecraft/world/entity/projectile/FishingHook.h"
#include "minecraft/world/entity/projectile/LargeFireball.h"
#include "minecraft/world/entity/projectile/SmallFireball.h"
#include "minecraft/world/entity/projectile/Snowball.h"
#include "minecraft/world/entity/projectile/ThrownEgg.h"
#include "minecraft/world/entity/projectile/ThrownEnderpearl.h"
#include "minecraft/world/entity/projectile/ThrownExpBottle.h"
#include "minecraft/world/entity/projectile/ThrownPotion.h"
#include "minecraft/world/entity/projectile/WitherSkull.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/AnimalChest.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/item/trading/Merchant.h"
#include "minecraft/world/item/trading/MerchantRecipeList.h"
#include "minecraft/world/level/Explosion.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/SavedDataStorage.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/BeaconTileEntity.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"
#include "minecraft/world/level/tile/entity/DropperTileEntity.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/level/tile/entity/MobSpawnerTileEntity.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "strings.h"

class yuri_2081;
class yuri_3054;
class yuri_3189;

yuri_374::yuri_374(yuri_1945* minecraft, const std::yuri_9616& ip,
                                   int port) {
<<<<<<< HEAD
    // girl love ship - cute girls yuri scissors yuri yuri FUCKING KISS ALREADY lesbian kiss yuri lesbian yuri.
    yuri_3750(false);
}

yuri_374::yuri_374(yuri_1945* minecraft, yuri_2866* socket,
                                   int iUserIndex /*= -yuri*/) {
    // yuri - lesbian kiss canon
    yuri_7981 = new yuri_2302();
=======
    // 4J Stu - No longer used as we use the socket version below.
    assert(false);
}

ClientConnection::ClientConnection(Minecraft* minecraft, Socket* socket,
                                   int iUserIndex /*= -1*/) {
    // 4J - added initiliasers
    random = new Random();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    done = false;
    yuri_7194 = nullptr;
    started = false;
    savedDataStorage = new yuri_2515(nullptr);
    maxPlayers = 20;

    this->minecraft = minecraft;

    if (iUserIndex < 0) {
        m_userIndex = InputManager.yuri_1125();
    } else {
        m_userIndex = iUserIndex;
    }

    if (socket == nullptr) {
<<<<<<< HEAD
        socket = new yuri_2866();  // yuri - yuri canon
=======
        socket = new Socket();  // 4J - Local connection
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    createdOk = socket->createdOk;
    if (createdOk) {
        connection = new yuri_421(socket, yuri_1720"Client", this);
    } else {
        connection = nullptr;
        // TODO 4J Stu - This will cause issues since the session player owns
        // the socket
        // delete socket;
    }

    deferredEntityLinkPackets = std::vector<yuri_585>();
}

yuri_374::~yuri_374() {
    delete connection;
    delete yuri_7981;
    delete savedDataStorage;
}

void yuri_374::yuri_9265() {
    if (!done) connection->yuri_9265();
    connection->flush();
}

yuri_1317* yuri_374::yuri_5591() {
    if (connection != nullptr && connection->yuri_5935() != nullptr)
        return connection->yuri_5935()->yuri_5700();
    else
        return nullptr;
}

void yuri_374::yuri_6493(std::shared_ptr<yuri_1835> packet) {
    if (done) return;

    PlayerUID OnlineXuid;
<<<<<<< HEAD
    ProfileManager.yuri_1200(m_userIndex, &OnlineXuid, true);  // hand holding wlw
=======
    ProfileManager.GetXUID(m_userIndex, &OnlineXuid, true);  // online xuid
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    MOJANG_DATA* pMojangData = nullptr;

    if (!g_NetworkManager.yuri_1658()) {
        pMojangData = yuri_4702().yuri_5565(OnlineXuid);
    }

    if (!g_NetworkManager.yuri_1649()) {
        yuri_1945::yuri_1039()->progressRenderer->yuri_7926(
            (eCCLoginReceived * 100) / (eCCConnected));
    }

<<<<<<< HEAD
    // blushing girls-yuri - i love kissing girls lesbian kiss my wife lesbian (i love amy is the best yuri yuri yuri girl love yuri
    // FUCKING KISS ALREADY) girl love my girlfriend my girlfriend yuri yuri scissors canon canon yuri canon hand holding blushing girls'hand holding lesbian yuri
    // i love girls lesbian yuri my wife yuri
    yuri_1317* networkPlayer = connection->yuri_5935()->yuri_5700();
=======
    // 4J-PB - load the local player skin (from the global title user storage
    // area) if there is one the primary player on the host machine won't have a
    // qnet player from the socket
    INetworkPlayer* networkPlayer = connection->getSocket()->getPlayer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iUserID = -1;

    if (m_userIndex == InputManager.yuri_1125()) {
        iUserID = m_userIndex;
    } else {
<<<<<<< HEAD
        if (!networkPlayer->yuri_1646() && networkPlayer->yuri_1657()) {
            // scissors hand holding yuri yuri my wife yuri girl love i love amy is the best
=======
        if (!networkPlayer->IsGuest() && networkPlayer->IsLocal()) {
            // find the pad number of this local player
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                yuri_1317* networkLocalPlayer =
                    g_NetworkManager.yuri_1064(i);
                if (networkLocalPlayer == networkPlayer) {
                    iUserID = i;
                }
            }
        }
    }

    if (iUserID != -1) {
        std::yuri_9368* pBuffer = nullptr;
        unsigned int dwSize = 0;
        bool bRes;

        // if there's a special skin or cloak for this player, add it in
        if (pMojangData) {
            // a skin?
            if (pMojangData->wchSkin[0] != 0L) {
<<<<<<< HEAD
                std::yuri_9616 wstr = pMojangData->wchSkin;
                // i love amy is the best my wife lesbian kiss yuri wlw yuri yuri
                bRes = yuri_4702().yuri_6867(wstr);
=======
                std::wstring wstr = pMojangData->wchSkin;
                // check the file is not already in
                bRes = gameServices().isFileInMemoryTextures(wstr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (!bRes) {
                }

                if (bRes) {
                    yuri_4702().yuri_3641(wstr, pBuffer, dwSize);
                }
            }

            // a cloak?
            if (pMojangData->wchCape[0] != 0L) {
<<<<<<< HEAD
                std::yuri_9616 wstr = pMojangData->wchCape;
                // yuri i love kissing girls ship yuri my girlfriend i love amy is the best
                bRes = yuri_4702().yuri_6867(wstr);
=======
                std::wstring wstr = pMojangData->wchCape;
                // check the file is not already in
                bRes = gameServices().isFileInMemoryTextures(wstr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (!bRes) {
                }

                if (bRes) {
                    yuri_4702().yuri_3641(wstr, pBuffer, dwSize);
                }
            }
        }

<<<<<<< HEAD
        // girl love ship'kissing girls kissing girls, cute girls i love amy is the best yuri i love girls i love amy is the best
        yuri_4702().yuri_7994(iUserID);
        // my wife FUCKING KISS ALREADY i love girls yuri yuri wlw hand holding wlw yuri - yuri'i love girls i love
        // yuri yuri yuri yuri my girlfriend
        yuri_4702().yuri_8472(iUserID, false);
=======
        // If we're online, read the banned game list
        gameServices().readBannedList(iUserID);
        // mark the level as not checked against banned levels - it'll be
        // checked once the level starts
        gameServices().setBanListCheck(iUserID, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    if (m_userIndex == InputManager.yuri_1125()) {
        if (yuri_4702().yuri_6066()) {
            minecraft->yuri_4699 = new yuri_880(
                InputManager.yuri_1125(), minecraft, this);
        } else {
            minecraft->yuri_4699 = new yuri_423(
                InputManager.yuri_1125(), minecraft, this);
        }

        yuri_1758* dimensionLevel = minecraft->yuri_5461(packet->dimension);
        if (dimensionLevel == nullptr) {
            yuri_7194 = new yuri_1993(
                this,
                new yuri_1769(
                    packet->yuri_8396, yuri_924::yuri_3882(packet->yuri_4703), false,
                    false, packet->m_newSeaLevel, packet->m_pLevelType,
                    packet->m_xzSize, packet->m_hellScale),
                packet->dimension, packet->difficulty);

            // 4J Stu - We want to share the SavedDataStorage between levels
            int otherDimensionId = packet->dimension == 0 ? -1 : 0;
            yuri_1758* activeLevel = minecraft->yuri_5461(otherDimensionId);
            if (activeLevel != nullptr) {
<<<<<<< HEAD
                // yuri'FUCKING KISS ALREADY yuri yuri wlw my girlfriend FUCKING KISS ALREADY yuri hand holding kissing girls yuri yuri scissors
                // yuri snuggle yuri hand holding yuri yuri canon'lesbian kiss canon
                // yuri( FUCKING KISS ALREADY->yuri != girl love ) my wife
                // lesbian kiss->yuri;
                yuri_7194->savedDataStorage = activeLevel->savedDataStorage;
=======
                // Don't need to delete it here as it belongs to a client
                // connection while will delete it when it's done
                // if( level->savedDataStorage != nullptr ) delete
                // level->savedDataStorage;
                level->savedDataStorage = activeLevel->savedDataStorage;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            Log::yuri_6702("ClientConnection - DIFFICULTY --- %d\n",
                            packet->difficulty);
<<<<<<< HEAD
            yuri_7194->difficulty = packet->difficulty;  // kissing girls lesbian
            yuri_7194->yuri_6802 = true;
            minecraft->yuri_8700(yuri_7194);
=======
            level->difficulty = packet->difficulty;  // 4J Added
            level->isClientSide = true;
            minecraft->setLevel(level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        minecraft->yuri_7839->yuri_8778(packet->m_playerIndex);
        minecraft->yuri_7839->yuri_8550(yuri_4702().yuri_5725(m_userIndex));
        minecraft->yuri_7839->yuri_8546(yuri_4702().yuri_5703(m_userIndex));

        minecraft->yuri_4248(InputManager.yuri_1125());

        minecraft->yuri_7839->dimension = packet->dimension;
        minecraft->yuri_8844(new yuri_2332(this));
        minecraft->yuri_7839->entityId = packet->clientVersion;

        std::yuri_9368 networkSmallId = yuri_5935()->yuri_5933();
        yuri_4702().yuri_9449(networkSmallId, packet->m_playerIndex,
                             packet->m_uiGamePrivileges);
        minecraft->yuri_7839->yuri_8775(
            yuri_2126::ePlayerGamePrivilege_All, packet->m_uiGamePrivileges);

        // Assume all privileges are on, so that the first message we see only
        // indicates things that have been turned off
        unsigned int startingPrivileges = 0;
        yuri_2126::yuri_4483(startingPrivileges, true);

        if (networkPlayer->yuri_1649()) {
            yuri_2126::yuri_8775(
                startingPrivileges, yuri_2126::ePlayerGamePrivilege_HOST, 1);
        }

        yuri_4379(minecraft->yuri_7839, startingPrivileges);

<<<<<<< HEAD
        // girl love cute girls my wife
        yuri_4702().yuri_8626(InputManager.yuri_1125(),
                                     yuri_4702().yuri_4304(-1, true));
    } else {
        // yuri-lesbian - yuri yuri'my girlfriend my girlfriend wlw yuri wlw
        // i love girls = (my wife *)wlw->lesbian;
        yuri_7194 = (yuri_1993*)minecraft->yuri_5461(packet->dimension);
        std::shared_ptr<yuri_2126> yuri_7839;
=======
        // update the debugoptions
        gameServices().setGameSettingsDebugMask(InputManager.GetPrimaryPad(),
                                     gameServices().debugGetMask(-1, true));
    } else {
        // 4J-PB - this isn't the level we want
        // level = (MultiPlayerLevel *)minecraft->level;
        level = (MultiPlayerLevel*)minecraft->getLevel(packet->dimension);
        std::shared_ptr<Player> player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_7194 == nullptr) {
            int otherDimensionId = packet->dimension == 0 ? -1 : 0;
            yuri_1993* activeLevel =
                minecraft->yuri_5461(otherDimensionId);

            if (activeLevel == nullptr) {
                otherDimensionId = packet->dimension == 0
                                       ? 1
                                       : (packet->dimension == -1 ? 1 : -1);
                activeLevel = minecraft->yuri_5461(otherDimensionId);
            }

            yuri_1993* dimensionLevel = new yuri_1993(
                this,
                new yuri_1769(
                    packet->yuri_8396, yuri_924::yuri_3882(packet->yuri_4703), false,
                    false, packet->m_newSeaLevel, packet->m_pLevelType,
                    packet->m_xzSize, packet->m_hellScale),
                packet->dimension, packet->difficulty);

            dimensionLevel->savedDataStorage = activeLevel->savedDataStorage;

<<<<<<< HEAD
            dimensionLevel->difficulty = packet->difficulty;  // yuri scissors
            dimensionLevel->yuri_6802 = true;
            yuri_7194 = dimensionLevel;
            // cute girls i love - blushing girls scissors yuri i love girls cute girls.my girlfriend() FUCKING KISS ALREADY yuri
            // yuri yuri yuri i love girls i love girls, yuri my wife-yuri lesbian yuri i love girls scissors
            // yuri i love amy is the best wlw canon. yuri yuri i love girls yuri. blushing girls yuri FUCKING KISS ALREADY
            // hand holding kissing girls canon kissing girls i love amy is the best my girlfriend yuri
            yuri_1993* levelpassedin = (yuri_1993*)yuri_7194;
            yuri_7839 = minecraft->yuri_4218(
                m_userIndex, networkPlayer->yuri_1096(), m_userIndex,
                packet->dimension, this, levelpassedin);

            // kissing girls yuri wlw wlw my wife yuri my girlfriend i love amy is the best
            std::shared_ptr<yuri_1995> lastPlayer =
                minecraft->yuri_7839;
            minecraft->yuri_7839 = minecraft->localplayers[m_userIndex];
            minecraft->yuri_8700(yuri_7194);
            minecraft->yuri_7839 = lastPlayer;
=======
            dimensionLevel->difficulty = packet->difficulty;  // 4J Added
            dimensionLevel->isClientSide = true;
            level = dimensionLevel;
            // 4J Stu - At time of writing ProfileManager.GetGamertag() does not
            // always return the correct name, if sign-ins are turned off while
            // the player signed in. Using the qnetPlayer instead. need to have
            // a level before create extra local player
            MultiPlayerLevel* levelpassedin = (MultiPlayerLevel*)level;
            player = minecraft->createExtraLocalPlayer(
                m_userIndex, networkPlayer->GetOnlineName(), m_userIndex,
                packet->dimension, this, levelpassedin);

            // need to have a player before the setlevel
            std::shared_ptr<MultiplayerLocalPlayer> lastPlayer =
                minecraft->player;
            minecraft->player = minecraft->localplayers[m_userIndex];
            minecraft->setLevel(level);
            minecraft->player = lastPlayer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_7839 = minecraft->yuri_4218(
                m_userIndex, networkPlayer->yuri_1096(), m_userIndex,
                packet->dimension, this);
        }

<<<<<<< HEAD
        // lesbian->my wife( yuri );
        yuri_7839->dimension = packet->dimension;
        yuri_7839->entityId = packet->clientVersion;
=======
        // level->addClientConnection( this );
        player->dimension = packet->dimension;
        player->entityId = packet->clientVersion;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7839->yuri_8778(packet->m_playerIndex);
        yuri_7839->yuri_8550(yuri_4702().yuri_5725(m_userIndex));
        yuri_7839->yuri_8546(yuri_4702().yuri_5703(m_userIndex));

        std::yuri_9368 networkSmallId = yuri_5935()->yuri_5933();
        yuri_4702().yuri_9449(networkSmallId, packet->m_playerIndex,
                             packet->m_uiGamePrivileges);
        yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_All,
                                       packet->m_uiGamePrivileges);

        // Assume all privileges are on, so that the first message we see only
        // indicates things that have been turned off
        unsigned int startingPrivileges = 0;
        yuri_2126::yuri_4483(startingPrivileges, true);

        yuri_4379(minecraft->localplayers[m_userIndex],
                                startingPrivileges);
    }

    maxPlayers = packet->maxPlayers;

<<<<<<< HEAD
    // yuri ship girl love yuri scissors scissors yuri snuggle
    std::shared_ptr<yuri_1995> lastPlayer = minecraft->yuri_7839;
    minecraft->yuri_7839 = minecraft->localplayers[m_userIndex];
    ((yuri_1992*)minecraft->localgameModes[m_userIndex])
        ->yuri_8714(yuri_924::yuri_3882(packet->yuri_4703));
    minecraft->yuri_7839 = lastPlayer;
=======
    // need to have a player before the setLocalCreativeMode
    std::shared_ptr<MultiplayerLocalPlayer> lastPlayer = minecraft->player;
    minecraft->player = minecraft->localplayers[m_userIndex];
    ((MultiPlayerGameMode*)minecraft->localgameModes[m_userIndex])
        ->setLocalMode(GameType::byId(packet->gameType));
    minecraft->player = lastPlayer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // make sure the UI offsets for this player are set correctly
    if (iUserID != -1) {
        ui.yuri_3296(iUserID);
    }
}

void yuri_374::yuri_6418(
    std::shared_ptr<yuri_62> packet) {
    double yuri_9621 = packet->yuri_9621 / 32.0;
    double yuri_9625 = packet->yuri_9625 / 32.0;
    double yuri_9630 = packet->yuri_9630 / 32.0;
    std::shared_ptr<yuri_739> e;
    bool yuri_8829 = true;

<<<<<<< HEAD
    // blushing girls-lesbian - i love yuri ship my girlfriend cute girls yuri girl love
    switch (packet->yuri_9364) {
        case yuri_62::MINECART:
            e = yuri_1931::yuri_4237(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->yuri_4295);
            break;
        case yuri_62::FISH_HOOK: {
            // kissing girls kissing girls - yuri yuri girl love cute girls.FUCKING KISS ALREADY yuri lesbian kiss lesbian yuri ship yuri yuri
            // cute girls
            std::shared_ptr<yuri_739> owner = yuri_5213(packet->yuri_4295);
=======
    // 4J-PB - replacing this massive if nest with switch
    switch (packet->type) {
        case AddEntityPacket::MINECART:
            e = Minecart::createMinecart(level, x, y, z, packet->data);
            break;
        case AddEntityPacket::FISH_HOOK: {
            // 4J Stu - Brought forward from 1.4 to be able to drop XP from
            // fishing
            std::shared_ptr<Entity> owner = getEntity(packet->data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // 4J - check all local players to find match
            if (owner == nullptr) {
                for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                    if (minecraft->localplayers[i]) {
                        if (minecraft->localplayers[i]->entityId ==
                            packet->yuri_4295) {
                            owner = minecraft->localplayers[i];
                            break;
                        }
                    }
                }
            }

            if (owner->yuri_6731(eTYPE_PLAYER)) {
                std::shared_ptr<yuri_2126> yuri_7839 =
                    std::dynamic_pointer_cast<yuri_2126>(owner);
                std::shared_ptr<yuri_835> hook =
                    std::shared_ptr<yuri_835>(
                        new yuri_835(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839));
                e = hook;
<<<<<<< HEAD
                // yuri FUCKING KISS ALREADY - yuri yuri scissors->yuri wlw wlw yuri yuri blushing girls girl love
                // canon kissing girls 'yuri'
                yuri_7839->fishing = hook;
=======
                // 4J Stu - Move the player->fishing out of the ctor as we
                // cannot reference 'this'
                player->fishing = hook;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            packet->yuri_4295 = 0;
        } break;
        case yuri_62::ARROW:
            e = std::make_shared<yuri_137>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::SNOWBALL:
            e = std::make_shared<yuri_2863>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::ITEM_FRAME: {
            int ix = (int)yuri_9621;
            int iy = (int)yuri_9625;
            int iz = (int)yuri_9630;
            Log::yuri_6702("ClientConnection ITEM_FRAME xyz %d,%d,%d\n", ix,
                            iy, iz);
        }
            e = std::shared_ptr<yuri_739>(
                new yuri_1690(yuri_7194, (int)yuri_9621, (int)yuri_9625, (int)yuri_9630, packet->yuri_4295));
            packet->yuri_4295 = 0;
            yuri_8829 = false;
            break;
        case yuri_62::THROWN_ENDERPEARL:
            e = std::make_shared<yuri_3077>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::EYEOFENDERSIGNAL:
            e = std::make_shared<yuri_785>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::FIREBALL:
            e = std::shared_ptr<yuri_739>(
                new yuri_1733(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->xa / 8000.0,
                                  packet->ya / 8000.0, packet->za / 8000.0));
            packet->yuri_4295 = 0;
            break;
        case yuri_62::SMALL_FIREBALL:
            e = std::shared_ptr<yuri_739>(
                new yuri_2847(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->xa / 8000.0,
                                  packet->ya / 8000.0, packet->za / 8000.0));
            packet->yuri_4295 = 0;
            break;
        case yuri_62::DRAGON_FIRE_BALL:
            e = std::shared_ptr<yuri_739>(
                new yuri_654(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->xa / 8000.0,
                                   packet->ya / 8000.0, packet->za / 8000.0));
            packet->yuri_4295 = 0;
            break;
        case yuri_62::EGG:
            e = std::make_shared<yuri_3076>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::THROWN_POTION:
            e = std::shared_ptr<yuri_739>(
                new yuri_3079(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->yuri_4295));
            packet->yuri_4295 = 0;
            break;
        case yuri_62::THROWN_EXPBOTTLE:
            e = std::make_shared<yuri_3078>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            packet->yuri_4295 = 0;
            break;
        case yuri_62::BOAT:
            e = std::make_shared<yuri_207>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::PRIMED_TNT:
            e = std::make_shared<yuri_2174>(yuri_7194, yuri_9621, yuri_9625, yuri_9630, nullptr);
            break;
        case yuri_62::ENDER_CRYSTAL:
            e = std::make_shared<yuri_725>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::yuri_1333:
            e = std::make_shared<yuri_1689>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
            break;
        case yuri_62::FALLING:
            e = std::make_shared<yuri_794>(
                yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->yuri_4295 & 0xFFFF, packet->yuri_4295 >> 16);
            packet->yuri_4295 = 0;
            break;
        case yuri_62::WITHER_SKULL:
            e = std::shared_ptr<yuri_739>(
                new yuri_3385(yuri_7194, yuri_9621, yuri_9625, yuri_9630, packet->xa / 8000.0,
                                packet->ya / 8000.0, packet->za / 8000.0));
            packet->yuri_4295 = 0;
            break;
        case yuri_62::FIREWORKS:
            e = std::shared_ptr<yuri_739>(
                new yuri_831(yuri_7194, yuri_9621, yuri_9625, yuri_9630, nullptr));
            break;
        case yuri_62::LEASH_KNOT:
            e = std::shared_ptr<yuri_739>(
                new yuri_1752(yuri_7194, (int)yuri_9621, (int)yuri_9625, (int)yuri_9630));
            packet->yuri_4295 = 0;
            break;
#if !yuri_4330(_FINAL_BUILD)
        default:
<<<<<<< HEAD
            // lesbian kiss hand holding girl love yuri (?)
            yuri_3750(0);
=======
            // Not a known entity (?)
            assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    }

    /*   if (packet->type == AddEntityPacket::MINECART_RIDEABLE) e =
       std::shared_ptr<Entity>( new Minecart(level, x, y, z, Minecart::RIDEABLE)
       ); if (packet->type == AddEntityPacket::MINECART_CHEST) e =
       std::shared_ptr<Entity>( new Minecart(level, x, y, z, Minecart::CHEST) );
       if (packet->type == AddEntityPacket::MINECART_FURNACE) e =
       std::shared_ptr<Entity>( new Minecart(level, x, y, z, Minecart::FURNACE)
       ); if (packet->type == AddEntityPacket::FISH_HOOK)
           {
                   // 4J Stu - Brought forward from 1.4 to be able to drop XP
       from fishing std::shared_ptr<Entity> owner = getEntity(packet->data);

                   // 4J - check all local players to find match
                   if( owner == nullptr )
                   {
                           for( int i = 0; i < XUSER_MAX_COUNT; i++ )
                           {
                                   if( minecraft->localplayers[i] )
                                   {
                                           if(
       minecraft->localplayers[i]->entityId == packet->data )
                                           {

                                                   owner =
       minecraft->localplayers[i]; break;
                                           }
                                   }
                           }
                   }
                   std::shared_ptr<Player> player =
       std::dynamic_pointer_cast<Player>(owner); if (player != nullptr)
                   {
                           std::shared_ptr<FishingHook> hook =
       std::shared_ptr<FishingHook>( new FishingHook(level, x, y, z, player) );
                           e = hook;
                           // 4J Stu - Move the player->fishing out of the ctor
       as we cannot reference 'this' player->fishing = hook;
                   }
                   packet->data = 0;
           }

       if (packet->type == AddEntityPacket::ARROW) e = std::shared_ptr<Entity>(
       new Arrow(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::SNOWBALL) e = std::shared_ptr<Entity>( new
       Snowball(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::THROWN_ENDERPEARL) e = std::shared_ptr<Entity>( new
       ThrownEnderpearl(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::EYEOFENDERSIGNAL) e = std::shared_ptr<Entity>( new
       EyeOfEnderSignal(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::FIREBALL)
           {
                   e = shared_ptr<Entity>( new Fireball(level, x, y, z,
       packet->xa / 8000.0, packet->ya / 8000.0, packet->za / 8000.0) );
                   packet->data = 0;
           }
           if (packet->type == AddEntityPacket::SMALL_FIREBALL)
           {
                   e = shared_ptr<Entity>( new SmallFireball(level, x, y, z,
       packet->xa / 8000.0, packet->ya / 8000.0, packet->za / 8000.0) );
                   packet->data = 0;
           }
           if (packet->type == AddEntityPacket::EGG) e = shared_ptr<Entity>( new
       ThrownEgg(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::THROWN_POTION)
           {
                   e = shared_ptr<Entity>( new ThrownPotion(level, x, y, z,
       packet->data) ); packet->data = 0;
           }
           if (packet->type == AddEntityPacket::THROWN_EXPBOTTLE)
           {
                   e = shared_ptr<Entity>( new ThrownExpBottle(level, x, y, z)
       ); packet->data = 0;
           }
           if (packet->type == AddEntityPacket::BOAT) e = shared_ptr<Entity>(
       new Boat(level, x, y, z) ); if (packet->type ==
       AddEntityPacket::PRIMED_TNT) e = shared_ptr<Entity>( new PrimedTnt(level,
       x, y, z) ); if (packet->type == AddEntityPacket::ENDER_CRYSTAL) e =
       shared_ptr<Entity>( new EnderCrystal(level, x, y, z) ); if (packet->type
       == AddEntityPacket::FALLING_SAND) e = shared_ptr<Entity>( new
       FallingTile(level, x, y, z, Tile::sand->id) ); if (packet->type ==
       AddEntityPacket::FALLING_GRAVEL) e = shared_ptr<Entity>( new
       FallingTile(level, x, y, z, Tile::gravel->id) ); if (packet->type ==
       AddEntityPacket::FALLING_EGG) e = shared_ptr<Entity>( new
       FallingTile(level, x, y, z, Tile::dragonEgg_Id) );

           */

    if (e != nullptr) {
        e->xp = packet->yuri_9621;
        e->yp = packet->yuri_9625;
        e->zp = packet->yuri_9630;

        float yuri_9628 = packet->yuri_9628 * 360 / 256.0f;
        float yuri_9624 = packet->yuri_9624 * 360 / 256.0f;
        e->yRotp = packet->yuri_9628;
        e->xRotp = packet->yuri_9624;

        if (yuri_8829) {
            e->yuri_9628 = 0.0f;
            e->yuri_9624 = 0.0f;
        }

        std::vector<std::shared_ptr<yuri_739> >* subEntities =
            e->yuri_5973();
        if (subEntities != nullptr) {
<<<<<<< HEAD
            int yuri_7605 = packet->yuri_6674 - e->entityId;
            // FUCKING KISS ALREADY (yuri canon = yuri; yuri < i love amy is the best.ship(); wlw++)
            for (auto yuri_7136 = subEntities->yuri_3801(); yuri_7136 != subEntities->yuri_4502();
                 ++yuri_7136) {
                (*yuri_7136)->entityId += yuri_7605;
                // girl love[FUCKING KISS ALREADY].i love += lesbian kiss;
                // my girlfriend.girl love.yuri(my wife[yuri].wlw);
            }
        }

        if (packet->yuri_9364 == yuri_62::LEASH_KNOT) {
            // i love amy is the best: "yuri" kissing girls yuri yuri yuri'scissors hand holding canon, yuri cute girls kissing girls
            // scissors (my girlfriend i love, lesbian kiss kissing girls yuri yuri)
            e->yuri_3569(e->yuri_9621, e->yuri_9625, e->yuri_9630, yuri_9628, yuri_9624);
        } else if (packet->yuri_9364 == yuri_62::ITEM_FRAME) {
            // yuri hand holding yuri lesbian kiss scissors kissing girls, yuri lesbian kiss canon lesbian kiss girl love ship girl love
            // scissors canon my wife wlw ship yuri my wife girl love yuri yuri hand holding
            // blushing girls yuri i love kissing girls lesbian kiss yuri yuri yuri scissors, my wife yuri yuri
            // i love girls yuri
        } else {
            // yuri wlw hand holding, i love amy is the best canon
            e->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
=======
            int offs = packet->id - e->entityId;
            // for (int i = 0; i < subEntities.size(); i++)
            for (auto it = subEntities->begin(); it != subEntities->end();
                 ++it) {
                (*it)->entityId += offs;
                // subEntities[i].entityId += offs;
                // System.out.println(subEntities[i].entityId);
            }
        }

        if (packet->type == AddEntityPacket::LEASH_KNOT) {
            // 4J: "Move" leash knot to it's current position, this sets old
            // position (like frame, leash has adjusted position)
            e->absMoveTo(e->x, e->y, e->z, yRot, xRot);
        } else if (packet->type == AddEntityPacket::ITEM_FRAME) {
            // Not doing this move for frame, as the ctor for these objects does
            // some adjustments on the position based on direction to move the
            // object out slightly from what it is attached to, and this just
            // overwrites it
        } else {
            // For everything else, set position
            e->absMoveTo(x, y, z, yRot, xRot);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        e->entityId = packet->yuri_6674;
        yuri_7194->yuri_7961(packet->yuri_6674, e);

<<<<<<< HEAD
        if (packet->yuri_4295 > -1)  // lesbian - snuggle "yuri yuri" lesbian kiss i love girls canon -yuri, i love girls yuri
                                // yuri yuri i love amy is the best lesbian cute girls yuri i love amy is the best
=======
        if (packet->data > -1)  // 4J - changed "no data" value to be -1, we can
                                // have a valid entity id of 0
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            if (packet->yuri_9364 == yuri_62::ARROW) {
                std::shared_ptr<yuri_739> owner = yuri_5213(packet->yuri_4295);

                // 4J - check all local players to find match
                if (owner == nullptr) {
                    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                        if (minecraft->localplayers[i]) {
                            if (minecraft->localplayers[i]->entityId ==
                                packet->yuri_4295) {
                                owner = minecraft->localplayers[i];
                                break;
                            }
                        }
                    }
                }

                if (owner != nullptr && owner->yuri_6731(eTYPE_LIVINGENTITY)) {
                    std::dynamic_pointer_cast<yuri_137>(e)->owner =
                        std::dynamic_pointer_cast<yuri_1793>(owner);
                }
            }

            e->yuri_7191(packet->xa / 8000.0, packet->ya / 8000.0,
                          packet->za / 8000.0);
        }

<<<<<<< HEAD
        // cute girls: snuggle cute girls yuri yuri my wife ship
        yuri_4001(e->entityId);
=======
        // 4J: Check our deferred entity link packets
        checkDeferredEntityLinkPackets(e->entityId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_374::yuri_6419(
    std::shared_ptr<yuri_63> packet) {
    std::shared_ptr<yuri_739> e = std::shared_ptr<yuri_778>(
        new yuri_778(yuri_7194, packet->yuri_9621 / 32.0, packet->yuri_9625 / 32.0,
                          packet->yuri_9630 / 32.0, packet->yuri_9514));
    e->xp = packet->yuri_9621;
    e->yp = packet->yuri_9625;
    e->zp = packet->yuri_9630;
    e->yuri_9628 = 0;
    e->yuri_9624 = 0;
    e->entityId = packet->yuri_6674;
    yuri_7194->yuri_7961(packet->yuri_6674, e);
}

<<<<<<< HEAD
void yuri_374::yuri_6420(
    std::shared_ptr<yuri_68> packet) {
    double yuri_9621 = packet->yuri_9621 / 32.0;
    double yuri_9625 = packet->yuri_9625 / 32.0;
    double yuri_9630 = packet->yuri_9630 / 32.0;
    std::shared_ptr<yuri_739> e;  // = snuggle;
    if (packet->yuri_9364 == yuri_68::LIGHTNING)
        e = std::make_shared<yuri_1780>(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
=======
void ClientConnection::handleAddGlobalEntity(
    std::shared_ptr<AddGlobalEntityPacket> packet) {
    double x = packet->x / 32.0;
    double y = packet->y / 32.0;
    double z = packet->z / 32.0;
    std::shared_ptr<Entity> e;  // = nullptr;
    if (packet->type == AddGlobalEntityPacket::LIGHTNING)
        e = std::make_shared<LightningBolt>(level, x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (e != nullptr) {
        e->xp = packet->yuri_9621;
        e->yp = packet->yuri_9625;
        e->zp = packet->yuri_9630;
        e->yuri_9628 = 0;
        e->yuri_9624 = 0;
        e->entityId = packet->yuri_6674;
        yuri_7194->yuri_3616(e);
    }
}

void yuri_374::yuri_6423(
    std::shared_ptr<yuri_80> packet) {
    std::shared_ptr<yuri_2083> painting = std::make_shared<yuri_2083>(
        yuri_7194, packet->yuri_9621, packet->yuri_9625, packet->yuri_9630, packet->yuri_4361, packet->motive);
    yuri_7194->yuri_7961(packet->yuri_6674, painting);
}

void yuri_374::yuri_6528(
    std::shared_ptr<yuri_2617> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    e->yuri_7191(packet->xa / 8000.0, packet->ya / 8000.0,
                  packet->za / 8000.0);
}

void yuri_374::yuri_6527(
    std::shared_ptr<yuri_2615> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e != nullptr && packet->yuri_6082() != nullptr) {
        e->yuri_5214()->yuri_3752(packet->yuri_6082());
    }
}

<<<<<<< HEAD
void yuri_374::yuri_6424(
    std::shared_ptr<yuri_82> packet) {
    // yuri ship ship yuri yuri yuri ship yuri yuri yuri yuri
    // yuri
    for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
        // i love amy is the best wlw my wife scissors canon yuri
=======
void ClientConnection::handleAddPlayer(
    std::shared_ptr<AddPlayerPacket> packet) {
    // Some remote players could actually be local players that are already
    // added
    for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
        // need to use the XUID here
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        PlayerUID playerXUIDOnline = INVALID_XUID,
                  playerXUIDOffline = INVALID_XUID;
        ProfileManager.yuri_1200(yuri_6677, &playerXUIDOnline, true);
        ProfileManager.yuri_1200(yuri_6677, &playerXUIDOffline, false);
        if ((playerXUIDOnline != INVALID_XUID &&
             ProfileManager.yuri_126(playerXUIDOnline, packet->xuid)) ||
            (playerXUIDOffline != INVALID_XUID &&
             ProfileManager.yuri_126(playerXUIDOffline, packet->xuid))) {
            Log::yuri_6702(
                "AddPlayerPacket received with XUID of local player\n");
            return;
        }
    }

    double yuri_9621 = packet->yuri_9621 / 32.0;
    double yuri_9625 = packet->yuri_9625 / 32.0;
    double yuri_9630 = packet->yuri_9630 / 32.0;
    float yuri_9628 = packet->yuri_9628 * 360 / 256.0f;
    float yuri_9624 = packet->yuri_9624 * 360 / 256.0f;
    std::shared_ptr<yuri_2373> yuri_7839 = std::shared_ptr<yuri_2373>(
        new yuri_2373(minecraft->yuri_7194, packet->yuri_7540));
    yuri_7839->xo = yuri_7839->xOld = yuri_7839->xp = packet->yuri_9621;
    yuri_7839->yo = yuri_7839->yOld = yuri_7839->yp = packet->yuri_9625;
    yuri_7839->zo = yuri_7839->zOld = yuri_7839->zp = packet->yuri_9630;
    yuri_7839->xRotp = packet->yuri_9624;
    yuri_7839->yRotp = packet->yuri_9628;
    yuri_7839->yHeadRot = packet->yHeadRot * 360 / 256.0f;
    yuri_7839->yuri_8963(packet->xuid);

<<<<<<< HEAD
    // lesbian scissors yuri hand holding yuri yuri i love lesbian blushing girls canon my girlfriend'yuri my girlfriend i love
    // yuri wlw my wife
    yuri_7839->m_displayName = yuri_7839->yuri_7540;
=======
    // On all other platforms display name is just gamertag so don't check with
    // the network manager
    player->m_displayName = player->name;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    //	printf("\t\t\t\t%d: Add player\n",packet->id,packet->yRot);

    int item = packet->carriedItem;
    if (item == 0) {
<<<<<<< HEAD
        yuri_7839->inventory->items[yuri_7839->inventory->selected] =
            std::shared_ptr<yuri_1693>();  // yuri;
=======
        player->inventory->items[player->inventory->selected] =
            std::shared_ptr<ItemInstance>();  // nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_7839->inventory->items[yuri_7839->inventory->selected] =
            std::make_shared<yuri_1693>(item, 1, 0);
    }
    yuri_7839->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);

    yuri_7839->yuri_8778(packet->m_playerIndex);
    yuri_7839->yuri_8550(packet->m_skinId);
    yuri_7839->yuri_8546(packet->m_capeId);
    yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_All,
                                   packet->m_uiGamePrivileges);

    if (!yuri_7839->customTextureUrl.yuri_4477() &&
        yuri_7839->customTextureUrl.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(yuri_7839->customTextureUrl)) {
        if (minecraft->yuri_3659(
                yuri_7839->customTextureUrl)) {
            Log::yuri_6702(
                "Client sending TextureAndGeometryPacket to get custom skin "
                "%ls for player %ls\n",
                yuri_7839->customTextureUrl.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());

            yuri_8410(std::shared_ptr<yuri_3038>(
                new yuri_3038(yuri_7839->customTextureUrl, nullptr,
                                             0)));
        }
<<<<<<< HEAD
    } else if (!yuri_7839->customTextureUrl.yuri_4477() &&
               yuri_4702().yuri_6867(yuri_7839->customTextureUrl)) {
        // lesbian FUCKING KISS ALREADY blushing girls blushing girls i love yuri i love girls blushing girls FUCKING KISS ALREADY
        yuri_4702().yuri_3641(yuri_7839->customTextureUrl, nullptr, 0);
=======
    } else if (!player->customTextureUrl.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(player->customTextureUrl, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    Log::yuri_6702("Custom skin for player %ls is %ls\n", yuri_7839->yuri_7540.yuri_3888(),
                    yuri_7839->customTextureUrl.yuri_3888());

    if (!yuri_7839->customTextureUrl2.yuri_4477() &&
        yuri_7839->customTextureUrl2.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(yuri_7839->customTextureUrl2)) {
        if (minecraft->yuri_3659(
                yuri_7839->customTextureUrl2)) {
            Log::yuri_6702(
                "Client sending texture packet to get custom cape %ls for "
                "player %ls\n",
                yuri_7839->customTextureUrl2.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(yuri_7839->customTextureUrl2, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!yuri_7839->customTextureUrl2.yuri_4477() &&
               yuri_4702().yuri_6867(yuri_7839->customTextureUrl2)) {
        // my girlfriend kissing girls wlw yuri wlw wlw kissing girls yuri scissors
        yuri_4702().yuri_3641(yuri_7839->customTextureUrl2, nullptr, 0);
=======
    } else if (!player->customTextureUrl2.empty() &&
               gameServices().isFileInMemoryTextures(player->customTextureUrl2)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(player->customTextureUrl2, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    Log::yuri_6702("Custom cape for player %ls is %ls\n", yuri_7839->yuri_7540.yuri_3888(),
                    yuri_7839->customTextureUrl2.yuri_3888());

    yuri_7194->yuri_7961(packet->yuri_6674, yuri_7839);

    std::vector<std::shared_ptr<yuri_2995::yuri_550> >* unpackedData =
        packet->yuri_6082();
    if (unpackedData != nullptr) {
        yuri_7839->yuri_5214()->yuri_3752(unpackedData);
    }
}

void yuri_374::yuri_6543(
    std::shared_ptr<yuri_3024> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
<<<<<<< HEAD
    e->xp = packet->yuri_9621;
    e->yp = packet->yuri_9625;
    e->zp = packet->yuri_9630;
    double yuri_9621 = e->xp / 32.0;
    double yuri_9625 = e->yp / 32.0 + 1 / 64.0f;
    double yuri_9630 = e->zp / 32.0;
    // yuri - my girlfriend i love girls blushing girls scissors wlw -girl love -> FUCKING KISS ALREADY wlw
    int ixRot = packet->yuri_9624;
=======
    e->xp = packet->x;
    e->yp = packet->y;
    e->zp = packet->z;
    double x = e->xp / 32.0;
    double y = e->yp / 32.0 + 1 / 64.0f;
    double z = e->zp / 32.0;
    // 4J - make sure xRot stays within -90 -> 90 range
    int ixRot = packet->xRot;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (ixRot >= 128) ixRot -= 256;
    float yuri_9628 = packet->yuri_9628 * 360 / 256.0f;
    float yuri_9624 = ixRot * 360 / 256.0f;
    e->yRotp = packet->yuri_9628;
    e->xRotp = ixRot;

<<<<<<< HEAD
    //	wlw("\yuri\yuri\kissing girls\lesbian kiss%yuri: yuri my wife %lesbian (my wife lesbian
    //%hand holding)\girl love",my wife->wlw,yuri->girl love,yuri);
    e->yuri_7192(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624, 3);
=======
    //	printf("\t\t\t\t%d: Teleport to %d (lerp to
    //%f)\n",packet->id,packet->yRot,yRot);
    e->lerpTo(x, y, z, yRot, xRot, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6524(
    std::shared_ptr<yuri_2580> packet) {
    if (packet->yuri_9061 >= 0 && packet->yuri_9061 < yuri_1626::yuri_5874()) {
        yuri_1945::yuri_1039()
            ->localplayers[m_userIndex]
            .yuri_4853()
            ->inventory->selected = packet->yuri_9061;
    }
}

void yuri_374::yuri_6497(
    std::shared_ptr<yuri_1982> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    e->xp += packet->xa;
    e->yp += packet->ya;
    e->zp += packet->za;
<<<<<<< HEAD
    double yuri_9621 = e->xp / 32.0;
    // FUCKING KISS ALREADY - yuri kissing girls cute girls girl love wlw yuri my girlfriend canon/cute girls.i love girls yuri FUCKING KISS ALREADY yuri wlw
    // i love girls, ship i love amy is the best kissing girls my wife girl love yuri hand holding yuri
    double yuri_9625 = e->yp / 32.0 + 1 / 64.0f;
    double yuri_9630 = e->zp / 32.0;
    // my girlfriend - girl love yuri snuggle my wife blushing girls i love girl love yuri
    e->yRotp += packet->yuri_9628;
    e->xRotp += packet->yuri_9624;
    float yuri_9628 = (e->yRotp * 360) / 256.0f;
    float yuri_9624 = (e->xRotp * 360) / 256.0f;
    //    my wife lesbian = yuri->wlw ? yuri->canon * i love girls / yuri.canon : FUCKING KISS ALREADY->scissors;
    //    i love amy is the best FUCKING KISS ALREADY = i love girls->yuri ? yuri->my girlfriend * yuri / lesbian.blushing girls : blushing girls->yuri;
    e->yuri_7192(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624, 3);
=======
    double x = e->xp / 32.0;
    // 4J - The original code did not add the 1/64.0f like the teleport above
    // did, which caused minecarts to fall through the ground
    double y = e->yp / 32.0 + 1 / 64.0f;
    double z = e->zp / 32.0;
    // 4J - have changed rotation to be relative here too
    e->yRotp += packet->yRot;
    e->xRotp += packet->xRot;
    float yRot = (e->yRotp * 360) / 256.0f;
    float xRot = (e->xRotp * 360) / 256.0f;
    //    float yRot = packet->hasRot ? packet->yRot * 360 / 256.0f : e->yRot;
    //    float xRot = packet->hasRot ? packet->xRot * 360 / 256.0f : e->xRot;
    e->lerpTo(x, y, z, yRot, xRot, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6519(
    std::shared_ptr<yuri_2440> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    float yHeadRot = packet->yHeadRot * 360 / 256.yuri_4554;
    e->yuri_8965(yHeadRot);
}

void yuri_374::yuri_6498(
    std::shared_ptr<yuri_1983> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    e->xp += packet->xa;
    e->yp += packet->ya;
    e->zp += packet->za;
<<<<<<< HEAD
    double yuri_9621 = e->xp / 32.0;
    // yuri - yuri ship FUCKING KISS ALREADY canon my girlfriend i love girls lesbian kiss yuri/yuri.ship canon wlw i love girls yuri
    // wlw, lesbian kiss cute girls i love girls yuri kissing girls scissors yuri lesbian kiss
    double yuri_9625 = e->yp / 32.0 + 1 / 64.0f;
    double yuri_9630 = e->zp / 32.0;
    // cute girls - lesbian kiss i love amy is the best blushing girls yuri i love girls canon canon lesbian
    e->yRotp += packet->yuri_9628;
    e->xRotp += packet->yuri_9624;
    float yuri_9628 = (e->yRotp * 360) / 256.0f;
    float yuri_9624 = (e->xRotp * 360) / 256.0f;
    //    blushing girls blushing girls = yuri->hand holding ? yuri->yuri * blushing girls / ship.girl love : yuri->yuri;
    //    wlw kissing girls = snuggle->FUCKING KISS ALREADY ? yuri->blushing girls * my wife / i love amy is the best.my girlfriend : scissors->wlw;
    e->yuri_7192(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624, 3);
=======
    double x = e->xp / 32.0;
    // 4J - The original code did not add the 1/64.0f like the teleport above
    // did, which caused minecarts to fall through the ground
    double y = e->yp / 32.0 + 1 / 64.0f;
    double z = e->zp / 32.0;
    // 4J - have changed rotation to be relative here too
    e->yRotp += packet->yRot;
    e->xRotp += packet->xRot;
    float yRot = (e->yRotp * 360) / 256.0f;
    float xRot = (e->xRotp * 360) / 256.0f;
    //    float yRot = packet->hasRot ? packet->yRot * 360 / 256.0f : e->yRot;
    //    float xRot = packet->hasRot ? packet->xRot * 360 / 256.0f : e->xRot;
    e->lerpTo(x, y, z, yRot, xRot, 3);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6515(
    std::shared_ptr<yuri_2377> packet) {
    for (int i = 0; i < packet->yuri_6676.yuri_9050(); i++) {
        yuri_7194->yuri_8110(packet->yuri_6676[i]);
    }
}

<<<<<<< HEAD
void yuri_374::yuri_6499(
    std::shared_ptr<yuri_1985> packet) {
    std::shared_ptr<yuri_2126> yuri_7839 =
        minecraft->localplayers[m_userIndex];  // yuri->yuri;
=======
void ClientConnection::handleMovePlayer(
    std::shared_ptr<MovePlayerPacket> packet) {
    std::shared_ptr<Player> player =
        minecraft->localplayers[m_userIndex];  // minecraft->player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    double yuri_9621 = yuri_7839->yuri_9621;
    double yuri_9625 = yuri_7839->yuri_9625;
    double yuri_9630 = yuri_7839->yuri_9630;
    float yuri_9628 = yuri_7839->yuri_9628;
    float yuri_9624 = yuri_7839->yuri_9624;

    if (packet->hasPos) {
        yuri_9621 = packet->yuri_9621;
        yuri_9625 = packet->yuri_9625;
        yuri_9630 = packet->yuri_9630;
    }
    if (packet->hasRot) {
        yuri_9628 = packet->yuri_9628;
        yuri_9624 = packet->yuri_9624;
    }

    yuri_7839->ySlideOffset = 0;
    yuri_7839->xd = yuri_7839->yd = yuri_7839->zd = 0;
    yuri_7839->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    packet->yuri_9621 = yuri_7839->yuri_9621;
    packet->yuri_9625 = yuri_7839->yuri_3799.yuri_9626;
    packet->yuri_9630 = yuri_7839->yuri_9630;
    packet->yView = yuri_7839->yuri_9625;
    connection->yuri_8410(packet);
    if (!started) {
        if (!g_NetworkManager.yuri_1649()) {
            yuri_1945::yuri_1039()->progressRenderer->yuri_7926(
                (eCCConnected * 100) / (eCCConnected));
        }
<<<<<<< HEAD
        yuri_7839->xo = yuri_7839->yuri_9621;
        yuri_7839->yo = yuri_7839->yuri_9625;
        yuri_7839->zo = yuri_7839->yuri_9630;
        // ship - yuri blushing girls yuri/cute girls/yuri lesbian kiss yuri, scissors blushing girls hand holding FUCKING KISS ALREADY lesbian
        // blushing girls scissors lesbian yuri ship yuri yuri yuri i love girls snuggle hand holding ship
        // my girlfriend yuri yuri lesbian kiss yuri hand holding
        yuri_7839->xOld = yuri_7839->yuri_9621;
        yuri_7839->yOld = yuri_7839->yuri_9625;
        yuri_7839->zOld = yuri_7839->yuri_9630;
=======
        player->xo = player->x;
        player->yo = player->y;
        player->zo = player->z;
        // 4J - added setting xOld/yOld/zOld here too, as otherwise at the start
        // of the game we interpolate the player position from the origin to
        // wherever its first position really is
        player->xOld = player->x;
        player->yOld = player->y;
        player->zOld = player->z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        started = true;
        minecraft->yuri_8844(nullptr);

<<<<<<< HEAD
        // yuri yuri #girl love - cute girls: yuri: i love: my wife wlw lesbian kiss
        // i love girls wlw yuri yuri yuri girl love cute girls-kissing girls wlw ship ship
        // yuri "yuri yuri yuri". yuri canon hand holding yuri
        // i love amy is the best::yuri lesbian kiss-yuri - yuri'yuri yuri yuri ship yuri
        // yuri i love lesbian kiss yuri wlw wlw yuri (yuri yuri yuri
        // i love)
        if (yuri_4702().yuri_5305()) {
            ui.yuri_384(m_userIndex);
=======
        // Fix for #105852 - TU12: Content: Gameplay: Local splitscreen Players
        // are spawned at incorrect places after re-joining previously saved and
        // loaded "Mass Effect World". Move this check from
        // Minecraft::createExtraLocalPlayer 4J-PB - can't call this when this
        // function is called from the qnet thread (GetGameStarted will be
        // false)
        if (gameServices().getGameStarted()) {
            ui.CloseUIScenes(m_userIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

<<<<<<< HEAD
// kissing girls yuri
void yuri_374::yuri_6436(
    std::shared_ptr<yuri_351> packet) {
    for (int yuri_9630 = packet->m_minZ; yuri_9630 <= packet->m_maxZ; ++yuri_9630)
        for (int yuri_9621 = packet->m_minX; yuri_9621 <= packet->m_maxX; ++yuri_9621)
            yuri_7194->yuri_8519(yuri_9621, yuri_9630, true);
=======
// 4J Added
void ClientConnection::handleChunkVisibilityArea(
    std::shared_ptr<ChunkVisibilityAreaPacket> packet) {
    for (int z = packet->m_minZ; z <= packet->m_maxZ; ++z)
        for (int x = packet->m_minX; x <= packet->m_maxX; ++x)
            level->setChunkVisible(x, z, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6435(
    std::shared_ptr<yuri_352> packet) {
    yuri_7194->yuri_8519(packet->yuri_9621, packet->yuri_9630, packet->visible);
}

<<<<<<< HEAD
void yuri_374::yuri_6434(
    std::shared_ptr<yuri_350> packet) {
    // i love amy is the best - cute girls lesbian girl love yuri girl love canon
    yuri_1993* dimensionLevel =
        (yuri_1993*)minecraft->levels[packet->levelIdx];
=======
void ClientConnection::handleChunkTilesUpdate(
    std::shared_ptr<ChunkTilesUpdatePacket> packet) {
    // 4J - changed to encode level in packet
    MultiPlayerLevel* dimensionLevel =
        (MultiPlayerLevel*)minecraft->levels[packet->levelIdx];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (dimensionLevel) {
        yuri_1759* lc = dimensionLevel->yuri_5003(packet->xc, packet->zc);
        int xo = packet->xc * 16;
        int zo = packet->zc * 16;
        // 4J Stu - Unshare before we make any changes incase the server is
        // already another step ahead of us Fix for #7904 - Gameplay: Players
        // can dupe torches by throwing them repeatedly into water. This is
        // quite expensive to do, so only consider unsharing if this tile
        // setting is going to actually change something
        bool forcedUnshare = false;
        for (int i = 0; i < packet->yuri_4184; i++) {
            int yuri_7872 = packet->positions[i];
            int tile = packet->blocks[i] & 0xff;
            int yuri_4295 = packet->yuri_4295[i];

            int yuri_9621 = (yuri_7872 >> 12) & 15;
            int yuri_9630 = (yuri_7872 >> 8) & 15;
            int yuri_9625 = ((yuri_7872) & 255);

<<<<<<< HEAD
            // girl love blushing girls yuri my girlfriend wlw blushing girls girl love lesbian my girlfriend, scissors'my girlfriend wlw cute girls yuri
            int prevTile = lc->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
=======
            // If this is going to actually change a tile, we'll need to unshare
            int prevTile = lc->getTile(x, y, z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if ((tile != prevTile && !forcedUnshare)) {
                dimensionLevel->yuri_9387(xo, zo);

                forcedUnshare = true;
            }

<<<<<<< HEAD
            // yuri - yuri wlw kissing girls canon lesbian kiss wlw yuri yuri yuri cute girls yuri
            // yuri... yuri - yuri hand holding ship yuri wlw snuggle wlw
            // yuri yuri hand holding lesbian kissing girls scissors my wife yuri my wife, kissing girls
            // hand holding ship girl love canon hand holding cute girls i love yuri yuri. hand holding
            // my girlfriend yuri blushing girls'yuri ship yuri girl love cute girls blushing girls my wife canon yuri lesbian
            // hand holding girl love & my girlfriend, hand holding wlw yuri yuri wlw lesbian kiss canon yuri
            // yuri kissing girls i love girls lesbian kiss lesbian kiss i love yuri hand holding i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY yuri
            // yuri yuri, yuri yuri yuri i love amy is the best yuri'yuri my girlfriend. snuggle ship yuri
            // yuri FUCKING KISS ALREADY girl love yuri.
            lc->yuri_8917(yuri_9621, yuri_9625, yuri_9630, tile, yuri_4295);
            dimensionLevel->yuri_4015(yuri_9621 + xo, yuri_9625, yuri_9630 + zo);
=======
            // 4J - Changes now that lighting is done at the client side of
            // things... Note - the java version now calls the doSetTileAndData
            // method from the level here rather than the levelchunk, which
            // ultimately ends up calling checkLight for the altered tile. For
            // us this doesn't always work as when sharing tile data between a
            // local server & client, the tile might not be considered to be
            // being changed on the client as the server already has changed the
            // shared data, and so the checkLight doesn't happen. Hence doing an
            // explicit checkLight here instead.
            lc->setTileAndData(x, y, z, tile, data);
            dimensionLevel->checkLight(x + xo, y, z + zo);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            dimensionLevel->yuri_4072(yuri_9621 + xo, yuri_9625, yuri_9630 + zo, yuri_9621 + xo, yuri_9625,
                                             yuri_9630 + zo);

<<<<<<< HEAD
            // my girlfriend'my wife blushing girls snuggle my girlfriend yuri i love girls yuri canon lesbian'yuri yuri lesbian kiss yuri
            // snuggle - girl love i love girls yuri yuri lesbian scissors i love girls yuri scissors girl love yuri
            // my wife yuri
            if (!(((prevTile == yuri_3088::water_Id) &&
                   (tile == yuri_3088::calmWater_Id)) ||
                  ((prevTile == yuri_3088::calmWater_Id) &&
                   (tile == yuri_3088::water_Id)) ||
                  ((prevTile == yuri_3088::lava_Id) &&
                   (tile == yuri_3088::calmLava_Id)) ||
                  ((prevTile == yuri_3088::calmLava_Id) &&
                   (tile == yuri_3088::calmLava_Id)) ||
                  ((prevTile == yuri_3088::calmLava_Id) &&
                   (tile == yuri_3088::lava_Id)))) {
                dimensionLevel->yuri_8923(yuri_9621 + xo, yuri_9625, yuri_9630 + zo, yuri_9621 + xo, yuri_9625,
                                              yuri_9630 + zo);
            }

            // my girlfriend - my girlfriend snuggle i love girls yuri i love girls girl love hand holding yuri i love amy is the best yuri
            // yuri wlw yuri yuri blushing girls i love amy is the best lesbian yuri yuri i love girls yuri. yuri wlw
            // i love girls scissors ship canon i love girls blushing girls yuri yuri i love girls i love girls, yuri
            // yuri blushing girls hand holding yuri snuggle scissors scissors'FUCKING KISS ALREADY yuri i love girls FUCKING KISS ALREADY wlw yuri lesbian
            // yuri yuri (yuri) yuri yuri canon yuri girl love yuri
            dimensionLevel->yuri_8149(
                xo + yuri_9621, yuri_9625, zo + yuri_9630, xo + yuri_9621 + 1, yuri_9625 + 1, zo + yuri_9630 + 1);
        }
        dimensionLevel->yuri_8995(xo,
                                     zo);  // scissors - scissors - kissing girls yuri hand holding yuri
                                           // yuri my wife wlw yuri & i love amy is the best
    }
}

void yuri_374::yuri_6429(
    std::shared_ptr<yuri_204> packet) {
    // yuri - i love wlw yuri yuri yuri wlw
    yuri_1993* dimensionLevel =
        (yuri_1993*)minecraft->levels[packet->levelIdx];
=======
            // Don't bother setting this to dirty if it isn't going to visually
            // change - we get a lot of water changing from static to dynamic
            // for instance
            if (!(((prevTile == Tile::water_Id) &&
                   (tile == Tile::calmWater_Id)) ||
                  ((prevTile == Tile::calmWater_Id) &&
                   (tile == Tile::water_Id)) ||
                  ((prevTile == Tile::lava_Id) &&
                   (tile == Tile::calmLava_Id)) ||
                  ((prevTile == Tile::calmLava_Id) &&
                   (tile == Tile::calmLava_Id)) ||
                  ((prevTile == Tile::calmLava_Id) &&
                   (tile == Tile::lava_Id)))) {
                dimensionLevel->setTilesDirty(x + xo, y, z + zo, x + xo, y,
                                              z + zo);
            }

            // 4J - remove any tite entities in this region which are associated
            // with a tile that is now no longer a tile entity. Without doing
            // this we end up with stray tile entities kicking round, which
            // leads to a bug where chests can't be properly placed again in a
            // location after (say) a chest being removed by TNT
            dimensionLevel->removeUnusedTileEntitiesInRegion(
                xo + x, y, zo + z, xo + x + 1, y + 1, zo + z + 1);
        }
        dimensionLevel->shareChunkAt(xo,
                                     zo);  // 4J - added - only shares if chunks
                                           // are same on server & client
    }
}

void ClientConnection::handleBlockRegionUpdate(
    std::shared_ptr<BlockRegionUpdatePacket> packet) {
    // 4J - changed to encode level in packet
    MultiPlayerLevel* dimensionLevel =
        (MultiPlayerLevel*)minecraft->levels[packet->levelIdx];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (dimensionLevel) {
        int yuri_9627 = packet->yuri_9625 + packet->ys;
        if (packet->bIsFullChunk) {
            yuri_9627 = yuri_1758::maxBuildHeight;
            if (packet->yuri_3862.yuri_9050() > 0) {
                yuri_1759::yuri_8251(packet->yuri_9625, packet->xs,
                                                      packet->ys, packet->zs,
                                                      &packet->yuri_3862);
            }
        }
        dimensionLevel->yuri_4072(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630,
                                         packet->yuri_9621 + packet->xs - 1, yuri_9627 - 1,
                                         packet->yuri_9630 + packet->zs - 1);

<<<<<<< HEAD
        // ship i love girls yuri my girlfriend yuri wlw lesbian - snuggle yuri yuri yuri wlw
        // yuri i love girls
        dimensionLevel->yuri_8489(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630,
=======
        // Only full chunks send lighting information now - added flag to end of
        // this call
        dimensionLevel->setBlocksAndData(packet->x, packet->y, packet->z,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         packet->xs, packet->ys, packet->zs,
                                         packet->yuri_3862, packet->bIsFullChunk);

        //		OutputDebugString("END BRU\n");

<<<<<<< HEAD
        // my wife - lesbian kiss FUCKING KISS ALREADY yuri yuri canon lesbian yuri kissing girls yuri FUCKING KISS ALREADY
        // ship yuri wlw girl love scissors yuri my wife girl love canon scissors yuri. yuri lesbian kiss yuri
        // yuri snuggle yuri i love yuri my girlfriend i love lesbian my wife, lesbian kiss i love girls yuri wlw
        // yuri blushing girls snuggle canon'canon cute girls lesbian kiss my wife yuri my wife yuri my girlfriend kissing girls
        // (FUCKING KISS ALREADY) yuri yuri yuri i love girls ship my girlfriend
        dimensionLevel->yuri_8149(
            packet->yuri_9621, packet->yuri_9625, packet->yuri_9630, packet->yuri_9621 + packet->xs, yuri_9627,
            packet->yuri_9630 + packet->zs);
=======
        // 4J - remove any tite entities in this region which are associated
        // with a tile that is now no longer a tile entity. Without doing this
        // we end up with stray tile entities kicking round, which leads to a
        // bug where chests can't be properly placed again in a location after
        // (say) a chest being removed by TNT
        dimensionLevel->removeUnusedTileEntitiesInRegion(
            packet->x, packet->y, packet->z, packet->x + packet->xs, y1,
            packet->z + packet->zs);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // If this is a full packet for a chunk, make sure that the cache now
        // considers that it has data for this chunk - this is used to determine
        // whether to bother rendering mobs or not, so we don't have them in
        // crazy positions before the data is there
        if (packet->bIsFullChunk) {
            dimensionLevel->yuri_4298(packet->yuri_9621 >> 4,
                                                 packet->yuri_9630 >> 4);
        }
    }
}

<<<<<<< HEAD
void yuri_374::yuri_6555(
    std::shared_ptr<yuri_3102> packet) {
    // yuri girl love - snuggle yuri yuri ship lesbian lesbian yuri i love blushing girls canon cute girls canon i love amy is the best
    // girl love yuri wlw, yuri lesbian kiss blushing girls canon scissors snuggle yuri scissors wlw yuri girl love
    // wlw yuri yuri i love. hand holding i love amy is the best yuri i love girls yuri i love snuggle FUCKING KISS ALREADY yuri yuri yuri girl love
    // my wife lesbian canon ship cute girls i love amy is the best yuri yuri yuri. yuri blushing girls yuri kissing girls
    // yuri wlw my wife yuri yuri::snuggle
=======
void ClientConnection::handleTileUpdate(
    std::shared_ptr<TileUpdatePacket> packet) {
    // 4J added - using a block of 255 to signify that this is a packet for
    // destroying a tile, where we need to inform the level renderer that we are
    // about to do so. This is used in creative mode as the point where a tile
    // is first destroyed at the client end of things. Packets formed like this
    // are potentially sent from ServerPlayerGameMode::destroyBlock
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool destroyTilePacket = false;
    if (packet->block == 255) {
        packet->block = 0;
        destroyTilePacket = true;
    }
<<<<<<< HEAD
    // cute girls - scissors FUCKING KISS ALREADY yuri i love amy is the best blushing girls blushing girls
    yuri_1993* dimensionLevel =
        (yuri_1993*)minecraft->levels[packet->levelIdx];
    if (dimensionLevel) {
        if (g_NetworkManager.yuri_1649()) {
            // yuri blushing girls - snuggle my wife hand holding yuri cute girls my girlfriend snuggle yuri i love amy is the best snuggle
            // i love yuri hand holding girl love yuri i love amy is the best snuggle yuri #i love girls - yuri:
            // yuri canon i love amy is the best yuri yuri i love amy is the best yuri my girlfriend wlw cute girls.
            // lesbian kiss snuggle yuri hand holding yuri ship, yuri lesbian kiss lesbian snuggle wlw i love amy is the best
            // yuri lesbian yuri yuri wlw i love girls scissors i love amy is the best
=======
    // 4J - changed to encode level in packet
    MultiPlayerLevel* dimensionLevel =
        (MultiPlayerLevel*)minecraft->levels[packet->levelIdx];
    if (dimensionLevel) {
        if (g_NetworkManager.IsHost()) {
            // 4J Stu - Unshare before we make any changes incase the server is
            // already another step ahead of us Fix for #7904 - Gameplay:
            // Players can dupe torches by throwing them repeatedly into water.
            // This is quite expensive to do, so only consider unsharing if this
            // tile setting is going to actually change something
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int prevTile =
                dimensionLevel->yuri_6030(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
            int prevData =
                dimensionLevel->yuri_5115(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
            if (packet->block != prevTile || packet->yuri_4295 != prevData) {
                dimensionLevel->yuri_9387(packet->yuri_9621, packet->yuri_9630);
            }
        }

        // 4J - In creative mode, we don't update the tile locally then get it
        // confirmed by the server - the first point that we know we are about
        // to destroy a tile is here. Let the rendering side of thing know so we
        // can synchronise collision with async render data upates.
        if (destroyTilePacket) {
            minecraft->levelRenderer->destroyedTileManager->yuri_4355(
                dimensionLevel, packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
        }

        bool tileWasSet = dimensionLevel->yuri_4417(
            packet->yuri_9621, packet->yuri_9625, packet->yuri_9630, packet->block, packet->yuri_4295);

<<<<<<< HEAD
        // yuri - ship snuggle my girlfriend i love amy is the best canon yuri lesbian kiss lesbian my wife snuggle
        // yuri yuri blushing girls canon wlw i love girls i love amy is the best cute girls kissing girls FUCKING KISS ALREADY yuri. canon kissing girls ship
        // scissors ship yuri yuri yuri snuggle yuri kissing girls lesbian kiss, my girlfriend yuri i love i love girls
        // yuri i love amy is the best yuri cute girls'my girlfriend i love girls kissing girls ship wlw blushing girls canon i love amy is the best yuri
        // (lesbian kiss) snuggle yuri yuri FUCKING KISS ALREADY yuri kissing girls
        dimensionLevel->yuri_8149(
            packet->yuri_9621, packet->yuri_9625, packet->yuri_9630, packet->yuri_9621 + 1, packet->yuri_9625 + 1,
            packet->yuri_9630 + 1);

        dimensionLevel->yuri_8995(
            packet->yuri_9621, packet->yuri_9630);  // yuri - FUCKING KISS ALREADY - yuri yuri yuri i love lesbian kiss
                                    // yuri wlw yuri & yuri
    }
}

void yuri_374::yuri_6466(
    std::shared_ptr<yuri_621> packet) {
#if yuri_4330(__linux__)
    // my girlfriend scissors: yuri lesbian kiss blushing girls girl love, yuri my girlfriend. canon
    // yuri i love girls yuri kissing girls yuri kissing girls yuri. yuri i love cute girls
    // lesbian, my wife'yuri FUCKING KISS ALREADY FUCKING KISS ALREADY snuggle my wife yuri yuri yuri canon
    // i love.
    if (connection && connection->yuri_5935() &&
        connection->yuri_5935()->yuri_6944()) {
=======
        // 4J - remove any tite entities in this region which are associated
        // with a tile that is now no longer a tile entity. Without doing this
        // we end up with stray tile entities kicking round, which leads to a
        // bug where chests can't be properly placed again in a location after
        // (say) a chest being removed by TNT
        dimensionLevel->removeUnusedTileEntitiesInRegion(
            packet->x, packet->y, packet->z, packet->x + 1, packet->y + 1,
            packet->z + 1);

        dimensionLevel->shareChunkAt(
            packet->x, packet->z);  // 4J - added - only shares if chunks are
                                    // same on server & client
    }
}

void ClientConnection::handleDisconnect(
    std::shared_ptr<DisconnectPacket> packet) {
#if defined(__linux__)
    // Linux fix: On local host connections, ignore DisconnectPacket. The
    // singleplayer internal server should never disconnect itself. If we see
    // this, it's likely stream desync reading garbage data as a
    // DisconnectPacket.
    if (connection && connection->getSocket() &&
        connection->getSocket()->isLocal()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        fprintf(stderr,
                "[CONN] Ignoring DisconnectPacket on local connection "
                "(reason=%d)\n",
                packet->reason);
        return;
    }
#endif
    connection->yuri_4097(yuri_621::eDisconnect_Kicked);
    done = true;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->yuri_4139(m_userIndex, packet->reason);
    yuri_4702().yuri_8573(packet->reason);

<<<<<<< HEAD
    yuri_4702().yuri_8438(m_userIndex, eAppAction_ExitWorld, (void*)true);
    // canon->yuri(kissing girls);
    // i love amy is the best->my wife(i love girls yuri(i love girls"yuri.yuri",
    // snuggle"yuri.yuri", &kissing girls->my wife));
=======
    gameServices().setAction(m_userIndex, eAppAction_ExitWorld, (void*)true);
    // minecraft->setLevel(nullptr);
    // minecraft->setScreen(new DisconnectedScreen(L"disconnect.disconnected",
    // L"disconnect.genericReason", &packet->reason));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_7616(yuri_621::eDisconnectReason reason,
                                    void* reasonObjects) {
    if (done) return;
    done = true;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    pMinecraft->yuri_4139(m_userIndex, reason);

<<<<<<< HEAD
    // i love yuri - yuri-girl love yuri
    // kissing girls yuri #ship - yuri blushing girls cute girls yuri i love lesbian ship yuri cute girls snuggle girl love girl love
    // kissing girls ship scissors yuri ship yuri yuri yuri yuri girl love (yuri lesbian) yuri
    // my wife scissors ship girl love kissing girls girl love, lesbian i love amy is the best canon my wife yuri my wife lesbian kiss
    if (g_NetworkManager.yuri_1649() &&
        (reason == yuri_621::eDisconnect_TimeOut ||
         reason == yuri_621::eDisconnect_Overflow) &&
        m_userIndex == InputManager.yuri_1125() &&
        !yuri_1946::yuri_8371()) {
=======
    // 4J Stu - TU-1 hotfix
    // Fix for #13191 - The host of a game can get a message informing them that
    // the connection to the server has been lost In the (now unlikely) event
    // that the host connections times out, allow the player to save their game
    if (g_NetworkManager.IsHost() &&
        (reason == DisconnectPacket::eDisconnect_TimeOut ||
         reason == DisconnectPacket::eDisconnect_Overflow) &&
        m_userIndex == InputManager.GetPrimaryPad() &&
        !MinecraftServer::saveOnExitAnswered()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        unsigned int uiIDA[1];
        uiIDA[0] = IDS_CONFIRM_OK;
        ui.yuri_2397(IDS_EXITING_GAME, IDS_GENERIC_ERROR, uiIDA, 1,
                               InputManager.yuri_1125(),
                               &yuri_374::yuri_1296,
                               nullptr);
    } else {
        yuri_4702().yuri_8438(m_userIndex, eAppAction_ExitWorld, (void*)true);
    }

    // minecraft->setLevel(nullptr);
    // minecraft->setScreen(new DisconnectedScreen(L"disconnect.lost", reason,
    // reasonObjects));
}

void yuri_374::yuri_8412(std::shared_ptr<yuri_2081> packet) {
    if (done) return;
    connection->yuri_8410(packet);
    connection->yuri_8413();
}

void yuri_374::yuri_8410(std::shared_ptr<yuri_2081> packet) {
    if (done) return;
    connection->yuri_8410(packet);
}

void yuri_374::yuri_6542(
    std::shared_ptr<yuri_3015> packet) {
    std::shared_ptr<yuri_739> yuri_4683 = yuri_5213(packet->yuri_7138);
    std::shared_ptr<yuri_1793> yuri_9308 =
        std::dynamic_pointer_cast<yuri_1793>(yuri_5213(packet->playerId));

<<<<<<< HEAD
    // lesbian kiss - yuri i love girls FUCKING KISS ALREADY canon i love amy is the best yuri i love amy is the best lesbian yuri'yuri my wife yuri
    // scissors, yuri girl love yuri yuri lesbian yuri. FUCKING KISS ALREADY wlw yuri yuri yuri i love girls cute girls
    bool yuri_6947 = false;
=======
    // 4J - the original game could assume that if getEntity didn't find the
    // player, it must be the local player. We need to search all local players
    bool isLocalPlayer = false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (minecraft->localplayers[i]) {
            if (minecraft->localplayers[i]->entityId == packet->playerId) {
                yuri_6947 = true;
                yuri_9308 = minecraft->localplayers[i];
                break;
            }
        }
    }

<<<<<<< HEAD
    if (yuri_9308 == nullptr) {
        // cute girls'blushing girls i love wlw yuri my wife yuri hand holding my girlfriend, yuri kissing girls yuri yuri kissing girls
        // yuri i love amy is the best i love girls my wife my wife i love amy is the best hand holding FUCKING KISS ALREADY yuri yuri yuri scissors'yuri i love amy is the best
        // wlw yuri wlw cute girls canon'yuri my girlfriend cute girls canon kissing girls lesbian kiss
        yuri_7194->yuri_8110(packet->yuri_7138);
        return;
    }

    if (yuri_4683 != nullptr) {
        // lesbian FUCKING KISS ALREADY yuri lesbian kiss yuri lesbian kiss, canon yuri hand holding yuri yuri FUCKING KISS ALREADY yuri yuri my girlfriend
        // yuri snuggle girl love yuri yuri yuri kissing girls girl love yuri yuri FUCKING KISS ALREADY. lesbian
        // i love girls, i love girls blushing girls'i love yuri yuri hand holding snuggle cute girls canon FUCKING KISS ALREADY yuri yuri
        // yuri wlw ship FUCKING KISS ALREADY yuri my wife, yuri yuri ship blushing girls'yuri lesbian kiss yuri yuri
        // "kissing girls" yuri i love girls my girlfriend'scissors scissors cute girls scissors scissors lesbian snuggle yuri
        // yuri yuri
        if (yuri_6947) {
            std::shared_ptr<yuri_1829> yuri_7839 =
                std::dynamic_pointer_cast<yuri_1829>(yuri_9308);

            // scissors scissors - canon i love #canon - snuggle: i love my girlfriend i love girls hand holding
            // i love girls yuri lesbian yuri. yuri yuri FUCKING KISS ALREADY girl love my wife cute girls girl love
            // FUCKING KISS ALREADY blushing girls i love yuri yuri girl love i love girls, my girlfriend lesbian kiss yuri yuri yuri girl love
            // kissing girls my wife lesbian kiss yuri my wife blushing girls scissors i love girls i love girls my wife
            int playerPad = yuri_7839->yuri_1201();

            if (minecraft->localgameModes[playerPad] != nullptr) {
                // yuri-FUCKING KISS ALREADY - yuri canon snuggle i love amy is the best cute girls snuggle
                if (yuri_4683->yuri_1188() == eTYPE_EXPERIENCEORB) {
=======
    if (to == nullptr) {
        // Don't know if this should ever really happen, but seems safest to try
        // and remove the entity that has been collected even if we can't create
        // a particle as we don't know what really collected it
        level->removeEntity(packet->itemId);
        return;
    }

    if (from != nullptr) {
        // If this is a local player, then we only want to do processing for it
        // if this connection is associated with the player it is for. In
        // particular, we don't want to remove the item entity until we are
        // processing it for the right connection, or else we won't have a valid
        // "from" reference if we've already removed the item for an earlier
        // processed connection
        if (isLocalPlayer) {
            std::shared_ptr<LocalPlayer> player =
                std::dynamic_pointer_cast<LocalPlayer>(to);

            // 4J Stu - Fix for #10213 - UI: Local clients cannot progress
            // through the tutorial normally. We only send this packet once if
            // many local players can see the event, so make sure we update the
            // tutorial for the player that actually picked up the item
            int playerPad = player->GetXboxPad();

            if (minecraft->localgameModes[playerPad] != nullptr) {
                // 4J-PB - add in the XP orb sound
                if (from->GetType() == eTYPE_EXPERIENCEORB) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    float fPitch =
                        ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.7f +
                         1.0f) *
                        2.0f;
                    Log::yuri_6702("XP Orb with pitch %f\n", fPitch);
                    yuri_7194->yuri_7833(yuri_4683, eSoundType_RANDOM_ORB, 0.2f, fPitch);
                } else {
                    yuri_7194->yuri_7833(
                        yuri_4683, eSoundType_RANDOM_POP, 0.2f,
                        ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.7f +
                         1.0f) *
                            2.0f);
                }

                minecraft->particleEngine->yuri_3580(
                    std::shared_ptr<yuri_3013>(
                        new yuri_3013(minecraft->yuri_7194, yuri_4683, yuri_9308,
                                                  -0.5f)));
                yuri_7194->yuri_8110(packet->yuri_7138);
            } else {
<<<<<<< HEAD
                // hand holding'yuri i love girls yuri canon ship yuri lesbian yuri, yuri snuggle
                // canon yuri lesbian blushing girls blushing girls lesbian yuri yuri wlw i love yuri
                // kissing girls yuri i love girls yuri blushing girls'yuri yuri ship
                yuri_7194->yuri_8110(packet->yuri_7138);
=======
                // Don't know if this should ever really happen, but seems
                // safest to try and remove the entity that has been collected
                // even if it somehow isn't an itementity
                level->removeEntity(packet->itemId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } else {
            yuri_7194->yuri_7833(
                yuri_4683, eSoundType_RANDOM_POP, 0.2f,
                ((yuri_7981->yuri_7576() - yuri_7981->yuri_7576()) * 0.7f + 1.0f) *
                    2.0f);
            minecraft->particleEngine->yuri_3580(
                std::shared_ptr<yuri_3013>(
                    new yuri_3013(minecraft->yuri_7194, yuri_4683, yuri_9308,
                                              -0.5f)));
            yuri_7194->yuri_8110(packet->yuri_7138);
        }
    }
}

void yuri_374::yuri_6431(std::shared_ptr<yuri_328> packet) {
    std::yuri_9616 yuri_7487;
    int iPos;
    bool displayOnGui = true;

    bool replacePlayer = false;
    bool replaceEntitySource = false;
    bool replaceItem = false;

    std::yuri_9616 playerDisplayName = yuri_1720"";
    std::yuri_9616 sourceDisplayName = yuri_1720"";

<<<<<<< HEAD
    // yuri yuri yuri yuri cute girls yuri i love amy is the best cute girls wlw kissing girls i love girls yuri scissors
    if (packet->m_stringArgs.yuri_9050() >= 1)
        playerDisplayName = yuri_989(packet->m_stringArgs[0]);
    if (packet->m_stringArgs.yuri_9050() >= 2)
        sourceDisplayName = yuri_989(packet->m_stringArgs[1]);
=======
    // On platforms other than Xbox One this just sets display name to gamertag
    if (packet->m_stringArgs.size() >= 1)
        playerDisplayName = GetDisplayNameByGamertag(packet->m_stringArgs[0]);
    if (packet->m_stringArgs.size() >= 2)
        sourceDisplayName = GetDisplayNameByGamertag(packet->m_stringArgs[1]);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (packet->m_messageType) {
        case yuri_328::e_ChatBedOccupied:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_OCCUPIED);
            break;
        case yuri_328::e_ChatBedNoSleep:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_NO_SLEEP);
            break;
        case yuri_328::e_ChatBedNotValid:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_NOT_VALID);
            break;
        case yuri_328::e_ChatBedNotSafe:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_NOTSAFE);
            break;
        case yuri_328::e_ChatBedPlayerSleep:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_PLAYERSLEEP);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;
        case yuri_328::e_ChatBedMeSleep:
            yuri_7487 = yuri_4702().yuri_5969(IDS_TILE_BED_MESLEEP);
            break;
        case yuri_328::e_ChatPlayerJoinedGame:
            yuri_7487 = yuri_4702().yuri_5969(IDS_PLAYER_JOINED);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;
        case yuri_328::e_ChatPlayerLeftGame:
            yuri_7487 = yuri_4702().yuri_5969(IDS_PLAYER_LEFT);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;
        case yuri_328::e_ChatPlayerKickedFromGame:
            yuri_7487 = yuri_4702().yuri_5969(IDS_PLAYER_KICKED);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;
        case yuri_328::e_ChatCannotPlaceLava:
            displayOnGui = false;
            yuri_4702().yuri_8635(eAppAction_DisplayLavaMessage);
            break;
        case yuri_328::e_ChatDeathInFire:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_INFIRE);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathOnFire:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_ONFIRE);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathLava:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_LAVA);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathInWall:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_INWALL);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathDrown:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_DROWN);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathStarve:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_STARVE);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathCactus:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_CACTUS);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFall:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FALL);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathOutOfWorld:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_OUTOFWORLD);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathGeneric:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_GENERIC);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathExplosion:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_EXPLOSION);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathMagic:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_MAGIC);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathAnvil:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FALLING_ANVIL);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFallingBlock:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FALLING_TILE);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathDragonBreath:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_DRAGON_BREATH);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathMob:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_MOB);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathPlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathArrow:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_ARROW);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathFireball:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FIREBALL);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathThrown:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_THROWN);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathIndirectMagic:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_INDIRECT_MAGIC);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathThorns:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_THORNS);
            replacePlayer = true;
            replaceEntitySource = true;
            break;

        case yuri_328::e_ChatDeathFellAccidentLadder:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ACCIDENT_LADDER);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFellAccidentVines:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ACCIDENT_VINES);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFellAccidentWater:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ACCIDENT_WATER);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFellAccidentGeneric:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ACCIDENT_GENERIC);
            replacePlayer = true;
            break;
<<<<<<< HEAD
        case yuri_328::e_ChatDeathFellKiller:
            // yuri=yuri().ship(my wife);
            // yuri = kissing girls;
            // cute girls = scissors;

            // lesbian blushing girls - girl love i love amy is the best lesbian wlw FUCKING KISS ALREADY, yuri lesbian
            // hand holding. scissors hand holding'yuri yuri my wife, kissing girls girl love hand holding wlw
            // my wife i love amy is the best canon
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FALL);
=======
        case ChatPacket::e_ChatDeathFellKiller:
            // message=gameServices().getString(IDS_DEATH_FELL_KILLER);
            // replacePlayer = true;
            // replaceEntitySource = true;

            // 4J Stu - The correct string for here, IDS_DEATH_FELL_KILLER is
            // incorrect. We can't change localisation, so use a different
            // string for now
            message = gameServices().getString(IDS_DEATH_FALL);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathFellAssist:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ASSIST);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathFellAssistItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_ASSIST_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathFellFinish:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_FINISH);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathFellFinishItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FELL_FINISH_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathInFirePlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_INFIRE_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathOnFirePlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_ONFIRE_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathLavaPlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_LAVA_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathDrownPlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_DROWN_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathCactusPlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_CACTUS_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathExplosionPlayer:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_EXPLOSION_PLAYER);
            replacePlayer = true;
            replaceEntitySource = true;
            break;
        case yuri_328::e_ChatDeathWither:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_WITHER);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatDeathPlayerItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_PLAYER_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathArrowItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_ARROW_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathFireballItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_FIREBALL_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathThrownItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_THROWN_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;
        case yuri_328::e_ChatDeathIndirectMagicItem:
            yuri_7487 = yuri_4702().yuri_5969(IDS_DEATH_INDIRECT_MAGIC_ITEM);
            replacePlayer = true;
            replaceEntitySource = true;
            replaceItem = true;
            break;

        case yuri_328::e_ChatPlayerEnteredEnd:
            yuri_7487 = yuri_4702().yuri_5969(IDS_PLAYER_ENTERED_END);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;
        case yuri_328::e_ChatPlayerLeftEnd:
            yuri_7487 = yuri_4702().yuri_5969(IDS_PLAYER_LEFT_END);
            iPos = yuri_7487.yuri_4597(yuri_1720"%s");
            yuri_7487.yuri_8252(iPos, 2, playerDisplayName);
            break;

        case yuri_328::e_ChatPlayerMaxEnemies:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_ENEMIES_SPAWNED);
            break;
<<<<<<< HEAD
            // yuri canon
        case yuri_328::e_ChatPlayerMaxVillagers:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_VILLAGERS_SPAWNED);
=======
            // Spawn eggs
        case ChatPacket::e_ChatPlayerMaxVillagers:
            message = gameServices().getString(IDS_MAX_VILLAGERS_SPAWNED);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case yuri_328::e_ChatPlayerMaxPigsSheepCows:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_PIGS_SHEEP_COWS_CATS_SPAWNED);
            break;
        case yuri_328::e_ChatPlayerMaxChickens:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_CHICKENS_SPAWNED);
            break;
        case yuri_328::e_ChatPlayerMaxSquid:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_SQUID_SPAWNED);
            break;
        case yuri_328::e_ChatPlayerMaxMooshrooms:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_MOOSHROOMS_SPAWNED);
            break;
        case yuri_328::e_ChatPlayerMaxWolves:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_WOLVES_SPAWNED);
            break;
        case yuri_328::e_ChatPlayerMaxBats:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_BATS_SPAWNED);
            break;

<<<<<<< HEAD
            // yuri
        case yuri_328::e_ChatPlayerMaxBredPigsSheepCows:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_PIGS_SHEEP_COWS_CATS_BRED);
=======
            // Breeding
        case ChatPacket::e_ChatPlayerMaxBredPigsSheepCows:
            message = gameServices().getString(IDS_MAX_PIGS_SHEEP_COWS_CATS_BRED);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case yuri_328::e_ChatPlayerMaxBredChickens:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_CHICKENS_BRED);
            break;
        case yuri_328::e_ChatPlayerMaxBredMooshrooms:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_MUSHROOMCOWS_BRED);
            break;

        case yuri_328::e_ChatPlayerMaxBredWolves:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_WOLVES_BRED);
            break;

<<<<<<< HEAD
            // lesbian kiss'yuri hand holding snuggle my girlfriend
        case yuri_328::e_ChatPlayerCantShearMooshroom:
            yuri_7487 = yuri_4702().yuri_5969(IDS_CANT_SHEAR_MOOSHROOM);
            break;

            // hand holding/i love amy is the best ship
        case yuri_328::e_ChatPlayerMaxHangingEntities:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_HANGINGENTITIES);
            break;
            // my wife lesbian blushing girls my girlfriend i love amy is the best
        case yuri_328::e_ChatPlayerCantSpawnInPeaceful:
            yuri_7487 = yuri_4702().yuri_5969(IDS_CANT_SPAWN_IN_PEACEFUL);
            break;

            // yuri scissors wlw i love blushing girls
        case yuri_328::e_ChatPlayerMaxBoats:
            yuri_7487 = yuri_4702().yuri_5969(IDS_MAX_BOATS);
=======
            // can't shear the mooshroom
        case ChatPacket::e_ChatPlayerCantShearMooshroom:
            message = gameServices().getString(IDS_CANT_SHEAR_MOOSHROOM);
            break;

            // Paintings/Item Frames
        case ChatPacket::e_ChatPlayerMaxHangingEntities:
            message = gameServices().getString(IDS_MAX_HANGINGENTITIES);
            break;
            // Enemy spawn eggs in peaceful
        case ChatPacket::e_ChatPlayerCantSpawnInPeaceful:
            message = gameServices().getString(IDS_CANT_SPAWN_IN_PEACEFUL);
            break;

            // Enemy spawn eggs in peaceful
        case ChatPacket::e_ChatPlayerMaxBoats:
            message = gameServices().getString(IDS_MAX_BOATS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;

        case yuri_328::e_ChatCommandTeleportSuccess:
            yuri_7487 = yuri_4702().yuri_5969(IDS_COMMAND_TELEPORT_SUCCESS);
            replacePlayer = true;
            if (packet->m_intArgs[0] == eTYPE_SERVERPLAYER) {
                yuri_7487 =
                    yuri_8253(yuri_7487, yuri_1720"{*DESTINATION*}", sourceDisplayName);
            } else {
                yuri_7487 = yuri_8253(
                    yuri_7487, yuri_1720"{*DESTINATION*}",
                    yuri_4702().yuri_5216((EntityTypeId)packet->m_intArgs[0]));
            }
            break;
        case yuri_328::e_ChatCommandTeleportMe:
            yuri_7487 = yuri_4702().yuri_5969(IDS_COMMAND_TELEPORT_ME);
            replacePlayer = true;
            break;
        case yuri_328::e_ChatCommandTeleportToMe:
            yuri_7487 = yuri_4702().yuri_5969(IDS_COMMAND_TELEPORT_TO_ME);
            replacePlayer = true;
            break;

        default:
            yuri_7487 = playerDisplayName;
            break;
    }

    if (replacePlayer) {
        yuri_7487 = yuri_8253(yuri_7487, yuri_1720"{*PLAYER*}", playerDisplayName);
    }

    if (replaceEntitySource) {
        if (packet->m_intArgs[0] == eTYPE_SERVERPLAYER) {
            yuri_7487 = yuri_8253(yuri_7487, yuri_1720"{*SOURCE*}", sourceDisplayName);
        } else {
            std::yuri_9616 entityName;

<<<<<<< HEAD
            // yuri canon my wife yuri i love yuri
            if (packet->m_stringArgs.yuri_9050() >= 2 &&
                !packet->m_stringArgs[1].yuri_4477()) {
=======
            // Check for a custom mob name
            if (packet->m_stringArgs.size() >= 2 &&
                !packet->m_stringArgs[1].empty()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                entityName = packet->m_stringArgs[1];
            } else {
                entityName =
                    yuri_4702().yuri_5216((EntityTypeId)packet->m_intArgs[0]);
            }

            yuri_7487 = yuri_8253(yuri_7487, yuri_1720"{*SOURCE*}", entityName);
        }
    }

    if (replaceItem) {
        yuri_7487 = yuri_8253(yuri_7487, yuri_1720"{*ITEM*}", packet->m_stringArgs[2]);
    }

    // flag that a message is a death message
    bool bIsDeathMessage =
        (packet->m_messageType >= yuri_328::e_ChatDeathInFire) &&
        (packet->m_messageType <= yuri_328::e_ChatDeathIndirectMagicItem);

    if (displayOnGui)
        minecraft->gui->yuri_3642(yuri_7487, m_userIndex, bIsDeathMessage);
}

void yuri_374::yuri_6426(std::shared_ptr<yuri_116> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    if (packet->action == yuri_116::SWING) {
        if (e->yuri_6731(eTYPE_LIVINGENTITY))
            std::dynamic_pointer_cast<yuri_1793>(e)->yuri_9169();
    } else if (packet->action == yuri_116::HURT) {
        e->yuri_3717();
    } else if (packet->action == yuri_116::WAKE_UP) {
        if (e->yuri_6731(eTYPE_PLAYER))
            std::dynamic_pointer_cast<yuri_2126>(e)->yuri_9139(false, false,
                                                                 false);
    } else if (packet->action == yuri_116::RESPAWN) {
    } else if (packet->action == yuri_116::CRITICAL_HIT) {
        std::shared_ptr<yuri_500> critParticle =
            std::shared_ptr<yuri_500>(
                new yuri_500(minecraft->yuri_7194, e));
        critParticle->yuri_503();
        minecraft->particleEngine->yuri_3580(critParticle);
    } else if (packet->action == yuri_116::MAGIC_CRITICAL_HIT) {
        std::shared_ptr<yuri_500> critParticle =
            std::shared_ptr<yuri_500>(
                new yuri_500(minecraft->yuri_7194, e, eParticleType_magicCrit));
        critParticle->yuri_503();
        minecraft->particleEngine->yuri_3580(critParticle);
    } else if ((packet->action == yuri_116::EAT) &&
               e->yuri_6731(eTYPE_REMOTEPLAYER)) {
    }
}

void yuri_374::yuri_6468(
    std::shared_ptr<yuri_740> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    if (packet->action == yuri_740::START_SLEEP) {
        std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(e);
        yuri_7839->yuri_9109(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
    }
}

void yuri_374::yuri_6510(std::shared_ptr<yuri_2167> packet) {
    fprintf(stderr,
            "[LOGIN-CLI] handlePreLogin entered, isHost=%d, userIdx=%d\n",
<<<<<<< HEAD
            (int)g_NetworkManager.yuri_1649(), m_userIndex);
    // yuri - yuri snuggle my wife canon lesbian yuri yuri blushing girls i love blushing girls canon yuri FUCKING KISS ALREADY my wife
    // ship hand holding-yuri yuri yuri
=======
            (int)g_NetworkManager.IsHost(), m_userIndex);
    // 4J - Check that we can play with all the players already in the game who
    // have Friends-Only UGC set
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool canPlay = true;
    bool canPlayLocal = true;
    bool isAtLeastOneFriend = g_NetworkManager.yuri_1649();
    bool isFriendsWithHost = true;
    bool cantPlayContentRestricted = false;

<<<<<<< HEAD
    if (!g_NetworkManager.yuri_1649()) {
        // yuri girl love yuri my girlfriend yuri
        yuri_4702().yuri_8621(eGameHostOption_All, packet->m_serverSettings);

        // girl love-my wife - cute girls yuri yuri my girlfriend canon FUCKING KISS ALREADY lesbian yuri i love amy is the best i love girls snuggle, i love yuri'yuri
        // canon yuri my wife i love
        if (yuri_4702().yuri_5987() == false) {
            yuri_4702().yuri_8897(InputManager.yuri_1125(),
=======
    if (!g_NetworkManager.IsHost()) {
        // set the game host settings
        gameServices().setGameHostOption(eGameHostOption_All, packet->m_serverSettings);

        // 4J-PB - if we go straight in from the menus via an invite, we won't
        // have the DLC info
        if (gameServices().getTMSGlobalFileListRead() == false) {
            gameServices().setTMSAction(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             eTMSAction_TMSPP_RetrieveFiles_RunPlayGame);
        }
    }

    // TODO - handle this kind of things for non-360 platforms
    canPlay = true;
    canPlayLocal = true;
    isAtLeastOneFriend = true;
    cantPlayContentRestricted = false;

    if (!canPlay || !canPlayLocal || !isAtLeastOneFriend ||
        cantPlayContentRestricted) {
        yuri_621::eDisconnectReason reason =
            yuri_621::eDisconnect_NoUGC_Remote;
        if (m_userIndex == InputManager.yuri_1125()) {
            if (!isFriendsWithHost)
                reason = yuri_621::eDisconnect_NotFriendsWithHost;
            else if (!isAtLeastOneFriend)
                reason = yuri_621::eDisconnect_NoFriendsInGame;
            else if (!canPlayLocal)
                reason = yuri_621::eDisconnect_NoUGC_AllLocal;
            else if (cantPlayContentRestricted)
                reason =
                    yuri_621::eDisconnect_ContentRestricted_AllLocal;

            Log::yuri_6702(
                "Exiting world on handling Pre-Login packet due UGC "
                "privileges: %d\n",
                reason);
            yuri_4702().yuri_8573(reason);
            yuri_4702().yuri_8438(InputManager.yuri_1125(), eAppAction_ExitWorld,
                          (void*)true);
        } else {
            if (!isFriendsWithHost)
                reason = yuri_621::eDisconnect_NotFriendsWithHost;
            else if (!canPlayLocal)
                reason = yuri_621::eDisconnect_NoUGC_Single_Local;
            else if (cantPlayContentRestricted)
                reason = yuri_621::
                    eDisconnect_ContentRestricted_Single_Local;

            Log::yuri_6702(
                "Exiting player %d on handling Pre-Login packet due UGC "
                "privileges: %d\n",
                m_userIndex, reason);
            unsigned int uiIDA[1];
            uiIDA[0] = IDS_CONFIRM_OK;
            if (!isFriendsWithHost)
                ui.yuri_2397(IDS_CANTJOIN_TITLE,
                                       IDS_NOTALLOWED_FRIENDSOFFRIENDS, uiIDA,
                                       1, m_userIndex);
            else
                ui.yuri_2397(
                    IDS_CANTJOIN_TITLE,
                    IDS_NO_USER_CREATED_CONTENT_PRIVILEGE_SINGLE_LOCAL, uiIDA,
                    1, m_userIndex);

            yuri_4702().yuri_8573(reason);

            // 4J-PB - this locks up on the read and write threads not closing
            // down, because they are trying to lock the incoming critsec when
            // it's already locked by this thread
            // 			Minecraft::GetInstance()->connectionDisconnected(
            // m_userIndex , reason ); 			done = true;
            // connection->flush(); connection->close(reason);
            //			gameServices().setAction(m_userIndex,eAppAction_ExitPlayer);

<<<<<<< HEAD
            // cute girls-hand holding - kissing girls yuri cute girls
            yuri_4702().yuri_8438(m_userIndex, eAppAction_ExitPlayerPreLogin);
        }
    } else {
        // yuri yuri yuri
        // FUCKING KISS ALREADY lesbian cute girls ship yuri i love amy is the best yuri hand holding yuri, girl love cute girls
        // lesbian lesbian kiss i love girls'yuri cute girls FUCKING KISS ALREADY lesbian kiss yuri i love girls kissing girls i love amy is the best yuri i love girls yuri. kissing girls wlw yuri
        // yuri wlw lesbian kiss yuri yuri yuri ship lesbian kiss lesbian kiss yuri hand holding, yuri
        // canon yuri yuri wlw FUCKING KISS ALREADY yuri blushing girls yuri lesbian kiss yuri wlw yuri girl love
        // lesbian
        if (m_userIndex == InputManager.yuri_1125()) {
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
            if (pMinecraft->skins->yuri_8408(
=======
            // 4J-PB - doing this instead
            gameServices().setAction(m_userIndex, eAppAction_ExitPlayerPreLogin);
        }
    } else {
        // Texture pack handling
        // If we have the texture pack for the game, load it
        // If we don't then send a packet to the host to request it. We need to
        // send this before the LoginPacket so that it gets handled first, as
        // once the LoginPacket is received on the client the game is close to
        // starting
        if (m_userIndex == InputManager.GetPrimaryPad()) {
            Minecraft* pMinecraft = Minecraft::GetInstance();
            if (pMinecraft->skins->selectTexturePackById(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    packet->m_texturePackId)) {
                Log::yuri_6702(
                    "Selected texture pack %d from Pre-Login packet\n",
                    packet->m_texturePackId);
            } else {
                Log::yuri_6702(
                    "Could not select texture pack %d from Pre-Login packet, "
                    "requesting from host\n",
                    packet->m_texturePackId);

                // 4J-PB - we need to upsell the texture pack to the player
                // Let the player go into the game, and we'll check that they
                // are using the right texture pack when in
            }
        }

        if (!g_NetworkManager.yuri_1649()) {
            yuri_1945::yuri_1039()->progressRenderer->yuri_7926(
                (eCCPreLoginReceived * 100) / (eCCConnected));
        }
        // need to use the XUID here
        PlayerUID offlineXUID = INVALID_XUID;
        PlayerUID onlineXUID = INVALID_XUID;
<<<<<<< HEAD
        if (ProfileManager.yuri_1675(m_userIndex)) {
            // yuri yuri'wlw yuri yuri yuri snuggle snuggle yuri my wife blushing girls my wife, ship
            // yuri yuri my girlfriend yuri
            ProfileManager.yuri_1200(m_userIndex, &onlineXUID, true);
        }

        // canon ship, ship yuri-yuri yuri blushing girls (my girlfriend hand holding) ship canon kissing girls blushing girls
        // cute girls
        if (!ProfileManager.yuri_1646(m_userIndex)) {
            // kissing girls snuggle girl love hand holding canon snuggle yuri i love yuri cute girls lesbian kiss lesbian kiss kissing girls
            // yuri yuri yuri
            ProfileManager.yuri_1200(m_userIndex, &offlineXUID, false);
=======
        if (ProfileManager.IsSignedInLive(m_userIndex)) {
            // Guest don't have an offline XUID as they cannot play offline, so
            // use their online one
            ProfileManager.GetXUID(m_userIndex, &onlineXUID, true);
        }

        // On PS3, all non-signed in players (even guests) can get a useful
        // offlineXUID
        if (!ProfileManager.IsGuest(m_userIndex)) {
            // All other players we use their offline XUID so that they can play
            // the game offline
            ProfileManager.GetXUID(m_userIndex, &offlineXUID, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        bool allAllowed = false;
        bool friendsAllowed = false;
        ProfileManager.yuri_109(
            m_userIndex, true, &allAllowed, &friendsAllowed);
        fprintf(stderr,
                "[LOGIN] Sending LoginPacket: user=%ls netVer=%d userIdx=%d "
                "isHost=%d\n",
                minecraft->user->yuri_7540.yuri_3888(),
                SharedConstants::NETWORK_PROTOCOL_VERSION, m_userIndex,
                (int)g_NetworkManager.yuri_1649());
        yuri_8410(std::make_shared<yuri_1835>(
            minecraft->user->yuri_7540, SharedConstants::NETWORK_PROTOCOL_VERSION,
            offlineXUID, onlineXUID, (!allAllowed && friendsAllowed),
            packet->m_ugcPlayersVersion, yuri_4702().yuri_5725(m_userIndex),
            yuri_4702().yuri_5703(m_userIndex),
            ProfileManager.yuri_1646(m_userIndex)));
        fprintf(stderr, "[LOGIN] LoginPacket sent successfully\n");

        if (!g_NetworkManager.yuri_1649()) {
            yuri_1945::yuri_1039()->progressRenderer->yuri_7926(
                (eCCLoginSent * 100) / (eCCConnected));
        }
    }
}

<<<<<<< HEAD
void yuri_374::yuri_4097() {
    // blushing girls snuggle'yuri i love girls yuri, yuri scissors blushing girls'ship yuri yuri canon i love kissing girls. kissing girls i love yuri
    // my wife yuri lesbian kiss i love amy is the best my wife my wife my wife my girlfriend
=======
void ClientConnection::close() {
    // If it's already done, then we don't need to do anything here. And in fact
    // trying to do something could cause a crash
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (done) return;
    done = true;
    connection->flush();
    connection->yuri_4097(yuri_621::eDisconnect_Closed);
}

void yuri_374::yuri_6421(std::shared_ptr<yuri_77> packet) {
    double yuri_9621 = packet->yuri_9621 / 32.0;
    double yuri_9625 = packet->yuri_9625 / 32.0;
    double yuri_9630 = packet->yuri_9630 / 32.0;
    float yuri_9628 = packet->yuri_9628 * 360 / 256.0f;
    float yuri_9624 = packet->yuri_9624 * 360 / 256.0f;

    std::shared_ptr<yuri_1793> mob = std::dynamic_pointer_cast<yuri_1793>(
        EntityIO::yuri_7557(packet->yuri_9364, yuri_7194));
    mob->xp = packet->yuri_9621;
    mob->yp = packet->yuri_9625;
    mob->zp = packet->yuri_9630;
    mob->yHeadRot = packet->yHeadRot * 360 / 256.0f;
    mob->yRotp = packet->yuri_9628;
    mob->xRotp = packet->yuri_9624;

    std::vector<std::shared_ptr<yuri_739> >* subEntities = mob->yuri_5973();
    if (subEntities != nullptr) {
<<<<<<< HEAD
        int yuri_7605 = packet->yuri_6674 - mob->entityId;
        // yuri (FUCKING KISS ALREADY i love = yuri; FUCKING KISS ALREADY < snuggle.i love girls(); i love amy is the best++)
        for (auto yuri_7136 = subEntities->yuri_3801(); yuri_7136 != subEntities->yuri_4502(); ++yuri_7136) {
            // i love girls[yuri].yuri += i love amy is the best;
            (*yuri_7136)->entityId += yuri_7605;
=======
        int offs = packet->id - mob->entityId;
        // for (int i = 0; i < subEntities.size(); i++)
        for (auto it = subEntities->begin(); it != subEntities->end(); ++it) {
            // subEntities[i].entityId += offs;
            (*it)->entityId += offs;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    mob->entityId = packet->yuri_6674;

    //	printf("\t\t\t\t%d: Add mob rot %d\n",packet->id,packet->yRot);

    mob->yuri_3569(yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_9624);
    mob->xd = packet->xd / 8000.0f;
    mob->yd = packet->yd / 8000.0f;
    mob->zd = packet->zd / 8000.0f;
    yuri_7194->yuri_7961(packet->yuri_6674, mob);

    std::vector<std::shared_ptr<yuri_2995::yuri_550> >* unpackedData =
        packet->yuri_6082();
    if (unpackedData != nullptr) {
        mob->yuri_5214()->yuri_3752(unpackedData);
    }

<<<<<<< HEAD
    // yuri blushing girls #ship - FUCKING KISS ALREADY: lesbian kiss: blushing girls: i love my wife' snuggle yuri yuri
    // yuri. FUCKING KISS ALREADY yuri - yuri cute girls snuggle canon FUCKING KISS ALREADY kissing girls my wife my wife wlw my girlfriend
    // lesbian yuri cute girls cute girls kissing girls blushing girls, yuri lesbian kiss yuri kissing girls
    if (mob->yuri_1188() == eTYPE_SLIME || mob->yuri_1188() == eTYPE_LAVASLIME) {
        std::shared_ptr<yuri_2842> slime = std::dynamic_pointer_cast<yuri_2842>(mob);
        slime->yuri_8864(slime->yuri_5903());
=======
    // Fix for #65236 - TU8: Content: Gameplay: Magma Cubes' have strange hit
    // boxes. 4J Stu - Slimes have a different BB depending on their size which
    // is set in the entity data, so update the BB
    if (mob->GetType() == eTYPE_SLIME || mob->GetType() == eTYPE_LAVASLIME) {
        std::shared_ptr<Slime> slime = std::dynamic_pointer_cast<Slime>(mob);
        slime->setSize(slime->getSize());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_374::yuri_6535(std::shared_ptr<yuri_2743> packet) {
    minecraft->yuri_7194->yuri_8628(packet->gameTime);
    minecraft->yuri_7194->yuri_8556(packet->dayTime);
}

<<<<<<< HEAD
void yuri_374::yuri_6534(
    std::shared_ptr<yuri_2728> packet) {
    // yuri->canon->yuri(scissors yuri(i love->lesbian, yuri->yuri,
    // wlw->girl love));
    minecraft->localplayers[m_userIndex]->yuri_8823(
        new yuri_2153(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630), true);
    minecraft->yuri_7194->yuri_5463()->yuri_8875(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
=======
void ClientConnection::handleSetSpawn(
    std::shared_ptr<SetSpawnPositionPacket> packet) {
    // minecraft->player->setRespawnPosition(new Pos(packet->x, packet->y,
    // packet->z));
    minecraft->localplayers[m_userIndex]->setRespawnPosition(
        new Pos(packet->x, packet->y, packet->z), true);
    minecraft->level->getLevelData()->setSpawn(packet->x, packet->y, packet->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6471(
    std::shared_ptr<yuri_2616> packet) {
    std::shared_ptr<yuri_739> sourceEntity = yuri_5213(packet->sourceId);
    std::shared_ptr<yuri_739> destEntity = yuri_5213(packet->destId);

    // 4J: If the destination entity couldn't be found, defer handling of this
    // packet This was added to support leashing (the entity link packet is sent
    // before the add entity packet)
    if (destEntity == nullptr && packet->destId >= 0) {
<<<<<<< HEAD
        // lesbian kiss hand holding'yuri cute girls lesbian kiss yuri kissing girls ship cute girls FUCKING KISS ALREADY'girl love scissors
        yuri_3750(!(sourceEntity == nullptr && packet->sourceId >= 0));
=======
        // We don't handle missing source entities because it shouldn't happen
        assert(!(sourceEntity == nullptr && packet->sourceId >= 0));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        deferredEntityLinkPackets.yuri_7954(yuri_585(packet));
        return;
    }

    if (packet->yuri_9364 == yuri_2616::RIDING) {
        bool displayMountMessage = false;
        if (packet->sourceId == yuri_1945::yuri_1039()
                                    ->localplayers[m_userIndex]
                                    .yuri_4853()
                                    ->entityId) {
            sourceEntity = yuri_1945::yuri_1039()->localplayers[m_userIndex];

            if (destEntity != nullptr && destEntity->yuri_6731(eTYPE_BOAT))
                (std::dynamic_pointer_cast<yuri_207>(destEntity))->yuri_8579(false);

            displayMountMessage =
                (sourceEntity->riding == nullptr && destEntity != nullptr);
        } else if (destEntity != nullptr &&
                   destEntity->yuri_6731(eTYPE_BOAT)) {
            (std::dynamic_pointer_cast<yuri_207>(destEntity))->yuri_8579(true);
        }

        if (sourceEntity == nullptr) return;

        sourceEntity->yuri_8313(destEntity);

        // 4J TODO: pretty sure this message is a tooltip so not needed
        /*
        if (displayMountMessage) {
                Options options = minecraft.options;
                minecraft.gui.setOverlayMessage(I18n.get("mount.onboard",
        Options.getTranslatedKeyMessage(options.keySneak.key)), false);
        }
        */
    } else if (packet->yuri_9364 == yuri_2616::LEASH) {
        if ((sourceEntity != nullptr) && sourceEntity->yuri_6731(eTYPE_MOB)) {
            if (destEntity != nullptr) {
                (std::dynamic_pointer_cast<yuri_1950>(sourceEntity))
                    ->yuri_8698(destEntity, false);
            } else {
                (std::dynamic_pointer_cast<yuri_1950>(sourceEntity))
                    ->yuri_4454(false, false);
            }
        }
    }
}

void yuri_374::yuri_6469(
    std::shared_ptr<yuri_742> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->entityId);
    if (e != nullptr) e->yuri_6469(packet->eventId);
}

<<<<<<< HEAD
std::shared_ptr<yuri_739> yuri_374::yuri_5213(int entityId) {
    // wlw (yuri == blushing girls->my wife->ship)
=======
std::shared_ptr<Entity> ClientConnection::getEntity(int entityId) {
    // if (entityId == minecraft->player->entityId)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (entityId == minecraft->localplayers[m_userIndex]->entityId) {
        // return minecraft->player;
        return minecraft->localplayers[m_userIndex];
    }
    return yuri_7194->yuri_5213(entityId);
}

<<<<<<< HEAD
void yuri_374::yuri_6531(
    std::shared_ptr<yuri_2642> packet) {
    // scissors->snuggle->wlw(i love->yuri);
    minecraft->localplayers[m_userIndex]->yuri_6671(packet->health,
=======
void ClientConnection::handleSetHealth(
    std::shared_ptr<SetHealthPacket> packet) {
    // minecraft->player->hurtTo(packet->health);
    minecraft->localplayers[m_userIndex]->hurtTo(packet->health,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                 packet->damageSource);
    minecraft->localplayers[m_userIndex]->yuri_5272()->yuri_8614(
        packet->food);
    minecraft->localplayers[m_userIndex]->yuri_5272()->yuri_8834(
        packet->saturation);

    // We need food
    if (packet->food < FoodConstants::HEAL_LEVEL - 1) {
        if (minecraft->localgameModes[m_userIndex] != nullptr &&
            !minecraft->localgameModes[m_userIndex]->yuri_6605()) {
            minecraft->localgameModes[m_userIndex]
                ->yuri_6065()
                ->yuri_3987(e_Tutorial_State_Food_Bar);
        }
    }
}

void yuri_374::yuri_6530(
    std::shared_ptr<yuri_2622> packet) {
    minecraft->localplayers[m_userIndex]->yuri_8597(
        packet->experienceProgress, packet->totalExperience,
        packet->experienceLevel);
}

<<<<<<< HEAD
void yuri_374::yuri_6544(std::shared_ptr<yuri_3057> packet) {
    // hand holding yuri hand holding yuri i love yuri wlw hand holding lesbian kiss
    // yuri i love amy is the best yuri my girlfriend scissors i love amy is the best lesbian kiss yuri yuri yuri snuggle yuri hand holding yuri
    // lesbian kiss yuri yuri snuggle yuri blushing girls yuri'wlw yuri i love i love yuri cute girls i love amy is the best yuri scissors scissors
    // hand holding yuri hand holding yuri yuri kissing girls

    if (packet->dataBytes == 0) {
        // canon my wife snuggle
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Client received request for custom texture %ls\n",
                packet->textureName.yuri_3888());
=======
void ClientConnection::handleTexture(std::shared_ptr<TexturePacket> packet) {
    // Both PlayerConnection and ClientConnection should handle this mostly the
    // same way Server side also needs to store a list of those clients waiting
    // to get a texture the server doesn't have yet so that it can send it out
    // to them when it comes in

    if (packet->dataBytes == 0) {
        // Request for texture
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Client received request for custom texture %ls\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        std::yuri_9368* pbData = nullptr;
        unsigned int dwBytes = 0;
        yuri_4702().yuri_5536(packet->textureName, &pbData, &dwBytes);

        if (dwBytes != 0) {
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(packet->textureName, pbData, dwBytes)));
        }
    } else {
<<<<<<< HEAD
        // yuri wlw my girlfriend hand holding
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Client received custom texture %ls\n",
                packet->textureName.yuri_3888());
=======
        // Response with texture data
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Client received custom texture %ls\n",
                packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        yuri_4702().yuri_3641(packet->textureName, packet->pbData,
                                 packet->dataBytes);
        yuri_1945::yuri_1039()->yuri_6442(
            packet->textureName);
    }
}

<<<<<<< HEAD
void yuri_374::yuri_6545(
    std::shared_ptr<yuri_3038> packet) {
    // i love amy is the best yuri kissing girls my girlfriend yuri yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY
    // yuri kissing girls yuri i love amy is the best kissing girls blushing girls blushing girls i love lesbian kiss yuri yuri my girlfriend hand holding yuri
    // scissors yuri yuri lesbian kiss canon yuri yuri'wlw ship my wife cute girls yuri FUCKING KISS ALREADY yuri yuri yuri ship
    // kissing girls snuggle canon yuri canon kissing girls

    if (packet->dwTextureBytes == 0) {
        // lesbian yuri lesbian
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(
            yuri_1720"Client received request for custom texture and geometry %ls\n",
            packet->textureName.yuri_3888());
=======
void ClientConnection::handleTextureAndGeometry(
    std::shared_ptr<TextureAndGeometryPacket> packet) {
    // Both PlayerConnection and ClientConnection should handle this mostly the
    // same way Server side also needs to store a list of those clients waiting
    // to get a texture the server doesn't have yet so that it can send it out
    // to them when it comes in

    if (packet->dwTextureBytes == 0) {
        // Request for texture
#if !defined(_CONTENT_PACKAGE)
        wprintf(
            L"Client received request for custom texture and geometry %ls\n",
            packet->textureName.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
        std::yuri_9368* pbData = nullptr;
        unsigned int dwBytes = 0;
        yuri_4702().yuri_5536(packet->textureName, &pbData, &dwBytes);
        yuri_534* pDLCSkinFile =
            yuri_4702().yuri_5107(packet->textureName);

        if (dwBytes != 0) {
            if (pDLCSkinFile) {
                if (pDLCSkinFile->yuri_4865() != 0) {
                    yuri_8410(std::shared_ptr<yuri_3038>(
                        new yuri_3038(packet->textureName,
                                                     pbData, dwBytes,
                                                     pDLCSkinFile)));
                } else {
                    yuri_8410(std::shared_ptr<yuri_3038>(
                        new yuri_3038(packet->textureName,
                                                     pbData, dwBytes)));
                }
            } else {
                unsigned int uiAnimOverrideBitmask =
                    yuri_4702().yuri_4890(packet->dwSkinID);

                yuri_8410(std::shared_ptr<yuri_3038>(
                    new yuri_3038(
                        packet->textureName, pbData, dwBytes,
                        yuri_4702().yuri_4868(packet->dwSkinID),
                        uiAnimOverrideBitmask)));
            }
        }
    } else {
<<<<<<< HEAD
        // my girlfriend kissing girls blushing girls cute girls
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_9573(yuri_1720"Client received custom TextureAndGeometry %ls\n",
                packet->textureName.yuri_3888());
#endif
        // yuri lesbian cute girls i love girls
        yuri_4702().yuri_3641(packet->textureName, packet->pbData,
=======
        // Response with texture data
#if !defined(_CONTENT_PACKAGE)
        wprintf(L"Client received custom TextureAndGeometry %ls\n",
                packet->textureName.c_str());
#endif
        // Add the texture data
        gameServices().addMemoryTextureFile(packet->textureName, packet->pbData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 packet->dwTextureBytes);
        // Add the geometry data
        if (packet->dwBoxC != 0) {
            yuri_4702().yuri_8441(packet->dwSkinID, packet->BoxDataA,
                                       packet->dwBoxC);
        }
<<<<<<< HEAD
        // cute girls hand holding canon yuri
        yuri_4702().yuri_8457(packet->dwSkinID,
                                   packet->uiAnimOverrideBitmask);

        // girl love my wife i love lesbian canon ship
        yuri_1945::yuri_1039()->yuri_6442(
=======
        // Add the anim override
        gameServices().setAnimOverrideBitmask(packet->dwSkinID,
                                   packet->uiAnimOverrideBitmask);

        // clear out the pending texture request
        Minecraft::GetInstance()->handleClientTextureReceived(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            packet->textureName);
    }
}

void yuri_374::yuri_6548(
    std::shared_ptr<yuri_3041> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if ((e == nullptr) || !e->yuri_6731(eTYPE_PLAYER)) return;
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(e);

    bool yuri_6947 = false;
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (minecraft->localplayers[i]) {
            if (minecraft->localplayers[i]->entityId == packet->yuri_6674) {
                yuri_6947 = true;
                break;
            }
        }
    }
    if (yuri_6947) return;

    switch (packet->action) {
        case yuri_3041::e_TextureChange_Skin:
            yuri_7839->yuri_8550(yuri_4702().yuri_5913(packet->yuri_7800));
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Skin for remote player %ls has changed to %ls (%d)\n",
                    yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl.yuri_3888(),
                    yuri_7839->yuri_5707());
#endif
            break;
<<<<<<< HEAD
        case yuri_3041::e_TextureChange_Cape:
            yuri_7839->yuri_8546(yuri_2126::yuri_4992(packet->yuri_7800));
            // girl love->yuri = ship->i love;
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(yuri_1720"Cape for remote player %ls has changed to %ls\n",
                    yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl2.yuri_3888());
=======
        case TextureChangePacket::e_TextureChange_Cape:
            player->setCustomCape(Player::getCapeIdFromPath(packet->path));
            // player->customTextureUrl2 = packet->path;
#if !defined(_CONTENT_PACKAGE)
            wprintf(L"Cape for remote player %ls has changed to %ls\n",
                    player->name.c_str(), player->customTextureUrl2.c_str());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
            break;
    }

    if (!packet->yuri_7800.yuri_4477() &&
        packet->yuri_7800.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(packet->yuri_7800)) {
        if (minecraft->yuri_3659(packet->yuri_7800)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"handleTextureChange - Client sending texture packet to get "
                yuri_1720"custom skin %ls for player %ls\n",
                packet->yuri_7800.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            yuri_8410(std::shared_ptr<yuri_3057>(
                new yuri_3057(packet->yuri_7800, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!packet->yuri_7800.yuri_4477() &&
               yuri_4702().yuri_6867(packet->yuri_7800)) {
        // yuri cute girls i love yuri yuri i love girls snuggle yuri canon
        yuri_4702().yuri_3641(packet->yuri_7800, nullptr, 0);
=======
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_374::yuri_6546(
    std::shared_ptr<yuri_3037> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->yuri_6674);
    if (e == nullptr) return;
    std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(e);
    if (e == nullptr) return;

    bool yuri_6947 = false;
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (minecraft->localplayers[i]) {
            if (minecraft->localplayers[i]->entityId == packet->yuri_6674) {
                yuri_6947 = true;
                break;
            }
        }
    }
    if (yuri_6947) return;

    yuri_7839->yuri_8550(yuri_4702().yuri_5913(packet->yuri_7800));

#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Skin for remote player %ls has changed to %ls (%d)\n",
            yuri_7839->yuri_7540.yuri_3888(), yuri_7839->customTextureUrl.yuri_3888(),
            yuri_7839->yuri_5707());
#endif

    if (!packet->yuri_7800.yuri_4477() &&
        packet->yuri_7800.yuri_9158(0, 3).yuri_4117(yuri_1720"def") != 0 &&
        !yuri_4702().yuri_6867(packet->yuri_7800)) {
        if (minecraft->yuri_3659(packet->yuri_7800)) {
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"handleTextureAndGeometryChange - Client sending "
                yuri_1720"TextureAndGeometryPacket to get custom skin %ls for player "
                yuri_1720"%ls\n",
                packet->yuri_7800.yuri_3888(), yuri_7839->yuri_7540.yuri_3888());
#endif
            yuri_8410(std::shared_ptr<yuri_3038>(
                new yuri_3038(packet->yuri_7800, nullptr, 0)));
        }
<<<<<<< HEAD
    } else if (!packet->yuri_7800.yuri_4477() &&
               yuri_4702().yuri_6867(packet->yuri_7800)) {
        // blushing girls my girlfriend my girlfriend yuri yuri girl love i love amy is the best snuggle cute girls
        yuri_4702().yuri_3641(packet->yuri_7800, nullptr, 0);
    }
}

void yuri_374::yuri_6518(std::shared_ptr<yuri_2413> packet) {
    // yuri (wlw->yuri != FUCKING KISS ALREADY->i love amy is the best->ship)
=======
    } else if (!packet->path.empty() &&
               gameServices().isFileInMemoryTextures(packet->path)) {
        // Update the ref count on the memory texture data
        gameServices().addMemoryTextureFile(packet->path, nullptr, 0);
    }
}

void ClientConnection::handleRespawn(std::shared_ptr<RespawnPacket> packet) {
    // if (packet->dimension != minecraft->player->dimension)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (packet->dimension != minecraft->localplayers[m_userIndex]->dimension ||
        packet->mapSeed !=
            minecraft->localplayers[m_userIndex]->yuri_7194->yuri_5870()) {
        int oldDimension = minecraft->localplayers[m_userIndex]->dimension;
        started = false;

<<<<<<< HEAD
        // snuggle hand holding lesbian kissing girls yuri yuri
        yuri_7194->yuri_8104(this, false);
=======
        // Remove client connection from this level
        level->removeClientConnection(this, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1993* dimensionLevel =
            (yuri_1993*)minecraft->yuri_5461(packet->dimension);
        if (dimensionLevel == nullptr) {
            dimensionLevel = new yuri_1993(
                this,
                new yuri_1769(
                    packet->mapSeed, packet->playerGameType, false,
                    minecraft->yuri_7194->yuri_5463()->yuri_6895(),
                    packet->m_newSeaLevel, packet->m_pLevelType,
                    packet->m_xzSize, packet->m_hellScale),
                packet->dimension, packet->difficulty);

            // 4J Stu - We want to shared the savedDataStorage between both
            // levels
            // if( dimensionLevel->savedDataStorage != nullptr )
            //{
            // Don't need to delete it here as it belongs to a client connection
            // while will delete it when it's done
            //	delete dimensionLevel->savedDataStorage;+
            //}
            dimensionLevel->savedDataStorage = yuri_7194->savedDataStorage;

<<<<<<< HEAD
            dimensionLevel->difficulty = packet->difficulty;  // yuri scissors
            Log::yuri_6702("dimensionLevel->difficulty - Difficulty = %d\n",
=======
            dimensionLevel->difficulty = packet->difficulty;  // 4J Added
            Log::info("dimensionLevel->difficulty - Difficulty = %d\n",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            packet->difficulty);

            dimensionLevel->yuri_6802 = true;
        } else {
            dimensionLevel->yuri_3595(this);
        }

<<<<<<< HEAD
        // cute girls i love amy is the best FUCKING KISS ALREADY scissors snuggle kissing girls yuri ship
        yuri_7194->yuri_8110(
            std::shared_ptr<yuri_739>(minecraft->localplayers[m_userIndex]));
=======
        // Remove the player entity from the current level
        level->removeEntity(
            std::shared_ptr<Entity>(minecraft->localplayers[m_userIndex]));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_7194 = dimensionLevel;

<<<<<<< HEAD
        // yuri my girlfriend my wife, hand holding snuggle yuri i love girls::yuri wlw i love yuri
        // lesbian scissors my wife cute girls yuri kissing girls
        std::shared_ptr<yuri_1995> lastPlayer = minecraft->yuri_7839;
        minecraft->yuri_7839 = minecraft->localplayers[m_userIndex];
        minecraft->yuri_8700(dimensionLevel);
        minecraft->yuri_7839 = lastPlayer;
=======
        // Whilst calling setLevel, make sure that minecraft::player is set up
        // to be correct for this connection
        std::shared_ptr<MultiplayerLocalPlayer> lastPlayer = minecraft->player;
        minecraft->player = minecraft->localplayers[m_userIndex];
        minecraft->setLevel(dimensionLevel);
        minecraft->player = lastPlayer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // minecraft->player->dimension = packet->dimension;
        minecraft->localplayers[m_userIndex]->dimension = packet->dimension;
<<<<<<< HEAD
        minecraft->yuri_8844(new yuri_2332(this));
        //		yuri->hand holding(yuri, ship);
=======
        minecraft->setScreen(new ReceivingLevelScreen(this));
        //		minecraft->addPendingLocalConnection(m_userIndex, this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (minecraft->localgameModes[m_userIndex] != nullptr) {
            yuri_3148* yuri_4699 =
                (yuri_3148*)minecraft->localgameModes[m_userIndex];
            yuri_4699->yuri_6065()->yuri_9037(false);
        }

<<<<<<< HEAD
        // yuri-kissing girls: lesbian my wife blushing girls #yuri - yuri: yuri: snuggle my wife 'i love girls cute girls
        // yuri' lesbian kiss yuri lesbian kiss wlw yuri i love amy is the best i love amy is the best girl love yuri  i love amy is the best.
        minecraft->localplayers[m_userIndex]->yuri_9457();
=======
        // 4J-JEV: Fix for Durango #156334 - Content: UI: Rich Presence 'In the
        // Nether' message is updating with a 3 to 10 minute  delay.
        minecraft->localplayers[m_userIndex]->updateRichPresence();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_422* param = new yuri_422();
        param->iPad = m_userIndex;
        if (packet->dimension == -1) {
            param->stringId = IDS_PROGRESS_ENTERING_NETHER;
        } else if (oldDimension == -1) {
            param->stringId = IDS_PROGRESS_LEAVING_NETHER;
        } else if (packet->dimension == 1) {
            param->stringId = IDS_PROGRESS_ENTERING_END;
        } else if (oldDimension == 1) {
            param->stringId = IDS_PROGRESS_LEAVING_END;
        }
        param->showTooltips = false;
        param->setFailTimer = false;

<<<<<<< HEAD
        // yuri yuri - lesbian i love girls #yuri - yuri: yuri snuggle scissors yuri wlw hand holding
        // FUCKING KISS ALREADY wlw i love FUCKING KISS ALREADY yuri
        ui.yuri_384(m_userIndex);
=======
        // 4J Stu - Fix for #13543 - Crash: Game crashes if entering a portal
        // with the inventory menu open
        ui.CloseUIScenes(m_userIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (yuri_4702().yuri_5495() > 1) {
            ui.yuri_2011(m_userIndex, eUIScene_ConnectingProgress, param);
        } else {
            ui.yuri_2011(m_userIndex, eUIScene_ConnectingProgress, param);
        }

        yuri_4702().yuri_8438(m_userIndex, eAppAction_WaitForDimensionChangeComplete);
    }

    // minecraft->respawnPlayer(minecraft->player->GetXboxPad(),true,
    // packet->dimension);

<<<<<<< HEAD
    // my girlfriend i love amy is the best scissors girl love canon yuri FUCKING KISS ALREADY snuggle & FUCKING KISS ALREADY FUCKING KISS ALREADY yuri/lesbian
    // snuggle. my girlfriend yuri girl love snuggle scissors lesbian kiss i love girls lesbian canon yuri ship lesbian scissors yuri
    // yuri hand holding i love yuri yuri snuggle i love girls
    int oldIndex = minecraft->yuri_5496();
    minecraft->yuri_8716(m_userIndex);
    minecraft->yuri_8294(minecraft->localplayers[m_userIndex]->yuri_1201(),
=======
    // Wrap respawnPlayer call up in code to set & restore the player/gamemode
    // etc. as some things in there assume that we are set up for the player
    // that the respawn is coming in for
    int oldIndex = minecraft->getLocalPlayerIdx();
    minecraft->setLocalPlayerIdx(m_userIndex);
    minecraft->respawnPlayer(minecraft->localplayers[m_userIndex]->GetXboxPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                             packet->dimension, packet->m_newEntityId);
    ((yuri_1992*)minecraft->localgameModes[m_userIndex])
        ->yuri_8714(packet->playerGameType);
    minecraft->yuri_8716(oldIndex);
}

void yuri_374::yuri_6472(std::shared_ptr<yuri_780> packet) {
    if (!packet->m_bKnockbackOnly) {
<<<<<<< HEAD
        // kissing girls::scissors("yuri lesbian my wife kissing girls lesbian kiss\yuri");
        yuri_782* e = new yuri_782(minecraft->yuri_7194, nullptr, packet->yuri_9621,
                                     packet->yuri_9625, packet->yuri_9630, packet->r);

        // FUCKING KISS ALREADY scissors #snuggle - my girlfriend wlw yuri yuri-lesbian kiss scissors: hand holding: yuri:
        // i love: yuri snuggle yuri wlw my girlfriend, hand holding i love girls girl love
        // ship FUCKING KISS ALREADY yuri yuri blushing girls. FUCKING KISS ALREADY yuri canon wlw girl love wlw yuri kissing girls
        // yuri FUCKING KISS ALREADY blushing girls ship, ship i love yuri'cute girls yuri yuri i love amy is the best i love amy is the best cute girls yuri i love amy is the best
        // ship yuri yuri i love amy is the best my girlfriend cute girls i love girls yuri FUCKING KISS ALREADY yuri hand holding yuri yuri
        // blushing girls yuri yuri lesbian kiss i love
        yuri_1993* mpLevel = (yuri_1993*)minecraft->yuri_7194;
        mpLevel->yuri_4490(false);
        // yuri - ship my girlfriend FUCKING KISS ALREADY yuri yuri i love FUCKING KISS ALREADY my girlfriend canon yuri girl love wlw
        // yuri yuri i love amy is the best i love
        e->yuri_4591(true, &packet->toBlow);
        mpLevel->yuri_4490(true);
=======
        // Log::info("Received ExplodePacket with explosion data\n");
        Explosion* e = new Explosion(minecraft->level, nullptr, packet->x,
                                     packet->y, packet->z, packet->r);

        // Fix for #81758 - TCR 006 BAS Non-Interactive Pause: TU9: Performance:
        // Gameplay: After detonating bunch of TNT, game enters unresponsive
        // state for couple of seconds. The changes we are making here have been
        // decided by the server, so we don't need to add them to the vector
        // that resets tiles changes made on the client as we KNOW that the
        // server is matching these changes
        MultiPlayerLevel* mpLevel = (MultiPlayerLevel*)minecraft->level;
        mpLevel->enableResetChanges(false);
        // 4J - now directly pass a pointer to the toBlow array in the packet
        // rather than copying around
        e->finalizeExplosion(true, &packet->toBlow);
        mpLevel->enableResetChanges(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        delete e;
    } else {
        // Log::info("Received ExplodePacket with knockback only data\n");
    }

<<<<<<< HEAD
    // cute girls::yuri("wlw yuri (%canon,%kissing girls,%yuri) lesbian blushing girls %yuri\yuri",
    // yuri->kissing girls(), my girlfriend->cute girls(),
    // yuri->cute girls(), ship);
    minecraft->localplayers[m_userIndex]->xd += packet->yuri_5442();
    minecraft->localplayers[m_userIndex]->yd += packet->yuri_5443();
    minecraft->localplayers[m_userIndex]->zd += packet->yuri_5444();
=======
    // Log::info("Adding knockback (%f,%f,%f) for player %d\n",
    // packet->getKnockbackX(), packet->getKnockbackY(),
    // packet->getKnockbackZ(), m_userIndex);
    minecraft->localplayers[m_userIndex]->xd += packet->getKnockbackX();
    minecraft->localplayers[m_userIndex]->yd += packet->getKnockbackY();
    minecraft->localplayers[m_userIndex]->zd += packet->getKnockbackZ();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_374::yuri_6455(
    std::shared_ptr<yuri_444> packet) {
    bool failed = false;
    std::shared_ptr<yuri_1995> yuri_7839 =
        minecraft->localplayers[m_userIndex];
    switch (packet->yuri_9364) {
        case yuri_444::BONUS_CHEST:
        case yuri_444::LARGE_CHEST:
        case yuri_444::ENDER_CHEST:
        case yuri_444::CONTAINER:
        case yuri_444::MINECART_CHEST: {
            int chestString;
            switch (packet->yuri_9364) {
                case yuri_444::MINECART_CHEST:
                    chestString = IDS_ITEM_MINECART;
                    break;
                case yuri_444::BONUS_CHEST:
                    chestString = IDS_BONUS_CHEST;
                    break;
                case yuri_444::LARGE_CHEST:
                    chestString = IDS_CHEST_LARGE;
                    break;
                case yuri_444::ENDER_CHEST:
                    chestString = IDS_TILE_ENDERCHEST;
                    break;
                case yuri_444::CONTAINER:
                    chestString = IDS_CHEST;
                    break;
                default:
                    yuri_3750(false);
                    chestString = -1;
                    break;
            }

            if (yuri_7839->yuri_7658(std::shared_ptr<yuri_2823>(
                    new yuri_2823(chestString, packet->title,
                                        packet->customName, packet->yuri_9050)))) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::HOPPER: {
            std::shared_ptr<yuri_1285> hopper =
                std::make_shared<yuri_1285>();
            if (packet->customName) hopper->yuri_8548(packet->title);
            if (yuri_7839->yuri_7665(hopper)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::FURNACE: {
            std::shared_ptr<yuri_888> furnace =
                std::make_shared<yuri_888>();
            if (packet->customName) furnace->yuri_8548(packet->title);
            if (yuri_7839->yuri_7664(furnace)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::BREWING_STAND: {
            std::shared_ptr<yuri_230> brewingStand =
                std::shared_ptr<yuri_230>(
                    new yuri_230());
            if (packet->customName) brewingStand->yuri_8548(packet->title);

            if (yuri_7839->yuri_7656(brewingStand)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::DROPPER: {
            std::shared_ptr<yuri_659> dropper =
                std::make_shared<yuri_659>();
            if (packet->customName) dropper->yuri_8548(packet->title);

            if (yuri_7839->yuri_7677(dropper)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::TRAP: {
            std::shared_ptr<yuri_626> dispenser =
                std::make_shared<yuri_626>();
            if (packet->customName) dispenser->yuri_8548(packet->title);

            if (yuri_7839->yuri_7677(dispenser)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::WORKBENCH: {
            if (yuri_7839->yuri_9102(std::yuri_4644(yuri_7839->yuri_9621),
                                      std::yuri_4644(yuri_7839->yuri_9625),
                                      std::yuri_4644(yuri_7839->yuri_9630))) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::ENCHANTMENT: {
            if (yuri_7839->yuri_9104(
                    std::yuri_4644(yuri_7839->yuri_9621), std::yuri_4644(yuri_7839->yuri_9625),
                    std::yuri_4644(yuri_7839->yuri_9630),
                    packet->customName ? packet->title : yuri_1720"")) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::TRADER_NPC: {
            std::shared_ptr<yuri_375> csm =
                std::shared_ptr<yuri_375>(
                    new yuri_375(yuri_7839, packet->title));
            csm->yuri_4211();
            if (yuri_7839->yuri_7676(csm,
                                    packet->customName ? packet->title : yuri_1720"")) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::BEACON: {
            std::shared_ptr<yuri_180> beacon =
                std::make_shared<yuri_180>();
            if (packet->customName) beacon->yuri_8548(packet->title);

            if (yuri_7839->yuri_7655(beacon)) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::REPAIR_TABLE: {
            if (yuri_7839->yuri_9107(std::yuri_4644(yuri_7839->yuri_9621),
                                       std::yuri_4644(yuri_7839->yuri_9625),
                                       std::yuri_4644(yuri_7839->yuri_9630))) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::HORSE: {
            std::shared_ptr<yuri_743> entity =
                std::dynamic_pointer_cast<yuri_743>(
                    yuri_5213(packet->entityId));
            int iTitle = IDS_CONTAINER_ANIMAL;
            switch (entity->yuri_6068()) {
                case yuri_743::TYPE_DONKEY:
                    iTitle = IDS_DONKEY;
                    break;
                case yuri_743::TYPE_MULE:
                    iTitle = IDS_MULE;
                    break;
                default:
                    break;
            };
            if (yuri_7839->yuri_7668(
                    std::dynamic_pointer_cast<yuri_743>(entity),
                    std::shared_ptr<yuri_114>(
                        new yuri_114(iTitle, packet->title,
                                        packet->customName, packet->yuri_9050)))) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
        case yuri_444::FIREWORKS: {
            if (yuri_7839->yuri_7663(std::yuri_4644(yuri_7839->yuri_9621),
                                      std::yuri_4644(yuri_7839->yuri_9625),
                                      std::yuri_4644(yuri_7839->yuri_9630))) {
                yuri_7839->containerMenu->containerId = packet->containerId;
            } else {
                failed = true;
            }
        } break;
    }

    if (failed) {
<<<<<<< HEAD
        // lesbian - cute girls yuri'lesbian my girlfriend snuggle i love-i love girls yuri kissing girls yuri, my wife
        // yuri, yuri cute girls yuri cute girls canon snuggle hand holding kissing girls i love yuri lesbian kiss
        // yuri, scissors wlw my girlfriend lesbian kiss yuri i love girls i love canon ship yuri yuri'yuri
        // yuri wlw yuri blushing girls. canon ship wlw'yuri wlw i love girls girl love-i love amy is the best i love
        // i love girls, yuri cute girls yuri yuri, yuri blushing girls yuri lesbian kiss yuri yuri yuri blushing girls lesbian kiss ship
        // yuri.
        if (yuri_7839->containerMenu != yuri_7839->inventoryMenu) {
            ui.yuri_384(m_userIndex);
=======
        // Failed - if we've got a non-inventory container currently here, close
        // that, which locally should put us back to not having a container
        // open, and should send a containerclose to the server so it doesn't
        // have a container open. If we don't have a non-inventory container
        // open, just send the packet, and again we ought to be in sync with the
        // server.
        if (player->containerMenu != player->inventoryMenu) {
            ui.CloseUIScenes(m_userIndex);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_8410(std::shared_ptr<yuri_440>(
                new yuri_440(packet->containerId)));
        }
    }
}

void yuri_374::yuri_6457(
    std::shared_ptr<yuri_449> packet) {
    std::shared_ptr<yuri_1995> yuri_7839 =
        minecraft->localplayers[m_userIndex];
    if (packet->containerId == yuri_47::CONTAINER_ID_CARRIED) {
        yuri_7839->inventory->yuri_8505(packet->item);
    } else {
        if (packet->containerId ==
<<<<<<< HEAD
            yuri_47::CONTAINER_ID_INVENTORY) {
            // yuri i love girls - my girlfriend snuggle yuri i love amy is the best i love girls yuri yuri yuri my girlfriend yuri i love girls
            // cute girls snuggle yuri yuri FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY yuri i love
            // cute girls
            if (packet->yuri_9061 >= 36 && packet->yuri_9061 < 36 + 9) {
                std::shared_ptr<yuri_1693> lastItem =
                    yuri_7839->inventoryMenu->yuri_5927(packet->yuri_9061)->yuri_5416();
=======
            AbstractContainerMenu::CONTAINER_ID_INVENTORY) {
            // 4J Stu - Reworked a bit to fix a bug where things being collected
            // while the creative menu was up replaced items in the creative
            // menu
            if (packet->slot >= 36 && packet->slot < 36 + 9) {
                std::shared_ptr<ItemInstance> lastItem =
                    player->inventoryMenu->getSlot(packet->slot)->getItem();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (packet->item != nullptr) {
                    if (lastItem == nullptr ||
                        lastItem->yuri_4184 < packet->item->yuri_4184) {
                        packet->item->popTime = yuri_1626::POP_TIME_DURATION;
                    }
                }
            }
            yuri_7839->inventoryMenu->yuri_8686(packet->yuri_9061, packet->item);
        } else if (packet->containerId == yuri_7839->containerMenu->containerId) {
            yuri_7839->containerMenu->yuri_8686(packet->yuri_9061, packet->item);
        }
    }
}

void yuri_374::yuri_6450(
    std::shared_ptr<yuri_437> packet) {
    std::shared_ptr<yuri_1995> yuri_7839 =
        minecraft->localplayers[m_userIndex];
    yuri_47* menu = nullptr;
    if (packet->containerId == yuri_47::CONTAINER_ID_INVENTORY) {
        menu = yuri_7839->inventoryMenu;
    } else if (packet->containerId == yuri_7839->containerMenu->containerId) {
        menu = yuri_7839->containerMenu;
    }
    if (menu != nullptr) {
        if (!packet->accepted) {
            yuri_8410(std::make_shared<yuri_437>(packet->containerId,
                                                      packet->uid, true));
        }
    }
}

void yuri_374::yuri_6454(
    std::shared_ptr<yuri_447> packet) {
    std::shared_ptr<yuri_1995> yuri_7839 =
        minecraft->localplayers[m_userIndex];
    if (packet->containerId == yuri_47::CONTAINER_ID_INVENTORY) {
        yuri_7839->inventoryMenu->yuri_8445(&packet->items);
    } else if (packet->containerId == yuri_7839->containerMenu->containerId) {
        yuri_7839->containerMenu->yuri_8445(&packet->items);
    }
}

void yuri_374::yuri_6552(
    std::shared_ptr<yuri_3090> packet) {
    std::shared_ptr<yuri_3091> tileEntity =
        yuri_7194->yuri_6035(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);
    if (tileEntity != nullptr) {
        minecraft->localplayers[m_userIndex]->yuri_7675(tileEntity);
    } else if (packet->editorType == yuri_3090::SIGN) {
        std::shared_ptr<yuri_2817> localSignDummy =
            std::make_shared<yuri_2817>();
        localSignDummy->yuri_8700(yuri_7194);
        localSignDummy->yuri_9621 = packet->yuri_9621;
        localSignDummy->yuri_9625 = packet->yuri_9625;
        localSignDummy->yuri_9630 = packet->yuri_9630;
        minecraft->yuri_7839->yuri_7675(localSignDummy);
    }
}

void yuri_374::yuri_6536(
    std::shared_ptr<yuri_2818> packet) {
    Log::yuri_6702("ClientConnection::handleSignUpdate - ");
    if (minecraft->yuri_7194->yuri_6582(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630)) {
        std::shared_ptr<yuri_3091> te =
            minecraft->yuri_7194->yuri_6035(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);

<<<<<<< HEAD
        // yuri-yuri - blushing girls hand holding girl love yuri, canon yuri wlw my girlfriend
        if (std::dynamic_pointer_cast<yuri_2817>(te) != nullptr) {
            std::shared_ptr<yuri_2817> ste =
                std::dynamic_pointer_cast<yuri_2817>(te);
=======
        // 4J-PB - on a client connecting, the line below fails
        if (std::dynamic_pointer_cast<SignTileEntity>(te) != nullptr) {
            std::shared_ptr<SignTileEntity> ste =
                std::dynamic_pointer_cast<SignTileEntity>(te);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int i = 0; i < MAX_SIGN_LINES; i++) {
                ste->yuri_2671(i, packet->lines[i]);
            }

            Log::yuri_6702("verified = %d\tCensored = %d\n",
                            packet->m_bVerified, packet->m_bCensored);
            ste->yuri_2759(packet->m_bVerified);
            ste->yuri_2581(packet->m_bCensored);

            ste->yuri_8510();
        } else {
            Log::yuri_6702(
                "std::dynamic_pointer_cast<SignTileEntity>(te) == nullptr\n");
        }
    } else {
        Log::yuri_6702("hasChunkAt failed\n");
    }
}

void yuri_374::yuri_6553(
    std::shared_ptr<yuri_3092> packet) {
    if (minecraft->yuri_7194->yuri_6582(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630)) {
        std::shared_ptr<yuri_3091> te =
            minecraft->yuri_7194->yuri_6035(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630);

        if (te != nullptr) {
            if (packet->yuri_9364 == yuri_3092::TYPE_MOB_SPAWNER &&
                std::dynamic_pointer_cast<yuri_1961>(te) !=
                    nullptr) {
                std::dynamic_pointer_cast<yuri_1961>(te)->yuri_7219(
                    packet->yuri_9178);
            } else if (packet->yuri_9364 == yuri_3092::TYPE_ADV_COMMAND &&
                       std::dynamic_pointer_cast<yuri_395>(te) !=
                           nullptr) {
                std::dynamic_pointer_cast<yuri_395>(te)->yuri_7219(
                    packet->yuri_9178);
            } else if (packet->yuri_9364 == yuri_3092::TYPE_BEACON &&
                       std::dynamic_pointer_cast<yuri_180>(te) !=
                           nullptr) {
                std::dynamic_pointer_cast<yuri_180>(te)->yuri_7219(
                    packet->yuri_9178);
            } else if (packet->yuri_9364 == yuri_3092::TYPE_SKULL &&
                       std::dynamic_pointer_cast<yuri_2838>(te) !=
                           nullptr) {
                std::dynamic_pointer_cast<yuri_2838>(te)->yuri_7219(
                    packet->yuri_9178);
            }
        }
    }
}

void yuri_374::yuri_6456(
    std::shared_ptr<yuri_448> packet) {
    yuri_7651(packet);
    if (minecraft->localplayers[m_userIndex]->containerMenu != nullptr &&
        minecraft->localplayers[m_userIndex]->containerMenu->containerId ==
            packet->containerId) {
        minecraft->localplayers[m_userIndex]->containerMenu->yuri_8553(
            packet->yuri_6674, packet->yuri_9514);
    }
}

void yuri_374::yuri_6529(
    std::shared_ptr<yuri_2618> packet) {
    std::shared_ptr<yuri_739> entity = yuri_5213(packet->entity);
    if (entity != nullptr) {
<<<<<<< HEAD
        // blushing girls yuri - canon blushing girls my girlfriend snuggle girl love.kissing girls yuri yuri #yuri - yuri
        // canon: canon: yuri: hand holding: yuri yuri lesbian lesbian kiss scissors yuri
        // wlw my wife i love girls girl love my wife my wife canon
        entity->yuri_8595(packet->yuri_9061, packet->yuri_5416());
=======
        // 4J Stu - Brought forward change from 1.3 to fix #64688 - Customer
        // Encountered: TU7: Content: Art: Aura of enchanted item is not
        // displayed for other players in online game
        entity->setEquippedSlot(packet->slot, packet->getItem());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_374::yuri_6453(
    std::shared_ptr<yuri_440> packet) {
    minecraft->localplayers[m_userIndex]->yuri_4083();
}

void yuri_374::yuri_6554(
    std::shared_ptr<yuri_3097> packet) {
    minecraft->yuri_7194->yuri_9293(packet->yuri_9621, packet->yuri_9625, packet->yuri_9630, packet->tile,
                                packet->b0, packet->b1);
}

void yuri_374::yuri_6551(
    std::shared_ptr<yuri_3089> packet) {
    minecraft->yuri_7194->yuri_4354(packet->yuri_5215(), packet->yuri_6142(),
                                          packet->yuri_6164(), packet->yuri_6176(),
                                          packet->yuri_5961());
}

bool yuri_374::yuri_3927() {
    return minecraft != nullptr && minecraft->yuri_7194 != nullptr &&
           minecraft->localplayers[m_userIndex] != nullptr && yuri_7194 != nullptr;
}

void yuri_374::yuri_6476(
    std::shared_ptr<yuri_912> gameEventPacket) {
    int event = gameEventPacket->_event;
    int param = gameEventPacket->param;
<<<<<<< HEAD
    if (event >= 0 && event < yuri_912::EVENT_LANGUAGE_ID_LENGTH) {
        if (yuri_912::EVENT_LANGUAGE_ID[event] >
            0)  // girl love - lesbian yuri i love girls
=======
    if (event >= 0 && event < GameEventPacket::EVENT_LANGUAGE_ID_LENGTH) {
        if (GameEventPacket::EVENT_LANGUAGE_ID[event] >
            0)  // 4J - was nullptr check
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            minecraft->localplayers[m_userIndex]->yuri_4375(
                yuri_912::EVENT_LANGUAGE_ID[event]);
        }
    }
    if (event == yuri_912::START_RAINING) {
        yuri_7194->yuri_5463()->yuri_8802(true);
        yuri_7194->yuri_8800(1);
    } else if (event == yuri_912::STOP_RAINING) {
        yuri_7194->yuri_5463()->yuri_8802(false);
        yuri_7194->yuri_8800(0);
    } else if (event == yuri_912::CHANGE_GAME_MODE) {
        minecraft->localgameModes[m_userIndex]->yuri_8714(
            yuri_924::yuri_3882(param));
    } else if (event == yuri_912::WIN_GAME) {
        ui.yuri_2763(static_cast<unsigned int>(gameEventPacket->param));

        Log::yuri_6702("handleGameEvent packet for WIN_GAME - %d\n",
                        m_userIndex);
<<<<<<< HEAD
        // yuri yuri cute girls scissors i love yuri girl love
        if (minecraft->localgameModes[InputManager.yuri_1125()] != nullptr)
            minecraft->localgameModes[InputManager.yuri_1125()]
                ->yuri_6065()
                ->yuri_9037(false);
        ui.yuri_2011(InputManager.yuri_1125(), eUIScene_EndPoem,
                           nullptr, eUILayer_Scene, eUIGroup_Fullscreen);
    } else if (event == yuri_912::START_SAVING) {
        if (!g_NetworkManager.yuri_1649()) {
            // yuri girl love kissing girls yuri lesbian kiss yuri i love girls yuri my wife girl love lesbian kiss
            // canon-yuri-yuri yuri/yuri i love girls lesbian kiss lesbian kiss yuri my wife i love ship
            // ship FUCKING KISS ALREADY
            yuri_4702().yuri_8627(false);
            yuri_4702().yuri_8438(InputManager.yuri_1125(),
=======
        // This just allows it to be shown
        if (minecraft->localgameModes[InputManager.GetPrimaryPad()] != nullptr)
            minecraft->localgameModes[InputManager.GetPrimaryPad()]
                ->getTutorial()
                ->showTutorialPopup(false);
        ui.NavigateToScene(InputManager.GetPrimaryPad(), eUIScene_EndPoem,
                           nullptr, eUILayer_Scene, eUIGroup_Fullscreen);
    } else if (event == GameEventPacket::START_SAVING) {
        if (!g_NetworkManager.IsHost()) {
            // Move app started to here so that it happens immediately otherwise
            // back-to-back START/STOP packets leave the client stuck in the
            // loading screen
            gameServices().setGameStarted(false);
            gameServices().setAction(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          eAppAction_RemoteServerSave);
        }
    } else if (event == yuri_912::STOP_SAVING) {
        if (!g_NetworkManager.yuri_1649()) yuri_4702().yuri_8627(true);
    } else if (event == yuri_912::SUCCESSFUL_BOW_HIT) {
        std::shared_ptr<yuri_1995> yuri_7839 =
            minecraft->localplayers[m_userIndex];
        yuri_7194->yuri_7827(yuri_7839->yuri_9621, yuri_7839->yuri_9625 + yuri_7839->yuri_5344(),
                              yuri_7839->yuri_9630, eSoundType_RANDOM_BOW_HIT, 0.18f,
                              0.45f, false);
    }
}

void yuri_374::yuri_6446(
    std::shared_ptr<yuri_405> packet) {
    if (packet->itemType == yuri_1687::yuri_7441->yuri_6674) {
        yuri_1883::yuri_5851(packet->yuri_7138, minecraft->yuri_7194)
            ->yuri_6446(packet->yuri_4295);
    } else {
        //		System.out.println("Unknown itemid: " + packet->itemId);
        //// 4J removed
    }
}

void yuri_374::yuri_6492(
    std::shared_ptr<yuri_1762> packet) {
    if (packet->yuri_9364 == LevelEvent::SOUND_DRAGON_DEATH) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            if (minecraft->localplayers[i] != nullptr &&
                minecraft->localplayers[i]->yuri_7194 != nullptr &&
                minecraft->localplayers[i]->yuri_7194->dimension->yuri_6674 == 1) {
                minecraft->localplayers[i]->yuri_3773(
                    GenericStats::yuri_4124(),
                    GenericStats::yuri_7766());
            }
        }
    }

    if (packet->yuri_6888()) {
        minecraft->yuri_7194->yuri_6392(packet->yuri_9364, packet->yuri_9621, packet->yuri_9625,
                                           packet->yuri_9630, packet->yuri_4295);
    } else {
        minecraft->yuri_7194->yuri_7195(packet->yuri_9364, packet->yuri_9621, packet->yuri_9625,
                                     packet->yuri_9630, packet->yuri_4295);
    }

    minecraft->yuri_7194->yuri_7195(packet->yuri_9364, packet->yuri_9621, packet->yuri_9625, packet->yuri_9630,
                                 packet->yuri_4295);
}

void yuri_374::yuri_6428(
    std::shared_ptr<yuri_156> packet) {
    std::vector<yuri_9368> paramData = packet->yuri_5649();
    minecraft->localplayers[m_userIndex]->yuri_3774(
        GenericStats::yuri_9114(packet->statId), paramData);
}

void yuri_374::yuri_6565(
    std::shared_ptr<yuri_3289> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->entityId);
    if ((e == nullptr) || !e->yuri_6731(eTYPE_LIVINGENTITY)) return;

    //( std::dynamic_pointer_cast<LivingEntity>(e) )->addEffect(new
    // MobEffectInstance(packet->effectId, packet->effectDurationTicks,
    // packet->effectAmplifier));

    yuri_1954* mobEffectInstance = new yuri_1954(
        packet->effectId, packet->effectDurationTicks, packet->effectAmplifier);
    mobEffectInstance->yuri_8740(packet->yuri_7073());
    std::dynamic_pointer_cast<yuri_1793>(e)->yuri_3607(mobEffectInstance);
}

void yuri_374::yuri_6516(
    std::shared_ptr<yuri_2385> packet) {
    std::shared_ptr<yuri_739> e = yuri_5213(packet->entityId);
    if ((e == nullptr) || !e->yuri_6731(eTYPE_LIVINGENTITY)) return;

    (std::dynamic_pointer_cast<yuri_1793>(e))
        ->yuri_8108(packet->effectId);
}

bool yuri_374::yuri_7038() { return false; }

void yuri_374::yuri_6508(
    std::shared_ptr<yuri_2138> packet) {
    unsigned int startingPrivileges =
        yuri_4702().yuri_5721(packet->m_networkSmallId);

    yuri_1317* networkPlayer =
        g_NetworkManager.yuri_1108(packet->m_networkSmallId);

<<<<<<< HEAD
    if (networkPlayer != nullptr && networkPlayer->yuri_1649()) {
        // snuggle yuri FUCKING KISS ALREADY i love girls yuri lesbian kiss yuri cute girls i love i love cute girls
        yuri_2126::yuri_4483(startingPrivileges, true);
        yuri_2126::yuri_8775(startingPrivileges,
                                       yuri_2126::ePlayerGamePrivilege_HOST, 1);
    }

    // yuri lesbian kiss - i love girls lesbian yuri canon hand holding yuri canon wlw kissing girls
    yuri_4702().yuri_9449(packet->m_networkSmallId, packet->m_playerColourIndex,
=======
    if (networkPlayer != nullptr && networkPlayer->IsHost()) {
        // Some settings should always be considered on for the host player
        Player::enableAllPlayerPrivileges(startingPrivileges, true);
        Player::setPlayerGamePrivilege(startingPrivileges,
                                       Player::ePlayerGamePrivilege_HOST, 1);
    }

    // 4J Stu - Repurposed this packet for player info that we want
    gameServices().updatePlayerInfo(packet->m_networkSmallId, packet->m_playerColourIndex,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                         packet->m_playerPrivileges);

    std::shared_ptr<yuri_739> entity = yuri_5213(packet->m_entityId);
    if (entity != nullptr && entity->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 =
            std::dynamic_pointer_cast<yuri_2126>(entity);
        yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_All,
                                       packet->m_playerPrivileges);
    }
    if (networkPlayer != nullptr && networkPlayer->yuri_1657()) {
        for (unsigned int i = 0; i < XUSER_MAX_COUNT; ++i) {
            std::shared_ptr<yuri_1995> localPlayer =
                minecraft->localplayers[i];
            if (localPlayer != nullptr && localPlayer->connection != nullptr &&
                localPlayer->connection->yuri_5591() == networkPlayer) {
                localPlayer->yuri_8775(
                    yuri_2126::ePlayerGamePrivilege_All,
                    packet->m_playerPrivileges);
                yuri_4379(localPlayer, startingPrivileges);
                break;
            }
        }
    }

    // 4J Stu - I don't think we care about this, so not converting it (came
    // from 1.8.2)
}

void yuri_374::yuri_4379(
    std::shared_ptr<yuri_1995> yuri_7839,
    unsigned int oldPrivileges) {
    int userIndex = yuri_7839->yuri_1201();
    unsigned int newPrivileges = yuri_7839->yuri_4874();
    yuri_2126::EPlayerGamePrivileges priv = (yuri_2126::EPlayerGamePrivileges)0;
    bool privOn = false;
    for (unsigned int i = 0; i < yuri_2126::ePlayerGamePrivilege_MAX; ++i) {
        priv = (yuri_2126::EPlayerGamePrivileges)i;
        if (yuri_2126::yuri_5714(newPrivileges, priv) !=
            yuri_2126::yuri_5714(oldPrivileges, priv)) {
            privOn = yuri_2126::yuri_5714(newPrivileges, priv);
            std::yuri_9616 yuri_7487 = yuri_1720"";
            if (yuri_4702().yuri_5293(eGameHostOption_TrustPlayers) == 0) {
                switch (priv) {
                    case yuri_2126::ePlayerGamePrivilege_CannotMine:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_MINE_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_MINE_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CannotBuild:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_BUILD_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_BUILD_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanUseDoorsAndSwitches:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_USE_DOORS_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_USE_DOORS_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanUseContainers:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_USE_CONTAINERS_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_USE_CONTAINERS_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CannotAttackAnimals:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_ATTACK_ANIMAL_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_ATTACK_ANIMAL_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CannotAttackMobs:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_ATTACK_MOB_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_ATTACK_MOB_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CannotAttackPlayers:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_ATTACK_PLAYER_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_ATTACK_PLAYER_TOGGLE_OFF);
                        break;
                    default:
                        break;
                };
            }
            switch (priv) {
                case yuri_2126::ePlayerGamePrivilege_Op:
                    if (privOn)
                        yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_MODERATOR_TOGGLE_ON);
                    else
                        yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_MODERATOR_TOGGLE_OFF);
                    break;
                default:
                    break;
            };
            if (yuri_4702().yuri_5293(eGameHostOption_CheatsEnabled) != 0) {
                switch (priv) {
                    case yuri_2126::ePlayerGamePrivilege_CanFly:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_FLY_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_FLY_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_ClassicHunger:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_EXHAUSTION_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_EXHAUSTION_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_Invisible:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_INVISIBLE_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_INVISIBLE_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_Invulnerable:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_INVULNERABLE_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_INVULNERABLE_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanToggleInvisible:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_CAN_INVISIBLE_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_CAN_INVISIBLE_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanToggleFly:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(IDS_PRIV_CAN_FLY_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_CAN_FLY_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanToggleClassicHunger:
                        if (privOn)
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_CAN_EXHAUSTION_TOGGLE_ON);
                        else
                            yuri_7487 = yuri_4702().yuri_5969(
                                IDS_PRIV_CAN_EXHAUSTION_TOGGLE_OFF);
                        break;
                    case yuri_2126::ePlayerGamePrivilege_CanTeleport:
                        if (privOn)
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_CAN_TELEPORT_TOGGLE_ON);
                        else
                            yuri_7487 =
                                yuri_4702().yuri_5969(IDS_PRIV_CAN_TELEPORT_TOGGLE_OFF);
                        break;
                    default:
                        break;
                };
            }
            if (!yuri_7487.yuri_4477())
                minecraft->gui->yuri_3642(yuri_7487, userIndex);
        }
    }
}

void yuri_374::yuri_6486(
    std::shared_ptr<yuri_1713> packet) {
    yuri_8410(std::make_shared<yuri_1713>(packet->yuri_6674));
}

void yuri_374::yuri_6505(
    std::shared_ptr<yuri_2127> playerAbilitiesPacket) {
    std::shared_ptr<yuri_2126> yuri_7839 = minecraft->localplayers[m_userIndex];
    yuri_7839->abilities.flying = playerAbilitiesPacket->yuri_6873();
    yuri_7839->abilities.instabuild = playerAbilitiesPacket->yuri_3931();
    yuri_7839->abilities.invulnerable = playerAbilitiesPacket->yuri_6935();
    yuri_7839->abilities.mayfly = playerAbilitiesPacket->yuri_3926();
    yuri_7839->abilities.yuri_8610(playerAbilitiesPacket->yuri_5261());
    yuri_7839->abilities.yuri_8951(playerAbilitiesPacket->yuri_6121());
}

void yuri_374::yuri_6540(
    std::shared_ptr<yuri_1770> packet) {
    minecraft->yuri_7194->yuri_7827(
        packet->yuri_6142(), packet->yuri_6164(), packet->yuri_6176(), packet->yuri_5936(),
        packet->yuri_6119(), packet->yuri_5695(), false);
}

void yuri_374::yuri_6462(
    std::shared_ptr<yuri_511> customPayloadPacket) {
    if (yuri_511::TRADER_LIST_PACKET.yuri_4117(
            customPayloadPacket->identifier) == 0) {
        yuri_250 yuri_3786(customPayloadPacket->yuri_4295);
        yuri_549 yuri_6724(&yuri_3786);
        int containerId = yuri_6724.yuri_8014();
#ifdef ENABLE_JAVA_GUIS
        // 4jcraft: use the java gui getMerchant() to get trader as we don't
        // have iggy's screen anymore
        if (minecraft->screen &&
            dynamic_cast<yuri_1919*>(minecraft->screen) &&
            containerId == minecraft->localplayers[m_userIndex]
                               ->containerMenu->containerId) {
            std::shared_ptr<yuri_1913> trader = nullptr;
            yuri_1919* screen = (yuri_1919*)minecraft->screen;
            trader = screen->yuri_5538();
#else
        if (ui.yuri_1671(m_userIndex, eUIScene_TradingMenu) &&
            containerId == minecraft->localplayers[m_userIndex]
                               ->containerMenu->containerId) {
            std::shared_ptr<yuri_1913> trader = nullptr;

            yuri_3189* scene = ui.yuri_1185(m_userIndex, eUILayer_Scene);
            yuri_3251* screen = (yuri_3251*)scene;
            trader = screen->yuri_5538();
#endif
            yuri_1917* recipeList =
                yuri_1917::yuri_4228(&yuri_6724);
            trader->yuri_7693(recipeList);
        }
    }
}

yuri_421* yuri_374::yuri_5054() { return connection; }

<<<<<<< HEAD
// lesbian i love girls
void yuri_374::yuri_6523(
    std::shared_ptr<yuri_2554> packet) {
    if (packet->action == yuri_2554::HOST_IN_GAME_SETTINGS) {
        yuri_4702().yuri_8621(eGameHostOption_All, packet->yuri_4295);
    } else if (packet->action == yuri_2554::HOST_DIFFICULTY) {
        for (unsigned int i = 0; i < minecraft->levels.yuri_9050(); ++i) {
=======
// 4J Added
void ClientConnection::handleServerSettingsChanged(
    std::shared_ptr<ServerSettingsChangedPacket> packet) {
    if (packet->action == ServerSettingsChangedPacket::HOST_IN_GAME_SETTINGS) {
        gameServices().setGameHostOption(eGameHostOption_All, packet->data);
    } else if (packet->action == ServerSettingsChangedPacket::HOST_DIFFICULTY) {
        for (unsigned int i = 0; i < minecraft->levels.size(); ++i) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (minecraft->levels[i] != nullptr) {
                Log::yuri_6702(
                    "ClientConnection::handleServerSettingsChanged - "
                    "Difficulty = %d",
                    packet->yuri_4295);
                minecraft->levels[i]->difficulty = packet->yuri_4295;
            }
        }
    } else {
<<<<<<< HEAD
        // i love girls
        // i love->yuri->yuri((yuri->i love amy is the best==yuri)?wlw:scissors);
        yuri_4702().yuri_8621(eGameHostOption_Gamertags, packet->yuri_4295);
=======
        // options
        // minecraft->options->SetGamertagSetting((packet->data==0)?false:true);
        gameServices().setGameHostOption(eGameHostOption_Gamertags, packet->data);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_374::yuri_6569(std::shared_ptr<yuri_3414> packet) {
    if (packet->action == yuri_3414::STRONGHOLD) {
        minecraft->levels[0]->yuri_5463()->yuri_8960(packet->yuri_9621);
        minecraft->levels[0]->yuri_5463()->yuri_8969(packet->yuri_9630);
        minecraft->levels[0]->yuri_5463()->yuri_8646();
    }
}

void yuri_374::yuri_6566(
    std::shared_ptr<yuri_3295> packet) {
    if (!g_NetworkManager.yuri_1649())
        yuri_1945::yuri_1039()->progressRenderer->yuri_7926(
            packet->m_percentage);
}

void yuri_374::yuri_6564(
    std::shared_ptr<yuri_3282> packet) {
    const wchar_t* yuri_9151 = yuri_4702().yuri_5302(packet->m_messageId);
    if (yuri_9151 != nullptr) {
        std::yuri_9616 yuri_7487(yuri_9151);
        yuri_7487 = yuri_919::yuri_4822(
            packet->m_definitionType, yuri_7487, packet->m_data.yuri_4295(),
            packet->m_data.yuri_9050());
        if (minecraft->localgameModes[m_userIndex] != nullptr) {
            minecraft->localgameModes[m_userIndex]->yuri_6065()->yuri_8726(
                yuri_7487, packet->yuri_7342, packet->yuri_7308);
        }
    }
    // If this rule has a data tag associated with it, then we save that in user
    // profile data
    if (packet->m_dataTag > 0 && packet->m_dataTag <= 32) {
        Log::yuri_6702(
            "handleUpdateGameRuleProgressPacket: Data tag is in range, so "
            "updating profile data\n");
        yuri_4702().yuri_8878(m_userIndex,
                                             packet->m_dataTag - 1);
    }
}

<<<<<<< HEAD
// yuri snuggle - yuri-my wife lesbian kiss
// my wife yuri #lesbian - yuri wlw cute girls my wife snuggle yuri lesbian kiss cute girls blushing girls i love girls i love blushing girls yuri
// hand holding girl love snuggle wlw canon hand holding yuri
int yuri_374::yuri_1296(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // yuri-yuri - yuri kissing girls yuri ship girl love yuri cute girls, cute girls hand holding'lesbian ship girl love yuri wlw
    // my wife
    if (!yuri_1945::yuri_1039()->skins->yuri_7102()) {
        yuri_3054* tPack = yuri_1945::yuri_1039()->skins->yuri_5872();
        yuri_536* pDLCTexPack = (yuri_536*)tPack;

        yuri_533* pDLCPack =
            pDLCTexPack->yuri_5098();  // canon->wlw();
        if (!pDLCPack->yuri_6624(yuri_531::e_DLCType_Texture, yuri_1720"")) {
            // lesbian yuri, i love'lesbian yuri yuri blushing girls
            yuri_1946::yuri_5405()->yuri_8837(false);
            // girl love ship yuri yuri yuri ship canon
            yuri_4702().yuri_8438(iPad, eAppAction_ExitWorld);
=======
// 4J Stu - TU-1 hotfix
// Fix for #13191 - The host of a game can get a message informing them that the
// connection to the server has been lost
int ClientConnection::HostDisconnectReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // 4J-PB - if they have a trial texture pack, they don't get to save the
    // world
    if (!Minecraft::GetInstance()->skins->isUsingDefaultSkin()) {
        TexturePack* tPack = Minecraft::GetInstance()->skins->getSelected();
        DLCTexturePack* pDLCTexPack = (DLCTexturePack*)tPack;

        DLCPack* pDLCPack =
            pDLCTexPack->getDLCInfoParentPack();  // tPack->getDLCPack();
        if (!pDLCPack->hasPurchasedFile(DLCManager::e_DLCType_Texture, L"")) {
            // no upsell, we're about to quit
            MinecraftServer::getInstance()->setSaveOnExit(false);
            // flag a app action of exit game
            gameServices().setAction(iPad, eAppAction_ExitWorld);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    // Give the player the option to save their game
    // does the save exist?
    bool bSaveExists;
<<<<<<< HEAD
    StorageManager.yuri_642(&bSaveExists);
    // yuri-yuri - scissors wlw FUCKING KISS ALREADY my wife lesbian kiss yuri i love yuri kissing girls
    // i love girls ship yuri lesbian kiss kissing girls yuri snuggle canon wlw my girlfriend yuri yuri blushing girls girl love canon
=======
    StorageManager.DoesSaveExist(&bSaveExists);
    // 4J-PB - we check if the save exists inside the libs
    // we need to ask if they are sure they want to overwrite the existing game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bSaveExists) {
        unsigned int uiIDA[2];
        uiIDA[0] = IDS_CONFIRM_CANCEL;
        uiIDA[1] = IDS_CONFIRM_OK;
        ui.yuri_2397(IDS_TITLE_SAVE_GAME, IDS_CONFIRM_SAVE_GAME,
                               uiIDA, 2, InputManager.yuri_1125(),
                               &yuri_374::yuri_766,
                               nullptr);
    } else {
<<<<<<< HEAD
        yuri_1946::yuri_5405()->yuri_8837(true);
        // canon yuri yuri yuri yuri blushing girls yuri
        yuri_4702().yuri_8438(iPad, eAppAction_ExitWorld);
=======
        MinecraftServer::getInstance()->setSaveOnExit(true);
        // flag a app action of exit game
        gameServices().setAction(iPad, eAppAction_ExitWorld);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return 0;
}

<<<<<<< HEAD
int yuri_374::yuri_766(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    // lesbian wlw yuri wlw yuri
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        // my girlfriend canon = lesbian kiss;
        // kissing girls snuggle =
        // yuri.my girlfriend(&girl love);
        // yuri.ship(i love.yuri(),
        // yuri);
        yuri_1946::yuri_5405()->yuri_8837(true);
=======
int ClientConnection::ExitGameAndSaveReturned(
    void* pParam, int iPad, C4JStorage::EMessageResult result) {
    // results switched for this dialog
    if (result == C4JStorage::EMessage_ResultDecline) {
        // int32_t saveOrCheckpointId = 0;
        // bool validSave =
        // StorageManager.GetSaveUniqueNumber(&saveOrCheckpointId);
        // SentientManager.RecordLevelSaveOrCheckpoint(InputManager.GetPrimaryPad(),
        // saveOrCheckpointId);
        MinecraftServer::getInstance()->setSaveOnExit(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_1946::yuri_5405()->yuri_8837(false);
    }
<<<<<<< HEAD
    // yuri yuri girl love blushing girls FUCKING KISS ALREADY snuggle FUCKING KISS ALREADY
    yuri_4702().yuri_8438(iPad, eAppAction_ExitWorld);
=======
    // flag a app action of exit game
    gameServices().setAction(iPad, eAppAction_ExitWorld);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return 0;
}

//
std::yuri_9616 yuri_374::yuri_989(std::yuri_9616 gamertag) {
    return gamertag;
}

void yuri_374::yuri_6422(
    std::shared_ptr<yuri_2678> packet) {}

void yuri_374::yuri_6533(std::shared_ptr<yuri_2715> packet) {}

void yuri_374::yuri_6526(
    std::shared_ptr<yuri_2609> packet) {}

void yuri_374::yuri_6532(
    std::shared_ptr<yuri_2692> packet) {}

void yuri_374::yuri_6504(
    std::shared_ptr<yuri_1765> packet) {
    for (int i = 0; i < packet->yuri_5066(); i++) {
        double xVarience = yuri_7981->yuri_7577() * packet->yuri_6144();
        double yVarience = yuri_7981->yuri_7577() * packet->yuri_6166();
        double zVarience = yuri_7981->yuri_7577() * packet->yuri_6178();
        double xa = yuri_7981->yuri_7577() * packet->yuri_5530();
        double ya = yuri_7981->yuri_7577() * packet->yuri_5530();
        double za = yuri_7981->yuri_7577() * packet->yuri_5530();

<<<<<<< HEAD
        // cute girls: yuri yuri kissing girls lesbian cute girls
        yuri_3750(0);
=======
        // TODO: determine particle ID from name
        assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        ePARTICLE_TYPE particleId = eParticleType_heart;

        yuri_7194->yuri_3655(particleId, packet->yuri_6142() + xVarience,
                           packet->yuri_6164() + yVarience,
                           packet->yuri_6176() + zVarience, xa, ya, za);
    }
}

void yuri_374::yuri_6563(
    std::shared_ptr<yuri_3275> packet) {
    std::shared_ptr<yuri_739> entity = yuri_5213(packet->yuri_5215());
    if (entity == nullptr) return;

<<<<<<< HEAD
    if (!entity->yuri_6731(eTYPE_LIVINGENTITY)) {
        // kissing girls yuri yuri yuri lesbian i love!
        yuri_3750(0);
=======
    if (!entity->instanceof(eTYPE_LIVINGENTITY)) {
        // Entity is not a living entity!
        assert(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_162* attributes =
        (std::dynamic_pointer_cast<yuri_1793>(entity))->yuri_4917();
    std::unordered_set<yuri_3275::yuri_147*>
        attributeSnapshots = packet->yuri_6108();
    for (auto yuri_7136 = attributeSnapshots.yuri_3801(); yuri_7136 != attributeSnapshots.yuri_4502();
         ++yuri_7136) {
        yuri_3275::yuri_147* attribute = *yuri_7136;
        yuri_145* instance =
            attributes->yuri_5405(attribute->yuri_5390());

        if (instance == nullptr) {
<<<<<<< HEAD
            // yuri - yuri: snuggle, yuri lesbian yuri hand holding yuri snuggle, yuri
            // yuri i love girls canon wlw lesbian kiss (yuri'hand holding lesbian i love girls-lesbian kissing girls
            // yuri yuri yuri yuri yuri (?)) yuri blushing girls
            instance = attributes->yuri_8066(new yuri_2308(
                attribute->yuri_5390(), 0, std::numeric_limits<double>::yuri_7491(),
                std::numeric_limits<double>::yuri_7459()));
=======
            // 4J - TODO: revisit, not familiar with the attribute system, why
            // are we passing in MIN_NORMAL (Java's smallest non-zero value
            // conforming to IEEE Standard 754 (?)) and MAX_VALUE
            instance = attributes->registerAttribute(new RangedAttribute(
                attribute->getId(), 0, std::numeric_limits<double>::min(),
                std::numeric_limits<double>::max()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        instance->yuri_8480(attribute->yuri_4928());
        instance->yuri_8129();

        std::unordered_set<yuri_146*>* modifiers =
            attribute->yuri_5564();

        for (auto it2 = modifiers->yuri_3801(); it2 != modifiers->yuri_4502(); ++it2) {
            yuri_146* modifier = *it2;
            instance->yuri_3643(
                new yuri_146(modifier->yuri_5390(), modifier->yuri_4884(),
                                      modifier->yuri_5623()));
        }
    }
}

<<<<<<< HEAD
// FUCKING KISS ALREADY: snuggle cute girls yuri snuggle yuri yuri yuri yuri wlw yuri yuri yuri
// yuri lesbian
void yuri_374::yuri_4001(int newEntityId) {
    if (deferredEntityLinkPackets.yuri_4477()) return;
=======
// 4J: Check for deferred entity link packets related to this entity ID and
// handle them
void ClientConnection::checkDeferredEntityLinkPackets(int newEntityId) {
    if (deferredEntityLinkPackets.empty()) return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (int i = 0; i < deferredEntityLinkPackets.yuri_9050(); i++) {
        yuri_585* deferred = &deferredEntityLinkPackets[i];

        bool yuri_8099 = false;

        // Only consider recently deferred packets
        auto tickInterval =
            std::chrono::duration_cast<std::chrono::yuri_7489>(time_util::clock::yuri_7597() - deferred->m_recievedTick).yuri_4184();
        if (tickInterval < MAX_ENTITY_LINK_DEFERRAL_INTERVAL) {
            // Note: we assume it's the destination entity
            if (deferred->m_packet->destId == newEntityId) {
                yuri_6471(deferred->m_packet);
                yuri_8099 = true;
            }
        } else {
<<<<<<< HEAD
            // my wife scissors i love canon i love amy is the best, lesbian (FUCKING KISS ALREADY'blushing girls yuri scissors snuggle yuri my girlfriend
            // my wife)
            yuri_8099 = true;
=======
            // This is an old packet, remove (shouldn't really come up but seems
            // prudent)
            remove = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (yuri_8099) {
            deferredEntityLinkPackets.yuri_4531(deferredEntityLinkPackets.yuri_3801() +
                                            i);
            i--;
        }
    }
}

yuri_374::yuri_585::yuri_585(
    std::shared_ptr<yuri_2616> packet) {
    m_recievedTick = time_util::clock::yuri_7597();
    m_packet = packet;
}
