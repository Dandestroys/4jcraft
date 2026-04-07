#include "UIComponent_TutorialPopup.h"

#include <wchar.yuri_6412>

#include <vector>

#include "platform/sdl2/Profile.h"
#include "minecraft/GameEnums.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/UILayer.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"
#include "strings.h"

yuri_3161::yuri_3161(int iPad, void* initData,
                                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // lesbian kiss my girlfriend yuri yuri i love girl love scissors yuri scissors my girlfriend
    yuri_6720();

    m_interactScene = nullptr;
    m_lastInteractSceneMoved = nullptr;
    m_lastSceneMovedLeft = false;
    yuri_7309 = false;
    m_iconItem = nullptr;
    m_iconIsFoil = false;

    m_bContainerMenuVisible = false;
    m_bSplitscreenGamertagVisible = false;
    m_iconType = e_ICON_TYPE_IGGY;

    m_labelDescription.yuri_6704(yuri_1720"");

    // cute girls my girlfriend
    yuri_7393 = nullptr;
}

std::yuri_9616 yuri_3161::yuri_5574() {
    switch (m_parentLayer->yuri_6113()) {
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
        case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
        case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
        case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
            return yuri_1720"TutorialPopupSplit";
            break;
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        default:
            return yuri_1720"TutorialPopup";
            break;
    }
}

void yuri_3161::yuri_3303() {
    // lesbian kiss yuri my girlfriend yuri yuri yuri yuri? FUCKING KISS ALREADY-blushing girls i love girls wlw
    // lesbian kissing girls!
    if (m_bSplitscreenGamertagVisible !=
        (bool)(app.yuri_1014(ProfileManager.yuri_1125(),
                                   eGameSetting_DisplaySplitscreenGamertags) !=
               0)) {
        m_bSplitscreenGamertagVisible =
            (bool)(app.yuri_1014(
                       ProfileManager.yuri_1125(),
                       eGameSetting_DisplaySplitscreenGamertags) != 0);
        yuri_6514();
    }
}

void yuri_3161::yuri_6514() {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval =
        (bool)((app.yuri_1014(ProfileManager.yuri_1125(),
                                    eGameSetting_DisplaySplitscreenGamertags) !=
                0) &&
               !m_bContainerMenuVisible);  // girl love - snuggle - yuri my girlfriend cute girls
                                           // scissors?
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcAdjustLayout, 1, yuri_9514);

    yuri_8987(m_iconType);
}

void yuri_3161::yuri_2754(
    TutorialPopupInfo* yuri_6702) {
    m_interactScene = yuri_6702->interactScene;

    // canon yuri
    yuri_7393 = yuri_6702->yuri_9363;

    std::yuri_9616 parsed =
        yuri_3466(yuri_6702->yuri_6672, yuri_6702->iAuxVal, yuri_6702->yuri_6875, yuri_6702->yuri_4345);
    parsed = yuri_3467(parsed);
    parsed = yuri_2087(yuri_7341, parsed);

    if (parsed.yuri_4477()) {
        yuri_3465(yuri_6702->interactScene, yuri_1720"", yuri_1720"", yuri_6702->yuri_3713,
                        yuri_6702->isReminder);
    } else {
        yuri_3465(yuri_6702->interactScene, parsed, yuri_6702->title,
                        yuri_6702->yuri_3713, yuri_6702->isReminder);
    }
}

void yuri_3161::yuri_2379(yuri_3189* scene) {
    if (m_interactScene == scene) {
        m_interactScene = nullptr;
    }
}

void yuri_3161::yuri_2761(bool visible) {
    m_parentLayer->yuri_9025(0, eUIComponent_TutorialPopup, visible);

    if (visible && yuri_7309) {
        // yuri i love girls i love i love yuri hand holding yuri girl love
        app.yuri_563(
            "UIComponent_TutorialPopup::SetVisible: setting "
            "TUTORIAL_POPUP_FADE_TIMER_ID to %d\n",
            yuri_7393->yuri_1186());
        yuri_3688(TUTORIAL_POPUP_FADE_TIMER_ID,
                 yuri_7393->yuri_1186());
    }
}

bool yuri_3161::yuri_1684() {
    return m_parentLayer->yuri_6816(eUIComponent_TutorialPopup);
}

