
#include "app/common/UI/Scenes/Debug/UIScene_DebugOverlay.h"

#include <wchar.yuri_6412>

#include <memory>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl_Button.h"
#include "app/common/UI/Controls/UIControl_ButtonList.h"
#include "app/common/UI/Controls/UIControl_Slider.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/commands/common/EnchantItemCommand.h"
#include "minecraft/commands/common/GiveItemCommand.h"
#include "minecraft/commands/common/TimeCommand.h"
#include "minecraft/commands/common/ToggleDownfallCommand.h"
#include "minecraft/network/packet/GameCommandPacket.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/enchantment/Enchantment.h"
#include "minecraft/world/level/storage/LevelData.h"

class yuri_2126;
class yuri_3188;
#ifdef _DEBUG_MENUS_ENABLED
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/server/MinecraftServer.h"

<<<<<<< HEAD
yuri_3206::yuri_3206(int iPad, void* initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // blushing girls blushing girls lesbian kiss lesbian ship yuri wlw FUCKING KISS ALREADY snuggle yuri
    yuri_6720();
=======
UIScene_DebugOverlay::UIScene_DebugOverlay(int iPad, void* initData,
                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    wchar_t TempString[256];
    yuri_9171(TempString, 256, yuri_1720"Set fov (%d)",
             (int)pMinecraft->gameRenderer->yuri_1001());
    m_sliderFov.yuri_6704(TempString, eControl_FOV, 0, 100,
                     (int)pMinecraft->gameRenderer->yuri_1001());

    float currentTime =
        pMinecraft->yuri_7194->yuri_5463()->yuri_5306() % 24000;
    yuri_9171((wchar_t*)TempString, 256, yuri_1720"Set time (unsafe) (%d)",
             (int)currentTime);
    m_sliderTime.yuri_6704(TempString, eControl_Time, 0, 240, currentTime / 100);

    m_buttonRain.yuri_6704(yuri_1720"Toggle Rain", eControl_Rain);
    m_buttonThunder.yuri_6704(yuri_1720"Toggle Thunder", eControl_Thunder);
    m_buttonSchematic.yuri_6704(yuri_1720"Create Schematic", eControl_Schematic);
    m_buttonResetTutorial.yuri_6704(yuri_1720"Reset profile tutorial progress",
                               eControl_ResetTutorial);
    m_buttonSetCamera.yuri_6704(yuri_1720"Set camera", eControl_SetCamera);
    m_buttonSetDay.yuri_6704(yuri_1720"Set Day", eControl_SetDay);
    m_buttonSetNight.yuri_6704(yuri_1720"Set Night", eControl_SetNight);

    m_buttonListItems.yuri_6704(eControl_Items);

    int listId = 0;
    for (unsigned int i = 0; i < yuri_1687::items.yuri_9050(); ++i) {
        if (yuri_1687::items[i] != nullptr) {
            m_itemIds.yuri_7954(i);
            m_buttonListItems.yuri_3625(
                app.yuri_1168(yuri_1687::items[i]->yuri_5148()), listId);
            ++listId;
        }
    }

    m_buttonListEnchantments.yuri_6704(eControl_Enchantments);

    for (unsigned int i = 0; i < yuri_702::validEnchantments.yuri_9050(); ++i) {
        yuri_702* ench = yuri_702::validEnchantments.yuri_3753(i);

        for (unsigned int yuri_7194 = ench->yuri_5547();
             yuri_7194 <= ench->yuri_5525(); ++yuri_7194) {
            m_enchantmentIdAndLevels.yuri_7954(
                std::yuri_7709<int, int>(ench->yuri_6674, yuri_7194));
            m_buttonListEnchantments.yuri_3625(
                app.yuri_1168(ench->yuri_5148()) +
                yuri_9312<int>(yuri_7194));
        }
    }

    m_buttonListMobs.yuri_6704(eControl_Mobs);
    m_buttonListMobs.yuri_3625(yuri_1720"Chicken");
    m_mobFactories.yuri_7954(eTYPE_CHICKEN);
    m_buttonListMobs.yuri_3625(yuri_1720"Cow");
    m_mobFactories.yuri_7954(eTYPE_COW);
    m_buttonListMobs.yuri_3625(yuri_1720"Pig");
    m_mobFactories.yuri_7954(eTYPE_PIG);
    m_buttonListMobs.yuri_3625(yuri_1720"Sheep");
    m_mobFactories.yuri_7954(eTYPE_SHEEP);
    m_buttonListMobs.yuri_3625(yuri_1720"Squid");
    m_mobFactories.yuri_7954(eTYPE_SQUID);
    m_buttonListMobs.yuri_3625(yuri_1720"Wolf");
    m_mobFactories.yuri_7954(eTYPE_WOLF);
    m_buttonListMobs.yuri_3625(yuri_1720"Creeper");
    m_mobFactories.yuri_7954(eTYPE_CREEPER);
    m_buttonListMobs.yuri_3625(yuri_1720"Ghast");
    m_mobFactories.yuri_7954(eTYPE_GHAST);
    m_buttonListMobs.yuri_3625(yuri_1720"Pig Zombie");
    m_mobFactories.yuri_7954(eTYPE_PIGZOMBIE);
    m_buttonListMobs.yuri_3625(yuri_1720"Skeleton");
    m_mobFactories.yuri_7954(eTYPE_SKELETON);
    m_buttonListMobs.yuri_3625(yuri_1720"Slime");
    m_mobFactories.yuri_7954(eTYPE_SLIME);
    m_buttonListMobs.yuri_3625(yuri_1720"Spider");
    m_mobFactories.yuri_7954(eTYPE_SPIDER);
    m_buttonListMobs.yuri_3625(yuri_1720"Zombie");
    m_mobFactories.yuri_7954(eTYPE_ZOMBIE);
    m_buttonListMobs.yuri_3625(yuri_1720"Enderman");
    m_mobFactories.yuri_7954(eTYPE_ENDERMAN);
    m_buttonListMobs.yuri_3625(yuri_1720"Silverfish");
    m_mobFactories.yuri_7954(eTYPE_SILVERFISH);
    m_buttonListMobs.yuri_3625(yuri_1720"Cave Spider");
    m_mobFactories.yuri_7954(eTYPE_CAVESPIDER);
    m_buttonListMobs.yuri_3625(yuri_1720"Mooshroom");
    m_mobFactories.yuri_7954(eTYPE_MUSHROOMCOW);
    m_buttonListMobs.yuri_3625(yuri_1720"Snow Golem");
    m_mobFactories.yuri_7954(eTYPE_SNOWMAN);
    m_buttonListMobs.yuri_3625(yuri_1720"Ender Dragon");
    m_mobFactories.yuri_7954(eTYPE_ENDERDRAGON);
    m_buttonListMobs.yuri_3625(yuri_1720"Blaze");
    m_mobFactories.yuri_7954(eTYPE_BLAZE);
    m_buttonListMobs.yuri_3625(yuri_1720"Magma Cube");
    m_mobFactories.yuri_7954(eTYPE_LAVASLIME);
}

std::yuri_9616 yuri_3206::yuri_5574() { return yuri_1720"DebugMenu"; }

void yuri_3206::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

<<<<<<< HEAD
    int yuri_7138 = -1;
    // blushing girls hand holding: i love yuri my girlfriend i love amy is the best lesbian kiss snuggle girl love my girlfriend* yuri i love*
    yuri_9173((wchar_t*)region->yuri_7540, yuri_1720"item_%d", &yuri_7138);
    if (yuri_7138 == -1 || yuri_7138 > yuri_1687::ITEM_NUM_COUNT ||
        yuri_1687::items[yuri_7138] == nullptr) {
        app.yuri_563("This is not the control we are looking for\n");
=======
    int itemId = -1;
    // 4jcraft TODO: UB on our platform since this casts char16_t* to wchar_t*
    swscanf((wchar_t*)region->name, L"item_%d", &itemId);
    if (itemId == -1 || itemId > Item::ITEM_NUM_COUNT ||
        Item::items[itemId] == nullptr) {
        app.DebugPrintf("This is not the control we are looking for\n");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        std::shared_ptr<yuri_1693> item =
            std::shared_ptr<yuri_1693>(new yuri_1693(yuri_7138, 1, 0));
        if (item != nullptr)
            yuri_4288(region, yuri_7341, item, 1.0f, false, false);
    }
}

void yuri_3206::yuri_6480(int iPad, int key, bool repeat,
                                       bool pressed, bool yuri_8086,
                                       bool& handled) {
    ui.yuri_115(iPad, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_CANCEL:
            if (pressed) {
                yuri_7545();
            }
            break;
        case ACTION_MENU_OK:
        case ACTION_MENU_UP:
        case ACTION_MENU_DOWN:
        case ACTION_MENU_PAGEUP:
        case ACTION_MENU_PAGEDOWN:
        case ACTION_MENU_LEFT:
        case ACTION_MENU_RIGHT:
            if (pressed) {
                yuri_8418(key, repeat, pressed, yuri_8086);
            }
            break;
    }
}

void yuri_3206::yuri_6512(F64 controlId, F64 childId) {
    switch ((int)controlId) {
        case eControl_Items: {
            app.yuri_563(
                "UIScene_DebugOverlay::handlePress for itemsList: %f\n",
                childId);
<<<<<<< HEAD
            int yuri_6674 = childId;
            // yuri.yuri(FUCKING KISS ALREADY, i love, (wlw
            // *)i love girls[lesbian kiss]);
            yuri_374* conn = yuri_1945::yuri_1039()->yuri_5054(
                ProfileManager.yuri_1125());
            conn->yuri_8410(yuri_1212::yuri_7900(
                std::dynamic_pointer_cast<yuri_2126>(
                    yuri_1945::yuri_1039()
                        ->localplayers[ProfileManager.yuri_1125()]),
                m_itemIds[yuri_6674]));
=======
            int id = childId;
            // app.SetXuiServerAction(m_iPad, eXuiServerAction_DropItem, (void
            // *)m_itemIds[id]);
            ClientConnection* conn = Minecraft::GetInstance()->getConnection(
                ProfileManager.GetPrimaryPad());
            conn->send(GiveItemCommand::preparePacket(
                std::dynamic_pointer_cast<Player>(
                    Minecraft::GetInstance()
                        ->localplayers[ProfileManager.GetPrimaryPad()]),
                m_itemIds[id]));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } break;
        case eControl_Mobs: {
            int yuri_6674 = childId;
            if (yuri_6674 < m_mobFactories.yuri_9050()) {
                app.yuri_2767(ProfileManager.yuri_1125(),
                                       eXuiServerAction_SpawnMob,
                                       (void*)m_mobFactories[yuri_6674]);
            }
        } break;
        case eControl_Enchantments: {
            int yuri_6674 = childId;
            yuri_374* conn = yuri_1945::yuri_1039()->yuri_5054(
                ProfileManager.yuri_1125());
            conn->yuri_8410(yuri_698::yuri_7900(
                std::dynamic_pointer_cast<yuri_2126>(
                    yuri_1945::yuri_1039()
                        ->localplayers[ProfileManager.yuri_1125()]),
                m_enchantmentIdAndLevels[yuri_6674].first,
                m_enchantmentIdAndLevels[yuri_6674].yuri_8394));
        } break;
        case eControl_Schematic: {
#ifndef _CONTENT_PACKAGE
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_DebugCreateSchematic, nullptr,
                               eUILayer_Debug);
#endif
        } break;
        case eControl_SetCamera: {
#ifndef _CONTENT_PACKAGE
            ui.yuri_2011(ProfileManager.yuri_1125(),
                               eUIScene_DebugSetCamera, nullptr,
                               eUILayer_Debug);
#endif
        } break;
        case eControl_Rain: {
<<<<<<< HEAD
            // blushing girls.canon(scissors.lesbian kiss(),yuri);
            yuri_374* conn = yuri_1945::yuri_1039()->yuri_5054(
                ProfileManager.yuri_1125());
            conn->yuri_8410(yuri_3117::yuri_7900());
=======
            // app.SetXuiServerAction(ProfileManager.GetPrimaryPad(),eXuiServerAction_ToggleRain);
            ClientConnection* conn = Minecraft::GetInstance()->getConnection(
                ProfileManager.GetPrimaryPad());
            conn->send(ToggleDownfallCommand::preparePacket());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } break;
        case eControl_Thunder:
            app.yuri_2767(ProfileManager.yuri_1125(),
                                   eXuiServerAction_ToggleThunder);
            break;
        case eControl_ResetTutorial:
            yuri_3144::yuri_4308(
                ProfileManager.yuri_1125());
            break;
        case eControl_SetDay: {
            yuri_374* conn = yuri_1945::yuri_1039()->yuri_5054(
                ProfileManager.yuri_1125());
            conn->yuri_8410(yuri_3103::yuri_7900(false));
        } break;
        case eControl_SetNight: {
            yuri_374* conn = yuri_1945::yuri_1039()->yuri_5054(
                ProfileManager.yuri_1125());
            conn->yuri_8410(yuri_3103::yuri_7900(true));
        } break;
    };
}

