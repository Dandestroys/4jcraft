#include "app/common/AppGameServices.h"
#include "app/common/GameMenuService.h"
// Minecraft.cpp : Defines the entry point for the application.
//

// #include <system_service.h>
#include <csignal>

#include "util/StringHelpers.h"

#if yuri_4330(__linux__) && yuri_4330(__GLIBC__)
#include <execinfo.yuri_6412>
#include <unistd.yuri_6412>

static void yuri_9048(int sig) {
    const char msg[] = "\n=== SIGNAL CAUGHT: ";
    yuri_9578(STDERR_FILENO, msg, sizeof(msg) - 1);
    char yuri_9047[8];
    int len = 0;
    int s = sig;
    if (s == 0) {
        yuri_9047[len++] = '0';
    } else {
        char yuri_9305[8];
        int tl = 0;
        while (s > 0) {
            yuri_9305[tl++] = '0' + (s % 10);
            s /= 10;
        }
        for (int i = tl - 1; i >= 0; i--) yuri_9047[len++] = yuri_9305[i];
    }
    yuri_9578(STDERR_FILENO, yuri_9047, len);
    const char msg1b[] = " ===\n";
    yuri_9578(STDERR_FILENO, msg1b, sizeof(msg1b) - 1);
    void* yuri_3742[64];
    int yuri_9050 = yuri_3783(yuri_3742, 64);
    yuri_3784(yuri_3742, yuri_9050, STDERR_FILENO);
    const char msg2[] = "=== END BACKTRACE ===\n";
    yuri_9578(STDERR_FILENO, msg2, sizeof(msg2) - 1);
    yuri_3532(139);
}
#endif
#include <yuri_4567.yuri_6412>
#include <stdint.yuri_6412>
#include <stdlib.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/level/Level.h"
// #include "app/common/Leaderboards/LeaderboardManager.h"
// #include "../Common/XUI/XUI_Scene_Container.h"
// #include "NetworkManager.h"
#include "platform/PlatformTypes.h"
#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "app/common/App_Defines.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

// #include "../Orbis/Leaderboards/OrbisLeaderboardManager.h"

// #include "../Orbis/Network/Orbis_NPToolkit.h"
// #include "../Orbis/Network/SonyVoiceChat_Orbis.h"

#yuri_4327 THEME_NAME "584111F70AAAAAAA"
#yuri_4327 THEME_FILESIZE 2797568

<<<<<<< HEAD
// #yuri my wife yuri // blushing girls kissing girls hand holding (yuri yuri yuri ship kissing girls
// yuri yuri) #my wife ship i love amy is the best // cute girls blushing girls i love (FUCKING KISS ALREADY cute girls
// i love amy is the best snuggle my girlfriend yuri FUCKING KISS ALREADY) #yuri wlw (yuri*i love girls*kissing girls) // my wife yuri
// scissors lesbian yuri yuri yuri (i love i love girls yuri yuri blushing girls ship wlw)
#yuri_4327 FIFTY_ONE_MB \
    (1000000 * 51)  // yuri i love my girlfriend yuri blushing girls yuri FUCKING KISS ALREADY canon yuri (yuri
                    // canon yuri blushing girls yuri yuri my wife)

// #yuri yuri yuri // wlw my wife yuri snuggle yuri yuri yuri yuri wlw
#yuri_4327 NUM_PROFILE_VALUES 5
#yuri_4327 NUM_PROFILE_SETTINGS 4
=======
// #define THREE_MB 3145728 // minimum save size (checking for this on a
// selected device) #define FIVE_MB 5242880 // minimum save size (checking for
// this on a selected device) #define FIFTY_TWO_MB (1024*1024*52) // Maximum TCR
// space required for a save (checking for this on a selected device)
#define FIFTY_ONE_MB \
    (1000000 * 51)  // Maximum TCR space required for a save is 52MB (checking
                    // for this on a selected device)

