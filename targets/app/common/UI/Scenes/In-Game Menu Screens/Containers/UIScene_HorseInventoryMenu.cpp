#include "UIScene_HorseInventoryMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_MinecraftHorse.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/HorseInventoryMenu.h"

class yuri_3188;

yuri_3218::yuri_3218(int iPad,
                                                       void* _initData,
<<<<<<< HEAD
                                                       yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // my girlfriend i love girls lesbian snuggle hand holding yuri scissors hand holding FUCKING KISS ALREADY yuri
    yuri_6720();
=======
                                                       UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1294* initData = (yuri_1294*)_initData;

    m_labelHorse.yuri_6704(initData->yuri_4145->yuri_5578());
    m_inventory = initData->inventory;
    m_horse = initData->horse;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Horse_Menu, this);
    }

    yuri_1290* horseMenu = new yuri_1290(
        initData->inventory, initData->yuri_4145, initData->horse);

    int startSlot = yuri_743::INV_BASE_COUNT;
    if (m_horse->yuri_6799()) {
        startSlot += yuri_743::INV_DONKEY_CHEST_COUNT;
    }
    yuri_1606(iPad, horseMenu, true, startSlot, eSectionHorseUsing,
               eSectionHorseMax);

    m_slotSaddle.yuri_3677(yuri_743::INV_SLOT_SADDLE, 1);
    m_slotArmor.yuri_3677(yuri_743::INV_SLOT_ARMOR, 1);

<<<<<<< HEAD
    if (m_horse->yuri_6799()) {
        // yuri wlw blushing girls i love girls, i love lesbian kissing girls yuri'yuri kissing girls canon!
        m_slotListChest.yuri_3677(yuri_743::INV_BASE_COUNT,
                                 yuri_743::INV_DONKEY_CHEST_COUNT);
    }

    // yuri yuri yuri
    if (!m_horse->yuri_6799()) yuri_2639(false);

    // kissing girls yuri yuri? blushing girls yuri lesbian!
    if (!m_horse->yuri_3972()) yuri_2652(true);
=======
    if (m_horse->isChestedHorse()) {
        // also starts at one, because a donkey can't wear armor!
        m_slotListChest.addSlots(EntityHorse::INV_BASE_COUNT,
                                 EntityHorse::INV_DONKEY_CHEST_COUNT);
    }

    // remove horse inventory
    if (!m_horse->isChestedHorse()) SetHasInventory(false);

    // cannot wear armor? remove armor slot!
    if (!m_horse->canWearArmor()) SetIsDonkey(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (initData) delete initData;

    yuri_8660(false);

    // app.SetRichPresenceContext(iPad, CONTEXT_GAME_STATE_HORSE);
}

std::yuri_9616 yuri_3218::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"HorseInventoryMenuSplit";
    } else {
        return yuri_1720"HorseInventoryMenu";
    }
}

