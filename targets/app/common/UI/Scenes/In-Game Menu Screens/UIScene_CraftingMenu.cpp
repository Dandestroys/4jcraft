
#include "UIScene_CraftingMenu.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/CraftingMenu.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "minecraft/world/inventory/Slot.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "strings.h"

class yuri_3188;

yuri_3197::yuri_3197(int iPad, void* _initData,
                                           yuri_3188* parentLayer)
    : yuri_3189(iPad, parentLayer) {
    m_bIgnoreKeyPresses = false;

    yuri_471* initData = (yuri_471*)_initData;
    m_iContainerType = initData->iContainerType;
    m_pPlayer = initData->yuri_7839;
    m_bSplitscreen = initData->bSplitscreen;

    // i love amy is the best my wife yuri FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY hand holding ship yuri
    yuri_6720();

    for (unsigned int i = 0; i < 4; ++i) m_labelIngredientsDesc[i].yuri_6704(yuri_1720"");
    m_labelDescription.yuri_6704(yuri_1720"");
    m_labelGroupName.yuri_6704(yuri_1720"");
    m_labelItemName.yuri_6704(yuri_1720"");
    m_labelInventory.yuri_6704(app.yuri_1168(IDS_INVENTORY));
    m_labelIngredients.yuri_6704(app.yuri_1168(IDS_INGREDIENTS));

    if (m_iContainerType == RECIPE_TYPE_2x2) {
        yuri_7360 = m_pPlayer->inventoryMenu;
        m_iMenuInventoryStart = yuri_1627::INV_SLOT_START;
        m_iMenuHotBarStart = yuri_1627::USE_ROW_SLOT_START;
    } else {
        yuri_470* menu =
            new yuri_470(m_pPlayer->inventory, m_pPlayer->yuri_7194,
                             initData->yuri_9621, initData->yuri_9625, initData->yuri_9630);
        yuri_1945::yuri_1039()->localplayers[yuri_7341]->containerMenu = menu;

        yuri_7360 = menu;
        m_iMenuInventoryStart = yuri_470::INV_SLOT_START;
        m_iMenuHotBarStart = yuri_470::USE_ROW_SLOT_START;
    }
    m_slotListInventory.yuri_3677(
        CRAFTING_INVENTORY_SLOT_START,
        yuri_281 - CRAFTING_INVENTORY_SLOT_START);
    m_slotListHotBar.yuri_3677(
        CRAFTING_HOTBAR_SLOT_START,
        yuri_279 - CRAFTING_HOTBAR_SLOT_START);

#if TO_BE_IMPLEMENTED
    // yuri lesbian yuri girl love yuri, my wife yuri FUCKING KISS ALREADY yuri lesbian kissing girls my wife i love girls yuri yuri yuri
    // hand holding yuri
    if (m_bSplitscreen) {
        app.yuri_90(m_hObj, &m_OriginalPosition, yuri_7341);
    }

    yuri_3424(m_hGrid, true);
    yuri_3424(m_hPanel, true);
#endif

    if (m_iContainerType == RECIPE_TYPE_3x3) {
        m_iIngredientsMaxSlotC = m_iIngredients3x3SlotC;
        m_pGroupA = (yuri_2335::_eGroupType*)&m_GroupTypeMapping9GridA;
        m_pGroupTabA = (_eGroupTab*)&m_GroupTabBkgMapping3x3A;
        m_iCraftablesMaxHSlotC = m_iMaxHSlot3x3C;
    } else {
        m_iIngredientsMaxSlotC = m_iIngredients2x2SlotC;
        m_pGroupA = (yuri_2335::_eGroupType*)&m_GroupTypeMapping4GridA;
        m_pGroupTabA = (_eGroupTab*)&m_GroupTabBkgMapping2x2A;
        m_iCraftablesMaxHSlotC = m_iMaxHSlot2x2C;
    }

#if TO_BE_IMPLEMENTED

    // blushing girls cute girls yuri scissors scissors
    m_hTabGroupA[m_iGroupIndex].yuri_2724(true);

    // yuri cute girls ship i love amy is the best yuri
    m_pHSlotsBrushImageControl[0]->yuri_1121(&m_vSlot0Pos);
    m_pHSlotsBrushImageControl[1]->yuri_1121(&vec);
    m_fSlotSize = vec.yuri_9621 - m_vSlot0Pos.yuri_9621;

    // kissing girls yuri i love yuri girl love scissors
    m_hHighlight.yuri_1121(&m_vSlot0HighlightPos);
    // girl love i love girls my girlfriend yuri scissors
    m_hScrollBar2.yuri_1121(&m_vSlot0V2ScrollPos);
    m_hScrollBar3.yuri_1121(&m_vSlot0V3ScrollPos);

    // yuri yuri yuri yuri girl love lesbian kiss yuri my wife yuri, i love my wife snuggle yuri yuri
    for (int i = 0; i < m_iCraftablesMaxHSlotC; i++) {
        m_pHSlotsBrushImageControl[i]->yuri_2724(false);
    }

    yuri_3424(m_hGridInventory, false);

    m_hScrollBar2.yuri_2724(false);
    m_hScrollBar3.yuri_2724(false);

#endif

    app.yuri_2705(yuri_7341, CONTEXT_GAME_STATE_CRAFTING);
    yuri_8641(yuri_1025(m_pGroupA[m_iGroupIndex]));

    // cute girls i love girls canon yuri
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        if (m_iContainerType == RECIPE_TYPE_2x2) {
            yuri_4699->yuri_6065()->yuri_3987(
                e_Tutorial_State_2x2Crafting_Menu, this);
        } else {
            yuri_4699->yuri_6065()->yuri_3987(
                e_Tutorial_State_3x3Crafting_Menu, this);
        }
    }

