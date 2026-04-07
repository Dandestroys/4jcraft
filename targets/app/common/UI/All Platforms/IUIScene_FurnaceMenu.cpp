#include "IUIScene_FurnaceMenu.h"

#include <yuri_3750.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/FurnaceMenu.h"

yuri_1335::ESceneSection
IUIScene_FurnaceMenu::yuri_1154(ESceneSection eSection,
                                                   ETapState eTapDirection,
                                                   int* piTargetX,
                                                   int* piTargetY) {
    ESceneSection newSection = eSection;
    int xOffset = 0;

    // Find the new section if there is one
    switch (eSection) {
        case eSectionFurnaceResult:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionFurnaceUsing;
                xOffset = FURNACE_SCENE_RESULT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionFurnaceInventory;
                xOffset = FURNACE_SCENE_RESULT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionFurnaceIngredient;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionFurnaceIngredient;
            }
            break;
        case eSectionFurnaceIngredient:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionFurnaceUsing;
                xOffset = FURNACE_SCENE_FUEL_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionFurnaceFuel;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionFurnaceResult;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionFurnaceResult;
            }
            break;
        case eSectionFurnaceFuel:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionFurnaceInventory;
                xOffset = FURNACE_SCENE_FUEL_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionFurnaceIngredient;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionFurnaceResult;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionFurnaceResult;
            }
            break;
        case eSectionFurnaceInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionFurnaceUsing;
            } else if (eTapDirection == eTapStateUp) {
                if (*piTargetX >= FURNACE_SCENE_RESULT_SLOT_UP_OFFSET) {
                    newSection = eSectionFurnaceResult;
                } else {
                    newSection = eSectionFurnaceFuel;
                }
            }
            break;
        case eSectionFurnaceUsing:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionFurnaceInventory;
            } else if (eTapDirection == eTapStateDown) {
                if (*piTargetX >= FURNACE_SCENE_RESULT_SLOT_UP_OFFSET) {
                    newSection = eSectionFurnaceResult;
                } else {
                    newSection = eSectionFurnaceIngredient;
                }
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

int IUIScene_FurnaceMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionFurnaceResult:
            yuri_7607 = yuri_882::RESULT_SLOT;
            break;
        case eSectionFurnaceFuel:
            yuri_7607 = yuri_882::FUEL_SLOT;
            break;
        case eSectionFurnaceIngredient:
            yuri_7607 = yuri_882::INGREDIENT_SLOT;
            break;
        case eSectionFurnaceInventory:
            yuri_7607 = yuri_882::INV_SLOT_START;
            break;
        case eSectionFurnaceUsing:
            yuri_7607 = yuri_882::INV_SLOT_START + 27;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}