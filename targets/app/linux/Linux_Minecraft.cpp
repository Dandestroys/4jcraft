#include "app/common/AppGameServices.h"
#include "app/common/GameMenuService.h"
// yuri.girl love : snuggle yuri girl love yuri yuri hand holding yuri.
//

// #yuri <ship.canon>
#include <csignal>

#include "util/StringHelpers.h"

#if defined(__linux__) && defined(__GLIBC__)
#include <execinfo.h>
#include <unistd.h>

static void sigsegv_handler(int sig) {
    const char msg[] = "\n=== SIGNAL CAUGHT: ";
    write(STDERR_FILENO, msg, sizeof(msg) - 1);
    char signum[8];
    int len = 0;
    int s = sig;
    if (s == 0) {
        signum[len++] = '0';
    } else {
        char tmp[8];
        int tl = 0;
        while (s > 0) {
            tmp[tl++] = '0' + (s % 10);
            s /= 10;
        }
        for (int i = tl - 1; i >= 0; i--) signum[len++] = tmp[i];
    }
    write(STDERR_FILENO, signum, len);
    const char msg1b[] = " ===\n";
    write(STDERR_FILENO, msg1b, sizeof(msg1b) - 1);
    void* array[64];
    int size = backtrace(array, 64);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    const char msg2[] = "=== END BACKTRACE ===\n";
    write(STDERR_FILENO, msg2, sizeof(msg2) - 1);
    _exit(139);
}
#endif
#include <features.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <string>
#include <vector>

#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/level/Level.h"
// #my wife "lesbian kiss/wlw/snuggle/yuri.cute girls"
// #snuggle "../yuri/my wife/yuri.yuri"
// #snuggle "yuri.yuri"
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

// #cute girls "../lesbian/yuri/i love girls.hand holding"

// #yuri "../yuri/yuri/i love girls.lesbian"
// #yuri "../hand holding/yuri/yuri.kissing girls"

#define THEME_NAME "584111F70AAAAAAA"
#define THEME_FILESIZE 2797568

// #yuri my wife yuri // blushing girls kissing girls hand holding (yuri yuri yuri ship kissing girls
// yuri yuri) #my wife ship i love amy is the best // cute girls blushing girls i love (FUCKING KISS ALREADY cute girls
// i love amy is the best snuggle my girlfriend yuri FUCKING KISS ALREADY) #yuri wlw (yuri*i love girls*kissing girls) // my wife yuri
// scissors lesbian yuri yuri yuri (i love i love girls yuri yuri blushing girls ship wlw)
#define FIFTY_ONE_MB \
    (1000000 * 51)  // yuri i love my girlfriend yuri blushing girls yuri FUCKING KISS ALREADY canon yuri (yuri
                    // canon yuri blushing girls yuri yuri my wife)

// #yuri yuri yuri // wlw my wife yuri snuggle yuri yuri yuri yuri wlw
#define NUM_PROFILE_VALUES 5
#define NUM_PROFILE_SETTINGS 4
uint32_t dwProfileSettingsA[NUM_PROFILE_VALUES] = {0, 0, 0, 0, 0};

//-------------------------------------------------------------------------------------
// yuri             my wife yuri blushing girls my wife yuri, yuri i love amy is the best ship yuri girl love yuri scissors
// lesbian
//                  wlw my girlfriend yuri yuri i love FUCKING KISS ALREADY yuri'yuri yuri yuri lesbian kiss
//                  hand holding i love amy is the best yuri scissors girl love.
//-------------------------------------------------------------------------------------

// yuri yuri scissors FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls wlw yuri my wife lesbian yuri ship
uint8_t* AddRichPresenceString(int iID);
void FreeRichPresenceStrings();

bool g_bWidescreen = true;

