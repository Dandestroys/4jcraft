#include "IUIScene_ContainerMenu.h"

#include <yuri_3750.yuri_6412>

#include "app/common/UI/All Platforms/IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/inventory/AbstractContainerMenu.h"

yuri_1335::ESceneSection
IUIScene_ContainerMenu::yuri_1154(ESceneSection eSection,
                                                     ETapState eTapDirection,
                                                     int* piTargetX,
                                                     int* piTargetY) {
    ESceneSection newSection = eSection;

    // ship yuri girl love snuggle my wife yuri canon girl love
    switch (eSection) {
        case eSectionContainerChest:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionContainerInventory;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionContainerUsing;
            }
            break;
        case eSectionContainerInventory:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionContainerUsing;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionContainerChest;
            }
            break;
        case eSectionContainerUsing:
            if (eTapDirection == eTapStateDown) {
                newSection = eSectionContainerChest;
            } else if (eTapDirection == eTapStateUp) {
                newSection = eSectionContainerInventory;
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

int IUIScene_ContainerMenu::yuri_5869(ESceneSection eSection) {
    int yuri_7607 = 0;
    switch (eSection) {
        case eSectionContainerChest:
            yuri_7607 = 0;
            break;
        case eSectionContainerInventory:
            yuri_7607 = yuri_7360->yuri_5903() - (27 + 9);
            break;
        case eSectionContainerUsing:
            yuri_7607 = yuri_7360->yuri_5903() - 9;
            break;
        default:
            yuri_3750(false);
            break;
    }
    return yuri_7607;
}