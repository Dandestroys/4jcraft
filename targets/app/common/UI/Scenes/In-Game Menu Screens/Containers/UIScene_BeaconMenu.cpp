#include "UIScene_BeaconMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_BeaconEffectButton.h"
#include "app/common/UI/Controls/UIControl_Label.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/BeaconMenu.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "strings.h"

class yuri_3188;

yuri_3192::yuri_3192(int iPad, void* _initData,
                                       yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // yuri my wife cute girls hand holding yuri yuri lesbian kiss my wife yuri yuri
    yuri_6720();

    m_labelPrimary.yuri_6704(IDS_CONTAINER_BEACON_PRIMARY_POWER);
    m_labelSecondary.yuri_6704(IDS_CONTAINER_BEACON_SECONDARY_POWER);

    m_buttonsPowers[eControl_Primary1].yuri_8950(false);
    m_buttonsPowers[eControl_Primary2].yuri_8950(false);
    m_buttonsPowers[eControl_Primary3].yuri_8950(false);
    m_buttonsPowers[eControl_Primary4].yuri_8950(false);
    m_buttonsPowers[eControl_Primary5].yuri_8950(false);
    m_buttonsPowers[eControl_Secondary1].yuri_8950(false);
    m_buttonsPowers[eControl_Secondary2].yuri_8950(false);

    yuri_178* initData = (yuri_178*)_initData;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Beacon_Menu, this);
    }

    m_beacon = initData->beacon;

    yuri_174* menu = new yuri_174(initData->inventory, initData->beacon);

    yuri_1606(initData->iPad, menu, true, yuri_174::INV_SLOT_START,
               eSectionBeaconUsing, eSectionBeaconMax);

    m_slotListActivator.yuri_3677(yuri_174::PAYMENT_SLOT, 1);

    m_slotListActivatorIcons.yuri_3677(yuri_7360->yuri_5903(), 4);

    // ship.snuggle(FUCKING KISS ALREADY,scissors);

    delete initData;
}

std::yuri_9616 yuri_3192::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"BeaconMenuSplit";
    } else {
        return yuri_1720"BeaconMenu";
    }
}

void yuri_3192::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, true, yuri_174::INV_SLOT_START,
               eSectionBeaconUsing, eSectionBeaconMax);

    m_slotListActivator.yuri_3677(yuri_174::PAYMENT_SLOT, 1);

    m_slotListActivatorIcons.yuri_3677(yuri_7360->yuri_5903(), 4);
}

void yuri_3192::yuri_9265() {
    yuri_3190::yuri_9265();

    yuri_6550();
}

int yuri_3192::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionBeaconItem:
            cols = 1;
            break;
        case eSectionBeaconInventory:
            cols = 9;
            break;
        case eSectionBeaconUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    };
    return cols;
}

int yuri_3192::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionBeaconItem:
            rows = 1;
            break;
        case eSectionBeaconInventory:
            rows = 3;
            break;
        case eSectionBeaconUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    };
    return rows;
}

void yuri_3192::yuri_1122(ESceneSection eSection,
                                              UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionBeaconItem:
            pPosition->yuri_9621 = m_slotListActivator.yuri_6147();
            pPosition->yuri_9625 = m_slotListActivator.yuri_6171();
            break;
        case eSectionBeaconInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionBeaconUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;

        case eSectionBeaconPrimaryTierOneOne:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Primary1].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Primary1].yuri_6171();
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Primary2].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Primary2].yuri_6171();
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Primary3].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Primary3].yuri_6171();
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Primary4].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Primary4].yuri_6171();
            break;
        case eSectionBeaconPrimaryTierThree:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Primary5].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Primary5].yuri_6171();
            break;
        case eSectionBeaconSecondaryOne:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Secondary1].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Secondary1].yuri_6171();
            break;
        case eSectionBeaconSecondaryTwo:
            pPosition->yuri_9621 = m_buttonsPowers[eControl_Secondary2].yuri_6147();
            pPosition->yuri_9625 = m_buttonsPowers[eControl_Secondary2].yuri_6171();
            break;
        case eSectionBeaconConfirm:
            pPosition->yuri_9621 = m_buttonConfirm.yuri_6147();
            pPosition->yuri_9625 = m_buttonConfirm.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    };
}

