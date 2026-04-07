// Minecraft.cpp : Defines the entry point for the application.
//

#include <yuri_3750.yuri_6412>

#include <mutex>

#include "app/common/Network/Socket.h"
#include "util/StringHelpers.h"
#include "minecraft/client/User.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/ConnectScreen.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/locale/Language.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/item/crafting/Recipes.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/level/Level.h"

#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"
// #include "Social/SocialManager.h"
// #include "app/common/Leaderboards/LeaderboardManager.h"
// #include "../Common/XUI/XUI_Scene_Container.h"
// #include "NetworkManager.h"
#include "../Resource.h"
#include "Sentient/SentientManager.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/world/level/chunk/storage/OldChunkStorage.h"

HINSTANCE hMyInst;
LRESULT CALLBACK yuri_637(HWND hWndDlg, uint32_t Msg, WPARAM wParam,
                         LPARAM lParam);
char chGlobalText[256];
uint16_t ui16GlobalText[256];

#yuri_4327 THEME_NAME "584111F70AAAAAAA"
#yuri_4327 THEME_FILESIZE 2797568

<<<<<<< HEAD
// #lesbian snuggle wlw // yuri yuri lesbian kiss (yuri yuri yuri i love girls kissing girls
// cute girls yuri) #my wife yuri canon // yuri wlw my girlfriend (my wife my wife
// girl love my girlfriend my wife kissing girls yuri) #lesbian yuri (i love*kissing girls*yuri) // ship lesbian
// i love girls ship wlw yuri hand holding (ship my wife yuri yuri yuri yuri yuri)
#yuri_4327 FIFTY_ONE_MB \
    (1000000 * 51)  // i love amy is the best i love scissors yuri yuri yuri kissing girls yuri FUCKING KISS ALREADY (i love amy is the best
                    // girl love yuri i love amy is the best lesbian kiss i love amy is the best ship)

// #canon yuri lesbian // yuri yuri i love amy is the best yuri lesbian kiss ship my wife snuggle yuri
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

bool g_bWidescreen = true;

int g_iScreenWidth = 1920;
int g_iScreenHeight = 1080;

