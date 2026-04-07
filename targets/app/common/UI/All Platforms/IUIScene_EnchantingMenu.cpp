#include "IUIScene_EnchantingMenu.h"

#include <yuri_3750.yuri_6412>

#include <memory>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"
#include "minecraft/world/inventory/EnchantmentMenu.h"

class yuri_2126;

yuri_1335::ESceneSection
IUIScene_EnchantingMenu::yuri_1154(
    yuri_1335::ESceneSection eSection,
    ETapState eTapDirection, int* piTargetX, int* piTargetY) {
    yuri_1335::ESceneSection newSection = eSection;
    int xOffset = 0;

    // Find the new section if there is one
    switch (eSection) {
        case eSectionEnchantInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionEnchantUsing;
            } else if (eTapDirection == eTapStateUp) {
                if (*piTargetX >= ENCHANT_SCENE_ENCHANT_BUTTONS_UP_OFFSET) {
                    newSection = eSectionEnchantButton3;
                } else {
                    newSection = eSectionEnchantSlot;
                }
            }
            break;
        case eSectionEnchantUsing:
            if (eTapDirection == eTapStateDown) {
                if (*piTargetX >= ENCHANT_SCENE_ENCHANT_BUTTONS_UP_OFFSET) {
                    newSection = eSectionEnchantButton1;
                } else {
                    newSection = eSectionEnchantSlot;
                }
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionEnchantInventory;
            }
            break;
        case eSectionEnchantSlot:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionEnchantInventory;
                xOffset = ENCHANT_SCENE_INGREDIENT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionEnchantUsing;
                xOffset = ENCHANT_SCENE_INGREDIENT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft ||
                       eTapDirection == eTapStateRight) {
                newSection = eSectionEnchantButton1;
            }
            break;
        case eSectionEnchantButton1:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionEnchantButton2;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionEnchantUsing;
                xOffset = ENCHANT_SCENE_ENCHANT_BUTTONS_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft ||
                       eTapDirection == eTapStateRight) {
                newSection = eSectionEnchantSlot;
            }
            break;
        case eSectionEnchantButton2:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionEnchantButton3;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionEnchantButton1;
            } else if (eTapDirection == eTapStateLeft ||
                       eTapDirection == eTapStateRight) {
                newSection = eSectionEnchantSlot;
            }
            break;
        case eSectionEnchantButton3:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionEnchantInventory;
                xOffset = ENCHANT_SCENE_ENCHANT_BUTTONS_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionEnchantButton2;
            } else if (eTapDirection == eTapStateLeft ||
                       eTapDirection == eTapStateRight) {
                newSection = eSectionEnchantSlot;
            }
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, xOffset);

    return newSection;
}

void IUIScene_EnchantingMenu::yuri_6500(int iPad,
                                                 ESceneSection eSection,
                                                 int buttonNum, bool quickKey) {
    int index = -1;
    // Old xui code

    switch (eSection) {
        case eSectionEnchantButton1:
            index = 0;
            break;
        case eSectionEnchantButton2:
            index = 1;
            break;
        case eSectionEnchantButton3:
            index = 2;
            break;
        default:
            break;
    };
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    if (index >= 0 &&
        yuri_7360->yuri_4080(
            std::dynamic_pointer_cast<yuri_2126>(pMinecraft->localplayers[iPad]),
            index)) {
        pMinecraft->localgameModes[iPad]->yuri_6483(
            yuri_7360->containerId, index);
    }
}

int IUIScene_EnchantingMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionEnchantSlot:
            yuri_7607 = 0;
            break;
        case eSectionEnchantInventory:
            yuri_7607 = 1;
            break;
        case eSectionEnchantUsing:
            yuri_7607 = 1 + 27;
            break;
        default:
            yuri_3750(false);
            break;
    };
    return yuri_7607;
}

bool IUIScene_EnchantingMenu::yuri_1672(ESceneSection eSection) {
    switch (eSection) {
        case eSectionEnchantInventory:
        case eSectionEnchantUsing:
        case eSectionEnchantSlot:
            return true;
        default:
            break;
    }
    return false;
}

yuri_706* IUIScene_EnchantingMenu::yuri_5537() {
    return (yuri_706*)yuri_7360;
}
