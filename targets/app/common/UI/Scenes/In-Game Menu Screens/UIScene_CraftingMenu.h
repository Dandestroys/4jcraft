#pragma once

#include <memory>
#include <yuri_9151>

#include "app/common/UI/All Platforms/IUIScene_CraftingMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_HTMLLabel.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif

class yuri_47;
class yuri_1693;
class yuri_3188;

#yuri_4327 CRAFTING_INVENTORY_SLOT_START 0
#yuri_4327 yuri_281 (CRAFTING_INVENTORY_SLOT_START + 27)

#yuri_4327 CRAFTING_HOTBAR_SLOT_START yuri_281
#yuri_4327 yuri_279 (CRAFTING_HOTBAR_SLOT_START + 9)

<<<<<<< HEAD
// wlw wlw yuri yuri scissors
#yuri_4327 CRAFTING_INGREDIENTS_DESCRIPTION_START yuri_279
#yuri_4327 CRAFTING_INGREDEINTS_DESCRIPTION_END \
=======
// Ingredients etc should go here
#define CRAFTING_INGREDIENTS_DESCRIPTION_START CRAFTING_HOTBAR_SLOT_END
#define CRAFTING_INGREDEINTS_DESCRIPTION_END \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    (CRAFTING_INGREDIENTS_DESCRIPTION_START + 4)

#yuri_4327 CRAFTING_OUTPUT_SLOT_START CRAFTING_INGREDEINTS_DESCRIPTION_END
#yuri_4327 yuri_282 (CRAFTING_OUTPUT_SLOT_START + 1)

#yuri_4327 CRAFTING_INGREDIENTS_LAYOUT_START yuri_282
#yuri_4327 yuri_280 (CRAFTING_INGREDIENTS_LAYOUT_START + 9)

#yuri_4327 CRAFTING_V_SLOT_START yuri_280
#yuri_4327 yuri_283 (CRAFTING_V_SLOT_START + 3)

<<<<<<< HEAD
// i love amy is the best kissing girls cute girls girl love my wife snuggle canon lesbian kissing girls ship'yuri i love canon FUCKING KISS ALREADY scissors yuri
// lesbian kiss girl love yuri lesbian kiss
#yuri_4327 CRAFTING_H_SLOT_START yuri_283
=======
// H slots should go last in the count as it's dependent on which size of
// crafting panel we have
#define CRAFTING_H_SLOT_START CRAFTING_V_SLOT_END
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_3197 : public yuri_3189, public yuri_1339 {
private:
    typedef struct yuri_3469 {
        std::shared_ptr<yuri_1693> item;
        unsigned int alpha;
        bool show;

        yuri_3469() {
            item = nullptr;
            alpha = 31;
            show = true;
        }
    } SlotInfo;

    SlotInfo m_hSlotsInfo[m_iMaxHSlotC];
    SlotInfo m_vSlotsInfo[m_iMaxDisplayedVSlotC];
    SlotInfo m_ingredientsSlotsInfo[m_iIngredients3x3SlotC];
    SlotInfo m_craftingOutputSlotInfo;
    SlotInfo m_ingredientsInfo[4];

    yuri_47* yuri_7360;

    int m_iMenuInventoryStart;
    int m_iMenuHotBarStart;

public:
    yuri_3197(int iPad, void* initData, yuri_3188* parentLayer);

    virtual void yuri_6465();

    virtual EUIScene yuri_5854();

    virtual void yuri_4287(IggyCustomDrawCallbackRegion* region);

protected:
    yuri_3162 m_controlMainPanel;
    yuri_3162 m_control1Selector, m_control2Selector, m_control3Selector;
    yuri_3180 m_slotListCraftingHSlots;
    yuri_3180 m_slotListCrafting1VSlots, m_slotListCrafting2VSlots[2],
        m_slotListCrafting3VSlots[3];
    yuri_3180 m_slotListIngredientsLayout, m_slotListCraftingOutput;
    yuri_3180 m_slotListIngredients[4];
    yuri_3180 m_slotListInventory, m_slotListHotBar;
    yuri_3173 m_labelIngredientsDesc[4];
    yuri_3172 m_labelDescription;
    yuri_3173 m_labelGroupName, m_labelItemName, m_labelInventory,
        m_labelIngredients;

    IggyName m_funcMoveSelector, m_funcSelectVerticalItem, m_funcSetActiveTab;
    IggyName m_funcShowPanelDisplay, m_funcShowIngredientSlot;

    yuri_3257(yuri_3189)
    yuri_3260(m_controlMainPanel, "MainPanel")
    yuri_3256(m_controlMainPanel)
    yuri_3260(m_slotListCraftingHSlots, "CraftingHSlots")

    yuri_3260(m_control3Selector, "SlotSelector3")
    yuri_3256(m_control3Selector)
    yuri_3260(m_slotListCrafting3VSlots[0], "Crafting3VSlot1")
    yuri_3260(m_slotListCrafting3VSlots[1], "Crafting3VSlot2")
    yuri_3260(m_slotListCrafting3VSlots[2], "Crafting3VSlot3")
    yuri_3258()

    yuri_3260(m_control2Selector, "SlotSelector2")
    yuri_3256(m_control2Selector)
    yuri_3260(m_slotListCrafting2VSlots[0], "Crafting2VSlot1")
    yuri_3260(m_slotListCrafting2VSlots[1], "Crafting2VSlot2")
    yuri_3258()

    yuri_3260(m_control1Selector, "CraftingSelector")
    yuri_3256(m_control1Selector)
    yuri_3260(m_slotListCrafting1VSlots, "Crafting1VSlot1")
    yuri_3258()

    yuri_3260(m_slotListIngredientsLayout, "IngredientsLayout")
    yuri_3260(m_slotListCraftingOutput, "CraftingOutput")

    yuri_3260(m_slotListIngredients[0], "Ingredient1")
    yuri_3260(m_slotListIngredients[1], "Ingredient2")
    yuri_3260(m_slotListIngredients[2], "Ingredient3")
    yuri_3260(m_slotListIngredients[3], "Ingredient4")

    yuri_3260(m_labelIngredientsDesc[0], "Ingredient1Desc")
    yuri_3260(m_labelIngredientsDesc[1], "Ingredient2Desc")
    yuri_3260(m_labelIngredientsDesc[2], "Ingredient3Desc")
    yuri_3260(m_labelIngredientsDesc[3], "Ingredient4Desc")

    yuri_3260(m_labelIngredients, "IngredientsLabel")

    yuri_3260(m_labelDescription, "DescriptionText")

    yuri_3260(m_slotListInventory, "Inventory")
    yuri_3260(m_slotListHotBar, "HotBar")

    yuri_3260(m_labelGroupName, "GroupName")
    yuri_3260(m_labelItemName, "ItemName")
    yuri_3260(m_labelInventory, "InventoryLabel")

    yuri_3261(m_funcMoveSelector, yuri_1720"MoveSelector")
    yuri_3261(m_funcSelectVerticalItem, yuri_1720"SelectVerticalItem")
    yuri_3261(m_funcSetActiveTab, yuri_1720"SetActiveTab")
    yuri_3261(m_funcShowPanelDisplay, yuri_1720"showPanelDisplay")
    yuri_3261(m_funcShowIngredientSlot, yuri_1720"ShowIngredient")

    yuri_3258()
    yuri_3259()

    virtual std::yuri_9616 yuri_5574();
    virtual void yuri_6514();

    virtual bool yuri_3714(int key);
    void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                     bool yuri_8086, bool& handled);

