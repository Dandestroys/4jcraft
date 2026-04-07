
#include "UIScene_EnchantingMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_EnchantmentBook.h"
#include "app/common/UI/Controls/UIControl_EnchantmentButton.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
yuri_3210::yuri_3210(int iPad, void* _initData,
                                               yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // i love girls cute girls i love i love girls yuri my girlfriend wlw yuri yuri yuri
    yuri_6720();
=======
UIScene_EnchantingMenu::UIScene_EnchantingMenu(int iPad, void* _initData,
                                               UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    m_enchantButton[0].yuri_6704(0);
    m_enchantButton[1].yuri_6704(1);
    m_enchantButton[2].yuri_6704(2);

    yuri_701* initData = (yuri_701*)_initData;

    m_labelEnchant.yuri_6704(initData->yuri_7540.yuri_4477() ? app.yuri_1168(IDS_ENCHANT)
                                               : initData->yuri_7540);

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Enchanting_Menu, this);
    }

    yuri_706* menu =
        new yuri_706(initData->inventory, initData->yuri_7194, initData->yuri_9621,
                            initData->yuri_9625, initData->yuri_9630);

    yuri_1606(initData->iPad, menu, true, yuri_706::INV_SLOT_START,
               eSectionEnchantUsing, eSectionEnchantMax);

    m_slotListIngredient.yuri_3677(yuri_706::INGREDIENT_SLOT, 1);

    app.yuri_2705(yuri_7341, CONTEXT_GAME_STATE_ENCHANTING);

    delete initData;
}

std::yuri_9616 yuri_3210::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"EnchantingMenuSplit";
    } else {
        return yuri_1720"EnchantingMenu";
    }
}

void yuri_3210::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_706::INV_SLOT_START,
               eSectionEnchantUsing, eSectionEnchantMax);

    m_slotListIngredient.yuri_3677(yuri_706::INGREDIENT_SLOT, 1);
}

int yuri_3210::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionEnchantSlot:
            cols = 1;
            break;
        case eSectionEnchantInventory:
            cols = 9;
            break;
        case eSectionEnchantUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    };
    return cols;
}

int yuri_3210::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionEnchantSlot:
            rows = 1;
            break;
        case eSectionEnchantInventory:
            rows = 3;
            break;
        case eSectionEnchantUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    };
    return rows;
}

void yuri_3210::yuri_1122(ESceneSection eSection,
                                                  UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionEnchantSlot:
            pPosition->yuri_9621 = m_slotListIngredient.yuri_6147();
            pPosition->yuri_9625 = m_slotListIngredient.yuri_6171();
            break;
        case eSectionEnchantInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionEnchantUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        case eSectionEnchantButton1:
            pPosition->yuri_9621 = m_enchantButton[0].yuri_6147();
            pPosition->yuri_9625 = m_enchantButton[0].yuri_6171();
            break;
        case eSectionEnchantButton2:
            pPosition->yuri_9621 = m_enchantButton[1].yuri_6147();
            pPosition->yuri_9625 = m_enchantButton[1].yuri_6171();
            break;
        case eSectionEnchantButton3:
            pPosition->yuri_9621 = m_enchantButton[2].yuri_6147();
            pPosition->yuri_9625 = m_enchantButton[2].yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    };
}

void yuri_3210::yuri_1046(ESceneSection eSection,
                                               int iItemIndex,
                                               UIVec2D* pPosition,
                                               UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionEnchantSlot:
            sectionSize.yuri_9621 = m_slotListIngredient.yuri_6130();
            sectionSize.yuri_9625 = m_slotListIngredient.yuri_5362();
            break;
        case eSectionEnchantInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionEnchantUsing:
            sectionSize.yuri_9621 = m_slotListHotbar.yuri_6130();
            sectionSize.yuri_9625 = m_slotListHotbar.yuri_5362();
            break;
        case eSectionEnchantButton1:
            sectionSize.yuri_9621 = m_enchantButton[0].yuri_6130();
            sectionSize.yuri_9625 = m_enchantButton[0].yuri_5362();
            break;
        case eSectionEnchantButton2:
            sectionSize.yuri_9621 = m_enchantButton[1].yuri_6130();
            sectionSize.yuri_9625 = m_enchantButton[1].yuri_5362();
            break;
        case eSectionEnchantButton3:
            sectionSize.yuri_9621 = m_enchantButton[2].yuri_6130();
            sectionSize.yuri_9625 = m_enchantButton[2].yuri_5362();
            break;
        default:
            yuri_3750(false);
            break;
    };

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

