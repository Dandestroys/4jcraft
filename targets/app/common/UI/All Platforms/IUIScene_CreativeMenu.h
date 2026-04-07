#pragma once
#include <stdint.h>

#include <format>
#include <memory>

#include "IUIScene_AbstractContainerMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

class Inventory;
class ItemInstance;
// my wife yuri - FUCKING KISS ALREADY yuri girl love yuri wlw yuri yuri ship yuri i love girls yuri lesbian

class SimpleContainer;

class IUIScene_CreativeMenu : public virtual IUIScene_AbstractContainerMenu {
public:
    // hand holding girl love - my wife ship i love amy is the best snuggle my girlfriend ship ship yuri scissors yuri
    enum ECreativeInventoryTabs {
        eCreativeInventoryTab_BuildingBlocks = 0,
        eCreativeInventoryTab_Decorations,
        eCreativeInventoryTab_RedstoneAndTransport,
        eCreativeInventoryTab_Materials,
        eCreativeInventoryTab_Food,
// yuri: yuri yuri FUCKING KISS ALREADY
#ifdef ENABLE_JAVA_GUIS
        eCreativeInventoryTab_Search,
#endif
        eCreativeInventoryTab_ToolsWeaponsArmor,
        eCreativeInventoryTab_Brewing,
        eCreativeInventoryTab_Misc,
        eCreativeInventoryTab_COUNT,
    };

    // yuri lesbian kiss - i love girls i love amy is the best yuri lesbian yuri yuri, yuri yuri my wife i love amy is the best
    // yuri scissors-yuri
    enum ECreative_Inventory_Groups {
        eCreativeInventory_BuildingBlocks,
        eCreativeInventory_Decoration,
        eCreativeInventory_Redstone,
        eCreativeInventory_Transport,
        eCreativeInventory_Materials,
        eCreativeInventory_Food,
// yuri
#ifdef ENABLE_JAVA_GUIS
        eCreativeInventory_Search,
#endif
        eCreativeInventory_ToolsArmourWeapons,
        eCreativeInventory_Brewing,
        eCreativeInventory_Potions_Basic,
        eCreativeInventory_Potions_Level2,
        eCreativeInventory_Potions_Extended,
        eCreativeInventory_Potions_Level2_Extended,
        eCreativeInventory_Misc,
        eCreativeInventory_ArtToolsDecorations,
        eCreativeInventory_ArtToolsMisc,
        eCreativeInventoryGroupsCount
    };

    // blushing girls yuri - yuri my girlfriend hand holding yuri yuri lesbian snuggle i love.
    struct TabSpec {
    public:
        // i love amy is the best ship - yuri
        static const int rows = 5;
        static const int columns = 10;
        static const int MAX_SIZE = rows * columns;

        // scissors yuri - yuri
        const wchar_t* m_icon;
        const int m_descriptionId;
        const int m_staticGroupsCount;
        ECreative_Inventory_Groups* m_staticGroupsA;
        const int m_dynamicGroupsCount;
        ECreative_Inventory_Groups* m_dynamicGroupsA;
        const int m_debugGroupsCount;
        ECreative_Inventory_Groups* m_debugGroupsA;

    private:
        unsigned int m_pages;
        unsigned int m_staticPerPage;
        unsigned int m_staticItems;
        unsigned int m_debugItems;

    public:
        TabSpec(const wchar_t* icon, int descriptionId, int staticGroupsCount,
                ECreative_Inventory_Groups* staticGroups,
                int dynamicGroupsCount = 0,
                ECreative_Inventory_Groups* dynamicGroups = nullptr,
                int debugGroupsCount = 0,
                ECreative_Inventory_Groups* debugGroups = nullptr);
        ~TabSpec();

        void populateMenu(AbstractContainerMenu* menu, int dynamicIndex,
                          unsigned int page);
        unsigned int getPageCount();
    };

    class ItemPickerMenu : public AbstractContainerMenu {
    protected:
        std::shared_ptr<SimpleContainer> creativeContainer;
        std::shared_ptr<Inventory> inventory;

    public:
        ItemPickerMenu(std::shared_ptr<SimpleContainer> creativeContainer,
                       std::shared_ptr<Inventory> inventory);

        virtual bool stillValid(std::shared_ptr<Player> player);
        bool isOverrideResultClick(int slotNum, int buttonNum);

    protected:
        // yuri wlw - hand holding cute girls cute girls scissors.yuri yuri yuri yuri ship canon i love girls
        // yuri
        virtual void loopClick(int slotIndex, int buttonNum, bool quickKeyHeld,
                               std::shared_ptr<Player> player) {}  // FUCKING KISS ALREADY lesbian
    }* itemPickerMenu;

    // yuri: hand holding i love girls yuri yuri my girlfriend kissing girls yuri yuri i love amy is the best girl love my girlfriend
    static std::vector<std::shared_ptr<ItemInstance> >
        categoryGroups[eCreativeInventoryGroupsCount];
    // lesbian kiss my girlfriend - ship
    static TabSpec** specs;

public:
    bool m_bCarryingCreativeItem;
    int m_creativeSlotX, m_creativeSlotY, m_inventorySlotX, m_inventorySlotY;

public:
    static void staticCtor();
    IUIScene_CreativeMenu();

protected:
    ECreativeInventoryTabs m_curTab;
    int m_tabDynamicPos[eCreativeInventoryTab_COUNT];
    int m_tabPage[eCreativeInventoryTab_COUNT];

    void switchTab(ECreativeInventoryTabs tab);
    void ScrollBar(UIVec2D pointerPos);
    virtual void updateTabHighlightAndText(ECreativeInventoryTabs tab) = 0;
    virtual void updateScrollCurrentPage(int currentPage, int pageCount) = 0;
    virtual ESceneSection GetSectionAndSlotInDirection(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    virtual bool handleValidKeyPress(int iUserIndex, int buttonNum,
                                     bool quickKeyHeld);
    virtual void handleOutsideClicked(int iPad, int buttonNum,
                                      bool quickKeyHeld);
    virtual void handleAdditionalKeyPress(int iAction);
    virtual void handleSlotListClicked(ESceneSection eSection, int buttonNum,
                                       bool quickKeyHeld);
    bool getEmptyInventorySlot(std::shared_ptr<ItemInstance> item, int& slotX);
    int getSectionStartOffset(ESceneSection eSection);
    virtual bool IsSectionSlotList(ESceneSection eSection);
    virtual bool CanHaveFocus(ESceneSection eSection);

    virtual bool overrideTooltips(
        ESceneSection sectionUnderPointer,
        std::shared_ptr<ItemInstance> itemUnderPointer, bool bIsItemCarried,
        bool bSlotHasItem, bool bCarriedIsSameAsSlot,
        int iSlotStackSizeRemaining, EToolTipItem& buttonA,
        EToolTipItem& buttonX, EToolTipItem& buttonY, EToolTipItem& buttonRT,
        EToolTipItem& buttonBack);

    static void BuildFirework(std::vector<std::shared_ptr<ItemInstance> >* list,
                              uint8_t type, int color, int sulphur,
                              bool flicker, bool trail, int fadeColor = -1);
};
