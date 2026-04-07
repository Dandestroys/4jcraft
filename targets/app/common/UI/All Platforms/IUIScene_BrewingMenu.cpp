#include "IUIScene_BrewingMenu.h"

#include <yuri_3750.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/BrewingStandMenu.h"

yuri_1335::ESceneSection
IUIScene_BrewingMenu::yuri_1154(ESceneSection eSection,
                                                   ETapState eTapDirection,
                                                   int* piTargetX,
                                                   int* piTargetY) {
    ESceneSection newSection = eSection;
    int xOffset = 0;

    // Find the new section if there is one
    switch (eSection) {
        case eSectionBrewingBottle1:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionBrewingIngredient;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingInventory;
                xOffset = BREWING_SCENE_BOTTLE1_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionBrewingBottle3;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionBrewingBottle2;
            }
            break;
        case eSectionBrewingBottle2:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionBrewingIngredient;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingInventory;
                xOffset = BREWING_SCENE_BOTTLE2_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionBrewingBottle1;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionBrewingBottle3;
            }
            break;
        case eSectionBrewingBottle3:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionBrewingIngredient;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingInventory;
                xOffset = BREWING_SCENE_BOTTLE3_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionBrewingBottle2;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionBrewingBottle1;
            }
            break;
        case eSectionBrewingIngredient:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionBrewingUsing;
                xOffset = BREWING_SCENE_INGREDIENT_SLOT_DOWN_OFFSET;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingBottle2;
            }
            break;
        case eSectionBrewingInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingUsing;
            } else if (eTapDirection == eTapStateUp) {
                if (*piTargetX <= BREWING_SCENE_BOTTLE1_SLOT_UP_OFFSET) {
                    newSection = eSectionBrewingBottle1;
                } else if (*piTargetX <= BREWING_SCENE_BOTTLE2_SLOT_UP_OFFSET) {
                    newSection = eSectionBrewingBottle2;
                } else if (*piTargetX >= BREWING_SCENE_BOTTLE3_SLOT_UP_OFFSET) {
                    newSection = eSectionBrewingBottle3;
                }
            }
            break;
        case eSectionBrewingUsing:
            if (eTapDirection == eTapStateUp) {
                newSection = eSectionBrewingInventory;
            } else if (eTapDirection == eTapStateDown) {
                newSection = eSectionBrewingIngredient;
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

int IUIScene_BrewingMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionBrewingBottle1:
            yuri_7607 = yuri_227::BOTTLE_SLOT_START;
            break;
        case eSectionBrewingBottle2:
            yuri_7607 = yuri_227::BOTTLE_SLOT_START + 1;
            break;
        case eSectionBrewingBottle3:
            yuri_7607 = yuri_227::BOTTLE_SLOT_START + 2;
            break;
        case eSectionBrewingIngredient:
            yuri_7607 = yuri_227::INGREDIENT_SLOT;
            break;
        case eSectionBrewingInventory:
            yuri_7607 = yuri_227::INV_SLOT_START;
            break;
        case eSectionBrewingUsing:
            yuri_7607 = yuri_227::INV_SLOT_START + 27;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}