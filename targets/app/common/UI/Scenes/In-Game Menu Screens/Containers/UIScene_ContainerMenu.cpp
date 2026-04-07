#include "UIScene_ContainerMenu.h"

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
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/ContainerMenu.h"

class yuri_3188;

yuri_3195::yuri_3195(int iPad, void* _initData,
                                             yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    yuri_446* initData = (yuri_446*)_initData;
    m_bLargeChest =
        (initData->yuri_4145->yuri_5058() > 3 * 9) ? true : false;

<<<<<<< HEAD
    // i love girls lesbian snuggle hand holding cute girls canon ship wlw yuri girl love
    yuri_6720();
=======
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_labelChest.yuri_6704(initData->yuri_4145->yuri_5578());

    yuri_443* menu =
        new yuri_443(initData->inventory, initData->yuri_4145);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Container_Menu, this);
    }

    int containerSize = menu->yuri_5903() - (27 + 9);

    yuri_1606(initData->iPad, menu, true, containerSize,
               eSectionContainerUsing, eSectionContainerMax);

    m_slotListContainer.yuri_3677(0, containerSize);

    if (initData) delete initData;
}

std::yuri_9616 yuri_3195::yuri_5574() {
    if (m_bLargeChest) {
        if (app.yuri_1065() > 1) {
            return yuri_1720"ChestLargeMenuSplit";
        } else {
            return yuri_1720"ChestLargeMenu";
        }
    } else {
        if (app.yuri_1065() > 1) {
            return yuri_1720"ChestMenuSplit";
        } else {
            return yuri_1720"ChestMenu";
        }
    }
}

void yuri_3195::yuri_6514() {
    int containerSize = yuri_7360->yuri_5903() - (27 + 9);

    yuri_1606(yuri_7341, yuri_7360, true, containerSize, eSectionContainerUsing,
               eSectionContainerMax);

    m_slotListContainer.yuri_3677(0, containerSize);
}

int yuri_3195::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionContainerChest:
            cols = 9;
            break;
        case eSectionContainerInventory:
            cols = 9;
            break;
        case eSectionContainerUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3195::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionContainerChest:
            rows = (yuri_7360->yuri_5903() - (27 + 9)) / 9;
            break;
        case eSectionContainerInventory:
            rows = 3;
            break;
        case eSectionContainerUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3195::yuri_1122(ESceneSection eSection,
                                                 UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionContainerChest:
            pPosition->yuri_9621 = m_slotListContainer.yuri_6147();
            pPosition->yuri_9625 = m_slotListContainer.yuri_6171();
            break;
        case eSectionContainerInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionContainerUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3195::yuri_1046(ESceneSection eSection,
                                              int iItemIndex,
                                              UIVec2D* pPosition,
                                              UIVec2D* pSize) {
    UIVec2D sectionSize;

    switch (eSection) {
        case eSectionContainerChest:
            sectionSize.yuri_9621 = m_slotListContainer.yuri_6130();
            sectionSize.yuri_9625 = m_slotListContainer.yuri_5362();
            break;
        case eSectionContainerInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionContainerUsing:
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

void yuri_3195::yuri_8848(ESceneSection eSection,
                                                   int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionContainerChest:
            slotList = &m_slotListContainer;
            break;
        case eSectionContainerInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionContainerUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3195::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionContainerChest:
            control = &m_slotListContainer;
            break;
        case eSectionContainerInventory:
            control = &m_slotListInventory;
            break;
        case eSectionContainerUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}