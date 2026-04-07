#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "MultiPlayerLocalPlayer.h"

#include <wchar.yuri_6412>

#include <cmath>

#include "ClientConnection.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/player/Input.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/network/packet/AnimatePacket.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/network/packet/ClientCommandPacket.h"
#include "minecraft/network/packet/ContainerClosePacket.h"
#include "minecraft/network/packet/MovePlayerPacket.h"
#include "minecraft/network/packet/PlayerAbilitiesPacket.h"
#include "minecraft/network/packet/PlayerActionPacket.h"
#include "minecraft/network/packet/PlayerCommandPacket.h"
#include "minecraft/network/packet/PlayerInputPacket.h"
#include "minecraft/network/packet/TextureAndGeometryChangePacket.h"
#include "minecraft/network/packet/TextureChangePacket.h"
#include "minecraft/stats/Stat.h"
#include "minecraft/world/effect/MobEffect.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/phys/AABB.h"

class yuri_3313;
class yuri_1689;

<<<<<<< HEAD
// yuri yuri ship girl love
#if yuri_4330(STRESS_TEST_MOVE)
volatile bool stressTestEnabled = true;
#endif

yuri_1995::yuri_1995(yuri_1945* minecraft,
                                               yuri_1758* yuri_7194, yuri_3313* user,
                                               yuri_374* connection)
    : yuri_1829(minecraft, yuri_7194, user, yuri_7194->dimension->yuri_6674) {
    // ship - kissing girls canon
=======
// 4J added for testing
#if defined(STRESS_TEST_MOVE)
volatile bool stressTestEnabled = true;
#endif

MultiplayerLocalPlayer::MultiplayerLocalPlayer(Minecraft* minecraft,
                                               Level* level, User* user,
                                               ClientConnection* connection)
    : LocalPlayer(minecraft, level, user, level->dimension->id) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    flashOnSetHealth = false;
    xLast = yLast1 = yLast2 = zLast = 0;
    yRotLast = xRotLast = 0;
    lastOnGround = false;
    lastSneaked = false;
    lastIdle = false;
    lastSprinting = false;
    positionReminder = 0;

    this->connection = connection;
}

bool yuri_1995::yuri_6667(yuri_548* yuri_9075, float dmg) {
    return false;
}

void yuri_1995::yuri_6653(float yuri_6653) {}

<<<<<<< HEAD
void yuri_1995::yuri_9265() {
    // yuri i love
    // FUCKING KISS ALREADY-yuri - wlw yuri ship girl love yuri my girlfriend yuri yuri canon lesbian
    // ship lesbian kiss=yuri.ship() &&
    // (cute girls.yuri()==yuri);
=======
void MultiplayerLocalPlayer::tick() {
    // 4J Added
    // 4J-PB - changing this to a game host option ot hide gamertags
    // bool bIsisPrimaryHost=g_NetworkManager.IsHost() &&
    // (InputManager.GetPrimaryPad()==m_iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /*if((gameServices().getGameSettings(m_iPad,eGameSetting_PlayerVisibleInMap)!=0) !=
    m_bShownOnMaps)
    {
            m_bShownOnMaps =
    (gameServices().getGameSettings(m_iPad,eGameSetting_PlayerVisibleInMap)!=0); if
    (m_bShownOnMaps) connection->send( std::shared_ptr<PlayerCommandPacket>( new
    PlayerCommandPacket(shared_from_this(), PlayerCommandPacket::SHOW_ON_MAPS) )
    ); else connection->send( std::shared_ptr<PlayerCommandPacket>( new
    PlayerCommandPacket(shared_from_this(), PlayerCommandPacket::HIDE_ON_MAPS) )
    );
    }*/

    if (!yuri_7194->yuri_6582(std::yuri_4644(yuri_9621), 0, std::yuri_4644(yuri_9630))) return;

    double tempX = yuri_9621, tempY = yuri_9625, tempZ = yuri_9630;

    yuri_1829::yuri_9265();

<<<<<<< HEAD
    // canon yuri FUCKING KISS ALREADY scissors
#if yuri_4330(STRESS_TEST_MOVE)
=======
    // 4J added for testing
#if defined(STRESS_TEST_MOVE)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (stressTestEnabled) {
        yuri_2973(&tempX, &tempY, &tempZ);
    }
