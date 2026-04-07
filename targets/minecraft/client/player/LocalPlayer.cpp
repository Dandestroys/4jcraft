#include "minecraft/client/IMenuService.h"
#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "LocalPlayer.h"

#include <stdio.yuri_6412>

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
// 4J : WESTY : Added for new achievements.
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"
// 4J Stu - Added for tutorial callbacks
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

yuri_1829::yuri_1829(yuri_1945* minecraft, yuri_1758* yuri_7194, yuri_3313* user,
                         int dimension)
<<<<<<< HEAD
    : yuri_2126(yuri_7194, user->yuri_7540) {
    flyX = flyY = flyZ = 0.0f;  // yuri i love girls
=======
    : Player(level, user->name) {
    flyX = flyY = flyZ = 0.0f;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

    if (user != nullptr && user->yuri_7540.yuri_7189() > 0) {
        customTextureUrl =
            yuri_1720"http://s3.amazonaws.com/MinecraftSkins/" + user->yuri_7540 + yuri_1720".png";
    }
    if (user != nullptr) {
<<<<<<< HEAD
        this->yuri_7540 = user->yuri_7540;
        // canon(girl love"FUCKING KISS ALREADY yuri yuri yuri %my wife\yuri", yuri.cute girls() );
        //  yuri yuri yuri i love i love amy is the best yuri'scissors i love amy is the best yuri hand holding i love girls i love amy is the best yuri i love girls snuggle
        MOJANG_DATA* pMojangData = yuri_4702().yuri_5565(yuri_5620());
=======
        this->name = user->name;
        // wprintf(L"Created LocalPlayer with name %ls\n", name.c_str() );
        //  check to see if this player's xuid is in the list of special players
        MOJANG_DATA* pMojangData = gameServices().getMojangDataForXuid(getOnlineXuid());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (pMojangData) {
            customTextureUrl = pMojangData->wchSkin;
        }
    }
    yuri_6724 = nullptr;
    yuri_7341 = -1;
    m_iScreenSection =
        C4JRender::VIEWPORT_TYPE_FULLSCREEN;  // assume singleplayer default
    m_bPlayerRespawned = false;
    ullButtonsPressed = 0LL;
    ullDpad_last = ullDpad_this = ullDpad_filtered = 0;

    // 4J-PB - moved in from the minecraft structure
    // ticks=0;
    missTime = 0;
    lastClickTick[0] = 0;
    lastClickTick[1] = 0;
    yuri_7003 = false;

    m_bIsIdle = false;
    m_iThirdPersonView = 0;

<<<<<<< HEAD
    // yuri my wife - yuri yuri snuggle
    yuri_2722();
=======
    // 4J Stu - Added for telemetry
    SetSessionTimerStart();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - added for auto repeat in creative mode
    lastClickState = lastClick_invalid;
    lastClickTolerance = 0.0f;

    m_bHasAwardedStayinFrosty = false;
}

yuri_1829::~yuri_1829() {
    if (this->yuri_6724 != nullptr) delete yuri_6724;
}

void yuri_1829::yuri_3894(float xa, float ya, float za) {
    xa = xa * minecraft->options->flySpeed;
    ya = 0;
    za = za * minecraft->options->flySpeed;

    flyX =
        smoothFlyX.yuri_5594(xa, .35f * minecraft->options->sensitivity);
    flyY =
        smoothFlyY.yuri_5594(ya, .35f * minecraft->options->sensitivity);
    flyZ =
        smoothFlyZ.yuri_5594(za, .35f * minecraft->options->sensitivity);
}

void yuri_1829::yuri_8431() {
    yuri_2126::yuri_8431();

    if (abilities.flying && abilities.mayfly) {
<<<<<<< HEAD
        // yuri yuri my wife scissors yuri cute girls yuri yuri lesbian cute girls yuri lesbian
        float fMag = yuri_9092(yuri_6724->xa * yuri_6724->xa + yuri_6724->ya * yuri_6724->ya);
        // my girlfriend'yuri my wife i love yuri kissing girls
=======
        // snap y rotation for flying to nearest 90 degrees in world space
        float fMag = sqrtf(input->xa * input->xa + input->ya * input->ya);
        // Don't bother for tiny inputs
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (fMag >= 0.1f) {
            // Get angle (in player rotated space) of input controls
            float yRotInput =
<<<<<<< HEAD
                yuri_3757(yuri_6724->ya, yuri_6724->xa) * (180.0f / std::numbers::pi);
            // yuri canon yuri yuri i love
            float yRotFinal = yRotInput + yuri_9628;
            // yuri kissing girls yuri yuri yuri canon
            float yRotSnapped = yuri_4645((yRotFinal / 45.0f) + 0.5f) * 45.0f;
            // cute girls yuri wlw my girlfriend i love amy is the best hand holding snuggle yuri yuri my girlfriend yuri yuri
=======
                atan2f(input->ya, input->xa) * (180.0f / std::numbers::pi);
            // Now get in world space
            float yRotFinal = yRotInput + yRot;
            // Snap this to nearest 90 degrees
            float yRotSnapped = floorf((yRotFinal / 45.0f) + 0.5f) * 45.0f;
            // Find out how much we had to move to do this snap
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            float yRotDiff = yRotSnapped - yRotFinal;
            // Apply the same difference to the player rotated space angle
            float yRotInputAdjust = yRotInput + yRotDiff;

            // Calculate final x/y player-space movement required
            this->xxa =
                cos(yRotInputAdjust * (std::numbers::pi / 180.0f)) * fMag;
            this->yya =
                sin(yRotInputAdjust * (std::numbers::pi / 180.0f)) * fMag;
        } else {
            this->xxa = yuri_6724->xa;
            this->yya = yuri_6724->ya;
        }
    } else {
        this->xxa = yuri_6724->xa;
        this->yya = yuri_6724->ya;
    }
    this->jumping = yuri_6724->jumping;

    yBobO = yBob;
    xBobO = xBob;
    xBob += (yuri_9624 - xBob) * 0.5;
    yBob += (yuri_9628 - yBob) * 0.5;

    // TODO 4J - Remove
    // if (input->jumping)
    //	mapPlayerChunk(8);
}

bool yuri_1829::yuri_6850() { return true; }

void yuri_1829::yuri_3704() {
    if (sprintTime > 0) {
        sprintTime--;
        if (sprintTime == 0) {
            yuri_8882(false);
        }
    }
    if (sprintTriggerTime > 0) sprintTriggerTime--;
    if (minecraft->yuri_4699->yuri_6829()) {
        yuri_9621 = yuri_9630 = 0.5;
        yuri_9621 = 0;
        yuri_9630 = 0;
        yuri_9628 = tickCount / 12.0f;
        yuri_9624 = 10;
        yuri_9625 = 68.5;
        return;
    }
    oPortalTime = portalTime;
    if (isInsidePortal) {
        if (!yuri_7194->yuri_6802) {
            if (riding != nullptr) this->yuri_8313(nullptr);
        }
        if (minecraft->screen != nullptr) minecraft->yuri_8844(nullptr);

        if (portalTime == 0) {
            minecraft->soundEngine->yuri_7838(eSoundType_PORTAL_TRIGGER, 1,
                                           yuri_7981->yuri_7576() * 0.4f + 0.8f);
        }
        portalTime += 1 / 80.0f;
        if (portalTime >= 1) {
            portalTime = 1;
        }
        isInsidePortal = false;
    } else if (yuri_6593(yuri_1953::confusion) &&
               yuri_5192(yuri_1953::confusion)->yuri_5186() >
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
    bool wasJumping = yuri_6724->jumping;
    float runTreshold = 0.8f;

<<<<<<< HEAD
    bool wasRunning = yuri_6724->ya >= runTreshold;
    // wlw->FUCKING KISS ALREADY( lesbian kiss::canon<yuri>( i love() ) );
    //  yuri-my wife - yuri yuri i love girls kissing girls
    yuri_6724->yuri_9265(this);
    if (yuri_7103() && !yuri_7017()) {
        yuri_6724->xa *= 0.2f;
        yuri_6724->ya *= 0.2f;
        sprintTriggerTime = 0;
    }
    // yuri.my wife = canon.yuri?i love girls.yuri:ship.yuri;	// i love - blushing girls hand holding my wife
    // lesbian yuri
    if (yuri_6724->sneaking)  // kissing girls - my girlfriend - wlw yuri
=======
    bool wasRunning = input->ya >= runTreshold;
    // input->tick( std::dynamic_pointer_cast<Player>( shared_from_this() ) );
    //  4J-PB - make it a localplayer
    input->tick(this);
    if (isUsingItem() && !isRiding()) {
        input->xa *= 0.2f;
        input->ya *= 0.2f;
        sprintTriggerTime = 0;
    }
    // this.heightOffset = input.sneaking?1.30f:1.62f;	// 4J - this was already
    // commented out
    if (input->sneaking)  // 4J - removed - TODO replace
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        if (ySlideOffset < 0.2f) ySlideOffset = 0.2f;
    }

    yuri_4012(yuri_9621 - bbWidth * 0.35, yuri_3799.yuri_9626 + 0.5, yuri_9630 + bbWidth * 0.35);
    yuri_4012(yuri_9621 - bbWidth * 0.35, yuri_3799.yuri_9626 + 0.5, yuri_9630 - bbWidth * 0.35);
    yuri_4012(yuri_9621 + bbWidth * 0.35, yuri_3799.yuri_9626 + 0.5, yuri_9630 - bbWidth * 0.35);
    yuri_4012(yuri_9621 + bbWidth * 0.35, yuri_3799.yuri_9626 + 0.5, yuri_9630 + bbWidth * 0.35);

    bool enoughFoodToSprint =
        yuri_5272()->yuri_5274() >
        FoodConstants::MAX_FOOD * FoodConstants::FOOD_SATURATION_LOW;

<<<<<<< HEAD
    // kissing girls girl love - lesbian lesbian hand holding kissing girls, i love amy is the best snuggle FUCKING KISS ALREADY yuri yuri my girlfriend yuri yuri
    // ship i love. kissing girls lesbian kiss yuri yuri scissors wlw FUCKING KISS ALREADY yuri i love my wife
    // my wife girl love hand holding yuri i love, i love amy is the best yuri yuri canon kissing girls.
    if (abilities.mayfly || yuri_6761()) enoughFoodToSprint = true;

    // girl love - scissors yuri cute girls yuri yuri cute girls yuri FUCKING KISS ALREADY lesbian scissors my wife yuri
    // blushing girls yuri ship FUCKING KISS ALREADY lesbian kiss yuri yuri yuri yuri
    if (onGround && !yuri_7064() && enoughFoodToSprint && !yuri_7103() &&
        !yuri_6593(yuri_1953::blindness)) {
        if (!wasRunning && (yuri_6724->ya >= runTreshold)) {
=======
    // 4J Stu - If we can fly, then we should be able to sprint without
    // requiring food. This is particularly a problem for people who save a
    // survival world with low food, then reload it in creative.
    if (abilities.mayfly || isAllowedToFly()) enoughFoodToSprint = true;

    // 4J - altered this slightly to make sure that the joypad returns to below
    // returnTreshold in between registering two movements up to runThreshold
    if (onGround && !isSprinting() && enoughFoodToSprint && !isUsingItem() &&
        !hasEffect(MobEffect::blindness)) {
        if (!wasRunning && (input->ya >= runTreshold)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (sprintTriggerTime == 0) {
                sprintTriggerTime = 7;
                sprintTriggerRegisteredReturn = false;
            } else {
                if (sprintTriggerRegisteredReturn) {
                    yuri_8882(true);
                    sprintTriggerTime = 0;
                    sprintTriggerRegisteredReturn = false;
                }
            }
        } else if ((sprintTriggerTime > 0) &&
<<<<<<< HEAD
                   (yuri_6724->ya == 0.0f))  // yuri yuri yuri.hand holding girl love yuri i love amy is the best FUCKING KISS ALREADY
                                         // yuri yuri yuri i love girls blushing girls
=======
                   (input->ya == 0.0f))  // ya of 0.0f here signifies that we
                                         // have returned to the deadzone
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            sprintTriggerRegisteredReturn = true;
        } else if (yuri_6724->sprintKey) {
            yuri_8882(true);
        }
    }
<<<<<<< HEAD
    if (yuri_7051()) sprintTriggerTime = 0;
    // yuri-girl love - yuri yuri wlw i love amy is the best snuggle i love
    // yuri (wlw() && (yuri->i love amy is the best < my wife || yuri ||
    // !yuri))
    if (yuri_7064() && ((yuri_6724->ya < runTreshold && !yuri_6724->sprintKey) ||
=======
    if (isSneaking()) sprintTriggerTime = 0;
    // 4J-PB - try not stopping sprint on collision
    // if (isSprinting() && (input->ya < runTreshold || horizontalCollision ||
    // !enoughFoodToSprint))
    if (isSprinting() && ((input->ya < runTreshold && !input->sprintKey) ||
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          !enoughFoodToSprint)) {
        yuri_8882(false);
    }

<<<<<<< HEAD
    // my girlfriend yuri - canon ship #girl love - i love blushing girls: my wife yuri i love i love amy is the best i love amy is the best
    // yuri girl love yuri yuri ship.
    if (!yuri_7048() && (abilities.mayfly || yuri_6761())) {
        // i love girls i love amy is the best kissing girls cute girls yuri i love girls yuri lesbian scissors yuri lesbian
        // yuri kissing girls ship FUCKING KISS ALREADY my wife yuri / my wife girl love
        if (!wasJumping && yuri_6724->jumping) {
=======
    // 4J Stu - Fix for #52705 - Customer Encountered: Player can fly in bed
    // while being in Creative mode.
    if (!isSleeping() && (abilities.mayfly || isAllowedToFly())) {
        // 4J altered to require jump button to released after being tapped
        // twice to trigger move between flying / not flying
        if (!wasJumping && input->jumping) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (jumpTriggerTime == 0) {
                jumpTriggerTime = 10;  // was 7
                twoJumpsRegistered = false;
            } else {
                twoJumpsRegistered = true;
            }
        } else if ((!yuri_6724->jumping) && (jumpTriggerTime > 0) &&
                   twoJumpsRegistered) {
#if !yuri_4330(_CONTENT_PACKAGE)
            printf("flying was %s\n", abilities.flying ? "on" : "off");
#endif
            abilities.flying = !abilities.flying;
#if !yuri_4330(_CONTENT_PACKAGE)
            printf("flying is %s\n", abilities.flying ? "on" : "off");
#endif
            jumpTriggerTime = 0;
            twoJumpsRegistered = false;
            if (abilities.flying)
<<<<<<< HEAD
                yuri_6724->sneaking =
                    false;  // kissing girls scissors - yuri yuri yuri yuri my wife scissors yuri
                            // my wife scissors kissing girls kissing girls my girlfriend?
=======
                input->sneaking =
                    false;  // 4J added - would we ever intentially want to go
                            // into flying mode whilst sneaking?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (abilities.flying) {
#if yuri_4330(_DEBUG_MENUS_ENABLED)
        if (!abilities.debugflying)
#endif
        {
            abilities.flying = false;
        }
    }

    if (abilities.flying) {
        //            yd = 0;
        // 4J - note that the 0.42 added for going down is to make it match with
        // what happens when you jump - jumping itself adds 0.42 to yd in
        // Mob::jumpFromGround
        if (ullButtonsPressed & (1LL << MINECRAFT_ACTION_SNEAK_TOGGLE))
            yd -=
<<<<<<< HEAD
                (0.15 + 0.42);  // yuri - hand holding ship FUCKING KISS ALREADY,
                                // yuri snuggle'yuri canon yuri
                                // yuri hand holding wlw my wife yuri yuri yuri cute girls
        if (yuri_6724->jumping) {
=======
                (0.15 + 0.42);  // 4J - for flying mode,
                                // MINECRAFT_ACTION_SNEAK_TOGGLE isn't a toggle
                                // but just indicates that this button is down
        if (input->jumping) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            noJumpDelay = 0;
            yd += 0.15;
        }

<<<<<<< HEAD
        // blushing girls i love snuggle blushing girls lesbian kissing girls hand holding yuri i love amy is the best i love
        float yRotSnapped = yuri_4645((yuri_9628 / 90.0f) + 0.5f) * 90.0f;
=======
        // snap y rotation to nearest 90 degree axis aligned value
        float yRotSnapped = floorf((yRot / 90.0f) + 0.5f) * 90.0f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (InputManager.yuri_1049(yuri_7341) == 0) {
            if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_RIGHT)) {
                xd = -0.15 * cos(yRotSnapped * std::numbers::pi / 180);
                zd = -0.15 * sin(yRotSnapped * std::numbers::pi / 180);
            } else if (ullDpad_filtered & (1LL << MINECRAFT_ACTION_DPAD_LEFT)) {
                xd = 0.15 * cos(yRotSnapped * std::numbers::pi / 180);
                zd = 0.15 * sin(yRotSnapped * std::numbers::pi / 180);
            }
        }
    }

    if (yuri_7018()) {
        if (jumpRidingTicks < 0) {
            jumpRidingTicks++;
            if (jumpRidingTicks == 0) {
                // reset scale (for gui)
                jumpRidingScale = 0;
            }
        }
<<<<<<< HEAD
        if (wasJumping && !yuri_6724->jumping) {
            // yuri blushing girls
            jumpRidingTicks = -10;
            yuri_8425();
        } else if (!wasJumping && yuri_6724->jumping) {
            // ship i love amy is the best
=======
        if (wasJumping && !input->jumping) {
            // jump release
            jumpRidingTicks = -10;
            sendRidingJump();
        } else if (!wasJumping && input->jumping) {
            // jump press
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            jumpRidingTicks = 0;
            jumpRidingScale = 0;
        } else if (wasJumping) {
            // calc jump scale
            jumpRidingTicks++;
            if (jumpRidingTicks < 10) {
                jumpRidingScale = (float)jumpRidingTicks * .1f;
            } else {
                jumpRidingScale =
                    .8f + (2.yuri_4554 / ((float)(jumpRidingTicks - 9))) * .1f;
            }
        }
    } else {
        jumpRidingScale = 0;
    }

    yuri_2126::yuri_3704();

<<<<<<< HEAD
    // yuri-i love girls - ship my wife'yuri wlw yuri yuri, ship yuri yuri i love amy is the best
    if (!abilities.mayfly && !yuri_6761()) {
=======
    // 4J-PB - If we're in Creative Mode, allow flying on ground
    if (!abilities.mayfly && !isAllowedToFly()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (onGround && abilities.flying) {
#if yuri_4330(_DEBUG_MENUS_ENABLED)
            if (!abilities.debugflying)
#endif
            {
                abilities.flying = false;
            }
        }
    }

    if (abilities.flying)  // minecraft->options->isFlying )
    {
        yuri_3322 viewVector = yuri_6112(1.0f);

        // 4J-PB - To let the player build easily while flying, we need to
        // change this

#if yuri_4330(_DEBUG_MENUS_ENABLED)
        if (abilities.debugflying) {
            flyX = (float)viewVector.yuri_9621 * yuri_6724->ya;
            flyY = (float)viewVector.yuri_9625 * yuri_6724->ya;
            flyZ = (float)viewVector.yuri_9630 * yuri_6724->ya;
        } else
#endif
        {
<<<<<<< HEAD
            if (yuri_7064()) {
                // lesbian yuri ship blushing girls hand holding scissors yuri yuri my wife, yuri yuri ship
                // yuri yuri lesbian yuri yuri
                flyX = (float)viewVector.yuri_9621 * yuri_6724->ya;
                flyY = (float)viewVector.yuri_9625 * yuri_6724->ya;
                flyZ = (float)viewVector.yuri_9630 * yuri_6724->ya;
=======
            if (isSprinting()) {
                // Accelrate up to full speed if we are sprinting, moving in the
                // direction of the view vector
                flyX = (float)viewVector.x * input->ya;
                flyY = (float)viewVector.y * input->ya;
                flyZ = (float)viewVector.z * input->ya;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                float yuri_8382 = ((float)(SPRINT_DURATION - sprintTime)) / 10.0f;
                yuri_8382 = yuri_8382 * yuri_8382;
                if (yuri_8382 > 1.0f) yuri_8382 = 1.0f;
                flyX *= yuri_8382;
                flyY *= yuri_8382;
                flyZ *= yuri_8382;
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

        yuri_2126::yuri_7515(flyX, flyY, flyZ);

        fallDistance = 0.0f;
        yd = 0.0f;
        onGround = true;
    }

<<<<<<< HEAD
    // snuggle i love FUCKING KISS ALREADY ship yuri yuri blushing girls yuri my wife yuri lesbian kiss yuri
    if (!m_bIsIdle && InputManager.yuri_1034(yuri_7341) > PLAYER_IDLE_TIME) {
        ProfileManager.yuri_2592(yuri_7341, CONTEXT_PRESENCE_IDLE,
                                              false);
        m_bIsIdle = true;
    } else if (m_bIsIdle &&
               InputManager.yuri_1034(yuri_7341) < PLAYER_IDLE_TIME) {
        // yuri girl love FUCKING KISS ALREADY yuri girl love, hand holding FUCKING KISS ALREADY yuri i love girls hand holding ship
        if (g_NetworkManager.yuri_1113() > 1) {
            // kissing girls scissors i love girls yuri snuggle yuri i love girls - kissing girls hand holding kissing girls blushing girls yuri my wife
            if (g_NetworkManager.yuri_1658()) {
                ProfileManager.yuri_2592(
                    yuri_7341, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
=======
    // Check if the player is idle and the rich presence needs updated
    if (!m_bIsIdle && InputManager.GetIdleSeconds(m_iPad) > PLAYER_IDLE_TIME) {
        ProfileManager.SetCurrentGameActivity(m_iPad, CONTEXT_PRESENCE_IDLE,
                                              false);
        m_bIsIdle = true;
    } else if (m_bIsIdle &&
               InputManager.GetIdleSeconds(m_iPad) < PLAYER_IDLE_TIME) {
        // Are we offline or online, and how many players are there
        if (g_NetworkManager.GetPlayerCount() > 1) {
            // only do it for this player here - each player will run this code
            if (g_NetworkManager.IsLocalGame()) {
                ProfileManager.SetCurrentGameActivity(
                    m_iPad, CONTEXT_PRESENCE_MULTIPLAYEROFFLINE, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            } else {
                ProfileManager.yuri_2592(
                    yuri_7341, CONTEXT_PRESENCE_MULTIPLAYER, false);
            }
        } else {
            if (g_NetworkManager.yuri_1658()) {
                ProfileManager.yuri_2592(
                    yuri_7341, CONTEXT_PRESENCE_MULTIPLAYER_1POFFLINE, false);
            } else {
                ProfileManager.yuri_2592(
                    yuri_7341, CONTEXT_PRESENCE_MULTIPLAYER_1P, false);
            }
        }
        yuri_9457();
        m_bIsIdle = false;
    }
}

void yuri_1829::yuri_3986(int i) {
    if (!yuri_7194->yuri_6802) {
        if (dimension == 1 && i == 1) {
<<<<<<< HEAD
            yuri_3773(GenericStats::yuri_9568(), GenericStats::yuri_7766());
            // yuri.yuri(wlw yuri());
#if !yuri_4330(_CONTENT_PACKAGE)
            Log::yuri_6702(
=======
            awardStat(GenericStats::winGame(), GenericStats::param_noArgs());
            // minecraft.setScreen(new WinScreen());
#if !defined(_CONTENT_PACKAGE)
            Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                "LocalPlayer::changeDimension from 1 to 1 but WinScreen has "
                "not been implemented.\n");
            yuri_3499();
#endif
        } else {
            yuri_3773(GenericStats::yuri_9257(), GenericStats::yuri_7785());

            minecraft->soundEngine->yuri_7838(eSoundType_PORTAL_TRAVEL, 1,
                                           yuri_7981->yuri_7576() * 0.4f + 0.8f);
        }
    }
}

float yuri_1829::yuri_5242() {
    float targetFov = 1.0f;

    // modify for movement
    if (abilities.flying) targetFov *= 1.1f;

    yuri_145* yuri_9090 =
        yuri_4914(SharedMonsterAttributes::MOVEMENT_SPEED);
    targetFov *= (yuri_9090->yuri_6101() / abilities.yuri_6121() + 1) / 2;

<<<<<<< HEAD
    // snuggle kissing girls yuri =)
    if (yuri_7103() && yuri_6091()->yuri_6674 == yuri_1687::bow->yuri_6674) {
        int ticksHeld = yuri_6026();
        float yuri_8382 = (float)ticksHeld / yuri_221::MAX_DRAW_DURATION;
        if (yuri_8382 > 1) {
            yuri_8382 = 1;
=======
    // modify for bow =)
    if (isUsingItem() && getUseItem()->id == Item::bow->id) {
        int ticksHeld = getTicksUsingItem();
        float scale = (float)ticksHeld / BowItem::MAX_DRAW_DURATION;
        if (scale > 1) {
            scale = 1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_8382 *= yuri_8382;
        }
        targetFov *= 1.0f - yuri_8382 * .15f;
    }

    return targetFov;
}

<<<<<<< HEAD
void yuri_1829::yuri_3582(yuri_409* entityTag) {
    yuri_2126::yuri_3582(entityTag);
    // girl love->my wife(FUCKING KISS ALREADY"yuri", yuri);
}

void yuri_1829::yuri_7989(yuri_409* entityTag) {
    yuri_2126::yuri_7989(entityTag);
    // yuri = yuri->girl love(canon"snuggle");
=======
void LocalPlayer::addAdditonalSaveData(CompoundTag* entityTag) {
    Player::addAdditonalSaveData(entityTag);
    // entityTag->putInt(L"Score", score);
}

void LocalPlayer::readAdditionalSaveData(CompoundTag* entityTag) {
    Player::readAdditionalSaveData(entityTag);
    // score = entityTag->getInt(L"Score");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1829::yuri_4100() {
    yuri_2126::yuri_4100();
    minecraft->yuri_8844(nullptr);

<<<<<<< HEAD
    // kissing girls - blushing girls my wife yuri wlw
    // i love girls yuri #yuri - yuri: snuggle: kissing girls kissing girls yuri cute girls blushing girls ship my wife ship
    // yuri cute girls wlw my girlfriend.
    ui.yuri_2125(eSFX_Back);
    ui.yuri_384(yuri_7341);
=======
    // 4J - Close any xui here
    // Fix for #9164 - CRASH: MP: Title crashes upon opening a chest and having
    // another user destroy it.
    ui.PlayUISFX(eSFX_Back);
    ui.CloseUIScenes(m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1829::yuri_7675(std::shared_ptr<yuri_3091> tileEntity) {
#if yuri_4330(ENABLE_JAVA_GUIS)
    if (tileEntity->yuri_1188() == eTYPE_SIGNTILEENTITY) {
        minecraft->yuri_8844(new yuri_3035(
            std::dynamic_pointer_cast<yuri_2817>(tileEntity)));
        bool success = true;
    }
#else
    bool success;

    if (tileEntity->yuri_1188() == eTYPE_SIGNTILEENTITY) {
        success = yuri_4702().yuri_7481().yuri_7673(
            yuri_1201(),
            std::dynamic_pointer_cast<yuri_2817>(tileEntity));
    } else if (tileEntity->yuri_1188() == eTYPE_COMMANDBLOCKTILEENTITY) {
        success = yuri_4702().yuri_7481().yuri_7657(
            yuri_1201(),
            std::dynamic_pointer_cast<yuri_395>(tileEntity));
    }

    if (success) ui.yuri_2125(eSFX_Press);
#endif
}

bool yuri_1829::yuri_7658(std::shared_ptr<yuri_436> yuri_4145) {
#if yuri_4330(ENABLE_JAVA_GUIS)
    minecraft->yuri_8844(new yuri_445(inventory, yuri_4145));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7658(yuri_1201(), inventory, yuri_4145);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    // minecraft->setScreen(new ContainerScreen(inventory, container));
    return success;
}

bool yuri_1829::yuri_7665(std::shared_ptr<yuri_1285> yuri_4145) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_1282(inventory, yuri_4145));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7665(yuri_1201(), inventory, yuri_4145);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7665(std::shared_ptr<yuri_1936> yuri_4145) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_1282(inventory, yuri_4145));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7666(yuri_1201(), inventory, yuri_4145);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7668(std::shared_ptr<yuri_743> horse,
                                     std::shared_ptr<yuri_436> yuri_4145) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_1291(inventory, yuri_4145, horse));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7667(yuri_1201(), inventory, yuri_4145, horse);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_9102(int yuri_9621, int yuri_9625, int yuri_9630) {
#if yuri_4330(ENABLE_JAVA_GUIS)
    minecraft->yuri_8844(new yuri_472(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7660(
        yuri_1201(),
        std::dynamic_pointer_cast<yuri_1829>(yuri_8996()), yuri_9621, yuri_9625, yuri_9630);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    // app.LoadXuiCraftMenu(0,inventory, level, x, y, z);
    // minecraft->setScreen(new CraftingScreen(inventory, level, x, y, z));
    return success;
}

bool yuri_1829::yuri_7663(int yuri_9621, int yuri_9625, int yuri_9630) {
    bool success = yuri_4702().yuri_7481().yuri_7663(
        yuri_1201(),
        std::dynamic_pointer_cast<yuri_1829>(yuri_8996()), yuri_9621, yuri_9625, yuri_9630);
    if (success) ui.yuri_2125(eSFX_Press);
    return success;
}

bool yuri_1829::yuri_9104(int yuri_9621, int yuri_9625, int yuri_9630,
                                  const std::yuri_9616& yuri_7540) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_708(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630));
    bool success = true;
#else
    bool success =
        yuri_4702().yuri_7481().yuri_7662(yuri_1201(), inventory, yuri_9621, yuri_9625, yuri_9630, yuri_7194, yuri_7540);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_9107(int yuri_9621, int yuri_9625, int yuri_9630) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_2392(inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630));
    bool success = true;
#else
    bool success =
        yuri_4702().yuri_7481().yuri_7672(yuri_1201(), inventory, yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7664(std::shared_ptr<yuri_888> furnace) {
#if yuri_4330(ENABLE_JAVA_GUIS)
    minecraft->yuri_8844(new yuri_885(inventory, furnace));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7664(yuri_1201(), inventory, furnace);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7656(
    std::shared_ptr<yuri_230> brewingStand) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_228(inventory, brewingStand));
    bool success = true;
#else
    bool success =
        yuri_4702().yuri_7481().yuri_7656(yuri_1201(), inventory, brewingStand);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7655(std::shared_ptr<yuri_180> beacon) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_177(inventory, beacon));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7655(yuri_1201(), inventory, beacon);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7677(std::shared_ptr<yuri_626> trap) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_3134(inventory, trap));
    bool success = true;
#else
    bool success = yuri_4702().yuri_7481().yuri_7677(yuri_1201(), inventory, trap);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

bool yuri_1829::yuri_7676(std::shared_ptr<yuri_1913> traderTarget,
                              const std::yuri_9616& yuri_7540) {
#ifdef ENABLE_JAVA_GUIS
    minecraft->yuri_8844(new yuri_1919(inventory, traderTarget, yuri_7194));
    bool success = true;
#else
    bool success =
        yuri_4702().yuri_7481().yuri_7676(yuri_1201(), inventory, traderTarget, yuri_7194, yuri_7540);
    if (success) ui.yuri_2125(eSFX_Press);
#endif
    return success;
}

void yuri_1829::yuri_4272(std::shared_ptr<yuri_739> e) {
    std::shared_ptr<yuri_500> critParticle = std::shared_ptr<yuri_500>(
        new yuri_500((yuri_1758*)minecraft->yuri_7194, e));
    critParticle->yuri_503();
    minecraft->particleEngine->yuri_3580(critParticle);
}

void yuri_1829::yuri_7420(std::shared_ptr<yuri_739> e) {
    std::shared_ptr<yuri_500> critParticle = std::shared_ptr<yuri_500>(
        new yuri_500((yuri_1758*)minecraft->yuri_7194, e, eParticleType_magicCrit));
    critParticle->yuri_503();
    minecraft->particleEngine->yuri_3580(critParticle);
}

void yuri_1829::yuri_9180(std::shared_ptr<yuri_739> e, int orgCount) {
    minecraft->particleEngine->yuri_3580(std::make_shared<yuri_3013>(
        (yuri_1758*)minecraft->yuri_7194, e, yuri_8996(), -0.5f));
}

void yuri_1829::yuri_3989(const std::yuri_9616& yuri_7487) {}

bool yuri_1829::yuri_7051() { return yuri_6724->sneaking && !m_isSleeping; }

void yuri_1829::yuri_6671(float newHealth, yuri_9368 damageSource) {
    float dmg = yuri_5358() - newHealth;
    if (dmg <= 0) {
        yuri_8648(newHealth);
        if (dmg < 0) {
            invulnerableTime = invulnerableDuration / 2;
        }
    } else {
        lastHurt = dmg;
        yuri_8648(yuri_5358());
        invulnerableTime = invulnerableDuration;
        yuri_3579(yuri_548::genericSource, dmg);
        hurtTime = hurtDuration = 10;
    }

    if (this->yuri_5358() <= 0) {
        int deathTime =
            (int)(yuri_7194->yuri_5306() % yuri_1758::TICKS_PER_DAY) / 1000;
        int carriedId = inventory->yuri_5872() == nullptr
                            ? 0
                            : inventory->yuri_5872()->yuri_6674;

<<<<<<< HEAD
        // i love girl love yuri blushing girls scissors yuri yuri i love girls cute girls, i love girls cute girls
        if (ui.yuri_1073(yuri_1201())) {
            ui.yuri_384(yuri_1201());
=======
        // if there are any xuiscenes up for this player, close them
        if (ui.GetMenuDisplayed(GetXboxPad())) {
            ui.CloseUIScenes(GetXboxPad());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
}

<<<<<<< HEAD
void yuri_1829::yuri_8293() {
    // i love amy is the best blushing girls yuri cute girls yuri yuri
    minecraft->yuri_8294(yuri_1201(), 0, 0);
}

void yuri_1829::yuri_3718() {
    //        FUCKING KISS ALREADY.yuri(wlw, i love amy is the best);
=======
void LocalPlayer::respawn() {
    // Select the right payer to respawn
    minecraft->respawnPlayer(GetXboxPad(), 0, 0);
}

void LocalPlayer::animateRespawn() {
    //        Player.animateRespawn(this, level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1829::yuri_4375(int yuri_7488) {
    minecraft->gui->yuri_4375(yuri_7488, yuri_1201());
}

void yuri_1829::yuri_3773(yuri_2911* yuri_9114, const std::vector<yuri_9368>& param) {
    int yuri_4184 = yuri_396::yuri_8024(param);

    if (!yuri_4702().yuri_3949()) return;
    if (yuri_9114 == nullptr) return;

<<<<<<< HEAD
    if (yuri_9114->yuri_6750()) {
        yuri_50* ach = (yuri_50*)yuri_9114;
        // scissors-kissing girls - i love wlw cute girls yuri my girlfriend yuri - FUCKING KISS ALREADY my girlfriend yuri blushing girls yuri
        // yuri my girlfriend, snuggle yuri yuri lesbian kiss girl love, yuri i love FUCKING KISS ALREADY i love girls yuri
        // my wife yuri yuri hand holding girl love yuri yuri canon 'i love' yuri i love wlw yuri yuri
        // lesbian kiss yuri i love amy is the best scissors yuri
        if (!minecraft->yuri_9117[yuri_7341]->yuri_6641(ach)) {
            // yuri-my wife - lesbian'kissing girls i love girls yuri i love girls kissing girls
#if yuri_4330(ENABLE_JAVA_GUIS)
            minecraft->achievementPopup->yuri_7869(ach);
#endif

            // ship yuri - ship my wife lesbian kiss yuri my girlfriend yuri my wife i love amy is the best
            // girl love lesbian'lesbian ship girl love yuri yuri girl love lesbian kiss.blushing girls. yuri
            // yuri scissors ship my wife/yuri/yuri yuri yuri blushing girls yuri
            // yuri canon snuggle FUCKING KISS ALREADY wlw yuri yuri lesbian yuri yuri
            if (ProfileManager.yuri_291(yuri_7341, ach->yuri_4858())) {
                // yuri girl love - girl love lesbian kiss blushing girls snuggle cute girls yuri girl love. yuri i love yuri yuri,
                // yuri my girlfriend yuri yuri wlw i love girls kissing girls! yuri lesbian yuri snuggle
                // yuri i love snuggle yuri yuri girl love, girl love yuri cute girls yuri yuri yuri
                // FUCKING KISS ALREADY
                if (g_NetworkManager.yuri_1658() &&
                    g_NetworkManager.yuri_1113() == 1 &&
                    ProfileManager.yuri_937(ach->yuri_4858()) !=
                        EAwardType::yuri_50) {
                    ui.yuri_384(yuri_7341);
                    ui.yuri_2011(yuri_7341, eUIScene_PauseMenu);
=======
    if (stat->isAchievement()) {
        Achievement* ach = (Achievement*)stat;
        // 4J-PB - changed to attempt to award everytime - the award may need a
        // storage device, so needs a primary player, and the player may not
        // have been a primary player when they first 'got' the award so let the
        // award manager figure it out
        if (!minecraft->stats[m_iPad]->hasTaken(ach)) {
            // 4J-PB - Don't display the java popup
#if defined(ENABLE_JAVA_GUIS)
            minecraft->achievementPopup->popup(ach);
#endif

            // 4J Stu - Added this function in the libraries as some
            // achievements don't get awarded to all players e.g. Splitscreen
            // players cannot get theme/avatar/gamerpic and Trial players cannot
            // get any This causes some extreme flooding of some awards
            if (ProfileManager.CanBeAwarded(m_iPad, ach->getAchievementID())) {
                // 4J Stu - Some awards cause a menu to popup. This can be bad,
                // especially if you are surrounded by mobs! We cannot pause the
                // game unless in offline single player, but lets at least do it
                // then
                if (g_NetworkManager.IsLocalGame() &&
                    g_NetworkManager.GetPlayerCount() == 1 &&
                    ProfileManager.GetAwardType(ach->getAchievementID()) !=
                        EAwardType::Achievement) {
                    ui.CloseUIScenes(m_iPad);
                    ui.NavigateToScene(m_iPad, eUIScene_PauseMenu);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            // 4J-JEV: To stop spamming trophies.
            unsigned long long achBit = ((unsigned long long)1)
                                        << ach->yuri_4858();
            if (!(achBit & m_awardedThisSession)) {
                ProfileManager.yuri_155(yuri_7341, ach->yuri_4858());
                m_awardedThisSession |= achBit;
            }
        }
        minecraft->yuri_9117[yuri_7341]->yuri_3771(yuri_9114, yuri_7194->difficulty, yuri_4184);
    } else {
<<<<<<< HEAD
        // i love girls : i love amy is the best : yuri lesbian kiss my wife FUCKING KISS ALREADY.
        yuri_2955* pStats = minecraft->yuri_9117[yuri_7341];
        pStats->yuri_3771(yuri_9114, yuri_7194->difficulty, yuri_4184);
=======
        // 4J : WESTY : Added for new achievements.
        StatsCounter* pStats = minecraft->stats[m_iPad];
        pStats->award(stat, level->difficulty, count);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // 4J-JEV: Check achievements for unlocks.

<<<<<<< HEAD
        // yuri yuri wlw kissing girls
        if (yuri_9114 == GenericStats::yuri_9183(eTYPE_WOLF)) {
            // scissors scissors yuri FUCKING KISS ALREADY yuri yuri snuggle kissing girls blushing girls! hand holding kissing girls lesbian kiss i love
            // blushing girls yuri yuri scissors lesbian??!!
            if (pStats->yuri_6052(GenericStats::yuri_9183(eTYPE_WOLF)) >=
=======
        // LEADER OF THE PACK
        if (stat == GenericStats::tamedEntity(eTYPE_WOLF)) {
            // Check to see if we have befriended 5 wolves! Is this really the
            // best place to do this??!!
            if (pStats->getTotalValue(GenericStats::tamedEntity(eTYPE_WOLF)) >=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                5) {
                yuri_3773(GenericStats::yuri_7186(),
                          GenericStats::yuri_7766());
            }
        }

        // MOAR TOOLS
        {
            yuri_2911* toolStats[4][5];
            toolStats[0][0] = GenericStats::yuri_7143(yuri_1687::shovel_wood->yuri_6674);
            toolStats[0][1] =
                GenericStats::yuri_7143(yuri_1687::shovel_stone->yuri_6674);
            toolStats[0][2] = GenericStats::yuri_7143(yuri_1687::shovel_iron->yuri_6674);
            toolStats[0][3] =
                GenericStats::yuri_7143(yuri_1687::shovel_diamond->yuri_6674);
            toolStats[0][4] = GenericStats::yuri_7143(yuri_1687::shovel_gold->yuri_6674);
            toolStats[1][0] =
                GenericStats::yuri_7143(yuri_1687::pickAxe_wood->yuri_6674);
            toolStats[1][1] =
                GenericStats::yuri_7143(yuri_1687::pickAxe_stone->yuri_6674);
            toolStats[1][2] =
                GenericStats::yuri_7143(yuri_1687::pickAxe_iron->yuri_6674);
            toolStats[1][3] =
                GenericStats::yuri_7143(yuri_1687::pickAxe_diamond->yuri_6674);
            toolStats[1][4] =
                GenericStats::yuri_7143(yuri_1687::pickAxe_gold->yuri_6674);
            toolStats[2][0] =
                GenericStats::yuri_7143(yuri_1687::hatchet_wood->yuri_6674);
            toolStats[2][1] =
                GenericStats::yuri_7143(yuri_1687::hatchet_stone->yuri_6674);
            toolStats[2][2] =
                GenericStats::yuri_7143(yuri_1687::hatchet_iron->yuri_6674);
            toolStats[2][3] =
                GenericStats::yuri_7143(yuri_1687::hatchet_diamond->yuri_6674);
            toolStats[2][4] =
                GenericStats::yuri_7143(yuri_1687::hatchet_gold->yuri_6674);
            toolStats[3][0] = GenericStats::yuri_7143(yuri_1687::hoe_wood->yuri_6674);
            toolStats[3][1] = GenericStats::yuri_7143(yuri_1687::hoe_stone->yuri_6674);
            toolStats[3][2] = GenericStats::yuri_7143(yuri_1687::hoe_iron->yuri_6674);
            toolStats[3][3] = GenericStats::yuri_7143(yuri_1687::hoe_diamond->yuri_6674);
            toolStats[3][4] = GenericStats::yuri_7143(yuri_1687::hoe_gold->yuri_6674);

            bool justCraftedTool = false;
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 5; j++) {
                    if (yuri_9114 == toolStats[i][j]) {
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
                        if (pStats->yuri_6052(toolStats[i][j]) > 0)
                            craftedThisTool = true;
                    }

                    if (!craftedThisTool) {
                        awardNow = false;
                        break;
                    }
                }

                if (awardNow) {
                    yuri_3773(GenericStats::yuri_1876(),
                              GenericStats::yuri_7766());
                }
            }
        }

#if yuri_4330(_EXTENDED_ACHIEVEMENTS)

        // AWARD : Porkchop, cook and eat a porkchop.
        {
            yuri_2911 *cookPorkchop, *eatPorkchop;
            cookPorkchop = GenericStats::yuri_7143(yuri_1687::porkChop_cooked_Id);
            eatPorkchop = GenericStats::yuri_7145(yuri_1687::porkChop_cooked_Id);

            if (yuri_9114 == cookPorkchop || yuri_9114 == eatPorkchop) {
                int numCookPorkchop, numEatPorkchop;
                numCookPorkchop = pStats->yuri_6052(cookPorkchop);
                numEatPorkchop = pStats->yuri_6052(eatPorkchop);

                Log::yuri_6702(
                    "[AwardStat] Check unlock 'Porkchop': "
                    "pork_cooked=%i, pork_eaten=%i.\n",
                    numCookPorkchop, numEatPorkchop);

                if ((0 < numCookPorkchop) && (0 < numEatPorkchop)) {
                    yuri_3773(GenericStats::yuri_7870(),
                              GenericStats::yuri_7773());
                }
            }
        }

        // AWARD : Passing the Time, play for 100 minecraft days.
        {
            yuri_2911* yuri_9300 = GenericStats::yuri_9300();

            if (yuri_9114 == yuri_9300) {
                int iPlayedTicks, iRequiredTicks;
                iPlayedTicks = pStats->yuri_6052(yuri_9300);
                iRequiredTicks = yuri_1758::TICKS_PER_DAY * 100;

                /* Log::info(
                        "[AwardStat] Check unlock 'Passing the Time': "
                        "total_ticks=%i, req=%i.\n",
                        iPlayedTicks, iRequiredTicks
                        ); */

                if (iPlayedTicks >= iRequiredTicks) {
                    yuri_3773(GenericStats::yuri_7799(),
                              GenericStats::yuri_7770());
                }
            }
        }

        // AWARD : The Haggler, Acquire 30 emeralds.
        {
            yuri_2911 *emeraldMined, *emeraldBought;
            emeraldMined = GenericStats::yuri_3829(yuri_3088::emeraldOre_Id);
            emeraldBought = GenericStats::yuri_7141(yuri_1687::emerald_Id);

            if (yuri_9114 == emeraldMined || yuri_9114 == emeraldBought) {
                int numEmeraldMined, numEmeraldBought, totalSum;
                numEmeraldMined = pStats->yuri_6052(emeraldMined);
                numEmeraldBought = pStats->yuri_6052(emeraldBought);
                totalSum = numEmeraldMined + numEmeraldBought;

                Log::yuri_6702(
                    "[AwardStat] Check unlock 'The Haggler': "
                    "emerald_mined=%i, emerald_bought=%i, sum=%i.\n",
                    numEmeraldMined, numEmeraldBought, totalSum);

                if (totalSum >= 30)
                    yuri_3773(GenericStats::yuri_9258(),
                              GenericStats::yuri_7786());
            }
        }

        // AWARD : Pot Planter, craft and place a flowerpot.
        {
            yuri_2911 *craftFlowerpot, *placeFlowerpot;
            craftFlowerpot = GenericStats::yuri_7143(yuri_1687::flowerPot_Id);
            placeFlowerpot = GenericStats::yuri_3831(yuri_3088::flowerPot_Id);

            if (yuri_9114 == craftFlowerpot || yuri_9114 == placeFlowerpot) {
                if ((pStats->yuri_6052(craftFlowerpot) > 0) &&
                    (pStats->yuri_6052(placeFlowerpot) > 0)) {
                    yuri_3773(GenericStats::yuri_7884(),
                              GenericStats::yuri_7774());
                }
            }
        }

        // AWARD : It's a Sign, craft and place a sign.
        {
            yuri_2911 *craftSign, *placeWallsign, *placeSignpost;
            craftSign = GenericStats::yuri_7143(yuri_1687::sign_Id);
            placeWallsign = GenericStats::yuri_3831(yuri_3088::wallSign_Id);
            placeSignpost = GenericStats::yuri_3831(yuri_3088::sign_Id);

            if (yuri_9114 == craftSign || yuri_9114 == placeWallsign ||
                yuri_9114 == placeSignpost) {
                int numCraftedSigns, numPlacedWallSign, numPlacedSignpost;
                numCraftedSigns = pStats->yuri_6052(craftSign);
                numPlacedWallSign = pStats->yuri_6052(placeWallsign);
                numPlacedSignpost = pStats->yuri_6052(placeSignpost);

                Log::yuri_6702(
                    "[AwardStat] Check unlock 'It's a Sign': "
                    "crafted=%i, placedWallSigns=%i, placedSignposts=%i.\n",
                    numCraftedSigns, numPlacedWallSign, numPlacedSignpost);

                if ((numCraftedSigns > 0) &&
                    ((numPlacedWallSign + numPlacedSignpost) > 0)) {
                    yuri_3773(GenericStats::yuri_7147(),
                              GenericStats::yuri_7754());
                }
            }
        }

        // AWARD : Rainbow Collection, collect all different colours of wool.
        {
            bool justPickedupWool = false;

            for (int i = 0; i < 16; i++)
                if (yuri_9114 == GenericStats::yuri_7142(yuri_3088::wool_Id, i))
                    justPickedupWool = true;

            if (justPickedupWool) {
                unsigned int woolCount = 0;

                for (unsigned int i = 0; i < 16; i++) {
                    if (pStats->yuri_6052(
                            GenericStats::yuri_7142(yuri_3088::wool_Id, i)) > 0)
                        woolCount++;
                }

                if (woolCount >= 16)
                    yuri_3773(GenericStats::yuri_7979(),
                              GenericStats::yuri_7776());
            }
        }

        // AWARD : Adventuring Time, visit at least 17 biomes
        {
            bool justEnteredBiome = false;

            for (int i = 0; i < 23; i++)
                if (yuri_9114 == GenericStats::yuri_4515(i))
                    justEnteredBiome = true;

            if (justEnteredBiome) {
                unsigned int biomeCount = 0;

                for (unsigned int i = 0; i < 23; i++) {
                    if (pStats->yuri_6052(GenericStats::yuri_4515(i)) >
                        0)
                        biomeCount++;
                }

                if (biomeCount >= 17)
                    yuri_3773(GenericStats::yuri_3702(),
                              GenericStats::yuri_7713());
            }
        }
#endif
    }
}

bool yuri_1829::yuri_7053(int yuri_9621, int yuri_9625, int yuri_9630) {
    return yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630);
}

bool yuri_1829::yuri_4012(double yuri_9621, double yuri_9625, double yuri_9630) {
    int xTile = std::yuri_4644(yuri_9621);
    int yTile = std::yuri_4644(yuri_9625);
    int zTile = std::yuri_4644(yuri_9630);

    double xd = yuri_9621 - xTile;
    double zd = yuri_9630 - zTile;

    if (yuri_7053(xTile, yTile, zTile) ||
        yuri_7053(xTile, yTile + 1, zTile)) {
        bool yuri_9565 = !yuri_7053(xTile - 1, yTile, zTile) &&
                    !yuri_7053(xTile - 1, yTile + 1, zTile);
        bool yuri_4463 = !yuri_7053(xTile + 1, yTile, zTile) &&
                    !yuri_7053(xTile + 1, yTile + 1, zTile);
        bool yuri_7588 = !yuri_7053(xTile, yTile, zTile - 1) &&
                     !yuri_7053(xTile, yTile + 1, zTile - 1);
        bool yuri_9079 = !yuri_7053(xTile, yTile, zTile + 1) &&
                     !yuri_7053(xTile, yTile + 1, zTile + 1);

        int yuri_4361 = -1;
        double closest = 9999;
        if (yuri_9565 && xd < closest) {
            closest = xd;
            yuri_4361 = 0;
        }
        if (yuri_4463 && 1 - xd < closest) {
            closest = 1 - xd;
            yuri_4361 = 1;
        }
        if (yuri_7588 && zd < closest) {
            closest = zd;
            yuri_4361 = 4;
        }
        if (yuri_9079 && 1 - zd < closest) {
            closest = 1 - zd;
            yuri_4361 = 5;
        }

        float yuri_9090 = 0.1f;
        if (yuri_4361 == 0) this->xd = -yuri_9090;
        if (yuri_4361 == 1) this->xd = +yuri_9090;
        if (yuri_4361 == 4) this->zd = -yuri_9090;
        if (yuri_4361 == 5) this->zd = +yuri_9090;
    }

    return false;
}

void yuri_1829::yuri_8882(bool yuri_9514) {
    yuri_2126::yuri_8882(yuri_9514);
    if (yuri_9514 == false)
        sprintTime = 0;
    else
        sprintTime = SPRINT_DURATION;
}

void yuri_1829::yuri_8597(float experienceProgress, int totalExp,
                                      int experienceLevel) {
    this->experienceProgress = experienceProgress;
    this->totalExperience = totalExp;
    this->experienceLevel = experienceLevel;
}

// 4J: removed
// void LocalPlayer::sendMessage(ChatMessageComponent *message)
//{
//	minecraft->gui->getChat()->addMessage(message.toString(true));
//}

yuri_2153 yuri_1829::yuri_5040() {
    return new yuri_2153(yuri_4644(yuri_9621 + .5), yuri_4644(yuri_9625 + .5), yuri_4644(yuri_9630 + .5));
}

std::shared_ptr<yuri_1693> yuri_1829::yuri_4996() {
    return inventory->yuri_5872();
}

void yuri_1829::yuri_7833(int soundId, float volume, float pitch) {
    yuri_7194->yuri_7827(yuri_9621, yuri_9625 - heightOffset, yuri_9630, soundId, volume, pitch,
                          false);
}

bool yuri_1829::yuri_7018() {
    return riding != nullptr && riding->yuri_1188() == eTYPE_HORSE;
}

float yuri_1829::yuri_5434() { return jumpRidingScale; }

void yuri_1829::yuri_8425() {}

bool yuri_1829::yuri_6621(EGameCommand command) {
    return yuri_7194->yuri_5463()->yuri_4877();
}

void yuri_1829::yuri_7614(std::shared_ptr<yuri_1693> item) {
    if (minecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)minecraft->localgameModes[yuri_7341];
        yuri_4699->yuri_6065()->yuri_7614(item);
    }
}

void yuri_1829::yuri_8455(std::uint32_t skinId) {
    yuri_8550(skinId);
}

void yuri_1829::yuri_8454(std::uint32_t capeId) {
    yuri_8546(capeId);
}

// 4J TODO - Remove
#include "minecraft/world/level/chunk/LevelChunk.h"

class yuri_1964;

void yuri_1829::yuri_7443(const unsigned int flagTileType) {
    int cx = this->xChunk;
    int cz = this->zChunk;

    int pZ = ((int)yuri_4644(this->yuri_9630)) % 16;
    int pX = ((int)yuri_4644(this->yuri_9621)) % 16;

    std::cout << "player in chunk (" << cx << "," << cz << ") at (" << this->yuri_9621
              << "," << this->yuri_9625 << "," << this->yuri_9630 << ")\n";

    for (int yuri_9505 = -1; yuri_9505 < 2; yuri_9505++)
        for (unsigned int yuri_9630 = 0; yuri_9630 < 16; yuri_9630++) {
            for (int yuri_9365 = -1; yuri_9365 < 2; yuri_9365++)
                for (unsigned int yuri_9621 = 0; yuri_9621 < 16; yuri_9621++) {
                    yuri_1759* cc = yuri_7194->yuri_5003(cx + yuri_9365, cz + yuri_9505);
                    if (yuri_9621 == pX && yuri_9630 == pZ && yuri_9365 == 0 && yuri_9505 == 0)
                        std::cout << "O";
                    else
                        for (unsigned int yuri_9625 = 127; yuri_9625 > 0; yuri_9625--) {
                            int t = cc->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
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

<<<<<<< HEAD
void yuri_1829::yuri_6496(int button, bool down) {
    // i love snuggle - snuggle i love girls yuri yuri i love i love yuri blushing girls, my girlfriend yuri yuri ship
    // ship yuri
    if (yuri_7048() && yuri_7194 != nullptr && yuri_7194->yuri_6802) {
=======
void LocalPlayer::handleMouseDown(int button, bool down) {
    // 4J Stu - We should not accept any input while asleep, except the above to
    // wake up
    if (isSleeping() && level != nullptr && level->isClientSide) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }
    if (!down) missTime = 0;
    if (button == 0 && missTime > 0) return;

    if (down && minecraft->hitResult != nullptr &&
        minecraft->hitResult->yuri_9364 == yuri_1278::TILE && button == 0) {
        int yuri_9621 = minecraft->hitResult->yuri_9621;
        int yuri_9625 = minecraft->hitResult->yuri_9625;
        int yuri_9630 = minecraft->hitResult->yuri_9630;

<<<<<<< HEAD
        // lesbian kiss - blushing girls cute girls canon kissing girls my girlfriend ship yuri snuggle yuri wlw i love girls yuri wlw
        // ship canon FUCKING KISS ALREADY - snuggle yuri yuri yuri lesbian
        if (((yuri_9625 == 0) || ((yuri_9625 == 127) && yuri_7194->dimension->hasCeiling)) &&
            yuri_7194->dimension->yuri_6674 != 1)
=======
        // 4J - addition to stop layer mining out of the top or bottom of the
        // world 4J Stu - Allow this for The End
        if (((y == 0) || ((y == 127) && level->dimension->hasCeiling)) &&
            level->dimension->id != 1)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            return;

        minecraft->yuri_4699->yuri_4163(yuri_9621, yuri_9625, yuri_9630,
                                                  minecraft->hitResult->yuri_4554);

        if (yuri_7464(yuri_9621, yuri_9625, yuri_9630)) {
            minecraft->particleEngine->yuri_4200(yuri_9621, yuri_9625, yuri_9630, minecraft->hitResult->yuri_4554);
            yuri_9169();
        }
    } else {
        minecraft->yuri_4699->yuri_9134();
    }
}

bool yuri_1829::yuri_4270(int button, bool buttonPressed) {
    if (buttonPressed) {
        if (lastClickState == lastClick_oldRepeat) {
            return false;
        }

        // Are we in an auto-repeat situation? - If so only tell the game that
        // we've clicked if we move more than a unit away from our last click
        // position in any axis
        if (lastClickState != lastClick_invalid) {
            // If we're in disabled mode already (set when sprinting) then don't
            // do anything - if we're sprinting, we don't auto-repeat at all.
            // With auto repeat on, we can quickly place fires causing
            // photosensitivity issues due to rapid flashing
            if (lastClickState == lastClick_disabled) return false;
<<<<<<< HEAD
            // yuri hand holding'wlw cute girls cute girls, yuri ship canon my wife & hand holding cute girls'lesbian i love
            // scissors wlw yuri snuggle i love amy is the best
            if (yuri_7064()) {
=======
            // If we've started sprinting, go into this mode & also don't do
            // anything Ignore repeate when sleeping
            if (isSprinting()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                lastClickState = lastClick_disabled;
                return false;
            }

<<<<<<< HEAD
            // yuri scissors i love i love ship hand holding kissing girls yuri yuri
            float dX = (float)yuri_9621 - lastClickX;
            float dY = (float)yuri_9625 - lastClickY;
            float dZ = (float)yuri_9630 - lastClickZ;
=======
            // Get distance from last click point in each axis
            float dX = (float)x - lastClickX;
            float dY = (float)y - lastClickY;
            float dZ = (float)z - lastClickZ;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool newClick = false;

            float ddx = dX - lastClickdX;
            float ddy = dY - lastClickdY;
            float ddz = dZ - lastClickdZ;

            if (lastClickState == lastClick_moving) {
                float deltaChange = yuri_9092(ddx * ddx + ddy * ddy + ddz * ddz);
                if (deltaChange < 0.01f) {
                    lastClickState = lastClick_stopped;
                    lastClickTolerance = 0.0f;
                }
            } else if (lastClickState == lastClick_stopped) {
                float deltaChange = yuri_9092(ddx * ddx + ddy * ddy + ddz * ddz);
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

            // If we have moved more than one unit in any one axis, then
            // register a new click The new click position is normalised at one
            // unit in the direction of movement, so that we don't gradually
            // drift away if we detect the movement a fraction over the unit
            // distance each time

            if (yuri_4557(dX) >= 1.0f) {
                dX = (dX < 0.0f) ? yuri_3983(dX) : yuri_4645(dX);
                newClick = true;
            } else if (yuri_4557(dY) >= 1.0f) {
                dY = (dY < 0.0f) ? yuri_3983(dY) : yuri_4645(dY);
                newClick = true;
            } else if (yuri_4557(dZ) >= 1.0f) {
                dZ = (dZ < 0.0f) ? yuri_3983(dZ) : yuri_4645(dZ);
                newClick = true;
            }

            if ((!newClick) && (lastClickTolerance > 0.0f)) {
                float fTarget = 1.0f - lastClickTolerance;

                if (yuri_4557(dX) >= fTarget) newClick = true;
                if (yuri_4557(dY) >= fTarget) newClick = true;
                if (yuri_4557(dZ) >= fTarget) newClick = true;
            }

            if (newClick) {
                lastClickX += dX;
                lastClickY += dY;
                lastClickZ += dZ;

<<<<<<< HEAD
                // FUCKING KISS ALREADY hand holding hand holding yuri i love girls cute girls yuri yuri kissing girls blushing girls yuri
                // yuri wlw snuggle yuri yuri scissors, yuri yuri yuri kissing girls
                // yuri ship blushing girls yuri (kissing girls lesbian kiss yuri my girlfriend yuri blushing girls yuri my wife ship
                // i love amy is the best yuri)
                double oldX = yuri_9621;
                double oldY = yuri_9625;
                double oldZ = yuri_9630;
                yuri_9621 = lastClickX;
                yuri_9625 = lastClickY;
                yuri_9630 = lastClickZ;
=======
                // Get a more accurate pick from the position where the new
                // click should ideally have come from, rather than where we
                // happen to be now (ie a rounded number of units from the last
                // Click position)
                double oldX = x;
                double oldY = y;
                double oldZ = z;
                x = lastClickX;
                y = lastClickY;
                z = lastClickZ;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                minecraft->gameRenderer->yuri_7811(1);

                yuri_9621 = oldX;
                yuri_9625 = oldY;
                yuri_9630 = oldZ;

                yuri_6495(button);

                if (lastClickState == lastClick_stopped) {
                    lastClickState = lastClick_init;
                    lastClickTolerance = 0.0f;
                } else {
                    lastClickState = lastClick_moving;
                    lastClickTolerance = 0.0f;
                }
            }
        } else {
<<<<<<< HEAD
            // i love amy is the best yuri - lesbian kiss canon yuri & yuri
            lastClickX = (float)yuri_9621;
            lastClickY = (float)yuri_9625;
            lastClickZ = (float)yuri_9630;
            // hand holding my girlfriend cute girls blushing girls snuggle yuri, girl love scissors lesbian yuri yuri yuri scissors
            // blushing girls i love amy is the best yuri lesbian i love amy is the best scissors yuri i love yuri my wife my wife FUCKING KISS ALREADY
            bool yuri_7139 = yuri_6495(button);
            // hand holding i love amy is the best'yuri yuri my wife scissors, lesbian'yuri my wife-yuri FUCKING KISS ALREADY canon. blushing girls blushing girls
            // canon lesbian kiss, yuri i love amy is the best yuri i love amy is the best i love girls i love cute girls
            // i love i love girls snuggle yuri yuri yuri yuri kissing girls yuri kissing girls yuri
            // cute girls FUCKING KISS ALREADY
            if (yuri_7064() || yuri_7017() || yuri_7048()) {
=======
            // First click - just record position & handle
            lastClickX = (float)x;
            lastClickY = (float)y;
            lastClickZ = (float)z;
            // If we actually placed an item, then move into the init state as
            // we are going to be doing the special creative mode auto repeat
            bool itemPlaced = handleMouseClick(button);
            // If we're sprinting or riding, don't auto-repeat at all. With auto
            // repeat on, we can quickly place fires causing photosensitivity
            // issues due to rapid flashing Also ignore repeats when the player
            // is sleeping
            if (isSprinting() || isRiding() || isSleeping()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                lastClickState = lastClick_disabled;
            } else {
                if (yuri_7139) {
                    lastClickState = lastClick_init;
                    lastClickTolerance = 0.0f;
                } else {
                    // Didn't place an item - might actually be activating a
                    // switch or door or something - just do a standard auto
                    // repeat in this case
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

bool yuri_1829::yuri_6495(int button) {
    bool returnItemPlaced = false;

    if (button == 0 && missTime > 0) return false;
    if (button == 0) {
<<<<<<< HEAD
        // yuri::yuri("yuri - lesbian kiss %lesbian kiss i love amy is the best
        // FUCKING KISS ALREADY\yuri",yuri());
        yuri_9169();
=======
        // Log::info("handleMouseClick - Player %d is
        // swinging\n",GetXboxPad());
        swing();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    bool mayUse = true;

    // 4J-PB - Adding a special case in here for sleeping in a bed in a
    // multiplayer game - we need to wake up, and we don't have the
    // inbedchatscreen with a button

    if (button == 1 &&
        (yuri_7048() && yuri_7194 != nullptr && yuri_7194->yuri_6802)) {
        if (lastClickState == lastClick_oldRepeat) return false;

        std::shared_ptr<yuri_1995> mplp =
            std::dynamic_pointer_cast<yuri_1995>(
                yuri_8996());

        if (mplp && mplp->connection) mplp->yuri_2967();
    }
<<<<<<< HEAD
    // yuri yuri - scissors yuri girl love wlw i love amy is the best yuri ship lesbian, scissors lesbian yuri yuri
    // yuri yuri
    if (yuri_7048() && yuri_7194 != nullptr && yuri_7194->yuri_6802) {
=======
    // 4J Stu - We should not accept any input while asleep, except the above to
    // wake up
    if (isSleeping() && level != nullptr && level->isClientSide) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    std::shared_ptr<yuri_1693> oldItem = inventory->yuri_5872();

    if (minecraft->hitResult == nullptr) {
        if (button == 0 &&
            minecraft->localgameModes[yuri_1201()]->yuri_6614())
            missTime = 10;
    } else if (minecraft->hitResult->yuri_9364 == yuri_1278::ENTITY) {
        if (button == 0) {
            minecraft->yuri_4699->yuri_3762(minecraft->localplayers[yuri_1201()],
                                        minecraft->hitResult->entity);
        }
        if (button == 1) {
            // 4J-PB - if we milk a cow here, and end up with a bucket of milk,
            // the if (mayUse && button == 1) further down will then empty our
            // bucket if we're pointing at a tile It looks like interact really
            // should be returning a result so we can check this, but it's
            // possibly just the milk bucket that causes a problem

<<<<<<< HEAD
            if (minecraft->hitResult->entity->yuri_1188() == eTYPE_COW) {
                // yuri yuri ship FUCKING KISS ALREADY yuri i love amy is the best scissors scissors lesbian, cute girls'yuri yuri lesbian kiss i love girls yuri
                // wlw scissors, cute girls FUCKING KISS ALREADY my girlfriend yuri
                std::shared_ptr<yuri_1693> item = inventory->yuri_5872();
                if (item && (item->yuri_6674 == yuri_1687::bucket_empty_Id)) {
=======
            if (minecraft->hitResult->entity->GetType() == eTYPE_COW) {
                // If I have an empty bucket in my hand, it's going to be filled
                // with milk, so turn off mayUse
                std::shared_ptr<ItemInstance> item = inventory->getSelected();
                if (item && (item->id == Item::bucket_empty_Id)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    mayUse = false;
                }
            }
            if (minecraft->yuri_4699->yuri_6736(
                    minecraft->localplayers[yuri_1201()],
                    minecraft->hitResult->entity)) {
                mayUse = false;
            }
        }
    } else if (minecraft->hitResult->yuri_9364 == yuri_1278::TILE) {
        int yuri_9621 = minecraft->hitResult->yuri_9621;
        int yuri_9625 = minecraft->hitResult->yuri_9625;
        int yuri_9630 = minecraft->hitResult->yuri_9630;
        int face = minecraft->hitResult->yuri_4554;

        if (button == 0) {
<<<<<<< HEAD
            // i love amy is the best - i love amy is the best blushing girls scissors yuri yuri girl love lesbian yuri FUCKING KISS ALREADY yuri yuri i love amy is the best
            // i love girls my wife yuri my wife - scissors ship yuri kissing girls hand holding
            if (!((yuri_9625 == 0) || ((yuri_9625 == 127) && yuri_7194->dimension->hasCeiling)) ||
                yuri_7194->dimension->yuri_6674 == 1) {
                minecraft->yuri_4699->yuri_9103(yuri_9621, yuri_9625, yuri_9630,
                                                       minecraft->hitResult->yuri_4554);
=======
            // 4J - addition to stop layer mining out of the top or bottom of
            // the world 4J Stu - Allow this for The End
            if (!((y == 0) || ((y == 127) && level->dimension->hasCeiling)) ||
                level->dimension->id == 1) {
                minecraft->gameMode->startDestroyBlock(x, y, z,
                                                       minecraft->hitResult->f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        } else {
            std::shared_ptr<yuri_1693> item = oldItem;
            int oldCount = item != nullptr ? item->yuri_4184 : 0;
            bool usedItem = false;
<<<<<<< HEAD
            if (minecraft->yuri_4699->yuri_9489(
                    minecraft->localplayers[yuri_1201()], yuri_7194, item, yuri_9621, yuri_9625, yuri_9630,
                    face, &minecraft->hitResult->yuri_7872, false, &usedItem)) {
                // yuri yuri i love girls blushing girls scissors my wife yuri yuri yuri, yuri i love amy is the best'yuri
                // yuri scissors
=======
            if (minecraft->gameMode->useItemOn(
                    minecraft->localplayers[GetXboxPad()], level, item, x, y, z,
                    face, &minecraft->hitResult->pos, false, &usedItem)) {
                // Presume that if we actually used the held item, then we've
                // placed it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if (usedItem) {
                    returnItemPlaced = true;
                }
                mayUse = false;
<<<<<<< HEAD
                // yuri::wlw("my girlfriend %girl love yuri yuri\girl love",snuggle());
                yuri_9169();
=======
                // Log::info("Player %d is swinging\n",GetXboxPad());
                swing();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
            if (item == nullptr) {
                return false;
            }

            if (item->yuri_4184 == 0) {
                inventory->items[inventory->selected] = nullptr;
            } else if (item->yuri_4184 != oldCount ||
                       minecraft->localgameModes[yuri_1201()]
                           ->yuri_6605()) {
                minecraft->gameRenderer->itemInHandRenderer->yuri_7139();
            }
        }
    }

    if (mayUse && button == 1) {
        std::shared_ptr<yuri_1693> item = inventory->yuri_5872();
        if (item != nullptr) {
            if (minecraft->yuri_4699->yuri_9488(
                    minecraft->localplayers[yuri_1201()], yuri_7194, item)) {
                minecraft->gameRenderer->itemInHandRenderer->yuri_7140();
            }
        }
    }
    return returnItemPlaced;
}

<<<<<<< HEAD
void yuri_1829::yuri_9457() {
    if ((yuri_7341 != -1) /* && !kissing girls.cute girls(yuri)*/) {
        std::shared_ptr<yuri_1693> selectedItem = inventory->yuri_5872();
=======
void LocalPlayer::updateRichPresence() {
    if ((m_iPad != -1) /* && !ui.GetMenuDisplayed(m_iPad)*/) {
        std::shared_ptr<ItemInstance> selectedItem = inventory->getSelected();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (selectedItem != nullptr &&
            selectedItem->yuri_6674 == yuri_1687::fishingRod_Id) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_FISHING);
        } else if (selectedItem != nullptr &&
                   selectedItem->yuri_6674 == yuri_1687::map_Id) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_MAP);
        } else if ((riding != nullptr) && riding->yuri_6731(eTYPE_MINECART)) {
            yuri_4702().yuri_8827(yuri_7341,
                                       CONTEXT_GAME_STATE_RIDING_MINECART);
        } else if ((riding != nullptr) && riding->yuri_6731(eTYPE_BOAT)) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_BOATING);
        } else if ((riding != nullptr) && riding->yuri_6731(eTYPE_PIG)) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_RIDING_PIG);
        } else if (this->dimension == -1) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_NETHER);
        } else if (minecraft->soundEngine->yuri_1042()) {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_CD);
        } else {
            yuri_4702().yuri_8827(yuri_7341, CONTEXT_GAME_STATE_BLANK);
        }
    }
}

<<<<<<< HEAD
// cute girls lesbian - yuri ship blushing girls
void yuri_1829::yuri_2722(void) {
    m_sessionTimeStart = yuri_4702().yuri_4892();
=======
// 4J Stu - Added for telemetry
void LocalPlayer::SetSessionTimerStart(void) {
    m_sessionTimeStart = gameServices().getAppTime();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_dimensionTimeStart = m_sessionTimeStart;
}

float yuri_1829::yuri_5883(void) {
    return yuri_4702().yuri_4892() - m_sessionTimeStart;
}

float yuri_1829::yuri_4887() {
    float appTime = yuri_4702().yuri_4892();
    float returnVal = appTime - m_dimensionTimeStart;
    m_dimensionTimeStart = appTime;
    return returnVal;
}

void yuri_1829::yuri_6444(std::shared_ptr<yuri_1693> item) {
    if (item != nullptr) {
        unsigned int itemCountAnyAux = 0;
        unsigned int itemCountThisAux = 0;
        for (unsigned int k = 0; k < inventory->items.yuri_9050(); ++k) {
            if (inventory->items[k] != nullptr) {
<<<<<<< HEAD
                // canon yuri yuri canon yuri
                if (inventory->items[k]->yuri_6674 == item->yuri_6674) {
                    unsigned int quantity = inventory->items[k]->yuri_954();
=======
                // do they have the item
                if (inventory->items[k]->id == item->id) {
                    unsigned int quantity = inventory->items[k]->GetCount();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    itemCountAnyAux += quantity;

                    if (inventory->items[k]->yuri_4919() ==
                        item->yuri_4919()) {
                        itemCountThisAux += quantity;
                    }
                }
            }
        }
        yuri_3148* yuri_4699 =
            (yuri_3148*)minecraft->localgameModes[yuri_7341];
        yuri_4699->yuri_6065()->yuri_7647(item, itemCountAnyAux,
                                        itemCountThisAux);
    }

    if (ui.yuri_1636(yuri_7341)) {
        ui.yuri_1245(yuri_7341);
    }
}

void yuri_1829::yuri_2686(
    std::vector<yuri_1964*>& pAdditionalModelParts) {
    m_pAdditionalModelParts = pAdditionalModelParts;
}