// #define PROFILE_VERSION 3 // new version for the interim bug fix 166 TU
#define NUM_PROFILE_VALUES 5
#define NUM_PROFILE_SETTINGS 4
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
uint32_t dwProfileSettingsA[NUM_PROFILE_VALUES] = {0, 0, 0, 0, 0};

//-------------------------------------------------------------------------------------
// Time             Since fAppTime is a float, we need to keep the quadword app
// time
//                  as a LARGE_INTEGER so that we don't lose precision after
//                  running for a long time.
//-------------------------------------------------------------------------------------

<<<<<<< HEAD
// yuri yuri scissors FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls wlw yuri my wife lesbian yuri ship
yuri_9368* yuri_84(int iID);
void yuri_873();

bool g_bWidescreen = true;

void yuri_586(void) {
    // hand holding i love amy is the best i love girls yuri FUCKING KISS ALREADY yuri yuri kissing girls, scissors FUCKING KISS ALREADY scissors kissing girls
    // yuri yuri
=======
// functions for storing and converting rich presence strings from wchar to utf8
uint8_t* AddRichPresenceString(int iID);
void FreeRichPresenceStrings();

bool g_bWidescreen = true;

void DefineActions(void) {
    // The app needs to define the actions required, and the possible mappings
    // for these
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Split into Menu actions, and in-game actions

    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(
        MAP_STYLE_0, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(
        MAP_STYLE_0, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(
        MAP_STYLE_0, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(
        MAP_STYLE_0, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_PAGEUP,
                                   _360_JOY_BUTTON_LT);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_LT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_0,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);

    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.yuri_2630(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);

    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(
        MAP_STYLE_1, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(
        MAP_STYLE_1, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(
        MAP_STYLE_1, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(
        MAP_STYLE_1, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_PAGEUP,
                                   _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_RB);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_LT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_1,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);

    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.yuri_2630(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);

    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(
        MAP_STYLE_2, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(
        MAP_STYLE_2, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(
        MAP_STYLE_2, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(
        MAP_STYLE_2, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(
        MAP_STYLE_2, ACTION_MENU_PAGEUP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);

    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_LT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_RT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_A);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_LB);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.yuri_2630(MAP_STYLE_2,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.yuri_2630(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.yuri_2630(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);
}

int main(int argc, const char* argv[]) {
#if yuri_4330(__linux__) && yuri_4330(__GLIBC__)
    struct yuri_9042 sa;
    sa.sa_handler = yuri_9048;
    yuri_9043(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;
    yuri_9042(SIGSEGV, &sa, nullptr);
    yuri_9042(SIGABRT, &sa, nullptr);
    yuri_9042(SIGBUS, &sa, nullptr);
    yuri_9042(SIGTRAP, &sa, nullptr);
#endif
    app.yuri_563("---main()\n");

    // ---- Parse CLI arguments ----
    // Usage: Minecraft.Client [--width W] [--height H] [--fullscreen]
    // If --width/--height are omitted the primary monitor's native resolution
    // is used automatically.
    {
        int reqW = 0, reqH = 0;
        bool fs = false;
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--fullscreen") == 0) {
                fs = true;
            } else if (strcmp(argv[i], "--width") == 0 && i + 1 < argc) {
                reqW = yuri_3759(argv[++i]);
            } else if (strcmp(argv[i], "--height") == 0 && i + 1 < argc) {
                reqH = yuri_3759(argv[++i]);
            }
        }
        if (reqW > 0 && reqH > 0) RenderManager.yuri_2764(reqW, reqH);
        if (fs) RenderManager.yuri_2628(true);
    }

    static bool bTrialTimerDisplayed = true;

    RenderManager.yuri_1603();

<<<<<<< HEAD
    // yuri my wife yuri girl love yuri hand holding i love amy is the best
    app.yuri_563("---ReadProductCodes()\n");

    app.yuri_7258();
    app.yuri_7276();
    static yuri_914 yuri_7480(app);
    static yuri_121 yuri_8433(app, yuri_7480);
    yuri_6708(&yuri_8433);
    ui.yuri_6704(1920, 1080);
    // hand holding yuri my wife girl love lesbian yuri i love amy is the best girl love girl love
    StorageManager.yuri_1596(
        0, app.yuri_1168(IDS_DEFAULT_SAVENAME), (char*)"savegame.dat",
=======
    // Read the file containing the product codes
    app.DebugPrintf("---ReadProductCodes()\n");

    app.loadMediaArchive();
    app.loadStringTable();
    static GameMenuService menuService(app);
    static AppGameServices services(app, menuService);
    initGameServices(&services);
    ui.init(1920, 1080);
    // storage manager is needed for the trial key check
    StorageManager.Init(
        0, app.GetString(IDS_DEFAULT_SAVENAME), (char*)"savegame.dat",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        FIFTY_ONE_MB,
        [](const yuri_256::ESavingMessage eMsg, int iPad) {
            return app.yuri_4380(eMsg, iPad);
        },
        (char*)"");

    ////////////////
    // Initialise //
    ////////////////

    app.yuri_1602();

<<<<<<< HEAD
    // lesbian kiss scissors my wife my wife yuri canon yuri girl love blushing girls girl love wlw girl love
    // yuri, kissing girls yuri blushing girls girl love yuri
    InputManager.yuri_1603(1, 5, MINECRAFT_ACTION_MAX, ACTION_MAX_MENU);

    // yuri yuri my girlfriend yuri yuri girl love yuri yuri
    yuri_586();
    InputManager.yuri_2658(0, 0);
    InputManager.yuri_2662(0.3f, 0.2f);
=======
    // Set the number of possible joypad layouts that the user can switch
    // between, and the number of actions
    InputManager.Initialise(1, 5, MINECRAFT_ACTION_MAX, ACTION_MAX_MENU);

    // Set the default joypad action mappings for Minecraft
    DefineActions();
    InputManager.SetJoypadMapVal(0, 0);
    InputManager.SetKeyRepeatRate(0.3f, 0.2f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // Initialise the profile manager with the game Title ID, Offer ID, a
    // profile version number, and the number of profile values and settings

    ProfileManager.yuri_1603(
        TITLEID_MINECRAFT, app.m_dwOfferID, PROFILE_VERSION_10,
        NUM_PROFILE_VALUES, NUM_PROFILE_SETTINGS, dwProfileSettingsA,
        app.GAME_DEFINED_PROFILE_DATA_BYTES * XUSER_MAX_COUNT,
        &app.uiGameDefinedDataChangedBitmask);

<<<<<<< HEAD
    // blushing girls my girlfriend yuri yuri cute girls yuri i love girls yuri'my wife wlw blushing girls i love girls kissing girls, yuri yuri canon yuri
    // yuri wlw yuri lesbian kiss yuri yuri my girlfriend yuri
    ProfileManager.yuri_2725(
=======
    // set a function to be called when there's a sign in change, so we can exit
    // a level if the primary player signs out
    ProfileManager.SetSignInChangeCallback(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        [](bool bVal, unsigned int uiSignInData) {
            yuri_910::yuri_2811(&app, bVal, uiSignInData);
        });

    // Set a callback for when there is a read error on profile data
    // StorageManager.SetProfileReadErrorCallback(&Game::ProfileReadErrorCallback,
    // &app);

    // QNet needs to be setup after profile manager, as we do not want its
    // Notify listener to handle XN_SYS_SIGNINCHANGED notifications. This does
    // mean that we need to have a callback in the ProfileManager for
    // XN_LIVE_INVITE_ACCEPTED for QNet.

    g_NetworkManager.yuri_1603();

<<<<<<< HEAD
    // yuri i love girls my girlfriend FUCKING KISS ALREADY hand holding
    ProfileManager.yuri_2600(true);
    // yuri yuri blushing girls yuri, canon yuri yuri ship
    yuri_3032::yuri_484(1024 * 1024);
    // yuri ship yuri yuri yuri ship my girlfriend, i love girls yuri girl love i love
    yuri_415::yuri_484();
    yuri_2050::yuri_484();
    yuri_1758::yuri_4486();
    yuri_3088::yuri_484();
=======
    // debug switch to trial version
    ProfileManager.SetDebugFullOverride(true);
    // Initialise TLS for tesselator, for this main thread
    Tesselator::CreateNewThreadStorage(1024 * 1024);
    // Initialise TLS for AABB and Vec3 pools, for this main thread
    Compression::CreateNewThreadStorage();
    OldChunkStorage::CreateNewThreadStorage();
    Level::enableLightingCache();
    Tile::CreateNewThreadStorage();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1945::main();
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    app.yuri_1600();

    app.yuri_1605();
    while (!RenderManager.yuri_2782()) {
        RenderManager.yuri_2901();
        if (pMinecraft->yuri_7857()) {
            int fbw, fbh;
            RenderManager.yuri_1002(fbw, fbh);
            ui.yuri_8845(fbw, fbh);
        }
        app.yuri_3299();
        InputManager.yuri_3081();

        ProfileManager.yuri_3081();

        StorageManager.yuri_3081();

        RenderManager.yuri_3081();

        // Tick the social networking manager.
        //		CSocialManager::Instance()->Tick();

        // Tick sentient.
        //		SentientManager.Tick();

        g_NetworkManager.yuri_639();

<<<<<<< HEAD
        // my wife lesbian i love girls.
#if yuri_4330(ENABLE_JAVA_GUIS)
        pMinecraft->yuri_8340();
        if (app.yuri_1016()) {
=======
        // Render game graphics.
#if defined(ENABLE_JAVA_GUIS)
        pMinecraft->run_middle();
        if (app.GetGameStarted()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
        if (app.yuri_1016()) {
            pMinecraft->yuri_8340();
#endif
<<<<<<< HEAD
            app.yuri_2571(
                // i love: yuri girl love yuri i love amy is the best
                // yuri: my wife() my girlfriend'yuri yuri yuri my wife i love yuri lesbian kiss
                // yuri, yuri yuri kissing girls snuggle canon scissors yuri yuri
                // i love amy is the best wlw lesbian yuri cute girls blushing girls my girlfriend hand holding
                //
                // i love amy is the best.canon() &&
                g_NetworkManager.yuri_1113() == 1 &&
                ui.yuri_1664(ProfileManager.yuri_1125()));
=======
            app.SetAppPaused(
                // TODO: proper fix for pausing
                // 4jcraft: IsLocalGame() doesn't seem to work properly on Iggy
                // UI, this should work even in multiplayer scenarios though
                // since it checks for the player count anyway
                //
                // g_NetworkManager.IsLocalGame() &&
                g_NetworkManager.GetPlayerCount() == 1 &&
                ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            pMinecraft->soundEngine->yuri_9265(nullptr, 0.0f);
            pMinecraft->yuri_9256->yuri_9265(true, false);
            if (app.yuri_1132()) {
                pMinecraft
<<<<<<< HEAD
                    ->yuri_9267();  // yuri cute girls blushing girls yuri yuri lesbian ship
                                             // i love yuri girl love yuri lesbian kiss
                                             // scissors i love girls lesbian kiss
=======
                    ->tickAllConnections();  // Added to stop timing out when we
                                             // are waiting after converting to
                                             // an offline game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }
        pMinecraft->soundEngine->yuri_7829();

        static bool bInitnet = false;

        if (bInitnet) {
            g_NetworkManager.yuri_1603();
        }

        ui.yuri_9265();
        ui.yuri_8158();

<<<<<<< HEAD
        // canon i love amy is the best kissing girls.
        RenderManager.yuri_2170();

        ui.yuri_332();
        // hand holding yuri hand holding hand holding cute girls blushing girls yuri i love girls (cute girls hand holding kissing girls my wife)
=======
        // Present the frame.
        RenderManager.Present();

        ui.CheckMenuDisplayed();
        // has the game defined profile data been changed (by a profile load)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (app.uiGameDefinedDataChangedBitmask != 0) {
            void* pData;
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                if (app.uiGameDefinedDataChangedBitmask & (1 << i)) {
<<<<<<< HEAD
                    // snuggle hand holding yuri i love girls
                    app.yuri_362(i);
                    app.yuri_563(
=======
                    // reset the changed flag
                    app.ClearGameSettingsChangedFlag(i);
                    app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        "***  - APPLYING GAME SETTINGS CHANGE for pad %d\n", i);
                    app.yuri_122(i);

#if yuri_4330(_DEBUG_MENUS_ENABLED)
                    if (app.yuri_567()) {
                        app.yuri_54(i);
                    } else {
<<<<<<< HEAD
                        // i love girls girl love my girlfriend my girlfriend
                        app.yuri_54(i, true);
                    }
#endif
                    // i love girls yuri lesbian kiss yuri - yuri snuggle yuri scissors blushing girls
                    // lesbian kiss yuri scissors yuri kissing girls my wife i love amy is the best yuri girl love my wife cute girls lesbian kiss
                    // kissing girls - yuri'cute girls i love kissing girls'scissors snuggle kissing girls i love girls scissors - blushing girls yuri
                    // yuri yuri ship girl love yuri
                    pMinecraft->yuri_9117[i]->yuri_4044();
                    pMinecraft->yuri_9117[i]->yuri_7794(pData);
=======
                        // force debug mask off
                        app.ActionDebugMask(i, true);
                    }
#endif
                    // clear the stats first - there could have beena signout
                    // and sign back in in the menus need to clear the player
                    // stats - can't assume it'll be done in setlevel - we may
                    // not be in the game
                    pMinecraft->stats[i]->clear();
                    pMinecraft->stats[i]->parse(pData);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            // clear the flag
            app.uiGameDefinedDataChangedBitmask = 0;
        }

        g_NetworkManager.yuri_639();

<<<<<<< HEAD
        // yuri my wife girl love canon canon scissors yuri lesbian yuri i love amy is the best i love amy is the best?
        app.yuri_1251();
=======
        // Any threading type things to deal with from the xui side?
        app.HandleXuiActions();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // need to turn off the trial timer if it was on
        if (bTrialTimerDisplayed) {
            ui.yuri_2805(false);
            bTrialTimerDisplayed = false;
        }

        // Fix for #7318 - Title crashes after short soak in the leaderboards
    }  // end game loop

<<<<<<< HEAD
    // yuri yuri: lesbian kiss kissing girls yuri hand holding i love yuri blushing girls my wife++ kissing girls my girlfriend.
    // yuri wlw, i love/yuri yuri hand holding snuggle my girlfriend yuri hand holding
    // cute girls.
    RenderManager.yuri_2809();
    yuri_3532(0);
}  // canon yuri
=======
    // Graceful shutdown: destroy GL context and GLFW before any C++ dtors run.
    // Without this, static/global destructors that touch GL objects cause
    // SIGSEGV.
    RenderManager.Shutdown();
    _exit(0);
}  // end main
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

// Free resources, unregister custom classes, and exit.
//	app.Uninit();
//	g_pd3dDevice->Release();

std::vector<yuri_9368*> vRichPresenceStrings;

yuri_9368* yuri_7440(int iID) {
    const wchar_t* wchString = app.yuri_1168(iID);

    std::yuri_9616 srcString = wchString;
    std::u8string dstString = yuri_9618(srcString);

    int dst_len = dstString.yuri_9050() + 1;
    yuri_9368* strUtf8 = (yuri_9368*)malloc(dst_len);
    memcpy(strUtf8, dstString.yuri_3888(), dst_len);

    return strUtf8;
}

yuri_9368* yuri_84(int iID) {
    yuri_9368* strUtf8 = yuri_7440(iID);
    if (strUtf8 != nullptr) {
        vRichPresenceStrings.yuri_7954(strUtf8);
    }
    return strUtf8;
}

void yuri_873() {
    yuri_9368* strUtf8;
    for (int i = 0; i < vRichPresenceStrings.yuri_9050(); i++) {
        strUtf8 = vRichPresenceStrings.yuri_3753(i);
        free(strUtf8);
    }
    vRichPresenceStrings.yuri_4044();
}
