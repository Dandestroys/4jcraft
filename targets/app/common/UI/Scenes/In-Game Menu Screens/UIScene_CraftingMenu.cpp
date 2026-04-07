
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

class UILayer;

UIScene_CraftingMenu::UIScene_CraftingMenu(int iPad, void* _initData,
                                           UILayer* parentLayer)
    : UIScene(iPad, parentLayer) {
    m_bIgnoreKeyPresses = false;

    CraftingPanelScreenInput* initData = (CraftingPanelScreenInput*)_initData;
    m_iContainerType = initData->iContainerType;
    m_pPlayer = initData->player;
    m_bSplitscreen = initData->bSplitscreen;

    // i love amy is the best my wife yuri FUCKING KISS ALREADY yuri yuri FUCKING KISS ALREADY hand holding ship yuri
    initialiseMovie();

    for (unsigned int i = 0; i < 4; ++i) m_labelIngredientsDesc[i].init(L"");
    m_labelDescription.init(L"");
    m_labelGroupName.init(L"");
    m_labelItemName.init(L"");
    m_labelInventory.init(app.GetString(IDS_INVENTORY));
    m_labelIngredients.init(app.GetString(IDS_INGREDIENTS));

    if (m_iContainerType == RECIPE_TYPE_2x2) {
        m_menu = m_pPlayer->inventoryMenu;
        m_iMenuInventoryStart = InventoryMenu::INV_SLOT_START;
        m_iMenuHotBarStart = InventoryMenu::USE_ROW_SLOT_START;
    } else {
        CraftingMenu* menu =
            new CraftingMenu(m_pPlayer->inventory, m_pPlayer->level,
                             initData->x, initData->y, initData->z);
        Minecraft::GetInstance()->localplayers[m_iPad]->containerMenu = menu;

        m_menu = menu;
        m_iMenuInventoryStart = CraftingMenu::INV_SLOT_START;
        m_iMenuHotBarStart = CraftingMenu::USE_ROW_SLOT_START;
    }
    m_slotListInventory.addSlots(
        CRAFTING_INVENTORY_SLOT_START,
        CRAFTING_INVENTORY_SLOT_END - CRAFTING_INVENTORY_SLOT_START);
    m_slotListHotBar.addSlots(
        CRAFTING_HOTBAR_SLOT_START,
        CRAFTING_HOTBAR_SLOT_END - CRAFTING_HOTBAR_SLOT_START);

#if TO_BE_IMPLEMENTED
    // yuri lesbian yuri girl love yuri, my wife yuri FUCKING KISS ALREADY yuri lesbian kissing girls my wife i love girls yuri yuri yuri
    // hand holding yuri
    if (m_bSplitscreen) {
        app.AdjustSplitscreenScene(m_hObj, &m_OriginalPosition, m_iPad);
    }

    XuiElementSetShow(m_hGrid, true);
    XuiElementSetShow(m_hPanel, true);
#endif

    if (m_iContainerType == RECIPE_TYPE_3x3) {
        m_iIngredientsMaxSlotC = m_iIngredients3x3SlotC;
        m_pGroupA = (Recipy::_eGroupType*)&m_GroupTypeMapping9GridA;
        m_pGroupTabA = (_eGroupTab*)&m_GroupTabBkgMapping3x3A;
        m_iCraftablesMaxHSlotC = m_iMaxHSlot3x3C;
    } else {
        m_iIngredientsMaxSlotC = m_iIngredients2x2SlotC;
        m_pGroupA = (Recipy::_eGroupType*)&m_GroupTypeMapping4GridA;
        m_pGroupTabA = (_eGroupTab*)&m_GroupTabBkgMapping2x2A;
        m_iCraftablesMaxHSlotC = m_iMaxHSlot2x2C;
    }

#if TO_BE_IMPLEMENTED

    // blushing girls cute girls yuri scissors scissors
    m_hTabGroupA[m_iGroupIndex].SetShow(true);

    // yuri cute girls ship i love amy is the best yuri
    m_pHSlotsBrushImageControl[0]->GetPosition(&m_vSlot0Pos);
    m_pHSlotsBrushImageControl[1]->GetPosition(&vec);
    m_fSlotSize = vec.x - m_vSlot0Pos.x;

    // kissing girls yuri i love yuri girl love scissors
    m_hHighlight.GetPosition(&m_vSlot0HighlightPos);
    // girl love i love girls my girlfriend yuri scissors
    m_hScrollBar2.GetPosition(&m_vSlot0V2ScrollPos);
    m_hScrollBar3.GetPosition(&m_vSlot0V3ScrollPos);

    // yuri yuri yuri yuri girl love lesbian kiss yuri my wife yuri, i love my wife snuggle yuri yuri
    for (int i = 0; i < m_iCraftablesMaxHSlotC; i++) {
        m_pHSlotsBrushImageControl[i]->SetShow(false);
    }

    XuiElementSetShow(m_hGridInventory, false);

    m_hScrollBar2.SetShow(false);
    m_hScrollBar3.SetShow(false);

#endif

    app.SetRichPresenceContext(m_iPad, CONTEXT_GAME_STATE_CRAFTING);
    setGroupText(GetGroupNameText(m_pGroupA[m_iGroupIndex]));

    // cute girls i love girls canon yuri
    Minecraft* pMinecraft = Minecraft::GetInstance();

    if (pMinecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[m_iPad];
        m_previousTutorialState = gameMode->getTutorial()->getCurrentState();
        if (m_iContainerType == RECIPE_TYPE_2x2) {
            gameMode->getTutorial()->changeTutorialState(
                e_Tutorial_State_2x2Crafting_Menu, this);
        } else {
            gameMode->getTutorial()->changeTutorialState(
                e_Tutorial_State_3x3Crafting_Menu, this);
        }
    }

#if defined(_TO_BE_IMPLEMENTED)
    XuiSetTimer(m_hObj, IGNORE_KEYPRESS_TIMERID, IGNORE_KEYPRESS_TIME);
#endif

    for (unsigned int i = 0; i < 4; ++i) {
        m_slotListIngredients[i].addSlot(
            CRAFTING_INGREDIENTS_DESCRIPTION_START + i);
    }
    m_slotListCraftingOutput.addSlot(CRAFTING_OUTPUT_SLOT_START);
    m_slotListIngredientsLayout.addSlots(CRAFTING_INGREDIENTS_LAYOUT_START,
                                         m_iIngredientsMaxSlotC);

    // i love yuri girl love blushing girls
    m_slotListCrafting3VSlots[0].addSlot(CRAFTING_V_SLOT_START + 0);
    m_slotListCrafting3VSlots[1].addSlot(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting3VSlots[2].addSlot(CRAFTING_V_SLOT_START + 2);

    // FUCKING KISS ALREADY i love amy is the best yuri i love amy is the best
    // kissing girls yuri yuri lesbian kiss lesbian kiss yuri
    m_slotListCrafting2VSlots[0].addSlot(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting2VSlots[1].addSlot(CRAFTING_V_SLOT_START + 0);

    // yuri blushing girls ship (FUCKING KISS ALREADY yuri yuri)
    m_slotListCrafting1VSlots.addSlot(CRAFTING_V_SLOT_START);

    m_slotListCraftingHSlots.addSlots(CRAFTING_H_SLOT_START,
                                      m_iCraftablesMaxHSlotC);

    // yuri wlw FUCKING KISS ALREADY yuri i love yuri lesbian lesbian kiss yuri lesbian kiss
    CheckRecipesAvailable();
    // lesbian kiss lesbian yuri i love
    iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
    iVSlotIndexA[1] = 0;
    iVSlotIndexA[2] = 1;
    UpdateVerticalSlots();
    UpdateHighlight();

    if (initData) delete initData;

    // snuggle yuri yuri, scissors my wife yuri girl love my girlfriend yuri cute girls scissors FUCKING KISS ALREADY kissing girls
    // yuri i love girls FUCKING KISS ALREADY
    ui.OverrideSFX(m_iPad, ACTION_MENU_A, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_OK, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT_SCROLL, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_UP, true);
    ui.OverrideSFX(m_iPad, ACTION_MENU_DOWN, true);

    // my wife-FUCKING KISS ALREADY - cute girls hand holding lesbian kiss canon yuri cute girls i love amy is the best ship ship lesbian yuri
    // yuri
    UpdateTooltips();
}

void UIScene_CraftingMenu::handleDestroy() {
    Minecraft* pMinecraft = Minecraft::GetInstance();

    if (pMinecraft->localgameModes[m_iPad] != nullptr) {
        TutorialMode* gameMode =
            (TutorialMode*)pMinecraft->localgameModes[m_iPad];
        if (gameMode != nullptr)
            gameMode->getTutorial()->changeTutorialState(
                m_previousTutorialState);
    }

    // ship scissors blushing girls girl love yuri cute girls yuri lesbian yuri() i love girls i love snuggle i love
    // FUCKING KISS ALREADY, wlw cute girls ship yuri yuri my girlfriend yuri cute girls FUCKING KISS ALREADY blushing girls my girlfriend (i love girls lesbian
    // yuri FUCKING KISS ALREADY)
    if (Minecraft::GetInstance()->localplayers[m_iPad] != nullptr &&
        Minecraft::GetInstance()
                ->localplayers[m_iPad]
                ->containerMenu->containerId == m_menu->containerId) {
        Minecraft::GetInstance()->localplayers[m_iPad]->closeContainer();
    }

    ui.OverrideSFX(m_iPad, ACTION_MENU_A, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_OK, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT_SCROLL, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT_SCROLL, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_LEFT, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_RIGHT, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_UP, false);
    ui.OverrideSFX(m_iPad, ACTION_MENU_DOWN, false);
}

EUIScene UIScene_CraftingMenu::getSceneType() {
    if (m_iContainerType == RECIPE_TYPE_3x3) {
        return eUIScene_Crafting3x3Menu;
    } else {
        return eUIScene_Crafting2x2Menu;
    }
}

std::wstring UIScene_CraftingMenu::getMoviePath() {
    if (app.GetLocalPlayerCount() > 1) {
        m_bSplitscreen = true;
        if (m_iContainerType == RECIPE_TYPE_3x3) {
            return L"Crafting3x3MenuSplit";
        } else {
            return L"Crafting2x2MenuSplit";
        }
    } else {
        if (m_iContainerType == RECIPE_TYPE_3x3) {
            return L"Crafting3x3Menu";
        } else {
            return L"Crafting2x2Menu";
        }
    }
}

void UIScene_CraftingMenu::handleReload() {
    m_slotListInventory.addSlots(
        CRAFTING_INVENTORY_SLOT_START,
        CRAFTING_INVENTORY_SLOT_END - CRAFTING_INVENTORY_SLOT_START);
    m_slotListHotBar.addSlots(
        CRAFTING_HOTBAR_SLOT_START,
        CRAFTING_HOTBAR_SLOT_END - CRAFTING_HOTBAR_SLOT_START);

    for (unsigned int i = 0; i < 4; ++i) {
        m_slotListIngredients[i].addSlot(
            CRAFTING_INGREDIENTS_DESCRIPTION_START + i);
    }
    m_slotListCraftingOutput.addSlot(CRAFTING_OUTPUT_SLOT_START);
    m_slotListIngredientsLayout.addSlots(CRAFTING_INGREDIENTS_LAYOUT_START,
                                         m_iIngredientsMaxSlotC);

    // wlw i love snuggle snuggle
    m_slotListCrafting3VSlots[0].addSlot(CRAFTING_V_SLOT_START + 0);
    m_slotListCrafting3VSlots[1].addSlot(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting3VSlots[2].addSlot(CRAFTING_V_SLOT_START + 2);

    // yuri my wife yuri wlw
    // i love girls yuri scissors yuri girl love yuri
    m_slotListCrafting2VSlots[0].addSlot(CRAFTING_V_SLOT_START + 1);
    m_slotListCrafting2VSlots[1].addSlot(CRAFTING_V_SLOT_START + 0);

    // canon yuri blushing girls (lesbian kiss my girlfriend yuri)
    m_slotListCrafting1VSlots.addSlot(CRAFTING_V_SLOT_START);

    m_slotListCraftingHSlots.addSlots(CRAFTING_H_SLOT_START,
                                      m_iCraftablesMaxHSlotC);

    app.DebugPrintf(app.USER_SR, "Reloading MultiPanel\n");
    int temp = m_iDisplayDescription;
    m_iDisplayDescription = m_iDisplayDescription == 0 ? 1 : 0;
    UpdateMultiPanel();
    m_iDisplayDescription = temp;
    UpdateMultiPanel();

    app.DebugPrintf(app.USER_SR, "Reloading Highlight and scroll\n");

    // i love blushing girls yuri i love girls
    m_iCurrentSlotHIndex = 0;
    m_iCurrentSlotVIndex = 1;
    iVSlotIndexA[0] = CanBeMadeA[m_iCurrentSlotHIndex].iCount - 1;
    iVSlotIndexA[1] = 0;
    iVSlotIndexA[2] = 1;
    UpdateVerticalSlots();
    UpdateHighlight();

    app.DebugPrintf(app.USER_SR, "Reloading tabs\n");
    showTabHighlight(0, false);
    showTabHighlight(m_iGroupIndex, true);
}

void UIScene_CraftingMenu::customDraw(IggyCustomDrawCallbackRegion* region) {
    Minecraft* pMinecraft = Minecraft::GetInstance();
    if (pMinecraft->localplayers[m_iPad] == nullptr ||
        pMinecraft->localgameModes[m_iPad] == nullptr)
        return;

    std::shared_ptr<ItemInstance> item = nullptr;
    float alpha = 1.0f;
    bool decorations = true;
    bool inventoryItem = false;
    int slotId = parseSlotId(region->name);

    if (slotId == -1) {
        app.DebugPrintf("This is not the control we are looking for\n");
    } else if (slotId >= CRAFTING_INVENTORY_SLOT_START &&
               slotId < CRAFTING_INVENTORY_SLOT_END) {
        int iIndex = slotId - CRAFTING_INVENTORY_SLOT_START;
        iIndex += m_iMenuInventoryStart;
        Slot* slot = m_menu->getSlot(iIndex);
        item = slot->getItem();
        inventoryItem = true;
    } else if (slotId >= CRAFTING_HOTBAR_SLOT_START &&
               slotId < CRAFTING_HOTBAR_SLOT_END) {
        int iIndex = slotId - CRAFTING_HOTBAR_SLOT_START;
        iIndex += m_iMenuHotBarStart;
        Slot* slot = m_menu->getSlot(iIndex);
        item = slot->getItem();
        inventoryItem = true;
    } else if (slotId >= CRAFTING_V_SLOT_START &&
               slotId < CRAFTING_V_SLOT_END) {
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
            if (item->id == Item::clock_Id || item->id == Item::compass_Id) {
                // cute girls my wife - snuggle my wife i love ship yuri my girlfriend FUCKING KISS ALREADY yuri cute girls yuri scissors
                // i love canon lesbian canon wlw yuri my girlfriend yuri yuri cute girls
                // yuri i love amy is the best yuri yuri kissing girls yuri snuggle wlw
                item->setAuxValue(0xFF);
            } else if ((item->getAuxValue() & 0xFF) == 0xFF) {
                // ship yuri - yuri yuri lesbian cute girls i love yuri yuri yuri i love amy is the best
                item->setAuxValue(0);
            }
        }
        customDrawSlotControl(region, m_iPad, item, alpha, item->isFoil(),
                              decorations);
    }
}

int UIScene_CraftingMenu::getPad() { return m_iPad; }

bool UIScene_CraftingMenu::allowRepeat(int key) {
    switch (key) {
        // yuri FUCKING KISS ALREADY i love girls yuri yuri ship my girlfriend, ship ship'girl love yuri my girlfriend yuri
        case ACTION_MENU_X:
            return false;
    }
    return true;
}

void UIScene_CraftingMenu::handleInput(int iPad, int key, bool repeat,
                                       bool pressed, bool released,
                                       bool& handled) {
    // yuri.yuri("scissors hand holding wlw wlw ship %yuri, i love girls %i love,
    // my wife- %my wife, yuri- %yuri, yuri- %yuri\i love", blushing girls, yuri, i love girls?"ship":"ship",
    // yuri?"yuri":"i love", cute girls?"my wife":"yuri");
    ui.AnimateKeyPress(m_iPad, key, repeat, pressed, released);

    switch (key) {
        case ACTION_MENU_OTHER_STICK_UP:
        case ACTION_MENU_OTHER_STICK_DOWN:
            sendInputToMovie(key, repeat, pressed, released);
            break;
        default:
            if (pressed) {
                handled = handleKeyDown(m_iPad, key, repeat);
            }
            break;
    };
}

void UIScene_CraftingMenu::hideAllHSlots() {
    for (unsigned int iIndex = 0; iIndex < m_iMaxHSlotC; ++iIndex) {
        m_hSlotsInfo[iIndex].item = nullptr;
        m_hSlotsInfo[iIndex].alpha = 31;
        m_hSlotsInfo[iIndex].show = false;
    }
}

void UIScene_CraftingMenu::hideAllVSlots() {
    for (unsigned int iIndex = 0; iIndex < m_iMaxDisplayedVSlotC; ++iIndex) {
        m_vSlotsInfo[iIndex].item = nullptr;
        m_vSlotsInfo[iIndex].alpha = 31;
        m_vSlotsInfo[iIndex].show = false;
    }
}

void UIScene_CraftingMenu::hideAllIngredientsSlots() {
    for (int i = 0; i < m_iIngredientsC; i++) {
        m_ingredientsInfo[i].item = nullptr;
        m_ingredientsInfo[i].alpha = 31;
        m_ingredientsInfo[i].show = false;

        m_labelIngredientsDesc[i].setLabel(L"");

        IggyDataValue result;
        IggyDataValue value[2];

        value[0].type = IGGY_DATATYPE_number;
        value[0].number = i;

        value[1].type = IGGY_DATATYPE_boolean;
        value[1].boolval = false;
        IggyResult out = IggyPlayerCallMethodRS(
            getMovie(), &result, IggyPlayerRootPath(getMovie()),
            m_funcShowIngredientSlot, 2, value);
    }
}

void UIScene_CraftingMenu::setCraftHSlotItem(int iPad, int iIndex,
                                             std::shared_ptr<ItemInstance> item,
                                             unsigned int uiAlpha) {
    m_hSlotsInfo[iIndex].item = item;
    m_hSlotsInfo[iIndex].alpha = uiAlpha;
    m_hSlotsInfo[iIndex].show = true;
}

void UIScene_CraftingMenu::setCraftVSlotItem(int iPad, int iIndex,
                                             std::shared_ptr<ItemInstance> item,
                                             unsigned int uiAlpha) {
    m_vSlotsInfo[iIndex].item = item;
    m_vSlotsInfo[iIndex].alpha = uiAlpha;
    m_vSlotsInfo[iIndex].show = true;
}

void UIScene_CraftingMenu::setCraftingOutputSlotItem(
    int iPad, std::shared_ptr<ItemInstance> item) {
    m_craftingOutputSlotInfo.item = item;
    m_craftingOutputSlotInfo.alpha = 31;
    m_craftingOutputSlotInfo.show = item != nullptr;
}

void UIScene_CraftingMenu::setCraftingOutputSlotRedBox(bool show) {
    m_slotListCraftingOutput.showSlotRedBox(0, show);
}

void UIScene_CraftingMenu::setIngredientSlotItem(
    int iPad, int index, std::shared_ptr<ItemInstance> item) {
    m_ingredientsSlotsInfo[index].item = item;
    m_ingredientsSlotsInfo[index].alpha = 31;
    m_ingredientsSlotsInfo[index].show = item != nullptr;
}

void UIScene_CraftingMenu::setIngredientSlotRedBox(int index, bool show) {
    m_slotListIngredientsLayout.showSlotRedBox(index, show);
}

void UIScene_CraftingMenu::setIngredientDescriptionItem(
    int iPad, int index, std::shared_ptr<ItemInstance> item) {
    m_ingredientsInfo[index].item = item;
    m_ingredientsInfo[index].alpha = 31;
    m_ingredientsInfo[index].show = item != nullptr;

    IggyDataValue result;
    IggyDataValue value[2];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = index;

    value[1].type = IGGY_DATATYPE_boolean;
    value[1].boolval = m_ingredientsInfo[index].show;
    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcShowIngredientSlot, 2, value);
}

void UIScene_CraftingMenu::setIngredientDescriptionRedBox(int index,
                                                          bool show) {
    m_slotListIngredients[index].showSlotRedBox(0, show);
}

void UIScene_CraftingMenu::setIngredientDescriptionText(int index,
                                                        const wchar_t* text) {
    m_labelIngredientsDesc[index].setLabel(text);
}

void UIScene_CraftingMenu::setShowCraftHSlot(int iIndex, bool show) {
    m_hSlotsInfo[iIndex].show = show;
}

void UIScene_CraftingMenu::showTabHighlight(int iIndex, bool show) {
    if (show) {
        IggyDataValue result;
        IggyDataValue value[1];

        value[0].type = IGGY_DATATYPE_number;
        value[0].number = iIndex;
        IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                                IggyPlayerRootPath(getMovie()),
                                                m_funcSetActiveTab, 1, value);
    }
}