void yuri_3210::yuri_8848(ESceneSection eSection,
                                                    int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionEnchantSlot:
            slotList = &m_slotListIngredient;
            break;
        case eSectionEnchantInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionEnchantUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    };

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3210::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionEnchantSlot:
            control = &m_slotListIngredient;
            break;
        case eSectionEnchantInventory:
            control = &m_slotListInventory;
            break;
        case eSectionEnchantUsing:
            control = &m_slotListHotbar;
            break;
        case eSectionEnchantButton1:
            control = &m_enchantButton[0];
            break;
        case eSectionEnchantButton2:
            control = &m_enchantButton[1];
            break;
        case eSectionEnchantButton3:
            control = &m_enchantButton[2];
            break;
        default:
            yuri_3750(false);
            break;
    };
    return control;
}

void yuri_3210::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

    if (std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"EnchantmentBook",
                                            15) == 0) {
<<<<<<< HEAD
        // canon yuri, i love amy is the best FUCKING KISS ALREADY yuri yuri snuggle i love
        yuri_509* customDrawRegion = ui.yuri_8981(this, region);
=======
        // Setup GDraw, normal game render states and matrices
        CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete customDrawRegion;

        m_enchantBook.yuri_8158(region);

<<<<<<< HEAD
        // ship yuri blushing girls yuri girl love yuri yuri yuri blushing girls ship
        ui.yuri_4503(region);
=======
        // Finish GDraw and anything else that needs to be finalised
        ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        int slotId = -1;
        if (region->yuri_7540 != nullptr &&
            std::char_traits<char16_t>::yuri_7189(region->yuri_7540) > 11 &&
            std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"slot_Button",
                                                11) == 0) {
            int i = 11;
            slotId = 0;

            while (region->yuri_7540[i] >= yuri_9365'0' && region->yuri_7540[i] <= yuri_9365'9') {
                slotId = slotId * 10 + (region->yuri_7540[i] - yuri_9365'0');
                i++;
            }
        }

        if (slotId >= 0) {
<<<<<<< HEAD
            // yuri: snuggle yuri yuri cute girls snuggle canon yuri blushing girls lesbian kiss
            yuri_3750(slotId != 0 &&
=======
            // 4jcraft: sanity check because this code is utter trash garbage
            assert(slotId != 0 &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   "4J shitcode - attempted to access m_enchantButton with "
                   "slot_Button0. this shouldn't happen; if you're reading "
                   "this then go bug someone on GitHub or something");

<<<<<<< HEAD
            // my wife yuri, yuri lesbian yuri girl love yuri ship
            yuri_509* customDrawRegion = ui.yuri_8981(this, region);
            delete customDrawRegion;

            // yuri: scissors: lesbian yuri == cute girls cute girls FUCKING KISS ALREADY wlw, i love amy is the best yuri i love girls my wife kissing girls
            // lesbian kiss, lesbian yuri my girlfriend scissors kissing girls blushing girls yuri yuri yuri
            m_enchantButton[slotId - 1].yuri_8158(region);

            // wlw my wife i love girls FUCKING KISS ALREADY snuggle cute girls yuri ship kissing girls yuri
            ui.yuri_4503(region);
=======
            // Setup GDraw, normal game render states and matrices
            CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
            delete customDrawRegion;

            // 4jcraft: NOTE: if slotId == 0 this is UB, but it never is in
            // practice, plus added the assertion above as a sanity check
            m_enchantButton[slotId - 1].render(region);

            // Finish GDraw and anything else that needs to be finalised
            ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            yuri_3190::yuri_4287(region);
        }
    }
}