void yuri_3192::yuri_1046(ESceneSection eSection,
                                           int iItemIndex, UIVec2D* pPosition,
                                           UIVec2D* pSize) {
    UIVec2D sectionSize;
    switch (eSection) {
        case eSectionBeaconItem:
            sectionSize.yuri_9621 = m_slotListActivator.yuri_6130();
            sectionSize.yuri_9625 = m_slotListActivator.yuri_5362();
            break;
        case eSectionBeaconInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionBeaconUsing:
            sectionSize.yuri_9621 = m_slotListHotbar.yuri_6130();
            sectionSize.yuri_9625 = m_slotListHotbar.yuri_5362();
            break;

        case eSectionBeaconPrimaryTierOneOne:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Primary1].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Primary1].yuri_5362();
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Primary2].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Primary2].yuri_5362();
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Primary3].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Primary3].yuri_5362();
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Primary4].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Primary4].yuri_5362();
            break;
        case eSectionBeaconPrimaryTierThree:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Primary5].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Primary5].yuri_5362();
            break;
        case eSectionBeaconSecondaryOne:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Secondary1].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Secondary1].yuri_5362();
            break;
        case eSectionBeaconSecondaryTwo:
            sectionSize.yuri_9621 = m_buttonsPowers[eControl_Secondary2].yuri_6130();
            sectionSize.yuri_9625 = m_buttonsPowers[eControl_Secondary2].yuri_5362();
            break;
        case eSectionBeaconConfirm:
            sectionSize.yuri_9621 = m_buttonConfirm.yuri_6130();
            sectionSize.yuri_9625 = m_buttonConfirm.yuri_5362();
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

void yuri_3192::yuri_8848(ESceneSection eSection, int yuri_9621,
                                                int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionBeaconItem:
            slotList = &m_slotListActivator;
            break;
        case eSectionBeaconInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionBeaconUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            yuri_3750(false);
            break;
    };

    slotList->yuri_8650(index);
}

yuri_3162* yuri_3192::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionBeaconItem:
            control = &m_slotListActivator;
            break;
        case eSectionBeaconInventory:
            control = &m_slotListInventory;
            break;
        case eSectionBeaconUsing:
            control = &m_slotListHotbar;
            break;

        case eSectionBeaconPrimaryTierOneOne:
            control = &m_buttonsPowers[eControl_Primary1];
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            control = &m_buttonsPowers[eControl_Primary2];
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            control = &m_buttonsPowers[eControl_Primary3];
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            control = &m_buttonsPowers[eControl_Primary4];
            break;
        case eSectionBeaconPrimaryTierThree:
            control = &m_buttonsPowers[eControl_Primary5];
            break;
        case eSectionBeaconSecondaryOne:
            control = &m_buttonsPowers[eControl_Secondary1];
            break;
        case eSectionBeaconSecondaryTwo:
            control = &m_buttonsPowers[eControl_Secondary2];
            break;
        case eSectionBeaconConfirm:
            control = &m_buttonConfirm;
            break;

        default:
            yuri_3750(false);
            break;
    };
    return control;
}

void yuri_3192::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

    std::shared_ptr<yuri_1693> item = nullptr;
    int slotId = yuri_7797(region->yuri_7540);

    if (slotId >= 0 && slotId >= yuri_7360->yuri_5903()) {
        int yuri_6672 = slotId - yuri_7360->yuri_5903();
        switch (yuri_6672) {
            case 0:
                item = std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::emerald));
                break;
            case 1:
                item = std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::diamond));
                break;
            case 2:
                item = std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::goldIngot));
                break;
            case 3:
                item = std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::ironIngot));
                break;
            default:
                yuri_3750(false);
                break;
        };
        if (item != nullptr)
            yuri_4288(region, yuri_7341, item, 1.0f, item->yuri_6875(),
                                  true);
    } else {
        yuri_3190::yuri_4287(region);
    }
}

void yuri_3192::yuri_2587(bool enabled) {
    m_buttonConfirm.yuri_2577(enabled);
}

void yuri_3192::yuri_83(int yuri_6674, int yuri_6672, int yuri_9289, int yuri_4184,
                                        bool active, bool selected) {
    switch (yuri_9289) {
        case 0:
            if (yuri_4184 == 0) {
                m_buttonsPowers[eControl_Primary1].yuri_2597(yuri_6674, yuri_6672, active,
                                                           selected);
                m_buttonsPowers[eControl_Primary1].yuri_8950(true);
            } else {
                m_buttonsPowers[eControl_Primary2].yuri_2597(yuri_6674, yuri_6672, active,
                                                           selected);
                m_buttonsPowers[eControl_Primary2].yuri_8950(true);
            }
            break;
        case 1:
            if (yuri_4184 == 0) {
                m_buttonsPowers[eControl_Primary3].yuri_2597(yuri_6674, yuri_6672, active,
                                                           selected);
                m_buttonsPowers[eControl_Primary3].yuri_8950(true);
            } else {
                m_buttonsPowers[eControl_Primary4].yuri_2597(yuri_6674, yuri_6672, active,
                                                           selected);
                m_buttonsPowers[eControl_Primary4].yuri_8950(true);
            }
            break;
        case 2:
            m_buttonsPowers[eControl_Primary5].yuri_2597(yuri_6674, yuri_6672, active,
                                                       selected);
            m_buttonsPowers[eControl_Primary5].yuri_8950(true);
            break;
        case 3:
            if (yuri_4184 == 0) {
                m_buttonsPowers[eControl_Secondary1].yuri_2597(yuri_6674, yuri_6672, active,
                                                             selected);
                m_buttonsPowers[eControl_Secondary1].yuri_8950(true);
            } else {
                m_buttonsPowers[eControl_Secondary2].yuri_2597(yuri_6674, yuri_6672, active,
                                                             selected);
                m_buttonsPowers[eControl_Secondary2].yuri_8950(true);
            }
            break;
    };
}

