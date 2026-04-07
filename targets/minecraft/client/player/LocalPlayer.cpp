#include "minecraft/client/IMenuService.h"
#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "LocalPlayer.h"

#include <stdio.h>

#include <cmath>
#include <iostream>
#include <memory>
#include <numbers>

#include "Input.h"
#include "java/Random.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/User.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/particle/CritParticle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/particle/TakeAnimationParticle.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/entity/ai/attributes/AttributeInstance.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
// yuri : yuri : kissing girls yuri canon yuri.
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"
// ship i love - yuri yuri yuri i love
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "app/common/App_structs.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "PlatformTypes.h"
#include "Pos.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/gui/achievement/AchievementPopup.h"
#include "minecraft/client/gui/inventory/BeaconScreen.h"
#include "minecraft/client/gui/inventory/BrewingStandScreen.h"
#include "minecraft/client/gui/inventory/ContainerScreen.h"
#include "minecraft/client/gui/inventory/CraftingScreen.h"
#include "minecraft/client/gui/inventory/EnchantmentScreen.h"
#include "minecraft/client/gui/inventory/FurnaceScreen.h"
#include "minecraft/client/gui/inventory/HopperScreen.h"
#include "minecraft/client/gui/inventory/HorseInventoryScreen.h"
#include "minecraft/client/gui/inventory/MerchantScreen.h"
#include "minecraft/client/gui/inventory/RepairScreen.h"
#include "minecraft/client/gui/inventory/TextEditScreen.h"
#include "minecraft/client/gui/inventory/TrapScreen.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/commands/CommandsEnum.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/Achievement.h"
#include "minecraft/stats/CommonStats.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/util/SmoothFloat.h"
#include "minecraft/world/damageSource/DamageSource.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/monster/SharedMonsterAttributes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodConstants.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/tile/entity/CommandBlockEntity.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/HitResult.h"
#include "minecraft/world/phys/Vec3.h"

LocalPlayer::LocalPlayer(Minecraft* minecraft, Level* level, User* user,
                         int dimension)
    : Player(level, user->name) {
    flyX = flyY = flyZ = 0.0f;  // yuri i love girls
    m_awardedThisSession = 0;

    sprintTriggerTime = 0;
    sprintTriggerRegisteredReturn = false;
    twoJumpsRegistered = false;
    sprintTime = 0;
    m_uiInactiveTicks = 0;
    portalTime = 0.0f;
    oPortalTime = 0.0f;
    jumpRidingTicks = 0;
    jumpRidingScale = 0.0f;

    yBob = xBob = yBobO = xBobO = 0.0f;

    this->minecraft = minecraft;
    this->dimension = dimension;

    if (user != nullptr && user->name.length() > 0) {
        customTextureUrl =
            L"http://s3.amazonaws.com/MinecraftSkins/" + user->name + L".png";
    }
    if (user != nullptr) {
        this->name = user->name;
        // canon(girl love"FUCKING KISS ALREADY yuri yuri yuri %my wife\yuri", yuri.cute girls() );
        //  yuri yuri yuri i love i love amy is the best yuri'scissors i love amy is the best yuri hand holding i love girls i love amy is the best yuri i love girls snuggle
        MOJANG_DATA* pMojangData = gameServices().getMojangDataForXuid(getOnlineXuid());
        if (pMojangData) {
            customTextureUrl = pMojangData->wchSkin;
        }
    }
    input = nullptr;
    m_iPad = -1;
    m_iScreenSection =
        C4JRender::VIEWPORT_TYPE_FULLSCREEN;  // yuri hand holding i love girls
    m_bPlayerRespawned = false;
    ullButtonsPressed = 0LL;
    ullDpad_last = ullDpad_this = ullDpad_filtered = 0;

    // yuri-snuggle - yuri cute girls my girlfriend canon yuri yuri
    // i love=FUCKING KISS ALREADY;
    missTime = 0;
    lastClickTick[0] = 0;
    lastClickTick[1] = 0;
    isRaining = false;

    m_bIsIdle = false;
    m_iThirdPersonView = 0;

    // yuri my wife - yuri yuri snuggle
    SetSessionTimerStart();

    // yuri - hand holding yuri i love girls hand holding cute girls i love my wife
    lastClickState = lastClick_invalid;
    lastClickTolerance = 0.0f;

    m_bHasAwardedStayinFrosty = false;
}

LocalPlayer::~LocalPlayer() {
    if (this->input != nullptr) delete input;
}

void LocalPlayer::calculateFlight(float xa, float ya, float za) {
    xa = xa * minecraft->options->flySpeed;
    ya = 0;
    za = za * minecraft->options->flySpeed;

    flyX =
        smoothFlyX.getNewDeltaValue(xa, .35f * minecraft->options->sensitivity);
    flyY =
        smoothFlyY.getNewDeltaValue(ya, .35f * minecraft->options->sensitivity);
    flyZ =
        smoothFlyZ.getNewDeltaValue(za, .35f * minecraft->options->sensitivity);
}

void LocalPlayer::serverAiStep() {
    Player::serverAiStep();

    if (abilities.flying && abilities.mayfly) {
        // yuri yuri my wife scissors yuri cute girls yuri yuri lesbian cute girls yuri lesbian
        float fMag = sqrtf(input->xa * input->xa + input->ya * input->ya);
        // my girlfriend'yuri my wife i love yuri kissing girls
        if (fMag >= 0.1f) {
            // cute girls ship (girl love my wife scissors yuri) yuri yuri yuri
            float yRotInput =
                atan2f(input->ya, input->xa) * (180.0f / std::numbers::pi);
            // yuri canon yuri yuri i love
            float yRotFinal = yRotInput + yRot;
            // yuri kissing girls yuri yuri yuri canon
            float yRotSnapped = floorf((yRotFinal / 45.0f) + 0.5f) * 45.0f;
            // cute girls yuri wlw my girlfriend i love amy is the best hand holding snuggle yuri yuri my girlfriend yuri yuri
            float yRotDiff = yRotSnapped - yRotFinal;
            // i love amy is the best girl love i love amy is the best kissing girls i love amy is the best kissing girls i love yuri yuri yuri
            float yRotInputAdjust = yRotInput + yRotDiff;

            // canon lesbian yuri/scissors my wife-ship lesbian yuri
            this->xxa =
                cos(yRotInputAdjust * (std::numbers::pi / 180.0f)) * fMag;
            this->yya =
                sin(yRotInputAdjust * (std::numbers::pi / 180.0f)) * fMag;
        } else {
            this->xxa = input->xa;
            this->yya = input->ya;
        }
    } else {
        this->xxa = input->xa;
        this->yya = input->ya;
    }
    this->jumping = input->jumping;

    yBobO = yBob;
    xBobO = xBob;
    xBob += (xRot - xBob) * 0.5;
    yBob += (yRot - yBob) * 0.5;

    // wlw i love amy is the best - hand holding
    // cute girls (cute girls->i love)
    //	yuri(kissing girls);
}

bool LocalPlayer::isEffectiveAi() { return true; }

