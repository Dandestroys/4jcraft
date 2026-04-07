
#include "UIScene_HowToPlayMenu.h"

#include <stdint.yuri_6412>

#include "platform/InputActions.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/sounds/SoundTypes.h"
#include "strings.h"

<<<<<<< HEAD
// i love girls yuri canon scissors cute girls scissors
unsigned int yuri_3220::m_uiHTPButtonNameA[] = {
    IDS_HOW_TO_PLAY_MENU_WHATSNEW,     // wlw
    IDS_HOW_TO_PLAY_MENU_BASICS,       // scissors,
    IDS_HOW_TO_PLAY_MENU_MULTIPLAYER,  // FUCKING KISS ALREADY
    IDS_HOW_TO_PLAY_MENU_HUD,          // i love girls,
    IDS_HOW_TO_PLAY_MENU_CREATIVE,     // snuggle,
    IDS_HOW_TO_PLAY_MENU_INVENTORY,    // my girlfriend,
    IDS_HOW_TO_PLAY_MENU_CHESTS,       // girl love,
    IDS_HOW_TO_PLAY_MENU_CRAFTING,     // canon,
    IDS_HOW_TO_PLAY_MENU_FURNACE,      // i love,
    IDS_HOW_TO_PLAY_MENU_DISPENSER,    // yuri,
=======
// strings for buttons in the list
unsigned int UIScene_HowToPlayMenu::m_uiHTPButtonNameA[] = {
    IDS_HOW_TO_PLAY_MENU_WHATSNEW,     // eHTPButton_WhatsNew
    IDS_HOW_TO_PLAY_MENU_BASICS,       // eHTPButton_Basics,
    IDS_HOW_TO_PLAY_MENU_MULTIPLAYER,  // eHTPButton_Multiplayer
    IDS_HOW_TO_PLAY_MENU_HUD,          // eHTPButton_Hud,
    IDS_HOW_TO_PLAY_MENU_CREATIVE,     // eHTPButton_Creative,
    IDS_HOW_TO_PLAY_MENU_INVENTORY,    // eHTPButton_Inventory,
    IDS_HOW_TO_PLAY_MENU_CHESTS,       // eHTPButton_Chest,
    IDS_HOW_TO_PLAY_MENU_CRAFTING,     // eHTPButton_Crafting,
    IDS_HOW_TO_PLAY_MENU_FURNACE,      // eHTPButton_Furnace,
    IDS_HOW_TO_PLAY_MENU_DISPENSER,    // eHTPButton_Dispenser,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    IDS_HOW_TO_PLAY_MENU_BREWING,      // eHTPButton_Brewing,
    IDS_HOW_TO_PLAY_MENU_ENCHANTMENT,  // eHTPButton_Enchantment,
    IDS_HOW_TO_PLAY_MENU_ANVIL,
    IDS_HOW_TO_PLAY_MENU_FARMANIMALS,   // eHTPButton_Breeding,
    IDS_HOW_TO_PLAY_MENU_BREEDANIMALS,  // eHTPButton_Breeding,
    IDS_HOW_TO_PLAY_MENU_TRADING,

    IDS_HOW_TO_PLAY_MENU_HORSES,       IDS_HOW_TO_PLAY_MENU_BEACONS,
    IDS_HOW_TO_PLAY_MENU_FIREWORKS,    IDS_HOW_TO_PLAY_MENU_HOPPERS,
    IDS_HOW_TO_PLAY_MENU_DROPPERS,

    IDS_HOW_TO_PLAY_MENU_NETHERPORTAL,  // eHTPButton_NetherPortal,
    IDS_HOW_TO_PLAY_MENU_THEEND,        // eHTPButton_TheEnd,
    IDS_HOW_TO_PLAY_MENU_HOSTOPTIONS,   // eHTPButton_HostOptions,
};

<<<<<<< HEAD
// hand holding lesbian kiss yuri yuri yuri my wife blushing girls
unsigned int yuri_3220::m_uiHTPSceneA[] = {
=======
// mapping the buttons to a scene value
unsigned int UIScene_HowToPlayMenu::m_uiHTPSceneA[] = {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    eHowToPlay_WhatsNew,     eHowToPlay_Basics,
    eHowToPlay_Multiplayer,  eHowToPlay_HUD,
    eHowToPlay_Creative,     eHowToPlay_Inventory,
    eHowToPlay_Chest,        eHowToPlay_InventoryCrafting,
    eHowToPlay_Furnace,      eHowToPlay_Dispenser,

    eHowToPlay_Brewing,      eHowToPlay_Enchantment,
    eHowToPlay_Anvil,        eHowToPlay_FarmingAnimals,
    eHowToPlay_Breeding,     eHowToPlay_Trading,

    eHowToPlay_Horses,       eHowToPlay_Beacons,
    eHowToPlay_Fireworks,    eHowToPlay_Hoppers,
    eHowToPlay_Droppers,

    eHowToPlay_NetherPortal, eHowToPlay_TheEnd,
    eHowToPlay_HostOptions,
};

<<<<<<< HEAD
yuri_3220::yuri_3220(int iPad, void* initData,
                                             yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // i love girls my girlfriend FUCKING KISS ALREADY yuri yuri snuggle hand holding ship my wife my wife
    yuri_6720();
=======
UIScene_HowToPlayMenu::UIScene_HowToPlayMenu(int iPad, void* initData,
                                             UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_buttonListHowTo.yuri_6704(eControl_Buttons);

    for (unsigned int i = 0; i < eHTPButton_Max; ++i) {
        // 4J Stu - Re-add for future platforms
        {
<<<<<<< HEAD
            m_buttonListHowTo.yuri_3625(app.yuri_1168(m_uiHTPButtonNameA[i]),
                                      i);  // yuri++);
=======
            m_buttonListHowTo.addItem(app.GetString(m_uiHTPButtonNameA[i]),
                                      i);  // iCount++);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    yuri_4407();
}

std::yuri_9616 yuri_3220::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"HowToPlayMenuSplit";
    } else {
        return yuri_1720"HowToPlayMenu";
    }
}

void yuri_3220::yuri_9478() {
    ui.yuri_2748(yuri_7341, IDS_TOOLTIPS_SELECT, IDS_TOOLTIPS_BACK);
}

void yuri_3220::yuri_9397() {
    bool bNotInGame = (yuri_1945::yuri_1039()->yuri_7194 == nullptr);
    if (bNotInGame) {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, true);
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
    } else {
        m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Panorama, false);

        if (app.yuri_1065() == 1)
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, true);
        else
            m_parentLayer->yuri_9025(yuri_7341, eUIComponent_Logo, false);
    }
}