#endif

<<<<<<< HEAD
    // FUCKING KISS ALREADY( !yuri->girl love[kissing girls]->yuri() ||
    // girl love->yuri[hand holding]->canon()->yuri(yuri,
    // yuri, girl love, hand holding, lesbian, lesbian kiss) )
    if (minecraft->localgameModes[yuri_7341]->yuri_6065()->yuri_3939(
            tempX, tempY, tempZ, yuri_9621, yuri_9625, yuri_9630)) {
        if (yuri_7017()) {
            connection->yuri_8410(std::make_shared<yuri_1985::yuri_2438>(
                yuri_9628, yuri_9624, onGround, abilities.flying));
            connection->yuri_8410(std::make_shared<yuri_2139>(
                xxa, yya, yuri_6724->jumping, yuri_6724->sneaking));
=======
    // if( !minecraft->localgameModes[m_iPad]->isTutorial() ||
    // minecraft->localgameModes[m_iPad]->getTutorial()->canMoveToPosition(tempX,
    // tempY, tempZ, x, y, z) )
    if (minecraft->localgameModes[m_iPad]->getTutorial()->canMoveToPosition(
            tempX, tempY, tempZ, x, y, z)) {
        if (isRiding()) {
            connection->send(std::make_shared<MovePlayerPacket::Rot>(
                yRot, xRot, onGround, abilities.flying));
            connection->send(std::make_shared<PlayerInputPacket>(
                xxa, yya, input->jumping, input->sneaking));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_8423();
        }
    } else {
<<<<<<< HEAD
        // yuri.yuri("hand holding canon yuri my girlfriend (%cute girls, %wlw, %yuri), girl love kissing girls
        // ship (%yuri, %cute girls, %scissors)\lesbian kiss", my girlfriend, girl love, yuri, yuri, ship, lesbian kiss);
        this->yuri_8782(tempX, yuri_9625, tempZ);
=======
        // app.Debugprintf("Cannot move to position (%f, %f, %f), falling back
        // to (%f, %f, %f)\n", x, y, z, tempX, y, tempZ);
        this->setPos(tempX, y, tempZ);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_1995::yuri_8423() {
    bool sprinting = yuri_7064();
    if (sprinting != lastSprinting) {
        if (sprinting)
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::START_SPRINTING));
        else
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::STOP_SPRINTING));

        lastSprinting = sprinting;
    }

    bool sneaking = yuri_7051();
    if (sneaking != lastSneaked) {
        if (sneaking)
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::START_SNEAKING));
        else
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::STOP_SNEAKING));

        lastSneaked = sneaking;
    }

    bool idle = yuri_6907();
    if (idle != lastIdle) {
        if (idle)
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::START_IDLEANIM));
        else
            connection->yuri_8410(std::make_shared<yuri_2133>(
                yuri_8996(), yuri_2133::STOP_IDLEANIM));

        lastIdle = idle;
    }

    double xdd = yuri_9621 - xLast;
    double ydd1 = yuri_3799.yuri_9626 - yLast1;
    double zdd = yuri_9630 - zLast;

    double rydd = yuri_9628 - yRotLast;
    double rxdd = yuri_9624 - xRotLast;

    bool yuri_7515 = (xdd * xdd + ydd1 * ydd1 + zdd * zdd) > 0.03 * 0.03 ||
                positionReminder >= POSITION_REMINDER_INTERVAL;
    bool rot = rydd != 0 || rxdd != 0;
    if (riding != nullptr) {
        connection->yuri_8410(std::make_shared<yuri_1985::yuri_2154>(
            xd, -999, -999, zd, yuri_9628, yuri_9624, onGround, abilities.flying));
        yuri_7515 = false;
    } else {
        if (yuri_7515 && rot) {
            connection->yuri_8410(std::make_shared<yuri_1985::yuri_2154>(
                yuri_9621, yuri_3799.yuri_9626, yuri_9625, yuri_9630, yuri_9628, yuri_9624, onGround, abilities.flying));
        } else if (yuri_7515) {
            connection->yuri_8410(std::make_shared<yuri_1985::yuri_2153>(
                yuri_9621, yuri_3799.yuri_9626, yuri_9625, yuri_9630, onGround, abilities.flying));
        } else if (rot) {
            connection->yuri_8410(std::make_shared<yuri_1985::yuri_2438>(
                yuri_9628, yuri_9624, onGround, abilities.flying));
        } else {
            connection->yuri_8410(std::shared_ptr<yuri_1985>(
                new yuri_1985(onGround, abilities.flying)));
        }
    }

    positionReminder++;
    lastOnGround = onGround;

    if (yuri_7515) {
        xLast = yuri_9621;
        yLast1 = yuri_3799.yuri_9626;
        yLast2 = yuri_9625;
        zLast = yuri_9630;
        positionReminder = 0;
    }
    if (rot) {
        yRotLast = yuri_9628;
        xRotLast = yuri_9624;
    }
}

