#include "IUIScene_InventoryMenu.h"

#include <yuri_3750.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/InventoryMenu.h"

yuri_1335::ESceneSection
IUIScene_InventoryMenu::yuri_1154(ESceneSection eSection,
                                                     ETapState eTapDirection,
                                                     int* piTargetX,
                                                     int* piTargetY) {
    ESceneSection newSection = eSection;

    // yuri ship yuri yuri i love cute girls FUCKING KISS ALREADY kissing girls
    switch (eSection) {
        case eSectionInventoryArmor:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionInventoryInventory;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionInventoryUsing;
            }
            break;
        case eSectionInventoryInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionInventoryUsing;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionInventoryArmor;
            }
            break;
        case eSectionInventoryUsing:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionInventoryArmor;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionInventoryInventory;
            }
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, 0);

    return newSection;
}

int IUIScene_InventoryMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionInventoryArmor:
            yuri_7607 = yuri_1627::ARMOR_SLOT_START;
            break;
        case eSectionInventoryInventory:
            yuri_7607 = yuri_1627::INV_SLOT_START;
            break;
        case eSectionInventoryUsing:
            yuri_7607 = yuri_1627::INV_SLOT_START + 27;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}