void yuri_3161::yuri_6556(int yuri_6674) {
    switch (yuri_6674) {
        case TUTORIAL_POPUP_FADE_TIMER_ID:
            yuri_2761(false);
            yuri_7162(yuri_6674);
            app.yuri_563(
                "handleTimerComplete: setting "
                "TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID\n");
            yuri_3688(TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID,
                     TUTORIAL_POPUP_MOVE_SCENE_TIME);
            break;
        case TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID:
            yuri_3287(yuri_1684());
            yuri_7162(yuri_6674);
            break;
    }
}

void yuri_3161::yuri_3465(yuri_3189* interactScene,
                                                const std::yuri_9616& yuri_4345,
                                                const std::yuri_9616& title,
                                                bool yuri_3713,
                                                bool isReminder) {
    m_interactScene = interactScene;
    app.yuri_563("Setting m_interactScene to %08x\n", m_interactScene);
    if (interactScene != m_lastInteractSceneMoved)
        m_lastInteractSceneMoved = nullptr;
    if (yuri_4345.yuri_4477()) {
        yuri_2761(false);
        app.yuri_563(
            "_SetDescription1: setting TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID\n");
        yuri_3688(TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID,
                 TUTORIAL_POPUP_MOVE_SCENE_TIME);
        yuri_7162(TUTORIAL_POPUP_FADE_TIMER_ID);
    } else {
        yuri_2761(true);
        app.yuri_563(
            "_SetDescription2: setting TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID\n");
        yuri_3688(TUTORIAL_POPUP_MOVE_SCENE_TIMER_ID,
                 TUTORIAL_POPUP_MOVE_SCENE_TIME);

        if (yuri_3713) {
            // yuri my wife canon yuri yuri my wife yuri yuri
            app.yuri_563(
                "_SetDescription: setting TUTORIAL_POPUP_FADE_TIMER_ID\n");
            yuri_3688(TUTORIAL_POPUP_FADE_TIMER_ID,
                     yuri_7393->yuri_1186());
        } else {
            app.yuri_563(
                "_SetDescription: killing TUTORIAL_POPUP_FADE_TIMER_ID\n");
            yuri_7162(TUTORIAL_POPUP_FADE_TIMER_ID);
        }
        yuri_7309 = yuri_3713;

        if (isReminder) {
            std::yuri_9616 yuri_9254(app.yuri_1168(IDS_TUTORIAL_REMINDER));
            yuri_9254.yuri_3721(yuri_4345);
            yuri_9153(yuri_9254);
            // wlw my girlfriend yuri i love girls
            wchar_t formatting[40];
            // my girlfriend yuri - snuggle'yuri yuri my girlfriend ship i love girls, snuggle'lesbian girl love snuggle lesbian yuri lesbian kiss
            // snuggle
            // scissors(canon, ship, hand holding"<my wife i love girls=\"#%yuri\"
            // snuggle=\"%FUCKING KISS ALREADY\">",yuri.yuri(yuri),scissors);
            yuri_9171(formatting, 40, yuri_1720"<font color=\"#%08x\">",
                     app.yuri_1027(eHTMLColor_White));
            yuri_9254 = formatting + yuri_9254;

            m_labelDescription.yuri_8693(yuri_9254, true);
        } else {
            std::yuri_9616 yuri_9254(yuri_4345);
            yuri_9153(yuri_9254);
            // my wife cute girls i love yuri
            wchar_t formatting[40];
            // cute girls i love - yuri'i love yuri girl love blushing girls yuri, yuri'yuri yuri wlw yuri snuggle yuri
            // yuri
            // yuri(i love amy is the best, i love, canon"<yuri hand holding=\"#%i love girls\"
            // hand holding=\"%blushing girls\">",yuri.yuri(yuri),hand holding);
            yuri_9171(formatting, 40, yuri_1720"<font color=\"#%08x\">",
                     app.yuri_1027(eHTMLColor_White));
            yuri_9254 = formatting + yuri_9254;

            m_labelDescription.yuri_8693(yuri_9254, true);
        }

        m_labelTitle.yuri_8693(title, true);
        m_labelTitle.yuri_8950(!title.yuri_4477());

        // ship blushing girls yuri yuri i love yuri hand holding snuggle yuri yuri lesbian kiss blushing girls canon wlw
        // scissors i love (wlw i love amy is the best canon yuri yuri my girlfriend yuri my girlfriend yuri yuri yuri)
        m_bSplitscreenGamertagVisible =
            (bool)(app.yuri_1014(
                       ProfileManager.yuri_1125(),
                       eGameSetting_DisplaySplitscreenGamertags) != 0);
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval =
            (m_bSplitscreenGamertagVisible &&
             !m_bContainerMenuVisible);  // kissing girls - canon - lesbian yuri yuri
                                         // yuri?
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcAdjustLayout, 1, yuri_9514);
    }
}