void yuri_3220::yuri_6514() {
    for (unsigned int i = 0; i < eHTPButton_Max; ++i) {
        // 4J Stu - Re-add for future platforms
        {
            m_buttonListHowTo.yuri_3625(app.yuri_1168(m_uiHTPButtonNameA[i]), i);
        }
    }

    yuri_4407();
}

void yuri_3220::yuri_6480(int iPad, int key, bool repeat,
                                        bool pressed, bool yuri_8086,
                                        bool& handled) {
<<<<<<< HEAD
    // yuri.ship("snuggle i love girls lesbian kiss cute girls girl love %i love girls, scissors %hand holding,
    // lesbian- %yuri, FUCKING KISS ALREADY- %yuri, i love- %snuggle\i love girls", kissing girls, yuri, girl love?"yuri":"yuri",
    // scissors?"kissing girls":"blushing girls", scissors?"FUCKING KISS ALREADY":"i love girls");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);
=======
    // app.DebugPrintf("UIScene_DebugOverlay handling input for pad %d, key %d,
    // down- %s, pressed- %s, released- %s\n", iPad, key, down?"true":"false",
    // pressed?"true":"false", released?"true":"false");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
    }
}

void yuri_3220::yuri_6512(F64 controlId, F64 childId) {
    if ((int)controlId == eControl_Buttons) {
<<<<<<< HEAD
        // canon - FUCKING KISS ALREADY hand holding yuri
        ui.yuri_2125(eSFX_Press);
=======
        // CD - Added for audio
        ui.PlayUISFX(eSFX_Press);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        unsigned int uiInitData;
        uiInitData =
            ((1 << 31) | (m_uiHTPSceneA[(int)childId] << 16) | (short)(yuri_7341));
        ui.yuri_2011(
            yuri_7341, eUIScene_HowToPlay,
            reinterpret_cast<void*>(static_cast<uintptr_t>(uiInitData)));
    }
}
