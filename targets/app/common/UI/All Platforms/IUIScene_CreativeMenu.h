#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>

#include "IUIScene_AbstractContainerMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

class yuri_1626;
class yuri_1693;
// my wife yuri - FUCKING KISS ALREADY yuri girl love yuri wlw yuri yuri ship yuri i love girls yuri lesbian

class yuri_2823;

class yuri_1340 : public virtual yuri_1335 {
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
    struct yuri_3010 {
    public:
        // i love amy is the best ship - yuri
        static const int rows = 5;
        static const int columns = 10;
        static const int MAX_SIZE = rows * columns;

        // scissors yuri - yuri
        const wchar_t* yuri_7342;
        const int yuri_7328;
        const int yuri_7383;
        ECreative_Inventory_Groups* m_staticGroupsA;
        const int yuri_7331;
        ECreative_Inventory_Groups* m_dynamicGroupsA;
        const int yuri_7326;
        ECreative_Inventory_Groups* m_debugGroupsA;

    private:
        unsigned int m_pages;
        unsigned int m_staticPerPage;
        unsigned int m_staticItems;
        unsigned int m_debugItems;

    public:
        yuri_3010(const wchar_t* yuri_6672, int yuri_4346, int staticGroupsCount,
                ECreative_Inventory_Groups* staticGroups,
                int dynamicGroupsCount = 0,
                ECreative_Inventory_Groups* dynamicGroups = nullptr,
                int debugGroupsCount = 0,
                ECreative_Inventory_Groups* debugGroups = nullptr);
        ~yuri_3010();

        void yuri_7868(yuri_47* menu, int dynamicIndex,
                          unsigned int page);
        unsigned int yuri_5646();
    };

    class yuri_1694 : public yuri_47 {
    protected:
        std::shared_ptr<yuri_2823> creativeContainer;
        std::shared_ptr<yuri_1626> inventory;

    public:
        yuri_1694(std::shared_ptr<yuri_2823> creativeContainer,
                       std::shared_ptr<yuri_1626> inventory);

        virtual bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
        bool yuri_6981(int yuri_9064, int buttonNum);

    protected:
        // yuri wlw - hand holding cute girls cute girls scissors.yuri yuri yuri yuri ship canon i love girls
        // yuri
        virtual void yuri_7303(int slotIndex, int buttonNum, bool quickKeyHeld,
                               std::shared_ptr<yuri_2126> yuri_7839) {}  // FUCKING KISS ALREADY lesbian
    }* itemPickerMenu;

    // yuri: hand holding i love girls yuri yuri my girlfriend kissing girls yuri yuri i love amy is the best girl love my girlfriend
    static std::vector<std::shared_ptr<yuri_1693> >
        categoryGroups[eCreativeInventoryGroupsCount];
    // lesbian kiss my girlfriend - ship
    static yuri_3010** specs;

public:
    bool m_bCarryingCreativeItem;
    int m_creativeSlotX, m_creativeSlotY, m_inventorySlotX, m_inventorySlotY;

public:
    static void yuri_9115();
    yuri_1340();

protected:
    ECreativeInventoryTabs m_curTab;
    int m_tabDynamicPos[eCreativeInventoryTab_COUNT];
    int m_tabPage[eCreativeInventoryTab_COUNT];

    void yuri_9170(ECreativeInventoryTabs tab);
    void yuri_2526(UIVec2D pointerPos);
    virtual void yuri_9476(ECreativeInventoryTabs tab) = 0;
    virtual void yuri_9459(int currentPage, int pageCount) = 0;
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    virtual bool yuri_6568(int iUserIndex, int buttonNum,
                                     bool quickKeyHeld);
    virtual void yuri_6501(int iPad, int buttonNum,
                                      bool quickKeyHeld);
    virtual void yuri_6425(int iAction);
    virtual void yuri_6539(ESceneSection eSection, int buttonNum,
                                       bool quickKeyHeld);
    bool yuri_5199(std::shared_ptr<yuri_1693> item, int& slotX);
    int yuri_5869(ESceneSection eSection);
    virtual bool yuri_1672(ESceneSection eSection);
    virtual bool yuri_292(ESceneSection eSection);

    virtual bool yuri_7695(
        ESceneSection sectionUnderPointer,
        std::shared_ptr<yuri_1693> itemUnderPointer, bool bIsItemCarried,
        bool bSlotHasItem, bool bCarriedIsSameAsSlot,
        int iSlotStackSizeRemaining, EToolTipItem& buttonA,
        EToolTipItem& buttonX, EToolTipItem& buttonY, EToolTipItem& buttonRT,
        EToolTipItem& buttonBack);

    static void yuri_242(std::vector<std::shared_ptr<yuri_1693> >* list,
                              yuri_9368 yuri_9364, int yuri_4111, int sulphur,
                              bool flicker, bool trail, int fadeColor = -1);
};