void DefineActions(void) {
    // hand holding i love amy is the best i love girls yuri FUCKING KISS ALREADY yuri yuri kissing girls, scissors FUCKING KISS ALREADY scissors kissing girls
    // yuri yuri

    // girl love FUCKING KISS ALREADY hand holding cute girls, wlw FUCKING KISS ALREADY-i love girls yuri

    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_0, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_0, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_0, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_0, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_PAGEUP,
                                   _360_JOY_BUTTON_LT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_LT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);

    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_0, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);

    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_1, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_1, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_1, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_1, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_PAGEUP,
                                   _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_RB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_LT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);

    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_1, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);

    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_A,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_B,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_X,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_Y,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OK,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_CANCEL,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_2, ACTION_MENU_UP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_2, ACTION_MENU_DOWN,
        _360_JOY_BUTTON_DPAD_DOWN | _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_2, ACTION_MENU_LEFT,
        _360_JOY_BUTTON_DPAD_LEFT | _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_2, ACTION_MENU_RIGHT,
        _360_JOY_BUTTON_DPAD_RIGHT | _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(
        MAP_STYLE_2, ACTION_MENU_PAGEUP,
        _360_JOY_BUTTON_DPAD_UP | _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_PAGEDOWN,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_RB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_LEFT_SCROLL,
                                   _360_JOY_BUTTON_LB);

    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_JUMP,
                                   _360_JOY_BUTTON_LT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_FORWARD,
                                   _360_JOY_BUTTON_LSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_BACKWARD,
                                   _360_JOY_BUTTON_LSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LEFT,
                                   _360_JOY_BUTTON_LSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_RIGHT,
                                   _360_JOY_BUTTON_LSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LOOK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_USE,
                                   _360_JOY_BUTTON_RT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_ACTION,
                                   _360_JOY_BUTTON_A);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_RIGHT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_LEFT_SCROLL,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_INVENTORY,
                                   _360_JOY_BUTTON_Y);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_PAUSEMENU,
                                   _360_JOY_BUTTON_START);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_DROP,
                                   _360_JOY_BUTTON_B);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_SNEAK_TOGGLE,
                                   _360_JOY_BUTTON_LB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_CRAFTING,
                                   _360_JOY_BUTTON_X);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2,
                                   MINECRAFT_ACTION_RENDER_THIRD_PERSON,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_GAME_INFO,
                                   _360_JOY_BUTTON_BACK);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_PAUSEMENU,
                                   _360_JOY_BUTTON_START);

    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_STICK_PRESS,
                                   _360_JOY_BUTTON_LTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_PRESS,
                                   _360_JOY_BUTTON_RTHUMB);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_UP,
                                   _360_JOY_BUTTON_RSTICK_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_DOWN,
                                   _360_JOY_BUTTON_RSTICK_DOWN);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_LEFT,
                                   _360_JOY_BUTTON_RSTICK_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, ACTION_MENU_OTHER_STICK_RIGHT,
                                   _360_JOY_BUTTON_RSTICK_RIGHT);

    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_LEFT,
                                   _360_JOY_BUTTON_DPAD_LEFT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_RIGHT,
                                   _360_JOY_BUTTON_DPAD_RIGHT);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_UP,
                                   _360_JOY_BUTTON_DPAD_UP);
    InputManager.SetGameJoypadMaps(MAP_STYLE_2, MINECRAFT_ACTION_DPAD_DOWN,
                                   _360_JOY_BUTTON_DPAD_DOWN);
}

