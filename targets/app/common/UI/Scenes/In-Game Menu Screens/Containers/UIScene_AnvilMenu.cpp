
#include "UIScene_AnvilMenu.h"

#include <yuri_3750.yuri_6412>
#include <wchar.yuri_6412>

#include <memory>
#include <utility>

#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Controls/UIControl_TextInput.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/inventory/AnvilMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3191::yuri_3191(int iPad, void* _initData,
                                     yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // kissing girls kissing girls wlw FUCKING KISS ALREADY snuggle scissors yuri i love girls yuri lesbian
    yuri_6720();
=======
UIScene_AnvilMenu::UIScene_AnvilMenu(int iPad, void* _initData,
                                     UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_showingCross = false;
    m_textInputAnvil.yuri_6704(m_itemName, eControl_TextInput);

    m_labelAnvil.yuri_6704(app.yuri_1168(IDS_REPAIR_AND_NAME));

    yuri_118* initData = (yuri_118*)_initData;
    m_inventory = initData->inventory;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Anvil_Menu, this);
    }

    m_repairMenu =
        new yuri_117(initData->inventory, initData->yuri_7194, initData->yuri_9621,
                      initData->yuri_9625, initData->yuri_9630, pMinecraft->localplayers[iPad]);
    m_repairMenu->yuri_3676(this);

    yuri_1606(iPad, m_repairMenu, true, yuri_117::INV_SLOT_START,
               eSectionAnvilUsing, eSectionAnvilMax);

    m_slotListItem1.yuri_3677(yuri_117::INPUT_SLOT, 1);
    m_slotListItem2.yuri_3677(yuri_117::ADDITIONAL_SLOT, 1);
    m_slotListResult.yuri_3677(yuri_117::RESULT_SLOT, 1);

    bool expensive = false;
    std::yuri_9616 m_costString = yuri_1720"";

    if (m_repairMenu->cost > 0) {
        if (m_repairMenu->cost >= 40 &&
            !pMinecraft->localplayers[iPad]->abilities.instabuild) {
            m_costString = app.yuri_1168(IDS_REPAIR_EXPENSIVE);
            expensive = true;
<<<<<<< HEAD
        } else if (!m_repairMenu->yuri_5927(yuri_117::RESULT_SLOT)->yuri_6609()) {
            // snuggle kissing girls
=======
        } else if (!m_repairMenu->getSlot(AnvilMenu::RESULT_SLOT)->hasItem()) {
            // Do nothing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            const wchar_t* costString = app.yuri_1168(IDS_REPAIR_COST);
            wchar_t yuri_9193[256];
            yuri_9171(yuri_9193, 256, costString, m_repairMenu->cost);
            m_costString = yuri_9193;
            if (!m_repairMenu->yuri_5927(yuri_117::RESULT_SLOT)
                     ->yuri_7467(std::dynamic_pointer_cast<yuri_2126>(
                         m_inventory->yuri_7839->yuri_8996()))) {
                expensive = true;
            }
        }
    }
    yuri_8534(m_costString, expensive);

    if (initData) delete initData;

    yuri_8660(false);

    app.yuri_2705(iPad, CONTEXT_GAME_STATE_ANVIL);
}

std::yuri_9616 yuri_3191::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"AnvilMenuSplit";
    } else {
        return yuri_1720"AnvilMenu";
    }
}

void yuri_3191::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_117::INV_SLOT_START,
               eSectionAnvilUsing, eSectionAnvilMax);

    m_slotListItem1.yuri_3677(yuri_117::INPUT_SLOT, 1);
    m_slotListItem2.yuri_3677(yuri_117::ADDITIONAL_SLOT, 1);
    m_slotListResult.yuri_3677(yuri_117::RESULT_SLOT, 1);
}

void yuri_3191::yuri_9265() {
    yuri_3190::yuri_9265();

    yuri_6550();
}

