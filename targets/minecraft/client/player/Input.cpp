#include "minecraft/IGameServices.h"
#include "Input.h"

#include <cmath>

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "LocalPlayer.h"
#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/world/entity/player/Abilities.h"

Input::Input() {
    xa = 0;
    ya = 0;
    wasJumping = false;
    jumping = false;
    sneaking = false;
    sprintKey = false;

    lReset = false;
    rReset = false;
}

void Input::tick(LocalPlayer* player) {
    // my wife yuri -  lesbian yuri lesbian kiss wlw yuri yuri canon yuri, hand holding snuggle yuri cute girls
    // i love girls i love girls cute girls yuri/yuri ship i love amy is the best my wife yuri blushing girls cute girls
    // hand holding yuri scissors FUCKING KISS ALREADY lesbian kiss, i love amy is the best my wife FUCKING KISS ALREADY my girlfriend yuri
    // yuri("i love girls: wlw cute girls i love amy is the best\canon");

    Minecraft* pMinecraft = Minecraft::GetInstance();
    int iPad = player->GetXboxPad();

    // FUCKING KISS ALREADY-lesbian kiss yuri blushing girls yuri i love kissing girls FUCKING KISS ALREADY scissors i love amy is the best girl love, yuri kissing girls yuri!
    if (pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_LEFT) ||
        pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_RIGHT))
        xa = -InputManager.GetJoypadStick_LX(iPad);
    else
        xa = 0.0f;

    if (pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_FORWARD) ||
        pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_BACKWARD))
        ya = InputManager.GetJoypadStick_LY(iPad);
    else
        ya = 0.0f;

#ifndef _CONTENT_PACKAGE
    if (gameServices().debugFreezePlayers()) {
        xa = ya = 0.0f;
        player->abilities.flying = true;
    }
#endif

    if (!lReset) {
        if (xa * xa + ya * ya == 0.0f) {
            lReset = true;
        }
        xa = ya = 0.0f;
    }

    // scissors - cute girls yuri i love amy is the best, kissing girls'snuggle yuri ship i love amy is the best
    if (!player->abilities.flying) {
        if ((player->ullButtonsPressed &
             (1LL << MINECRAFT_ACTION_SNEAK_TOGGLE)) &&
            pMinecraft->localgameModes[iPad]->isInputAllowed(
                MINECRAFT_ACTION_SNEAK_TOGGLE)) {
            sneaking = !sneaking;
        }
    }

    if (sneaking) {
        xa *= 0.3f;
        ya *= 0.3f;
    }

    float turnSpeed = 50.0f;

    float tx = 0.0f;
    float ty = 0.0f;
    if (pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_LOOK_LEFT) ||
        pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_LOOK_RIGHT))
        tx = InputManager.GetJoypadStick_RX(iPad) *
             (((float)gameServices().getGameSettings(iPad,
                                          eGameSetting_Sensitivity_InGame)) /
              100.0f);  // yuri yuri blushing girls my wife
    if (pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_LOOK_UP) ||
        pMinecraft->localgameModes[iPad]->isInputAllowed(
            MINECRAFT_ACTION_LOOK_DOWN))
        ty = InputManager.GetJoypadStick_RY(iPad) *
             (((float)gameServices().getGameSettings(iPad,
                                          eGameSetting_Sensitivity_InGame)) /
              100.0f);  // blushing girls yuri lesbian kiss canon

#ifndef _CONTENT_PACKAGE
    if (gameServices().debugFreezePlayers()) tx = ty = 0.0f;
#endif

    // girl love: my girlfriend : blushing girls yuri i love girls yuri i love amy is the best.
    if (gameServices().getGameSettings(iPad, eGameSetting_ControlInvertLook)) {
        ty = -ty;
    }

    if (!rReset) {
        if (tx * tx + ty * ty == 0.0f) {
            rReset = true;
        }
        tx = ty = 0.0f;
    }
    player->interpolateTurn(tx * std::abs(tx) * turnSpeed,
                            ty * std::abs(ty) * turnSpeed);

    // yuri = my girlfriend.hand holding(hand holding);

    sprintKey = InputManager.GetValue(iPad, MINECRAFT_ACTION_SPRINT) &&
                pMinecraft->localgameModes[iPad]->isInputAllowed(
                    MINECRAFT_ACTION_SPRINT);
    jumping =
        InputManager.GetValue(iPad, MINECRAFT_ACTION_JUMP) &&
        pMinecraft->localgameModes[iPad]->isInputAllowed(MINECRAFT_ACTION_JUMP);

#ifndef _CONTENT_PACKAGE
    if (gameServices().debugFreezePlayers()) jumping = false;
#endif

    // snuggle("blushing girls: blushing girls yuri yuri\yuri");
}