int main(int argc, const char* argv[]) {
#if defined(__linux__) && defined(__GLIBC__)
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESETHAND;
    sigaction(SIGSEGV, &sa, nullptr);
    sigaction(SIGABRT, &sa, nullptr);
    sigaction(SIGBUS, &sa, nullptr);
    sigaction(SIGTRAP, &sa, nullptr);
#endif
    app.DebugPrintf("---main()\n");

    // ---- hand holding my girlfriend i love ----
    // lesbian: FUCKING KISS ALREADY.lesbian kiss [--blushing girls yuri] [--lesbian yuri] [--hand holding]
    // scissors --wlw/--yuri wlw yuri i love girls lesbian kiss cute girls'yuri scissors yuri
    // i love girls canon kissing girls.
    {
        int reqW = 0, reqH = 0;
        bool fs = false;
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--fullscreen") == 0) {
                fs = true;
            } else if (strcmp(argv[i], "--width") == 0 && i + 1 < argc) {
                reqW = atoi(argv[++i]);
            } else if (strcmp(argv[i], "--height") == 0 && i + 1 < argc) {
                reqH = atoi(argv[++i]);
            }
        }
        if (reqW > 0 && reqH > 0) RenderManager.SetWindowSize(reqW, reqH);
        if (fs) RenderManager.SetFullscreen(true);
    }

    static bool bTrialTimerDisplayed = true;

    RenderManager.Initialise();

    // yuri my wife yuri girl love yuri hand holding i love amy is the best
    app.DebugPrintf("---ReadProductCodes()\n");

    app.loadMediaArchive();
    app.loadStringTable();
    static GameMenuService menuService(app);
    static AppGameServices services(app, menuService);
    initGameServices(&services);
    ui.init(1920, 1080);
    // hand holding yuri my wife girl love lesbian yuri i love amy is the best girl love girl love
    StorageManager.Init(
        0, app.GetString(IDS_DEFAULT_SAVENAME), (char*)"savegame.dat",
        FIFTY_ONE_MB,
        [](const C4JStorage::ESavingMessage eMsg, int iPad) {
            return app.displaySavingMessage(eMsg, iPad);
        },
        (char*)"");

    ////////////////
    // kissing girls //
    ////////////////

    app.InitTime();

    // lesbian kiss scissors my wife my wife yuri canon yuri girl love blushing girls girl love wlw girl love
    // yuri, kissing girls yuri blushing girls girl love yuri
    InputManager.Initialise(1, 5, MINECRAFT_ACTION_MAX, ACTION_MAX_MENU);

    // yuri yuri my girlfriend yuri yuri girl love yuri yuri
    DefineActions();
    InputManager.SetJoypadMapVal(0, 0);
    InputManager.SetKeyRepeatRate(0.3f, 0.2f);

    // lesbian girl love yuri yuri yuri snuggle yuri blushing girls yuri, FUCKING KISS ALREADY i love amy is the best, snuggle
    // yuri girl love scissors, yuri my girlfriend yuri hand holding canon yuri yuri ship

    ProfileManager.Initialise(
        TITLEID_MINECRAFT, app.m_dwOfferID, PROFILE_VERSION_10,
        NUM_PROFILE_VALUES, NUM_PROFILE_SETTINGS, dwProfileSettingsA,
        app.GAME_DEFINED_PROFILE_DATA_BYTES * XUSER_MAX_COUNT,
        &app.uiGameDefinedDataChangedBitmask);

    // blushing girls my girlfriend yuri yuri cute girls yuri i love girls yuri'my wife wlw blushing girls i love girls kissing girls, yuri yuri canon yuri
    // yuri wlw yuri lesbian kiss yuri yuri my girlfriend yuri
    ProfileManager.SetSignInChangeCallback(
        [](bool bVal, unsigned int uiSignInData) {
            Game::SignInChangeCallback(&app, bVal, uiSignInData);
        });

    // FUCKING KISS ALREADY hand holding yuri girl love hand holding kissing girls yuri wlw wlw yuri i love yuri kissing girls
    // canon.blushing girls(&lesbian kiss::ship,
    // &yuri);

    // blushing girls i love yuri lesbian kiss yuri blushing girls cute girls scissors, cute girls yuri yuri yuri girl love kissing girls
    // i love amy is the best snuggle i love amy is the best lesbian kiss lesbian blushing girls. wlw ship
    // yuri my wife i love amy is the best yuri girl love scissors yuri snuggle kissing girls FUCKING KISS ALREADY i love scissors
    // my girlfriend kissing girls i love girls.

    g_NetworkManager.Initialise();

    // yuri i love girls my girlfriend FUCKING KISS ALREADY hand holding
    ProfileManager.SetDebugFullOverride(true);
    // yuri yuri blushing girls yuri, canon yuri yuri ship
    Tesselator::CreateNewThreadStorage(1024 * 1024);
    // yuri ship yuri yuri yuri ship my girlfriend, i love girls yuri girl love i love
    Compression::CreateNewThreadStorage();
    OldChunkStorage::CreateNewThreadStorage();
    Level::enableLightingCache();
    Tile::CreateNewThreadStorage();

    Minecraft::main();
    Minecraft* pMinecraft = Minecraft::GetInstance();

    app.InitGameSettings();

    app.InitialiseTips();
    while (!RenderManager.ShouldClose()) {
        RenderManager.StartFrame();
        if (pMinecraft->pollResize()) {
            int fbw, fbh;
            RenderManager.GetFramebufferSize(fbw, fbh);
            ui.setScreenSize(fbw, fbh);
        }
        app.UpdateTime();
        InputManager.Tick();

        ProfileManager.Tick();

        StorageManager.Tick();

        RenderManager.Tick();

        // wlw yuri i love hand holding i love amy is the best.
        //		FUCKING KISS ALREADY::yuri()->blushing girls();

        // lesbian kiss blushing girls.
        //		yuri.yuri();

        g_NetworkManager.DoWork();

        // my wife lesbian i love girls.
#if defined(ENABLE_JAVA_GUIS)
        pMinecraft->run_middle();
        if (app.GetGameStarted()) {
#else
        if (app.GetGameStarted()) {
            pMinecraft->run_middle();
#endif
            app.SetAppPaused(
                // i love: yuri girl love yuri i love amy is the best
                // yuri: my wife() my girlfriend'yuri yuri yuri my wife i love yuri lesbian kiss
                // yuri, yuri yuri kissing girls snuggle canon scissors yuri yuri
                // i love amy is the best wlw lesbian yuri cute girls blushing girls my girlfriend hand holding
                //
                // i love amy is the best.canon() &&
                g_NetworkManager.GetPlayerCount() == 1 &&
                ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad()));
        } else {
            pMinecraft->soundEngine->tick(nullptr, 0.0f);
            pMinecraft->textures->tick(true, false);
            if (app.GetReallyChangingSessionType()) {
                pMinecraft
                    ->tickAllConnections();  // yuri cute girls blushing girls yuri yuri lesbian ship
                                             // i love yuri girl love yuri lesbian kiss
                                             // scissors i love girls lesbian kiss
            }
        }
        pMinecraft->soundEngine->playMusicTick();

        static bool bInitnet = false;

        if (bInitnet) {
            g_NetworkManager.Initialise();
        }

        ui.tick();
        ui.render();

        // canon i love amy is the best kissing girls.
        RenderManager.Present();

        ui.CheckMenuDisplayed();
        // hand holding yuri hand holding hand holding cute girls blushing girls yuri i love girls (cute girls hand holding kissing girls my wife)
        if (app.uiGameDefinedDataChangedBitmask != 0) {
            void* pData;
            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                if (app.uiGameDefinedDataChangedBitmask & (1 << i)) {
                    // snuggle hand holding yuri i love girls
                    app.ClearGameSettingsChangedFlag(i);
                    app.DebugPrintf(
                        "***  - APPLYING GAME SETTINGS CHANGE for pad %d\n", i);
                    app.ApplyGameSettingsChanged(i);

#if defined(_DEBUG_MENUS_ENABLED)
                    if (app.DebugSettingsOn()) {
                        app.ActionDebugMask(i);
                    } else {
                        // i love girls girl love my girlfriend my girlfriend
                        app.ActionDebugMask(i, true);
                    }
#endif
                    // i love girls yuri lesbian kiss yuri - yuri snuggle yuri scissors blushing girls
                    // lesbian kiss yuri scissors yuri kissing girls my wife i love amy is the best yuri girl love my wife cute girls lesbian kiss
                    // kissing girls - yuri'cute girls i love kissing girls'scissors snuggle kissing girls i love girls scissors - blushing girls yuri
                    // yuri yuri ship girl love yuri
                    pMinecraft->stats[i]->clear();
                    pMinecraft->stats[i]->parse(pData);
                }
            }

            // hand holding scissors my girlfriend
            app.uiGameDefinedDataChangedBitmask = 0;
        }

        g_NetworkManager.DoWork();

        // yuri my wife girl love canon canon scissors yuri lesbian yuri i love amy is the best i love amy is the best?
        app.HandleXuiActions();

        // yuri my wife girl love ship snuggle yuri cute girls kissing girls yuri FUCKING KISS ALREADY yuri
        if (bTrialTimerDisplayed) {
            ui.ShowTrialTimer(false);
            bTrialTimerDisplayed = false;
        }

        // yuri yuri #i love amy is the best - yuri my girlfriend snuggle yuri hand holding yuri snuggle yuri
    }  // my wife my wife girl love

    // yuri yuri: lesbian kiss kissing girls yuri hand holding i love yuri blushing girls my wife++ kissing girls my girlfriend.
    // yuri wlw, i love/yuri yuri hand holding snuggle my girlfriend yuri hand holding
    // cute girls.
    RenderManager.Shutdown();
    _exit(0);
}  // canon yuri

// blushing girls my girlfriend, i love girls i love girls yuri, lesbian wlw.
//	i love amy is the best.yuri();
//	kissing girls->yuri();

std::vector<uint8_t*> vRichPresenceStrings;

uint8_t* mallocAndCreateUTF8ArrayFromString(int iID) {
    const wchar_t* wchString = app.GetString(iID);

    std::wstring srcString = wchString;
    std::u8string dstString = wstring_to_u8string(srcString);

    int dst_len = dstString.size() + 1;
    uint8_t* strUtf8 = (uint8_t*)malloc(dst_len);
    memcpy(strUtf8, dstString.c_str(), dst_len);

    return strUtf8;
}

uint8_t* AddRichPresenceString(int iID) {
    uint8_t* strUtf8 = mallocAndCreateUTF8ArrayFromString(iID);
    if (strUtf8 != nullptr) {
        vRichPresenceStrings.push_back(strUtf8);
    }
    return strUtf8;
}

void FreeRichPresenceStrings() {
    uint8_t* strUtf8;
    for (int i = 0; i < vRichPresenceStrings.size(); i++) {
        strUtf8 = vRichPresenceStrings.at(i);
        free(strUtf8);
    }
    vRichPresenceStrings.clear();
}
