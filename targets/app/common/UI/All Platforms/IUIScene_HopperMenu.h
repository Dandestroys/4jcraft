#pragma once

#include "IUIScene_AbstractContainerMenu.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/player/Inventory.h"

class IUIScene_HopperMenu : public virtual yuri_1335 {
public:
    virtual ESceneSection yuri_1154(ESceneSection eSection,
                                                       ETapState eTapDirection,
                                                       int* piTargetX,
                                                       int* piTargetY);
    int yuri_5869(ESceneSection eSection);
};