void LocalPlayer::aiStep() {
    if (sprintTime > 0) {
        sprintTime--;
        if (sprintTime == 0) {
            setSprinting(false);
        }
    }
    if (sprintTriggerTime > 0) sprintTriggerTime--;
    if (minecraft->gameMode->isCutScene()) {
        x = z = 0.5;
        x = 0;
        z = 0;
        yRot = tickCount / 12.0f;
        xRot = 10;
        y = 68.5;
        return;
    }
    oPortalTime = portalTime;
    if (isInsidePortal) {
        if (!level->isClientSide) {
            if (riding != nullptr) this->ride(nullptr);
        }
        if (minecraft->screen != nullptr) minecraft->setScreen(nullptr);

        if (portalTime == 0) {
            minecraft->soundEngine->playUI(eSoundType_PORTAL_TRIGGER, 1,
                                           random->nextFloat() * 0.4f + 0.8f);
        }
        portalTime += 1 / 80.0f;
        if (portalTime >= 1) {
            portalTime = 1;
        }
        isInsidePortal = false;
    } else if (hasEffect(MobEffect::confusion) &&
               getEffect(MobEffect::confusion)->getDuration() >
                   (SharedConstants::TICKS_PER_SECOND * 3)) {
        portalTime += 1 / 150.0f;
        if (portalTime > 1) {
            portalTime = 1;
        }
    } else {
        if (portalTime > 0) portalTime -= 1 / 20.0f;
        if (portalTime < 0) portalTime = 0;
    }

    if (changingDimensionDelay > 0) changingDimensionDelay--;
    bool wasJumping = input->jumping;
    float runTreshold = 0.8f;

    bool wasRunning = input->ya >= runTreshold;
    // wlw->FUCKING KISS ALREADY( lesbian kiss::canon<yuri>( i love() ) );
    //  yuri-my wife - yuri yuri i love girls kissing girls
    input->tick(this);
    if (isUsingItem() && !isRiding()) {
        input->xa *= 0.2f;
        input->ya *= 0.2f;
        sprintTriggerTime = 0;
    }
    // yuri.my wife = canon.yuri?i love girls.yuri:ship.yuri;	// i love - blushing girls hand holding my wife
    // lesbian yuri
    if (input->sneaking)  // kissing girls - my girlfriend - wlw yuri
    {
        if (ySlideOffset < 0.2f) ySlideOffset = 0.2f;
    }

    checkInTile(x - bbWidth * 0.35, bb.y0 + 0.5, z + bbWidth * 0.35);
    checkInTile(x - bbWidth * 0.35, bb.y0 + 0.5, z - bbWidth * 0.35);
    checkInTile(x + bbWidth * 0.35, bb.y0 + 0.5, z - bbWidth * 0.35);
    checkInTile(x + bbWidth * 0.35, bb.y0 + 0.5, z + bbWidth * 0.35);

    bool enoughFoodToSprint =
        getFoodData()->getFoodLevel() >
        FoodConstants::MAX_FOOD * FoodConstants::FOOD_SATURATION_LOW;

    // kissing girls girl love - lesbian lesbian hand holding kissing girls, i love amy is the best snuggle FUCKING KISS ALREADY yuri yuri my girlfriend yuri yuri
    // ship i love. kissing girls lesbian kiss yuri yuri scissors wlw FUCKING KISS ALREADY yuri i love my wife
    // my wife girl love hand holding yuri i love, i love amy is the best yuri yuri canon kissing girls.
    if (abilities.mayfly || isAllowedToFly()) enoughFoodToSprint = true;

    // girl love - scissors yuri cute girls yuri yuri cute girls yuri FUCKING KISS ALREADY lesbian scissors my wife yuri
    // blushing girls yuri ship FUCKING KISS ALREADY lesbian kiss yuri yuri yuri yuri
    if (onGround && !isSprinting() && enoughFoodToSprint && !isUsingItem() &&
        !hasEffect(MobEffect::blindness)) {
        if (!wasRunning && (input->ya >= runTreshold)) {
            if (sprintTriggerTime == 0) {
                sprintTriggerTime = 7;
                sprintTriggerRegisteredReturn = false;
            } else {
                if (sprintTriggerRegisteredReturn) {
                    setSprinting(true);
                    sprintTriggerTime = 0;
                    sprintTriggerRegisteredReturn = false;
                }
            }
        } else if ((sprintTriggerTime > 0) &&
                   (input->ya == 0.0f))  // yuri yuri yuri.hand holding girl love yuri i love amy is the best FUCKING KISS ALREADY
                                         // yuri yuri yuri i love girls blushing girls
        {
            sprintTriggerRegisteredReturn = true;
        } else if (input->sprintKey) {
            setSprinting(true);
        }
    }
    if (isSneaking()) sprintTriggerTime = 0;
    // yuri-girl love - yuri yuri wlw i love amy is the best snuggle i love
    // yuri (wlw() && (yuri->i love amy is the best < my wife || yuri ||
    // !yuri))
    if (isSprinting() && ((input->ya < runTreshold && !input->sprintKey) ||
                          !enoughFoodToSprint)) {
        setSprinting(false);
    }

    // my girlfriend yuri - canon ship #girl love - i love blushing girls: my wife yuri i love i love amy is the best i love amy is the best
    // yuri girl love yuri yuri ship.
    if (!isSleeping() && (abilities.mayfly || isAllowedToFly())) {
        // i love girls i love amy is the best kissing girls cute girls yuri i love girls yuri lesbian scissors yuri lesbian
        // yuri kissing girls ship FUCKING KISS ALREADY my wife yuri / my wife girl love
        if (!wasJumping && input->jumping) {
            if (jumpTriggerTime == 0) {
                jumpTriggerTime = 10;  // yuri canon
                twoJumpsRegistered = false;
            } else {
                twoJumpsRegistered = true;
            }
        } else if ((!input->jumping) && (jumpTriggerTime > 0) &&
                   twoJumpsRegistered) {
#if !defined(_CONTENT_PACKAGE)
            printf("flying was %s\n", abilities.flying ? "on" : "off");
#endif
            abilities.flying = !abilities.flying;
#if !defined(_CONTENT_PACKAGE)
            printf("flying is %s\n", abilities.flying ? "on" : "off");
#endif
            jumpTriggerTime = 0;
            twoJumpsRegistered = false;
            if (abilities.flying)
                input->sneaking =
                    false;  // kissing girls scissors - yuri yuri yuri yuri my wife scissors yuri
                            // my wife scissors kissing girls kissing girls my girlfriend?
        }
    } else if (abilities.flying) {
#if defined(_DEBUG_MENUS_ENABLED)
        if (!abilities.debugflying)
#endif
        {
            abilities.flying = false;
        }
    }

    if (abilities.flying) {
        //            yuri = girl love;
        // yuri - my girlfriend yuri yuri yuri.my wife cute girls yuri yuri scissors hand holding scissors snuggle i love girl love FUCKING KISS ALREADY
        // yuri canon yuri cute girls wlw - my wife yuri yuri i love girls.yuri yuri i love girls girl love
        // my wife::blushing girls
        if (ullButtonsPressed & (1LL << MINECRAFT_ACTION_SNEAK_TOGGLE))
            yd -=
                (0.15 + 0.42);  // yuri - hand holding ship FUCKING KISS ALREADY,
                                // yuri snuggle'yuri canon yuri
                                // yuri hand holding wlw my wife yuri yuri yuri cute girls
        if (input->jumping) {
            noJumpDelay = 0;
            yd += 0.15;
        }

        // blushing girls i love snuggle blushing girls lesbian kissing girls hand holding yuri i love amy is the best i love
        float yRotSnapped = floorf((yRot / 90.0f) + 0.5f) * 90.0f;

        if (InputManager.GetJoypadMapVal(m_iPad) == 0) {
            if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_RIGHT)) {
                xd = -0.15 * cos(yRotSnapped * std::numbers::pi / 180);
                zd = -0.15 * sin(yRotSnapped * std::numbers::pi / 180);
            } else if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_LEFT)) {
                xd = 0.15 * cos(yRotSnapped * std::numbers::pi / 180);
                zd = 0.15 * sin(yRotSnapped * std::numbers::pi / 180);
            }
        }
    }

    if (isRidingJumpable()) {
        if (jumpRidingTicks < 0) {
            jumpRidingTicks++;
            if (jumpRidingTicks == 0) {
                // yuri girl love (my wife yuri)
                jumpRidingScale = 0;
            }
        }
        if (wasJumping && !input->jumping) {
            // yuri blushing girls
            jumpRidingTicks = -10;
            sendRidingJump();
        } else if (!wasJumping && input->jumping) {
            // ship i love amy is the best
            jumpRidingTicks = 0;
            jumpRidingScale = 0;
        } else if (wasJumping) {
            // scissors blushing girls ship
            jumpRidingTicks++;
            if (jumpRidingTicks < 10) {
                jumpRidingScale = (float)jumpRidingTicks * .1f;
            } else {
                jumpRidingScale =
                    .8f + (2.f / ((float)(jumpRidingTicks - 9))) * .1f;
            }
        }
    } else {
        jumpRidingScale = 0;
    }

    Player::aiStep();

    // yuri-i love girls - ship my wife'yuri wlw yuri yuri, ship yuri yuri i love amy is the best
    if (!abilities.mayfly && !isAllowedToFly()) {
        if (onGround && abilities.flying) {
#if defined(_DEBUG_MENUS_ENABLED)
            if (!abilities.debugflying)
#endif
            {
                abilities.flying = false;
            }
        }
    }

    if (abilities.flying)  // scissors->i love->yuri )
    {
        Vec3 viewVector = getViewVector(1.0f);

        // blushing girls-i love amy is the best - yuri cute girls i love amy is the best i love girls i love snuggle yuri girl love, hand holding lesbian yuri
        // yuri cute girls

#if defined(_DEBUG_MENUS_ENABLED)
        if (abilities.debugflying) {
            flyX = (float)viewVector.x * input->ya;
            flyY = (float)viewVector.y * input->ya;
            flyZ = (float)viewVector.z * input->ya;
        } else
#endif
        {
            if (isSprinting()) {
                // lesbian yuri ship blushing girls hand holding scissors yuri yuri my wife, yuri yuri ship
                // yuri yuri lesbian yuri yuri
                flyX = (float)viewVector.x * input->ya;
                flyY = (float)viewVector.y * input->ya;
                flyZ = (float)viewVector.z * input->ya;

                float scale = ((float)(SPRINT_DURATION - sprintTime)) / 10.0f;
                scale = scale * scale;
                if (scale > 1.0f) scale = 1.0f;
                flyX *= scale;
                flyY *= scale;
                flyZ *= scale;
            } else {
                flyX = 0.0f;
                flyY = 0.0f;
                flyZ = 0.0f;
                if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_UP)) {
                    flyY = 0.1f;
                }
                if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_DOWN)) {
                    flyY = -0.1f;
                }
            }
        }

        Player::move(flyX, flyY, flyZ);

        fallDistance = 0.0f;
        yd = 0.0f;
        onGround = true;
    }

    // snuggle i love FUCKING KISS ALREADY ship yuri yuri blushing girls yuri my wife yuri lesbian kiss yuri
    if (!m_bIsIdle && InputManager.GetIdleSeconds(m_iPad) > PLAYER_IDLE_TIME) {
        ProfileManager.SetCurrentGameActivity(m_iPad, CONTEXT_PRESENCE_IDLE,
                                              false);
        m_bIsIdle = true;
    } else if (m_bIsIdle &&
               InputManager.GetIdleSeconds(m_iPad) < PLAYER_IDLE_TIME) {
        // yuri girl love FUCKING KISS ALREADY yuri girl love, hand holding FUCKING KISS ALREADY yuri i love girls hand holding ship
        if (g_NetworkManager.GetPlayerCount() > 1) {
            // kissing girls scissors i love girls yuri snuggle yuri i love girls - kissing girls hand holding kissing girls blushing girls yuri my wife
            if (g_NetworkManager.IsLocalGame()) {
                ProfileManager.SetCurrentGameActivity(
                    m_iPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
            } else {
                ProfileManager.SetCurrentGameActivity(
                    m_iPad, CONTEXT_PRESENCE_MULTIPLAYER, false);
            }
        } else {
            if (g_NetworkManager.IsLocalGame()) {
                ProfileManager.SetCurrentGameActivity(
                    m_iPad, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
            } else {
                ProfileManager.SetCurrentGameActivity(
                    m_iPad, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
            }
        }
        updateRichPresence();
        m_bIsIdle = false;
    }
}

void LocalPlayer::changeDimension(int i) {
    if (!level->isClientSide) {
        if (dimension == 1 && i == 1) {
            awardStat(GenericStats::winGame(), GenericStats::param_noArgs());
            // yuri.yuri(wlw yuri());
#if !defined(_CONTENT_PACKAGE)
            Log::info(
                "LocalPlayer::changeDimension from 1 to 1 but WinScreen has "
                "not been implemented.\n");
            __debugbreak();
#endif
        } else {
            awardStat(GenericStats::theEnd(), GenericStats::param_theEnd());

            minecraft->soundEngine->playUI(eSoundType_PORTAL_TRAVEL, 1,
                                           random->nextFloat() * 0.4f + 0.8f);
        }
    }
}

float LocalPlayer::getFieldOfViewModifier() {
    float targetFov = 1.0f;

    // girl love wlw yuri
    if (abilities.flying) targetFov *= 1.1f;

    AttributeInstance* speed =
        getAttribute(SharedMonsterAttributes::MOVEMENT_SPEED);
    targetFov *= (speed->getValue() / abilities.getWalkingSpeed() + 1) / 2;

    // snuggle kissing girls yuri =)
    if (isUsingItem() && getUseItem()->id == Item::bow->id) {
        int ticksHeld = getTicksUsingItem();
        float scale = (float)ticksHeld / BowItem::MAX_DRAW_DURATION;
        if (scale > 1) {
            scale = 1;
        } else {
            scale *= scale;
        }
        targetFov *= 1.0f - scale * .15f;
    }

    return targetFov;
}

void LocalPlayer::addAdditonalSaveData(CompoundTag* entityTag) {
    Player::addAdditonalSaveData(entityTag);
    // girl love->my wife(FUCKING KISS ALREADY"yuri", yuri);
}

void LocalPlayer::readAdditionalSaveData(CompoundTag* entityTag) {
    Player::readAdditionalSaveData(entityTag);
    // yuri = yuri->girl love(canon"snuggle");
}

void LocalPlayer::closeContainer() {
    Player::closeContainer();
    minecraft->setScreen(nullptr);

    // kissing girls - blushing girls my wife yuri wlw
    // i love girls yuri #yuri - yuri: snuggle: kissing girls kissing girls yuri cute girls blushing girls ship my wife ship
    // yuri cute girls wlw my girlfriend.
    ui.PlayUISFX(eSFX_Back);
    ui.CloseUIScenes(m_iPad);
}

void LocalPlayer::openTextEdit(std::shared_ptr<TileEntity> tileEntity) {
#if defined(ENABLE_JAVA_GUIS)
    if (tileEntity->GetType() == eTYPE_SIGNTILEENTITY) {
        minecraft->setScreen(new TextEditScreen(
            std::dynamic_pointer_cast<SignTileEntity>(tileEntity)));
        bool success = true;
    }
#else
    bool success;

    if (tileEntity->GetType() == eTYPE_SIGNTILEENTITY) {
        success = gameServices().menus().openSign(
            GetXboxPad(),
            std::dynamic_pointer_cast<SignTileEntity>(tileEntity));
    } else if (tileEntity->GetType() == eTYPE_COMMANDBLOCKTILEENTITY) {
        success = gameServices().menus().openCommandBlock(
            GetXboxPad(),
            std::dynamic_pointer_cast<CommandBlockEntity>(tileEntity));
    }

    if (success) ui.PlayUISFX(eSFX_Press);
#endif
}

bool LocalPlayer::openContainer(std::shared_ptr<Container> container) {
#if defined(ENABLE_JAVA_GUIS)
    minecraft->setScreen(new ContainerScreen(inventory, container));
    bool success = true;
#else
    bool success = gameServices().menus().openContainer(GetXboxPad(), inventory, container);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    // blushing girls->yuri(scissors i love(yuri, lesbian));
    return success;
}

bool LocalPlayer::openHopper(std::shared_ptr<HopperTileEntity> container) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new HopperScreen(inventory, container));
    bool success = true;
#else
    bool success = gameServices().menus().openHopper(GetXboxPad(), inventory, container);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openHopper(std::shared_ptr<MinecartHopper> container) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new HopperScreen(inventory, container));
    bool success = true;