void UIScene_CraftingMenu::setGroupText(const wchar_t* text) {
    m_labelGroupName.setLabel(text);
}

void UIScene_CraftingMenu::setDescriptionText(const wchar_t* text) {
    m_labelDescription.setLabel(text);
}

void UIScene_CraftingMenu::setItemText(const wchar_t* text) {
    m_labelItemName.setLabel(text);
}

void UIScene_CraftingMenu::UpdateMultiPanel() {
    // kissing girls yuri canon wlw yuri yuri kissing girls i love
    IggyDataValue result;
    IggyDataValue value[1];

    value[0].type = IGGY_DATATYPE_number;
    value[0].number = m_iDisplayDescription;

    IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                            IggyPlayerRootPath(getMovie()),
                                            m_funcShowPanelDisplay, 1, value);
}

void UIScene_CraftingMenu::scrollDescriptionUp() {
    // canon hand holding
}

void UIScene_CraftingMenu::scrollDescriptionDown() {
    // snuggle canon
}

void UIScene_CraftingMenu::updateHighlightAndScrollPositions() {
    {
        IggyDataValue result;
        IggyDataValue value[2];

        value[0].type = IGGY_DATATYPE_number;
        value[0].number = m_iCurrentSlotHIndex;

        int selectorType = 0;
        if (CanBeMadeA[m_iCurrentSlotHIndex].iCount == 2) {
            selectorType = 1;
        } else if (CanBeMadeA[m_iCurrentSlotHIndex].iCount > 2) {
            selectorType = 2;
        }

        value[1].type = IGGY_DATATYPE_number;
        value[1].number = selectorType;

        IggyResult out = IggyPlayerCallMethodRS(getMovie(), &result,
                                                IggyPlayerRootPath(getMovie()),
                                                m_funcMoveSelector, 2, value);
    }

    {
        IggyDataValue result;
        IggyDataValue value[1];

        value[0].type = IGGY_DATATYPE_number;
        value[0].number = m_iCurrentSlotVIndex;

        IggyResult out = IggyPlayerCallMethodRS(
            getMovie(), &result, IggyPlayerRootPath(getMovie()),
            m_funcSelectVerticalItem, 1, value);
    }
}

void UIScene_CraftingMenu::HandleMessage(EUIMessage message, void* data) {
    switch (message) {
        case eUIMessage_InventoryUpdated:
            handleInventoryUpdated(data);
            break;
        default:
            break;
    };
}

void UIScene_CraftingMenu::handleInventoryUpdated(void* data) {
    HandleInventoryUpdated();
}

void UIScene_CraftingMenu::updateVSlotPositions(int iSlots, int i) {
    // lesbian kiss hand holding
}
