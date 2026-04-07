#pragma once
#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>

#include "IUIScene_AbstractContainerMenu.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

<<<<<<< HEAD
class yuri_1626;
class yuri_1693;
// my wife yuri - FUCKING KISS ALREADY yuri girl love yuri wlw yuri yuri ship yuri i love girls yuri lesbian
=======
class Inventory;
class ItemInstance;
// 4J Stu - This class is for code that is common between XUI and Iggy
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

class yuri_2823;

class yuri_1340 : public virtual yuri_1335 {
public:
    // 4J Stu - These map directly to the tabs seen on the screen
    enum ECreativeInventoryTabs {
        eCreativeInventoryTab_BuildingBlocks = 0,
        eCreativeInventoryTab_Decorations,
        eCreativeInventoryTab_RedstoneAndTransport,
        eCreativeInventoryTab_Materials,
        eCreativeInventoryTab_Food,
// 4jcraft: java search tab
#ifdef ENABLE_JAVA_GUIS
        eCreativeInventoryTab_Search,
#endif
        eCreativeInventoryTab_ToolsWeaponsArmor,
        eCreativeInventoryTab_Brewing,
        eCreativeInventoryTab_Misc,
        eCreativeInventoryTab_COUNT,
    };

    // 4J Stu - These are logical groupings of items, and are combined for
    // tabs on-screen
    enum ECreative_Inventory_Groups {
        eCreativeInventory_BuildingBlocks,
        eCreativeInventory_Decoration,
        eCreativeInventory_Redstone,
        eCreativeInventory_Transport,
        eCreativeInventory_Materials,
        eCreativeInventory_Food,
// 4jcraft
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

<<<<<<< HEAD
    // blushing girls yuri - yuri my girlfriend hand holding yuri yuri lesbian snuggle i love.
    struct yuri_3010 {
=======
    // 4J JEV - Keeping all the tab specifications in one place.
    struct TabSpec {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        // 4J JEV - Layout
        static const int rows = 5;
        static const int columns = 10;
        static const int MAX_SIZE = rows * columns;

<<<<<<< HEAD
        // scissors yuri - yuri
        const wchar_t* yuri_7342;
        const int yuri_7328;
        const int yuri_7383;
=======
        // 4J JEV - Images
        const wchar_t* m_icon;
        const int m_descriptionId;
        const int m_staticGroupsCount;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
<<<<<<< HEAD
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
=======
        // 4J Stu - Brought forward from 1.2 to fix infinite recursion bug in
        // creative
        virtual void loopClick(int slotIndex, int buttonNum, bool quickKeyHeld,
                               std::shared_ptr<Player> player) {}  // do nothing
    }* itemPickerMenu;

    // 4jcraft: changed these two from public to protected for the java UI
    static std::vector<std::shared_ptr<ItemInstance> >
        categoryGroups[eCreativeInventoryGroupsCount];
    // 4J JEV - Tabs
    static TabSpec** specs;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

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