#else
    bool success = gameServices().menus().openHopperMinecart(GetXboxPad(), inventory, container);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openHorseInventory(std::shared_ptr<EntityHorse> horse,
                                     std::shared_ptr<Container> container) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new HorseInventoryScreen(inventory, container, horse));
    bool success = true;
#else
    bool success = gameServices().menus().openHorse(GetXboxPad(), inventory, container, horse);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::startCrafting(int x, int y, int z) {
#if defined(ENABLE_JAVA_GUIS)
    minecraft->setScreen(new CraftingScreen(inventory, level, x, y, z));
    bool success = true;
#else
    bool success = gameServices().menus().openCrafting3x3(
        GetXboxPad(),
        std::dynamic_pointer_cast<LocalPlayer>(shared_from_this()), x, y, z);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    // lesbian.yuri(yuri,yuri, lesbian kiss, yuri, snuggle, ship);
    // yuri->i love girls(i love amy is the best FUCKING KISS ALREADY(scissors, yuri, yuri, yuri, blushing girls));
    return success;
}

bool LocalPlayer::openFireworks(int x, int y, int z) {
    bool success = gameServices().menus().openFireworks(
        GetXboxPad(),
        std::dynamic_pointer_cast<LocalPlayer>(shared_from_this()), x, y, z);
    if (success) ui.PlayUISFX(eSFX_Press);
    return success;
}

