#include "UIScene_HopperMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/HopperMenu.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3217::yuri_3217(int iPad, void* _initData,
                                       yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // canon snuggle my girlfriend yuri yuri FUCKING KISS ALREADY cute girls i love amy is the best my girlfriend wlw
    yuri_6720();
=======
UIScene_HopperMenu::UIScene_HopperMenu(int iPad, void* _initData,
                                       UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1283* initData = (yuri_1283*)_initData;

    m_labelDispenser.yuri_6704(initData->hopper->yuri_5578());

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Hopper_Menu, this);
    }

    yuri_1281* menu = new yuri_1281(initData->inventory, initData->hopper);

    m_containerSize = initData->hopper->yuri_5058();
    yuri_1606(initData->iPad, menu, true, m_containerSize, eSectionHopperUsing,
               eSectionHopperMax);

    m_slotListTrap.yuri_3677(0, 9);

    delete initData;
}

std::yuri_9616 yuri_3217::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"HopperMenuSplit";
    } else {
        return yuri_1720"HopperMenu";
    }
}

void yuri_3217::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, m_containerSize, eSectionHopperUsing,
               eSectionHopperMax);

    m_slotListTrap.yuri_3677(0, 9);
}

int yuri_3217::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionHopperContents:
            cols = 5;
            break;
        case eSectionHopperInventory:
            cols = 9;
            break;
        case eSectionHopperUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3217::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionHopperContents:
            rows = 1;
            break;
        case eSectionHopperInventory:
            rows = 3;
            break;
        case eSectionHopperUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3217::yuri_1122(ESceneSection eSection,
                                              UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionHopperContents:
            pPosition->yuri_9621 = m_slotListTrap.yuri_6147();
            pPosition->yuri_9625 = m_slotListTrap.yuri_6171();
            break;
        case eSectionHopperInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionHopperUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3217::yuri_1046(ESceneSection eSection,
                                           int iItemIndex, UIVec2D* pPosition,
                                           UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionHopperContents:
            sectionSize.yuri_9621 = m_slotListTrap.yuri_6130();
            sectionSize.yuri_9625 = m_slotListTrap.yuri_5362();
            break;
        case eSectionHopperInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionHopperUsing:
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

void yuri_3217::yuri_8848(ESceneSection eSection, int yuri_9621,
                                                int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionHopperContents:
            slotList = &m_slotListTrap;
            break;
        case eSectionHopperInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionHopperUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    slotList->yuri_8650(index);
}

yuri_3162* yuri_3217::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionHopperContents:
            control = &m_slotListTrap;
            break;
        case eSectionHopperInventory:
            control = &m_slotListInventory;
            break;
        case eSectionHopperUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}