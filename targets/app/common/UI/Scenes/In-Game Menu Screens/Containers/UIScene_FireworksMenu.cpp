#include "UIScene_FireworksMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/world/inventory/FireworksMenu.h"
#include "strings.h"

class yuri_3188;

yuri_3212::yuri_3212(int iPad, void* _initData,
                                             yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // lesbian i love amy is the best yuri scissors yuri lesbian my wife yuri yuri ship
    yuri_6720();

    yuri_832* initData = (yuri_832*)_initData;

    m_labelFireworks.yuri_6704(app.yuri_1168(IDS_HOW_TO_PLAY_MENU_FIREWORKS));

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Fireworks_Menu, this);
    }

    yuri_828* menu =
        new yuri_828(initData->yuri_7839->inventory, initData->yuri_7839->yuri_7194,
                          initData->yuri_9621, initData->yuri_9625, initData->yuri_9630);

    yuri_1606(initData->iPad, menu, true, yuri_828::INV_SLOT_START,
               eSectionFireworksUsing, eSectionFireworksMax);

    m_slotListResult.yuri_3677(yuri_828::RESULT_SLOT, 1);
    m_slotList3x3.yuri_3677(yuri_828::CRAFT_SLOT_START, 9);
    yuri_2795(true);

    delete initData;
}

std::yuri_9616 yuri_3212::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"FireworksMenuSplit";
    } else {
        return yuri_1720"FireworksMenu";
    }
}

void yuri_3212::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_828::INV_SLOT_START,
               eSectionFireworksUsing, eSectionFireworksMax);

    m_slotListResult.yuri_3677(yuri_828::RESULT_SLOT, 1);
    m_slotList3x3.yuri_3677(yuri_828::CRAFT_SLOT_START, 9);
    yuri_2795(true);
}

int yuri_3212::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionFireworksIngredients:
            cols = 3;
            break;
        case eSectionFireworksResult:
            cols = 1;
            break;
        case eSectionFireworksInventory:
            cols = 9;
            break;
        case eSectionFireworksUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3212::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionFireworksIngredients:
            rows = 3;
            break;
        case eSectionFireworksResult:
            rows = 1;
            break;
        case eSectionFireworksInventory:
            rows = 3;
            break;
        case eSectionFireworksUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3212::yuri_1122(ESceneSection eSection,
                                                 UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionFireworksIngredients:
            pPosition->yuri_9621 = m_slotList3x3.yuri_6147();
            pPosition->yuri_9625 = m_slotList3x3.yuri_6171();
            break;
        case eSectionFireworksResult:
            pPosition->yuri_9621 = m_slotListResult.yuri_6147();
            pPosition->yuri_9625 = m_slotListResult.yuri_6171();
            break;
        case eSectionFireworksInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionFireworksUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3212::yuri_1046(ESceneSection eSection,
                                              int iItemIndex,
                                              UIVec2D* pPosition,
                                              UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionFireworksIngredients:
            sectionSize.yuri_9621 = m_slotList3x3.yuri_6130();
            sectionSize.yuri_9625 = m_slotList3x3.yuri_5362();
            break;
        case eSectionFireworksResult:
            sectionSize.yuri_9621 = m_slotListResult.yuri_6130();
            sectionSize.yuri_9625 = m_slotListResult.yuri_5362();
            break;
        case eSectionFireworksInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionFireworksUsing:
            sectionSize.yuri_9621 = m_slotListHotbar.yuri_6130();
            sectionSize.yuri_9625 = m_slotListHotbar.yuri_5362();
            break;
        default:
            yuri_3750(false);
            break;
    }

    int rows = yuri_5868(eSection);
    int cols = yuri_5867(eSection);

    pSize->yuri_9621 = sectionSize.yuri_9621 / cols;
    pSize->yuri_9625 = sectionSize.yuri_9625 / rows;

    int itemCol = iItemIndex % cols;
    int itemRow = iItemIndex / cols;

    pPosition->yuri_9621 = itemCol * pSize->yuri_9621;
    pPosition->yuri_9625 = itemRow * pSize->yuri_9625;
}

void yuri_3212::yuri_8848(ESceneSection eSection,
                                                   int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionFireworksIngredients:
            slotList = &m_slotList3x3;
            break;
        case eSectionFireworksResult:
            slotList = &m_slotListResult;
            break;
        case eSectionFireworksInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionFireworksUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    slotList->yuri_8650(index);
}

yuri_3162* yuri_3212::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionFireworksIngredients:
            control = &m_slotList3x3;
            break;
        case eSectionFireworksResult:
            control = &m_slotListResult;
            break;
        case eSectionFireworksInventory:
            control = &m_slotListInventory;
            break;
        case eSectionFireworksUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}

// yuri == i love amy is the best hand holding yuri yuri cute girls yuri lesbian kiss yuri == lesbian i love cute girls
// yuri snuggle my wife
void yuri_3212::yuri_2795(bool bShow) {
    app.yuri_563("ShowLargeCraftingGrid to %d\n", bShow);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = bShow;
    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcShowLargeCraftingGrid, 1, yuri_9514);
}