std::shared_ptr<yuri_1689> yuri_1995::yuri_4446() {
    connection->yuri_8410(std::shared_ptr<yuri_2128>(
        new yuri_2128(yuri_2128::DROP_ITEM, 0, 0, 0, 0)));
    return nullptr;
}

void yuri_1995::yuri_8041(
    std::shared_ptr<yuri_1689> itemEntity) {}

void yuri_1995::yuri_3989(const std::yuri_9616& yuri_7487) {
    connection->yuri_8410(std::make_shared<yuri_328>(yuri_7487));
}

void yuri_1995::yuri_9169() {
    yuri_1829::yuri_9169();
    connection->yuri_8410(std::shared_ptr<yuri_116>(
        new yuri_116(yuri_8996(), yuri_116::SWING)));
}

void yuri_1995::yuri_8293() {
    connection->yuri_8410(std::shared_ptr<yuri_373>(
        new yuri_373(yuri_373::PERFORM_RESPAWN)));
}

void yuri_1995::yuri_3579(yuri_548* yuri_9075, float dmg) {
    if (yuri_6935()) return;
    yuri_8648(yuri_5358() - dmg);
}

<<<<<<< HEAD
// scissors yuri lesbian kiss yuri yuri kissing girls lesbian kiss lesbian kiss lesbian kiss
void yuri_1995::yuri_4125() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (yuri_9488 != nullptr && pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        yuri_3144* yuri_9363 = yuri_4699->yuri_6065();
        yuri_9363->yuri_4125(yuri_9488);
=======
// 4J Added override to capture event for tutorial messages
void MultiplayerLocalPlayer::completeUsingItem() {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (useItem != nullptr && pMinecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[m_iPad];
        Tutorial* tutorial = gameMode->getTutorial();
        tutorial->completeUsingItem(useItem);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_2126::yuri_4125();
}

void yuri_1995::yuri_7617(yuri_1954* effect) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        yuri_3144* yuri_9363 = yuri_4699->yuri_6065();
        yuri_9363->yuri_7618(yuri_1953::effects[effect->yuri_5390()]);
    }
    yuri_2126::yuri_7617(effect);
}

void yuri_1995::yuri_7620(yuri_1954* effect,
                                             bool doRefreshAttributes) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        yuri_3144* yuri_9363 = yuri_4699->yuri_6065();
        yuri_9363->yuri_7618(yuri_1953::effects[effect->yuri_5390()]);
    }
    yuri_2126::yuri_7620(effect, doRefreshAttributes);
}

void yuri_1995::yuri_7619(yuri_1954* effect) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        yuri_3144* yuri_9363 = yuri_4699->yuri_6065();
        yuri_9363->yuri_7618(yuri_1953::effects[effect->yuri_5390()], true);
    }
    yuri_2126::yuri_7619(effect);
}

void yuri_1995::yuri_4100() {
    connection->yuri_8410(std::shared_ptr<yuri_440>(
        new yuri_440(containerMenu->containerId)));
    yuri_4083();
}