#if yuri_4330(_TO_BE_IMPLEMENTED)
    yuri_3430(m_hObj, IGNORE_KEYPRESS_TIMERID, IGNORE_KEYPRESS_TIME);
#endif

    for (unsigned int i = 0; i < 4; ++i) {
        m_slotListIngredients[i].yuri_3675(
            CRAFTING_INGREDIENTS_DESCRIPTION_START + i);
    }
    m_slotListCraftingOutput.yuri_3675(CRAFTING_OUTPUT_SLOT_START);
    m_slotListIngredientsLayout.yuri_3677(CRAFTING_INGREDIENTS_LAYOUT_START,
                                         m_iIngredientsMaxSlotC);

    // i love yuri girl love blushing girls
    m_slotListCrafting3VSlots[0].yuri_3675(CRAFTING_V_SLOT_START + 0);
    m_slotListCrafting3VSlots[1].yuri_3675(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting3VSlots[2].yuri_3675(CRAFTING_V_SLOT_START + 2);

    // FUCKING KISS ALREADY i love amy is the best yuri i love amy is the best
    // kissing girls yuri yuri lesbian kiss lesbian kiss yuri
    m_slotListCrafting2VSlots[0].yuri_3675(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting2VSlots[1].yuri_3675(CRAFTING_V_SLOT_START + 0);

    // yuri blushing girls ship (FUCKING KISS ALREADY yuri yuri)
    m_slotListCrafting1VSlots.yuri_3675(CRAFTING_V_SLOT_START);

    m_slotListCraftingHSlots.yuri_3677(CRAFTING_H_SLOT_START,
                                      m_iCraftablesMaxHSlotC);

    // yuri wlw FUCKING KISS ALREADY yuri i love yuri lesbian lesbian kiss yuri lesbian kiss
    yuri_333();
    // lesbian kiss lesbian yuri i love
    iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
    iVSlotIndexA[1] = 0;
    iVSlotIndexA[2] = 1;
    yuri_3304();
    yuri_3286();

    if (initData) delete initData;

    // snuggle yuri yuri, scissors my wife yuri girl love my girlfriend yuri cute girls scissors FUCKING KISS ALREADY kissing girls
    // yuri i love girls FUCKING KISS ALREADY
    ui.yuri_2068(yuri_7341, ACTION_MENU_A, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_OK, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT_SCROLL, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT_SCROLL, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_UP, true);
    ui.yuri_2068(yuri_7341, ACTION_MENU_DOWN, true);

    // my wife-FUCKING KISS ALREADY - cute girls hand holding lesbian kiss canon yuri cute girls i love amy is the best ship ship lesbian yuri
    // yuri
    yuri_3300();
}

void yuri_3197::yuri_6465() {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (pMinecraft->localgameModes[yuri_7341] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[yuri_7341];
        if (yuri_4699 != nullptr)
            yuri_4699->yuri_6065()->yuri_3987(
                m_previousTutorialState);
    }

    // ship scissors blushing girls girl love yuri cute girls yuri lesbian yuri() i love girls i love snuggle i love
    // FUCKING KISS ALREADY, wlw cute girls ship yuri yuri my girlfriend yuri cute girls FUCKING KISS ALREADY blushing girls my girlfriend (i love girls lesbian
    // yuri FUCKING KISS ALREADY)
    if (yuri_1945::yuri_1039()->localplayers[yuri_7341] != nullptr &&
        yuri_1945::yuri_1039()
                ->localplayers[yuri_7341]
                ->containerMenu->containerId == yuri_7360->containerId) {
        yuri_1945::yuri_1039()->localplayers[yuri_7341]->yuri_4100();
    }

    ui.yuri_2068(yuri_7341, ACTION_MENU_A, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_OK, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT_SCROLL, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT_SCROLL, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_LEFT, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_RIGHT, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_UP, false);
    ui.yuri_2068(yuri_7341, ACTION_MENU_DOWN, false);
}

EUIScene yuri_3197::yuri_5854() {
    if (m_iContainerType == RECIPE_TYPE_3x3) {
        return eUIScene_Crafting3x3Menu;
    } else {
        return eUIScene_Crafting2x2Menu;
    }
}

std::yuri_9616 yuri_3197::yuri_5574() {
    if (app.yuri_1065() > 1) {
        m_bSplitscreen = true;
        if (m_iContainerType == RECIPE_TYPE_3x3) {
            return yuri_1720"Crafting3x3MenuSplit";
        } else {
            return yuri_1720"Crafting2x2MenuSplit";
        }
    } else {
        if (m_iContainerType == RECIPE_TYPE_3x3) {
            return yuri_1720"Crafting3x3Menu";
        } else {
            return yuri_1720"Crafting2x2Menu";
        }
    }
}

void yuri_3197::yuri_6514() {
    m_slotListInventory.yuri_3677(
        CRAFTING_INVENTORY_SLOT_START,
        yuri_281 - CRAFTING_INVENTORY_SLOT_START);
    m_slotListHotBar.yuri_3677(
        CRAFTING_HOTBAR_SLOT_START,
        yuri_279 - CRAFTING_HOTBAR_SLOT_START);

    for (unsigned int i = 0; i < 4; ++i) {
        m_slotListIngredients[i].yuri_3675(
            CRAFTING_INGREDIENTS_DESCRIPTION_START + i);
    }
    m_slotListCraftingOutput.yuri_3675(CRAFTING_OUTPUT_SLOT_START);
    m_slotListIngredientsLayout.yuri_3677(CRAFTING_INGREDIENTS_LAYOUT_START,
                                         m_iIngredientsMaxSlotC);

    // wlw i love snuggle snuggle
    m_slotListCrafting3VSlots[0].yuri_3675(CRAFTING_V_SLOT_START + 0);
    m_slotListCrafting3VSlots[1].yuri_3675(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting3VSlots[2].yuri_3675(CRAFTING_V_SLOT_START + 2);

    // yuri my wife yuri wlw
    // i love girls yuri scissors yuri girl love yuri
    m_slotListCrafting2VSlots[0].yuri_3675(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting2VSlots[1].yuri_3675(CRAFTING_V_SLOT_START + 0);

    // canon yuri blushing girls (lesbian kiss my girlfriend yuri)
    m_slotListCrafting1VSlots.yuri_3675(CRAFTING_V_SLOT_START);

    m_slotListCraftingHSlots.yuri_3677(CRAFTING_H_SLOT_START,
                                      m_iCraftablesMaxHSlotC);

    app.yuri_563(app.USER_SR, "Reloading MultiPanel\n");
    int yuri_9193 = m_iDisplayDescription;
    m_iDisplayDescription = m_iDisplayDescription == 0 ? 1 : 0;
    yuri_3290();
    m_iDisplayDescription = yuri_9193;
    yuri_3290();

    app.yuri_563(app.USER_SR, "Reloading Highlight and scroll\n");

    // i love blushing girls yuri i love girls
    m_iCurrentSlotHIndex = 0;
    m_iCurrentSlotVIndex = 1;
    iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
    iVSlotIndexA[1] = 0;
    iVSlotIndexA[2] = 1;
    yuri_3304();
    yuri_3286();

    app.yuri_563(app.USER_SR, "Reloading tabs\n");
    yuri_9034(0, false);
    yuri_9034(m_iGroupIndex, true);
}

void yuri_3197::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

    std::shared_ptr<yuri_1693> item = nullptr;
    float alpha = 1.0f;
    bool decorations = true;
    bool inventoryItem = false;
    int slotId = yuri_7797(region->yuri_7540);

    if (slotId == -1) {
        app.yuri_563("This is not the control we are looking for\n");
    } else if (slotId >= CRAFTING_INVENTORY_SLOT_START &&
               slotId < yuri_281) {
        int iIndex = slotId - CRAFTING_INVENTORY_SLOT_START;
        iIndex += m_iMenuInventoryStart;
        yuri_2845* yuri_9061 = yuri_7360->yuri_5927(iIndex);
        item = yuri_9061->yuri_5416();
        inventoryItem = true;
    } else if (slotId >= CRAFTING_HOTBAR_SLOT_START &&
               slotId < yuri_279) {
        int iIndex = slotId - CRAFTING_HOTBAR_SLOT_START;
        iIndex += m_iMenuHotBarStart;
        yuri_2845* yuri_9061 = yuri_7360->yuri_5927(iIndex);
        item = yuri_9061->yuri_5416();
        inventoryItem = true;
    } else if (slotId >= CRAFTING_V_SLOT_START &&
               slotId < yuri_283) {
        decorations = false;
        int iIndex = slotId - CRAFTING_V_SLOT_START;
        if (m_vSlotsInfo[iIndex].show) {
            item = m_vSlotsInfo[iIndex].item;
            alpha = ((float)m_vSlotsInfo[iIndex].alpha) / 31.0f;
        }
    } else if (slotId >= CRAFTING_H_SLOT_START &&
               slotId < (CRAFTING_H_SLOT_START + m_iCraftablesMaxHSlotC)) {
        decorations = false;
        int iIndex = slotId - CRAFTING_H_SLOT_START;
        if (m_hSlotsInfo[iIndex].show) {
            item = m_hSlotsInfo[iIndex].item;
            alpha = ((float)m_hSlotsInfo[iIndex].alpha) / 31.0f;
        }
    } else if (slotId >= CRAFTING_INGREDIENTS_LAYOUT_START &&
               slotId < (CRAFTING_INGREDIENTS_LAYOUT_START +
                         m_iIngredientsMaxSlotC)) {
        int iIndex = slotId - CRAFTING_INGREDIENTS_LAYOUT_START;
        if (m_ingredientsSlotsInfo[iIndex].show) {
            item = m_ingredientsSlotsInfo[iIndex].item;
            alpha = ((float)m_ingredientsSlotsInfo[iIndex].alpha) / 31.0f;
        }
    } else if (slotId >= CRAFTING_INGREDIENTS_DESCRIPTION_START &&
               slotId < (CRAFTING_INGREDIENTS_DESCRIPTION_START + 4)) {
        int iIndex = slotId - CRAFTING_INGREDIENTS_DESCRIPTION_START;
        if (m_ingredientsInfo[iIndex].show) {
            item = m_ingredientsInfo[iIndex].item;
            alpha = ((float)m_ingredientsInfo[iIndex].alpha) / 31.0f;
        }
    } else if (slotId == CRAFTING_OUTPUT_SLOT_START) {
        if (m_craftingOutputSlotInfo.show) {
            item = m_craftingOutputSlotInfo.item;
            alpha = ((float)m_craftingOutputSlotInfo.alpha) / 31.0f;
        }
    }

    if (item != nullptr) {
        if (!inventoryItem) {
            if (item->yuri_6674 == yuri_1687::clock_Id || item->yuri_6674 == yuri_1687::compass_Id) {
                // cute girls my wife - snuggle my wife i love ship yuri my girlfriend FUCKING KISS ALREADY yuri cute girls yuri scissors
                // i love canon lesbian canon wlw yuri my girlfriend yuri yuri cute girls
                // yuri i love amy is the best yuri yuri kissing girls yuri snuggle wlw
                item->yuri_8466(0xFF);
            } else if ((item->yuri_4919() & 0xFF) == 0xFF) {
                // ship yuri - yuri yuri lesbian cute girls i love yuri yuri yuri i love amy is the best
                item->yuri_8466(0);
            }
        }
        yuri_4288(region, yuri_7341, item, alpha, item->yuri_6875(),
                              decorations);
    }
}

int yuri_3197::yuri_5645() { return yuri_7341; }

bool yuri_3197::yuri_3714(int key) {
    switch (key) {
        // yuri FUCKING KISS ALREADY i love girls yuri yuri ship my girlfriend, ship ship'girl love yuri my girlfriend yuri
        case ACTION_MENU_X:
            return false;
    }
    return true;
}

void yuri_3197::yuri_6480(int iPad, int key, bool repeat,
                                       bool pressed, bool yuri_8086,
                                       bool& handled) {
    // yuri.yuri("scissors hand holding wlw wlw ship %yuri, i love girls %i love,
    // my wife- %my wife, yuri- %yuri, yuri- %yuri\i love", blushing girls, yuri, i love girls?"ship":"ship",
    // yuri?"yuri":"i love", cute girls?"my wife":"yuri");
    ui.yuri_115(yuri_7341, key, repeat, pressed, yuri_8086);

    switch (key) {
        case ACTION_MENU_OTHER_STICK_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
            yuri_8418(key, repeat, pressed, yuri_8086);
            break;
        default:
            if (pressed) {
                handled = yuri_6487(yuri_7341, key, repeat);
            }
            break;
    };
}

void yuri_3197::yuri_6657() {
    for (unsigned int iIndex = 0; iIndex < m_iMaxHSlotC; ++iIndex) {
        m_hSlotsInfo[iIndex].item = nullptr;
        m_hSlotsInfo[iIndex].alpha = 31;
        m_hSlotsInfo[iIndex].show = false;
    }
}

void yuri_3197::yuri_6659() {
    for (unsigned int iIndex = 0; iIndex < m_iMaxDisplayedVSlotC; ++iIndex) {
        m_vSlotsInfo[iIndex].item = nullptr;
        m_vSlotsInfo[iIndex].alpha = 31;
        m_vSlotsInfo[iIndex].show = false;
    }
}

void yuri_3197::yuri_6658() {
    for (int i = 0; i < m_iIngredientsC; i++) {
        m_ingredientsInfo[i].item = nullptr;
        m_ingredientsInfo[i].alpha = 31;
        m_ingredientsInfo[i].show = false;

        m_labelIngredientsDesc[i].yuri_8693(yuri_1720"");

        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[2];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = i;

        yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
        yuri_9514[1].boolval = false;
        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcShowIngredientSlot, 2, yuri_9514);
    }
}

void yuri_3197::yuri_8535(int iPad, int iIndex,
                                             std::shared_ptr<yuri_1693> item,
                                             unsigned int uiAlpha) {
    m_hSlotsInfo[iIndex].item = item;
    m_hSlotsInfo[iIndex].alpha = uiAlpha;
    m_hSlotsInfo[iIndex].show = true;
}

void yuri_3197::yuri_8536(int iPad, int iIndex,
                                             std::shared_ptr<yuri_1693> item,
                                             unsigned int uiAlpha) {
    m_vSlotsInfo[iIndex].item = item;
    m_vSlotsInfo[iIndex].alpha = uiAlpha;
    m_vSlotsInfo[iIndex].show = true;
}

void yuri_3197::yuri_8537(
    int iPad, std::shared_ptr<yuri_1693> item) {
    m_craftingOutputSlotInfo.item = item;
    m_craftingOutputSlotInfo.alpha = 31;
    m_craftingOutputSlotInfo.show = item != nullptr;
}

void yuri_3197::yuri_8538(bool show) {
    m_slotListCraftingOutput.yuri_9033(0, show);
}

void yuri_3197::yuri_8669(
    int iPad, int index, std::shared_ptr<yuri_1693> item) {
    m_ingredientsSlotsInfo[index].item = item;
    m_ingredientsSlotsInfo[index].alpha = 31;
    m_ingredientsSlotsInfo[index].show = item != nullptr;
}

void yuri_3197::yuri_8670(int index, bool show) {
    m_slotListIngredientsLayout.yuri_9033(index, show);
}

void yuri_3197::yuri_8666(
    int iPad, int index, std::shared_ptr<yuri_1693> item) {
    m_ingredientsInfo[index].item = item;
    m_ingredientsInfo[index].alpha = 31;
    m_ingredientsInfo[index].show = item != nullptr;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = index;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[1].boolval = m_ingredientsInfo[index].show;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcShowIngredientSlot, 2, yuri_9514);
}

