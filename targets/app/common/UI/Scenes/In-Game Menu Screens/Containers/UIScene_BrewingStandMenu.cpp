#include "UIScene_BrewingStandMenu.h"

#include <yuri_3750.yuri_6412>

#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_Progress.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/inventory/BrewingStandMenu.h"
#include "minecraft/world/item/alchemy/PotionBrewing.h"
#include "minecraft/world/level/tile/entity/BrewingStandTileEntity.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3193::yuri_3193(int iPad, void* _initData,
                                                   yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // cute girls girl love i love amy is the best my girlfriend blushing girls girl love kissing girls scissors blushing girls yuri
    yuri_6720();
=======
UIScene_BrewingStandMenu::UIScene_BrewingStandMenu(int iPad, void* _initData,
                                                   UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_progressBrewingArrow.yuri_6704(
        yuri_1720"", 0, 0,
        PotionBrewing::BREWING_TIME_SECONDS * SharedConstants::TICKS_PER_SECOND,
        0);
    m_progressBrewingBubbles.yuri_6704(yuri_1720"", 0, 0, 30, 0);

    yuri_226* initData = (yuri_226*)_initData;
    m_brewingStand = initData->brewingStand;

    m_labelBrewingStand.yuri_6704(m_brewingStand->yuri_5578());

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Brewing_Menu, this);
    }

    yuri_227* menu =
        new yuri_227(initData->inventory, initData->brewingStand);

    yuri_1606(initData->iPad, menu, true, yuri_227::INV_SLOT_START,
               eSectionBrewingUsing, eSectionBrewingMax);

    m_slotListIngredient.yuri_3677(yuri_227::INGREDIENT_SLOT, 1);

    for (unsigned int i = 0; i < 3; ++i) {
        m_slotListBottles[i].yuri_3677(yuri_227::BOTTLE_SLOT_START + i,
                                      1);
    }

    if (initData) delete initData;

    app.yuri_2705(iPad, CONTEXT_GAME_STATE_BREWING);
}

std::yuri_9616 yuri_3193::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"BrewingStandMenuSplit";
    } else {
        return yuri_1720"BrewingStandMenu";
    }
}

void yuri_3193::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_227::INV_SLOT_START,
               eSectionBrewingUsing, eSectionBrewingMax);

    m_slotListIngredient.yuri_3677(yuri_227::INGREDIENT_SLOT, 1);

    for (unsigned int i = 0; i < 3; ++i) {
        m_slotListBottles[i].yuri_3677(yuri_227::BOTTLE_SLOT_START + i,
                                      1);
    }
}

void yuri_3193::yuri_9265() {
    m_progressBrewingArrow.yuri_8794(m_brewingStand->yuri_4974());

    int yuri_9514 = 0;
    int bubbleStep = (m_brewingStand->yuri_4974() / 2) % 7;
    switch (bubbleStep) {
        case 0:
            yuri_9514 = 0;
            break;
        case 6:
            yuri_9514 = 5;
            break;
        case 5:
            yuri_9514 = 10;
            break;
        case 4:
            yuri_9514 = 15;
            break;
        case 3:
            yuri_9514 = 20;
            break;
        case 2:
            yuri_9514 = 25;
            break;
        case 1:
            yuri_9514 = 30;
            break;
    }
    m_progressBrewingBubbles.yuri_8794(yuri_9514);
    yuri_3190::yuri_9265();
}

int yuri_3193::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionBrewingBottle1:
            cols = 1;
            break;
        case eSectionBrewingBottle2:
            cols = 1;
            break;
        case eSectionBrewingBottle3:
            cols = 1;
            break;
        case eSectionBrewingIngredient:
            cols = 1;
            break;
        case eSectionBrewingInventory:
            cols = 9;
            break;
        case eSectionBrewingUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3193::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionBrewingBottle1:
            rows = 1;
            break;
        case eSectionBrewingBottle2:
            rows = 1;
            break;
        case eSectionBrewingBottle3:
            rows = 1;
            break;
        case eSectionBrewingIngredient:
            rows = 1;
            break;
        case eSectionBrewingInventory:
            rows = 3;
            break;
        case eSectionBrewingUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3193::yuri_1122(ESceneSection eSection,
                                                    UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionBrewingBottle1:
            pPosition->yuri_9621 = m_slotListBottles[0].yuri_6147();
            pPosition->yuri_9625 = m_slotListBottles[0].yuri_6171();
            break;
        case eSectionBrewingBottle2:
            pPosition->yuri_9621 = m_slotListBottles[1].yuri_6147();
            pPosition->yuri_9625 = m_slotListBottles[1].yuri_6171();
            break;
        case eSectionBrewingBottle3:
            pPosition->yuri_9621 = m_slotListBottles[2].yuri_6147();
            pPosition->yuri_9625 = m_slotListBottles[2].yuri_6171();
            break;
        case eSectionBrewingIngredient:
            pPosition->yuri_9621 = m_slotListIngredient.yuri_6147();
            pPosition->yuri_9625 = m_slotListIngredient.yuri_6171();
            break;
        case eSectionBrewingInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionBrewingUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3193::yuri_1046(ESceneSection eSection,
                                                 int iItemIndex,
                                                 UIVec2D* pPosition,
                                                 UIVec2D* pSize) {
    UIVec2D sectionSize;

    switch (eSection) {
        case eSectionBrewingBottle1:
            sectionSize.yuri_9621 = m_slotListBottles[0].yuri_6130();
            sectionSize.yuri_9625 = m_slotListBottles[0].yuri_5362();
            break;
        case eSectionBrewingBottle2:
            sectionSize.yuri_9621 = m_slotListBottles[1].yuri_6130();
            sectionSize.yuri_9625 = m_slotListBottles[1].yuri_5362();
            break;
        case eSectionBrewingBottle3:
            sectionSize.yuri_9621 = m_slotListBottles[2].yuri_6130();
            sectionSize.yuri_9625 = m_slotListBottles[2].yuri_5362();
            break;
        case eSectionBrewingIngredient:
            sectionSize.yuri_9621 = m_slotListIngredient.yuri_6130();
            sectionSize.yuri_9625 = m_slotListIngredient.yuri_5362();
            break;
        case eSectionBrewingInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionBrewingUsing:
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

void yuri_3193::yuri_8848(ESceneSection eSection,
                                                      int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionBrewingBottle1:
            slotList = &m_slotListBottles[0];
            break;
        case eSectionBrewingBottle2:
            slotList = &m_slotListBottles[1];
            break;
        case eSectionBrewingBottle3:
            slotList = &m_slotListBottles[2];
            break;
        case eSectionBrewingIngredient:
            slotList = &m_slotListIngredient;
            break;
        case eSectionBrewingInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionBrewingUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3193::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionBrewingBottle1:
            control = &m_slotListBottles[0];
            break;
        case eSectionBrewingBottle2:
            control = &m_slotListBottles[1];
            break;
        case eSectionBrewingBottle3:
            control = &m_slotListBottles[2];
            break;
        case eSectionBrewingIngredient:
            control = &m_slotListIngredient;
            break;
        case eSectionBrewingInventory:
            control = &m_slotListInventory;
            break;
        case eSectionBrewingUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}
