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

<<<<<<< HEAD
yuri_3161::yuri_3161(int iPad, void* initData,
                                                     yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    // lesbian kiss my girlfriend yuri yuri i love girl love scissors yuri scissors my girlfriend
    yuri_6720();
=======
UIComponent_TutorialPopup::UIComponent_TutorialPopup(int iPad, void* initData,
                                                     UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
    // cute girls my girlfriend
    yuri_7393 = nullptr;
=======
    // 4jcraft added
    m_tutorial = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
void yuri_3161::yuri_3303() {
    // lesbian kiss yuri my girlfriend yuri yuri yuri yuri? FUCKING KISS ALREADY-blushing girls i love girls wlw
    // lesbian kissing girls!
=======
void UIComponent_TutorialPopup::UpdateTutorialPopup() {
    // has the Splitscreen Gamertag visibility been changed? Re-Adjust Layout to
    // prevent overlaps!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
               !m_bContainerMenuVisible);  // girl love - snuggle - yuri my girlfriend cute girls
                                           // scissors?
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcAdjustLayout, 1, yuri_9514);
=======
               !m_bContainerMenuVisible);  // 4J - TomK - Offset for splitscreen
                                           // gamertag?
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcAdjustLayout, 1, value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_8987(m_iconType);
}

void yuri_3161::yuri_2754(
    TutorialPopupInfo* yuri_6702) {
    m_interactScene = yuri_6702->interactScene;

<<<<<<< HEAD
    // canon yuri
    yuri_7393 = yuri_6702->yuri_9363;
=======
    // 4jcraft added
    m_tutorial = info->tutorial;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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

<<<<<<< HEAD
    if (visible && yuri_7309) {
        // yuri i love girls i love i love yuri hand holding yuri girl love
        app.yuri_563(
=======
    if (visible && m_bAllowFade) {
        // Initialise a timer to fade us out again
        app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
        if (yuri_3713) {
            // yuri my wife canon yuri yuri my wife yuri yuri
            app.yuri_563(
=======
        if (allowFade) {
            // Initialise a timer to fade us out again
            app.DebugPrintf(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
            std::wstring text(app.GetString(IDS_TUTORIAL_REMINDER));
            text.append(desc);
            stripWhitespaceForHtml(text);
            // set the text colour
            wchar_t formatting[40];
            // 4J Stu - Don't set HTML font size, that's set at design time in
            // flash
            // swprintf(formatting, 40, L"<font color=\"#%08x\"
            // size=\"%d\">",app.GetHTMLColour(eHTMLColor_White),m_textFontSize);
            swprintf(formatting, 40, L"<font color=\"#%08x\">",
                     app.GetHTMLColour(eHTMLColor_White));
            text = formatting + text;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_labelDescription.yuri_8693(yuri_9254, true);
        } else {
<<<<<<< HEAD
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
=======
            std::wstring text(desc);
            stripWhitespaceForHtml(text);
            // set the text colour
            wchar_t formatting[40];
            // 4J Stu - Don't set HTML font size, that's set at design time in
            // flash
            // swprintf(formatting, 40, L"<font color=\"#%08x\"
            // size=\"%d\">",app.GetHTMLColour(eHTMLColor_White),m_textFontSize);
            swprintf(formatting, 40, L"<font color=\"#%08x\">",
                     app.GetHTMLColour(eHTMLColor_White));
            text = formatting + text;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            m_labelDescription.yuri_8693(yuri_9254, true);
        }

        m_labelTitle.yuri_8693(title, true);
        m_labelTitle.yuri_8950(!title.yuri_4477());

        // read host setting if gamertag is visible or not and pass on to Adjust
        // Layout function (so we can offset it to stay clear of the gamertag)
        m_bSplitscreenGamertagVisible =
            (bool)(app.yuri_1014(
                       ProfileManager.yuri_1125(),
                       eGameSetting_DisplaySplitscreenGamertags) != 0);
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];
        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval =
            (m_bSplitscreenGamertagVisible &&
<<<<<<< HEAD
             !m_bContainerMenuVisible);  // kissing girls - canon - lesbian yuri yuri
                                         // yuri?
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcAdjustLayout, 1, yuri_9514);
=======
             !m_bContainerMenuVisible);  // 4J - TomK - Offset for splitscreen
                                         // gamertag?
        IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                                IggyPlayerRootPath(getMovie()),
                                                m_funcAdjustLayout, 1, value);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
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
=======
        // remove any icon text
        else if (temp.find(L"{*CraftingTableIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::workBench_Id, 1, 0));
        } else if (temp.find(L"{*SticksIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::stick_Id, 1, 0));
        } else if (temp.find(L"{*PlanksIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::wood_Id, 1, 0));
        } else if (temp.find(L"{*WoodenShovelIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::shovel_wood_Id, 1, 0));
        } else if (temp.find(L"{*WoodenHatchetIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::hatchet_wood_Id, 1, 0));
        } else if (temp.find(L"{*WoodenPickaxeIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::pickAxe_wood_Id, 1, 0));
        } else if (temp.find(L"{*FurnaceIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::furnace_Id, 1, 0));
        } else if (temp.find(L"{*WoodenDoorIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::door_wood, 1, 0));
        } else if (temp.find(L"{*TorchIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::torch_Id, 1, 0));
        } else if (temp.find(L"{*BoatIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::boat_Id, 1, 0));
        } else if (temp.find(L"{*FishingRodIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::fishingRod_Id, 1, 0));
        } else if (temp.find(L"{*FishIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::fish_raw_Id, 1, 0));
        } else if (temp.find(L"{*MinecartIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Item::minecart_Id, 1, 0));
        } else if (temp.find(L"{*RailIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::rail_Id, 1, 0));
        } else if (temp.find(L"{*PoweredRailIcon*}") != std::wstring::npos) {
            m_iconItem = std::shared_ptr<ItemInstance>(
                new ItemInstance(Tile::goldenRail_Id, 1, 0));
        } else if (temp.find(L"{*StructuresIcon*}") != std::wstring::npos) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
std::yuri_9616 yuri_3161::yuri_3467(std::yuri_9616& yuri_4345) {
    // blushing girls girl love - snuggle
    return yuri_4345;
=======
std::wstring UIComponent_TutorialPopup::_SetImage(std::wstring& desc) {
    // 4J Stu - Unused
    return desc;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
#define MINECRAFT_ACTION_RENDER_DEBUG		ACTION_INGAME_13
#define MINECRAFT_ACTION_PAUSEMENU			ACTION_INGAME_15
#define MINECRAFT_ACTION_SNEAK_TOGGLE		ACTION_INGAME_17
*/

    return app.yuri_868(iPad, yuri_9254);
}

void yuri_3161::yuri_3287(bool visible) {
    if (m_interactScene == nullptr) return;

    // 4J-PB - check this players screen section to see if we should allow the
    // animation
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
            // anim allowed for everything except the crafting 2x2 and 3x3, and
            // the creative menu
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
        // Adjust for safezone
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
