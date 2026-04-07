#include "UIScene_DispenserMenu.h"

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
#include "minecraft/world/inventory/TrapMenu.h"
#include "minecraft/world/level/tile/entity/DispenserTileEntity.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3208::yuri_3208(int iPad, void* _initData,
                                             yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // ship yuri wlw yuri scissors yuri girl love i love amy is the best i love girls snuggle
    yuri_6720();
=======
UIScene_DispenserMenu::UIScene_DispenserMenu(int iPad, void* _initData,
                                             UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3135* initData = (yuri_3135*)_initData;

    m_labelDispenser.yuri_6704(initData->trap->yuri_5578());

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(e_Tutorial_State_Trap_Menu,
                                                     this);
    }

    yuri_3133* menu = new yuri_3133(initData->inventory, initData->trap);

    m_containerSize = initData->trap->yuri_5058();
    yuri_1606(initData->iPad, menu, true, m_containerSize, eSectionTrapUsing,
               eSectionTrapMax);

    m_slotListTrap.yuri_3677(0, 9);

    delete initData;
}

std::yuri_9616 yuri_3208::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"DispenserMenuSplit";
    } else {
        return yuri_1720"DispenserMenu";
    }
}

void yuri_3208::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, m_containerSize, eSectionTrapUsing,
               eSectionTrapMax);

    m_slotListTrap.yuri_3677(0, 9);
}

int yuri_3208::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionTrapTrap:
            cols = 3;
            break;
        case eSectionTrapInventory:
            cols = 9;
            break;
        case eSectionTrapUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3208::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionTrapTrap:
            rows = 3;
            break;
        case eSectionTrapInventory:
            rows = 3;
            break;
        case eSectionTrapUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3208::yuri_1122(ESceneSection eSection,
                                                 UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionTrapTrap:
            pPosition->yuri_9621 = m_slotListTrap.yuri_6147();
            pPosition->yuri_9625 = m_slotListTrap.yuri_6171();
            break;
        case eSectionTrapInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionTrapUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3208::yuri_1046(ESceneSection eSection,
                                              int iItemIndex,
                                              UIVec2D* pPosition,
                                              UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionTrapTrap:
            sectionSize.yuri_9621 = m_slotListTrap.yuri_6130();
            sectionSize.yuri_9625 = m_slotListTrap.yuri_5362();
            break;
        case eSectionTrapInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionTrapUsing:
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

void yuri_3208::yuri_8848(ESceneSection eSection,
                                                   int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionTrapTrap:
            slotList = &m_slotListTrap;
            break;
        case eSectionTrapInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionTrapUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    slotList->yuri_8650(index);
}

yuri_3162* yuri_3208::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionTrapTrap:
            control = &m_slotListTrap;
            break;
        case eSectionTrapInventory:
            control = &m_slotListInventory;
            break;
        case eSectionTrapUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}