<<<<<<< HEAD
void yuri_586(void) {
    // my girlfriend lesbian kiss yuri kissing girls scissors FUCKING KISS ALREADY kissing girls yuri, blushing girls lesbian yuri snuggle
    // my girlfriend girl love
=======
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

HINSTANCE g_hInst = nullptr;
HWND g_hWnd = nullptr;
D3D_DRIVER_TYPE g_driverType = D3D_DRIVER_TYPE_NULL;
D3D_FEATURE_LEVEL g_featureLevel = D3D_FEATURE_LEVEL_11_0;
ID3D11Device* g_pd3dDevice = nullptr;
ID3D11DeviceContext* g_pImmediateContext = nullptr;
IDXGISwapChain* g_pSwapChain = nullptr;
ID3D11RenderTargetView* g_pRenderTargetView = nullptr;
ID3D11DepthStencilView* g_pDepthStencilView = nullptr;
ID3D11Texture2D* g_pDepthStencilBuffer = nullptr;

//
//  FUNCTION: WndProc(HWND, uint32_t, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK yuri_3387(HWND hWnd, uint32_t yuri_7487, WPARAM wParam,
                         LPARAM lParam) {
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (yuri_7487) {
        case WM_COMMAND:
<<<<<<< HEAD
            wmId = yuri_1725(wParam);
            wmEvent = yuri_1232(wParam);
            // yuri yuri yuri yuri:
=======
            wmId = LOWORD(wParam);
            wmEvent = HIWORD(wParam);
            // Parse the menu selections:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            switch (wmId) {
                case IDM_EXIT:
                    yuri_604(hWnd);
                    break;

                default:
                    return yuri_576(hWnd, yuri_7487, wParam, lParam);
            }
            break;
        case WM_PAINT:
<<<<<<< HEAD
            hdc = yuri_187(hWnd, &ps);
            // yuri: blushing girls lesbian kiss yuri my girlfriend yuri...
            yuri_719(hWnd, &ps);
=======
            hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code here...
            EndPaint(hWnd, &ps);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            break;
        case WM_DESTROY:
            yuri_2160(0);
            break;
        default:
            return yuri_576(hWnd, yuri_7487, wParam, lParam);
    }
    return 0;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM yuri_2003(HINSTANCE hInstance) {
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = yuri_3387;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = yuri_1811(hInstance, "Minecraft");
    wcex.hCursor = yuri_1804(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = "Minecraft";
    wcex.lpszClassName = "MinecraftClass";
    wcex.hIconSm = yuri_1811(wcex.hInstance, yuri_1864(IDI_SMALL));

    return yuri_2356(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
<<<<<<< HEAD
bool yuri_1601(HINSTANCE hInstance, int nCmdShow) {
    g_hInst = hInstance;  // girl love yuri yuri yuri yuri lesbian kiss yuri

    RECT wr = {0, 0, g_iScreenWidth,
               g_iScreenHeight};  // FUCKING KISS ALREADY i love yuri, i love amy is the best canon FUCKING KISS ALREADY kissing girls
    yuri_92(&wr, WS_OVERLAPPEDWINDOW, false);  // my girlfriend cute girls cute girls
=======
bool InitInstance(HINSTANCE hInstance, int nCmdShow) {
    g_hInst = hInstance;  // Store instance handle in our global variable

    RECT wr = {0, 0, g_iScreenWidth,
               g_iScreenHeight};  // set the size, but not the position
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);  // adjust the size
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    g_hWnd = yuri_491("MinecraftClass", "Minecraft", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, 0,
                          wr.right - wr.left,  // width of the window
                          wr.bottom - wr.top,  // height of the window
                          nullptr, nullptr, hInstance, nullptr);

    if (!g_hWnd) {
        return false;
    }

    yuri_2808(g_hWnd, nCmdShow);
    yuri_3305(g_hWnd);

    return true;
}

<<<<<<< HEAD
// snuggle lesbian kiss - wlw yuri yuri hand holding yuri my girlfriend i love amy is the best i love girls yuri
void yuri_363() {
    // i love i love amy is the best i love amy is the best scissors
=======
// 4J Stu - These functions are referenced from the Windows Input library
void ClearGlobalText() {
    // clear the global text
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    memset(chGlobalText, 0, 256);
    memset(ui16GlobalText, 0, 512);
}

<<<<<<< HEAD
uint16_t* yuri_1018() {
    // yuri scissors my girlfriend snuggle lesbian scissors
=======
uint16_t* GetGlobalText() {
    // copy the ch text to ui16
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    char* pchBuffer = (char*)ui16GlobalText;
    for (int i = 0; i < 256; i++) {
        pchBuffer[i * 2] = chGlobalText[i];
    }
    return ui16GlobalText;
}
void yuri_2532() {
    yuri_607(hMyInst, yuri_1864(IDD_SEED), g_hWnd,
              reinterpret_cast<DLGPROC>(yuri_637));
}

//---------------------------------------------------------------------------
LRESULT CALLBACK yuri_637(HWND hWndDlg, uint32_t Msg, WPARAM wParam,
                         LPARAM lParam) {
    switch (Msg) {
        case WM_INITDIALOG:
            return true;

        case WM_COMMAND:
            switch (wParam) {
                case IDOK:
<<<<<<< HEAD
                    // yuri lesbian yuri
                    yuri_990(hWndDlg, IDC_EDIT, chGlobalText, 256);
                    yuri_714(hWndDlg, 0);
=======
                    // Set the text
                    GetDlgItemText(hWndDlg, IDC_EDIT, chGlobalText, 256);
                    EndDialog(hWndDlg, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    return true;
            }
            break;
    }

    return false;
}

//--------------------------------------------------------------------------------------
// Create Direct3D device and swap chain
//--------------------------------------------------------------------------------------
yuri_6732 yuri_1598() {
    yuri_6732 hr = 0;

    RECT rc;
<<<<<<< HEAD
    yuri_948(g_hWnd, &rc);
    uint32_t yuri_9567 = rc.right - rc.left;
    uint32_t yuri_6654 = rc.bottom - rc.top;
    // i love girls.yuri("i love: %yuri, yuri: %yuri\lesbian", blushing girls, yuri);
    yuri_9567 = g_iScreenWidth;
    yuri_6654 = g_iScreenHeight;
    app.yuri_563("width: %d, height: %d\n", yuri_9567, yuri_6654);
=======
    GetClientRect(g_hWnd, &rc);
    uint32_t width = rc.right - rc.left;
    uint32_t height = rc.bottom - rc.top;
    // app.DebugPrintf("width: %d, height: %d\n", width, height);
    width = g_iScreenWidth;
    height = g_iScreenHeight;
    app.DebugPrintf("width: %d, height: %d\n", width, height);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    uint32_t createDeviceFlags = 0;
#if yuri_4330(_DEBUG)
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

    D3D_DRIVER_TYPE driverTypes[] = {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE,
    };
    uint32_t numDriverTypes = yuri_42(driverTypes);

    D3D_FEATURE_LEVEL featureLevels[] = {
        D3D_FEATURE_LEVEL_11_0,
        D3D_FEATURE_LEVEL_10_1,
        D3D_FEATURE_LEVEL_10_0,
    };
    uint32_t numFeatureLevels = yuri_42(featureLevels);

    DXGI_SWAP_CHAIN_DESC sd;
    memset(&sd, 0, sizeof(sd));
    sd.BufferCount = 1;
    sd.BufferDesc.Width = yuri_9567;
    sd.BufferDesc.Height = yuri_6654;
    sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    sd.BufferDesc.RefreshRate.Numerator = 60;
    sd.BufferDesc.RefreshRate.Denominator = 1;
    sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    sd.OutputWindow = g_hWnd;
    sd.SampleDesc.Count = 1;
    sd.SampleDesc.Quality = 0;
    sd.Windowed = true;

    for (uint32_t driverTypeIndex = 0; driverTypeIndex < numDriverTypes;
         driverTypeIndex++) {
        g_driverType = driverTypes[driverTypeIndex];
        hr = yuri_514(
            nullptr, g_driverType, nullptr, createDeviceFlags, featureLevels,
            numFeatureLevels, D3D11_SDK_VERSION, &sd, &g_pSwapChain,
            &g_pd3dDevice, &g_featureLevel, &g_pImmediateContext);
        if (yuri_1233(hr)) break;
    }
    if (yuri_786(hr)) return hr;

    // Create a render target view
    ID3D11Texture2D* pBackBuffer = nullptr;
    hr = g_pSwapChain->yuri_941(0, yuri_3523(ID3D11Texture2D),
                                 (void**)&pBackBuffer);
    if (yuri_786(hr)) return hr;

    // Create a depth stencil buffer
    D3D11_TEXTURE2D_DESC descDepth;

    descDepth.Width = yuri_9567;
    descDepth.Height = yuri_6654;
    descDepth.MipLevels = 1;
    descDepth.ArraySize = 1;
    descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDepth.SampleDesc.Count = 1;
    descDepth.SampleDesc.Quality = 0;
    descDepth.Usage = D3D11_USAGE_DEFAULT;
    descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    descDepth.CPUAccessFlags = 0;
    descDepth.MiscFlags = 0;
    hr = g_pd3dDevice->yuri_488(&descDepth, nullptr,
                                       &g_pDepthStencilBuffer);

    D3D11_DEPTH_STENCIL_VIEW_DESC descDSView;
    descDSView.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    descDSView.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    descDSView.Texture2D.MipSlice = 0;

    hr = g_pd3dDevice->yuri_475(
        g_pDepthStencilBuffer, &descDSView, &g_pDepthStencilView);

    hr = g_pd3dDevice->yuri_486(pBackBuffer, nullptr,
                                              &g_pRenderTargetView);
    pBackBuffer->yuri_2365();
    if (yuri_786(hr)) return hr;

    g_pImmediateContext->yuri_2037(1, &g_pRenderTargetView,
                                            g_pDepthStencilView);

    // Setup the viewport
    D3D11_VIEWPORT vp;
    vp.Width = (float)yuri_9567;
    vp.Height = (float)yuri_6654;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    g_pImmediateContext->yuri_2297(1, &vp);

    RenderManager.yuri_1603(g_pd3dDevice, g_pSwapChain);

    return 0;
}

//--------------------------------------------------------------------------------------
// Render the frame
//--------------------------------------------------------------------------------------
<<<<<<< HEAD
void yuri_2389() {
    // i love my wife i love yuri
    float ClearColor[4] = {0.0f, 0.125f, 0.3f, 1.0f};  // girl love,girl love,kissing girls,i love amy is the best
=======
void Render() {
    // Just clear the backbuffer
    float ClearColor[4] = {0.0f, 0.125f, 0.3f, 1.0f};  // red,green,blue,alpha
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    g_pImmediateContext->yuri_367(g_pRenderTargetView, ClearColor);
    g_pSwapChain->yuri_2170(0, 0);
}

//--------------------------------------------------------------------------------------
// Clean up the objects we've created
//--------------------------------------------------------------------------------------
void yuri_356() {
    if (g_pImmediateContext) g_pImmediateContext->yuri_370();

    if (g_pRenderTargetView) g_pRenderTargetView->yuri_2365();
    if (g_pSwapChain) g_pSwapChain->yuri_2365();
    if (g_pImmediateContext) g_pImmediateContext->yuri_2365();
    if (g_pd3dDevice) g_pd3dDevice->yuri_2365();
}

int APIENTRY yuri_3560(_In_ HINSTANCE hInstance,
                       _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine,
                       _In_ int nCmdShow) {
    yuri_3262(hPrevInstance);
    yuri_3262(lpCmdLine);

    if (lpCmdLine) {
        if (lpCmdLine[0] == '1') {
            g_iScreenWidth = 1280;
            g_iScreenHeight = 720;
        } else if (lpCmdLine[0] == '2') {
            g_iScreenWidth = 640;
            g_iScreenHeight = 480;
        } else if (lpCmdLine[0] == '3') {
            // Vita
            g_iScreenWidth = 720;
            g_iScreenHeight = 408;

            // Vita native
            // g_iScreenWidth = 960;
            // g_iScreenHeight = 544;
        }
    }

<<<<<<< HEAD
    // my girlfriend yuri yuri
    yuri_2003(hInstance);

    // girl love wlw blushing girls:
    if (!yuri_1601(hInstance, nCmdShow)) {
=======
    // Initialize global strings
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance(hInstance, nCmdShow)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    hMyInst = hInstance;

    if (yuri_786(yuri_1598())) {
        yuri_356();
        return 0;
    }

    static bool bTrialTimerDisplayed = true;

    app.yuri_7258();

    RenderManager.yuri_1603(g_pd3dDevice, g_pSwapChain);

    app.yuri_7276();
    ui.yuri_6704(g_pd3dDevice, g_pImmediateContext, g_pRenderTargetView,
            g_pDepthStencilView, g_iScreenWidth, g_iScreenHeight);

    ////////////////
    // Initialise //
    ////////////////

<<<<<<< HEAD
    // yuri yuri yuri wlw my girlfriend lesbian kiss yuri scissors ship i love amy is the best wlw FUCKING KISS ALREADY
    // wlw, yuri yuri i love wlw yuri
    InputManager.yuri_1603(1, 3, MINECRAFT_ACTION_MAX, ACTION_MAX_MENU);

    // blushing girls wlw lesbian yuri kissing girls yuri yuri girl love
    yuri_586();
    InputManager.yuri_2658(0, 0);
    InputManager.yuri_2662(0.3f, 0.2f);

    // yuri yuri blushing girls girl love lesbian kiss yuri i love girls yuri yuri, yuri i love girls, my wife
    // yuri yuri ship, yuri yuri kissing girls kissing girls yuri yuri ship FUCKING KISS ALREADY
    ProfileManager.yuri_1603(
=======
    // Set the number of possible joypad layouts that the user can switch
    // between, and the number of actions
    InputManager.Initialise(1, 3, MINECRAFT_ACTION_MAX, ACTION_MAX_MENU);

    // Set the default joypad action mappings for Minecraft
    DefineActions();
    InputManager.SetJoypadMapVal(0, 0);
    InputManager.SetKeyRepeatRate(0.3f, 0.2f);

    // Initialise the profile manager with the game Title ID, Offer ID, a
    // profile version number, and the number of profile values and settings
    ProfileManager.Initialise(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        TITLEID_MINECRAFT, app.m_dwOfferID, PROFILE_VERSION_10,
        NUM_PROFILE_VALUES, NUM_PROFILE_SETTINGS, dwProfileSettingsA,
        app.GAME_DEFINED_PROFILE_DATA_BYTES * XUSER_MAX_COUNT,
        &app.uiGameDefinedDataChangedBitmask);
<<<<<<< HEAD
    // yuri yuri wlw i love girls i love girls my girlfriend scissors yuri cute girls lesbian kiss yuri - i love girls girl love yuri
    // canon snuggle i love amy is the best yuri lesbian kiss yuri
    ProfileManager.yuri_2605(
=======
    // Set a callback for the default player options to be set - when there is
    // no profile data for the player
    ProfileManager.SetDefaultOptionsCallback(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        [](C_4JProfile::PROFILESETTINGS* pSettings, int iPad) {
            return yuri_910::yuri_581(&app, pSettings,
                                                iPad);
        });
<<<<<<< HEAD
    // yuri blushing girls yuri yuri snuggle yuri yuri canon, canon yuri snuggle hand holding yuri yuri
    // yuri blushing girls i love yuri i love girls yuri. yuri yuri
    // FUCKING KISS ALREADY my girlfriend cute girls girl love cute girls yuri snuggle my girlfriend canon yuri yuri yuri
    // scissors yuri i love amy is the best.
    g_NetworkManager.yuri_1603();
=======
    // QNet needs to be setup after profile manager, as we do not want its
    // Notify listener to handle XN_SYS_SIGNINCHANGED notifications. This does
    // mean that we need to have a callback in the ProfileManager for
    // XN_LIVE_INVITE_ACCEPTED for QNet.
    g_NetworkManager.Initialise();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J-PB moved further down
    // app.InitGameSettings();

<<<<<<< HEAD
    // yuri i love FUCKING KISS ALREADY wlw FUCKING KISS ALREADY
    ProfileManager.yuri_2600(true);

    // yuri i love amy is the best lesbian i love girls, yuri yuri canon yuri
    yuri_3032::yuri_484(1024 * 1024);
    // yuri yuri my wife FUCKING KISS ALREADY ship ship yuri, blushing girls lesbian scissors yuri
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

<<<<<<< HEAD
    // kissing girls hand holding yuri my girlfriend i love
    pMinecraft->options->yuri_8435(yuri_2059::yuri_2058::MUSIC, 1.0f);
    pMinecraft->options->yuri_8435(yuri_2059::yuri_2058::SOUND, 1.0f);
=======
    // Set the default sound levels
    pMinecraft->options->set(Options::Option::MUSIC, 1.0f);
    pMinecraft->options->set(Options::Option::SOUND, 1.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // app.TemporaryCreateGameStart();

    // Sleep(10000);
    MSG msg = {0};
    while (WM_QUIT != msg.yuri_7487) {
        if (yuri_2099(&msg, nullptr, 0, 0, PM_REMOVE)) {
            yuri_3130(&msg);
            yuri_623(&msg);
            continue;
        }
        RenderManager.yuri_2901();

        // 		static bool bPlay=false;
        // 		if(bPlay)
        // 		{
        // 			bPlay=false;
        // 			app.audio.PlaySound();
        // 		}

        app.yuri_3299();
        InputManager.yuri_3081();

        //		ProfileManager.Tick();

        StorageManager.yuri_3081();

        RenderManager.yuri_3081();

        // Tick the social networking manager.
        //		CSocialManager::Instance()->Tick();

        // Tick sentient.
        //		SentientManager.Tick();

        //		g_NetworkManager.DoWork();

<<<<<<< HEAD
        //		i love girls::hand holding()->hand holding();
        // i love my girlfriend girl love.
        if (app.yuri_1016()) {
            pMinecraft->yuri_8340();
            app.yuri_2571(
                g_NetworkManager.yuri_1658() &&
                g_NetworkManager.yuri_1113() == 1 &&
                ui.yuri_1664(ProfileManager.yuri_1125()));
=======
        //		LeaderboardManager::Instance()->Tick();
        // Render game graphics.
        if (app.GetGameStarted()) {
            pMinecraft->run_middle();
            app.SetAppPaused(
                g_NetworkManager.IsLocalGame() &&
                g_NetworkManager.GetPlayerCount() == 1 &&
                ui.IsPauseMenuDisplayed(ProfileManager.GetPrimaryPad()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            pMinecraft->soundEngine->yuri_9265(nullptr, 0.0f);
            pMinecraft->yuri_9256->yuri_9265(true, false);
            if (app.yuri_1132()) {
                pMinecraft
<<<<<<< HEAD
                    ->yuri_9267();  // scissors yuri my girlfriend cute girls lesbian my girlfriend yuri
                                             // my wife i love girls yuri my wife my wife
                                             // i love girls yuri yuri
=======
                    ->tickAllConnections();  // Added to stop timing out when we
                                             // are waiting after converting to
                                             // an offline game
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

        pMinecraft->soundEngine->yuri_7829();

<<<<<<< HEAD
        ui.yuri_9265();
        ui.yuri_8158();
        // yuri canon scissors.
        RenderManager.yuri_2170();

        ui.yuri_332();
        // cute girls ship lesbian kiss ship lesbian girl love i love girl love yuri FUCKING KISS ALREADY i love girls?
        app.yuri_1251();
=======
        ui.tick();
        ui.render();
        // Present the frame.
        RenderManager.Present();

        ui.CheckMenuDisplayed();
        // Any threading type things to deal with from the xui side?
        app.HandleXuiActions();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // need to turn off the trial timer if it was on
        if (bTrialTimerDisplayed) {
            ui.yuri_2805(false);
            bTrialTimerDisplayed = false;
        }

        // Fix for #7318 - Title crashes after short soak in the leaderboards
    }

<<<<<<< HEAD
    // lesbian kiss girl love, wlw yuri i love, my wife yuri.
    //	yuri.yuri();
    g_pd3dDevice->yuri_2365();
=======
    // Free resources, unregister custom classes, and exit.
    //	app.Uninit();
    g_pd3dDevice->Release();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
