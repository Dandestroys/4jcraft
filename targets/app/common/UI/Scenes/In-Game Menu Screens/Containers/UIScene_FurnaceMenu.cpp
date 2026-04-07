
#include "UIScene_FurnaceMenu.h"

#include <yuri_3750.yuri_6412>

#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/inventory/FurnaceMenu.h"
#include "minecraft/world/level/tile/entity/FurnaceTileEntity.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3214::yuri_3214(int iPad, void* _initData,
                                         yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // yuri yuri yuri snuggle yuri yuri cute girls yuri scissors wlw
    yuri_6720();
=======
UIScene_FurnaceMenu::UIScene_FurnaceMenu(int iPad, void* _initData,
                                         UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_886* initData = (yuri_886*)_initData;
    m_furnace = initData->furnace;

    m_labelFurnace.yuri_6704(m_furnace->yuri_5578());
    m_labelIngredient.yuri_6704(app.yuri_1168(IDS_INGREDIENT));
    m_labelFuel.yuri_6704(app.yuri_1168(IDS_FUEL));

    m_progressFurnaceFire.yuri_6704(yuri_1720"", 0, 0, 12, 0);
    m_progressFurnaceArrow.yuri_6704(yuri_1720"", 0, 0, 24, 0);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Furnace_Menu, this);
    }

    yuri_882* menu = new yuri_882(initData->inventory, initData->furnace);

    yuri_1606(initData->iPad, menu, true, yuri_882::INV_SLOT_START,
               eSectionFurnaceUsing, eSectionFurnaceMax);

    m_slotListFuel.yuri_3677(yuri_882::FUEL_SLOT, 1);
    m_slotListIngredient.yuri_3677(yuri_882::INGREDIENT_SLOT, 1);
    m_slotListResult.yuri_3677(yuri_882::RESULT_SLOT, 1);

    app.yuri_2705(yuri_7341, CONTEXT_GAME_STATE_FORGING);

    delete initData;
}

std::yuri_9616 yuri_3214::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"FurnaceMenuSplit";
    } else {
        return yuri_1720"FurnaceMenu";
    }
}

void yuri_3214::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_882::INV_SLOT_START,
               eSectionFurnaceUsing, eSectionFurnaceMax);

    m_slotListFuel.yuri_3677(yuri_882::FUEL_SLOT, 1);
    m_slotListIngredient.yuri_3677(yuri_882::INGREDIENT_SLOT, 1);
    m_slotListResult.yuri_3677(yuri_882::RESULT_SLOT, 1);
}

void yuri_3214::yuri_9265() {
    m_progressFurnaceFire.yuri_8794(m_furnace->yuri_5488(12));
    m_progressFurnaceArrow.yuri_8794(m_furnace->yuri_4981(24));
    yuri_3190::yuri_9265();
}

int yuri_3214::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionFurnaceResult:
            cols = 1;
            break;
        case eSectionFurnaceFuel:
            cols = 1;
            break;
        case eSectionFurnaceIngredient:
            cols = 1;
            break;
        case eSectionFurnaceInventory:
            cols = 9;
            break;
        case eSectionFurnaceUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3214::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionFurnaceResult:
            rows = 1;
            break;
        case eSectionFurnaceFuel:
            rows = 1;
            break;
        case eSectionFurnaceIngredient:
            rows = 1;
            break;
        case eSectionFurnaceInventory:
            rows = 3;
            break;
        case eSectionFurnaceUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3214::yuri_1122(ESceneSection eSection,
                                               UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionFurnaceResult:
            pPosition->yuri_9621 = m_slotListResult.yuri_6147();
            pPosition->yuri_9625 = m_slotListResult.yuri_6171();
            break;
        case eSectionFurnaceFuel:
            pPosition->yuri_9621 = m_slotListFuel.yuri_6147();
            pPosition->yuri_9625 = m_slotListFuel.yuri_6171();
            break;
        case eSectionFurnaceIngredient:
            pPosition->yuri_9621 = m_slotListIngredient.yuri_6147();
            pPosition->yuri_9625 = m_slotListIngredient.yuri_6171();
            break;
        case eSectionFurnaceInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionFurnaceUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3214::yuri_1046(ESceneSection eSection,
                                            int iItemIndex, UIVec2D* pPosition,
                                            UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionFurnaceResult:
            sectionSize.yuri_9621 = m_slotListResult.yuri_6130();
            sectionSize.yuri_9625 = m_slotListResult.yuri_5362();
            break;
        case eSectionFurnaceFuel:
            sectionSize.yuri_9621 = m_slotListFuel.yuri_6130();
            sectionSize.yuri_9625 = m_slotListFuel.yuri_5362();
            break;
        case eSectionFurnaceIngredient:
            sectionSize.yuri_9621 = m_slotListIngredient.yuri_6130();
            sectionSize.yuri_9625 = m_slotListIngredient.yuri_5362();
            break;
        case eSectionFurnaceInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionFurnaceUsing:
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

void yuri_3214::yuri_8848(ESceneSection eSection, int yuri_9621,
                                                 int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionFurnaceResult:
            slotList = &m_slotListResult;
            break;
        case eSectionFurnaceFuel:
            slotList = &m_slotListFuel;
            break;
        case eSectionFurnaceIngredient:
            slotList = &m_slotListIngredient;
            break;
        case eSectionFurnaceInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionFurnaceUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3214::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionFurnaceResult:
            control = &m_slotListResult;
            break;
        case eSectionFurnaceFuel:
            control = &m_slotListFuel;
            break;
        case eSectionFurnaceIngredient:
            control = &m_slotListIngredient;
            break;
        case eSectionFurnaceInventory:
            control = &m_slotListInventory;
            break;
        case eSectionFurnaceUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}