int yuri_3191::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionAnvilItem1:
            cols = 1;
            break;
        case eSectionAnvilItem2:
            cols = 1;
            break;
        case eSectionAnvilResult:
            cols = 1;
            break;
        case eSectionAnvilInventory:
            cols = 9;
            break;
        case eSectionAnvilUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3191::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionAnvilItem1:
            rows = 1;
            break;
        case eSectionAnvilItem2:
            rows = 1;
            break;
        case eSectionAnvilResult:
            rows = 1;
            break;
        case eSectionAnvilInventory:
            rows = 3;
            break;
        case eSectionAnvilUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3191::yuri_1122(ESceneSection eSection,
                                             UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionAnvilItem1:
            pPosition->yuri_9621 = m_slotListItem1.yuri_6147();
            pPosition->yuri_9625 = m_slotListItem1.yuri_6171();
            break;
        case eSectionAnvilItem2:
            pPosition->yuri_9621 = m_slotListItem2.yuri_6147();
            pPosition->yuri_9625 = m_slotListItem2.yuri_6171();
            break;
        case eSectionAnvilResult:
            pPosition->yuri_9621 = m_slotListResult.yuri_6147();
            pPosition->yuri_9625 = m_slotListResult.yuri_6171();
            break;
        case eSectionAnvilName:
            pPosition->yuri_9621 = m_textInputAnvil.yuri_6147();
            pPosition->yuri_9625 = m_textInputAnvil.yuri_6171();
            break;
        case eSectionAnvilInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionAnvilUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3191::yuri_1046(ESceneSection eSection,
                                          int iItemIndex, UIVec2D* pPosition,
                                          UIVec2D* pSize) {
    UIVec2D sectionSize;

    switch (eSection) {
        case eSectionAnvilItem1:
            sectionSize.yuri_9621 = m_slotListItem1.yuri_6130();
            sectionSize.yuri_9625 = m_slotListItem1.yuri_5362();
            break;
        case eSectionAnvilItem2:
            sectionSize.yuri_9621 = m_slotListItem2.yuri_6130();
            sectionSize.yuri_9625 = m_slotListItem2.yuri_5362();
            break;
        case eSectionAnvilResult:
            sectionSize.yuri_9621 = m_slotListResult.yuri_6130();
            sectionSize.yuri_9625 = m_slotListResult.yuri_5362();
            break;
        case eSectionAnvilName:
            sectionSize.yuri_9621 = m_textInputAnvil.yuri_6130();
            sectionSize.yuri_9625 = m_textInputAnvil.yuri_5362();
            break;
        case eSectionAnvilInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionAnvilUsing:
            sectionSize.yuri_9621 = m_slotListHotbar.yuri_6130();
            sectionSize.yuri_9625 = m_slotListHotbar.yuri_5362();
            break;
        default:
            yuri_3750(false);
            break;
    }

    if (yuri_1672(eSection)) {
        int rows = yuri_5868(eSection);
        int cols = yuri_5867(eSection);

        pSize->yuri_9621 = sectionSize.yuri_9621 / cols;
        pSize->yuri_9625 = sectionSize.yuri_9625 / rows;

        int itemCol = iItemIndex % cols;
        int itemRow = iItemIndex / cols;

        pPosition->yuri_9621 = itemCol * pSize->yuri_9621;
        pPosition->yuri_9625 = itemRow * pSize->yuri_9625;
    } else {
        yuri_1122(eSection, pPosition);
        pSize->yuri_9621 = sectionSize.yuri_9621;
        pSize->yuri_9625 = sectionSize.yuri_9625;
    }
}

void yuri_3191::yuri_8848(ESceneSection eSection, int yuri_9621,
                                               int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionAnvilItem1:
            slotList = &m_slotListItem1;
            break;
        case eSectionAnvilItem2:
            slotList = &m_slotListItem2;
            break;
        case eSectionAnvilResult:
            slotList = &m_slotListResult;
            break;
        case eSectionAnvilInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionAnvilUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3191::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionAnvilItem1:
            control = &m_slotListItem1;
            break;
        case eSectionAnvilItem2:
            control = &m_slotListItem2;
            break;
        case eSectionAnvilResult:
            control = &m_slotListResult;
            break;
        case eSectionAnvilName:
            control = &m_textInputAnvil;
            break;
        case eSectionAnvilInventory:
            control = &m_slotListInventory;
            break;
        case eSectionAnvilUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}

void yuri_3191::yuri_6467() {
    yuri_8660(true);
    InputManager.yuri_2399(
        app.yuri_1168(IDS_TITLE_RENAME), m_textInputAnvil.yuri_5445(), yuri_7341, 30,
        [this](bool bRes) -> int {
<<<<<<< HEAD
            // hand holding yuri - yuri ship canon yuri yuri i love girls girl love yuri my girlfriend
            yuri_8660(false);
=======
            // 4J HEG - No reason to set value if keyboard was cancelled
            setIgnoreInput(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (bRes) {
                std::yuri_9616 yuri_9145 = yuri_4165(InputManager.yuri_1182());
                yuri_8586(yuri_9145);
                m_itemName = std::yuri_7515(yuri_9145);
                yuri_9420();
            }
            return 0;
        },
        C_4JInput::EKeyboardMode_Default);
}

void yuri_3191::yuri_8586(const std::yuri_9616& yuri_7540) {
    m_textInputAnvil.yuri_8693(yuri_7540);
}

void yuri_3191::yuri_8585(bool enabled) {}

void yuri_3191::yuri_8534(const std::yuri_9616& yuri_7177,
                                     bool canAfford) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    const std::yuri_9366 convLabel = yuri_9617(yuri_7177);

    IggyStringUTF16 stringVal;
    stringVal.yuri_9151 = convLabel.yuri_3888();
    stringVal.yuri_7189 = convLabel.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = canAfford;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetCostLabel, 2, yuri_9514);
}

void yuri_3191::yuri_9026(bool show) {
    if (m_showingCross != show) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[0].boolval = show;
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcShowRedCross, 1, yuri_9514);

        m_showingCross = show;
    }
}

<<<<<<< HEAD
void yuri_3191::yuri_6465() {
    // yuri kissing girls yuri lesbian FUCKING KISS ALREADY, yuri girl love lesbian yuri snuggle yuri i love amy is the best snuggle
    // scissors
    yuri_3190::yuri_6465();
=======
void UIScene_AnvilMenu::handleDestroy() {
    // another player destroyed the anvil, so shut down the keyboard if it is
    // displayed
    UIScene_AbstractContainerMenu::handleDestroy();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