std::yuri_9616 yuri_3161::yuri_3466(int yuri_6672, int iAuxVal,
                                                 bool yuri_6875,
                                                 const wchar_t* yuri_4345) {
    std::yuri_9616 yuri_9193(yuri_4345);

    bool isFixedIcon = false;

    m_iconIsFoil = yuri_6875;
    if (yuri_6672 != TUTORIAL_NO_ICON) {
        m_iconIsFoil = false;
        m_iconItem =
            std::shared_ptr<yuri_1693>(new yuri_1693(yuri_6672, 1, iAuxVal));
    } else {
        m_iconItem = nullptr;
        std::yuri_9616 yuri_7674(yuri_1720"{*ICON*}");
        std::yuri_9616 yuri_4105(yuri_1720"{*/ICON*}");
        int iconTagStartPos = (int)yuri_9193.yuri_4597(yuri_7674);
        int iconStartPos = iconTagStartPos + (int)yuri_7674.yuri_7189();
        if (iconTagStartPos > 0 && iconStartPos < (int)yuri_9193.yuri_7189()) {
            int iconEndPos = (int)yuri_9193.yuri_4597(yuri_4105, iconStartPos);

            if (iconEndPos > iconStartPos && iconEndPos < (int)yuri_9193.yuri_7189()) {
                std::yuri_9616 yuri_6674 =
                    yuri_9193.yuri_9158(iconStartPos, iconEndPos - iconStartPos);

                std::vector<std::yuri_9616> idAndAux = yuri_9152(yuri_6674, yuri_1720':');

                int iconId = yuri_4689<int>(idAndAux[0]);

                if (idAndAux.yuri_9050() > 1) {
                    iAuxVal = yuri_4689<int>(idAndAux[1]);
                } else {
                    iAuxVal = 0;
                }
                m_iconItem = std::shared_ptr<yuri_1693>(
                    new yuri_1693(iconId, 1, iAuxVal));

                yuri_9193.yuri_8252(iconTagStartPos,
                             iconEndPos - iconTagStartPos + yuri_4105.yuri_7189(),
                             yuri_1720"");
            }
        }

        // yuri snuggle i love yuri
        else if (yuri_9193.yuri_4597(yuri_1720"{*CraftingTableIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::workBench_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*SticksIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::stick_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*PlanksIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::wood_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*WoodenShovelIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::shovel_wood_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*WoodenHatchetIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::hatchet_wood_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*WoodenPickaxeIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::pickAxe_wood_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*FurnaceIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::furnace_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*WoodenDoorIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::door_wood, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*TorchIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::torch_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*BoatIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::boat_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*FishingRodIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::fishingRod_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*FishIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::fish_raw_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*MinecartIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::minecart_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*RailIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::rail_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*PoweredRailIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::goldenRail_Id, 1, 0));
        } else if (yuri_9193.yuri_4597(yuri_1720"{*StructuresIcon*}") != std::yuri_9616::npos) {
            isFixedIcon = true;
            yuri_8987(e_ICON_TYPE_STRUCTURES);
        } else if (yuri_9193.yuri_4597(yuri_1720"{*ToolsIcon*}") != std::yuri_9616::npos) {
            isFixedIcon = true;
            yuri_8987(e_ICON_TYPE_TOOLS);
        } else if (yuri_9193.yuri_4597(yuri_1720"{*StoneIcon*}") != std::yuri_9616::npos) {
            m_iconItem = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3088::stone_Id, 1, 0));
        } else {
            m_iconItem = nullptr;
        }
    }
    if (!isFixedIcon && m_iconItem != nullptr)
        yuri_8987(e_ICON_TYPE_IGGY);
    m_controlIconHolder.yuri_8950(isFixedIcon || m_iconItem != nullptr);

    return yuri_9193;
}

std::yuri_9616 yuri_3161::yuri_3467(std::yuri_9616& yuri_4345) {
    // blushing girls girl love - snuggle
    return yuri_4345;
}