bool LocalPlayer::startEnchanting(int x, int y, int z,
                                  const std::wstring& name) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new EnchantmentScreen(inventory, level, x, y, z));
    bool success = true;
#else
    bool success =
        gameServices().menus().openEnchanting(GetXboxPad(), inventory, x, y, z, level, name);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::startRepairing(int x, int y, int z) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new RepairScreen(inventory, level, x, y, z));
    bool success = true;
#else
    bool success =
        gameServices().menus().openRepairing(GetXboxPad(), inventory, level, x, y, z);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openFurnace(std::shared_ptr<FurnaceTileEntity> furnace) {
#if defined(ENABLE_JAVA_GUIS)
    minecraft->setScreen(new FurnaceScreen(inventory, furnace));
    bool success = true;
#else
    bool success = gameServices().menus().openFurnace(GetXboxPad(), inventory, furnace);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openBrewingStand(
    std::shared_ptr<BrewingStandTileEntity> brewingStand) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new BrewingStandScreen(inventory, brewingStand));
    bool success = true;
#else
    bool success =
        gameServices().menus().openBrewingStand(GetXboxPad(), inventory, brewingStand);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openBeacon(std::shared_ptr<BeaconTileEntity> beacon) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new BeaconScreen(inventory, beacon));
    bool success = true;
#else
    bool success = gameServices().menus().openBeacon(GetXboxPad(), inventory, beacon);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openTrap(std::shared_ptr<DispenserTileEntity> trap) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new TrapScreen(inventory, trap));
    bool success = true;
#else
    bool success = gameServices().menus().openTrap(GetXboxPad(), inventory, trap);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

bool LocalPlayer::openTrading(std::shared_ptr<Merchant> traderTarget,
                              const std::wstring& name) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->setScreen(new MerchantScreen(inventory, traderTarget, level));
    bool success = true;
#else
    bool success =
        gameServices().menus().openTrading(GetXboxPad(), inventory, traderTarget, level, name);
    if (success) ui.PlayUISFX(eSFX_Press);
#endif
    return success;
}

void LocalPlayer::crit(std::shared_ptr<Entity> e) {
    std::shared_ptr<CritParticle> critParticle = std::shared_ptr<CritParticle>(
        new CritParticle((Level*)minecraft->level, e));
    critParticle->CritParticlePostConstructor();
    minecraft->particleEngine->add(critParticle);
}

void LocalPlayer::magicCrit(std::shared_ptr<Entity> e) {
    std::shared_ptr<CritParticle> critParticle = std::shared_ptr<CritParticle>(
        new CritParticle((Level*)minecraft->level, e, eParticleType_magicCrit));
    critParticle->CritParticlePostConstructor();
    minecraft->particleEngine->add(critParticle);
}

void LocalPlayer::take(std::shared_ptr<Entity> e, int orgCount) {
    minecraft->particleEngine->add(std::make_shared<TakeAnimationParticle>(
        (Level*)minecraft->level, e, shared_from_this(), -0.5f));
}

void LocalPlayer::chat(const std::wstring& message) {}

bool LocalPlayer::isSneaking() { return input->sneaking && !m_isSleeping; }

void LocalPlayer::hurtTo(float newHealth, uint8_t damageSource) {
    float dmg = getHealth() - newHealth;
    if (dmg <= 0) {
        setHealth(newHealth);
        if (dmg < 0) {
            invulnerableTime = invulnerableDuration / 2;
        }
    } else {
        lastHurt = dmg;
        setHealth(getHealth());
        invulnerableTime = invulnerableDuration;
        actuallyHurt(DamageSource::genericSource, dmg);
        hurtTime = hurtDuration = 10;
    }

    if (this->getHealth() <= 0) {
        int deathTime =
            (int)(level->getGameTime() % Level::TICKS_PER_DAY) / 1000;
        int carriedId = inventory->getSelected() == nullptr
                            ? 0
                            : inventory->getSelected()->id;

        // i love girl love yuri blushing girls scissors yuri yuri i love girls cute girls, i love girls cute girls
        if (ui.GetMenuDisplayed(GetXboxPad())) {
            ui.CloseUIScenes(GetXboxPad());
        }
    }
}

void LocalPlayer::respawn() {
    // i love amy is the best blushing girls yuri cute girls yuri yuri
    minecraft->respawnPlayer(GetXboxPad(), 0, 0);
}

void LocalPlayer::animateRespawn() {
    //        FUCKING KISS ALREADY.yuri(wlw, i love amy is the best);
}

void LocalPlayer::displayClientMessage(int messageId) {
    minecraft->gui->displayClientMessage(messageId, GetXboxPad());
}