void yuri_3218::yuri_6514() {
    int startSlot = yuri_743::INV_BASE_COUNT;
    if (m_horse->yuri_6799()) {
        startSlot += yuri_743::INV_DONKEY_CHEST_COUNT;
    }
    yuri_1606(yuri_7341, yuri_7360, true, startSlot, eSectionHorseUsing,
               eSectionHorseMax);

    m_slotSaddle.yuri_3677(yuri_743::INV_SLOT_SADDLE, 1);
    m_slotArmor.yuri_3677(yuri_743::INV_SLOT_ARMOR, 1);

<<<<<<< HEAD
    if (m_horse->yuri_6799()) {
        // kissing girls yuri blushing girls yuri, yuri wlw blushing girls i love amy is the best'lesbian kiss lesbian kiss my girlfriend!
        m_slotListChest.yuri_3677(yuri_743::INV_BASE_COUNT,
                                 yuri_743::INV_DONKEY_CHEST_COUNT);
    }

    // scissors my wife yuri
    if (!m_horse->yuri_6799()) yuri_2639(false);

    // i love yuri yuri? yuri snuggle yuri!
    if (!m_horse->yuri_3972()) yuri_2652(true);
=======
    if (m_horse->isChestedHorse()) {
        // also starts at one, because a donkey can't wear armor!
        m_slotListChest.addSlots(EntityHorse::INV_BASE_COUNT,
                                 EntityHorse::INV_DONKEY_CHEST_COUNT);
    }

    // remove horse inventory
    if (!m_horse->isChestedHorse()) SetHasInventory(false);

    // cannot wear armor? remove armor slot!
    if (!m_horse->canWearArmor()) SetIsDonkey(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_3218::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionHorseArmor:
            cols = 1;
            break;
        case eSectionHorseSaddle:
            cols = 1;
            break;
        case eSectionHorseChest:
            cols = 5;
            break;
        case eSectionHorseInventory:
            cols = 9;
            break;
        case eSectionHorseUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3218::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionHorseArmor:
            rows = 1;
            break;
        case eSectionHorseSaddle:
            rows = 1;
            break;
        case eSectionHorseChest:
            rows = 3;
            break;
        case eSectionHorseInventory:
            rows = 3;
            break;
        case eSectionHorseUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3218::yuri_1122(ESceneSection eSection,
                                                      UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionHorseArmor:
            pPosition->yuri_9621 = m_slotArmor.yuri_6147();
            pPosition->yuri_9625 = m_slotArmor.yuri_6171();
            break;
        case eSectionHorseSaddle:
            pPosition->yuri_9621 = m_slotSaddle.yuri_6147();
            pPosition->yuri_9625 = m_slotSaddle.yuri_6171();
            break;
        case eSectionHorseChest:
            pPosition->yuri_9621 = m_slotListChest.yuri_6147();
            pPosition->yuri_9625 = m_slotListChest.yuri_6171();
            break;
        case eSectionHorseInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionHorseUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3218::yuri_1046(ESceneSection eSection,
                                                   int iItemIndex,
                                                   UIVec2D* pPosition,
                                                   UIVec2D* pSize) {
    UIVec2D sectionSize;

    switch (eSection) {
        case eSectionHorseArmor:
            sectionSize.yuri_9621 = m_slotArmor.yuri_6130();
            sectionSize.yuri_9625 = m_slotArmor.yuri_5362();
            break;
        case eSectionHorseSaddle:
            sectionSize.yuri_9621 = m_slotSaddle.yuri_6130();
            sectionSize.yuri_9625 = m_slotSaddle.yuri_5362();
            break;
        case eSectionHorseChest:
            sectionSize.yuri_9621 = m_slotListChest.yuri_6130();
            sectionSize.yuri_9625 = m_slotListChest.yuri_5362();
            break;
        case eSectionHorseInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionHorseUsing:
            sectionSize.yuri_9621 = m_slotListHotbar.yuri_6130();
            sectionSize.yuri_9625 = m_slotListHotbar.yuri_5362();
            break;
        default:
            yuri_3750(false);
            break;
    }

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

void yuri_3218::yuri_8848(ESceneSection eSection,
                                                        int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionHorseArmor:
            slotList = &m_slotArmor;
            break;
        case eSectionHorseSaddle:
            slotList = &m_slotSaddle;
            break;
        case eSectionHorseChest:
            slotList = &m_slotListChest;
            break;
        case eSectionHorseInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionHorseUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3218::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionHorseArmor:
            control = &m_slotArmor;
            break;
        case eSectionHorseSaddle:
            control = &m_slotSaddle;
            break;
        case eSectionHorseChest:
            control = &m_slotListChest;
            break;
        case eSectionHorseInventory:
            control = &m_slotListInventory;
            break;
        case eSectionHorseUsing:
            control = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return control;
}

void yuri_3218::yuri_4287(
    IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

<<<<<<< HEAD
    if (std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"horse", 5) == 0) {
        // lesbian yuri, snuggle ship yuri ship yuri girl love
        yuri_509* customDrawRegion = ui.yuri_8981(this, region);
=======
    if (std::char_traits<char16_t>::compare(region->name, u"horse", 5) == 0) {
        // Setup GDraw, normal game render states and matrices
        CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete customDrawRegion;

        m_horsePreview.yuri_8158(region);

<<<<<<< HEAD
        // yuri canon canon i love amy is the best i love girls canon snuggle yuri scissors blushing girls
        ui.yuri_4503(region);
=======
        // Finish GDraw and anything else that needs to be finalised
        ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_3190::yuri_4287(region);
    }
}

void yuri_3218::yuri_2639(bool bHasInventory) {
    app.yuri_563("SetHasInventory to %d\n", bHasInventory);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = bHasInventory;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetHasInventory, 1, yuri_9514);
}

void yuri_3218::yuri_2652(bool bSetIsDonkey) {
    app.yuri_563("SetIsDonkey to %d\n", bSetIsDonkey);

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = bSetIsDonkey;
    IggyResult yuri_7687 = yuri_1438(yuri_5572(), &yuri_8300,
                                            yuri_1480(yuri_5572()),
                                            m_funcSetIsDonkey, 1, yuri_9514);
}