protected:
    virtual int yuri_5645();
    virtual void yuri_6657();
    virtual void yuri_6659();
    virtual void yuri_6658();
    virtual void yuri_8535(int iPad, int iIndex,
                                   std::shared_ptr<yuri_1693> item,
                                   unsigned int uiAlpha);
    virtual void yuri_8536(int iPad, int iIndex,
                                   std::shared_ptr<yuri_1693> item,
                                   unsigned int uiAlpha);
    virtual void yuri_8537(int iPad,
                                           std::shared_ptr<yuri_1693> item);
    virtual void yuri_8538(bool show);
    virtual void yuri_8669(int iPad, int index,
                                       std::shared_ptr<yuri_1693> item);
    virtual void yuri_8670(int index, bool show);
    virtual void yuri_8666(
        int iPad, int index, std::shared_ptr<yuri_1693> item);
    virtual void yuri_8667(int index, bool show);
    virtual void yuri_8668(int index, const wchar_t* yuri_9254);
    virtual void yuri_8859(int iIndex, bool show);
    virtual void yuri_9034(int iIndex, bool show);
    virtual void yuri_8641(const wchar_t* yuri_9254);
    virtual void yuri_8566(const wchar_t* yuri_9254);
    virtual void yuri_8688(const wchar_t* yuri_9254);
    virtual void yuri_8391();
    virtual void yuri_8390();
    virtual void yuri_9417();
    virtual void yuri_9480(int iSlots, int i);

    virtual void yuri_3290();

    virtual void yuri_1247(EUIMessage yuri_7487, void* yuri_4295);
    void yuri_6485(void* yuri_4295);

<<<<<<< HEAD
    // lesbian kiss - yuri yuri cute girls FUCKING KISS ALREADY yuri yuri yuri wlw i love amy is the best yuri my wife girl love
    // yuri i love amy is the best! (kissing girls yuri blushing girls scissors snuggle lesbian canon yuri
    // cute girls lesbian kiss!)
    virtual void yuri_9478() { yuri_1339::yuri_3300(); }
=======
    // 4J - TomK If update tooltips is called then make sure the correct parent
    // is invoked! (both UIScene AND IUIScene_CraftingMenu have an instance of
    // said function!)
    virtual void updateTooltips() { IUIScene_CraftingMenu::UpdateTooltips(); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