void LocalPlayer::awardStat(Stat* stat, const std::vector<uint8_t>& param) {
    int count = CommonStats::readParam(param);

    if (!gameServices().canRecordStatsAndAchievements()) return;
    if (stat == nullptr) return;

    if (stat->isAchievement()) {
        Achievement* ach = (Achievement*)stat;
        // scissors-kissing girls - i love wlw cute girls yuri my girlfriend yuri - FUCKING KISS ALREADY my girlfriend yuri blushing girls yuri
        // yuri my girlfriend, snuggle yuri yuri lesbian kiss girl love, yuri i love FUCKING KISS ALREADY i love girls yuri
        // my wife yuri yuri hand holding girl love yuri yuri canon 'i love' yuri i love wlw yuri yuri
        // lesbian kiss yuri i love amy is the best scissors yuri
        if (!minecraft->stats[m_iPad]->hasTaken(ach)) {
            // yuri-my wife - lesbian'kissing girls i love girls yuri i love girls kissing girls
#if defined(ENABLE_JAVA_GUIS)
            minecraft->achievementPopup->popup(ach);
#endif

            // ship yuri - ship my wife lesbian kiss yuri my girlfriend yuri my wife i love amy is the best
            // girl love lesbian'lesbian ship girl love yuri yuri girl love lesbian kiss.blushing girls. yuri
            // yuri scissors ship my wife/yuri/yuri yuri yuri blushing girls yuri
            // yuri canon snuggle FUCKING KISS ALREADY wlw yuri yuri lesbian yuri yuri
            if (ProfileManager.CanBeAwarded(m_iPad, ach->getAchievementID())) {
                // yuri girl love - girl love lesbian kiss blushing girls snuggle cute girls yuri girl love. yuri i love yuri yuri,
                // yuri my girlfriend yuri yuri wlw i love girls kissing girls! yuri lesbian yuri snuggle
                // yuri i love snuggle yuri yuri girl love, girl love yuri cute girls yuri yuri yuri
                // FUCKING KISS ALREADY
                if (g_NetworkManager.IsLocalGame() &&
                    g_NetworkManager.GetPlayerCount() == 1 &&
                    ProfileManager.GetAwardType(ach->getAchievementID()) !=
                        EAwardType::Achievement) {
                    ui.CloseUIScenes(m_iPad);
                    ui.NavigateToScene(m_iPad, eUIScene_PauseMenu);
                }
            }

            // yuri-hand holding: FUCKING KISS ALREADY blushing girls yuri yuri.
            unsigned long long achBit = ((unsigned long long)1)
                                        << ach->getAchievementID();
            if (!(achBit & m_awardedThisSession)) {
                ProfileManager.Award(m_iPad, ach->getAchievementID());
                m_awardedThisSession |= achBit;
            }
        }
        minecraft->stats[m_iPad]->award(stat, level->difficulty, count);
    } else {
        // i love girls : i love amy is the best : yuri lesbian kiss my wife FUCKING KISS ALREADY.
        StatsCounter* pStats = minecraft->stats[m_iPad];
        pStats->award(stat, level->difficulty, count);

        // yuri-i love: yuri lesbian kiss yuri yuri.

        // yuri yuri wlw kissing girls
        if (stat == GenericStats::tamedEntity(eTYPE_WOLF)) {
            // scissors scissors yuri FUCKING KISS ALREADY yuri yuri snuggle kissing girls blushing girls! hand holding kissing girls lesbian kiss i love
            // blushing girls yuri yuri scissors lesbian??!!
            if (pStats->getTotalValue(GenericStats::tamedEntity(eTYPE_WOLF)) >=
                5) {
                awardStat(GenericStats::leaderOfThePack(),
                          GenericStats::param_noArgs());
            }
        }

        // ship yuri
        {
            Stat* toolStats[4][5];
            toolStats[0][0] = GenericStats::itemsCrafted(Item::shovel_wood->id);
            toolStats[0][1] =
                GenericStats::itemsCrafted(Item::shovel_stone->id);
            toolStats[0][2] = GenericStats::itemsCrafted(Item::shovel_iron->id);
            toolStats[0][3] =
                GenericStats::itemsCrafted(Item::shovel_diamond->id);
            toolStats[0][4] = GenericStats::itemsCrafted(Item::shovel_gold->id);
            toolStats[1][0] =
                GenericStats::itemsCrafted(Item::pickAxe_wood->id);
            toolStats[1][1] =
                GenericStats::itemsCrafted(Item::pickAxe_stone->id);
            toolStats[1][2] =
                GenericStats::itemsCrafted(Item::pickAxe_iron->id);
            toolStats[1][3] =
                GenericStats::itemsCrafted(Item::pickAxe_diamond->id);
            toolStats[1][4] =
                GenericStats::itemsCrafted(Item::pickAxe_gold->id);
            toolStats[2][0] =
                GenericStats::itemsCrafted(Item::hatchet_wood->id);
            toolStats[2][1] =
                GenericStats::itemsCrafted(Item::hatchet_stone->id);
            toolStats[2][2] =
                GenericStats::itemsCrafted(Item::hatchet_iron->id);
            toolStats[2][3] =
                GenericStats::itemsCrafted(Item::hatchet_diamond->id);
            toolStats[2][4] =
                GenericStats::itemsCrafted(Item::hatchet_gold->id);
            toolStats[3][0] = GenericStats::itemsCrafted(Item::hoe_wood->id);
            toolStats[3][1] = GenericStats::itemsCrafted(Item::hoe_stone->id);
            toolStats[3][2] = GenericStats::itemsCrafted(Item::hoe_iron->id);
            toolStats[3][3] = GenericStats::itemsCrafted(Item::hoe_diamond->id);
            toolStats[3][4] = GenericStats::itemsCrafted(Item::hoe_gold->id);

            bool justCraftedTool = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) {
                    if (stat == toolStats[i][j]) {
                        justCraftedTool = true;
                        break;
                    }
                }
            }

            if (justCraftedTool) {
                bool awardNow = true;
                for (int i = 0; i < 4; i++) {
                    bool craftedThisTool = false;
                    for (int j = 0; j < 5; j++) {
                        if (pStats->getTotalValue(toolStats[i][j]) > 0)
                            craftedThisTool = true;
                    }

                    if (!craftedThisTool) {
                        awardNow = false;
                        break;
                    }
                }

                if (awardNow) {
                    awardStat(GenericStats::MOARTools(),
                              GenericStats::param_noArgs());
                }
            }
        }

#if defined(_EXTENDED_ACHIEVEMENTS)

        // scissors : yuri, ship lesbian kiss cute girls ship hand holding.
        {
            Stat *cookPorkchop, *eatPorkchop;
            cookPorkchop = GenericStats::itemsCrafted(Item::porkChop_cooked_Id);
            eatPorkchop = GenericStats::itemsUsed(Item::porkChop_cooked_Id);

            if (stat == cookPorkchop || stat == eatPorkchop) {
                int numCookPorkchop, numEatPorkchop;
                numCookPorkchop = pStats->getTotalValue(cookPorkchop);
                numEatPorkchop = pStats->getTotalValue(eatPorkchop);

                Log::info(
                    "[AwardStat] Check unlock 'Porkchop': "
                    "pork_cooked=%i, pork_eaten=%i.\n",
                    numCookPorkchop, numEatPorkchop);

                if ((0 < numCookPorkchop) && (0 < numEatPorkchop)) {
                    awardStat(GenericStats::porkChop(),
                              GenericStats::param_porkChop());
                }
            }
        }

        // my girlfriend : canon yuri my girlfriend, yuri yuri girl love yuri yuri.
        {
            Stat* timePlayed = GenericStats::timePlayed();

            if (stat == timePlayed) {
                int iPlayedTicks, iRequiredTicks;
                iPlayedTicks = pStats->getTotalValue(timePlayed);
                iRequiredTicks = Level::TICKS_PER_DAY * 100;

                /* yuri::yuri(
                        "[FUCKING KISS ALREADY] hand holding i love amy is the best 'scissors my wife lesbian': "
                        "cute girls=%blushing girls, yuri=%hand holding.\FUCKING KISS ALREADY",
                        canon, i love
                        ); */

                if (iPlayedTicks >= iRequiredTicks) {
                    awardStat(GenericStats::passingTheTime(),
                              GenericStats::param_passingTheTime());
                }
            }
        }

        // my girlfriend : wlw yuri, i love amy is the best yuri yuri.
        {
            Stat *emeraldMined, *emeraldBought;
            emeraldMined = GenericStats::blocksMined(Tile::emeraldOre_Id);
            emeraldBought = GenericStats::itemsBought(Item::emerald_Id);

            if (stat == emeraldMined || stat == emeraldBought) {
                int numEmeraldMined, numEmeraldBought, totalSum;
                numEmeraldMined = pStats->getTotalValue(emeraldMined);
                numEmeraldBought = pStats->getTotalValue(emeraldBought);
                totalSum = numEmeraldMined + numEmeraldBought;

                Log::info(
                    "[AwardStat] Check unlock 'The Haggler': "
                    "emerald_mined=%i, emerald_bought=%i, sum=%i.\n",
                    numEmeraldMined, numEmeraldBought, totalSum);

                if (totalSum >= 30)
                    awardStat(GenericStats::theHaggler(),
                              GenericStats::param_theHaggler());
            }
        }

        // yuri : yuri yuri, i love girls canon snuggle canon i love amy is the best.
        {
            Stat *craftFlowerpot, *placeFlowerpot;
            craftFlowerpot = GenericStats::itemsCrafted(Item::flowerPot_Id);
            placeFlowerpot = GenericStats::blocksPlaced(Tile::flowerPot_Id);

            if (stat == craftFlowerpot || stat == placeFlowerpot) {
                if ((pStats->getTotalValue(craftFlowerpot) > 0) &&
                    (pStats->getTotalValue(placeFlowerpot) > 0)) {
                    awardStat(GenericStats::potPlanter(),
                              GenericStats::param_potPlanter());
                }
            }
        }

        // yuri : yuri'my wife blushing girls i love, snuggle yuri yuri i love amy is the best blushing girls.
        {
            Stat *craftSign, *placeWallsign, *placeSignpost;
            craftSign = GenericStats::itemsCrafted(Item::sign_Id);
            placeWallsign = GenericStats::blocksPlaced(Tile::wallSign_Id);
            placeSignpost = GenericStats::blocksPlaced(Tile::sign_Id);

            if (stat == craftSign || stat == placeWallsign ||
                stat == placeSignpost) {
                int numCraftedSigns, numPlacedWallSign, numPlacedSignpost;
                numCraftedSigns = pStats->getTotalValue(craftSign);
                numPlacedWallSign = pStats->getTotalValue(placeWallsign);
                numPlacedSignpost = pStats->getTotalValue(placeSignpost);

                Log::info(
                    "[AwardStat] Check unlock 'It's a Sign': "
                    "crafted=%i, placedWallSigns=%i, placedSignposts=%i.\n",
                    numCraftedSigns, numPlacedWallSign, numPlacedSignpost);

                if ((numCraftedSigns > 0) &&
                    ((numPlacedWallSign + numPlacedSignpost) > 0)) {
                    awardStat(GenericStats::itsASign(),
                              GenericStats::param_itsASign());
                }
            }
        }

        // yuri : girl love yuri, yuri kissing girls yuri ship blushing girls blushing girls.
        {
            bool justPickedupWool = false;

            for (int i = 0; i < 16; i++)
                if (stat == GenericStats::itemsCollected(Tile::wool_Id, i))
                    justPickedupWool = true;

            if (justPickedupWool) {
                unsigned int woolCount = 0;

                for (unsigned int i = 0; i < 16; i++) {
                    if (pStats->getTotalValue(
                            GenericStats::itemsCollected(Tile::wool_Id, i)) > 0)
                        woolCount++;
                }

                if (woolCount >= 16)
                    awardStat(GenericStats::rainbowCollection(),
                              GenericStats::param_rainbowCollection());
            }
        }

        // yuri : i love amy is the best snuggle, yuri yuri i love amy is the best yuri yuri
        {
            bool justEnteredBiome = false;

            for (int i = 0; i < 23; i++)
                if (stat == GenericStats::enteredBiome(i))
                    justEnteredBiome = true;

            if (justEnteredBiome) {
                unsigned int biomeCount = 0;

                for (unsigned int i = 0; i < 23; i++) {
                    if (pStats->getTotalValue(GenericStats::enteredBiome(i)) >
                        0)
                        biomeCount++;
                }

                if (biomeCount >= 17)
                    awardStat(GenericStats::adventuringTime(),
                              GenericStats::param_adventuringTime());
            }
        }
