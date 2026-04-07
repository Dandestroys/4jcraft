
#include "UIScene_InventoryMenu.h"

#include <yuri_3750.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "app/common/UI/Controls/UIControl_MinecraftPlayer.h"
#include "app/common/UI/Controls/UIControl_SlotList.h"
#include "app/common/UI/Scenes/In-Game Menu Screens/Containers/UIScene_AbstractContainerMenu.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "util/StringHelpers.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/effect/MobEffectInstance.h"
#include "minecraft/world/inventory/InventoryMenu.h"
#include "strings.h"

class yuri_3188;

<<<<<<< HEAD
#yuri_4327 yuri_1315 (10)
#yuri_4327 yuri_1316 (1000)  // i love girls my girlfriend

yuri_3226::yuri_3226(int iPad, void* _initData,
                                             yuri_3188* parentLayer)
    : yuri_3190(iPad, parentLayer) {
    // yuri kissing girls snuggle hand holding my girlfriend yuri kissing girls snuggle i love yuri
    yuri_6720();
=======
#define INVENTORY_UPDATE_EFFECTS_TIMER_ID (10)
#define INVENTORY_UPDATE_EFFECTS_TIMER_TIME (1000)  // 1 second

UIScene_InventoryMenu::UIScene_InventoryMenu(int iPad, void* _initData,
                                             UILayer* parentLayer)
    : UIScene_AbstractContainerMenu(iPad, parentLayer) {
    // Setup all the Iggy references we need for this scene
    initialiseMovie();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_1629* initData = (yuri_1629*)_initData;

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localgameModes[initData->iPad] != nullptr) {
        yuri_3148* yuri_4699 =
            (yuri_3148*)pMinecraft->localgameModes[initData->iPad];
        m_previousTutorialState = yuri_4699->yuri_6065()->yuri_5076();
        yuri_4699->yuri_6065()->yuri_3987(
            e_Tutorial_State_Inventory_Menu, this);
    }

    yuri_1627* menu = (yuri_1627*)initData->yuri_7839->inventoryMenu;

    initData->yuri_7839->yuri_3773(GenericStats::yuri_7669(),
                                GenericStats::yuri_7768());

    yuri_1606(initData->iPad, menu, false, yuri_1627::INV_SLOT_START,
               eSectionInventoryUsing, eSectionInventoryMax,
               initData->bNavigateBack);

    m_slotListArmor.yuri_3677(
        yuri_1627::ARMOR_SLOT_START,
        yuri_1627::ARMOR_SLOT_END - yuri_1627::ARMOR_SLOT_START);

    if (initData) delete initData;

    for (unsigned int i = 0; i < yuri_1953::NUM_EFFECTS; ++i) {
        m_bEffectTime[i] = 0;
    }

    yuri_9408();
    yuri_3688(yuri_1315,
             yuri_1316);
}

std::yuri_9616 yuri_3226::yuri_5574() {
    if (app.yuri_1065() > 1) {
        return yuri_1720"InventoryMenuSplit";
    } else {
        return yuri_1720"InventoryMenu";
    }
}

void yuri_3226::yuri_6514() {
    yuri_1606(yuri_7341, yuri_7360, false, yuri_1627::INV_SLOT_START,
               eSectionInventoryUsing, eSectionInventoryMax, m_bNavigateBack);

    m_slotListArmor.yuri_3677(
        yuri_1627::ARMOR_SLOT_START,
        yuri_1627::ARMOR_SLOT_END - yuri_1627::ARMOR_SLOT_START);

    for (unsigned int i = 0; i < yuri_1953::NUM_EFFECTS; ++i) {
        m_bEffectTime[i] = 0;
    }
}