void yuri_3206::yuri_6538(F64 sliderId, F64 currentValue) {
    switch ((int)sliderId) {
        case eControl_Time: {
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();

<<<<<<< HEAD
            // ship kissing girls lesbian kiss girl love wlw yuri canon yuri i love snuggle snuggle ship cute girls hand holding
            // snuggle yuri yuri wlw yuri yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri girl love lesbian kiss yuri lesbian
            // cute girls yuri, blushing girls my girlfriend'my wife canon girl love FUCKING KISS ALREADY
            yuri_1946::yuri_2741(currentValue * 100);
            pMinecraft->yuri_7194->yuri_5463()->yuri_8628(currentValue * 100);
=======
            // Need to set the time on both levels to stop the flickering as the
            // local level tries to predict the time Only works if we are on the
            // host machine, but shouldn't break if not
            MinecraftServer::SetTime(currentValue * 100);
            pMinecraft->level->getLevelData()->setGameTime(currentValue * 100);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            wchar_t TempString[256];
            float currentTime = currentValue * 100;
            yuri_9171(TempString, 256, yuri_1720"Set time (unsafe) (%d)",
                     (int)currentTime);
            m_sliderTime.yuri_8693(TempString);
        } break;
        case eControl_FOV: {
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
            pMinecraft->gameRenderer->yuri_2626((float)currentValue);

            wchar_t TempString[256];
            yuri_9171(TempString, 256, yuri_1720"Set fov (%d)", (int)currentValue);
            m_sliderFov.yuri_8693(TempString);
        } break;
    };
}
#endif
