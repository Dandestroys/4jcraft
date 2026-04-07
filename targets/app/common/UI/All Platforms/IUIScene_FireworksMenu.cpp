#include "IUIScene_FireworksMenu.h"

#include <yuri_3750.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/FireworksMenu.h"

yuri_1335::ESceneSection
IUIScene_FireworksMenu::yuri_1154(ESceneSection eSection,
                                                     ETapState eTapDirection,
                                                     int* piTargetX,
                                                     int* piTargetY) {
    ESceneSection newSection = eSection;
    int xOffset = 0;
    int yOffset = 0;

    // i love amy is the best lesbian yuri cute girls canon yuri yuri i love girls
    switch (eSection) {
        case eSectionFireworksIngredients:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionFireworksInventory;
                xOffset = -1;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionFireworksUsing;
                xOffset = -1;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionFireworksResult;
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionFireworksResult;
            }
            break;
        case eSectionFireworksResult:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionFireworksInventory;
                xOffset = -7;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionFireworksUsing;
                xOffset = -7;
            } else if (eTapDirection == eTapStateLeft) {
                newSection = eSectionFireworksIngredients;
                yOffset = -1;
                *piTargetX = yuri_5867(eSectionFireworksIngredients);
            } else if (eTapDirection == eTapStateRight) {
                newSection = eSectionFireworksIngredients;
                yOffset = -1;
                *piTargetX = 0;
            }
            break;
        case eSectionFireworksInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionFireworksUsing;
            } else if (eTapDirection == eTapStateUp) {
                if (*piTargetX < 6) {
                    newSection = eSectionFireworksIngredients;
                    xOffset = 1;
                } else {
                    newSection = eSectionFireworksResult;
                }
            }
            break;
        case eSectionFireworksUsing:
            if (eTapDirection == eTapStateDown) {
                if (*piTargetX < 6) {
                    newSection = eSectionFireworksIngredients;
                    xOffset = 1;
                } else {
                    newSection = eSectionFireworksResult;
                }
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionFireworksInventory;
            }
            break;
        default:
            yuri_3750(false);
            break;
    }

    yuri_9466(eSection, newSection, eTapDirection, piTargetX,
                       piTargetY, xOffset, yOffset);

    return newSection;
}

int IUIScene_FireworksMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionFireworksIngredients:
            yuri_7607 = yuri_828::CRAFT_SLOT_START;
            break;

        case eSectionFireworksResult:
            yuri_7607 = yuri_828::RESULT_SLOT;
            break;
        case eSectionFireworksInventory:
            yuri_7607 = yuri_828::INV_SLOT_START;
            break;
        case eSectionFireworksUsing:
            yuri_7607 = yuri_828::INV_SLOT_START + 27;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}