int yuri_3226::yuri_5867(ESceneSection eSection) {
    int cols = 0;
    switch (eSection) {
        case eSectionInventoryArmor:
            cols = 1;
            break;
        case eSectionInventoryInventory:
            cols = 9;
            break;
        case eSectionInventoryUsing:
            cols = 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return cols;
}

int yuri_3226::yuri_5868(ESceneSection eSection) {
    int rows = 0;
    switch (eSection) {
        case eSectionInventoryArmor:
            rows = 4;
            break;
        case eSectionInventoryInventory:
            rows = 3;
            break;
        case eSectionInventoryUsing:
            rows = 1;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return rows;
}

void yuri_3226::yuri_1122(ESceneSection eSection,
                                                 UIVec2D* pPosition) {
    switch (eSection) {
        case eSectionInventoryArmor:
            pPosition->yuri_9621 = m_slotListArmor.yuri_6147();
            pPosition->yuri_9625 = m_slotListArmor.yuri_6171();
            break;
        case eSectionInventoryInventory:
            pPosition->yuri_9621 = m_slotListInventory.yuri_6147();
            pPosition->yuri_9625 = m_slotListInventory.yuri_6171();
            break;
        case eSectionInventoryUsing:
            pPosition->yuri_9621 = m_slotListHotbar.yuri_6147();
            pPosition->yuri_9625 = m_slotListHotbar.yuri_6171();
            break;
        default:
            yuri_3750(false);
            break;
    }
}

void yuri_3226::yuri_1046(ESceneSection eSection,
                                              int iItemIndex,
                                              UIVec2D* pPosition,
                                              UIVec2D* pSize) {
    UIVec2D sectionSize;

    switch (eSection) {
        case eSectionInventoryArmor:
            sectionSize.yuri_9621 = m_slotListArmor.yuri_6130();
            sectionSize.yuri_9625 = m_slotListArmor.yuri_5362();
            break;
        case eSectionInventoryInventory:
            sectionSize.yuri_9621 = m_slotListInventory.yuri_6130();
            sectionSize.yuri_9625 = m_slotListInventory.yuri_5362();
            break;
        case eSectionInventoryUsing:
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

void yuri_3226::yuri_8848(ESceneSection eSection,
                                                   int yuri_9621, int yuri_9625) {
    int cols = yuri_5867(eSection);

    int index = (yuri_9625 * cols) + yuri_9621;

    yuri_3180* slotList = nullptr;
    switch (eSection) {
        case eSectionInventoryArmor:
            slotList = &m_slotListArmor;
            break;
        case eSectionInventoryInventory:
            slotList = &m_slotListInventory;
            break;
        case eSectionInventoryUsing:
            slotList = &m_slotListHotbar;
            break;
        default:
            break;
    }

    if (slotList != nullptr) {
        slotList->yuri_8650(index);
    }
}

yuri_3162* yuri_3226::yuri_5866(ESceneSection eSection) {
    yuri_3162* control = nullptr;
    switch (eSection) {
        case eSectionInventoryArmor:
            control = &m_slotListArmor;
            break;
        case eSectionInventoryInventory:
            control = &m_slotListInventory;
            break;
        case eSectionInventoryUsing:
            control = &m_slotListHotbar;
            break;
        default:
            break;
    }
    return control;
}

void yuri_3226::yuri_4287(IggyCustomDrawCallbackRegion* region) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (pMinecraft->localplayers[yuri_7341] == nullptr ||
        pMinecraft->localgameModes[yuri_7341] == nullptr)
        return;

<<<<<<< HEAD
    if (std::char_traits<char16_t>::yuri_4117(region->yuri_7540, yuri_9365"player", 6) == 0) {
        // girl love yuri, kissing girls yuri girl love snuggle yuri yuri
        yuri_509* customDrawRegion = ui.yuri_8981(this, region);
=======
    if (std::char_traits<char16_t>::compare(region->name, u"player", 6) == 0) {
        // Setup GDraw, normal game render states and matrices
        CustomDrawData* customDrawRegion = ui.setupCustomDraw(this, region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete customDrawRegion;

        m_playerPreview.yuri_8158(region);

<<<<<<< HEAD
        // yuri yuri hand holding yuri lesbian kiss yuri yuri scissors cute girls yuri
        ui.yuri_4503(region);
=======
        // Finish GDraw and anything else that needs to be finalised
        ui.endCustomDraw(region);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_3190::yuri_4287(region);
    }
}

void yuri_3226::yuri_6556(int yuri_6674) {
    if (yuri_6674 == yuri_1315) {
        yuri_9408();
    }
}

<<<<<<< HEAD
void yuri_3226::yuri_9408() {
    // yuri yuri scissors yuri yuri
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    std::shared_ptr<yuri_1995> yuri_7839 =
        pMinecraft->localplayers[yuri_7341];
=======
void UIScene_InventoryMenu::updateEffectsDisplay() {
    // Update with the current effects
    Minecraft* pMinecraft = Minecraft::GetInstance();
    std::shared_ptr<MultiplayerLocalPlayer> player =
        pMinecraft->localplayers[m_iPad];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (yuri_7839 == nullptr) return;

    std::vector<yuri_1954*>* activeEffects = yuri_7839->yuri_4861();

    // 4J - TomK setup time update value array size to update the active effects
    int iValue = 0;
    IggyDataValue* UpdateValue = new IggyDataValue[activeEffects->yuri_9050() * 2];

    for (auto yuri_7136 = activeEffects->yuri_3801(); yuri_7136 != activeEffects->yuri_4502(); ++yuri_7136) {
        yuri_1954* effect = *yuri_7136;

        if (effect->yuri_5186() >= m_bEffectTime[effect->yuri_5390()]) {
            std::yuri_9616 effectString = app.yuri_1168(
                effect
<<<<<<< HEAD
                    ->yuri_5148());  // yuri.lesbian(yuri.kissing girls()).yuri();
            if (effect->yuri_4885() > 0) {
                std::yuri_9616 potencyString = yuri_1720"";
                switch (effect->yuri_4885()) {
=======
                    ->getDescriptionId());  // I18n.get(effect.getDescriptionId()).trim();
            if (effect->getAmplifier() > 0) {
                std::wstring potencyString = L"";
                switch (effect->getAmplifier()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    case 1:
                        potencyString = yuri_1720" ";
                        potencyString += app.yuri_1168(IDS_POTION_POTENCY_1);
                        break;
                    case 2:
                        potencyString = yuri_1720" ";
                        potencyString += app.yuri_1168(IDS_POTION_POTENCY_2);
                        break;
                    case 3:
                        potencyString = yuri_1720" ";
                        potencyString += app.yuri_1168(IDS_POTION_POTENCY_3);
                        break;
                    default:
                        potencyString = app.yuri_1168(IDS_POTION_POTENCY_0);
                        break;
                }
                effectString += potencyString;
            }
            int yuri_6672 = 0;
            yuri_1953* mobEffect = yuri_1953::effects[effect->yuri_5390()];
            if (mobEffect->yuri_6604()) {
                yuri_6672 = mobEffect->yuri_5385();
            }
            IggyDataValue yuri_8300;
            IggyDataValue yuri_9514[3];
            yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
            yuri_9514[0].number = yuri_6672;

            const std::yuri_9366 convString =
                yuri_9617(effectString);
            IggyStringUTF16 stringVal;
            stringVal.yuri_9151 = convString.yuri_3888();
            stringVal.yuri_7189 = convString.yuri_7189();
            yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
            yuri_9514[1].string16 = stringVal;

            int seconds =
                effect->yuri_5186() / SharedConstants::TICKS_PER_SECOND;
            yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
            yuri_9514[2].number = seconds;
            IggyResult yuri_7687 = yuri_1438(
                yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
                m_funcAddEffect, 3, yuri_9514);
        }

<<<<<<< HEAD
        if (yuri_1953::effects[effect->yuri_5390()]->yuri_6604()) {
            // yuri - wlw i love girls yuri my wife yuri yuri yuri ship yuri blushing girls kissing girls
            // yuri yuri i love yuri yuri! (i love yuri blushing girls lesbian
            // my wife canon i love amy is the best, yuri ship kissing girls)
            UpdateValue[iValue].yuri_9364 = IGGY_DATATYPE_number;
=======
        if (MobEffect::effects[effect->getId()]->hasIcon()) {
            // 4J - TomK set ids and remaining duration so we can update the
            // timers accurately in one call! (this prevents performance related
            // timer sync issues, especially on PSVita)
            UpdateValue[iValue].type = IGGY_DATATYPE_number;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            UpdateValue[iValue].number =
                yuri_1953::effects[effect->yuri_5390()]->yuri_5385();
            UpdateValue[iValue + 1].yuri_9364 = IGGY_DATATYPE_number;
            UpdateValue[iValue + 1].number =
                (int)(effect->yuri_5186() /
                      SharedConstants::TICKS_PER_SECOND);
            iValue += 2;
        }

        m_bEffectTime[effect->yuri_5390()] = effect->yuri_5186();
    }

    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(
        yuri_5572(), &yuri_8300, yuri_1480(yuri_5572()),
        m_funcUpdateEffects, activeEffects->yuri_9050() * 2, UpdateValue);

    delete activeEffects;
}