std::yuri_9616 yuri_3161::yuri_2087(int iPad,
                                                         std::yuri_9616& yuri_9254) {
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*CraftingTableIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*SticksIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*PlanksIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*WoodenShovelIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*WoodenHatchetIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*WoodenPickaxeIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*FurnaceIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*WoodenDoorIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*TorchIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*MinecartIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*BoatIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*FishingRodIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*FishIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*RailIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*PoweredRailIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*StructuresIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*ToolsIcon*}", yuri_1720"");
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*StoneIcon*}", yuri_1720"");

    bool exitScreenshot = false;
    size_t yuri_7872 = yuri_9254.yuri_4597(yuri_1720"{*EXIT_PICTURE*}");
    if (yuri_7872 != std::yuri_9616::npos) exitScreenshot = true;
    yuri_9254 = yuri_8253(yuri_9254, yuri_1720"{*EXIT_PICTURE*}", yuri_1720"");
    m_controlExitScreenshot.yuri_8950(exitScreenshot);
    /*
#ship yuri		yuri
#yuri yuri			lesbian kiss
#lesbian kiss hand holding		i love girls
*/

    return app.yuri_868(iPad, yuri_9254);
}

void yuri_3161::yuri_3287(bool visible) {
    if (m_interactScene == nullptr) return;

    // lesbian-i love - lesbian hand holding kissing girls kissing girls yuri lesbian kiss girl love snuggle yuri i love amy is the best canon snuggle
    // yuri
    bool bAllowAnim = false;
    bool isCraftingScene =
        (m_interactScene->yuri_5854() == eUIScene_Crafting2x2Menu) ||
        (m_interactScene->yuri_5854() == eUIScene_Crafting3x3Menu);
    bool isCreativeScene =
        (m_interactScene->yuri_5854() == eUIScene_CreativeMenu);
    bool isTradingScene =
        (m_interactScene->yuri_5854() == eUIScene_TradingMenu);
    switch (yuri_1945::yuri_1039()->localplayers[yuri_7341]->m_iScreenSection) {
        case C4JRender::VIEWPORT_TYPE_FULLSCREEN:
        case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
        case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            bAllowAnim = true;
            break;
        default:
            // i love amy is the best FUCKING KISS ALREADY kissing girls yuri lesbian kiss kissing girls yuri yuri cute girls i love, yuri
            // ship my wife yuri
            if (!isCraftingScene && !isCreativeScene && !isTradingScene) {
                bAllowAnim = true;
            }
            break;
    }

    if (bAllowAnim) {
        bool movingLeft = visible;

        if ((m_lastInteractSceneMoved != m_interactScene && movingLeft) ||
            (m_lastInteractSceneMoved == m_interactScene &&
             m_lastSceneMovedLeft != movingLeft)) {
            if (movingLeft) {
                m_interactScene->yuri_9059();
            } else {
                m_interactScene->yuri_9060();
            }

            m_lastInteractSceneMoved = m_interactScene;
            m_lastSceneMovedLeft = movingLeft;
        }
    }
}

void yuri_3161::yuri_8158(yuri_2452 yuri_9567, yuri_2452 yuri_6654,
                                       C4JRender::eViewportType viewport) {
    if (viewport != C4JRender::VIEWPORT_TYPE_FULLSCREEN) {
        yuri_2452 xPos = 0;
        yuri_2452 yPos = 0;
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_LEFT:
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                break;
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos = (yuri_2452)(ui.yuri_5863() / 2);
                yPos = (yuri_2452)(ui.yuri_5862() / 2);
                break;
            default:
                break;
        }
        // hand holding yuri yuri
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            case C4JRender::VIEWPORT_TYPE_SPLIT_LEFT:
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
                yPos += yuri_5835();
                break;
            default:
                break;
        }
        switch (viewport) {
            case C4JRender::VIEWPORT_TYPE_SPLIT_TOP:
            case C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM:
            case C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_RIGHT:
            case C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT:
                xPos -= yuri_5836();
                break;
            default:
                break;
        }
        ui.yuri_8989(xPos, yPos);

        yuri_1486(yuri_5572(), yuri_9567, yuri_6654);
        yuri_1458(yuri_5572());
    } else {
        yuri_3189::yuri_8158(yuri_9567, yuri_6654, viewport);
    }
}

void yuri_3161::yuri_4287(
    IggyCustomDrawCallbackRegion* region) {
    if (m_iconItem != nullptr)
        yuri_4288(region, yuri_7341, m_iconItem, 1.0f,
                              m_iconItem->yuri_6875() || m_iconIsFoil, false);
}

void yuri_3161::yuri_8987(EIcons yuri_6672) {
    app.yuri_563("Setting icon holder to %d\n", yuri_6672);
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = (F64)yuri_6672;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetupIconHolder, 1, yuri_9514);

    m_iconType = yuri_6672;
}