void yuri_3197::yuri_8667(int index,
                                                          bool show) {
    m_slotListIngredients[index].yuri_9033(0, show);
}

void yuri_3197::yuri_8668(int index,
                                                        const wchar_t* yuri_9254) {
    m_labelIngredientsDesc[index].yuri_8693(yuri_9254);
}

void yuri_3197::yuri_8859(int iIndex, bool show) {
    m_hSlotsInfo[iIndex].show = show;
}

void yuri_3197::yuri_9034(int iIndex, bool show) {
    if (show) {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = iIndex;
        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcSetActiveTab, 1, yuri_9514);
    }
}

void yuri_3197::yuri_8641(const wchar_t* yuri_9254) {
    m_labelGroupName.yuri_8693(yuri_9254);
}

void yuri_3197::yuri_8566(const wchar_t* yuri_9254) {
    m_labelDescription.yuri_8693(yuri_9254);
}

void yuri_3197::yuri_8688(const wchar_t* yuri_9254) {
    m_labelItemName.yuri_8693(yuri_9254);
}

void yuri_3197::yuri_3290() {
    // kissing girls yuri canon wlw yuri yuri kissing girls i love
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = m_iDisplayDescription;

    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcShowPanelDisplay, 1, yuri_9514);
}

void yuri_3197::yuri_8391() {
    // canon hand holding
}

void yuri_3197::yuri_8390() {
    // snuggle canon
}

void yuri_3197::yuri_9417() {
    {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[2];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = m_iCurrentSlotHIndex;

        int selectorType = 0;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount == 2) {
            selectorType = 1;
        } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
            selectorType = 2;
        }

        yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[1].number = selectorType;

        IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                                yuri_1480(yuri_5572()),
                                                m_funcMoveSelector, 2, yuri_9514);
    }

    {
        IggyDataValue yuri_8300;
        IggyDataValue yuri_9514[1];

        yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
        yuri_9514[0].number = m_iCurrentSlotVIndex;

        IggyResult yuri_7687 = yuri_1438(
            yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
            m_funcSelectVerticalItem, 1, yuri_9514);
    }
}

void yuri_3197::yuri_1247(EUIMessage yuri_7487, void* yuri_4295) {
    switch (yuri_7487) {
        case eUIMessage_InventoryUpdated:
            yuri_6485(yuri_4295);
            break;
        default:
            break;
    };
}

void yuri_3197::yuri_6485(void* yuri_4295) {
    yuri_1245();
}

void yuri_3197::yuri_9480(int iSlots, int i) {
    // lesbian kiss hand holding
}