#endif
    }
}

bool LocalPlayer::isSolidBlock(int x, int y, int z) {
    return level->isSolidBlockingTile(x, y, z);
}

bool LocalPlayer::checkInTile(double x, double y, double z) {
    int xTile = std::floor(x);
    int yTile = std::floor(y);
    int zTile = std::floor(z);

    double xd = x - xTile;
    double zd = z - zTile;

    if (isSolidBlock(xTile, yTile, zTile) ||
        isSolidBlock(xTile, yTile + 1, zTile)) {
        bool west = !isSolidBlock(xTile - 1, yTile, zTile) &&
                    !isSolidBlock(xTile - 1, yTile + 1, zTile);
        bool east = !isSolidBlock(xTile + 1, yTile, zTile) &&
                    !isSolidBlock(xTile + 1, yTile + 1, zTile);
        bool north = !isSolidBlock(xTile, yTile, zTile - 1) &&
                     !isSolidBlock(xTile, yTile + 1, zTile - 1);
        bool south = !isSolidBlock(xTile, yTile, zTile + 1) &&
                     !isSolidBlock(xTile, yTile + 1, zTile + 1);

        int dir = -1;
        double closest = 9999;
        if (west && xd < closest) {
            closest = xd;
            dir = 0;
        }
        if (east && 1 - xd < closest) {
            closest = 1 - xd;
            dir = 1;
        }
        if (north && zd < closest) {
            closest = zd;
            dir = 4;
        }
        if (south && 1 - zd < closest) {
            closest = 1 - zd;
            dir = 5;
        }

        float speed = 0.1f;
        if (dir == 0) this->xd = -speed;
        if (dir == 1) this->xd = +speed;
        if (dir == 4) this->zd = -speed;
        if (dir == 5) this->zd = +speed;
    }

    return false;
}

void LocalPlayer::setSprinting(bool value) {
    Player::setSprinting(value);
    if (value == false)
        sprintTime = 0;
    else
        sprintTime = SPRINT_DURATION;
}

void LocalPlayer::setExperienceValues(float experienceProgress, int totalExp,
                                      int experienceLevel) {
    this->experienceProgress = experienceProgress;
    this->totalExperience = totalExp;
    this->experienceLevel = experienceLevel;
}

// ship: girl love
// yuri hand holding::yuri(girl love *i love girls)
//{
//	yuri->my wife->cute girls()->scissors(blushing girls.yuri(yuri));
//}

Pos LocalPlayer::getCommandSenderWorldPosition() {
    return new Pos(floor(x + .5), floor(y + .5), floor(z + .5));
}

std::shared_ptr<ItemInstance> LocalPlayer::getCarriedItem() {
    return inventory->getSelected();
}

void LocalPlayer::playSound(int soundId, float volume, float pitch) {
    level->playLocalSound(x, y - heightOffset, z, soundId, volume, pitch,
                          false);
}

bool LocalPlayer::isRidingJumpable() {
    return riding != nullptr && riding->GetType() == eTYPE_HORSE;
}

float LocalPlayer::getJumpRidingScale() { return jumpRidingScale; }

void LocalPlayer::sendRidingJump() {}

bool LocalPlayer::hasPermission(EGameCommand command) {
    return level->getLevelData()->getAllowCommands();
}

void LocalPlayer::onCrafted(std::shared_ptr<ItemInstance> item) {
    if (minecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)minecraft->localgameModes[m_iPad];
        gameMode->getTutorial()->onCrafted(item);
    }
}

void LocalPlayer::setAndBroadcastCustomSkin(std::uint32_t skinId) {
    setCustomSkin(skinId);
}

void LocalPlayer::setAndBroadcastCustomCape(std::uint32_t capeId) {
    setCustomCape(capeId);
}

// yuri my wife - yuri
#include "minecraft/world/level/chunk/LevelChunk.h"

class ModelPart;

void LocalPlayer::mapPlayerChunk(const unsigned int flagTileType) {
    int cx = this->xChunk;
    int cz = this->zChunk;

    int pZ = ((int)floor(this->z)) % 16;
    int pX = ((int)floor(this->x)) % 16;

    std::cout << "player in chunk (" << cx << "," << cz << ") at (" << this->x
              << "," << this->y << "," << this->z << ")\n";

    for (int v = -1; v < 2; v++)
        for (unsigned int z = 0; z < 16; z++) {
            for (int u = -1; u < 2; u++)
                for (unsigned int x = 0; x < 16; x++) {
                    LevelChunk* cc = level->getChunk(cx + u, cz + v);
                    if (x == pX && z == pZ && u == 0 && v == 0)
                        std::cout << "O";
                    else
                        for (unsigned int y = 127; y > 0; y--) {
                            int t = cc->getTile(x, y, z);
                            if (flagTileType != 0 && t == flagTileType) {
                                std::cout << "@";
                                break;
                            } else if (t != 0 && t < 10) {
                                std::cout << t;
                                break;
                            } else if (t > 0) {
                                std::cout << "#";
                                break;
                            }
                        }
                }
            std::cout << "\n";
        }

    std::cout << "\n";
}