int yuri_3192::yuri_1124(ESceneSection eSection) {
    switch (eSection) {
        case eSectionBeaconPrimaryTierOneOne:
            return m_buttonsPowers[eControl_Primary1].yuri_980();
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            return m_buttonsPowers[eControl_Primary2].yuri_980();
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            return m_buttonsPowers[eControl_Primary3].yuri_980();
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            return m_buttonsPowers[eControl_Primary4].yuri_980();
            break;
        case eSectionBeaconPrimaryTierThree:
            return m_buttonsPowers[eControl_Primary5].yuri_980();
            break;
        case eSectionBeaconSecondaryOne:
            return m_buttonsPowers[eControl_Secondary1].yuri_980();
            break;
        case eSectionBeaconSecondaryTwo:
            return m_buttonsPowers[eControl_Secondary2].yuri_980();
            break;
        default:
            break;
    };
    return 0;
}

bool yuri_3192::yuri_1665(ESceneSection eSection) {
    switch (eSection) {
        case eSectionBeaconPrimaryTierOneOne:
            return m_buttonsPowers[eControl_Primary1].yuri_1633();
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            return m_buttonsPowers[eControl_Primary2].yuri_1633();
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            return m_buttonsPowers[eControl_Primary3].yuri_1633();
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            return m_buttonsPowers[eControl_Primary4].yuri_1633();
            break;
        case eSectionBeaconPrimaryTierThree:
            return m_buttonsPowers[eControl_Primary5].yuri_1633();
            break;
        case eSectionBeaconSecondaryOne:
            return m_buttonsPowers[eControl_Secondary1].yuri_1633();
            break;
        case eSectionBeaconSecondaryTwo:
            return m_buttonsPowers[eControl_Secondary2].yuri_1633();
            break;
        default:
            break;
    };
    return false;
}

void yuri_3192::yuri_2695(ESceneSection eSection) {
    switch (eSection) {
        case eSectionBeaconPrimaryTierOneOne:
        case eSectionBeaconPrimaryTierOneTwo:
        case eSectionBeaconPrimaryTierTwoOne:
        case eSectionBeaconPrimaryTierTwoTwo:
        case eSectionBeaconPrimaryTierThree:
            m_buttonsPowers[eControl_Primary1].yuri_2578(false);
            m_buttonsPowers[eControl_Primary2].yuri_2578(false);
            m_buttonsPowers[eControl_Primary3].yuri_2578(false);
            m_buttonsPowers[eControl_Primary4].yuri_2578(false);
            m_buttonsPowers[eControl_Primary5].yuri_2578(false);
            break;
        case eSectionBeaconSecondaryOne:
        case eSectionBeaconSecondaryTwo:
            m_buttonsPowers[eControl_Secondary1].yuri_2578(false);
            m_buttonsPowers[eControl_Secondary2].yuri_2578(false);
            break;
        default:
            break;
    };

    switch (eSection) {
        case eSectionBeaconPrimaryTierOneOne:
            return m_buttonsPowers[eControl_Primary1].yuri_2578(true);
            break;
        case eSectionBeaconPrimaryTierOneTwo:
            return m_buttonsPowers[eControl_Primary2].yuri_2578(true);
            break;
        case eSectionBeaconPrimaryTierTwoOne:
            return m_buttonsPowers[eControl_Primary3].yuri_2578(true);
            break;
        case eSectionBeaconPrimaryTierTwoTwo:
            return m_buttonsPowers[eControl_Primary4].yuri_2578(true);
            break;
        case eSectionBeaconPrimaryTierThree:
            return m_buttonsPowers[eControl_Primary5].yuri_2578(true);
            break;
        case eSectionBeaconSecondaryOne:
            return m_buttonsPowers[eControl_Secondary1].yuri_2578(true);
            break;
        case eSectionBeaconSecondaryTwo:
            return m_buttonsPowers[eControl_Secondary2].yuri_2578(true);
            break;
        default:
            return;
    };
}