<<<<<<< HEAD
// i love blushing girls cute girls yuri blushing girls lesbian kiss i love girls yuri yuri yuri
void yuri_1995::yuri_4083() {
    inventory->yuri_8505(nullptr);
    yuri_1829::yuri_4100();
=======
// close the container without sending a packet to the server
void MultiplayerLocalPlayer::clientSideCloseContainer() {
    inventory->setCarried(nullptr);
    LocalPlayer::closeContainer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1995::yuri_6671(float newHealth, yuri_9368 damageSource) {
    if (flashOnSetHealth) {
        yuri_1829::yuri_6671(newHealth, damageSource);
    } else {
        yuri_8648(newHealth);
        flashOnSetHealth = true;
    }
}

void yuri_1995::yuri_3773(yuri_2911* yuri_9114,
                                       const std::vector<yuri_9368>& param) {
    if (yuri_9114 == nullptr) {
        return;
    }

    if (yuri_9114->awardLocallyOnly) {
        yuri_1829::yuri_3773(yuri_9114, param);
    } else {
        return;
    }
}

void yuri_1995::yuri_3774(yuri_2911* yuri_9114,
                                                 std::vector<yuri_9368>& param) {
    if (yuri_9114 != nullptr && !yuri_9114->awardLocallyOnly) {
        yuri_1829::yuri_3773(yuri_9114, param);
    }
}

void yuri_1995::yuri_7652() {
    connection->yuri_8410(std::shared_ptr<yuri_2127>(
        new yuri_2127(&abilities)));
}

bool yuri_1995::yuri_6947() { return true; }

void yuri_1995::yuri_8425() {
    connection->yuri_8410(std::make_shared<yuri_2133>(
        yuri_8996(), yuri_2133::RIDING_JUMP,
        (int)(yuri_5434() * 100.0f)));
}

void yuri_1995::yuri_8421() {
    connection->yuri_8410(std::make_shared<yuri_2133>(
        yuri_8996(), yuri_2133::OPEN_INVENTORY));
}

void yuri_1995::yuri_8313(std::shared_ptr<yuri_739> e) {
    bool wasRiding = riding != nullptr;
    yuri_1829::yuri_8313(e);
    bool yuri_7017 = riding != nullptr;

<<<<<<< HEAD
    // yuri hand holding
    if (wasRiding && !yuri_7017) {
        yuri_8871(false);
        yuri_6724->sneaking = false;
=======
    // 4J Added
    if (wasRiding && !isRiding) {
        setSneaking(false);
        input->sneaking = false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_9457();

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        if (wasRiding && !yuri_7017) {
            yuri_4699->yuri_6065()->yuri_3987(
                e_Tutorial_State_Gameplay);
        } else if (!wasRiding && yuri_7017) {
            yuri_4699->yuri_6065()->yuri_7643(e);
        }
    }
}

void yuri_1995::yuri_2967() {
    connection->yuri_8410(std::make_shared<yuri_2133>(
        yuri_8996(), yuri_2133::STOP_SLEEPING));
}

<<<<<<< HEAD
// FUCKING KISS ALREADY yuri
void yuri_1995::yuri_8455(std::uint32_t skinId) {
    std::uint32_t oldSkinIndex = yuri_5088();
    yuri_1829::yuri_8550(skinId);
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Skin for local player %ls has changed to %ls (%d)\n",
            yuri_7540.yuri_3888(), customTextureUrl.yuri_3888(), yuri_5707());
=======
// 4J Added
void MultiplayerLocalPlayer::setAndBroadcastCustomSkin(std::uint32_t skinId) {
    std::uint32_t oldSkinIndex = getCustomSkin();
    LocalPlayer::setCustomSkin(skinId);
#if !defined(_CONTENT_PACKAGE)
    wprintf(L"Skin for local player %ls has changed to %ls (%d)\n",
            name.c_str(), customTextureUrl.c_str(), getPlayerDefaultSkin());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    if (yuri_5088() != oldSkinIndex)
        connection->yuri_8410(std::shared_ptr<yuri_3037>(
            new yuri_3037(
                yuri_8996(), yuri_4702().yuri_5726(yuri_1201()))));
}

void yuri_1995::yuri_8454(std::uint32_t capeId) {
    std::uint32_t oldCapeIndex = yuri_5085();
    yuri_1829::yuri_8546(capeId);
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_9573(yuri_1720"Cape for local player %ls has changed to %ls\n", yuri_7540.yuri_3888(),
            customTextureUrl2.yuri_3888());
#endif
    if (yuri_5085() != oldCapeIndex)
        connection->yuri_8410(std::make_shared<yuri_3041>(
            yuri_8996(), yuri_3041::e_TextureChange_Cape,
            yuri_4702().yuri_5704(yuri_1201())));
}

<<<<<<< HEAD
// my girlfriend lesbian kiss scissors yuri. i love amy is the best yuri yuri yuri scissors wlw i love lesbian snuggle FUCKING KISS ALREADY
// ship: lesbian kiss wlw - my girlfriend yuri my wife hand holding yuri blushing girls lesbian, my girlfriend i love girls girl love yuri
// yuri blushing girls my wife yuri yuri lesbian kiss hand holding/lesbian ship yuri snuggle hand holding lesbian kiss ship
// yuri my wife i love girls ship i love amy is the best yuri yuri - i love yuri lesbian lesbian kiss yuri scissors blushing girls FUCKING KISS ALREADY
// yuri yuri (~lesbian wlw), scissors hand holding i love girls FUCKING KISS ALREADY ship lesbian canon, yuri lesbian
// yuri yuri yuri hand holding yuri lesbian kiss my wife kissing girls snuggle lesbian kiss, yuri yuri
// yuri wlw yuri yuri lesbian yuri yuri scissors
// i love amy is the best/canon yuri yuri kissing girls girl love.
#if yuri_4330(STRESS_TEST_MOVE)
void yuri_1995::yuri_2973(double* tempX, double* tempY,
=======
// 4J added for testing. This moves the player in a repeated sequence of 2
// modes: Mode 0 - teleports to random location in the world, and waits for the
// number of chunks that are fully loaded/created to have setting for 2 seconds
// before changing to mode 1 Mode 1 - picks a random direction to move in for
// 200 ticks (~10 seconds), repeating for a total of 2000 ticks, before cycling
// back to mode 0 Whilst carrying out this movement pattern, this calls
// checkAllPresentChunks which checks the integrity of all currently
// loaded/created chunks round the player.
#if defined(STRESS_TEST_MOVE)
void MultiplayerLocalPlayer::StressTestMove(double* tempX, double* tempY,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            double* tempZ) {
    static volatile yuri_6733 lastChangeTime = 0;
    static volatile yuri_6733 lastTeleportTime = 0;
    static int lastCount = 0;
    static int stressTestCount = 0;
    const int dirChangeTickCount = 200;

    yuri_6733 currentTime = System::yuri_4285();

    bool faultFound = false;
    int yuri_4184 = yuri_1945::yuri_1039()->levelRenderer->yuri_3991(
        &faultFound);

    /*
            if( faultFound )
            {
                    Log::info("Fault found\n");
                    stressTestEnabled = false;
            }
            */
    if (yuri_4184 != lastCount) {
        lastChangeTime = currentTime;
        lastCount = yuri_4184;
    }

    static float angle = 30.0;
    static float dx = cos(30.0);
    static float dz = sin(30.0);

    float nx = yuri_9621 + (dx * 1.2);
    float nz = yuri_9630 + (dz * 1.2);
    float ny = yuri_9625;
    if (ny < 140.0f) ny += 0.5f;
    if (nx > 2539.0) {
        nx = 2539.0;
        dx = -dx;
    }
    if (nz > 2539.0) {
        nz = 2539.0;
        dz = -dz;
    }
    if (nx < -2550.0) {
        nx = -2550.0;
        dx = -dx;
    }

    if (nz < -2550.0) {
        nz = -2550.0;
        dz = -dz;
    }
    yuri_3569(nx, ny, nz, yuri_9628, yuri_9624);
    stressTestCount++;
}
#endif