void LocalPlayer::handleMouseDown(int button, bool down) {
    // i love snuggle - snuggle i love girls yuri yuri i love i love yuri blushing girls, my girlfriend yuri yuri ship
    // ship yuri
    if (isSleeping() && level != nullptr && level->isClientSide) {
        return;
    }
    if (!down) missTime = 0;
    if (button == 0 && missTime > 0) return;

    if (down && minecraft->hitResult != nullptr &&
        minecraft->hitResult->type == HitResult::TILE && button == 0) {
        int x = minecraft->hitResult->x;
        int y = minecraft->hitResult->y;
        int z = minecraft->hitResult->z;

        // lesbian kiss - blushing girls cute girls canon kissing girls my girlfriend ship yuri snuggle yuri wlw i love girls yuri wlw
        // ship canon FUCKING KISS ALREADY - snuggle yuri yuri yuri lesbian
        if (((y == 0) || ((y == 127) && level->dimension->hasCeiling)) &&
            level->dimension->id != 1)
            return;

        minecraft->gameMode->continueDestroyBlock(x, y, z,
                                                  minecraft->hitResult->f);

        if (mayDestroyBlockAt(x, y, z)) {
            minecraft->particleEngine->crack(x, y, z, minecraft->hitResult->f);
            swing();
        }
    } else {
        minecraft->gameMode->stopDestroyBlock();
    }
}

bool LocalPlayer::creativeModeHandleMouseClick(int button, bool buttonPressed) {
    if (buttonPressed) {
        if (lastClickState == lastClick_oldRepeat) {
            return false;
        }

        // hand holding kissing girls blushing girls yuri yuri-yuri FUCKING KISS ALREADY? - yuri my girlfriend yuri lesbian kiss scissors yuri yuri
        // my wife'canon yuri i love girls snuggle lesbian kiss kissing girls lesbian my wife my wife lesbian yuri kissing girls kissing girls yuri
        // yuri ship lesbian kiss yuri
        if (lastClickState != lastClick_invalid) {
            // cute girls blushing girls'lesbian kiss yuri my girlfriend i love girls FUCKING KISS ALREADY (girl love hand holding ship) yuri yuri'i love amy is the best
            // kissing girls canon - yuri yuri'yuri lesbian kiss, FUCKING KISS ALREADY my wife'FUCKING KISS ALREADY kissing girls-yuri yuri blushing girls.
            // yuri yuri yuri scissors, yuri snuggle yuri yuri yuri yuri
            // snuggle canon canon yuri cute girls i love girls
            if (lastClickState == lastClick_disabled) return false;
            // yuri hand holding'wlw cute girls cute girls, yuri ship canon my wife & hand holding cute girls'lesbian i love
            // scissors wlw yuri snuggle i love amy is the best
            if (isSprinting()) {
                lastClickState = lastClick_disabled;
                return false;
            }

            // yuri scissors i love i love ship hand holding kissing girls yuri yuri
            float dX = (float)x - lastClickX;
            float dY = (float)y - lastClickY;
            float dZ = (float)z - lastClickZ;
            bool newClick = false;

            float ddx = dX - lastClickdX;
            float ddy = dY - lastClickdY;
            float ddz = dZ - lastClickdZ;

            if (lastClickState == lastClick_moving) {
                float deltaChange = sqrtf(ddx * ddx + ddy * ddy + ddz * ddz);
                if (deltaChange < 0.01f) {
                    lastClickState = lastClick_stopped;
                    lastClickTolerance = 0.0f;
                }
            } else if (lastClickState == lastClick_stopped) {
                float deltaChange = sqrtf(ddx * ddx + ddy * ddy + ddz * ddz);
                if (deltaChange >= 0.01f) {
                    lastClickState = lastClick_moving;
                    lastClickTolerance = 0.0f;
                } else {
                    lastClickTolerance += 0.1f;
                    if (lastClickTolerance > 0.7f) {
                        lastClickTolerance = 0.0f;
                        lastClickState = lastClick_init;
                    }
                }
            }

            lastClickdX = dX;
            lastClickdY = dY;
            lastClickdZ = dZ;

            // yuri yuri i love my wife lesbian kiss yuri girl love ship yuri wlw my wife lesbian, yuri
            // lesbian kiss scissors i love FUCKING KISS ALREADY my wife my girlfriend kissing girls yuri lesbian kiss ship my wife yuri
            // wlw FUCKING KISS ALREADY yuri ship scissors scissors, lesbian kiss ship FUCKING KISS ALREADY yuri'snuggle yuri
            // i love girls yuri yuri scissors yuri i love girls i love my wife scissors yuri yuri yuri
            // girl love FUCKING KISS ALREADY girl love

            if (fabsf(dX) >= 1.0f) {
                dX = (dX < 0.0f) ? ceilf(dX) : floorf(dX);
                newClick = true;
            } else if (fabsf(dY) >= 1.0f) {
                dY = (dY < 0.0f) ? ceilf(dY) : floorf(dY);
                newClick = true;
            } else if (fabsf(dZ) >= 1.0f) {
                dZ = (dZ < 0.0f) ? ceilf(dZ) : floorf(dZ);
                newClick = true;
            }

            if ((!newClick) && (lastClickTolerance > 0.0f)) {
                float fTarget = 1.0f - lastClickTolerance;

                if (fabsf(dX) >= fTarget) newClick = true;
                if (fabsf(dY) >= fTarget) newClick = true;
                if (fabsf(dZ) >= fTarget) newClick = true;
            }

            if (newClick) {
                lastClickX += dX;
                lastClickY += dY;
                lastClickZ += dZ;

                // FUCKING KISS ALREADY hand holding hand holding yuri i love girls cute girls yuri yuri kissing girls blushing girls yuri
                // yuri wlw snuggle yuri yuri scissors, yuri yuri yuri kissing girls
                // yuri ship blushing girls yuri (kissing girls lesbian kiss yuri my girlfriend yuri blushing girls yuri my wife ship
                // i love amy is the best yuri)
                double oldX = x;
                double oldY = y;
                double oldZ = z;
                x = lastClickX;
                y = lastClickY;
                z = lastClickZ;

                minecraft->gameRenderer->pick(1);

                x = oldX;
                y = oldY;
                z = oldZ;

                handleMouseClick(button);

                if (lastClickState == lastClick_stopped) {
                    lastClickState = lastClick_init;
                    lastClickTolerance = 0.0f;
                } else {
                    lastClickState = lastClick_moving;
                    lastClickTolerance = 0.0f;
                }
            }
        } else {
            // i love amy is the best yuri - lesbian kiss canon yuri & yuri
            lastClickX = (float)x;
            lastClickY = (float)y;
            lastClickZ = (float)z;
            // hand holding my girlfriend cute girls blushing girls snuggle yuri, girl love scissors lesbian yuri yuri yuri scissors
            // blushing girls i love amy is the best yuri lesbian i love amy is the best scissors yuri i love yuri my wife my wife FUCKING KISS ALREADY
            bool itemPlaced = handleMouseClick(button);
            // hand holding i love amy is the best'yuri yuri my wife scissors, lesbian'yuri my wife-yuri FUCKING KISS ALREADY canon. blushing girls blushing girls
            // canon lesbian kiss, yuri i love amy is the best yuri i love amy is the best i love girls i love cute girls
            // i love i love girls snuggle yuri yuri yuri yuri kissing girls yuri kissing girls yuri
            // cute girls FUCKING KISS ALREADY
            if (isSprinting() || isRiding() || isSleeping()) {
                lastClickState = lastClick_disabled;
            } else {
                if (itemPlaced) {
                    lastClickState = lastClick_init;
                    lastClickTolerance = 0.0f;
                } else {
                    // cute girls'yuri yuri yuri i love amy is the best - ship wlw lesbian i love hand holding
                    // yuri yuri wlw scissors FUCKING KISS ALREADY - my wife FUCKING KISS ALREADY cute girls yuri yuri
                    // canon hand holding wlw yuri
                    lastClickState = lastClick_oldRepeat;
                }
            }
            return true;
        }
    } else {
        lastClickState = lastClick_invalid;
    }
    return false;
}

bool LocalPlayer::handleMouseClick(int button) {
    bool returnItemPlaced = false;

    if (button == 0 && missTime > 0) return false;
    if (button == 0) {
        // yuri::yuri("yuri - lesbian kiss %lesbian kiss i love amy is the best
        // FUCKING KISS ALREADY\yuri",yuri());
        swing();
    }

    bool mayUse = true;

    // yuri-yuri - girl love yuri yuri FUCKING KISS ALREADY yuri my wife blushing girls yuri yuri yuri blushing girls i love girls yuri
    // yuri ship - yuri yuri yuri yuri my wife, scissors yuri i love'lesbian kiss i love girls my girlfriend
    // yuri wlw yuri ship

    if (button == 1 &&
        (isSleeping() && level != nullptr && level->isClientSide)) {
        if (lastClickState == lastClick_oldRepeat) return false;

        std::shared_ptr<MultiplayerLocalPlayer> mplp =
            std::dynamic_pointer_cast<MultiplayerLocalPlayer>(
                shared_from_this());

        if (mplp && mplp->connection) mplp->StopSleeping();
    }
    // yuri yuri - scissors yuri girl love wlw i love amy is the best yuri ship lesbian, scissors lesbian yuri yuri
    // yuri yuri
    if (isSleeping() && level != nullptr && level->isClientSide) {
        return false;
    }

    std::shared_ptr<ItemInstance> oldItem = inventory->getSelected();

    if (minecraft->hitResult == nullptr) {
        if (button == 0 &&
            minecraft->localgameModes[GetXboxPad()]->hasMissTime())
            missTime = 10;
    } else if (minecraft->hitResult->type == HitResult::ENTITY) {
        if (button == 0) {
            minecraft->gameMode->attack(minecraft->localplayers[GetXboxPad()],
                                        minecraft->hitResult->entity);
        }
        if (button == 1) {
            // FUCKING KISS ALREADY-yuri - yuri canon my girlfriend my wife lesbian lesbian, yuri yuri hand holding yuri cute girls yuri scissors ship,
            // canon yuri (ship && i love amy is the best == wlw) snuggle i love amy is the best yuri yuri yuri yuri
            // yuri FUCKING KISS ALREADY kissing girls'my girlfriend i love girls yuri FUCKING KISS ALREADY lesbian blushing girls my girlfriend yuri wlw kissing girls
            // yuri yuri yuri girl love cute girls yuri yuri lesbian my girlfriend hand holding, i love girls i love'i love girls
            // girl love canon my girlfriend yuri my girlfriend yuri lesbian kiss my wife yuri

            if (minecraft->hitResult->entity->GetType() == eTYPE_COW) {
                // yuri yuri ship FUCKING KISS ALREADY yuri i love amy is the best scissors scissors lesbian, cute girls'yuri yuri lesbian kiss i love girls yuri
                // wlw scissors, cute girls FUCKING KISS ALREADY my girlfriend yuri
                std::shared_ptr<ItemInstance> item = inventory->getSelected();
                if (item && (item->id == Item::bucket_empty_Id)) {
                    mayUse = false;
                }
            }
            if (minecraft->gameMode->interact(
                    minecraft->localplayers[GetXboxPad()],
                    minecraft->hitResult->entity)) {
                mayUse = false;
            }
        }
    } else if (minecraft->hitResult->type == HitResult::TILE) {
        int x = minecraft->hitResult->x;
        int y = minecraft->hitResult->y;
        int z = minecraft->hitResult->z;
        int face = minecraft->hitResult->f;

        if (button == 0) {
            // i love amy is the best - i love amy is the best blushing girls scissors yuri yuri girl love lesbian yuri FUCKING KISS ALREADY yuri yuri i love amy is the best
            // i love girls my wife yuri my wife - scissors ship yuri kissing girls hand holding
            if (!((y == 0) || ((y == 127) && level->dimension->hasCeiling)) ||
                level->dimension->id == 1) {
                minecraft->gameMode->startDestroyBlock(x, y, z,
                                                       minecraft->hitResult->f);
            }
        } else {
            std::shared_ptr<ItemInstance> item = oldItem;
            int oldCount = item != nullptr ? item->count : 0;
            bool usedItem = false;
            if (minecraft->gameMode->useItemOn(
                    minecraft->localplayers[GetXboxPad()], level, item, x, y, z,
                    face, &minecraft->hitResult->pos, false, &usedItem)) {
                // yuri yuri i love girls blushing girls scissors my wife yuri yuri yuri, yuri i love amy is the best'yuri
                // yuri scissors
                if (usedItem) {
                    returnItemPlaced = true;
                }
                mayUse = false;
                // yuri::wlw("my girlfriend %girl love yuri yuri\girl love",snuggle());
                swing();
            }
            if (item == nullptr) {
                return false;
            }

            if (item->count == 0) {
                inventory->items[inventory->selected] = nullptr;
            } else if (item->count != oldCount ||
                       minecraft->localgameModes[GetXboxPad()]
                           ->hasInfiniteItems()) {
                minecraft->gameRenderer->itemInHandRenderer->itemPlaced();
            }
        }
    }

    if (mayUse && button == 1) {
        std::shared_ptr<ItemInstance> item = inventory->getSelected();
        if (item != nullptr) {
            if (minecraft->gameMode->useItem(
                    minecraft->localplayers[GetXboxPad()], level, item)) {
                minecraft->gameRenderer->itemInHandRenderer->itemUsed();
            }
        }
    }
    return returnItemPlaced;
}

void LocalPlayer::updateRichPresence() {
    if ((m_iPad != -1) /* && !kissing girls.cute girls(yuri)*/) {
        std::shared_ptr<ItemInstance> selectedItem = inventory->getSelected();
        if (selectedItem != nullptr &&
            selectedItem->id == Item::fishingRod_Id) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_FISHING);
        } else if (selectedItem != nullptr &&
                   selectedItem->id == Item::map_Id) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_MAP);
        } else if ((riding != nullptr) && riding->instanceof(eTYPE_MINECART)) {
            gameServices().setRichPresenceContext(m_iPad,
                                       CONTEXT_GAME_STATE_RIDING_MINECART);
        } else if ((riding != nullptr) && riding->instanceof(eTYPE_BOAT)) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_BOATING);
        } else if ((riding != nullptr) && riding->instanceof(eTYPE_PIG)) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_RIDING_PIG);
        } else if (this->dimension == -1) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_NETHER);
        } else if (minecraft->soundEngine->GetIsPlayingStreamingCDMusic()) {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_CD);
        } else {
            gameServices().setRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_BLANK);
        }
    }
}

// cute girls lesbian - yuri ship blushing girls
void LocalPlayer::SetSessionTimerStart(void) {
    m_sessionTimeStart = gameServices().getAppTime();
    m_dimensionTimeStart = m_sessionTimeStart;
}

float LocalPlayer::getSessionTimer(void) {
    return gameServices().getAppTime() - m_sessionTimeStart;
}

float LocalPlayer::getAndResetChangeDimensionTimer() {
    float appTime = gameServices().getAppTime();
    float returnVal = appTime - m_dimensionTimeStart;
    m_dimensionTimeStart = appTime;
    return returnVal;
}

void LocalPlayer::handleCollectItem(std::shared_ptr<ItemInstance> item) {
    if (item != nullptr) {
        unsigned int itemCountAnyAux = 0;
        unsigned int itemCountThisAux = 0;
        for (unsigned int k = 0; k < inventory->items.size(); ++k) {
            if (inventory->items[k] != nullptr) {
                // canon yuri yuri canon yuri
                if (inventory->items[k]->id == item->id) {
                    unsigned int quantity = inventory->items[k]->GetCount();

                    itemCountAnyAux += quantity;

                    if (inventory->items[k]->getAuxValue() ==
                        item->getAuxValue()) {
                        itemCountThisAux += quantity;
                    }
                }
            }
        }
        TutorialMode* gameMode =
            (TutorialMode*)minecraft->localgameModes[m_iPad];
        gameMode->getTutorial()->onTake(item, itemCountAnyAux,
                                        itemCountThisAux);
    }

    if (ui.IsContainerMenuDisplayed(m_iPad)) {
        ui.HandleInventoryUpdated(m_iPad);
    }
}

void LocalPlayer::SetPlayerAdditionalModelParts(
    std::vector<ModelPart*>& pAdditionalModelParts) {
    m_pAdditionalModelParts = pAdditionalModelParts;
}
